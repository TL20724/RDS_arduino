#include <Wire.h>
#include <RH_ASK.h>
#include <LiquidCrystal_I2C.h>
#define MODULE_PIN 10  // Replace with your desired pin
#define RDS_TEXT1 "Radio TEI FM"
#define RDS_TEXT2 "Paizei: ---"

RH_ASK rf_driver;


#define I2C_ADDR 0x27
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);

void setup() {
  Serial.begin(9600);

  if (!rf_driver.init())
  Serial.println("Initialization failed, check your connections");
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(RDS_TEXT1);
  lcd.setCursor(0, 1);
  lcd.print(RDS_TEXT2);
}

void loop() {
  const char* textToSend1 = RDS_TEXT1;
  rf_driver.send((uint8_t*)textToSend1, strlen(textToSend1));
  rf_driver.waitPacketSent();
  delay(5000);
  const char* textToSend2 = RDS_TEXT2;
  rf_driver.send((uint8_t*)textToSend2, strlen(textToSend2));
  rf_driver.waitPacketSent();
  delay(5000);
}
