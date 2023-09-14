// set pin
const int avoidPin = 14;  // the number of the avoid avoid module pin

// variable for storing the avoid status 
int avoidState = 0;

void setup() {
  Serial.begin(115200);  
  // initialize the avoid pin as an input
  pinMode(avoidPin, INPUT);
}

void loop() {
  // read the state of the avoid value
  avoidState = digitalRead(avoidPin);
  Serial.println(avoidState);
}
