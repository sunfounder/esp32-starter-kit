.. _ar_fruit_piano:

6.1 Fruchtpiano
====================

Haben Sie jemals davon geträumt, Klavier zu spielen, konnten sich aber keines leisten? Oder möchten Sie einfach nur Spaß haben und ein Fruchtpiano basteln? Dann ist dieses Projekt genau das Richtige für Sie!

Mit nur wenigen Berührungssensoren auf dem ESP32-Board können Sie jetzt Ihre Lieblingsmelodien spielen und das Klavierspielen genießen, ohne viel Geld ausgeben zu müssen.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Über die Touch-Pins**

Der ESP32-Mikrocontroller verfügt über eine integrierte Touchsensorfunktionalität, die es Ihnen ermöglicht, bestimmte Pins auf dem Board als berührungsempfindliche Eingänge zu verwenden. Der Touchsensor funktioniert, indem er Veränderungen in der Kapazität an den Touch-Pins misst, die durch die elektrischen Eigenschaften des menschlichen Körpers verursacht werden.

Hier sind einige wichtige Merkmale des Touchsensors am ESP32:

* **Anzahl der Touch-Pins**

    Der ESP32 hat bis zu 10 Touch-Pins, abhängig vom spezifischen Board. Die Touch-Pins sind typischerweise mit einem „T“ gefolgt von einer Zahl gekennzeichnet.

    * GPIO4: TOUCH0
    * GPIO0：TOUCH1
    * GPIO2: TOUCH2
    * GPIO15: TOUCH3
    * GPIO13: TOUCH4
    * GPIO12: TOUCH5
    * GPIO14: TOUCH6
    * GPIO27: TOUCH7
    * GPIO33: TOUCH8
    * GPIO32: TOUCH9

    .. note::
        Die Pins GPIO0 und GPIO2 werden zum Booten und Flashen der Firmware auf dem ESP32 verwendet. Diese Pins sind auch mit der integrierten LED und dem Knopf verbunden. Daher wird generell nicht empfohlen, diese Pins für andere Zwecke zu verwenden, da dies die normale Funktion des Boards stören könnte.


* **Empfindlichkeit**

    Der Touchsensor auf dem ESP32 ist sehr empfindlich und kann sogar kleine Änderungen in der Kapazität erkennen. Die Empfindlichkeit kann über Softwareeinstellungen angepasst werden.

* **ESD-Schutz**

    Die Touch-Pins auf dem ESP32 verfügen über einen eingebauten ESD (Elektrostatische Entladung)-Schutz, der hilft, Schäden am Board durch statische Elektrizität zu verhindern.

* **Multitouch**

    Der Touchsensor auf dem ESP32 unterstützt Multitouch, was bedeutet, dass Sie mehrere Berührungsereignisse gleichzeitig erkennen können.


**Schaltplan**

.. image:: ../../img/circuit/circuit_6.1_fruit_piano.png

Die Idee hinter diesem Projekt besteht darin, Touchsensoren zu verwenden, um zu erkennen, wenn ein Benutzer einen bestimmten Pin berührt. 
Jeder Touch-Pin ist mit einer bestimmten Note verbunden, und wenn der Benutzer einen Pin berührt, 
wird die entsprechende Note auf dem passiven Summer gespielt. 
Das Ergebnis ist eine einfache und erschwingliche Möglichkeit, das Klavierspielen zu genießen.


**Verdrahtung**

.. image:: ../../img/wiring/6.1_fruit_piano_bb.png

In diesem Projekt müssen Sie das ESP32 WROOM 32E von der Erweiterungsplatine entfernen und dann in das Steckbrett einsetzen. Dies liegt daran, dass einige Pins auf der Erweiterungsplatine mit Widerständen verbunden sind, was die Kapazität der Pins beeinflusst.

**Code**


.. note::

    * Sie können die Datei ``6.1_fruit_piano.ino`` direkt unter dem Pfad ``esp32-starter-kit-main\c\codes\6.1_fruit_piano`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/3e06ce6c-268a-4fdc-99d0-6d74f68265e2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Sie können Früchte mit diesen ESP32-Pins verbinden: 4, 15, 13, 12, 14, 27, 33, 32.

Wenn das Skript läuft, werden durch Berühren dieser Früchte die Noten C, D, E, F, G, A, B und C5 gespielt.

**Wie funktioniert das?**

* ``touchRead(uint8_t pin);``

    Diese Funktion erhält die Daten des Touchsensors. Jeder Touchsensor hat einen Zähler, der die Anzahl der Lade-/Entladezyklen zählt. 
    Wenn das Pad **touched** wird, ändert sich der Wert im Zähler aufgrund der größeren äquivalenten Kapazität. 
    Die Änderung der Daten bestimmt, ob das Pad berührt wurde oder nicht.

    * ``pin`` GPIO-Pin, um TOUCH-Wert zu lesen

    Diese Funktion gibt einen Wert zwischen 0 und 4095 zurück, wobei ein niedrigerer Wert eine stärkere Berührungseingabe anzeigt.

.. note::
    ``threshold`` muss basierend auf der Leitfähigkeit verschiedener Früchte angepasst werden.
    
    Sie können das Skript zuerst ausführen, um die von der Shell gedruckten Werte zu sehen.

    .. code-block::

      0: 60
      1: 62
      2: 71
      3: 74
      4: 73
      5: 78
      6: 80
      7: 82


    Nach dem Berühren der Früchte an den Pins 12, 14 und 27 sehen die gedruckten Werte wie folgt aus. Daher habe ich den ``threshold`` auf 30 gesetzt, was bedeutet, dass, wenn ein Wert unter 30 erkannt wird, er als berührt gilt und der Summer verschiedene Noten abgibt.
    
    .. code-block::

      0: 60
      1: 62
      2: 71
      3: 9
      4: 12
      5: 14
      6: 75
      7: 78


