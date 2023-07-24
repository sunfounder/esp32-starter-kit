const int buzzerPin = 14; //buzzer pin
const int resolution = 8; 

// Frequencies of the 7 musical notes (in Hz)
int frequencies[] = {262, 294, 330, 349, 392, 440, 494};


// Function to play a frequency on the buzzer for a given duration
void playFrequency(int frequency, int duration) {
  ledcWriteTone(0, frequency); // Start the tone
  delay(duration); // Wait for the specified duration
  ledcWriteTone(0, 0); // Stop the buzzer
}

void setup() {
  ledcSetup(0, 2000, resolution); // Set up the PWM channel
  ledcAttachPin(buzzerPin, 0); // Attach the buzzer pin to the PWM channel
}

void loop() {
  for (int i = 0; i < 7; i++) {
    playFrequency(frequencies[i], 300); // Play each note for 300ms
    delay(50); // Add a brief pause between the notes
  }
  delay(1000); // Wait for 1 second before replaying the sequence
}
