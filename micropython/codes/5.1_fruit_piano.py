from machine import Pin, PWM, TouchPad
import time

# Define the touch pins and their corresponding notes
touch_pins = [4, 15, 13, 12, 14, 27, 33, 32]  # Use valid touch-capable pins
notes = [262, 294, 330, 349, 392, 440, 494, 523]

# Initialize the touch sensors
touch_sensors = [TouchPad(Pin(pin)) for pin in touch_pins]

# Initialize the buzzer
buzzer = PWM(Pin(25), duty=0)

# Function to play a tone
def play_tone(frequency, duration):
    buzzer.freq(frequency)
    buzzer.duty(512)
    time.sleep_ms(duration)
    buzzer.duty(0)

touch_threshold = 200

# Main loop to check for touch inputs and play the corresponding note
while True:
    for i, touch_sensor in enumerate(touch_sensors):
        value = touch_sensor.read()
        print(i,value)
        if value < touch_threshold:
            play_tone(notes[i], 100)
            time.sleep_ms(50)
        time.sleep(0.01)
