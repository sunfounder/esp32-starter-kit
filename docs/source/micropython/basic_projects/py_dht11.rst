.. _py_dht11:

5.13 Temperatur - Feuchtigkeit
=======================================
Der DHT11 ist ein Temperatur- und Feuchtigkeitssensor, der häufig für Umweltmessungen verwendet wird. Es handelt sich um einen digitalen Sensor, der mit einem Mikrocontroller kommuniziert, um Temperatur- und Feuchtigkeitswerte bereitzustellen.

In diesem Projekt werden wir den DHT11-Sensor auslesen und die von ihm erfassten Temperatur- und Feuchtigkeitswerte ausgeben.

Durch das Auslesen der vom Sensor bereitgestellten Daten können wir die aktuellen Temperatur- und Feuchtigkeitswerte in der Umgebung ermitteln. Diese Werte können für die Echtzeitüberwachung von Umweltbedingungen, Wetterbeobachtungen, Raumklimasteuerung, Feuchtigkeitsberichte und mehr verwendet werden.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 20

        *   - Verfügbare Pins
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schaltplan**

.. image:: ../../img/circuit/circuit_5.13_dht11.png


**Verdrahtung**

.. image:: ../../img/wiring/5.13_dht11_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.13_dht11.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 

.. code-block:: python

    import dht
    import machine
    import time

    # Initialize the DHT11 sensor and connect it to pin 14
    sensor = dht.DHT11(machine.Pin(14))

    # Loop indefinitely to continuously measure temperature and humidity
    while True:
        try:
            # Measure temperature and humidity
            sensor.measure()

            # Get temperature and humidity values
            temp = sensor.temperature()
            humi = sensor.humidity()

            # Print temperature and humidity
            print("Temperature: {}, Humidity: {}".format(temp, humi))

            # Wait for 1 second between measurements
            time.sleep(1)
        except Exception as e:
            print("Error: ", e)
            time.sleep(1)


Wenn der Code läuft, sehen Sie, wie die Shell kontinuierlich die Temperatur und Feuchtigkeit ausgibt, und während das Programm stabil läuft, werden diese beiden Werte immer genauer.


**Weitere Informationen**

Sie können auch die Temperatur und Feuchtigkeit auf dem I2C LCD1602 anzeigen.

.. image:: ../../img/wiring/5.13_dht11_lcd_bb.png

.. note::

    * Öffnen Sie die Datei ``5.13_dht11_lcd.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 
    * Hier müssen Sie die Bibliothek ``lcd1602.py`` verwenden, überprüfen Sie bitte, ob sie auf den ESP32 hochgeladen wurde. Für eine detaillierte Anleitung siehe :ref:`add_libraries_py`.

.. code-block:: python

    import dht
    import machine
    import time
    from lcd1602 import LCD

    # Initialize the DHT11 sensor and connect it to pin 14
    sensor = dht.DHT11(machine.Pin(14))

    # Initialize the LCD1602 display
    lcd = LCD()

    # Loop to measure temperature and humidity
    while True:
        try:
            # Measure temperature and humidity
            sensor.measure()

            # Get temperature and humidity values
            temp = sensor.temperature()
            humi = sensor.humidity()

            # Print temperature and humidity
            print("Temperature: {}, Humidity: {}".format(temp, humi))

            # Clear the LCD display
            lcd.clear()

            # Display temperature and humidity on the LCD1602 screen
            lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
            lcd.write(0, 1, "Humi: {}%".format(humi))

            # Wait for 2 seconds before measuring again
            time.sleep(2)

        except Exception as e:
            print("Error: ", e)
            time.sleep(2)

