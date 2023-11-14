.. _py_joystick:

5.11 Bedienung des Joysticks
================================

Wenn Sie viele Videospiele spielen, sollten Sie mit dem Joystick sehr vertraut sein.
Er wird normalerweise verwendet, um den Charakter zu bewegen, den Bildschirm zu drehen usw.

Das Prinzip hinter der Fähigkeit des Joysticks, dem Computer unsere Aktionen zu übermitteln, ist sehr einfach.
Man kann ihn sich als aus zwei Potentiometern bestehend vorstellen, die senkrecht zueinander stehen.
Diese beiden Potentiometer messen den analogen Wert des Joysticks vertikal und horizontal, was in einem Wert (x, y) in einem ebenen rechtwinkligen Koordinatensystem resultiert.


Der Joystick dieses Kits verfügt auch über einen digitalen Eingang, der aktiviert wird, wenn der Joystick gedrückt wird.

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 15

        *   - Für Analogeingang
            - IO14, IO25, I35, I34, I39, I36
        *   - Für Digitaleingang
            - IO13, IO14, IO27, IO26, IO25, IO33, IO4, IO18, IO19, IO21, IO22, IO23

* **Strapping Pins (Eingang)**

    Strapping Pins sind eine spezielle Gruppe von Pins, die verwendet werden, um spezifische Startmodi während des Gerätestarts zu bestimmen 
    (z. B. Power-On-Reset).

        
    .. list-table::
        :widths: 5 15

        *   - Strapping-Pins
            - IO5, IO0, IO2, IO12, IO15 
    
    Generell wird **nicht empfohlen, sie als Eingangspins zu verwenden**. Wenn Sie diese Pins verwenden möchten, bedenken Sie die möglichen Auswirkungen auf den Startprozess. Für weitere Details siehe den Abschnitt :ref:`esp32_strapping`.

**Schaltplan**

.. image:: ../../img/circuit/circuit_5.11_joystick.png

Der SW (Z-Achse)-Pin ist mit IO33 verbunden, der einen eingebauten 4,7K-Pull-up-Widerstand hat. Daher gibt er, wenn der SW-Knopf nicht gedrückt ist, ein hohes Signal aus. Wird der Knopf gedrückt, wird ein niedriges Signal ausgegeben.

I34 und I35 ändern ihre Werte, wenn Sie den Joystick bewegen. Der Bereich der Werte reicht von 0 bis 4095.

**Verdrahtung**

.. image:: ../../img/wiring/5.11_joystick_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.11_joystick.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 

.. code-block:: python

    from machine import ADC,Pin
    import time

    xAxis = ADC(Pin(34, Pin.IN)) # create an ADC object acting on a pin      
    xAxis.atten(xAxis.ATTN_11DB)
    yAxis = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      
    yAxis.atten(yAxis.ATTN_11DB)
    button = Pin(33, Pin.IN, Pin.PULL_UP)

    while True:
        xValue = xAxis.read()  # read a raw analog value in the range 0-4095
        yValue = yAxis.read()  # read a raw analog value in the range 0-4095
        btnValue = button.value()
        print(f"X:{xValue}, Y:{yValue}, Button:{btnValue}")
        time.sleep(0.1)

Wenn das Programm läuft, gibt die Shell die x-, y- und Knopfwerte des Joysticks aus.

.. code-block:: 

    X:1921, Y:1775, Button:0
    X:1921, Y:1775, Button:0
    X:1923, Y:1775, Button:0
    X:1924, Y:1776, Button:0
    X:1926, Y:1777, Button:0
    X:1925, Y:1776, Button:0
    X:1924, Y:1776, Button:0


* Die x- und y-Achsenwerte sind analoge Werte, die von 0 bis 4095 variieren.
* Der Knopf ist ein digitaler Wert mit einem Status von 1 (Loslassen) oder 0 (Drücken).

    .. image:: img/joystick_direction.png
