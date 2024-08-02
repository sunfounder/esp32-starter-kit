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

