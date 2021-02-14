
/*  
 *   
Note: In MQTTBuild.ino, there are three important variables that must be unique to 
each sensor on the HA MQTT server

char *TopicRoot = "DiningRoom";
char *Topic0Root = "Temp";
char *Topic1Root = "RSSI";



sensor 1:
      platform: mqtt
      state_topic: 'DiningRoom/DRTempSense'
      name: 'Temperature'
      unit_of_measurement: '°C'
      value_template: '{{ value_json.temperature }}'
    
sensor 2:
      platform: mqtt
      state_topic: 'DiningRoom/DRTempSense'
      name: 'Humidity'
      unit_of_measurement: '%'
      value_template: '{{ value_json.humidity }}'
      
sensor 6:
    platform: mqtt
    name: "RSSIyMyOffice"
    state_topic: 'DiningRoom/DRTempSense/RSSI'
    unit_of_measurement: 'dBm'
    value_template: "{{ value_json.RSSI }}"
*/
