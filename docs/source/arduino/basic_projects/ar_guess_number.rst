.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_guess_number:

6.7 Guess Number
==================
Are you feeling lucky? Want to test your intuition and see if you can guess the right number? Then look no further than the Guess Number game! 

With this project, you can play a fun and exciting game of chance.

Using an IR remote control, players input numbers between 0 and 99 to try and guess the randomly generated lucky point number. 
The system displays the player's input number on an LCD screen, along with upper and lower limit tips to help guide the 
player towards the right answer. With every guess, players get closer to the lucky point number, 
until finally, someone hits the jackpot and wins the game!

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Schematic**

.. image:: ../../img/circuit/circuit_6.7_guess_number.png

**Wiring**

.. image:: ../../img/wiring/6.7_guess_receiver_bb.png
    :width: 800

**Code**

.. note::

    * You can open the file ``6.7_guess_number.ino`` under the path of ``esp32-starter-kit-main\c\codes\6.7_guess_number`` directly.
    * The ``LiquidCrystal_I2C`` and  ``IRremoteESP8266`` libraries are used here, refer to :ref:`install_lib_man` for a tutorial to install.

.. warning::

    If you are using an ESP32 development board version 3.0.0 or higher, you may encounter errors during the compilation process.
    This issue is usually because the newer versions of the board no longer support the ``IRremoteESP8266`` library.
    To properly run this example, it is recommended to downgrade your ESP32 board's firmware version to 2.0.17. 
    After completing this example, upgrade back to the latest version.


    .. image:: ../../faq/img/version_2.0.17.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e4217f5-c1b7-4859-a34d-d791bbc5e57a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

    
* After the code is successfully uploaded, press any number button on the remote control to start the game.
* Input a number using the number buttons on the remote control. To input a single digit, you need to press the **cycle** key to confirm.
* The system will show the input number and the upper and lower limit tips on the LCD screen.
* Keep guessing until you correctly guess the lucky point number.
* After a successful guess, the system will show a success message and generate a new lucky point number.

.. note:: 

    If the code and wiring are correct, but the LCD still fails to display any content, you can adjust the potentiometer on the back to increase the contrast.


**How it works?**

#. In the ``setup()`` function, the I2C LCD screen and IR receiver are initialized. Then call the ``initNewValue()`` function to generate a new random lucky number, and a welcome message is displayed on the LCD screen.

    .. code-block:: arduino

        void setup() {
            // Initialize the LCD screen
            lcd.init();
            lcd.backlight();

            // Start the serial communication
            Serial.begin(9600);

            // Enable the IR receiver
            irrecv.enableIRIn();

            // Initialize a new lucky point value
            initNewValue();
        }

#. In the ``loop`` function, the code waits for a signal from the IR receiver. When a signal is received, the ``decodeKeyValue`` function is called to decode the signal and get the corresponding button value.

    .. code-block:: arduino

        void loop() {
        // If a signal is received from the IR receiver
        if (irrecv.decode(&results)) {
            bool result = 0;
            String num = decodeKeyValue(results.value);

            // If the POWER button is pressed
            if (num == "POWER") {
                initNewValue(); // Initialize a new lucky point value
            }

            // If the CYCLE button is pressed
            else if (num == "CYCLE") {
                result = detectPoint(); // Detect the input number
                lcdShowInput(result); // Show the result on the LCD screen
            }

            // If a number button (0-9) is pressed, 
            //add the digit to the input number 
            //and detect the number if it is greater than or equal to 10
            else if (num >= "0" && num <= "9") {
                count = count * 10;
                count += num.toInt();
                if (count >= 10) {
                    result = detectPoint();
                }
                lcdShowInput(result);
            }
            irrecv.resume();
        }
        }

    * Depending on the button value, the appropriate function is called. If a number button is pressed, the ``count`` variable is updated, and the ``detectPoint`` function is called to detect if the input number is correct. The ``lcdShowInput`` function is called to show the input number and the upper and lower limit tips on the LCD screen.
    * If the ``POWER`` button is pressed, the ``initNewValue`` function is called to generate a new lucky point number and show the welcome message on the LCD screen.
    * If the ``CYCLE`` button is pressed, the ``detectPoint`` function is called to detect if the input number is correct. The ``lcdShowInput`` function is called to show the input number and the upper and lower limit tips on the LCD screen.

