7.1 Bluetooth
===================

This document provides a guide to develop a simple Bluetooth Low Energy (BLE) serial communication application 
using the ESP32 microcontroller. The ESP32 is a powerful microcontroller that integrates Wi-Fi and Bluetooth 
connectivity, making it an ideal candidate for developing wireless applications. BLE is 
a low-power wireless communication protocol that is designed for short-range communication. 
This document will cover the steps to set up the ESP32 to act as a BLE server and communicate with a BLE client over a serial connection.


**About the Bluetooth Function**

The ESP32 WROOM 32E is a module that integrates Wi-Fi and Bluetooth connectivity into a single chip. 
It supports Bluetooth Low Energy (BLE) and Classic Bluetooth protocols.

The module can be used as a Bluetooth client or server. As a Bluetooth client, the module can connect to 
other Bluetooth devices and exchange data with them. As a Bluetooth server, the module can provide 
services to other Bluetooth devices.

The ESP32 WROOM 32E supports various Bluetooth profiles, including the Generic Access Profile (GAP), Generic Attribute Profile (GATT), 
and Serial Port Profile (SPP). The SPP profile allows the module to emulate a serial port over Bluetooth, 
enabling serial communication with other Bluetooth devices.

To use the Bluetooth function of the ESP32 WROOM 32E, you need to program it using an appropriate software 
development kit (SDK) or using the Arduino IDE with the ESP32 BLE library. 
The ESP32 BLE library provides a high-level interface for working with BLE. It includes examples that demonstrate 
how to use the module as a BLE client and server.

Overall, the Bluetooth function of the ESP32 WROOM 32E provides a convenient and low-power way to enable wireless 
communication in your projects.

**Operation Steps**

Here are the step-by-step instructions to set up Bluetooth communication between your ESP32 and mobile device using the LightBlue app:

#. Download the LightBlue app from the App Store (for iOS) or Google Play (for Android).

    .. image:: img/bluetooth_lightblue.png

#. Open the ``7.1_bluetooth.ino`` file located in the ``esp32-ultimate-kit\c\codes\7.1_bluetooth`` directory, or copy the code into the Arduino IDE.

    .. raw:: html
        
#. To avoid UUID conflicts, it is recommended to randomly generate three new UUIDs using the |link_uuid| provided by the Bluetooth SIG, and fill them in the following lines of code.

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png


#. Select the correct board and port, then click the **Upload** button.

    .. image:: img/bluetooth_upload.png

#. After the code has been successfully uploaded, turn on **Bluetooth** on your mobile device and open the **LightBlue** app.

    .. image:: img/bluetooth_open.png

#. On the **Scan** page, find **ESP32-Bluetooth** and click **CONNECT**. If you don't see it, try refreshing the page a few times. When **"Connected to device!"** appears, the Bluetooth connection is successful. Scroll down to see the three UUIDs set in the code.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Click the **Receive** UUID. Select the appropriate data format in the box to the right of **Data Format**, such as "HEX" for hexadecimal, "UTF-8 String" for character, or "Binary" for binary, etc. Then click **SUBSCRIBE**.

    .. image:: img/bluetooth_read.png
        :width: 300

#. Go back to the Arduino IDE, open the Serial Monitor, set the baud rate to 115200, then type "welcome" and press Enter.

    .. image:: img/bluetooth_serial.png

#. You should now see the "welcome" message in the LightBlue app.

    .. image:: img/bluetooth_welcome.png
        :width: 400

#. To send information from the mobile device to the Serial Monitor, click the TX UUID, set the data format to "UTF-8 String", and write a message.

    .. image:: img/bluetooth_send.png


#. You should see the message in the Serial Monitor.

    .. image:: img/bluetooth_receive.png
