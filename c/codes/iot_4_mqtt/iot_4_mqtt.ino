/*********
  :ref: https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/
  https://docs.sunfounder.com/projects/kepler-kit/en/latest/iotproject/5.mqtt_pub.html
*********/

#include <WiFi.h>
#include <PubSubClient.h>
//#include <Wire.h>

// Replace the next variables with your SSID/Password combination
const char* ssid = "SSID";
const char* password = "PASSWORD";

// Add your MQTT Broker address, example:
const char* mqtt_server = "broker.hivemq.com";
const char* unique_identifier = "sunfounder-client-sdgvsda";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
int value = 0;


// LED Pin
const int ledPin = 4;
const int buttonPin = 14;

// When you connect to WIFI, only 36 39 34 35 32 33 pins can be used for analog reading.
// Define constants
const int thermistorPin = 36; // Pin connected to the thermistor
const float referenceVoltage = 3.3;
const float referenceResistor = 10000; // Resistance value (10k)
const float beta = 3950; // Beta value (Typical Value)
const float nominalTemperature = 25; // Nominal temperature for calculating the temperature coefficient
const float nominalResistance = 10000; // Resistance value at nominal temperature



void setup() {
  Serial.begin(115200);

  // default settings
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // If a message is received on the topic "SF/LED", you check if the message is either "on" or "off".
  // Changes the output state according to the message
  if (String(topic) == "SF/LED") {
    Serial.print("Changing state to ");
    if (messageTemp == "on") {
      Serial.println("on");
      digitalWrite(ledPin, HIGH);
    } else if (messageTemp == "off") {
      Serial.println("off");
      digitalWrite(ledPin, LOW);
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(unique_identifier)) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("SF/LED");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

float thermistor() {
  int adcValue = analogRead(thermistorPin); // Read ADC value
  float voltage = (adcValue * referenceVoltage) / 4095.0; // Calculate voltage
  float resistance = (voltage * referenceResistor) / (referenceVoltage - voltage); // Calculate thermistor resistance with updated configuration

  // Calculate temperature using the Beta parameter equation
  float tempK = 1 / (((log(resistance / nominalResistance)) / beta) + (1 / (nominalTemperature + 273.15)));
  
  float tempC = tempK - 273.15; // Get temperature in Celsius
  float tempF = 1.8 * tempC + 32.0; // Get temperature in Fahrenheit

  //Print temperature
  Serial.print("Temp: ");
  Serial.println(tempC);
  delay(200); //wait for 200 milliseconds
  return tempC;
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // if the button pressed, publish the temperature to topic "SF/TEMP"
  if (digitalRead(buttonPin)) {
    long now = millis();
    if (now - lastMsg > 5000) {
      lastMsg = now;
      char tempString[8];
      dtostrf(thermistor(), 1, 2, tempString);
      client.publish("SF/TEMP", tempString);
    }
  }
}