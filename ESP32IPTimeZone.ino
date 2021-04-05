#include <WiFiManager.h> 
#include <ESP32IPTimeZone.h>

void initWiFi(){
  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  
#ifdef RESET
  wm.resetSettings();
#endif

  wm.setDebugOutput(false);
  wm.setCountry("au");
  boolean result = wm.autoConnect("LMG-STA","12345678"); 
  if (result) 
    Serial.println("LMG connected");
   else 
    Serial.println("LMG connection failed"); 
}

void setup() {
  Serial.begin(115200);
  delay(4000);
  initWiFi();
  ESP32IPTimeZone IPtz = ESP32IPTimeZone();
  Serial.println(IPtz.getIPTimeZoneS());
  ESP32IPTimeZone::IPTimeZone iptz =IPtz.getIPTimeZone();
  Serial.println("UNIX TIME :" + String(iptz.unixtime));
}

void loop(){  
}
