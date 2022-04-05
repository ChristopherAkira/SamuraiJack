#include <WiFi.h>
#include <AsyncTCP.h>
#include "Adafruit_VL53L0X.h"
#include "VL_Funcs.h"



//#define OTA 
#ifdef OTA
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
AsyncWebServer server(80);
const char* ssid = "HASHI";
const char* password = "GETWICKED";
#endif




void setup(void) {
  Serial.begin(115200);
  #ifdef OTA
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
  });

  AsyncElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();
  Serial.println("HTTP server started");
  #endif

}

void loop(void) {
}