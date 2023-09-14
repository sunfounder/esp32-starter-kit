from machine import Pin
from neopixel import NeoPixel

pin = Pin(14, Pin.OUT)   # set a pin to output to drive NeoPixels
pixels = NeoPixel(pin, 8)   # create NeoPixel driver on pin for 8 pixels
pixels[0] = [64,154,227]    # set the pixel 
pixels[1] = [128,0,128]
pixels[2] = [50,150,50]
pixels[3] = [255,30,30]
pixels[4] = [0,128,255]
pixels[5] = [99,199,0]
pixels[6] = [128,128,128]
pixels[7] = [255,100,0]

pixels.write()              # write data to all pixels