#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include "DHT.h"
#define DHT11_PIN 2 
#define DHTTYPE DHT11

//dht
DHT dht(DHT11_PIN, DHTTYPE);

//server
String server = "api.thingspeak.com";
unsigned long channelNumber = 1;
const char* writeAPIKey = "JH442P18M4DOWYEI";
String readAPIKey = "REG5C56EQ2XIF2NL";

//password + ssid
char* ssid = "iPhone (Eliza)";
char* password = "";

//wifi client
WiFiClient http;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Connecting to");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(http);
}

void loop() {
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
    }
    long t = long(temperature);
  int x = ThingSpeak.writeField(channelNumber, 1, temperature, writeAPIKey); 
  delay(20000);
}
