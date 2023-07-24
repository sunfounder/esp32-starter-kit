#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 13     // Set the pin connected to the DHT11 data pin
#define MOIS_PIN 14 // Soil mOisture module
#define LIGHT_PIN 35 // Photoresistor
#define B_1A 27 // Pump pin
#define B_1B 26 // Pump pin
#define BUTTON 32 // Button

#define DHTTYPE DHT11  // DHT 11
DHT dht(DHTPIN, DHTTYPE);

int page = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(115200);

  // Initialize the dht11
  dht.begin();

  lcd.init();  // initialize the lcd
  lcd.backlight();
  lcd.clear();

  // initialize digital pin as an output.
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);

  pinMode(BUTTON, INPUT);
}

void loop() {

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  lcd.clear();
  // Show message per 2 second
  if ((page++) % 2) {
    // Display temperature and humidity
    lcd.setCursor(0, 0);
    lcd.print("Humi: ");
    lcd.print(humidity);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("\xDF");
    lcd.print("C");
  } else {
    // Display moisture and light sensor values
    lcd.setCursor(0, 0);
    lcd.print("Mois: ");
    lcd.print(analogRead(MOIS_PIN));
    lcd.setCursor(0, 1);
    lcd.print("Light: ");
    lcd.print(analogRead(LIGHT_PIN));
  }
  // Water plant while button pressed
  Serial.println(digitalRead(BUTTON));
  if (digitalRead(BUTTON) == HIGH) {
    // Turn on water pump if button is pressed
    digitalWrite(B_1A, HIGH);
    digitalWrite(B_1B, LOW);
  } else {
    // Turn off water pump if button is not pressed
    digitalWrite(B_1A, LOW);
    digitalWrite(B_1B, LOW);
  }

  delay(2000);
}