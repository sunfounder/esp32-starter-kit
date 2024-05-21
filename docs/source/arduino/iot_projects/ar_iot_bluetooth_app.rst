.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _iot_bluetooth_app:

8.10 Android-Anwendung - RGB-LED-Steuerung über Arduino und Bluetooth
=======================================================================

Ziel dieses Projekts ist die Entwicklung einer Android-Anwendung, die in der Lage ist, den Farbton einer RGB-LED über ein Smartphone mittels Bluetooth-Technologie zu manipulieren.

Diese Android-Anwendung wird mit Hilfe einer kostenlosen webbasierten Plattform namens MIT App Inventor 2 erstellt. Das Projekt bietet eine hervorragende Gelegenheit, Erfahrungen im Umgang mit der Schnittstelle zwischen einem Arduino und einem Smartphone zu sammeln.

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../../_static/video/10_ble_app.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**1. Erstellung der Android-Anwendung**

Die Android-Anwendung wird mit Hilfe einer kostenlosen Webanwendung namens |link_appinventor| erstellt.
MIT App Inventor ist ein hervorragender Einstiegspunkt für die Android-Entwicklung aufgrund seiner intuitiven Drag-and-Drop-Funktionen, die die Erstellung einfacher Anwendungen ermöglichen.

Beginnen wir.

#. Hier ist die Login-Seite: http://ai2.appinventor.mit.edu. Sie benötigen ein Google-Konto, um sich bei MIT App Inventor anzumelden.

#. Nach dem Einloggen navigieren Sie zu **Projects** -> **Import project (.aia) from my computer**. Laden Sie anschließend die Datei ``control_rgb_led.aia`` hoch, die sich im Pfad ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor`` befindet.

   .. image:: img/10_ble_app_inventor1.png

#. Nach dem Hochladen der ``.aia``-Datei sehen Sie die Anwendung in der Software **MIT App Inventor**. Dies ist eine vorkonfigurierte Vorlage. Sie können diese Vorlage nach dem Kennenlernen von **MIT App Inventor** über die folgenden Schritte anpassen.

   .. image:: img/10_ble_app_inventor2.png

#. In **MIT App Inventor** haben Sie 2 Hauptbereiche: den **Designer** und die **Blocks**.

   .. image:: img/10_ble_app_inventor3.png

#. Der **Designer** ermöglicht es Ihnen, Schaltflächen, Texte, Bildschirme hinzuzufügen und das gesamte ästhetische Erscheinungsbild Ihrer Anwendung zu modifizieren.

   .. image:: img/10_ble_app_inventor2.png
   

#. Anschließend haben Sie den Bereich **Blocks**. Der Bereich **Blocks** erleichtert die Erstellung maßgeschneiderter Funktionen für Ihre Anwendung.

   .. image:: img/10_ble_app_inventor5.png

#. Um die Anwendung auf einem Smartphone zu installieren, navigieren Sie zum Tab **Build**.

   .. image:: img/10_ble_app_inventor6.png

   * Sie können eine ``.apk``-Datei generieren. Nachdem Sie diese Option ausgewählt haben, erscheint eine Seite, auf der Sie zwischen dem Herunterladen einer ``.apk``-Datei oder dem Scannen eines QR-Codes zur Installation wählen können. Befolgen Sie die Installationsanleitung, um die Installation der Anwendung abzuschließen.
   * Wenn Sie diese App im **Google Play** oder einem anderen App-Marktplatz hochladen möchten, können Sie eine ``.apk``-Datei generieren.



**2. Hochladen des Codes**

#. Bauen Sie die Schaltung auf.

   .. image:: ../../components/img/rgb_pin.jpg
      :width: 200
      :align: center

   Die RGB-LED besteht aus 4 Pins: Der längste Pin ist der gemeinsame Kathodenpin, üblicherweise mit GND verbunden; der Pin links vom längsten Pin steht für Rot; und die beiden Pins rechts symbolisieren Grün und Blau.

   .. image:: ../../img/wiring/2.3_color_light_bb.png

#. Verbinden Sie anschließend das ESP32-WROOM-32E mit Ihrem Computer über ein USB-Kabel.

   .. image:: ../../img/plugin_esp32.png

#. Öffnen Sie die Datei ``iot_10_bluetooth_app_inventor.ino``, die sich im Verzeichnis ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor`` befindet, oder kopieren Sie den Code in die Arduino IDE.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/07622bb5-31eb-4a89-b6f2-085f3332051f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nachdem Sie das passende Board (**ESP32 Dev Module**) und den Port ausgewählt haben, klicken Sie auf den **Upload**-Button.

**3. App- und ESP32-Verbindung**

Stellen Sie sicher, dass die zuvor erstellte Anwendung auf Ihrem Smartphone installiert ist.

#. Aktivieren Sie zunächst **Bluetooth** auf Ihrem Smartphone.

   .. image:: img/10_ble_mobile1.png
      :width: 500
      :align: center

#. Navigieren Sie zu den **Bluetooth settings** auf Ihrem Smartphone und finden Sie **ESP32RGB**.

   .. image:: img/10_ble_mobile2.png
      :width: 500
      :align: center


#. Nachdem Sie darauf geklickt haben, stimmen Sie der **Pair**-Anfrage im Pop-up-Fenster zu.

   .. image:: img/10_ble_mobile3.png
      :width: 500
      :align: center

#. Öffnen Sie jetzt die kürzlich installierte **Control_RGB_LED**-APP.

   .. image:: img/10_ble_mobile4.png
      :align: center

#. Klicken Sie in der APP auf **Connect Bluetooth**, um eine Verbindung zwischen der APP und dem ESP32 herzustellen.

   .. image:: img/10_ble_mobile5.png
      :width: 500
      :align: center

#. Wählen Sie das ``xx.xx.xx.xx.xx.xx ESP32RGB``, das angezeigt wird. Wenn Sie ``SerialBT.begin("ESP32RGB");`` im Code geändert haben, wählen Sie einfach den Namen Ihrer Einstellung.

   .. image:: img/10_ble_mobile6.png
      :width: 500
      :align: center

#. Wenn Sie eine Weile gewartet haben und immer noch keine Gerätenamen sehen, kann es sein, dass diese APP nicht erlaubt ist, umliegende Geräte zu scannen. In diesem Fall müssen Sie die Einstellungen manuell anpassen.

   * Halten Sie das APP-Symbol lange gedrückt und klicken Sie auf die sich daraus ergebende **APP Info**. Wenn Sie einen anderen Weg haben, um auf diese Seite zuzugreifen, folgen Sie diesem.

      .. image:: img/10_ble_mobile8.png
         :width: 500
         :align: center

   * Navigieren Sie zur Seite **Permissions**.

      .. image:: img/10_ble_mobile9.png
         :width: 500
         :align: center

   * Suchen Sie nach **Nearby devices** und wählen Sie **Always**, um dieser APP das Scannen von Geräten in der Nähe zu erlauben.

      .. image:: img/10_ble_mobile10.png
         :width: 500
         :align: center

   * Starten Sie nun die APP neu und wiederholen Sie die Schritte 5 und 6, um erfolgreich eine Bluetooth-Verbindung herzustellen.

#. Nach erfolgreicher Verbindung werden Sie automatisch zur Hauptseite zurückgeführt, wo es als verbunden angezeigt wird. Jetzt können Sie die RGB-Werte anpassen und die Farbe der RGB-Anzeige ändern, indem Sie auf den Button **Change Color** drücken.

   .. image:: img/10_ble_mobile7.png
      :width: 500
      :align: center

