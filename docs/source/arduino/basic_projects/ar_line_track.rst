.. _ar_line_track:

5.4 Linie Erkennen
===================================

Das Linienverfolgungsmodul wird verwendet, um das Vorhandensein von schwarzen Flächen auf dem Boden zu erkennen, wie zum Beispiel schwarze Linien, die mit Isolierband geklebt sind.

Sein Emitter sendet geeignetes Infrarotlicht in den Boden, das von schwarzen Oberflächen relativ absorbiert und schwach reflektiert wird. Das Gegenteil ist der Fall bei weißen Oberflächen. Wenn reflektiertes Licht erkannt wird, wird der Boden momentan als weiß angezeigt. Wird es nicht erkannt, wird er als schwarz angezeigt.

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

Sie können sie auch separat über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

**Verfügbare Pins**

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 20

        *   - Verfügbare Pins
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Strapping Pins (Eingang)**

    Strapping-Pins sind eine spezielle Gruppe von Pins, die verwendet werden, um bestimmte Boot-Modi während des Gerätestarts 
    (d.h., Einschalt-Reset) zu bestimmen.

        
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    
    

    Generell wird **nicht empfohlen, sie als Eingangspins zu verwenden**. Wenn Sie diese Pins verwenden möchten, berücksichtigen Sie den potenziellen Einfluss auf den Boot-Vorgang. Weitere Details finden Sie im Abschnitt :ref:`esp32_strapping`.


**Schaltplan**

.. image:: ../../img/circuit/circuit_5.4_line.png

Wenn das Linienverfolgungsmodul eine schwarze Linie erkennt, gibt IO14 ein hohes Niveau zurück. Andererseits gibt es ein niedriges Niveau zurück, wenn es eine weiße Linie erkennt. Sie können das blaue Potentiometer einstellen, um die Empfindlichkeit der Erkennung dieses Moduls zu ändern.

**Verdrahtung**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**Code**

.. note::

    * Sie können die Datei ``5.4_detect_the_line.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\5.4_detect_the_line`` öffnen. 
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fc7f3fe9-179a-4a3a-acbf-a4014faf3920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Wenn das Linienverfolgungsmodul eine schwarze Linie erkennt, nachdem der Code erfolgreich hochgeladen wurde, wird "Schwarz" im Seriellen Monitor angezeigt. Andernfalls wird "Weiß" gedruckt.

