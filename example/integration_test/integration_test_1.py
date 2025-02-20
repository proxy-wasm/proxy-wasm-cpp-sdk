import subprocess
import threading
import requests
import time
import json
from http.server import ThreadingHTTPServer, BaseHTTPRequestHandler

# Constants
EXT_AUTHZ_PORT = 8081
UPSTREAM_PORT = 8080
ENVOY_PORT = 10000
ENVOY_CONFIG = "envoy_config.yaml"
ENVOY_CONFIG_MONITOR = "envoy_config_monitoring.yaml"
ENVOY_BINARY = "./envoy-binary"

# Dummy ExtAuthz Handler
class ExtAuthzHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        # Parse headers
        auth_header = self.headers.get("x-verkada-auth", "")
        
        # Log the incoming request
        # print(f"Received request with x-verkada-auth: '{auth_header}'")
        
        # Determine the response based on the x-verkada-auth header
        if "bad" in auth_header:
            # Forbidden response (403)
            self.send_response(403)
            self.send_header("Content-Type", "application/json")
            self.send_header("x-custom-header-ext-authz", "forbidden")
            self.end_headers()
            response = {"status": "denied", "message": "Authorization failed"}
        else:
            # OK response (200)
            self.send_response(200)
            self.send_header("Content-Type", "application/json")
            self.send_header("x-custom-header-ext-authz", "success")
            self.end_headers()
            response = {"status": "ok", "message": "Authorization successful"}
        
        # Send the response
        response_json = json.dumps(response)
        self.wfile.write(response_json.encode("utf-8"))

    def do_POST(self):
        # Route based on the path
        if self.path != "/auth/tokeninfo":
            self.send_response(404)
            self.end_headers()
            return

        # Parse headers
        auth_header = self.headers.get("x-verkada-auth", "")
        
        # Log the incoming request
        print(f"Received POST request with x-verkada-auth: '{auth_header}'")
        
        # Determine the response based on the x-verkada-auth header
        if "bad" in auth_header:
            # Forbidden response (4xx)
            self.send_response(403)
            self.send_header("Content-Type", "application/json")
            self.send_header("x-custom-header-ext-authz", "forbidden")
            self.end_headers()
            response = {"status": "denied", "message": "Authorization failed"}
        else:
            # OK response (200)
            self.send_response(200)
            self.send_header("Content-Type", "application/json")
            self.send_header("x-custom-header-ext-authz", "success")
            self.end_headers()

            response = {
                "securityToken": [{
                    "creation": "1733506911",
                    "effectiveEntityId": "98379d30-9b64-4789-a7cc-849c565d3bda",
                    "expiration": "2048866911",
                    "ipAddress": "104.28.237.136",
                    "maxExpirationDuration": "315360000",
                    "realEntityId": "98379d30-9b64-4789-a7cc-849c565d3bda",
                    "token": "v2_b328e4ca910bab490ecaab71f9787f9f",
                    "tokenHash": "421ef1f93cdf057712421ae48c033359f28da054f1589245e1f19ec6130a2af0",
                    "organizationId": "",
                    "cacheId": "421ef1f93cdf057712421ae48c033359f28da054f1589245e1f19ec6130a2af0",
                    "platform": "curl/8.7.1",
                    "tokenInfo": None,
                    "sessionTimeout": "604800",
                    "tokenScopeKeys": []
                }]
            }
        
        # Set the HTTP status code
        response_json = json.dumps(response)
        self.wfile.write(response_json.encode("utf-8"))

# Function to run ExtAuthz server
def run_ext_authz_server():
    server_address = ('127.0.0.1', EXT_AUTHZ_PORT)
    httpd = ThreadingHTTPServer(server_address, ExtAuthzHandler)
    print(f"ExtAuthz Server started on port {EXT_AUTHZ_PORT}...")
    httpd.serve_forever()

# Custom handler for the upstream service
class UpstreamHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-Type", "text/plain")
        self.end_headers()
        self.wfile.write(b"Upstream service response")

# Function to start upstream service with custom handler
def start_upstream_service():
    server_address = ('', UPSTREAM_PORT)
    httpd = ThreadingHTTPServer(server_address, UpstreamHandler)
    print(f"Upstream service started on port {UPSTREAM_PORT}...")
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


# Function to start Envoy
def start_envoy(envoy_config_file):
    return subprocess.Popen(
        [ENVOY_BINARY, "-c", envoy_config_file, "--log-level", "info", "--log-path", "envoy.log", ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )

valid_token = "v2_b328e4ca910bab490ecaab71f9787f9f"
invalid_token = "v2_b328e4ca910bab490ecaab71f9787f9fbad"

# Function to send test requests
def test_monitoring():
    test_cases = [
        {"name": "Monitor Valid Token", "header-xva": valid_token, "expected_status": 200},
        {"name": "Monitor Invalid Token", "header-xva": invalid_token, "expected_status": 200},
        {"name": "Monitor No Token", "header-xva": None, "expected_status": 200},
    ]

    envoy_url = f"http://127.0.0.1:{ENVOY_PORT}/"

    for test in test_cases:
        headers = {}
        if test["header-xva"]:
            headers["x-verkada-auth"] = test["header-xva"]

        print(f"Running test: {test['name']}")
        response = requests.get(envoy_url, headers=headers)
        print(f"Response Status: {response.status_code}")
        # assert response.status_code == test["expected_status"], f"Test failed: {test['name']}"
        assert response.status_code == test["expected_status"], (
            f"Test failed: {test['name']}\n"
            f"Expected status: {test['expected_status']}, but got: {response.status_code}\n")

def test_enforce():
    test_cases = [
        {"name": "Enforce Valid Token", "header-xva": valid_token, "expected_status": 200},
        {"name": "Enforce Invalid Token", "header-xva": invalid_token, "expected_status": 403},
        {"name": "Enforce No Token", "header-xva": None, "expected_status": 200}, # For now, we're not enforcing no token, because there may be other tokens
    ]

    envoy_url = f"http://127.0.0.1:{ENVOY_PORT}/test"

    for test in test_cases:
        headers = {}
        if test["header-xva"]:
            headers["x-verkada-auth"] = test["header-xva"]

        print(f"Running test: {test['name']}")
        response = requests.get(envoy_url, headers=headers)
        print(f"Response Status: {response.status_code}")
        assert response.status_code == test["expected_status"], (
            f"Test failed: {test['name']}\n"
            f"Expected status: {test['expected_status']}, but got: {response.status_code}\n"
            f"Response body: {response.text}"
        )

# Main function
def main():
    # Start ExtAuthz server in a separate thread
    ext_authz_thread = threading.Thread(target=run_ext_authz_server, daemon=True)
    ext_authz_thread.start()
    time.sleep(1)  # Give it a second to start

    # Start upstream service
    upstream_process = start_upstream_service()
    time.sleep(1)  # Give it a second to start

    try:
        # Start Envoy
        envoy_process = start_envoy(ENVOY_CONFIG_MONITOR)
        print(f"Envoy started with PID: {envoy_process.pid}")
        time.sleep(1)  # Allow Envoy to initialize

        # Run monitoring tests
        test_monitoring()

        # Restart Envoy with regular config
        print("Restarting Envoy with regular config...")
        envoy_process.terminate()
        envoy_process.wait()  # Wait for the process to terminate
        envoy_process = start_envoy(ENVOY_CONFIG)
        print(f"Envoy restarted with PID: {envoy_process.pid}")
        time.sleep(1)  # Allow Envoy to initialize

        # Run enforcement tests
        test_enforce()
    finally:
        # Cleanup
        print("Stopping processes...")
        #ext_authz_thread.shutdown()
        upstream_process.shutdown()
        envoy_process.terminate()
        print("All processes stopped.")

if __name__ == "__main__":
    main()
