.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _py_line_track:

5.4 Detect the Line
===================================

The line-tracking module is used to detect the presence of black areas on the ground, such as black lines taped with electrical tape.

Its emitter emits appropriate infrared light into the ground, which is relatively absorbed and weakly reflected by black surfaces. The opposite is true for white surfaces. If reflected light is detected, the ground is currently indicated as white. If it is not detected, it is indicated as black.

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
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - Available Pins
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Strapping Pins (Input)**

    Strapping pins are a special set of pins that are used to determine specific boot modes during device startup 
    (i.e., power-on reset).

        
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    
    Generally, it is **not recommended to use them as input pins**. If you wish to use these pins, consider the potential impact on the booting process. For more details, please refer to the :ref:`esp32_strapping` section.

**Schematic**

.. image:: ../../img/circuit/circuit_5.4_line.png

When the line tracking module detects a black line, IO14 returns a high level. On the other hand, when it detects a white line, IO14 returns a low level. You can adjust the blue potentiometer to modify the sensitivity of this module's detection.


**Wiring**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**Code**

.. note::

    * Open the ``5.4_detect_the_line.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 


.. code-block:: python

    import machine
    import time

    # Create a pin object named greyscale, set pin number 14 as input
    line = machine.Pin(14, machine.Pin.IN)


    while True:
        # Check if the value is 1 (black)
        if line.value() == 1:
            # Print "black"
            print("black")
            time.sleep(0.5)
        # If the value is not 1 (it's 0, which means white)
        else :
            # Print "white"
            print("white")
            time.sleep(0.5)



When the line tracking module detects there is black line, there appears "black" on the Shell; otherwise, "white" is displayed.
