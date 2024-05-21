.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

8.8 Kamera mit Home Assistant
======================================

Dieses Projekt führt Sie durch die Einrichtung eines Video-Stream-Web-Servers für die ESP32-Kamera und dessen Integration in die beliebte Heimautomatisierungsplattform Home Assistant. Diese Integration ermöglicht Ihnen den Zugriff auf den Server von jedem Gerät in Ihrem Netzwerk aus.

.. note::
    
    Bevor Sie mit diesem Projekt beginnen, benötigen Sie ein Betriebssystem mit installiertem Home Assistant.
        
    Wir empfehlen die Installation des Home Assistant OS auf einem Raspberry Pi.
        
    Falls Sie keinen Raspberry Pi besitzen, können Sie es auch auf einer virtuellen Maschine unter Windows, macOS oder Linux installieren.
        
    Anweisungen zur Installation finden Sie auf der offiziellen Website: https://www.home-assistant.io/installation/
        
    Fahren Sie mit diesem Projekt erst nach einer erfolgreichen Installation fort.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-


**1. Konfiguration in ESPHome**

#. Stecken Sie zuerst die Kamera ein.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Verbinden Sie Ihr ESP32 mit dem Host, auf dem Sie das Home Assistant System installiert haben (z.B. wenn es auf einem Raspberry Pi installiert ist, verbinden Sie es mit dem Pi).

    .. image:: ../../img/plugin_esp32.png

#. Installieren Sie das ESPHome Addon.

    .. image:: img/sp230629_145928.png

#. Klicken Sie auf **START**, dann auf **OPEN WEB UI**.

    .. image:: img/sp230629_172645.png
        :width: 700
        :align: center

#. Fügen Sie neue Geräte hinzu.

    .. image:: img/sp230629_172733.png

#. Es könnte eine Aufforderung erscheinen. Klicken Sie auf **CONTINUE**.

    .. image:: img/sp230629_172816.png
        :align: center


#. Erstellen Sie eine Konfiguration. Hier können Sie für **Name** einen beliebigen Namen eingeben. Für das WLAN geben Sie die Details des Netzwerks ein, in dem sich Ihr Home Assistant System befindet.

    .. image:: img/sp230629_172926.png

#. Wählen Sie den **ESP32** als Gerätetyp.

    .. image:: img/sp230629_173043.png

#. Wenn Sie ein Feuerwerksfeier-Symbol sehen, bedeutet dies, dass Sie das Gerät erfolgreich erstellt haben. Klicken Sie auf überspringen (NICHT auf **INSTALL** klicken).

    .. image:: img/sp230629_173151.png

    An diesem Punkt haben Sie das Gerät nur in ESPHome hinzugefügt. Um das ESP32-Modul in Home Assistant zu integrieren, sind zusätzliche Konfigurationen notwendig:


#. Klicken Sie auf **EDIT**.

    .. image:: img/sp230629_173322.png

#. Nachdem Sie die ``.yaml``-Schnittstelle geöffnet haben, ändern Sie ``ssid`` und ``password`` mit Ihren WLAN-Daten.

    .. image:: img/sp230629_174301.png

#. Fügen Sie im Abschnitt ``captive_portal`` den folgenden Code ein:

    .. code-block::

        # Example configuration entry
        esp32_camera:
            external_clock:
                pin: GPIO0
                frequency: 20MHz
            i2c_pins:
                sda: GPIO26
                scl: GPIO27
            data_pins: [GPIO5, GPIO18, GPIO19, GPIO21, GPIO36, GPIO39, GPIO34, GPIO35]
            vsync_pin: GPIO25
            href_pin: GPIO23
            pixel_clock_pin: GPIO22
            power_down_pin: GPIO32

            # Image settings
            name: My Camera
            # ...

    .. note:: 
        
        Für weitere Details zur ``.yaml``-Konfiguration für ESP32 können Sie sich auf `ESP32 Kamera - ESPHome <https://esphome.io/components/esp32_camera.html>`_ beziehen.

#. **Save** Sie und klicken Sie dann auf **INSTALL**.

    .. image:: img/sp230629_174447.png

#. Wählen Sie die USB-Port-Methode zur Installation.

    .. image:: img/sp230629_174852.png

    .. note:: 
        
        Die erste Kompilierung wird Abhängigkeitspakete herunterladen, was etwa 10 Minuten dauern kann. Bitte haben Sie Geduld. Wenn der Prozess lange Zeit stillsteht, überprüfen Sie, ob genügend Speicherplatz auf Ihrem System vorhanden ist.

#. Warten Sie auf die Nachricht ``INFO Successfully compiled program.``, was anzeigt, dass die Firmware-Kompilierung abgeschlossen ist.

    .. image:: img/sp230630_115109.png

    .. sp230630_114902.png

    .. note:: 

        An diesem Punkt sollte der Knoten als **ONLINE** angezeigt werden. Wenn nicht, stellen Sie sicher, dass Ihr ESP32 im selben Netzwerksegment ist oder versuchen Sie, das Gerät neu zu starten.

        .. image:: img/sp230630_153024.png

**2. Konfiguration in Home Assistant**

Nach der Integration mit Esphome müssen Sie die Kamera in Home Assistant noch konfigurieren. 

#. Gehen Sie zu **Settings** > **Devices & Services**.

    .. image:: img/sp230630_155917.png

#. Jetzt sollten Sie den Reiter esphome sehen. Klicken Sie auf **CONFIGURE**.

    .. image:: img/sp230630_155736.png

#. Klicken Sie auf **SUBMIT**.

    .. image:: img/sp230630_162218.png

#. Warten Sie auf die **Success**-Nachricht.

    .. image:: img/sp230630_162311.png

#. Klicken Sie im **Overview** oben rechts auf das Menü und wählen Sie **Edit Dashboard**.

    .. image:: img/sp230630_164745.png

#. Klicken Sie auf **ADD CARD**.

    .. image:: img/sp230630_164850.png

#. Wählen Sie **Picture entity**.

    .. image:: img/sp230630_164935.png

#. Wählen Sie im Feld Entität das ESP32 aus, das Sie gerade hinzugefügt haben. Dann **save**.

    .. image:: img/sp230630_165019.png

#. Klicken Sie zuletzt auf **DONE**, um die **EDIT**-Schnittstelle zu verlassen.

    .. image:: img/sp230630_165235.png

Nun können Sie Ihren Kamera-Feed in Home Assistant ansehen.


