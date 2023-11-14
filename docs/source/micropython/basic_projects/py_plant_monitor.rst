.. _py_plant_monitor:

6.8 Pflanzenüberwachung
===============================

Willkommen beim Pflanzenüberwachungsprojekt!

In diesem Projekt werden wir ein ESP32-Board verwenden, um ein System zu entwickeln, das uns hilft, unsere Pflanzen zu pflegen. Mit diesem System können wir Temperatur, Luftfeuchtigkeit, Bodenfeuchtigkeit und Lichtverhältnisse unserer Pflanzen überwachen und sicherstellen, dass sie die notwendige Pflege und Aufmerksamkeit erhalten, um zu gedeihen.

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

Sie können die Komponenten auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.8_plant_monitor_l293d.png

Das System verwendet einen DHT11-Sensor, um die Temperatur- und Luftfeuchtigkeitswerte der Umgebung zu messen.
Gleichzeitig wird ein Bodenfeuchtigkeitsmodul verwendet, um den Feuchtigkeitsgehalt des Bodens zu messen, und ein Fotowiderstand dient zur Messung des Lichtniveaus. Die Messwerte dieser Sensoren werden auf einem LCD-Bildschirm angezeigt, und eine Wasserpumpe kann mit einem Knopf gesteuert werden, um die Pflanze bei Bedarf zu bewässern.

IO32 verfügt über einen internen Pull-Down-Widerstand von 1K und befindet sich standardmäßig auf einem niedrigen Logikniveau. Wenn der Knopf gedrückt wird, wird eine Verbindung zu VCC (Hohe Spannung) hergestellt, was zu einem hohen Logikniveau auf IO32 führt.


**Verdrahtung**

.. note::

    Es wird hier empfohlen, zuerst die Batterie einzusetzen und dann den Schalter auf dem Erweiterungsboard auf die ON-Position zu schieben, um die Batterieversorgung zu aktivieren.


.. image:: ../../img/wiring/6.8_plant_monitor_l293d_bb.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``6.8_plant_monitor.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren Sie den Code in Thonny. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der rechten unteren Ecke ausgewählt ist.

.. code-block:: python

      from machine import ADC, Pin
      import time
      import dht
      from lcd1602 import LCD

      # DHT11
      dht11 = dht.DHT11(Pin(13))

      # Soil moisture
      moisture_pin = ADC(Pin(14))
      moisture_pin.atten(ADC.ATTN_11DB)

      # Photoresistor
      photoresistor = ADC(Pin(35))
      photoresistor.atten(ADC.ATTN_11DB)

      # Button and pump
      button = Pin(32, Pin.IN)

      motor1A = Pin(27, Pin.OUT)
      motor2A = Pin(26, Pin.OUT)

      # I2C LCD1602 setup
      lcd = LCD()

      # Rotate the pump
      def rotate():
      motor1A.value(1)
      motor2A.value(0)

      # Stop the pump
      def stop():
      motor1A.value(0)
      motor2A.value(0)

      button_state = False

      # Define the button callback function to toggle the button state
      def button_callback(pin):
      global button_state
      button_state = not button_state

      # Attach the button callback function to the rising edge of the button pin
      button.irq(trigger=Pin.IRQ_RISING, handler=button_callback)

      page = 0
      temp = 0
      humi = 0
            
      try:
      while True:
            
            # If the button is pressed and button state is True
            if button_state:
                  print("rotate")
                  rotate()

            # If the button is pressed again and button state is False
            if not button_state:
                  print("stop")
                  stop()
            time.sleep(2)

            # Clear the LCD display
            lcd.clear()
            
            # Toggle the value of the page variable between 0 and 1
            page=(page+1)%2
            
            # When page is 1, display temperature and humidity on the LCD1602
            if page is 1:
                  try:
                  # Measure temperature and humidity
                  dht11.measure()

                  # Get temperature and humidity values
                  temp = dht11.temperature()
                  humi = dht11.humidity()
                  except Exception as e:
                  print("Error: ", e)         

                  # Display temperature and humidity
                  lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
                  lcd.write(0, 1, "Humi: {}%".format(humi))

            # If page is 0, display the soil moisture and light
            else:
                  light = photoresistor.read()
                  moisture = moisture_pin.read()

                  # Clear the LCD display
                  lcd.clear()

                  # Display the value of soil moisture and light
                  lcd.write(0, 0, f"Moisture: {moisture}")
                  lcd.write(0, 1, f"Light: {light}")

      except KeyboardInterrupt:
      # Stop the motor when KeyboardInterrupt is caught
      stop()



* Während der Code ausgeführt wird, zeigt das I2C LCD1602 abwechselnd Temperatur und Luftfeuchtigkeit sowie Analogwerte der Bodenfeuchtigkeit und Lichtintensität an, mit einem Intervall von 2 Sekunden.
* Drücken Sie den Knopf, um die Wasserpumpe zu starten, und drücken Sie ihn erneut, um die Wasserpumpe zu stoppen.

.. note:: 

    Falls der Code und die Verkabelung korrekt sind, aber das LCD dennoch keinen Inhalt anzeigt, können Sie das Potentiometer auf der Rückseite justieren, um den Kontrast zu erhöhen.
