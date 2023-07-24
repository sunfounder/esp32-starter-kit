# Import the LCD class from the lcd1602 module
from lcd1602 import LCD

import time

# Create an instance of the LCD class and assign it to the lcd variable
lcd = LCD()
# Set the string " Hello!\n"
string = " Hello!\n"
# Display the string on the LCD screen
lcd.message(string)

time.sleep(2)
# Set the string "    Sunfounder!"
string = "    Sunfounder!"
# Display the string on the LCD screen
lcd.message(string)

time.sleep(2)
# Clear the LCD screen
lcd.clear()
