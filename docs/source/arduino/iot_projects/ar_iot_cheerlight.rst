.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _iot_cheerlights:


8.5 CheerLights
===============================
CheerLights is a global network of synchronized lights that can be controlled by anyone.

Join the |link_cheerlights| LED color-changing community, which allows LEDs around the world to change colors simultaneously.

You can place your LEDs in a corner of your office to remind yourself that you are not alone.

In this case, we also utilize MQTT, but instead of publishing our own messages, we subscribe to the "cheerlights" topic. This allows us to receive messages sent by others to the "cheerlights" topic and use that information to change the color of our LED strip accordingly.

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|


**How to do?**

#. Build the circuit.

    .. image:: ../../img/wiring/iot_5_cheerlight_bb.png

#. Then, connect ESP32-WROOM-32E to the computer using the USB cable.

    .. image:: ../../img/plugin_esp32.png

#. Open the code.

    * Open the ``iot_5_cheerlights.ino`` file located in the ``esp32-starter-kit-main\c\codes\iot_5_cheerlights`` directory, or copy the code into the Arduino IDE.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``PubSubClient`` and ``Adafruit_NeoPixel`` libraries are used here, you can install them from the **Library Manager**.

        .. image:: img/mqtt_lib.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4fc7b0ff-db8e-4bf3-ad34-d68c1857794b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Locate the following lines and modify them with your ``SSID`` and ``PASSWORD``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Find the next line and modify your ``unique_identifier``. Guarantee that your ``unique_identifier`` is truly unique as any IDs that are identical trying to log in to the same **MQTT Broker** may result in a login failure.

    .. code-block::  Arduino

        // Add your MQTT Broker address:
        const char* mqtt_server = "mqtt.cheerlights.com";
        const char* unique_identifier = "sunfounder-client-sdgvsasdda";    

#. After selecting the correct board (ESP32 Dev Module) and port, click the **Upload** button.

#. At this point, you can see that your RGB strip is displaying a certain color. Place it on your desk and you will notice that it periodically changes colors. This is because other @CheerLights followers are changing the color of your lights!

#. Open the Serial Monitor. You will see messages similar to the following:

.. code-block:: 
  
    WiFi connected
    IP address: 
    192.168.18.77
    Attempting MQTT connection...connected
    Message arrived on topic: cheerlights. 
    Message: oldlace
    Changing color to oldlace

**Control global @CheerLights devices**

#. Join the |link_discord_server| and utilize the CheerLights bot to set the color. Simply type ``/cheerlights`` in any of the channels on the **CheerLights Discord Server** to activate the bot.

    .. image:: img/sp230511_163558.png

#. Follow the instructions provided by the bot to set the color. This will allow you to control CheerLights devices globally.

    .. image:: img/sp230511_163849.png