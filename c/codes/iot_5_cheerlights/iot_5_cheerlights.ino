/*********
  :ref: https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/
  https://docs.sunfounder.com/projects/kepler-kit/en/latest/iotproject/5.mqtt_pub.html
*********/

#include <WiFi.h>
#include <PubSubClient.h>
//#include <Wire.h>
#include <Adafruit_NeoPixel.h>



// Replace the next variables with your SSID/Password combination
const char* ssid = "SSID";
const char* password = "PASSWORD";

// Add your MQTT Broker address:
const char* mqtt_server = "mqtt.cheerlights.com";
const char* unique_identifier = "sunfounder-client-sdgvsasdda";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
int value = 0;


// Define the supported CheerLights colors and their RGB values
String colorName[] = {"red", "pink", "green", "blue", "cyan", "white", "warmwhite", "oldlace", "purple", "magenta", "yellow", "orange"};

int colorRGB[][3] = { 255,   0,   0,  // "red"
                      255, 192, 203,  // "pink"
                        0, 255,   0,  // "green"
                        0,   0, 255,  // "blue"
                        0, 255, 255,  // "cyan"
                      255, 255, 255,  // "white"
                      255, 223, 223,  // "warmwhite"
                      255, 223, 223,  // "oldlace"
                      128,   0, 128,  // "purple"
                      255,   0, 255,  // "magenta"
                      255, 255,   0,  // "yellow"
                      255, 165,   0}; // "orange"

// init rgb strip 
#define LED_PIN 13
#define NUM_LEDS 8

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);

  // wifi default settings
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  // rgb strip begin
  pixels.begin();
  pixels.show(); 

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

  // If a message is received on the topic, you will check this message.
  // Changes the output state according to the message
  if (String(topic) == "cheerlights") {
    Serial.print("Changing color to ");
    Serial.println(messageTemp);
    setColor(messageTemp);
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
      client.subscribe("cheerlights");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setColor(String color) {
  // Loop through the list of colors to find the matching color
  for (int colorIndex = 0; colorIndex < 12; colorIndex++) {
    if (color == colorName[colorIndex]) {
      // Set the color of each NeoPixel on the strip
      for (int pixel = 0; pixel < NUM_LEDS; pixel++) {
        pixels.setPixelColor(pixel, pixels.Color (colorRGB [colorIndex][0], colorRGB [colorIndex][1], colorRGB [colorIndex][2]));
      }
      pixels.show();
    }
  }
}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}