.. _iot_telegram:

8.7 ESP-Kamera mit Telegram-Bot
====================================

In diesem Projekt zeigen wir, wie Sie das ESP32 mit Ihrer Lieblings-Messaging-Anwendung integrieren können. Für diese Demonstration verwenden wir Telegram.

Erstellen Sie einen Telegram-Bot, der es Ihnen ermöglicht, Ihren Schaltkreis von überall zu steuern, Fotos zu machen und den Blitz zu verwalten. Außerdem wird jedes Mal, wenn jemand an Ihrem Gerät vorbeigeht, ein neues Foto aufgenommen und eine Benachrichtigung an Ihr Telegram-Konto gesendet.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
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

**Einen Telegram-Bot erstellen**

#. Gehen Sie zu **Google Play** oder dem **App Store** und laden und installieren Sie **Telegram**.

#. Suchen Sie in der **Telegram**-App nach ``botfather``, und sobald er erscheint, klicken Sie darauf, um ihn zu öffnen. Alternativ können Sie direkt diesen Link verwenden: t.me/botfather.

    .. image:: img/sp230515_135927.png

#. Wenn Sie den Chat geöffnet haben, senden Sie den Befehl ``/start``.

    .. image:: img/sp230515_140149.png

#. Geben Sie ``/newbot`` ein und folgen Sie den angegebenen Anweisungen, um Ihren Bot zu erstellen. Nach erfolgreichem Abschluss gibt Ihnen der BotFather den Zugangslink und die API für Ihren neuen Bot.

    .. image:: img/sp230515_140830.png

**Autorisierung von Telegram-Benutzern**

Da jeder mit dem von Ihnen erstellten Bot interagieren kann, besteht ein Risiko des Informationslecks. Um dies zu verhindern, möchten wir, dass der Bot nur auf autorisierte Benutzer reagiert.

#. Suchen Sie in Ihrem **Telegram**-Konto nach ``IDBot`` oder öffnen Sie den Link: t.me/myidbot.

    .. image:: img/sp230515_144241.png

#. Senden Sie den Befehl ``/getid``. Speichern Sie die bereitgestellte ID zur späteren Verwendung in unserem Programm.

    .. image:: img/sp230515_144614.png

**Code hochladen**

#. Schließen Sie zuerst die Kamera an.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Bauen Sie den Schaltkreis auf.

    .. image:: ../../img/wiring/iot_7_cam_telegram_bb.png
        
#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``iot_7_cam_telegram.ino``, die sich im Verzeichnis ``esp32-starter-kit-main\c\codes\iot_7_cam_telegram`` befindet, oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Button.
    * :ref:`unknown_com_port`
    * Die Bibliotheken ``UniversalTelegramBot`` und ``ArduinoJson`` werden hier verwendet. Sie können sie aus dem **Library Manager** installieren.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/d7c439b0-fca3-4648-9714-900a2859740c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Suchen und ändern Sie die folgenden Zeilen mit Ihren WLAN-Daten und ersetzen Sie ``<SSID>`` und ``<PASSWORD>``:

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

5. Aktualisieren Sie die nächste Zeile, indem Sie ``<CHATID>`` durch Ihre Telegram-ID ersetzen, die Sie von @IDBot erhalten haben.

    .. code-block:: Arduino

        // Use @myidbot to find out the chat ID of an individual or a group
        // Also note that you need to click "start" on a bot before it can
        // message you
        String chatId = "<CHATID>";

#. Aktualisieren Sie die nächste Zeile, indem Sie ``<BOTTOKEN>`` durch den Token Ihres Telegram-Bots ersetzen, den Ihnen @BotFather bereitgestellt hat.

    .. code-block:: Arduino

        // Initialize Telegram BOT
        String BOTtoken = "<BOTTOKEN>";

#. Nachdem Sie das richtige Board (ESP32 Dev Module) und den Port ausgewählt haben, klicken Sie auf den **Upload**-Button.
#. Öffnen Sie den Serial Monitor. Wenn eine IP-Adresse gedruckt wird, deutet dies auf eine erfolgreiche Ausführung hin.

    .. code-block::

        Connecting to xxxx
        ESP32-CAM IP Address: 192.168.18.76
        Init Done!

#. Jetzt können Sie über Telegram mit Ihrem ESP32 interagieren.

    .. image:: img/sp230515_161237.png

