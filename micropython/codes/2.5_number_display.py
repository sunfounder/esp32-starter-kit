import machine
import time

# Define the segment code for a common anode 7-segment display
SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

# Initialize the pins for the 74HC595 shift register
sdi = machine.Pin(25, machine.Pin.OUT)  # DS
rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

# Define the hc595_shift function to shift data into the 74HC595 shift register
def hc595_shift(dat):
    # Set the RCLK pin to low
    rclk.off()
    
    # Iterate through each bit (from 7 to 0)
    for bit in range(7, -1, -1):
        # Extract the current bit from the input data
        value = 1 & (dat >> bit)
        
        # Set the SRCLK pin to low
        srclk.off()
        
        # Set the value of the SDI pin
        sdi.value(value)
        
        # Clock the current bit into the shift register by setting the SRCLK pin to high
        srclk.on()
        
    # Latch the data into the storage register by setting the RCLK pin to high
    rclk.on()

# Continuously loop through the numbers 0 to 9 and display them on the 7-segment display
while True:
    for num in range(10):
        hc595_shift(SEGCODE[num])  # Shift the segment code for the current number into the 74HC595
        time.sleep_ms(500)  # Wait 500 milliseconds before displaying the next number
