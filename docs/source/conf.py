# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------
import sphinx_rtd_theme
import time  ###

project = 'SunFounder ESP32 Starter Kit'
copyright = f'{time.localtime().tm_year}, SunFounder'  ###
author = 'www.sunfounder.com'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = ['sphinx.ext.autosectionlabel'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []

html_static_path = ['_static']

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]




# SunFounder logo

html_js_files = [
    'https://ezblock.cc/readDocFile/custom.js',
    './lang.js', # new
]
html_css_files = [
    'https://ezblock.cc/readDocFile/custom.css',
]

#### RTD+

# html_js_files = [
#     'https://ezblock.cc/readDocFile/custom.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/ace.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/ext-language_tools.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/theme-chrome.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/mode-python.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/mode-sh.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/monokai.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/xterm.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/FitAddon.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/readTheDocIndex.js',

# ]
# html_css_files = [
#     'https://ezblock.cc/readDocFile/custom.css',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/css/index.css',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/css/xterm.css',
# ]



# Multi-language

language = 'en' # Before running make html, set the language.
locale_dirs = ['locale/'] # .po files for other languages are placed in the locale/ folder.

gettext_compact = False # Support for generating the contents of the folders inside source/ into other languages.




# open link in a new window

rst_epilog = """

.. |link_spanish_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/esp32-starter-kit-es/es/latest/index.html" target="_blank">Lecciones en línea de español</a>

.. |link_german_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/esp32-starter-kit/de/latest/" target="_blank">Deutsch Online-Kurs</a>

.. |link_jp_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/esp32-starter-kit/ja/latest/" target="_blank">日本語オンライン教材</a>

.. |link_en_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/esp32-starter-kit/en/latest/" target="_blank">English Online-tutorials</a>

.. |link_thonny| raw:: html

    <a href="https://thonny.org/" target="_blank">Thonny</a>

.. |link_download_arduino| raw:: html

    <a href="https://www.arduino.cc/en/software#future-version-of-the-arduino-ide" target="_blank">Arduino IDE 2.0.0 Page</a>

.. |link_ascii| raw:: html

    <a href="https://www.asciitable.com/" target="_blank">ASCII table of characters</a>

.. |link_processing_download| raw:: html

    <a href="https://processing.org/download" target="_blank">Procesing download</a>

.. |link_processing_tutorial| raw:: html

    <a href="https://processing.org/tutorials/overview/" target="_blank">Processing Overview</a>

.. |link_esp32_micropython_download| raw:: html

    <a href="https://micropython.org/download/esp32/" target="_blank">MicroPython firmware for the ESP32</a>

.. |link_ledc| raw:: html

    <a href="https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/ledc.html" target="_blank">LEDC</a>

.. |link_esp32servo| raw:: html

    <a href="https://madhephaestus.github.io/ESP32Servo/classServo.html" target="_blank">ESP32Servo</a>

.. |link_uuid| raw:: html

    <a href="https://www.uuidgenerator.net/version4" target="_blank">Online UUID Generator</a>

.. |link_hivemq| raw:: html

    <a href="https://www.hivemq.com/demos/websocket-client/" target="_blank">HiveMQ Web Client</a>

.. |link_openweather| raw:: html

    <a href="https://openweathermap.org/" target="_blank">OpenWeather</a>

.. |link_discord_server| raw:: html

    <a href="https://discord.com/invite/G7Q5UjDT7K" target="_blank">Discord Server</a>

.. |link_cheerlights| raw:: html

    <a href="https://cheerlights.com/" target="_blank">@CheerLights</a>

.. |link_adafruit_io| raw:: html

    <a href="https://io.adafruit.com/" target="_blank">Adafruit IO</a>

.. |link_botfather| raw:: html

    <a href="https://t.me/botfather" target="_blank">BotFather</a>

.. |link_appinventor| raw:: html

    <a href="http://appinventor.mit.edu/" target="_blank">MIT App Inventor</a>

.. |link_appinventor_login| raw:: html

    <a href="http://ai2.appinventor.mit.edu" target="_blank">login portal</a>

.. |link_blynk_virtualWrite| raw:: html

    <a href="https://docs.blynk.io/en/blynk-library-firmware-api/virtual-pins#blynk.virtualwrite-vpin-value" target="_blank">Blynk.virtualWrite()</a> 

.. |link_blynk_timer_intro| raw:: html

    <a href="https://docs.blynk.io/en/legacy-platform/legacy-articles/keep-your-void-loop-clean" target="_blank">Why we use Blynk timer?</a> 

.. |link_blynk_quickstart| raw:: html

    <a href="https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/quickstart-device-code-overview" target="_blank">Blynk Quickstart</a> 

.. |link_blynk_doc| raw:: html

    <a href="https://docs.blynk.io/" target="_blank">Blynk Documentation</a> 

.. |link_blynk_syncing| raw:: html

    <a href="https://docs.blynk.io/en/blynk-library-firmware-api/state-syncing#for-hardware" target="_blank">Blynk - State Syncing</a> 

.. |link_blynk_write| raw:: html

    <a href="https://docs.blynk.io/en/getting-started/using-virtual-pins-to-control-physical-devices#the-blynk_write-vpin-function" target="_blank">Blynk - BLYNK_WRITE()</a>     

.. |link_blynk| raw:: html

    <a href="https://blynk.io/" target="_blank">BLYNK</a>     

.. |link_blynk_logEvent| raw:: html

    <a href="https://docs.blynk.io/en/getting-started/events-tutorial#use-blynk.logevent-firmware-api" target="_blank">Blynk.logEvent()</a> 

.. |link_esp32_datasheet| raw:: html

    <a href="https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf" target="_blank">ESP32-WROOM-32E Datasheet</a> 



"""

# Purchase links of components

rst_epilog += """

.. |link_esp32_starter_kit| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-esp32-ultimate-starter-kit-with-esp32-camera-extension-board-battery" target="_blank">ESP32 Starter Kit</a>



.. |link_esp32_wroom_32e_buy| raw:: html

    <a href="https://www.sunfounder.com/products/esp-wroom-32-esp32-esp-32s-development-board" target="_blank">BUY</a>    

.. |link_led_buy| raw:: html

    <a href="https://www.sunfounder.com/products/500pcs-5-colors-x-100pcs-5mm-leds-with-white-red-yellow-green-blue-colors-kit-box" target="_blank">BUY</a>

.. |link_resistor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/1-4w-resistor-assortment-kit-40-values-400pcs" target="_blank">BUY</a>

.. |link_wires_buy| raw:: html

    <a href="https://www.sunfounder.com/products/560pcs-jumper-wire-kit-with-14-lengths" target="_blank">BUY</a>

.. |link_breadboard_buy| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-breadboard-kit" target="_blank">BUY</a>

.. |link_rgb_led_buy| raw:: html

    <a href="https://www.sunfounder.com/products/100pcs-5mm-4-pin-rgb-common-cathode-led" target="_blank">BUY</a>

.. |link_button_buy| raw:: html

    <a href="https://www.sunfounder.com/products/100pcs-6x6x5-mm-miniature-push-button" target="_blank">BUY</a>

.. |link_capacitor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/ceramic-capacitor-assortment-kit-set-of-600-small-assorted-capacitors" target="_blank">BUY</a>

.. |link_potentiometer_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10pcs-10k-ohm-trim-potentiometer-breadboard" target="_blank">BUY</a>

.. |link_photoresistor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/100pcs-photoresistor-photo-light-sensitive-resistor-5516" target="_blank">BUY</a>

.. |link_thermistor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/50pcs-ntc-thermistor-mf11-103-10k-ohm" target="_blank">BUY</a>

.. |link_transistor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10-values-200pcs-power-supply-general-transistor-npn-pnp-assortment-kit-bc337-bc327-2n2222-2n2907-2n3904-2n3906-s8050-s8550-a1015-c1815-set" target="_blank">BUY</a>

.. |link_relay_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10pcs-srs-05vdc-sl-c-5v-relay-coil-spdt-6-pin-pcb-electromagnetic-power-relay" target="_blank">BUY</a>

.. |link_passive_buzzer_buy| raw:: html

    <a href="https://www.sunfounder.com/products/20pcs-3-5v-2-terminals-passive-buzzer" target="_blank">BUY</a>

.. |link_ws2812_buy| raw:: html

    <a href="https://www.sunfounder.com/products/2pcs-8-bit-ws2812b-rgb-led-strip-5050smd-individual-addressable-60pixels-m" target="_blank">BUY</a>

.. |link_i2clcd1602_buy| raw:: html

    <a href="https://www.sunfounder.com/products/i2c-lcd1602-module" target="_blank">BUY</a>

.. |link_motor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/5pcs-1-5v-6v-type-miniature-dc-motors" target="_blank">BUY</a>

.. |link_servo_buy| raw:: html

    <a href="https://www.sunfounder.com/products/sg90-micro-digital-servo" target="_blank">BUY</a>

.. |link_keypad_buy| raw:: html

    <a href="https://www.sunfounder.com/products/membrane-switch-keypad" target="_blank">BUY</a>

.. |link_74hc595_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10-pcs-ic-74hc595-74595-sn74hc595n-8-bit-shift-register-dip-16" target="_blank">BUY</a>

.. |link_7segment_buy| raw:: html

    <a href="https://www.sunfounder.com/products/30pcs-0-56-7-segment-led" target="_blank">BUY</a>

.. |link_ultrasonic_buy| raw:: html

    <a href="https://www.sunfounder.com/products/5pcs-hc-sr04-ultrasonic-module-distance-sensor" target="_blank">BUY</a>

.. |link_dht22_buy| raw:: html

    <a href="https://www.sunfounder.com/products/dht22-am2302-digital-temperature-and-humidity-sensor" target="_blank">BUY</a>

.. |link_receiver_buy| raw:: html

    <a href="https://www.sunfounder.com/products/infrared-receiver-module" target="_blank">BUY</a>

.. |link_rfid_buy| raw:: html

    <a href="https://www.sunfounder.com/products/rfid-kit-blue" target="_blank">BUY</a>

.. |link_pir_buy| raw:: html

    <a href="https://www.sunfounder.com/products/hcsr501-infrared-sensor?_pos=1&_sid=2bd5fd3cc&_ss=r" target="_blank">BUY</a>

.. |link_avoid_buy| raw:: html

    <a href="https://www.sunfounder.com/products/ir-obstacle-avoidance-sensor-module" target="_blank">BUY</a> 

.. |link_line_track_buy| raw:: html

    <a href="https://www.sunfounder.com/products/tracking-sensor-module" target="_blank">BUY</a> 

.. |link_soil_moisture_buy| raw:: html

    <a href="https://www.sunfounder.com/products/capacitive-soil-moisture-sensor-module" target="_blank">BUY</a>  

.. |link_joystick_buy| raw:: html

    <a href="https://www.sunfounder.com/products/dual-axis-button-joystick-module-ps2-game" target="_blank">BUY</a> 

.. |link_dht11_buy| raw:: html

    <a href="https://www.sunfounder.com/products/dht11-temperature-and-humidity-sensor-module" target="_blank">BUY</a> 
        
"""
