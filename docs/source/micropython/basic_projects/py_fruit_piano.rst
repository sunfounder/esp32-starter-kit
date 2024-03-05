.. _py_fruit_piano:

6.1 Fruchtpiano
============================

Haben Sie schon einmal davon geträumt, Klavier zu spielen, konnten sich aber kein Klavier leisten? Oder möchten Sie einfach nur etwas Spaß mit einem selbstgebauten Fruchtpiano haben? Dann ist dieses Projekt genau das Richtige für Sie!

Mit nur wenigen Berührungssensoren auf dem ESP32-Board können Sie jetzt Ihre Lieblingsmelodien spielen und das Klavierspielen genießen, ohne dabei ein Vermögen auszugeben.

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Über die Touch-Pins**

Der ESP32-Mikrocontroller verfügt über integrierte Touch-Sensor-Funktionalität, die es Ihnen ermöglicht, bestimmte Pins auf dem Board als berührungsempfindliche Eingänge zu verwenden. Der Touch-Sensor funktioniert, indem er Änderungen der Kapazität an den Touch-Pins misst, die durch die elektrischen Eigenschaften des menschlichen Körpers verursacht werden.

Hier sind einige Schlüsselfunktionen des Touch-Sensors auf dem ESP32:

* **Anzahl der Touch-Pins**

    Der ESP32 verfügt über bis zu 10 Touch-Pins, abhängig vom spezifischen Board. Die Touch-Pins sind typischerweise mit einem "T" gefolgt von einer Nummer gekennzeichnet.

    * GPIO4: TOUCH0
    * GPIO0: TOUCH1
    * GPIO2: TOUCH2
    * GPIO15: TOUCH3
    * GPIO13: TOUCH4
    * GPIO12: TOUCH5
    * GPIO14: TOUCH6
    * GPIO27: TOUCH7
    * GPIO33: TOUCH8
    * GPIO32: TOUCH9

    .. note::
        Die Pins GPIO0 und GPIO2 werden für das Bootstrapping und das Flashen der Firmware auf den ESP32 verwendet. Diese Pins sind auch mit der onboard LED und dem Button verbunden. Daher wird im Allgemeinen nicht empfohlen, diese Pins für andere Zwecke zu verwenden, da dies den normalen Betrieb des Boards stören könnte.

* **Empfindlichkeit**

    Der Touch-Sensor auf dem ESP32 ist sehr empfindlich und kann selbst kleine Änderungen der Kapazität erkennen. Die Empfindlichkeit kann über Softwareeinstellungen angepasst werden.

* **ESD-Schutz**

    Die Touch-Pins auf dem ESP32 verfügen über einen eingebauten ESD (Electrostatic Discharge) Schutz, der hilft, Schäden am Board durch statische Elektrizität zu verhindern.

* **Multitouch**

    Der Touch-Sensor auf dem ESP32 unterstützt Multitouch, was bedeutet, dass Sie mehrere Berührungsereignisse gleichzeitig erkennen können.


**Schaltplan**

.. image:: ../../img/circuit/circuit_6.1_fruit_piano.png

Die Idee hinter diesem Projekt besteht darin, Berührungssensoren zu verwenden, um zu erkennen, wenn ein Benutzer einen bestimmten Pin berührt.
Jeder Berührungspin ist mit einer bestimmten Note verbunden, und wenn der Benutzer einen Pin berührt, wird die entsprechende Note auf dem passiven Summer gespielt.
Das Ergebnis ist eine einfache und erschwingliche Möglichkeit, das Klavierspielen zu genießen.


**Verdrahtung**

.. image:: ../../img/wiring/6.1_fruit_piano_bb.png

In diesem Projekt müssen Sie das ESP32 WROOM 32E von der Erweiterungsplatine entfernen und dann in das Steckbrett einsetzen. Dies liegt daran, dass einige Pins auf der Erweiterungsplatine mit Widerständen verbunden sind, was die Kapazität der Pins beeinflusst.

**Code**

.. note::

    * Öffnen Sie die Datei ``6.1_fruit_piano.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 

.. code-block:: python

    from machine import Pin, PWM, TouchPad
    import time

    # Define the touch pins and their corresponding notes
    touch_pins = [4, 15, 13, 12, 14, 27, 33, 32]  # Use valid touch-capable pins
    notes = [262, 294, 330, 349, 392, 440, 494, 523]

    # Initialize the touch sensors
    touch_sensors = [TouchPad(Pin(pin)) for pin in touch_pins]

    # Initialize the buzzer
    buzzer = PWM(Pin(25), duty=0)

    # Function to play a tone
    def play_tone(frequency, duration):
        buzzer.freq(frequency)
        buzzer.duty(512)
        time.sleep_ms(duration)
        buzzer.duty(0)

    touch_threshold = 200

    # Main loop to check for touch inputs and play the corresponding note
    while True:
        for i, touch_sensor in enumerate(touch_sensors):
            value = touch_sensor.read()
            print(i,value)
            if value < touch_threshold:
                play_tone(notes[i], 100)
                time.sleep_ms(50)
            time.sleep(0.01)


Sie können Früchte an diese ESP32-Pins anschließen: 4, 15, 13, 12, 14, 27, 33, 32.

Wenn das Skript läuft, spielen das Berühren dieser Früchte die Noten C, D, E, F, G, A, H und C5.

.. note::
    ``Touch_threshold`` muss basierend auf der Leitfähigkeit verschiedener Früchte angepasst werden.
    
    Sie können das Skript zuerst ausführen, um die von der Shell ausgegebenen Werte zu sehen.

    .. code-block::

        0 884
        1 801
        2 856
        3 964
        4 991
        5 989
        6 1072
        7 1058

    Nach dem Berühren der Früchte an den Pins 12, 14 und 27 lauten die ausgegebenen Werte wie folgt. Daher habe ich den ``touch_threshold`` auf 200 gesetzt, was bedeutet, dass ein Wert unter 200 als Berührung betrachtet wird und der Summer verschiedene Noten abgibt.
    
    .. code-block::

        0 882
        1 810
        2 799
        3 109
        4 122
        5 156
        6 1068
        7 1055

