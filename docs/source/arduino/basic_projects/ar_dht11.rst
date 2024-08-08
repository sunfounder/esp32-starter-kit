.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_dht11:

5.13 Temperatur - Feuchtigkeit
=======================================

Der DHT11 ist ein häufig für Umweltmessungen verwendeter Temperatur- und Feuchtigkeitssensor. Es handelt sich um einen digitalen Sensor, der mit einem Mikrocontroller kommuniziert, um Temperatur- und Feuchtigkeitswerte bereitzustellen.

In diesem Projekt werden wir den DHT11-Sensor auslesen und die von ihm erfassten Temperatur- und Feuchtigkeitswerte ausgeben.

Durch das Auslesen der vom Sensor bereitgestellten Daten können wir die aktuellen Temperatur- und Feuchtigkeitswerte in der Umgebung ermitteln. Diese Werte können für die Echtzeitüberwachung von Umweltbedingungen, Wetterbeobachtungen, Raumklimakontrolle, Feuchtigkeitsberichte und mehr verwendet werden.

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

    * Öffnen Sie die Datei ``5.13_dht11.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\5.13_dht11``.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Button.
    * :ref:`unknown_com_port`
    * Hier wird die Bibliothek „DHT-Sensorbibliothek“ verwendet, die Sie aus dem **Library Manager** installieren können.

        .. image:: img/dht_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/95bef6dc-a4db-4315-9308-6663b77ddfa0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Denken Sie daran, die serielle Kommunikationsgeschwindigkeit auf 115200 einzustellen.

Nachdem der Code erfolgreich hochgeladen wurde, wird der Serielle Monitor kontinuierlich die Temperatur und Feuchtigkeit ausgeben, und während das Programm stetig läuft, werden diese beiden Werte immer genauer.


**Wie funktioniert das?**

#.  Beinhaltet die ``DHT.h``-Bibliothek, die Funktionen zur Interaktion mit den DHT-Sensoren bereitstellt. Anschließend den Pin und Typ für den DHT-Sensor festlegen.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 14  // Set the pin connected to the DHT11 data pin
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#.  Initialisiert die serielle Kommunikation mit einer Baudrate von 115200 und initialisiert den DHT-Sensor.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#.  In der Funktion ``loop()``, die Temperatur- und Feuchtigkeitswerte vom DHT11-Sensor lesen und sie auf dem seriellen Monitor ausgeben.

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * Die Funktion ``dht.readHumidity()`` wird aufgerufen, um den Feuchtigkeitswert vom DHT-Sensor zu lesen.
    * Die Funktion ``dht.readTemperature()`` wird aufgerufen, um den Temperaturwert vom DHT-Sensor zu lesen.
    * Die Funktion ``isnan()`` wird verwendet, um zu überprüfen, ob die Messwerte gültig sind. Wenn entweder der Feuchtigkeits- oder der Temperaturwert NaN (keine Zahl) ist, deutet dies auf eine fehlgeschlagene Messung vom Sensor hin, und eine Fehlermeldung wird ausgegeben.

**Mehr erfahren**

Sie können auch die Temperatur und Feuchtigkeit auf dem I2C LCD1602 anzeigen.


.. note::

    * Sie können die Datei ``5.10_thermistor_lcd.ino`` unter dem Pfad ``euler-kit/arduino/5.10_thermistor_lcd`` öffnen. 
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Button.
    * :ref:`unknown_com_port`
    * Die Bibliotheken ``LiquidCrystal_I2C`` und ``DHT-Sensorbibliothek`` werden hier verwendet, Sie können sie aus dem **Library Manager** installieren.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fb46ba7e-0a09-4805-87ab-f733e23eb920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
