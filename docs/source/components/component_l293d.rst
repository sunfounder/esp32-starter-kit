.. _cpn_l293d:

L293D 
=================

L293D is a 4-channel motor driver integrated by chip with high voltage and high current. 
It's designed to connect to standard DTL, TTL logic level, and drive inductive loads (such as relay coils, DC, Stepper Motors) and power switching transistors etc. 
DC Motors are devices that turn DC electrical energy into mechanical energy. They are widely used in electrical drive for their superior speed regulation performance.

See the figure of pins below. L293D has two pins (Vcc1 and Vcc2) for power supply. 
Vcc2 is used to supply power for the motor, while Vcc1 to supply for the chip. Since a small-sized DC motor is used here, connect both pins to +5V.

.. image:: img/l293d111.png

The following is the internal structure of L293D. 
Pin EN is an enable pin and only works with high level; A stands for input and Y for output. 
You can see the relationship among them at the right bottom. 
When pin EN is High level, if A is High, Y outputs high level; if A is Low, Y outputs Low level. When pin EN is Low level, the L293D does not work.

.. image:: img/l293d334.png

* `L293D Datasheet <https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1627004062301&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D>`_


**Example**

* :ref:`ar_motor` (Arduino Project)
* :ref:`ar_pump` (Arduino Project)
* :ref:`py_motor` (MicroPython Project)
* :ref:`py_pump` (MicroPython Project)
* :ref:`sh_rotating_fan` (Scratch Project)