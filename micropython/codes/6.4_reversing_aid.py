# Import required libraries
from machine import Pin
import time
from lcd1602 import LCD
import _thread

# Initialize the buzzer
buzzer = Pin(14, Pin.OUT)

# Initialize the ultrasonic module
TRIG = Pin(26, Pin.OUT)
ECHO = Pin(25, Pin.IN)

# Initialize the LCD1602 display
lcd = LCD()

dis = 100

# Calculate the distance
def distance():
    # Ensure trigger is off initially
    TRIG.off()
    time.sleep_us(2)  # Wait for 2 microseconds

    # Send a 10-microsecond pulse to the trigger pin
    TRIG.on()
    time.sleep_us(10)
    TRIG.off()

    # Wait for the echo pin to go high
    while not ECHO.value():
        pass

    # Record the time when the echo pin goes high
    time1 = time.ticks_us()

    # Wait for the echo pin to go low
    while ECHO.value():
        pass

    # Record the time when the echo pin goes low
    time2 = time.ticks_us()

    # Calculate the time difference between the two recorded times
    during = time.ticks_diff(time2, time1)

    # Calculate and return the distance (in cm) using the speed of sound (340 m/s)
    return during * 340 / 2 / 10000

# Thread to continuously update the ultrasonic sensor reading
def ultrasonic_thread():
    global dis
    while True:
        dis = distance()
        
        # Clear the LCD screen
        lcd.clear()
        
        # Display the distance
        lcd.write(0, 0, 'Dis: %.2f cm' % dis)
        time.sleep(0.5)

# Start the ultrasonic sensor reading thread
_thread.start_new_thread(ultrasonic_thread, ())

# Beep function for the buzzer
def beep():
    buzzer.value(1)
    time.sleep(0.1)
    buzzer.value(0)
    time.sleep(0.1)

# Initialize the intervals variable
intervals = 10000000
previousMills = time.ticks_ms()
time.sleep(1)

# Main loop
while True:
    # Update intervals based on distance
    if dis < 0 and dis > 500:
        pass
    elif dis <= 10:
        intervals = 300
    elif dis <= 20:
        intervals = 500
    elif dis <= 50:
        intervals = 1000
    else:
        intervals = 2000

    # Print the distance if it's not -1
    if dis != -1:
        print('Distance: %.2f' % dis)
    time.sleep_ms(100)

    # Check if it's time to beep
    currentMills = time.ticks_ms()
    if time.ticks_diff(currentMills, previousMills) >= intervals:
        beep()
        previousMills = currentMills
