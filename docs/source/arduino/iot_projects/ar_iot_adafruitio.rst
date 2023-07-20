6. Temperature and Humidity Monitoring with Adafruit IO
=============================================================

In this project, we will guide you on how to use a popular IoT platform. There are many free (or low-cost) platforms available online for programming enthusiasts. Some examples are Adafruit IO, Blynk, Arduino Cloud, ThingSpeak, and so on. The usage of these platforms is quite similar. Here, we will be focusing on Adafruit IO.

We will write an Arduino program that uses the DHT11 sensor to send temperature and humidity readings to Adafruit IO's dashboard. You can also control an LED on the circuit through a switch on the dashboard.

**Setting up the Dashboard**

#. Visit |link_adafruit_io|, then click on **Start for free** to create a free account.

    .. image:: img/sp230516_102503.png

#. Fill out the form to create an account.

    .. image:: img/sp230516_102629.png

#. After creating an Adafruit account, you'll need to reopen Adafruit io. Click on the **Dashboards**, then click on **New Dashboard**.

    .. image:: img/sp230516_103347.png

#. Create a **New Dashboard**.

    .. image:: img/sp230516_103744.png

#. Enter the newly created **Dashboard** and create a new block.

    .. image:: img/sp230516_104234.png

#. Create 1 **Toggle** block.

    .. image:: img/sp230516_105727.png

#. Next, you'll need to create a new feed here. This toggle will be used to control the LED, and we'll name this feed "LED".

    .. image:: img/sp230516_105641.png

#. Check the **LED** feed, then move to the next step.

    .. image:: img/sp230516_105925.png

#. Complete the block settings (mainly Block Title, On Text, and Off Text), then click on the **Create block** button at the bottom right to finish.

    .. image:: img/sp230516_110124.png

#. We also need to create two **Text Blocks** next. They will be used to display temperature and humidity. So, create two feeds named **temperature** and **humidity**.

    .. image:: img/sp230516_110657.png

#. After creation, your Dashboard should look something like this:

    .. image:: img/sp230516_111134.png

#. You can adjust the layout by using the **Edit Layout** option on the Dashboard.

    .. image:: img/sp230516_111240.png

#. Click on **API KEY**, and you will see your username and **API KEY** displayed. Note these down as you'll need them for your code.

    .. image:: img/sp230516_111641.png

**Running the Code**

#. Build the circuit. 

    DHT11 接GPIO13 and the LED 接 GPIO15.

#. Then, connect ESP32-WROOM-32E to the computer using the USB cable.

    .. image:: img/plugin_esp32.png

#. Open the code.

    * Open the ``iot_6_adafruit_io.ino`` file located in the ``esp32-ultimate-kit-main\c\codes\iot_6_adafruit_io`` directory, or copy the code into the Arduino IDE.
    * Or copy this code into **Arduino IDE**.
    * The ``Adafruit_MQTT Library`` and ``DHT sensor library`` are used here, you can install them from the **Library Manager**.

    .. raw:: html


#. Find the following lines and replace ``<SSID>`` and ``<PASSWORD>`` with the specific details of your WiFi network.

    .. code-block::  Arduino

        /************************* WiFi Access Point *********************************/

        #define WLAN_SSID "<SSID>"
        #define WLAN_PASS "<PASSWORD>"

#. Then replace ``<YOUR_ADAFRUIT_IO_USERNAME>`` with your Adafruit IO username and ``<YOUR_ADAFRUIT_IO_KEY>`` with the **API KEY** you just copied.

    .. code-block::  Arduino

        // Adafruit IO Account Configuration
        // (to obtain these values, visit https://io.adafruit.com and click on Active Key)
        #define AIO_USERNAME "<YOUR_ADAFRUIT_IO_USERNAME>"
        #define AIO_KEY      "<YOUR_ADAFRUIT_IO_KEY>"

#. After selecting the correct board (ESP32 Dev Module) and port, click the **Upload** button.

#. Once the code is successfully uploaded, you will observe the following message in the serial monitor, indicating successful communication with Adafruit IO.
    
    .. code-block::

        Adafruit IO MQTTS (SSL/TLS) Example


        Connecting to xxxxx
        WiFi connected
        IP address: 
        192.168.18.76
        Connecting to MQTT... MQTT Connected!
        Temperature: 27.10
        Humidity: 61.00

#. Navigate back to Adafruit IO. Now you can observe the temperature and humidity readings on the dashboard, or utilize the LED toggle switch to control the on/off state of the external LED connected to the circuit.

    .. image:: img/sp230516_143220.png
