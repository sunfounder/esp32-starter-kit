.. _ar_joystick:

5.11 Toggle the Joystick
================================

The joystick should be very familiar to anyone who plays video games regularly.
It is usually used to move characters or rotate the screen.

Our movements can be read by the Joystick, which works on a very simple principle.
It consists of two potentiometers that are perpendicular to each other.
These two potentiometers measure the analog value of the joystick in both vertical and horizontal directions, producing a value (x,y) in a planar right-angle coordinate system.


This kit also includes a joystick with a digital input. It is activated when the joystick is pressed.




**Schematic**

.. image:: img/circuit_5.3_joystick.png

.. note::
    The SW pin is connected to a 10K pull-up resistor, 
    the reason is to be able to get a stable high level on the SW pin (Z axis) when the joystick is not pressed; 
    otherwise the SW is in a suspended state and the output value may vary between 0/1.


**Wiring**



.. image:: img/toggle_the_joystick_bb.jpg
    :width: 800
    :align: center


* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_joystick`

**Code**

.. note::

    * Open the ``5.9_joystick.ino`` file under the path of ``esp32-ultimate-kit\c\codes\5.9_joystick``.
    * Or copy this code into **Arduino IDE**.
    
    
.. raw:: html
    

Open the serial monitor after the code has been uploaded successfully to see the x,y,z values of the joystick.

* The x-axis and y-axis values are analog values that vary from 0 to 4095.
* The Z-axis is a digital value with a status of 1 or 0 ( when pressed, it is 0 ).