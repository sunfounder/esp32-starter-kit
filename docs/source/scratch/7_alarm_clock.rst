.. _sh_light_alarm:

2.7 Light Alarm Clock
======================

In life, there are various kinds of time alarm clocks. Now let's make a light-controlled alarm clock. When morning comes, the brightness of light increases and this light-controlled alarm clock will remind you that it's time to get up.

.. image:: img/10_clock.png

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

You Will Learn
---------------------

- Photoresistor working principle
- Stopping sound playback and stopping scripts from running

Build the Circuit
-----------------------

A photoresistor or photocell is a light-controlled variable resistor. The resistance of a photoresistor decreases with increasing incident light intensity.

Build the circuit according to the following diagram.

Connect one end of the photoresistor to 5V, the other end to pin35, and connect a 10K resistor in series with GND at this end.

So when the light intensity increases, the resistance of a photoresistor decreases, the voltage division of the 10K resistor increases, and the value obtained by pin35 becomes larger.

.. image:: img/circuit/8_light_alarm_bb.png

Programming
------------------

**1. Select a sprite**

Delete the default sprite, click the **Choose a Sprite** button in the lower right corner of the sprite area, enter **bell** in the search box, and then click to add it.

.. image:: img/10_sprite.png

**2. Read the value of pin35**

Create two variables **before** and **current**. When green flag is clicked, read the value of pin35 and store it in variable **before** as a reference value. In [forever], read the value of pin35 again, store it in the variable **current**.

.. image:: img/10_reada0.png

**3. Make a sound**

When the value of current pin35 is greater than the previous 50, which represents the current light intensity is greater than the threshold, then let the sprite make a sound.

.. image:: img/10_sound.png

**4. Turning the sprite**

Use [turn block] to make the **bell** sprite turn left and right to achieve the alarm effect.

.. image:: img/10_turn.png

**5. stop all**

Stops the alarm when it has been ringing for a while.

.. image:: img/10_stop.png

