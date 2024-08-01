// Define the musical notes
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523

// Define the buzzer pin and touch pins
const int BUZZER_PIN = 25;
const int TOUCH_PINS[] = { 4, 15, 13, 12, 14, 27, 33, 32 };

const int CHANNEL = 0;  // Use channel 0 of the LEDC module
const int FREQUENCY = 2000; // Set the frequency to 2000 Hz
const int RESOLUTION = 8; // Set the resolution to 8 bits

// Define the musical notes
const int TONE[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 }; 

int threshold = 30;

void setup() {
  Serial.begin(115200);

  // Set the touch pins as inputs
  for (int i = 0; i < 8; i++) {
    pinMode(TOUCH_PINS[i], INPUT);
  }

  ledcAttach(BUZZER_PIN, FREQUENCY, RESOLUTION);  // Initialize the LEDC module
}

void loop() {

  // Loop through each touch pin
  for (int i = 0; i < 8; i++) {

    // Read and print the touch value
    int touchValue = touchRead(TOUCH_PINS[i]);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(touchValue);

    // Check if the current touch pin is being touched
    if (touchValue < threshold) {
      ledcWriteTone(BUZZER_PIN, TONE[i]);  // Write the tone to the LEDC BUZZER_PIN
      delay(150);
      ledcWrite(BUZZER_PIN, 0);  // Turn off the tone by writing 0 to the LEDC channel
    }
  }
}