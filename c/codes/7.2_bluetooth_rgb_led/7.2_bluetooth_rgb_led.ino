#include "BLEDevice.h"
#include "BLEServer.h"
#include "BLEUtils.h"
#include "BLE2902.h"

// Define RGB LED pins
const int redPin = 27;
const int greenPin = 26;
const int bluePin = 25;

// Define PWM frequency and resolution
const int freq = 5000;
const int resolution = 8;

// Define the Bluetooth device name
const char *bleName = "ESP32_Bluetooth";

// Define the received text and the time of the last message
String receivedText = "";
unsigned long lastMessageTime = 0;

// Define the UUIDs of the service and characteristics
#define SERVICE_UUID "8785d8b3-9d23-473b-aee5-3fabe2ba9583"
#define CHARACTERISTIC_UUID_RX "b2bcd13b-aab6-4660-92ae-40abf6941fce"
#define CHARACTERISTIC_UUID_TX "4219d86a-d701-4fd2-bd84-04db50f70fe2"

// Define the Bluetooth characteristic
BLECharacteristic *pCharacteristic;

void setup() {
  Serial.begin(115200);      // Initialize the serial port
  setupBLE();                // Initialize the Bluetooth BLE

  ledcAttach(redPin, freq, resolution);
  ledcAttach(greenPin, freq, resolution);
  ledcAttach(bluePin, freq, resolution);
}

void loop() {
  // When the received text is not empty and the time since the last message is over 1 second
  // Send a notification and print the received text
  if (receivedText.length() > 0 && millis() - lastMessageTime > 1000) {
    Serial.print("Received message: ");
    Serial.println(receivedText);
    pCharacteristic->setValue(receivedText.c_str());
    pCharacteristic->notify();
    receivedText = "";
  }

  // Read data from the serial port and send it to BLE characteristic
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    const char *newValue = str.c_str();
    pCharacteristic->setValue(newValue);
    pCharacteristic->notify();
  }
}

// Define the BLE server callbacks
class MyServerCallbacks : public BLEServerCallbacks {
  // Print the connection message when a client is connected
  void onConnect(BLEServer *pServer) {
    Serial.println("Connected");
  }
  // Print the disconnection message when a client is disconnected
  void onDisconnect(BLEServer *pServer) {
    Serial.println("Disconnected");
  }
};

// Define the BLE characteristic callbacks
class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    std::string value = std::string(pCharacteristic->getValue().c_str());
    if (value == "led_off") {
      setColor(0, 0, 0); // turn the RGB LED off
      Serial.println("RGB LED turned off");
    } else if (value == "red") {
      setColor(255, 0, 0); // Red
      Serial.println("red");
    }
    else if (value == "green") {
      setColor(0, 255, 0); // green
      Serial.println("green");
    }
    else if (value == "blue") {
      setColor(0, 0, 255); // blue
      Serial.println("blue");
    }
    else if (value == "yellow") {
      setColor(255, 150, 0); // yellow
      Serial.println("yellow");
    }
    else if (value == "purple") {
      setColor(80, 0, 80); // purple
      Serial.println("purple");
    }
  }
};

// Initialize the Bluetooth BLE
void setupBLE() {
  BLEDevice::init(bleName);                        // Initialize the BLE device
  BLEServer *pServer = BLEDevice::createServer();  // Create the BLE server
  // Print the error message if the BLE server creation fails
  if (pServer == nullptr) {
    Serial.println("Error creating BLE server");
    return;
  }
  pServer->setCallbacks(new MyServerCallbacks());  // Set the BLE server callbacks

  // Create the BLE service
  BLEService *pService = pServer->createService(SERVICE_UUID);
  // Print the error message if the BLE service creation fails
  if (pService == nullptr) {
    Serial.println("Error creating BLE service");
    return;
  }
  // Create the BLE characteristic for sending notifications
  pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristic->addDescriptor(new BLE2902());  // Add the descriptor
  // Create the BLE characteristic for receiving data
  BLECharacteristic *pCharacteristicRX = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
  pCharacteristicRX->setCallbacks(new MyCharacteristicCallbacks());  // Set the BLE characteristic callbacks
  pService->start();                                                 // Start the BLE service
  pServer->getAdvertising()->start();                                // Start advertising
  Serial.println("Waiting for a client connection...");              // Wait for a client connection
}

void setColor(int red, int green, int blue) {
  // For common-anode RGB LEDs, use 255 minus the color value
  ledcWrite(redPin, red);
  ledcWrite(greenPin, green);
  ledcWrite(bluePin, blue);
}
