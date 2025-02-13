#include "AuthConfigCheck.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <auth-check-file> <request-file>" << std::endl;
        return 1;
    }

    std::string authCheckFile = argv[1];
    std::string requestFile = argv[2];

    AuthConfigCheck authConfigCheck(authCheckFile);

    std::ifstream infile(requestFile);
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string host, path;
        if (!(iss >> host >> path)) {
            std::cerr << "Invalid request format: " << line << std::endl;
            continue;
        }

        std::string matchType;
        auto result = authConfigCheck.matchRequest(host, path, matchType);
        std::cout << "Host: " << host << ", Path: " << path << ", Match Type: " << matchType
                  << ", Host ID: " << result.first << ", Endpoint ID: " << result.second << std::endl;
    }

    return 0;
}