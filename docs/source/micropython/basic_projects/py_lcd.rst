.. _py_lcd1602:

2.6 Display Characters
==================================================

Now, we will explore the fascinating world of character display using the I2C LCD1602 module.

Through this project, we will learn how to initialize the LCD module, set the desired display parameters, and send character data to be displayed on the screen. We can showcase custom messages, display sensor readings, or create interactive menus. The possibilities are endless!

By mastering the art of character display on the I2C LCD1602, we will unlock new avenues for communication and information display in our projects. Let's dive into this exciting journey and bring our characters to life on the LCD screen

**Available Pins**

Here is a list of available pins on the ESP32 board for this project.

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Available Pins
        - Usage Description

    *   - IO21
        - SDA
    *   - IO22
        - SCL
    
**Schematic**

.. image:: ../../img/circuit/circuit_2.6_lcd.png

**Wiring**

.. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
    :width: 800

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_wires`
* :ref:`cpn_lcd`


**Code**

.. note::

    * Open the ``2.6_liquid_crystal_display.py`` file located in the ``esp32-ultimate-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
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

