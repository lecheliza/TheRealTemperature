#include <LiquidCrystal.h>

//LCD pins
const uint8_t RS = 2;
const uint8_t E = 3;
const uint8_t D4 = 4;
const uint8_t D5 = 5;
const uint8_t D6 = 6;
const uint8_t D7 = 7;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

//hc-sr04 pins
const uint8_t echo = 11;
const uint8_t trig = 12;

//global temp vars
float temperature1 = 0.0, temperature2 = 0.0, realTemperature = 0.0;

void readFromSerialToFloats(float &t1, float &t2) {
  String data = Serial.readString();
  t1 = data.substring(0, data.indexOf(' ')).toFloat();
  t2 = data.substring(data.indexOf(' ')).toFloat();
}

void setup() {
  Serial.begin(9600);
  readFromSerialToFloats(temperature1, temperature2);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  lcd.clear();
  lcd.print("Temp: ");
  long distance = 0L, takenTime = 0L;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  takenTime = pulseIn(echo, HIGH);
  distance = takenTime / 58;

  temperature1 = 0.0;
  temperature2 = 0.0;
  realTemperature = 0.0;
  
  readFromSerialToFloats(temperature1, temperature2);
  
  float difference = abs(temperature2 - temperature1);
  
  if (difference < 10) {
    realTemperature = (temperature1 + temperature2) / 2;
  } else {
    realTemperature = min(temperature1, temperature2);
  }
  lcd.print(realTemperature);
  if (distance > 0 && distance <= 50)
    lcd.display();
  else
    lcd.noDisplay();

  delay(15000);
}
