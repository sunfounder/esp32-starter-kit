.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _sh_low_temperature:

2.6 Low Temperature Alarm
=========================

In this project, we will make a low temperature alarm system, when the temperature is below the threshold, the **Snowflake** sprite will appear on the stage.

.. image:: img/9_tem.png

Required Components
---------------------

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

You Will Learn
---------------------

- Thermistor working principle
- Multivariable and Subtractive Operations

Build the Circuit
-----------------------

A thermistor is a type of resistor whose resistance is strongly dependent on temperature, more so than in standard resistors, and there are two types of resistors, PTC (resistance increases as temperature increases) and PTC (resistance decreases as temperature increases).

Build the circuit according to the following diagram.

One end of the thermistor is connected to GND, the other end is connected to pin35, and a 10K resistor is connected in series to 5V.

The NTC thermistor is used here, so when the temperature rises, the resistance of the thermistor decreases, the voltage division of pin35 decreases, and the value obtained from pin35 decreases, and vice versa increases.

.. image:: img/circuit/7_low_temp_bb.png

Programming
------------------

**1. Select a sprite**

Delete the default sprite, click the **Choose a Sprite** button in the lower right corner of the sprite area, enter **Snowflake** in the search box, and then click to add it.

.. image:: img/9_snow.png

**2. Create 2 variables**

Create two variables, **before** and **current**, to store the value of pin35 in different cases.

.. image:: img/9_va.png

**3. Read the value of pin35**

When the green flag is clicked, the value of pin35 is read and stored in the variable **before**.

.. image:: img/9_before.png

**4. Read the value of pin35 again**

In [forever], read the value of pin35 again and store it in the variable **current**.

.. image:: img/9_current.png

**5. Determining temperature changes**

Using the [if else] block, determine if the current value of pin35 is 200 greater than before, which represents a decrease in temperature. At this point let **Snowflake** sprite show, otherwise hide.

* [-] & [>]: subtraction and comparison operators from **Operators** platette.

.. image:: img/9_show.png