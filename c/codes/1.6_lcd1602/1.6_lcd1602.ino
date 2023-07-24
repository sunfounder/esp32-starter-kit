#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//SDA->21,SCL->22 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int count = 0;

void setup()
{
  lcd.init();// initialize the lcd 
  lcd.backlight(); // Turns on the LCD backlight.
  lcd.print("Hello, world!");   // Print a message to the LCD.
  delay(3000);
}

void loop()
{
  lcd.clear(); 
  lcd.setCursor(0, 0); // Sets the cursor position to the first row and first column (0, 0).
  lcd.print("COUNT: ");
  lcd.print(count); // Prints the current value of the count variable.
  delay(1000);
  count++; // Increments the counter by 1. 
}
