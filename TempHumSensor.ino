#include "settings.h"

void publishTempConfig() {  
  const size_t bufferSize = JSON_OBJECT_SIZE(8);
  DynamicJsonBuffer jsonBuffer(bufferSize);
  JsonObject& root = jsonBuffer.createObject();

  String jsonVal="{{value_json."+String(Topic0Class)+"}}";
  Serial.print("PublishTempConfig");
  Serial.println(jsonVal);

  root["name"] = Topic0Root;
  root["dev_cla"] = Topic0Class;
  root["stat_t"] = Topic0State;
  root["unit_of_meas"] = "°F";
  //root["val_tpl"] = "{{value_json.temperature}}";
  root["val_tpl"] = String(jsonVal);

  root["pl_avail"] = "online";
  root["pl_not_avail"] = "offline";
  // root["uniq_id"] = mqtt_clientId"_temp";
  root.prettyPrintTo(Serial);
  Serial.println("");
  char message[256];
  root.printTo(message, sizeof(message));
  client.publish(Topic0Config, message, true);
}

bool checkBound(float newValue, float prevValue, float maxDiff) {
  return !isnan(newValue) &&
         (newValue < prevValue - maxDiff || newValue > prevValue + maxDiff);
}


// function called to publish the temperature and the humidity
void publishData(float p_temperature, float p_humidity) {
  // create a JSON object
  // doc : https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  // INFO: the data must be converted into a string; a problem occurs when using floats...
  root["temperature"] = (String)p_temperature;
  root["humidity"] = (String)p_humidity;
  root.prettyPrintTo(Serial);
  Serial.println("");
  /*
     {
        "temperature": "23.20" ,
        "humidity": "43.70"
     }
  */
  char data[200];
  root.printTo(data, root.measureLength() + 1);
  client.publish(Topic0, data, true);
  yield();
}


float temp = 0.0;
float hum = 0.0;
float diff = 1.0;

void UpdateSensorData(void)
{
    float newTemp = dht.getTemperature();
    float newHum = dht.getHumidity();

    publishData(newTemp, newHum);

/*
    if (checkBound(newTemp, temp, diff)) {
      temp = newTemp;
      Serial.print("New temperature:");
      Serial.println(String(temp).c_str());
      client.publish(Topic0, String(temp).c_str(), true);
    }

    //if (checkBound(newHum, hum, diff)) {
      hum = newHum;
      Serial.println("New humidity:");
      Serial.print(Topic0);
      Serial.println(String(hum).c_str());
      client.publish((const char*)Topic0, String(hum).c_str(), true);
      //Serial.print(Topic0);
    //}
 */
}


