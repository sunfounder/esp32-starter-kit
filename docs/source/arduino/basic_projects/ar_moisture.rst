.. _ar_moisture:

5.9 Bodenfeuchtigkeit messen
============================
Dieser kapazitive Bodenfeuchtigkeitssensor unterscheidet sich von den meisten resistiven Sensoren auf dem Markt, indem er das Prinzip der kapazitiven Induktion zur Messung der Bodenfeuchtigkeit verwendet.

Durch das visuelle Ablesen der Werte vom Bodenfeuchtigkeitssensor können wir Informationen über den Feuchtigkeitsgehalt im Boden sammeln. Diese Informationen sind nützlich für verschiedene Anwendungen, wie automatische Bewässerungssysteme, Pflanzengesundheitsüberwachung oder Umweltsensorikprojekte.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv bequem, ein ganzes Kit zu kaufen, hier ist der Link:

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

    Die folgenden Pins sind Strapping-Pins, die den Startprozess des ESP32 während des Einschaltens oder Zurücksetzens beeinflussen. Sobald der ESP32 jedoch erfolgreich gestartet ist, können sie als reguläre Pins verwendet werden.

    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO0, IO12

**Schaltplan**

.. image:: ../../img/circuit/circuit_5.9_soil_moisture.png

Durch das Einstecken des Moduls in den Boden und das Bewässern wird der auf I35 gelesene Wert sinken.

**Verdrahtung**

.. image:: ../../img/wiring/5.9_moisture_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.9_moisture.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\5.9_moisture``.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Button.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/431302c2-3579-4be6-8142-c91d28757004/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Sobald der Code erfolgreich hochgeladen wurde, gibt der serielle Monitor den Bodenfeuchtigkeitswert aus.

Durch das Einstecken des Moduls in den Boden und das Bewässern wird der Wert des Bodenfeuchtigkeitssensors kleiner.
