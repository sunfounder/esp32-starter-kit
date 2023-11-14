.. _ar_plant_monitor:

6.6 Pflanzenüberwachung
===============================

Willkommen beim Projekt Pflanzenüberwachung!

In diesem Projekt werden wir ein ESP32-Board verwenden, um ein System zu erstellen, das uns hilft, unsere Pflanzen zu pflegen. Mit diesem System können wir die Temperatur, die Luftfeuchtigkeit, die Bodenfeuchtigkeit und den Lichtpegel unserer Pflanzen überwachen und sicherstellen, dass sie die Pflege und Aufmerksamkeit erhalten, die sie zum Gedeihen benötigen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.8_plant_monitor_l293d.png

Das System verwendet einen DHT11-Sensor, um die Temperatur- und Feuchtigkeitswerte der Umgebung zu messen. 
In der Zwischenzeit wird ein Bodenfeuchtigkeitsmodul verwendet, um den Feuchtigkeitsgehalt des Bodens zu messen, und ein Fotowiderstand, um 
das Lichtniveau zu messen. Die Messwerte dieser Sensoren werden auf einem LCD-Bildschirm angezeigt, und eine Wasserpumpe kann gesteuert werden 
mit einem Knopf, um die Pflanze bei Bedarf zu bewässern.

IO32 hat einen internen Pull-Down-Widerstand von 1K und ist standardmäßig auf einem niedrigen Logikniveau. Wenn der Knopf gedrückt wird, stellt er eine Verbindung zu VCC (Hochspannung) her, was zu einem hohen Logikniveau auf IO32 führt.


**Verdrahtung**

.. note::

    Es wird empfohlen, hier die Batterie einzulegen und dann den Schalter auf dem Erweiterungsboard auf die ON-Position zu schieben, um die Batterieversorgung zu aktivieren.

.. image:: ../../img/wiring/6.8_plant_monitor_l293d_bb.png
    :width: 800

**Code**

.. note::

    * Sie können die Datei ``6.6_plant_monitor.ino`` direkt unter dem Pfad ``esp32-starter-kit-main\c\codes\6.6_plant_monitor`` öffnen. 
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    * Die Bibliotheken ``LiquidCrystal_I2C`` und ``DHT sensor library`` werden hier verwendet, Sie können sie aus dem **Library Manager** installieren.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/52f54c4d-ad8c-49c4-816a-2a55a247d425/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

* Nach dem Hochladen des Codes zeigt das I2C LCD1602 abwechselnd Temperatur und Luftfeuchtigkeit sowie Bodenfeuchtigkeit und Lichtintensität analoge Werte an, mit einem 2-Sekunden-Intervall.
* Die Wasserpumpe wird mit einem Knopfdruck gesteuert. Um die Pflanzen zu bewässern, halten Sie den Knopf gedrückt und lassen Sie ihn los, um das Bewässern zu stoppen.

.. note:: 

    Wenn der Code und die Verdrahtung korrekt sind, das LCD jedoch weiterhin keinen Inhalt anzeigt, können Sie den Potentiometer auf der Rückseite verstellen, um den Kontrast zu erhöhen.

