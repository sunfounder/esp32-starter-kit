.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_moisture:

5.9 Messung der Bodenfeuchtigkeit
=================================

Dieser kapazitive Bodenfeuchtigkeitssensor unterscheidet sich von den meisten auf dem Markt erhältlichen resistiven Sensoren, da er das Prinzip der kapazitiven Induktion zur Erfassung der Bodenfeuchtigkeit verwendet.

Durch das visuelle Ablesen der Werte vom Bodenfeuchtigkeitssensor können wir Informationen über den Feuchtigkeitsgehalt im Boden sammeln. Diese Informationen sind nützlich für verschiedene Anwendungen, wie automatische Bewässerungssysteme, Überwachung der Pflanzengesundheit oder Umweltsensorprojekte.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

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

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Verfügbare Pins**

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 15

        *   - Verfügbare Pins
            - IO14, IO25, I35, I34, I39, I36


* **Strapping Pins**

    Die folgenden Pins sind Strapping-Pins, die den Startvorgang des ESP32 beim Einschalten oder Zurücksetzen beeinflussen. Sobald der ESP32 jedoch erfolgreich hochgefahren ist, können sie als reguläre Pins verwendet werden.

    .. list-table::
        :widths: 5 15

        *   - Strapping-Pins
            - IO0, IO12

**Schaltplan**

.. image:: ../../img/circuit/circuit_5.9_soil_moisture.png

Durch Einsetzen des Moduls in den Boden und Bewässerung desselben wird der auf I35 abgelesene Wert sinken.

**Verdrahtung**

.. image:: ../../img/wiring/5.9_moisture_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.9_moisture.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 



.. code-block:: python


    from machine import ADC,Pin
    import time

    # create an ADC object acting on a pin
    moisture = ADC(Pin(35, Pin.IN))

    # Configure the ADC attenuation to 11dB for full range     
    moisture.atten(moisture.ATTN_11DB)

    while True:

        # read a raw analog value in the range 0-4095
        value = moisture.read()  
        print(value)
        time.sleep(0.05)



Wenn das Skript läuft, sehen Sie den Wert der Bodenfeuchtigkeit in der Shell.

Durch Einsetzen des Moduls in den Boden und Bewässerung desselben wird der Wert des Bodenfeuchtigkeitssensors kleiner werden.
