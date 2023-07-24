import machine
import time

# Define the frequencies of several musical notes in Hz
C4 = 262
D4 = 294
E4 = 330
F4 = 349
G4 = 392
A4 = 440
B4 = 494

# Create a PWM object representing pin 14 and assign it to the buzzer variable
buzzer = machine.PWM(machine.Pin(14))

# Define a tone function that takes as input a Pin object representing the buzzer, a frequency in Hz, and a duration in milliseconds
def tone(pin, frequency, duration):
    pin.freq(frequency) # Set the frequency
    pin.duty(512) # Set the duty cycle
    time.sleep_ms(duration) # Pause for the duration in milliseconds
    pin.duty(0) # Set the duty cycle to 0 to stop the tone

# Play a sequence of notes with different frequency inputs and durations
tone(buzzer, C4, 250)
time.sleep_ms(500)
tone(buzzer, D4, 250)
time.sleep_ms(500)
tone(buzzer, E4, 250)
time.sleep_ms(500)
tone(buzzer, F4, 250)
time.sleep_ms(500)
tone(buzzer, G4, 250)
time.sleep_ms(500)
tone(buzzer, A4, 250)
time.sleep_ms(500)
tone(buzzer, B4, 250)
