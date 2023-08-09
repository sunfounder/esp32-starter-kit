.. _ar_ac_buz:

3.1 Beep
==================
This is a simple project to make an active buzzer beep quickly four times every second.


**Available Pins**

Here is a list of available pins on the ESP32 board for this project.

.. list-table::
    :widths: 5 20 

    * - Available Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schematic**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

When the IO14 output is high, after the 1K current limiting resistor (to protect the transistor), the S8050 (NPN transistor) will conduct, so that the buzzer will sound.

The role of S8050 (NPN transistor) is to amplify the current and make the buzzer sound louder. In fact, you can also connect the buzzer directly to IO14, but you will find that the buzzer sound is smaller.

**Wiring**


Two types of buzzers are included in the kit. 
We need to use active buzzer. Turn them around, the sealed back (not the exposed PCB) is the one we want.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

The buzzer needs to use a transistor when working, here we use S8050 (NPN Transistor).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_buzzer`
* :ref:`cpn_transistor`


**Code**


.. note::

   * You can open the file ``3.1_beep.ino`` under the path of ``esp32-starter-kit-main\c\codes\3.1_beep``. 
   * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
   
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f17a663c-2941-407e-9137-6f6eacd28c23/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is uploaded successfully, you will hear a beep every second.