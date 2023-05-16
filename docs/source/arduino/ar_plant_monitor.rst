6.6 Plant Monitor
===============================

Welcome to the Plant Monitor project! 

In this project, we will be using an ESP32 board to create a system that helps us take care of our plants. With this system, we can monitor the temperature, humidity, soil moisture, and light levels of our plants, and ensure that they are getting the care and attention they need to thrive.



**Schematic**

|sch_ws2812|

The system uses a DHT11 sensor to measure the temperature and humidity levels of the surrounding environment. Meanwhile, a soil moisture module is used to measure the moisture level of the soil and a photoresistor is used to measure the light level. The readings from these sensors are displayed on an LCD screen, and a water pump can be controlled using a button to water the plant when needed.


**Wiring**



**Code**

.. note::

    * You can open the file ``6.6_plant_monitor.ino`` under the path of ``esp32-ultimate-kit\c\codes\6.6_plant_monitor``. 
    * Or copy this code into **Arduino IDE**.
    * The ``LiquidCrystal_I2C`` and  ``dht`` libraries are used here, refer to :ref:`install_libraries_ar` for a tutorial to install.


.. raw:: html
    

* After uploading the code, the I2C LCD1602 alternately displays temperature and humidity, as well as soil moisture and light intensity analog values, with a 2-second interval.
* The water pump is controlled using a button press. To water the plants, hold down the button, and release it to stop watering.

.. note:: 

    If the code and wiring are correct, but the LCD still fails to display any content, you can adjust the potentiometer on the back to increase the contrast.
