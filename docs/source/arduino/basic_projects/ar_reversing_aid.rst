.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_reversing_aid:

6.3 Einparkhilfe
===================

Stellen Sie sich Folgendes vor: Sie sitzen in Ihrem Auto und möchten rückwärts in eine enge Parklücke fahren. Mit unserem Projekt haben Sie ein Ultraschallmodul am Heck Ihres Fahrzeugs montiert, das als digitales Auge fungiert. Wenn Sie den Rückwärtsgang einlegen, wird das Modul aktiviert und sendet Ultraschallimpulse aus, die von Hindernissen hinter Ihnen reflektiert werden.

Das Besondere geschieht, wenn diese Impulse zum Modul zurückkehren. Es berechnet blitzschnell die Entfernung zwischen Ihrem Auto und den Objekten und verwandelt diese Daten in eine Echtzeit-Visuelle-Rückmeldung, die auf einem lebendigen LCD-Bildschirm angezeigt wird. Sie erleben dynamische, farbkodierte Indikatoren, die die Nähe zu Hindernissen anzeigen und Ihnen so ein kristallklares Verständnis der Umgebung ermöglichen.

Aber wir haben noch mehr getan. Um Sie noch tiefer in dieses Fahrerlebnis einzutauchen, haben wir einen lebhaften Summer integriert. Nähert sich Ihr Auto einem Hindernis, intensiviert sich das Tempo des Summers und erzeugt eine akustische Symphonie der Warnungen. Es ist, als hätten Sie ein persönliches Orchester, das Sie durch die Komplexität des Rückwärtsparkens leitet.

Dieses innovative Projekt verbindet Spitzentechnologie mit einer interaktiven Benutzeroberfläche und macht Ihr Rückwärtserlebnis sicher und stressfrei. Mit dem Ultraschallmodul, dem LCD-Display und dem lebhaften Summer, die harmonisch zusammenarbeiten, fühlen Sie sich beim Manövrieren in engen Räumen ermächtigt und selbstbewusst, sodass Sie sich auf die Freude am Fahren konzentrieren können.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen. Hier ist der Link:

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.4_reversing_aid.png
    :width: 800
    :align: center


Der Ultraschallsensor im Projekt sendet hochfrequente Schallwellen aus und misst die Zeit, die die Wellen benötigen, um nach dem Aufprall auf ein Objekt zurückzukehren. Durch die Analyse dieser Daten kann die Entfernung zwischen dem Sensor und dem Objekt berechnet werden. Um eine Warnung zu geben, wenn das Objekt zu nah ist, wird ein Summer verwendet, um ein hörbares Signal zu erzeugen. Zusätzlich wird die gemessene Entfernung auf einem LCD-Bildschirm zur einfachen Visualisierung angezeigt.

**Verdrahtung**

.. image:: ../../img/wiring/6.4_aid_ultrasonic_bb.png


**Code**

.. note::

    * Sie können die Datei ``6.3_reversing_aid.ino`` direkt unter dem Pfad ``esp32-starter-kit-main\c\codes\6.3_reversing_aid`` öffnen.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    * Hier wird die Bibliothek ``LiquidCrystal I2C`` verwendet, die Sie aus dem **Library Manager** installieren können.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c06deba0-36fd-4f17-8290-c7a39202e089/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Nachdem der Code erfolgreich hochgeladen wurde, wird die aktuell erkannte Entfernung auf dem LCD angezeigt. Dann ändert der Summer die Klangfrequenz je nach Entfernung.

.. note:: 

    Wenn der Code und die Verdrahtung korrekt sind, das LCD jedoch weiterhin keinen Inhalt anzeigt, können Sie den Potentiometer auf der Rückseite verstellen, um den Kontrast zu erhöhen.


**Wie funktioniert das?**

Dieser Code hilft uns, ein einfaches Entfernungsmessgerät zu erstellen, das die Entfernung zwischen Objekten messen und Feedback über ein LCD-Display und einen Summer geben kann.

Die Funktion ``loop()`` enthält die Hauptlogik des Programms und läuft kontinuierlich. Lassen Sie uns die Funktion ``loop()`` genauer betrachten.

#. Schleife zum Lesen der Entfernung und Aktualisieren der Parameter

    In der ``loop`` liest der Code zunächst die vom Ultraschallmodul gemessene Entfernung und aktualisiert den Intervallparameter basierend auf der Entfernung.

    .. code-block:: arduino

        // Update the distance
        distance = readDistance();

        // Update intervals based on distance
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. Überprüfen, ob es Zeit zum Piepen ist

    Der Code berechnet die Differenz zwischen der aktuellen Zeit und der vorherigen Piepzeit, und wenn die Differenz größer oder gleich der Intervallzeit ist, löst er den Summer aus und aktualisiert die vorherige Piepzeit.

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. LCD-Display aktualisieren

    Der Code löscht das LCD-Display und zeigt dann "Dis:" und die aktuelle Entfernung in Zentimetern in der ersten Zeile an.

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);

