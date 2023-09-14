.. _cpn_esp32_wroom_32e:

ESP32 WROOM 32E
=================

The ESP32 WROOM-32E is a versatile and powerful module built around Espressif's ESP32 chipset. It offers dual-core processing, integrated Wi-Fi and Bluetooth connectivity, and boasts a wide range of peripheral interfaces. Known for its low-power consumption, the module is ideal for IoT applications, enabling smart connectivity and robust performance in compact form factors.

.. image:: img/esp32_wroom_32e.jpg
    :width: 600
    :align: center


Key features include:

* **Processing Power**: It's equipped with a dual-core Xtensa® 32-bit LX6 microprocessor, offering scalability and flexibility.
* **Wireless Capabilities**: With integrated 2.4 GHz Wi-Fi and dual-mode Bluetooth, it's perfectly suited for applications demanding stable wireless communication.
* **Memory & Storage**: It comes with ample SRAM and high-performance flash storage, catering to user programs and data storage needs.
* **GPIO**: Offering up to 34 GPIO pins, it supports a variety of external devices and sensors.
* **Low Power Consumption**: Multiple power-saving modes are available, making it ideal for battery-powered or energy-efficient scenarios.
* **Security**: Integrated encryption and security features ensure user data and privacy are well-protected.
* **Versatility**: From simple household appliances to complex industrial machinery, the WROOM-32E delivers consistent, efficient performance.

In summary, the ESP32 WROOM-32E not only offers robust processing capabilities and diverse connectivity options but also boasts an array of features making it a preferred choice in the IoT and smart device sectors.

* |link_esp32_datasheet|

.. _esp32_pinout:

Pinout Diagram
-------------------------

The ESP32 has some pin usage limitations due to various functionalities sharing certain pins. When designing a project, it's a good practice to carefully plan the pin usage and cross-check for potential conflicts 
to ensure proper functioning and avoid issues.


.. image:: img/esp32_pinout.jpg
    :width: 800
    :align: center

Here are some of the key restrictions and considerations:

* **ADC1 and ADC2**: ADC2 cannot be used when WiFi or Bluetooth is active. However, ADC1 can be used without any restrictions.
* **Bootstrapping Pins**: GPIO0, GPIO2, GPIO5, GPIO12, and GPIO15 are used for bootstrapping during the boot process. Care should be taken not to connect external components that could interfere with the boot process on these pins.
* **JTAG Pins**: GPIO12, GPIO13, GPIO14, and GPIO15 can be used as JTAG pins for debugging purposes. If JTAG debugging is not required, these pins can be used as regular GPIOs.
* **Touch Pins**: Some pins support touch functionalities. These pins should be used carefully if you intend to use them for touch sensing.
* **Power Pins**: Some pins are reserved for power-related functions and should be used accordingly. For example, avoid drawing excessive current from power supply pins like 3V3 and GND.
* **Input-only Pins**: Some pins are input-only and should not be used as outputs.


.. _esp32_strapping:

**Strapping Pins**
--------------------------

ESP32 has five strapping pins:

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Strapping Pins
        - Description
    *   - IO5
        - Defaults to pull-up, the voltage level of IO5 and IO15 affects the Timing of SDIO Slave.
    *   - IO0
        - Defaults to pull-up, if pulled low, it enters download mode.
    *   - IO2
        - Defaults to pull-down, IO0 and IO2 will make ESP32 enter download mode.
    *   - IO12(MTDI)
        - Defaults to pull-down, if pulled high, ESP32 will fail to boot up normally.
    *   - IO15(MTDO)
        - Defaults to pull-up, if pulled low, debug log will not be visible. Additionally, the voltage level of IO5 and IO15 affects the Timing of SDIO Slave.


Software can read the values of these five bits from register "GPIO_STRAPPING".
During the chip's system reset release (power-on-reset, RTC watchdog reset and brownout reset), the latches of
the strapping pins sample the voltage level as strapping bits of "0" or "1", and hold these bits until the chip is
powered down or shut down. The strapping bits configure the device's boot mode, the operating voltage of
VDD_SDIO and other initial system settings.

Each strapping pin is connected to its internal pull-up/pull-down during the chip reset. Consequently, if a
strapping pin is unconnected or the connected external circuit is high-impedance, the internal weak
pull-up/pull-down will determine the default input level of the strapping pins.

To change the strapping bit values, users can apply the external pull-down/pull-up resistances, or use the host
MCU's GPIOs to control the voltage level of these pins when powering on ESP32.

After reset release, the strapping pins work as normal-function pins.
Refer to following table for a detailed boot-mode configuration by strapping pins.

.. image:: img/esp32_strapping.png

* FE: falling-edge, RE: rising-edge
* Firmware can configure register bits to change the settings of "Voltage of Internal
* LDO (VDD_SDIO)" and "Timing of SDIO Slave", after booting.
* The module integrates a 3.3 V SPI flash, so the pin MTDI cannot be set to 1 when the module is powered up.

.. _cpn_esp32_camera_extension:

ESP32 Camera Extension
=======================

We have designed an expansion board that enables you to fully utilize the camera and SD card functionalities of the ESP32 WROOM 32E. By combining the OV2640 camera, Micro SD, and ESP32 WROOM 32E, you get an all-in-one expansion board.

The board provides two types of GPIO headers - one with female headers, perfect for quick prototyping projects. The other type features screw terminals, ensuring stable wire connections and making it suitable for IoT projects.

Additionally, you can power your project using a single 3.7V 18650 battery. If the battery runs low, you can conveniently charge it by simply plugging in a 5V Micro USB cable. This makes it a great tool for outdoor projects and remote applications.

.. image:: img/esp32_camera_extension.jpg
    :width: 600
    :align: center

Interface Introduction
----------------------

.. image:: img/esp32_camera_extension_pinout.jpg
    :width: 800
    :align: center

* **Power Switch**
    * Controls the battery's power supply, toggling it on and off.

* **Charging Port**
    * Upon connecting a 5V Micro USB cable, the battery can be charged.

* **Battery Port**
    * Features a PH2.0-2P interface, compatible with 3.7V 18650 lithium batterry.
    * Provides power to both the ESP32 WROOM 32E and ESP32 Camera Extension.

* **ESP32 Pin Headers**
    * Intended for the ESP32 WROOM 32E module. Pay close attention to its orientation; ensure both Micro USB ports face the same side to avoid incorrect placement.

* **GPIO Headers**
    * **Female Headers**: Used to connect various components to the ESP32, perfect for quick prototyping projects.
    * **Screw Terminal**: 3.5mm pitch 14pin screw terminal, ensuring stable wire connections and making it suitable for IoT projects.

* **Indicator Lights**
    * **PWR**: Lights up when the battery is powered or when a Micro USB is directly plugged into the ESP32.
    * **CHG**: Illuminates upon connecting a Micro USB to the board's charging port, signifying charging onset. It will turn off once the battery is fully charged.

* **Micro SD Connector**
    * Spring-loaded slot for the easy insertion and ejection of Micro SD card.

* **24-pin 0.5mm FFC / FPC connector**
    * Designed for the OV2640 camera, making it suitable for various vision-related projects.


ESP32 Camera Extension Pinout
--------------------------------

The ESP32 WROOM 32E's pinout diagram can be found in :ref:`esp32_pinout`. 

However, when the ESP32 WROOM 32E is inserted into the extension board, some of its pins may also be used to drive the Micro SD card or a camera. 

Consequently, pull-up or pull-down resistors have be added to these pins. If you're using these pins as inputs, it's crucial to account for these resistors as they can affect input levels.

Here's the pinout table for the right-side pins:

    .. image:: img/esp32_extension_pinout1.jpg
        :width: 100%
        :align: center

Here's the pinout table for the left-side pins:

    .. image:: img/esp32_extension_pinout2.jpg
        :width: 100%
        :align: center

    .. note::

        There are some specific constraints:

        * **IO33** is connected to a 4.7K pull-up resistor and a filtering capacitor, which prevents it from driving the WS2812 RGB Strip.

Interface Insertion Guide
-------------------------------

**Upload Code**

    When you need to upload code to the ESP32 WROOM 32E, connect it to your computer using a Micro USB cable.

    .. image:: ../img/plugin_esp32.png
        :width: 600
        :align: center

**Inserting the Micro SD Card**

    Gently push in the Micro SD card to secure it in place. Pushing it again will eject it.

    .. image:: ../img/insert_sd.png
        :width: 600
        :align: center

**Attaching the Camera**

    When connecting the camera, ensure the black stripe of the FPC cable is facing upwards and is fully inserted 
    into the connector.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

**Battery Power and Charging**

    Carefully insert the battery cable into the battery port, avoiding applying too much force to prevent pushing up the battery terminal. If the terminal is pushed up, it's okay as long as the pins are not broken; you can simply press it back into position.

    .. image:: ../img/plugin_battery.png
        :width: 600
        :align: center

    If the battery is drained, plug in a 5V Micro USB to charge it.

    .. image:: ../img/battery_charge.png
        :width: 600
        :align: center
