
.. _car_speed:

3. Speed Up
===================

In addition to the digital signal (HIGH/LOW), the input of L298N can also receive PWM signal to control the speed of the output.

In other words, we can use ``AnalogWrite()`` to control the moving speed of the car.

In this project, we let the car gradually change its forward speed, first accelerating and then decelerating.


**Wiring**

This project is the same wiring as :ref:`car_move_code`.

**Code**

.. note::

    * Open the ``2.speed_up.ino`` file under the path of ``3in1-kit\car_project\2.speed_up``.
    * Or copy this code into **Arduino IDE**.
    
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c15276c1-2359-4de6-ac82-a14a72e041c6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


After the program runs, the car will gradually accelerate and then gradually decelerate.

**How it works?**

The purpose of this project is to write different PWM values to IN1~IN4 to control the forward speed of the car.


#. Use the ``for()`` statement to give ``speed`` in steps of 5, writing values from 0 to 255 so you can see the change in the car's forward speed.

    .. code-block:: arduino

        void loop() {
            for(int i=0;i<=255;i+=5){
                moveForward(i);
                delay(500);
            }
            for(int i=255;i>=0;i-=5){
                moveForward(i);
                delay(500);
            }
        }

#. About the ``moveForward()`` function.

    As opposed to :ref:`car_move_code` which directly gives high/low levels to IN1~IN4, here we pass a parameter ``speed`` to where we need to give high levels.

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(in1, 0);
            analogWrite(in2, speed);
            analogWrite(in3, speed);
            analogWrite(in4, 0);
        }


* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

The ``for`` statement is used to repeat a block of statements enclosed in curly braces. An increment counter is usually used to increment and terminate the loop. 

    .. code-block:: arduino

        for (initialization; condition; increment) {
        // statement(s);
        }

    * ``initialization``: happens first and exactly once.
    * ``condition``: each time through the loop, condition is tested; if it’s true, the statement block, and the increment is executed, then the condition is tested again. When the condition becomes false, the loop ends.
    * ``increment``: executed each time through the loop when condition is true.
