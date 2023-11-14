8.2 Kamera-Webserver
=============================

Dieses Projekt kombiniert das ESP32-Board mit einem Kameramodul, um hochwertiges Video über ein lokales Netzwerk zu streamen. 
Richten Sie mühelos Ihr eigenes Kamerasystem ein und überwachen Sie jeden Ort in Echtzeit.

Mit der Web-Oberfläche des Projekts können Sie auf den Kamerastream zugreifen und ihn von jedem mit dem Netzwerk verbundenen Gerät aus steuern. 
Passen Sie die Kameraeinstellungen an, um das Streaming-Erlebnis zu optimieren, und stellen Sie die Einstellungen einfach über die benutzerfreundliche Oberfläche ein.

Erweitern Sie Ihre Überwachungs- oder Live-Streaming-Fähigkeiten mit dem vielseitigen ESP32 Camera Streaming-Projekt. Überwachen Sie Ihr Zuhause, Ihr Büro oder jeden gewünschten Ort mit Leichtigkeit und Zuverlässigkeit.

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

**Wie macht man das?**

#. Schließen Sie zuerst die Kamera an.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Verbinden Sie dann ESP32-WROOM-32E mit dem Computer über das USB-Kabel.

    .. image:: ../../img/plugin_esp32.png

#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``iot_2_camera_server.ino``, die sich im Verzeichnis ``esp32-starter-kit-main\c\codes\iot_2_camera_server`` befindet, oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/15e00b39-34e1-49f9-b039-f10053d31407/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Suchen Sie die folgenden Zeilen und ändern Sie sie mit Ihrem ``<SSID>`` und ``<PASSWORD>``.

    .. code-block::  Arduino

        // Ersetzen Sie die nächsten Variablen mit Ihrer SSID/Passwort-Kombination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. Aktivieren Sie jetzt **PSRAM**.

    .. image:: img/sp230516_150554.png

#. Stellen Sie das Partitionsschema auf **Huge APP (3MB No OTA/1MB SPIFFS)** ein.

    .. image:: img/sp230516_150840.png

#. Nachdem Sie das richtige Board (ESP32 Dev Module) und den Port ausgewählt haben, klicken Sie auf den "Hochladen"-Knopf.

#. Im seriellen Monitor sehen Sie eine erfolgreiche WLAN-Verbindungsmeldung und die zugewiesene IP-Adresse.

    .. code-block::

        .....
        WiFi connected
        Starting web server on port: '80'
        Starting stream server on port: '81'
        Camera Ready! Use 'http://192.168.18.77' to connect

#. Geben Sie die IP-Adresse in Ihrem Webbrowser ein. Sie sehen eine Web-Oberfläche, auf der Sie **Start Stream** klicken können, um den Kamerastream anzusehen.

    .. image:: img/sp230516_151521.png

#. Scrollen Sie zurück nach oben auf der Seite, wo Sie den Live-Kamerastream sehen. Sie können die Einstellungen auf der linken Seite der Oberfläche anpassen.

    .. image:: img/sp230516_180520.png

.. note:: 

    * Dieses ESP32-Modul unterstützt Gesichtserkennung. Um es zu aktivieren, stellen Sie die Auflösung auf 240x240 ein und schalten Sie die Option für die Gesichtserkennung am unteren Rand der Oberfläche um.
    * Dieses ESP32-Modul unterstützt keine Gesichtserkennung.
