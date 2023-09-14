// Define the pins used for the 74hc595 and button
const int STcp = 27;//ST_CP
const int SHcp = 26;//SH_CP 
const int DS = 25; //DS 
const int buttonPin = 13;

// Define an array of values to display numbers on a 7-segment display
int datArray[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int buttonState = false;

void setup ()
{
  // Set the button pin to input mode
  pinMode(buttonPin,INPUT); 

  //Set pins to 74hc595
  pinMode(STcp,OUTPUT);
  pinMode(SHcp,OUTPUT);
  pinMode(DS,OUTPUT);
}

void loop()
{
  // Check if the button is pressed
  if(digitalRead(buttonPin) == LOW)
  {
    // Generate a random number between 1 and 6
    int diceNumber = random(1, 7);

     // Display the number on the 7-segment display
    show_number(diceNumber);

    // Delay for 50 milliseconds
    delay(50);
  }
}

// Function to display a number on a 7-segment display
void show_number(int num)
{
  // Ground ST_CP and hold low for as long as you are transmitting
  digitalWrite(STcp, LOW);

  // Send the data for the number to the shift register
  shiftOut(DS, SHcp, MSBFIRST, datArray[num]);

  // Pull the ST_CP to save the data
  digitalWrite(STcp, HIGH);
}