.. _ar_tilt:

5.2 Tilt It！
==========================

|img_tilt|

The tilt switch is a 2-pin device with a metal ball in the middle. When the switch is upright, the two pins are connected; when it is tilted, the two pins are disconnected.

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
        - Resistor
        - 1(10KΩ)
        - |link_resistor_buy|
    *   - 6
        - Tilt Switch
        - 1
        - 
     *   - 7
        - LED
        - 1
        - |link_led_buy|   

**Schematic**

|sch_tilt|

When you put it upright, pin14 will get high; after tilting it, pin14 will get low.

The purpose of the 10K resistor is to keep the pin14 in a stable low state when the tilt switch is in a tilted state.

* :ref:`cpn_tilt`

**Wiring**

|wiring_tilt|

开关引脚接14，同侧引脚接10K电阻之后接GND，另外一侧接3.3V.
LED接26.

**Code**

.. note::

   * You can open the file ``5.2_tilt_switch.ino`` under the path of ``esp32-ultimate-kit\c\codes\5.2_tilt_switch``. 
   * Or copy this code into **Arduino IDE**.

.. code-block:: arduino


After code upload successfully, the LED will be turned on when the switch is upright, and turned off when the switch is tilted.


