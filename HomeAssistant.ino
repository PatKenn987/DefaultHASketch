
/*  
light:
  - platform: mqtt
    unique_id: "0462" 
    name: "Example_Light"
    command_topic: "room/light"
    state_topic: "room/light/state"
    payload_on: "on"
    payload_off: "off"    
    availability_topic: "room/light/availibility"
    payload_available: "online"
    payload_not_available: "offline"    
    json_attributes_topic: "room/WifiStatus"
    json_attributes_template: >
      {"RSSI":"{{value}}"}

sensor:
  - platform: mqtt
    name: "Temperature"
    state_topic: "MyBedRoom/TempHumSensor1"
    unit_of_measurement: '°C'
    value_template: "{{ value_json.temperature }}"
  - platform: mqtt
    name: "Humidity"
    state_topic: "MyBedRoom/TempHumSensor1"
    unit_of_measurement: '%'
    value_template: "{{ value_json.humidity }}"
    

sensor:
  - platform: mqtt
    name: "RSSI"
    device_class: signal_strength
    unique_id: "0463" 
    state_topic: "MyBedRoom/WifiRSSI/"
    unit_of_measurement: 'dBm'
 
*/
