6.10 Take Photo SD
============================

Introduction
This document describes a project that involves taking a photo using the ESP32-CAM and saving it to an SD card. The aim of the project is to provide a simple solution for capturing images using the ESP32-CAM and storing them on an SD card.

Project Principle
The project involves the use of the ESP32-CAM to capture images and the SD_MMC library to store them on an SD card. The camera is initialized using the esp_camera library, and the image is captured using the esp_camera_fb_get() function. The image is then saved to the SD card using the SD_MMC library.

Related Precautions
When using the ESP32-CAM, it is important to note that the GPIO 0 pin must be connected to GND to upload a sketch. Additionally, after connecting GPIO 0 to GND, the ESP32-CAM onboard RESET button must be pressed to put the board in flashing mode. It is also important to ensure that the SD card is properly mounted before saving images to it.

Operating Steps
To use the project, follow the steps below:

Connect the ESP32-CAM to your computer using a USB cable.

Select the "AI Thinker ESP32-CAM" board in the Arduino IDE.

Upload the code to the ESP32-CAM.

Make sure that the SD card is properly inserted in the SD card reader.

Disconnect the ESP32-CAM from the computer and power it using a 5V power supply.

The ESP32-CAM will take a photo and save it to the SD card. The file name will be in the format "pictureX.jpg", where X is the picture number.

The ESP32-CAM will enter deep sleep mode to conserve power.

Code Explanation
The code starts by including the necessary libraries for the ESP32-CAM, SD card access, and flash memory access. The pin definitions for the camera are also specified.

The ESP32-CAM is initialized using the esp_camera_init() function, and the SD card is mounted using the SD_MMC.begin() function. The EEPROM library is used to read and write from flash memory.

The camera_fb_t structure is used to capture the image using the esp_camera_fb_get() function. The image is then saved to the SD card using the FILE_WRITE mode of the fs::File class. The picture number is also stored in the EEPROM to ensure that each picture has a unique name.

The ESP32-CAM onboard LED is turned off to conserve power, and the ESP32-CAM enters deep sleep mode using the esp_deep_sleep_start() function.

In summary, this project provides a simple solution for capturing images using the ESP32-CAM and storing them on an SD card. It is important to note the precautions when using the ESP32-CAM and ensure that the SD card is properly mounted before saving images to it.