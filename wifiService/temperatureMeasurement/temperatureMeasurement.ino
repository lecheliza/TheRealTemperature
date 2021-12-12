#include "DHT.h"
#define DHT11_PIN 2 
#define DHTTYPE DHT11
DHT dht(DHT11_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(6000);

  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.println(temperature);
}
