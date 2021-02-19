
/*  
Note: In MQTTBuild.ino, the BuildMQTTMsg() function will construct the various MQTT messages
that are required to communicate with Home Assistant.  Implementation and use of all of these 
message is WIP, but all of the currently known messages that are required are constructed in this
function, even if they are not yet used.

Based on what I have seen/read, MQTT message for Home Assistant take the form of
root/ID/command - Not applicable for a device that just reports data.  If a command is required
(Even just an Enable command) this is what is used (ex.  This would be  used to turn a switch on/off) 
root/ID/state - For a sensor, reports back the data associated with the sensor.  
root/ID/configuration - I beleive that this is used to allow for automatic configuration of a device on 
the MQTT network.  I don't have this working yet

There are a few different variables that are used to assemble these messages
root = This is configured with the WiFi Mgr.  Refer to the comments in settings.h for how this works
The value of "root" is defined in the mqtt_topic[] string.
ID = This value is the last 4 bytes of the MAC Address of the device.  This ensures that the MQTT message will be unique

It is critical that messages are unique on the MQTT channel.  




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
