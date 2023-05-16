.. _ar_pump:

4.2 Pumping
===================

The water pump is also a motor, which converts the mechanical energy of the motor or other external energy through a special structure to transport the liquid.

**Schematic**

.. image:: img/circuit_1.3_wheel.png

IN1~IN4 are the inputs of the L298N module, and OUT1~OUT4 are the outputs.

A simple way to use them is: input high level for INx, OUTx will output high level; input low level for INx, OUTx will output low level.
Connecting the two ends of the motor to OUT1 and OUT2, inputting opposite level signals for IN1 and IN2 will make the motor rotate. OUT3 and OUT4 can be used in the same way.

**Wiring**


.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L298N
      - R3 Board
      - Motor
    * - 12V
      - 5V
      - 
    * - GND
      - GND
      - 
    * - IN3
      - 9
      -
    * - IN4
      - 10
      - 
    * - OUT3
      - 
      - one wire of the motor
    * - OUT4
      - 
      - one wire of the motor

.. image:: img/pumping_bb.jpg
    :width: 800
    :align: center

* :ref:`cpn_uno`
* :ref:`cpn_wires`
* :ref:`cpn_l298n`
* :ref:`cpn_pump`

**Code**

.. note::

   * You can open the file ``4.2_pump.ino`` under the path of ``esp32-ultimate-kit\c\codes\4.2_pump``. 
   * Or copy this code into **Arduino IDE**.
   
   
.. raw:: html
    


Connect the tubing to the pump and place it inside the water-filled container. Once the code has been successfully uploaded, you will observe the water in the container gradually being drained. During this experiment, please ensure that the electrical circuit is kept away from water to prevent short-circuiting!
