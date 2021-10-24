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

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  lcd.clear();
  lcd.print("Temperature: ");
  long distance = 0L, takenTime = 0L;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  takenTime = pulseIn(echo, HIGH);
  distance = takenTime / 58;

  if (distance > 0 && distance <= 50)
    lcd.print(distance);
  else
    lcd.clear();

  delay(1000);
}
