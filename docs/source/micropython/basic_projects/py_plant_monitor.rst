.. _py_plant_monitor:

6.8 Plant Monitor
===============================

Welcome to the Plant Monitor project! 

In this project, we will be using an ESP32 board to create a system that helps us take care of our plants. With this system, we can monitor the temperature, humidity, soil moisture, and light levels of our plants, and ensure that they are getting the care and attention they need to thrive.

**Required Components**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schematic**

.. image:: ../../img/circuit/circuit_6.8_plant_monitor_l293d.png

The system uses a DHT11 sensor to measure the temperature and humidity levels of the surrounding environment. 
Meanwhile, a soil moisture module is used to measure the moisture level of the soil and a photoresistor is used to 
measure the light level. The readings from these sensors are displayed on an LCD screen, and a water pump can be controlled 
using a button to water the plant when needed.

IO32 has an internal pull-down resistor of 1K, and by default, it is at a low logic level. When the button is pressed, it establishes a connection to VCC (high voltage), resulting in a high logic level on IO32.


**Wiring**

.. note::

    It is recommended here to insert the battery and then slide the switch on the expansion board to the ON position to activate the battery supply.


.. image:: ../../img/wiring/6.8_plant_monitor_l293d_bb.png
    :width: 800

**Code**

.. note::

    * Open the ``6.8_plant_monitor.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



.. code-block:: python

      from machine import ADC, Pin
      import time
      import dht
      from lcd1602 import LCD

      # DHT11
      dht11 = dht.DHT11(Pin(13))

      # Soil moisture
      moisture_pin = ADC(Pin(14))
      moisture_pin.atten(ADC.ATTN_11DB)

      # Photoresistor
      photoresistor = ADC(Pin(35))
      photoresistor.atten(ADC.ATTN_11DB)

      # Button and pump
      button = Pin(32, Pin.IN)

      motor1A = Pin(27, Pin.OUT)
      motor2A = Pin(26, Pin.OUT)

      # I2C LCD1602 setup
      lcd = LCD()

      # Rotate the pump
      def rotate():
      motor1A.value(1)
      motor2A.value(0)

      # Stop the pump
      def stop():
      motor1A.value(0)
      motor2A.value(0)

      button_state = False

      # Define the button callback function to toggle the button state
      def button_callback(pin):
      global button_state
      button_state = not button_state

      # Attach the button callback function to the rising edge of the button pin
      button.irq(trigger=Pin.IRQ_RISING, handler=button_callback)

      page = 0
      temp = 0
      humi = 0
            
      try:
      while True:
            
            # If the button is pressed and button state is True
            if button_state:
                  print("rotate")
                  rotate()

            # If the button is pressed again and button state is False
            if not button_state:
                  print("stop")
                  stop()
            time.sleep(2)

            # Clear the LCD display
            lcd.clear()
            
            # Toggle the value of the page variable between 0 and 1
            page=(page+1)%2
            
            # When page is 1, display temperature and humidity on the LCD1602
            if page is 1:
                  try:
                  # Measure temperature and humidity
                  dht11.measure()

                  # Get temperature and humidity values
                  temp = dht11.temperature()
                  humi = dht11.humidity()
                  except Exception as e:
                  print("Error: ", e)         

                  # Display temperature and humidity
                  lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
                  lcd.write(0, 1, "Humi: {}%".format(humi))

            # If page is 0, display the soil moisture and light
            else:
                  light = photoresistor.read()
                  moisture = moisture_pin.read()

                  # Clear the LCD display
                  lcd.clear()

                  # Display the value of soil moisture and light
                  lcd.write(0, 0, f"Moisture: {moisture}")
                  lcd.write(0, 1, f"Light: {light}")

      except KeyboardInterrupt:
      # Stop the motor when KeyboardInterrupt is caught
      stop()



* When the code is running, the I2C LCD1602 alternately displays temperature and humidity, as well as soil moisture and light intensity analog values, with a 2-second interval.
* Press the button to start the water pump, and press it again to stop the water pump.

.. note:: 

    If the code and wiring are correct, but the LCD still fails to display any content, you can adjust the potentiometer on the back to increase the contrast.
