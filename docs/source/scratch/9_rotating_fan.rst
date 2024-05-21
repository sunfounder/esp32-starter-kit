.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _sh_rotating_fan:

2.9 Rotating Fan
========================

In this project, we will make a spinning star sprite and fan.

Clicking on the left and right arrow sprites on the stage will control the clockwise and counterclockwise rotation of the motor and star sprite, click on the star sprite to stop the rotation.

.. image:: img/13_fan.png

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
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_l293d`
        - \-

You Will Learn
---------------------

- Motor working principle
- Broadcast function
- Stop other script in sprite block

Build the Circuit
-----------------------

.. image:: img/circuit/10_rotaing_fan_bb.png

Programming
------------------
The effect we want to achieve is to use 2 arrow sprites to control the clockwise and counterclockwise rotation of the motor and the star sprite respectively, clicking on the star sprite will stop the motor from rotating.

**1. Add sprites**

Delete the default sprite, then select the **Star** sprite and the **Arrow1** sprite, and copy **Arrow1** once.

.. image:: img/13_star.png

In the **Costumes** option, change the **Arrow1** sprite to a different direction costume.

.. image:: img/13_star1.png

Adjust the size and position of the sprite appropriately.

.. image:: img/13_star2.png

**2. Left arrow sprite**

When this sprite is clicked, it broadcasts a message - turn, then sets digital pin12 to low and pin14 to high, and sets the variable **flag** to 1. If you click the left arrow sprite, you will find that the motor turns counterclockwise, if your turn is clockwise, then you swap the positions of pin12 and pin14.

There are 2 points to note here.

* `[broadcast <https://en.scratch-wiki.info/wiki/Broadcast>`_]: from the **Events** palette, used to broadcast a message to the other sprites, when the other sprites receive this message, it will perform a specific event. For example, here is **turn**, when the **star** sprite receives this message, it executes the rotation script.
* variable flag: The direction of rotation of the star sprite is determined by the value of flag. So when you create the **flag** variable, you need to make it apply to all sprites.

.. image:: img/13_left.png
    :width: 600

**3. right-arrow sprite**

When this sprite is clicked, broadcast a message turn, then set digital pin12 high and pin14 low to make the motor turn clockwise and set the **flag** variable to 0.

.. image:: img/13_right.png

**4. star sprite**

There are 2 events included here.

* When the **star** sprite receives the broadcasted message turn, it determines the value of flag; if flag is 1, it turns 10 degrees to the left, otherwise it reverses. Since it is in [FOREVER], it will keep turning.
* When this sprite is clicked, set both pins of the motor to high to make it stop rotating and stop the other scripts in this sprite.

.. image:: img/13_broadcast.png



