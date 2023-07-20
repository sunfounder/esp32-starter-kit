9. Home Environment Monitoring with Blynk
==========================================

**1. Configuring the Blynk**


#. Go to the `BLYNK <https://blynk.io/>`_ and click **START FREE**. 

    .. image:: img/sp220607_142551.png

#. Fill in your email address to register an account.

    .. image:: img/sp220607_142807.png

#. Go to your email address to complete your account registration.

    .. image:: img/sp220607_142936.png

#. Afterwards, **Blynk Tour** will appear and you can read it to learn the basic information about the Blynk.

    .. image:: img/sp220607_143244.png

#. Next we need to create a template and device with this **Quick Start**, click **Let's go**.


    .. image:: img/sp220607_143608.png

#. Select the hardware and connection type.

    .. image:: img/sp20220614173218.png

#. Here you are told which IDE you need to prepare, we recommend the **Arduino IDE**.

    .. image:: img/sp20220614173454.png

#. Here is the library you need to add, but the recommended library here is a bit problematic, we need to add other libraries manually (we will mention it later). Click **Next** here, and a new template and device will be created.

    .. image:: img/sp20220614173629.png

#. The next steps are to upload the relevant code and connect your board to Blynk, but since there is a problem with the library provided earlier, you need to add other libraries again. So click **Cancel** here to stop **Quick Start**.

    .. image:: img/sp20220614174006.png

#. Click the **Search** button and you will see the new device you just created.

    .. image:: img/sp20220614174410.png

#. Go to this **Quickstart Device** and you will see ``TEMPLATE_ID``, ``DEVICE_NAME`` and ``AUTH_TOKEN`` on the **Device info** page, and you will need to copy them later.


    .. image:: img/sp20220614174721.png

In this chapter, we will use Blynk to create a home environment monitor.
You can measure the temperature, humidity, and light intensity of a room using the DHT11 and photoresistor.
By sending these values to Blynk, you will be able to know the environment of your home via the internet.

**1. Build the Cirduit**

.. note::

    The ESP8266 module requires a high current to provide a stable operating environment, so make sure the 9V battery is plugged in.

.. image:: img/wiring_dht11.jpg

* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_esp8266`
* :ref:`cpn_photoresistor`
* :ref:`cpn_dht11`
* :ref:`cpn_resistor`

**2. Edit Dashboard**


#. For recording humidity values, create a **Datastream** of type **Virtual Pin** on the **Datastream** page. Set the DATA TYPE to **Double** and MIN and MAX to **0** and **100**. Also set the units to **Percentage, %**.

    .. image:: img/sp220610_145748.png

#. Then create a **Datastream** of type **Virtual Pin** for recording the temperature. Set DATA TYPE to ``Double``, MIN and MAX to ``-30`` and ``50``, and units to **Celsius, °C**.

    .. image:: img/sp220610_145811.png

#. Also create a **Datastream** of type **Virtual Pin** to record the light intensity. Use the default data type - **Integer**, with MIN and MAX set to ``0`` and ``1024``.

    .. image:: img/sp220610_145834.png

#. Go to the **Wed Dashboard** page, drag two **Label** widgets and set their data streams to **V4** and **V5** respectively, and drag a **Gauge** widget and set the data stream to **V6**. Also in the widget setting, you can enable **Change color based on value** and select the appropriate color to make the widget look better and more intuitive.

.. image:: img/sp220610_150400.png
    :align: center


**3. Run the Code**

#. Open the ``5.home_environment_monitoring.ino`` file under the path of ``3in1-kit\iot_project\5.home_environment_monitoring``, or copy this code into **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/4f0ad85e-8aff-4df9-99dd-c6741aed8219/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Replace the ``Template ID``, ``Device Name``, and ``Auth Token`` with your own. You also need to enter the ``ssid`` and ``password`` of the WiFi you are using. For detailed tutorials, please refer to :ref:`connect_blynk`.
#. After selecting the correct board and port, click the **Upoad** button.

#. Open the Serial monitor(set baudrate to 115200) and wait for a prompt such as a successful connection to appear.

    .. image:: img/2_ready.png

    .. note::

        If the message ``ESP is not responding`` appears when you connect, please follow these steps.

        * Make sure the 9V battery is plugged in.
        * Reset the ESP8266 module by connecting the pin RST to GND for 1 second, then unplug it.
        * Press the reset button on the R3 board.

        Sometimes, you may need to repeat the above operation 3-5 times, please be patient.

#. Now, you will see the current ambient temperature, humidity and light intensity on Blynk.

    .. image:: img/sp220610_150400.png
        :align: center

#. If you want to use Blynk on mobile devices, please refer to :ref:`blynk_mobile`.

    .. image:: img/mobile_home.jpg

**How it works?**

These two functions are used to get the temperature, humidity and light intensity of the room.


.. code-block:: arduino

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {
        Serial.print("DHT11, \t");
        int chk = DHT.read11(DHT11_PIN);
        switch (chk)
        {
            case DHTLIB_OK:
            Serial.print("OK,\t");
            roomHumidity = DHT.humidity;
            Serial.print(roomHumidity, 1);
            Serial.print(",\t");
            roomTemperature = DHT.temperature;
            Serial.println(roomTemperature, 1);
            //    delay(1000);
            return true;
            case DHTLIB_ERROR_CHECKSUM:
            Serial.println("Checksum error,\t");
            break;
            case DHTLIB_ERROR_TIMEOUT:
            Serial.println("Time out error,\t");
            //    delay(20);
            break;
            default:
            Serial.println("Unknown error,\t");
            break;
        }
        return false;
    }


With the Blynk ``Timer``, the ambient temperature, humidity, and light intensity are obtained every second and sent to the data stream on the Blynk Cloud, from which the widgets display the data.

.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        if(chk==true){
            Blynk.virtualWrite(V4,roomHumidity);
            Blynk.virtualWrite(V5,roomTemperature);
        }
        Blynk.virtualWrite(V6,light);
    }