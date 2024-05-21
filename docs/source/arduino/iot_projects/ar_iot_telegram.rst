.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _iot_telegram:

8.7 ESP Camera with Telegram Bot
====================================

In this project, we'll demonstrate how to integrate the ESP32 with your favorite messaging application. For this demonstration, we're using Telegram.

Create a Telegram Bot, allowing you to control your circuit from anywhere, capture photos, and manage the flash. Moreover, whenever someone passes by your device, it will snap a new photo and send a notification to your Telegram account.

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Creating a Telegram Bot**

#. Head to **Google Play** or the **App Store** and download and install **Telegram**.

#. Search for ``botfather`` in the **Telegram** app, and once it appears, click on it to open. or you can directly access this link: t.me/botfather.

    .. image:: img/sp230515_135927.png

#. Upon opening, you'll be presented with a chat window. Send the command ``/start``.

    .. image:: img/sp230515_140149.png

#. Enter ``/newbot`` and follow the provided instructions to create your bot. Once successful, the BotFather will provide you with the access link and API for your new bot.

    .. image:: img/sp230515_140830.png

**Authorizing Telegram Users**

As anyone can interact with the bot you've created, there's a risk of information leakage. To address this, we want the bot to only respond to authorized users.

#. In your **Telegram** account, search for ``IDBot`` or open the link: t.me/myidbot.

    .. image:: img/sp230515_144241.png

#. Send the command ``/getid``. Save the provided ID for later use in our program.

    .. image:: img/sp230515_144614.png

**Upload the Code**

#. First plug in the camera.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Build the circuit.

    .. image:: ../../img/wiring/iot_7_cam_telegram_bb.png
        
#. Open the code.

    * Open the ``iot_7_cam_telegram.ino`` file located in the ``esp32-starter-kit-main\c\codes\iot_7_cam_telegram`` directory, or copy the code into the Arduino IDE.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``UniversalTelegramBot`` and ``ArduinoJson`` libraries are used here, you can install them from the **Library Manager**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/d7c439b0-fca3-4648-9714-900a2859740c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Locate and modify the following lines with your WiFi details, replacing ``<SSID>`` and ``<PASSWORD>``:

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

5. Update the next line, replacing ``<CHATID>`` with your Telegram ID, which you obtained from @IDBot.

    .. code-block:: Arduino

        // Use @myidbot to find out the chat ID of an individual or a group
        // Also note that you need to click "start" on a bot before it can
        // message you
        String chatId = "<CHATID>";

#. Update the next line, substituting ``<BOTTOKEN>`` with the token of your Telegram BOT, which was provided by @BotFather.

    .. code-block:: Arduino

        // Initialize Telegram BOT
        String BOTtoken = "<BOTTOKEN>";

#. After selecting the correct board (ESP32 Dev Module) and port, click the **Upload** button.
#. Open the Serial Monitor. If an IP address is printed, this indicates successful execution. 

    .. code-block::

        Connecting to xxxx
        ESP32-CAM IP Address: 192.168.18.76
        Init Done!

#. Now, you can interact with your ESP32 via Telegram.

    .. image:: img/sp230515_161237.png
