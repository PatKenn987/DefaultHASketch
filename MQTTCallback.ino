#include "settings.h"

  String response;
  char tempbuffer[128];

/*This callback function will be called when an MQTT Topic that has been subscribed to is received.
 * In order to subscribe to a topic, you must modify the code in the reconnect() function. The idea 
 * is to keep the topics generic (Topic0, Topic1, etc) to make it easier to maintain the code.  All
 * topics are defined in settings.h
 * 
 * 
 */

void mqtt_callback(char* topic, byte* payload, unsigned int length){  
  for (int i = 0; i < length; i++) {
    response += (char)payload[i];
  }
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  Serial.println(response);
  
  strcpy(tempbuffer, response.c_str());
/*********************************************/

  if (strcmp(topic, TOPIC_TEMP_CONF) == 0)
  {
    if (strcmp(tempbuffer, Topic0OnState)== 0)
    {
      Device = ON;
      client.publish(Topic0State, Topic0OnState);
      Serial.println(Topic0OnState);
    }
    else
    {
      Device = OFF; 
      client.publish(Topic0State, Topic0OffState);
      Serial.println(Topic0OffState);
    }
    //client.publish(Attribute_Topic0, msg);
  }
/*********************************************  
  if (strcmp(topic, Availiblity_Topic0) == 0)
  {
    //const char * OnlineText = "online";
    if (strcmp(tempbuffer, "online")== 0)
    {
      sensorState = ENABLED;
      //client.publish(Availiblity_Topic0, "online");
      Serial.println("online");
    }
    else
    {
      sensorState = DISABLED;
      //client.publish(Availiblity_Topic0, "offline");
      Serial.println("offline");
    }    
  }*/
}


