.. _ar_servo:

4.3 Swinging Servo
======================
A Servo is a type of position-based device known for its ability to maintain specific angles and deliver precise rotation. This makes it highly desirable for control systems that demand consistent angle adjustments. It's not surprising that Servos have found extensive use in high-end remote-controlled toys, from airplane models to submarine replicas and sophisticated remote-controlled robots.

In this intriguing adventure, we'll challenge ourselves to manipulate the Servo in a unique way - by making it sway! This project offers a brilliant opportunity to dive deeper into the dynamics of Servos, sharpening your skills in precise control systems and offering a deeper understanding of their operation.

Are you ready to make the Servo dance to your tunes? Let's embark on this exciting journey!


**Available Pins**

Here is a list of available pins on the ESP32 board for this project.

.. list-table::
    :widths: 5 20 

    * - Available Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schematic**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**Wiring**

* Orange wire is signal and connected to IO25.
* Red wire is VCC and connected to 5V.
* Brown wire is GND and connected to GND.

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png


* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_wires`
* :ref:`cpn_servo`

**Code**

.. note::

    * Open the ``4.3_servo.ino`` file under the path of ``esp32-starter-kit-main\c\codes\4.3_servo``. Or copy this code into **Arduino IDE**.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``ESP32Servo`` library is used here, you can install it from the **Library Manager**.

        .. image:: img/servo_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/34c7969e-fee3-413c-9fe7-9d38ca6fb906/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Once you finish uploading the code, you can see the servo arm rotating in the range 0°~180°.

**How it works?**

#. Include the |link_esp32servo| library: This line imports the ESP32Servo library, which is required to control the servo motor.

    .. code-block:: arduino

        #include <ESP32Servo.h>

#. Define the servo and the pin it is connected to: This section declares a Servo object (``myServo``) and a constant integer (``servoPin``) to represent the pin that the servo motor is connected to (pin 25).

    .. code-block:: arduino

        // Define the servo and the pin it is connected to
        Servo myServo;
        const int servoPin = 25;

#. Define the minimum and maximum pulse widths for the servo: This section sets the minimum and maximum pulse widths for the servo motor (0.5 ms and 2.5 ms, respectively).

    .. code-block:: arduino

        // Define the minimum and maximum pulse widths for the servo
        const int minPulseWidth = 500; // 0.5 ms
        const int maxPulseWidth = 2500; // 2.5 ms


#. The ``setup`` function initializes the servo motor by attaching it to the specified pin and setting its pulse width range. It also sets the PWM frequency for the servo to the standard 50Hz.

    .. code-block:: arduino

        void setup() {
            // Attach the servo to the specified pin and set its pulse width range
            myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

            // Set the PWM frequency for the servo
            myServo.setPeriodHertz(50); // Standard 50Hz servo
        }
    
    * ``attach (int pin, int min, int max)``: This function attaches the servo motor to the specified GPIO pin and sets the minimum and maximum pulse widths for the servo.

        * ``pin``: The GPIO pin number that the servo is connected to. 
        * The ``min`` and ``max``: the minimum and maximum pulse widths, respectively, in microseconds. These values define the range of motion of the servo motor.

    * ``setPeriodHertz(int hertz)``: This function sets the PWM frequency for the servo motor in hertz.

        * ``hertz``: The desired PWM frequency in hertz. The default PWM frequency for servos is 50Hz, which is suitable for most applications. 


#. The ``loop`` function is the main part of the code that continuously runs. It rotates the servo motor from 0 to 180 degrees, then back to 0 degrees. This is done by mapping the angle to the corresponding pulse width and updating the servo motor with the new pulse width value.

    .. code-block:: arduino

        void loop() {
            // Rotate the servo from 0 to 180 degrees
            for (int angle = 0; angle <= 180; angle++) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }
    
            // Rotate the servo from 180 to 0 degrees
            for (int angle = 180; angle >= 0; angle--) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }
        }

    * ``writeMicroseconds(int value)``: This function sets the pulse width of the servo motor in microseconds. 
    
        * ``value``: The desired pulse width in microseconds. 
        
        The ``writeMicroseconds(int value)`` function takes an integer value as its argument, representing the desired pulse width in microseconds. This value should typically fall within the range specified by the minimum and maximum pulse widths (``minPulseWidth`` and ``maxPulseWidth``) defined earlier in the code. The function then sets the pulse width for the servo motor, causing it to move to the corresponding position.
        