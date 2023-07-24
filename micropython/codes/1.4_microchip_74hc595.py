import machine
import time

# Initialize the pins for the 74HC595 shift register
sdi = machine.Pin(25, machine.Pin.OUT)  # DS
rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

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

num = 0

# Shift data into the 74HC595 to create a moving LED pattern
for i in range(16):
    if i < 8:
        num = (num << 1) + 1  # Shift left and set the least significant bit to 1
    elif i >= 8:
        num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
    hc595_shift(num)  # Shift the current value into the 74HC595
    print("{:0>8b}".format(num))  # Print the current value in binary format
    time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value
