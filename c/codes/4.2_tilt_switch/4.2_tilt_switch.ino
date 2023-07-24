// Set pin numbers
const int tiltPin = 14;  // Tilt Switch
const int ledPin = 26;   // LED

// Variable for storing the tilt status
int tiltState = 0;

void setup() {
  Serial.begin(115200);
  // Initialize the tilt pin as an input
  pinMode(tiltPin, INPUT);
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the state of the tilt switch
  tiltState = digitalRead(tiltPin);

  Serial.println(tiltState);
  // If the switch is upright
  if (tiltState == HIGH) {
    // Turn LED on
    digitalWrite(ledPin, HIGH);

  } else {
    // Turn LED off
    digitalWrite(ledPin, LOW);
  }
}
