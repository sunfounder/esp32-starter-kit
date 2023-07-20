.. _ar_pir:

4.5 Detect Human Movement
========================================

Passive infrared sensor (PIR sensor) is a common sensor that can measure infrared (IR) light emitted by objects in its field of view.
Simply put, it will receive infrared radiation emitted from the body, thereby detecting the movement of people and other animals.
More specifically, it tells the main control board that someone has entered your room.


**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - For Input
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - For Output
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::
    
    IO32 cannot be used **as input pin** in this project because it is internally connected to a 1K pull-down resistor, which sets its default value to 0.

* **Strapping Pins (Input)**

    Strapping pins are a special set of pins that are used to determine specific boot modes during device startup 
    (i.e., power-on reset).

    
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    

    

    Generally, it is **not recommended to use them as input pins**. If you wish to use these pins, consider the potential impact on the booting process. For more details, please refer to the :ref:`esp32_strapping` section.


**Schematic**

.. image:: ../../img/circuit/circuit_5.5_pir.png

When the PIR module detects motion, IO14 will go high, and the LED will be lit. Otherwise, when no motion is detected, IO14 will be low, and the LED will turn off.

.. note::
    The PIR module has two potentiometers: one adjusts sensitivity, the other adjusts detection distance. To make the PIR module work better, you need to turn both of them counterclockwise to the end.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**Wiring**

.. image:: ../../img/wiring/5.5_pir_bb.png

* :ref:`cpn_esp32_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_led`
* :ref:`cpn_pir`

**Code**

.. note::

   * You can open the file ``4.5_pir.ino`` under the path of ``esp32-ultimate-kit-main\c\codes\4.5_pir``. 
   * Or copy this code into **Arduino IDE**.  

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b5f0cc8-b732-4ed2-b68e-bb7d0a73a1b8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
After the code has been uploaded successfully, the LED will light up and then go off when the PIR module detects someone passing.

.. note::
    The PIR module has two potentiometers: one adjusts sensitivity, the other adjusts detection distance. To make the PIR module work better, you need to turn both of them counterclockwise to the end.

    .. image:: img/pir_back.png



