.. _ar_transistor:

5.6 Two Kinds of Transistors
==========================================
This kit is equipped with two types of transistors, S8550 and S8050, the former is PNP and the latter is NPN. They look very similar, and we need to check carefully to see their labels.
When a High level signal goes through an NPN transistor, it is energized. But a PNP one needs a Low level signal to manage it. Both types of transistor are frequently used for contactless switches, just like in this experiment.

|img_NPN&PNP|

Let's use LED and button to understand how to use transistor!

:ref:`cpn_transistor`

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
        - 3(220Ω, 1KΩ, 10KΩ)
        - |link_resistor_buy|
    *   - 6
        - LED
        - 1
        - |link_led_buy|
    *   - 7
        - Button
        - 1
        - |link_button_buy|
    *   - 8
        - Transistor
        - 1(S8050/S8550)
        - |link_transistor_buy|


**Way to connect NPN (S8050) transistor**

|sch_s8050|

In this circuit, when the button is pressed, pin14 is high.

By programming pin26 to output high, after a 1k current limiting resistor (to protect the transistor), the S8050 (NPN transistor) is allowed to conduct, thus allowing the LED to light up.


|wiring_s8050|

**Way to connect PNP(S8550) transistor**

|sch_s8550|

In this circuit, pin14 is low by the default and will change to high when the button is pressed.

By programming pin26 to output **low**, after a 1k current limiting resistor (to protect the transistor), the S8550 (PNP transistor) is allowed to conduct, thus allowing the LED to light up.

The only difference you will notice between this circuit and the previous one is that in the previous circuit the cathode of the LED is connected to the **collector** of the **S8050 (NPN transistor)**, while this one is connected to the **emitter** of the **S8550 (PNP transistor)**.

|wiring_s8550|


**Code**

.. note::

   * You can open the file ``5.6_transistor.ino`` under the path of ``esp32-ultimate-kit\c\codes\5.6_transistor``. 
   * Or copy this code into **Arduino IDE**.
   
   

.. raw:: html


Two types of transistors can be controlled using the same code. 
When we press the button, the ESP32 will send a high-level signal to the transistor; 
when we release it, it will send a low-level signal.

* The circuit using the S8050 (NPN transistor) will light up when the button is pressed, indicating that it is in a high-level conduction state;
* The circuit using the S8550 (PNP transistor) will light up when the button is released, indicating that it is in a low-level conduction state.