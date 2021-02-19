/*
 * Module:  MQTTMsgBuild 
 * --------------------
 * This file containts the function required to programattically assemble 
 * the necessary MQTT Topics for the Home Assistant interface              
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
#include "settings.h"

//char *TopicRoot = "DiningRoom";
char *Topic0Root = "TempHum";
char *Topic1Root = "RSSI";
char *Topic2Root = "Oil";

void BuildMQTTMsg()
{
  Serial.println("BuildMQTTMsg");  
  //Read the MAC address and store the last 4 bytes into device_id.  This will ensure the Device ID is unique
  GetMACAddres();

  //***********Setup Topic0 topic name**************
  strcpy(Topic0, mqtt_topic);
  strcat(Topic0, "/");
  Serial.print("Topic0");  
  Serial.println(Topic0);  

  strcat(Topic0, device_id);
  strcat(Topic0, "/");  
  strcat(Topic0, Topic0Root);  
  if(strlen(Topic0) > MAX_MQTT_TOPIC)
    Serial.println("Topic0 too long");

   //***********Setup Topic0 State topic name*******
  strcpy(Topic0State,Topic0);
  strcat(Topic0State, "/");
  strcat(Topic0State, "state");
  if(strlen(Topic0State) > MAX_MQTT_TOPIC)
    Serial.println("Topic0State too long");
  //***********Setup Topic0Command topic name*******
  strcpy(Topic0State,Topic0);
  strcat(Topic0State, "/");
  strcat(Topic0State, "state");
  if(strlen(Topic0State) > MAX_MQTT_TOPIC)
    Serial.println("Topic0State too long");
    
  //***********Setup Topic0 Config topic name********
  strcpy(Topic0Config,Topic0);
  strcat(Topic0Config, "/");
  strcat(Topic0Config, "config");
  if(strlen(Topic0Config) > MAX_MQTT_TOPIC)
    Serial.println("Topic0Config too long"); 
     
  //Print out the MQTT message strings for Topic 0
  Serial.print("Topic 0 =");
  Serial.println(Topic0);
  Serial.print("Topic 0 State =");
  Serial.println(Topic0State);
  Serial.print("Topic 0 Config =");
  Serial.println(Topic0Config);

/************************************************
  ***********Setup Topic1 topic name ***********/
  strcpy(Topic1, mqtt_topic);
  strcat(Topic1, "/");
  strcat(Topic1, device_id);
  strcat(Topic1, "/");  
  strcat(Topic1, Topic1Root); 

  //***********Setup Topic1 State topic name*******
  strcpy(Topic1State,Topic1);
  strcat(Topic1State, "/");
  strcat(Topic1State, "state");
  if(strlen(Topic1State) > MAX_MQTT_TOPIC)
    Serial.println("Topic1State too long");
    
  //***********Setup Topic1 Config topic name********
  strcpy(Topic1Config,Topic1);
  strcat(Topic1Config, "/");
  strcat(Topic1Config, "config");
  if(strlen(Topic1Config) > MAX_MQTT_TOPIC)
    Serial.println("Topic1Config too long"); 

  //Print out the MQTT message strings for Topic 1
  Serial.print("Topic 1 =");
  Serial.println(Topic1);
  Serial.print("Topic 1 State =");
  Serial.println(Topic1State);
  Serial.print("Topic 1 Config =");
  Serial.println(Topic1Config); 
  Serial.println();

/************************************************
  ***********Setup Topic2 topic name ***********/
  strcpy(Topic2, mqtt_topic);
  strcat(Topic2, "/");
  strcat(Topic2, device_id);
  strcat(Topic2, "/");  
  strcat(Topic2, Topic2Root); 

  //***********Setup Topic1 State topic name*******
  strcpy(Topic2State,Topic2);
  strcat(Topic2State, "/");
  strcat(Topic2State, "state");
  if(strlen(Topic2State) > MAX_MQTT_TOPIC)
    Serial.println("Topic1State too long");
    
  //***********Setup Topic1 Config topic name********
  strcpy(Topic2Config,Topic2);
  strcat(Topic2Config, "/");
  strcat(Topic2Config, "config");
  if(strlen(Topic2Config) > MAX_MQTT_TOPIC)
    Serial.println("Topic2Config too long"); 

  //Print out the MQTT message strings for Topic 1
  Serial.print("Topic 2 =");
  Serial.println(Topic2);
  Serial.print("Topic 2 State =");
  Serial.println(Topic2State);
  Serial.print("Topic 2 Config =");
  Serial.println(Topic2Config); 
  Serial.println();
  
}

