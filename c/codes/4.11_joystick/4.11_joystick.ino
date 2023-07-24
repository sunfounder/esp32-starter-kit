// Define constants for the x and y axis and the button pins
#define xAxis 34
#define yAxis 35
#define btn 33


void setup() {
  // Initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  // Set the mode of the button pin to input
  pinMode(btn, INPUT);  
}

void loop() {
  // Read the analog value for x,y axis
  int xValue = analogRead(xAxis);
  int yValue = analogRead(yAxis); 

  // Read the digital value from the button pin
  int btnValue = digitalRead(btn);
  
  // print out the values
  Serial.printf("Joystick value is %d , %d , %d \n",xValue,yValue,btnValue);
  
  delay(300);  // Delay between reads
}
