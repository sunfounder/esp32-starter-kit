.. _ar_pir:

5.5 Detect Human Movement
========================================

Passive infrared sensor (PIR sensor) is a common sensor that can measure infrared (IR) light emitted by objects in its field of view.
Simply put, it will receive infrared radiation emitted from the body, thereby detecting the movement of people and other animals.
More specifically, it tells the main control board that someone has entered your room.

:ref:`cpn_pir`

**Bill of Materials**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Kepler Kit	
        - 450+
        - |link_kepler_kit|

You can also buy them separately from the links below.


.. list-table::
    :widths: 5 20 5 20
    :header-rows: 1

    *   - SN
        - COMPONENT	
        - QUANTITY
        - LINK

    *   - 1
        - Raspberry Pi Pico W
        - 1
        - |link_picow_buy|
    *   - 2
        - Micro USB Cable
        - 1
        - 
    *   - 3
        - Breadboard
        - 1
        - |link_breadboard_buy|
    *   - 4
        - Wires
        - Several
        - |link_wires_buy|
    *   - 5
        - PIR Module
        - 1
        - |link_pir_buy|
    *   - 6
        - LED
        - 1
        - |link_led_buy|


**Schematic**

|sch_pir|

When the PIR module detects someone passing by, pin14 will be high, otherwise it will be low.

.. note::
    The PIR module has two potentiometers: one adjusts sensitivity, the other adjusts detection distance. To make the PIR module work better, you need to turn both of them counterclockwise to the end.

    |img_PIR_TTE|

**Wiring**

PIR连接到14引脚，LED连接到26引脚

|wiring_pir|

**Code**

.. note::

   * You can open the file ``5.5_pir.ino`` under the path of ``esp32-ultimate-kit\c\codes\5.1_pir``. 
   * Or copy this code into **Arduino IDE**.  

.. raw:: html



After the code has been uploaded successfully, the LED will light up and then go off when the PIR module detects someone passing.

.. note::
    The PIR module has two potentiometers: one adjusts sensitivity, the other adjusts detection distance. To make the PIR module work better, you need to turn both of them counterclockwise to the end.

    .. image:: img/pir_back.png



