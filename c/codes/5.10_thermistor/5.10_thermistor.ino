// Define constants
const int thermistorPin = 35; // Pin connected to the thermistor
const float referenceVoltage = 3.3;
const float referenceResistor = 10000; // the 'other' resistor
const float beta = 3950; // Beta value (Typical Value)
const float nominalTemperature = 25; // Nominal temperature for calculating the temperature coefficient
const float nominalResistance = 10000; // Resistance value at nominal temperature

void setup() {
  Serial.begin(115200); // Initialize serial communication
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
  printf("TempC: %.2f C\n", tempC);
  printf("TempF: %.2f F\n", tempF);

  delay(300); // Wait 1 second
}
