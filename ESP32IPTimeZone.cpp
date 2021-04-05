#include <ESP32IPTimeZone.h>

 String ESP32IPTimeZone::getIPTimeZoneS(){
  String result = "ERROR_NO_NETWORK";
  String url=ipLocSvr+"/"+request;
  if(WiFi.status()== WL_CONNECTED){   
    HTTPClient http;
    DEBUGPRINT("Connect to "+url);
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode == 200) 
        result = http.getString();
    else 
        result = "ERROR"+String(httpCode);
    http.end();
  };
  DEBUGPRINT("RESULT: "+ result);
  return result;
 }

ESP32IPTimeZone::IPTimeZone ESP32IPTimeZone::getIPTimeZone(){
  #define SIZE 768
  IPTimeZone ipTZ;
  ipTZ.status = true;
  DynamicJsonDocument doc(SIZE);
  deserializeJson(doc, getIPTimeZoneS());
  ipTZ.abbreviation=doc["abbreviation"].as<String>();
  ipTZ.datetime = doc["datetime"].as<String>();
  ipTZ.day_of_week = doc["day_of_week"].as<uint8_t>();
  ipTZ.day_of_year = doc["day_of_year"].as<uint16_t>();
  ipTZ.dst = doc["dst"].as<boolean>();
  ipTZ.dst_from = doc["dst_from"].as<String>();
  ipTZ.dst_offset = doc["dst_offset"].as<int>();
  ipTZ.dst_until = doc["dst_until"].as<String>();
  ipTZ.raw_offset = doc["raw_offset"].as<long int>();
  ipTZ.timezone = doc["timezone"].as<String>();
  ipTZ.unixtime = doc["unixtime"].as<long int>();
  ipTZ.utc_datetime = doc["utc_datetime"].as<String>();
  ipTZ.utc_offset = doc["utc_offset"].as<String>();
  ipTZ.week_number = doc["week_number"].as<uint8_t>();
  return ipTZ;
}
 
