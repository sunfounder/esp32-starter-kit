.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_lcd1602:

2.6 Display Characters
===============================

Now, we will explore the fascinating world of character display using the I2C LCD1602 module.

Through this project, we will learn how to initialize the LCD module, set the desired display parameters, and send character data to be displayed on the screen. We can showcase custom messages, display sensor readings, or create interactive menus. The possibilities are endless!

By mastering the art of character display on the I2C LCD1602, we will unlock new avenues for communication and information display in our projects. Let's dive into this exciting journey and bring our characters to life on the LCD screen

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
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|


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

**Code**

.. note::

    * Open the ``2.6_lcd1602.ino`` file under the path of ``esp32-starter-kit-main\c\codes\2.6_lcd1602``.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``LiquidCrystal I2C`` library is used here, you can install it from the **Library Manager**.

        .. image:: img/lcd_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/31e33e53-67b2-4e29-b78b-f647fd45fb0b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

When this program is uploaded, the I2C LCD1602 will display the welcome message, "Hello, Sunfounder!", for 3 seconds. After that, the screen will show a "COUNT:" label and the count value, which increments every second.


.. note:: 

    If the code and wiring are correct, but the LCD still fails to display any content, you can adjust the potentiometer on the back to increase the contrast.

**How it works?**

By calling the library ``LiquidCrystal_I2C.h``, you can easily drive the LCD. 

.. code-block:: arduino

    #include <LiquidCrystal_I2C.h>

Library Functions：


* Creates a new instance of the ``LiquidCrystal_I2C`` class that represents a particular LCD attached to your Arduino board.

    .. code-block:: arduino

        LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

    * ``lcd_AddR``: The address of the LCD defaults to 0x27.
    * ``lcd_cols``: The LCD1602 has 16 columns.
    * ``lcd_rows``: The LCD1602 has 2 rows.

* Initialize the lcd.

    .. code-block:: arduino

        void init()

* Turn the (optional) backlight on.

    .. code-block:: arduino

        void backlight()

* Turn the (optional) backlight off.

    .. code-block:: arduino

        void nobacklight()

* Turn the LCD display on.

    .. code-block:: arduino

        void display()

* Turn the LCD display off quickly.

    .. code-block:: arduino

        void nodisplay()

* Clear display, set cursor position to zero.

    .. code-block:: arduino

        void clear()

* Set the cursor position to col,row.

    .. code-block:: arduino

        void setCursor(uint8_t col,uint8_t row)

* Prints text to the LCD.

    .. code-block:: arduino

        void print(data,BASE)

    * ``data``: The data to print (char, byte, int, long, or string).
    * ``BASE (optional)``: The base in which to print numbers.

        * ``BIN`` for binary (base 2)
        * ``DEC`` for decimal (base 10)
        * ``OCT`` for octal (base 8)
        * ``HEX`` for hexadecimal (base 16).
