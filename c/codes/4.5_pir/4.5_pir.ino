// set pin numbers
const int pirPin = 14;  // the number of the pir pin
const int ledPin = 26;     // LED pin

// variable for storing the pir status 
int pirState = 0;

void setup() {
  Serial.begin(115200);  
  // initialize the pir pin as an input
  pinMode(pirPin, INPUT);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the state of the pir value
  pirState = digitalRead(pirPin);
  Serial.println(pirState);
  delay(100);

  // if the pir is pressed, the pirState is HIGH
  if (pirState == HIGH) {
    // turn LED on
    digitalWrite(ledPin, HIGH);

  } else {
    // turn LED off
    digitalWrite(ledPin, LOW);
  }
}
