#define motor1A 13
#define motor2A 14

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);  
}

// the loop function runs over and over again forever
void loop() {

  // Rotate
  digitalWrite(motor1A, HIGH);     
  digitalWrite(motor2A, LOW);   
  delay(5);

  // Stop
  digitalWrite(motor1A, LOW);     
  digitalWrite(motor2A, LOW);    
  delay(2000); // wait for a second
}
