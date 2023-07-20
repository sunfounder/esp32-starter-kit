.. _cpn_esp32_extension:

ESP32 WROOM 32E and Extension Board
=============================================

ESP32 WROOM 32E
------------------------

https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf
看这个名称都有M和U的修饰，那么我就查到了。

JTAG接口主要由4根信号线组成：TCK、TDI、TDO、TMS。

TCK是JTAG模块外部输入时钟；

TDI是JTAG模块外部数据输入信号；

TDO是JTAG模块外部输出信号；

TMS是JTAG模块的模式选择信号；

应该就是解惑了，ESP32可以使用JTAG来调试，这12-14就是JTAG的引脚。

官方有个调试器：

ESP-Prog 是一款乐鑫推出的开发调试工具，具有自动下载固件、串口通信、JTAG 在线调试等功能。自动下载固件和串口通信功能适用于 ESP8266 和 ESP32 平台。JTAG 在线调试功能适用于 ESP32 平台。
 
ESP-Prog 使用简单方便，仅用一根 USB 线即可实现与电脑的连接，电脑端可识别出下载功能和 JTAG 功能对应的两个端口。


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
