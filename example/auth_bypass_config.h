// Read Kubernetes configmap for bypass auth check config.

#pragma once

// Bypass config for staging
const std::string auth_bypass_config_yaml_staging = R"(
apiVersion: v1
items:
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /core/v1/user/command/init
          - /org/[0-9a-f-]{36}/user/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /core/v1/command/login/password
          - /core/v1/organization/get_for_user
          - /core/v1/organization/short_name/validate
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/disable
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/enable
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories/[0-9a-f-]{36}
          - /core/v1/user/auth/challenges
          - /core/v1/user/magic_link/redeem
          - /internal/core/v1/organization/[0-9a-f-]{36}
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /core/v1/user/command/init
          - /org/[0-9a-f-]{36}/user/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /core/v1/command/login/password
          - /core/v1/organization/get_for_user
          - /core/v1/organization/short_name/validate
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/disable
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/enable
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories/[0-9a-f-]{36}
          - /core/v1/user/auth/challenges
          - /core/v1/user/magic_link/redeem
          - /internal/core/v1/organization/[0-9a-f-]{36}
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /core/v1/user/command/init
          - /org/[0-9a-f-]{36}/user/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /core/v1/command/login/password
          - /core/v1/organization/get_for_user
          - /core/v1/organization/short_name/validate
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/disable
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/enable
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories/[0-9a-f-]{36}
          - /core/v1/user/auth/challenges
          - /core/v1/user/magic_link/redeem
          - /internal/core/v1/organization/[0-9a-f-]{36}
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /core/v1/user/command/init
          - /org/[0-9a-f-]{36}/user/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /core/v1/command/login/password
          - /core/v1/organization/get_for_user
          - /core/v1/organization/short_name/validate
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/disable
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/enable
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories/[0-9a-f-]{36}
          - /core/v1/user/auth/challenges
          - /core/v1/user/magic_link/redeem
          - /internal/core/v1/organization/[0-9a-f-]{36}
      - host: vprovision.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /core/v1/organization/get_for_user
          - /core/v1/organization/short_name/validate
          - /internal/core/v1/organization/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-dollhouse
    namespace: vinfra
    resourceVersion: "5009066376"
    uid: 03343e7f-db97-4c8a-9039-d0c54b5c55b2
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: istio-test.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
      - host: istio-test.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2025-01-24T06:27:04Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-istio
    namespace: vinfra
    resourceVersion: "5009066378"
    uid: bb641512-0051-474b-a842-7355f5ba586e
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /heartbeat
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /heartbeat
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /heartbeat
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /heartbeat
      - host: tachometer.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-tachometer
    namespace: vinfra
    resourceVersion: "5009066380"
    uid: b8961b3d-2c39-484a-a397-30e3619edeae
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: access.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /llm/ping
      - host: vcerberus.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /llm/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2025-02-20T00:15:16Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vaccessai
    namespace: vinfra
    resourceVersion: "5009066382"
    uid: 064d647c-3dc3-49e5-8d8e-410c5f7868b0
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: access.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /integrations/atrium/card_types
          - /integrations/atrium/card_types_mapping
          - /integrations/atrium/credentials
          - /integrations/atrium/user_import
      - host: vcerberus.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /integrations/atrium/card_types
          - /integrations/atrium/card_types_mapping
          - /integrations/atrium/credentials
          - /integrations/atrium/user_import
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-20T16:13:56Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vaccessintegrations
    namespace: vinfra
    resourceVersion: "5009066385"
    uid: ab25dc94-5dad-4540-90ce-57f74acb81ec
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vadmission.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /is_lockdowned
          - /mutate
          - /ping
          - /validate
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vadmission
    namespace: vinfra
    resourceVersion: "5009066387"
    uid: 5d32bbb9-ffdb-4309-a47a-09107fbcb749
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vagent.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /agent_workflow/get
          - /agent_workflow/step/checkpoint/create
          - /agent_workflow/step/update
          - /cases/claim
          - /cases/create
          - /cases/create_comment
          - /cases/create_verification
          - /cases/dispatch_profile/set
          - /cases/get
          - /cases/heartbeat
          - /cases/list
          - /cases/list_comments
          - /cases/list_contexts
          - /cases/list_history
          - /cases/list_verifications
          - /cases/pause
          - /cases/security_tokens
          - /cases/update
          - /cases/update_verification
          - /conference/get_details
          - /conference/list
          - /conference/start
          - /conversation/list_messages
          - /device/cases/close
          - /device/cases/create
          - /device/cases/get
          - /device/cases/resolve
          - /dispatch/confirm
          - /dispatch/create
          - /dispatch/get_psap_info
          - /dispatch/list
          - /dispatch/request
          - /dispatch/update
          - /sms/batch_update
          - /sms/create
          - /sms/list
        unauthenticatedEndpoints:
          - /ping
          - /twilio/conference/recording_status_callback
          - /twilio/conference/status_callback
          - /twilio/sms/media
          - /twilio/sms/receive_callback
          - /twilio/sms/send_status_callback
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vagent
    namespace: vinfra
    resourceVersion: "5009066390"
    uid: 25de6663-cda4-413b-a723-8df6d8fa8dd0
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vairflow.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /.*
      - host: vairflow.staging.cf.verkada.com
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /.*
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2025-01-13T20:30:35Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vairflow
    namespace: vinfra
    resourceVersion: "5009066393"
    uid: 3a444b16-a5a4-4b78-a813-cc2606110d8d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: valarm.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alarm/details
          - /alarm_configuration/add_person_detected_camera
          - /alarm_configuration/add_user_to_notify
          - /alarm_configuration/create
          - /alarm_configuration/delete
          - /alarm_configuration/details
          - /alarm_configuration/emergency_dispatch_context_camera/add
          - /alarm_configuration/emergency_dispatch_context_camera/update
          - /alarm_configuration/list
          - /alarm_configuration/remove_user_to_notify
          - /alarm_configuration/select_all_access_entity_triggers
          - /alarm_configuration/select_all_camera_triggers
          - /alarm_configuration/select_all_environmental_sensor_triggers
          - /alarm_configuration/select_all_keypad_triggers
          - /alarm_configuration/set_remote_monitoring_users
          - /alarm_configuration/update
          - /alarm_configuration/update_access_action_doors
          - /alarm_configuration/update_access_doors
          - /alarm_configuration/update_access_entity
          - /alarm_configuration/update_camera
          - /alarm_configuration/update_environmental_sensor
          - /alarm_configuration/update_environmental_sensors
          - /alarm_configuration/update_keypad
          - /alarm_configuration_user/bulk_set
          - /alarm_configuration_user/create
          - /alarm_configuration_user/push_enabled
          - /alarm_configuration_user/update
          - /alarm_events
          - /alarm_feedback/create
          - /alarm_feedback/get
          - /alarm_feedback/update
          - /alarm_response_schedule/list
          - /alarm_response_schedule/update_list
          - /bulk/alarm_configuration/update
          - /bulk/alarm_configuration/update_users_to_notify
          - /bulk/keycode/add
          - /bulk/zone/arm
          - /bulk/zone/disarm
          - /bulk/zone/submit_command_event
          - /bulk/zone/update
          - /bulk/zone/update_postal_address
          - /bulk/zone/update_unusual_state_change_windows
          - /bulk/zone/update_zone_arm_schedules
          - /camera_event/get_roi_overlap
          - /cellular/submit_ping
          - /command/lockout_event/submit
          - /debug/create_sensor_event
          - /device/commission/unassigned/batch
          - /device/current_state
          - /device/disable_learning_mode
          - /device/enable_learning_mode
          - /device/event/acknowledge
          - /device/event/list
          - /device/get_all
          - /device/get_or_create_wireless_device
          - /device/hub/[0-9a-f-]{36}
          - /device/hub/commission
          - /device/hub/decommission
          - /device/hub/details
          - /device/hub/list
          - /device/hub/submit_battery_reading
          - /device/hub/submit_wireless_stat_group
          - /device/hub/wireless_join_request
          - /device/hub_wireless_device/commission
          - /device/keypad/add_to_zone
          - /device/keypad/commission
          - /device/keypad/decommission
          - /device/keypad/get_all
          - /device/keypad/get_info
          - /device/keypad/hub_list
          - /device/keypad/restart
          - /device/keypad/unassigned/get_all
          - /device/keypad/update
          - /device/keypad_hub/commission
          - /device/keypad_hub/decommission
          - /device/rs485/sign_request
          - /device/sensor/add_nearby_camera
          - /device/sensor/add_to_zone
          - /device/sensor/delete
          - /device/sensor/remove_from_zone
          - /device/sensor/remove_nearby_camera
          - /device/sensor/update
          - /device/setup/batch
          - /device/unassigned/get_all
          - /device/warnings
          - /door/zone/get_configs
          - /door/zone/update_configs
          - /event
          - /event/detailed_organization_alarm_list
          - /event/detailed_zone_state_change_list
          - /event/hub_submit
          - /event/hub_submit_autogenic
          - /event/hub_submit_sync_state
          - /event/list
          - /event/persistent_change_datapoints
          - /event/person_detected_datapoints
          - /event/resolve_alarm
          - /event/submit
          - /event/submit_wired_sensor_event
          - /event/upload_event_log
          - /gpio_pin_configuration/create_or_update
          - /gpio_pin_configuration/delete
          - /gpio_pin_configuration/details
          - /gpio_pin_configuration/list
          - /gpio_pin_configuration/update_hub_device_id
          - /hub/init
          - /hub/key_rotation
          - /hub/peers/webrtc
          - /integration_test/create_live_link
          - /keycode/create
          - /keycode/create/user
          - /keycode/delete
          - /keycode/update
          - /keycode/update/user
          - /keycode/user
          - /keypad/arm_countdown
          - /keypad/asset/download/((.+)\/)*([^\/]+)
          - /keypad/camera_groups
          - /keypad/cameras
          - /keypad/cellular_devices
          - /keypad/configurations
          - /keypad/device/event/list
          - /keypad/devices/access_devices
          - /keypad/devices/cameras
          - /keypad/devices/environmental_sensors
          - /keypad/devices/hub_groups
          - /keypad/devices/speakers
          - /keypad/doors
          - /keypad/environmental_sensors
          - /keypad/event/submit
          - /keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /keypad/keycodes
          - /keypad/list
          - /keypad/server_connectivity_status
          - /keypad/submit_offline_event
          - /keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /keypad/thumbnail/upload
          - /keypad/tts/generate
          - /keypad/update_device_info
          - /keypad/users
          - /keypad/v2/device/event/list
          - /keypad/video/download/playlist\.m3u8
          - /keypad/video/download/video\.ts
          - /keypad/video/upload
          - /keypad/zone/details
          - /keypad/zone/details/list
          - /keypad/zone/get_zone_associations
          - /keypad/zone/list
          - /keypad/zone/set_associations
          - /keypad/zone/update_configs
          - /keypad/zones
          - /licensing/overview
          - /org_alarm_settings/get
          - /org_alarm_settings/update
          - /organization/usage/video_verification
          - /organization/usage/video_verification/by_day
          - /output_pin_configuration/create_or_update
          - /output_pin_configuration/delete
          - /output_pin_configuration/details
          - /output_pin_configuration/list
          - /output_pin_configuration/update_hub_device_id
          - /peer_connection/list
          - /person_detected_data_point/list
          - /postal_address/create
          - /postal_address/delete
          - /postal_address/list
          - /postal_address/update
          - /postal_address/usage/video_verification
          - /read_only_check
          - /reporting/devices
          - /reporting/event_types
          - /reporting/events
          - /reporting/walk_tests
          - /unusual_state_change_window/list
          - /unusual_state_change_window/update_list
          - /valarm_internal_user/admin/delete_moved_cameras_for_zone/dry_run
          - /valarm_internal_user/admin/device/hub/decommission
          - /valarm_internal_user/admin/device/hub/list
          - /valarm_internal_user/admin/device/keypad/decommission
          - /valarm_internal_user/admin/device/wireless_sensor/decommission
          - /valarm_internal_user/admin/get_camera_config
          - /valarm_internal_user/admin/lockouts
          - /valarm_internal_user/admin/set_wireless_regulatory_code
          - /valarm_internal_user/create_shared_camera_for_trip
          - /valarm_internal_user/device/sensor/update
          - /valarm_internal_user/public/v1/devices
          - /valarm_internal_user/public/v1/sites
          - /valarm_internal_user/s3/alarm_event/video/presigned
          - /valarm_internal_user/send_camera_gif
          - /webrtc/get_ice_servers
          - /websocket/submit_webrtc_offer
          - /wireless_output_configs/create
          - /wireless_output_configs/delete
          - /wireless_output_configs/update
          - /zone/alarms_overview
          - /zone/arm
          - /zone/create
          - /zone/delete
          - /zone/details
          - /zone/disarm
          - /zone/list
          - /zone/status
          - /zone/submit_command_event
          - /zone/submit_mobile_event
          - /zone/toggle_walk_test_mode
          - /zone/update
          - /zone/update_postal_address
          - /zone/usage/video_verification
          - /zone/users
          - /zone/walk_test_report
          - /zone/walk_test_status
          - /zone_activity/items
          - /zone_arm_schedule/list
          - /zone_arm_schedule/update_list
        unauthenticatedEndpoints:
          - /[a-zA-Z0-9]{40}/camera_thumbnail\.gif
          - /[a-zA-Z0-9]{40}/camera_thumbnail_v2\.gif
          - /alarm_flow_health_check
          - /alarms-app/magic-link
          - /arm_schedule_check
          - /cellular/events/twilio
          - /events/noonlight_webhook
          - /keypad_thumbnail/with_secret_token/[a-zA-Z0-9]{64}\.jpeg
          - /ping
          - /schedule/noonlight_webhook/disarm_override
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/((.+)\/)*([^\/]+)
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/video\.m3u8
          - /shared_camera/[0-9a-f-]{36}/live/((.+)\/)*([^\/]+)
          - /socket\.io/
          - /talkdown/zone/details
          - /valarm/ping
          - /valarm_internal_user/admin/openapi/json
          - /video_verification/noonlight_webhook
          - /webrtc/get_ice_servers_talkdown
          - /worker_health_check
          - /zone/talkdown/details
      - host: alarms.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alarm/details
          - /alarm_configuration/add_person_detected_camera
          - /alarm_configuration/add_user_to_notify
          - /alarm_configuration/create
          - /alarm_configuration/delete
          - /alarm_configuration/details
          - /alarm_configuration/emergency_dispatch_context_camera/add
          - /alarm_configuration/emergency_dispatch_context_camera/update
          - /alarm_configuration/list
          - /alarm_configuration/remove_user_to_notify
          - /alarm_configuration/select_all_access_entity_triggers
          - /alarm_configuration/select_all_camera_triggers
          - /alarm_configuration/select_all_environmental_sensor_triggers
          - /alarm_configuration/select_all_keypad_triggers
          - /alarm_configuration/set_remote_monitoring_users
          - /alarm_configuration/update
          - /alarm_configuration/update_access_action_doors
          - /alarm_configuration/update_access_doors
          - /alarm_configuration/update_access_entity
          - /alarm_configuration/update_camera
          - /alarm_configuration/update_environmental_sensor
          - /alarm_configuration/update_environmental_sensors
          - /alarm_configuration/update_keypad
          - /alarm_configuration_user/bulk_set
          - /alarm_configuration_user/create
          - /alarm_configuration_user/push_enabled
          - /alarm_configuration_user/update
          - /alarm_events
          - /alarm_feedback/create
          - /alarm_feedback/get
          - /alarm_feedback/update
          - /alarm_response_schedule/list
          - /alarm_response_schedule/update_list
          - /bulk/alarm_configuration/update
          - /bulk/alarm_configuration/update_users_to_notify
          - /bulk/keycode/add
          - /bulk/zone/arm
          - /bulk/zone/disarm
          - /bulk/zone/submit_command_event
          - /bulk/zone/update
          - /bulk/zone/update_postal_address
          - /bulk/zone/update_unusual_state_change_windows
          - /bulk/zone/update_zone_arm_schedules
          - /camera_event/get_roi_overlap
          - /cellular/submit_ping
          - /command/lockout_event/submit
          - /debug/create_sensor_event
          - /device/commission/unassigned/batch
          - /device/current_state
          - /device/disable_learning_mode
          - /device/enable_learning_mode
          - /device/event/acknowledge
          - /device/event/list
          - /device/get_all
          - /device/get_or_create_wireless_device
          - /device/hub/[0-9a-f-]{36}
          - /device/hub/commission
          - /device/hub/decommission
          - /device/hub/details
          - /device/hub/list
          - /device/hub/submit_battery_reading
          - /device/hub/submit_wireless_stat_group
          - /device/hub/wireless_join_request
          - /device/hub_wireless_device/commission
          - /device/keypad/add_to_zone
          - /device/keypad/commission
          - /device/keypad/decommission
          - /device/keypad/get_all
          - /device/keypad/get_info
          - /device/keypad/hub_list
          - /device/keypad/restart
          - /device/keypad/unassigned/get_all
          - /device/keypad/update
          - /device/keypad_hub/commission
          - /device/keypad_hub/decommission
          - /device/rs485/sign_request
          - /device/sensor/add_nearby_camera
          - /device/sensor/add_to_zone
          - /device/sensor/delete
          - /device/sensor/remove_from_zone
          - /device/sensor/remove_nearby_camera
          - /device/sensor/update
          - /device/setup/batch
          - /device/unassigned/get_all
          - /device/warnings
          - /door/zone/get_configs
          - /door/zone/update_configs
          - /event
          - /event/detailed_organization_alarm_list
          - /event/detailed_zone_state_change_list
          - /event/hub_submit
          - /event/hub_submit_autogenic
          - /event/hub_submit_sync_state
          - /event/list
          - /event/persistent_change_datapoints
          - /event/person_detected_datapoints
          - /event/resolve_alarm
          - /event/submit
          - /event/submit_wired_sensor_event
          - /event/upload_event_log
          - /gpio_pin_configuration/create_or_update
          - /gpio_pin_configuration/delete
          - /gpio_pin_configuration/details
          - /gpio_pin_configuration/list
          - /gpio_pin_configuration/update_hub_device_id
          - /hub/init
          - /hub/key_rotation
          - /hub/peers/webrtc
          - /integration_test/create_live_link
          - /keycode/create
          - /keycode/create/user
          - /keycode/delete
          - /keycode/update
          - /keycode/update/user
          - /keycode/user
          - /keypad/arm_countdown
          - /keypad/asset/download/((.+)\/)*([^\/]+)
          - /keypad/camera_groups
          - /keypad/cameras
          - /keypad/cellular_devices
          - /keypad/configurations
          - /keypad/device/event/list
          - /keypad/devices/access_devices
          - /keypad/devices/cameras
          - /keypad/devices/environmental_sensors
          - /keypad/devices/hub_groups
          - /keypad/devices/speakers
          - /keypad/doors
          - /keypad/environmental_sensors
          - /keypad/event/submit
          - /keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /keypad/keycodes
          - /keypad/list
          - /keypad/server_connectivity_status
          - /keypad/submit_offline_event
          - /keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /keypad/thumbnail/upload
          - /keypad/tts/generate
          - /keypad/update_device_info
          - /keypad/users
          - /keypad/v2/device/event/list
          - /keypad/video/download/playlist\.m3u8
          - /keypad/video/download/video\.ts
          - /keypad/video/upload
          - /keypad/zone/details
          - /keypad/zone/details/list
          - /keypad/zone/get_zone_associations
          - /keypad/zone/list
          - /keypad/zone/set_associations
          - /keypad/zone/update_configs
          - /keypad/zones
          - /licensing/overview
          - /org_alarm_settings/get
          - /org_alarm_settings/update
          - /organization/usage/video_verification
          - /organization/usage/video_verification/by_day
          - /output_pin_configuration/create_or_update
          - /output_pin_configuration/delete
          - /output_pin_configuration/details
          - /output_pin_configuration/list
          - /output_pin_configuration/update_hub_device_id
          - /peer_connection/list
          - /person_detected_data_point/list
          - /postal_address/create
          - /postal_address/delete
          - /postal_address/list
          - /postal_address/update
          - /postal_address/usage/video_verification
          - /read_only_check
          - /reporting/devices
          - /reporting/event_types
          - /reporting/events
          - /reporting/walk_tests
          - /unusual_state_change_window/list
          - /unusual_state_change_window/update_list
          - /valarm_internal_user/admin/delete_moved_cameras_for_zone/dry_run
          - /valarm_internal_user/admin/device/hub/decommission
          - /valarm_internal_user/admin/device/hub/list
          - /valarm_internal_user/admin/device/keypad/decommission
          - /valarm_internal_user/admin/device/wireless_sensor/decommission
          - /valarm_internal_user/admin/get_camera_config
          - /valarm_internal_user/admin/lockouts
          - /valarm_internal_user/admin/set_wireless_regulatory_code
          - /valarm_internal_user/create_shared_camera_for_trip
          - /valarm_internal_user/device/sensor/update
          - /valarm_internal_user/public/v1/devices
          - /valarm_internal_user/public/v1/sites
          - /valarm_internal_user/s3/alarm_event/video/presigned
          - /valarm_internal_user/send_camera_gif
          - /webrtc/get_ice_servers
          - /websocket/submit_webrtc_offer
          - /wireless_output_configs/create
          - /wireless_output_configs/delete
          - /wireless_output_configs/update
          - /zone/alarms_overview
          - /zone/arm
          - /zone/create
          - /zone/delete
          - /zone/details
          - /zone/disarm
          - /zone/list
          - /zone/status
          - /zone/submit_command_event
          - /zone/submit_mobile_event
          - /zone/toggle_walk_test_mode
          - /zone/update
          - /zone/update_postal_address
          - /zone/usage/video_verification
          - /zone/users
          - /zone/walk_test_report
          - /zone/walk_test_status
          - /zone_activity/items
          - /zone_arm_schedule/list
          - /zone_arm_schedule/update_list
        unauthenticatedEndpoints:
          - /[a-zA-Z0-9]{40}/camera_thumbnail\.gif
          - /[a-zA-Z0-9]{40}/camera_thumbnail_v2\.gif
          - /alarm_flow_health_check
          - /alarms-app/magic-link
          - /arm_schedule_check
          - /cellular/events/twilio
          - /events/noonlight_webhook
          - /keypad_thumbnail/with_secret_token/[a-zA-Z0-9]{64}\.jpeg
          - /ping
          - /schedule/noonlight_webhook/disarm_override
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/((.+)\/)*([^\/]+)
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/video\.m3u8
          - /shared_camera/[0-9a-f-]{36}/live/((.+)\/)*([^\/]+)
          - /socket\.io/
          - /talkdown/zone/details
          - /valarm/ping
          - /valarm_internal_user/admin/openapi/json
          - /video_verification/noonlight_webhook
          - /webrtc/get_ice_servers_talkdown
          - /worker_health_check
          - /zone/talkdown/details
      - host: device-alarms.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alarm/details
          - /alarm_configuration/add_person_detected_camera
          - /alarm_configuration/add_user_to_notify
          - /alarm_configuration/create
          - /alarm_configuration/delete
          - /alarm_configuration/details
          - /alarm_configuration/emergency_dispatch_context_camera/add
          - /alarm_configuration/emergency_dispatch_context_camera/update
          - /alarm_configuration/list
          - /alarm_configuration/remove_user_to_notify
          - /alarm_configuration/select_all_access_entity_triggers
          - /alarm_configuration/select_all_camera_triggers
          - /alarm_configuration/select_all_environmental_sensor_triggers
          - /alarm_configuration/select_all_keypad_triggers
          - /alarm_configuration/set_remote_monitoring_users
          - /alarm_configuration/update
          - /alarm_configuration/update_access_action_doors
          - /alarm_configuration/update_access_doors
          - /alarm_configuration/update_access_entity
          - /alarm_configuration/update_camera
          - /alarm_configuration/update_environmental_sensor
          - /alarm_configuration/update_environmental_sensors
          - /alarm_configuration/update_keypad
          - /alarm_configuration_user/bulk_set
          - /alarm_configuration_user/create
          - /alarm_configuration_user/push_enabled
          - /alarm_configuration_user/update
          - /alarm_events
          - /alarm_feedback/create
          - /alarm_feedback/get
          - /alarm_feedback/update
          - /alarm_response_schedule/list
          - /alarm_response_schedule/update_list
          - /bulk/alarm_configuration/update
          - /bulk/alarm_configuration/update_users_to_notify
          - /bulk/keycode/add
          - /bulk/zone/arm
          - /bulk/zone/disarm
          - /bulk/zone/submit_command_event
          - /bulk/zone/update
          - /bulk/zone/update_postal_address
          - /bulk/zone/update_unusual_state_change_windows
          - /bulk/zone/update_zone_arm_schedules
          - /camera_event/get_roi_overlap
          - /cellular/submit_ping
          - /command/lockout_event/submit
          - /debug/create_sensor_event
          - /device/commission/unassigned/batch
          - /device/current_state
          - /device/disable_learning_mode
          - /device/enable_learning_mode
          - /device/event/acknowledge
          - /device/event/list
          - /device/get_all
          - /device/get_or_create_wireless_device
          - /device/hub/[0-9a-f-]{36}
          - /device/hub/commission
          - /device/hub/decommission
          - /device/hub/details
          - /device/hub/list
          - /device/hub/submit_battery_reading
          - /device/hub/submit_wireless_stat_group
          - /device/hub/wireless_join_request
          - /device/hub_wireless_device/commission
          - /device/keypad/add_to_zone
          - /device/keypad/commission
          - /device/keypad/decommission
          - /device/keypad/get_all
          - /device/keypad/get_info
          - /device/keypad/hub_list
          - /device/keypad/restart
          - /device/keypad/unassigned/get_all
          - /device/keypad/update
          - /device/keypad_hub/commission
          - /device/keypad_hub/decommission
          - /device/rs485/sign_request
          - /device/sensor/add_nearby_camera
          - /device/sensor/add_to_zone
          - /device/sensor/delete
          - /device/sensor/remove_from_zone
          - /device/sensor/remove_nearby_camera
          - /device/sensor/update
          - /device/setup/batch
          - /device/unassigned/get_all
          - /device/warnings
          - /door/zone/get_configs
          - /door/zone/update_configs
          - /event
          - /event/detailed_organization_alarm_list
          - /event/detailed_zone_state_change_list
          - /event/hub_submit
          - /event/hub_submit_autogenic
          - /event/hub_submit_sync_state
          - /event/list
          - /event/persistent_change_datapoints
          - /event/person_detected_datapoints
          - /event/resolve_alarm
          - /event/submit
          - /event/submit_wired_sensor_event
          - /event/upload_event_log
          - /gpio_pin_configuration/create_or_update
          - /gpio_pin_configuration/delete
          - /gpio_pin_configuration/details
          - /gpio_pin_configuration/list
          - /gpio_pin_configuration/update_hub_device_id
          - /hub/init
          - /hub/key_rotation
          - /hub/peers/webrtc
          - /integration_test/create_live_link
          - /keycode/create
          - /keycode/create/user
          - /keycode/delete
          - /keycode/update
          - /keycode/update/user
          - /keycode/user
          - /keypad/arm_countdown
          - /keypad/asset/download/((.+)\/)*([^\/]+)
          - /keypad/camera_groups
          - /keypad/cameras
          - /keypad/cellular_devices
          - /keypad/configurations
          - /keypad/device/event/list
          - /keypad/devices/access_devices
          - /keypad/devices/cameras
          - /keypad/devices/environmental_sensors
          - /keypad/devices/hub_groups
          - /keypad/devices/speakers
          - /keypad/doors
          - /keypad/environmental_sensors
          - /keypad/event/submit
          - /keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /keypad/keycodes
          - /keypad/list
          - /keypad/server_connectivity_status
          - /keypad/submit_offline_event
          - /keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /keypad/thumbnail/upload
          - /keypad/tts/generate
          - /keypad/update_device_info
          - /keypad/users
          - /keypad/v2/device/event/list
          - /keypad/video/download/playlist\.m3u8
          - /keypad/video/download/video\.ts
          - /keypad/video/upload
          - /keypad/zone/details
          - /keypad/zone/details/list
          - /keypad/zone/get_zone_associations
          - /keypad/zone/list
          - /keypad/zone/set_associations
          - /keypad/zone/update_configs
          - /keypad/zones
          - /licensing/overview
          - /org_alarm_settings/get
          - /org_alarm_settings/update
          - /organization/usage/video_verification
          - /organization/usage/video_verification/by_day
          - /output_pin_configuration/create_or_update
          - /output_pin_configuration/delete
          - /output_pin_configuration/details
          - /output_pin_configuration/list
          - /output_pin_configuration/update_hub_device_id
          - /peer_connection/list
          - /person_detected_data_point/list
          - /postal_address/create
          - /postal_address/delete
          - /postal_address/list
          - /postal_address/update
          - /postal_address/usage/video_verification
          - /read_only_check
          - /reporting/devices
          - /reporting/event_types
          - /reporting/events
          - /reporting/walk_tests
          - /unusual_state_change_window/list
          - /unusual_state_change_window/update_list
          - /valarm_internal_user/admin/delete_moved_cameras_for_zone/dry_run
          - /valarm_internal_user/admin/device/hub/decommission
          - /valarm_internal_user/admin/device/hub/list
          - /valarm_internal_user/admin/device/keypad/decommission
          - /valarm_internal_user/admin/device/wireless_sensor/decommission
          - /valarm_internal_user/admin/get_camera_config
          - /valarm_internal_user/admin/lockouts
          - /valarm_internal_user/admin/set_wireless_regulatory_code
          - /valarm_internal_user/create_shared_camera_for_trip
          - /valarm_internal_user/device/sensor/update
          - /valarm_internal_user/public/v1/devices
          - /valarm_internal_user/public/v1/sites
          - /valarm_internal_user/s3/alarm_event/video/presigned
          - /valarm_internal_user/send_camera_gif
          - /webrtc/get_ice_servers
          - /websocket/submit_webrtc_offer
          - /wireless_output_configs/create
          - /wireless_output_configs/delete
          - /wireless_output_configs/update
          - /zone/alarms_overview
          - /zone/arm
          - /zone/create
          - /zone/delete
          - /zone/details
          - /zone/disarm
          - /zone/list
          - /zone/status
          - /zone/submit_command_event
          - /zone/submit_mobile_event
          - /zone/toggle_walk_test_mode
          - /zone/update
          - /zone/update_postal_address
          - /zone/usage/video_verification
          - /zone/users
          - /zone/walk_test_report
          - /zone/walk_test_status
          - /zone_activity/items
          - /zone_arm_schedule/list
          - /zone_arm_schedule/update_list
        unauthenticatedEndpoints:
          - /[a-zA-Z0-9]{40}/camera_thumbnail\.gif
          - /[a-zA-Z0-9]{40}/camera_thumbnail_v2\.gif
          - /alarm_flow_health_check
          - /alarms-app/magic-link
          - /arm_schedule_check
          - /cellular/events/twilio
          - /events/noonlight_webhook
          - /keypad_thumbnail/with_secret_token/[a-zA-Z0-9]{64}\.jpeg
          - /ping
          - /schedule/noonlight_webhook/disarm_override
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/((.+)\/)*([^\/]+)
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/video\.m3u8
          - /shared_camera/[0-9a-f-]{36}/live/((.+)\/)*([^\/]+)
          - /socket\.io/
          - /talkdown/zone/details
          - /valarm/ping
          - /valarm_internal_user/admin/openapi/json
          - /video_verification/noonlight_webhook
          - /webrtc/get_ice_servers_talkdown
          - /worker_health_check
          - /zone/talkdown/details
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /valarm/cellular/submit_ping
          - /valarm/command/lockout_event/submit
          - /valarm/device/current_state
          - /valarm/device/get_or_create_wireless_device
          - /valarm/device/hub/submit_battery_reading
          - /valarm/device/hub/submit_wireless_stat_group
          - /valarm/device/hub/wireless_join_request
          - /valarm/device/keypad/hub_list
          - /valarm/device/rs485/sign_request
          - /valarm/door/zone/get_configs
          - /valarm/event/hub_submit
          - /valarm/event/hub_submit_autogenic
          - /valarm/event/hub_submit_sync_state
          - /valarm/event/resolve_alarm
          - /valarm/event/upload_event_log
          - /valarm/hub/init
          - /valarm/hub/key_rotation
          - /valarm/hub/peers/webrtc
          - /valarm/keypad/arm_countdown
          - /valarm/keypad/asset/download/((.+)\/)*([^\/]+)
          - /valarm/keypad/camera_groups
          - /valarm/keypad/cameras
          - /valarm/keypad/cellular_devices
          - /valarm/keypad/configurations
          - /valarm/keypad/device/event/list
          - /valarm/keypad/devices/access_devices
          - /valarm/keypad/devices/cameras
          - /valarm/keypad/devices/environmental_sensors
          - /valarm/keypad/devices/hub_groups
          - /valarm/keypad/devices/speakers
          - /valarm/keypad/doors
          - /valarm/keypad/environmental_sensors
          - /valarm/keypad/event/submit
          - /valarm/keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /valarm/keypad/keycodes
          - /valarm/keypad/list
          - /valarm/keypad/server_connectivity_status
          - /valarm/keypad/submit_offline_event
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /valarm/keypad/thumbnail/upload
          - /valarm/keypad/tts/generate
          - /valarm/keypad/update_device_info
          - /valarm/keypad/users
          - /valarm/keypad/v2/device/event/list
          - /valarm/keypad/video/download/playlist\.m3u8
          - /valarm/keypad/video/download/video\.ts
          - /valarm/keypad/video/upload
          - /valarm/keypad/zone/details
          - /valarm/keypad/zone/details/list
          - /valarm/keypad/zone/get_zone_associations
          - /valarm/keypad/zone/list
          - /valarm/keypad/zone/set_associations
          - /valarm/keypad/zone/update_configs
          - /valarm/keypad/zones
          - /valarm/reporting/event_types
          - /valarm/webrtc/get_ice_servers
          - /valarm/zone/arm
          - /valarm/zone/disarm
        unauthenticatedEndpoints:
          - /valarm/ping
          - /valarm/webrtc/get_ice_servers_talkdown
          - /valarm/websocket/submit_webrtc_offer
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /valarm/cellular/submit_ping
          - /valarm/command/lockout_event/submit
          - /valarm/device/current_state
          - /valarm/device/get_or_create_wireless_device
          - /valarm/device/hub/submit_battery_reading
          - /valarm/device/hub/submit_wireless_stat_group
          - /valarm/device/hub/wireless_join_request
          - /valarm/device/keypad/hub_list
          - /valarm/device/rs485/sign_request
          - /valarm/door/zone/get_configs
          - /valarm/event/hub_submit
          - /valarm/event/hub_submit_autogenic
          - /valarm/event/hub_submit_sync_state
          - /valarm/event/resolve_alarm
          - /valarm/event/upload_event_log
          - /valarm/hub/init
          - /valarm/hub/key_rotation
          - /valarm/hub/peers/webrtc
          - /valarm/keypad/arm_countdown
          - /valarm/keypad/asset/download/((.+)\/)*([^\/]+)
          - /valarm/keypad/camera_groups
          - /valarm/keypad/cameras
          - /valarm/keypad/cellular_devices
          - /valarm/keypad/configurations
          - /valarm/keypad/device/event/list
          - /valarm/keypad/devices/access_devices
          - /valarm/keypad/devices/cameras
          - /valarm/keypad/devices/environmental_sensors
          - /valarm/keypad/devices/hub_groups
          - /valarm/keypad/devices/speakers
          - /valarm/keypad/doors
          - /valarm/keypad/environmental_sensors
          - /valarm/keypad/event/submit
          - /valarm/keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /valarm/keypad/keycodes
          - /valarm/keypad/list
          - /valarm/keypad/server_connectivity_status
          - /valarm/keypad/submit_offline_event
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /valarm/keypad/thumbnail/upload
          - /valarm/keypad/tts/generate
          - /valarm/keypad/update_device_info
          - /valarm/keypad/users
          - /valarm/keypad/v2/device/event/list
          - /valarm/keypad/video/download/playlist\.m3u8
          - /valarm/keypad/video/download/video\.ts
          - /valarm/keypad/video/upload
          - /valarm/keypad/zone/details
          - /valarm/keypad/zone/details/list
          - /valarm/keypad/zone/get_zone_associations
          - /valarm/keypad/zone/list
          - /valarm/keypad/zone/set_associations
          - /valarm/keypad/zone/update_configs
          - /valarm/keypad/zones
          - /valarm/reporting/event_types
          - /valarm/webrtc/get_ice_servers
          - /valarm/zone/arm
          - /valarm/zone/disarm
        unauthenticatedEndpoints:
          - /valarm/ping
          - /valarm/webrtc/get_ice_servers_talkdown
          - /valarm/websocket/submit_webrtc_offer
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /valarm/cellular/submit_ping
          - /valarm/command/lockout_event/submit
          - /valarm/device/current_state
          - /valarm/device/get_or_create_wireless_device
          - /valarm/device/hub/submit_battery_reading
          - /valarm/device/hub/submit_wireless_stat_group
          - /valarm/device/hub/wireless_join_request
          - /valarm/device/keypad/hub_list
          - /valarm/device/rs485/sign_request
          - /valarm/door/zone/get_configs
          - /valarm/event/hub_submit
          - /valarm/event/hub_submit_autogenic
          - /valarm/event/hub_submit_sync_state
          - /valarm/event/resolve_alarm
          - /valarm/event/upload_event_log
          - /valarm/hub/init
          - /valarm/hub/key_rotation
          - /valarm/hub/peers/webrtc
          - /valarm/keypad/arm_countdown
          - /valarm/keypad/asset/download/((.+)\/)*([^\/]+)
          - /valarm/keypad/camera_groups
          - /valarm/keypad/cameras
          - /valarm/keypad/cellular_devices
          - /valarm/keypad/configurations
          - /valarm/keypad/device/event/list
          - /valarm/keypad/devices/access_devices
          - /valarm/keypad/devices/cameras
          - /valarm/keypad/devices/environmental_sensors
          - /valarm/keypad/devices/hub_groups
          - /valarm/keypad/devices/speakers
          - /valarm/keypad/doors
          - /valarm/keypad/environmental_sensors
          - /valarm/keypad/event/submit
          - /valarm/keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /valarm/keypad/keycodes
          - /valarm/keypad/list
          - /valarm/keypad/server_connectivity_status
          - /valarm/keypad/submit_offline_event
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /valarm/keypad/thumbnail/upload
          - /valarm/keypad/tts/generate
          - /valarm/keypad/update_device_info
          - /valarm/keypad/users
          - /valarm/keypad/v2/device/event/list
          - /valarm/keypad/video/download/playlist\.m3u8
          - /valarm/keypad/video/download/video\.ts
          - /valarm/keypad/video/upload
          - /valarm/keypad/zone/details
          - /valarm/keypad/zone/details/list
          - /valarm/keypad/zone/get_zone_associations
          - /valarm/keypad/zone/list
          - /valarm/keypad/zone/set_associations
          - /valarm/keypad/zone/update_configs
          - /valarm/keypad/zones
          - /valarm/reporting/event_types
          - /valarm/webrtc/get_ice_servers
          - /valarm/zone/arm
          - /valarm/zone/disarm
        unauthenticatedEndpoints:
          - /valarm/ping
          - /valarm/webrtc/get_ice_servers_talkdown
          - /valarm/websocket/submit_webrtc_offer
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /valarm/cellular/submit_ping
          - /valarm/command/lockout_event/submit
          - /valarm/device/current_state
          - /valarm/device/get_or_create_wireless_device
          - /valarm/device/hub/submit_battery_reading
          - /valarm/device/hub/submit_wireless_stat_group
          - /valarm/device/hub/wireless_join_request
          - /valarm/device/keypad/hub_list
          - /valarm/device/rs485/sign_request
          - /valarm/door/zone/get_configs
          - /valarm/event/hub_submit
          - /valarm/event/hub_submit_autogenic
          - /valarm/event/hub_submit_sync_state
          - /valarm/event/resolve_alarm
          - /valarm/event/upload_event_log
          - /valarm/hub/init
          - /valarm/hub/key_rotation
          - /valarm/hub/peers/webrtc
          - /valarm/keypad/arm_countdown
          - /valarm/keypad/asset/download/((.+)\/)*([^\/]+)
          - /valarm/keypad/camera_groups
          - /valarm/keypad/cameras
          - /valarm/keypad/cellular_devices
          - /valarm/keypad/configurations
          - /valarm/keypad/device/event/list
          - /valarm/keypad/devices/access_devices
          - /valarm/keypad/devices/cameras
          - /valarm/keypad/devices/environmental_sensors
          - /valarm/keypad/devices/hub_groups
          - /valarm/keypad/devices/speakers
          - /valarm/keypad/doors
          - /valarm/keypad/environmental_sensors
          - /valarm/keypad/event/submit
          - /valarm/keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /valarm/keypad/keycodes
          - /valarm/keypad/list
          - /valarm/keypad/server_connectivity_status
          - /valarm/keypad/submit_offline_event
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /valarm/keypad/thumbnail/upload
          - /valarm/keypad/tts/generate
          - /valarm/keypad/update_device_info
          - /valarm/keypad/users
          - /valarm/keypad/v2/device/event/list
          - /valarm/keypad/video/download/playlist\.m3u8
          - /valarm/keypad/video/download/video\.ts
          - /valarm/keypad/video/upload
          - /valarm/keypad/zone/details
          - /valarm/keypad/zone/details/list
          - /valarm/keypad/zone/get_zone_associations
          - /valarm/keypad/zone/list
          - /valarm/keypad/zone/set_associations
          - /valarm/keypad/zone/update_configs
          - /valarm/keypad/zones
          - /valarm/reporting/event_types
          - /valarm/webrtc/get_ice_servers
          - /valarm/zone/arm
          - /valarm/zone/disarm
        unauthenticatedEndpoints:
          - /valarm/ping
          - /valarm/webrtc/get_ice_servers_talkdown
          - /valarm/websocket/submit_webrtc_offer
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-valarm
    namespace: vinfra
    resourceVersion: "5009066397"
    uid: d1226205-e604-4faa-96b3-1f71bf6f8015
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vallegion.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /client/doors/[0-9a-f-]{36}/relations
          - /client/doors/[0-9a-f-]{36}/status
        unauthenticatedEndpoints:
          - /engage/certificates
          - /engage/newCA/current
          - /engage/newCredentials
          - /engage/wss
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vallegion
    namespace: vinfra
    resourceVersion: "5009066404"
    uid: 93f84c96-73ce-4a62-8371-b4ac22f687a2
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vannounce.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /v1/alerts
          - /v1/alerts/[0-9a-f-]{36}/acknowledge
          - /v1/alerts/extended
        unauthenticatedEndpoints:
          - /ping
          - /v1/vsuite/[0-9a-f-]{36}/alerts
          - /v1/vsuite/alert/[0-9a-f-]{36}/edit
          - /v1/vsuite/alert/[0-9a-f-]{36}/resolve
          - /v1/vsuite/alert/create
          - /v1/vsuite/alert/templates
          - /v1/vsuite/alert/templates/[\w\.\-]+/i18n
      - host: vannounce.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /v1/cross_shard/[0-9a-f-]{36}/alerts
          - /v1/cross_shard/alert/[0-9a-f-]{36}/edit
          - /v1/cross_shard/alert/[0-9a-f-]{36}/resolve
          - /v1/cross_shard/alert/create
          - /v1/cross_shard/alert/templates
          - /v1/cross_shard/alert/templates/[\w\.\-]+/i18n
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vannounce
    namespace: vinfra
    resourceVersion: "5009066409"
    uid: 23edc6b7-2e2a-4064-a9e8-cc6d03391c17
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /app/init
          - /app/init/floorplans
          - /app/v2/init
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /app/init
          - /app/init/floorplans
          - /app/v2/init
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /app/init
          - /app/init/floorplans
          - /app/v2/init
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /app/init
          - /app/init/floorplans
          - /app/v2/init
      - host: vappinit.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /app/init
          - /app/init/floorplans
          - /app/v2/init
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vappinit
    namespace: vinfra
    resourceVersion: "5009066412"
    uid: ef0ae11a-f7bf-4ff0-ae6b-ad427c856143
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vapplewallet.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
      - host: access.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /applewallet/prepareProvisioning
          - /applewallet/provisioningStatus
      - host: vcerberus.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /applewallet/prepareProvisioning
          - /applewallet/provisioningStatus
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vapplewallet
    namespace: vinfra
    resourceVersion: "5009066416"
    uid: 94d12236-3db1-4180-b0e3-50b8bfe6ca1d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vassa.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /client/daemons
          - /client/doors/[0-9a-f-]{36}/lock
          - /client/doors/[0-9a-f-]{36}/reload
          - /client/doors/[0-9a-f-]{36}/unlock
          - /client/dsrs
          - /client/dsrs/[0-9a-f-]{36}
          - /client/dsrs/[0-9a-f-]{36}/accessPoints
          - /client/dsrs/[0-9a-f-]{36}/accessPoints/unregister
          - /client/dsrs/[0-9a-f-]{36}/clear
          - /client/dsrs/[0-9a-f-]{36}/decommission
          - /client/dsrs/[0-9a-f-]{36}/recommission
          - /client/users/[0-9a-f-]{36}/extended
          - /dsr/callback
          - /dsr/daemon/update
          - /dsr/wss
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vassa
    namespace: vinfra
    resourceVersion: "5009066419"
    uid: c79b0ab0-acbf-4732-9915-e76bcc8ec81a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /auth/access_token
          - /device/auth/enroll
          - /device/auth/token
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /auth/access_token
          - /device/auth/enroll
          - /device/auth/token
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /auth/access_token
          - /device/auth/enroll
          - /device/auth/token
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /auth/access_token
          - /device/auth/enroll
          - /device/auth/token
      - host: vauth.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/organizations/[0-9a-f-]{36}/entities/[0-9a-f-]{36}/grants
          - /admin/organizations/[0-9a-f-]{36}/security_entities/[0-9a-f-]{36}/flattened_permissions
          - /admin/organizations/[0-9a-f-]{36}/security_entities/[0-9a-f-]{36}/site_roles
          - /auth/access_token
          - /auth/active_tokens
          - /auth/any_org_or_site_admin_assert
          - /auth/assert
          - /auth/assert/any
          - /auth/assert_by_id
          - /auth/assert_org_and_site_admin_for_camera
          - /auth/become
          - /auth/become_status
          - /auth/check
          - /auth/check_by_grantee_ids
          - /auth/email/change
          - /auth/force_logout
          - /auth/get_active_accounts
          - /auth/init
          - /auth/invalidate_tokens
          - /auth/linked_accounts
          - /auth/login
          - /auth/logout
          - /auth/magic
          - /auth/org/[0-9a-f-]{36}/twofactor/allowedmethods
          - /auth/org/force_logout_all
          - /auth/org/lockout/[0-9a-f-]{36}
          - /auth/org/passwd/reset
          - /auth/org/twofactor
          - /auth/org/twofactor/allowedmethods
          - /auth/org/twofactor/reset
          - /auth/org_properties/[0-9a-f-]{36}
          - /auth/org_settings
          - /auth/passkey/verify
          - /auth/passwd
          - /auth/reset
          - /auth/reset/redeem
          - /auth/revoke_token
          - /auth/set_org_session_timeout
          - /auth/toggle_become
          - /auth/token_log
          - /auth/tokens/my
          - /auth/twofactor/backup
          - /auth/twofactor/new_backup
          - /auth/twofactor/passkey/disable
          - /auth/twofactor/qr/disable
          - /auth/twofactor/qr/setup
          - /auth/twofactor/qr/verify
          - /auth/twofactor/sms/disable
          - /auth/twofactor/sms/new
          - /auth/twofactor/sms/setup
          - /auth/twofactor/sms/verify
          - /auth/twofactor/status
          - /auth/twofactor/usePasskeyAs2fa
          - /auth/twofactor/webauthn/authenticate
          - /auth/twofactor/webauthn/disable
          - /auth/twofactor/webauthn/setup
          - /auth/twofactor/webauthn/verify
          - /auth/twofactor_enforced/qr/verify
          - /auth/twofactor_enforced/reset/passkey
          - /auth/twofactor_enforced/reset/qr
          - /auth/twofactor_enforced/reset/sms
          - /auth/twofactor_enforced/reset/usePasskeyAs2fa
          - /auth/twofactor_enforced/reset/webauthn
          - /auth/twofactor_enforced/sms/verify
          - /auth/twofactor_enforced/webauthn/verify
          - /bearer/generate
          - /bearer/list
          - /bearer/revoke
          - /device/auth/enroll
          - /device/auth/token
          - /directory/delete
          - /directory/parents
          - /embed/create
          - /embed/html/[0-9a-f-]{36}/
          - /embed/html/[0-9a-f-]{36}/allowlist
          - /embed/list
          - /embed/list_by_org
          - /embed/revoke
          - /internal/auth/force_logout
          - /internal/org/[0-9a-f-]{36}/update_role_grants_to_custom_roles
          - /live_link/create
          - /live_link/edit
          - /live_link/get
          - /live_link/get_expiration
          - /live_link/list
          - /live_link/redeem
          - /live_link/revoke
          - /magic_link/create
          - /magic_link/redeem
          - /org/[0-9a-f-]{36}/authed_entities_under_parent
          - /org/[0-9a-f-]{36}/custom_roles
          - /org/[0-9a-f-]{36}/custom_roles/enable
          - /org/[0-9a-f-]{36}/custom_roles/get_state
          - /org/[0-9a-f-]{36}/directory_entities
          - /org/[0-9a-f-]{36}/flattened_permissions
          - /org/[0-9a-f-]{36}/users/export
          - /organizations/[0-9a-f-]{36}/grants
          - /organizations/[0-9a-f-]{36}/roles
          - /permissions/for_grantee
          - /permissions/get_permissible_entities
          - /permissions/grant
          - /permissions/list
          - /permissions/list_admin_sites
          - /permissions/list_admins
          - /permissions/modify
          - /permissions/my
          - /permissions/require_real
          - /permissions/revoke
          - /ping
          - /roles/all
          - /roles/default/permissions
          - /saml/access_token
          - /saml/login/[0-9a-zA-Z._-]{1,64}
          - /saml/provider/[0-9a-f-]{36}
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}/edit
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}/upload
          - /saml/provider/[0-9a-f-]{36}/create
          - /saml/provider/[0-9a-f-]{36}/edit
          - /saml/provider/[0-9a-f-]{36}/provider_name
          - /saml/provider/[0-9a-f-]{36}/upload
          - /saml/providers
          - /saml/providers/[0-9a-f-]{36}
          - /saml/sso/[0-9a-zA-Z._-]{1,64}
          - /security_entities/create
          - /security_entities/list
          - /security_entity_group/create
          - /security_entity_group/delete
          - /security_entity_group/edit
          - /security_entity_group/get
          - /security_entity_group/list
          - /security_entity_group/members/add
          - /security_entity_group/members/list
          - /security_entity_group/members/remove
          - /security_entity_group/set_permissions
          - /support_full_access_expiration
          - /unlock_link/[0-9a-f-]{36}/exchange
          - /unlock_link/info
          - /user/auth_info
          - /user/grants
          - /user/org_ids
          - /user/security_entity_groups/list
          - /virtual_entity/auth/assert
        unauthenticatedEndpoints:
          - /auth/session_accounts
          - /auth/tokeninfo
          - /auth/twofactor_enforced/passkey/verify
      - host: saml.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/organizations/[0-9a-f-]{36}/entities/[0-9a-f-]{36}/grants
          - /admin/organizations/[0-9a-f-]{36}/security_entities/[0-9a-f-]{36}/flattened_permissions
          - /admin/organizations/[0-9a-f-]{36}/security_entities/[0-9a-f-]{36}/site_roles
          - /auth/access_token
          - /auth/active_tokens
          - /auth/any_org_or_site_admin_assert
          - /auth/assert
          - /auth/assert/any
          - /auth/assert_by_id
          - /auth/assert_org_and_site_admin_for_camera
          - /auth/become
          - /auth/become_status
          - /auth/check
          - /auth/check_by_grantee_ids
          - /auth/email/change
          - /auth/force_logout
          - /auth/get_active_accounts
          - /auth/init
          - /auth/invalidate_tokens
          - /auth/linked_accounts
          - /auth/login
          - /auth/logout
          - /auth/magic
          - /auth/org/[0-9a-f-]{36}/twofactor/allowedmethods
          - /auth/org/force_logout_all
          - /auth/org/lockout/[0-9a-f-]{36}
          - /auth/org/passwd/reset
          - /auth/org/twofactor
          - /auth/org/twofactor/allowedmethods
          - /auth/org/twofactor/reset
          - /auth/org_properties/[0-9a-f-]{36}
          - /auth/org_settings
          - /auth/passkey/verify
          - /auth/passwd
          - /auth/reset
          - /auth/reset/redeem
          - /auth/revoke_token
          - /auth/set_org_session_timeout
          - /auth/toggle_become
          - /auth/token_log
          - /auth/tokens/my
          - /auth/twofactor/backup
          - /auth/twofactor/new_backup
          - /auth/twofactor/passkey/disable
          - /auth/twofactor/qr/disable
          - /auth/twofactor/qr/setup
          - /auth/twofactor/qr/verify
          - /auth/twofactor/sms/disable
          - /auth/twofactor/sms/new
          - /auth/twofactor/sms/setup
          - /auth/twofactor/sms/verify
          - /auth/twofactor/status
          - /auth/twofactor/usePasskeyAs2fa
          - /auth/twofactor/webauthn/authenticate
          - /auth/twofactor/webauthn/disable
          - /auth/twofactor/webauthn/setup
          - /auth/twofactor/webauthn/verify
          - /auth/twofactor_enforced/qr/verify
          - /auth/twofactor_enforced/reset/passkey
          - /auth/twofactor_enforced/reset/qr
          - /auth/twofactor_enforced/reset/sms
          - /auth/twofactor_enforced/reset/usePasskeyAs2fa
          - /auth/twofactor_enforced/reset/webauthn
          - /auth/twofactor_enforced/sms/verify
          - /auth/twofactor_enforced/webauthn/verify
          - /bearer/generate
          - /bearer/list
          - /bearer/revoke
          - /device/auth/enroll
          - /device/auth/token
          - /directory/delete
          - /directory/parents
          - /embed/create
          - /embed/html/[0-9a-f-]{36}/
          - /embed/html/[0-9a-f-]{36}/allowlist
          - /embed/list
          - /embed/list_by_org
          - /embed/revoke
          - /internal/auth/force_logout
          - /internal/org/[0-9a-f-]{36}/update_role_grants_to_custom_roles
          - /live_link/create
          - /live_link/edit
          - /live_link/get
          - /live_link/get_expiration
          - /live_link/list
          - /live_link/redeem
          - /live_link/revoke
          - /magic_link/create
          - /magic_link/redeem
          - /org/[0-9a-f-]{36}/authed_entities_under_parent
          - /org/[0-9a-f-]{36}/custom_roles
          - /org/[0-9a-f-]{36}/custom_roles/enable
          - /org/[0-9a-f-]{36}/custom_roles/get_state
          - /org/[0-9a-f-]{36}/directory_entities
          - /org/[0-9a-f-]{36}/flattened_permissions
          - /org/[0-9a-f-]{36}/users/export
          - /organizations/[0-9a-f-]{36}/grants
          - /organizations/[0-9a-f-]{36}/roles
          - /permissions/for_grantee
          - /permissions/get_permissible_entities
          - /permissions/grant
          - /permissions/list
          - /permissions/list_admin_sites
          - /permissions/list_admins
          - /permissions/modify
          - /permissions/my
          - /permissions/require_real
          - /permissions/revoke
          - /ping
          - /roles/all
          - /roles/default/permissions
          - /saml/access_token
          - /saml/login/[0-9a-zA-Z._-]{1,64}
          - /saml/provider/[0-9a-f-]{36}
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}/edit
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}/upload
          - /saml/provider/[0-9a-f-]{36}/create
          - /saml/provider/[0-9a-f-]{36}/edit
          - /saml/provider/[0-9a-f-]{36}/provider_name
          - /saml/provider/[0-9a-f-]{36}/upload
          - /saml/providers
          - /saml/providers/[0-9a-f-]{36}
          - /saml/sso/[0-9a-zA-Z._-]{1,64}
          - /security_entities/create
          - /security_entities/list
          - /security_entity_group/create
          - /security_entity_group/delete
          - /security_entity_group/edit
          - /security_entity_group/get
          - /security_entity_group/list
          - /security_entity_group/members/add
          - /security_entity_group/members/list
          - /security_entity_group/members/remove
          - /security_entity_group/set_permissions
          - /support_full_access_expiration
          - /unlock_link/[0-9a-f-]{36}/exchange
          - /unlock_link/info
          - /user/auth_info
          - /user/grants
          - /user/org_ids
          - /user/security_entity_groups/list
          - /virtual_entity/auth/assert
        unauthenticatedEndpoints:
          - /auth/session_accounts
          - /auth/tokeninfo
          - /auth/twofactor_enforced/passkey/verify
      - host: vauth.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /auth/passkey_login
          - /internal/auth/cross_org/token
          - /internal/command_session
          - /internal/permissions/modify
          - /internal/security_entities/create
        unauthenticatedEndpoints:
          - /auth/tokeninfo
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vauth
    namespace: vinfra
    resourceVersion: "5009066425"
    uid: d18d0e42-068f-4940-9fd2-3b876b89727c
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/backup/failure
          - /submit/backup/index
          - /submit/backup/upload_info
        unauthenticatedEndpoints:
          - /submit/backup/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /submit/backup_segments/[0-9a-f-]{36}/latest
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/backup/failure
          - /submit/backup/index
          - /submit/backup/upload_info
        unauthenticatedEndpoints:
          - /submit/backup/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /submit/backup_segments/[0-9a-f-]{36}/latest
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/backup/failure
          - /submit/backup/index
          - /submit/backup/upload_info
        unauthenticatedEndpoints:
          - /submit/backup/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /submit/backup_segments/[0-9a-f-]{36}/latest
      - host: vbackup.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /batch/backup_config/get
          - /batch/backup_config/set
          - /batch/backup_pct_done/get
          - /batch/latest_backup_ts/get
          - /batch/oldest_backup_ts/get
          - /config/org/v1/[0-9a-f-]{36}/ecb_license_states
          - /config/v1/[0-9a-f-]{36}/backup_resolution
          - /config/v1/[0-9a-f-]{36}/backup_schedule
          - /config/v1/[0-9a-f-]{36}/backup_status
          - /config/v1/[0-9a-f-]{36}/latest_backup_ts
          - /config/v1/[0-9a-f-]{36}/oldest_backup_ts
          - /config/v1/[0-9a-f-]{36}/upload_schedule
          - /internal/[0-9a-f-]{36}/backup_all_info
          - /internal/[0-9a-f-]{36}/backup_resolution
          - /internal/[0-9a-f-]{36}/backup_schedule
          - /internal/[0-9a-f-]{36}/backup_status
          - /internal/[0-9a-f-]{36}/backup_up_to_date
          - /internal/[0-9a-f-]{36}/retention
          - /internal/[0-9a-f-]{36}/upload_schedule
          - /internal/batch/backup_config/get
          - /internal/batch/backup_config/set
        unauthenticatedEndpoints:
          - /internal/org/[0-9a-f-]{36}/ecb_info
          - /internal/supertest/backup_available
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vbackup
    namespace: vinfra
    resourceVersion: "5009066431"
    uid: 2176ff09-4b44-46da-8d54-c098fcdf71e7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vbroadcast.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /command/alarm/call_history/list
          - /command/call_event/submit
          - /command/call_history/list
          - /command/call_recording/get
          - /command/create_media_task
          - /command/delete_media_file_for_site
          - /command/delete_media_task
          - /command/device/broadcast_oneshot_media
          - /command/device/media_on_event
          - /command/device/play_media_once
          - /command/device/set_mic_muted
          - /command/device/set_microphone_sensitivity
          - /command/device/set_recording
          - /command/device/set_speaker_volume
          - /command/device/stop_media_once
          - /command/get_media_file
          - /command/get_media_file_for_site
          - /command/get_media_task
          - /command/site/media_on_event
          - /command/site/set_recording
          - /command/stream_tts_message
          - /command/tts/submit
          - /command/update_media_task_status
          - /command/upload_media_file
          - /command/upload_tts_message
          - /command/webrtc/get_ice_servers
          - /device/get_media_file
          - /device/poll_events
          - /device/speaker/device_info
          - /device/submit/af_at_status
          - /device/submit/call_event
          - /device/test/websocket_response
          - /device/webrtc/get_ice_servers
          - /management/speaker/associate_camera
          - /management/speaker/batch/lookup
          - /management/speaker/commission
          - /management/speaker/commission/unassigned/batch
          - /management/speaker/decommission
          - /management/speaker/disassociate_camera
          - /management/speaker/list
          - /management/speaker/setup/batch
          - /management/speaker/unassigned/list
          - /management/speaker/update
          - /websocket/submit_webrtc_offer
        unauthenticatedEndpoints:
          - /command/media/get_media_alerts_by_site
          - /internal/add_media_status
          - /ping
          - /socket\.io/
          - /talkdown/speakers/get_for_site_id
          - /talkdown/webrtc/get_ice_servers
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbroadcast/command/create_media_task
          - /vbroadcast/command/delete_media_task
          - /vbroadcast/command/device/media_on_event
          - /vbroadcast/command/device/set_microphone_sensitivity
          - /vbroadcast/command/device/set_speaker_volume
          - /vbroadcast/command/get_media_task
          - /vbroadcast/command/site/media_on_event
          - /vbroadcast/command/tts/submit
          - /vbroadcast/command/update_media_task_status
          - /vbroadcast/command/upload_media_file
          - /vbroadcast/device/get_media_file
          - /vbroadcast/device/media/add_media_alert
          - /vbroadcast/device/media_file/[0-9a-f-]{36}
          - /vbroadcast/device/poll_events
          - /vbroadcast/device/speaker/device_info
          - /vbroadcast/device/submit/af_at_status
          - /vbroadcast/device/submit/call_event
          - /vbroadcast/device/test/websocket_response
          - /vbroadcast/device/tts_file/[0-9a-f-]{36}
          - /vbroadcast/device/upload/presigned_url
          - /vbroadcast/device/webrtc/get_ice_servers
          - /vbroadcast/management/speaker/batch/lookup
          - /vbroadcast/management/speaker/commission
          - /vbroadcast/management/speaker/commission/unassigned/batch
          - /vbroadcast/management/speaker/decommission
          - /vbroadcast/management/speaker/disassociate_camera
          - /vbroadcast/management/speaker/list
          - /vbroadcast/management/speaker/setup/batch
          - /vbroadcast/management/speaker/unassigned/list
          - /vbroadcast/websocket/submit_webrtc_offer
        unauthenticatedEndpoints:
          - /vbroadcast/ping
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbroadcast/command/create_media_task
          - /vbroadcast/command/delete_media_task
          - /vbroadcast/command/device/media_on_event
          - /vbroadcast/command/device/set_microphone_sensitivity
          - /vbroadcast/command/device/set_speaker_volume
          - /vbroadcast/command/get_media_task
          - /vbroadcast/command/site/media_on_event
          - /vbroadcast/command/tts/submit
          - /vbroadcast/command/update_media_task_status
          - /vbroadcast/command/upload_media_file
          - /vbroadcast/device/get_media_file
          - /vbroadcast/device/media/add_media_alert
          - /vbroadcast/device/media_file/[0-9a-f-]{36}
          - /vbroadcast/device/poll_events
          - /vbroadcast/device/speaker/device_info
          - /vbroadcast/device/submit/af_at_status
          - /vbroadcast/device/submit/call_event
          - /vbroadcast/device/test/websocket_response
          - /vbroadcast/device/tts_file/[0-9a-f-]{36}
          - /vbroadcast/device/upload/presigned_url
          - /vbroadcast/device/webrtc/get_ice_servers
          - /vbroadcast/management/speaker/batch/lookup
          - /vbroadcast/management/speaker/commission
          - /vbroadcast/management/speaker/commission/unassigned/batch
          - /vbroadcast/management/speaker/decommission
          - /vbroadcast/management/speaker/disassociate_camera
          - /vbroadcast/management/speaker/list
          - /vbroadcast/management/speaker/setup/batch
          - /vbroadcast/management/speaker/unassigned/list
          - /vbroadcast/websocket/submit_webrtc_offer
        unauthenticatedEndpoints:
          - /vbroadcast/ping
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbroadcast/command/create_media_task
          - /vbroadcast/command/delete_media_task
          - /vbroadcast/command/device/media_on_event
          - /vbroadcast/command/device/set_microphone_sensitivity
          - /vbroadcast/command/device/set_speaker_volume
          - /vbroadcast/command/get_media_task
          - /vbroadcast/command/site/media_on_event
          - /vbroadcast/command/tts/submit
          - /vbroadcast/command/update_media_task_status
          - /vbroadcast/command/upload_media_file
          - /vbroadcast/device/get_media_file
          - /vbroadcast/device/media/add_media_alert
          - /vbroadcast/device/media_file/[0-9a-f-]{36}
          - /vbroadcast/device/poll_events
          - /vbroadcast/device/speaker/device_info
          - /vbroadcast/device/submit/af_at_status
          - /vbroadcast/device/submit/call_event
          - /vbroadcast/device/test/websocket_response
          - /vbroadcast/device/tts_file/[0-9a-f-]{36}
          - /vbroadcast/device/upload/presigned_url
          - /vbroadcast/device/webrtc/get_ice_servers
          - /vbroadcast/management/speaker/batch/lookup
          - /vbroadcast/management/speaker/commission
          - /vbroadcast/management/speaker/commission/unassigned/batch
          - /vbroadcast/management/speaker/decommission
          - /vbroadcast/management/speaker/disassociate_camera
          - /vbroadcast/management/speaker/list
          - /vbroadcast/management/speaker/setup/batch
          - /vbroadcast/management/speaker/unassigned/list
          - /vbroadcast/websocket/submit_webrtc_offer
        unauthenticatedEndpoints:
          - /vbroadcast/ping
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbroadcast/command/create_media_task
          - /vbroadcast/command/delete_media_task
          - /vbroadcast/command/device/media_on_event
          - /vbroadcast/command/device/set_microphone_sensitivity
          - /vbroadcast/command/device/set_speaker_volume
          - /vbroadcast/command/get_media_task
          - /vbroadcast/command/site/media_on_event
          - /vbroadcast/command/tts/submit
          - /vbroadcast/command/update_media_task_status
          - /vbroadcast/command/upload_media_file
          - /vbroadcast/device/get_media_file
          - /vbroadcast/device/media/add_media_alert
          - /vbroadcast/device/media_file/[0-9a-f-]{36}
          - /vbroadcast/device/poll_events
          - /vbroadcast/device/speaker/device_info
          - /vbroadcast/device/submit/af_at_status
          - /vbroadcast/device/submit/call_event
          - /vbroadcast/device/test/websocket_response
          - /vbroadcast/device/tts_file/[0-9a-f-]{36}
          - /vbroadcast/device/upload/presigned_url
          - /vbroadcast/device/webrtc/get_ice_servers
          - /vbroadcast/management/speaker/batch/lookup
          - /vbroadcast/management/speaker/commission
          - /vbroadcast/management/speaker/commission/unassigned/batch
          - /vbroadcast/management/speaker/decommission
          - /vbroadcast/management/speaker/disassociate_camera
          - /vbroadcast/management/speaker/list
          - /vbroadcast/management/speaker/setup/batch
          - /vbroadcast/management/speaker/unassigned/list
          - /vbroadcast/websocket/submit_webrtc_offer
        unauthenticatedEndpoints:
          - /vbroadcast/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vbroadcast
    namespace: vinfra
    resourceVersion: "5009066438"
    uid: dd4c8ffa-6164-4782-9863-bd70a501ab32
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbugreport/create_issue
          - /vbugreport/get_teams
          - /vbugreport/linear/create_issue
          - /vbugreport/linear/get_teams
          - /vbugreport/linear/upload_file
          - /vbugreport/upload_file
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbugreport/create_issue
          - /vbugreport/get_teams
          - /vbugreport/linear/create_issue
          - /vbugreport/linear/get_teams
          - /vbugreport/linear/upload_file
          - /vbugreport/upload_file
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbugreport/create_issue
          - /vbugreport/get_teams
          - /vbugreport/linear/create_issue
          - /vbugreport/linear/get_teams
          - /vbugreport/linear/upload_file
          - /vbugreport/upload_file
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbugreport/create_issue
          - /vbugreport/get_teams
          - /vbugreport/linear/create_issue
          - /vbugreport/linear/get_teams
          - /vbugreport/linear/upload_file
          - /vbugreport/upload_file
      - host: vbugreport.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /ping
          - /vbugreport/create_issue
          - /vbugreport/get_teams
          - /vbugreport/linear/create_issue
          - /vbugreport/linear/get_teams
          - /vbugreport/linear/upload_file
          - /vbugreport/upload_file
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vbugreport
    namespace: vinfra
    resourceVersion: "5009066443"
    uid: d0fd36ea-819c-4ee7-96b6-ad06cc862bec
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/media_key/decrypt
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/media_key/decrypt
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/media_key/decrypt
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/media_key/decrypt
      - host: vcameramgmt.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/has_id
          - /camera/media_key/decrypt
          - /camera/name/get
          - /camera/settings/led/get
          - /camera/settings/led/set
          - /camera/settings/retention/get
          - /camera/settings/retention/set
          - /camera/settings/rtsp/batch_get
          - /camera/settings/rtsp/batch_set
          - /camera/settings/rtsp/get
          - /camera/settings/rtsp/set
          - /get_cameras_by_org_id
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vcameramgmt
    namespace: vinfra
    resourceVersion: "5009066445"
    uid: 7d6e9939-615d-460f-824f-29f24aa556d0
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vcamerastats.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/incompatibility/users
          - /streaming/incompatibility/add
          - /streaming/stats/add
        unauthenticatedEndpoints:
          - /camera/streamstats/get
          - /org/streaming/metrics
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vcamerastats
    namespace: vinfra
    resourceVersion: "5009066451"
    uid: db8023b3-c348-4a2e-a27b-77b75507077d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/latest
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/latest
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/latest
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vcamsegs
    namespace: vinfra
    resourceVersion: "5009066457"
    uid: d801301f-6176-4547-bad0-289181056a90
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vcellular.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /cellular_device/commission
          - /cellular_device/commission/unassigned/batch
          - /cellular_device/decommission
          - /cellular_device/list
          - /cellular_device/register_imei
          - /cellular_device/setup/batch
          - /cellular_device/unassigned/list
          - /cellular_device/update
          - /event
          - /event/list
          - /event/submit_pings
          - /internal/admin/cellular_device/decommission
          - /vcellular/ping
        unauthenticatedEndpoints:
          - /event/list/status
          - /ping
          - /vcellular/ping
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcellular/event
          - /vcellular/event/list
          - /vcellular/event/submit_pings
          - /vcellular/ping
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcellular/event
          - /vcellular/event/list
          - /vcellular/event/submit_pings
          - /vcellular/ping
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcellular/event
          - /vcellular/event/list
          - /vcellular/event/submit_pings
          - /vcellular/ping
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcellular/event
          - /vcellular/event/list
          - /vcellular/event/submit_pings
          - /vcellular/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vcellular
    namespace: vinfra
    resourceVersion: "5009066460"
    uid: aeb2fe72-3277-4405-a3ec-c3789c85ad42
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/status/update
          - /access_controller/update
          - /access_device/[0-9a-f-]{36}/config
          - /door/config/get
          - /door/event/send
          - /submit_current_time
        unauthenticatedEndpoints:
          - /access_controller/auth/init
          - /model/[\w\-. ]+/firmware_version/[\w\-. +%]+
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/status/update
          - /access_controller/update
          - /access_device/[0-9a-f-]{36}/config
          - /door/config/get
          - /door/event/send
          - /submit_current_time
        unauthenticatedEndpoints:
          - /access_controller/auth/init
          - /model/[\w\-. ]+/firmware_version/[\w\-. +%]+
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/status/update
          - /access_controller/update
          - /access_device/[0-9a-f-]{36}/config
          - /door/config/get
          - /door/event/send
          - /submit_current_time
        unauthenticatedEndpoints:
          - /access_controller/auth/init
          - /model/[\w\-. ]+/firmware_version/[\w\-. +%]+
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/status/update
          - /access_controller/update
          - /access_device/[0-9a-f-]{36}/config
          - /door/config/get
          - /door/event/send
          - /submit_current_time
        unauthenticatedEndpoints:
          - /access_controller/auth/init
          - /model/[\w\-. ]+/firmware_version/[\w\-. +%]+
      - host: access.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[0-9a-f-]{36}/alert_subscription
          - /[0-9a-f-]{36}/alert_subscriptions
          - /[0-9a-f-]{36}/config
          - /[0-9a-f-]{36}/keys
          - /[0-9a-f-]{36}/keys/[0-9a-f-]{36}
          - /access/v2/device/access_config/1
          - /access/v2/device/access_config/2
          - /access/v2/device/access_config/3
          - /access/v2/device/access_controller/config/get
          - /access/v2/device/access_controller/config_status/set
          - /access/v2/device/access_device/peripheral/metadata
          - /access/v2/device/config/1
          - /access/v2/device/config/2
          - /access/v2/device/device_information
          - /access/v2/device/device_io/[0-9a-f-]{36}/metadata
          - /access/v2/device/device_io/[0-9a-f-]{36}/tamper
          - /access/v2/device/door/[0-9a-f-]{36}/unlock
          - /access/v2/device/event/2
          - /access/v2/device/schedule_config/1
          - /access/v2/device/verkada_nfc/desfire_key
          - /access/v2/device/verkada_nfc/desfire_key/2
          - /access/v2/device/verkada_nfc/master_key
          - /access/v2/user/access_controller/[0-9a-f-]{36}/config_status/get
          - /access/v2/user/access_controller/[0-9a-f-]{36}/mode
          - /access/v2/user/access_controller/[0-9a-f-]{36}/reader_peripherals/status
          - /access/v2/user/access_controller/assign_hub
          - /access/v2/user/access_controller/reader_peripherals/statuses
          - /access/v2/user/access_controller/switch_mode
          - /access/v2/user/access_controllers
          - /access/v2/user/access_device/[0-9a-f-]{36}/manual_behavior
          - /access/v2/user/access_device/[0-9a-f-]{36}/manual_behavior/[0-9a-f-]{36}
          - /access/v2/user/access_device/[0-9a-f-]{36}/reboot
          - /access/v2/user/access_device/commission_unassigned_bulk
          - /access/v2/user/access_device/setup
          - /access/v2/user/allegion_engage/site/[0-9a-f-]{36}/sync
          - /access/v2/user/areas
          - /access/v2/user/areas/[0-9a-f-]{36}
          - /access/v2/user/aux_inputs
          - /access/v2/user/aux_output/[0-9a-f-]{36}
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario/[0-9a-f-]{36}
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario/[0-9a-f-]{36}/dismiss
          - /access/v2/user/aux_output/[0-9a-f-]{36}/dismiss
          - /access/v2/user/aux_output/[0-9a-f-]{36}/peer_devices
          - /access/v2/user/aux_output/status
          - /access/v2/user/aux_outputs
          - /access/v2/user/credentials/export_csv
          - /access/v2/user/credentials/import_csv
          - /access/v2/user/demo
          - /access/v2/user/door/[0-9a-f-]{36}/privacy_groups
          - /access/v2/user/door/[0-9a-f-]{36}/verify_site
          - /access/v2/user/doors
          - /access/v2/user/doors/[0-9a-f-]{36}
          - /access/v2/user/elevator
          - /access/v2/user/elevator/[0-9a-f-]{36}
          - /access/v2/user/elevator/[0-9a-f-]{36}/nearby_cameras
          - /access/v2/user/elevators
          - /access/v2/user/license_plate
          - /access/v2/user/license_plate/[\w\.\-]+
          - /access/v2/user/license_plate/delete
          - /access/v2/user/live_links
          - /access/v2/user/live_links/[0-9a-f-]{36}
          - /access/v2/user/lockdowns
          - /access/v2/user/lockdowns/[0-9a-f-]{36}
          - /access/v2/user/mfa_code
          - /access/v2/user/mfa_code/delete
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controller/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controller/[0-9a-f-]{36}/reader_peripheral/delete
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controllers
          - /access/v2/user/organization/[0-9a-f-]{36}/auto_expire_exempt_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/badge_template
          - /access/v2/user/organization/[0-9a-f-]{36}/badge_template/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/bulk_set_auto_expire_exempt_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/entity_events/[0-9a-f-]{36}/possible_cards
          - /access/v2/user/organization/[0-9a-f-]{36}/images
          - /access/v2/user/organization/[0-9a-f-]{36}/images/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/images/[0-9a-f-]{36}\.png
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/preview
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/csv
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/end
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/event
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/event/latest
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report/[0-9a-f-]{36}/send
          - /access/v2/user/organization/[0-9a-f-]{36}/user_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/users/stats/group_member_count
          - /access/v2/user/organization/door_access_report
          - /access/v2/user/organization/door_access_report/export
          - /access/v2/user/organization/mobile_nfc
          - /access/v2/user/pass/android_nfc
          - /access/v2/user/pass/unlockables/1
          - /access/v2/user/pass_app_issue
          - /access/v2/user/roles
          - /access/v2/user/roles/modify
          - /access/v2/user/schedules
          - /access/v2/user/schedules/[0-9a-f-]{36}
          - /access/v2/user/users/[0-9a-f-]{36}/mfa_codes
          - /access/v2/user/users/bulk
          - /access/v2/user/users/invite_guest
          - /access/v2/user/users/search
          - /access/v2/user/virtual_device/[0-9a-f-]{36}/toggle
          - /access/v2/user/virtual_device/[0-9a-f-]{36}/unlock
          - /access/v2/user/visit_types
          - /access/v2/user/visit_types/[0-9a-f-]{36}
          - /access/v2/user/visitor/[0-9a-f-]{36}/checkout
          - /access/v2/user/visitor/[0-9a-f-]{36}/visits
          - /access/v2/user/visitor/credentials/delete
          - /access/v2/user/visits
          - /access/v2/user/visits/[0-9a-f-]{36}
          - /access/v2/user/visits/count
          - /access/v2/user/visits/possible_cards
          - /access/v2/user/wireless_hub/bulk_assign_wireless_locks
          - /access/v2/user/wireless_hub/remove_connections
          - /access/v2/user/wireless_hubs
          - /access/v2/user/wireless_lock/remove_connections
          - /access/v2/user/wireless_locks
          - /access/v2/users/organization/events/time
          - /access_controller/[0-9a-f-]{36}/aux_input
          - /access_controller/[0-9a-f-]{36}/aux_output
          - /access_controller/[0-9a-f-]{36}/manual_behavior/[0-9a-f-]{36}/device_io
          - /access_controller/aux_was_pressed
          - /access_controller/ble_stat/update
          - /access_controller/config/get
          - /access_controller/config/set
          - /access_controller/edit
          - /access_controller/event/history
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/health/update
          - /access_controller/identify
          - /access_controller/move_to_site
          - /access_controller/p2p_stat/update
          - /access_controller/reader_peripheral
          - /access_controller/reader_peripheral/clear
          - /access_controller/reader_stat/update
          - /access_controller/reboot
          - /access_controller/status
          - /access_controller/status/update
          - /access_controller/update
          - /access_controller/version
          - /access_controller/wireless_lock_stat/update
          - /access_device/[0-9a-f-]{36}/config
          - /access_device/[0-9a-f-]{36}/event
          - /access_device/commission
          - /access_device/decommission
          - /access_methods/get
          - /access_methods/modify
          - /action/[0-9a-f-]{36}
          - /alert_subscription/[0-9a-f-]{36}
          - /auth/assert
          - /auth/assert/permissions
          - /aux_input/[0-9a-f-]{36}
          - /aux_input/[0-9a-f-]{36}/action
          - /aux_input/[0-9a-f-]{36}/device_io
          - /aux_input/[0-9a-f-]{36}/lockdown_peer_devices
          - /aux_input/[0-9a-f-]{36}/peer_devices
          - /aux_input/set_nearby_cameras
          - /aux_output/[0-9a-f-]{36}
          - /debug-endpoint-for-error-capture-testing
          - /device_io/[0-9a-f-]{36}
          - /door/[0-9a-f-]{36}/device_io
          - /door/[0-9a-f-]{36}/display_image/[\w\-. +%]+
          - /door/[0-9a-f-]{36}/display_image/[\w\-. +%]+/image\.jpg
          - /door/[0-9a-f-]{36}/display_image/image\.jpg
          - /door/[0-9a-f-]{36}/metrics
          - /door/access_credentials
          - /door/config/get
          - /door/config/set
          - /door/convert
          - /door/create
          - /door/delete
          - /door/direct-permissions/list
          - /door/event/
          - /door/event/history
          - /door/event/latest
          - /door/event/send
          - /door/event/status
          - /door/move
          - /door/set_door_state
          - /door/set_metadata
          - /door/set_nearby_cameras
          - /door/stats
          - /door/unlock
          - /door/unlock/modify
          - /door/unlockable/list
          - /door/user_groups/bulk_grant_access
          - /door/user_groups/bulk_revoke_access
          - /door/user_groups/grant_access
          - /door/user_groups/list
          - /door/user_groups/revoke_access
          - /door/users/list
          - /elevator/[0-9a-f-]{36}/device_io
          - /get_entities
          - /get_users
          - /organization/config/get
          - /organization/config/set
          - /organizations/[0-9a-f-]{36}/lockdowns
          - /organizations/[0-9a-f-]{36}/lockdowns/release
          - /organizations/[0-9a-f-]{36}/lockdowns/trigger
          - /organizations/[0-9a-f-]{36}/schedules
          - /organizations/[0-9a-f-]{36}/schedules/[0-9a-f-]{36}
          - /pass-app/metrics
          - /submit_current_time
          - /swordfish/access/v2/user/allegion_engage/site
          - /swordfish/access/v2/user/allegion_engage/site/[0-9a-f-]{36}/invite
          - /swordfish/access/v2/user/allegion_engage/site/[0-9a-f-]{36}/sync
          - /user/[0-9a-f-]{36}
          - /user/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /user/access_card/activation_state
          - /user/access_card/active
          - /user/access_card/add
          - /user/access_card/delete
          - /user/access_card/get
          - /user/access_card/scan
          - /user/access_controller/[0-9a-f-]{36}/reader_peripheral/[A-Z0-9-]{14}
          - /user/code/delete
          - /user/code/set
          - /user/door/config/get
          - /user/email
          - /user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /user/photos/upload
          - /user/roles
          - /user_groups/add_group
          - /user_groups/add_user
          - /user_groups/bulk_add_users
          - /user_groups/bulk_remove_users
          - /user_groups/doors/list
          - /user_groups/get
          - /user_groups/get_group_membership
          - /user_groups/remove_group
          - /user_groups/remove_user
          - /user_groups/scim_groups
          - /user_groups/update_group_name
          - /user_roles/modify
          - /users/async_upload_csv
          - /users/async_upload_csv/status/
          - /users/create
          - /users/delete
          - /users/export_csv
          - /users/get_csv_template
          - /users/upload_csv
          - /users/upload_csv/pre_validate
          - /v1/device/information
        unauthenticatedEndpoints:
          - /\.well-known/apple-app-site-association
          - /access/v2/unlock/[0-9a-f-]{36}
          - /access/v2/user/linked_accounts
          - /access/v2/user/session_accounts
          - /access/v2/user/unlock_link/[0-9a-f-]{36}/exchange
          - /access/v2/webhook/ironclad/apple_wallet_notify
          - /access_card/qr_code\.jpg
          - /access_controller/auth/init
          - /internal/door/event/send
          - /internal/users/async_upload_csv/process_chunk
          - /internal/users/async_upload_csv/status/
          - /internal/users/async_upload_csv/status/[0-9a-f-]{36}
          - /internal/users/async_upload_csv/status/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /logs/relay-vaccess-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/4505653327888384/store/
          - /logs/relay-vaccess-sentry/api/5549229/store/
          - /model/[\w\-. ]+/firmware_version/[a-zA-Z0-9-:_.]+
          - /pass-app/magic-link
          - /ping
          - /swordfish/lock/Config
          - /swordfish/lock/alert
          - /swordfish/lock/audit
          - /swordfish/lock/certificates/current
          - /swordfish/lock/db/[0-9]+
          - /swordfish/lock/newCA
          - /swordfish/ping
          - /verkada-access-firmware\.s3\.amazonaws\.com/((.+)\/)*([^\/]+)
          - /verkada-access-firmware\.s3\.us-west-2\.amazonaws\.com/((.+)\/)*([^\/]+)
      - host: vcerberus.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[0-9a-f-]{36}/alert_subscription
          - /[0-9a-f-]{36}/alert_subscriptions
          - /[0-9a-f-]{36}/config
          - /[0-9a-f-]{36}/keys
          - /[0-9a-f-]{36}/keys/[0-9a-f-]{36}
          - /access/v2/device/access_config/1
          - /access/v2/device/access_config/2
          - /access/v2/device/access_config/3
          - /access/v2/device/access_controller/config/get
          - /access/v2/device/access_controller/config_status/set
          - /access/v2/device/access_device/peripheral/metadata
          - /access/v2/device/config/1
          - /access/v2/device/config/2
          - /access/v2/device/device_information
          - /access/v2/device/device_io/[0-9a-f-]{36}/metadata
          - /access/v2/device/device_io/[0-9a-f-]{36}/tamper
          - /access/v2/device/door/[0-9a-f-]{36}/unlock
          - /access/v2/device/event/2
          - /access/v2/device/schedule_config/1
          - /access/v2/device/verkada_nfc/desfire_key
          - /access/v2/device/verkada_nfc/desfire_key/2
          - /access/v2/device/verkada_nfc/master_key
          - /access/v2/user/access_controller/[0-9a-f-]{36}/config_status/get
          - /access/v2/user/access_controller/[0-9a-f-]{36}/mode
          - /access/v2/user/access_controller/[0-9a-f-]{36}/reader_peripherals/status
          - /access/v2/user/access_controller/assign_hub
          - /access/v2/user/access_controller/reader_peripherals/statuses
          - /access/v2/user/access_controller/switch_mode
          - /access/v2/user/access_controllers
          - /access/v2/user/access_device/[0-9a-f-]{36}/manual_behavior
          - /access/v2/user/access_device/[0-9a-f-]{36}/manual_behavior/[0-9a-f-]{36}
          - /access/v2/user/access_device/[0-9a-f-]{36}/reboot
          - /access/v2/user/access_device/commission_unassigned_bulk
          - /access/v2/user/access_device/setup
          - /access/v2/user/allegion_engage/site/[0-9a-f-]{36}/sync
          - /access/v2/user/areas
          - /access/v2/user/areas/[0-9a-f-]{36}
          - /access/v2/user/aux_inputs
          - /access/v2/user/aux_output/[0-9a-f-]{36}
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario/[0-9a-f-]{36}
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario/[0-9a-f-]{36}/dismiss
          - /access/v2/user/aux_output/[0-9a-f-]{36}/dismiss
          - /access/v2/user/aux_output/[0-9a-f-]{36}/peer_devices
          - /access/v2/user/aux_output/status
          - /access/v2/user/aux_outputs
          - /access/v2/user/credentials/export_csv
          - /access/v2/user/credentials/import_csv
          - /access/v2/user/demo
          - /access/v2/user/door/[0-9a-f-]{36}/privacy_groups
          - /access/v2/user/door/[0-9a-f-]{36}/verify_site
          - /access/v2/user/doors
          - /access/v2/user/doors/[0-9a-f-]{36}
          - /access/v2/user/elevator
          - /access/v2/user/elevator/[0-9a-f-]{36}
          - /access/v2/user/elevator/[0-9a-f-]{36}/nearby_cameras
          - /access/v2/user/elevators
          - /access/v2/user/license_plate
          - /access/v2/user/license_plate/[\w\.\-]+
          - /access/v2/user/license_plate/delete
          - /access/v2/user/live_links
          - /access/v2/user/live_links/[0-9a-f-]{36}
          - /access/v2/user/lockdowns
          - /access/v2/user/lockdowns/[0-9a-f-]{36}
          - /access/v2/user/mfa_code
          - /access/v2/user/mfa_code/delete
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controller/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controller/[0-9a-f-]{36}/reader_peripheral/delete
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controllers
          - /access/v2/user/organization/[0-9a-f-]{36}/auto_expire_exempt_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/badge_template
          - /access/v2/user/organization/[0-9a-f-]{36}/badge_template/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/bulk_set_auto_expire_exempt_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/entity_events/[0-9a-f-]{36}/possible_cards
          - /access/v2/user/organization/[0-9a-f-]{36}/images
          - /access/v2/user/organization/[0-9a-f-]{36}/images/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/images/[0-9a-f-]{36}\.png
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/preview
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/csv
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/end
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/event
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/event/latest
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report/[0-9a-f-]{36}/send
          - /access/v2/user/organization/[0-9a-f-]{36}/user_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/users/stats/group_member_count
          - /access/v2/user/organization/door_access_report
          - /access/v2/user/organization/door_access_report/export
          - /access/v2/user/organization/mobile_nfc
          - /access/v2/user/pass/android_nfc
          - /access/v2/user/pass/unlockables/1
          - /access/v2/user/pass_app_issue
          - /access/v2/user/roles
          - /access/v2/user/roles/modify
          - /access/v2/user/schedules
          - /access/v2/user/schedules/[0-9a-f-]{36}
          - /access/v2/user/users/[0-9a-f-]{36}/mfa_codes
          - /access/v2/user/users/bulk
          - /access/v2/user/users/invite_guest
          - /access/v2/user/users/search
          - /access/v2/user/virtual_device/[0-9a-f-]{36}/toggle
          - /access/v2/user/virtual_device/[0-9a-f-]{36}/unlock
          - /access/v2/user/visit_types
          - /access/v2/user/visit_types/[0-9a-f-]{36}
          - /access/v2/user/visitor/[0-9a-f-]{36}/checkout
          - /access/v2/user/visitor/[0-9a-f-]{36}/visits
          - /access/v2/user/visitor/credentials/delete
          - /access/v2/user/visits
          - /access/v2/user/visits/[0-9a-f-]{36}
          - /access/v2/user/visits/count
          - /access/v2/user/visits/possible_cards
          - /access/v2/user/wireless_hub/bulk_assign_wireless_locks
          - /access/v2/user/wireless_hub/remove_connections
          - /access/v2/user/wireless_hubs
          - /access/v2/user/wireless_lock/remove_connections
          - /access/v2/user/wireless_locks
          - /access/v2/users/organization/events/time
          - /access_controller/[0-9a-f-]{36}/aux_input
          - /access_controller/[0-9a-f-]{36}/aux_output
          - /access_controller/[0-9a-f-]{36}/manual_behavior/[0-9a-f-]{36}/device_io
          - /access_controller/aux_was_pressed
          - /access_controller/ble_stat/update
          - /access_controller/config/get
          - /access_controller/config/set
          - /access_controller/edit
          - /access_controller/event/history
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/health/update
          - /access_controller/identify
          - /access_controller/move_to_site
          - /access_controller/p2p_stat/update
          - /access_controller/reader_peripheral
          - /access_controller/reader_peripheral/clear
          - /access_controller/reader_stat/update
          - /access_controller/reboot
          - /access_controller/status
          - /access_controller/status/update
          - /access_controller/update
          - /access_controller/version
          - /access_controller/wireless_lock_stat/update
          - /access_device/[0-9a-f-]{36}/config
          - /access_device/[0-9a-f-]{36}/event
          - /access_device/commission
          - /access_device/decommission
          - /access_methods/get
          - /access_methods/modify
          - /action/[0-9a-f-]{36}
          - /alert_subscription/[0-9a-f-]{36}
          - /auth/assert
          - /auth/assert/permissions
          - /aux_input/[0-9a-f-]{36}
          - /aux_input/[0-9a-f-]{36}/action
          - /aux_input/[0-9a-f-]{36}/device_io
          - /aux_input/[0-9a-f-]{36}/lockdown_peer_devices
          - /aux_input/[0-9a-f-]{36}/peer_devices
          - /aux_input/set_nearby_cameras
          - /aux_output/[0-9a-f-]{36}
          - /debug-endpoint-for-error-capture-testing
          - /device_io/[0-9a-f-]{36}
          - /door/[0-9a-f-]{36}/device_io
          - /door/[0-9a-f-]{36}/display_image/[\w\-. +%]+
          - /door/[0-9a-f-]{36}/display_image/[\w\-. +%]+/image\.jpg
          - /door/[0-9a-f-]{36}/display_image/image\.jpg
          - /door/[0-9a-f-]{36}/metrics
          - /door/access_credentials
          - /door/config/get
          - /door/config/set
          - /door/convert
          - /door/create
          - /door/delete
          - /door/direct-permissions/list
          - /door/event/
          - /door/event/history
          - /door/event/latest
          - /door/event/send
          - /door/event/status
          - /door/move
          - /door/set_door_state
          - /door/set_metadata
          - /door/set_nearby_cameras
          - /door/stats
          - /door/unlock
          - /door/unlock/modify
          - /door/unlockable/list
          - /door/user_groups/bulk_grant_access
          - /door/user_groups/bulk_revoke_access
          - /door/user_groups/grant_access
          - /door/user_groups/list
          - /door/user_groups/revoke_access
          - /door/users/list
          - /elevator/[0-9a-f-]{36}/device_io
          - /get_entities
          - /get_users
          - /organization/config/get
          - /organization/config/set
          - /organizations/[0-9a-f-]{36}/lockdowns
          - /organizations/[0-9a-f-]{36}/lockdowns/release
          - /organizations/[0-9a-f-]{36}/lockdowns/trigger
          - /organizations/[0-9a-f-]{36}/schedules
          - /organizations/[0-9a-f-]{36}/schedules/[0-9a-f-]{36}
          - /pass-app/metrics
          - /submit_current_time
          - /swordfish/access/v2/user/allegion_engage/site
          - /swordfish/access/v2/user/allegion_engage/site/[0-9a-f-]{36}/invite
          - /swordfish/access/v2/user/allegion_engage/site/[0-9a-f-]{36}/sync
          - /user/[0-9a-f-]{36}
          - /user/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /user/access_card/activation_state
          - /user/access_card/active
          - /user/access_card/add
          - /user/access_card/delete
          - /user/access_card/get
          - /user/access_card/scan
          - /user/access_controller/[0-9a-f-]{36}/reader_peripheral/[A-Z0-9-]{14}
          - /user/code/delete
          - /user/code/set
          - /user/door/config/get
          - /user/email
          - /user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /user/photos/upload
          - /user/roles
          - /user_groups/add_group
          - /user_groups/add_user
          - /user_groups/bulk_add_users
          - /user_groups/bulk_remove_users
          - /user_groups/doors/list
          - /user_groups/get
          - /user_groups/get_group_membership
          - /user_groups/remove_group
          - /user_groups/remove_user
          - /user_groups/scim_groups
          - /user_groups/update_group_name
          - /user_roles/modify
          - /users/async_upload_csv
          - /users/async_upload_csv/status/
          - /users/create
          - /users/delete
          - /users/export_csv
          - /users/get_csv_template
          - /users/upload_csv
          - /users/upload_csv/pre_validate
          - /v1/device/information
        unauthenticatedEndpoints:
          - /\.well-known/apple-app-site-association
          - /access/v2/unlock/[0-9a-f-]{36}
          - /access/v2/user/linked_accounts
          - /access/v2/user/session_accounts
          - /access/v2/user/unlock_link/[0-9a-f-]{36}/exchange
          - /access/v2/webhook/ironclad/apple_wallet_notify
          - /access_card/qr_code\.jpg
          - /access_controller/auth/init
          - /internal/door/event/send
          - /internal/users/async_upload_csv/process_chunk
          - /internal/users/async_upload_csv/status/
          - /internal/users/async_upload_csv/status/[0-9a-f-]{36}
          - /internal/users/async_upload_csv/status/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /logs/relay-vaccess-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/4505653327888384/store/
          - /logs/relay-vaccess-sentry/api/5549229/store/
          - /model/[\w\-. ]+/firmware_version/[a-zA-Z0-9-:_.]+
          - /pass-app/magic-link
          - /ping
          - /swordfish/lock/Config
          - /swordfish/lock/alert
          - /swordfish/lock/audit
          - /swordfish/lock/certificates/current
          - /swordfish/lock/db/[0-9]+
          - /swordfish/lock/newCA
          - /swordfish/ping
          - /verkada-access-firmware\.s3\.amazonaws\.com/((.+)\/)*([^\/]+)
          - /verkada-access-firmware\.s3\.us-west-2\.amazonaws\.com/((.+)\/)*([^\/]+)
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vcerberus
    namespace: vinfra
    resourceVersion: "5009066465"
    uid: ed8040cd-e3fa-44d1-8e08-f1ae99a620ff
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcity/cameras/invite_to_share
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/accept
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/inbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/outbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/pending
          - /vcity/org/[0-9a-f-]{36}/sharing_organizations
          - /vcity/sharing/cameras/revoke_by_owner
          - /vcity/sharing/cameras/revoke_by_viewer
          - /vcity/sharing/set_auth
          - /vcity/sharing/token
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcity/cameras/invite_to_share
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/accept
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/inbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/outbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/pending
          - /vcity/org/[0-9a-f-]{36}/sharing_organizations
          - /vcity/sharing/cameras/revoke_by_owner
          - /vcity/sharing/cameras/revoke_by_viewer
          - /vcity/sharing/set_auth
          - /vcity/sharing/token
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcity/cameras/invite_to_share
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/accept
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/inbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/outbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/pending
          - /vcity/org/[0-9a-f-]{36}/sharing_organizations
          - /vcity/sharing/cameras/revoke_by_owner
          - /vcity/sharing/cameras/revoke_by_viewer
          - /vcity/sharing/set_auth
          - /vcity/sharing/token
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcity/cameras/invite_to_share
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/accept
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/inbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/outbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/pending
          - /vcity/org/[0-9a-f-]{36}/sharing_organizations
          - /vcity/sharing/cameras/revoke_by_owner
          - /vcity/sharing/cameras/revoke_by_viewer
          - /vcity/sharing/set_auth
          - /vcity/sharing/token
      - host: vcity.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /internal/cameras/invite_to_share
          - /internal/org/[0-9a-f-]{36}/sharing/cameras/accept
          - /internal/org/[0-9a-f-]{36}/sharing/cameras/inbound
          - /internal/org/[0-9a-f-]{36}/sharing/cameras/outbound
          - /internal/org/[0-9a-f-]{36}/sharing/cameras/pending
          - /internal/org/[0-9a-f-]{36}/sharing_organizations
          - /internal/sharing/cameras/revoke
          - /internal/sharing/cross_org_token
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-10T20:52:39Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vcity
    namespace: vinfra
    resourceVersion: "5009066467"
    uid: 7d64497a-2440-4b34-8838-78408564a5e7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/check-in
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/stable
          - /vconductor/device_instance/auth/check
          - /vconductor/device_instance/check-in
          - /vconductor/device_instance/network_address
          - /vconductor/global/device_instance/auth/check
          - /vconductor/key/add_public_key
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update/[0-9a-f-]{36}/status
          - /vconductor/software_distribution/update_config/get
          - /vconductor/software_distribution/upload/path/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/[0-9a-f-]{36}/network_address
          - /device_instance/auth/enroll
          - /device_instance/auth/init
          - /device_instance/auth/token
          - /device_instance/auth/verify_hmac
          - /device_instance/commission
          - /device_instance/decommission
          - /device_instance/details
          - /device_instance/network_addresses/retrieve
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/upload/url/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/device_instance/auth/enroll
          - /vconductor/device_instance/auth/init
          - /vconductor/device_instance/auth/token
          - /vconductor/device_instance/auth/verify_hmac
          - /vconductor/ping
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/check-in
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/stable
          - /vconductor/device_instance/auth/check
          - /vconductor/device_instance/check-in
          - /vconductor/device_instance/network_address
          - /vconductor/global/device_instance/auth/check
          - /vconductor/key/add_public_key
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update/[0-9a-f-]{36}/status
          - /vconductor/software_distribution/update_config/get
          - /vconductor/software_distribution/upload/path/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/[0-9a-f-]{36}/network_address
          - /device_instance/auth/enroll
          - /device_instance/auth/init
          - /device_instance/auth/token
          - /device_instance/auth/verify_hmac
          - /device_instance/commission
          - /device_instance/decommission
          - /device_instance/details
          - /device_instance/network_addresses/retrieve
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/upload/url/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/device_instance/auth/enroll
          - /vconductor/device_instance/auth/init
          - /vconductor/device_instance/auth/token
          - /vconductor/device_instance/auth/verify_hmac
          - /vconductor/ping
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/check-in
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/stable
          - /vconductor/device_instance/auth/check
          - /vconductor/device_instance/check-in
          - /vconductor/device_instance/network_address
          - /vconductor/global/device_instance/auth/check
          - /vconductor/key/add_public_key
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update/[0-9a-f-]{36}/status
          - /vconductor/software_distribution/update_config/get
          - /vconductor/software_distribution/upload/path/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/[0-9a-f-]{36}/network_address
          - /device_instance/auth/enroll
          - /device_instance/auth/init
          - /device_instance/auth/token
          - /device_instance/auth/verify_hmac
          - /device_instance/commission
          - /device_instance/decommission
          - /device_instance/details
          - /device_instance/network_addresses/retrieve
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/upload/url/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/device_instance/auth/enroll
          - /vconductor/device_instance/auth/init
          - /vconductor/device_instance/auth/token
          - /vconductor/device_instance/auth/verify_hmac
          - /vconductor/ping
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/check-in
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/stable
          - /vconductor/device_instance/auth/check
          - /vconductor/device_instance/check-in
          - /vconductor/device_instance/network_address
          - /vconductor/global/device_instance/auth/check
          - /vconductor/key/add_public_key
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update/[0-9a-f-]{36}/status
          - /vconductor/software_distribution/update_config/get
          - /vconductor/software_distribution/upload/path/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/[0-9a-f-]{36}/network_address
          - /device_instance/auth/enroll
          - /device_instance/auth/init
          - /device_instance/auth/token
          - /device_instance/auth/verify_hmac
          - /device_instance/commission
          - /device_instance/decommission
          - /device_instance/details
          - /device_instance/network_addresses/retrieve
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/upload/url/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/device_instance/auth/enroll
          - /vconductor/device_instance/auth/init
          - /vconductor/device_instance/auth/token
          - /vconductor/device_instance/auth/verify_hmac
          - /vconductor/ping
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: access.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/details
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/device_instance/auth/check
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update_config/get
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/auth/init
          - /device_instance/commission
          - /device_instance/decommission
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/device_instance/auth/init
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: vcerberus.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/details
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/device_instance/auth/check
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update_config/get
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/auth/init
          - /device_instance/commission
          - /device_instance/decommission
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/device_instance/auth/init
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: vconductor.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /command/device/find
          - /command/device/list
          - /command/device/metadata
          - /command/device/search
          - /device_instance/auth/check
          - /device_instance/check-in
          - /device_instance/network_address
          - /global/device_instance/auth/check
          - /internal/admin/device/metadata
          - /internal/admin/device/update
          - /internal/admin/device_instance/decommission
          - /internal_user/key/public_keys
          - /key/add_public_key
          - /key/create_keypair
          - /org/[0-9a-f-]{36}/devices
          - /org/[0-9a-f-]{36}/devices/assign
          - /org/[0-9a-f-]{36}/unassigned_devices
          - /regional/device_instance/auth/check
          - /serial_number/batch/validate
          - /serial_number/create
          - /serial_number/validate
          - /software_distribution/clear_download_loop_events
          - /software_distribution/device_list_latest
          - /software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/latest/[\w\-. ]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/stable
          - /software_distribution/latest_v2
          - /software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /software_distribution/site/[0-9a-f-]{36}/update_schedule
          - /software_distribution/update/[0-9a-f-]{36}/status
          - /software_distribution/update_config/get
          - /software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/command/device/batch/commission
          - /vconductor/command/device/metadata
          - /vconductor/device_instance/auth/check
          - /vconductor/device_instance/check-in
          - /vconductor/device_instance/network_address
          - /vconductor/key/add_public_key
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update/[0-9a-f-]{36}/status
          - /vconductor/software_distribution/update_config/get
          - /vconductor/software_distribution/upload/path/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/auth/enroll
          - /device_instance/auth/init
          - /device_instance/auth/token
          - /device_instance/auth/verify_hmac
          - /device_instance/commission
          - /device_instance/decommission
          - /device_instance/details
          - /key/bulk/set_rotate_after
          - /key/public_keys
          - /key/sign
          - /ping
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /software_distribution/site/[0-9a-f-]{36}/update_schedule
          - /software_distribution/upload/[\w\-. ]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/upload/[\w\-. ]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/upload/url/[\w\-. ]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/device_instance/auth/enroll
          - /vconductor/device_instance/auth/init
          - /vconductor/device_instance/auth/token
          - /vconductor/device_instance/auth/verify_hmac
          - /vconductor/ping
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vconductor
    namespace: vinfra
    resourceVersion: "5009066472"
    uid: 2b74755b-b756-4da9-8e46-c43af6885cc8
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vcorgi.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[0-9a-f-]{36}/[0-9a-f-]{36}/agreements
          - /[0-9a-f-]{36}/[0-9a-f-]{36}/sign_agreement
          - /[0-9a-f-]{36}/agreements
          - /[0-9a-f-]{36}/device/agreements
          - /[0-9a-f-]{36}/key_contact
          - /[0-9a-f-]{36}/key_contact/BILLING
          - /[0-9a-f-]{36}/key_contact/PRIMARY
          - /[0-9a-f-]{36}/key_contact/SECURITY
          - /[0-9a-f-]{36}/key_contacts
          - /[0-9a-f-]{36}/notification_contacts
          - /[0-9a-f-]{36}/notification_contacts/edit
          - /[0-9a-f-]{36}/security_checklist
          - /[0-9a-f-]{36}/sign_agreement
          - /[0-9a-f-]{36}/verify_data_deletion
          - /[0-9a-f-]{36}/video_sharing_agreement
          - /device/recommended_default_settings/apply
          - /device/recommended_default_settings/device_cache
          - /device/recommended_default_settings/get
          - /operations/list
          - /org/[0-9a-f-]{36}/end_customers
          - /org/[0-9a-f-]{36}/feature
          - /org/[0-9a-f-]{36}/features
          - /org/[0-9a-f-]{36}/features/compliance_report
          - /org/[0-9a-f-]{36}/features/removal_requests
          - /org/[0-9a-f-]{36}/features/removal_requests/approve
          - /org/[0-9a-f-]{36}/features/removal_requests/cancel
          - /org/[0-9a-f-]{36}/features/removal_requests/resend
          - /org/[0-9a-f-]{36}/is_partner
          - /org/[0-9a-f-]{36}/oidc_provider
          - /org/[0-9a-f-]{36}/oidc_provider/verify
          - /org/[0-9a-f-]{36}/partner
          - /org/[0-9a-f-]{36}/partner_token
          - /org/[0-9a-f-]{36}/partners
          - /org/[0-9a-f-]{36}/privacy_disclosure
          - /org/[0-9a-f-]{36}/privacy_disclosure/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/privacy_disclosure/[0-9a-f-]{36}/logo
          - /org/[0-9a-f-]{36}/privacy_disclosure/logo
          - /org/[0-9a-f-]{36}/privacy_disclosures
          - /org/[0-9a-f-]{36}/reason_code
          - /org/[0-9a-f-]{36}/salesforce_account
          - /org/[0-9a-f-]{36}/site_location/[0-9a-f-]{36}/site_project
          - /org/[0-9a-f-]{36}/site_planner/preferences
          - /org/[0-9a-f-]{36}/site_planner/salesforce/check
          - /org/[0-9a-f-]{36}/site_planner/salesforce/login
          - /org/[0-9a-f-]{36}/site_planner/salesforce/opportunity
          - /org/[0-9a-f-]{36}/site_planner/salesforce/opportunity/[\w\.\-]+
          - /org/[0-9a-f-]{36}/site_planner/site_location/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/[0-9a-f-]{36}/upload
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/copy
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/delete
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/live_link
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/live_link/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/live_links
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/permissions
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/resource
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/resource/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/save
          - /org/[0-9a-f-]{36}/site_project/create
          - /org/[0-9a-f-]{36}/site_project/list
          - /org/[0-9a-f-]{36}/user_inactive_deactivate_period
          - /org/[0-9a-f-]{36}/users/delete
          - /org/support_cases
          - /site_planner/site_location
          - /site_planner/site_location/[0-9a-f-]{36}
          - /site_planner/site_location/list
          - /site_planner/site_plan
          - /site_planner/site_plan/[0-9a-f-]{36}
          - /user/email/preferences
          - /v2/org/[0-9a-f-]{36}/privacy_disclosure
          - /v2/org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}
          - /v2/org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/copy
          - /v2/org/[0-9a-f-]{36}/site_project/create
          - /v2/org/[0-9a-f-]{36}/site_project/list
        unauthenticatedEndpoints:
          - /login/oidc
          - /ping
          - /public/oidc_provider
          - /public/privacy_disclosure
          - /site_planner/live_link/[0-9a-f-]{36}/redeem
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vcorgi
    namespace: vinfra
    resourceVersion: "5009066475"
    uid: a8ccdb10-81bb-406d-b3e4-163a0f40bf10
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdashboard.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/hyperzoom/get
          - /camera/hyperzoom/list
          - /device/line_crossing/get
          - /device/line_crossing/update
          - /device/occupancy_trends/get
          - /user/dashboard/aggregate
          - /user/dashboard/create
          - /user/dashboard/delete
          - /user/dashboard/get
          - /user/dashboard/list
          - /user/dashboard/update
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vdashboard
    namespace: vinfra
    resourceVersion: "5009066478"
    uid: f912500e-c2f9-4d7d-bad8-3a5e8edcb4ad
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdelete.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vdelete
    namespace: vinfra
    resourceVersion: "5009066480"
    uid: 4b083c34-326a-47b7-b94e-d2200cc7e0a4
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/config/get
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/config/get
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/config/get
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/config/get
      - host: vdeviceconfig.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/config/get
          - /user/camera/config/get
          - /user/camera/config/set
          - /user/camera/feature/get
          - /user/camera/feature/set
          - /user/org/config/get
          - /user/org/config/set
          - /user/org/feature/get
          - /user/org/feature/set
        unauthenticatedEndpoints:
          - /internal/camera/config/get
          - /internal/camera/config/set
          - /internal/model/config/set
          - /ping
      - host: vdeviceconfig.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /internal/camera/config/get
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vdeviceconfig
    namespace: vinfra
    resourceVersion: "5009066483"
    uid: 92b2eb1b-8ef0-45c9-86df-b127f321e5ff
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdevicemap.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
          - /vdevicemap/get_queryable
          - /vdevicemap/get_zipcodes
          - /vdevicemap/upload_queryable
          - /vdevicemap/upload_zipcodes
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vdevicemap
    namespace: vinfra
    resourceVersion: "5009066486"
    uid: 45f5dab5-839b-4dfc-901c-5fff558bf22a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vdevicestats/ws/stats
        unauthenticatedEndpoints:
          - /camera/stats/add
          - /vdevicestats/camera/stats/add
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vdevicestats/ws/stats
        unauthenticatedEndpoints:
          - /camera/stats/add
          - /vdevicestats/camera/stats/add
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vdevicestats/ws/stats
        unauthenticatedEndpoints:
          - /camera/stats/add
          - /vdevicestats/camera/stats/add
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vdevicestats/ws/stats
        unauthenticatedEndpoints:
          - /camera/stats/add
          - /vdevicestats/camera/stats/add
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vdevicestats
    namespace: vinfra
    resourceVersion: "5009066490"
    uid: 4feaf75e-8899-4738-85f1-8c00794877f7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdirectmail.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /directmail/configs
          - /directmail/leads
          - /directmail/sends
          - /directmail/sends/demos_created
          - /directmail/sends/this_week
          - /followup/accounts/
          - /followup/call
          - /followup/comment
          - /followup/email
          - /followup/google-auth
          - /followup/ignore
          - /followup/log
          - /followup/me
          - /followup/opportunities/
          - /followup/signals
          - /followup/unignore
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vdirectmail
    namespace: vinfra
    resourceVersion: "5009066493"
    uid: 27cf5f02-d111-4752-b417-9364fb411f26
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdoorman.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /ping
        unauthenticatedEndpoints:
          - /host_portal/magic_link/request
          - /outlook/guest/codes
          - /outlook/guest/login
          - /package/slack/[0-9a-f-]{36}/
          - /packages/teams/callback
          - /slack/[0-9a-f-]{36}
          - /teams/callback
          - /unauthed_feature_flags
      - host: mailroom.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/toggle
          - /access/org/[0-9a-f-]{36}/toggle
          - /access_control_migration/org/[0-9a-f-]{36}
          - /analytics/app
          - /analytics/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /analytics/package
          - /analytics_v2/org/[0-9a-f-]{36}
          - /analytics_v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /app-login/[0-9a-f-]{36}
          - /application_url/org_id/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/web
          - /approve_list/org/[0-9a-f-]{36}
          - /bg_check/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /bg_check/applicant/org/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /bg_check/cancel/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /bg_check/confirm/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/events/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/fetch/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /bg_check/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /botd/badge/[0-9a-f-]{36}
          - /botd/org/[0-9a-f-]{36}
          - /call_button/access_token/device/[0-9a-f-]{36}
          - /call_button/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /context_devices/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/config/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/logo_image/[0-9a-f-]{36}
          - /demo_visit_hyperzoom/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /demo_visit_video/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /device/[0-9a-f-]{36}
          - /device/[0-9a-f-]{36}/events
          - /device/[0-9a-f-]{36}/screenshot
          - /device/[0-9a-f-]{36}/stash_visit
          - /device/health
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/claim
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/identify
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/test_print
          - /device_init
          - /document/org/[0-9a-f-]{36}
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_fields
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_progress
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/convert
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_fields
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_progress
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_redirect
          - /echo
          - /event/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/resend
          - /event/by_day/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /face_match/device/[0-9a-f-]{36}
          - /face_match/device/[0-9a-f-]{36}/model
          - /face_match/device/[0-9a-f-]{36}/opt_in
          - /form/org/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/form/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/publish
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/form/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /guardian/temp/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /guardian/temp/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /guest/announcements/create
          - /guest/announcements/org/[0-9a-f-]{36}
          - /guest/licensing/overview/org/[0-9a-f-]{36}
          - /guest/org/[0-9a-f-]{36}/guest/[0-9a-f-]{36}/poi
          - /guest/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest/[0-9a-f-]{36}/photo
          - /guest/photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest/[0-9a-f-]{36}
          - /guest/trial/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/departments/org/[0-9a-f-]{36}
          - /healthcare/end_visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/[0-9a-f-]{36}/departments
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/verify
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/search
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /healthcare/partially_registered_visitor/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/partially_registered_visitor/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clear
          - /healthcare/partially_registered_visitor/qr_code/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/command/org/[0-9a-f-]{36}
          - /host/command/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/csv/org/[0-9a-f-]{36}
          - /host/csv/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/email/org/[0-9a-f-]{36}
          - /host/email/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/inherit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/all
          - /host/org/[0-9a-f-]{36}/delete
          - /host/org/[0-9a-f-]{36}/host/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/all
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/delete
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/host/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/host_id/[0-9a-f-]{36}/photo
          - /internal/pending_applicant_notifications
          - /internal/receptionist/notification_receptionist_manual_entry
          - /internal/receptionist/notification_receptionist_review
          - /internal/sync_command_hosts
          - /invite/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /invite_nfc/[0-9a-f-]{36}
          - /invited_guest/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /invited_guest/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/resend
          - /licensing/org/[0-9a-f-]{36}/guest_activity_last_30_days
          - /licensing/org/[0-9a-f-]{36}/package_site_activity_last_30_days
          - /licensing/org/[0-9a-f-]{36}/request_purchase/guest
          - /licensing/org/[0-9a-f-]{36}/request_purchase/mailroom
          - /licensing/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest
          - /licensing/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/mailroom
          - /licensing/overview/org/[0-9a-f-]{36}
          - /locale
          - /mailroom/licensing/overview/org/[0-9a-f-]{36}
          - /mailroom/trial/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/api_key_info
          - /meraki/org/[0-9a-f-]{36}/networks
          - /meraki/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/ssids
          - /multi_part_document/org/[0-9a-f-]{36}
          - /multi_part_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /multi_part_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/convert
          - /open_ended_questions/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type/[0-9a-f-]{36}
          - /open_ended_questions/org/[0-9a-f-]{36}/visitor_type/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/bootstrap
          - /org/[0-9a-f-]{36}/command/groups
          - /org/[0-9a-f-]{36}/deny_list/upload_csv
          - /org/[0-9a-f-]{36}/email_security
          - /org/[0-9a-f-]{36}/extend_trial
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/deny_list/[0-9a-f-]{36}/review
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/deny_list/upload_csv
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}/screenshot
          - /org/[0-9a-f-]{36}/trial
          - /org/assets/[0-9a-f-]{36}
          - /org/broken_link/[0-9a-f-]{36}
          - /org/preferences/[0-9a-f-]{36}
          - /org/shortname
          - /org/trial_devices/request/[0-9a-f-]{36}
          - /package/[0-9a-f-]{36}/image
          - /package/[0-9a-f-]{36}/reassign
          - /package/pickup/user/[0-9a-f-]{36}
          - /package_context_devices/device/[0-9a-f-]{36}
          - /package_context_devices/site/[0-9a-f-]{36}
          - /package_context_devices/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /package_media/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_org/extend_trial
          - /package_org/milestone/[0-9a-f-]{36}
          - /package_org/preferences/[0-9a-f-]{36}
          - /package_org/trial_devices/request/[0-9a-f-]{36}
          - /package_printer/[0-9a-f-]{36}
          - /package_printer/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/location
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/location/[0-9a-f-]{36}
          - /package_tag/site/[0-9a-f-]{36}
          - /packages/announcements/create
          - /packages/announcements/org/[0-9a-f-]{36}
          - /packages/get_name_from_address_dict/site/[0-9a-f-]{36}
          - /packages/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /packages/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/package/[0-9a-f-]{36}
          - /packages/package/[0-9a-f-]{36}
          - /packages/site/[0-9a-f-]{36}
          - /packages/site/[0-9a-f-]{36}/stats/graph
          - /packages/site/[0-9a-f-]{36}/stats/topline
          - /packages/site/[0-9a-f-]{36}/tracking_history
          - /packages/slack/[0-9a-f-]{36}/oauth_redirect
          - /packages/slack/[0-9a-f-]{36}/slack_active
          - /packages/slack/[0-9a-f-]{36}/uninstall_extention
          - /packages/slack/[0-9a-f-]{36}/workspace_logo
          - /packages/teams/org/[0-9a-f-]{36}/consent/redirect
          - /packages/teams/org/[0-9a-f-]{36}/info
          - /packages/teams/org/[0-9a-f-]{36}/uninstall
          - /packages/v2/site/[0-9a-f-]{36}
          - /packages_demo/package/site/[0-9a-f-]{36}
          - /patient/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient/[0-9a-f-]{36}
          - /patient_known_person/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient/[0-9a-f-]{36}
          - /patient_known_person/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient_known_person/[0-9a-f-]{36}
          - /patient_known_person/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient_known_person/[0-9a-f-]{36}
          - /permissions/org/[0-9a-f-]{36}
          - /printer/[0-9a-f-]{36}/print
          - /printer/device/[0-9a-f-]{36}
          - /printer/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /qr_code/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /questionnaire/org/[0-9a-f-]{36}
          - /questionnaire/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /receptionist/org/[0-9a-f-]{36}/update_notification
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/cancel
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/deny
          - /recipients/site/[0-9a-f-]{36}
          - /registration_url/device/[0-9a-f-]{36}
          - /registration_url/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/redirect
          - /registration_url/org_id/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/web
          - /school/csv/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/assign
          - /school/org/[0-9a-f-]{36}/connect
          - /school/org/[0-9a-f-]{36}/disconnect
          - /school/org/[0-9a-f-]{36}/reconnect
          - /school/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/sync
          - /school/org/[0-9a-f-]{36}/sync
          - /security_screen/confirm/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /single_event/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/[0-9a-f-]{36}/enable_custom_print_driver
          - /site/[0-9a-f-]{36}/timestamp/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /site/assets/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/enable
          - /site/org/[0-9a-f-]{36}
          - /site/settings/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/settings/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /slack/[0-9a-f-]{36}/oauth_redirect
          - /slack/[0-9a-f-]{36}/slack_active
          - /slack/[0-9a-f-]{36}/uninstall_extention
          - /slack/[0-9a-f-]{36}/workspace_logo
          - /sync_command_hosts/org/[0-9a-f-]{36}
          - /sync_command_hosts/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /tablet_screen_sharing/access_token/device/[0-9a-f-]{36}
          - /tablet_screen_sharing/access_token/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /teams/org/[0-9a-f-]{36}/consent/redirect
          - /teams/org/[0-9a-f-]{36}/info
          - /teams/org/[0-9a-f-]{36}/uninstall
          - /unlock_link/assert_valid
          - /user/my/org/[0-9a-f-]{36}
          - /user/org/[0-9a-f-]{36}
          - /user/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /user/reception/my/org/[0-9a-f-]{36}
          - /user/valid_sites/org/[0-9a-f-]{36}
          - /user_group/org/[0-9a-f-]{36}/user_group/[0-9a-f-]{36}
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/approve
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/deny
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/pend
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/upload
          - /visit/batch/signout_previous/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/by_contact/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/docs/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/export/org/[0-9a-f-]{36}
          - /visit/export/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/export/v2/org/[0-9a-f-]{36}
          - /visit/id_photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/id_signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/land_page/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/redeem
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/allow_entry
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/id/scan
          - /visit/photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/purpose/org/[0-9a-f-]{36}
          - /visit/purpose/org/[0-9a-f-]{36}/suggested
          - /visit/qr_signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/reprint/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/visit_notes/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/clone
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/hide
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/order
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/clone
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/publish
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /visitor_type/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/order
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/clone
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/publish
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/hide
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /visitor_type_document/org/[0-9a-f-]{36}
          - /visitor_type_document/org/[0-9a-f-]{36}/reorder
          - /visitor_type_document/org/[0-9a-f-]{36}/replace
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/reorder
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/replace
          - /visitor_type_migration/org/[0-9a-f-]{36}
          - /workplace/licensing/overview/org/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /\.well-known/apple-app-site-association
          - /app_review/register
          - /batch_bg_check/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /batch_bg_check/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/form_id/[0-9a-f-]{36}
          - /bg_check/manual/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v2/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v3/manual/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v3/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /call_button/twilio/voice/[0-9a-f-]{36}
          - /device/token
          - /device/token/v2
          - /device/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /device_init
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_config
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_config
          - /echo
          - /entrance/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/host_portal
          - /event/host_portal/[0-9a-f-]{36}
          - /event/v2/[0-9a-f-]{36}
          - /event/v2/host_portal
          - /file
          - /global/device/init
          - /global/device/token
          - /global/host_portal/magic_link/request
          - /global/outlook/guest/codes
          - /global/outlook/guest/login
          - /global/slack/guest/[0-9a-f-]{36}
          - /global/slack/mailroom/[0-9a-f-]{36}
          - /global/teams/guest
          - /global/teams/mailroom
          - /guardian/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /guest/[0-9a-f-]{36}/photo
          - /guest/org/[0-9a-f-]{36}
          - /host/checkin/org/[0-9a-f-]{36}
          - /host/delegates
          - /host/host_portal/site/[0-9a-f-]{36}
          - /host/inherit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/preferences
          - /host/preferences/image
          - /host_approval/app_config/token/[0-9a-f-]{36}
          - /host_approval/slack/[0-9a-f-]{36}/
          - /host_approval/token/[0-9a-f-]{36}
          - /host_portal/app_config
          - /host_portal/logout
          - /host_portal/magic_link/redeem
          - /host_portal/magic_link/request
          - /host_portal/ping
          - /internal/document/media_convert_job
          - /internal/guest/trial/site/[0-9a-f-]{36}
          - /internal/invite
          - /internal/mailroom/trial/site/[0-9a-f-]{36}
          - /internal/org/[0-9a-f-]{36}
          - /invite_guest/host_portal/event/[0-9a-f-]{36}
          - /invite_guest/host_portal/org/[0-9a-f-]{36}/csv/parse
          - /notifications/callback/[a-z0-9]{32}
          - /notifications/email_status
          - /notifications/pinpoint_sms
          - /notifications/pinpoint_sms/mailroom
          - /notifications/pinpoint_sms/v2
          - /org/quickstart
          - /outlook/guest
          - /outlook/guest/fetch
          - /outlook/guest/signout
          - /package/[0-9a-f-]{36}/photo
          - /package/email/not_mine/[0-9a-f-]{36}
          - /package/email/pickup/[0-9a-f-]{36}
          - /package/pickup/rfid/[A-Z0-9]{24}
          - /package/pickup/user/[0-9a-f-]{36}
          - /package/slack/[0-9a-f-]{36}/
          - /package_media/[0-9a-f-]{36}
          - /package_org/quickstart
          - /package_portal/employee
          - /package_portal/employee/[0-9a-f-]{36}
          - /package_portal/employee/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_portal/not_my
          - /package_portal/pickup
          - /package_portal/single/[0-9a-f-]{36}
          - /package_portal/single/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /package_portal/single/[0-9a-f-]{36}/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_status/app_config/token/[0-9a-f-]{36}
          - /package_status/app_config/token/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /packages/carriers
          - /packages/rfid_inventory
          - /packages/site/[0-9a-f-]{36}
          - /packages/slack/oauth_callback
          - /packages/teams/consent/callback
          - /packages_demo/config
          - /packages_demo/package/site/[0-9a-f-]{36}
          - /packages_demo/signature/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /pass/org/[0-9a-f-]{36}/apple
          - /pass/org/[0-9a-f-]{36}/google
          - /pass/v1/devices/[a-zA-Z0-9-]+/registrations/[\w\.\-]+
          - /pass/v1/devices/[a-zA-Z0-9-]+/registrations/[\w\.\-]+/[0-9a-f-]{36}
          - /pass/v1/passes/[\w\.\-]+/[0-9a-f-]{36}
          - /ping
          - /ping_env
          - /reception-app/magic-login/redeem
          - /registration_app_config/camera/[0-9a-f-]{36}/thumbnail
          - /registration_app_config/org/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/verify
          - /slack/[0-9a-f-]{36}
          - /slack/oauth_callback
          - /student/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /teams/consent/callback
          - /twilio/webhook/[a-z0-9]{32}
          - /twilio/webhook/packages/[a-z0-9]{32}
          - /unauthed_feature_flags
          - /visit/fastpass/org/[0-9a-f-]{36}
          - /visit/invited/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/search
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /visit/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/return/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/signout/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /visit/v2/return/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/vt/[0-9a-f-]{36}
      - host: vdoorman.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/toggle
          - /access/org/[0-9a-f-]{36}/toggle
          - /access_control_migration/org/[0-9a-f-]{36}
          - /analytics/app
          - /analytics/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /analytics/package
          - /analytics_v2/org/[0-9a-f-]{36}
          - /analytics_v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /app-login/[0-9a-f-]{36}
          - /application_url/org_id/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/web
          - /approve_list/org/[0-9a-f-]{36}
          - /bg_check/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /bg_check/applicant/org/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /bg_check/cancel/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /bg_check/confirm/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/events/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/fetch/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /bg_check/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /botd/badge/[0-9a-f-]{36}
          - /botd/org/[0-9a-f-]{36}
          - /call_button/access_token/device/[0-9a-f-]{36}
          - /call_button/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /context_devices/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/config/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/logo_image/[0-9a-f-]{36}
          - /demo_visit_hyperzoom/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /demo_visit_video/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /device/[0-9a-f-]{36}
          - /device/[0-9a-f-]{36}/events
          - /device/[0-9a-f-]{36}/screenshot
          - /device/[0-9a-f-]{36}/stash_visit
          - /device/health
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/claim
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/identify
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/test_print
          - /device_init
          - /document/org/[0-9a-f-]{36}
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_fields
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_progress
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/convert
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_fields
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_progress
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_redirect
          - /echo
          - /event/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/resend
          - /event/by_day/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /face_match/device/[0-9a-f-]{36}
          - /face_match/device/[0-9a-f-]{36}/model
          - /face_match/device/[0-9a-f-]{36}/opt_in
          - /form/org/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/form/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/publish
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/form/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /guardian/temp/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /guardian/temp/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /guest/announcements/create
          - /guest/announcements/org/[0-9a-f-]{36}
          - /guest/licensing/overview/org/[0-9a-f-]{36}
          - /guest/org/[0-9a-f-]{36}/guest/[0-9a-f-]{36}/poi
          - /guest/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest/[0-9a-f-]{36}/photo
          - /guest/photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest/[0-9a-f-]{36}
          - /guest/trial/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/departments/org/[0-9a-f-]{36}
          - /healthcare/end_visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/[0-9a-f-]{36}/departments
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/verify
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/search
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /healthcare/partially_registered_visitor/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/partially_registered_visitor/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clear
          - /healthcare/partially_registered_visitor/qr_code/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/command/org/[0-9a-f-]{36}
          - /host/command/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/csv/org/[0-9a-f-]{36}
          - /host/csv/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/email/org/[0-9a-f-]{36}
          - /host/email/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/inherit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/all
          - /host/org/[0-9a-f-]{36}/delete
          - /host/org/[0-9a-f-]{36}/host/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/all
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/delete
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/host/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/host_id/[0-9a-f-]{36}/photo
          - /internal/pending_applicant_notifications
          - /internal/receptionist/notification_receptionist_manual_entry
          - /internal/receptionist/notification_receptionist_review
          - /internal/sync_command_hosts
          - /invite/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /invite_nfc/[0-9a-f-]{36}
          - /invited_guest/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /invited_guest/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/resend
          - /licensing/org/[0-9a-f-]{36}/guest_activity_last_30_days
          - /licensing/org/[0-9a-f-]{36}/package_site_activity_last_30_days
          - /licensing/org/[0-9a-f-]{36}/request_purchase/guest
          - /licensing/org/[0-9a-f-]{36}/request_purchase/mailroom
          - /licensing/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest
          - /licensing/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/mailroom
          - /licensing/overview/org/[0-9a-f-]{36}
          - /locale
          - /mailroom/licensing/overview/org/[0-9a-f-]{36}
          - /mailroom/trial/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/api_key_info
          - /meraki/org/[0-9a-f-]{36}/networks
          - /meraki/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/ssids
          - /multi_part_document/org/[0-9a-f-]{36}
          - /multi_part_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /multi_part_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/convert
          - /open_ended_questions/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type/[0-9a-f-]{36}
          - /open_ended_questions/org/[0-9a-f-]{36}/visitor_type/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/bootstrap
          - /org/[0-9a-f-]{36}/command/groups
          - /org/[0-9a-f-]{36}/deny_list/upload_csv
          - /org/[0-9a-f-]{36}/email_security
          - /org/[0-9a-f-]{36}/extend_trial
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/deny_list/[0-9a-f-]{36}/review
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/deny_list/upload_csv
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}/screenshot
          - /org/[0-9a-f-]{36}/trial
          - /org/assets/[0-9a-f-]{36}
          - /org/broken_link/[0-9a-f-]{36}
          - /org/preferences/[0-9a-f-]{36}
          - /org/shortname
          - /org/trial_devices/request/[0-9a-f-]{36}
          - /package/[0-9a-f-]{36}/image
          - /package/[0-9a-f-]{36}/reassign
          - /package/pickup/user/[0-9a-f-]{36}
          - /package_context_devices/device/[0-9a-f-]{36}
          - /package_context_devices/site/[0-9a-f-]{36}
          - /package_context_devices/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /package_media/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_org/extend_trial
          - /package_org/milestone/[0-9a-f-]{36}
          - /package_org/preferences/[0-9a-f-]{36}
          - /package_org/trial_devices/request/[0-9a-f-]{36}
          - /package_printer/[0-9a-f-]{36}
          - /package_printer/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/location
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/location/[0-9a-f-]{36}
          - /package_tag/site/[0-9a-f-]{36}
          - /packages/announcements/create
          - /packages/announcements/org/[0-9a-f-]{36}
          - /packages/get_name_from_address_dict/site/[0-9a-f-]{36}
          - /packages/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /packages/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/package/[0-9a-f-]{36}
          - /packages/package/[0-9a-f-]{36}
          - /packages/site/[0-9a-f-]{36}
          - /packages/site/[0-9a-f-]{36}/stats/graph
          - /packages/site/[0-9a-f-]{36}/stats/topline
          - /packages/site/[0-9a-f-]{36}/tracking_history
          - /packages/slack/[0-9a-f-]{36}/oauth_redirect
          - /packages/slack/[0-9a-f-]{36}/slack_active
          - /packages/slack/[0-9a-f-]{36}/uninstall_extention
          - /packages/slack/[0-9a-f-]{36}/workspace_logo
          - /packages/teams/org/[0-9a-f-]{36}/consent/redirect
          - /packages/teams/org/[0-9a-f-]{36}/info
          - /packages/teams/org/[0-9a-f-]{36}/uninstall
          - /packages/v2/site/[0-9a-f-]{36}
          - /packages_demo/package/site/[0-9a-f-]{36}
          - /patient/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient/[0-9a-f-]{36}
          - /patient_known_person/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient/[0-9a-f-]{36}
          - /patient_known_person/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient_known_person/[0-9a-f-]{36}
          - /patient_known_person/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient_known_person/[0-9a-f-]{36}
          - /permissions/org/[0-9a-f-]{36}
          - /printer/[0-9a-f-]{36}/print
          - /printer/device/[0-9a-f-]{36}
          - /printer/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /qr_code/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /questionnaire/org/[0-9a-f-]{36}
          - /questionnaire/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /receptionist/org/[0-9a-f-]{36}/update_notification
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/cancel
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/deny
          - /recipients/site/[0-9a-f-]{36}
          - /registration_url/device/[0-9a-f-]{36}
          - /registration_url/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/redirect
          - /registration_url/org_id/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/web
          - /school/csv/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/assign
          - /school/org/[0-9a-f-]{36}/connect
          - /school/org/[0-9a-f-]{36}/disconnect
          - /school/org/[0-9a-f-]{36}/reconnect
          - /school/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/sync
          - /school/org/[0-9a-f-]{36}/sync
          - /security_screen/confirm/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /single_event/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/[0-9a-f-]{36}/enable_custom_print_driver
          - /site/[0-9a-f-]{36}/timestamp/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /site/assets/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/enable
          - /site/org/[0-9a-f-]{36}
          - /site/settings/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/settings/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /slack/[0-9a-f-]{36}/oauth_redirect
          - /slack/[0-9a-f-]{36}/slack_active
          - /slack/[0-9a-f-]{36}/uninstall_extention
          - /slack/[0-9a-f-]{36}/workspace_logo
          - /sync_command_hosts/org/[0-9a-f-]{36}
          - /sync_command_hosts/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /tablet_screen_sharing/access_token/device/[0-9a-f-]{36}
          - /tablet_screen_sharing/access_token/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /teams/org/[0-9a-f-]{36}/consent/redirect
          - /teams/org/[0-9a-f-]{36}/info
          - /teams/org/[0-9a-f-]{36}/uninstall
          - /unlock_link/assert_valid
          - /user/my/org/[0-9a-f-]{36}
          - /user/org/[0-9a-f-]{36}
          - /user/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /user/reception/my/org/[0-9a-f-]{36}
          - /user/valid_sites/org/[0-9a-f-]{36}
          - /user_group/org/[0-9a-f-]{36}/user_group/[0-9a-f-]{36}
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/approve
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/deny
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/pend
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/upload
          - /visit/batch/signout_previous/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/by_contact/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/docs/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/export/org/[0-9a-f-]{36}
          - /visit/export/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/export/v2/org/[0-9a-f-]{36}
          - /visit/id_photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/id_signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/land_page/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/redeem
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/allow_entry
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/id/scan
          - /visit/photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/purpose/org/[0-9a-f-]{36}
          - /visit/purpose/org/[0-9a-f-]{36}/suggested
          - /visit/qr_signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/reprint/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/visit_notes/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/clone
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/hide
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/order
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/clone
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/publish
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /visitor_type/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/order
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/clone
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/publish
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/hide
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /visitor_type_document/org/[0-9a-f-]{36}
          - /visitor_type_document/org/[0-9a-f-]{36}/reorder
          - /visitor_type_document/org/[0-9a-f-]{36}/replace
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/reorder
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/replace
          - /visitor_type_migration/org/[0-9a-f-]{36}
          - /workplace/licensing/overview/org/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /\.well-known/apple-app-site-association
          - /app_review/register
          - /batch_bg_check/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /batch_bg_check/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/form_id/[0-9a-f-]{36}
          - /bg_check/manual/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v2/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v3/manual/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v3/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /call_button/twilio/voice/[0-9a-f-]{36}
          - /device/token
          - /device/token/v2
          - /device/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /device_init
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_config
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_config
          - /echo
          - /entrance/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/host_portal
          - /event/host_portal/[0-9a-f-]{36}
          - /event/v2/[0-9a-f-]{36}
          - /event/v2/host_portal
          - /file
          - /global/device/init
          - /global/device/token
          - /global/host_portal/magic_link/request
          - /global/outlook/guest/codes
          - /global/outlook/guest/login
          - /global/slack/guest/[0-9a-f-]{36}
          - /global/slack/mailroom/[0-9a-f-]{36}
          - /global/teams/guest
          - /global/teams/mailroom
          - /guardian/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /guest/[0-9a-f-]{36}/photo
          - /guest/org/[0-9a-f-]{36}
          - /host/checkin/org/[0-9a-f-]{36}
          - /host/delegates
          - /host/host_portal/site/[0-9a-f-]{36}
          - /host/inherit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/preferences
          - /host/preferences/image
          - /host_approval/app_config/token/[0-9a-f-]{36}
          - /host_approval/slack/[0-9a-f-]{36}/
          - /host_approval/token/[0-9a-f-]{36}
          - /host_portal/app_config
          - /host_portal/logout
          - /host_portal/magic_link/redeem
          - /host_portal/magic_link/request
          - /host_portal/ping
          - /internal/document/media_convert_job
          - /internal/guest/trial/site/[0-9a-f-]{36}
          - /internal/invite
          - /internal/mailroom/trial/site/[0-9a-f-]{36}
          - /internal/org/[0-9a-f-]{36}
          - /invite_guest/host_portal/event/[0-9a-f-]{36}
          - /invite_guest/host_portal/org/[0-9a-f-]{36}/csv/parse
          - /notifications/callback/[a-z0-9]{32}
          - /notifications/email_status
          - /notifications/pinpoint_sms
          - /notifications/pinpoint_sms/mailroom
          - /notifications/pinpoint_sms/v2
          - /org/quickstart
          - /outlook/guest
          - /outlook/guest/fetch
          - /outlook/guest/signout
          - /package/[0-9a-f-]{36}/photo
          - /package/email/not_mine/[0-9a-f-]{36}
          - /package/email/pickup/[0-9a-f-]{36}
          - /package/pickup/rfid/[A-Z0-9]{24}
          - /package/pickup/user/[0-9a-f-]{36}
          - /package/slack/[0-9a-f-]{36}/
          - /package_media/[0-9a-f-]{36}
          - /package_org/quickstart
          - /package_portal/employee
          - /package_portal/employee/[0-9a-f-]{36}
          - /package_portal/employee/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_portal/not_my
          - /package_portal/pickup
          - /package_portal/single/[0-9a-f-]{36}
          - /package_portal/single/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /package_portal/single/[0-9a-f-]{36}/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_status/app_config/token/[0-9a-f-]{36}
          - /package_status/app_config/token/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /packages/carriers
          - /packages/rfid_inventory
          - /packages/site/[0-9a-f-]{36}
          - /packages/slack/oauth_callback
          - /packages/teams/consent/callback
          - /packages_demo/config
          - /packages_demo/package/site/[0-9a-f-]{36}
          - /packages_demo/signature/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /pass/org/[0-9a-f-]{36}/apple
          - /pass/org/[0-9a-f-]{36}/google
          - /pass/v1/devices/[a-zA-Z0-9-]+/registrations/[\w\.\-]+
          - /pass/v1/devices/[a-zA-Z0-9-]+/registrations/[\w\.\-]+/[0-9a-f-]{36}
          - /pass/v1/passes/[\w\.\-]+/[0-9a-f-]{36}
          - /ping
          - /ping_env
          - /reception-app/magic-login/redeem
          - /registration_app_config/camera/[0-9a-f-]{36}/thumbnail
          - /registration_app_config/org/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/verify
          - /slack/[0-9a-f-]{36}
          - /slack/oauth_callback
          - /student/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /teams/consent/callback
          - /twilio/webhook/[a-z0-9]{32}
          - /twilio/webhook/packages/[a-z0-9]{32}
          - /unauthed_feature_flags
          - /visit/fastpass/org/[0-9a-f-]{36}
          - /visit/invited/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/search
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /visit/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/return/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/signout/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /visit/v2/return/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/vt/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vdoorman
    namespace: vinfra
    resourceVersion: "5009066498"
    uid: b74de103-c841-4cf4-aafd-32f52d270bd7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdoormansocket.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /subscribe
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vdoormansocket
    namespace: vinfra
    resourceVersion: "5009066505"
    uid: 51096507-85a4-43f6-a9a2-65cbb738ab91
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vecho.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vecho
    namespace: vinfra
    resourceVersion: "5009066509"
    uid: 82edccc1-8568-4fda-8cbe-46551e0188c9
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vemr.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /adt_update/status/org_id/[0-9a-f-]{36}
          - /patients/site/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /internal/adt_update
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vemr
    namespace: vinfra
    resourceVersion: "5009066513"
    uid: e6a2fb8b-7196-40e6-bff3-50cd617eb857
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: veventsock.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /user/listen_unseen_alert_counts/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-veventsock
    namespace: vinfra
    resourceVersion: "5009066516"
    uid: 527e424d-3962-49ed-b815-6603a9b0c849
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vexplore.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /cross_shard/accounting/balance
          - /cross_shard/accounting/history
          - /cross_shard/accounting/history/csv
          - /cross_shard/accounting/income
          - /cross_shard/alarm/status
          - /cross_shard/camera/status
          - /cross_shard/download_org_users
          - /cross_shard/get_org_by_short_name
          - /cross_shard/get_org_licensing_exemption_status
          - /cross_shard/license
          - /cross_shard/license/burn
          - /cross_shard/license/children
          - /cross_shard/license/claim
          - /cross_shard/license/claim/dryrun
          - /cross_shard/license/grant
          - /cross_shard/license/grant/dryrun
          - /cross_shard/license/history
          - /cross_shard/license/history/csv
          - /cross_shard/license/run_cohort_emails
          - /cross_shard/license/send_expired_email_to_target_orgs
          - /cross_shard/license/split
          - /cross_shard/license/trials
          - /cross_shard/license/unclaim
          - /cross_shard/license/update_job_schedule
          - /cross_shard/license/void
          - /cross_shard/licensing/org/[0-9a-f-]{36}/trials
          - /cross_shard/list_orders
          - /cross_shard/logistics/get_organization_info
          - /cross_shard/logistics/skus
          - /cross_shard/models/list
          - /cross_shard/modify_license_exemption
          - /cross_shard/order
          - /cross_shard/order/csv
          - /cross_shard/order_count
          - /cross_shard/org/[0-9a-f-]{36}/privacy_disclosure
          - /cross_shard/org/[0-9a-f-]{36}/privacy_disclosures
          - /cross_shard/org/get
          - /cross_shard/org/streaming/metrics
          - /cross_shard/org/toggle_internal_status
          - /cross_shard/org_alarms
          - /cross_shard/org_cameras
          - /cross_shard/org_contacts
          - /cross_shard/org_intercoms
          - /cross_shard/org_lockout_status/[0-9a-f-]{36}
          - /cross_shard/org_sensors
          - /cross_shard/org_stats
          - /cross_shard/org_users
          - /cross_shard/organization/license
          - /cross_shard/query_cameras
          - /cross_shard/query_orders
          - /cross_shard/query_orgs
          - /cross_shard/query_users
          - /cross_shard/query_uuid
          - /cross_shard/retention/org/[0-9a-f-]{36}
          - /cross_shard/sensor/status
          - /cross_shard/supplychain/order_search
          - /cross_shard/user/get_orgs
          - /cross_shard/v3/license/grant
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vexplore
    namespace: vinfra
    resourceVersion: "5009066518"
    uid: 84e9e4d6-983a-4ce9-894a-5ba7f71a7432
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/export/bulk/start
          - /library/export/delete
          - /library/export/detected_objects
          - /library/export/download
          - /library/export/grid_[0-9]+\.jpg
          - /library/export/label/set
          - /library/export/list
          - /library/export/list/metadata
          - /library/export/list/organization
          - /library/export/list/tags
          - /library/export/list/user
          - /library/export/multi/start
          - /library/export/public/set
          - /library/export/share
          - /library/export/start
          - /library/export/status
          - /library/export/statuses
          - /library/export/stop
          - /library/export/tags/set
          - /library/export/thumb\.jpg
        unauthenticatedEndpoints:
          - /archive/verify
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/export/bulk/start
          - /library/export/delete
          - /library/export/detected_objects
          - /library/export/download
          - /library/export/grid_[0-9]+\.jpg
          - /library/export/label/set
          - /library/export/list
          - /library/export/list/metadata
          - /library/export/list/organization
          - /library/export/list/tags
          - /library/export/list/user
          - /library/export/multi/start
          - /library/export/public/set
          - /library/export/share
          - /library/export/start
          - /library/export/status
          - /library/export/statuses
          - /library/export/stop
          - /library/export/tags/set
          - /library/export/thumb\.jpg
        unauthenticatedEndpoints:
          - /archive/verify
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/export/bulk/start
          - /library/export/delete
          - /library/export/detected_objects
          - /library/export/download
          - /library/export/grid_[0-9]+\.jpg
          - /library/export/label/set
          - /library/export/list
          - /library/export/list/metadata
          - /library/export/list/organization
          - /library/export/list/tags
          - /library/export/list/user
          - /library/export/multi/start
          - /library/export/public/set
          - /library/export/share
          - /library/export/start
          - /library/export/status
          - /library/export/statuses
          - /library/export/stop
          - /library/export/tags/set
          - /library/export/thumb\.jpg
        unauthenticatedEndpoints:
          - /archive/verify
      - host: vexport.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vexport
    namespace: vinfra
    resourceVersion: "5009066521"
    uid: 328f0a56-4b79-4a6b-be9f-1ac4cad557ea
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /feature_flags/init
        unauthenticatedEndpoints:
          - /corp_tools/feature_flags/tools_init
          - /feature_flags/device_init
          - /feature_flags/get_all
          - /feature_flags/guest_init
          - /feature_flags/init_layer
          - /feature_flags/set_used
          - /tools/feature_flags/tools_init
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /feature_flags/init
        unauthenticatedEndpoints:
          - /corp_tools/feature_flags/tools_init
          - /feature_flags/device_init
          - /feature_flags/get_all
          - /feature_flags/guest_init
          - /feature_flags/init_layer
          - /feature_flags/set_used
          - /tools/feature_flags/tools_init
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /feature_flags/init
        unauthenticatedEndpoints:
          - /corp_tools/feature_flags/tools_init
          - /feature_flags/device_init
          - /feature_flags/get_all
          - /feature_flags/guest_init
          - /feature_flags/init_layer
          - /feature_flags/set_used
          - /tools/feature_flags/tools_init
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /feature_flags/init
        unauthenticatedEndpoints:
          - /corp_tools/feature_flags/tools_init
          - /feature_flags/device_init
          - /feature_flags/get_all
          - /feature_flags/guest_init
          - /feature_flags/init_layer
          - /feature_flags/set_used
          - /tools/feature_flags/tools_init
      - host: vfeatureflag.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /feature_flags/get_all
          - /feature_flags/init
          - /ping
        unauthenticatedEndpoints:
          - /feature_flags/device_init
          - /feature_flags/guest_init
          - /feature_flags/init_layer
          - /feature_flags/set_used
      - host: vfeatureflag.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /feature_flags/get_all
          - /feature_flags/set_used
          - /internal/fanout/feature_flags/get_ready_for_permanent_deletion
          - /internal/fanout/feature_flags/get_ready_for_soft_deletion
          - /internal/feature_flags/is_feature_flag_enabled
          - /shortnames/get_all
          - /tools/feature_flags/add_child
          - /tools/feature_flags/create
          - /tools/feature_flags/create_rollout
          - /tools/feature_flags/delete
          - /tools/feature_flags/delete_rollout
          - /tools/feature_flags/device
          - /tools/feature_flags/email
          - /tools/feature_flags/get_audit_logs
          - /tools/feature_flags/get_children
          - /tools/feature_flags/get_entities_for_flag
          - /tools/feature_flags/get_exemption_feature_flags
          - /tools/feature_flags/get_exemption_list
          - /tools/feature_flags/get_feature_flag
          - /tools/feature_flags/get_parents
          - /tools/feature_flags/get_rollout_custom_group
          - /tools/feature_flags/get_rollout_custom_group_preview
          - /tools/feature_flags/get_rollout_group
          - /tools/feature_flags/get_rollout_group_preview
          - /tools/feature_flags/get_rollout_metadata
          - /tools/feature_flags/get_rollout_status
          - /tools/feature_flags/get_soft_deleted
          - /tools/feature_flags/organization
          - /tools/feature_flags/remove_child
          - /tools/feature_flags/set_exemption_list
          - /tools/feature_flags/set_feature_flag
          - /tools/feature_flags/set_feature_flag_minimum_version
          - /tools/feature_flags/set_global_feature_flag
          - /tools/feature_flags/set_rollout_group
          - /tools/feature_flags/set_sample_size
          - /tools/feature_flags/set_shard_feature_flag
          - /tools/feature_flags/shortnames/add
          - /tools/feature_flags/shortnames/check_available
          - /tools/feature_flags/sync
          - /tools/feature_flags/update_metadata
          - /tools/feature_flags/update_team_name
          - /tools/feature_flags/user
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vfeatureflag
    namespace: vinfra
    resourceVersion: "5009066525"
    uid: fbfca30b-f66c-42f8-af22-9f1d74e16de4
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vfilter.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/avmux/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/avmux/[\w\-. +%]+
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/stream/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. +%]+
        unauthenticatedEndpoints:
          - /filter/avmux/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vfilter
    namespace: vinfra
    resourceVersion: "5009066527"
    uid: a5e2f735-bff2-44d1-a139-ec6b0c3ed05d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vfleetmgmt.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /internal/camera/firmware-version/config
          - /internal/camera/healthstatus
          - /internal/validate
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vfleetmgmt
    namespace: vinfra
    resourceVersion: "5009066529"
    uid: c0e3fdd3-3486-4000-858b-2cb693bcb1b8
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /flow/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /flow/ping
      - host: vstream.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /flow/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /flow/ping
      - host: "*.vproxy.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /flow/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /flow/ping
      - host: "*.vstream.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /flow/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /flow/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vflow
    namespace: vinfra
    resourceVersion: "5009066531"
    uid: 24485777-6476-4b99-b195-8078bffe8b2f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /floorplans/legacy/features
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /floorplans/legacy/features
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /floorplans/legacy/features
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /floorplans/legacy/features
      - host: vfootprint.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /floorplans
          - /floorplans/[0-9a-f-]{36}/image
          - /floorplans/cameras/[0-9a-f-]{36}/calibration/images
          - /floorplans/cameras/[0-9a-f-]{36}/calibration/status
          - /floorplans/cameras/[0-9a-f-]{36}/motion-history
          - /floorplans/floorplan
          - /floorplans/legacy/features
          - /floorplans/orgs
          - /floorplans/orgs/[0-9a-f-]{36}
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/[0-9a-f-]{36}
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/[0-9a-f-]{36}/
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/transformation-matrix
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/transformation-matrix/submit
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floors/[0-9a-f-]{36}/
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floors/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/location
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vfootprint
    namespace: vinfra
    resourceVersion: "5009066535"
    uid: 1f628312-e153-4e60-9f6d-efa1f6a44a32
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vfortress/box/add_camera
          - /vfortress/box/get_pcap
          - /vfortress/box/reboot
          - /vfortress/box/remove_all_cameras
          - /vfortress/box/remove_camera
          - /vfortress/box/self
          - /vfortress/box/set_static_ip
          - /vfortress/box/update_cameras
          - /vfortress/camera/check_credentials
          - /vfortress/camera/get_retention
          - /vfortress/camera/get_snapshots
          - /vfortress/camera/get_stream_profiles
          - /vfortress/camera/save_local_data
          - /vfortress/camera/set_disk_size
          - /vfortress/camera/set_retention
          - /vfortress/cameras/list/box
          - /vfortress/cameras/list/org
          - /vfortress/commission
          - /vfortress/decommission
          - /vfortress/discovery
          - /vfortress/get_box
          - /vfortress/list_boxes
          - /vfortress/sensor/config/get
          - /vfortress/sensor/config/set
          - /vfortress/sensor/force_reconfigure
          - /vfortress/update_box
          - /vfortress/update_boxes
          - /vfortress/ws
        unauthenticatedEndpoints:
          - /vfortress/ping
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vfortress/box/add_camera
          - /vfortress/box/get_pcap
          - /vfortress/box/reboot
          - /vfortress/box/remove_all_cameras
          - /vfortress/box/remove_camera
          - /vfortress/box/self
          - /vfortress/box/set_static_ip
          - /vfortress/box/update_cameras
          - /vfortress/camera/check_credentials
          - /vfortress/camera/get_retention
          - /vfortress/camera/get_snapshots
          - /vfortress/camera/get_stream_profiles
          - /vfortress/camera/save_local_data
          - /vfortress/camera/set_disk_size
          - /vfortress/camera/set_retention
          - /vfortress/cameras/list/box
          - /vfortress/cameras/list/org
          - /vfortress/commission
          - /vfortress/decommission
          - /vfortress/discovery
          - /vfortress/get_box
          - /vfortress/list_boxes
          - /vfortress/sensor/config/get
          - /vfortress/sensor/config/set
          - /vfortress/sensor/force_reconfigure
          - /vfortress/update_box
          - /vfortress/update_boxes
          - /vfortress/ws
        unauthenticatedEndpoints:
          - /vfortress/ping
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vfortress/box/add_camera
          - /vfortress/box/get_pcap
          - /vfortress/box/reboot
          - /vfortress/box/remove_all_cameras
          - /vfortress/box/remove_camera
          - /vfortress/box/self
          - /vfortress/box/set_static_ip
          - /vfortress/box/update_cameras
          - /vfortress/camera/check_credentials
          - /vfortress/camera/get_retention
          - /vfortress/camera/get_snapshots
          - /vfortress/camera/get_stream_profiles
          - /vfortress/camera/save_local_data
          - /vfortress/camera/set_disk_size
          - /vfortress/camera/set_retention
          - /vfortress/cameras/list/box
          - /vfortress/cameras/list/org
          - /vfortress/commission
          - /vfortress/decommission
          - /vfortress/discovery
          - /vfortress/get_box
          - /vfortress/list_boxes
          - /vfortress/sensor/config/get
          - /vfortress/sensor/config/set
          - /vfortress/sensor/force_reconfigure
          - /vfortress/update_box
          - /vfortress/update_boxes
          - /vfortress/ws
        unauthenticatedEndpoints:
          - /vfortress/ping
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vfortress/box/add_camera
          - /vfortress/box/get_pcap
          - /vfortress/box/reboot
          - /vfortress/box/remove_all_cameras
          - /vfortress/box/remove_camera
          - /vfortress/box/self
          - /vfortress/box/set_static_ip
          - /vfortress/box/update_cameras
          - /vfortress/camera/check_credentials
          - /vfortress/camera/get_retention
          - /vfortress/camera/get_snapshots
          - /vfortress/camera/get_stream_profiles
          - /vfortress/camera/save_local_data
          - /vfortress/camera/set_disk_size
          - /vfortress/camera/set_retention
          - /vfortress/cameras/list/box
          - /vfortress/cameras/list/org
          - /vfortress/commission
          - /vfortress/decommission
          - /vfortress/discovery
          - /vfortress/get_box
          - /vfortress/list_boxes
          - /vfortress/sensor/config/get
          - /vfortress/sensor/config/set
          - /vfortress/sensor/force_reconfigure
          - /vfortress/update_box
          - /vfortress/update_boxes
          - /vfortress/ws
        unauthenticatedEndpoints:
          - /vfortress/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vfortress
    namespace: vinfra
    resourceVersion: "5009066540"
    uid: a6ccefab-faaa-4ecf-b273-27dbd568538f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vglobal.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /org/generate_short_name/.{1,100}
          - /org/validate_short_name
          - /orgs/get_with_shards
          - /passkey_authentication/options
          - /passkey_login
          - /ping
          - /prod_sharding/release_status
          - /regional_magic_link/create
          - /shard/get_for_email
          - /shard_mapping/get
          - /shards
          - /user/send_list_of_orgs
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vglobal
    namespace: vinfra
    resourceVersion: "5009066544"
    uid: 48bdfa19-9d7b-4766-a1d4-6dae5b876f17
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vguard.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /datadog/e2e_health_check
          - /web/cameras_set
          - /web/create_guard
          - /web/create_guard_doors
          - /web/delete_guard
          - /web/delete_guard_doors
          - /web/doors_set
          - /web/get_incidents
          - /web/guard_camera_list
          - /web/guard_list
          - /web/guard_settings
          - /web/mute_camera
          - /web/pause_guard
          - /web/resolve_escalation
          - /web/resume_guard
          - /web/schedules_render
          - /web/schedules_set
          - /web/shift_details
          - /web/shift_end
          - /web/shift_list
          - /web/shift_start
          - /web/site_settings
          - /web/speakers_set
          - /web/unavailable_cameras
          - /web/unmute_camera
          - /web/update_guard
          - /web/update_guard_doors
        unauthenticatedEndpoints:
          - /ping
          - /web/guard_doors_list
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vguard
    namespace: vinfra
    resourceVersion: "5009066548"
    uid: c3db4570-a457-4fc1-b029-e31e914e3881
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vhistory/camera/[0-9a-f-]{36}/connect
          - /vhistory/camera/vhs
          - /vhistory/client/vhs
          - /vhistory/media
          - /vhistory/media/[\w\-. +%]+
        unauthenticatedEndpoints:
          - /vhistory/internal/media/[\w\-. +%]+
          - /vhistory/ping
      - host: vstream.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vhistory/camera/[0-9a-f-]{36}/connect
          - /vhistory/camera/vhs
          - /vhistory/client/vhs
          - /vhistory/media
          - /vhistory/media/[\w\-. +%]+
        unauthenticatedEndpoints:
          - /vhistory/internal/media/[\w\-. +%]+
          - /vhistory/ping
      - host: "*.vproxy.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vhistory/camera/[0-9a-f-]{36}/connect
          - /vhistory/camera/vhs
          - /vhistory/client/vhs
          - /vhistory/media
          - /vhistory/media/[\w\-. +%]+
        unauthenticatedEndpoints:
          - /vhistory/internal/media/[\w\-. +%]+
          - /vhistory/ping
      - host: "*.vstream.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vhistory/camera/[0-9a-f-]{36}/connect
          - /vhistory/camera/vhs
          - /vhistory/client/vhs
          - /vhistory/media
          - /vhistory/media/[\w\-. +%]+
        unauthenticatedEndpoints:
          - /vhistory/internal/media/[\w\-. +%]+
          - /vhistory/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vhistory
    namespace: vinfra
    resourceVersion: "5009066553"
    uid: c69be65a-9e22-479a-a339-01eb107607d8
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: videntity.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /identity/appearances
          - /identity/attribute/append
          - /identity/attribute/remove
          - /identity/bulk/get
          - /identity/bulk/upload
          - /identity/create
          - /identity/delete
          - /identity/frequent/get
          - /identity/get
          - /identity/image/create
          - /identity/image/delete
          - /identity/list
          - /identity/merge
          - /identity/search/events
          - /identity/strangers/get
          - /identity/unmerge
          - /identity/update
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-videntity
    namespace: vinfra
    resourceVersion: "5009066556"
    uid: d2513daa-0774-4950-a5c7-0c6881dd703f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vimagetuner.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device/capture_raw
          - /device/capture_yuv
          - /device/configure_development
          - /device/get_shutter_gain
          - /device/override_iq/get
          - /device/override_iq/set
          - /device/remote_shell
          - /device/replace_iq_binaries
          - /device/set_ae_lines
          - /device/set_ae_lines_hdr
          - /device/start_amage_server
          - /ping
          - /tune
          - /utils/compile_iq_binaries
          - /utils/ituner_to_c
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vimagetuner
    namespace: vinfra
    resourceVersion: "5009066559"
    uid: 834879d6-4ace-4fa5-9236-d0cecee802b0
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vinnout.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /client/areas/[0-9a-f-]{36}
          - /client/areas/[0-9a-f-]{36}/users/[0-9a-f-]{36}/location
          - /client/areas/[0-9a-f-]{36}/users/[0-9a-f-]{36}/violation
          - /client/users/[0-9a-f-]{36}
          - /device/events
          - /device/status
          - /device/wss
        unauthenticatedEndpoints:
          - /ping
      - host: access.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinnout/device/events
          - /vinnout/device/status
          - /vinnout/device/wss
      - host: vcerberus.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinnout/device/events
          - /vinnout/device/status
          - /vinnout/device/wss
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vinnout
    namespace: vinfra
    resourceVersion: "5009066564"
    uid: ce6f528d-ff09-4947-a0ea-e4e84c735f8d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinter/v1/device/desk/away
          - /vinter/v1/device/desk/batch_telemetry
          - /vinter/v1/device/desk/config
          - /vinter/v1/device/desk/remote_unlock
          - /vinter/v1/device/desk/single_telemetry
          - /vinter/v1/device/desk/twilio/access_token
          - /vinter/v1/device/desk/user/[0-9a-f-]{36}/photo/[\w\-. +%]+
          - /vinter/v1/device/intercom/audio_files
          - /vinter/v1/device/intercom/batch_telemetry
          - /vinter/v1/device/intercom/config
          - /vinter/v1/device/intercom/local_sip_account_registration_status
          - /vinter/v1/device/intercom/raw_event
          - /vinter/v1/device/intercom/remote_unlock
          - /vinter/v1/device/intercom/single_telemetry
          - /vinter/v1/device/intercom/sound_link
          - /vinter/v1/device/intercom/status
          - /vinter/v1/device/intercom/vmeerkat_status
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/batch/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/audio_file
          - /vinter/v1/user/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/disable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/enable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/reset
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/new_call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_targets
          - /vinter/v1/user/organization/[0-9a-f-]{36}/dashboard
          - /vinter/v1/user/organization/[0-9a-f-]{36}/desk/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/events
          - /vinter/v1/user/organization/[0-9a-f-]{36}/generate_report
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/approach
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/checks
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_type
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/emergency_phone
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/initiate_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/location
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound_upload
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_tts
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/reboot
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/soft_button_press
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/un_hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/is_pass_active
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/sip_registration_status
          - /vinter/v1/user/organization/[0-9a-f-]{36}/telemetry_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/command_app_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/web_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/user_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/web_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/intercom
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/remote_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/twilio/access_token
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/twilio/access_token
        unauthenticatedEndpoints:
          - /vinter/call/ping
          - /vinter/device/ping
          - /vinter/internal/ping
          - /vinter/ping
          - /vinter/poll/ping
          - /vinter/status_test
          - /vinter/transient/1/ping
          - /vinter/transient/2/ping
          - /vinter/transient/3/ping
          - /vinter/transient/4/ping
          - /vinter/transient/5/ping
          - /vinter/transient/ping
          - /vinter/unlock/ping
          - /vinter/user/ping
          - /vinter/v1/device/desk/serial_number
          - /vinter/v1/external/livekit/webhook/all
          - /vinter/v1/external/twilio/intercom_call
          - /vinter/v1/external/twilio/intercom_call_status
          - /vinter/v1/external/twilio/receiver_call
          - /vinter/v1/external/twilio/receiver_call_status
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinter/v1/device/desk/away
          - /vinter/v1/device/desk/batch_telemetry
          - /vinter/v1/device/desk/config
          - /vinter/v1/device/desk/remote_unlock
          - /vinter/v1/device/desk/single_telemetry
          - /vinter/v1/device/desk/twilio/access_token
          - /vinter/v1/device/desk/user/[0-9a-f-]{36}/photo/[\w\-. +%]+
          - /vinter/v1/device/intercom/audio_files
          - /vinter/v1/device/intercom/batch_telemetry
          - /vinter/v1/device/intercom/config
          - /vinter/v1/device/intercom/local_sip_account_registration_status
          - /vinter/v1/device/intercom/raw_event
          - /vinter/v1/device/intercom/remote_unlock
          - /vinter/v1/device/intercom/single_telemetry
          - /vinter/v1/device/intercom/sound_link
          - /vinter/v1/device/intercom/status
          - /vinter/v1/device/intercom/vmeerkat_status
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/batch/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/audio_file
          - /vinter/v1/user/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/disable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/enable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/reset
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/new_call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_targets
          - /vinter/v1/user/organization/[0-9a-f-]{36}/dashboard
          - /vinter/v1/user/organization/[0-9a-f-]{36}/desk/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/events
          - /vinter/v1/user/organization/[0-9a-f-]{36}/generate_report
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/approach
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/checks
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_type
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/emergency_phone
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/initiate_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/location
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound_upload
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_tts
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/reboot
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/soft_button_press
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/un_hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/is_pass_active
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/sip_registration_status
          - /vinter/v1/user/organization/[0-9a-f-]{36}/telemetry_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/command_app_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/web_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/user_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/web_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/intercom
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/remote_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/twilio/access_token
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/twilio/access_token
        unauthenticatedEndpoints:
          - /vinter/call/ping
          - /vinter/device/ping
          - /vinter/internal/ping
          - /vinter/ping
          - /vinter/poll/ping
          - /vinter/status_test
          - /vinter/transient/1/ping
          - /vinter/transient/2/ping
          - /vinter/transient/3/ping
          - /vinter/transient/4/ping
          - /vinter/transient/5/ping
          - /vinter/transient/ping
          - /vinter/unlock/ping
          - /vinter/user/ping
          - /vinter/v1/device/desk/serial_number
          - /vinter/v1/external/livekit/webhook/all
          - /vinter/v1/external/twilio/intercom_call
          - /vinter/v1/external/twilio/intercom_call_status
          - /vinter/v1/external/twilio/receiver_call
          - /vinter/v1/external/twilio/receiver_call_status
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinter/v1/device/desk/away
          - /vinter/v1/device/desk/batch_telemetry
          - /vinter/v1/device/desk/config
          - /vinter/v1/device/desk/remote_unlock
          - /vinter/v1/device/desk/single_telemetry
          - /vinter/v1/device/desk/twilio/access_token
          - /vinter/v1/device/desk/user/[0-9a-f-]{36}/photo/[\w\-. +%]+
          - /vinter/v1/device/intercom/audio_files
          - /vinter/v1/device/intercom/batch_telemetry
          - /vinter/v1/device/intercom/config
          - /vinter/v1/device/intercom/local_sip_account_registration_status
          - /vinter/v1/device/intercom/raw_event
          - /vinter/v1/device/intercom/remote_unlock
          - /vinter/v1/device/intercom/single_telemetry
          - /vinter/v1/device/intercom/sound_link
          - /vinter/v1/device/intercom/status
          - /vinter/v1/device/intercom/vmeerkat_status
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/batch/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/audio_file
          - /vinter/v1/user/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/disable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/enable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/reset
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/new_call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_targets
          - /vinter/v1/user/organization/[0-9a-f-]{36}/dashboard
          - /vinter/v1/user/organization/[0-9a-f-]{36}/desk/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/events
          - /vinter/v1/user/organization/[0-9a-f-]{36}/generate_report
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/approach
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/checks
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_type
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/emergency_phone
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/initiate_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/location
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound_upload
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_tts
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/reboot
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/soft_button_press
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/un_hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/is_pass_active
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/sip_registration_status
          - /vinter/v1/user/organization/[0-9a-f-]{36}/telemetry_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/command_app_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/web_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/user_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/web_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/intercom
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/remote_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/twilio/access_token
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/twilio/access_token
        unauthenticatedEndpoints:
          - /vinter/call/ping
          - /vinter/device/ping
          - /vinter/internal/ping
          - /vinter/ping
          - /vinter/poll/ping
          - /vinter/status_test
          - /vinter/transient/1/ping
          - /vinter/transient/2/ping
          - /vinter/transient/3/ping
          - /vinter/transient/4/ping
          - /vinter/transient/5/ping
          - /vinter/transient/ping
          - /vinter/unlock/ping
          - /vinter/user/ping
          - /vinter/v1/device/desk/serial_number
          - /vinter/v1/external/livekit/webhook/all
          - /vinter/v1/external/twilio/intercom_call
          - /vinter/v1/external/twilio/intercom_call_status
          - /vinter/v1/external/twilio/receiver_call
          - /vinter/v1/external/twilio/receiver_call_status
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinter/v1/device/desk/away
          - /vinter/v1/device/desk/batch_telemetry
          - /vinter/v1/device/desk/config
          - /vinter/v1/device/desk/remote_unlock
          - /vinter/v1/device/desk/single_telemetry
          - /vinter/v1/device/desk/twilio/access_token
          - /vinter/v1/device/desk/user/[0-9a-f-]{36}/photo/[\w\-. +%]+
          - /vinter/v1/device/intercom/audio_files
          - /vinter/v1/device/intercom/batch_telemetry
          - /vinter/v1/device/intercom/config
          - /vinter/v1/device/intercom/local_sip_account_registration_status
          - /vinter/v1/device/intercom/raw_event
          - /vinter/v1/device/intercom/remote_unlock
          - /vinter/v1/device/intercom/single_telemetry
          - /vinter/v1/device/intercom/sound_link
          - /vinter/v1/device/intercom/status
          - /vinter/v1/device/intercom/vmeerkat_status
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/batch/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/audio_file
          - /vinter/v1/user/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/disable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/enable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/reset
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/new_call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_targets
          - /vinter/v1/user/organization/[0-9a-f-]{36}/dashboard
          - /vinter/v1/user/organization/[0-9a-f-]{36}/desk/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/events
          - /vinter/v1/user/organization/[0-9a-f-]{36}/generate_report
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/approach
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/checks
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_type
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/emergency_phone
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/initiate_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/location
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound_upload
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_tts
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/reboot
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/soft_button_press
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/un_hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/is_pass_active
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/sip_registration_status
          - /vinter/v1/user/organization/[0-9a-f-]{36}/telemetry_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/command_app_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/web_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/user_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/web_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/intercom
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/remote_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/twilio/access_token
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/twilio/access_token
        unauthenticatedEndpoints:
          - /vinter/call/ping
          - /vinter/device/ping
          - /vinter/internal/ping
          - /vinter/ping
          - /vinter/poll/ping
          - /vinter/status_test
          - /vinter/transient/1/ping
          - /vinter/transient/2/ping
          - /vinter/transient/3/ping
          - /vinter/transient/4/ping
          - /vinter/transient/5/ping
          - /vinter/transient/ping
          - /vinter/unlock/ping
          - /vinter/user/ping
          - /vinter/v1/device/desk/serial_number
          - /vinter/v1/external/livekit/webhook/all
          - /vinter/v1/external/twilio/intercom_call
          - /vinter/v1/external/twilio/intercom_call_status
          - /vinter/v1/external/twilio/receiver_call
          - /vinter/v1/external/twilio/receiver_call_status
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vinter
    namespace: vinfra
    resourceVersion: "5009066574"
    uid: 4b9fba01-d9c9-475b-9ddf-d03091a40325
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vinvestigate.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /evidence/archive/create
          - /evidence/archive/delete
          - /evidence/archive/get
          - /evidence/archive/objects_in_range
          - /evidence/archive/update
          - /evidence/archive_info/get
          - /evidence/bulk/status
          - /evidence/delete
          - /evidence/event/create
          - /evidence/hyperzoom/delete
          - /evidence/library/archive/enckey
          - /evidence/library/archive/init\.mp4
          - /evidence/library/archive/playlist\.m3u8
          - /evidence/library/archive/thumb\.jpg
          - /evidence/library/archive/video\.m4s
          - /evidence/library/hyperzoom\.jpg
          - /evidence/list
          - /incident/bulk/preview
          - /incident/change_logs/list
          - /incident/count
          - /incident/create
          - /incident/delete
          - /incident/download
          - /incident/download/status
          - /incident/external_token/get
          - /incident/get
          - /incident/list
          - /incident/share
          - /incident/share/list
          - /incident/share/list/v2
          - /incident/share/revoke
          - /incident/share/revoke/v2
          - /incident/share/v2
          - /incident/update
          - /prompt/event_search
          - /prompt/motion_intervals
          - /prompt/motion_search
          - /prompt/search
        unauthenticatedEndpoints:
          - /incident/external_token/redeem
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vinvestigate
    namespace: vinfra
    resourceVersion: "5009066577"
    uid: 3c0bd1b1-b656-42df-a2ee-9203e87b4fc7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vkms/device/authping
          - /vkms/device/store_public_key
          - /vkms/e2ee/convert_camera_to_e2ee
          - /vkms/e2ee/convert_camera_to_e2ee/batch
          - /vkms/e2ee/convert_camera_to_traditional
          - /vkms/e2ee/delete_association
          - /vkms/e2ee/delete_non_verified_init_keys
          - /vkms/e2ee/get_key_policy_file/latest
          - /vkms/e2ee/get_key_policy_files
          - /vkms/e2ee/get_key_policy_files/latest
          - /vkms/e2ee/init_keys
          - /vkms/e2ee/init_keys_backfill
          - /vkms/e2ee/retrieve_keys
          - /vkms/e2ee/retrieve_live_link_key
          - /vkms/e2ee/set_association
          - /vkms/e2ee/store_key_policy_file
          - /vkms/e2ee/store_verification_info
          - /vkms/e2ee/support_token_key/set
          - /vkms/e2ee/vendor_envelope_key/[0-9a-f-]{36}
          - /vkms/external_envelope_key/[0-9a-f-]{36}/[0-9]+
          - /vkms/external_envelope_keys/lookup
          - /vkms/retrieve_camera_envelope_keys
          - /vkms/retrieve_cameras_ece_status
          - /vkms/unlock_media_keys
          - /vkms/user/camera/retrieve_sharing_key/latest
          - /vkms/verify_kms_access/[0-9a-f-]{36}
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vkms/device/authping
          - /vkms/device/store_public_key
          - /vkms/e2ee/convert_camera_to_e2ee
          - /vkms/e2ee/convert_camera_to_e2ee/batch
          - /vkms/e2ee/convert_camera_to_traditional
          - /vkms/e2ee/delete_association
          - /vkms/e2ee/delete_non_verified_init_keys
          - /vkms/e2ee/get_key_policy_file/latest
          - /vkms/e2ee/get_key_policy_files
          - /vkms/e2ee/get_key_policy_files/latest
          - /vkms/e2ee/init_keys
          - /vkms/e2ee/init_keys_backfill
          - /vkms/e2ee/retrieve_keys
          - /vkms/e2ee/retrieve_live_link_key
          - /vkms/e2ee/set_association
          - /vkms/e2ee/store_key_policy_file
          - /vkms/e2ee/store_verification_info
          - /vkms/e2ee/support_token_key/set
          - /vkms/e2ee/vendor_envelope_key/[0-9a-f-]{36}
          - /vkms/external_envelope_key/[0-9a-f-]{36}/[0-9]+
          - /vkms/external_envelope_keys/lookup
          - /vkms/retrieve_camera_envelope_keys
          - /vkms/retrieve_cameras_ece_status
          - /vkms/unlock_media_keys
          - /vkms/user/camera/retrieve_sharing_key/latest
          - /vkms/verify_kms_access/[0-9a-f-]{36}
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vkms/device/authping
          - /vkms/device/store_public_key
          - /vkms/e2ee/convert_camera_to_e2ee
          - /vkms/e2ee/convert_camera_to_e2ee/batch
          - /vkms/e2ee/convert_camera_to_traditional
          - /vkms/e2ee/delete_association
          - /vkms/e2ee/delete_non_verified_init_keys
          - /vkms/e2ee/get_key_policy_file/latest
          - /vkms/e2ee/get_key_policy_files
          - /vkms/e2ee/get_key_policy_files/latest
          - /vkms/e2ee/init_keys
          - /vkms/e2ee/init_keys_backfill
          - /vkms/e2ee/retrieve_keys
          - /vkms/e2ee/retrieve_live_link_key
          - /vkms/e2ee/set_association
          - /vkms/e2ee/store_key_policy_file
          - /vkms/e2ee/store_verification_info
          - /vkms/e2ee/support_token_key/set
          - /vkms/e2ee/vendor_envelope_key/[0-9a-f-]{36}
          - /vkms/external_envelope_key/[0-9a-f-]{36}/[0-9]+
          - /vkms/external_envelope_keys/lookup
          - /vkms/retrieve_camera_envelope_keys
          - /vkms/retrieve_cameras_ece_status
          - /vkms/unlock_media_keys
          - /vkms/user/camera/retrieve_sharing_key/latest
          - /vkms/verify_kms_access/[0-9a-f-]{36}
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vkms/device/authping
          - /vkms/device/store_public_key
          - /vkms/e2ee/convert_camera_to_e2ee
          - /vkms/e2ee/convert_camera_to_e2ee/batch
          - /vkms/e2ee/convert_camera_to_traditional
          - /vkms/e2ee/delete_association
          - /vkms/e2ee/delete_non_verified_init_keys
          - /vkms/e2ee/get_key_policy_file/latest
          - /vkms/e2ee/get_key_policy_files
          - /vkms/e2ee/get_key_policy_files/latest
          - /vkms/e2ee/init_keys
          - /vkms/e2ee/init_keys_backfill
          - /vkms/e2ee/retrieve_keys
          - /vkms/e2ee/retrieve_live_link_key
          - /vkms/e2ee/set_association
          - /vkms/e2ee/store_key_policy_file
          - /vkms/e2ee/store_verification_info
          - /vkms/e2ee/support_token_key/set
          - /vkms/e2ee/vendor_envelope_key/[0-9a-f-]{36}
          - /vkms/external_envelope_key/[0-9a-f-]{36}/[0-9]+
          - /vkms/external_envelope_keys/lookup
          - /vkms/retrieve_camera_envelope_keys
          - /vkms/retrieve_cameras_ece_status
          - /vkms/unlock_media_keys
          - /vkms/user/camera/retrieve_sharing_key/latest
          - /vkms/verify_kms_access/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vkms
    namespace: vinfra
    resourceVersion: "5009066580"
    uid: b7e4b355-5da2-4cfb-a212-38dd8f889898
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlicensing.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device/batch/information
          - /health_check
          - /job/status
          - /license
          - /license/claim
          - /license/claim/dryrun
          - /license/history
          - /license/trials
          - /license_exemption/add_orgs
          - /license_exemption/organization/[0-9a-f-]{36}
          - /license_exemption/organizations
          - /licensing/org/[0-9a-f-]{36}/trials
          - /licensing/org/[0-9a-f-]{36}/trials/software
          - /licensing/org/[0-9a-f-]{36}/trials/software/[0-9a-f-]{36}/conversion
          - /logistics/get_organization_info
          - /logistics/org/[0-9a-f-]{36}/customer
          - /order/claim_order
          - /order/details
          - /order/unclaim_order
          - /org/[0-9a-f-]{36}/get_device_counts
          - /organization/license
          - /ping
          - /v2/order/details
        unauthenticatedEndpoints:
          - /health_check
          - /internal/device/batch/information
          - /internal/logistics/get_organization_info
          - /license/update_job_schedule
          - /licensing/org/[0-9a-f-]{36}/get_compliance_info
          - /order
          - /order/boomi/create_order
          - /order/netsuite/run
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vlicensing
    namespace: vinfra
    resourceVersion: "5009066585"
    uid: 0c820baa-1cb2-4059-a53c-a834261c465d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlive.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alert_groups/create
          - /alert_groups/delete
          - /alert_groups/get
          - /alert_groups/move
          - /alert_groups/star
          - /alert_groups/unstar
          - /alert_groups/update
          - /alert_rules/create
          - /alert_rules/delete
          - /alert_rules/get
          - /alert_rules/mute_preference/delete
          - /alert_rules/mute_preference/get
          - /alert_rules/mute_preference/set
          - /alert_rules/update
          - /alerts/enable_user_mobile_alert
          - /alerts/get
          - /alerts/get_unseen_alert_counts
          - /alerts/get_user_alert_preferences
          - /alerts/mark_alert_rules_seen
          - /alerts/update_alert_metadata
          - /device/new_events_fw/update
          - /device/presets/create_default
          - /device/presets/create_default/batch
          - /device/presets/get
          - /device/presets/get/batch
          - /device/presets/update
          - /device/presets/update/batch
          - /device/tamper/create_default
          - /live_link/create
          - /live_link/get
          - /migration/presets/clean_unused
          - /org/events/get
          - /ping
          - /push_token/update_state
          - /slack/config/delete
          - /slack/enabled/get
          - /slack/oauth/authorize/get
          - /teams/config/delete
          - /teams/enabled/get
          - /teams/oauth/authorize/get
          - /view/get_event_info
        unauthenticatedEndpoints:
          - /notifications/location_map
          - /slack/oauth/callback
          - /teams/bot/callback
          - /teams/oauth/callback
          - /token_force_logout
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vlive
    namespace: vinfra
    resourceVersion: "5009066587"
    uid: f1f4a3ba-004d-4767-aca8-55a606f76953
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlocaldns.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /ping
          - /v1/[0-9a-f-]{36}/redirect
          - /v1/[0-9a-f-]{36}/url
          - /v1/[A-Z0-9-]{14}/redirect
          - /v1/[A-Z0-9-]{14}/url
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vlocaldns
    namespace: vinfra
    resourceVersion: "5009066592"
    uid: e10a4f07-761d-46c8-b61f-e014e7f1e34d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlog.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /audit-log/details
          - /audit-log/event-hierarchy
          - /audit-log/event-types
          - /audit-log/export
          - /audit-log/list
          - /audit-log/message-codes
          - /audit-logs/cameras/get
          - /operations/list
        unauthenticatedEndpoints:
          - /openapi\.json
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vlog
    namespace: vinfra
    resourceVersion: "5009066595"
    uid: d91173a6-6d8b-4f7f-9fbc-ff5dbe261ef1
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlogging.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /logging/camera_status/[0-9a-f-]{36}
          - /logging/mobile_events
          - /logging/web_events
          - /logging/web_events/
        unauthenticatedEndpoints:
          - /access-ble-logs
          - /access-ble-logs/
          - /alarm-v2-logs
          - /alarm-v2-logs/
          - /api-metrics
          - /api-metrics/
          - /connect-box-logs
          - /connect-box-logs/
          - /core-command-logs
          - /core-command-logs/
          - /core-command-logs/api/v2/logs
          - /core-command-logs/api/v2/logs/
          - /datadog_events
          - /datadog_events/api/v2/rum
          - /datadog_events/api/v2/rum/
          - /desk-station-logs
          - /desk-station-logs/
          - /device-metrics
          - /device-metrics/
          - /internal/web/build-analytics
          - /internal/web/build-analytics/
          - /logging/camera_log
          - /logs/intercom-relay
          - /logs/intercom-relay/
          - /logs/relay
          - /ping
          - /ptz
          - /ptz/
          - /public-api-metrics
          - /public-api-metrics/
          - /security-logs
          - /security-logs/
          - /verkada-linux-logs
          - /verkada-linux-logs/
          - /vhecate-data-access-logs
          - /vhecate-data-access-logs/
          - /webrtc-statistics
          - /webrtc-statistics/
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /alarm-v2-logs
          - /alarm-v2-logs/
          - /connect-box-logs
          - /connect-box-logs/
          - /desk-station-logs
          - /desk-station-logs/
          - /device-metrics
          - /device-metrics/
          - /logs/relay
          - /logs/relay/
          - /verkada-linux-logs
          - /verkada-linux-logs/
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /alarm-v2-logs
          - /alarm-v2-logs/
          - /connect-box-logs
          - /connect-box-logs/
          - /desk-station-logs
          - /desk-station-logs/
          - /device-metrics
          - /device-metrics/
          - /logs/relay
          - /logs/relay/
          - /verkada-linux-logs
          - /verkada-linux-logs/
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /alarm-v2-logs
          - /alarm-v2-logs/
          - /connect-box-logs
          - /connect-box-logs/
          - /desk-station-logs
          - /desk-station-logs/
          - /device-metrics
          - /device-metrics/
          - /logs/relay
          - /logs/relay/
          - /verkada-linux-logs
          - /verkada-linux-logs/
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /alarm-v2-logs
          - /alarm-v2-logs/
          - /connect-box-logs
          - /connect-box-logs/
          - /desk-station-logs
          - /desk-station-logs/
          - /device-metrics
          - /device-metrics/
          - /logs/relay
          - /logs/relay/
          - /verkada-linux-logs
          - /verkada-linux-logs/
      - host: access.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /logs/intercom-relay
          - /logs/intercom-relay/
          - /logs/relay
          - /logs/relay/
      - host: vcerberus.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /logs/intercom-relay
          - /logs/intercom-relay/
          - /logs/relay
          - /logs/relay/
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vlogging
    namespace: vinfra
    resourceVersion: "5009066598"
    uid: 942686c9-6901-4578-a31a-59909bef915d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vmdm.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /
          - /MDMServiceConfig
          - /device/update_device_info
          - /device/update_serial_number
          - /mdm/checkin
          - /mdm/connect
          - /mdm/enroll
          - /push/[a-zA-Z0-9-]+
          - /scep
          - /v1/apps
          - /v1/blueprints
          - /v1/challenge
          - /v1/commands
          - /v1/config/certificate
          - /v1/dep-tokens
          - /v1/dep/account
          - /v1/dep/assign
          - /v1/dep/autoassigners
          - /v1/dep/devices
          - /v1/dep/profiles
          - /v1/dep/syncnow
          - /v1/devices
          - /v1/devices/[a-zA-Z0-9-]+/block
          - /v1/devices/[a-zA-Z0-9-]+/unblock
          - /v1/profiles
          - /v1/push/[a-zA-Z0-9-]+
          - /v1/users
          - /v1/vpp-tokens
          - /v1/vpp/apps
          - /v1/vpp/assets
          - /v1/vpp/licenses
          - /v1/vpp/metadata
          - /v1/vpp/serviceconfig
          - /vmdm-api/admin/command
          - /vmdm-api/admin/ensure_device_in_correct_state/all
          - /vmdm-api/admin/ensure_device_in_correct_state/enterprise
          - /vmdm-api/admin/get_device_command
          - /vmdm-api/admin/get_device_event
          - /vmdm-api/admin/get_device_info
          - /vmdm-api/admin/modify_device_profiles
          - /vmdm-api/admin/run_app_update
          - /vmdm-api/admin/run_enrollment_task
          - /vmdm-api/admin/set_device_verkada_serial_number
          - /vmdm-api/admin/set_is_development_device
          - /vmdm-api/admin/set_skip_single_app_mode
          - /vmdm-api/admin/set_use_enterprise_app
          - /vmdm-api/admin/update_application_config/all
          - /vmdm-api/device/request_shutdown
          - /vmdm-api/device/update_device_info
          - /vmdm-api/device/update_serial_number
          - /vmdm-api/ping
          - /vmdm-api/webhook
        unauthenticatedEndpoints:
          - /vmdm-api/device/latest_vx_version
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vmdm
    namespace: vinfra
    resourceVersion: "5009066600"
    uid: 3c1766cf-8b04-445c-bdb2-b0311192f60b
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/available
          - /library/enckey/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /library/gaps
          - /library/multivideo\.vkdae2ee
          - /library/video/size
          - /library/video\.m3u8
          - /library/video\.ts
          - /library/video\.vkdae2ee
          - /submit/enckey/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/[0-9]+
          - /submit/segments_batch/[0-9a-f-]{36}
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/available
          - /library/enckey/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /library/gaps
          - /library/multivideo\.vkdae2ee
          - /library/video/size
          - /library/video\.m3u8
          - /library/video\.ts
          - /library/video\.vkdae2ee
          - /submit/enckey/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/[0-9]+
          - /submit/segments_batch/[0-9a-f-]{36}
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/available
          - /library/enckey/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /library/gaps
          - /library/multivideo\.vkdae2ee
          - /library/video/size
          - /library/video\.m3u8
          - /library/video\.ts
          - /library/video\.vkdae2ee
          - /submit/enckey/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/[0-9]+
          - /submit/segments_batch/[0-9a-f-]{36}
      - host: vmedia.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/available
          - /library/enckey/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /library/gaps
          - /library/get_hd_rate
          - /library/get_hd_segment_intervals
          - /library/get_next_hd_interval
          - /library/get_oldest_hd_interval
          - /library/video/size
          - /library/video\.m3u8
          - /library/video\.ts
          - /library/video\.vkdae2ee
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/[0-9]+
          - /submit/segments_batch/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /get_media_key
          - /get_video_segments
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vmedia
    namespace: vinfra
    resourceVersion: "5009066603"
    uid: 6738266e-c0f6-44d1-acee-fd2b02ec7a8b
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: access.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /meerkat/[0-9a-f-]{36}
          - /meerkat/local_player/[0-9a-f-]{36}
          - /meerkat/ping
          - /meerkat/relay
          - /meerkat/toggle_door
          - /meerkat/unlock_door
          - /meerkat/unlock_entities
      - host: vcerberus.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /meerkat/[0-9a-f-]{36}
          - /meerkat/local_player/[0-9a-f-]{36}
          - /meerkat/ping
          - /meerkat/relay
          - /meerkat/toggle_door
          - /meerkat/unlock_door
          - /meerkat/unlock_entities
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vmeerkat
    namespace: vinfra
    resourceVersion: "5009066607"
    uid: cda13de5-32ca-4a21-a2cd-a94d7caf31fd
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmetrics-collector/metrics/submit
        unauthenticatedEndpoints:
          - /vmetrics-collector/ping
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmetrics-collector/metrics/submit
        unauthenticatedEndpoints:
          - /vmetrics-collector/ping
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmetrics-collector/metrics/submit
        unauthenticatedEndpoints:
          - /vmetrics-collector/ping
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmetrics-collector/metrics/submit
        unauthenticatedEndpoints:
          - /vmetrics-collector/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vmetricscollector
    namespace: vinfra
    resourceVersion: "5009066609"
    uid: 74de5a9b-1f42-463a-8331-608810b7ce51
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmotion/replay
          - /vmotion/ws/motion
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmotion/replay
          - /vmotion/ws/motion
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmotion/replay
          - /vmotion/ws/motion
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmotion/replay
          - /vmotion/ws/motion
      - host: vmotion.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /notifications/thumbnail
          - /ping
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /events/objects_by_track_id
          - /library/object_counts/beta
          - /library/object_search/v3
          - /library/objects_in_range/v3
        unauthenticatedEndpoints:
          - /internal/object_search/v3
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /events/objects_by_track_id
          - /library/object_counts/beta
          - /library/object_search/v3
          - /library/objects_in_range/v3
        unauthenticatedEndpoints:
          - /internal/object_search/v3
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /events/objects_by_track_id
          - /library/object_counts/beta
          - /library/object_search/v3
          - /library/objects_in_range/v3
        unauthenticatedEndpoints:
          - /internal/object_search/v3
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vmotion
    namespace: vinfra
    resourceVersion: "5009066612"
    uid: f53867cf-62b0-446b-b62e-617d5cf2294c
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vnet.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /activity_logs/[0-9a-f-]{36}
          - /bluetooth/fetch_info
          - /bluetooth/fetch_networks/[0-9a-f-]{36}
          - /bluetooth/forget_network
          - /bluetooth/get_site_default/[0-9a-f-]{36}
          - /bluetooth/initiate_fetch_network/[0-9a-f-]{36}
          - /bluetooth/set_network
          - /command/ws
          - /config/[0-9a-f-]{36}
          - /configs/batch/get
          - /configs/batch/set
          - /configurer/ws/[0-9a-f-]{36}
          - /device/alert_events_submit/[0-9a-f-]{36}
          - /device/wattage_output/[0-9a-f-]{36}
          - /device_count
          - /devices/[0-9a-f-]{36}
          - /devices/batch/commission
          - /devices/batch/move_unassigned
          - /devices/batch/status
          - /devices/by_connected
          - /devices/check_mac
          - /devices/commission
          - /devices/decommission
          - /devices/export/[0-9a-f-]{36}
          - /devices/list
          - /licensing/allowed_devices
          - /plugged_device
          - /plugged_device/[0-9a-f-]{36}
          - /plugged_devices/[0-9a-f-]{36}
          - /sim_configuration
          - /sim_configuration/[0-9a-f-]{36}
          - /sim_configuration/update_flag
          - /site/batch/config/network
          - /site/config/network/[0-9a-f-]{36}
          - /site/config/push/[0-9a-f-]{36}
          - /speedtest/[0-9a-f-]{36}
          - /uptime/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vnet
    namespace: vinfra
    resourceVersion: "5009066614"
    uid: 113e3ad3-6b34-444b-b06c-6a74b48cd536
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /site/disable
          - /site/enable
          - /site/update
          - /vnetcap/sites/state
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /site/disable
          - /site/enable
          - /site/update
          - /vnetcap/sites/state
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /site/disable
          - /site/enable
          - /site/update
          - /vnetcap/sites/state
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /site/disable
          - /site/enable
          - /site/update
          - /vnetcap/sites/state
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-16T23:33:28Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vnetcap
    namespace: vinfra
    resourceVersion: "5009066616"
    uid: 70646615-bffb-4139-a9ec-0997372389aa
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vnetsuite.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device/batch/information
          - /enforcement
          - /enforcement/override
          - /job/status
          - /license
          - /license/claim
          - /license/claim/dryrun
          - /license/history
          - /license/trials
          - /licensing/org/[0-9a-f-]{36}/get_compliance_info
          - /licensing/org/[0-9a-f-]{36}/trials
          - /logistics/get_organization_info
          - /logistics/org/[0-9a-f-]{36}/customer
          - /order/claim_order
          - /order/details
          - /order/unclaim_order
          - /organization/license
          - /partner/[0-9a-f-]{36}/order/csv
          - /partner/analytics
          - /partner/orders
          - /partner/orders/autocomplete
          - /v2/order/details
        unauthenticatedEndpoints:
          - /accounting/balance
          - /accounting/history
          - /accounting/history/csv
          - /accounting/income
          - /health_check
          - /internal/device/batch/information
          - /internal/license
          - /internal/license/children
          - /internal/license/claim
          - /internal/license/claim/dryrun
          - /internal/license/history
          - /internal/license/trial_serial_number
          - /internal/licensing/co_terming_group/[0-9a-f-]{36}/compliance_check
          - /internal/licensing/get_org_device_caps/[0-9a-f-]{36}
          - /internal/licensing/org/[0-9a-f-]{36}/co_terming_groups
          - /internal/licensing/org/[0-9a-f-]{36}/compliance_check
          - /internal/licensing/org/[0-9a-f-]{36}/trials
          - /internal/licensing/org/activated_renewals
          - /internal/logistics/get_organization_info
          - /internal/logistics/org/[0-9a-f-]{36}/customer
          - /internal/logistics/org/[0-9a-f-]{36}/sales_customer
          - /internal/order/rma/serial-numbers/filter
          - /internal/organization/license
          - /internal/serial_number/details
          - /internal/v2/accounting/balance
          - /internal/v2/accounting/history
          - /internal/v2/accounting/history/csv
          - /internal/v2/accounting/income
          - /internal/v2/license
          - /internal/v2/license/burn
          - /internal/v2/license/children
          - /internal/v2/license/claim
          - /internal/v2/license/claim/dryrun
          - /internal/v2/license/grant
          - /internal/v2/license/history
          - /internal/v2/license/history/csv
          - /internal/v2/license/split
          - /internal/v2/license/trials
          - /internal/v2/license/trials/raw
          - /internal/v2/license/unclaim
          - /internal/v2/license/update_job_schedule
          - /internal/v2/license/void
          - /internal/v2/licensing/get_org_logistics/[0-9a-f-]{36}
          - /internal/v2/order
          - /internal/v2/order/claim_order
          - /internal/v2/order/csv
          - /internal/v2/order/details
          - /internal/v2/order/unclaim_order
          - /internal/v2/organization/license
          - /internal/v3/license/grant
          - /internal/v3/license/grant/dryrun
          - /license/burn
          - /license/grant
          - /license/split
          - /license/unclaim
          - /license/update_job_schedule
          - /license/void
          - /logistics/org/[0-9a-f-]{36}/bookings
          - /order
          - /order/boomi/create_order
          - /order/external/create_order
          - /order/external/create_order_with_order_number
          - /order/netsuite/run
          - /org/[0-9a-f-]{36}/get_device_counts
          - /ping
          - /restricted_devices
          - /restricted_devices/[A-Z0-9-]{14}/logs
          - /restricted_devices/[A-Z0-9-]{14}/notes
          - /restricted_devices/csv_upload
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vnetsuite
    namespace: vinfra
    resourceVersion: "5009066620"
    uid: 457c11fc-522a-4b94-8a71-894da08bf887
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vnexus.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /add_customer
          - /find_new_customer_in_athena
          - /generate_reports
          - /get_customers
          - /ping
          - /retrieve_customer_metadata
          - /upload
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vnexus
    namespace: vinfra
    resourceVersion: "5009066622"
    uid: 10a5590e-4183-472c-86da-ebcfec723f5b
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/language_embedding/get
          - /user/custom_classes/add
          - /user/custom_classes/get
          - /user/custom_classes/set
          - /user/custom_detections/get
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/language_embedding/get
          - /user/custom_classes/add
          - /user/custom_classes/get
          - /user/custom_classes/set
          - /user/custom_detections/get
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/language_embedding/get
          - /user/custom_classes/add
          - /user/custom_classes/get
          - /user/custom_classes/set
          - /user/custom_detections/get
      - host: vomni.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/language_embedding/get
          - /user/custom_classes/add
          - /user/custom_classes/get
          - /user/custom_classes/set
          - /user/custom_detections/get
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vomni
    namespace: vinfra
    resourceVersion: "5009066625"
    uid: 47e25c39-65c3-4dd5-b1d2-94d2deea9f50
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/short_status
          - /camera/update
        unauthenticatedEndpoints:
          - /vonline/ws/online
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/short_status
          - /camera/update
        unauthenticatedEndpoints:
          - /vonline/ws/online
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/short_status
          - /camera/update
        unauthenticatedEndpoints:
          - /vonline/ws/online
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/short_status
          - /camera/update
        unauthenticatedEndpoints:
          - /vonline/ws/online
      - host: vonline.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/short_status
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vonline
    namespace: vinfra
    resourceVersion: "5009066628"
    uid: d8c13c5f-6c9b-4821-b5be-98952ab77e19
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /vopenapi/v1
          - /vopenapi/v1/((.+)\/)*([^\/]+)
          - /vopenapi/v1/((.+)\/)*([^\/]+)/[\w\.\-]+
          - /vopenapi/v1/ci-spec/[\w\.\-]+/[\w\.\-]+
          - /vopenapi/v1/ping
          - /vopenapi/v1/spec/[\w\.\-]+
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /vopenapi/v1
          - /vopenapi/v1/((.+)\/)*([^\/]+)
          - /vopenapi/v1/((.+)\/)*([^\/]+)/[\w\.\-]+
          - /vopenapi/v1/ci-spec/[\w\.\-]+/[\w\.\-]+
          - /vopenapi/v1/ping
          - /vopenapi/v1/spec/[\w\.\-]+
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /vopenapi/v1
          - /vopenapi/v1/((.+)\/)*([^\/]+)
          - /vopenapi/v1/((.+)\/)*([^\/]+)/[\w\.\-]+
          - /vopenapi/v1/ci-spec/[\w\.\-]+/[\w\.\-]+
          - /vopenapi/v1/ping
          - /vopenapi/v1/spec/[\w\.\-]+
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /vopenapi/v1
          - /vopenapi/v1/((.+)\/)*([^\/]+)
          - /vopenapi/v1/((.+)\/)*([^\/]+)/[\w\.\-]+
          - /vopenapi/v1/ci-spec/[\w\.\-]+/[\w\.\-]+
          - /vopenapi/v1/ping
          - /vopenapi/v1/spec/[\w\.\-]+
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vopenapi
    namespace: vinfra
    resourceVersion: "5009066631"
    uid: dbb53e56-1ca4-4b05-bac2-6096ca7b597a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vpair.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /live_link/pair
        unauthenticatedEndpoints:
          - /live_link/pair
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vpair
    namespace: vinfra
    resourceVersion: "5009066633"
    uid: 0f58b6cb-7e44-4cdc-8d6f-06bd448c5f4f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vparrot.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vparrot
    namespace: vinfra
    resourceVersion: "5009066636"
    uid: 218d2de0-2831-4dcf-874e-1bfa9f609b35
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vpeer-to-peer.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
          - /user/peer_connection_status
          - /user/peer_connection_status/2
      - host: vpeertopeer.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
          - /user/peer_connection_status
          - /user/peer_connection_status/2
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vpeertopeer
    namespace: vinfra
    resourceVersion: "5009066639"
    uid: ba06ab51-5d5e-4cd7-b321-0903d5466852
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprism.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /public/accountSequences/.{1,100}
          - /public/account_alerts
          - /public/activity_notification
          - /public/activity_points
          - /public/add_saved_accounts
          - /public/alerts
          - /public/all_templates
          - /public/append_new_opt_out_log
          - /public/buzz_scores
          - /public/contacts
          - /public/convert_zi_contact
          - /public/create_campaign_member
          - /public/create_contact
          - /public/create_contact_from_zoominfo
          - /public/create_custom_list
          - /public/create_feedback
          - /public/create_note
          - /public/crimeinfo
          - /public/custom_generate
          - /public/delete_note
          - /public/delete_task
          - /public/details
          - /public/enrich_zi_contacts
          - /public/feature_flags
          - /public/feedback
          - /public/generate
          - /public/generate_map_accounts
          - /public/generate_map_lifetime_customers
          - /public/generate_saved_accounts
          - /public/generatev2
          - /public/generic_logging_handler
          - /public/get_account_prescription
          - /public/get_accounts_by_id
          - /public/get_contact_hitlist
          - /public/get_custom_list
          - /public/goals
          - /public/gpt_generate_script
          - /public/gpt_summarize_desc
          - /public/highlights_activity
          - /public/leader_board
          - /public/load_template
          - /public/metric/accounts_prospected
          - /public/past_weekly_points
          - /public/recent_activity
          - /public/refresh_contacts
          - /public/remove_saved_accounts
          - /public/resync_note
          - /public/search_accounts
          - /public/search_contact
          - /public/search_locations
          - /public/search_opportunity
          - /public/sequence_templates
          - /public/sequence_templates/upsert
          - /public/sequences
          - /public/sequences/create
          - /public/sequences/schedule_email
          - /public/sequences/update_status
          - /public/signals
          - /public/tasks
          - /public/update_alerts
          - /public/update_contact
          - /public/update_custom_list
          - /public/update_goal
          - /public/update_note
          - /public/update_template
          - /public/upload_template
          - /public/upsert_contact_hitlist
          - /public/upsert_task
          - /public/user_templates
          - /public/users/connect_w_google
          - /public/users/google/send_email
          - /public/users/me
          - /public/users/update
          - /public/v2/gpt_generate_call_script
          - /public/v2/gpt_generate_email
          - /public/weekly_activities
          - /public/weekly_points_ranking
          - /public/weekly_progress
          - /public/zi_contacts
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vprism
    namespace: vinfra
    resourceVersion: "5009066641"
    uid: e544b967-ce2b-461b-bc17-e63ea818ea00
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprochronicle.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /activity_feed_event/list
          - /alarm_events/get
          - /alarm_system/status_event/list
          - /alarm_system_status_event/list
          - /device_event/get
          - /device_event/list
          - /events/create
          - /online_events_for_devices_in_org
          - /partition_tripped_event/list
          - /signal_strength_metrics/list
          - /subscribe/events
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vprochronicle
    namespace: vinfra
    resourceVersion: "5009066644"
    uid: 0cf5037a-d751-4fbb-9ede-90e66dbf4f3c
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprocomm.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alarm_system/get_fire_state
          - /alarm_system/get_state
          - /alarm_system/update_config_now
          - /connection_info/list
          - /device_state/list
          - /keypad/ports
          - /output/user_disable
          - /output/user_enable
          - /partition/arm
          - /partition/disarm
          - /partition/resolve
          - /response_config_id/disarm_by_agent
          - /submit/wired_event
          - /submit/wireless_event
          - /submit/wireless_initial_state_event
          - /troubleshoot/user_reboot
        unauthenticatedEndpoints:
          - /partition/resolve_by_agent
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vprocomm
    namespace: vinfra
    resourceVersion: "5009066648"
    uid: e58eb0c1-6587-4580-b73e-5ef4ee05079a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproconfig.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access_control/delete_door_action
          - /access_control/get_door_actions
          - /access_control/set_door_action
          - /alarm_system/add_devices
          - /alarm_system/create
          - /alarm_system/create_leaderless
          - /alarm_system/delete
          - /alarm_system/get
          - /alarm_system/get_all
          - /alarm_system/get_devices
          - /alarm_system/list
          - /alarm_system/update_address
          - /alarm_system/update_site
          - /arm_schedule/alarm_system/create
          - /arm_schedule/override
          - /arm_schedule/partition/create
          - /arm_schedule/update
          - /arm_schedule_events/update
          - /arm_schedule_override/delete
          - /arm_schedule_override/update
          - /arm_schedule_override_events/update
          - /delay_setting/create
          - /delay_setting/update_alarm_delay
          - /delay_setting/update_arm_delay
          - /device/console_pin_config/set
          - /device/create_smoke_sensor_conventional
          - /device/create_wired_input
          - /device/create_wired_output
          - /device/decommission
          - /device/delete
          - /device/get
          - /device/input_pin_config/set
          - /device/name/set
          - /device/nearby_camera/add
          - /device/nearby_camera/delete
          - /device/output_pin_config/set
          - /device/sensor_config/set
          - /internal/site/output_devices
          - /internal/unassigned_device/commission_bulk
          - /keycode/create
          - /keycode/delete
          - /keycode/generate
          - /keycode/list
          - /keycode/update
          - /org/get_devices_and_alarm_systems
          - /partition/assign_devices
          - /partition/assign_response_config
          - /partition/create
          - /partition/delete
          - /partition/get
          - /partition/get_devices
          - /partition/list
          - /partition/name/set
          - /partition/unassign_response_config
          - /postal_address/get
          - /sensor_policy/set
          - /unassigned_device/commission_bulk
          - /unassigned_device/set_up_alarm_device
          - /unassigned_device/set_up_colossus
          - /unassigned_device/set_up_mantis
          - /unassigned_device/set_up_simon
          - /unassigned_device/set_up_spalding
        unauthenticatedEndpoints:
          - /ping
          - /synthetic/get_state
          - /vcard
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vproconfig
    namespace: vinfra
    resourceVersion: "5009066653"
    uid: 3922068d-f4ab-4daf-a189-ee7c56ed657f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproresponse.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /incident/delete
          - /incident/get
          - /incident/get_active
          - /incident/get_by_time_range
          - /incident/list
          - /incident/request_dispatch
          - /incident/resolve
          - /incident/share
          - /incident/update_viewed
          - /response/config/create
          - /response/config/delete
          - /response/config/update
          - /response/site/create
          - /response/site/delete
          - /response/site/get
          - /response/site/list
          - /response/site/update
          - /site/camera_trigger/count
          - /site/license/count
          - /web/incident/get
          - /web/incident/get_by_time_range
        unauthenticatedEndpoints:
          - /incident/redeem
          - /incident/redeem/[\w\.\-]+
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vproresponse
    namespace: vinfra
    resourceVersion: "5009066657"
    uid: b813f79a-cedf-48d5-b5c0-41efc51a7aa7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[\w\-. +%]+/download/[\w\-. +%]+
          - /[\w\-. +%]+/version
          - /activity/add
          - /analytics/cv_enabled_cameras
          - /app/live_link
          - /app/live_link/contacts/create
          - /app/live_link/contacts/delete
          - /app/live_link/contacts/edit
          - /app/live_link/contacts/get
          - /app/live_link/contacts/get_shared
          - /app/live_link/contacts/list
          - /app/live_link/contacts/revoke
          - /app/live_link/contacts/revoke_all
          - /app/live_link/contacts/share_link
          - /app/live_link/create
          - /app/live_link/get_contacts_shared_to
          - /app/live_link/revoke
          - /audit_log/get_camera_log
          - /audit_log/get_organization_log
          - /building/create
          - /building/delete
          - /building/list
          - /building/update
          - /buildings
          - /camera/audio/batch/get
          - /camera/audio/enable
          - /camera/auto_level/get
          - /camera/auto_level/set
          - /camera/autofocus
          - /camera/batch/get_low_bandwidth_mode
          - /camera/batch/get_readonly_mode
          - /camera/batch/lookup
          - /camera/batch/set_low_bandwidth_mode
          - /camera/batch/set_readonly_mode
          - /camera/calibration_images/get
          - /camera/calibration_matrix/delete
          - /camera/calibration_matrix/get
          - /camera/calibration_status
          - /camera/cloud_backup/is_enabled
          - /camera/codec/set
          - /camera/color/get_temperature
          - /camera/color/get_tint
          - /camera/color/set_temperature
          - /camera/color/set_tint
          - /camera/config/merge
          - /camera/cv/get_enabled_features
          - /camera/cv/set_enabled_features
          - /camera/cv_features/batch/get
          - /camera/cv_features/batch/set
          - /camera/decommission
          - /camera/deleted
          - /camera/download_offline_mode_certificate
          - /camera/edit/batch
          - /camera/event
          - /camera/exposure/get_compensation
          - /camera/exposure/set_compensation
          - /camera/favorites/get
          - /camera/favorites/modify
          - /camera/firmware_relay/((.+)\/)*([^\/]+)
          - /camera/fisheye/mode/get
          - /camera/fisheye/mode/set
          - /camera/focus_target/get
          - /camera/focus_target/set
          - /camera/get
          - /camera/get_calibrations_ready
          - /camera/get_cb_status
          - /camera/get_ffu_binaries
          - /camera/get_lan_url
          - /camera/groups/get
          - /camera/has_id
          - /camera/hq_bitrate/get
          - /camera/hq_bitrate/set
          - /camera/identify
          - /camera/image/settings
          - /camera/init/batch
          - /camera/init/perform
          - /camera/init/sharded
          - /camera/lan_token
          - /camera/level_assist
          - /camera/level_assist_active
          - /camera/location/set
          - /camera/manual_focus
          - /camera/manual_piris
          - /camera/manual_zoom
          - /camera/name/get
          - /camera/name/set
          - /camera/network_quality/submit
          - /camera/next_device/delete
          - /camera/next_device/get
          - /camera/next_device/update
          - /camera/night_threshold/get
          - /camera/night_threshold/set
          - /camera/operating_mode/get
          - /camera/operating_mode/set
          - /camera/privacy/set
          - /camera/public_key
          - /camera/reboot
          - /camera/release_channel/set
          - /camera/retention/get
          - /camera/retention/next_upload
          - /camera/retention/report
          - /camera/rotate
          - /camera/rotate/get
          - /camera/rotate/set
          - /camera/serial/get
          - /camera/site/batch/set
          - /camera/site/get
          - /camera/sq_bitrate/get
          - /camera/stats/get
          - /camera/stats/get_sum
          - /camera/storage/failure/get
          - /camera/storage/failure/set
          - /camera/storage/failure/unset
          - /camera/timezone/get
          - /camera/timezone/set
          - /camera/upload/logs
          - /camera/upload_sd_repair_result
          - /camera/wdr/enable
          - /camera/wdr/is_enabled
          - /camera/wifi/delete
          - /camera/wifi/get
          - /camera/wifi/set
          - /camera_grid/copy
          - /camera_grid/create
          - /camera_grid/delete
          - /camera_grid/list
          - /camera_grid/update
          - /cameras/get_mac_addresses
          - /cameras/operating_mode/get
          - /cameras_in_org
          - /cloud/enable_static_ip
          - /cloud/static_ips
          - /command/user/init
          - /command_version/set
          - /compliance/check_address
          - /customer/get
          - /default_endpoints
          - /device/batch/information
          - /device/decommission
          - /device/delete_orderproduct
          - /device/get_or_create_default_site
          - /device/initialize
          - /device/notes/get
          - /device/notes/set
          - /device/stats/get
          - /feature/is_enabled
          - /feedback/add
          - /firmware/((.+)\/)*([^\/]+)
          - /firmware/vtoolbox/((.+)\/)*([^\/]+)
          - /floor/create
          - /floor/delete
          - /floor/list
          - /floor/update
          - /floor_plan/change_walls
          - /floor_plan/create
          - /floor_plan/delete
          - /floor_plan/get_image
          - /floor_plan/get_metadata
          - /floor_plan/mobile_get_zip_and_bounds
          - /floor_plan/retrieve_walls
          - /floor_plan/set_floor
          - /floor_plan/set_metadata
          - /floor_plan/upload_image
          - /floorplan/get_fov_mappings
          - /floors
          - /info/device/lookup
          - /info/release_channel/get_all
          - /local_player/doors
          - /local_player/init
          - /local_player/set_grid
          - /local_player/status
          - /local_player/status/update
          - /local_player/update
          - /local_player/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /local_player/users/[0-9a-f-]{36}
          - /local_player/users/list
          - /local_player/users/update
          - /logistics/camera/short_status
          - /manufacturer/reset
          - /model/all_display_names
          - /model/capabilities
          - /model/config/merge
          - /models/list
          - /non_superuser/feature_flags/get_all
          - /notifications/group_preferences/set
          - /notifications/mute_preferences/get
          - /notifications/mute_preferences/set
          - /notifications/preferences/get
          - /notifications/preferences/set
          - /org/[0-9a-f-]{36}/cameras
          - /org/[0-9a-f-]{36}/users/list
          - /org/add_user
          - /org/admin
          - /org/camera/list
          - /org/camera_group/add_camera
          - /org/camera_group/batch_move_cameras
          - /org/camera_group/create
          - /org/camera_group/delete
          - /org/camera_group/modify
          - /org/camera_group/remove_camera
          - /org/camera_group/reorder_cameras
          - /org/camera_group/sites_to_grids
          - /org/camera_group/users
          - /org/cameras/get_csv
          - /org/cameras/get_cv_enabled
          - /org/create
          - /org/cv/set_enabled_features
          - /org/delete
          - /org/disable_cloud_backup
          - /org/download_offline_mode_certificate
          - /org/enable_offline_mode
          - /org/encryption_settings/get
          - /org/encryption_settings/set
          - /org/events
          - /org/features/get
          - /org/get_camera_groups
          - /org/invite
          - /org/modify
          - /org/remove_user
          - /org/remove_users
          - /org/resend_invite
          - /org/send_pass_app_invite
          - /org/set_user_permissions
          - /org/settings/get
          - /org/settings/set
          - /org/settings/update
          - /org/site/list
          - /org/toggle_hipaa
          - /org/users
          - /organization/[0-9a-f-]{36}/user/employment
          - /organization/[0-9a-f-]{36}/user/name
          - /organization/[0-9a-f-]{36}/user/phone
          - /organization/[0-9a-f-]{36}/users
          - /organization/[0-9a-f-]{36}/users/search
          - /particulate_sensors
          - /resource/create
          - /resource/get
          - /serial_number/assignment_upload
          - /serial_number/list
          - /site/[0-9a-f-]{36}/user/invite
          - /site/camera/list
          - /spurdog/view_settings/get
          - /spurdog/view_settings/update
          - /ssl/create_local_device_root_certificate_authority
          - /user/become_status
          - /user/camera/batch/compliance/list
          - /user/camera/compliance/list
          - /user/camera/compliance/override
          - /user/camera/compliance/remove
          - /user/camera/config/batch/delete
          - /user/camera/config/batch/get
          - /user/camera/config/batch/set
          - /user/camera/config/delete
          - /user/camera/config/get
          - /user/camera/config/set
          - /user/contact_info
          - /user/email/change
          - /user/email/send_verification_code
          - /user/get_orgs
          - /user/linked_accounts
          - /user/locale/set
          - /user/name
          - /user/passwd
          - /user/phone
          - /user/phone/verify
          - /user/profile_image/get
          - /user/profile_image/upload
          - /user/replace_app_token
          - /user/set_active
          - /user/settings/get
          - /user/settings/set
          - /user/settings/update
          - /user/toggle_become
          - /users/get_or_create
          - /v1/device/information
          - /vayu/batch/commission
          - /vayu/get_data
          - /vayu/list
          - /vayu/set
          - /vayu/submit_data
          - /vayu/update
        unauthenticatedEndpoints:
          - /app/live_link/redeem
          - /camera/auth/init
          - /camera/org_id/get
          - /cameras_release_tool/get_cameras
          - /cameras_release_tool/set_default_firmware_version
          - /cameras_release_tool/set_firmware_version
          - /check_auth
          - /command_version/get
          - /customer/get_details
          - /device/auth/init
          - /direct/ping
          - /embed/[0-9a-f-]{36}/
          - /firmware/((.+)\/)*([^\/]+)
          - /internal/camera/config/get
          - /internal/camera/config/get/filtered
          - /internal/camera/config/set/single
          - /internal/camera/healthstatus
          - /internal/camera/lookup
          - /internal/camera/release_channel/set
          - /internal/org/get
          - /internal/org/remove_user
          - /internal/orgs/get_for_user
          - /internal/send_email
          - /internal/users/search
          - /is_online
          - /logs/relay-intrusion-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/1894804/store/
          - /org/check_shortname/[^/]*[0-9a-z]+[^/]*
          - /org/generate_shortname/.{1,100}
          - /org/invitation/info
          - /ping
          - /ping-command
          - /ping-device
          - /prestart/get
          - /time
          - /twilio/c8e78359-da58-4612-8ce5-3381fa9bd484
          - /user/add_cookie_user_id
          - /user/auth_challenges
          - /user/create
          - /user/email/verify
          - /user/login
          - /user/logout
          - /user/reset/redeem
          - /user/saml/sso/[0-9a-zA-Z._-]{1,64}
          - /user/saml/sso/login/redirect
          - /user/send_org_membership
          - /user/session_accounts
          - /user/validate_short_name
          - /vprovision-ping
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[\w\-. +%]+/download/[\w\-. +%]+
          - /[\w\-. +%]+/version
          - /activity/add
          - /analytics/cv_enabled_cameras
          - /app/live_link
          - /app/live_link/contacts/create
          - /app/live_link/contacts/delete
          - /app/live_link/contacts/edit
          - /app/live_link/contacts/get
          - /app/live_link/contacts/get_shared
          - /app/live_link/contacts/list
          - /app/live_link/contacts/revoke
          - /app/live_link/contacts/revoke_all
          - /app/live_link/contacts/share_link
          - /app/live_link/create
          - /app/live_link/get_contacts_shared_to
          - /app/live_link/revoke
          - /audit_log/get_camera_log
          - /audit_log/get_organization_log
          - /building/create
          - /building/delete
          - /building/list
          - /building/update
          - /buildings
          - /camera/audio/batch/get
          - /camera/audio/enable
          - /camera/auto_level/get
          - /camera/auto_level/set
          - /camera/autofocus
          - /camera/batch/get_low_bandwidth_mode
          - /camera/batch/get_readonly_mode
          - /camera/batch/lookup
          - /camera/batch/set_low_bandwidth_mode
          - /camera/batch/set_readonly_mode
          - /camera/calibration_images/get
          - /camera/calibration_matrix/delete
          - /camera/calibration_matrix/get
          - /camera/calibration_status
          - /camera/cloud_backup/is_enabled
          - /camera/codec/set
          - /camera/color/get_temperature
          - /camera/color/get_tint
          - /camera/color/set_temperature
          - /camera/color/set_tint
          - /camera/config/merge
          - /camera/cv/get_enabled_features
          - /camera/cv/set_enabled_features
          - /camera/cv_features/batch/get
          - /camera/cv_features/batch/set
          - /camera/decommission
          - /camera/deleted
          - /camera/download_offline_mode_certificate
          - /camera/edit/batch
          - /camera/event
          - /camera/exposure/get_compensation
          - /camera/exposure/set_compensation
          - /camera/favorites/get
          - /camera/favorites/modify
          - /camera/firmware_relay/((.+)\/)*([^\/]+)
          - /camera/fisheye/mode/get
          - /camera/fisheye/mode/set
          - /camera/focus_target/get
          - /camera/focus_target/set
          - /camera/get
          - /camera/get_calibrations_ready
          - /camera/get_cb_status
          - /camera/get_ffu_binaries
          - /camera/get_lan_url
          - /camera/groups/get
          - /camera/has_id
          - /camera/hq_bitrate/get
          - /camera/hq_bitrate/set
          - /camera/identify
          - /camera/image/settings
          - /camera/init/batch
          - /camera/init/perform
          - /camera/init/sharded
          - /camera/lan_token
          - /camera/level_assist
          - /camera/level_assist_active
          - /camera/location/set
          - /camera/manual_focus
          - /camera/manual_piris
          - /camera/manual_zoom
          - /camera/name/get
          - /camera/name/set
          - /camera/network_quality/submit
          - /camera/next_device/delete
          - /camera/next_device/get
          - /camera/next_device/update
          - /camera/night_threshold/get
          - /camera/night_threshold/set
          - /camera/operating_mode/get
          - /camera/operating_mode/set
          - /camera/privacy/set
          - /camera/public_key
          - /camera/reboot
          - /camera/release_channel/set
          - /camera/retention/get
          - /camera/retention/next_upload
          - /camera/retention/report
          - /camera/rotate
          - /camera/rotate/get
          - /camera/rotate/set
          - /camera/serial/get
          - /camera/site/batch/set
          - /camera/site/get
          - /camera/sq_bitrate/get
          - /camera/stats/get
          - /camera/stats/get_sum
          - /camera/storage/failure/get
          - /camera/storage/failure/set
          - /camera/storage/failure/unset
          - /camera/timezone/get
          - /camera/timezone/set
          - /camera/upload/logs
          - /camera/upload_sd_repair_result
          - /camera/wdr/enable
          - /camera/wdr/is_enabled
          - /camera/wifi/delete
          - /camera/wifi/get
          - /camera/wifi/set
          - /camera_grid/copy
          - /camera_grid/create
          - /camera_grid/delete
          - /camera_grid/list
          - /camera_grid/update
          - /cameras/get_mac_addresses
          - /cameras/operating_mode/get
          - /cameras_in_org
          - /cloud/enable_static_ip
          - /cloud/static_ips
          - /command/user/init
          - /command_version/set
          - /compliance/check_address
          - /customer/get
          - /default_endpoints
          - /device/batch/information
          - /device/decommission
          - /device/delete_orderproduct
          - /device/get_or_create_default_site
          - /device/initialize
          - /device/notes/get
          - /device/notes/set
          - /device/stats/get
          - /feature/is_enabled
          - /feedback/add
          - /firmware/((.+)\/)*([^\/]+)
          - /firmware/vtoolbox/((.+)\/)*([^\/]+)
          - /floor/create
          - /floor/delete
          - /floor/list
          - /floor/update
          - /floor_plan/change_walls
          - /floor_plan/create
          - /floor_plan/delete
          - /floor_plan/get_image
          - /floor_plan/get_metadata
          - /floor_plan/mobile_get_zip_and_bounds
          - /floor_plan/retrieve_walls
          - /floor_plan/set_floor
          - /floor_plan/set_metadata
          - /floor_plan/upload_image
          - /floorplan/get_fov_mappings
          - /floors
          - /info/device/lookup
          - /info/release_channel/get_all
          - /local_player/doors
          - /local_player/init
          - /local_player/set_grid
          - /local_player/status
          - /local_player/status/update
          - /local_player/update
          - /local_player/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /local_player/users/[0-9a-f-]{36}
          - /local_player/users/list
          - /local_player/users/update
          - /logistics/camera/short_status
          - /manufacturer/reset
          - /model/all_display_names
          - /model/capabilities
          - /model/config/merge
          - /models/list
          - /non_superuser/feature_flags/get_all
          - /notifications/group_preferences/set
          - /notifications/mute_preferences/get
          - /notifications/mute_preferences/set
          - /notifications/preferences/get
          - /notifications/preferences/set
          - /org/[0-9a-f-]{36}/cameras
          - /org/[0-9a-f-]{36}/users/list
          - /org/add_user
          - /org/admin
          - /org/camera/list
          - /org/camera_group/add_camera
          - /org/camera_group/batch_move_cameras
          - /org/camera_group/create
          - /org/camera_group/delete
          - /org/camera_group/modify
          - /org/camera_group/remove_camera
          - /org/camera_group/reorder_cameras
          - /org/camera_group/sites_to_grids
          - /org/camera_group/users
          - /org/cameras/get_csv
          - /org/cameras/get_cv_enabled
          - /org/create
          - /org/cv/set_enabled_features
          - /org/delete
          - /org/disable_cloud_backup
          - /org/download_offline_mode_certificate
          - /org/enable_offline_mode
          - /org/encryption_settings/get
          - /org/encryption_settings/set
          - /org/events
          - /org/features/get
          - /org/get_camera_groups
          - /org/invite
          - /org/modify
          - /org/remove_user
          - /org/remove_users
          - /org/resend_invite
          - /org/send_pass_app_invite
          - /org/set_user_permissions
          - /org/settings/get
          - /org/settings/set
          - /org/settings/update
          - /org/site/list
          - /org/toggle_hipaa
          - /org/users
          - /organization/[0-9a-f-]{36}/user/employment
          - /organization/[0-9a-f-]{36}/user/name
          - /organization/[0-9a-f-]{36}/user/phone
          - /organization/[0-9a-f-]{36}/users
          - /organization/[0-9a-f-]{36}/users/search
          - /particulate_sensors
          - /resource/create
          - /resource/get
          - /serial_number/assignment_upload
          - /serial_number/list
          - /site/[0-9a-f-]{36}/user/invite
          - /site/camera/list
          - /spurdog/view_settings/get
          - /spurdog/view_settings/update
          - /ssl/create_local_device_root_certificate_authority
          - /user/become_status
          - /user/camera/batch/compliance/list
          - /user/camera/compliance/list
          - /user/camera/compliance/override
          - /user/camera/compliance/remove
          - /user/camera/config/batch/delete
          - /user/camera/config/batch/get
          - /user/camera/config/batch/set
          - /user/camera/config/delete
          - /user/camera/config/get
          - /user/camera/config/set
          - /user/contact_info
          - /user/email/change
          - /user/email/send_verification_code
          - /user/get_orgs
          - /user/linked_accounts
          - /user/locale/set
          - /user/name
          - /user/passwd
          - /user/phone
          - /user/phone/verify
          - /user/profile_image/get
          - /user/profile_image/upload
          - /user/replace_app_token
          - /user/set_active
          - /user/settings/get
          - /user/settings/set
          - /user/settings/update
          - /user/toggle_become
          - /users/get_or_create
          - /v1/device/information
          - /vayu/batch/commission
          - /vayu/get_data
          - /vayu/list
          - /vayu/set
          - /vayu/submit_data
          - /vayu/update
        unauthenticatedEndpoints:
          - /app/live_link/redeem
          - /camera/auth/init
          - /camera/org_id/get
          - /cameras_release_tool/get_cameras
          - /cameras_release_tool/set_default_firmware_version
          - /cameras_release_tool/set_firmware_version
          - /check_auth
          - /command_version/get
          - /customer/get_details
          - /device/auth/init
          - /direct/ping
          - /embed/[0-9a-f-]{36}/
          - /firmware/((.+)\/)*([^\/]+)
          - /internal/camera/config/get
          - /internal/camera/config/get/filtered
          - /internal/camera/config/set/single
          - /internal/camera/healthstatus
          - /internal/camera/lookup
          - /internal/camera/release_channel/set
          - /internal/org/get
          - /internal/org/remove_user
          - /internal/orgs/get_for_user
          - /internal/send_email
          - /internal/users/search
          - /is_online
          - /logs/relay-intrusion-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/1894804/store/
          - /org/check_shortname/[^/]*[0-9a-z]+[^/]*
          - /org/generate_shortname/.{1,100}
          - /org/invitation/info
          - /ping
          - /ping-command
          - /ping-device
          - /prestart/get
          - /time
          - /twilio/c8e78359-da58-4612-8ce5-3381fa9bd484
          - /user/add_cookie_user_id
          - /user/auth_challenges
          - /user/create
          - /user/email/verify
          - /user/login
          - /user/logout
          - /user/reset/redeem
          - /user/saml/sso/[0-9a-zA-Z._-]{1,64}
          - /user/saml/sso/login/redirect
          - /user/send_org_membership
          - /user/session_accounts
          - /user/validate_short_name
          - /vprovision-ping
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[\w\-. +%]+/download/[\w\-. +%]+
          - /[\w\-. +%]+/version
          - /activity/add
          - /analytics/cv_enabled_cameras
          - /app/live_link
          - /app/live_link/contacts/create
          - /app/live_link/contacts/delete
          - /app/live_link/contacts/edit
          - /app/live_link/contacts/get
          - /app/live_link/contacts/get_shared
          - /app/live_link/contacts/list
          - /app/live_link/contacts/revoke
          - /app/live_link/contacts/revoke_all
          - /app/live_link/contacts/share_link
          - /app/live_link/create
          - /app/live_link/get_contacts_shared_to
          - /app/live_link/revoke
          - /audit_log/get_camera_log
          - /audit_log/get_organization_log
          - /building/create
          - /building/delete
          - /building/list
          - /building/update
          - /buildings
          - /camera/audio/batch/get
          - /camera/audio/enable
          - /camera/auto_level/get
          - /camera/auto_level/set
          - /camera/autofocus
          - /camera/batch/get_low_bandwidth_mode
          - /camera/batch/get_readonly_mode
          - /camera/batch/lookup
          - /camera/batch/set_low_bandwidth_mode
          - /camera/batch/set_readonly_mode
          - /camera/calibration_images/get
          - /camera/calibration_matrix/delete
          - /camera/calibration_matrix/get
          - /camera/calibration_status
          - /camera/cloud_backup/is_enabled
          - /camera/codec/set
          - /camera/color/get_temperature
          - /camera/color/get_tint
          - /camera/color/set_temperature
          - /camera/color/set_tint
          - /camera/config/merge
          - /camera/cv/get_enabled_features
          - /camera/cv/set_enabled_features
          - /camera/cv_features/batch/get
          - /camera/cv_features/batch/set
          - /camera/decommission
          - /camera/deleted
          - /camera/download_offline_mode_certificate
          - /camera/edit/batch
          - /camera/event
          - /camera/exposure/get_compensation
          - /camera/exposure/set_compensation
          - /camera/favorites/get
          - /camera/favorites/modify
          - /camera/firmware_relay/((.+)\/)*([^\/]+)
          - /camera/fisheye/mode/get
          - /camera/fisheye/mode/set
          - /camera/focus_target/get
          - /camera/focus_target/set
          - /camera/get
          - /camera/get_calibrations_ready
          - /camera/get_cb_status
          - /camera/get_ffu_binaries
          - /camera/get_lan_url
          - /camera/groups/get
          - /camera/has_id
          - /camera/hq_bitrate/get
          - /camera/hq_bitrate/set
          - /camera/identify
          - /camera/image/settings
          - /camera/init/batch
          - /camera/init/perform
          - /camera/init/sharded
          - /camera/lan_token
          - /camera/level_assist
          - /camera/level_assist_active
          - /camera/location/set
          - /camera/manual_focus
          - /camera/manual_piris
          - /camera/manual_zoom
          - /camera/name/get
          - /camera/name/set
          - /camera/network_quality/submit
          - /camera/next_device/delete
          - /camera/next_device/get
          - /camera/next_device/update
          - /camera/night_threshold/get
          - /camera/night_threshold/set
          - /camera/operating_mode/get
          - /camera/operating_mode/set
          - /camera/privacy/set
          - /camera/public_key
          - /camera/reboot
          - /camera/release_channel/set
          - /camera/retention/get
          - /camera/retention/next_upload
          - /camera/retention/report
          - /camera/rotate
          - /camera/rotate/get
          - /camera/rotate/set
          - /camera/serial/get
          - /camera/site/batch/set
          - /camera/site/get
          - /camera/sq_bitrate/get
          - /camera/stats/get
          - /camera/stats/get_sum
          - /camera/storage/failure/get
          - /camera/storage/failure/set
          - /camera/storage/failure/unset
          - /camera/timezone/get
          - /camera/timezone/set
          - /camera/upload/logs
          - /camera/upload_sd_repair_result
          - /camera/wdr/enable
          - /camera/wdr/is_enabled
          - /camera/wifi/delete
          - /camera/wifi/get
          - /camera/wifi/set
          - /camera_grid/copy
          - /camera_grid/create
          - /camera_grid/delete
          - /camera_grid/list
          - /camera_grid/update
          - /cameras/get_mac_addresses
          - /cameras/operating_mode/get
          - /cameras_in_org
          - /cloud/enable_static_ip
          - /cloud/static_ips
          - /command/user/init
          - /command_version/set
          - /compliance/check_address
          - /customer/get
          - /default_endpoints
          - /device/batch/information
          - /device/decommission
          - /device/delete_orderproduct
          - /device/get_or_create_default_site
          - /device/initialize
          - /device/notes/get
          - /device/notes/set
          - /device/stats/get
          - /feature/is_enabled
          - /feedback/add
          - /firmware/((.+)\/)*([^\/]+)
          - /firmware/vtoolbox/((.+)\/)*([^\/]+)
          - /floor/create
          - /floor/delete
          - /floor/list
          - /floor/update
          - /floor_plan/change_walls
          - /floor_plan/create
          - /floor_plan/delete
          - /floor_plan/get_image
          - /floor_plan/get_metadata
          - /floor_plan/mobile_get_zip_and_bounds
          - /floor_plan/retrieve_walls
          - /floor_plan/set_floor
          - /floor_plan/set_metadata
          - /floor_plan/upload_image
          - /floorplan/get_fov_mappings
          - /floors
          - /info/device/lookup
          - /info/release_channel/get_all
          - /local_player/doors
          - /local_player/init
          - /local_player/set_grid
          - /local_player/status
          - /local_player/status/update
          - /local_player/update
          - /local_player/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /local_player/users/[0-9a-f-]{36}
          - /local_player/users/list
          - /local_player/users/update
          - /logistics/camera/short_status
          - /manufacturer/reset
          - /model/all_display_names
          - /model/capabilities
          - /model/config/merge
          - /models/list
          - /non_superuser/feature_flags/get_all
          - /notifications/group_preferences/set
          - /notifications/mute_preferences/get
          - /notifications/mute_preferences/set
          - /notifications/preferences/get
          - /notifications/preferences/set
          - /org/[0-9a-f-]{36}/cameras
          - /org/[0-9a-f-]{36}/users/list
          - /org/add_user
          - /org/admin
          - /org/camera/list
          - /org/camera_group/add_camera
          - /org/camera_group/batch_move_cameras
          - /org/camera_group/create
          - /org/camera_group/delete
          - /org/camera_group/modify
          - /org/camera_group/remove_camera
          - /org/camera_group/reorder_cameras
          - /org/camera_group/sites_to_grids
          - /org/camera_group/users
          - /org/cameras/get_csv
          - /org/cameras/get_cv_enabled
          - /org/create
          - /org/cv/set_enabled_features
          - /org/delete
          - /org/disable_cloud_backup
          - /org/download_offline_mode_certificate
          - /org/enable_offline_mode
          - /org/encryption_settings/get
          - /org/encryption_settings/set
          - /org/events
          - /org/features/get
          - /org/get_camera_groups
          - /org/invite
          - /org/modify
          - /org/remove_user
          - /org/remove_users
          - /org/resend_invite
          - /org/send_pass_app_invite
          - /org/set_user_permissions
          - /org/settings/get
          - /org/settings/set
          - /org/settings/update
          - /org/site/list
          - /org/toggle_hipaa
          - /org/users
          - /organization/[0-9a-f-]{36}/user/employment
          - /organization/[0-9a-f-]{36}/user/name
          - /organization/[0-9a-f-]{36}/user/phone
          - /organization/[0-9a-f-]{36}/users
          - /organization/[0-9a-f-]{36}/users/search
          - /particulate_sensors
          - /resource/create
          - /resource/get
          - /serial_number/assignment_upload
          - /serial_number/list
          - /site/[0-9a-f-]{36}/user/invite
          - /site/camera/list
          - /spurdog/view_settings/get
          - /spurdog/view_settings/update
          - /ssl/create_local_device_root_certificate_authority
          - /user/become_status
          - /user/camera/batch/compliance/list
          - /user/camera/compliance/list
          - /user/camera/compliance/override
          - /user/camera/compliance/remove
          - /user/camera/config/batch/delete
          - /user/camera/config/batch/get
          - /user/camera/config/batch/set
          - /user/camera/config/delete
          - /user/camera/config/get
          - /user/camera/config/set
          - /user/contact_info
          - /user/email/change
          - /user/email/send_verification_code
          - /user/get_orgs
          - /user/linked_accounts
          - /user/locale/set
          - /user/name
          - /user/passwd
          - /user/phone
          - /user/phone/verify
          - /user/profile_image/get
          - /user/profile_image/upload
          - /user/replace_app_token
          - /user/set_active
          - /user/settings/get
          - /user/settings/set
          - /user/settings/update
          - /user/toggle_become
          - /users/get_or_create
          - /v1/device/information
          - /vayu/batch/commission
          - /vayu/get_data
          - /vayu/list
          - /vayu/set
          - /vayu/submit_data
          - /vayu/update
        unauthenticatedEndpoints:
          - /app/live_link/redeem
          - /camera/auth/init
          - /camera/org_id/get
          - /cameras_release_tool/get_cameras
          - /cameras_release_tool/set_default_firmware_version
          - /cameras_release_tool/set_firmware_version
          - /check_auth
          - /command_version/get
          - /customer/get_details
          - /device/auth/init
          - /direct/ping
          - /embed/[0-9a-f-]{36}/
          - /firmware/((.+)\/)*([^\/]+)
          - /internal/camera/config/get
          - /internal/camera/config/get/filtered
          - /internal/camera/config/set/single
          - /internal/camera/healthstatus
          - /internal/camera/lookup
          - /internal/camera/release_channel/set
          - /internal/org/get
          - /internal/org/remove_user
          - /internal/orgs/get_for_user
          - /internal/send_email
          - /internal/users/search
          - /is_online
          - /logs/relay-intrusion-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/1894804/store/
          - /org/check_shortname/[^/]*[0-9a-z]+[^/]*
          - /org/generate_shortname/.{1,100}
          - /org/invitation/info
          - /ping
          - /ping-command
          - /ping-device
          - /prestart/get
          - /time
          - /twilio/c8e78359-da58-4612-8ce5-3381fa9bd484
          - /user/add_cookie_user_id
          - /user/auth_challenges
          - /user/create
          - /user/email/verify
          - /user/login
          - /user/logout
          - /user/reset/redeem
          - /user/saml/sso/[0-9a-zA-Z._-]{1,64}
          - /user/saml/sso/login/redirect
          - /user/send_org_membership
          - /user/session_accounts
          - /user/validate_short_name
          - /vprovision-ping
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[\w\-. +%]+/download/[\w\-. +%]+
          - /[\w\-. +%]+/version
          - /activity/add
          - /analytics/cv_enabled_cameras
          - /app/live_link
          - /app/live_link/contacts/create
          - /app/live_link/contacts/delete
          - /app/live_link/contacts/edit
          - /app/live_link/contacts/get
          - /app/live_link/contacts/get_shared
          - /app/live_link/contacts/list
          - /app/live_link/contacts/revoke
          - /app/live_link/contacts/revoke_all
          - /app/live_link/contacts/share_link
          - /app/live_link/create
          - /app/live_link/get_contacts_shared_to
          - /app/live_link/revoke
          - /audit_log/get_camera_log
          - /audit_log/get_organization_log
          - /building/create
          - /building/delete
          - /building/list
          - /building/update
          - /buildings
          - /camera/audio/batch/get
          - /camera/audio/enable
          - /camera/auto_level/get
          - /camera/auto_level/set
          - /camera/autofocus
          - /camera/batch/get_low_bandwidth_mode
          - /camera/batch/get_readonly_mode
          - /camera/batch/lookup
          - /camera/batch/set_low_bandwidth_mode
          - /camera/batch/set_readonly_mode
          - /camera/calibration_images/get
          - /camera/calibration_matrix/delete
          - /camera/calibration_matrix/get
          - /camera/calibration_status
          - /camera/cloud_backup/is_enabled
          - /camera/codec/set
          - /camera/color/get_temperature
          - /camera/color/get_tint
          - /camera/color/set_temperature
          - /camera/color/set_tint
          - /camera/config/merge
          - /camera/cv/get_enabled_features
          - /camera/cv/set_enabled_features
          - /camera/cv_features/batch/get
          - /camera/cv_features/batch/set
          - /camera/decommission
          - /camera/deleted
          - /camera/download_offline_mode_certificate
          - /camera/edit/batch
          - /camera/event
          - /camera/exposure/get_compensation
          - /camera/exposure/set_compensation
          - /camera/favorites/get
          - /camera/favorites/modify
          - /camera/firmware_relay/((.+)\/)*([^\/]+)
          - /camera/fisheye/mode/get
          - /camera/fisheye/mode/set
          - /camera/focus_target/get
          - /camera/focus_target/set
          - /camera/get
          - /camera/get_calibrations_ready
          - /camera/get_cb_status
          - /camera/get_ffu_binaries
          - /camera/get_lan_url
          - /camera/groups/get
          - /camera/has_id
          - /camera/hq_bitrate/get
          - /camera/hq_bitrate/set
          - /camera/identify
          - /camera/image/settings
          - /camera/init/batch
          - /camera/init/perform
          - /camera/init/sharded
          - /camera/lan_token
          - /camera/level_assist
          - /camera/level_assist_active
          - /camera/location/set
          - /camera/manual_focus
          - /camera/manual_piris
          - /camera/manual_zoom
          - /camera/name/get
          - /camera/name/set
          - /camera/network_quality/submit
          - /camera/next_device/delete
          - /camera/next_device/get
          - /camera/next_device/update
          - /camera/night_threshold/get
          - /camera/night_threshold/set
          - /camera/operating_mode/get
          - /camera/operating_mode/set
          - /camera/privacy/set
          - /camera/public_key
          - /camera/reboot
          - /camera/release_channel/set
          - /camera/retention/get
          - /camera/retention/next_upload
          - /camera/retention/report
          - /camera/rotate
          - /camera/rotate/get
          - /camera/rotate/set
          - /camera/serial/get
          - /camera/site/batch/set
          - /camera/site/get
          - /camera/sq_bitrate/get
          - /camera/stats/get
          - /camera/stats/get_sum
          - /camera/storage/failure/get
          - /camera/storage/failure/set
          - /camera/storage/failure/unset
          - /camera/timezone/get
          - /camera/timezone/set
          - /camera/upload/logs
          - /camera/upload_sd_repair_result
          - /camera/wdr/enable
          - /camera/wdr/is_enabled
          - /camera/wifi/delete
          - /camera/wifi/get
          - /camera/wifi/set
          - /camera_grid/copy
          - /camera_grid/create
          - /camera_grid/delete
          - /camera_grid/list
          - /camera_grid/update
          - /cameras/get_mac_addresses
          - /cameras/operating_mode/get
          - /cameras_in_org
          - /cloud/enable_static_ip
          - /cloud/static_ips
          - /command/user/init
          - /command_version/set
          - /compliance/check_address
          - /customer/get
          - /default_endpoints
          - /device/batch/information
          - /device/decommission
          - /device/delete_orderproduct
          - /device/get_or_create_default_site
          - /device/initialize
          - /device/notes/get
          - /device/notes/set
          - /device/stats/get
          - /feature/is_enabled
          - /feedback/add
          - /firmware/((.+)\/)*([^\/]+)
          - /firmware/vtoolbox/((.+)\/)*([^\/]+)
          - /floor/create
          - /floor/delete
          - /floor/list
          - /floor/update
          - /floor_plan/change_walls
          - /floor_plan/create
          - /floor_plan/delete
          - /floor_plan/get_image
          - /floor_plan/get_metadata
          - /floor_plan/mobile_get_zip_and_bounds
          - /floor_plan/retrieve_walls
          - /floor_plan/set_floor
          - /floor_plan/set_metadata
          - /floor_plan/upload_image
          - /floorplan/get_fov_mappings
          - /floors
          - /info/device/lookup
          - /info/release_channel/get_all
          - /local_player/doors
          - /local_player/init
          - /local_player/set_grid
          - /local_player/status
          - /local_player/status/update
          - /local_player/update
          - /local_player/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /local_player/users/[0-9a-f-]{36}
          - /local_player/users/list
          - /local_player/users/update
          - /logistics/camera/short_status
          - /manufacturer/reset
          - /model/all_display_names
          - /model/capabilities
          - /model/config/merge
          - /models/list
          - /non_superuser/feature_flags/get_all
          - /notifications/group_preferences/set
          - /notifications/mute_preferences/get
          - /notifications/mute_preferences/set
          - /notifications/preferences/get
          - /notifications/preferences/set
          - /org/[0-9a-f-]{36}/cameras
          - /org/[0-9a-f-]{36}/users/list
          - /org/add_user
          - /org/admin
          - /org/camera/list
          - /org/camera_group/add_camera
          - /org/camera_group/batch_move_cameras
          - /org/camera_group/create
          - /org/camera_group/delete
          - /org/camera_group/modify
          - /org/camera_group/remove_camera
          - /org/camera_group/reorder_cameras
          - /org/camera_group/sites_to_grids
          - /org/camera_group/users
          - /org/cameras/get_csv
          - /org/cameras/get_cv_enabled
          - /org/create
          - /org/cv/set_enabled_features
          - /org/delete
          - /org/disable_cloud_backup
          - /org/download_offline_mode_certificate
          - /org/enable_offline_mode
          - /org/encryption_settings/get
          - /org/encryption_settings/set
          - /org/events
          - /org/features/get
          - /org/get_camera_groups
          - /org/invite
          - /org/modify
          - /org/remove_user
          - /org/remove_users
          - /org/resend_invite
          - /org/send_pass_app_invite
          - /org/set_user_permissions
          - /org/settings/get
          - /org/settings/set
          - /org/settings/update
          - /org/site/list
          - /org/toggle_hipaa
          - /org/users
          - /organization/[0-9a-f-]{36}/user/employment
          - /organization/[0-9a-f-]{36}/user/name
          - /organization/[0-9a-f-]{36}/user/phone
          - /organization/[0-9a-f-]{36}/users
          - /organization/[0-9a-f-]{36}/users/search
          - /particulate_sensors
          - /resource/create
          - /resource/get
          - /serial_number/assignment_upload
          - /serial_number/list
          - /site/[0-9a-f-]{36}/user/invite
          - /site/camera/list
          - /spurdog/view_settings/get
          - /spurdog/view_settings/update
          - /ssl/create_local_device_root_certificate_authority
          - /user/become_status
          - /user/camera/batch/compliance/list
          - /user/camera/compliance/list
          - /user/camera/compliance/override
          - /user/camera/compliance/remove
          - /user/camera/config/batch/delete
          - /user/camera/config/batch/get
          - /user/camera/config/batch/set
          - /user/camera/config/delete
          - /user/camera/config/get
          - /user/camera/config/set
          - /user/contact_info
          - /user/email/change
          - /user/email/send_verification_code
          - /user/get_orgs
          - /user/linked_accounts
          - /user/locale/set
          - /user/name
          - /user/passwd
          - /user/phone
          - /user/phone/verify
          - /user/profile_image/get
          - /user/profile_image/upload
          - /user/replace_app_token
          - /user/set_active
          - /user/settings/get
          - /user/settings/set
          - /user/settings/update
          - /user/toggle_become
          - /users/get_or_create
          - /v1/device/information
          - /vayu/batch/commission
          - /vayu/get_data
          - /vayu/list
          - /vayu/set
          - /vayu/submit_data
          - /vayu/update
        unauthenticatedEndpoints:
          - /app/live_link/redeem
          - /camera/auth/init
          - /camera/org_id/get
          - /cameras_release_tool/get_cameras
          - /cameras_release_tool/set_default_firmware_version
          - /cameras_release_tool/set_firmware_version
          - /check_auth
          - /command_version/get
          - /customer/get_details
          - /device/auth/init
          - /direct/ping
          - /embed/[0-9a-f-]{36}/
          - /firmware/((.+)\/)*([^\/]+)
          - /internal/camera/config/get
          - /internal/camera/config/get/filtered
          - /internal/camera/config/set/single
          - /internal/camera/healthstatus
          - /internal/camera/lookup
          - /internal/camera/release_channel/set
          - /internal/org/get
          - /internal/org/remove_user
          - /internal/orgs/get_for_user
          - /internal/send_email
          - /internal/users/search
          - /is_online
          - /logs/relay-intrusion-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/1894804/store/
          - /org/check_shortname/[^/]*[0-9a-z]+[^/]*
          - /org/generate_shortname/.{1,100}
          - /org/invitation/info
          - /ping
          - /ping-command
          - /ping-device
          - /prestart/get
          - /time
          - /twilio/c8e78359-da58-4612-8ce5-3381fa9bd484
          - /user/add_cookie_user_id
          - /user/auth_challenges
          - /user/create
          - /user/email/verify
          - /user/login
          - /user/logout
          - /user/reset/redeem
          - /user/saml/sso/[0-9a-zA-Z._-]{1,64}
          - /user/saml/sso/login/redirect
          - /user/send_org_membership
          - /user/session_accounts
          - /user/validate_short_name
          - /vprovision-ping
      - host: vprovision.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /internal/camera/lookup
          - /internal/camera/site/disable_traffic_shaping
          - /internal/camera/site/enable_traffic_shaping
          - /internal/org/cameras/info
          - /internal/org/short_name
          - /internal/orgs/get_for_user
          - /internal/send_email
          - /internal/sharded/mark_deleted
          - /internal/sharded/prepare
          - /user/validate_short_name
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vprovision
    namespace: vinfra
    resourceVersion: "5009066662"
    uid: d77ab588-11ce-4833-9115-74ba81a14a98
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /_accept/hls/[0-9a-f-]{36}
          - /_accept/hls/[A-Z0-9-]{14}
          - /_accept/remotesh/[0-9a-f-]{36}
          - /_accept/remotesh/[A-Z0-9-]{14}
          - /_accept/signed_remotesh/[0-9a-f-]{36}
          - /_accept/signed_remotesh/[A-Z0-9-]{14}
        unauthenticatedEndpoints:
          - /_proxy/hls/[0-9a-f-]{36}/((.+)\/)*([^\/]+)
          - /_proxy/hls/[A-Z0-9-]{14}/((.+)\/)*([^\/]+)
          - /_proxy/remotesh/[0-9a-f-]{36}
          - /_proxy/remotesh/[A-Z0-9-]{14}
          - /_proxy/signed_remotesh/[0-9a-f-]{36}
          - /_proxy/signed_remotesh/[A-Z0-9-]{14}
          - /_response/[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /ping
          - /remotesh_ping
          - /speedtest/download
          - /speedtest/upload
      - host: vstream.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /_accept/hls/[0-9a-f-]{36}
          - /_accept/hls/[A-Z0-9-]{14}
          - /_accept/remotesh/[0-9a-f-]{36}
          - /_accept/remotesh/[A-Z0-9-]{14}
          - /_accept/signed_remotesh/[0-9a-f-]{36}
          - /_accept/signed_remotesh/[A-Z0-9-]{14}
        unauthenticatedEndpoints:
          - /_proxy/hls/[0-9a-f-]{36}/((.+)\/)*([^\/]+)
          - /_proxy/hls/[A-Z0-9-]{14}/((.+)\/)*([^\/]+)
          - /_proxy/remotesh/[0-9a-f-]{36}
          - /_proxy/remotesh/[A-Z0-9-]{14}
          - /_proxy/signed_remotesh/[0-9a-f-]{36}
          - /_proxy/signed_remotesh/[A-Z0-9-]{14}
          - /_response/[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /ping
          - /remotesh_ping
          - /speedtest/download
          - /speedtest/upload
      - host: "*.vproxy.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /_accept/hls/[0-9a-f-]{36}
          - /_accept/hls/[A-Z0-9-]{14}
          - /_accept/remotesh/[0-9a-f-]{36}
          - /_accept/remotesh/[A-Z0-9-]{14}
          - /_accept/signed_remotesh/[0-9a-f-]{36}
          - /_accept/signed_remotesh/[A-Z0-9-]{14}
        unauthenticatedEndpoints:
          - /_proxy/hls/[0-9a-f-]{36}/((.+)\/)*([^\/]+)
          - /_proxy/hls/[A-Z0-9-]{14}/((.+)\/)*([^\/]+)
          - /_proxy/remotesh/[0-9a-f-]{36}
          - /_proxy/remotesh/[A-Z0-9-]{14}
          - /_proxy/signed_remotesh/[0-9a-f-]{36}
          - /_proxy/signed_remotesh/[A-Z0-9-]{14}
          - /_response/[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /ping
          - /remotesh_ping
          - /speedtest/download
          - /speedtest/upload
      - host: "*.vstream.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /_accept/hls/[0-9a-f-]{36}
          - /_accept/hls/[A-Z0-9-]{14}
          - /_accept/remotesh/[0-9a-f-]{36}
          - /_accept/remotesh/[A-Z0-9-]{14}
          - /_accept/signed_remotesh/[0-9a-f-]{36}
          - /_accept/signed_remotesh/[A-Z0-9-]{14}
        unauthenticatedEndpoints:
          - /_proxy/hls/[0-9a-f-]{36}/((.+)\/)*([^\/]+)
          - /_proxy/hls/[A-Z0-9-]{14}/((.+)\/)*([^\/]+)
          - /_proxy/remotesh/[0-9a-f-]{36}
          - /_proxy/remotesh/[A-Z0-9-]{14}
          - /_proxy/signed_remotesh/[0-9a-f-]{36}
          - /_proxy/signed_remotesh/[A-Z0-9-]{14}
          - /_response/[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /ping
          - /remotesh_ping
          - /speedtest/download
          - /speedtest/upload
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vproxy
    namespace: vinfra
    resourceVersion: "5009066670"
    uid: 75451c88-380e-4554-aa1d-c2b352dbacb7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vptz/camera/ws
        unauthenticatedEndpoints:
          - /vptz/ping
      - host: vstream.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vptz/camera/ws
        unauthenticatedEndpoints:
          - /vptz/ping
      - host: "*.vproxy.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vptz/camera/ws
        unauthenticatedEndpoints:
          - /vptz/ping
      - host: "*.vstream.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vptz/camera/ws
        unauthenticatedEndpoints:
          - /vptz/ping
      - host: vptz.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/ws
          - /contextual_triggers/config/get
          - /contextual_triggers/config/set
          - /contextual_triggers/context_camera_preset/delete
          - /contextual_triggers/create
          - /contextual_triggers/delete
          - /contextual_triggers/edit
          - /contextual_triggers/get
          - /user/guard_tours/create
          - /user/guard_tours/delete
          - /user/guard_tours/edit
          - /user/guard_tours/get
          - /user/guard_tours_location/thumbnail
          - /user/guard_tours_location_image/create
          - /user/presets/create
          - /user/presets/delete
          - /user/presets/get
          - /user/presets/home/update
          - /user/presets/new
          - /user/presets/sort_index/update
          - /user/presets/thumbnail
          - /user/sentry_mode/get
          - /user/sentry_mode/set
          - /user/ws/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vptz
    namespace: vinfra
    resourceVersion: "5009066674"
    uid: d0870053-f199-4954-a214-32625c406e50
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: api.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/orgs/[0-9a-f-]{36}/v2/apikeys
          - /admin/orgs/[0-9a-f-]{36}/v2/apikeys/[\w\.\-]+
          - /admin/orgs/[0-9a-f-]{36}/v2/granular_apikeys
          - /admin/orgs/[0-9a-f-]{36}/v2/webhookconfig
          - /integrations/auror/auth
          - /integrations/auror/export
          - /integrations/axon_evidence/auth
          - /integrations/axon_evidence/cases/[0-9a-f-]{36}/get
          - /integrations/axon_evidence/categories/[0-9a-f-]{36}/get
          - /integrations/axon_evidence/export
          - /integrations/config/[0-9a-f-]{36}/[0-9a-f-]{36}/delete_config
          - /integrations/config/[0-9a-f-]{36}/get_config
          - /integrations/config/get_available_integrations
          - /integrations/config/set_config
        unauthenticatedEndpoints:
          - /access/v1/access_groups
          - /access/v1/access_groups/group
          - /access/v1/access_groups/group/user
          - /access/v1/access_users
          - /access/v1/access_users/user
          - /access/v1/access_users/user/ble/activate
          - /access/v1/access_users/user/ble/deactivate
          - /access/v1/access_users/user/end_date
          - /access/v1/access_users/user/entry_code
          - /access/v1/access_users/user/pass/invite
          - /access/v1/access_users/user/profile_photo
          - /access/v1/access_users/user/remote_unlock/activate
          - /access/v1/access_users/user/remote_unlock/deactivate
          - /access/v1/access_users/user/start_date
          - /access/v1/access_users_photos_api
          - /access/v1/access_users_photos_api/user
          - /access/v1/credentials/card
          - /access/v1/credentials/card/activate
          - /access/v1/credentials/card/deactivate
          - /access/v1/credentials/license_plate
          - /access/v1/credentials/license_plate/activate
          - /access/v1/credentials/license_plate/deactivate
          - /access/v1/credentials/mfa_code
          - /access/v1/door/access_level
          - /access/v1/door/access_level/[0-9a-f-]{36}
          - /access/v1/door/access_level/[0-9a-f-]{36}/access_schedule_event
          - /access/v1/door/access_level/[0-9a-f-]{36}/access_schedule_event/[0-9a-f-]{36}
          - /access/v1/door/admin_unlock
          - /access/v1/door/exception_calendar
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}/exception
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}/exception/[0-9a-f-]{36}
          - /access/v1/door/user_unlock
          - /access/v1/doors
          - /admin/access_v1/openapi\.json
          - /admin/alarms_v1/openapi\.json
          - /admin/camera_v1/openapi\.json
          - /admin/core_v1/openapi\.json
          - /admin/guest_v1/openapi\.json
          - /admin/openapi/openapi\.json
          - /admin/ping
          - /admin/sensor_v1/openapi\.json
          - /admin/tokens/openapi\.json
          - /admin/viewing_station_v1/openapi\.json
          - /alarms/v1/devices
          - /alarms/v1/sites
          - /cameras/v1/alerts
          - /cameras/v1/analytics/dashboard_occupancy_trends
          - /cameras/v1/analytics/lpr/images
          - /cameras/v1/analytics/lpr/license_plate_of_interest
          - /cameras/v1/analytics/lpr/license_plate_of_interest/batch
          - /cameras/v1/analytics/lpr/timestamps
          - /cameras/v1/analytics/max_object_counts
          - /cameras/v1/analytics/object_counts
          - /cameras/v1/analytics/object_position_mqtt
          - /cameras/v1/analytics/occupancy_trends
          - /cameras/v1/audio/status
          - /cameras/v1/cloud_backup/settings
          - /cameras/v1/config
          - /cameras/v1/devices
          - /cameras/v1/feature
          - /cameras/v1/footage/link
          - /cameras/v1/footage/thumbnails
          - /cameras/v1/footage/thumbnails/latest
          - /cameras/v1/footage/thumbnails/link
          - /cameras/v1/footage/token
          - /cameras/v1/occupancy_trend_enabled
          - /cameras/v1/people/person_of_interest
          - /cameras/v1/video_tagging/event
          - /cameras/v1/video_tagging/event/search
          - /cameras/v1/video_tagging/event_type
          - /core/v1/audit_log
          - /core/v1/user
          - /environment/v1/alerts
          - /environment/v1/data
          - /events/v1/access
          - /guest/v1/deny_list
          - /guest/v1/sites
          - /guest/v1/visits
          - /orgs/[0-9a-f-]{36}/auditlog
          - /orgs/[0-9a-f-]{36}/cameras
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/fullres
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/history/[0-9]+
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/latest
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/objects/counts
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/thumbnail/[0-9]+
          - /orgs/[0-9a-f-]{36}/license_plate_of_interest
          - /orgs/[0-9a-f-]{36}/license_plate_of_interest/[\w\.\-]+
          - /orgs/[0-9a-f-]{36}/notifications
          - /orgs/[0-9a-f-]{36}/persons_of_interest
          - /orgs/[0-9a-f-]{36}/persons_of_interest/[0-9a-f-]{36}
          - /orgs/[0-9a-f-]{36}/sensors/[0-9a-f-]{36}/sensor_data
          - /orgs/[0-9a-f-]{36}/sensors/alerts
          - /ping
          - /stream/cameras/v1/footage/stream/[\w\-. +%]+
          - /token
          - /viewing_station/v1/devices
      - host: apiadmin.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/orgs/[0-9a-f-]{36}/v2/apikeys
          - /admin/orgs/[0-9a-f-]{36}/v2/apikeys/[\w\.\-]+
          - /admin/orgs/[0-9a-f-]{36}/v2/granular_apikeys
          - /admin/orgs/[0-9a-f-]{36}/v2/webhookconfig
          - /integrations/auror/auth
          - /integrations/auror/export
          - /integrations/axon_evidence/auth
          - /integrations/axon_evidence/cases/[0-9a-f-]{36}/get
          - /integrations/axon_evidence/categories/[0-9a-f-]{36}/get
          - /integrations/axon_evidence/export
          - /integrations/config/[0-9a-f-]{36}/[0-9a-f-]{36}/delete_config
          - /integrations/config/[0-9a-f-]{36}/get_config
          - /integrations/config/get_available_integrations
          - /integrations/config/set_config
        unauthenticatedEndpoints:
          - /access/v1/access_groups
          - /access/v1/access_groups/group
          - /access/v1/access_groups/group/user
          - /access/v1/access_users
          - /access/v1/access_users/user
          - /access/v1/access_users/user/ble/activate
          - /access/v1/access_users/user/ble/deactivate
          - /access/v1/access_users/user/end_date
          - /access/v1/access_users/user/entry_code
          - /access/v1/access_users/user/pass/invite
          - /access/v1/access_users/user/profile_photo
          - /access/v1/access_users/user/remote_unlock/activate
          - /access/v1/access_users/user/remote_unlock/deactivate
          - /access/v1/access_users/user/start_date
          - /access/v1/access_users_photos_api
          - /access/v1/access_users_photos_api/user
          - /access/v1/credentials/card
          - /access/v1/credentials/card/activate
          - /access/v1/credentials/card/deactivate
          - /access/v1/credentials/license_plate
          - /access/v1/credentials/license_plate/activate
          - /access/v1/credentials/license_plate/deactivate
          - /access/v1/credentials/mfa_code
          - /access/v1/door/access_level
          - /access/v1/door/access_level/[0-9a-f-]{36}
          - /access/v1/door/access_level/[0-9a-f-]{36}/access_schedule_event
          - /access/v1/door/access_level/[0-9a-f-]{36}/access_schedule_event/[0-9a-f-]{36}
          - /access/v1/door/admin_unlock
          - /access/v1/door/exception_calendar
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}/exception
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}/exception/[0-9a-f-]{36}
          - /access/v1/door/user_unlock
          - /access/v1/doors
          - /admin/access_v1/openapi\.json
          - /admin/alarms_v1/openapi\.json
          - /admin/camera_v1/openapi\.json
          - /admin/core_v1/openapi\.json
          - /admin/guest_v1/openapi\.json
          - /admin/openapi/openapi\.json
          - /admin/ping
          - /admin/sensor_v1/openapi\.json
          - /admin/tokens/openapi\.json
          - /admin/viewing_station_v1/openapi\.json
          - /alarms/v1/devices
          - /alarms/v1/sites
          - /cameras/v1/alerts
          - /cameras/v1/analytics/dashboard_occupancy_trends
          - /cameras/v1/analytics/lpr/images
          - /cameras/v1/analytics/lpr/license_plate_of_interest
          - /cameras/v1/analytics/lpr/license_plate_of_interest/batch
          - /cameras/v1/analytics/lpr/timestamps
          - /cameras/v1/analytics/max_object_counts
          - /cameras/v1/analytics/object_counts
          - /cameras/v1/analytics/object_position_mqtt
          - /cameras/v1/analytics/occupancy_trends
          - /cameras/v1/audio/status
          - /cameras/v1/cloud_backup/settings
          - /cameras/v1/config
          - /cameras/v1/devices
          - /cameras/v1/feature
          - /cameras/v1/footage/link
          - /cameras/v1/footage/thumbnails
          - /cameras/v1/footage/thumbnails/latest
          - /cameras/v1/footage/thumbnails/link
          - /cameras/v1/footage/token
          - /cameras/v1/occupancy_trend_enabled
          - /cameras/v1/people/person_of_interest
          - /cameras/v1/video_tagging/event
          - /cameras/v1/video_tagging/event/search
          - /cameras/v1/video_tagging/event_type
          - /core/v1/audit_log
          - /core/v1/user
          - /environment/v1/alerts
          - /environment/v1/data
          - /events/v1/access
          - /guest/v1/deny_list
          - /guest/v1/sites
          - /guest/v1/visits
          - /orgs/[0-9a-f-]{36}/auditlog
          - /orgs/[0-9a-f-]{36}/cameras
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/fullres
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/history/[0-9]+
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/latest
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/objects/counts
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/thumbnail/[0-9]+
          - /orgs/[0-9a-f-]{36}/license_plate_of_interest
          - /orgs/[0-9a-f-]{36}/license_plate_of_interest/[\w\.\-]+
          - /orgs/[0-9a-f-]{36}/notifications
          - /orgs/[0-9a-f-]{36}/persons_of_interest
          - /orgs/[0-9a-f-]{36}/persons_of_interest/[0-9a-f-]{36}
          - /orgs/[0-9a-f-]{36}/sensors/[0-9a-f-]{36}/sensor_data
          - /orgs/[0-9a-f-]{36}/sensors/alerts
          - /ping
          - /stream/cameras/v1/footage/stream/[\w\-. +%]+
          - /token
          - /viewing_station/v1/devices
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vpublicapi
    namespace: vinfra
    resourceVersion: "5009066681"
    uid: 34ef5b17-4ac6-4dcb-b0d8-213a1e8da4d0
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vrasr-internal.staging.cf.verkada.com
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /api/devices
          - /api/devices/[0-9a-f-]{36}
          - /api/devices/traffic-split
          - /api/get-service
          - /api/insert-routing-rules
          - /api/list-services
          - /api/request-replay/clear
          - /api/request-replay/paths
          - /api/request-replay/record
          - /api/request-replay/requests
          - /api/request-replay/trim
          - /api/users
          - /api/users/[0-9a-f-]{36}
          - /api/v2/get-service
          - /api/v2/insert-routing-rules
          - /ping
          - /request-replay/ping
          - /vadmission/add-app-and-version-to-whitelist
          - /vadmission/add-app-to-whitelist
          - /vadmission/add-whitelist
          - /vadmission/is-locked-down
      - host: vrasr.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /api/devices
          - /api/devices/[0-9a-f-]{36}
          - /api/devices/traffic-split
          - /api/get-service
          - /api/insert-routing-rules
          - /api/list-services
          - /api/users
          - /api/users/[0-9a-f-]{36}
          - /api/v2/get-service
          - /api/v2/insert-routing-rules
          - /ping
          - /vadmission/add-app-and-version-to-whitelist
          - /vadmission/add-app-to-whitelist
          - /vadmission/add-whitelist
          - /vadmission/is-locked-down
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vrasr
    namespace: vinfra
    resourceVersion: "5009066686"
    uid: 6aaeee98-a582-4c2e-a00c-e76ac4a2d414
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
      - host: vscim.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /ping
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
      - host: scim.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /ping
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vscim
    namespace: vinfra
    resourceVersion: "5009066690"
    uid: 2a6c0aae-704c-4c81-a342-598707e481c8
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /exemplars/get
          - /exemplars/upload
          - /face/known_face\.jpg
          - /faces/timeline_summary
          - /hyperzoom/person/search
          - /hyperzoom/person/update_search_result
          - /identity/add_profile_photo
          - /identity/bulk/get
          - /identity/bulk/update
          - /identity/create
          - /identity/get
          - /identity/list
          - /identity/list/tag/all
          - /identity/merge
          - /identity/search_by_image
          - /identity/unmerge
          - /identity/update
          - /person/cross_camera_search
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /exemplars/get
          - /exemplars/upload
          - /face/known_face\.jpg
          - /faces/timeline_summary
          - /hyperzoom/person/search
          - /hyperzoom/person/update_search_result
          - /identity/add_profile_photo
          - /identity/bulk/get
          - /identity/bulk/update
          - /identity/create
          - /identity/get
          - /identity/list
          - /identity/list/tag/all
          - /identity/merge
          - /identity/search_by_image
          - /identity/unmerge
          - /identity/update
          - /person/cross_camera_search
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /exemplars/get
          - /exemplars/upload
          - /face/known_face\.jpg
          - /faces/timeline_summary
          - /hyperzoom/person/search
          - /hyperzoom/person/update_search_result
          - /identity/add_profile_photo
          - /identity/bulk/get
          - /identity/bulk/update
          - /identity/create
          - /identity/get
          - /identity/list
          - /identity/list/tag/all
          - /identity/merge
          - /identity/search_by_image
          - /identity/unmerge
          - /identity/update
          - /person/cross_camera_search
      - host: vsearchapi.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /appearance_search/org/[0-9a-f-]{36}
          - /audio/transcriptions
          - /custom_detections/org/[0-9a-f-]{36}
          - /custom_event/delete
          - /custom_event/download
          - /custom_event/get
          - /custom_event/search
          - /custom_event/update
          - /custom_event_type/create
          - /custom_event_type/delete
          - /custom_event_type/get
          - /custom_event_type/update
          - /exemplars/get
          - /exemplars/upload
          - /face/known_face\.jpg
          - /get_objects_info/org/[0-9a-f-]{36}
          - /helix_threshold
          - /helix_threshold/[0-9a-f-]{36}
          - /hyperzoom/mark_wrong_detection
          - /hyperzoom/sensor_data
          - /hyperzooms/get_cv_enabled_cameras
          - /hyperzooms/get_cv_enabled_cameras_by_org
          - /identity/add_profile_photo
          - /identity/bulk/get
          - /identity/bulk/update
          - /identity/create
          - /identity/get
          - /identity/list
          - /identity/merge
          - /identity/search_by_image
          - /identity/unmerge
          - /identity/update
          - /nlp_events/org/[0-9a-f-]{36}/create
          - /nlp_events/org/[0-9a-f-]{36}/delete
          - /nlp_events/org/[0-9a-f-]{36}/get
          - /nlp_events/org/[0-9a-f-]{36}/preview
          - /nlp_motion_search/org/[0-9a-f-]{36}
          - /nlp_search/backfill/[0-9a-f-]{36}
          - /nlp_search/org/[0-9a-f-]{36}
          - /nlp_search/suggestions/[0-9a-f-]{36}
          - /nlp_search/user_opt_in/[0-9a-f-]{36}
          - /person/cross_camera_search
          - /person_attributes/org/[0-9a-f-]{36}
          - /segment_image/org/[0-9a-f-]{36}
          - /tags/[0-9a-f-]{36}
          - /tags/[0-9a-f-]{36}/entity
          - /tags/[0-9a-f-]{36}/entity/[0-9a-f-]{36}
          - /tags/[0-9a-f-]{36}/entity/[a-zA-Z0-9_-]{20}
          - /tags/create
          - /tags/remove
          - /timeline/object/org/[0-9a-f-]{36}
          - /unusual_activities/get
          - /vehicle/search/[0-9a-f-]{36}
          - /vehicle_attributes/org/[0-9a-f-]{36}
          - /vehicle_attributes/org/[0-9a-f-]{36}/camera/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /internal/custom_event/create
          - /internal/custom_event/delete
          - /internal/custom_event/get
          - /internal/custom_event/search
          - /internal/custom_event/update
          - /internal/custom_event_type/create
          - /internal/custom_event_type/delete
          - /internal/custom_event_type/get
          - /internal/custom_event_type/update
          - /nlp_search_feedback/org/[0-9a-f-]{36}
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vsearchapi
    namespace: vinfra
    resourceVersion: "5009066692"
    uid: 2edbfdc7-9dd9-4531-a2cb-50f54e50a822
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsensor.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /devices/[0-9a-f-]{36}/beta/alert_events
          - /devices/[0-9a-f-]{36}/beta/latest_alert_events
        unauthenticatedEndpoints:
          - /vsensor/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vsensor
    namespace: vinfra
    resourceVersion: "5009066696"
    uid: af9c8abb-c54f-43cf-b5fd-fce380d8e43b
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsensor.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alert_events/[0-9a-f-]{36}
          - /analytics/alert_events/devices/[0-9a-f-]{36}/summary
          - /analytics/alert_events/most_active_alert_types
          - /analytics/alert_events/sites
          - /analytics/alert_events/sites/[0-9a-f-]{36}
          - /analytics/alert_events/sites/[0-9a-f-]{36}/list
          - /analytics/alert_events/sites/[0-9a-f-]{36}/summary
          - /analytics/alert_events/sites/list
          - /analytics/alert_events/sites/summary
          - /calibration/[0-9a-f-]{36}
          - /calibration/[0-9a-f-]{36}/certificate
          - /calibration/history/[0-9a-f-]{36}
          - /calibration/list
          - /dashboards
          - /dashboards/[0-9a-f-]{36}
          - /dashboards/[0-9a-f-]{36}/live_link/devices
          - /dashboards/list
          - /dashboards/live_link/can_manage
          - /dashboards/live_link/create
          - /dashboards/live_link/share
          - /device/status
          - /devices/[0-9a-f-]{36}
          - /devices/[0-9a-f-]{36}/alert_configs
          - /devices/[0-9a-f-]{36}/alert_events
          - /devices/[0-9a-f-]{36}/alerts/csv
          - /devices/[0-9a-f-]{36}/data/audio
          - /devices/[0-9a-f-]{36}/data/csv
          - /devices/[0-9a-f-]{36}/feedback/alert_events
          - /devices/[0-9a-f-]{36}/get_user_preferences
          - /devices/[0-9a-f-]{36}/latest_alert_events
          - /devices/[0-9a-f-]{36}/set_user_preferences
          - /devices/[0-9a-f-]{36}/thumbnail
          - /devices/alert_configs/list
          - /devices/batch/alert_configs
          - /devices/batch/commission
          - /devices/batch/move
          - /devices/batch/settings
          - /devices/batch/status
          - /devices/commission
          - /devices/decommission
          - /devices/list
          - /devices/org/alert_events
          - /devices/version/system/download/[\w\.\-]+
          - /devices/version/system/latest
          - /insights/people
          - /insights/people/[0-9a-f-]{36}
          - /licensing/[0-9a-f-]{36}
          - /user_preferences
          - /vmss_config/delete
          - /vmss_config/device/get/[0-9a-f-]{36}
          - /vmss_config/get/[0-9a-f-]{36}
          - /vmss_config/list
          - /vmss_config/set
          - /vmss_device_status/get/[0-9a-f-]{36}
          - /vmss_device_status/set
          - /vsensorconfig/batch/config
          - /vsensorconfig/batch/config/list
          - /vsensorconfig/config/[0-9a-f-]{36}
          - /vsensorconfig/reload/[0-9a-f-]{36}
          - /vsensorconfig/ws/[0-9a-f-]{36}
          - /zones
          - /zones/[0-9a-f-]{36}
          - /zones/[0-9a-f-]{36}/preferences
          - /zones/ongoing_alert_event_readings/[0-9a-f-]{36}
          - /zones/ongoing_alert_events/[0-9a-f-]{36}
          - /zones/preferences
        unauthenticatedEndpoints:
          - /ping
          - /vsensorconfig/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vsensorconfig
    namespace: vinfra
    resourceVersion: "5009066698"
    uid: 21851112-0eb9-4d3c-92fa-f9b98a3e5b18
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsensor.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /query
          - /query_latest/[0-9a-f-]{36}
          - /vsensordata/batch/aggregated_query
          - /vsensordata/sensor/[0-9a-f-]{36}/audio/aac/[\w\-. +%]+\.aac
          - /vsensordata/sensor/[0-9a-f-]{36}/audio/manifest\.m3u8
          - /vsensordata/sensor/[0-9a-f-]{36}/backup_data
          - /vsensordata/sensor/[0-9a-f-]{36}/backup_data_ts
          - /vsensordata/sensor/[0-9a-f-]{36}/ws
        unauthenticatedEndpoints:
          - /vsensordata/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vsensordata
    namespace: vinfra
    resourceVersion: "5009066700"
    uid: 66fea7d0-8c3d-42f9-b6ef-03c451b22a76
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsight.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[0-9a-f-]{36}/[0-9a-f-]{36}/agreements
          - /[0-9a-f-]{36}/[0-9a-f-]{36}/sign_agreement
          - /[0-9a-f-]{36}/device/agreements
          - /context_camera/camera/[0-9a-f-]{36}
          - /license_plates/org/[0-9a-f-]{36}/get_appearance_summary
          - /license_plates/org/[0-9a-f-]{36}/get_num_appearances
          - /license_plates/org/[0-9a-f-]{36}/user_get
          - /lpoi/csv_upload/org/[0-9a-f-]{36}
          - /lpoi/org/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vsight
    namespace: vinfra
    resourceVersion: "5009066703"
    uid: fddf70c3-e8d0-4e18-b1f1-5e4dbf9f3b1f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vslackada.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
          - /shoutouts/handle_modal
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vslackada
    namespace: vinfra
    resourceVersion: "5009066705"
    uid: cfa59da7-f06c-4c57-897b-621ae3e8afed
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vssh.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
          - /vssh/tools/add_public_key
          - /vssh/tools/delete_session
          - /vssh/tools/get_session
          - /vssh/tools/list_sessions
          - /vssh/tools/update_session
          - /vssh/ws/device/[0-9a-f-]{36}
          - /vssh/ws/user
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-13T21:41:03Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vssh
    namespace: vinfra
    resourceVersion: "5009066708"
    uid: 3b7045cc-abb6-4e65-86a1-a36b7c4a0180
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vstore.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /api/v1/active-notification
          - /api/v1/addressbook
          - /api/v1/addressbooks
          - /api/v1/addressbooks/reseller
          - /api/v1/autocomplete
          - /api/v1/clear-notifications
          - /api/v1/customer
          - /api/v1/dealid
          - /api/v1/dealids/reseller
          - /api/v1/draft
          - /api/v1/draft/download
          - /api/v1/draft/email
          - /api/v1/drafts
          - /api/v1/feedback
          - /api/v1/migrate/quotes
          - /api/v1/notification
          - /api/v1/order
          - /api/v1/orders
          - /api/v1/placedetails
          - /api/v1/productcatalog
          - /api/v1/proposal
          - /api/v1/shippingcost
          - /api/v1/shippingcoupon
          - /api/v1/shippingmethods
          - /api/v1/suggest
          - /api/v1/sync/orders
          - /api/v1/sync/products
          - /api/v1/user/search
          - /api/v1/userinfo
          - /api/v1/vat
          - /auth/logout
          - /auth/okta/callback
          - /auth/salesforce/callback
          - /auth/salesforce/login
          - /ping
      - host: vconcierge.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /api/v1/attached-files
          - /api/v1/autocomplete
          - /api/v1/customer
          - /api/v1/edit
          - /api/v1/file
          - /api/v1/files
          - /api/v1/options
          - /api/v1/order
          - /api/v1/orders
          - /api/v1/parse-po
          - /api/v1/placedetails
          - /api/v1/productcatalog
          - /api/v1/pull-all
          - /api/v1/pull-from-netsuite
          - /api/v1/push-to-netsuite
          - /api/v1/reseller
          - /api/v1/shippingcost
          - /api/v1/shippingmethods
          - /api/v1/split
          - /api/v1/statistics
          - /netsuite/order
          - /ping
      - host: vreturns.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /api/v1/autocomplete
          - /api/v1/orderlines-order
          - /api/v1/orderlines-serial
          - /api/v1/placedetails
          - /api/v1/return
          - /api/v1/search-order
          - /api/v1/search-serial
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vstorefront
    namespace: vinfra
    resourceVersion: "5009066713"
    uid: bd20d247-6764-4350-b0c2-44edf7b2ba40
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /stream/[0-9a-f-]{36}
          - /stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/bytes/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mp4/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
        unauthenticatedEndpoints:
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /vstream/ping
      - host: vstream.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /stream/[0-9a-f-]{36}
          - /stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/bytes/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mp4/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
        unauthenticatedEndpoints:
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /vstream/ping
      - host: "*.vproxy.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /stream/[0-9a-f-]{36}
          - /stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/bytes/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mp4/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
        unauthenticatedEndpoints:
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /vstream/ping
      - host: "*.vstream.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /stream/[0-9a-f-]{36}
          - /stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/bytes/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mp4/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
        unauthenticatedEndpoints:
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /vstream/ping
      - host: vstream-sec.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /stream/[0-9a-f-]{36}
          - /stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/bytes/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mp4/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
        unauthenticatedEndpoints:
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /vstream/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vstream
    namespace: vinfra
    resourceVersion: "5009066715"
    uid: 2e25168f-5255-471f-946d-8aae0b6eeadf
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /rtc/[0-9a-f-]{36}/viewerConnectionDetails
          - /rtc/kinesisvideo/createSignalingChannel
          - /rtc/kinesisvideo/deleteSignalingChannel
          - /rtc/kinesisvideo/describeSignalingChannel
          - /rtc/kinesisvideo/getSignalingChannelEndpoint
          - /rtc/kinesisvideo/v1/get-ice-server-config
        unauthenticatedEndpoints:
          - /rtc/ping
      - host: vstream.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /rtc/[0-9a-f-]{36}/viewerConnectionDetails
          - /rtc/kinesisvideo/createSignalingChannel
          - /rtc/kinesisvideo/deleteSignalingChannel
          - /rtc/kinesisvideo/describeSignalingChannel
          - /rtc/kinesisvideo/getSignalingChannelEndpoint
          - /rtc/kinesisvideo/v1/get-ice-server-config
        unauthenticatedEndpoints:
          - /rtc/ping
      - host: "*.vproxy.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /rtc/[0-9a-f-]{36}/viewerConnectionDetails
          - /rtc/kinesisvideo/createSignalingChannel
          - /rtc/kinesisvideo/deleteSignalingChannel
          - /rtc/kinesisvideo/describeSignalingChannel
          - /rtc/kinesisvideo/getSignalingChannelEndpoint
          - /rtc/kinesisvideo/v1/get-ice-server-config
        unauthenticatedEndpoints:
          - /rtc/ping
      - host: "*.vstream.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /rtc/[0-9a-f-]{36}/viewerConnectionDetails
          - /rtc/kinesisvideo/createSignalingChannel
          - /rtc/kinesisvideo/deleteSignalingChannel
          - /rtc/kinesisvideo/describeSignalingChannel
          - /rtc/kinesisvideo/getSignalingChannelEndpoint
          - /rtc/kinesisvideo/v1/get-ice-server-config
        unauthenticatedEndpoints:
          - /rtc/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vstreamrtc
    namespace: vinfra
    resourceVersion: "5009066720"
    uid: a1c13bcf-5432-4876-9e44-09ffd60c6ffc
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/retention_trigger/check
          - /camera/submit_transformation_matrix
          - /camera/transformation_matrix/calculate
          - /camera_poi/get_embedding_encryption_key
          - /camera_poi/get_org_pois
          - /camera_poi/get_org_pois_v2
          - /cameras/get_region
          - /cameras/set_region
          - /get/camera/resource/accessibility
          - /library/background
          - /library/calibration_image\.jpg
          - /library/closest_thumb\.jpg
          - /library/cloud_retention
          - /library/count_people
          - /library/detected_objects
          - /library/exact_thumb\.gif
          - /library/exact_thumb\.jpg
          - /library/exact_thumb\.json
          - /library/exact_thumb\.webp
          - /library/exemplar\.jpg
          - /library/fullres\.jpg
          - /library/fullres\.json
          - /library/get_seen_labels
          - /library/grid_10x10\.jpg
          - /library/grid_5x5\.jpg
          - /library/hyperzoom
          - /library/hyperzoom\.jpg
          - /library/latest\.jpg
          - /library/motion_coverage
          - /library/motion_search
          - /library/object_search
          - /library/object_search/v2
          - /library/object_stats
          - /library/object_tracking_hyperzoom\.jpg
          - /library/objects_in_range
          - /library/persistent_change
          - /library/representing_thumb_times
          - /library/thumb\.jpg
          - /library/timelapse\.m3u8
          - /library/timelapse\.mp4
          - /library/timelapse\.ts
          - /library/tracked_objects
          - /license_plates/org/[0-9a-f-]{36}/get
          - /object_tracking/restore_backup
          - /org/get_region
          - /org/set_region
          - /set/camera/resource/accessibility
          - /stats
          - /submit/fullres/[0-9a-f-]{36}/[0-9]+
          - /submit/hyperzoom/[0-9]+/[0-9]+
          - /submit/motion_rollup
          - /submit/object_tracking/upload_url
          - /submit/object_tracking_hyperzoom/[0-9_-]+
          - /submit/raw_frame/[0-9]+
          - /submit/raw_frame_detections/[0-9]+
          - /submit/stats
          - /submit/thumbnail/[0-9a-f-]{36}/[0-9]+
          - /submit/thumbnail_detection/[0-9]+
          - /thumbnail/upload/url
          - /v1/floor_plan/get_history_heat_map
          - /v1/floor_plan/get_history_heat_map_cell
        unauthenticatedEndpoints:
          - /ping
          - /submit/persistent_change
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/retention_trigger/check
          - /camera/submit_transformation_matrix
          - /camera/transformation_matrix/calculate
          - /camera_poi/get_embedding_encryption_key
          - /camera_poi/get_org_pois
          - /camera_poi/get_org_pois_v2
          - /cameras/get_region
          - /cameras/set_region
          - /get/camera/resource/accessibility
          - /library/background
          - /library/calibration_image\.jpg
          - /library/closest_thumb\.jpg
          - /library/cloud_retention
          - /library/count_people
          - /library/detected_objects
          - /library/exact_thumb\.gif
          - /library/exact_thumb\.jpg
          - /library/exact_thumb\.json
          - /library/exact_thumb\.webp
          - /library/exemplar\.jpg
          - /library/fullres\.jpg
          - /library/fullres\.json
          - /library/get_seen_labels
          - /library/grid_10x10\.jpg
          - /library/grid_5x5\.jpg
          - /library/hyperzoom
          - /library/hyperzoom\.jpg
          - /library/latest\.jpg
          - /library/motion_coverage
          - /library/motion_search
          - /library/object_search
          - /library/object_search/v2
          - /library/object_stats
          - /library/object_tracking_hyperzoom\.jpg
          - /library/objects_in_range
          - /library/persistent_change
          - /library/representing_thumb_times
          - /library/thumb\.jpg
          - /library/timelapse\.m3u8
          - /library/timelapse\.mp4
          - /library/timelapse\.ts
          - /library/tracked_objects
          - /license_plates/org/[0-9a-f-]{36}/get
          - /object_tracking/restore_backup
          - /org/get_region
          - /org/set_region
          - /set/camera/resource/accessibility
          - /stats
          - /submit/fullres/[0-9a-f-]{36}/[0-9]+
          - /submit/hyperzoom/[0-9]+/[0-9]+
          - /submit/motion_rollup
          - /submit/object_tracking/upload_url
          - /submit/object_tracking_hyperzoom/[0-9_-]+
          - /submit/raw_frame/[0-9]+
          - /submit/raw_frame_detections/[0-9]+
          - /submit/stats
          - /submit/thumbnail/[0-9a-f-]{36}/[0-9]+
          - /submit/thumbnail_detection/[0-9]+
          - /thumbnail/upload/url
          - /v1/floor_plan/get_history_heat_map
          - /v1/floor_plan/get_history_heat_map_cell
        unauthenticatedEndpoints:
          - /ping
          - /submit/persistent_change
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/retention_trigger/check
          - /camera/submit_transformation_matrix
          - /camera/transformation_matrix/calculate
          - /camera_poi/get_embedding_encryption_key
          - /camera_poi/get_org_pois
          - /camera_poi/get_org_pois_v2
          - /cameras/get_region
          - /cameras/set_region
          - /get/camera/resource/accessibility
          - /library/background
          - /library/calibration_image\.jpg
          - /library/closest_thumb\.jpg
          - /library/cloud_retention
          - /library/count_people
          - /library/detected_objects
          - /library/exact_thumb\.gif
          - /library/exact_thumb\.jpg
          - /library/exact_thumb\.json
          - /library/exact_thumb\.webp
          - /library/exemplar\.jpg
          - /library/fullres\.jpg
          - /library/fullres\.json
          - /library/get_seen_labels
          - /library/grid_10x10\.jpg
          - /library/grid_5x5\.jpg
          - /library/hyperzoom
          - /library/hyperzoom\.jpg
          - /library/latest\.jpg
          - /library/motion_coverage
          - /library/motion_search
          - /library/object_search
          - /library/object_search/v2
          - /library/object_stats
          - /library/object_tracking_hyperzoom\.jpg
          - /library/objects_in_range
          - /library/persistent_change
          - /library/representing_thumb_times
          - /library/thumb\.jpg
          - /library/timelapse\.m3u8
          - /library/timelapse\.mp4
          - /library/timelapse\.ts
          - /library/tracked_objects
          - /license_plates/org/[0-9a-f-]{36}/get
          - /object_tracking/restore_backup
          - /org/get_region
          - /org/set_region
          - /set/camera/resource/accessibility
          - /stats
          - /submit/fullres/[0-9a-f-]{36}/[0-9]+
          - /submit/hyperzoom/[0-9]+/[0-9]+
          - /submit/motion_rollup
          - /submit/object_tracking/upload_url
          - /submit/object_tracking_hyperzoom/[0-9_-]+
          - /submit/raw_frame/[0-9]+
          - /submit/raw_frame_detections/[0-9]+
          - /submit/stats
          - /submit/thumbnail/[0-9a-f-]{36}/[0-9]+
          - /submit/thumbnail_detection/[0-9]+
          - /thumbnail/upload/url
          - /v1/floor_plan/get_history_heat_map
          - /v1/floor_plan/get_history_heat_map_cell
        unauthenticatedEndpoints:
          - /ping
          - /submit/persistent_change
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vsubmit
    namespace: vinfra
    resourceVersion: "5009066723"
    uid: d8b6b95c-f3ef-45ab-ae85-868c3666454a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsuite.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /is_internal_user
          - /ping
        unauthenticatedEndpoints:
          - /log_user_session
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vsuite
    namespace: vinfra
    resourceVersion: "5009066725"
    uid: 6d4afbd3-b733-46ee-b641-59883308d038
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsupertest.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
          - /proxy/[\w\.\-]+/[\w\.\-]+/((.+)\/)*([^\/]+)
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vsupertest
    namespace: vinfra
    resourceVersion: "5009066728"
    uid: 51f29200-ecde-46d3-9bf0-37e5830dccb5
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vtestgen.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
          - /test
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vtestgen
    namespace: vinfra
    resourceVersion: "5009066730"
    uid: 99789f4a-a250-4859-a9d7-64657f4f737f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vtfserver.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /agents
          - /ping
          - /plan/logs
          - /workspaces
          - /workspaces/[a-zA-Z0-9_-]+
          - /workspaces/[a-zA-Z0-9_-]+/runs
          - /workspaces/[a-zA-Z0-9_-]+/runs/[a-zA-Z0-9_-]+
          - /workspaces/[a-zA-Z0-9_-]+/runs/[a-zA-Z0-9_-]+/apply
          - /workspaces/[a-zA-Z0-9_-]+/runs/[a-zA-Z0-9_-]+/logs
          - /workspaces/[a-zA-Z0-9_-]+/runs/regular
          - /workspaces/[a-zA-Z0-9_-]+/runs/speculative
      - host: vtfserver-http.staging.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /api/agents
          - /api/vcs_providers
          - /api/vcs_providers/[a-zA-Z0-9_-]+
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vtfserver
    namespace: vinfra
    resourceVersion: "5009066732"
    uid: db0fb0ea-f416-4a50-b455-e27355e94b64
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/cropped_thumbnail
          - /library/hyperzoom_by_track\.jpg
          - /library/hyperzoom_metadata_by_track
          - /library/video/enckey
          - /library/video/init\.mp4
          - /library/video/playlist\.m3u8
          - /library/video\.gif
          - /library/video_thumb\.jpg
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/cropped_thumbnail
          - /library/hyperzoom_by_track\.jpg
          - /library/hyperzoom_metadata_by_track
          - /library/video/enckey
          - /library/video/init\.mp4
          - /library/video/playlist\.m3u8
          - /library/video\.gif
          - /library/video_thumb\.jpg
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/cropped_thumbnail
          - /library/hyperzoom_by_track\.jpg
          - /library/hyperzoom_metadata_by_track
          - /library/video/enckey
          - /library/video/init\.mp4
          - /library/video/playlist\.m3u8
          - /library/video\.gif
          - /library/video_thumb\.jpg
      - host: vthumb.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/cropped_thumbnail
          - /library/hyperzoom_by_track\.jpg
          - /library/hyperzoom_metadata_by_track
          - /library/video/enckey
          - /library/video/init\.mp4
          - /library/video/playlist\.m3u8
          - /library/video\.gif
          - /library/video_thumb\.jpg
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vthumb
    namespace: vinfra
    resourceVersion: "5009066736"
    uid: 5bfe5c9b-3b0d-4549-b575-6aa034a5abee
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
        unauthenticatedEndpoints:
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support_window/become
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
        unauthenticatedEndpoints:
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support_window/become
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
        unauthenticatedEndpoints:
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support_window/become
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
        unauthenticatedEndpoints:
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support_window/become
      - host: vsupportapi.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/get_ffu_assets
          - /vtoolbox/public/get_ffu_assets_granular
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/become
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
      - host: vtoolbox.staging.cf.verkada.com
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/get_ffu_assets
          - /vtoolbox/public/get_ffu_assets_granular
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/become
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
      - host: vtoolbox.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/get_ffu_assets
          - /vtoolbox/public/get_ffu_assets_granular
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/become
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
      - host: vtoolbox.staging.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /api/global/fanout_gui
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vtoolbox
    namespace: vinfra
    resourceVersion: "5009066739"
    uid: 2a6cb81f-01f1-43ce-89a6-59e86209e2ca
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vvectordb.internal-gateway.staging.cf.verkada.com
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /collections/[\w\.\-]+/msearch
          - /collections/[\w\.\-]+/search
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vvectordb
    namespace: vinfra
    resourceVersion: "5009066743"
    uid: 8a517c30-e60b-4100-a3e6-89b27ded26a2
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
          - /vviewers/sites/streaminfo
          - /vviewers/streams/kickout
          - /vviewers/web/audioevent
          - /vviewers/web/faceblur
          - /vviewers/web/ws
      - host: vprovision.us.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
          - /vviewers/sites/streaminfo
          - /vviewers/streams/kickout
          - /vviewers/web/audioevent
          - /vviewers/web/faceblur
          - /vviewers/web/ws
      - host: "*.vprovision.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
          - /vviewers/sites/streaminfo
          - /vviewers/streams/kickout
          - /vviewers/web/audioevent
          - /vviewers/web/faceblur
          - /vviewers/web/ws
      - host: device-gateway.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
          - /vviewers/sites/streaminfo
          - /vviewers/streams/kickout
          - /vviewers/web/audioevent
          - /vviewers/web/faceblur
          - /vviewers/web/ws
      - host: vproxy.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
        unauthenticatedEndpoints:
          - /vviewers/ping
      - host: vstream.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
        unauthenticatedEndpoints:
          - /vviewers/ping
      - host: "*.vproxy.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
        unauthenticatedEndpoints:
          - /vviewers/ping
      - host: "*.vstream.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
        unauthenticatedEndpoints:
          - /vviewers/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vviewers
    namespace: vinfra
    resourceVersion: "5009066745"
    uid: c8d3cd84-0275-4e58-a6a7-8d64eeef5bee
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vvx.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/set_device_verkada_serial_number
          - /device/available_os_updates
          - /device/commission
          - /device/decommission
          - /device/ensure_state
          - /device/list
          - /device/os_update_status
          - /device/restart
          - /device/schedule_os_update_download
          - /device/schedule_os_update_install
          - /device/vx_os_update_status
          - /device/wifi/set
          - /devices/cameraHistoryInfo
          - /internal/viewing_station/firewall_test
          - /socket\.io/
          - /viewing_station/add_device_signing_key
          - /viewing_station/batch/status
          - /viewing_station/doors
          - /viewing_station/firewall/result
          - /viewing_station/firewall/targets
          - /viewing_station/firewall_test
          - /viewing_station/gateway/attached
          - /viewing_station/gateway/attached_devices
          - /viewing_station/get_shared_organization_key_id
          - /viewing_station/grid/banner
          - /viewing_station/grid/update
          - /viewing_station/init
          - /viewing_station/metrics
          - /viewing_station/retrieve_device_key_sharing_key
          - /viewing_station/retrieve_encrypted_customer_keys
          - /viewing_station/share_keys
          - /viewing_station/status
          - /viewing_station/update
          - /viewing_station/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+\.jpg
          - /viewing_station/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+\.png
          - /viewing_station/user_info/[0-9a-f-]{36}
          - /viewing_station/users/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:07Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vvx
    namespace: vinfra
    resourceVersion: "5009066748"
    uid: 927358f6-5c3d-4e2c-bc6c-57c26891dc48
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vworlddetect/test
      - host: vsubmit-global.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vworlddetect/test
      - host: "*.vsubmit.vnetcap.staging.vcamera.net"
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vworlddetect/test
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-vworlddetect
    namespace: vinfra
    resourceVersion: "5009066752"
    uid: 51af00db-d306-4747-8f95-b6259f89c825
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vpava.staging.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /web-api/action
          - /web-api/devices/[0-9a-f-]{36}/decommission
          - /web-api/devices/[0-9a-f-]{36}/settings
          - /web-api/devices/[0-9a-f-]{36}/update
          - /web-api/media
          - /web-api/media/[a-zA-Z0-9-]+
          - /web-api/organizations/[0-9a-f-]{36}/devices
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-04T01:24:08Z"
    labels:
      pattern: vshield-auth-check-bypass-component
      verkada/for_removal: "1740060682"
    name: vshield-auth-check-bypass-web-api
    namespace: vinfra
    resourceVersion: "5009066755"
    uid: a4ae32d5-11a7-4062-bbb0-e3766d003db1
kind: List
metadata:
  resourceVersion: ""
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: localhost:10000
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /  
)";

// Bypass config for staging2
const std::string auth_bypass_config_yaml_staging2 = R"(
apiVersion: v1
items:
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: localhost:10000
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /core/v1/user/command/init
          - /org/[0-9a-f-]{36}/user/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /core/v1/command/login/password
          - /core/v1/organization/get_for_user
          - /core/v1/organization/short_name/validate
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/disable
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/enable
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories
          - /core/v1/user/auth/challenges
          - /core/v1/user/magic_link/redeem
          - /internal/core/v1/organization/[0-9a-f-]{36}
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /core/v1/user/command/init
          - /org/[0-9a-f-]{36}/user/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /core/v1/command/login/password
          - /core/v1/organization/get_for_user
          - /core/v1/organization/short_name/validate
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/disable
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/enable
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories
          - /core/v1/user/auth/challenges
          - /core/v1/user/magic_link/redeem
          - /internal/core/v1/organization/[0-9a-f-]{36}
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /core/v1/user/command/init
          - /org/[0-9a-f-]{36}/user/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /core/v1/command/login/password
          - /core/v1/organization/get_for_user
          - /core/v1/organization/short_name/validate
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/disable
          - /core/v1/organizations/[0-9a-f-]{36}/features/user_directories/enable
          - /core/v1/organizations/[0-9a-f-]{36}/user_directories
          - /core/v1/user/auth/challenges
          - /core/v1/user/magic_link/redeem
          - /internal/core/v1/organization/[0-9a-f-]{36}
      - host: vprovision.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /core/v1/organization/get_for_user
          - /core/v1/organization/short_name/validate
          - /internal/core/v1/organization/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-dollhouse
    namespace: vinfra
    resourceVersion: "2459774846"
    uid: c00ac524-e71e-4016-af90-efb28ba58623
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: istio-test.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
      - host: istio-test.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /istio-synthetic-tests/noistio/ping
          - /istio-synthetic-tests/sidecar/ping
          - /istio-synthetic-tests/ztunnel/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2025-01-24T06:20:59Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-istio
    namespace: vinfra
    resourceVersion: "2418256183"
    uid: 2382b1a5-f70f-4d38-a9bc-733118181702
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /heartbeat
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /heartbeat
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /heartbeat
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-tachometer
    namespace: vinfra
    resourceVersion: "2417982140"
    uid: d3d84519-409f-4cd6-ade7-9bac1f87477d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vcerberus.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /integrations/atrium/card_types
          - /integrations/atrium/card_types_mapping
          - /integrations/atrium/credentials
          - /integrations/atrium/user_import
      - host: access.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /integrations/atrium/card_types
          - /integrations/atrium/card_types_mapping
          - /integrations/atrium/credentials
          - /integrations/atrium/user_import
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-20T16:12:35Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vaccessintegrations
    namespace: vinfra
    resourceVersion: "2364433419"
    uid: c8bb5d64-ccbc-4288-9bb5-4e270c7a63b9
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vagent.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /agent_workflow/get
          - /agent_workflow/step/checkpoint/create
          - /agent_workflow/step/update
          - /cases/claim
          - /cases/create
          - /cases/create_comment
          - /cases/create_verification
          - /cases/dispatch_profile/set
          - /cases/get
          - /cases/heartbeat
          - /cases/list
          - /cases/list_comments
          - /cases/list_contexts
          - /cases/list_history
          - /cases/list_verifications
          - /cases/pause
          - /cases/security_tokens
          - /cases/update
          - /cases/update_verification
          - /conference/get_details
          - /conference/list
          - /conference/start
          - /conversation/list_messages
          - /device/cases/close
          - /device/cases/create
          - /device/cases/get
          - /device/cases/resolve
          - /dispatch/confirm
          - /dispatch/create
          - /dispatch/get_psap_info
          - /dispatch/list
          - /dispatch/request
          - /dispatch/update
          - /sms/batch_update
          - /sms/create
          - /sms/list
        unauthenticatedEndpoints:
          - /ping
          - /twilio/conference/recording_status_callback
          - /twilio/conference/status_callback
          - /twilio/sms/media
          - /twilio/sms/receive_callback
          - /twilio/sms/send_status_callback
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vagent
    namespace: vinfra
    resourceVersion: "2463023267"
    uid: 1bc23e4f-4849-442b-9a5d-001ee4814dcc
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: valarm.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alarm/details
          - /alarm_configuration/add_person_detected_camera
          - /alarm_configuration/add_user_to_notify
          - /alarm_configuration/create
          - /alarm_configuration/delete
          - /alarm_configuration/details
          - /alarm_configuration/emergency_dispatch_context_camera/add
          - /alarm_configuration/emergency_dispatch_context_camera/update
          - /alarm_configuration/list
          - /alarm_configuration/remove_user_to_notify
          - /alarm_configuration/select_all_access_entity_triggers
          - /alarm_configuration/select_all_camera_triggers
          - /alarm_configuration/select_all_environmental_sensor_triggers
          - /alarm_configuration/select_all_keypad_triggers
          - /alarm_configuration/set_remote_monitoring_users
          - /alarm_configuration/update
          - /alarm_configuration/update_access_action_doors
          - /alarm_configuration/update_access_doors
          - /alarm_configuration/update_access_entity
          - /alarm_configuration/update_camera
          - /alarm_configuration/update_environmental_sensor
          - /alarm_configuration/update_environmental_sensors
          - /alarm_configuration/update_keypad
          - /alarm_configuration_user/bulk_set
          - /alarm_configuration_user/create
          - /alarm_configuration_user/push_enabled
          - /alarm_configuration_user/update
          - /alarm_events
          - /alarm_feedback/create
          - /alarm_feedback/get
          - /alarm_feedback/update
          - /alarm_response_schedule/list
          - /alarm_response_schedule/update_list
          - /bulk/alarm_configuration/update
          - /bulk/alarm_configuration/update_users_to_notify
          - /bulk/keycode/add
          - /bulk/zone/arm
          - /bulk/zone/disarm
          - /bulk/zone/submit_command_event
          - /bulk/zone/update
          - /bulk/zone/update_postal_address
          - /bulk/zone/update_unusual_state_change_windows
          - /bulk/zone/update_zone_arm_schedules
          - /camera_event/get_roi_overlap
          - /cellular/submit_ping
          - /command/lockout_event/submit
          - /debug/create_sensor_event
          - /device/commission/unassigned/batch
          - /device/current_state
          - /device/disable_learning_mode
          - /device/enable_learning_mode
          - /device/event/acknowledge
          - /device/event/list
          - /device/get_all
          - /device/get_or_create_wireless_device
          - /device/hub/[0-9a-f-]{36}
          - /device/hub/commission
          - /device/hub/decommission
          - /device/hub/details
          - /device/hub/list
          - /device/hub/submit_battery_reading
          - /device/hub/submit_wireless_stat_group
          - /device/hub/wireless_join_request
          - /device/hub_wireless_device/commission
          - /device/keypad/add_to_zone
          - /device/keypad/commission
          - /device/keypad/decommission
          - /device/keypad/get_all
          - /device/keypad/get_info
          - /device/keypad/hub_list
          - /device/keypad/restart
          - /device/keypad/unassigned/get_all
          - /device/keypad/update
          - /device/keypad_hub/commission
          - /device/keypad_hub/decommission
          - /device/rs485/sign_request
          - /device/sensor/add_nearby_camera
          - /device/sensor/add_to_zone
          - /device/sensor/delete
          - /device/sensor/remove_from_zone
          - /device/sensor/remove_nearby_camera
          - /device/sensor/update
          - /device/setup/batch
          - /device/unassigned/get_all
          - /device/warnings
          - /door/zone/get_configs
          - /door/zone/update_configs
          - /event
          - /event/detailed_organization_alarm_list
          - /event/detailed_zone_state_change_list
          - /event/hub_submit
          - /event/hub_submit_autogenic
          - /event/hub_submit_sync_state
          - /event/list
          - /event/persistent_change_datapoints
          - /event/person_detected_datapoints
          - /event/resolve_alarm
          - /event/submit
          - /event/submit_wired_sensor_event
          - /event/upload_event_log
          - /gpio_pin_configuration/create_or_update
          - /gpio_pin_configuration/delete
          - /gpio_pin_configuration/details
          - /gpio_pin_configuration/list
          - /gpio_pin_configuration/update_hub_device_id
          - /hub/init
          - /hub/key_rotation
          - /hub/peers/webrtc
          - /integration_test/create_live_link
          - /keycode/create
          - /keycode/create/user
          - /keycode/delete
          - /keycode/update
          - /keycode/update/user
          - /keycode/user
          - /keypad/arm_countdown
          - /keypad/asset/download/((.+)\/)*([^\/]+)
          - /keypad/camera_groups
          - /keypad/cameras
          - /keypad/cellular_devices
          - /keypad/configurations
          - /keypad/device/event/list
          - /keypad/devices/access_devices
          - /keypad/devices/cameras
          - /keypad/devices/environmental_sensors
          - /keypad/devices/hub_groups
          - /keypad/devices/speakers
          - /keypad/doors
          - /keypad/environmental_sensors
          - /keypad/event/submit
          - /keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /keypad/keycodes
          - /keypad/list
          - /keypad/server_connectivity_status
          - /keypad/submit_offline_event
          - /keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /keypad/thumbnail/upload
          - /keypad/tts/generate
          - /keypad/update_device_info
          - /keypad/users
          - /keypad/v2/device/event/list
          - /keypad/video/download/playlist\.m3u8
          - /keypad/video/download/video\.ts
          - /keypad/video/upload
          - /keypad/zone/details
          - /keypad/zone/details/list
          - /keypad/zone/get_zone_associations
          - /keypad/zone/list
          - /keypad/zone/set_associations
          - /keypad/zone/update_configs
          - /keypad/zones
          - /licensing/overview
          - /org_alarm_settings/get
          - /org_alarm_settings/update
          - /organization/usage/video_verification
          - /organization/usage/video_verification/by_day
          - /output_pin_configuration/create_or_update
          - /output_pin_configuration/delete
          - /output_pin_configuration/details
          - /output_pin_configuration/list
          - /output_pin_configuration/update_hub_device_id
          - /peer_connection/list
          - /person_detected_data_point/list
          - /postal_address/create
          - /postal_address/delete
          - /postal_address/list
          - /postal_address/update
          - /postal_address/usage/video_verification
          - /read_only_check
          - /reporting/devices
          - /reporting/event_types
          - /reporting/events
          - /reporting/walk_tests
          - /unusual_state_change_window/list
          - /unusual_state_change_window/update_list
          - /valarm_internal_user/admin/delete_moved_cameras_for_zone/dry_run
          - /valarm_internal_user/admin/device/hub/decommission
          - /valarm_internal_user/admin/device/hub/list
          - /valarm_internal_user/admin/device/keypad/decommission
          - /valarm_internal_user/admin/device/wireless_sensor/decommission
          - /valarm_internal_user/admin/get_camera_config
          - /valarm_internal_user/admin/lockouts
          - /valarm_internal_user/admin/set_wireless_regulatory_code
          - /valarm_internal_user/create_shared_camera_for_trip
          - /valarm_internal_user/device/sensor/update
          - /valarm_internal_user/public/v1/devices
          - /valarm_internal_user/public/v1/sites
          - /valarm_internal_user/s3/alarm_event/video/presigned
          - /valarm_internal_user/send_camera_gif
          - /webrtc/get_ice_servers
          - /websocket/submit_webrtc_offer
          - /wireless_output_configs/create
          - /wireless_output_configs/delete
          - /wireless_output_configs/update
          - /zone/alarms_overview
          - /zone/arm
          - /zone/create
          - /zone/delete
          - /zone/details
          - /zone/disarm
          - /zone/list
          - /zone/status
          - /zone/submit_command_event
          - /zone/submit_mobile_event
          - /zone/toggle_walk_test_mode
          - /zone/update
          - /zone/update_postal_address
          - /zone/usage/video_verification
          - /zone/users
          - /zone/walk_test_report
          - /zone/walk_test_status
          - /zone_activity/items
          - /zone_arm_schedule/list
          - /zone_arm_schedule/update_list
        unauthenticatedEndpoints:
          - /[a-zA-Z0-9]{40}/camera_thumbnail\.gif
          - /[a-zA-Z0-9]{40}/camera_thumbnail_v2\.gif
          - /alarm_flow_health_check
          - /alarms-app/magic-link
          - /arm_schedule_check
          - /cellular/events/twilio
          - /events/noonlight_webhook
          - /keypad_thumbnail/with_secret_token/[a-zA-Z0-9]{64}\.jpeg
          - /ping
          - /schedule/noonlight_webhook/disarm_override
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/((.+)\/)*([^\/]+)
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/video\.m3u8
          - /shared_camera/[0-9a-f-]{36}/live/((.+)\/)*([^\/]+)
          - /socket\.io/
          - /talkdown/zone/details
          - /valarm/ping
          - /valarm_internal_user/admin/openapi/json
          - /video_verification/noonlight_webhook
          - /webrtc/get_ice_servers_talkdown
          - /worker_health_check
          - /zone/talkdown/details
      - host: alarms.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alarm/details
          - /alarm_configuration/add_person_detected_camera
          - /alarm_configuration/add_user_to_notify
          - /alarm_configuration/create
          - /alarm_configuration/delete
          - /alarm_configuration/details
          - /alarm_configuration/emergency_dispatch_context_camera/add
          - /alarm_configuration/emergency_dispatch_context_camera/update
          - /alarm_configuration/list
          - /alarm_configuration/remove_user_to_notify
          - /alarm_configuration/select_all_access_entity_triggers
          - /alarm_configuration/select_all_camera_triggers
          - /alarm_configuration/select_all_environmental_sensor_triggers
          - /alarm_configuration/select_all_keypad_triggers
          - /alarm_configuration/set_remote_monitoring_users
          - /alarm_configuration/update
          - /alarm_configuration/update_access_action_doors
          - /alarm_configuration/update_access_doors
          - /alarm_configuration/update_access_entity
          - /alarm_configuration/update_camera
          - /alarm_configuration/update_environmental_sensor
          - /alarm_configuration/update_environmental_sensors
          - /alarm_configuration/update_keypad
          - /alarm_configuration_user/bulk_set
          - /alarm_configuration_user/create
          - /alarm_configuration_user/push_enabled
          - /alarm_configuration_user/update
          - /alarm_events
          - /alarm_feedback/create
          - /alarm_feedback/get
          - /alarm_feedback/update
          - /alarm_response_schedule/list
          - /alarm_response_schedule/update_list
          - /bulk/alarm_configuration/update
          - /bulk/alarm_configuration/update_users_to_notify
          - /bulk/keycode/add
          - /bulk/zone/arm
          - /bulk/zone/disarm
          - /bulk/zone/submit_command_event
          - /bulk/zone/update
          - /bulk/zone/update_postal_address
          - /bulk/zone/update_unusual_state_change_windows
          - /bulk/zone/update_zone_arm_schedules
          - /camera_event/get_roi_overlap
          - /cellular/submit_ping
          - /command/lockout_event/submit
          - /debug/create_sensor_event
          - /device/commission/unassigned/batch
          - /device/current_state
          - /device/disable_learning_mode
          - /device/enable_learning_mode
          - /device/event/acknowledge
          - /device/event/list
          - /device/get_all
          - /device/get_or_create_wireless_device
          - /device/hub/[0-9a-f-]{36}
          - /device/hub/commission
          - /device/hub/decommission
          - /device/hub/details
          - /device/hub/list
          - /device/hub/submit_battery_reading
          - /device/hub/submit_wireless_stat_group
          - /device/hub/wireless_join_request
          - /device/hub_wireless_device/commission
          - /device/keypad/add_to_zone
          - /device/keypad/commission
          - /device/keypad/decommission
          - /device/keypad/get_all
          - /device/keypad/get_info
          - /device/keypad/hub_list
          - /device/keypad/restart
          - /device/keypad/unassigned/get_all
          - /device/keypad/update
          - /device/keypad_hub/commission
          - /device/keypad_hub/decommission
          - /device/rs485/sign_request
          - /device/sensor/add_nearby_camera
          - /device/sensor/add_to_zone
          - /device/sensor/delete
          - /device/sensor/remove_from_zone
          - /device/sensor/remove_nearby_camera
          - /device/sensor/update
          - /device/setup/batch
          - /device/unassigned/get_all
          - /device/warnings
          - /door/zone/get_configs
          - /door/zone/update_configs
          - /event
          - /event/detailed_organization_alarm_list
          - /event/detailed_zone_state_change_list
          - /event/hub_submit
          - /event/hub_submit_autogenic
          - /event/hub_submit_sync_state
          - /event/list
          - /event/persistent_change_datapoints
          - /event/person_detected_datapoints
          - /event/resolve_alarm
          - /event/submit
          - /event/submit_wired_sensor_event
          - /event/upload_event_log
          - /gpio_pin_configuration/create_or_update
          - /gpio_pin_configuration/delete
          - /gpio_pin_configuration/details
          - /gpio_pin_configuration/list
          - /gpio_pin_configuration/update_hub_device_id
          - /hub/init
          - /hub/key_rotation
          - /hub/peers/webrtc
          - /integration_test/create_live_link
          - /keycode/create
          - /keycode/create/user
          - /keycode/delete
          - /keycode/update
          - /keycode/update/user
          - /keycode/user
          - /keypad/arm_countdown
          - /keypad/asset/download/((.+)\/)*([^\/]+)
          - /keypad/camera_groups
          - /keypad/cameras
          - /keypad/cellular_devices
          - /keypad/configurations
          - /keypad/device/event/list
          - /keypad/devices/access_devices
          - /keypad/devices/cameras
          - /keypad/devices/environmental_sensors
          - /keypad/devices/hub_groups
          - /keypad/devices/speakers
          - /keypad/doors
          - /keypad/environmental_sensors
          - /keypad/event/submit
          - /keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /keypad/keycodes
          - /keypad/list
          - /keypad/server_connectivity_status
          - /keypad/submit_offline_event
          - /keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /keypad/thumbnail/upload
          - /keypad/tts/generate
          - /keypad/update_device_info
          - /keypad/users
          - /keypad/v2/device/event/list
          - /keypad/video/download/playlist\.m3u8
          - /keypad/video/download/video\.ts
          - /keypad/video/upload
          - /keypad/zone/details
          - /keypad/zone/details/list
          - /keypad/zone/get_zone_associations
          - /keypad/zone/list
          - /keypad/zone/set_associations
          - /keypad/zone/update_configs
          - /keypad/zones
          - /licensing/overview
          - /org_alarm_settings/get
          - /org_alarm_settings/update
          - /organization/usage/video_verification
          - /organization/usage/video_verification/by_day
          - /output_pin_configuration/create_or_update
          - /output_pin_configuration/delete
          - /output_pin_configuration/details
          - /output_pin_configuration/list
          - /output_pin_configuration/update_hub_device_id
          - /peer_connection/list
          - /person_detected_data_point/list
          - /postal_address/create
          - /postal_address/delete
          - /postal_address/list
          - /postal_address/update
          - /postal_address/usage/video_verification
          - /read_only_check
          - /reporting/devices
          - /reporting/event_types
          - /reporting/events
          - /reporting/walk_tests
          - /unusual_state_change_window/list
          - /unusual_state_change_window/update_list
          - /valarm_internal_user/admin/delete_moved_cameras_for_zone/dry_run
          - /valarm_internal_user/admin/device/hub/decommission
          - /valarm_internal_user/admin/device/hub/list
          - /valarm_internal_user/admin/device/keypad/decommission
          - /valarm_internal_user/admin/device/wireless_sensor/decommission
          - /valarm_internal_user/admin/get_camera_config
          - /valarm_internal_user/admin/lockouts
          - /valarm_internal_user/admin/set_wireless_regulatory_code
          - /valarm_internal_user/create_shared_camera_for_trip
          - /valarm_internal_user/device/sensor/update
          - /valarm_internal_user/public/v1/devices
          - /valarm_internal_user/public/v1/sites
          - /valarm_internal_user/s3/alarm_event/video/presigned
          - /valarm_internal_user/send_camera_gif
          - /webrtc/get_ice_servers
          - /websocket/submit_webrtc_offer
          - /wireless_output_configs/create
          - /wireless_output_configs/delete
          - /wireless_output_configs/update
          - /zone/alarms_overview
          - /zone/arm
          - /zone/create
          - /zone/delete
          - /zone/details
          - /zone/disarm
          - /zone/list
          - /zone/status
          - /zone/submit_command_event
          - /zone/submit_mobile_event
          - /zone/toggle_walk_test_mode
          - /zone/update
          - /zone/update_postal_address
          - /zone/usage/video_verification
          - /zone/users
          - /zone/walk_test_report
          - /zone/walk_test_status
          - /zone_activity/items
          - /zone_arm_schedule/list
          - /zone_arm_schedule/update_list
        unauthenticatedEndpoints:
          - /[a-zA-Z0-9]{40}/camera_thumbnail\.gif
          - /[a-zA-Z0-9]{40}/camera_thumbnail_v2\.gif
          - /alarm_flow_health_check
          - /alarms-app/magic-link
          - /arm_schedule_check
          - /cellular/events/twilio
          - /events/noonlight_webhook
          - /keypad_thumbnail/with_secret_token/[a-zA-Z0-9]{64}\.jpeg
          - /ping
          - /schedule/noonlight_webhook/disarm_override
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/((.+)\/)*([^\/]+)
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/video\.m3u8
          - /shared_camera/[0-9a-f-]{36}/live/((.+)\/)*([^\/]+)
          - /socket\.io/
          - /talkdown/zone/details
          - /valarm/ping
          - /valarm_internal_user/admin/openapi/json
          - /video_verification/noonlight_webhook
          - /webrtc/get_ice_servers_talkdown
          - /worker_health_check
          - /zone/talkdown/details
      - host: device-alarms.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alarm/details
          - /alarm_configuration/add_person_detected_camera
          - /alarm_configuration/add_user_to_notify
          - /alarm_configuration/create
          - /alarm_configuration/delete
          - /alarm_configuration/details
          - /alarm_configuration/emergency_dispatch_context_camera/add
          - /alarm_configuration/emergency_dispatch_context_camera/update
          - /alarm_configuration/list
          - /alarm_configuration/remove_user_to_notify
          - /alarm_configuration/select_all_access_entity_triggers
          - /alarm_configuration/select_all_camera_triggers
          - /alarm_configuration/select_all_environmental_sensor_triggers
          - /alarm_configuration/select_all_keypad_triggers
          - /alarm_configuration/set_remote_monitoring_users
          - /alarm_configuration/update
          - /alarm_configuration/update_access_action_doors
          - /alarm_configuration/update_access_doors
          - /alarm_configuration/update_access_entity
          - /alarm_configuration/update_camera
          - /alarm_configuration/update_environmental_sensor
          - /alarm_configuration/update_environmental_sensors
          - /alarm_configuration/update_keypad
          - /alarm_configuration_user/bulk_set
          - /alarm_configuration_user/create
          - /alarm_configuration_user/push_enabled
          - /alarm_configuration_user/update
          - /alarm_events
          - /alarm_feedback/create
          - /alarm_feedback/get
          - /alarm_feedback/update
          - /alarm_response_schedule/list
          - /alarm_response_schedule/update_list
          - /bulk/alarm_configuration/update
          - /bulk/alarm_configuration/update_users_to_notify
          - /bulk/keycode/add
          - /bulk/zone/arm
          - /bulk/zone/disarm
          - /bulk/zone/submit_command_event
          - /bulk/zone/update
          - /bulk/zone/update_postal_address
          - /bulk/zone/update_unusual_state_change_windows
          - /bulk/zone/update_zone_arm_schedules
          - /camera_event/get_roi_overlap
          - /cellular/submit_ping
          - /command/lockout_event/submit
          - /debug/create_sensor_event
          - /device/commission/unassigned/batch
          - /device/current_state
          - /device/disable_learning_mode
          - /device/enable_learning_mode
          - /device/event/acknowledge
          - /device/event/list
          - /device/get_all
          - /device/get_or_create_wireless_device
          - /device/hub/[0-9a-f-]{36}
          - /device/hub/commission
          - /device/hub/decommission
          - /device/hub/details
          - /device/hub/list
          - /device/hub/submit_battery_reading
          - /device/hub/submit_wireless_stat_group
          - /device/hub/wireless_join_request
          - /device/hub_wireless_device/commission
          - /device/keypad/add_to_zone
          - /device/keypad/commission
          - /device/keypad/decommission
          - /device/keypad/get_all
          - /device/keypad/get_info
          - /device/keypad/hub_list
          - /device/keypad/restart
          - /device/keypad/unassigned/get_all
          - /device/keypad/update
          - /device/keypad_hub/commission
          - /device/keypad_hub/decommission
          - /device/rs485/sign_request
          - /device/sensor/add_nearby_camera
          - /device/sensor/add_to_zone
          - /device/sensor/delete
          - /device/sensor/remove_from_zone
          - /device/sensor/remove_nearby_camera
          - /device/sensor/update
          - /device/setup/batch
          - /device/unassigned/get_all
          - /device/warnings
          - /door/zone/get_configs
          - /door/zone/update_configs
          - /event
          - /event/detailed_organization_alarm_list
          - /event/detailed_zone_state_change_list
          - /event/hub_submit
          - /event/hub_submit_autogenic
          - /event/hub_submit_sync_state
          - /event/list
          - /event/persistent_change_datapoints
          - /event/person_detected_datapoints
          - /event/resolve_alarm
          - /event/submit
          - /event/submit_wired_sensor_event
          - /event/upload_event_log
          - /gpio_pin_configuration/create_or_update
          - /gpio_pin_configuration/delete
          - /gpio_pin_configuration/details
          - /gpio_pin_configuration/list
          - /gpio_pin_configuration/update_hub_device_id
          - /hub/init
          - /hub/key_rotation
          - /hub/peers/webrtc
          - /integration_test/create_live_link
          - /keycode/create
          - /keycode/create/user
          - /keycode/delete
          - /keycode/update
          - /keycode/update/user
          - /keycode/user
          - /keypad/arm_countdown
          - /keypad/asset/download/((.+)\/)*([^\/]+)
          - /keypad/camera_groups
          - /keypad/cameras
          - /keypad/cellular_devices
          - /keypad/configurations
          - /keypad/device/event/list
          - /keypad/devices/access_devices
          - /keypad/devices/cameras
          - /keypad/devices/environmental_sensors
          - /keypad/devices/hub_groups
          - /keypad/devices/speakers
          - /keypad/doors
          - /keypad/environmental_sensors
          - /keypad/event/submit
          - /keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /keypad/keycodes
          - /keypad/list
          - /keypad/server_connectivity_status
          - /keypad/submit_offline_event
          - /keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /keypad/thumbnail/upload
          - /keypad/tts/generate
          - /keypad/update_device_info
          - /keypad/users
          - /keypad/v2/device/event/list
          - /keypad/video/download/playlist\.m3u8
          - /keypad/video/download/video\.ts
          - /keypad/video/upload
          - /keypad/zone/details
          - /keypad/zone/details/list
          - /keypad/zone/get_zone_associations
          - /keypad/zone/list
          - /keypad/zone/set_associations
          - /keypad/zone/update_configs
          - /keypad/zones
          - /licensing/overview
          - /org_alarm_settings/get
          - /org_alarm_settings/update
          - /organization/usage/video_verification
          - /organization/usage/video_verification/by_day
          - /output_pin_configuration/create_or_update
          - /output_pin_configuration/delete
          - /output_pin_configuration/details
          - /output_pin_configuration/list
          - /output_pin_configuration/update_hub_device_id
          - /peer_connection/list
          - /person_detected_data_point/list
          - /postal_address/create
          - /postal_address/delete
          - /postal_address/list
          - /postal_address/update
          - /postal_address/usage/video_verification
          - /read_only_check
          - /reporting/devices
          - /reporting/event_types
          - /reporting/events
          - /reporting/walk_tests
          - /unusual_state_change_window/list
          - /unusual_state_change_window/update_list
          - /valarm_internal_user/admin/delete_moved_cameras_for_zone/dry_run
          - /valarm_internal_user/admin/device/hub/decommission
          - /valarm_internal_user/admin/device/hub/list
          - /valarm_internal_user/admin/device/keypad/decommission
          - /valarm_internal_user/admin/device/wireless_sensor/decommission
          - /valarm_internal_user/admin/get_camera_config
          - /valarm_internal_user/admin/lockouts
          - /valarm_internal_user/admin/set_wireless_regulatory_code
          - /valarm_internal_user/create_shared_camera_for_trip
          - /valarm_internal_user/device/sensor/update
          - /valarm_internal_user/public/v1/devices
          - /valarm_internal_user/public/v1/sites
          - /valarm_internal_user/s3/alarm_event/video/presigned
          - /valarm_internal_user/send_camera_gif
          - /webrtc/get_ice_servers
          - /websocket/submit_webrtc_offer
          - /wireless_output_configs/create
          - /wireless_output_configs/delete
          - /wireless_output_configs/update
          - /zone/alarms_overview
          - /zone/arm
          - /zone/create
          - /zone/delete
          - /zone/details
          - /zone/disarm
          - /zone/list
          - /zone/status
          - /zone/submit_command_event
          - /zone/submit_mobile_event
          - /zone/toggle_walk_test_mode
          - /zone/update
          - /zone/update_postal_address
          - /zone/usage/video_verification
          - /zone/users
          - /zone/walk_test_report
          - /zone/walk_test_status
          - /zone_activity/items
          - /zone_arm_schedule/list
          - /zone_arm_schedule/update_list
        unauthenticatedEndpoints:
          - /[a-zA-Z0-9]{40}/camera_thumbnail\.gif
          - /[a-zA-Z0-9]{40}/camera_thumbnail_v2\.gif
          - /alarm_flow_health_check
          - /alarms-app/magic-link
          - /arm_schedule_check
          - /cellular/events/twilio
          - /events/noonlight_webhook
          - /keypad_thumbnail/with_secret_token/[a-zA-Z0-9]{64}\.jpeg
          - /ping
          - /schedule/noonlight_webhook/disarm_override
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/((.+)\/)*([^\/]+)
          - /shared_camera/[0-9a-f-]{36}/[0-9]{10}-[0-9]{10}/video\.m3u8
          - /shared_camera/[0-9a-f-]{36}/live/((.+)\/)*([^\/]+)
          - /socket\.io/
          - /talkdown/zone/details
          - /valarm/ping
          - /valarm_internal_user/admin/openapi/json
          - /video_verification/noonlight_webhook
          - /webrtc/get_ice_servers_talkdown
          - /worker_health_check
          - /zone/talkdown/details
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /valarm/cellular/submit_ping
          - /valarm/command/lockout_event/submit
          - /valarm/device/current_state
          - /valarm/device/get_or_create_wireless_device
          - /valarm/device/hub/submit_battery_reading
          - /valarm/device/hub/submit_wireless_stat_group
          - /valarm/device/hub/wireless_join_request
          - /valarm/device/keypad/hub_list
          - /valarm/device/rs485/sign_request
          - /valarm/door/zone/get_configs
          - /valarm/event/hub_submit
          - /valarm/event/hub_submit_autogenic
          - /valarm/event/hub_submit_sync_state
          - /valarm/event/resolve_alarm
          - /valarm/event/upload_event_log
          - /valarm/hub/init
          - /valarm/hub/key_rotation
          - /valarm/hub/peers/webrtc
          - /valarm/keypad/arm_countdown
          - /valarm/keypad/asset/download/((.+)\/)*([^\/]+)
          - /valarm/keypad/camera_groups
          - /valarm/keypad/cameras
          - /valarm/keypad/cellular_devices
          - /valarm/keypad/configurations
          - /valarm/keypad/device/event/list
          - /valarm/keypad/devices/access_devices
          - /valarm/keypad/devices/cameras
          - /valarm/keypad/devices/environmental_sensors
          - /valarm/keypad/devices/hub_groups
          - /valarm/keypad/devices/speakers
          - /valarm/keypad/doors
          - /valarm/keypad/environmental_sensors
          - /valarm/keypad/event/submit
          - /valarm/keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /valarm/keypad/keycodes
          - /valarm/keypad/list
          - /valarm/keypad/server_connectivity_status
          - /valarm/keypad/submit_offline_event
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /valarm/keypad/thumbnail/upload
          - /valarm/keypad/tts/generate
          - /valarm/keypad/update_device_info
          - /valarm/keypad/users
          - /valarm/keypad/v2/device/event/list
          - /valarm/keypad/video/download/playlist\.m3u8
          - /valarm/keypad/video/download/video\.ts
          - /valarm/keypad/video/upload
          - /valarm/keypad/zone/details
          - /valarm/keypad/zone/details/list
          - /valarm/keypad/zone/get_zone_associations
          - /valarm/keypad/zone/list
          - /valarm/keypad/zone/set_associations
          - /valarm/keypad/zone/update_configs
          - /valarm/keypad/zones
          - /valarm/reporting/event_types
          - /valarm/webrtc/get_ice_servers
          - /valarm/zone/arm
          - /valarm/zone/disarm
        unauthenticatedEndpoints:
          - /valarm/ping
          - /valarm/webrtc/get_ice_servers_talkdown
          - /valarm/websocket/submit_webrtc_offer
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /valarm/cellular/submit_ping
          - /valarm/command/lockout_event/submit
          - /valarm/device/current_state
          - /valarm/device/get_or_create_wireless_device
          - /valarm/device/hub/submit_battery_reading
          - /valarm/device/hub/submit_wireless_stat_group
          - /valarm/device/hub/wireless_join_request
          - /valarm/device/keypad/hub_list
          - /valarm/device/rs485/sign_request
          - /valarm/door/zone/get_configs
          - /valarm/event/hub_submit
          - /valarm/event/hub_submit_autogenic
          - /valarm/event/hub_submit_sync_state
          - /valarm/event/resolve_alarm
          - /valarm/event/upload_event_log
          - /valarm/hub/init
          - /valarm/hub/key_rotation
          - /valarm/hub/peers/webrtc
          - /valarm/keypad/arm_countdown
          - /valarm/keypad/asset/download/((.+)\/)*([^\/]+)
          - /valarm/keypad/camera_groups
          - /valarm/keypad/cameras
          - /valarm/keypad/cellular_devices
          - /valarm/keypad/configurations
          - /valarm/keypad/device/event/list
          - /valarm/keypad/devices/access_devices
          - /valarm/keypad/devices/cameras
          - /valarm/keypad/devices/environmental_sensors
          - /valarm/keypad/devices/hub_groups
          - /valarm/keypad/devices/speakers
          - /valarm/keypad/doors
          - /valarm/keypad/environmental_sensors
          - /valarm/keypad/event/submit
          - /valarm/keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /valarm/keypad/keycodes
          - /valarm/keypad/list
          - /valarm/keypad/server_connectivity_status
          - /valarm/keypad/submit_offline_event
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /valarm/keypad/thumbnail/upload
          - /valarm/keypad/tts/generate
          - /valarm/keypad/update_device_info
          - /valarm/keypad/users
          - /valarm/keypad/v2/device/event/list
          - /valarm/keypad/video/download/playlist\.m3u8
          - /valarm/keypad/video/download/video\.ts
          - /valarm/keypad/video/upload
          - /valarm/keypad/zone/details
          - /valarm/keypad/zone/details/list
          - /valarm/keypad/zone/get_zone_associations
          - /valarm/keypad/zone/list
          - /valarm/keypad/zone/set_associations
          - /valarm/keypad/zone/update_configs
          - /valarm/keypad/zones
          - /valarm/reporting/event_types
          - /valarm/webrtc/get_ice_servers
          - /valarm/zone/arm
          - /valarm/zone/disarm
        unauthenticatedEndpoints:
          - /valarm/ping
          - /valarm/webrtc/get_ice_servers_talkdown
          - /valarm/websocket/submit_webrtc_offer
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /valarm/cellular/submit_ping
          - /valarm/command/lockout_event/submit
          - /valarm/device/current_state
          - /valarm/device/get_or_create_wireless_device
          - /valarm/device/hub/submit_battery_reading
          - /valarm/device/hub/submit_wireless_stat_group
          - /valarm/device/hub/wireless_join_request
          - /valarm/device/keypad/hub_list
          - /valarm/device/rs485/sign_request
          - /valarm/door/zone/get_configs
          - /valarm/event/hub_submit
          - /valarm/event/hub_submit_autogenic
          - /valarm/event/hub_submit_sync_state
          - /valarm/event/resolve_alarm
          - /valarm/event/upload_event_log
          - /valarm/hub/init
          - /valarm/hub/key_rotation
          - /valarm/hub/peers/webrtc
          - /valarm/keypad/arm_countdown
          - /valarm/keypad/asset/download/((.+)\/)*([^\/]+)
          - /valarm/keypad/camera_groups
          - /valarm/keypad/cameras
          - /valarm/keypad/cellular_devices
          - /valarm/keypad/configurations
          - /valarm/keypad/device/event/list
          - /valarm/keypad/devices/access_devices
          - /valarm/keypad/devices/cameras
          - /valarm/keypad/devices/environmental_sensors
          - /valarm/keypad/devices/hub_groups
          - /valarm/keypad/devices/speakers
          - /valarm/keypad/doors
          - /valarm/keypad/environmental_sensors
          - /valarm/keypad/event/submit
          - /valarm/keypad/get_server_connectivity_status/[0-9a-f-]{36}
          - /valarm/keypad/keycodes
          - /valarm/keypad/list
          - /valarm/keypad/server_connectivity_status
          - /valarm/keypad/submit_offline_event
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/[0-9]+\.jpeg
          - /valarm/keypad/thumbnail/download/[0-9a-f-]{36}/latest\.jpeg
          - /valarm/keypad/thumbnail/upload
          - /valarm/keypad/tts/generate
          - /valarm/keypad/update_device_info
          - /valarm/keypad/users
          - /valarm/keypad/v2/device/event/list
          - /valarm/keypad/video/download/playlist\.m3u8
          - /valarm/keypad/video/download/video\.ts
          - /valarm/keypad/video/upload
          - /valarm/keypad/zone/details
          - /valarm/keypad/zone/details/list
          - /valarm/keypad/zone/get_zone_associations
          - /valarm/keypad/zone/list
          - /valarm/keypad/zone/set_associations
          - /valarm/keypad/zone/update_configs
          - /valarm/keypad/zones
          - /valarm/reporting/event_types
          - /valarm/webrtc/get_ice_servers
          - /valarm/zone/arm
          - /valarm/zone/disarm
        unauthenticatedEndpoints:
          - /valarm/ping
          - /valarm/webrtc/get_ice_servers_talkdown
          - /valarm/websocket/submit_webrtc_offer
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-valarm
    namespace: vinfra
    resourceVersion: "2417982130"
    uid: 0fa549ef-b8fa-44d3-9b8a-01901615bf2c
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vallegion.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /client/doors/[0-9a-f-]{36}/relations
          - /client/doors/[0-9a-f-]{36}/status
        unauthenticatedEndpoints:
          - /engage/certificates
          - /engage/newCA/current
          - /engage/newCredentials
          - /engage/wss
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vallegion
    namespace: vinfra
    resourceVersion: "2158702153"
    uid: c99e7584-bfa6-46e5-8b62-4119a3333da4
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vannounce.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /v1/alerts
          - /v1/alerts/[0-9a-f-]{36}/acknowledge
          - /v1/alerts/extended
        unauthenticatedEndpoints:
          - /ping
          - /v1/vsuite/[0-9a-f-]{36}/alerts
          - /v1/vsuite/alert/[0-9a-f-]{36}/edit
          - /v1/vsuite/alert/[0-9a-f-]{36}/resolve
          - /v1/vsuite/alert/create
          - /v1/vsuite/alert/templates
          - /v1/vsuite/alert/templates/[\w\.\-]+/i18n
      - host: vannounce.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /v1/cross_shard/[0-9a-f-]{36}/alerts
          - /v1/cross_shard/alert/[0-9a-f-]{36}/edit
          - /v1/cross_shard/alert/[0-9a-f-]{36}/resolve
          - /v1/cross_shard/alert/create
          - /v1/cross_shard/alert/templates
          - /v1/cross_shard/alert/templates/[\w\.\-]+/i18n
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vannounce
    namespace: vinfra
    resourceVersion: "2158702205"
    uid: f7f02018-0ed8-4ce2-8ae8-cb69b0b4bf3d
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /app/init
          - /app/init/floorplans
          - /app/v2/init
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /app/init
          - /app/init/floorplans
          - /app/v2/init
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /app/init
          - /app/init/floorplans
          - /app/v2/init
      - host: vappinit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /app/init
          - /app/init/floorplans
          - /app/v2/init
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vappinit
    namespace: vinfra
    resourceVersion: "2417982126"
    uid: 4b091d53-dfdc-4fdf-90b2-e725968765ad
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vapplewallet.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
      - host: vcerberus.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /applewallet/prepareProvisioning
          - /applewallet/provisioningStatus
      - host: access.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /applewallet/prepareProvisioning
          - /applewallet/provisioningStatus
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vapplewallet
    namespace: vinfra
    resourceVersion: "2158702200"
    uid: 09bbe301-74b9-4e9c-9524-288faff88126
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vassa.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /client/daemons
          - /client/doors/[0-9a-f-]{36}/lock
          - /client/doors/[0-9a-f-]{36}/reload
          - /client/doors/[0-9a-f-]{36}/unlock
          - /client/dsrs
          - /client/dsrs/[0-9a-f-]{36}
          - /client/dsrs/[0-9a-f-]{36}/accessPoints
          - /client/dsrs/[0-9a-f-]{36}/accessPoints/unregister
          - /client/dsrs/[0-9a-f-]{36}/clear
          - /client/dsrs/[0-9a-f-]{36}/decommission
          - /client/dsrs/[0-9a-f-]{36}/recommission
          - /client/users/[0-9a-f-]{36}/extended
          - /dsr/callback
          - /dsr/daemon/update
          - /dsr/wss
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vassa
    namespace: vinfra
    resourceVersion: "2158702197"
    uid: ba8284e9-9855-47ea-b505-d67e330435a7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /auth/access_token
          - /device/auth/enroll
          - /device/auth/token
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /auth/access_token
          - /device/auth/enroll
          - /device/auth/token
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /auth/access_token
          - /device/auth/enroll
          - /device/auth/token
      - host: vauth.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/organizations/[0-9a-f-]{36}/entities/[0-9a-f-]{36}/grants
          - /admin/organizations/[0-9a-f-]{36}/security_entities/[0-9a-f-]{36}/flattened_permissions
          - /admin/organizations/[0-9a-f-]{36}/security_entities/[0-9a-f-]{36}/site_roles
          - /auth/access_token
          - /auth/active_tokens
          - /auth/any_org_or_site_admin_assert
          - /auth/assert
          - /auth/assert/any
          - /auth/assert_by_id
          - /auth/assert_org_and_site_admin_for_camera
          - /auth/become
          - /auth/become_status
          - /auth/check
          - /auth/check_by_grantee_ids
          - /auth/email/change
          - /auth/force_logout
          - /auth/get_active_accounts
          - /auth/init
          - /auth/invalidate_tokens
          - /auth/linked_accounts
          - /auth/login
          - /auth/logout
          - /auth/magic
          - /auth/org/[0-9a-f-]{36}/twofactor/allowedmethods
          - /auth/org/force_logout_all
          - /auth/org/lockout/[0-9a-f-]{36}
          - /auth/org/passwd/reset
          - /auth/org/twofactor
          - /auth/org/twofactor/allowedmethods
          - /auth/org/twofactor/reset
          - /auth/org_properties/[0-9a-f-]{36}
          - /auth/org_settings
          - /auth/passkey/verify
          - /auth/passwd
          - /auth/reset
          - /auth/reset/redeem
          - /auth/revoke_token
          - /auth/set_org_session_timeout
          - /auth/toggle_become
          - /auth/token_log
          - /auth/tokens/my
          - /auth/twofactor/backup
          - /auth/twofactor/new_backup
          - /auth/twofactor/passkey/disable
          - /auth/twofactor/qr/disable
          - /auth/twofactor/qr/setup
          - /auth/twofactor/qr/verify
          - /auth/twofactor/sms/disable
          - /auth/twofactor/sms/new
          - /auth/twofactor/sms/setup
          - /auth/twofactor/sms/verify
          - /auth/twofactor/status
          - /auth/twofactor/usePasskeyAs2fa
          - /auth/twofactor/webauthn/authenticate
          - /auth/twofactor/webauthn/disable
          - /auth/twofactor/webauthn/setup
          - /auth/twofactor/webauthn/verify
          - /auth/twofactor_enforced/qr/verify
          - /auth/twofactor_enforced/reset/passkey
          - /auth/twofactor_enforced/reset/qr
          - /auth/twofactor_enforced/reset/sms
          - /auth/twofactor_enforced/reset/usePasskeyAs2fa
          - /auth/twofactor_enforced/reset/webauthn
          - /auth/twofactor_enforced/sms/verify
          - /auth/twofactor_enforced/webauthn/verify
          - /bearer/generate
          - /bearer/list
          - /bearer/revoke
          - /device/auth/enroll
          - /device/auth/token
          - /directory/delete
          - /directory/parents
          - /embed/create
          - /embed/html/[0-9a-f-]{36}/
          - /embed/html/[0-9a-f-]{36}/allowlist
          - /embed/list
          - /embed/list_by_org
          - /embed/revoke
          - /internal/auth/force_logout
          - /internal/org/[0-9a-f-]{36}/update_role_grants_to_custom_roles
          - /live_link/create
          - /live_link/edit
          - /live_link/get
          - /live_link/get_expiration
          - /live_link/list
          - /live_link/redeem
          - /live_link/revoke
          - /magic_link/create
          - /magic_link/redeem
          - /org/[0-9a-f-]{36}/authed_entities_under_parent
          - /org/[0-9a-f-]{36}/custom_roles
          - /org/[0-9a-f-]{36}/custom_roles/enable
          - /org/[0-9a-f-]{36}/custom_roles/get_state
          - /org/[0-9a-f-]{36}/directory_entities
          - /org/[0-9a-f-]{36}/flattened_permissions
          - /org/[0-9a-f-]{36}/users/export
          - /organizations/[0-9a-f-]{36}/grants
          - /organizations/[0-9a-f-]{36}/roles
          - /permissions/for_grantee
          - /permissions/get_permissible_entities
          - /permissions/grant
          - /permissions/list
          - /permissions/list_admin_sites
          - /permissions/list_admins
          - /permissions/modify
          - /permissions/my
          - /permissions/require_real
          - /permissions/revoke
          - /ping
          - /roles/all
          - /roles/default/permissions
          - /saml/access_token
          - /saml/login/[0-9a-zA-Z._-]{1,64}
          - /saml/provider/[0-9a-f-]{36}
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}/edit
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}/upload
          - /saml/provider/[0-9a-f-]{36}/create
          - /saml/provider/[0-9a-f-]{36}/edit
          - /saml/provider/[0-9a-f-]{36}/provider_name
          - /saml/provider/[0-9a-f-]{36}/upload
          - /saml/providers
          - /saml/providers/[0-9a-f-]{36}
          - /saml/sso/[0-9a-zA-Z._-]{1,64}
          - /security_entities/create
          - /security_entities/list
          - /security_entity_group/create
          - /security_entity_group/delete
          - /security_entity_group/edit
          - /security_entity_group/get
          - /security_entity_group/list
          - /security_entity_group/members/add
          - /security_entity_group/members/list
          - /security_entity_group/members/remove
          - /security_entity_group/set_permissions
          - /support_full_access_expiration
          - /unlock_link/[0-9a-f-]{36}/exchange
          - /unlock_link/info
          - /user/auth_info
          - /user/grants
          - /user/org_ids
          - /user/security_entity_groups/list
          - /virtual_entity/auth/assert
        unauthenticatedEndpoints:
          - /auth/session_accounts
          - /auth/tokeninfo
          - /auth/twofactor_enforced/passkey/verify
      - host: saml.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/organizations/[0-9a-f-]{36}/entities/[0-9a-f-]{36}/grants
          - /admin/organizations/[0-9a-f-]{36}/security_entities/[0-9a-f-]{36}/flattened_permissions
          - /admin/organizations/[0-9a-f-]{36}/security_entities/[0-9a-f-]{36}/site_roles
          - /auth/access_token
          - /auth/active_tokens
          - /auth/any_org_or_site_admin_assert
          - /auth/assert
          - /auth/assert/any
          - /auth/assert_by_id
          - /auth/assert_org_and_site_admin_for_camera
          - /auth/become
          - /auth/become_status
          - /auth/check
          - /auth/check_by_grantee_ids
          - /auth/email/change
          - /auth/force_logout
          - /auth/get_active_accounts
          - /auth/init
          - /auth/invalidate_tokens
          - /auth/linked_accounts
          - /auth/login
          - /auth/logout
          - /auth/magic
          - /auth/org/[0-9a-f-]{36}/twofactor/allowedmethods
          - /auth/org/force_logout_all
          - /auth/org/lockout/[0-9a-f-]{36}
          - /auth/org/passwd/reset
          - /auth/org/twofactor
          - /auth/org/twofactor/allowedmethods
          - /auth/org/twofactor/reset
          - /auth/org_properties/[0-9a-f-]{36}
          - /auth/org_settings
          - /auth/passkey/verify
          - /auth/passwd
          - /auth/reset
          - /auth/reset/redeem
          - /auth/revoke_token
          - /auth/set_org_session_timeout
          - /auth/toggle_become
          - /auth/token_log
          - /auth/tokens/my
          - /auth/twofactor/backup
          - /auth/twofactor/new_backup
          - /auth/twofactor/passkey/disable
          - /auth/twofactor/qr/disable
          - /auth/twofactor/qr/setup
          - /auth/twofactor/qr/verify
          - /auth/twofactor/sms/disable
          - /auth/twofactor/sms/new
          - /auth/twofactor/sms/setup
          - /auth/twofactor/sms/verify
          - /auth/twofactor/status
          - /auth/twofactor/usePasskeyAs2fa
          - /auth/twofactor/webauthn/authenticate
          - /auth/twofactor/webauthn/disable
          - /auth/twofactor/webauthn/setup
          - /auth/twofactor/webauthn/verify
          - /auth/twofactor_enforced/qr/verify
          - /auth/twofactor_enforced/reset/passkey
          - /auth/twofactor_enforced/reset/qr
          - /auth/twofactor_enforced/reset/sms
          - /auth/twofactor_enforced/reset/usePasskeyAs2fa
          - /auth/twofactor_enforced/reset/webauthn
          - /auth/twofactor_enforced/sms/verify
          - /auth/twofactor_enforced/webauthn/verify
          - /bearer/generate
          - /bearer/list
          - /bearer/revoke
          - /device/auth/enroll
          - /device/auth/token
          - /directory/delete
          - /directory/parents
          - /embed/create
          - /embed/html/[0-9a-f-]{36}/
          - /embed/html/[0-9a-f-]{36}/allowlist
          - /embed/list
          - /embed/list_by_org
          - /embed/revoke
          - /internal/auth/force_logout
          - /internal/org/[0-9a-f-]{36}/update_role_grants_to_custom_roles
          - /live_link/create
          - /live_link/edit
          - /live_link/get
          - /live_link/get_expiration
          - /live_link/list
          - /live_link/redeem
          - /live_link/revoke
          - /magic_link/create
          - /magic_link/redeem
          - /org/[0-9a-f-]{36}/authed_entities_under_parent
          - /org/[0-9a-f-]{36}/custom_roles
          - /org/[0-9a-f-]{36}/custom_roles/enable
          - /org/[0-9a-f-]{36}/custom_roles/get_state
          - /org/[0-9a-f-]{36}/directory_entities
          - /org/[0-9a-f-]{36}/flattened_permissions
          - /org/[0-9a-f-]{36}/users/export
          - /organizations/[0-9a-f-]{36}/grants
          - /organizations/[0-9a-f-]{36}/roles
          - /permissions/for_grantee
          - /permissions/get_permissible_entities
          - /permissions/grant
          - /permissions/list
          - /permissions/list_admin_sites
          - /permissions/list_admins
          - /permissions/modify
          - /permissions/my
          - /permissions/require_real
          - /permissions/revoke
          - /ping
          - /roles/all
          - /roles/default/permissions
          - /saml/access_token
          - /saml/login/[0-9a-zA-Z._-]{1,64}
          - /saml/provider/[0-9a-f-]{36}
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}/edit
          - /saml/provider/[0-9a-f-]{36}/[0-9a-zA-Z._-]{1,64}/upload
          - /saml/provider/[0-9a-f-]{36}/create
          - /saml/provider/[0-9a-f-]{36}/edit
          - /saml/provider/[0-9a-f-]{36}/provider_name
          - /saml/provider/[0-9a-f-]{36}/upload
          - /saml/providers
          - /saml/providers/[0-9a-f-]{36}
          - /saml/sso/[0-9a-zA-Z._-]{1,64}
          - /security_entities/create
          - /security_entities/list
          - /security_entity_group/create
          - /security_entity_group/delete
          - /security_entity_group/edit
          - /security_entity_group/get
          - /security_entity_group/list
          - /security_entity_group/members/add
          - /security_entity_group/members/list
          - /security_entity_group/members/remove
          - /security_entity_group/set_permissions
          - /support_full_access_expiration
          - /unlock_link/[0-9a-f-]{36}/exchange
          - /unlock_link/info
          - /user/auth_info
          - /user/grants
          - /user/org_ids
          - /user/security_entity_groups/list
          - /virtual_entity/auth/assert
        unauthenticatedEndpoints:
          - /auth/session_accounts
          - /auth/tokeninfo
          - /auth/twofactor_enforced/passkey/verify
      - host: vauth.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /auth/passkey_login
          - /internal/auth/cross_org/token
          - /internal/command_session
          - /internal/permissions/modify
          - /internal/security_entities/create
        unauthenticatedEndpoints:
          - /auth/tokeninfo
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vauth
    namespace: vinfra
    resourceVersion: "2417982162"
    uid: 1f53d8a5-3abd-43fb-902d-d514a9ce043b
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/backup/failure
          - /submit/backup/index
          - /submit/backup/upload_info
        unauthenticatedEndpoints:
          - /submit/backup/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /submit/backup_segments/[0-9a-f-]{36}/latest
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/backup/failure
          - /submit/backup/index
          - /submit/backup/upload_info
        unauthenticatedEndpoints:
          - /submit/backup/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /submit/backup_segments/[0-9a-f-]{36}/latest
      - host: vbackup.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /batch/backup_config/get
          - /batch/backup_config/set
          - /batch/backup_pct_done/get
          - /batch/latest_backup_ts/get
          - /batch/oldest_backup_ts/get
          - /config/org/v1/[0-9a-f-]{36}/ecb_license_states
          - /config/v1/[0-9a-f-]{36}/backup_resolution
          - /config/v1/[0-9a-f-]{36}/backup_schedule
          - /config/v1/[0-9a-f-]{36}/backup_status
          - /config/v1/[0-9a-f-]{36}/latest_backup_ts
          - /config/v1/[0-9a-f-]{36}/oldest_backup_ts
          - /config/v1/[0-9a-f-]{36}/upload_schedule
          - /internal/[0-9a-f-]{36}/backup_all_info
          - /internal/[0-9a-f-]{36}/backup_resolution
          - /internal/[0-9a-f-]{36}/backup_schedule
          - /internal/[0-9a-f-]{36}/backup_status
          - /internal/[0-9a-f-]{36}/backup_up_to_date
          - /internal/[0-9a-f-]{36}/retention
          - /internal/[0-9a-f-]{36}/upload_schedule
          - /internal/batch/backup_config/get
          - /internal/batch/backup_config/set
        unauthenticatedEndpoints:
          - /internal/org/[0-9a-f-]{36}/ecb_info
          - /internal/supertest/backup_available
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vbackup
    namespace: vinfra
    resourceVersion: "2459366577"
    uid: e995dbe6-49fd-43eb-a40a-0158715d55e2
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbroadcast/command/create_media_task
          - /vbroadcast/command/delete_media_task
          - /vbroadcast/command/device/media_on_event
          - /vbroadcast/command/device/set_microphone_sensitivity
          - /vbroadcast/command/device/set_speaker_volume
          - /vbroadcast/command/get_media_task
          - /vbroadcast/command/site/media_on_event
          - /vbroadcast/command/tts/submit
          - /vbroadcast/command/update_media_task_status
          - /vbroadcast/command/upload_media_file
          - /vbroadcast/device/get_media_file
          - /vbroadcast/device/media/add_media_alert
          - /vbroadcast/device/media_file/[0-9a-f-]{36}
          - /vbroadcast/device/poll_events
          - /vbroadcast/device/speaker/device_info
          - /vbroadcast/device/submit/af_at_status
          - /vbroadcast/device/submit/call_event
          - /vbroadcast/device/test/websocket_response
          - /vbroadcast/device/tts_file/[0-9a-f-]{36}
          - /vbroadcast/device/upload/presigned_url
          - /vbroadcast/device/webrtc/get_ice_servers
          - /vbroadcast/management/speaker/batch/lookup
          - /vbroadcast/management/speaker/commission
          - /vbroadcast/management/speaker/commission/unassigned/batch
          - /vbroadcast/management/speaker/decommission
          - /vbroadcast/management/speaker/disassociate_camera
          - /vbroadcast/management/speaker/list
          - /vbroadcast/management/speaker/setup/batch
          - /vbroadcast/management/speaker/unassigned/list
          - /vbroadcast/websocket/submit_webrtc_offer
        unauthenticatedEndpoints:
          - /vbroadcast/ping
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbroadcast/command/create_media_task
          - /vbroadcast/command/delete_media_task
          - /vbroadcast/command/device/media_on_event
          - /vbroadcast/command/device/set_microphone_sensitivity
          - /vbroadcast/command/device/set_speaker_volume
          - /vbroadcast/command/get_media_task
          - /vbroadcast/command/site/media_on_event
          - /vbroadcast/command/tts/submit
          - /vbroadcast/command/update_media_task_status
          - /vbroadcast/command/upload_media_file
          - /vbroadcast/device/get_media_file
          - /vbroadcast/device/media/add_media_alert
          - /vbroadcast/device/media_file/[0-9a-f-]{36}
          - /vbroadcast/device/poll_events
          - /vbroadcast/device/speaker/device_info
          - /vbroadcast/device/submit/af_at_status
          - /vbroadcast/device/submit/call_event
          - /vbroadcast/device/test/websocket_response
          - /vbroadcast/device/tts_file/[0-9a-f-]{36}
          - /vbroadcast/device/upload/presigned_url
          - /vbroadcast/device/webrtc/get_ice_servers
          - /vbroadcast/management/speaker/batch/lookup
          - /vbroadcast/management/speaker/commission
          - /vbroadcast/management/speaker/commission/unassigned/batch
          - /vbroadcast/management/speaker/decommission
          - /vbroadcast/management/speaker/disassociate_camera
          - /vbroadcast/management/speaker/list
          - /vbroadcast/management/speaker/setup/batch
          - /vbroadcast/management/speaker/unassigned/list
          - /vbroadcast/websocket/submit_webrtc_offer
        unauthenticatedEndpoints:
          - /vbroadcast/ping
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbroadcast/command/create_media_task
          - /vbroadcast/command/delete_media_task
          - /vbroadcast/command/device/media_on_event
          - /vbroadcast/command/device/set_microphone_sensitivity
          - /vbroadcast/command/device/set_speaker_volume
          - /vbroadcast/command/get_media_task
          - /vbroadcast/command/site/media_on_event
          - /vbroadcast/command/tts/submit
          - /vbroadcast/command/update_media_task_status
          - /vbroadcast/command/upload_media_file
          - /vbroadcast/device/get_media_file
          - /vbroadcast/device/media/add_media_alert
          - /vbroadcast/device/media_file/[0-9a-f-]{36}
          - /vbroadcast/device/poll_events
          - /vbroadcast/device/speaker/device_info
          - /vbroadcast/device/submit/af_at_status
          - /vbroadcast/device/submit/call_event
          - /vbroadcast/device/test/websocket_response
          - /vbroadcast/device/tts_file/[0-9a-f-]{36}
          - /vbroadcast/device/upload/presigned_url
          - /vbroadcast/device/webrtc/get_ice_servers
          - /vbroadcast/management/speaker/batch/lookup
          - /vbroadcast/management/speaker/commission
          - /vbroadcast/management/speaker/commission/unassigned/batch
          - /vbroadcast/management/speaker/decommission
          - /vbroadcast/management/speaker/disassociate_camera
          - /vbroadcast/management/speaker/list
          - /vbroadcast/management/speaker/setup/batch
          - /vbroadcast/management/speaker/unassigned/list
          - /vbroadcast/websocket/submit_webrtc_offer
        unauthenticatedEndpoints:
          - /vbroadcast/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vbroadcast
    namespace: vinfra
    resourceVersion: "2417982165"
    uid: 1d6438b6-5dd3-4702-89fe-0e71d29f6407
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbugreport/create_issue
          - /vbugreport/get_teams
          - /vbugreport/linear/create_issue
          - /vbugreport/linear/get_teams
          - /vbugreport/linear/upload_file
          - /vbugreport/upload_file
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbugreport/create_issue
          - /vbugreport/get_teams
          - /vbugreport/linear/create_issue
          - /vbugreport/linear/get_teams
          - /vbugreport/linear/upload_file
          - /vbugreport/upload_file
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vbugreport/create_issue
          - /vbugreport/get_teams
          - /vbugreport/linear/create_issue
          - /vbugreport/linear/get_teams
          - /vbugreport/linear/upload_file
          - /vbugreport/upload_file
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vbugreport
    namespace: vinfra
    resourceVersion: "2417982182"
    uid: 7c7b2005-2c5d-438e-b2a3-5fb4b42d9de4
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/media_key/decrypt
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/media_key/decrypt
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/media_key/decrypt
      - host: vcameramgmt.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/has_id
          - /camera/media_key/decrypt
          - /camera/name/get
          - /camera/settings/led/get
          - /camera/settings/led/set
          - /camera/settings/retention/get
          - /camera/settings/retention/set
          - /camera/settings/rtsp/batch_get
          - /camera/settings/rtsp/batch_set
          - /camera/settings/rtsp/get
          - /camera/settings/rtsp/set
          - /get_cameras_by_org_id
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vcameramgmt
    namespace: vinfra
    resourceVersion: "2417982167"
    uid: 32a3aed5-8a28-426a-8500-82408105f856
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vcamerastats.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/incompatibility/users
          - /streaming/incompatibility/add
          - /streaming/stats/add
        unauthenticatedEndpoints:
          - /camera/streamstats/get
          - /org/streaming/metrics
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vcamerastats
    namespace: vinfra
    resourceVersion: "2158702201"
    uid: 6f435cdb-0e50-4f15-a878-9e3274103f9e
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/latest
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/latest
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vcamsegs
    namespace: vinfra
    resourceVersion: "2158702202"
    uid: 25be97dc-2971-41b2-bc92-3b000f99cb2f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vcellular.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /cellular_device/commission
          - /cellular_device/commission/unassigned/batch
          - /cellular_device/decommission
          - /cellular_device/list
          - /cellular_device/register_imei
          - /cellular_device/setup/batch
          - /cellular_device/unassigned/list
          - /cellular_device/update
          - /event
          - /event/list
          - /event/submit_pings
          - /internal/admin/cellular_device/decommission
          - /vcellular/ping
        unauthenticatedEndpoints:
          - /event/list/status
          - /ping
          - /vcellular/ping
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcellular/event
          - /vcellular/event/list
          - /vcellular/event/submit_pings
          - /vcellular/ping
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcellular/event
          - /vcellular/event/list
          - /vcellular/event/submit_pings
          - /vcellular/ping
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcellular/event
          - /vcellular/event/list
          - /vcellular/event/submit_pings
          - /vcellular/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vcellular
    namespace: vinfra
    resourceVersion: "2417982136"
    uid: 982e0a34-239f-4972-9b06-50a35fb34a95
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/status/update
          - /access_controller/update
          - /access_device/[0-9a-f-]{36}/config
          - /door/config/get
          - /door/event/send
          - /submit_current_time
        unauthenticatedEndpoints:
          - /access_controller/auth/init
          - /model/[\w\-. ]+/firmware_version/[\w\-. +%]+
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/status/update
          - /access_controller/update
          - /access_device/[0-9a-f-]{36}/config
          - /door/config/get
          - /door/event/send
          - /submit_current_time
        unauthenticatedEndpoints:
          - /access_controller/auth/init
          - /model/[\w\-. ]+/firmware_version/[\w\-. +%]+
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/status/update
          - /access_controller/update
          - /access_device/[0-9a-f-]{36}/config
          - /door/config/get
          - /door/event/send
          - /submit_current_time
        unauthenticatedEndpoints:
          - /access_controller/auth/init
          - /model/[\w\-. ]+/firmware_version/[\w\-. +%]+
      - host: vcerberus.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[0-9a-f-]{36}/alert_subscription
          - /[0-9a-f-]{36}/alert_subscriptions
          - /[0-9a-f-]{36}/config
          - /[0-9a-f-]{36}/keys
          - /[0-9a-f-]{36}/keys/[0-9a-f-]{36}
          - /access/v2/device/access_config/1
          - /access/v2/device/access_config/2
          - /access/v2/device/access_config/3
          - /access/v2/device/access_controller/config/get
          - /access/v2/device/access_controller/config_status/set
          - /access/v2/device/access_device/peripheral/metadata
          - /access/v2/device/config/1
          - /access/v2/device/config/2
          - /access/v2/device/device_information
          - /access/v2/device/device_io/[0-9a-f-]{36}/metadata
          - /access/v2/device/device_io/[0-9a-f-]{36}/tamper
          - /access/v2/device/door/[0-9a-f-]{36}/unlock
          - /access/v2/device/event/2
          - /access/v2/device/schedule_config/1
          - /access/v2/device/verkada_nfc/desfire_key
          - /access/v2/device/verkada_nfc/desfire_key/2
          - /access/v2/device/verkada_nfc/master_key
          - /access/v2/user/access_controller/[0-9a-f-]{36}/config_status/get
          - /access/v2/user/access_controller/[0-9a-f-]{36}/mode
          - /access/v2/user/access_controller/[0-9a-f-]{36}/reader_peripherals/status
          - /access/v2/user/access_controller/assign_hub
          - /access/v2/user/access_controller/reader_peripherals/statuses
          - /access/v2/user/access_controller/switch_mode
          - /access/v2/user/access_controllers
          - /access/v2/user/access_device/[0-9a-f-]{36}/manual_behavior
          - /access/v2/user/access_device/[0-9a-f-]{36}/manual_behavior/[0-9a-f-]{36}
          - /access/v2/user/access_device/[0-9a-f-]{36}/reboot
          - /access/v2/user/access_device/commission_unassigned_bulk
          - /access/v2/user/access_device/setup
          - /access/v2/user/allegion_engage/site/[0-9a-f-]{36}/sync
          - /access/v2/user/areas
          - /access/v2/user/areas/[0-9a-f-]{36}
          - /access/v2/user/aux_inputs
          - /access/v2/user/aux_output/[0-9a-f-]{36}
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario/[0-9a-f-]{36}
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario/[0-9a-f-]{36}/dismiss
          - /access/v2/user/aux_output/[0-9a-f-]{36}/dismiss
          - /access/v2/user/aux_output/[0-9a-f-]{36}/peer_devices
          - /access/v2/user/aux_output/status
          - /access/v2/user/aux_outputs
          - /access/v2/user/credentials/export_csv
          - /access/v2/user/credentials/import_csv
          - /access/v2/user/demo
          - /access/v2/user/door/[0-9a-f-]{36}/privacy_groups
          - /access/v2/user/door/[0-9a-f-]{36}/verify_site
          - /access/v2/user/doors
          - /access/v2/user/elevator
          - /access/v2/user/elevator/[0-9a-f-]{36}
          - /access/v2/user/elevator/[0-9a-f-]{36}/nearby_cameras
          - /access/v2/user/elevators
          - /access/v2/user/license_plate
          - /access/v2/user/license_plate/[\w\.\-]+
          - /access/v2/user/license_plate/delete
          - /access/v2/user/live_links
          - /access/v2/user/live_links/[0-9a-f-]{36}
          - /access/v2/user/lockdowns
          - /access/v2/user/lockdowns/[0-9a-f-]{36}
          - /access/v2/user/mfa_code
          - /access/v2/user/mfa_code/delete
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controller/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controller/[0-9a-f-]{36}/reader_peripheral/delete
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controllers
          - /access/v2/user/organization/[0-9a-f-]{36}/auto_expire_exempt_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/badge_template
          - /access/v2/user/organization/[0-9a-f-]{36}/badge_template/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/bulk_set_auto_expire_exempt_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/entity_events/[0-9a-f-]{36}/possible_cards
          - /access/v2/user/organization/[0-9a-f-]{36}/images
          - /access/v2/user/organization/[0-9a-f-]{36}/images/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/images/[0-9a-f-]{36}\.png
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/preview
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/csv
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/end
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/event
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/event/latest
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report/[0-9a-f-]{36}/send
          - /access/v2/user/organization/[0-9a-f-]{36}/user_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/users/stats/group_member_count
          - /access/v2/user/organization/door_access_report
          - /access/v2/user/organization/door_access_report/export
          - /access/v2/user/organization/mobile_nfc
          - /access/v2/user/pass/android_nfc
          - /access/v2/user/pass/unlockables/1
          - /access/v2/user/pass_app_issue
          - /access/v2/user/roles
          - /access/v2/user/roles/modify
          - /access/v2/user/schedules
          - /access/v2/user/schedules/[0-9a-f-]{36}
          - /access/v2/user/users/[0-9a-f-]{36}/mfa_codes
          - /access/v2/user/users/bulk
          - /access/v2/user/users/invite_guest
          - /access/v2/user/users/search
          - /access/v2/user/virtual_device/[0-9a-f-]{36}/toggle
          - /access/v2/user/virtual_device/[0-9a-f-]{36}/unlock
          - /access/v2/user/visit_types
          - /access/v2/user/visit_types/[0-9a-f-]{36}
          - /access/v2/user/visitor/credentials/delete
          - /access/v2/user/visits
          - /access/v2/user/visits/[0-9a-f-]{36}
          - /access/v2/user/visits/count
          - /access/v2/user/wireless_hub/bulk_assign_wireless_locks
          - /access/v2/user/wireless_hub/remove_connections
          - /access/v2/user/wireless_hubs
          - /access/v2/user/wireless_lock/remove_connections
          - /access/v2/user/wireless_locks
          - /access/v2/users/organization/events/time
          - /access_controller/[0-9a-f-]{36}/aux_input
          - /access_controller/[0-9a-f-]{36}/aux_output
          - /access_controller/[0-9a-f-]{36}/manual_behavior/[0-9a-f-]{36}/device_io
          - /access_controller/aux_was_pressed
          - /access_controller/ble_stat/update
          - /access_controller/config/get
          - /access_controller/config/set
          - /access_controller/edit
          - /access_controller/event/history
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/health/update
          - /access_controller/identify
          - /access_controller/move_to_site
          - /access_controller/p2p_stat/update
          - /access_controller/reader_peripheral
          - /access_controller/reader_peripheral/clear
          - /access_controller/reader_stat/update
          - /access_controller/reboot
          - /access_controller/status
          - /access_controller/status/update
          - /access_controller/update
          - /access_controller/version
          - /access_controller/wireless_lock_stat/update
          - /access_device/[0-9a-f-]{36}/config
          - /access_device/[0-9a-f-]{36}/event
          - /access_device/commission
          - /access_device/decommission
          - /access_methods/get
          - /access_methods/modify
          - /action/[0-9a-f-]{36}
          - /alert_subscription/[0-9a-f-]{36}
          - /auth/assert
          - /auth/assert/permissions
          - /aux_input/[0-9a-f-]{36}
          - /aux_input/[0-9a-f-]{36}/action
          - /aux_input/[0-9a-f-]{36}/device_io
          - /aux_input/[0-9a-f-]{36}/lockdown_peer_devices
          - /aux_input/[0-9a-f-]{36}/peer_devices
          - /aux_input/set_nearby_cameras
          - /aux_output/[0-9a-f-]{36}
          - /debug-endpoint-for-error-capture-testing
          - /device_io/[0-9a-f-]{36}
          - /door/[0-9a-f-]{36}/device_io
          - /door/[0-9a-f-]{36}/display_image/[\w\-. +%]+
          - /door/[0-9a-f-]{36}/display_image/[\w\-. +%]+/image\.jpg
          - /door/[0-9a-f-]{36}/display_image/image\.jpg
          - /door/[0-9a-f-]{36}/metrics
          - /door/access_credentials
          - /door/config/get
          - /door/config/set
          - /door/convert
          - /door/create
          - /door/delete
          - /door/direct-permissions/list
          - /door/event/
          - /door/event/history
          - /door/event/latest
          - /door/event/send
          - /door/event/status
          - /door/move
          - /door/set_door_state
          - /door/set_metadata
          - /door/set_nearby_cameras
          - /door/stats
          - /door/unlock
          - /door/unlock/modify
          - /door/unlockable/list
          - /door/user_groups/bulk_grant_access
          - /door/user_groups/bulk_revoke_access
          - /door/user_groups/grant_access
          - /door/user_groups/list
          - /door/user_groups/revoke_access
          - /door/users/list
          - /elevator/[0-9a-f-]{36}/device_io
          - /get_entities
          - /get_users
          - /organization/config/get
          - /organization/config/set
          - /organizations/[0-9a-f-]{36}/lockdowns
          - /organizations/[0-9a-f-]{36}/lockdowns/release
          - /organizations/[0-9a-f-]{36}/lockdowns/trigger
          - /organizations/[0-9a-f-]{36}/schedules
          - /organizations/[0-9a-f-]{36}/schedules/[0-9a-f-]{36}
          - /pass-app/metrics
          - /submit_current_time
          - /swordfish/access/v2/user/allegion_engage/site
          - /swordfish/access/v2/user/allegion_engage/site/[0-9a-f-]{36}/invite
          - /swordfish/access/v2/user/allegion_engage/site/[0-9a-f-]{36}/sync
          - /user/[0-9a-f-]{36}
          - /user/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /user/access_card/activation_state
          - /user/access_card/active
          - /user/access_card/add
          - /user/access_card/delete
          - /user/access_card/get
          - /user/access_card/scan
          - /user/access_controller/[0-9a-f-]{36}/reader_peripheral/[A-Z0-9-]{14}
          - /user/code/delete
          - /user/code/set
          - /user/door/config/get
          - /user/email
          - /user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /user/photos/upload
          - /user/roles
          - /user_groups/add_group
          - /user_groups/add_user
          - /user_groups/bulk_add_users
          - /user_groups/bulk_remove_users
          - /user_groups/doors/list
          - /user_groups/get
          - /user_groups/get_group_membership
          - /user_groups/remove_group
          - /user_groups/remove_user
          - /user_groups/scim_groups
          - /user_groups/update_group_name
          - /user_roles/modify
          - /users/async_upload_csv
          - /users/async_upload_csv/status/
          - /users/create
          - /users/delete
          - /users/export_csv
          - /users/get_csv_template
          - /users/upload_csv
          - /users/upload_csv/pre_validate
          - /v1/device/information
        unauthenticatedEndpoints:
          - /\.well-known/apple-app-site-association
          - /access/v2/unlock/[0-9a-f-]{36}
          - /access/v2/user/linked_accounts
          - /access/v2/user/session_accounts
          - /access/v2/user/unlock_link/[0-9a-f-]{36}/exchange
          - /access/v2/webhook/ironclad/apple_wallet_notify
          - /access_card/qr_code\.jpg
          - /access_controller/auth/init
          - /internal/door/event/send
          - /internal/users/async_upload_csv/process_chunk
          - /internal/users/async_upload_csv/status/
          - /internal/users/async_upload_csv/status/[0-9a-f-]{36}
          - /internal/users/async_upload_csv/status/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /logs/relay-vaccess-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/4505653327888384/store/
          - /logs/relay-vaccess-sentry/api/5549229/store/
          - /model/[\w\-. ]+/firmware_version/[a-zA-Z0-9-:_.]+
          - /pass-app/magic-link
          - /ping
          - /swordfish/lock/Config
          - /swordfish/lock/alert
          - /swordfish/lock/audit
          - /swordfish/lock/certificates/current
          - /swordfish/lock/db/[0-9]+
          - /swordfish/lock/newCA
          - /swordfish/ping
          - /verkada-access-firmware\.s3\.amazonaws\.com/((.+)\/)*([^\/]+)
          - /verkada-access-firmware\.s3\.us-west-2\.amazonaws\.com/((.+)\/)*([^\/]+)
      - host: access.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[0-9a-f-]{36}/alert_subscription
          - /[0-9a-f-]{36}/alert_subscriptions
          - /[0-9a-f-]{36}/config
          - /[0-9a-f-]{36}/keys
          - /[0-9a-f-]{36}/keys/[0-9a-f-]{36}
          - /access/v2/device/access_config/1
          - /access/v2/device/access_config/2
          - /access/v2/device/access_config/3
          - /access/v2/device/access_controller/config/get
          - /access/v2/device/access_controller/config_status/set
          - /access/v2/device/access_device/peripheral/metadata
          - /access/v2/device/config/1
          - /access/v2/device/config/2
          - /access/v2/device/device_information
          - /access/v2/device/device_io/[0-9a-f-]{36}/metadata
          - /access/v2/device/device_io/[0-9a-f-]{36}/tamper
          - /access/v2/device/door/[0-9a-f-]{36}/unlock
          - /access/v2/device/event/2
          - /access/v2/device/schedule_config/1
          - /access/v2/device/verkada_nfc/desfire_key
          - /access/v2/device/verkada_nfc/desfire_key/2
          - /access/v2/device/verkada_nfc/master_key
          - /access/v2/user/access_controller/[0-9a-f-]{36}/config_status/get
          - /access/v2/user/access_controller/[0-9a-f-]{36}/mode
          - /access/v2/user/access_controller/[0-9a-f-]{36}/reader_peripherals/status
          - /access/v2/user/access_controller/assign_hub
          - /access/v2/user/access_controller/reader_peripherals/statuses
          - /access/v2/user/access_controller/switch_mode
          - /access/v2/user/access_controllers
          - /access/v2/user/access_device/[0-9a-f-]{36}/manual_behavior
          - /access/v2/user/access_device/[0-9a-f-]{36}/manual_behavior/[0-9a-f-]{36}
          - /access/v2/user/access_device/[0-9a-f-]{36}/reboot
          - /access/v2/user/access_device/commission_unassigned_bulk
          - /access/v2/user/access_device/setup
          - /access/v2/user/allegion_engage/site/[0-9a-f-]{36}/sync
          - /access/v2/user/areas
          - /access/v2/user/areas/[0-9a-f-]{36}
          - /access/v2/user/aux_inputs
          - /access/v2/user/aux_output/[0-9a-f-]{36}
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario/[0-9a-f-]{36}
          - /access/v2/user/aux_output/[0-9a-f-]{36}/aux_scenario/[0-9a-f-]{36}/dismiss
          - /access/v2/user/aux_output/[0-9a-f-]{36}/dismiss
          - /access/v2/user/aux_output/[0-9a-f-]{36}/peer_devices
          - /access/v2/user/aux_output/status
          - /access/v2/user/aux_outputs
          - /access/v2/user/credentials/export_csv
          - /access/v2/user/credentials/import_csv
          - /access/v2/user/demo
          - /access/v2/user/door/[0-9a-f-]{36}/privacy_groups
          - /access/v2/user/door/[0-9a-f-]{36}/verify_site
          - /access/v2/user/doors
          - /access/v2/user/elevator
          - /access/v2/user/elevator/[0-9a-f-]{36}
          - /access/v2/user/elevator/[0-9a-f-]{36}/nearby_cameras
          - /access/v2/user/elevators
          - /access/v2/user/license_plate
          - /access/v2/user/license_plate/[\w\.\-]+
          - /access/v2/user/license_plate/delete
          - /access/v2/user/live_links
          - /access/v2/user/live_links/[0-9a-f-]{36}
          - /access/v2/user/lockdowns
          - /access/v2/user/lockdowns/[0-9a-f-]{36}
          - /access/v2/user/mfa_code
          - /access/v2/user/mfa_code/delete
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controller/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controller/[0-9a-f-]{36}/reader_peripheral/delete
          - /access/v2/user/organization/[0-9a-f-]{36}/access_controllers
          - /access/v2/user/organization/[0-9a-f-]{36}/auto_expire_exempt_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/badge_template
          - /access/v2/user/organization/[0-9a-f-]{36}/badge_template/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/bulk_set_auto_expire_exempt_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/entity_events/[0-9a-f-]{36}/possible_cards
          - /access/v2/user/organization/[0-9a-f-]{36}/images
          - /access/v2/user/organization/[0-9a-f-]{36}/images/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/images/[0-9a-f-]{36}\.png
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/preview
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/csv
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/end
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/event
          - /access/v2/user/organization/[0-9a-f-]{36}/muster/template/[0-9a-f-]{36}/report/[0-9a-f-]{36}/event/latest
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report/[0-9a-f-]{36}
          - /access/v2/user/organization/[0-9a-f-]{36}/saved_report/[0-9a-f-]{36}/send
          - /access/v2/user/organization/[0-9a-f-]{36}/user_groups
          - /access/v2/user/organization/[0-9a-f-]{36}/users/stats/group_member_count
          - /access/v2/user/organization/door_access_report
          - /access/v2/user/organization/door_access_report/export
          - /access/v2/user/organization/mobile_nfc
          - /access/v2/user/pass/android_nfc
          - /access/v2/user/pass/unlockables/1
          - /access/v2/user/pass_app_issue
          - /access/v2/user/roles
          - /access/v2/user/roles/modify
          - /access/v2/user/schedules
          - /access/v2/user/schedules/[0-9a-f-]{36}
          - /access/v2/user/users/[0-9a-f-]{36}/mfa_codes
          - /access/v2/user/users/bulk
          - /access/v2/user/users/invite_guest
          - /access/v2/user/users/search
          - /access/v2/user/virtual_device/[0-9a-f-]{36}/toggle
          - /access/v2/user/virtual_device/[0-9a-f-]{36}/unlock
          - /access/v2/user/visit_types
          - /access/v2/user/visit_types/[0-9a-f-]{36}
          - /access/v2/user/visitor/credentials/delete
          - /access/v2/user/visits
          - /access/v2/user/visits/[0-9a-f-]{36}
          - /access/v2/user/visits/count
          - /access/v2/user/wireless_hub/bulk_assign_wireless_locks
          - /access/v2/user/wireless_hub/remove_connections
          - /access/v2/user/wireless_hubs
          - /access/v2/user/wireless_lock/remove_connections
          - /access/v2/user/wireless_locks
          - /access/v2/users/organization/events/time
          - /access_controller/[0-9a-f-]{36}/aux_input
          - /access_controller/[0-9a-f-]{36}/aux_output
          - /access_controller/[0-9a-f-]{36}/manual_behavior/[0-9a-f-]{36}/device_io
          - /access_controller/aux_was_pressed
          - /access_controller/ble_stat/update
          - /access_controller/config/get
          - /access_controller/config/set
          - /access_controller/edit
          - /access_controller/event/history
          - /access_controller/event/update
          - /access_controller/firmware/[a-zA-Z0-9-:_.]+
          - /access_controller/firmware_versions
          - /access_controller/health/update
          - /access_controller/identify
          - /access_controller/move_to_site
          - /access_controller/p2p_stat/update
          - /access_controller/reader_peripheral
          - /access_controller/reader_peripheral/clear
          - /access_controller/reader_stat/update
          - /access_controller/reboot
          - /access_controller/status
          - /access_controller/status/update
          - /access_controller/update
          - /access_controller/version
          - /access_controller/wireless_lock_stat/update
          - /access_device/[0-9a-f-]{36}/config
          - /access_device/[0-9a-f-]{36}/event
          - /access_device/commission
          - /access_device/decommission
          - /access_methods/get
          - /access_methods/modify
          - /action/[0-9a-f-]{36}
          - /alert_subscription/[0-9a-f-]{36}
          - /auth/assert
          - /auth/assert/permissions
          - /aux_input/[0-9a-f-]{36}
          - /aux_input/[0-9a-f-]{36}/action
          - /aux_input/[0-9a-f-]{36}/device_io
          - /aux_input/[0-9a-f-]{36}/lockdown_peer_devices
          - /aux_input/[0-9a-f-]{36}/peer_devices
          - /aux_input/set_nearby_cameras
          - /aux_output/[0-9a-f-]{36}
          - /debug-endpoint-for-error-capture-testing
          - /device_io/[0-9a-f-]{36}
          - /door/[0-9a-f-]{36}/device_io
          - /door/[0-9a-f-]{36}/display_image/[\w\-. +%]+
          - /door/[0-9a-f-]{36}/display_image/[\w\-. +%]+/image\.jpg
          - /door/[0-9a-f-]{36}/display_image/image\.jpg
          - /door/[0-9a-f-]{36}/metrics
          - /door/access_credentials
          - /door/config/get
          - /door/config/set
          - /door/convert
          - /door/create
          - /door/delete
          - /door/direct-permissions/list
          - /door/event/
          - /door/event/history
          - /door/event/latest
          - /door/event/send
          - /door/event/status
          - /door/move
          - /door/set_door_state
          - /door/set_metadata
          - /door/set_nearby_cameras
          - /door/stats
          - /door/unlock
          - /door/unlock/modify
          - /door/unlockable/list
          - /door/user_groups/bulk_grant_access
          - /door/user_groups/bulk_revoke_access
          - /door/user_groups/grant_access
          - /door/user_groups/list
          - /door/user_groups/revoke_access
          - /door/users/list
          - /elevator/[0-9a-f-]{36}/device_io
          - /get_entities
          - /get_users
          - /organization/config/get
          - /organization/config/set
          - /organizations/[0-9a-f-]{36}/lockdowns
          - /organizations/[0-9a-f-]{36}/lockdowns/release
          - /organizations/[0-9a-f-]{36}/lockdowns/trigger
          - /organizations/[0-9a-f-]{36}/schedules
          - /organizations/[0-9a-f-]{36}/schedules/[0-9a-f-]{36}
          - /pass-app/metrics
          - /submit_current_time
          - /swordfish/access/v2/user/allegion_engage/site
          - /swordfish/access/v2/user/allegion_engage/site/[0-9a-f-]{36}/invite
          - /swordfish/access/v2/user/allegion_engage/site/[0-9a-f-]{36}/sync
          - /user/[0-9a-f-]{36}
          - /user/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /user/access_card/activation_state
          - /user/access_card/active
          - /user/access_card/add
          - /user/access_card/delete
          - /user/access_card/get
          - /user/access_card/scan
          - /user/access_controller/[0-9a-f-]{36}/reader_peripheral/[A-Z0-9-]{14}
          - /user/code/delete
          - /user/code/set
          - /user/door/config/get
          - /user/email
          - /user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /user/photos/upload
          - /user/roles
          - /user_groups/add_group
          - /user_groups/add_user
          - /user_groups/bulk_add_users
          - /user_groups/bulk_remove_users
          - /user_groups/doors/list
          - /user_groups/get
          - /user_groups/get_group_membership
          - /user_groups/remove_group
          - /user_groups/remove_user
          - /user_groups/scim_groups
          - /user_groups/update_group_name
          - /user_roles/modify
          - /users/async_upload_csv
          - /users/async_upload_csv/status/
          - /users/create
          - /users/delete
          - /users/export_csv
          - /users/get_csv_template
          - /users/upload_csv
          - /users/upload_csv/pre_validate
          - /v1/device/information
        unauthenticatedEndpoints:
          - /\.well-known/apple-app-site-association
          - /access/v2/unlock/[0-9a-f-]{36}
          - /access/v2/user/linked_accounts
          - /access/v2/user/session_accounts
          - /access/v2/user/unlock_link/[0-9a-f-]{36}/exchange
          - /access/v2/webhook/ironclad/apple_wallet_notify
          - /access_card/qr_code\.jpg
          - /access_controller/auth/init
          - /internal/door/event/send
          - /internal/users/async_upload_csv/process_chunk
          - /internal/users/async_upload_csv/status/
          - /internal/users/async_upload_csv/status/[0-9a-f-]{36}
          - /internal/users/async_upload_csv/status/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /logs/relay-vaccess-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/4505653327888384/store/
          - /logs/relay-vaccess-sentry/api/5549229/store/
          - /model/[\w\-. ]+/firmware_version/[a-zA-Z0-9-:_.]+
          - /pass-app/magic-link
          - /ping
          - /swordfish/lock/Config
          - /swordfish/lock/alert
          - /swordfish/lock/audit
          - /swordfish/lock/certificates/current
          - /swordfish/lock/db/[0-9]+
          - /swordfish/lock/newCA
          - /swordfish/ping
          - /verkada-access-firmware\.s3\.amazonaws\.com/((.+)\/)*([^\/]+)
          - /verkada-access-firmware\.s3\.us-west-2\.amazonaws\.com/((.+)\/)*([^\/]+)
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vcerberus
    namespace: vinfra
    resourceVersion: "2459366582"
    uid: 4dad5b35-8b75-441d-9cfa-e04f9282f518
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcity/cameras/invite_to_share
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/accept
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/inbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/outbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/pending
          - /vcity/org/[0-9a-f-]{36}/sharing_organizations
          - /vcity/sharing/cameras/revoke_by_owner
          - /vcity/sharing/cameras/revoke_by_viewer
          - /vcity/sharing/set_auth
          - /vcity/sharing/token
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcity/cameras/invite_to_share
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/accept
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/inbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/outbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/pending
          - /vcity/org/[0-9a-f-]{36}/sharing_organizations
          - /vcity/sharing/cameras/revoke_by_owner
          - /vcity/sharing/cameras/revoke_by_viewer
          - /vcity/sharing/set_auth
          - /vcity/sharing/token
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vcity/cameras/invite_to_share
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/accept
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/inbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/outbound
          - /vcity/org/[0-9a-f-]{36}/sharing/cameras/pending
          - /vcity/org/[0-9a-f-]{36}/sharing_organizations
          - /vcity/sharing/cameras/revoke_by_owner
          - /vcity/sharing/cameras/revoke_by_viewer
          - /vcity/sharing/set_auth
          - /vcity/sharing/token
      - host: vcity.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /internal/cameras/invite_to_share
          - /internal/org/[0-9a-f-]{36}/sharing/cameras/accept
          - /internal/org/[0-9a-f-]{36}/sharing/cameras/inbound
          - /internal/org/[0-9a-f-]{36}/sharing/cameras/outbound
          - /internal/org/[0-9a-f-]{36}/sharing/cameras/pending
          - /internal/org/[0-9a-f-]{36}/sharing_organizations
          - /internal/sharing/cameras/revoke
          - /internal/sharing/cross_org_token
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-10T20:52:22Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vcity
    namespace: vinfra
    resourceVersion: "2431161476"
    uid: 88b108b0-d348-4523-8756-d7b695cc514e
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/check-in
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/stable
          - /vconductor/device_instance/auth/check
          - /vconductor/device_instance/check-in
          - /vconductor/device_instance/network_address
          - /vconductor/global/device_instance/auth/check
          - /vconductor/key/add_public_key
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update/[0-9a-f-]{36}/status
          - /vconductor/software_distribution/update_config/get
          - /vconductor/software_distribution/upload/path/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/[0-9a-f-]{36}/network_address
          - /device_instance/auth/enroll
          - /device_instance/auth/init
          - /device_instance/auth/token
          - /device_instance/auth/verify_hmac
          - /device_instance/commission
          - /device_instance/decommission
          - /device_instance/details
          - /device_instance/network_addresses/retrieve
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/upload/url/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/device_instance/auth/enroll
          - /vconductor/device_instance/auth/init
          - /vconductor/device_instance/auth/token
          - /vconductor/device_instance/auth/verify_hmac
          - /vconductor/ping
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/check-in
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/stable
          - /vconductor/device_instance/auth/check
          - /vconductor/device_instance/check-in
          - /vconductor/device_instance/network_address
          - /vconductor/global/device_instance/auth/check
          - /vconductor/key/add_public_key
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update/[0-9a-f-]{36}/status
          - /vconductor/software_distribution/update_config/get
          - /vconductor/software_distribution/upload/path/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/[0-9a-f-]{36}/network_address
          - /device_instance/auth/enroll
          - /device_instance/auth/init
          - /device_instance/auth/token
          - /device_instance/auth/verify_hmac
          - /device_instance/commission
          - /device_instance/decommission
          - /device_instance/details
          - /device_instance/network_addresses/retrieve
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/upload/url/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/device_instance/auth/enroll
          - /vconductor/device_instance/auth/init
          - /vconductor/device_instance/auth/token
          - /vconductor/device_instance/auth/verify_hmac
          - /vconductor/ping
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/check-in
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/stable
          - /vconductor/device_instance/auth/check
          - /vconductor/device_instance/check-in
          - /vconductor/device_instance/network_address
          - /vconductor/global/device_instance/auth/check
          - /vconductor/key/add_public_key
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update/[0-9a-f-]{36}/status
          - /vconductor/software_distribution/update_config/get
          - /vconductor/software_distribution/upload/path/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/[0-9a-f-]{36}/network_address
          - /device_instance/auth/enroll
          - /device_instance/auth/init
          - /device_instance/auth/token
          - /device_instance/auth/verify_hmac
          - /device_instance/commission
          - /device_instance/decommission
          - /device_instance/details
          - /device_instance/network_addresses/retrieve
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/upload/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/upload/url/[0-9a-f-]{36}/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/device_instance/auth/enroll
          - /vconductor/device_instance/auth/init
          - /vconductor/device_instance/auth/token
          - /vconductor/device_instance/auth/verify_hmac
          - /vconductor/ping
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: vcerberus.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/details
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/device_instance/auth/check
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update_config/get
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/auth/init
          - /device_instance/commission
          - /device_instance/decommission
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/device_instance/auth/init
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: access.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device_instance/auth/check
          - /device_instance/details
          - /device_instance/network_address
          - /regional/device_instance/auth/check
          - /software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/device_instance/auth/check
          - /vconductor/regional/device_instance/auth/check
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update_config/get
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/auth/init
          - /device_instance/commission
          - /device_instance/decommission
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/device_instance/auth/init
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
      - host: vconductor.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /command/device/find
          - /command/device/list
          - /command/device/metadata
          - /device_instance/auth/check
          - /device_instance/check-in
          - /device_instance/network_address
          - /global/device_instance/auth/check
          - /internal/admin/device/metadata
          - /internal/admin/device/update
          - /internal/admin/device_instance/decommission
          - /internal_user/key/public_keys
          - /key/add_public_key
          - /key/create_keypair
          - /org/[0-9a-f-]{36}/devices
          - /org/[0-9a-f-]{36}/devices/assign
          - /org/[0-9a-f-]{36}/unassigned_devices
          - /regional/device_instance/auth/check
          - /serial_number/batch/validate
          - /serial_number/create
          - /serial_number/validate
          - /software_distribution/clear_download_loop_events
          - /software_distribution/device_list_latest
          - /software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/latest/[\w\-. ]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/stable
          - /software_distribution/latest_v2
          - /software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /software_distribution/site/[0-9a-f-]{36}/update_schedule
          - /software_distribution/update/[0-9a-f-]{36}/status
          - /software_distribution/update_config/get
          - /software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/command/device/batch/commission
          - /vconductor/command/device/metadata
          - /vconductor/device_instance/auth/check
          - /vconductor/device_instance/check-in
          - /vconductor/device_instance/network_address
          - /vconductor/key/add_public_key
          - /vconductor/software_distribution/device_list_latest
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/download/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/latest_v2
          - /vconductor/software_distribution/release_channel_name/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /vconductor/software_distribution/update/[0-9a-f-]{36}/status
          - /vconductor/software_distribution/update_config/get
          - /vconductor/software_distribution/upload/path/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/upload/url/[a-zA-Z_]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/vconductor/software_distribution/update_config/get
        unauthenticatedEndpoints:
          - /device_instance/auth/enroll
          - /device_instance/auth/init
          - /device_instance/auth/token
          - /device_instance/auth/verify_hmac
          - /device_instance/commission
          - /device_instance/decommission
          - /device_instance/details
          - /key/bulk/set_rotate_after
          - /key/public_keys
          - /key/sign
          - /ping
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/[\w\-. +%]+
          - /software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
          - /software_distribution/site/[0-9a-f-]{36}/update_schedule
          - /software_distribution/upload/[\w\-. ]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /software_distribution/upload/[\w\-. ]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /software_distribution/upload/url/[\w\-. ]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/device_instance/auth/enroll
          - /vconductor/device_instance/auth/init
          - /vconductor/device_instance/auth/token
          - /vconductor/device_instance/auth/verify_hmac
          - /vconductor/ping
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+
          - /vconductor/software_distribution/_download/[\w\-._]+/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*/[a-zA-Z0-9-:_.]+/((.+)\/)*([^\/]+)
          - /vconductor/software_distribution/latest/(?i)[^/]*(sensor|os|bin|disk_image|rootfs|kernel|container|system|application|bootloader|signature|version-manager|rhodesd|beefeater|gandalf|gandalfxp|dumbledore|kenobi-reader|hagrid|overlay_services)+[^/]*
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vconductor
    namespace: vinfra
    resourceVersion: "2417982161"
    uid: fb5228fb-be41-4002-ac21-049845866876
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vcorgi.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[0-9a-f-]{36}/[0-9a-f-]{36}/agreements
          - /[0-9a-f-]{36}/[0-9a-f-]{36}/sign_agreement
          - /[0-9a-f-]{36}/agreements
          - /[0-9a-f-]{36}/device/agreements
          - /[0-9a-f-]{36}/key_contact
          - /[0-9a-f-]{36}/key_contact/BILLING
          - /[0-9a-f-]{36}/key_contact/PRIMARY
          - /[0-9a-f-]{36}/key_contact/SECURITY
          - /[0-9a-f-]{36}/key_contacts
          - /[0-9a-f-]{36}/notification_contacts
          - /[0-9a-f-]{36}/notification_contacts/edit
          - /[0-9a-f-]{36}/security_checklist
          - /[0-9a-f-]{36}/sign_agreement
          - /[0-9a-f-]{36}/verify_data_deletion
          - /[0-9a-f-]{36}/video_sharing_agreement
          - /device/recommended_default_settings/apply
          - /device/recommended_default_settings/device_cache
          - /device/recommended_default_settings/get
          - /operations/list
          - /org/[0-9a-f-]{36}/end_customers
          - /org/[0-9a-f-]{36}/feature
          - /org/[0-9a-f-]{36}/features
          - /org/[0-9a-f-]{36}/features/compliance_report
          - /org/[0-9a-f-]{36}/features/removal_requests
          - /org/[0-9a-f-]{36}/features/removal_requests/approve
          - /org/[0-9a-f-]{36}/features/removal_requests/cancel
          - /org/[0-9a-f-]{36}/features/removal_requests/resend
          - /org/[0-9a-f-]{36}/is_partner
          - /org/[0-9a-f-]{36}/oidc_provider
          - /org/[0-9a-f-]{36}/oidc_provider/verify
          - /org/[0-9a-f-]{36}/partner
          - /org/[0-9a-f-]{36}/partner_token
          - /org/[0-9a-f-]{36}/partners
          - /org/[0-9a-f-]{36}/privacy_disclosure
          - /org/[0-9a-f-]{36}/privacy_disclosure/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/privacy_disclosure/[0-9a-f-]{36}/logo
          - /org/[0-9a-f-]{36}/privacy_disclosure/logo
          - /org/[0-9a-f-]{36}/privacy_disclosures
          - /org/[0-9a-f-]{36}/reason_code
          - /org/[0-9a-f-]{36}/salesforce_account
          - /org/[0-9a-f-]{36}/site_location/[0-9a-f-]{36}/site_project
          - /org/[0-9a-f-]{36}/site_planner/preferences
          - /org/[0-9a-f-]{36}/site_planner/salesforce/check
          - /org/[0-9a-f-]{36}/site_planner/salesforce/login
          - /org/[0-9a-f-]{36}/site_planner/salesforce/opportunity
          - /org/[0-9a-f-]{36}/site_planner/salesforce/opportunity/[\w\.\-]+
          - /org/[0-9a-f-]{36}/site_planner/site_location/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/[0-9a-f-]{36}/upload
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/copy
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/delete
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/live_link
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/live_link/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/live_links
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/permissions
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/resource
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/resource/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/save
          - /org/[0-9a-f-]{36}/site_project/create
          - /org/[0-9a-f-]{36}/site_project/list
          - /org/[0-9a-f-]{36}/user_inactive_deactivate_period
          - /org/[0-9a-f-]{36}/users/delete
          - /org/support_cases
          - /site_planner/site_location
          - /site_planner/site_location/[0-9a-f-]{36}
          - /site_planner/site_location/list
          - /site_planner/site_plan
          - /site_planner/site_plan/[0-9a-f-]{36}
          - /user/email/preferences
          - /v2/org/[0-9a-f-]{36}/privacy_disclosure
          - /v2/org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}
          - /v2/org/[0-9a-f-]{36}/site_project/[0-9a-f-]{36}/copy
          - /v2/org/[0-9a-f-]{36}/site_project/create
          - /v2/org/[0-9a-f-]{36}/site_project/list
        unauthenticatedEndpoints:
          - /login/oidc
          - /ping
          - /public/oidc_provider
          - /public/privacy_disclosure
          - /site_planner/live_link/[0-9a-f-]{36}/redeem
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vcorgi
    namespace: vinfra
    resourceVersion: "2208351996"
    uid: 26318528-af2c-494a-8bb3-f00851678b73
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdashboard.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/hyperzoom/get
          - /camera/hyperzoom/list
          - /device/line_crossing/get
          - /device/line_crossing/update
          - /device/occupancy_trends/get
          - /user/dashboard/aggregate
          - /user/dashboard/create
          - /user/dashboard/delete
          - /user/dashboard/get
          - /user/dashboard/list
          - /user/dashboard/update
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vdashboard
    namespace: vinfra
    resourceVersion: "2158702237"
    uid: 3116f475-c8f7-4d86-8acf-2804bcbab35b
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdelete.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vdelete
    namespace: vinfra
    resourceVersion: "2158702233"
    uid: cd37c7e4-b493-40d6-ac6e-34a5bbe9f7bd
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/config/get
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/config/get
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/config/get
      - host: vdeviceconfig.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/config/get
          - /user/camera/config/get
          - /user/camera/config/set
          - /user/camera/feature/get
          - /user/camera/feature/set
          - /user/org/config/get
          - /user/org/config/set
          - /user/org/feature/get
          - /user/org/feature/set
        unauthenticatedEndpoints:
          - /internal/camera/config/get
          - /internal/camera/config/set
          - /internal/model/config/set
          - /ping
      - host: vdeviceconfig.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /internal/camera/config/get
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vdeviceconfig
    namespace: vinfra
    resourceVersion: "2417982183"
    uid: 51a1caa5-5b40-4286-af6b-fdb6cc7f91b5
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vdevicestats/ws/stats
        unauthenticatedEndpoints:
          - /camera/stats/add
          - /vdevicestats/camera/stats/add
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vdevicestats/ws/stats
        unauthenticatedEndpoints:
          - /camera/stats/add
          - /vdevicestats/camera/stats/add
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vdevicestats/ws/stats
        unauthenticatedEndpoints:
          - /camera/stats/add
          - /vdevicestats/camera/stats/add
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vdevicestats
    namespace: vinfra
    resourceVersion: "2417982129"
    uid: 94c2d821-b277-457b-bc6d-522024553054
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdoorman.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /ping
        unauthenticatedEndpoints:
          - /host_portal/magic_link/request
          - /outlook/guest/codes
          - /outlook/guest/login
          - /package/slack/[0-9a-f-]{36}/
          - /packages/teams/callback
          - /slack/[0-9a-f-]{36}
          - /teams/callback
          - /unauthed_feature_flags
      - host: mailroom.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/toggle
          - /access/org/[0-9a-f-]{36}/toggle
          - /analytics/app
          - /analytics/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /analytics/package
          - /analytics_v2/org/[0-9a-f-]{36}
          - /analytics_v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /app-login/[0-9a-f-]{36}
          - /application_url/org_id/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/web
          - /approve_list/org/[0-9a-f-]{36}
          - /bg_check/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /bg_check/applicant/org/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /bg_check/cancel/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /bg_check/confirm/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/fetch/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /bg_check/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /botd/badge/[0-9a-f-]{36}
          - /botd/org/[0-9a-f-]{36}
          - /call_button/access_token/device/[0-9a-f-]{36}
          - /call_button/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /context_devices/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/config/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/logo_image/[0-9a-f-]{36}
          - /demo_visit_hyperzoom/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /demo_visit_video/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /device/[0-9a-f-]{36}
          - /device/[0-9a-f-]{36}/events
          - /device/[0-9a-f-]{36}/screenshot
          - /device/[0-9a-f-]{36}/stash_visit
          - /device/health
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/claim
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/identify
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/test_print
          - /device_init
          - /document/org/[0-9a-f-]{36}
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_fields
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_progress
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/convert
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_fields
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_progress
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_redirect
          - /echo
          - /event/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/resend
          - /event/by_day/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /face_match/device/[0-9a-f-]{36}
          - /face_match/device/[0-9a-f-]{36}/model
          - /face_match/device/[0-9a-f-]{36}/opt_in
          - /form/org/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/form/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/publish
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/form/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /guardian/temp/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /guardian/temp/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /guest/announcements/create
          - /guest/announcements/org/[0-9a-f-]{36}
          - /guest/licensing/overview/org/[0-9a-f-]{36}
          - /guest/org/[0-9a-f-]{36}/guest/[0-9a-f-]{36}/poi
          - /guest/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest/[0-9a-f-]{36}/photo
          - /guest/photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest/[0-9a-f-]{36}
          - /guest/trial/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/departments/org/[0-9a-f-]{36}
          - /healthcare/end_visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/[0-9a-f-]{36}/departments
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/verify
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/search
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /healthcare/partially_registered_visitor/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/partially_registered_visitor/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clear
          - /healthcare/partially_registered_visitor/qr_code/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/command/org/[0-9a-f-]{36}
          - /host/command/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/csv/org/[0-9a-f-]{36}
          - /host/csv/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/email/org/[0-9a-f-]{36}
          - /host/email/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/inherit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/all
          - /host/org/[0-9a-f-]{36}/delete
          - /host/org/[0-9a-f-]{36}/host/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/all
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/delete
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/host/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/host_id/[0-9a-f-]{36}/photo
          - /internal/pending_applicant_notifications
          - /internal/receptionist/notification_receptionist_manual_entry
          - /internal/receptionist/notification_receptionist_review
          - /internal/sync_command_hosts
          - /invite/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /invite_nfc/[0-9a-f-]{36}
          - /invited_guest/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /invited_guest/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/resend
          - /licensing/org/[0-9a-f-]{36}/guest_activity_last_30_days
          - /licensing/org/[0-9a-f-]{36}/package_site_activity_last_30_days
          - /licensing/org/[0-9a-f-]{36}/request_purchase/guest
          - /licensing/org/[0-9a-f-]{36}/request_purchase/mailroom
          - /licensing/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest
          - /licensing/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/mailroom
          - /licensing/overview/org/[0-9a-f-]{36}
          - /locale
          - /mailroom/licensing/overview/org/[0-9a-f-]{36}
          - /mailroom/trial/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/api_key_info
          - /meraki/org/[0-9a-f-]{36}/networks
          - /meraki/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/ssids
          - /multi_part_document/org/[0-9a-f-]{36}
          - /multi_part_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /multi_part_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/convert
          - /open_ended_questions/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type/[0-9a-f-]{36}
          - /open_ended_questions/org/[0-9a-f-]{36}/visitor_type/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/bootstrap
          - /org/[0-9a-f-]{36}/command/groups
          - /org/[0-9a-f-]{36}/deny_list/upload_csv
          - /org/[0-9a-f-]{36}/email_security
          - /org/[0-9a-f-]{36}/extend_trial
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/deny_list/[0-9a-f-]{36}/review
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/deny_list/upload_csv
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}/screenshot
          - /org/[0-9a-f-]{36}/trial
          - /org/assets/[0-9a-f-]{36}
          - /org/broken_link/[0-9a-f-]{36}
          - /org/preferences/[0-9a-f-]{36}
          - /org/shortname
          - /org/trial_devices/request/[0-9a-f-]{36}
          - /package/[0-9a-f-]{36}/image
          - /package/[0-9a-f-]{36}/reassign
          - /package/pickup/user/[0-9a-f-]{36}
          - /package_context_devices/device/[0-9a-f-]{36}
          - /package_context_devices/site/[0-9a-f-]{36}
          - /package_context_devices/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /package_media/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_org/extend_trial
          - /package_org/milestone/[0-9a-f-]{36}
          - /package_org/preferences/[0-9a-f-]{36}
          - /package_org/trial_devices/request/[0-9a-f-]{36}
          - /package_printer/[0-9a-f-]{36}
          - /package_printer/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/location
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/location/[0-9a-f-]{36}
          - /package_tag/site/[0-9a-f-]{36}
          - /packages/announcements/create
          - /packages/announcements/org/[0-9a-f-]{36}
          - /packages/get_name_from_address_dict/site/[0-9a-f-]{36}
          - /packages/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /packages/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/package/[0-9a-f-]{36}
          - /packages/package/[0-9a-f-]{36}
          - /packages/site/[0-9a-f-]{36}
          - /packages/site/[0-9a-f-]{36}/stats/graph
          - /packages/site/[0-9a-f-]{36}/stats/topline
          - /packages/site/[0-9a-f-]{36}/tracking_history
          - /packages/slack/[0-9a-f-]{36}/oauth_redirect
          - /packages/slack/[0-9a-f-]{36}/slack_active
          - /packages/slack/[0-9a-f-]{36}/uninstall_extention
          - /packages/slack/[0-9a-f-]{36}/workspace_logo
          - /packages/teams/org/[0-9a-f-]{36}/consent/redirect
          - /packages/teams/org/[0-9a-f-]{36}/info
          - /packages/teams/org/[0-9a-f-]{36}/uninstall
          - /packages/v2/site/[0-9a-f-]{36}
          - /packages_demo/package/site/[0-9a-f-]{36}
          - /patient/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient/[0-9a-f-]{36}
          - /patient_known_person/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient/[0-9a-f-]{36}
          - /patient_known_person/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient_known_person/[0-9a-f-]{36}
          - /patient_known_person/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient_known_person/[0-9a-f-]{36}
          - /permissions/org/[0-9a-f-]{36}
          - /printer/[0-9a-f-]{36}/print
          - /printer/device/[0-9a-f-]{36}
          - /printer/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /qr_code/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /questionnaire/org/[0-9a-f-]{36}
          - /questionnaire/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /receptionist/org/[0-9a-f-]{36}/update_notification
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/cancel
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/deny
          - /recipients/site/[0-9a-f-]{36}
          - /registration_url/device/[0-9a-f-]{36}
          - /registration_url/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/redirect
          - /registration_url/org_id/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/web
          - /school/csv/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/assign
          - /school/org/[0-9a-f-]{36}/connect
          - /school/org/[0-9a-f-]{36}/disconnect
          - /school/org/[0-9a-f-]{36}/reconnect
          - /school/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/sync
          - /school/org/[0-9a-f-]{36}/sync
          - /security_screen/confirm/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /single_event/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/[0-9a-f-]{36}/enable_custom_print_driver
          - /site/[0-9a-f-]{36}/timestamp/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /site/assets/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/enable
          - /site/org/[0-9a-f-]{36}
          - /site/settings/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/settings/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /slack/[0-9a-f-]{36}/oauth_redirect
          - /slack/[0-9a-f-]{36}/slack_active
          - /slack/[0-9a-f-]{36}/uninstall_extention
          - /slack/[0-9a-f-]{36}/workspace_logo
          - /sync_command_hosts/org/[0-9a-f-]{36}
          - /sync_command_hosts/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /tablet_screen_sharing/access_token/device/[0-9a-f-]{36}
          - /tablet_screen_sharing/access_token/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /teams/org/[0-9a-f-]{36}/consent/redirect
          - /teams/org/[0-9a-f-]{36}/info
          - /teams/org/[0-9a-f-]{36}/uninstall
          - /unlock_link/assert_valid
          - /user/my/org/[0-9a-f-]{36}
          - /user/org/[0-9a-f-]{36}
          - /user/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /user/reception/my/org/[0-9a-f-]{36}
          - /user/valid_sites/org/[0-9a-f-]{36}
          - /user_group/org/[0-9a-f-]{36}/user_group/[0-9a-f-]{36}
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/approve
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/deny
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/pend
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/upload
          - /visit/batch/signout_previous/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/by_contact/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/docs/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/export/org/[0-9a-f-]{36}
          - /visit/export/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/export/v2/org/[0-9a-f-]{36}
          - /visit/id_photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/id_signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/land_page/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/redeem
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/allow_entry
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/id/scan
          - /visit/photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/purpose/org/[0-9a-f-]{36}
          - /visit/purpose/org/[0-9a-f-]{36}/suggested
          - /visit/qr_signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/reprint/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/visit_notes/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/clone
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/hide
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/order
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/clone
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/publish
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /visitor_type/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/order
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/clone
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/publish
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/hide
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /visitor_type_document/org/[0-9a-f-]{36}
          - /visitor_type_document/org/[0-9a-f-]{36}/reorder
          - /visitor_type_document/org/[0-9a-f-]{36}/replace
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/reorder
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/replace
          - /visitor_type_migration/org/[0-9a-f-]{36}
          - /workplace/licensing/overview/org/[0-9a-f-]{36}
       unauthenticatedEndpoints:
          - /\.well-known/apple-app-site-association
          - /app_review/register
          - /batch_bg_check/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /batch_bg_check/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/form_id/[0-9a-f-]{36}
          - /bg_check/manual/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v2/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v3/manual/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v3/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /call_button/twilio/voice/[0-9a-f-]{36}
          - /device/token
          - /device/token/v2
          - /device/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /device_init
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_config
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_config
          - /echo
          - /entrance/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/host_portal
          - /event/host_portal/[0-9a-f-]{36}
          - /event/v2/[0-9a-f-]{36}
          - /event/v2/host_portal
          - /file
          - /global/device/init
          - /global/device/token
          - /global/host_portal/magic_link/request
          - /global/outlook/guest/codes
          - /global/outlook/guest/login
          - /global/slack/guest/[0-9a-f-]{36}
          - /global/slack/mailroom/[0-9a-f-]{36}
          - /global/teams/guest
          - /global/teams/mailroom
          - /guardian/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /guest/[0-9a-f-]{36}/photo
          - /guest/org/[0-9a-f-]{36}
          - /host/checkin/org/[0-9a-f-]{36}
          - /host/delegates
          - /host/host_portal/site/[0-9a-f-]{36}
          - /host/inherit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/preferences
          - /host/preferences/image
          - /host_approval/app_config/token/[0-9a-f-]{36}
          - /host_approval/slack/[0-9a-f-]{36}/
          - /host_approval/token/[0-9a-f-]{36}
          - /host_portal/app_config
          - /host_portal/logout
          - /host_portal/magic_link/redeem
          - /host_portal/magic_link/request
          - /host_portal/ping
          - /internal/document/media_convert_job
          - /internal/guest/trial/site/[0-9a-f-]{36}
          - /internal/invite
          - /internal/mailroom/trial/site/[0-9a-f-]{36}
          - /internal/org/[0-9a-f-]{36}
          - /invite_guest/host_portal/event/[0-9a-f-]{36}
          - /invite_guest/host_portal/org/[0-9a-f-]{36}/csv/parse
          - /notifications/callback/[a-z0-9]{32}
          - /notifications/email_status
          - /notifications/pinpoint_sms
          - /notifications/pinpoint_sms/mailroom
          - /notifications/pinpoint_sms/v2
          - /org/quickstart
          - /outlook/guest
          - /outlook/guest/fetch
          - /outlook/guest/signout
          - /package/[0-9a-f-]{36}/photo
          - /package/email/not_mine/[0-9a-f-]{36}
          - /package/email/pickup/[0-9a-f-]{36}
          - /package/pickup/rfid/[A-Z0-9]{24}
          - /package/pickup/user/[0-9a-f-]{36}
          - /package/slack/[0-9a-f-]{36}/
          - /package_media/[0-9a-f-]{36}
          - /package_org/quickstart
          - /package_portal/employee
          - /package_portal/employee/[0-9a-f-]{36}
          - /package_portal/employee/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_portal/not_my
          - /package_portal/pickup
          - /package_portal/single/[0-9a-f-]{36}
          - /package_portal/single/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /package_portal/single/[0-9a-f-]{36}/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_status/app_config/token/[0-9a-f-]{36}
          - /package_status/app_config/token/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /packages/carriers
          - /packages/rfid_inventory
          - /packages/site/[0-9a-f-]{36}
          - /packages/slack/oauth_callback
          - /packages/teams/consent/callback
          - /packages_demo/config
          - /packages_demo/package/site/[0-9a-f-]{36}
          - /packages_demo/signature/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /pass/org/[0-9a-f-]{36}/apple
          - /pass/org/[0-9a-f-]{36}/google
          - /pass/v1/devices/[a-zA-Z0-9-]+/registrations/[\w\.\-]+
          - /pass/v1/devices/[a-zA-Z0-9-]+/registrations/[\w\.\-]+/[0-9a-f-]{36}
          - /pass/v1/passes/[\w\.\-]+/[0-9a-f-]{36}
          - /ping
          - /ping_env
          - /reception-app/magic-login/redeem
          - /registration_app_config/camera/[0-9a-f-]{36}/thumbnail
          - /registration_app_config/org/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/verify
          - /slack/[0-9a-f-]{36}
          - /slack/oauth_callback
          - /student/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /teams/consent/callback
          - /twilio/webhook/[a-z0-9]{32}
          - /twilio/webhook/packages/[a-z0-9]{32}
          - /unauthed_feature_flags
          - /visit/fastpass/org/[0-9a-f-]{36}
          - /visit/invited/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/search
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /visit/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/return/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/signout/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /visit/v2/return/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/vt/[0-9a-f-]{36}
      - host: vdoorman.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/toggle
          - /access/org/[0-9a-f-]{36}/toggle
          - /analytics/app
          - /analytics/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /analytics/package
          - /analytics_v2/org/[0-9a-f-]{36}
          - /analytics_v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /app-login/[0-9a-f-]{36}
          - /application_url/org_id/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/web
          - /approve_list/org/[0-9a-f-]{36}
          - /bg_check/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /bg_check/applicant/org/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /bg_check/cancel/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /bg_check/confirm/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/fetch/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /bg_check/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /botd/badge/[0-9a-f-]{36}
          - /botd/org/[0-9a-f-]{36}
          - /call_button/access_token/device/[0-9a-f-]{36}
          - /call_button/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /context_devices/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /context_devices/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/config/[0-9a-f-]{36}
          - /custom_app_config/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/logo_image/[0-9a-f-]{36}
          - /demo_visit_hyperzoom/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /demo_visit_video/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /device/[0-9a-f-]{36}
          - /device/[0-9a-f-]{36}/events
          - /device/[0-9a-f-]{36}/screenshot
          - /device/[0-9a-f-]{36}/stash_visit
          - /device/health
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/claim
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/identify
          - /device/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/test_print
          - /device_init
          - /document/org/[0-9a-f-]{36}
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_fields
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video
          - /document/org/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_progress
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/convert
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_fields
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_progress
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_redirect
          - /echo
          - /event/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/resend
          - /event/by_day/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /face_match/device/[0-9a-f-]{36}
          - /face_match/device/[0-9a-f-]{36}/model
          - /face_match/device/[0-9a-f-]{36}/opt_in
          - /form/org/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/form/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/publish
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/form/[0-9a-f-]{36}
          - /form/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /guardian/temp/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /guardian/temp/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /guest/announcements/create
          - /guest/announcements/org/[0-9a-f-]{36}
          - /guest/licensing/overview/org/[0-9a-f-]{36}
          - /guest/org/[0-9a-f-]{36}/guest/[0-9a-f-]{36}/poi
          - /guest/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest/[0-9a-f-]{36}/photo
          - /guest/photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest/[0-9a-f-]{36}
          - /guest/trial/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/departments/org/[0-9a-f-]{36}
          - /healthcare/end_visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/[0-9a-f-]{36}
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/[0-9a-f-]{36}/departments
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/checkpoint/verify
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/search
          - /healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /healthcare/partially_registered_visitor/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /healthcare/partially_registered_visitor/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clear
          - /healthcare/partially_registered_visitor/qr_code/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/command/org/[0-9a-f-]{36}
          - /host/command/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/csv/org/[0-9a-f-]{36}
          - /host/csv/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/email/org/[0-9a-f-]{36}
          - /host/email/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/inherit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/all
          - /host/org/[0-9a-f-]{36}/delete
          - /host/org/[0-9a-f-]{36}/host/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/all
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/delete
          - /host/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/host/[0-9a-f-]{36}
          - /host/org/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/host_id/[0-9a-f-]{36}/photo
          - /internal/pending_applicant_notifications
          - /internal/receptionist/notification_receptionist_manual_entry
          - /internal/receptionist/notification_receptionist_review
          - /internal/sync_command_hosts
          - /invite/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /invite_nfc/[0-9a-f-]{36}
          - /invited_guest/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /invited_guest/[0-9a-f-]{36}/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/resend
          - /licensing/org/[0-9a-f-]{36}/guest_activity_last_30_days
          - /licensing/org/[0-9a-f-]{36}/package_site_activity_last_30_days
          - /licensing/org/[0-9a-f-]{36}/request_purchase/guest
          - /licensing/org/[0-9a-f-]{36}/request_purchase/mailroom
          - /licensing/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/guest
          - /licensing/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/mailroom
          - /licensing/overview/org/[0-9a-f-]{36}
          - /locale
          - /mailroom/licensing/overview/org/[0-9a-f-]{36}
          - /mailroom/trial/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/api_key_info
          - /meraki/org/[0-9a-f-]{36}/networks
          - /meraki/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /meraki/org/[0-9a-f-]{36}/ssids
          - /multi_part_document/org/[0-9a-f-]{36}
          - /multi_part_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /multi_part_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/convert
          - /open_ended_questions/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type/[0-9a-f-]{36}
          - /open_ended_questions/org/[0-9a-f-]{36}/visitor_type/[0-9a-f-]{36}
          - /org/[0-9a-f-]{36}/bootstrap
          - /org/[0-9a-f-]{36}/command/groups
          - /org/[0-9a-f-]{36}/deny_list/upload_csv
          - /org/[0-9a-f-]{36}/email_security
          - /org/[0-9a-f-]{36}/extend_trial
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/deny_list/[0-9a-f-]{36}/review
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/deny_list/upload_csv
          - /org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}/screenshot
          - /org/[0-9a-f-]{36}/trial
          - /org/assets/[0-9a-f-]{36}
          - /org/broken_link/[0-9a-f-]{36}
          - /org/preferences/[0-9a-f-]{36}
          - /org/shortname
          - /org/trial_devices/request/[0-9a-f-]{36}
          - /package/[0-9a-f-]{36}/image
          - /package/[0-9a-f-]{36}/reassign
          - /package/pickup/user/[0-9a-f-]{36}
          - /package_context_devices/device/[0-9a-f-]{36}
          - /package_context_devices/site/[0-9a-f-]{36}
          - /package_context_devices/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /package_media/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_org/extend_trial
          - /package_org/milestone/[0-9a-f-]{36}
          - /package_org/preferences/[0-9a-f-]{36}
          - /package_org/trial_devices/request/[0-9a-f-]{36}
          - /package_printer/[0-9a-f-]{36}
          - /package_printer/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/location
          - /package_site/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/location/[0-9a-f-]{36}
          - /package_tag/site/[0-9a-f-]{36}
          - /packages/announcements/create
          - /packages/announcements/org/[0-9a-f-]{36}
          - /packages/get_name_from_address_dict/site/[0-9a-f-]{36}
          - /packages/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /packages/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/package/[0-9a-f-]{36}
          - /packages/package/[0-9a-f-]{36}
          - /packages/site/[0-9a-f-]{36}
          - /packages/site/[0-9a-f-]{36}/stats/graph
          - /packages/site/[0-9a-f-]{36}/stats/topline
          - /packages/site/[0-9a-f-]{36}/tracking_history
          - /packages/slack/[0-9a-f-]{36}/oauth_redirect
          - /packages/slack/[0-9a-f-]{36}/slack_active
          - /packages/slack/[0-9a-f-]{36}/uninstall_extention
          - /packages/slack/[0-9a-f-]{36}/workspace_logo
          - /packages/teams/org/[0-9a-f-]{36}/consent/redirect
          - /packages/teams/org/[0-9a-f-]{36}/info
          - /packages/teams/org/[0-9a-f-]{36}/uninstall
          - /packages/v2/site/[0-9a-f-]{36}
          - /packages_demo/package/site/[0-9a-f-]{36}
          - /patient/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient/[0-9a-f-]{36}
          - /patient_known_person/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient/[0-9a-f-]{36}
          - /patient_known_person/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient_known_person/[0-9a-f-]{36}
          - /patient_known_person/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/patient_known_person/[0-9a-f-]{36}
          - /permissions/org/[0-9a-f-]{36}
          - /printer/[0-9a-f-]{36}/print
          - /printer/device/[0-9a-f-]{36}
          - /printer/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /qr_code/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /questionnaire/org/[0-9a-f-]{36}
          - /questionnaire/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /receptionist/org/[0-9a-f-]{36}/update_notification
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/cancel
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /receptionist/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/deny
          - /recipients/site/[0-9a-f-]{36}
          - /registration_url/device/[0-9a-f-]{36}
          - /registration_url/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/redirect
          - /registration_url/org_id/[0-9a-f-]{36}/site_id/[0-9a-f-]{36}/web
          - /school/csv/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/assign
          - /school/org/[0-9a-f-]{36}/connect
          - /school/org/[0-9a-f-]{36}/disconnect
          - /school/org/[0-9a-f-]{36}/reconnect
          - /school/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/sync
          - /school/org/[0-9a-f-]{36}/sync
          - /security_screen/confirm/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /single_event/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/[0-9a-f-]{36}/enable_custom_print_driver
          - /site/[0-9a-f-]{36}/timestamp/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /site/assets/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/healthcare/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/enable
          - /site/org/[0-9a-f-]{36}
          - /site/settings/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /site/settings/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /slack/[0-9a-f-]{36}/oauth_redirect
          - /slack/[0-9a-f-]{36}/slack_active
          - /slack/[0-9a-f-]{36}/uninstall_extention
          - /slack/[0-9a-f-]{36}/workspace_logo
          - /sync_command_hosts/org/[0-9a-f-]{36}
          - /sync_command_hosts/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /tablet_screen_sharing/access_token/device/[0-9a-f-]{36}
          - /tablet_screen_sharing/access_token/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /teams/org/[0-9a-f-]{36}/consent/redirect
          - /teams/org/[0-9a-f-]{36}/info
          - /teams/org/[0-9a-f-]{36}/uninstall
          - /unlock_link/assert_valid
          - /user/my/org/[0-9a-f-]{36}
          - /user/org/[0-9a-f-]{36}
          - /user/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /user/reception/my/org/[0-9a-f-]{36}
          - /user/valid_sites/org/[0-9a-f-]{36}
          - /user_group/org/[0-9a-f-]{36}/user_group/[0-9a-f-]{36}
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/approve
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/deny
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/pend
          - /visit/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/upload
          - /visit/batch/signout_previous/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/by_contact/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/docs/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/export/org/[0-9a-f-]{36}
          - /visit/export/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/export/v2/org/[0-9a-f-]{36}
          - /visit/id_photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/id_signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/land_page/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/redeem
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/allow_entry
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/id/scan
          - /visit/photo/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/purpose/org/[0-9a-f-]{36}
          - /visit/purpose/org/[0-9a-f-]{36}/suggested
          - /visit/qr_signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/reprint/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/visit_notes/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/clone
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/hide
          - /visitor_type/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/order
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/clone
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/publish
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/v2/applicant/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /visitor_type/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/order
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/assign/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/clone
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/publish
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/clone
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/hide
          - /visitor_type/v2/standard/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/publish
          - /visitor_type_document/org/[0-9a-f-]{36}
          - /visitor_type_document/org/[0-9a-f-]{36}/reorder
          - /visitor_type_document/org/[0-9a-f-]{36}/replace
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/reorder
          - /visitor_type_document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/replace
          - /visitor_type_migration/org/[0-9a-f-]{36}
          - /workplace/licensing/overview/org/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /\.well-known/apple-app-site-association
          - /app_review/register
          - /batch_bg_check/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /batch_bg_check/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}/form_id/[0-9a-f-]{36}
          - /bg_check/manual/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v2/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v3/manual/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /bg_check/v3/submit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /call_button/twilio/voice/[0-9a-f-]{36}
          - /device/token
          - /device/token/v2
          - /device/visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /device_init
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/pdf_config
          - /document/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/document/[0-9a-f-]{36}/video_config
          - /echo
          - /entrance/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /event/host_portal
          - /event/host_portal/[0-9a-f-]{36}
          - /event/v2/[0-9a-f-]{36}
          - /event/v2/host_portal
          - /file
          - /global/device/init
          - /global/device/token
          - /global/host_portal/magic_link/request
          - /global/outlook/guest/codes
          - /global/outlook/guest/login
          - /global/slack/guest/[0-9a-f-]{36}
          - /global/slack/mailroom/[0-9a-f-]{36}
          - /global/teams/guest
          - /global/teams/mailroom
          - /guardian/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /guest/[0-9a-f-]{36}/photo
          - /guest/org/[0-9a-f-]{36}
          - /host/checkin/org/[0-9a-f-]{36}
          - /host/delegates
          - /host/host_portal/site/[0-9a-f-]{36}
          - /host/inherit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /host/preferences
          - /host/preferences/image
          - /host_approval/app_config/token/[0-9a-f-]{36}
          - /host_approval/slack/[0-9a-f-]{36}/
          - /host_approval/token/[0-9a-f-]{36}
          - /host_portal/app_config
          - /host_portal/logout
          - /host_portal/magic_link/redeem
          - /host_portal/magic_link/request
          - /host_portal/ping
          - /internal/document/media_convert_job
          - /internal/guest/trial/site/[0-9a-f-]{36}
          - /internal/invite
          - /internal/mailroom/trial/site/[0-9a-f-]{36}
          - /internal/org/[0-9a-f-]{36}
          - /invite_guest/host_portal/event/[0-9a-f-]{36}
          - /invite_guest/host_portal/org/[0-9a-f-]{36}/csv/parse
          - /notifications/callback/[a-z0-9]{32}
          - /notifications/email_status
          - /notifications/pinpoint_sms
          - /notifications/pinpoint_sms/mailroom
          - /notifications/pinpoint_sms/v2
          - /org/quickstart
          - /outlook/guest
          - /outlook/guest/fetch
          - /outlook/guest/signout
          - /package/[0-9a-f-]{36}/photo
          - /package/email/not_mine/[0-9a-f-]{36}
          - /package/email/pickup/[0-9a-f-]{36}
          - /package/pickup/rfid/[A-Z0-9]{24}
          - /package/pickup/user/[0-9a-f-]{36}
          - /package/slack/[0-9a-f-]{36}/
          - /package_media/[0-9a-f-]{36}
          - /package_org/quickstart
          - /package_portal/employee
          - /package_portal/employee/[0-9a-f-]{36}
          - /package_portal/employee/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_portal/not_my
          - /package_portal/pickup
          - /package_portal/single/[0-9a-f-]{36}
          - /package_portal/single/[0-9a-f-]{36}/[0-9a-f-]{36}
          - /package_portal/single/[0-9a-f-]{36}/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /package_status/app_config/token/[0-9a-f-]{36}
          - /package_status/app_config/token/[0-9a-f-]{36}/(?i)[^/]*(large|small)+[^/]*
          - /packages/carriers
          - /packages/rfid_inventory
          - /packages/site/[0-9a-f-]{36}
          - /packages/slack/oauth_callback
          - /packages/teams/consent/callback
          - /packages_demo/config
          - /packages_demo/package/site/[0-9a-f-]{36}
          - /packages_demo/signature/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /pass/org/[0-9a-f-]{36}/apple
          - /pass/org/[0-9a-f-]{36}/google
          - /pass/v1/devices/[a-zA-Z0-9-]+/registrations/[\w\.\-]+
          - /pass/v1/devices/[a-zA-Z0-9-]+/registrations/[\w\.\-]+/[0-9a-f-]{36}
          - /pass/v1/passes/[\w\.\-]+/[0-9a-f-]{36}
          - /ping
          - /ping_env
          - /reception-app/magic-login/redeem
          - /registration_app_config/camera/[0-9a-f-]{36}/thumbnail
          - /registration_app_config/org/[0-9a-f-]{36}
          - /school/org/[0-9a-f-]{36}/verify
          - /slack/[0-9a-f-]{36}
          - /slack/oauth_callback
          - /student/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /teams/consent/callback
          - /twilio/webhook/[a-z0-9]{32}
          - /twilio/webhook/packages/[a-z0-9]{32}
          - /unauthed_feature_flags
          - /visit/fastpass/org/[0-9a-f-]{36}
          - /visit/invited/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/search
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visit/[0-9a-f-]{36}/check_in
          - /visit/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /visit/photo/redirect/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/return/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/signed_in/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/signout/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}
          - /visit/v2/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/visitor_type_id/[0-9a-f-]{36}
          - /visit/v2/return/org/[0-9a-f-]{36}/site/[0-9a-f-]{36}/vt/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vdoorman
    namespace: vinfra
    resourceVersion: "2442330994"
    uid: 7f8473f6-ace6-4bd4-a932-e419dae086f7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vdoormansocket.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /subscribe
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vdoormansocket
    namespace: vinfra
    resourceVersion: "2158702260"
    uid: 055ff29d-ea91-4d36-957f-895252109d47
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vecho.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vecho
    namespace: vinfra
    resourceVersion: "2158702254"
    uid: 2efce7a6-755a-4d13-9676-75c6654bf201
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vemr.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /adt_update/status/org_id/[0-9a-f-]{36}
          - /patients/site/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /internal/adt_update
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vemr
    namespace: vinfra
    resourceVersion: "2158702274"
    uid: 0cdc6e2c-b5b5-4f8a-99bf-f392de9367bd
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: veventsock.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /user/listen_unseen_alert_counts/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-veventsock
    namespace: vinfra
    resourceVersion: "2158702271"
    uid: 958a652d-51c4-4e6d-96aa-a150c0abe5e4
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vexplore.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /cross_shard/accounting/balance
          - /cross_shard/accounting/history
          - /cross_shard/accounting/history/csv
          - /cross_shard/accounting/income
          - /cross_shard/alarm/status
          - /cross_shard/camera/status
          - /cross_shard/download_org_users
          - /cross_shard/get_org_by_short_name
          - /cross_shard/get_org_licensing_exemption_status
          - /cross_shard/license
          - /cross_shard/license/burn
          - /cross_shard/license/children
          - /cross_shard/license/claim
          - /cross_shard/license/claim/dryrun
          - /cross_shard/license/grant
          - /cross_shard/license/grant/dryrun
          - /cross_shard/license/history
          - /cross_shard/license/history/csv
          - /cross_shard/license/run_cohort_emails
          - /cross_shard/license/send_expired_email_to_target_orgs
          - /cross_shard/license/split
          - /cross_shard/license/trials
          - /cross_shard/license/unclaim
          - /cross_shard/license/update_job_schedule
          - /cross_shard/license/void
          - /cross_shard/licensing/org/[0-9a-f-]{36}/trials
          - /cross_shard/list_orders
          - /cross_shard/logistics/get_organization_info
          - /cross_shard/logistics/skus
          - /cross_shard/models/list
          - /cross_shard/modify_license_exemption
          - /cross_shard/order
          - /cross_shard/order/csv
          - /cross_shard/order_count
          - /cross_shard/org/[0-9a-f-]{36}/privacy_disclosure
          - /cross_shard/org/[0-9a-f-]{36}/privacy_disclosures
          - /cross_shard/org/get
          - /cross_shard/org/streaming/metrics
          - /cross_shard/org/toggle_internal_status
          - /cross_shard/org_alarms
          - /cross_shard/org_cameras
          - /cross_shard/org_contacts
          - /cross_shard/org_intercoms
          - /cross_shard/org_lockout_status/[0-9a-f-]{36}
          - /cross_shard/org_sensors
          - /cross_shard/org_stats
          - /cross_shard/org_users
          - /cross_shard/organization/license
          - /cross_shard/query_cameras
          - /cross_shard/query_orders
          - /cross_shard/query_orgs
          - /cross_shard/query_users
          - /cross_shard/query_uuid
          - /cross_shard/retention/org/[0-9a-f-]{36}
          - /cross_shard/sensor/status
          - /cross_shard/supplychain/order_search
          - /cross_shard/user/get_orgs
          - /cross_shard/v3/license/grant
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vexplore
    namespace: vinfra
    resourceVersion: "2390095550"
    uid: 889a40f8-c3a6-4960-8474-d34a5f2fa7ac
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/export/bulk/start
          - /library/export/delete
          - /library/export/detected_objects
          - /library/export/download
          - /library/export/grid_[0-9]+\.jpg
          - /library/export/label/set
          - /library/export/list
          - /library/export/list/metadata
          - /library/export/list/organization
          - /library/export/list/tags
          - /library/export/list/user
          - /library/export/multi/start
          - /library/export/public/set
          - /library/export/share
          - /library/export/start
          - /library/export/status
          - /library/export/statuses
          - /library/export/stop
          - /library/export/tags/set
          - /library/export/thumb\.jpg
        unauthenticatedEndpoints:
          - /archive/verify
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/export/bulk/start
          - /library/export/delete
          - /library/export/detected_objects
          - /library/export/download
          - /library/export/grid_[0-9]+\.jpg
          - /library/export/label/set
          - /library/export/list
          - /library/export/list/metadata
          - /library/export/list/organization
          - /library/export/list/tags
          - /library/export/list/user
          - /library/export/multi/start
          - /library/export/public/set
          - /library/export/share
          - /library/export/start
          - /library/export/status
          - /library/export/statuses
          - /library/export/stop
          - /library/export/tags/set
          - /library/export/thumb\.jpg
        unauthenticatedEndpoints:
          - /archive/verify
      - host: vexport.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vexport
    namespace: vinfra
    resourceVersion: "2158702299"
    uid: 6fffc81f-5830-41dc-9d8d-4d8d58be3272
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /feature_flags/init
        unauthenticatedEndpoints:
          - /corp_tools/feature_flags/tools_init
          - /feature_flags/device_init
          - /feature_flags/get_all
          - /feature_flags/guest_init
          - /feature_flags/init_layer
          - /feature_flags/set_used
          - /tools/feature_flags/tools_init
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /feature_flags/init
        unauthenticatedEndpoints:
          - /corp_tools/feature_flags/tools_init
          - /feature_flags/device_init
          - /feature_flags/get_all
          - /feature_flags/guest_init
          - /feature_flags/init_layer
          - /feature_flags/set_used
          - /tools/feature_flags/tools_init
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /feature_flags/init
        unauthenticatedEndpoints:
          - /corp_tools/feature_flags/tools_init
          - /feature_flags/device_init
          - /feature_flags/get_all
          - /feature_flags/guest_init
          - /feature_flags/init_layer
          - /feature_flags/set_used
          - /tools/feature_flags/tools_init
      - host: vfeatureflag.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /feature_flags/get_all
          - /feature_flags/init
          - /ping
        unauthenticatedEndpoints:
          - /feature_flags/device_init
          - /feature_flags/guest_init
          - /feature_flags/init_layer
          - /feature_flags/set_used
      - host: vfeatureflag.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /feature_flags/get_all
          - /feature_flags/set_used
          - /internal/fanout/feature_flags/get_ready_for_permanent_deletion
          - /internal/fanout/feature_flags/get_ready_for_soft_deletion
          - /internal/feature_flags/is_feature_flag_enabled
          - /shortnames/get_all
          - /tools/feature_flags/add_child
          - /tools/feature_flags/create
          - /tools/feature_flags/create_rollout
          - /tools/feature_flags/delete
          - /tools/feature_flags/delete_rollout
          - /tools/feature_flags/device
          - /tools/feature_flags/email
          - /tools/feature_flags/get_audit_logs
          - /tools/feature_flags/get_children
          - /tools/feature_flags/get_entities_for_flag
          - /tools/feature_flags/get_exemption_feature_flags
          - /tools/feature_flags/get_exemption_list
          - /tools/feature_flags/get_feature_flag
          - /tools/feature_flags/get_parents
          - /tools/feature_flags/get_rollout_custom_group
          - /tools/feature_flags/get_rollout_custom_group_preview
          - /tools/feature_flags/get_rollout_group
          - /tools/feature_flags/get_rollout_group_preview
          - /tools/feature_flags/get_rollout_metadata
          - /tools/feature_flags/get_rollout_status
          - /tools/feature_flags/get_soft_deleted
          - /tools/feature_flags/organization
          - /tools/feature_flags/remove_child
          - /tools/feature_flags/set_exemption_list
          - /tools/feature_flags/set_feature_flag
          - /tools/feature_flags/set_feature_flag_minimum_version
          - /tools/feature_flags/set_global_feature_flag
          - /tools/feature_flags/set_rollout_group
          - /tools/feature_flags/set_sample_size
          - /tools/feature_flags/set_shard_feature_flag
          - /tools/feature_flags/shortnames/add
          - /tools/feature_flags/shortnames/check_available
          - /tools/feature_flags/sync
          - /tools/feature_flags/update_metadata
          - /tools/feature_flags/update_team_name
          - /tools/feature_flags/user
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vfeatureflag
    namespace: vinfra
    resourceVersion: "2459366580"
    uid: 783d789c-a5d9-42fe-96a4-54db154d2407
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vfilter.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/avmux/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/avmux/[\w\-. +%]+
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/stream/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. +%]+
        unauthenticatedEndpoints:
          - /filter/avmux/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vfilter
    namespace: vinfra
    resourceVersion: "2383832389"
    uid: 4bdbd742-5ff5-4380-b506-34529c59e5be
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vfleetmgmt.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /internal/camera/firmware-version/config
          - /internal/camera/healthstatus
          - /internal/validate
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vfleetmgmt
    namespace: vinfra
    resourceVersion: "2158702329"
    uid: f01ceaaa-d11d-427c-b96c-6aa14cf86e16
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /flow/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /flow/ping
      - host: vstream.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /flow/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /flow/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vflow
    namespace: vinfra
    resourceVersion: "2158702352"
    uid: 2364ff92-1a01-4d76-8819-f28e393d11c8
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /floorplans/legacy/features
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /floorplans/legacy/features
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /floorplans/legacy/features
      - host: vfootprint.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /floorplans
          - /floorplans/[0-9a-f-]{36}/image
          - /floorplans/cameras/[0-9a-f-]{36}/calibration/images
          - /floorplans/cameras/[0-9a-f-]{36}/calibration/status
          - /floorplans/cameras/[0-9a-f-]{36}/motion-history
          - /floorplans/floorplan
          - /floorplans/legacy/features
          - /floorplans/orgs
          - /floorplans/orgs/[0-9a-f-]{36}
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/[0-9a-f-]{36}
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/[0-9a-f-]{36}/
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/transformation-matrix
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floorplans/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/transformation-matrix/submit
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floors/[0-9a-f-]{36}/
          - /floorplans/orgs/[0-9a-f-]{36}/buildings/[0-9a-f-]{36}/floors/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/location
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vfootprint
    namespace: vinfra
    resourceVersion: "2417982184"
    uid: d7f26179-b54c-4027-87f1-062dfcc16fee
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vfortress/box/add_camera
          - /vfortress/box/get_pcap
          - /vfortress/box/reboot
          - /vfortress/box/remove_all_cameras
          - /vfortress/box/remove_camera
          - /vfortress/box/self
          - /vfortress/box/set_static_ip
          - /vfortress/box/update_cameras
          - /vfortress/camera/check_credentials
          - /vfortress/camera/get_retention
          - /vfortress/camera/get_snapshots
          - /vfortress/camera/get_stream_profiles
          - /vfortress/camera/save_local_data
          - /vfortress/camera/set_disk_size
          - /vfortress/camera/set_retention
          - /vfortress/cameras/list/box
          - /vfortress/cameras/list/org
          - /vfortress/commission
          - /vfortress/decommission
          - /vfortress/discovery
          - /vfortress/get_box
          - /vfortress/list_boxes
          - /vfortress/sensor/config/get
          - /vfortress/sensor/config/set
          - /vfortress/sensor/force_reconfigure
          - /vfortress/update_box
          - /vfortress/update_boxes
          - /vfortress/ws
        unauthenticatedEndpoints:
          - /vfortress/ping
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vfortress/box/add_camera
          - /vfortress/box/get_pcap
          - /vfortress/box/reboot
          - /vfortress/box/remove_all_cameras
          - /vfortress/box/remove_camera
          - /vfortress/box/self
          - /vfortress/box/set_static_ip
          - /vfortress/box/update_cameras
          - /vfortress/camera/check_credentials
          - /vfortress/camera/get_retention
          - /vfortress/camera/get_snapshots
          - /vfortress/camera/get_stream_profiles
          - /vfortress/camera/save_local_data
          - /vfortress/camera/set_disk_size
          - /vfortress/camera/set_retention
          - /vfortress/cameras/list/box
          - /vfortress/cameras/list/org
          - /vfortress/commission
          - /vfortress/decommission
          - /vfortress/discovery
          - /vfortress/get_box
          - /vfortress/list_boxes
          - /vfortress/sensor/config/get
          - /vfortress/sensor/config/set
          - /vfortress/sensor/force_reconfigure
          - /vfortress/update_box
          - /vfortress/update_boxes
          - /vfortress/ws
        unauthenticatedEndpoints:
          - /vfortress/ping
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vfortress/box/add_camera
          - /vfortress/box/get_pcap
          - /vfortress/box/reboot
          - /vfortress/box/remove_all_cameras
          - /vfortress/box/remove_camera
          - /vfortress/box/self
          - /vfortress/box/set_static_ip
          - /vfortress/box/update_cameras
          - /vfortress/camera/check_credentials
          - /vfortress/camera/get_retention
          - /vfortress/camera/get_snapshots
          - /vfortress/camera/get_stream_profiles
          - /vfortress/camera/save_local_data
          - /vfortress/camera/set_disk_size
          - /vfortress/camera/set_retention
          - /vfortress/cameras/list/box
          - /vfortress/cameras/list/org
          - /vfortress/commission
          - /vfortress/decommission
          - /vfortress/discovery
          - /vfortress/get_box
          - /vfortress/list_boxes
          - /vfortress/sensor/config/get
          - /vfortress/sensor/config/set
          - /vfortress/sensor/force_reconfigure
          - /vfortress/update_box
          - /vfortress/update_boxes
          - /vfortress/ws
        unauthenticatedEndpoints:
          - /vfortress/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vfortress
    namespace: vinfra
    resourceVersion: "2459366576"
    uid: 05cf0d69-11ef-4ff5-a104-cfe816840346
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vguard.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /datadog/e2e_health_check
          - /web/cameras_set
          - /web/create_guard
          - /web/create_guard_doors
          - /web/delete_guard
          - /web/delete_guard_doors
          - /web/doors_set
          - /web/get_incidents
          - /web/guard_camera_list
          - /web/guard_list
          - /web/guard_settings
          - /web/mute_camera
          - /web/pause_guard
          - /web/resolve_escalation
          - /web/resume_guard
          - /web/schedules_render
          - /web/schedules_set
          - /web/shift_details
          - /web/shift_end
          - /web/shift_list
          - /web/shift_start
          - /web/site_settings
          - /web/speakers_set
          - /web/unavailable_cameras
          - /web/unmute_camera
          - /web/update_guard
          - /web/update_guard_doors
        unauthenticatedEndpoints:
          - /ping
          - /web/guard_doors_list
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vguard
    namespace: vinfra
    resourceVersion: "2299874592"
    uid: 4ecab805-0e9c-49c3-98e1-9ab7383f1b18
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vhistory/camera/[0-9a-f-]{36}/connect
          - /vhistory/camera/vhs
          - /vhistory/client/vhs
          - /vhistory/media
          - /vhistory/media/[\w\-. +%]+
        unauthenticatedEndpoints:
          - /vhistory/internal/media/[\w\-. +%]+
          - /vhistory/ping
      - host: vstream.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vhistory/camera/[0-9a-f-]{36}/connect
          - /vhistory/camera/vhs
          - /vhistory/client/vhs
          - /vhistory/media
          - /vhistory/media/[\w\-. +%]+
        unauthenticatedEndpoints:
          - /vhistory/internal/media/[\w\-. +%]+
          - /vhistory/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vhistory
    namespace: vinfra
    resourceVersion: "2158702270"
    uid: 92692058-e241-4269-8334-4375c756948a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: videntity.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /identity/appearances
          - /identity/attribute/append
          - /identity/attribute/remove
          - /identity/bulk/get
          - /identity/bulk/upload
          - /identity/create
          - /identity/delete
          - /identity/frequent/get
          - /identity/get
          - /identity/image/create
          - /identity/image/delete
          - /identity/list
          - /identity/merge
          - /identity/search/events
          - /identity/strangers/get
          - /identity/unmerge
          - /identity/update
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-videntity
    namespace: vinfra
    resourceVersion: "2416989520"
    uid: ab8a9e06-00e9-4253-a56d-72f652014c3a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vimagetuner.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device/capture_raw
          - /device/capture_yuv
          - /device/configure_development
          - /device/get_shutter_gain
          - /device/override_iq/get
          - /device/override_iq/set
          - /device/remote_shell
          - /device/replace_iq_binaries
          - /device/set_ae_lines
          - /device/set_ae_lines_hdr
          - /device/start_amage_server
          - /ping
          - /tune
          - /utils/compile_iq_binaries
          - /utils/ituner_to_c
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vimagetuner
    namespace: vinfra
    resourceVersion: "2158702296"
    uid: db5dd2d2-f6e3-4bdd-8cf9-630d04bda185
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vinnout.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /client/areas/[0-9a-f-]{36}
          - /client/areas/[0-9a-f-]{36}/users/[0-9a-f-]{36}/location
          - /client/areas/[0-9a-f-]{36}/users/[0-9a-f-]{36}/violation
          - /client/users/[0-9a-f-]{36}
          - /device/events
          - /device/status
          - /device/wss
        unauthenticatedEndpoints:
          - /ping
      - host: vcerberus.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinnout/device/events
          - /vinnout/device/status
          - /vinnout/device/wss
      - host: access.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinnout/device/events
          - /vinnout/device/status
          - /vinnout/device/wss
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vinnout
    namespace: vinfra
    resourceVersion: "2158702282"
    uid: 74d1ee7d-165a-43c5-91ff-2d51d2d53743
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinter/v1/device/desk/away
          - /vinter/v1/device/desk/batch_telemetry
          - /vinter/v1/device/desk/config
          - /vinter/v1/device/desk/remote_unlock
          - /vinter/v1/device/desk/single_telemetry
          - /vinter/v1/device/desk/twilio/access_token
          - /vinter/v1/device/desk/user/[0-9a-f-]{36}/photo/[\w\-. +%]+
          - /vinter/v1/device/intercom/audio_files
          - /vinter/v1/device/intercom/batch_telemetry
          - /vinter/v1/device/intercom/config
          - /vinter/v1/device/intercom/local_sip_account_registration_status
          - /vinter/v1/device/intercom/raw_event
          - /vinter/v1/device/intercom/remote_unlock
          - /vinter/v1/device/intercom/single_telemetry
          - /vinter/v1/device/intercom/sound_link
          - /vinter/v1/device/intercom/status
          - /vinter/v1/device/intercom/vmeerkat_status
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/batch/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/audio_file
          - /vinter/v1/user/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/disable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/enable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/reset
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/new_call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_targets
          - /vinter/v1/user/organization/[0-9a-f-]{36}/dashboard
          - /vinter/v1/user/organization/[0-9a-f-]{36}/desk/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/events
          - /vinter/v1/user/organization/[0-9a-f-]{36}/generate_report
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/approach
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/checks
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_type
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/emergency_phone
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/initiate_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/location
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound_upload
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_tts
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/reboot
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/un_hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/is_pass_active
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/sip_registration_status
          - /vinter/v1/user/organization/[0-9a-f-]{36}/telemetry_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/command_app_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/web_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/user_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/web_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/intercom
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/remote_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/twilio/access_token
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/twilio/access_token
        unauthenticatedEndpoints:
          - /vinter/call/ping
          - /vinter/device/ping
          - /vinter/internal/ping
          - /vinter/ping
          - /vinter/poll/ping
          - /vinter/status_test
          - /vinter/transient/1/ping
          - /vinter/transient/2/ping
          - /vinter/transient/3/ping
          - /vinter/transient/4/ping
          - /vinter/transient/5/ping
          - /vinter/transient/ping
          - /vinter/unlock/ping
          - /vinter/user/ping
          - /vinter/v1/device/desk/serial_number
          - /vinter/v1/external/livekit/webhook/all
          - /vinter/v1/external/twilio/intercom_call
          - /vinter/v1/external/twilio/intercom_call_status
          - /vinter/v1/external/twilio/receiver_call
          - /vinter/v1/external/twilio/receiver_call_status
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinter/v1/device/desk/away
          - /vinter/v1/device/desk/batch_telemetry
          - /vinter/v1/device/desk/config
          - /vinter/v1/device/desk/remote_unlock
          - /vinter/v1/device/desk/single_telemetry
          - /vinter/v1/device/desk/twilio/access_token
          - /vinter/v1/device/desk/user/[0-9a-f-]{36}/photo/[\w\-. +%]+
          - /vinter/v1/device/intercom/audio_files
          - /vinter/v1/device/intercom/batch_telemetry
          - /vinter/v1/device/intercom/config
          - /vinter/v1/device/intercom/local_sip_account_registration_status
          - /vinter/v1/device/intercom/raw_event
          - /vinter/v1/device/intercom/remote_unlock
          - /vinter/v1/device/intercom/single_telemetry
          - /vinter/v1/device/intercom/sound_link
          - /vinter/v1/device/intercom/status
          - /vinter/v1/device/intercom/vmeerkat_status
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/batch/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/audio_file
          - /vinter/v1/user/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/disable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/enable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/reset
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/new_call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_targets
          - /vinter/v1/user/organization/[0-9a-f-]{36}/dashboard
          - /vinter/v1/user/organization/[0-9a-f-]{36}/desk/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/events
          - /vinter/v1/user/organization/[0-9a-f-]{36}/generate_report
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/approach
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/checks
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_type
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/emergency_phone
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/initiate_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/location
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound_upload
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_tts
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/reboot
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/un_hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/is_pass_active
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/sip_registration_status
          - /vinter/v1/user/organization/[0-9a-f-]{36}/telemetry_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/command_app_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/web_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/user_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/web_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/intercom
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/remote_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/twilio/access_token
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/twilio/access_token
        unauthenticatedEndpoints:
          - /vinter/call/ping
          - /vinter/device/ping
          - /vinter/internal/ping
          - /vinter/ping
          - /vinter/poll/ping
          - /vinter/status_test
          - /vinter/transient/1/ping
          - /vinter/transient/2/ping
          - /vinter/transient/3/ping
          - /vinter/transient/4/ping
          - /vinter/transient/5/ping
          - /vinter/transient/ping
          - /vinter/unlock/ping
          - /vinter/user/ping
          - /vinter/v1/device/desk/serial_number
          - /vinter/v1/external/livekit/webhook/all
          - /vinter/v1/external/twilio/intercom_call
          - /vinter/v1/external/twilio/intercom_call_status
          - /vinter/v1/external/twilio/receiver_call
          - /vinter/v1/external/twilio/receiver_call_status
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vinter/v1/device/desk/away
          - /vinter/v1/device/desk/batch_telemetry
          - /vinter/v1/device/desk/config
          - /vinter/v1/device/desk/remote_unlock
          - /vinter/v1/device/desk/single_telemetry
          - /vinter/v1/device/desk/twilio/access_token
          - /vinter/v1/device/desk/user/[0-9a-f-]{36}/photo/[\w\-. +%]+
          - /vinter/v1/device/intercom/audio_files
          - /vinter/v1/device/intercom/batch_telemetry
          - /vinter/v1/device/intercom/config
          - /vinter/v1/device/intercom/local_sip_account_registration_status
          - /vinter/v1/device/intercom/raw_event
          - /vinter/v1/device/intercom/remote_unlock
          - /vinter/v1/device/intercom/single_telemetry
          - /vinter/v1/device/intercom/sound_link
          - /vinter/v1/device/intercom/status
          - /vinter/v1/device/intercom/vmeerkat_status
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/async/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/batch/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/audio_file
          - /vinter/v1/user/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/disable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/enable
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}/reset
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_schedule/new_call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/call_targets
          - /vinter/v1/user/organization/[0-9a-f-]{36}/dashboard
          - /vinter/v1/user/organization/[0-9a-f-]{36}/desk/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/device/[0-9a-f-]{36}/call_sequence/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/events
          - /vinter/v1/user/organization/[0-9a-f-]{36}/generate_report
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/approach
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/checks
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/door_type
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/emergency_phone
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/initiate_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/location
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_sound_upload
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/play_tts
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/reboot
          - /vinter/v1/user/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/un_hold_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/is_pass_active
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings
          - /vinter/v1/user/organization/[0-9a-f-]{36}/settings/audio_message
          - /vinter/v1/user/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/organization/[0-9a-f-]{36}/sip_registration_status
          - /vinter/v1/user/organization/[0-9a-f-]{36}/telemetry_call
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/command_app_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/twilio/web_access_token
          - /vinter/v1/user/organization/[0-9a-f-]{36}/user_config
          - /vinter/v1/user/organization/[0-9a-f-]{36}/web_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/batch_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/intercom
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/remote_unlock
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/single_telemetry
          - /vinter/v1/user/pass/organization/[0-9a-f-]{36}/twilio/access_token
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/call_schedule/[0-9a-f-]{36}
          - /vinter/v1/user/transition/organization/[0-9a-f-]{36}/intercom/[0-9a-f-]{36}/call_schedule
          - /vinter/v1/user/twilio/access_token
        unauthenticatedEndpoints:
          - /vinter/call/ping
          - /vinter/device/ping
          - /vinter/internal/ping
          - /vinter/ping
          - /vinter/poll/ping
          - /vinter/status_test
          - /vinter/transient/1/ping
          - /vinter/transient/2/ping
          - /vinter/transient/3/ping
          - /vinter/transient/4/ping
          - /vinter/transient/5/ping
          - /vinter/transient/ping
          - /vinter/unlock/ping
          - /vinter/user/ping
          - /vinter/v1/device/desk/serial_number
          - /vinter/v1/external/livekit/webhook/all
          - /vinter/v1/external/twilio/intercom_call
          - /vinter/v1/external/twilio/intercom_call_status
          - /vinter/v1/external/twilio/receiver_call
          - /vinter/v1/external/twilio/receiver_call_status
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vinter
    namespace: vinfra
    resourceVersion: "2417982186"
    uid: cae76988-39bd-4134-aa5a-a9bec17af74a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vinvestigate.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /evidence/archive/create
          - /evidence/archive/delete
          - /evidence/archive/get
          - /evidence/archive/objects_in_range
          - /evidence/archive/update
          - /evidence/archive_info/get
          - /evidence/bulk/status
          - /evidence/delete
          - /evidence/event/create
          - /evidence/hyperzoom/delete
          - /evidence/library/archive/enckey
          - /evidence/library/archive/init\.mp4
          - /evidence/library/archive/playlist\.m3u8
          - /evidence/library/archive/thumb\.jpg
          - /evidence/library/archive/video\.m4s
          - /evidence/library/hyperzoom\.jpg
          - /evidence/list
          - /incident/bulk/preview
          - /incident/change_logs/list
          - /incident/count
          - /incident/create
          - /incident/delete
          - /incident/download
          - /incident/download/status
          - /incident/external_token/get
          - /incident/get
          - /incident/list
          - /incident/share
          - /incident/share/list
          - /incident/share/list/v2
          - /incident/share/revoke
          - /incident/share/revoke/v2
          - /incident/share/v2
          - /incident/update
          - /prompt/event_search
          - /prompt/motion_intervals
          - /prompt/motion_search
          - /prompt/search
        unauthenticatedEndpoints:
          - /incident/external_token/redeem
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vinvestigate
    namespace: vinfra
    resourceVersion: "2158702298"
    uid: 8f75fc66-9a74-495e-997f-697400aa12b0
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vkms/device/store_sharing_key
          - /vkms/e2ee/convert_camera_to_e2ee
          - /vkms/e2ee/convert_camera_to_e2ee/batch
          - /vkms/e2ee/convert_camera_to_traditional
          - /vkms/e2ee/delete_association
          - /vkms/e2ee/delete_non_verified_init_keys
          - /vkms/e2ee/get_key_policy_file/latest
          - /vkms/e2ee/get_key_policy_files
          - /vkms/e2ee/get_key_policy_files/latest
          - /vkms/e2ee/init_keys
          - /vkms/e2ee/init_keys_backfill
          - /vkms/e2ee/retrieve_keys
          - /vkms/e2ee/retrieve_live_link_key
          - /vkms/e2ee/set_association
          - /vkms/e2ee/store_key_policy_file
          - /vkms/e2ee/store_verification_info
          - /vkms/e2ee/support_token_key/set
          - /vkms/e2ee/vendor_envelope_key/[0-9a-f-]{36}
          - /vkms/external_envelope_key/[0-9a-f-]{36}/[0-9]+
          - /vkms/external_envelope_keys/lookup
          - /vkms/retrieve_camera_envelope_keys
          - /vkms/retrieve_cameras_ece_status
          - /vkms/unlock_media_keys
          - /vkms/user/camera/retrieve_sharing_key
          - /vkms/verify_kms_access/[0-9a-f-]{36}
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vkms/device/store_sharing_key
          - /vkms/e2ee/convert_camera_to_e2ee
          - /vkms/e2ee/convert_camera_to_e2ee/batch
          - /vkms/e2ee/convert_camera_to_traditional
          - /vkms/e2ee/delete_association
          - /vkms/e2ee/delete_non_verified_init_keys
          - /vkms/e2ee/get_key_policy_file/latest
          - /vkms/e2ee/get_key_policy_files
          - /vkms/e2ee/get_key_policy_files/latest
          - /vkms/e2ee/init_keys
          - /vkms/e2ee/init_keys_backfill
          - /vkms/e2ee/retrieve_keys
          - /vkms/e2ee/retrieve_live_link_key
          - /vkms/e2ee/set_association
          - /vkms/e2ee/store_key_policy_file
          - /vkms/e2ee/store_verification_info
          - /vkms/e2ee/support_token_key/set
          - /vkms/e2ee/vendor_envelope_key/[0-9a-f-]{36}
          - /vkms/external_envelope_key/[0-9a-f-]{36}/[0-9]+
          - /vkms/external_envelope_keys/lookup
          - /vkms/retrieve_camera_envelope_keys
          - /vkms/retrieve_cameras_ece_status
          - /vkms/unlock_media_keys
          - /vkms/user/camera/retrieve_sharing_key
          - /vkms/verify_kms_access/[0-9a-f-]{36}
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vkms/device/store_sharing_key
          - /vkms/e2ee/convert_camera_to_e2ee
          - /vkms/e2ee/convert_camera_to_e2ee/batch
          - /vkms/e2ee/convert_camera_to_traditional
          - /vkms/e2ee/delete_association
          - /vkms/e2ee/delete_non_verified_init_keys
          - /vkms/e2ee/get_key_policy_file/latest
          - /vkms/e2ee/get_key_policy_files
          - /vkms/e2ee/get_key_policy_files/latest
          - /vkms/e2ee/init_keys
          - /vkms/e2ee/init_keys_backfill
          - /vkms/e2ee/retrieve_keys
          - /vkms/e2ee/retrieve_live_link_key
          - /vkms/e2ee/set_association
          - /vkms/e2ee/store_key_policy_file
          - /vkms/e2ee/store_verification_info
          - /vkms/e2ee/support_token_key/set
          - /vkms/e2ee/vendor_envelope_key/[0-9a-f-]{36}
          - /vkms/external_envelope_key/[0-9a-f-]{36}/[0-9]+
          - /vkms/external_envelope_keys/lookup
          - /vkms/retrieve_camera_envelope_keys
          - /vkms/retrieve_cameras_ece_status
          - /vkms/unlock_media_keys
          - /vkms/user/camera/retrieve_sharing_key
          - /vkms/verify_kms_access/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vkms
    namespace: vinfra
    resourceVersion: "2463023277"
    uid: 1f5a9f31-da95-49ca-8e06-a66b807ab6a5
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlicensing.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device/batch/information
          - /health_check
          - /job/status
          - /license
          - /license/claim
          - /license/claim/dryrun
          - /license/history
          - /license/trials
          - /license_exemption/add_orgs
          - /license_exemption/organization/[0-9a-f-]{36}
          - /license_exemption/organizations
          - /licensing/org/[0-9a-f-]{36}/trials
          - /licensing/org/[0-9a-f-]{36}/trials/software
          - /licensing/org/[0-9a-f-]{36}/trials/software/[0-9a-f-]{36}/conversion
          - /logistics/get_organization_info
          - /logistics/org/[0-9a-f-]{36}/customer
          - /order/claim_order
          - /order/details
          - /order/unclaim_order
          - /org/[0-9a-f-]{36}/get_device_counts
          - /organization/license
          - /ping
          - /v2/order/details
        unauthenticatedEndpoints:
          - /health_check
          - /internal/device/batch/information
          - /internal/logistics/get_organization_info
          - /license/update_job_schedule
          - /licensing/org/[0-9a-f-]{36}/get_compliance_info
          - /order
          - /order/boomi/create_order
          - /order/netsuite/run
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vlicensing
    namespace: vinfra
    resourceVersion: "2158702169"
    uid: 0c61b7f7-df84-4bd2-8839-10da742ebfaf
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlive.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alert_groups/create
          - /alert_groups/delete
          - /alert_groups/get
          - /alert_groups/move
          - /alert_groups/star
          - /alert_groups/unstar
          - /alert_groups/update
          - /alert_rules/create
          - /alert_rules/delete
          - /alert_rules/get
          - /alert_rules/mute_preference/delete
          - /alert_rules/mute_preference/get
          - /alert_rules/mute_preference/set
          - /alert_rules/update
          - /alerts/enable_user_mobile_alert
          - /alerts/get
          - /alerts/get_unseen_alert_counts
          - /alerts/get_user_alert_preferences
          - /alerts/mark_alert_rules_seen
          - /alerts/update_alert_metadata
          - /device/new_events_fw/update
          - /device/presets/create_default
          - /device/presets/create_default/batch
          - /device/presets/get
          - /device/presets/get/batch
          - /device/presets/update
          - /device/presets/update/batch
          - /device/tamper/create_default
          - /live_link/create
          - /live_link/get
          - /migration/presets/clean_unused
          - /org/events/get
          - /ping
          - /push_token/update_state
          - /slack/config/delete
          - /slack/enabled/get
          - /slack/oauth/authorize/get
          - /teams/config/delete
          - /teams/enabled/get
          - /teams/oauth/authorize/get
          - /view/get_event_info
        unauthenticatedEndpoints:
          - /notifications/location_map
          - /slack/oauth/callback
          - /teams/bot/callback
          - /teams/oauth/callback
          - /token_force_logout
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vlive
    namespace: vinfra
    resourceVersion: "2413040061"
    uid: 648f79f8-a08a-4387-a745-ec3c4f6fae33
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlocaldns.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /ping
          - /v1/[0-9a-f-]{36}/redirect
          - /v1/[0-9a-f-]{36}/url
          - /v1/[A-Z0-9-]{14}/redirect
          - /v1/[A-Z0-9-]{14}/url
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vlocaldns
    namespace: vinfra
    resourceVersion: "2158702163"
    uid: 115050fd-9d88-4bdc-bd95-ed31f071258b
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlog.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /audit-log/details
          - /audit-log/event-hierarchy
          - /audit-log/event-types
          - /audit-log/export
          - /audit-log/list
          - /audit-log/message-codes
          - /audit-logs/cameras/get
          - /operations/list
        unauthenticatedEndpoints:
          - /openapi\.json
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vlog
    namespace: vinfra
    resourceVersion: "2158702216"
    uid: 806bbfdc-08c7-4b55-b944-535ab2855f7b
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vlogging.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /logging/camera_status/[0-9a-f-]{36}
          - /logging/mobile_events
          - /logging/web_events
          - /logging/web_events/
        unauthenticatedEndpoints:
          - /access-ble-logs
          - /access-ble-logs/
          - /alarm-v2-logs
          - /alarm-v2-logs/
          - /api-metrics
          - /api-metrics/
          - /connect-box-logs
          - /connect-box-logs/
          - /core-command-logs
          - /core-command-logs/
          - /core-command-logs/api/v2/logs
          - /core-command-logs/api/v2/logs/
          - /datadog_events
          - /datadog_events/api/v2/rum
          - /datadog_events/api/v2/rum/
          - /desk-station-logs
          - /desk-station-logs/
          - /device-metrics
          - /device-metrics/
          - /internal/web/build-analytics
          - /internal/web/build-analytics/
          - /logging/camera_log
          - /logs/intercom-relay
          - /logs/intercom-relay/
          - /logs/relay
          - /ping
          - /ptz
          - /ptz/
          - /public-api-metrics
          - /public-api-metrics/
          - /security-logs
          - /security-logs/
          - /verkada-linux-logs
          - /verkada-linux-logs/
          - /vhecate-data-access-logs
          - /vhecate-data-access-logs/
          - /webrtc-statistics
          - /webrtc-statistics/
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /alarm-v2-logs
          - /alarm-v2-logs/
          - /connect-box-logs
          - /connect-box-logs/
          - /desk-station-logs
          - /desk-station-logs/
          - /device-metrics
          - /device-metrics/
          - /logs/relay
          - /logs/relay/
          - /verkada-linux-logs
          - /verkada-linux-logs/
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /alarm-v2-logs
          - /alarm-v2-logs/
          - /connect-box-logs
          - /connect-box-logs/
          - /desk-station-logs
          - /desk-station-logs/
          - /device-metrics
          - /device-metrics/
          - /logs/relay
          - /logs/relay/
          - /verkada-linux-logs
          - /verkada-linux-logs/
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /alarm-v2-logs
          - /alarm-v2-logs/
          - /connect-box-logs
          - /connect-box-logs/
          - /desk-station-logs
          - /desk-station-logs/
          - /device-metrics
          - /device-metrics/
          - /logs/relay
          - /logs/relay/
          - /verkada-linux-logs
          - /verkada-linux-logs/
      - host: vcerberus.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /logs/intercom-relay
          - /logs/intercom-relay/
          - /logs/relay
          - /logs/relay/
      - host: access.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /logs/intercom-relay
          - /logs/intercom-relay/
          - /logs/relay
          - /logs/relay/
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vlogging
    namespace: vinfra
    resourceVersion: "2417982158"
    uid: f8ce9976-2812-4fa5-b3b9-e82130589fc7
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vmdm.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /
          - /MDMServiceConfig
          - /device/update_device_info
          - /device/update_serial_number
          - /mdm/checkin
          - /mdm/connect
          - /mdm/enroll
          - /push/[a-zA-Z0-9-]+
          - /scep
          - /v1/apps
          - /v1/blueprints
          - /v1/challenge
          - /v1/commands
          - /v1/config/certificate
          - /v1/dep-tokens
          - /v1/dep/account
          - /v1/dep/assign
          - /v1/dep/autoassigners
          - /v1/dep/devices
          - /v1/dep/profiles
          - /v1/dep/syncnow
          - /v1/devices
          - /v1/devices/[a-zA-Z0-9-]+/block
          - /v1/devices/[a-zA-Z0-9-]+/unblock
          - /v1/profiles
          - /v1/push/[a-zA-Z0-9-]+
          - /v1/users
          - /v1/vpp-tokens
          - /v1/vpp/apps
          - /v1/vpp/assets
          - /v1/vpp/licenses
          - /v1/vpp/metadata
          - /v1/vpp/serviceconfig
          - /vmdm-api/admin/command
          - /vmdm-api/admin/ensure_device_in_correct_state/all
          - /vmdm-api/admin/ensure_device_in_correct_state/enterprise
          - /vmdm-api/admin/get_device_command
          - /vmdm-api/admin/get_device_event
          - /vmdm-api/admin/get_device_info
          - /vmdm-api/admin/modify_device_profiles
          - /vmdm-api/admin/run_app_update
          - /vmdm-api/admin/run_enrollment_task
          - /vmdm-api/admin/set_device_verkada_serial_number
          - /vmdm-api/admin/set_is_development_device
          - /vmdm-api/admin/set_skip_single_app_mode
          - /vmdm-api/admin/set_use_enterprise_app
          - /vmdm-api/admin/update_application_config/all
          - /vmdm-api/device/request_shutdown
          - /vmdm-api/device/update_device_info
          - /vmdm-api/device/update_serial_number
          - /vmdm-api/ping
          - /vmdm-api/webhook
        unauthenticatedEndpoints:
          - /vmdm-api/device/latest_vx_version
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vmdm
    namespace: vinfra
    resourceVersion: "2158702234"
    uid: 626e04ee-dcdf-4752-b53d-edd148d53125
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/available
          - /library/enckey/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /library/gaps
          - /library/multivideo\.vkdae2ee
          - /library/video/size
          - /library/video\.m3u8
          - /library/video\.ts
          - /library/video\.vkdae2ee
          - /submit/enckey/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/[0-9]+
          - /submit/segments_batch/[0-9a-f-]{36}
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/available
          - /library/enckey/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /library/gaps
          - /library/multivideo\.vkdae2ee
          - /library/video/size
          - /library/video\.m3u8
          - /library/video\.ts
          - /library/video\.vkdae2ee
          - /submit/enckey/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/[0-9]+
          - /submit/segments_batch/[0-9a-f-]{36}
      - host: vmedia.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/available
          - /library/enckey/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /library/gaps
          - /library/get_hd_rate
          - /library/get_hd_segment_intervals
          - /library/get_next_hd_interval
          - /library/get_oldest_hd_interval
          - /library/video/size
          - /library/video\.m3u8
          - /library/video\.ts
          - /library/video\.vkdae2ee
          - /submit/segments/[0-9a-f-]{36}
          - /submit/segments/[0-9a-f-]{36}/[0-9]+
          - /submit/segments_batch/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /get_media_key
          - /get_video_segments
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vmedia
    namespace: vinfra
    resourceVersion: "2383832387"
    uid: b938fffe-08b4-4287-911b-8d25c9f22258
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vcerberus.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /meerkat/[0-9a-f-]{36}
          - /meerkat/local_player/[0-9a-f-]{36}
          - /meerkat/ping
          - /meerkat/relay
          - /meerkat/toggle_door
          - /meerkat/unlock_door
          - /meerkat/unlock_entities
      - host: access.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /meerkat/[0-9a-f-]{36}
          - /meerkat/local_player/[0-9a-f-]{36}
          - /meerkat/ping
          - /meerkat/relay
          - /meerkat/toggle_door
          - /meerkat/unlock_door
          - /meerkat/unlock_entities
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vmeerkat
    namespace: vinfra
    resourceVersion: "2158702236"
    uid: cccacbf5-c73c-4def-ab2f-7c0dae976333
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmetrics-collector/metrics/submit
        unauthenticatedEndpoints:
          - /vmetrics-collector/ping
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmetrics-collector/metrics/submit
        unauthenticatedEndpoints:
          - /vmetrics-collector/ping
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmetrics-collector/metrics/submit
        unauthenticatedEndpoints:
          - /vmetrics-collector/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vmetricscollector
    namespace: vinfra
    resourceVersion: "2417982160"
    uid: 32c54f62-4354-4215-ac25-b67fd73586dc
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmotion/replay
          - /vmotion/ws/motion
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmotion/replay
          - /vmotion/ws/motion
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vmotion/replay
          - /vmotion/ws/motion
      - host: vmotion.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /notifications/thumbnail
          - /ping
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /events/objects_by_track_id
          - /library/object_counts/beta
          - /library/object_search/v3
          - /library/objects_in_range/v3
        unauthenticatedEndpoints:
          - /internal/object_search/v3
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /events/objects_by_track_id
          - /library/object_counts/beta
          - /library/object_search/v3
          - /library/objects_in_range/v3
        unauthenticatedEndpoints:
          - /internal/object_search/v3
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vmotion
    namespace: vinfra
    resourceVersion: "2417982131"
    uid: 4006691b-ddc8-4493-9023-e5ea44fac573
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vnet.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /activity_logs/[0-9a-f-]{36}
          - /bluetooth/fetch_info
          - /bluetooth/fetch_networks/[0-9a-f-]{36}
          - /bluetooth/forget_network
          - /bluetooth/get_site_default/[0-9a-f-]{36}
          - /bluetooth/initiate_fetch_network/[0-9a-f-]{36}
          - /bluetooth/set_network
          - /command/ws
          - /config/[0-9a-f-]{36}
          - /configs/batch/get
          - /configs/batch/set
          - /configurer/ws/[0-9a-f-]{36}
          - /device/alert_events_submit/[0-9a-f-]{36}
          - /device/wattage_output/[0-9a-f-]{36}
          - /device_count
          - /devices/[0-9a-f-]{36}
          - /devices/batch/commission
          - /devices/batch/move_unassigned
          - /devices/batch/status
          - /devices/by_connected
          - /devices/check_mac
          - /devices/commission
          - /devices/decommission
          - /devices/export/[0-9a-f-]{36}
          - /devices/list
          - /licensing/allowed_devices
          - /plugged_device
          - /plugged_device/[0-9a-f-]{36}
          - /plugged_devices/[0-9a-f-]{36}
          - /sim_configuration
          - /sim_configuration/[0-9a-f-]{36}
          - /sim_configuration/update_flag
          - /site/batch/config/network
          - /site/config/network/[0-9a-f-]{36}
          - /site/config/push/[0-9a-f-]{36}
          - /speedtest/[0-9a-f-]{36}
          - /uptime/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vnet
    namespace: vinfra
    resourceVersion: "2459699003"
    uid: f287543c-475e-4957-b29b-94495fa9b6c2
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /site/disable
          - /site/enable
          - /site/update
          - /vnetcap/sites/state
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /site/disable
          - /site/enable
          - /site/update
          - /vnetcap/sites/state
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /site/disable
          - /site/enable
          - /site/update
          - /vnetcap/sites/state
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-12-20T18:50:48Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vnetcap
    namespace: vinfra
    resourceVersion: "2463314513"
    uid: 09ef86c4-da98-471f-b515-3e765be64297
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vnetsuite.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /device/batch/information
          - /enforcement
          - /enforcement/override
          - /job/status
          - /license
          - /license/claim
          - /license/claim/dryrun
          - /license/history
          - /license/trials
          - /licensing/org/[0-9a-f-]{36}/get_compliance_info
          - /licensing/org/[0-9a-f-]{36}/trials
          - /logistics/get_organization_info
          - /logistics/org/[0-9a-f-]{36}/customer
          - /order/claim_order
          - /order/details
          - /order/unclaim_order
          - /organization/license
          - /partner/[0-9a-f-]{36}/order/csv
          - /partner/analytics
          - /partner/orders
          - /partner/orders/autocomplete
          - /v2/order/details
        unauthenticatedEndpoints:
          - /accounting/balance
          - /accounting/history
          - /accounting/history/csv
          - /accounting/income
          - /health_check
          - /internal/device/batch/information
          - /internal/license
          - /internal/license/children
          - /internal/license/claim
          - /internal/license/claim/dryrun
          - /internal/license/history
          - /internal/license/trial_serial_number
          - /internal/licensing/co_terming_group/[0-9a-f-]{36}/compliance_check
          - /internal/licensing/get_org_device_caps/[0-9a-f-]{36}
          - /internal/licensing/org/[0-9a-f-]{36}/co_terming_groups
          - /internal/licensing/org/[0-9a-f-]{36}/compliance_check
          - /internal/licensing/org/[0-9a-f-]{36}/trials
          - /internal/licensing/org/activated_renewals
          - /internal/logistics/get_organization_info
          - /internal/logistics/org/[0-9a-f-]{36}/customer
          - /internal/logistics/org/[0-9a-f-]{36}/sales_customer
          - /internal/order/rma/serial-numbers/filter
          - /internal/organization/license
          - /internal/serial_number/details
          - /internal/v2/accounting/balance
          - /internal/v2/accounting/history
          - /internal/v2/accounting/history/csv
          - /internal/v2/accounting/income
          - /internal/v2/license
          - /internal/v2/license/burn
          - /internal/v2/license/children
          - /internal/v2/license/claim
          - /internal/v2/license/claim/dryrun
          - /internal/v2/license/grant
          - /internal/v2/license/history
          - /internal/v2/license/history/csv
          - /internal/v2/license/split
          - /internal/v2/license/trials
          - /internal/v2/license/trials/raw
          - /internal/v2/license/unclaim
          - /internal/v2/license/update_job_schedule
          - /internal/v2/license/void
          - /internal/v2/licensing/get_org_logistics/[0-9a-f-]{36}
          - /internal/v2/order
          - /internal/v2/order/claim_order
          - /internal/v2/order/csv
          - /internal/v2/order/details
          - /internal/v2/order/unclaim_order
          - /internal/v2/organization/license
          - /internal/v3/license/grant
          - /internal/v3/license/grant/dryrun
          - /license/burn
          - /license/grant
          - /license/split
          - /license/unclaim
          - /license/update_job_schedule
          - /license/void
          - /logistics/org/[0-9a-f-]{36}/bookings
          - /order
          - /order/boomi/create_order
          - /order/external/create_order
          - /order/external/create_order_with_order_number
          - /order/netsuite/run
          - /org/[0-9a-f-]{36}/get_device_counts
          - /ping
          - /restricted_devices
          - /restricted_devices/[A-Z0-9-]{14}/logs
          - /restricted_devices/[A-Z0-9-]{14}/notes
          - /restricted_devices/csv_upload
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vnetsuite
    namespace: vinfra
    resourceVersion: "2378623407"
    uid: 26f88fd6-97b3-4d2f-9657-f8e8246e9493
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/language_embedding/get
          - /user/custom_classes/add
          - /user/custom_classes/get
          - /user/custom_classes/set
          - /user/custom_detections/get
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/language_embedding/get
          - /user/custom_classes/add
          - /user/custom_classes/get
          - /user/custom_classes/set
          - /user/custom_detections/get
      - host: vomni.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/language_embedding/get
          - /user/custom_classes/add
          - /user/custom_classes/get
          - /user/custom_classes/set
          - /user/custom_detections/get
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vomni
    namespace: vinfra
    resourceVersion: "2158702316"
    uid: d27e1c72-52c0-4745-80ca-e715a51558c8
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/short_status
          - /camera/update
        unauthenticatedEndpoints:
          - /vonline/ws/online
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/short_status
          - /camera/update
        unauthenticatedEndpoints:
          - /vonline/ws/online
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/short_status
          - /camera/update
        unauthenticatedEndpoints:
          - /vonline/ws/online
      - host: vonline.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/short_status
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vonline
    namespace: vinfra
    resourceVersion: "2417982144"
    uid: d238612d-bb3d-4a23-b27a-a200e8389235
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vparrot.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vparrot
    namespace: vinfra
    resourceVersion: "2158702235"
    uid: 282dd099-ef59-4172-bb80-63cbdd0955b4
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vpeer-to-peer.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
          - /user/peer_connection_status
          - /user/peer_connection_status/2
      - host: vpeertopeer.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
          - /user/peer_connection_status
          - /user/peer_connection_status/2
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /peer-to-peer/ping
          - /peer-to-peer/websocket/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vpeertopeer
    namespace: vinfra
    resourceVersion: "2417982139"
    uid: 22e12294-9428-4e3f-a42e-ea4155e9a864
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprochronicle.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /activity_feed_event/list
          - /alarm_events/get
          - /alarm_system/status_event/list
          - /alarm_system_status_event/list
          - /device_event/get
          - /device_event/list
          - /events/create
          - /online_events_for_devices_in_org
          - /partition_tripped_event/list
          - /signal_strength_metrics/list
          - /subscribe/events
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vprochronicle
    namespace: vinfra
    resourceVersion: "2352274495"
    uid: 43de687c-ba6f-4730-ad9c-46f72ebe65e0
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprocomm.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alarm_system/get_fire_state
          - /alarm_system/get_state
          - /alarm_system/update_config_now
          - /device_state/list
          - /keypad/ports
          - /output/user_disable
          - /output/user_enable
          - /partition/arm
          - /partition/disarm
          - /partition/resolve
          - /response_config_id/disarm_by_agent
          - /submit/wired_event
          - /submit/wireless_event
          - /submit/wireless_initial_state_event
          - /troubleshoot/user_reboot
        unauthenticatedEndpoints:
          - /partition/resolve_by_agent
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vprocomm
    namespace: vinfra
    resourceVersion: "2430710781"
    uid: a090b24f-4f0d-4a92-8050-3e0fc19d43d9
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproconfig.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /access_control/delete_door_action
          - /access_control/get_door_actions
          - /access_control/set_door_action
          - /alarm_system/add_devices
          - /alarm_system/create
          - /alarm_system/create_leaderless
          - /alarm_system/delete
          - /alarm_system/get
          - /alarm_system/get_all
          - /alarm_system/get_devices
          - /alarm_system/list
          - /alarm_system/update_address
          - /alarm_system/update_site
          - /arm_schedule/alarm_system/create
          - /arm_schedule/override
          - /arm_schedule/partition/create
          - /arm_schedule/update
          - /arm_schedule_events/update
          - /arm_schedule_override/delete
          - /arm_schedule_override/update
          - /arm_schedule_override_events/update
          - /delay_setting/create
          - /delay_setting/update_alarm_delay
          - /delay_setting/update_arm_delay
          - /device/console_pin_config/set
          - /device/create_smoke_sensor_conventional
          - /device/create_wired_input
          - /device/create_wired_output
          - /device/decommission
          - /device/delete
          - /device/get
          - /device/input_pin_config/set
          - /device/name/set
          - /device/nearby_camera/add
          - /device/nearby_camera/delete
          - /device/output_pin_config/set
          - /device/sensor_config/set
          - /internal/site/output_devices
          - /internal/unassigned_device/commission_bulk
          - /keycode/create
          - /keycode/delete
          - /keycode/generate
          - /keycode/list
          - /keycode/update
          - /org/get_devices_and_alarm_systems
          - /partition/assign_devices
          - /partition/assign_response_config
          - /partition/create
          - /partition/delete
          - /partition/get
          - /partition/get_devices
          - /partition/list
          - /partition/name/set
          - /partition/unassign_response_config
          - /postal_address/get
          - /sensor_policy/set
          - /unassigned_device/commission_bulk
          - /unassigned_device/set_up_alarm_device
          - /unassigned_device/set_up_colossus
          - /unassigned_device/set_up_mantis
          - /unassigned_device/set_up_simon
          - /unassigned_device/set_up_spalding
        unauthenticatedEndpoints:
          - /ping
          - /synthetic/get_state
          - /vcard
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vproconfig
    namespace: vinfra
    resourceVersion: "2285321828"
    uid: a3fcf4cd-80fa-4253-881d-c161972067ab
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproresponse.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /incident/delete
          - /incident/get
          - /incident/get_active
          - /incident/get_by_time_range
          - /incident/list
          - /incident/request_dispatch
          - /incident/resolve
          - /incident/share
          - /incident/update_viewed
          - /response/config/create
          - /response/config/delete
          - /response/config/update
          - /response/site/create
          - /response/site/delete
          - /response/site/get
          - /response/site/list
          - /response/site/update
          - /site/camera_trigger/count
          - /site/license/count
          - /web/incident/get
          - /web/incident/get_by_time_range
        unauthenticatedEndpoints:
          - /incident/redeem
          - /incident/redeem/[\w\.\-]+
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vproresponse
    namespace: vinfra
    resourceVersion: "2456102918"
    uid: e1b9487c-7645-482a-b1d9-dc5cc250930f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[\w\-. +%]+/download/[\w\-. +%]+
          - /[\w\-. +%]+/version
          - /activity/add
          - /analytics/cv_enabled_cameras
          - /app/live_link
          - /app/live_link/contacts/create
          - /app/live_link/contacts/delete
          - /app/live_link/contacts/edit
          - /app/live_link/contacts/get
          - /app/live_link/contacts/get_shared
          - /app/live_link/contacts/list
          - /app/live_link/contacts/revoke
          - /app/live_link/contacts/revoke_all
          - /app/live_link/contacts/share_link
          - /app/live_link/create
          - /app/live_link/get_contacts_shared_to
          - /app/live_link/revoke
          - /audit_log/get_camera_log
          - /audit_log/get_organization_log
          - /building/create
          - /building/delete
          - /building/list
          - /building/update
          - /buildings
          - /camera/audio/batch/get
          - /camera/audio/enable
          - /camera/auto_level/get
          - /camera/auto_level/set
          - /camera/autofocus
          - /camera/batch/get_low_bandwidth_mode
          - /camera/batch/lookup
          - /camera/batch/set_low_bandwidth_mode
          - /camera/calibration_images/get
          - /camera/calibration_matrix/delete
          - /camera/calibration_matrix/get
          - /camera/calibration_status
          - /camera/cloud_backup/is_enabled
          - /camera/codec/set
          - /camera/color/get_temperature
          - /camera/color/get_tint
          - /camera/color/set_temperature
          - /camera/color/set_tint
          - /camera/config/merge
          - /camera/cv/get_enabled_features
          - /camera/cv/set_enabled_features
          - /camera/cv_features/batch/get
          - /camera/cv_features/batch/set
          - /camera/decommission
          - /camera/deleted
          - /camera/download_offline_mode_certificate
          - /camera/edit/batch
          - /camera/event
          - /camera/exposure/get_compensation
          - /camera/exposure/set_compensation
          - /camera/favorites/get
          - /camera/favorites/modify
          - /camera/firmware_relay/((.+)\/)*([^\/]+)
          - /camera/fisheye/mode/get
          - /camera/fisheye/mode/set
          - /camera/focus_target/get
          - /camera/focus_target/set
          - /camera/get
          - /camera/get_calibrations_ready
          - /camera/get_cb_status
          - /camera/get_ffu_binaries
          - /camera/get_lan_url
          - /camera/groups/get
          - /camera/has_id
          - /camera/hq_bitrate/get
          - /camera/hq_bitrate/set
          - /camera/identify
          - /camera/image/settings
          - /camera/init/batch
          - /camera/init/perform
          - /camera/init/sharded
          - /camera/lan_token
          - /camera/level_assist
          - /camera/level_assist_active
          - /camera/location/set
          - /camera/manual_focus
          - /camera/manual_piris
          - /camera/manual_zoom
          - /camera/name/get
          - /camera/name/set
          - /camera/network_quality/submit
          - /camera/next_device/delete
          - /camera/next_device/get
          - /camera/next_device/update
          - /camera/night_threshold/get
          - /camera/night_threshold/set
          - /camera/operating_mode/get
          - /camera/operating_mode/set
          - /camera/privacy/set
          - /camera/public_key
          - /camera/reboot
          - /camera/release_channel/set
          - /camera/retention/get
          - /camera/retention/next_upload
          - /camera/retention/report
          - /camera/rotate
          - /camera/rotate/get
          - /camera/rotate/set
          - /camera/serial/get
          - /camera/site/batch/set
          - /camera/site/get
          - /camera/sq_bitrate/get
          - /camera/stats/get
          - /camera/stats/get_sum
          - /camera/storage/failure/get
          - /camera/storage/failure/set
          - /camera/storage/failure/unset
          - /camera/timezone/get
          - /camera/timezone/set
          - /camera/upload/logs
          - /camera/upload_sd_repair_result
          - /camera/wdr/enable
          - /camera/wdr/is_enabled
          - /camera/wifi/delete
          - /camera/wifi/get
          - /camera/wifi/set
          - /camera_grid/copy
          - /camera_grid/create
          - /camera_grid/delete
          - /camera_grid/list
          - /camera_grid/update
          - /cameras/get_mac_addresses
          - /cameras/operating_mode/get
          - /cameras_in_org
          - /cloud/enable_static_ip
          - /cloud/static_ips
          - /command/user/init
          - /command_version/set
          - /compliance/check_address
          - /customer/get
          - /default_endpoints
          - /device/batch/information
          - /device/decommission
          - /device/delete_orderproduct
          - /device/get_or_create_default_site
          - /device/initialize
          - /device/notes/get
          - /device/notes/set
          - /device/stats/get
          - /feature/is_enabled
          - /feedback/add
          - /firmware/((.+)\/)*([^\/]+)
          - /firmware/vtoolbox/((.+)\/)*([^\/]+)
          - /floor/create
          - /floor/delete
          - /floor/list
          - /floor/update
          - /floor_plan/change_walls
          - /floor_plan/create
          - /floor_plan/delete
          - /floor_plan/get_image
          - /floor_plan/get_metadata
          - /floor_plan/mobile_get_zip_and_bounds
          - /floor_plan/retrieve_walls
          - /floor_plan/set_floor
          - /floor_plan/set_metadata
          - /floor_plan/upload_image
          - /floorplan/get_fov_mappings
          - /floors
          - /info/device/lookup
          - /info/release_channel/get_all
          - /local_player/doors
          - /local_player/init
          - /local_player/set_grid
          - /local_player/status
          - /local_player/status/update
          - /local_player/update
          - /local_player/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /local_player/users/[0-9a-f-]{36}
          - /local_player/users/list
          - /local_player/users/update
          - /logistics/camera/short_status
          - /manufacturer/reset
          - /model/all_display_names
          - /model/capabilities
          - /model/config/merge
          - /models/list
          - /non_superuser/feature_flags/get_all
          - /notifications/group_preferences/set
          - /notifications/mute_preferences/get
          - /notifications/mute_preferences/set
          - /notifications/preferences/get
          - /notifications/preferences/set
          - /org/[0-9a-f-]{36}/cameras
          - /org/[0-9a-f-]{36}/users/list
          - /org/add_user
          - /org/admin
          - /org/camera/list
          - /org/camera_group/add_camera
          - /org/camera_group/batch_move_cameras
          - /org/camera_group/create
          - /org/camera_group/delete
          - /org/camera_group/modify
          - /org/camera_group/remove_camera
          - /org/camera_group/reorder_cameras
          - /org/camera_group/sites_to_grids
          - /org/camera_group/users
          - /org/cameras/get_csv
          - /org/cameras/get_cv_enabled
          - /org/create
          - /org/cv/set_enabled_features
          - /org/delete
          - /org/disable_cloud_backup
          - /org/download_offline_mode_certificate
          - /org/enable_offline_mode
          - /org/encryption_settings/get
          - /org/encryption_settings/set
          - /org/events
          - /org/features/get
          - /org/get_camera_groups
          - /org/invite
          - /org/modify
          - /org/remove_user
          - /org/remove_users
          - /org/resend_invite
          - /org/send_pass_app_invite
          - /org/set_user_permissions
          - /org/settings/get
          - /org/settings/set
          - /org/settings/update
          - /org/site/list
          - /org/toggle_hipaa
          - /org/users
          - /organization/[0-9a-f-]{36}/user/employment
          - /organization/[0-9a-f-]{36}/user/name
          - /organization/[0-9a-f-]{36}/user/phone
          - /organization/[0-9a-f-]{36}/users
          - /organization/[0-9a-f-]{36}/users/search
          - /particulate_sensors
          - /resource/create
          - /resource/get
          - /serial_number/assignment_upload
          - /serial_number/list
          - /site/[0-9a-f-]{36}/user/invite
          - /site/camera/list
          - /spurdog/view_settings/get
          - /spurdog/view_settings/update
          - /ssl/create_local_device_root_certificate_authority
          - /user/become_status
          - /user/camera/batch/compliance/list
          - /user/camera/compliance/list
          - /user/camera/compliance/override
          - /user/camera/compliance/remove
          - /user/camera/config/batch/delete
          - /user/camera/config/batch/get
          - /user/camera/config/batch/set
          - /user/camera/config/delete
          - /user/camera/config/get
          - /user/camera/config/set
          - /user/contact_info
          - /user/email/change
          - /user/email/send_verification_code
          - /user/get_orgs
          - /user/linked_accounts
          - /user/locale/set
          - /user/name
          - /user/passwd
          - /user/phone
          - /user/phone/verify
          - /user/profile_image/get
          - /user/profile_image/upload
          - /user/replace_app_token
          - /user/set_active
          - /user/settings/get
          - /user/settings/set
          - /user/settings/update
          - /user/toggle_become
          - /users/get_or_create
          - /v1/device/information
          - /vayu/batch/commission
          - /vayu/get_data
          - /vayu/list
          - /vayu/set
          - /vayu/submit_data
          - /vayu/update
        unauthenticatedEndpoints:
          - /app/live_link/redeem
          - /camera/auth/init
          - /camera/org_id/get
          - /cameras_release_tool/get_cameras
          - /cameras_release_tool/set_default_firmware_version
          - /cameras_release_tool/set_firmware_version
          - /check_auth
          - /command_version/get
          - /customer/get_details
          - /device/auth/init
          - /direct/ping
          - /embed/[0-9a-f-]{36}/
          - /firmware/((.+)\/)*([^\/]+)
          - /internal/camera/config/get
          - /internal/camera/config/get/filtered
          - /internal/camera/config/set/single
          - /internal/camera/healthstatus
          - /internal/camera/lookup
          - /internal/camera/release_channel/set
          - /internal/org/get
          - /internal/org/remove_user
          - /internal/orgs/get_for_user
          - /internal/send_email
          - /internal/users/search
          - /is_online
          - /logs/relay-intrusion-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/1894804/store/
          - /org/check_shortname/[^/]*[0-9a-z]+[^/]*
          - /org/generate_shortname/.{1,100}
          - /org/invitation/info
          - /ping
          - /ping-command
          - /ping-device
          - /prestart/get
          - /time
          - /twilio/c8e78359-da58-4612-8ce5-3381fa9bd484
          - /user/add_cookie_user_id
          - /user/auth_challenges
          - /user/create
          - /user/email/verify
          - /user/login
          - /user/logout
          - /user/reset/redeem
          - /user/saml/sso/[0-9a-zA-Z._-]{1,64}
          - /user/saml/sso/login/redirect
          - /user/send_org_membership
          - /user/session_accounts
          - /user/validate_short_name
          - /vprovision-ping
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[\w\-. +%]+/download/[\w\-. +%]+
          - /[\w\-. +%]+/version
          - /activity/add
          - /analytics/cv_enabled_cameras
          - /app/live_link
          - /app/live_link/contacts/create
          - /app/live_link/contacts/delete
          - /app/live_link/contacts/edit
          - /app/live_link/contacts/get
          - /app/live_link/contacts/get_shared
          - /app/live_link/contacts/list
          - /app/live_link/contacts/revoke
          - /app/live_link/contacts/revoke_all
          - /app/live_link/contacts/share_link
          - /app/live_link/create
          - /app/live_link/get_contacts_shared_to
          - /app/live_link/revoke
          - /audit_log/get_camera_log
          - /audit_log/get_organization_log
          - /building/create
          - /building/delete
          - /building/list
          - /building/update
          - /buildings
          - /camera/audio/batch/get
          - /camera/audio/enable
          - /camera/auto_level/get
          - /camera/auto_level/set
          - /camera/autofocus
          - /camera/batch/get_low_bandwidth_mode
          - /camera/batch/lookup
          - /camera/batch/set_low_bandwidth_mode
          - /camera/calibration_images/get
          - /camera/calibration_matrix/delete
          - /camera/calibration_matrix/get
          - /camera/calibration_status
          - /camera/cloud_backup/is_enabled
          - /camera/codec/set
          - /camera/color/get_temperature
          - /camera/color/get_tint
          - /camera/color/set_temperature
          - /camera/color/set_tint
          - /camera/config/merge
          - /camera/cv/get_enabled_features
          - /camera/cv/set_enabled_features
          - /camera/cv_features/batch/get
          - /camera/cv_features/batch/set
          - /camera/decommission
          - /camera/deleted
          - /camera/download_offline_mode_certificate
          - /camera/edit/batch
          - /camera/event
          - /camera/exposure/get_compensation
          - /camera/exposure/set_compensation
          - /camera/favorites/get
          - /camera/favorites/modify
          - /camera/firmware_relay/((.+)\/)*([^\/]+)
          - /camera/fisheye/mode/get
          - /camera/fisheye/mode/set
          - /camera/focus_target/get
          - /camera/focus_target/set
          - /camera/get
          - /camera/get_calibrations_ready
          - /camera/get_cb_status
          - /camera/get_ffu_binaries
          - /camera/get_lan_url
          - /camera/groups/get
          - /camera/has_id
          - /camera/hq_bitrate/get
          - /camera/hq_bitrate/set
          - /camera/identify
          - /camera/image/settings
          - /camera/init/batch
          - /camera/init/perform
          - /camera/init/sharded
          - /camera/lan_token
          - /camera/level_assist
          - /camera/level_assist_active
          - /camera/location/set
          - /camera/manual_focus
          - /camera/manual_piris
          - /camera/manual_zoom
          - /camera/name/get
          - /camera/name/set
          - /camera/network_quality/submit
          - /camera/next_device/delete
          - /camera/next_device/get
          - /camera/next_device/update
          - /camera/night_threshold/get
          - /camera/night_threshold/set
          - /camera/operating_mode/get
          - /camera/operating_mode/set
          - /camera/privacy/set
          - /camera/public_key
          - /camera/reboot
          - /camera/release_channel/set
          - /camera/retention/get
          - /camera/retention/next_upload
          - /camera/retention/report
          - /camera/rotate
          - /camera/rotate/get
          - /camera/rotate/set
          - /camera/serial/get
          - /camera/site/batch/set
          - /camera/site/get
          - /camera/sq_bitrate/get
          - /camera/stats/get
          - /camera/stats/get_sum
          - /camera/storage/failure/get
          - /camera/storage/failure/set
          - /camera/storage/failure/unset
          - /camera/timezone/get
          - /camera/timezone/set
          - /camera/upload/logs
          - /camera/upload_sd_repair_result
          - /camera/wdr/enable
          - /camera/wdr/is_enabled
          - /camera/wifi/delete
          - /camera/wifi/get
          - /camera/wifi/set
          - /camera_grid/copy
          - /camera_grid/create
          - /camera_grid/delete
          - /camera_grid/list
          - /camera_grid/update
          - /cameras/get_mac_addresses
          - /cameras/operating_mode/get
          - /cameras_in_org
          - /cloud/enable_static_ip
          - /cloud/static_ips
          - /command/user/init
          - /command_version/set
          - /compliance/check_address
          - /customer/get
          - /default_endpoints
          - /device/batch/information
          - /device/decommission
          - /device/delete_orderproduct
          - /device/get_or_create_default_site
          - /device/initialize
          - /device/notes/get
          - /device/notes/set
          - /device/stats/get
          - /feature/is_enabled
          - /feedback/add
          - /firmware/((.+)\/)*([^\/]+)
          - /firmware/vtoolbox/((.+)\/)*([^\/]+)
          - /floor/create
          - /floor/delete
          - /floor/list
          - /floor/update
          - /floor_plan/change_walls
          - /floor_plan/create
          - /floor_plan/delete
          - /floor_plan/get_image
          - /floor_plan/get_metadata
          - /floor_plan/mobile_get_zip_and_bounds
          - /floor_plan/retrieve_walls
          - /floor_plan/set_floor
          - /floor_plan/set_metadata
          - /floor_plan/upload_image
          - /floorplan/get_fov_mappings
          - /floors
          - /info/device/lookup
          - /info/release_channel/get_all
          - /local_player/doors
          - /local_player/init
          - /local_player/set_grid
          - /local_player/status
          - /local_player/status/update
          - /local_player/update
          - /local_player/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /local_player/users/[0-9a-f-]{36}
          - /local_player/users/list
          - /local_player/users/update
          - /logistics/camera/short_status
          - /manufacturer/reset
          - /model/all_display_names
          - /model/capabilities
          - /model/config/merge
          - /models/list
          - /non_superuser/feature_flags/get_all
          - /notifications/group_preferences/set
          - /notifications/mute_preferences/get
          - /notifications/mute_preferences/set
          - /notifications/preferences/get
          - /notifications/preferences/set
          - /org/[0-9a-f-]{36}/cameras
          - /org/[0-9a-f-]{36}/users/list
          - /org/add_user
          - /org/admin
          - /org/camera/list
          - /org/camera_group/add_camera
          - /org/camera_group/batch_move_cameras
          - /org/camera_group/create
          - /org/camera_group/delete
          - /org/camera_group/modify
          - /org/camera_group/remove_camera
          - /org/camera_group/reorder_cameras
          - /org/camera_group/sites_to_grids
          - /org/camera_group/users
          - /org/cameras/get_csv
          - /org/cameras/get_cv_enabled
          - /org/create
          - /org/cv/set_enabled_features
          - /org/delete
          - /org/disable_cloud_backup
          - /org/download_offline_mode_certificate
          - /org/enable_offline_mode
          - /org/encryption_settings/get
          - /org/encryption_settings/set
          - /org/events
          - /org/features/get
          - /org/get_camera_groups
          - /org/invite
          - /org/modify
          - /org/remove_user
          - /org/remove_users
          - /org/resend_invite
          - /org/send_pass_app_invite
          - /org/set_user_permissions
          - /org/settings/get
          - /org/settings/set
          - /org/settings/update
          - /org/site/list
          - /org/toggle_hipaa
          - /org/users
          - /organization/[0-9a-f-]{36}/user/employment
          - /organization/[0-9a-f-]{36}/user/name
          - /organization/[0-9a-f-]{36}/user/phone
          - /organization/[0-9a-f-]{36}/users
          - /organization/[0-9a-f-]{36}/users/search
          - /particulate_sensors
          - /resource/create
          - /resource/get
          - /serial_number/assignment_upload
          - /serial_number/list
          - /site/[0-9a-f-]{36}/user/invite
          - /site/camera/list
          - /spurdog/view_settings/get
          - /spurdog/view_settings/update
          - /ssl/create_local_device_root_certificate_authority
          - /user/become_status
          - /user/camera/batch/compliance/list
          - /user/camera/compliance/list
          - /user/camera/compliance/override
          - /user/camera/compliance/remove
          - /user/camera/config/batch/delete
          - /user/camera/config/batch/get
          - /user/camera/config/batch/set
          - /user/camera/config/delete
          - /user/camera/config/get
          - /user/camera/config/set
          - /user/contact_info
          - /user/email/change
          - /user/email/send_verification_code
          - /user/get_orgs
          - /user/linked_accounts
          - /user/locale/set
          - /user/name
          - /user/passwd
          - /user/phone
          - /user/phone/verify
          - /user/profile_image/get
          - /user/profile_image/upload
          - /user/replace_app_token
          - /user/set_active
          - /user/settings/get
          - /user/settings/set
          - /user/settings/update
          - /user/toggle_become
          - /users/get_or_create
          - /v1/device/information
          - /vayu/batch/commission
          - /vayu/get_data
          - /vayu/list
          - /vayu/set
          - /vayu/submit_data
          - /vayu/update
        unauthenticatedEndpoints:
          - /app/live_link/redeem
          - /camera/auth/init
          - /camera/org_id/get
          - /cameras_release_tool/get_cameras
          - /cameras_release_tool/set_default_firmware_version
          - /cameras_release_tool/set_firmware_version
          - /check_auth
          - /command_version/get
          - /customer/get_details
          - /device/auth/init
          - /direct/ping
          - /embed/[0-9a-f-]{36}/
          - /firmware/((.+)\/)*([^\/]+)
          - /internal/camera/config/get
          - /internal/camera/config/get/filtered
          - /internal/camera/config/set/single
          - /internal/camera/healthstatus
          - /internal/camera/lookup
          - /internal/camera/release_channel/set
          - /internal/org/get
          - /internal/org/remove_user
          - /internal/orgs/get_for_user
          - /internal/send_email
          - /internal/users/search
          - /is_online
          - /logs/relay-intrusion-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/1894804/store/
          - /org/check_shortname/[^/]*[0-9a-z]+[^/]*
          - /org/generate_shortname/.{1,100}
          - /org/invitation/info
          - /ping
          - /ping-command
          - /ping-device
          - /prestart/get
          - /time
          - /twilio/c8e78359-da58-4612-8ce5-3381fa9bd484
          - /user/add_cookie_user_id
          - /user/auth_challenges
          - /user/create
          - /user/email/verify
          - /user/login
          - /user/logout
          - /user/reset/redeem
          - /user/saml/sso/[0-9a-zA-Z._-]{1,64}
          - /user/saml/sso/login/redirect
          - /user/send_org_membership
          - /user/session_accounts
          - /user/validate_short_name
          - /vprovision-ping
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[\w\-. +%]+/download/[\w\-. +%]+
          - /[\w\-. +%]+/version
          - /activity/add
          - /analytics/cv_enabled_cameras
          - /app/live_link
          - /app/live_link/contacts/create
          - /app/live_link/contacts/delete
          - /app/live_link/contacts/edit
          - /app/live_link/contacts/get
          - /app/live_link/contacts/get_shared
          - /app/live_link/contacts/list
          - /app/live_link/contacts/revoke
          - /app/live_link/contacts/revoke_all
          - /app/live_link/contacts/share_link
          - /app/live_link/create
          - /app/live_link/get_contacts_shared_to
          - /app/live_link/revoke
          - /audit_log/get_camera_log
          - /audit_log/get_organization_log
          - /building/create
          - /building/delete
          - /building/list
          - /building/update
          - /buildings
          - /camera/audio/batch/get
          - /camera/audio/enable
          - /camera/auto_level/get
          - /camera/auto_level/set
          - /camera/autofocus
          - /camera/batch/get_low_bandwidth_mode
          - /camera/batch/lookup
          - /camera/batch/set_low_bandwidth_mode
          - /camera/calibration_images/get
          - /camera/calibration_matrix/delete
          - /camera/calibration_matrix/get
          - /camera/calibration_status
          - /camera/cloud_backup/is_enabled
          - /camera/codec/set
          - /camera/color/get_temperature
          - /camera/color/get_tint
          - /camera/color/set_temperature
          - /camera/color/set_tint
          - /camera/config/merge
          - /camera/cv/get_enabled_features
          - /camera/cv/set_enabled_features
          - /camera/cv_features/batch/get
          - /camera/cv_features/batch/set
          - /camera/decommission
          - /camera/deleted
          - /camera/download_offline_mode_certificate
          - /camera/edit/batch
          - /camera/event
          - /camera/exposure/get_compensation
          - /camera/exposure/set_compensation
          - /camera/favorites/get
          - /camera/favorites/modify
          - /camera/firmware_relay/((.+)\/)*([^\/]+)
          - /camera/fisheye/mode/get
          - /camera/fisheye/mode/set
          - /camera/focus_target/get
          - /camera/focus_target/set
          - /camera/get
          - /camera/get_calibrations_ready
          - /camera/get_cb_status
          - /camera/get_ffu_binaries
          - /camera/get_lan_url
          - /camera/groups/get
          - /camera/has_id
          - /camera/hq_bitrate/get
          - /camera/hq_bitrate/set
          - /camera/identify
          - /camera/image/settings
          - /camera/init/batch
          - /camera/init/perform
          - /camera/init/sharded
          - /camera/lan_token
          - /camera/level_assist
          - /camera/level_assist_active
          - /camera/location/set
          - /camera/manual_focus
          - /camera/manual_piris
          - /camera/manual_zoom
          - /camera/name/get
          - /camera/name/set
          - /camera/network_quality/submit
          - /camera/next_device/delete
          - /camera/next_device/get
          - /camera/next_device/update
          - /camera/night_threshold/get
          - /camera/night_threshold/set
          - /camera/operating_mode/get
          - /camera/operating_mode/set
          - /camera/privacy/set
          - /camera/public_key
          - /camera/reboot
          - /camera/release_channel/set
          - /camera/retention/get
          - /camera/retention/next_upload
          - /camera/retention/report
          - /camera/rotate
          - /camera/rotate/get
          - /camera/rotate/set
          - /camera/serial/get
          - /camera/site/batch/set
          - /camera/site/get
          - /camera/sq_bitrate/get
          - /camera/stats/get
          - /camera/stats/get_sum
          - /camera/storage/failure/get
          - /camera/storage/failure/set
          - /camera/storage/failure/unset
          - /camera/timezone/get
          - /camera/timezone/set
          - /camera/upload/logs
          - /camera/upload_sd_repair_result
          - /camera/wdr/enable
          - /camera/wdr/is_enabled
          - /camera/wifi/delete
          - /camera/wifi/get
          - /camera/wifi/set
          - /camera_grid/copy
          - /camera_grid/create
          - /camera_grid/delete
          - /camera_grid/list
          - /camera_grid/update
          - /cameras/get_mac_addresses
          - /cameras/operating_mode/get
          - /cameras_in_org
          - /cloud/enable_static_ip
          - /cloud/static_ips
          - /command/user/init
          - /command_version/set
          - /compliance/check_address
          - /customer/get
          - /default_endpoints
          - /device/batch/information
          - /device/decommission
          - /device/delete_orderproduct
          - /device/get_or_create_default_site
          - /device/initialize
          - /device/notes/get
          - /device/notes/set
          - /device/stats/get
          - /feature/is_enabled
          - /feedback/add
          - /firmware/((.+)\/)*([^\/]+)
          - /firmware/vtoolbox/((.+)\/)*([^\/]+)
          - /floor/create
          - /floor/delete
          - /floor/list
          - /floor/update
          - /floor_plan/change_walls
          - /floor_plan/create
          - /floor_plan/delete
          - /floor_plan/get_image
          - /floor_plan/get_metadata
          - /floor_plan/mobile_get_zip_and_bounds
          - /floor_plan/retrieve_walls
          - /floor_plan/set_floor
          - /floor_plan/set_metadata
          - /floor_plan/upload_image
          - /floorplan/get_fov_mappings
          - /floors
          - /info/device/lookup
          - /info/release_channel/get_all
          - /local_player/doors
          - /local_player/init
          - /local_player/set_grid
          - /local_player/status
          - /local_player/status/update
          - /local_player/update
          - /local_player/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+
          - /local_player/users/[0-9a-f-]{36}
          - /local_player/users/list
          - /local_player/users/update
          - /logistics/camera/short_status
          - /manufacturer/reset
          - /model/all_display_names
          - /model/capabilities
          - /model/config/merge
          - /models/list
          - /non_superuser/feature_flags/get_all
          - /notifications/group_preferences/set
          - /notifications/mute_preferences/get
          - /notifications/mute_preferences/set
          - /notifications/preferences/get
          - /notifications/preferences/set
          - /org/[0-9a-f-]{36}/cameras
          - /org/[0-9a-f-]{36}/users/list
          - /org/add_user
          - /org/admin
          - /org/camera/list
          - /org/camera_group/add_camera
          - /org/camera_group/batch_move_cameras
          - /org/camera_group/create
          - /org/camera_group/delete
          - /org/camera_group/modify
          - /org/camera_group/remove_camera
          - /org/camera_group/reorder_cameras
          - /org/camera_group/sites_to_grids
          - /org/camera_group/users
          - /org/cameras/get_csv
          - /org/cameras/get_cv_enabled
          - /org/create
          - /org/cv/set_enabled_features
          - /org/delete
          - /org/disable_cloud_backup
          - /org/download_offline_mode_certificate
          - /org/enable_offline_mode
          - /org/encryption_settings/get
          - /org/encryption_settings/set
          - /org/events
          - /org/features/get
          - /org/get_camera_groups
          - /org/invite
          - /org/modify
          - /org/remove_user
          - /org/remove_users
          - /org/resend_invite
          - /org/send_pass_app_invite
          - /org/set_user_permissions
          - /org/settings/get
          - /org/settings/set
          - /org/settings/update
          - /org/site/list
          - /org/toggle_hipaa
          - /org/users
          - /organization/[0-9a-f-]{36}/user/employment
          - /organization/[0-9a-f-]{36}/user/name
          - /organization/[0-9a-f-]{36}/user/phone
          - /organization/[0-9a-f-]{36}/users
          - /organization/[0-9a-f-]{36}/users/search
          - /particulate_sensors
          - /resource/create
          - /resource/get
          - /serial_number/assignment_upload
          - /serial_number/list
          - /site/[0-9a-f-]{36}/user/invite
          - /site/camera/list
          - /spurdog/view_settings/get
          - /spurdog/view_settings/update
          - /ssl/create_local_device_root_certificate_authority
          - /user/become_status
          - /user/camera/batch/compliance/list
          - /user/camera/compliance/list
          - /user/camera/compliance/override
          - /user/camera/compliance/remove
          - /user/camera/config/batch/delete
          - /user/camera/config/batch/get
          - /user/camera/config/batch/set
          - /user/camera/config/delete
          - /user/camera/config/get
          - /user/camera/config/set
          - /user/contact_info
          - /user/email/change
          - /user/email/send_verification_code
          - /user/get_orgs
          - /user/linked_accounts
          - /user/locale/set
          - /user/name
          - /user/passwd
          - /user/phone
          - /user/phone/verify
          - /user/profile_image/get
          - /user/profile_image/upload
          - /user/replace_app_token
          - /user/set_active
          - /user/settings/get
          - /user/settings/set
          - /user/settings/update
          - /user/toggle_become
          - /users/get_or_create
          - /v1/device/information
          - /vayu/batch/commission
          - /vayu/get_data
          - /vayu/list
          - /vayu/set
          - /vayu/submit_data
          - /vayu/update
        unauthenticatedEndpoints:
          - /app/live_link/redeem
          - /camera/auth/init
          - /camera/org_id/get
          - /cameras_release_tool/get_cameras
          - /cameras_release_tool/set_default_firmware_version
          - /cameras_release_tool/set_firmware_version
          - /check_auth
          - /command_version/get
          - /customer/get_details
          - /device/auth/init
          - /direct/ping
          - /embed/[0-9a-f-]{36}/
          - /firmware/((.+)\/)*([^\/]+)
          - /internal/camera/config/get
          - /internal/camera/config/get/filtered
          - /internal/camera/config/set/single
          - /internal/camera/healthstatus
          - /internal/camera/lookup
          - /internal/camera/release_channel/set
          - /internal/org/get
          - /internal/org/remove_user
          - /internal/orgs/get_for_user
          - /internal/send_email
          - /internal/users/search
          - /is_online
          - /logs/relay-intrusion-memfault/api/v0/chunks/[A-Z0-9-]{14}
          - /logs/relay-vaccess-sentry/api/1894804/store/
          - /org/check_shortname/[^/]*[0-9a-z]+[^/]*
          - /org/generate_shortname/.{1,100}
          - /org/invitation/info
          - /ping
          - /ping-command
          - /ping-device
          - /prestart/get
          - /time
          - /twilio/c8e78359-da58-4612-8ce5-3381fa9bd484
          - /user/add_cookie_user_id
          - /user/auth_challenges
          - /user/create
          - /user/email/verify
          - /user/login
          - /user/logout
          - /user/reset/redeem
          - /user/saml/sso/[0-9a-zA-Z._-]{1,64}
          - /user/saml/sso/login/redirect
          - /user/send_org_membership
          - /user/session_accounts
          - /user/validate_short_name
          - /vprovision-ping
      - host: vprovision.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /internal/camera/lookup
          - /internal/camera/site/disable_traffic_shaping
          - /internal/camera/site/enable_traffic_shaping
          - /internal/org/cameras/info
          - /internal/org/short_name
          - /internal/orgs/get_for_user
          - /internal/send_email
          - /internal/sharded/mark_deleted
          - /internal/sharded/prepare
          - /user/validate_short_name
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vprovision
    namespace: vinfra
    resourceVersion: "2459366586"
    uid: d26be35d-0cc1-49e4-90b1-f32fb1e27c8c
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /_accept/hls/[0-9a-f-]{36}
          - /_accept/hls/[A-Z0-9-]{14}
          - /_accept/remotesh/[0-9a-f-]{36}
          - /_accept/remotesh/[A-Z0-9-]{14}
          - /_accept/signed_remotesh/[0-9a-f-]{36}
          - /_accept/signed_remotesh/[A-Z0-9-]{14}
        unauthenticatedEndpoints:
          - /_proxy/hls/[0-9a-f-]{36}/((.+)\/)*([^\/]+)
          - /_proxy/hls/[A-Z0-9-]{14}/((.+)\/)*([^\/]+)
          - /_proxy/remotesh/[0-9a-f-]{36}
          - /_proxy/remotesh/[A-Z0-9-]{14}
          - /_proxy/signed_remotesh/[0-9a-f-]{36}
          - /_proxy/signed_remotesh/[A-Z0-9-]{14}
          - /_response/[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /ping
          - /remotesh_ping
          - /speedtest/download
          - /speedtest/upload
      - host: vstream.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /_accept/hls/[0-9a-f-]{36}
          - /_accept/hls/[A-Z0-9-]{14}
          - /_accept/remotesh/[0-9a-f-]{36}
          - /_accept/remotesh/[A-Z0-9-]{14}
          - /_accept/signed_remotesh/[0-9a-f-]{36}
          - /_accept/signed_remotesh/[A-Z0-9-]{14}
        unauthenticatedEndpoints:
          - /_proxy/hls/[0-9a-f-]{36}/((.+)\/)*([^\/]+)
          - /_proxy/hls/[A-Z0-9-]{14}/((.+)\/)*([^\/]+)
          - /_proxy/remotesh/[0-9a-f-]{36}
          - /_proxy/remotesh/[A-Z0-9-]{14}
          - /_proxy/signed_remotesh/[0-9a-f-]{36}
          - /_proxy/signed_remotesh/[A-Z0-9-]{14}
          - /_response/[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[0-9a-f-]{36}_[0-9a-f-]{36}
          - /_response/signed_remotesh_[A-Z0-9-]{14}_[0-9a-f-]{36}
          - /ping
          - /remotesh_ping
          - /speedtest/download
          - /speedtest/upload
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vproxy
    namespace: vinfra
    resourceVersion: "2158702351"
    uid: e331a32e-7746-4697-81da-450885c77c21
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vptz/camera/ws
        unauthenticatedEndpoints:
          - /vptz/ping
      - host: vstream.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vptz/camera/ws
        unauthenticatedEndpoints:
          - /vptz/ping
      - host: vptz.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/ws
          - /contextual_triggers/config/get
          - /contextual_triggers/config/set
          - /contextual_triggers/context_camera_preset/delete
          - /contextual_triggers/create
          - /contextual_triggers/delete
          - /contextual_triggers/edit
          - /contextual_triggers/get
          - /user/guard_tours/create
          - /user/guard_tours/delete
          - /user/guard_tours/edit
          - /user/guard_tours/get
          - /user/guard_tours_location/thumbnail
          - /user/guard_tours_location_image/create
          - /user/presets/create
          - /user/presets/delete
          - /user/presets/get
          - /user/presets/home/update
          - /user/presets/new
          - /user/presets/sort_index/update
          - /user/presets/thumbnail
          - /user/sentry_mode/get
          - /user/sentry_mode/set
          - /user/ws/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vptz
    namespace: vinfra
    resourceVersion: "2158702314"
    uid: 2c2a50f6-7792-4f23-857e-00af99438b96
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: api.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/orgs/[0-9a-f-]{36}/v2/apikeys
          - /admin/orgs/[0-9a-f-]{36}/v2/apikeys/[\w\.\-]+
          - /admin/orgs/[0-9a-f-]{36}/v2/granular_apikeys
          - /admin/orgs/[0-9a-f-]{36}/v2/webhookconfig
          - /integrations/auror/auth
          - /integrations/auror/export
          - /integrations/axon_evidence/auth
          - /integrations/axon_evidence/cases/[0-9a-f-]{36}/get
          - /integrations/axon_evidence/categories/[0-9a-f-]{36}/get
          - /integrations/axon_evidence/export
          - /integrations/config/[0-9a-f-]{36}/[0-9a-f-]{36}/delete_config
          - /integrations/config/[0-9a-f-]{36}/get_config
          - /integrations/config/get_available_integrations
          - /integrations/config/set_config
        unauthenticatedEndpoints:
          - /access/v1/access_groups
          - /access/v1/access_groups/group
          - /access/v1/access_groups/group/user
          - /access/v1/access_users
          - /access/v1/access_users/user
          - /access/v1/access_users/user/ble/activate
          - /access/v1/access_users/user/ble/deactivate
          - /access/v1/access_users/user/end_date
          - /access/v1/access_users/user/entry_code
          - /access/v1/access_users/user/pass/invite
          - /access/v1/access_users/user/profile_photo
          - /access/v1/access_users/user/remote_unlock/activate
          - /access/v1/access_users/user/remote_unlock/deactivate
          - /access/v1/access_users/user/start_date
          - /access/v1/access_users_photos_api
          - /access/v1/access_users_photos_api/user
          - /access/v1/credentials/card
          - /access/v1/credentials/card/activate
          - /access/v1/credentials/card/deactivate
          - /access/v1/credentials/license_plate
          - /access/v1/credentials/license_plate/activate
          - /access/v1/credentials/license_plate/deactivate
          - /access/v1/credentials/mfa_code
          - /access/v1/door/admin_unlock
          - /access/v1/door/exception_calendar
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}/exception
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}/exception/[0-9a-f-]{36}
          - /access/v1/door/user_unlock
          - /access/v1/doors
          - /admin/access_v1/openapi\.json
          - /admin/alarms_v1/openapi\.json
          - /admin/camera_v1/openapi\.json
          - /admin/core_v1/openapi\.json
          - /admin/guest_v1/openapi\.json
          - /admin/openapi/openapi\.json
          - /admin/ping
          - /admin/sensor_v1/openapi\.json
          - /admin/tokens/openapi\.json
          - /admin/viewing_station_v1/openapi\.json
          - /alarms/v1/devices
          - /alarms/v1/sites
          - /cameras/v1/alerts
          - /cameras/v1/analytics/dashboard_occupancy_trends
          - /cameras/v1/analytics/lpr/images
          - /cameras/v1/analytics/lpr/license_plate_of_interest
          - /cameras/v1/analytics/lpr/license_plate_of_interest/batch
          - /cameras/v1/analytics/lpr/timestamps
          - /cameras/v1/analytics/max_object_counts
          - /cameras/v1/analytics/object_counts
          - /cameras/v1/analytics/object_position_mqtt
          - /cameras/v1/analytics/occupancy_trends
          - /cameras/v1/audio/status
          - /cameras/v1/cloud_backup/settings
          - /cameras/v1/config
          - /cameras/v1/devices
          - /cameras/v1/feature
          - /cameras/v1/footage/link
          - /cameras/v1/footage/thumbnails
          - /cameras/v1/footage/thumbnails/latest
          - /cameras/v1/footage/thumbnails/link
          - /cameras/v1/footage/token
          - /cameras/v1/occupancy_trend_enabled
          - /cameras/v1/people/person_of_interest
          - /cameras/v1/video_tagging/event
          - /cameras/v1/video_tagging/event/search
          - /cameras/v1/video_tagging/event_type
          - /core/v1/audit_log
          - /core/v1/user
          - /environment/v1/alerts
          - /environment/v1/data
          - /events/v1/access
          - /guest/v1/deny_list
          - /guest/v1/sites
          - /guest/v1/visits
          - /orgs/[0-9a-f-]{36}/auditlog
          - /orgs/[0-9a-f-]{36}/cameras
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/fullres
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/history/[0-9]+
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/latest
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/objects/counts
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/thumbnail/[0-9]+
          - /orgs/[0-9a-f-]{36}/license_plate_of_interest
          - /orgs/[0-9a-f-]{36}/license_plate_of_interest/[\w\.\-]+
          - /orgs/[0-9a-f-]{36}/notifications
          - /orgs/[0-9a-f-]{36}/persons_of_interest
          - /orgs/[0-9a-f-]{36}/persons_of_interest/[0-9a-f-]{36}
          - /orgs/[0-9a-f-]{36}/sensors/[0-9a-f-]{36}/sensor_data
          - /orgs/[0-9a-f-]{36}/sensors/alerts
          - /ping
          - /stream/cameras/v1/footage/stream/[\w\-. +%]+
          - /token
          - /viewing_station/v1/devices
      - host: apiadmin.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/orgs/[0-9a-f-]{36}/v2/apikeys
          - /admin/orgs/[0-9a-f-]{36}/v2/apikeys/[\w\.\-]+
          - /admin/orgs/[0-9a-f-]{36}/v2/granular_apikeys
          - /admin/orgs/[0-9a-f-]{36}/v2/webhookconfig
          - /integrations/auror/auth
          - /integrations/auror/export
          - /integrations/axon_evidence/auth
          - /integrations/axon_evidence/cases/[0-9a-f-]{36}/get
          - /integrations/axon_evidence/categories/[0-9a-f-]{36}/get
          - /integrations/axon_evidence/export
          - /integrations/config/[0-9a-f-]{36}/[0-9a-f-]{36}/delete_config
          - /integrations/config/[0-9a-f-]{36}/get_config
          - /integrations/config/get_available_integrations
          - /integrations/config/set_config
        unauthenticatedEndpoints:
          - /access/v1/access_groups
          - /access/v1/access_groups/group
          - /access/v1/access_groups/group/user
          - /access/v1/access_users
          - /access/v1/access_users/user
          - /access/v1/access_users/user/ble/activate
          - /access/v1/access_users/user/ble/deactivate
          - /access/v1/access_users/user/end_date
          - /access/v1/access_users/user/entry_code
          - /access/v1/access_users/user/pass/invite
          - /access/v1/access_users/user/profile_photo
          - /access/v1/access_users/user/remote_unlock/activate
          - /access/v1/access_users/user/remote_unlock/deactivate
          - /access/v1/access_users/user/start_date
          - /access/v1/access_users_photos_api
          - /access/v1/access_users_photos_api/user
          - /access/v1/credentials/card
          - /access/v1/credentials/card/activate
          - /access/v1/credentials/card/deactivate
          - /access/v1/credentials/license_plate
          - /access/v1/credentials/license_plate/activate
          - /access/v1/credentials/license_plate/deactivate
          - /access/v1/credentials/mfa_code
          - /access/v1/door/admin_unlock
          - /access/v1/door/exception_calendar
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}/exception
          - /access/v1/door/exception_calendar/[0-9a-f-]{36}/exception/[0-9a-f-]{36}
          - /access/v1/door/user_unlock
          - /access/v1/doors
          - /admin/access_v1/openapi\.json
          - /admin/alarms_v1/openapi\.json
          - /admin/camera_v1/openapi\.json
          - /admin/core_v1/openapi\.json
          - /admin/guest_v1/openapi\.json
          - /admin/openapi/openapi\.json
          - /admin/ping
          - /admin/sensor_v1/openapi\.json
          - /admin/tokens/openapi\.json
          - /admin/viewing_station_v1/openapi\.json
          - /alarms/v1/devices
          - /alarms/v1/sites
          - /cameras/v1/alerts
          - /cameras/v1/analytics/dashboard_occupancy_trends
          - /cameras/v1/analytics/lpr/images
          - /cameras/v1/analytics/lpr/license_plate_of_interest
          - /cameras/v1/analytics/lpr/license_plate_of_interest/batch
          - /cameras/v1/analytics/lpr/timestamps
          - /cameras/v1/analytics/max_object_counts
          - /cameras/v1/analytics/object_counts
          - /cameras/v1/analytics/object_position_mqtt
          - /cameras/v1/analytics/occupancy_trends
          - /cameras/v1/audio/status
          - /cameras/v1/cloud_backup/settings
          - /cameras/v1/config
          - /cameras/v1/devices
          - /cameras/v1/feature
          - /cameras/v1/footage/link
          - /cameras/v1/footage/thumbnails
          - /cameras/v1/footage/thumbnails/latest
          - /cameras/v1/footage/thumbnails/link
          - /cameras/v1/footage/token
          - /cameras/v1/occupancy_trend_enabled
          - /cameras/v1/people/person_of_interest
          - /cameras/v1/video_tagging/event
          - /cameras/v1/video_tagging/event/search
          - /cameras/v1/video_tagging/event_type
          - /core/v1/audit_log
          - /core/v1/user
          - /environment/v1/alerts
          - /environment/v1/data
          - /events/v1/access
          - /guest/v1/deny_list
          - /guest/v1/sites
          - /guest/v1/visits
          - /orgs/[0-9a-f-]{36}/auditlog
          - /orgs/[0-9a-f-]{36}/cameras
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/fullres
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/history/[0-9]+
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/latest
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/objects/counts
          - /orgs/[0-9a-f-]{36}/cameras/[0-9a-f-]{36}/thumbnail/[0-9]+
          - /orgs/[0-9a-f-]{36}/license_plate_of_interest
          - /orgs/[0-9a-f-]{36}/license_plate_of_interest/[\w\.\-]+
          - /orgs/[0-9a-f-]{36}/notifications
          - /orgs/[0-9a-f-]{36}/persons_of_interest
          - /orgs/[0-9a-f-]{36}/persons_of_interest/[0-9a-f-]{36}
          - /orgs/[0-9a-f-]{36}/sensors/[0-9a-f-]{36}/sensor_data
          - /orgs/[0-9a-f-]{36}/sensors/alerts
          - /ping
          - /stream/cameras/v1/footage/stream/[\w\-. +%]+
          - /token
          - /viewing_station/v1/devices
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vpublicapi
    namespace: vinfra
    resourceVersion: "2416989517"
    uid: 887ad45e-b30e-45a4-82a6-9e67ad0727c6
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vrasr.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /api/devices
          - /api/devices/[0-9a-f-]{36}
          - /api/devices/traffic-split
          - /api/get-service
          - /api/insert-routing-rules
          - /api/list-services
          - /api/users
          - /api/users/[0-9a-f-]{36}
          - /api/v2/get-service
          - /api/v2/insert-routing-rules
          - /ping
          - /vadmission/add-app-and-version-to-whitelist
          - /vadmission/add-app-to-whitelist
          - /vadmission/add-whitelist
          - /vadmission/is-locked-down
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vrasr
    namespace: vinfra
    resourceVersion: "2158702340"
    uid: e5e89928-28f0-4ae4-b093-878c7cc51cb1
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
      - host: vscim.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /ping
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
      - host: scim.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /org/scim_provider/[0-9a-f-]{36}
          - /org/scim_provider/create
          - /org/scim_provider/delete
          - /org/scim_provider/edit
          - /org/scim_provider/regenerate_token
        unauthenticatedEndpoints:
          - /ping
          - /scim/Groups
          - /scim/Groups/[0-9a-f-]{36}
          - /scim/ServiceProviderConfig
          - /scim/Users
          - /scim/Users/[0-9a-f-]{36}
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vscim
    namespace: vinfra
    resourceVersion: "2417982147"
    uid: 4b1efa46-1c14-4392-b8be-a040bf6ca72a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /exemplars/get
          - /exemplars/upload
          - /face/known_face\.jpg
          - /faces/timeline_summary
          - /hyperzoom/person/search
          - /hyperzoom/person/update_search_result
          - /identity/add_profile_photo
          - /identity/bulk/get
          - /identity/bulk/update
          - /identity/create
          - /identity/get
          - /identity/list
          - /identity/list/tag/all
          - /identity/merge
          - /identity/search_by_image
          - /identity/unmerge
          - /identity/update
          - /person/cross_camera_search
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /exemplars/get
          - /exemplars/upload
          - /face/known_face\.jpg
          - /faces/timeline_summary
          - /hyperzoom/person/search
          - /hyperzoom/person/update_search_result
          - /identity/add_profile_photo
          - /identity/bulk/get
          - /identity/bulk/update
          - /identity/create
          - /identity/get
          - /identity/list
          - /identity/list/tag/all
          - /identity/merge
          - /identity/search_by_image
          - /identity/unmerge
          - /identity/update
          - /person/cross_camera_search
      - host: vsearchapi.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /appearance_search/org/[0-9a-f-]{36}
          - /audio/transcriptions
          - /custom_detections/org/[0-9a-f-]{36}
          - /custom_event/delete
          - /custom_event/download
          - /custom_event/get
          - /custom_event/search
          - /custom_event/update
          - /custom_event_type/create
          - /custom_event_type/delete
          - /custom_event_type/get
          - /custom_event_type/update
          - /exemplars/get
          - /exemplars/upload
          - /face/known_face\.jpg
          - /get_objects_info/org/[0-9a-f-]{36}
          - /hyperzoom/mark_wrong_detection
          - /hyperzoom/sensor_data
          - /hyperzooms/get_cv_enabled_cameras
          - /hyperzooms/get_cv_enabled_cameras_by_org
          - /identity/add_profile_photo
          - /identity/bulk/get
          - /identity/bulk/update
          - /identity/create
          - /identity/get
          - /identity/list
          - /identity/merge
          - /identity/search_by_image
          - /identity/unmerge
          - /identity/update
          - /nlp_events/org/[0-9a-f-]{36}/create
          - /nlp_events/org/[0-9a-f-]{36}/delete
          - /nlp_events/org/[0-9a-f-]{36}/get
          - /nlp_events/org/[0-9a-f-]{36}/preview
          - /nlp_motion_search/org/[0-9a-f-]{36}
          - /nlp_search/backfill/[0-9a-f-]{36}
          - /nlp_search/org/[0-9a-f-]{36}
          - /nlp_search/suggestions/[0-9a-f-]{36}
          - /nlp_search/user_opt_in/[0-9a-f-]{36}
          - /person/cross_camera_search
          - /person_attributes/org/[0-9a-f-]{36}
          - /segment_image/org/[0-9a-f-]{36}
          - /tags/[0-9a-f-]{36}
          - /tags/[0-9a-f-]{36}/entity
          - /tags/[0-9a-f-]{36}/entity/[0-9a-f-]{36}
          - /tags/[0-9a-f-]{36}/entity/[a-zA-Z0-9_-]{20}
          - /tags/create
          - /tags/remove
          - /timeline/object/org/[0-9a-f-]{36}
          - /unusual_activities/get
          - /vehicle/search/[0-9a-f-]{36}
          - /vehicle_attributes/org/[0-9a-f-]{36}
          - /vehicle_attributes/org/[0-9a-f-]{36}/camera/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /internal/custom_event/create
          - /internal/custom_event/delete
          - /internal/custom_event/get
          - /internal/custom_event/search
          - /internal/custom_event/update
          - /internal/custom_event_type/create
          - /internal/custom_event_type/delete
          - /internal/custom_event_type/get
          - /internal/custom_event_type/update
          - /nlp_search_feedback/org/[0-9a-f-]{36}
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vsearchapi
    namespace: vinfra
    resourceVersion: "2378623404"
    uid: f82842dc-3b4f-43fe-97ad-b2829a25d463
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsensor.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /devices/[0-9a-f-]{36}/beta/alert_events
          - /devices/[0-9a-f-]{36}/beta/latest_alert_events
          - /devices/batch/commission
          - /devices/commission
        unauthenticatedEndpoints:
          - /vsensor/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vsensor
    namespace: vinfra
    resourceVersion: "2459366587"
    uid: 208ee5b9-8e2b-4ec7-999f-883d9c3d4743
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsensor.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /alert_events/[0-9a-f-]{36}
          - /analytics/alert_events/devices/[0-9a-f-]{36}/summary
          - /analytics/alert_events/most_active_alert_types
          - /analytics/alert_events/sites
          - /analytics/alert_events/sites/[0-9a-f-]{36}
          - /analytics/alert_events/sites/[0-9a-f-]{36}/list
          - /analytics/alert_events/sites/[0-9a-f-]{36}/summary
          - /analytics/alert_events/sites/list
          - /analytics/alert_events/sites/summary
          - /calibration/[0-9a-f-]{36}
          - /calibration/[0-9a-f-]{36}/certificate
          - /calibration/history/[0-9a-f-]{36}
          - /calibration/list
          - /dashboards
          - /dashboards/[0-9a-f-]{36}
          - /dashboards/[0-9a-f-]{36}/live_link/devices
          - /dashboards/list
          - /dashboards/live_link/can_manage
          - /dashboards/live_link/create
          - /dashboards/live_link/share
          - /device/status
          - /devices/[0-9a-f-]{36}
          - /devices/[0-9a-f-]{36}/alert_configs
          - /devices/[0-9a-f-]{36}/alert_events
          - /devices/[0-9a-f-]{36}/alerts/csv
          - /devices/[0-9a-f-]{36}/data/audio
          - /devices/[0-9a-f-]{36}/data/csv
          - /devices/[0-9a-f-]{36}/feedback/alert_events
          - /devices/[0-9a-f-]{36}/get_user_preferences
          - /devices/[0-9a-f-]{36}/latest_alert_events
          - /devices/[0-9a-f-]{36}/set_user_preferences
          - /devices/[0-9a-f-]{36}/thumbnail
          - /devices/alert_configs/list
          - /devices/batch/alert_configs
          - /devices/batch/move
          - /devices/batch/settings
          - /devices/batch/status
          - /devices/decommission
          - /devices/list
          - /devices/org/alert_events
          - /devices/version/system/download/[\w\.\-]+
          - /devices/version/system/latest
          - /licensing/[0-9a-f-]{36}
          - /user_preferences
          - /vmss_config/delete
          - /vmss_config/device/get/[0-9a-f-]{36}
          - /vmss_config/get/[0-9a-f-]{36}
          - /vmss_config/list
          - /vmss_config/set
          - /vmss_device_status/get/[0-9a-f-]{36}
          - /vmss_device_status/set
          - /vsensorconfig/batch/config
          - /vsensorconfig/batch/config/list
          - /vsensorconfig/config/[0-9a-f-]{36}
          - /vsensorconfig/reload/[0-9a-f-]{36}
          - /vsensorconfig/ws/[0-9a-f-]{36}
          - /zones
          - /zones/[0-9a-f-]{36}
          - /zones/[0-9a-f-]{36}/preferences
          - /zones/ongoing_alert_event_readings/[0-9a-f-]{36}
          - /zones/ongoing_alert_events/[0-9a-f-]{36}
          - /zones/preferences
        unauthenticatedEndpoints:
          - /ping
          - /vsensorconfig/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vsensorconfig
    namespace: vinfra
    resourceVersion: "2459366588"
    uid: 986b3da9-1b9a-47f0-a4ed-b2ebbcfea45e
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsensor.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /query
          - /query_latest/[0-9a-f-]{36}
          - /vsensordata/batch/aggregated_query
          - /vsensordata/sensor/[0-9a-f-]{36}/audio/aac/[\w\-. +%]+\.aac
          - /vsensordata/sensor/[0-9a-f-]{36}/audio/manifest\.m3u8
          - /vsensordata/sensor/[0-9a-f-]{36}/backup_data
          - /vsensordata/sensor/[0-9a-f-]{36}/backup_data_ts
          - /vsensordata/sensor/[0-9a-f-]{36}/ws
        unauthenticatedEndpoints:
          - /vsensordata/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vsensordata
    namespace: vinfra
    resourceVersion: "2158702164"
    uid: e0fa8f30-fe74-4abf-bff7-070f9b566f91
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsight.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /[0-9a-f-]{36}/[0-9a-f-]{36}/agreements
          - /[0-9a-f-]{36}/[0-9a-f-]{36}/sign_agreement
          - /[0-9a-f-]{36}/device/agreements
          - /context_camera/camera/[0-9a-f-]{36}
          - /license_plates/org/[0-9a-f-]{36}/get_appearance_summary
          - /license_plates/org/[0-9a-f-]{36}/get_num_appearances
          - /license_plates/org/[0-9a-f-]{36}/user_get
          - /lpoi/csv_upload/org/[0-9a-f-]{36}
          - /lpoi/org/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vsight
    namespace: vinfra
    resourceVersion: "2158702162"
    uid: b21ef655-6687-4e8f-a75f-07e53ccbde29
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /stream/[0-9a-f-]{36}
          - /stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/bytes/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mp4/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
        unauthenticatedEndpoints:
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /vstream/ping
      - host: vstream.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /stream/[0-9a-f-]{36}
          - /stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/bytes/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mp4/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
        unauthenticatedEndpoints:
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /vstream/ping
      - host: vstream-sec.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /filter/stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /stream/[0-9a-f-]{36}
          - /stream/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/bytes/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mediasource/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
          - /stream/mp4/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*
        unauthenticatedEndpoints:
          - /filter/stream/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /filter/transcode/[\w\-. ]+/[0-9a-f-]{36}/(?i)[^/]*(high|low|audio|tiny|hevc_tiny|low_res|high_res|tiny_res|hevc_tiny_res)+[^/]*/[\w\-. +%]+
          - /vstream/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vstream
    namespace: vinfra
    resourceVersion: "2383832388"
    uid: 1e20ba6d-9b3f-4005-bf08-2ab8b192f48f
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vproxy.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /rtc/[0-9a-f-]{36}/viewerConnectionDetails
          - /rtc/kinesisvideo/createSignalingChannel
          - /rtc/kinesisvideo/deleteSignalingChannel
          - /rtc/kinesisvideo/describeSignalingChannel
          - /rtc/kinesisvideo/getSignalingChannelEndpoint
          - /rtc/kinesisvideo/v1/get-ice-server-config
        unauthenticatedEndpoints:
          - /rtc/ping
      - host: vstream.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /rtc/[0-9a-f-]{36}/viewerConnectionDetails
          - /rtc/kinesisvideo/createSignalingChannel
          - /rtc/kinesisvideo/deleteSignalingChannel
          - /rtc/kinesisvideo/describeSignalingChannel
          - /rtc/kinesisvideo/getSignalingChannelEndpoint
          - /rtc/kinesisvideo/v1/get-ice-server-config
        unauthenticatedEndpoints:
          - /rtc/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vstreamrtc
    namespace: vinfra
    resourceVersion: "2158702199"
    uid: 0a536142-9c67-445b-8ca8-122ac460c5d5
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/retention_trigger/check
          - /camera/submit_transformation_matrix
          - /camera/transformation_matrix/calculate
          - /camera_poi/get_embedding_encryption_key
          - /camera_poi/get_org_pois
          - /camera_poi/get_org_pois_v2
          - /cameras/get_region
          - /cameras/set_region
          - /get/camera/resource/accessibility
          - /library/background
          - /library/calibration_image\.jpg
          - /library/closest_thumb\.jpg
          - /library/cloud_retention
          - /library/count_people
          - /library/detected_objects
          - /library/exact_thumb\.gif
          - /library/exact_thumb\.jpg
          - /library/exact_thumb\.json
          - /library/exact_thumb\.webp
          - /library/exemplar\.jpg
          - /library/fullres\.jpg
          - /library/fullres\.json
          - /library/get_seen_labels
          - /library/grid_10x10\.jpg
          - /library/grid_5x5\.jpg
          - /library/hyperzoom
          - /library/hyperzoom\.jpg
          - /library/latest\.jpg
          - /library/motion_coverage
          - /library/motion_search
          - /library/object_search
          - /library/object_search/v2
          - /library/object_stats
          - /library/object_tracking_hyperzoom\.jpg
          - /library/objects_in_range
          - /library/persistent_change
          - /library/representing_thumb_times
          - /library/thumb\.jpg
          - /library/timelapse\.m3u8
          - /library/timelapse\.mp4
          - /library/timelapse\.ts
          - /library/tracked_objects
          - /license_plates/org/[0-9a-f-]{36}/get
          - /object_tracking/restore_backup
          - /org/get_region
          - /org/set_region
          - /set/camera/resource/accessibility
          - /stats
          - /submit/fullres/[0-9a-f-]{36}/[0-9]+
          - /submit/hyperzoom/[0-9]+/[0-9]+
          - /submit/motion_rollup
          - /submit/object_tracking/upload_url
          - /submit/object_tracking_hyperzoom/[0-9_-]+
          - /submit/raw_frame/[0-9]+
          - /submit/raw_frame_detections/[0-9]+
          - /submit/stats
          - /submit/thumbnail/[0-9a-f-]{36}/[0-9]+
          - /submit/thumbnail_detection/[0-9]+
          - /thumbnail/upload/url
          - /v1/floor_plan/get_history_heat_map
          - /v1/floor_plan/get_history_heat_map_cell
        unauthenticatedEndpoints:
          - /ping
          - /submit/persistent_change
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /camera/retention_trigger/check
          - /camera/submit_transformation_matrix
          - /camera/transformation_matrix/calculate
          - /camera_poi/get_embedding_encryption_key
          - /camera_poi/get_org_pois
          - /camera_poi/get_org_pois_v2
          - /cameras/get_region
          - /cameras/set_region
          - /get/camera/resource/accessibility
          - /library/background
          - /library/calibration_image\.jpg
          - /library/closest_thumb\.jpg
          - /library/cloud_retention
          - /library/count_people
          - /library/detected_objects
          - /library/exact_thumb\.gif
          - /library/exact_thumb\.jpg
          - /library/exact_thumb\.json
          - /library/exact_thumb\.webp
          - /library/exemplar\.jpg
          - /library/fullres\.jpg
          - /library/fullres\.json
          - /library/get_seen_labels
          - /library/grid_10x10\.jpg
          - /library/grid_5x5\.jpg
          - /library/hyperzoom
          - /library/hyperzoom\.jpg
          - /library/latest\.jpg
          - /library/motion_coverage
          - /library/motion_search
          - /library/object_search
          - /library/object_search/v2
          - /library/object_stats
          - /library/object_tracking_hyperzoom\.jpg
          - /library/objects_in_range
          - /library/persistent_change
          - /library/representing_thumb_times
          - /library/thumb\.jpg
          - /library/timelapse\.m3u8
          - /library/timelapse\.mp4
          - /library/timelapse\.ts
          - /library/tracked_objects
          - /license_plates/org/[0-9a-f-]{36}/get
          - /object_tracking/restore_backup
          - /org/get_region
          - /org/set_region
          - /set/camera/resource/accessibility
          - /stats
          - /submit/fullres/[0-9a-f-]{36}/[0-9]+
          - /submit/hyperzoom/[0-9]+/[0-9]+
          - /submit/motion_rollup
          - /submit/object_tracking/upload_url
          - /submit/object_tracking_hyperzoom/[0-9_-]+
          - /submit/raw_frame/[0-9]+
          - /submit/raw_frame_detections/[0-9]+
          - /submit/stats
          - /submit/thumbnail/[0-9a-f-]{36}/[0-9]+
          - /submit/thumbnail_detection/[0-9]+
          - /thumbnail/upload/url
          - /v1/floor_plan/get_history_heat_map
          - /v1/floor_plan/get_history_heat_map_cell
        unauthenticatedEndpoints:
          - /ping
          - /submit/persistent_change
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vsubmit
    namespace: vinfra
    resourceVersion: "2158702347"
    uid: f6fd6264-4dcc-46d0-a8f8-3caade0aff24
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsuite.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /is_internal_user
          - /ping
        unauthenticatedEndpoints:
          - /log_user_session
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vsuite
    namespace: vinfra
    resourceVersion: "2158702154"
    uid: 85930aa8-7970-4ec8-8a9b-c8c5f9c054da
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsupertest.staging2.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /ping
          - /proxy/[\w\.\-]+/[\w\.\-]+/((.+)\/)*([^\/]+)
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vsupertest
    namespace: vinfra
    resourceVersion: "2158702157"
    uid: 0c530b5f-d81d-4e3b-a84e-6b24ea42bf53
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/cropped_thumbnail
          - /library/hyperzoom_by_track\.jpg
          - /library/hyperzoom_metadata_by_track
          - /library/video/enckey
          - /library/video/init\.mp4
          - /library/video/playlist\.m3u8
          - /library/video\.gif
          - /library/video_thumb\.jpg
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/cropped_thumbnail
          - /library/hyperzoom_by_track\.jpg
          - /library/hyperzoom_metadata_by_track
          - /library/video/enckey
          - /library/video/init\.mp4
          - /library/video/playlist\.m3u8
          - /library/video\.gif
          - /library/video_thumb\.jpg
      - host: vthumb.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /library/cropped_thumbnail
          - /library/hyperzoom_by_track\.jpg
          - /library/hyperzoom_metadata_by_track
          - /library/video/enckey
          - /library/video/init\.mp4
          - /library/video/playlist\.m3u8
          - /library/video\.gif
          - /library/video_thumb\.jpg
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vthumb
    namespace: vinfra
    resourceVersion: "2158702155"
    uid: 24ca6850-418d-4eb0-940c-abb0715f8a4a
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
        unauthenticatedEndpoints:
          - /vtoolbox/public/feature_flags/set_usage
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support_window/become
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
        unauthenticatedEndpoints:
          - /vtoolbox/public/feature_flags/set_usage
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support_window/become
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
        unauthenticatedEndpoints:
          - /vtoolbox/public/feature_flags/set_usage
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support_window/become
      - host: vsupportapi.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/feature_flags/set_usage
          - /vtoolbox/public/get_ffu_assets
          - /vtoolbox/public/get_ffu_assets_granular
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/become
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
      - host: vtoolbox.staging2.cf.verkada.com
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/feature_flags/set_usage
          - /vtoolbox/public/get_ffu_assets
          - /vtoolbox/public/get_ffu_assets_granular
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/become
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
      - host: vtoolbox.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vsupportapi/public/support_window/create
          - /vsupportapi/public/support_window/edit
          - /vsupportapi/public/support_window/get
          - /vsupportapi/public/user/support_video_access_expiration
          - /vtoolbox/public/feature_flags/set_usage
          - /vtoolbox/public/get_ffu_assets
          - /vtoolbox/public/get_ffu_assets_granular
          - /vtoolbox/public/motion_test/camera_get
          - /vtoolbox/public/motion_test/camera_set
          - /vtoolbox/public/motion_test/get_results
          - /vtoolbox/public/motion_test/store_results
          - /vtoolbox/public/support/camera/config/get
          - /vtoolbox/public/support/camera/config/set
          - /vtoolbox/public/support/set_feature_flag
          - /vtoolbox/public/support_window/become
          - /vtoolbox/public/support_window/create
          - /vtoolbox/public/support_window/edit
          - /vtoolbox/public/support_window/get
          - /vtoolbox/public/user/support_video_access_expiration
      - host: vtoolbox.staging2.internal.vcamera.net
        authCheckTrafficWeight: 100
        unauthenticatedEndpoints:
          - /api/feature_flags/all
          - /api/feature_flags/delete
          - /api/feature_flags/organization
          - /api/feature_flags/rename
          - /api/feature_flags/set_sample_size
          - /api/feature_flags/update_metadata
          - /api/feature_flags/update_team_name
          - /api/feature_flags/user
          - /api/global/fanout_gui
          - /api/user/create_feature_flag
          - /api/user/set_global_feature_flag
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vtoolbox
    namespace: vinfra
    resourceVersion: "2417982155"
    uid: ca0a4df8-e4fc-4a86-999d-87b4f18440e6
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vprovision.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
          - /vviewers/sites/streaminfo
          - /vviewers/streams/kickout
          - /vviewers/web/audioevent
          - /vviewers/web/faceblur
          - /vviewers/web/ws
      - host: vprovision.us.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
          - /vviewers/sites/streaminfo
          - /vviewers/streams/kickout
          - /vviewers/web/audioevent
          - /vviewers/web/faceblur
          - /vviewers/web/ws
      - host: device-gateway.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
          - /vviewers/sites/streaminfo
          - /vviewers/streams/kickout
          - /vviewers/web/audioevent
          - /vviewers/web/faceblur
          - /vviewers/web/ws
      - host: vproxy.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
        unauthenticatedEndpoints:
          - /vviewers/ping
      - host: vstream.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vviewers/device/submit
          - /vviewers/device/submit/history
        unauthenticatedEndpoints:
          - /vviewers/ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vviewers
    namespace: vinfra
    resourceVersion: "2417982150"
    uid: 4a239979-7a87-44b4-8035-7dd3d1ad6fcc
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vvx.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /admin/set_device_verkada_serial_number
          - /device/available_os_updates
          - /device/commission
          - /device/decommission
          - /device/ensure_state
          - /device/list
          - /device/os_update_status
          - /device/restart
          - /device/schedule_os_update_download
          - /device/schedule_os_update_install
          - /device/vx_os_update_status
          - /device/wifi/set
          - /devices/cameraHistoryInfo
          - /internal/viewing_station/firewall_test
          - /socket\.io/
          - /viewing_station/add_device_signing_key
          - /viewing_station/batch/status
          - /viewing_station/doors
          - /viewing_station/firewall/result
          - /viewing_station/firewall/targets
          - /viewing_station/firewall_test
          - /viewing_station/gateway/attached
          - /viewing_station/gateway/attached_devices
          - /viewing_station/get_shared_organization_key_id
          - /viewing_station/grid/banner
          - /viewing_station/grid/update
          - /viewing_station/init
          - /viewing_station/metrics
          - /viewing_station/retrieve_device_key_sharing_key
          - /viewing_station/retrieve_encrypted_customer_keys
          - /viewing_station/share_keys
          - /viewing_station/status
          - /viewing_station/update
          - /viewing_station/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+\.jpg
          - /viewing_station/user/photos/[0-9a-f-]{36}/[0-9a-f-]{36}/[\w\-. +%]+\.png
          - /viewing_station/user_info/[0-9a-f-]{36}
          - /viewing_station/users/[0-9a-f-]{36}
        unauthenticatedEndpoints:
          - /ping
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vvx
    namespace: vinfra
    resourceVersion: "2180408402"
    uid: ce4613c0-4150-45bb-a755-5d4756bcd1b4
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vsubmit.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vworlddetect/test
      - host: vsubmit-global.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /vworlddetect/test
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2024-11-23T01:57:36Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-vworlddetect
    namespace: vinfra
    resourceVersion: "2158702203"
    uid: 3c41dee2-0796-41d9-8363-56a635f547df
- apiVersion: v1
  data:
    config.yaml: |
      domain: vshield-auth-bypass
      authCheckExceptions:
      - host: vpava.staging2.vcamera.net
        authCheckTrafficWeight: 100
        authenticatedEndpoints:
          - /web-api/devices/[0-9a-f-]{36}/decommission
          - /web-api/devices/[0-9a-f-]{36}/update
          - /web-api/media
          - /web-api/media/[a-zA-Z0-9-]+
          - /web-api/organizations/[0-9a-f-]{36}/devices
  kind: ConfigMap
  metadata:
    annotations:
      argocd.argoproj.io/sync-options: Replace=true
    creationTimestamp: "2025-01-14T16:13:38Z"
    labels:
      app.kubernetes.io/instance: routing
      pattern: vshield-auth-check-bypass-component
    name: vshield-auth-check-bypass-web-api
    namespace: vinfra
    resourceVersion: "2459366585"
    uid: b2591c3e-482c-44d1-b2f1-e45e3322556a
kind: List
metadata:
  resourceVersion: ""
)";

// Bypass config for staging
const std::string& auth_bypass_config_yaml = auth_bypass_config_yaml_staging;
