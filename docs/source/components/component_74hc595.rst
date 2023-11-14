.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

Sind Sie jemals in der Situation gewesen, eine Vielzahl von LEDs steuern zu wollen, oder benötigten Sie einfach mehr I/O-Pins, um Tasten, Sensoren und Servos gleichzeitig zu kontrollieren? Sicherlich können Sie einige Sensoren an Arduino-Pins anschließen, doch bald werden Ihnen die Pins am Arduino ausgehen.

Die Lösung hierfür sind "Schieberegister". Schieberegister ermöglichen es Ihnen, die Anzahl der I/O-Pins, die Sie vom Arduino (oder jedem Mikrocontroller) verwenden können, zu erweitern. Der 74HC595-Schieberegister ist einer der bekanntesten.

Der 74HC595 steuert im Wesentlichen acht unabhängige Ausgangspins und verwendet dabei nur drei Eingangspins. Wenn Sie mehr als acht zusätzliche I/O-Leitungen benötigen, können Sie problemlos beliebig viele Schieberegister kaskadieren und so eine große Anzahl an I/O-Leitungen schaffen. All dies wird durch das sogenannte Verschieben erreicht.

**Merkmale**

* 8-Bit serieller Eingang, paralleler Ausgang
* Breiter Betriebsspannungsbereich von 2 V bis 6 V
* Hochstrom-3-State-Ausgänge können bis zu 15 LSTTL-Lasten treiben
* Geringer Stromverbrauch, maximal 80 µA ICC
* Typische tPD = 14 ns
* ±6-mA-Ausgangstreiber bei 5 V
* Geringer Eingangsstrom von maximal 1 µA
* Schieberegister mit direkter Rückstellung

**Pins des 74HC595 und ihre Funktionen:**

.. image:: img/74hc595_pin.png
    :width: 600

* **Q0-Q7**: 8-Bit parallele Datenausgangspins, geeignet zur Steuerung von 8 LEDs oder 8 Pins eines 7-Segment-Displays direkt.
* **Q7'**: Serieller Ausgangspin, verbunden mit dem DS eines weiteren 74HC595, um mehrere 74HC595 in Serie zu schalten
* **MR**: Rücksetzpin, aktiv bei niedrigem Pegel;
* **SHcp**: Zeitsequenzeingang des Schieberegisters. Bei der steigenden Flanke bewegen sich die Daten im Schieberegister sukzessive um ein Bit, d. h., die Daten in Q1 gehen zu Q2 usw. Bei der fallenden Flanke bleiben die Daten im Schieberegister unverändert.
* **STcp**: Zeitsequenzeingang des Speicherregisters. Bei der steigenden Flanke bewegen sich die Daten aus dem Schieberegister in das Speicherregister.
* **OE**: Ausgangsaktivierungspin, aktiv bei niedrigem Pegel.
* **DS**: Serieller Dateneingangspin
* **VCC**: Positive Versorgungsspannung.
* **GND**: Erde.

**Funktionsdiagramm**

.. image:: img/74hc595_functional_diagram.png

**Arbeitsprinzip**

Wenn MR (Pin 10) auf hohem Pegel und OE (Pin 13) auf niedrigem Pegel ist, 
werden die Daten bei der steigenden Flanke von SHcp eingegeben und gelangen durch die steigende Flanke von STcp ins Speicherregister.

* Schieberegister

    * Angenommen, wir möchten die Binärdaten 1110 1110 in das Schieberegister des 74HC595 eingeben.
    * Die Daten werden ab Bit 0 des Schieberegisters eingegeben.
    * Bei jeder steigenden Flanke des Schieberegister-Takts werden die Bits im Schieberegister um einen Schritt verschoben. Zum Beispiel übernimmt Bit 7 den vorherigen Wert in Bit 6, Bit 6 bekommt den Wert von Bit 5 usw.

.. image:: img/74hc595_shift.png

* Speicherregister

    * Wenn das Speicherregister im Zustand der steigenden Flanke ist, werden die Daten des Schieberegisters in das Speicherregister übertragen.
    * Das Speicherregister ist direkt mit den 8 Ausgangspins verbunden, Q0 bis Q7 können ein Byte Daten empfangen.
    * Das sogenannte Speicherregister bedeutet, dass die Daten in diesem Register bestehen und nicht mit einem Ausgang verschwinden.
    * Die Daten bleiben gültig und unverändert, solange der 74HC595 kontinuierlich mit Strom versorgt wird.
    * Wenn neue Daten ankommen, werden die Daten im Speicherregister überschrieben und aktualisiert.

.. image:: img/74hc595_storage.png

**Beispiele**

* :ref:`ar_74hc595` (Arduino-Projekt)
* :ref:`ar_7_segment` (Arduino-Projekt)
* :ref:`ar_dice` (Arduino-Projekt)
* :ref:`py_74hc595` (MicroPython-Projekt)
* :ref:`py_7_segment` (MicroPython-Projekt)
* :ref:`py_dice` (MicroPython-Projekt)
