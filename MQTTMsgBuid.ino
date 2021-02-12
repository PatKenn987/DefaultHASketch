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

char *TopicRoot = "DiningRoom";
char *Topic0Root = "Temp";
char *Topic1Root = "RSSI";

void BuildMQTTMsg()
{
  //***********Setup Topic0 topic name**************
  strcpy(Topic0,TopicRoot);
  strcat(Topic0, "/");
  strcat(Topic0, device_id);
 // strcat(Topic0, "/");  
  //strcat(Topic0, Topic0Root);  
  if(strlen(Topic0) > MAX_MQTT_TOPIC)
    Serial.println("Topic0 too long");
    
  //***********Setup Topic0 State topic name*******
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
  strcpy(Topic1,TopicRoot);
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
}

