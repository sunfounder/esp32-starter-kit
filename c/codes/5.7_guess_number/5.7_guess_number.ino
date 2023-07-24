#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>

// Define the IR receiver pin
const uint16_t IR_RECEIVE_PIN = 14;

// Create an IRrecv object
IRrecv irrecv(IR_RECEIVE_PIN);

// Create a decode_results object
decode_results results;

const long interval = 1000;

unsigned long previousMillis = 0;

// Initialize the LCD object
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialize the input number value
int count = 0;

// Initialize the random lucky point
int pointValue = 0;

// Initialize the upper and lower limit tips
int upper = 99;
int lower = 0;

void setup() {
  // Initialize the LCD screen
  lcd.init();
  lcd.backlight();

  // Start the serial communication
  Serial.begin(9600);

  // Enable the IR receiver
  irrecv.enableIRIn();

  // Initialize a new lucky point value
  initNewValue();
}

void loop() {
  // If a signal is received from the IR receiver
  if (irrecv.decode(&results)) {
    bool result = 0;
    String num = decodeKeyValue(results.value);

    // If the POWER button is pressed
    if (num == "POWER") {
      initNewValue(); // Initialize a new lucky point value
    }

    // If the CYCLE button is pressed
    else if (num == "CYCLE") {
      result = detectPoint(); // Detect the input number
      lcdShowInput(result); // Show the result on the LCD screen
    }

    // If a number button (0-9) is pressed, 
    //add the digit to the input number 
    //and detect the number if it is greater than or equal to 10
    else if (num >= "0" && num <= "9") {
      count = count * 10;
      count += num.toInt();
      if (count >= 10) {
        result = detectPoint();
      }
      lcdShowInput(result);
    }
    irrecv.resume();
  }
}

// Function to initialize a new lucky point value
void initNewValue() {
  // Set the random seed based on the analog value from pin A0
  randomSeed(analogRead(A0));

  // Generate a new random lucky point value
  pointValue = random(99);

  // Reset the upper and lower limit tips
  upper = 99;
  lower = 0;

  // Show the welcome message on the LCD screen
  lcd.clear();
  lcd.print("    Welcome!");
  lcd.setCursor(0, 1);
  lcd.print("Press Any Number");

  // Reset the input number value
  count = 0;

  // Print the lucky point value to the serial monitor
  Serial.print("point is ");
  Serial.println(pointValue);
}

// Detect the input number 
//and update the upper/lower limit tips accordingly
bool detectPoint() {
  if (count > pointValue) {
    if (count < upper)upper = count;
  }
  else if (count < pointValue) {
    if (count > lower)lower = count;
  }

  // If the input number is equal to the lucky point value, 
  else if (count == pointValue) {

    // Reset the input number and return true
    count = 0;
    return 1;
  }
  // Reset the input number and return false
  count = 0;
  return 0;
}

// Show the input number and the upper/lower limit tips
void lcdShowInput(bool result) {
  lcd.clear();

  // If the input number is equal to the lucky point value
  if (result == 1)
  {
    // Show the success message and initialize a new lucky point value
    lcd.setCursor(0, 1);
    lcd.print(" You've got it! ");
    delay(5000);
    initNewValue();
    return;
  }
  lcd.print("Enter number:");
  lcd.print(count);
  lcd.setCursor(0, 1);
  lcd.print(lower);
  lcd.print(" < Point < ");
  lcd.print(upper);
}

// Function to decode the key value from the IR receiver signal
String decodeKeyValue(long result)
{
  switch(result){
    case 0xFF6897:
      return "0";
    case 0xFF30CF:
      return "1"; 
    case 0xFF18E7:
      return "2"; 
    case 0xFF7A85:
      return "3"; 
    case 0xFF10EF:
      return "4"; 
    case 0xFF38C7:
      return "5"; 
    case 0xFF5AA5:
     return "6"; 
    case 0xFF42BD:
      return "7"; 
    case 0xFF4AB5:
      return "8"; 
    case 0xFF52AD:
      return "9"; 
    case 0xFF906F:
      return "+"; 
    case 0xFFA857:
      return "-"; 
    case 0xFFE01F:
      return "EQ"; 
    case 0xFFB04F:
      return "U/SD";
    case 0xFF9867:
      return "CYCLE";         
    case 0xFF22DD:
      return "PLAY/PAUSE";   
    case 0xFF02FD:
      return "BACKWARD";   
    case 0xFFC23D:
      return "FORWARD";   
    case 0xFFA25D:
      return "POWER";   
    case 0xFFE21D:
      return "MUTE";   
    case 0xFF629D:
      return "MODE";       
    case 0xFFFFFFFF:
      return "ERROR";   
    default :
      return "ERROR";
    }
}