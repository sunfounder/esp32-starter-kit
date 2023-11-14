.. _ar_blink:

2.1 Hallo, LED!
=======================================

Genau wie das Drucken von "Hallo, Welt!" der erste Schritt beim Erlernen des Programmierens ist, ist die Verwendung eines Programms zur Steuerung einer LED die traditionelle Einführung in das Erlernen der physischen Programmierung.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

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

Du kannst sie auch einzeln über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENEINFÜHRUNG
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


**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schaltplan**

.. image:: ../../img/circuit/circuit_2.1_led.png

Dieser Schaltkreis funktioniert nach einem einfachen Prinzip, und die Stromrichtung ist in der Abbildung dargestellt. Die LED leuchtet auf, nachdem der 220-Ohm-Strombegrenzungswiderstand, wenn Pin26 ein hohes Pegel ausgibt. Die LED schaltet sich aus, wenn Pin26 ein niedriges Pegel ausgibt.

**Verdrahtung**

.. image:: ../../img/wiring/2.1_hello_led_bb.png


**Code**

.. note::

    * Du kannst die Datei ``2.1_hello_led.ino`` im Pfad ``esp32-starter-kit-main\c\codes\2.1_hello_led`` öffnen. 
    * Wähle das Board (ESP32 Dev Module) und den entsprechenden Port aus und klicke dann auf die **Upload**-Schaltfläche.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1bff2463-40ad-43c1-8815-9f448bab3735/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



Nach erfolgreichem Hochladen des Codes siehst du die blinkende LED.

**Wie funktioniert das?**

#. Deklariere eine Integer-Konstante mit dem Namen ``ledPin`` und weise ihr den Wert 26 zu. 

    .. code-block:: arduino

        const int ledPin = 26;  // The GPIO pin for the LED


#. Initialisiere den Pin in der ``setup()``-Funktion, in der du den Pin im ``OUTPUT``-Modus initialisieren musst.

    .. code-block:: arduino

        void setup() {
            pinMode(ledPin, OUTPUT);
        }

    * ``void pinMode(uint8_t pin, uint8_t mode);``: Diese Funktion wird verwendet, um den GPIO-Betriebsmodus für einen bestimmten Pin festzulegen.

        * ``pin`` definiert die GPIO-Pinnummer.
        * ``mode`` legt den Betriebsmodus fest.

        Folgende Modi werden für die grundlegende Ein- und Ausgabe unterstützt:

        * ``INPUT`` setzt den GPIO als Eingang ohne Pull-up oder Pull-down (hochohmig).
        * ``OUTPUT`` setzt den GPIO als Ausgabe-/Lesemodus.
        * ``INPUT_PULLDOWN`` setzt den GPIO als Eingang mit internem Pull-down.
        * ``INPUT_PULLUP`` setzt den GPIO als Eingang mit internem Pull-up.

#. Die ``loop()``-Funktion enthält die Hauptlogik des Programms und läuft kontinuierlich. Sie wechselt zwischen dem Setzen des Pins auf High und Low, wobei zwischen den Änderungen ein Intervall von einer Sekunde liegt.

    .. code-block:: arduino

        void loop() {
            digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(1000);                       // wait for a second
            digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
            delay(1000);                       // wait for a second
        }

    * ``void digitalWrite(uint8_t pin, uint8_t val);``: Diese Funktion setzt den Zustand des ausgewählten GPIO auf ``HIGH`` oder ``LOW``. Diese Funktion wird nur verwendet, wenn der ``pinMode`` als ``OUTPUT`` konfiguriert wurde.
    
        * ``pin`` definiert die GPIO-Pinnummer.
        * ``val`` setzt den Ausgangszustand auf ``HIGH`` oder ``LOW``.