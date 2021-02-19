#include <strings.h>
#ifndef SETTINGS_H
#define SETTINGS_H

//Template Libraries
#include <FS.h>                   
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
//NTPClient and WiFiUDP required for NTP
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
//********************************************
//Device Specific Libraries
#include <DHTesp.h>
//********************************************
//Device Specific
#define DHTTYPE DHT11
#define DHTPIN  5 //D1
//********************************************
//Template values

#define FALSE 0
#define TRUE 0

/* Parameters for WiFiMgr.  This feature will allow the AP, ESSID, MQTT server, 
*  MQTT User Name and Password to be defined at start up via a web interface to avoid including them
*  in the source files*/
//Connect TRIGGER_PIN (D7) to Gnd to enable Wifi feature.  This should be done at initial startup
#define TRIGGER_PIN D7
#define MQTT_PORT 1883

/*WiFi Mgr provides the ability to store important variables in non-vol on the Arduino
/These variables (Wifi AP, Wifi Password, MQTT Server, MQTT user, MQTT PW, and root MQTT Topic
/are initialized when the device is first run by shorting pins D7 to ground.  This will cause the
/WiFi Mgr to start in AP mode and spin up an HTTP server that can be used to enter the values */
/*These variables are used by WiFi Mgr to configure  MQTT Server, MQTT user, MQTT PW, and root MQTT*/
char mqtt_server[40];
char mqtt_user[40];
char mqtt_password[40];
char mqtt_topic[40];

//flag for saving data.  
bool shouldSaveConfig = false;


/*********************************************************
Sensor State machine - This enumeration is used to track the internal state of the MQTT device.  Currently
it is only for internal debuggin.
***********************************************************/
enum States {
    UN_INIT,
    WIFI_INIT,
    MQTT_INIT,
    INIT,
    ENABLED,
    DISABLED,
};
/*********************************************************
For MQTT devices that accept commands, this variable will store the current value.  This
value is not relevant if the device does not need to process commands. (i.e. a sensor)
It is instantiated in the main module.
*************************************************************/
enum DeviceState {
    ON,
    OFF
};

//MQTT topics
//NOTE: It is critical that all of these text strings are identical to what is included in 
//the configuration.yaml file in Home Assistant
//Sensor

/**IMPORTANT: The device_id and UID must be unique for each MQTT device or else there will be continuous disconnect message**/
char device_id[16];         //This name identifies our device on the MQTT bus. Must be unique
const char *UID = "0432";

#define TOPIC_TEMP_CONF "homeassistant/TempHumSensor1/office_temp/config"


char *Topic0Class ="temperature";

#define MAX_MQTT_TOPIC 128

char Topic0[MAX_MQTT_TOPIC];
char Topic0State[MAX_MQTT_TOPIC];
char Topic0Config[MAX_MQTT_TOPIC];
char *Topic0OnState = "on";
char *Topic0OffState = "off";

char Topic1[MAX_MQTT_TOPIC];
char Topic1State[MAX_MQTT_TOPIC];
char Topic1Config[MAX_MQTT_TOPIC];

char *Topic1OnState = "on";
char *Topic1OffState = "off";

char Topic2[MAX_MQTT_TOPIC];
char Topic2State[MAX_MQTT_TOPIC];
char Topic2Config[MAX_MQTT_TOPIC];

#endif

