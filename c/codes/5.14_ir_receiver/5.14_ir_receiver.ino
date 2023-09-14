#include <IRremoteESP8266.h>
#include <IRrecv.h>

// Define the IR receiver pin
const uint16_t IR_RECEIVE_PIN = 14;

// Create an IRrecv object
IRrecv irrecv(IR_RECEIVE_PIN);

// Create a decode_results object
decode_results results;

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Start the IR receiver
  irrecv.enableIRIn();
}

void loop() {
  // If an IR signal is received
  if (irrecv.decode(&results)) {
    String key = decodeKeyValue(results.value);
    if (key != "ERROR") {
      // Print the value of the signal to the serial monitor
      Serial.println(key);
    }
    irrecv.resume(); // Continue to receive the next signal
  }
}

// Function to decode the value of the IR signal
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