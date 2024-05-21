.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_photoresistor:

5.7 Das Licht erfühlen
=============================

Der Fotowiderstand ist ein häufig verwendetes Gerät für analoge Eingänge, ähnlich einem Potentiometer. Sein Widerstandswert ändert sich je nach Intensität des empfangenen Lichts. Bei starker Lichteinwirkung verringert sich der Widerstand des Fotowiderstands, und bei abnehmender Lichtintensität steigt der Widerstand.

Indem wir den Wert des Fotowiderstands auslesen, können wir Informationen über die Umgebungslichtverhältnisse sammeln. Diese Informationen können für Aufgaben wie die Steuerung der Helligkeit einer LED, die Anpassung der Empfindlichkeit eines Sensors oder die Umsetzung lichtabhängiger Aktionen in einem Projekt genutzt werden.

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

Sie können diese auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Verfügbare Pins**

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 15

        *   - Verfügbare Pins
            - IO14, IO25, I35, I34, I39, I36


* **Strapping Pins**

    Die folgenden Pins sind Strapping-Pins, die den Startvorgang des ESP32 beim Einschalten oder Zurücksetzen beeinflussen. Nach erfolgreichem Booten des ESP32 können sie jedoch als reguläre Pins verwendet werden.

    .. list-table::
        :widths: 5 15

        *   - Strapping-Pins
            - IO0, IO12

**Schaltplan**

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

Mit zunehmender Lichtintensität verringert sich der Widerstand des lichtabhängigen Widerstands (LDR), was zu einer Abnahme des auf I35 ausgelesenen Werts führt.

**Verdrahtung**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.7_feel_the_light.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren Sie den Code in Thonny. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke auswählen. 

.. code-block:: python

    from machine import ADC,Pin
    import time

    # create an ADC object acting on a pin
    photoresistor = ADC(Pin(35, Pin.IN))

    # Configure the ADC attenuation to 11dB for full range     
    photoresistor.atten(photoresistor.ATTN_11DB)

    while True:

        # read a raw analog value in the range 0-4095
        value = photoresistor.read()  
        print(value)
        time.sleep(0.05)


Nachdem das Programm ausgeführt wurde, zeigt die Shell die Werte des Fotowiderstands an. Sie können eine Taschenlampe darauf richten oder ihn mit der Hand abdecken, um zu sehen, wie sich der Wert ändert.

* ``atten(photoresistor.ATTN_11DB)``: Konfigurieren Sie die ADC-Dämpfung auf 11dB für den vollen Bereich.

    Um Spannungen über der Referenzspannung zu messen, wenden Sie eine Eingangsdämpfung mit dem Schlüsselwortargument atten an. 

    Gültige Werte (und ungefähre lineare Messbereiche) sind:

    * ADC.ATTN_0DB: Keine Dämpfung (100mV - 950mV)
    * ADC.ATTN_2_5DB: 2,5dB Dämpfung (100mV - 1250mV)
    * ADC.ATTN_6DB: 6dB Dämpfung (150mV - 1750mV)
    * ADC.ATTN_11DB: 11dB Dämpfung (150mV - 2450mV)

* `machine.ADC - MicroPython Dokumentation <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

