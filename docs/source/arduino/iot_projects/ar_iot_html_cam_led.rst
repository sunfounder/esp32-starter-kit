.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _iot_html_cam:

8.3 Benutzerdefinierter Video-Streaming-Webserver
====================================================

Das Projekt "Benutzerdefinierter Video-Streaming-Webserver" bietet die Möglichkeit, zu lernen, wie man eine Webseite von Grund auf erstellt und sie so anpasst, dass Videostreams abgespielt werden können. Zusätzlich können Sie interaktive Schaltflächen, wie EIN und AUS, integrieren, um die Helligkeit der LED zu steuern.

Durch den Aufbau dieses Projekts sammeln Sie praktische Erfahrungen in der Webentwicklung, HTML, CSS und JavaScript. Sie lernen, wie man eine responsive Webseite erstellt, die Videostreams in Echtzeit anzeigen kann. Außerdem entdecken Sie, wie man interaktive Schaltflächen integriert, um den Zustand der LED zu steuern und so ein dynamisches Benutzererlebnis zu bieten.

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**Wie macht man das?**

#. Schließen Sie zuerst die Kamera an.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Bauen Sie den Schaltkreis.

    .. image:: ../../img/wiring/iot_3_html_led_bb.png

#. Verbinden Sie dann ESP32-WROOM-32E mit dem Computer über das USB-Kabel.

    .. image:: ../../img/plugin_esp32.png

#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``iot_3_html_cam_led.ino``, die sich im Verzeichnis ``esp32-starter-kit-main\c\codes\iot_3_html_cam_led`` befindet, oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a5e33c30-63dc-4987-94c3-89bc6a599e24/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Suchen Sie die folgenden Zeilen und ändern Sie sie mit Ihrem ``SSID`` und ``PASSWORD``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Nachdem Sie das richtige Board (ESP32 Dev Module) und den Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.

#. Im seriellen Monitor sehen Sie eine erfolgreiche WLAN-Verbindungsmeldung und die zugewiesene IP-Adresse.

    .. code-block:: 

        WiFi connected
        Camera Stream Ready! Go to: http://192.168.18.77

#. Geben Sie die IP-Adresse in Ihrem Webbrowser ein. Sie werden zu der unten gezeigten Webseite geleitet, auf der Sie die benutzerdefinierten EIN- und AUS-Tasten verwenden können, um die LED zu steuern.

    .. image:: img/sp230510_180503.png 

#. Legen Sie einen Akku in das Erweiterungsboard ein und entfernen Sie das USB-Kabel. Jetzt können Sie das Gerät überall innerhalb der WLAN-Reichweite platzieren.

    .. image:: ../../img/plugin_battery.png

