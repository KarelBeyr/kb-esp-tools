#ifndef Thingspeak_h
#define Thingspeak_h
//#include "tools.h"
#include "Arduino.h"

//void maybeInquireThingspeak(State *state);
void logMessageToThingspeak(String err);
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1);
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2);
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3);
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4);
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4, String d5);
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4, String d5, String d6);
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4, String d5, String d6, String d7);
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4, String d5, String d6, String d7, String d8);

#endif
