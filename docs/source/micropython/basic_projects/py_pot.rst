.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_potentiometer:

5.8 Drehen Sie den Knopf
===========================
Ein Potentiometer ist ein dreipoliges Gerät, das häufig verwendet wird, um den Widerstand in einem Schaltkreis anzupassen. Es verfügt über einen Drehknopf oder einen Schieberegler, mit dem der Widerstandswert des Potentiometers verändert werden kann. In diesem Projekt werden wir es nutzen, um die Helligkeit einer LED zu steuern, ähnlich einer Schreibtischlampe in unserem Alltag. Durch Anpassen der Position des Potentiometers können wir den Widerstand im Stromkreis verändern und somit den durch die LED fließenden Strom regulieren, was deren Helligkeit entsprechend anpasst. Dies ermöglicht es uns, ein anpassbares und verstellbares Beleuchtungserlebnis zu schaffen, vergleichbar mit dem einer Schreibtischlampe.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

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

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

Wenn Sie das Potentiometer drehen, ändert sich der Wert von I35. Durch Programmierung können Sie den Wert von I35 nutzen, um die Helligkeit der LED zu steuern. Daher ändert sich die Helligkeit der LED entsprechend, wenn Sie am Potentiometer drehen.


**Verdrahtung**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**Code**


.. note::

    * Öffnen Sie die Datei ``5.8_turn_the_knob.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 



.. code-block:: python

    from machine import ADC, Pin, PWM
    import time

    pot = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      

    # Configure the ADC attenuation to 11dB for full range
    pot.atten(pot.ATTN_11DB)

    # Create a PWM object
    led = PWM(Pin(26), freq=1000)

    while True:
        # Read a raw analog value in the range of 0-4095
        value = pot.read()

        # Scale the value to the range of 0-1023 for ESP32 PWM duty cycle
        pwm_value = int(value * 1023 / 4095)

        # Update the LED brightness based on the potentiometer value
        led.duty(pwm_value)

        # Read the voltage in microvolts and convert it to volts
        voltage = pot.read_uv() / 1000000

        # Print the raw value and the voltage
        print(f"value: {value}, Voltage: {voltage}V")

        # Wait for 0.5 seconds before taking the next reading
        time.sleep(0.5)

Mit diesem Skript ausgeführt, ändert sich die Helligkeit der LED, wenn das Potentiometer gedreht wird, während der analoge Wert und die Spannung an diesem Punkt im Shell angezeigt werden.

* `machine.ADC - MicroPython Docs <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_
