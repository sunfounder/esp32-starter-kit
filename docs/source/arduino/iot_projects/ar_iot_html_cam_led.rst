
.. _iot_html_cam:


8.3 Custom Video Streaming Web Server
========================================

The Custom Video Streaming Web Server project offers an opportunity to learn how to create a web page from scratch and customize it to play video streams. Additionally, you can incorporate interactive buttons, such as ON and OFF, to control the LED's brightness.

By building this project, you will gain hands-on experience in web development, HTML, CSS, and JavaScript. You will learn how to create a responsive web page that can display video streams in real-time. Moreover, you will discover how to integrate interactive buttons to control the LED's state, providing a dynamic user experience.

**Required Components**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**How to do?**

#. First plug in the camera.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Build the circuit.

    .. image:: ../../img/wiring/iot_3_html_led_bb.png

#. Then, connect ESP32-WROOM-32E to the computer using the USB cable.

    .. image:: ../../img/plugin_esp32.png

#. Open the code.

    * Open the ``iot_3_html_cam_led.ino`` file located in the ``esp32-starter-kit-main\c\codes\iot_3_html_cam_led`` directory, or copy the code into the Arduino IDE.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a5e33c30-63dc-4987-94c3-89bc6a599e24/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

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

    .. image:: ../../img/plugin_battery.png
