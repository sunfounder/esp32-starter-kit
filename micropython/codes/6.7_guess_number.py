from lcd1602 import LCD
import machine
import time
import urandom
from machine import Pin
from ir_rx.print_error import print_error
from ir_rx.nec import NEC_8

# IR receiver configuration
pin_ir = Pin(14, Pin.IN)

# Initialize the guessing game variables
lower = 0
upper = 99
pointValue = int(urandom.uniform(lower, upper))
count = 0

# Initialize the LCD1602 display
lcd = LCD()

# Initialize a new random value for the game
def init_new_value():
    global pointValue, upper, lower, count
    pointValue = int(urandom.uniform(lower, upper))
    print(pointValue)
    upper = 99
    lower = 0
    count = 0
    return False

# Display messages on the LCD based on the game state
def lcd_show(result):
    global count
    lcd.clear()
    if result == True: 
        string = "GAME OVER!\n"
        string += "Point is " + str(pointValue)
    else: 
        string = "Enter number: " + str(count) + "\n"
        string += str(lower) + " < Point < " + str(upper)
    lcd.message(string)
    return

# Process the entered number and update the game state
def number_processing():
    global upper, count, lower
    if count > pointValue:
        if count < upper:
            upper = count
    elif count < pointValue:
        if count > lower:
            lower = count
    elif count == pointValue:
        return True
    count = 0
    return False

# Process the key inputs from the IR remote control
def process_key(key):
    global count, lower, upper, pointValue, result
    if key == "Power":
        init_new_value()
        lcd_show(False)
    elif key == "+":
        result = number_processing()
        lcd_show(result)
        if result:
            time.sleep(5)
            init_new_value()
            lcd_show(False)
        else:
            lcd_show(False)
    elif key.isdigit():
        count = count * 10 + int(key) if count * 10 + int(key) <= 99 else count
        lcd_show(False)

# Decode the received data and return the corresponding key name
def decodeKeyValue(data):       
    if data == 0x16:
        return "0"
    if data == 0x0C:
        return "1"
    if data == 0x18:
        return "2"
    if data == 0x5E:
        return "3"
    if data == 0x08:
        return "4"
    if data == 0x1C:
        return "5"
    if data == 0x5A:
        return "6"
    if data == 0x42:
        return "7"
    if data == 0x52:
        return "8"
    if data == 0x4A:
        return "9"
    if data == 0x09:
        return "+"
    if data == 0x15:
        return "-"
    if data == 0x7:
        return "EQ"
    if data == 0x0D:
        return "U/SD"
    if data == 0x19:
        return "CYCLE"
    if data == 0x44:
        return "PLAY/PAUSE"
    if data == 0x43:
        return "FORWARD"
    if data == 0x40:
        return "BACKWARD"
    if data == 0x45:
        return "POWER"
    if data == 0x47:
        return "MUTE"
    if data == 0x46:
        return "MODE"
    return "ERROR"

def callback(data, addr, ctrl):
    if data < 0:
        pass
    else:
        key = decodeKeyValue(data)
        if key != "ERROR":
            process_key(key)

# Initialize the IR receiver object with the callback function
ir = NEC_8(pin_ir, callback)

# ir.error_function(print_error)

# Initialize the game with a new random value
init_new_value()

# Show the initial game state on the LCD
lcd_show(False)

try:
    while True:
        pass
except KeyboardInterrupt:
    ir.close()
