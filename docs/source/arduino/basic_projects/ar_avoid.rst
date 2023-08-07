.. _ar_ir_obstacle:

5.3 Detect the Obstacle
===================================

This module is commonly installed on the car and robot to judge the
existence of the obstacles ahead. Also it is widely used in hand held
device, water faucet and so on.

**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - Available Pins
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Strapping Pins (Input)**

    Strapping pins are a special set of pins that are used to determine specific boot modes during device startup 
    (i.e., power-on reset).
        
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    
    Generally, it is **not recommended to use them as input pins**. If you wish to use these pins, consider the potential impact on the booting process. For more details, please refer to the :ref:`esp32_strapping` section.

**Schematic**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

When the obstacle avoidance module does not detect any obstacles, IO14 returns a high level. However, when it detects an obstacle, it returns a low level. You can adjust the blue potentiometer to modify the detection distance of this module.

**Wiring**


.. image:: ../../img/wiring/5.3_avoid_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_avoid`
* :ref:`cpn_wires`

**Code**

.. note::

   * You can open the file ``5.3.detect_the_obstacle.ino`` under the path of ``esp32-ultimate-kit-main\c\codes\5.3.detect_the_obstacle``. 
   * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b0f22caa-3c77-4dc1-9a33-20ff23d04a5e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

After the code is uploaded successfully, if the IR obstacle avoidance module detects something blocking in front of it, "0" will appear on the serial monitor, otherwise "1" will be displayed.