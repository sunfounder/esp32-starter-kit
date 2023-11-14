.. _ar_thermistor:

5.10 Thermometer
===========================

Ein Thermistor ist ein Temperatursensor, der eine starke Temperaturabhängigkeit aufweist und in zwei Typen eingeteilt werden kann: Negative Temperature Coefficient (NTC) und Positive Temperature Coefficient (PTC). Der Widerstand eines NTC-Thermistors verringert sich mit steigender Temperatur, während der Widerstand eines PTC-Thermistors mit steigender Temperatur zunimmt.

In diesem Projekt werden wir einen NTC-Thermistor verwenden. Durch das Verbinden des NTC-Thermistors mit einem analogen Eingangspin des ESP32-Mikrocontrollers können wir seinen Widerstand messen, der direkt proportional zur Temperatur ist.

Indem wir den NTC-Thermistor einbeziehen und die notwendigen Berechnungen durchführen, können wir die Temperatur genau messen und auf dem I2C LCD1602-Modul anzeigen. Dieses Projekt ermöglicht eine Echtzeit-Temperaturüberwachung und bietet eine visuelle Schnittstelle zur Temperaturanzeige.

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|


**Verfügbare Pins**

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 15

        *   - Verfügbare Pins
            - IO14, IO25, I35, I34, I39, I36


* **Strapping Pins**

    Die folgenden Pins sind Strapping-Pins, die den Startprozess des ESP32 während des Einschaltens oder Zurücksetzens beeinflussen. Sobald der ESP32 jedoch erfolgreich gestartet ist, können sie als reguläre Pins verwendet werden.

    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO0, IO12


**Schaltplan**

.. image:: ../../img/circuit/circuit_5.10_thermistor.png

Wenn die Temperatur steigt, verringert sich der Widerstand des Thermistors, was dazu führt, dass der auf I35 gelesene Wert sinkt. Zusätzlich kann durch die Verwendung einer Formel der analoge Wert in eine Temperatur umgerechnet und dann ausgegeben werden.

**Verdrahtung**

.. image:: ../../img/wiring/5.10_thermistor_bb.png


.. note::
    * Der Thermistor ist schwarz und mit 103 gekennzeichnet.
    * Der Farbring des 10K-Ohm-Widerstands ist rot, schwarz, schwarz, rot und braun.

**Code**

.. note::

    * Öffnen Sie die Datei ``5.10_thermistor.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\5.10_thermistor``.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Button.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d0407e3b-cd1e-4f5e-a7b6-391da394339b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Nachdem der Code erfolgreich hochgeladen wurde, gibt der Serielle Monitor die Temperaturen in Celsius und Fahrenheit aus.

**Wie funktioniert das?**

Jeder Thermistor hat einen normalen Widerstand. Hier beträgt er 10k Ohm, gemessen bei 25 Grad Celsius.

Wenn die Temperatur steigt, verringert sich der Widerstand des Thermistors. Dann werden die Spannungsdaten durch den A/D-Adapter in digitale Daten umgewandelt.

Die Temperatur in Celsius oder Fahrenheit wird über die Programmierung ausgegeben.

Hier ist der Zusammenhang zwischen Widerstand und Temperatur:

    **RT =RN expB(1/TK - 1/TN)** 

    * **RT** ist der Widerstand des NTC-Thermistors bei der Temperatur **TK**. 
    * **RN** ist der Widerstand des NTC-Thermistors unter der Nenntemperatur TN. Hier beträgt der numerische Wert von RN 10k. 
    * **TK** ist eine Kelvintemperatur und die Einheit ist K. Hier beträgt der numerische Wert von **TK** ``373.15 + Grad Celsius``. 
    * **TN** ist eine Nenntemperatur in Kelvin; die Einheit ist auch K. Hier beträgt der numerische Wert von TN ``373.15+25``.
    * Und **B(beta)**, die Materialkonstante des NTC-Thermistors, wird auch als Wärmeempfindlichkeitsindex bezeichnet und hat einen numerischen Wert ``4950``. 
    * **exp** ist die Abkürzung von Exponentialfunktion, und die Basiszahl ``e`` ist eine natürliche Zahl und beträgt ungefähr 2,7.

    Umrechnen dieser Formel ``TK=1/(ln(RT/RN)/B+1/TN)`` um die Kelvintemperatur zu erhalten, die minus 273,15 Grad Celsius entspricht.

    Diese Beziehung ist eine empirische Formel. Sie ist nur genau, wenn die Temperatur und der Widerstand innerhalb des wirksamen Bereichs liegen.

**Mehr erfahren**

Sie können auch die berechneten Temperaturen in Celsius und Fahrenheit auf dem I2C LCD1602 anzeigen.


.. note::

    * Sie können die Datei ``5.10_thermistor_lcd.ino`` unter dem Pfad ``euler-kit/arduino/5.10_thermistor_lcd`` öffnen. 
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Button.
    * :ref:`unknown_com_port`
    * Hier wird die ``LiquidCrystal I2C``-Bibliothek verwendet, die Sie aus dem **Library Manager** installieren können.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/93344677-8c5d-41d7-a833-f6365495d344/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

