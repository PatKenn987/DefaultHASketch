#include "settings.h"

//Class instantiations
WiFiClient espClient;
PubSubClient client(espClient);
WiFiUDP ntpUDP;
DHTesp dht;

// By default 'pool.ntp.org' is used with 60 seconds update interval and
// no offset.   -18000 is UTC - 5 hours or EST
NTPClient timeClient(ntpUDP,"pool.ntp.org", -18000, 60000);

extern void SetupWifi(void);
extern void GetConnectionInfo(void);
extern void mqtt_callback(char* topic, byte* payload, unsigned int length);
extern void PublishRSSI(void);
extern void BuildMQTTMsg(void);
extern void publishTempConfig(void);
extern void UpdateSensorData(void);

enum States sensorState;
enum DeviceState Device;

#define TEN_SECS 10000

long lastMsg = 0;

void setup() {
  sensorState = UN_INIT;                //Set the initial state of the internal state machine
  pinMode(TRIGGER_PIN, INPUT_PULLUP);   //Setup the pin that will enable WiFi Mgr mode
  Serial.begin(115200);                 //Enable serial port at 115.2 KBaud
  delay(1000);             
          
  /*******WiFi Setup *******************/       
  SetupWifi();                          //WiFi Mgr call to Init WiFi from non-vol data (or invoke AP Mode)
  delay(5000);
  
  /*******MQTT Setup *******************/
  BuildMQTTMsg();                       //Build all of the MQTT messages for the sensor
  client.setServer(mqtt_server, MQTT_PORT); 
  client.setCallback(mqtt_callback); // Initialize the callback routine

  /*******Initialize state variables *******************/  
  Device = OFF;                       //Initialize the device to off
  
  sensorState = ENABLED;
  timeClient.begin();   //Start NTP Client
  dht.setup(DHTPIN, DHTesp::DHT11); // Connect DHT sensor
  publishTempConfig();
}

void reconnect() {
  Serial.println("Reconnect");
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    Serial.println(client.state());
   
    if (client.connect(device_id, mqtt_user, mqtt_password)) {
      Serial.println("connected");
      sensorState = MQTT_INIT;
    } else {
      sensorState = WIFI_INIT;
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {
   if (!client.connected()) {
     reconnect();
   }
   client.loop();
   timeClient.update();

   long now = millis();
  
   if (now - lastMsg > TEN_SECS) 
   {
     Serial.print("UTC Time = ");
     Serial.println(timeClient.getFormattedTime());
     UpdateSensorData();
     PublishRSSI();
     lastMsg = now;
     Serial.print("mqtt_topic = ");
     Serial.println(mqtt_topic);
   }
   delay(1000);
}

