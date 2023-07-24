#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//SDA->21,SCL->22 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


// Define constants
const int thermistorPin = 35; // Pin connected to the thermistor
const float referenceVoltage = 3.3;
const float referenceResistor = 10000; // Resistance value (10k)
const float beta = 3950; // Beta value (Typical Value)
const float nominalTemperature = 25; // Nominal temperature for calculating the temperature coefficient
const float nominalResistance = 10000; // Resistance value at nominal temperature

void setup() {

  lcd.clear(); 
  lcd.init();// initialize the lcd 
  lcd.backlight(); // Turns on the LCD backlight.

  //Serial.begin(115200); // Initialize serial communication
  pinMode(thermistorPin, INPUT); // Set pin as input
}

void loop() {
  int adcValue = analogRead(thermistorPin); // Read ADC value
  float voltage = (adcValue * referenceVoltage) / 4095.0; // Calculate voltage
  float resistance = (voltage * referenceResistor) / (referenceVoltage - voltage); // Calculate thermistor resistance with updated configuration

  // Calculate temperature using the Beta parameter equation
  float tempK = 1 / (((log(resistance / nominalResistance)) / beta) + (1 / (nominalTemperature + 273.15)));
  
  float tempC = tempK - 273.15; // Get temperature in Celsius
  float tempF = 1.8 * tempC + 32.0; // Get temperature in Fahrenheit

  //Print temperature
  //printf("TempC: %.2f C\n", tempC);
  //printf("TempF: %.2f F\n", tempF);

  // Display temperature on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);
  lcd.write(223); // Degree symbol
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(tempF, 1);
  lcd.write(223); // Degree symbol
  lcd.print("F");

  delay(300); // Wait 1 second
}
