#include "AudioFileSourceSD_MMC.h"
#include "AudioOutputI2S.h"
#include "AudioGeneratorMP3.h"
#include "SD_MMC.h"
#include "FS.h"

// Declare pointers for the MP3 generator, file source, and output.
AudioGeneratorMP3 *mp3;
AudioFileSourceSD_MMC *file;
AudioOutputI2S *out;

void setup() {
  // Start the serial communication.
  Serial.begin(115200);
  delay(1000);

  // Initialize the SD card. If it fails, print an error message.
  if (!SD_MMC.begin()) {
    Serial.println("SD card mount failed!");
  }

  // Open the MP3 file from the SD card. Replace "/To Alice.mp3" with your own MP3 file name.
  file = new AudioFileSourceSD_MMC("/Jingle Bells.mp3");
  
  // Set up the I2S output on ESP32's internal DAC.
  out = new AudioOutputI2S(0, 1);
  
  // Set the output to mono.
  out->SetOutputModeMono(true);

  // Initialize the MP3 generator with the file and output.
  mp3 = new AudioGeneratorMP3();
  mp3->begin(file, out);
}

void loop() {
  // If the MP3 is running, loop it. Otherwise, stop it.
  if (mp3->isRunning()) {
    if (!mp3->loop()) mp3->stop();
  } 
  // If the MP3 is not running, print a message and wait for 1 second.
  else {
    Serial.println("MP3 done");
    delay(1000);
  }
}
