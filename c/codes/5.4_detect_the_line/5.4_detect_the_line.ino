// Set pin number
const int linePin = 14;  // The number of the line track module pin

// Variable for storing the line status 
int lineState = 0;

void setup() {
  Serial.begin(115200);  
  // Initialize the line track module pin as an input
  pinMode(linePin, INPUT);
}

void loop() {
  // Read the state of the line track module
  lineState = digitalRead(linePin);

  if (lineState == HIGH) {
    Serial.println("Black");
    delay(100);
  }
  else {
    Serial.println("White");
    delay(100);
  }
}
