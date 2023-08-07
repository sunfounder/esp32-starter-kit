.. _py_guess_number:

6.7 Guess Number
==============================

Are you feeling lucky? Want to test your intuition and see if you can guess the right number? Then look no further than the Guess Number game! 

With this project, you can play a fun and exciting game of chance.

Using an IR remote control, players input numbers between 0 and 99 to try and guess the randomly generated lucky point number. 
The system displays the player's input number on an LCD screen, along with upper and lower limit tips to help guide the 
player towards the right answer. With every guess, players get closer to the lucky point number, 
until finally, someone hits the jackpot and wins the game!


**Schematic**

.. image:: ../../img/circuit/circuit_6.7_guess_number.png

**Wiring**

.. image:: ../../img/wiring/6.7_guess_receiver_bb.png
    :width: 800

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_receiver`
* :ref:`cpn_lcd`

**Code**

.. note::

    * Open the ``6.7_game_guess_number.py`` file located in the ``esp32-ultimate-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * The ``lcd1602.py`` and ``ir_rx`` libraries are used here and check if it's uploaded to ESP32. Refer to :ref:`add_libraries_py` for a tutorial.

.. code-block:: python

    from lcd1602 import LCD
    import machine
    import time
    import urandom
    from machine import Pin
    from ir_rx.print_error import print_error
    from ir_rx.nec import NEC_8

    # IR receiver configuration
    pin_ir = Pin(14, Pin.IN)

    # Initialize the guessing game variables
    lower = 0
    upper = 99
    pointValue = int(urandom.uniform(lower, upper))
    count = 0

    # Initialize the LCD1602 display
    lcd = LCD()

    # Initialize a new random value for the game
    def init_new_value():
        global pointValue, upper, lower, count
        pointValue = int(urandom.uniform(lower, upper))
        print(pointValue)
        upper = 99
        lower = 0
        count = 0
        return False

    # Display messages on the LCD based on the game state
    def lcd_show(result):
        global count
        lcd.clear()
        if result == True: 
            string = "GAME OVER!\n"
            string += "Point is " + str(pointValue)
        else: 
            string = "Enter number: " + str(count) + "\n"
            string += str(lower) + " < Point < " + str(upper)
        lcd.message(string)
        return

    # Process the entered number and update the game state
    def number_processing():
        global upper, count, lower
        if count > pointValue:
            if count < upper:
                upper = count
        elif count < pointValue:
            if count > lower:
                lower = count
        elif count == pointValue:
            return True
        count = 0
        return False

    # Process the key inputs from the IR remote control
    def process_key(key):
        global count, lower, upper, pointValue, result
        if key == "Power":
            init_new_value()
            lcd_show(False)
        elif key == "+":
            result = number_processing()
            lcd_show(result)
            if result:
                time.sleep(5)
                init_new_value()
                lcd_show(False)
            else:
                lcd_show(False)
        elif key.isdigit():
            count = count * 10 + int(key) if count * 10 + int(key) <= 99 else count
            lcd_show(False)

    # Decode the received data and return the corresponding key name
    def decodeKeyValue(data):       
        if data == 0x16:
            return "0"
        if data == 0x0C:
            return "1"
        if data == 0x18:
            return "2"
        if data == 0x5E:
            return "3"
        if data == 0x08:
            return "4"
        if data == 0x1C:
            return "5"
        if data == 0x5A:
            return "6"
        if data == 0x42:
            return "7"
        if data == 0x52:
            return "8"
        if data == 0x4A:
            return "9"
        if data == 0x09:
            return "+"
        if data == 0x15:
            return "-"
        if data == 0x7:
            return "EQ"
        if data == 0x0D:
            return "U/SD"
        if data == 0x19:
            return "CYCLE"
        if data == 0x44:
            return "PLAY/PAUSE"
        if data == 0x43:
            return "FORWARD"
        if data == 0x40:
            return "BACKWARD"
        if data == 0x45:
            return "POWER"
        if data == 0x47:
            return "MUTE"
        if data == 0x46:
            return "MODE"
        return "ERROR"

    def callback(data, addr, ctrl):
        if data < 0:
            pass
        else:
            key = decodeKeyValue(data)
            if key != "ERROR":
                process_key(key)

    # Initialize the IR receiver object with the callback function
    ir = NEC_8(pin_ir, callback)

    # ir.error_function(print_error)

    # Initialize the game with a new random value
    init_new_value()

    # Show the initial game state on the LCD
    lcd_show(False)

    try:
        while True:
            pass
    except KeyboardInterrupt:
        ir.close()



* When the code runs, a secret number is produced but not displayed on the LCD, and what you need to do is to guess it. 
* Press the number you guessed on the remote control, then press the ``+`` key to confirm.
* Simultaneously, the range shown on the I2C LCD1602 will decrease, and you must press the appropriate number based on this new range.
* If you got the lucky number luckily or unluckily, there will appear ``GAME OVER!``.

.. note:: 

    If the code and wiring are correct, but the LCD still fails to display any content, you can adjust the potentiometer on the back to increase the contrast.

**How it works?**

The following is a detailed analysis of part of the code.

#. Initialize the guessing game variables.

    .. code-block:: python
    
        lower = 0
        upper = 99
        pointValue = int(urandom.uniform(lower, upper))
        count = 0


    * ``lower`` and ``upper`` bounds for the secret number.
    * The secret number (``pointValue``) randomly generated between ``lower`` and ``upper`` bounds.
    * The user's current guess (``count``).

#. This function resets the guessing game values and generates a new secret number.

    .. code-block:: python
    
        def init_new_value():
            global pointValue, upper, lower, count
            pointValue = int(urandom.uniform(lower, upper))
            print(pointValue)
            upper = 99
            lower = 0
            count = 0
            return False

#. This function displays the current game status on the LCD screen.

    .. code-block:: python

        def lcd_show(result):
            global count
            lcd.clear()
            if result == True: 
                string = "GAME OVER!\n"
                string += "Point is " + str(pointValue)
            else: 
                string = "Enter number: " + str(count) + "\n"
                string += str(lower) + " < Point < " + str(upper)
            lcd.message(string)
            return

    * If the game is over (``result=True``), it shows ``GAME OVER!`` and the secret number.
    * Otherwise, it shows the current guess (``count``) and the current guessing range (``lower`` to ``upper``)

#. This function processes the user's current guess (``count``) and updates the guessing range.

    .. code-block:: python

        def number_processing():
            global upper, count, lower
            if count > pointValue:
                if count < upper:
                    upper = count
            elif count < pointValue:
                if count > lower:
                    lower = count
            elif count == pointValue:
                return True
            count = 0
            return False
    
    * If the current guess (``count``) is higher than the secret number, the upper bound is updated.
    * If the current guess (``count``) is lower than the secret number, the lower bound is updated.
    * If the current guess (``count``) is equal to the secret number, the function returns ``True`` (game over).

#. This function processes the key press events received from the IR remote.

    .. code-block:: python

        def process_key(key):
            global count, lower, upper, pointValue, result
            if key == "Power":
                init_new_value()
                lcd_show(False)
            elif key == "+":
                result = number_processing()
                lcd_show(result)
                if result:
                    time.sleep(5)
                    init_new_value()
                    lcd_show(False)
                else:
                    lcd_show(False)
            elif key.isdigit():
                count = count * 10 + int(key) if count * 10 + int(key) <= 99 else count
                lcd_show(False)

    * If the ``Power`` key is pressed, the game is reset.
    * If the ``+`` key is pressed, the current guess (``count``) is processed and the game status is updated.
    * If a digit key is pressed, the current guess (``count``) is updated with the new digit.

#. This callback function is triggered when the IR receiver receives

    .. code-block:: python

        def callback(data, addr, ctrl):
            if data < 0:
                pass
            else:
                key = decodeKeyValue(data)
                if key != "ERROR":
                    process_key(key)