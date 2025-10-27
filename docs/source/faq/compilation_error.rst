Some project code fails to compile?
===============================================

Q1: ``'ledcAttach' was not declared in this scope``
-----------------------------------------------------

When using LEDs, RGB LEDs, or passive buzzers, you will need the ESP32 board's |link_ledc| peripheral to generate PWM signals. However, the ESP32 board was recently upgraded to version 3.0, which caused changes in the function names and usage within the |link_ledc| peripheral.

Therefore, we have updated our code accordingly. If you encounter ledc-related issues during compilation, please upgrade your ESP32 board to version 3.0 or higher.

.. image:: img/version_3.0.3.png


Q2: Errors in Bluetooth and IR receiver-related projects after upgrading ESP32 to version 3.0?
--------------------------------------------------------------------------------------------------------

The ESP32 board has been upgraded to version 3.0, but the libraries used in Bluetooth and IR receiver-related projects are not yet compatible with version 3.0.

To run these projects, it is recommended to temporarily downgrade the ESP32 version to 2.0, specifically version 2.0.17.

We will continuously monitor the updates of these libraries, and once they are compatible with ESP32 version 3.0, we will promptly update our code and documentation.

.. image:: img/version_2.0.17.png

.. _download_mode:

Q3: “Wrong boot mode detected (0x13)” error when flashing ESP32 firmware?
--------------------------------------------------------------------------------------

When flashing ESP32 firmware with Thonny or uploading code to ESP32 using the Arduino IDE, you may encounter the following error:

.. code-block:: text

    A fatal error occurred: Failed to connect to ESP32: Wrong boot mode detected (0x13)! The chip needs to be in download mode.

This does not indicate a hardware problem with your ESP32 board.  
This issue may occur when the computer fails to automatically put the ESP32 into **download mode** during the flashing process.

**Cause**

ESP32 must be in **download mode** to flash firmware successfully.  
In some environments, the automatic download trigger may not work as expected due to timing differences in USB drivers, USB port behavior, or how the operating system handles DTR/RTS signals.  
As a result, the ESP32 remains in normal run mode, causing the flashing to fail.

**Solution**

If you encounter this error, you can manually enter download mode before flashing:

* **Using buttons (BOOT + EN/RST):**  
  Press and hold the ``BOOT`` button, then short press ``EN`` (or ``RST``), and finally release ``BOOT``.  
  This forces the ESP32 into download mode.

* **Using a jumper wire:**  
  Connect ``GPIO0`` to ``GND`` with a jumper wire, then press ``EN`` (or power cycle the board) to enter download mode.  
  After flashing, remove the jumper wire to allow normal boot.

**Notes**

* Make sure to use a proper **data cable** (not a charge-only cable).  
* If the problem persists, try changing the USB port, updating the USB-to-serial driver, or lowering the baud rate (e.g., ``115200``).  


