.. _py_lcd:

2.6 Liquid Crystal Display
===============================

LCD1602 is a character type liquid crystal display, which can display 32 (16*2) characters at the same time.

As we all know, though LCD and some other displays greatly enrich the man-machine interaction, 
they share a common weakness. When they are connected to a controller, 
multiple IOs will be occupied of the controller which has no so many outer ports. 
Also it restricts other functions of the controller. 
Therefore, LCD1602 with an I2C bus is developed to solve the problem.

* :ref:`cpn_lcd`
* `Inter-Integrated Circuit - Wikipedia <https://en.wikipedia.org/wiki/I2C>`_


|pin_i2c|

Here we will use the I2C0 interface to control the LCD1602 and display text.


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
        - I2C LCD1602
        - 1
        - |link_i2clcd1602_buy|

**Schematic**

|sch_lcd|

**Wiring**

|wiring_lcd|

**Code**

.. note::

    * Open the ``2.6_liquid_crystal_display.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * The ``lcd1602.py`` library is used here and check if it's uploaded to ESP32. Refer to :ref:`add_libraries_py` for a tutorial.

.. code-block:: python

    # Import the LCD class from the lcd1602 module
    from lcd1602 import LCD

    import time

    # Create an instance of the LCD class and assign it to the lcd variable
    lcd = LCD()
    # Set the string " Hello!\n"
    string = " Hello!\n"
    # Display the string on the LCD screen
    lcd.message(string)

    time.sleep(2)
    # Set the string "    Sunfounder!"
    string = "    Sunfounder!"
    # Display the string on the LCD screen
    lcd.message(string)

    time.sleep(2)
    # Clear the LCD screen
    lcd.clear()


After the script runs, you will be able to see two lines of text will appear on the LCD screen in turn and then disappear.


.. note:: 

    If the code and wiring are correct, but the LCD still fails to display any content, you can adjust the potentiometer on the back to increase the contrast.


**How it works?**

In the ``lcd1602`` library, we integrate the relevant functions of lcd1602 into the LCD class.

#. Import ``lcd1602`` module.

    .. code-block:: python

        from lcd1602 import LCD    

#. Declare an object of the ``LCD`` class and name it ``lcd``.

    .. code-block:: python

        lcd = LCD()

#. This statement will display the text on the LCD. It should be noted that the argument must be a string type. If we want to pass an integer or float, we must use the forced conversion statement ``str()``.

    .. code-block:: python

        lcd.message(string)


#. If you call this statement multiple times, lcd will superimpose the texts. This requires the use of the following statement to clear the display.

    .. code-block:: python

        lcd.clear()

