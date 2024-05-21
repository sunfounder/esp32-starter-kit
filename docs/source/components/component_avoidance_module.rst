.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_avoid:

Obstacle Avoidance Module
===========================================


.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Power supply, 3.3 ~ 5V DC.
* **GND**: Ground
* **OUT**: Signal pin, usually high level, and low level when an obstacle is detected.


The IR obstacle avoidance module has strong adaptability to environmental light, it has a pair of infrared transmitting and receiving tubes.

The transmitting tube emits infrared frequency, when the detection direction encounters an obstacle, the infrared radiation is received by the receiving tube, 
after the comparator circuit processing, the indicator will light up and output low level signal.

The detection distance can be adjusted by potentiometer, the effective distance range 2-30cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Example**

* :ref:`ar_ir_obstacle` (Arduino Project)
* :ref:`py_ir_obstacle` (MicroPython Project)
* :ref:`sh_shooting` (Scratch Project)
* :ref:`sh_tap_tile` (Scratch Project)






