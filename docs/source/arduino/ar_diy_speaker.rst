.. _ar_rgb:

6.9 DIY Speaker
==============================================

Introduction
This document describes a project that involves playing audio files using an ESP32 microcontroller. The aim of the project is to provide a simple solution for playing audio files using the XT_DAC_Audio library on the ESP32.

Project Principle
The project involves the use of the XT_DAC_Audio library to play audio files stored in the SoundData.h file. The audio data is played through the internal DAC of the ESP32. The XT_Wav_Class is used to load the audio data from the SoundData.h file. The XT_DAC_Audio_Class is used to play the audio data through the internal DAC of the ESP32.

Related Precautions
When using the internal DAC of the ESP32, it is important to note that the output voltage level is limited to 1.1V. Therefore, it is recommended to use an external amplifier to boost the output voltage level to the desired level. It is also important to ensure that the audio data is in the correct format and sample rate to prevent distortion or noise during playback.

Operating Steps
To use the project, follow the steps below:

Connect the speaker to the R and L pins of the ESP32

Upload the code to the ESP32

The audio data is stored in the SoundData.h file. Open the file and replace the sample data with the audio data in WAV format.

Play the audio by running the code on the ESP32.

Code Explanation
The code starts by including the necessary libraries and creating an instance of the XT_Wav_Class and XT_DAC_Audio_Class. The XT_Wav_Class is configured with the audio data stored in the SoundData.h file. The XT_DAC_Audio_Class is configured with the pin number of the DAC and the channel number.

The "FillBuffer()" method of the XT_DAC_Audio_Class is called to fill the audio buffer. When the audio file is not playing, the "Play()" method of the XT_DAC_Audio_Class is called to start playing the audio.

The "loop()" function is used to continuously fill the audio buffer and play the audio. The demo counter is also incremented and printed to the serial monitor.

In summary, this project provides a simple solution for playing audio files using the internal DAC of the ESP32. It is important to note the precautions when using the internal DAC and ensure that the audio data is in the correct format and sample rate.



播放SD卡内的音乐




To modify the code to play music stored on an SD card, you will need to make the following changes:

Include the necessary libraries for SD card access. You can use the "SD.h" library for this purpose.
arduino
Copy
#include <driver/rtc_io.h>
#include <SD.h>
#include "SoundData.h"
#include "XT_DAC_Audio.h"
Initialize the SD card in the "setup()" function. You will need to specify the pin used for the SD card reader and call the "begin()" method.
Copy
const int chipSelect = 4; // replace with the chip select pin you are using
SD.begin(chipSelect);
Load the audio data from the SD card instead of the SoundData.h file. You will need to read the audio data from the SD card and pass it to the XT_Wav_Class constructor.
Copy
File audioFile = SD.open("filename.wav"); // replace with the name of your audio file
XT_Wav_Class Sound(audioFile);
Modify the "loop()" function to read the audio data from the SD card and play it using the XT_DAC_Audio_Class. You will need to modify the "FillBuffer()" and "Play()" methods to read from the SD card instead of the SoundData.h file.
clojure
Copy
void loop() {
  DacAudio.FillBuffer();
  if(Sound.Playing==false) {
    Sound.LoadNextBlock(); // read the next block of audio data from the SD card
    DacAudio.Play(&Sound);
  }
  Serial.println(DemoCounter++);
}
The modified code should look like this:

arduino
Copy
#include <driver/rtc_io.h>
#include <SD.h>
#include "XT_DAC_Audio.h"

//R,L connect to GPIO25
XT_DAC_Audio_Class DacAudio(25,0);

File audioFile;
XT_Wav_Class Sound(audioFile);
uint32_t DemoCounter=0;

void setup() {
  Serial.begin(115200);
  const int chipSelect = 4; // replace with the chip select pin you are using
  SD.begin(chipSelect);
  audioFile = SD.open("filename.wav"); // replace with the name of your audio file
  Sound = XT_Wav_Class(audioFile);
}

void loop() {
  DacAudio.FillBuffer();
  if(Sound.Playing==false) {
    Sound.LoadNextBlock(); // read the next block of audio data from the SD card
    DacAudio.Play(&Sound);
  }
  Serial.println(DemoCounter++);
}
Note: Make sure that your audio file is in WAV format and has a sample rate and bit depth supported by the ESP32's internal DAC.



