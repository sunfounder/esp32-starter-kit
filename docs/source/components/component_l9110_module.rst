.. _cpn_l9110:

L9110 Motor Drive Module
=============================

The L9110 motor driver module is capable of simultaneously driving two motors. It contains two independent L9110S driver chips, with each channel having a continuous current output capability of 800mA.

This module has a wide voltage range from 2.5V to 12V, allowing it to be compatible with both 3.3V and 5V microcontrollers.

The L9110 motor driver module provides a convenient and efficient solution for controlling motors in various applications. Its dual-channel design allows independent control of two motors, making it suitable for projects requiring the control of multiple motors simultaneously.

With its high continuous current output capability, the L9110 motor driver module can effectively drive small to medium-sized motors, enabling the implementation of various robotic, automation, and motor control projects. Its wide voltage range adds versatility, ensuring compatibility with different power supply configurations.

The module is designed to be easy to use, with accessible input and output terminals for connecting to microcontrollers or other control devices. It also incorporates protective features such as overcurrent and overtemperature protection, enhancing the safety and reliability of motor operations.

.. image:: img/xx.jpg
    :width: 400
    :align: center

* B-1A & B-1B: Input pins for controlling the spinning direction of Motor B.
* A-1A & A-1B: Input pins for controlling the spinning direction of Motor A.
* B-OUT1 & B-OUT2: Output pins for Motor B.
* A-OUT1 & A-OUT2: Output pins for Motor A.
* VCC: Power input pin (2.5V-12V).
* GND: Ground pin.

**Features**

* On-board 2 L9110S motor control chip
* Dual-channel motor control.
* Independent motor spinning direction control.
* High current output (800mA per channel).
* Wide voltage range (2.5V-12V).
* Compact design.
* Convenient input and output terminals.
* Built-in protective features.
* Versatile applications.
* PCB Size: 29.2mm x 23mm
* Operating Temperature: -20°C ~ 80°C
* Power-On LED indicator

**Operating Principle**

Here is the truth table of Motor B:

This truth table shows the different states of Motor B based on the values of input pins B-1A and B-1B. It indicates the direction of rotation (clockwise or counterclockwise), braking, or stopping of Motor B.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B
      - The state of Motor B
    * - 1
      - 0
      - Rotate clockwise
    * - 0
      - 1
      - Rotate counterclockwise
    * - 0
      - 0
      - Brake
    * - 1
      - 1
      - Stop

Here is the truth table of Motor A:

This truth table shows the different states of Motor A based on the values of input pins A-1A and A-1B. It indicates the direction of rotation (clockwise or counterclockwise), braking, or stopping of Motor A.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - The state of Motor B
    * - 1
      - 0
      - Rotate clockwise
    * - 0
      - 1
      - Rotate counterclockwise
    * - 0
      - 0
      - Brake
    * - 1
      - 1
      - Stop


**Example**

* :ref:`ar_motor` (Learning Project)
* :ref:`car_move` (Car Project)
* :ref:`car_speed` (Car Project)
* :ref:`iot_car` (IoT Project)
* :ref:`sh_test` (Scratch Project)


