#include "SD_MMC.h"

void setup() {
  Serial.begin(115200); // Initialize serial communication
  if (!SD_MMC.begin()) { // Check if SD card is mounted successfully
    Serial.println("Failed to mount SD card"); // Print error message if SD card failed to mount
    return;
  }

  // Create a file in the root directory of SD card and open it in write mode.
  File file = SD_MMC.open("/test.txt", FILE_WRITE); 
  if (!file) {
    Serial.println("Failed to open file for writing"); // Print error message if file failed to open
    return;
  }
  if (file.println("Test file write")) { // Write a line of text to the file
    Serial.println("File write successful"); // Print success message if write operation is successful
  } else {
    Serial.println("File write failed"); // Print error message if write operation failed
  }
  file.close(); // Close the file

  File root = SD_MMC.open("/"); // Open the root directory of SD card
  if (!root) {
    Serial.println("Failed to open directory"); // Print error message if directory failed to open
    return;
  }
  Serial.println("Files found in root directory:"); // Print the list of files found in the root directory
  while (File file = root.openNextFile()) { // Loop through all the files in the root directory
    Serial.print("  ");
    Serial.print(file.name()); // Print the filename
    Serial.print("\t");
    Serial.println(file.size()); // Print the filesize
    file.close(); // Close the file
  }
}
void loop() {} // Empty loop function, does nothing
