.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _iot_cheerlights:

8.5 CheerLights
===============================
CheerLights ist ein globales Netzwerk synchronisierter Lichter, das von jedem gesteuert werden kann.

Treten Sie der |link_cheerlights| LED-Farbwechsel-Community bei, die es ermöglicht, dass LEDs auf der ganzen Welt gleichzeitig ihre Farben ändern.

Sie können Ihre LEDs in einer Ecke Ihres Büros platzieren, um sich daran zu erinnern, dass Sie nicht allein sind.

In diesem Fall nutzen wir auch MQTT, aber anstatt unsere eigenen Nachrichten zu veröffentlichen, abonnieren wir das Thema "cheerlights". Dies ermöglicht es uns, Nachrichten, die von anderen an das Thema "cheerlights" gesendet wurden, zu empfangen und diese Informationen zu nutzen, um die Farbe unseres LED-Streifens entsprechend zu ändern.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM SET
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|


**Wie macht man das?**

#. Bauen Sie den Schaltkreis.

    .. image:: ../../img/wiring/iot_5_cheerlight_bb.png

#. Verbinden Sie dann ESP32-WROOM-32E mit dem Computer über das USB-Kabel.

    .. image:: ../../img/plugin_esp32.png

#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``iot_5_cheerlights.ino``, die sich im Verzeichnis ``esp32-starter-kit-main\c\codes\iot_5_cheerlights`` befindet, oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    * Hier werden die Bibliotheken ``PubSubClient`` und ``Adafruit_NeoPixel`` verwendet, die Sie über den **Library Manager** installieren können.

        .. image:: img/mqtt_lib.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4fc7b0ff-db8e-4bf3-ad34-d68c1857794b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Suchen Sie die folgenden Zeilen und ändern Sie sie mit Ihrem ``SSID`` und ``PASSWORD``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Finden Sie die nächste Zeile und ändern Sie Ihren ``unique_identifier``. Stellen Sie sicher, dass Ihr ``unique_identifier`` wirklich einzigartig ist, da identische IDs, die versuchen, sich bei demselben **MQTT Broker** anzumelden, zu einem Anmeldefehler führen können.

    .. code-block::  Arduino

        // Add your MQTT Broker address:
        const char* mqtt_server = "mqtt.cheerlights.com";
        const char* unique_identifier = "sunfounder-client-sdgvsasdda";    

#. Nachdem Sie das richtige Board (ESP32 Dev Module) und den Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.

#. An diesem Punkt können Sie sehen, dass Ihr RGB-Streifen eine bestimmte Farbe anzeigt. Platzieren Sie ihn auf Ihrem Schreibtisch und Sie werden bemerken, dass er periodisch die Farben wechselt. Das liegt daran, dass andere @CheerLights-Follower die Farbe Ihrer Lichter ändern!

#. Öffnen Sie den Seriellen Monitor. Sie werden Nachrichten ähnlich den folgenden sehen:

.. code-block:: 
  
    WiFi connected
    IP address: 
    192.168.18.77
    Attempting MQTT connection...connected
    Message arrived on topic: cheerlights. 
    Message: oldlace
    Changing color to oldlace

**Globale @CheerLights-Geräte steuern**

#. Treten Sie dem |link_discord_server| bei und nutzen Sie den CheerLights-Bot, um die Farbe festzulegen. Tippen Sie einfach ``/cheerlights`` in einem der Kanäle auf dem **CheerLights Discord Server**, um den Bot zu aktivieren.

    .. image:: img/sp230511_163558.png

#. Befolgen Sie die Anweisungen des Bots, um die Farbe festzulegen. Dadurch können Sie CheerLights-Geräte weltweit steuern.

    .. image:: img/sp230511_163849.png
