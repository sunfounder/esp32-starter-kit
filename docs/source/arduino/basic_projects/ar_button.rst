.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_button:

5.1 Lesen des Tasterwerts
==============================================
In diesem interaktiven Projekt werden wir uns in die Welt der Tastersteuerung und LED-Manipulation begeben.

Das Konzept ist einfach, aber effektiv. Wir werden den Zustand eines Tasters lesen. Wenn der Taster gedrückt wird, registriert er ein hohes Spannungsniveau oder einen 'hohen Zustand'. Diese Aktion löst dann das Aufleuchten einer LED aus.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Verfügbare Pins**

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 20

        *   - Für Eingang
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Für Ausgang
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Bedingte Verwendung Pins (Eingang)**

    Die folgenden Pins haben eingebaute Pull-up- oder Pull-down-Widerstände, sodass externe Widerstände nicht erforderlich sind, wenn **sie als Eingangspins verwendet werden**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Bedingte Verwendung Pins
            - Beschreibung
        *   - IO13, IO15, IO2, IO4
            - Hochziehen mit einem 47K-Widerstand setzt den Wert standardmäßig auf hoch.
        *   - IO27, IO26, IO33
            - Hochziehen mit einem 4.7K-Widerstand setzt den Wert standardmäßig auf hoch.
        *   - IO32
            - Herunterziehen mit einem 1K-Widerstand setzt den Wert standardmäßig auf niedrig.

* **Strapping Pins (Eingang)**

    Strapping-Pins sind eine spezielle Gruppe von Pins, die verwendet werden, um bestimmte Boot-Modi während des Gerätestarts 
    (d.h., Einschalt-Reset) zu bestimmen.
     
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    
    Generell wird **nicht empfohlen, sie als Eingangspins zu verwenden**. Wenn Sie diese Pins verwenden möchten, berücksichtigen Sie den potenziellen Einfluss auf den Boot-Vorgang. Weitere Details finden Sie im Abschnitt :ref:`esp32_strapping`.


**Schaltplan**

.. image:: ../../img/circuit/circuit_5.1_button.png

Um eine ordnungsgemäße Funktionalität zu gewährleisten, verbinden Sie eine Seite des Taster-Pins mit 3,3V und die andere Seite mit IO14. Wenn der Taster gedrückt wird, wird IO14 auf hoch gesetzt, was dazu führt, dass die LED aufleuchtet. Wird der Taster losgelassen, kehrt IO14 in seinen schwebenden Zustand zurück, der entweder hoch oder niedrig sein kann. Um ein stabiles niedriges Niveau zu gewährleisten, wenn der Taster nicht gedrückt ist, sollte IO14 über einen 10K-Pull-Down-Widerstand mit GND verbunden werden.

**Verdrahtung**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::
    
    Ein Vier-Pin-Taster ist in H-Form gestaltet. Wenn der Taster nicht gedrückt ist, sind die linke und rechte Pins getrennt, und es kann kein Strom zwischen ihnen fließen. Wenn der Taster jedoch gedrückt wird, werden die linke und rechte Pins verbunden, wodurch ein Stromweg entsteht.

**Code**

.. note::

    * Sie können die Datei ``5.1_button.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\5.1_button`` öffnen. 
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/702c5a70-78e7-4a8b-a0c7-10c0acebfc12/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, leuchtet die LED auf, wenn Sie den Taster drücken, und geht aus, wenn Sie ihn loslassen.

Gleichzeitig können Sie den Seriellen Monitor in der oberen rechten Ecke öffnen, um den Wert des Tasters zu beobachten. Wenn der Taster gedrückt wird, wird "1" gedruckt, ansonsten "0".

.. image:: img/button_serial.png


**Wie funktioniert das?**

Die vorherigen Projekte beinhalteten alle das Ausgeben von Signalen, entweder in Form von digitalen oder PWM-Signalen.

Dieses Projekt beinhaltet das Empfangen von Eingangssignalen von externen Komponenten zum ESP32-Board. Sie können das Eingangssignal über den Seriellen Monitor in der Arduino IDE einsehen.


#. In der ``setup()`` Funktion wird der Taster-Pin als ``input`` und der LED-Pin als ``output`` initialisiert. Die serielle Kommunikation wird ebenfalls mit einer Baudrate von 115200 gestartet.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            // initialize the button pin as an input
            pinMode(buttonPin, INPUT);
            // initialize the LED pin as an output
            pinMode(ledPin, OUTPUT);
        }
    
    * ``Serial.begin(speed)``: Legt die Datenrate in Bits pro Sekunde (Baud) für die serielle Datenübertragung fest.

        * ``speed``: in Bits pro Sekunde (Baud). Erlaubte Datentypen: ``long``.

#. In der ``loop()`` Funktion wird der Zustand des Tasters gelesen und in der Variablen ``buttonState`` gespeichert. Der Wert von ``buttonState`` wird mit ``Serial.println()`` in den Seriellen Monitor gedruckt.

    .. code-block:: arduino

        void loop() {
            // read the state of the button value
            buttonState = digitalRead(buttonPin);
            Serial.println(buttonState);
            delay(100);
            // if the button is pressed, the buttonState is HIGH
            if (buttonState == HIGH) {
                // turn LED on
                digitalWrite(ledPin, HIGH);

            } else {
                // turn LED off
                digitalWrite(ledPin, LOW);
            }
        }

    Wenn der Taster gedrückt und der ``buttonState`` HIGH ist, wird die LED eingeschaltet, indem der ``ledPin`` auf ``HIGH`` gesetzt wird. Andernfalls wird die LED ausgeschaltet.

    * ``int digitalRead(uint8_t pin);``: Um den Zustand eines als EINGANG konfigurierten Pins zu lesen, wird die Funktion digitalRead verwendet. Diese Funktion gibt den logischen Zustand des ausgewählten Pins als ``HIGH`` oder ``LOW`` zurück.

        * ``pin`` auswählen GPIO

    * ``Serial.println()``: Druckt Daten an den seriellen Port als lesbaren ASCII-Text, gefolgt von einem Wagenrücklaufzeichen (ASCII 13 oder '\r') und einem Zeilenumbruchzeichen (ASCII 10 oder '\n').

