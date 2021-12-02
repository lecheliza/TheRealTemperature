#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

//server
const string serverAddress = " ";
unsigned long channelNumber = 1;
const char* writeAPIKey = " ";

//password + ssid
const string ssid = " ";
const string password = " ";

//time things
unsigned long lastTime = 0;
unsigned long timerDelay = 0;

void setup() {
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");  
  }
  Serial.println("Connected to WIFI network with IP address: ");
  Serial.print(WiFi.localIP());
}

void loop() {
  WiFiClient wifi;
  HttpClient http;

  http.begin(wifi, server);
  http.get();
}
