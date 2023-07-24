// set pin numbers
const int buttonPin = 14;  // Button pin
const int ledPin = 26;     // LED pin

// variable for storing the button status
int buttonState = 0;

void setup() {
  Serial.begin(115200);
  // initialize the button pin as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the state of the button value
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  delay(100);
  // if the button is pressed, the buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    digitalWrite(ledPin, HIGH);

  } else {
    // turn LED off
    digitalWrite(ledPin, LOW);
  }
}
