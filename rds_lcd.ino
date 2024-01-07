#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR 0x27
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  Radio Tei FM");
  lcd.setCursor(0, 1);
  lcd.print("Paizei twra: ---");
}
