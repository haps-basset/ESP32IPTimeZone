#pragma once

#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#ifdef  DEBUG
#define PRINTP(x)      Serial.println("POINTER => "+String((unsigned long int)&x,HEX))
#define DEBUGPRINT(x)  Serial.println (String(x) + " debug heap " + String(ESP.getHeapSize(),HEX) + "  " + String(ESP.getFreeHeap(),HEX))
#else
#define PRINTP(x)
#define DEBUGPRINT(x)
#endif

class ESP32IPTimeZone {
  private:
    String ipLocSvr = "http://worldtimeapi.org";
    String request = "/api/ip";
  public:
    struct IPTimeZone {
        boolean  status = false;
        String   abbreviation;
        String   datetime;
        uint8_t  day_of_week;
        uint16_t day_of_year;
        boolean  dst;
        String   dst_from;
        int      dst_offset;
        String   dst_until;
        long int raw_offset;
        String   timezone;
        long int unixtime;
        String   utc_datetime;
        String   utc_offset;
        uint8_t  week_number;
        };
    String getIPTimeZoneS();
    IPTimeZone getIPTimeZone();
};
