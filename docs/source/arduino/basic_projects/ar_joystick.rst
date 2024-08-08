.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_joystick:

5.11 Toggle the Joystick
================================
If you play a lot of video games, then you should be very familiar with the Joystick.
It is usually used to move the character around, rotate the screen, etc.

The principle behind Joystick's ability to allow the computer to read our actions is very simple.
It can be thought of as consisting of two potentiometers that are perpendicular to each other.
These two potentiometers measure the analog value of the joystick vertically and horizontally, resulting in a value (x,y) in a planar right-angle coordinate system.


The joystick of this kit also has a digital input, which is activated when the joystick is pressed.

**Required Components**

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 15

        *   - For Analog Input
            - IO14, IO25, I35, I34, I39, I36
        *   - For Digital Input
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
            
**Schematic**

.. image:: ../../img/circuit/circuit_5.11_joystick.png

The SW (Z-axis) pin is connected to IO33, which has a built-in 4.7K pull-up resistor. Therefore, when the SW button is not pressed, it will output a high level. When the button is pressed, it will output a low level.

I34 and I35 will change their values as you manipulate the joystick. The range of values is from 0 to 4095.

**Wiring**

.. image:: ../../img/wiring/5.11_joystick_bb.png

**Code**

.. note::

    * Open the ``5.11_joystick.ino`` file under the path of ``esp32-starter-kit-main\c\codes\5.11_joystick``.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a2065d70-d207-4e51-b03e-ffd2a26597ef/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Open the serial monitor after the code has been uploaded successfully to see the x,y,z values of the joystick.

Remember to Set the serial communication baud rate to 115200.

* The x-axis and y-axis values are analog values that vary from 0 to 4095.
* The Z-axis is a digital value with a status of 1 or 0 ( when pressed, it is 0 ).