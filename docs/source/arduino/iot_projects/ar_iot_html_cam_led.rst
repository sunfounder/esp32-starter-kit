3. Custom Video Streaming Web Server
========================================

The Custom Video Streaming Web Server project offers an opportunity to learn how to create a web page from scratch and customize it to play video streams. Additionally, you can incorporate interactive buttons, such as ON and OFF, to control the LED's brightness.

By building this project, you will gain hands-on experience in web development, HTML, CSS, and JavaScript. You will learn how to create a responsive web page that can display video streams in real-time. Moreover, you will discover how to integrate interactive buttons to control the LED's state, providing a dynamic user experience.

**How to do?**

#. First plug in the camera.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Build the circuit.

    .. image:: img/3_custom_server.png
    
    * :ref:`cpn_esp32_extension`
    * :ref:`cpn_breadboard`
    * :ref:`cpn_wires`
    * :ref:`cpn_resistor`
    * :ref:`cpn_led`

#. Then, connect ESP32-WROOM-32E to the computer using the USB cable.

    .. image:: img/plugin_esp32.png

#. Open the code.

    * Open the ``iot_3_html_cam_led.ino`` file located in the ``esp32-ultimate-kit-main\c\codes\iot_3_html_cam_led`` directory, or copy the code into the Arduino IDE.
    * Or copy this code into **Arduino IDE**.
 
    .. raw:: html

#. Locate the following lines and modify them with your ``<SSID>`` and ``<PASSWORD>``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. After selecting the correct board (ESP32 Dev Module) and port, click the **Upload** button.

#. You will see a successful WiFi connection message and the assigned IP address in the Serial Monitor.

    .. code-block:: 

        WiFi connected
        Camera Stream Ready! Go to: http://192.168.18.77

#. Enter the IP address in your web browser. You will be directed to the web page shown below, where you can use the customized ON and OFF buttons to control the LED.

    .. image:: img/sp230510_180503.png 

#. Insert a battery into the expansion board and remove the USB cable. Now you can place the device anywhere you desire within the Wi-Fi range.

    .. image:: img/plugin_battery.png
