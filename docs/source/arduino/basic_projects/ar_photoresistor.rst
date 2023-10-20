.. _ar_photoresistor:

5.7 Feel the Light
===========================

The photoresistor is a commonly used device for analog inputs, similar to a potentiometer. Its resistance value changes based on the intensity of the light it receives. When exposed to strong light, the resistance of the photoresistor decreases, and as the light intensity decreases, the resistance increases.

By reading the value of the photoresistor, we can gather information about the ambient light conditions. This information can be used for tasks such as controlling the brightness of an LED, adjusting the sensitivity of a sensor, or implementing light-dependent actions in a project.

**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 15

        *   - Available Pins
            - IO14, IO25, I35, I34, I39, I36


* **Strapping Pins**

    The following pins are strapping pins, which affect the startup process of the ESP32 during power on or reset. However, once the ESP32 is booted up successfully, they can be used as regular pins.

    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO0, IO12

**Schematic**

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

As the light intensity increases, the resistance of the light-dependent resistor (LDR) decreases, resulting in a decrease in the value read on I35.

**Wiring**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_photoresistor`

**Code**

.. note::

    * Open the ``5.7_feel_the_light.ino`` file under the path of ``esp32-starter-kit-main\c\codes\5.7_feel_the_light``.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/58b494c7-eef4-4476-af65-4823cef13f90/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is uploaded successfully, the Serial Monitor prints out the photoresistor values from 0 ~ 4095. 
The stronger the current ambient brightness, the larger the value displayed on the serial monitor.

.. note::
    For the ESP32, the resolution is between 9 to 12 and it will change the ADC hardware resolution. Else value will be shifted.

    Default is 12 bits (range from 0 to 4096) for all chips except ESP32S3 where default is 13 bits (range from 0 to 8192).

    You can add ``analogReadResolution(10);`` to ``setup()`` function to set a different resolution, such as ``20``.

    
