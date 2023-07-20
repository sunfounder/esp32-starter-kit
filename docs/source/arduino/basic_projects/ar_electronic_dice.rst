.. _ar_dice:

5.4 Electronic Dice
=============================

This project builds upon the :ref:`py_74hc_7seg` project by adding a button to control the digit displayed on the seven-segment display.

In this project, a random number is generated and displayed on the seven-segment display to simulate a dice roll. When the button is pressed, a stable number (randomly selected from 1 to 6) is displayed on the seven-segment display. Pressing the button again will initiate the simulation of a dice roll, generating random numbers as before. This cycle continues each time the button is pressed.


**Schematic**

.. image:: ../../img/circuit/circuit_6.6_electronic_dice.png

This project builds upon the :ref:`py_74hc595_7seg` project by adding a button to control the digit displayed on the seven-segment display.

The button is directly connected to IO13 without an external pull-up or pull-down resistor because IO13 has an internal pull-up resistor of 47K, eliminating the need for an additional external resistor.


**Wiring**

.. image:: ../../img/wiring/6.6_DICE_bb.png

* :ref:`cpn_esp32_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_74hc595`
* :ref:`cpn_7_segment`
* :ref:`cpn_button`

**Code**

.. note::

    * Open the ``5.4_electronic_dice.ino`` file under the path of ``esp32-ultimate-kit-main\c\codes\5.4_electronic_dice``.
    * Or copy this code into **Arduino IDE**.
    
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ad904f48-cd24-49ce-ad92-91b1fb76364d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
This project is based on :ref:`ar_segment` with a button to start/pause the scrolling display on the 7-segment Display.

When the button is pressed, the 7-segment display scrolls through the numbers 1-6, and when the button is released, it displays a random number.

