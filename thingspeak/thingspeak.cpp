#include <Arduino.h>
#include "thingspeak.h"
#include "debugUtils.h"
#include <WiFi.h>
#include <HTTPClient.h>
unsigned long lastConnectionTime = 0;

const char *thingSpeakServer = "api.thingspeak.com";

void postDataToThingspeak(String data, String apiKey)
{
    WiFiClient client;
    DEBUG_PRINTLN("Posting data to thingspeak");
    DEBUG_PRINTLN(data);
    if (!client.connect(thingSpeakServer, 80))
    {
        DEBUG_PRINTLN("connection failed");
        client.stop();
        return;
    }
    else
    {
        if (client.connect(thingSpeakServer, 80))
        {
            client.println("POST /update HTTP/1.1");
            client.println("Host: api.thingspeak.com");
            client.println("Connection: close");
            client.println("User-Agent: ESP32WiFi/1.1");
            client.println("X-THINGSPEAKAPIKEY: " + apiKey);
            client.println("Content-Type: application/x-www-form-urlencoded");
            client.print("Content-Length: ");
            client.print(data.length());
            client.print("\n\n");
            client.print(data);
        }
    }

    unsigned long timeout = millis();
    while (client.available() == 0) {
        if (millis() - timeout > 5000) {
            DEBUG_PRINTLN(">>> Client Timeout !");
            client.stop();
            return;
        }
    }

    // Read all the lines of the reply from server and print them to Serial
    while(client.available()) {
        String line = client.readStringUntil('\r');
    }

    client.stop();
}

void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4, String d5, String d6, String d7, String d8)
{
    if (millis() - lastConnectionTime > interval)
    {
        String data = "field1=" + d1 + "&field2=" + d2 + "&field3=" + d3 + "&field4=" + d4 + "&field5=" + d5 + "&field6=" + d6 + "&field7=" + d7 + "&field8=" + d8;
        postDataToThingspeak(data, apiKey);
        lastConnectionTime = millis();
    } else {
        DEBUG_PRINTLN("Thing speak not sending because it was too soon");
    }
}

void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1) { maybeLogTelemetryToThingspeak(apiKey, interval, d1, "0", "0", "0", "0", "0", "0", "0"); }
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2) { maybeLogTelemetryToThingspeak(apiKey, interval, d1, d2, "0", "0", "0", "0", "0", "0"); }
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3) { maybeLogTelemetryToThingspeak(apiKey, interval, d1, d2, d3, "0", "0", "0", "0", "0"); }
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4) { maybeLogTelemetryToThingspeak(apiKey, interval, d1, d2, d3, d4, "0", "0", "0", "0"); }
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4, String d5) { maybeLogTelemetryToThingspeak(apiKey, interval, d1, d2, d3, d4, d5, "0", "0", "0"); }
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4, String d5, String d6) { maybeLogTelemetryToThingspeak(apiKey, interval, d1, d2, d3, d4, d5, d6, "0", "0"); }
void maybeLogTelemetryToThingspeak(String apiKey, unsigned long interval, String d1, String d2, String d3, String d4, String d5, String d6, String d7) { maybeLogTelemetryToThingspeak(apiKey, interval, d1, d2, d3, d4, d5, d6, d7, "0"); }

String iso8601date() {
    int month, day, year;
    char buff[16];
    static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
    sscanf(__DATE__, "%s %d %d", buff, &day, &year);
    month = (strstr(month_names, buff)-month_names)/3+1;
    sprintf(buff, "%d%02d%02d.txt", year, month, day);
    String res(buff);
    return res;
}

String iso8601time() {
    String res = "";
    String input(__TIME__);
    res = res + input.substring(0, 2) + input.substring(3,5);
    return res;
}

void logMessageToThingspeak(String message)
{
//   String data = "field1=0&field2=" + iso8601date()
//      + "&field3=" + iso8601time()
//     + "&field4=" + message;
//   postDataToThingspeak(data, "xx");
}
