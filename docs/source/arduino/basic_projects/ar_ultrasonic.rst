.. _ar_ultrasonic:

5.12 Measuring Distance
======================================
The ultrasonic module is used for distance measurement or object detection. In this project, we will program the module to obtain obstacle distances. By sending ultrasonic pulses and measuring the time it takes for them to bounce back, we can calculate distances. This enables us to implement distance-based actions or obstacle avoidance behaviors.

**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - For Input
            - IO13, IO14, IO27, IO26, IO25, IO33, IO32, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - For Output
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schematic**

.. image:: ../../img/circuit/circuit_5.12_ultrasonic.png

The ESP32 sends a set of square wave signals to the Trig pin of the ultrasonic sensor every 10 seconds. This prompts the ultrasonic sensor to emit a 40kHz ultrasound signal outward. If there is an obstacle in front, the ultrasound waves will be reflected back.

By recording the time it takes from sending to receiving the signal, dividing it by 2, and multiplying it by the speed of light, you can determine the distance to the obstacle.

**Wiring**

.. image:: ../../img/wiring/5.12_ultrasonic_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_wires`
* :ref:`cpn_ultrasonic`

**Code**

.. note::

    * Open the ``5.12_ultrasonic.ino`` file under the path of ``esp32-ultimate-kit-main\c\codes\5.12_ultrasonic``.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/28ded128-62a8-4b2b-b21a-450f03323cd8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



After the code is successfully uploaded, the serial monitor will print out the distance between the ultrasonic sensor and the obstacle ahead.

**How it works?**

About the application of ultrasonic sensor, we can directly check the subfunction.

.. code-block:: arduino

    float readSensorData(){// ...}

* The ``trigPin`` of the ultrasonic module transmits a 10us square wave signal every 2us.

    .. code-block:: arduino

        // Trigger a low signal before sending a high signal
        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2);
        // Send a 10-microsecond high signal to the trigPin
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10);
        // Return to low signal
        digitalWrite(trigPin, LOW);


* The ``echoPin`` receives a high level signal if there is an obstacle within the range and use the ``pulseIn()`` function to record the time from sending to receiving.

    .. code-block:: arduino

        unsigned long microsecond = pulseIn(echoPin, HIGH);

* The speed of sound is 340 meters per second, which is equivalent to 29 microseconds per centimeter. By measuring the time it takes for a square wave to travel to an obstacle and return, we can calculate the distance traveled by dividing the total time by 2. This gives us the distance of the obstacle from the source of the sound wave.

    .. code-block:: arduino

        float distance = microsecond / 29.00 / 2;  


Note that the ultrasonic sensor will pause the program when it is working, which may cause some lagging when writing complex projects.
