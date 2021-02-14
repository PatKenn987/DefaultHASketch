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

/*Variables related to MQTT Time out.  If the MQTT server is unavailable, the program will time 
out into the main loop.  This is mostly useful for development and debug when a server is not available*/
int MQTTTimeOut = 0;
bool TimedOut = FALSE;
#define MQTT_TIMEOUT_ATTEMPTS 5

char mqtt_server[40];
char mqtt_user[40];
char mqtt_password[40];
char mqtt_topic[40];

//flag for saving data
bool shouldSaveConfig = false;

//Sensor State machine
enum States {
    UN_INIT,
    WIFI_INIT,
    MQTT_INIT,
    INIT,
    ENABLED,
    DISABLED,
};

enum DeviceState {
    ON,
    OFF
};

//MQTT topics
//NOTE: It is critical that all of these text strings are identical to what is included in 
//the configuration.yaml file in Home Assistant
//Sensor


/**IMPORTANT: The device_id and UID must be unique for each MQTT device or else there will be continuous disconnect message**/
const char *device_id = "DRTempSense";  // This name identifies our device on the MQTT bus. Must be unique
const char *UID = "0432";

#define TOPIC_TEMP_CONF "homeassistant/TempHumSensor1/office_temp/config"

/*
#define TOPIC_TEMP "homeassistant/TempHumSensor1/office_temp"
#define TOPIC_HUM  "homeassistant/TempHumSensor1/office_hum"

#define TOPIC_STATE     "homeassistant/TempHumSensor1/office/state"


#define TOPIC_HUM_CONF  "homeassistant/TempHumSensor1/office_hum/config"
#define TOPIC_STATE     "homeassistant/TempHumSensor1/office/state"

#define TEMP_NAME "OfficeTemp"
#define TEMP_CLASS "temperature"
#define PRESS_NAME "OfficePressure"*/

char *Topic0Class ="temperature";

#define MAX_MQTT_TOPIC 128

char Topic0[MAX_MQTT_TOPIC];
char Topic0State[MAX_MQTT_TOPIC];
char Topic0Config[MAX_MQTT_TOPIC];
char *Topic0OnState = "on";
char *Topic0OffState = "off";

char Topic1[MAX_MQTT_TOPIC];
char Topic1State[MAX_MQTT_TOPIC];
char *Topic1OnState = "on";
char *Topic1OffState = "off";
char Topic1Config[MAX_MQTT_TOPIC];

/*Ultimately the goal is to be able to define the Mqtt messages via the WiFiMgr when the device is
 * installed and have them stored into flash.  I think this will greatly simplify the management 
 * of multiple devices.  However, first step is to be able to calculate the values
 */


/*
 #define humidity_topic "senso/humidity"
#define temperature_topic "senso/temperature"
const char *UniqueID = "0432";
const char *Topic0 = "home/sensor1/infojson";



const char *State_Topic0 = "home/sensor1/state";
const char *State_Topic0OnState = "on";
const char *State_Topic0OffState = "off";

const char *Availiblity_Topic0 = "home/sensor1/status";

const char *Attribute_Topic0 = "home/sensor1/attributes";

const char *Topic1 = "sensor1/";
const char *State_Topic1 = "sensor1/WifiRSSI/";
*/

#endif

