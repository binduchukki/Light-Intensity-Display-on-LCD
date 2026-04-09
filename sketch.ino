#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int ldrPin = A0;
int ledPin = 9;

void setup()
 {
  pinMode(ledPin, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light:");
  lcd.print(ldrValue);

  lcd.setCursor(0, 1);

  if (ldrValue < 500) {
    digitalWrite(ledPin, HIGH);
    lcd.print("Dark - Light ON");
  } 
  else {
    digitalWrite(ledPin, LOW);
    lcd.print("Bright-Light OFF");
  }

  delay(500);
}