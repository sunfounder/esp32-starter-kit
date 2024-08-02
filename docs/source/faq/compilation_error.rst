Some examples don't compile
===============================================

**Q:** Projects using PWM cannot be compiled, prompting the error ``'ledcAttach' was not declared in this scope``.

**A:** This is caused by the version of your development board being too low. Please update it to the latest version.

.. image:: img/version_3.0.3.png




**Q:** Projects using the IR module cannot be compiled, and many errors related to ``IRrecv.cpp`` are reported.

**A:** If you are using an ESP32 development board version 3.0.0 or higher, you may encounter errors during the compilation process.
This issue is usually because the newer versions of the board no longer support the ``<IRremoteESP8266.h>`` library.
To properly run this example, it is recommended to downgrade your ESP32 board's firmware version to 2.0.17. After completing this example, upgrade back to the latest version.

.. image:: img/version_2.0.17.png
