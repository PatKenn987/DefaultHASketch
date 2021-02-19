#include "settings.h"

#define DEBUG 0

void PublishRSSI(void)
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char Temp[20];
  // INFO: the data must be converted into a string; a problem occurs when using floats...
//  Serial.printf("RSSI: %d dBm\n", WiFi.RSSI());
  sprintf(Temp, "%d", WiFi.RSSI());
  
  root["RSSI"] = (String)Temp;
  root.prettyPrintTo(Serial);
  Serial.println("");

  char data[200];
  root.printTo(data, root.measureLength() + 1);
  client.publish(Topic1, data, true);
  yield();
}

void GetMACAddres(void)
{
  byte mac[7];                     // the MAC address of your Wifi shield
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  Serial.print(mac[5],HEX);
  Serial.print(":");
  Serial.print(mac[4],HEX);
  Serial.print(":");
  Serial.print(mac[3],HEX);
  Serial.print(":");
  Serial.print(mac[2],HEX);
  Serial.print(":");
  Serial.print(mac[1],HEX);
  Serial.print(":");
  Serial.println(mac[0],HEX);
  mac[6] = 0x00;
  
  sprintf(device_id, "%2.2X%2.2X%2.2X%2.2X",mac[3], mac[2], mac[1], mac[0]);
  Serial.print("device_id = ");
  Serial.println(device_id);
}

/*
void GetConnectionInfo(void)
{
    WiFi.macAddress(ConInfo.macAddr);
    Serial.printf("RSSI: %d dBm\n", WiFi.RSSI());

    if(1 == DEBUG){
    Serial.println();
    Serial.printf("MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", ConInfo.macAddr[0], ConInfo.macAddr[1], ConInfo.macAddr[2], ConInfo.macAddr[3], ConInfo.macAddr[4], ConInfo.macAddr[5]);

    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.print("Subnet mask: ");
    Serial.println(WiFi.subnetMask());

    Serial.printf("Gataway IP: %s\n", WiFi.gatewayIP().toString().c_str());

    Serial.print("DNS #1, #2 IP: ");
    WiFi.dnsIP().printTo(Serial);
    Serial.print(", ");
    WiFi.dnsIP(1).printTo(Serial);
    Serial.println();

    Serial.printf("Default hostname: %s\n", WiFi.hostname().c_str());
    //WiFi.hostname("Station_Tester_02");
    //Serial.printf("New hostname: %s\n", WiFi.hostname().c_str());

    Serial.printf("SSID: %s\n", WiFi.SSID().c_str());

    Serial.printf("SSID: %s\n", WiFi.psk().c_str());

    Serial.printf("BSSID: %s\n", WiFi.BSSIDstr().c_str());

    Serial.printf("RSSI: %d dBm\n", WiFi.RSSI());

    //WiFi.printDiag(Serial);
    }
}
*/


