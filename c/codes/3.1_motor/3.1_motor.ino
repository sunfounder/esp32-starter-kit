#define B_1A 13
#define B_1B 14

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);  
}

// the loop function runs over and over again forever
void loop() {
  
  // Rotate
  digitalWrite(B_1A, HIGH);     
  digitalWrite(B_1B, LOW);   
  delay(1000); 

  // Rotate in the opposite direction
  digitalWrite(B_1A, LOW);     
  digitalWrite(B_1B, HIGH);    
  delay(1000); 

  // Stop
  digitalWrite(B_1A, LOW);     
  digitalWrite(B_1B, LOW);    
  delay(2000);
}

