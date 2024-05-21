.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_dht11:

5.13 Temperature - Humidity
=======================================

The DHT11 is a temperature and humidity sensor commonly used for environmental measurements. It is a digital sensor that communicates with a microcontroller to provide temperature and humidity readings.

In this project, we will be reading the DHT11 sensor and printing out the temperature and humidity values it detects.

By reading the data provided by the sensor, we can obtain the current temperature and humidity values in the environment. These values can be used for real-time monitoring of environmental conditions, weather observations, indoor climate control, humidity reports, and more.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - Available Pins
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schematic**

.. image:: ../../img/circuit/circuit_5.13_dht11.png


**Wiring**

.. image:: ../../img/wiring/5.13_dht11_bb.png

**Code**

.. note::

    * Open the ``5.13_dht11.ino`` file under the path of ``esp32-starter-kit-main\c\codes\5.13_dht11``.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``DHT sensor library`` library is used here, you can install it from the **Library Manager**.

        .. image:: img/dht_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/95bef6dc-a4db-4315-9308-6663b77ddfa0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is uploaded successfully, you will see the Serial Monitor continuously print out the temperature and humidity, and as the program runs steadily, these two values will become more and more accurate.

**How it works?**

#.  Includes the ``DHT.h`` library, which provides functions to interact with the DHT sensors. Then, set the pin and type for the DHT sensor.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 14  // Set the pin connected to the DHT11 data pin
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Initializes serial communication at a baud rate of 115200 and initializes the DHT sensor.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. In the ``loop()`` function, read temperature and humidity values from the DHT11 sensor, and print them to the serial monitor.

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * The ``dht.readHumidity()`` function is called to read the humidity value from the DHT sensor.
    * The ``dht.readTemperature()`` function is called to read the temperature value from the DHT sensor.
    * The ``isnan()`` function is used to check if the readings are valid. If either the humidity or temperature value is NaN (not a number), it indicates a failed reading from the sensor, and an error message is printed.

**Learn More**

You can also display the temperature and humidity on the I2C LCD1602.


.. note::

    * You can open the file ``5.10_thermistor_lcd.ino`` under the path of ``euler-kit/arduino/5.10_thermistor_lcd``. 
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``LiquidCrystal_I2C`` and  ``DHT sensor library`` libraries are used here, you can install them from the **Library Manager**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fb46ba7e-0a09-4805-87ab-f733e23eb920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    