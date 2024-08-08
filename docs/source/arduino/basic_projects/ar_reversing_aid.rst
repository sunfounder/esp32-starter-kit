.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_reversing_aid:

6.3 Reversing Aid
===================
Imagine this: You're in your car, about to reverse into a tight parking spot. With our project, you will have an ultrasonic module mounted on the rear of your vehicle, acting as a digital eye. As you engage the reverse gear, the module springs to life, emitting ultrasonic pulses that bounce off obstacles behind you.

The magic happens when these pulses return to the module. It swiftly calculates the distance between your car and the objects, transforming this data into real-time visual feedback displayed on a vibrant LCD screen. You'll witness dynamic, color-coded indicators depicting the proximity of obstacles, ensuring you have a crystal-clear understanding of the surrounding environment.

But we didn't stop there. To immerse you further into this driving experience, we incorporated a lively buzzer. As your car inches closer to an obstacle, the buzzer's tempo intensifies, creating an auditory symphony of warnings. It's like having a personal orchestra guiding you through the complexities of reverse parking.

This innovative project combines cutting-edge technology with an interactive user interface, making your reversing experience safe and stress-free. With the ultrasonic module, LCD display, and lively buzzer working harmoniously, you'll feel empowered and confident while maneuvering in tight spaces, leaving you free to focus on the joy of driving.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Schematic**

.. image:: ../../img/circuit/circuit_6.4_reversing_aid.png
    :width: 800
    :align: center


The ultrasonic sensor in the project emits high-frequency sound waves and measures the time it takes for the waves to bounce back after hitting an object. By analyzing this data, the distance between the sensor and the object can be calculated. To provide a warning when the object is too close, a buzzer is used to produce an audible signal. Additionally, the measured distance is displayed on an LCD screen for easy visualization.

**Wiring**

.. image:: ../../img/wiring/6.4_aid_ultrasonic_bb.png

**Code**


.. note::

    * You can open the file ``6.3_reversing_aid.ino`` under the path of ``esp32-starter-kit-main\c\codes\6.3_reversing_aid`` directly.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``LiquidCrystal I2C`` library is used here, you can install it from the **Library Manager**.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c06deba0-36fd-4f17-8290-c7a39202e089/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

After the code is successfully uploaded, the current detected distance will be displayed on the LCD. Then the buzzer will change the sounding frequency according to different distances.

.. note:: 

    If the code and wiring are correct, but the LCD still fails to display any content, you can adjust the potentiometer on the back to increase the contrast.


**How it works?**

This code helps us create a simple distance measuring device that can measure the distance between objects and provide feedback through an LCD display and a buzzer.

The ``loop()`` function contains the main logic of the program and runs continuously. Let's take a closer look at the ``loop()`` function.

#. Loop to read distance and update parameters

    In the ``loop``, the code first reads the distance measured by the ultrasonic module and updates the interval parameter based on the distance. 

    .. code-block:: arduino

        // Update the distance
        distance = readDistance();

        // Update intervals based on distance
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. Check if it's time to beep

    The code calculates the difference between the current time and the previous beep time, and if the difference is greater than or equal to the interval time, it triggers the buzzer and updates the previous beep time.

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. Update LCD display

    The code clears the LCD display and then displays "Dis:" and the current distance in centimeters on the first line.

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);





