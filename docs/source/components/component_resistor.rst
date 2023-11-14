.. _cpn_resistor:

Widerstand
============

.. image:: img/resistor.png
    :width: 300

Ein Widerstand ist ein elektronisches Bauelement, das dazu dient, den Strom in einem Zweig zu begrenzen.
Ein Festwiderstand ist eine Art von Widerstand, dessen Widerstandswert nicht verändert werden kann, im Gegensatz zu einem Potentiometer oder einem variablen Widerstand, bei denen der Widerstandswert einstellbar ist.

Es gibt zwei allgemein verwendete Schaltzeichen für Widerstände. Normalerweise ist der Widerstandswert darauf vermerkt. Wenn diese Symbole also in einem Schaltplan auftauchen, repräsentieren sie einen Widerstand.

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** ist die Einheit des Widerstands, größere Einheiten sind KΩ, MΩ usw.
Ihre Beziehung lässt sich wie folgt darstellen: 1 MΩ = 1000 KΩ, 1 KΩ = 1000 Ω. Normalerweise ist der Wert des Widerstands darauf vermerkt.

Bei der Verwendung eines Widerstands muss man zuerst seinen Widerstandswert kennen. Hier gibt es zwei Methoden: Sie können die Farbringe auf dem Widerstand beobachten oder ein Multimeter verwenden, um den Widerstand zu messen. Die erste Methode wird empfohlen, da sie bequemer und schneller ist.

.. image:: img/resistance_card.jpg

Wie auf der Karte dargestellt, steht jede Farbe für eine Zahl.

.. list-table::

   * - Schwarz
     - Braun
     - Rot
     - Orange
     - Gelb
     - Grün
     - Blau
     - Violett
     - Grau
     - Weiß
     - Gold
     - Silber
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0,1
     - 0,01

Häufig verwendet werden 4- und 5-Ring-Widerstände, auf denen sich 4 bzw. 5 farbige Ringe befinden.

Normalerweise kann es schwierig sein, bei einem neuen Widerstand zu entscheiden, an welchem Ende man mit dem Lesen der Farben beginnen soll.
Ein Tipp ist, dass der Abstand zwischen dem vierten und fünften Ring vergleichsweise größer ist.

Deshalb können Sie den Abstand zwischen den beiden Farbringen an einem Ende des Widerstands beobachten; 
ist dieser größer als jeder andere Ringabstand, dann sollten Sie von der gegenüberliegenden Seite beginnen zu lesen.

Sehen wir uns an, wie der Widerstandswert eines 5-Ring-Widerstands wie unten dargestellt gelesen wird.

.. image:: img/220ohm.jpg
    :width: 500

Für diesen Widerstand sollte der Wert also von links nach rechts gelesen werden. 
Der Wert sollte in diesem Format sein: 1. Band 2. Band 3. Band x 10^Multiplikator (Ω) und der zulässige Fehler ist ±Toleranz%. 
Der Widerstandswert dieses Widerstands beträgt daher 2(rot) 2(rot) 0(schwarz) x 10^0(schwarz) Ω = 220 Ω, 
und der zulässige Fehler beträgt ± 1% (braun).

.. list-table::Häufige Widerstandsfarbcodes
    :header-rows: 1

    * - Widerstand 
      - Farbcode  
    * - 10Ω   
      - braun schwarz schwarz silber braun
    * - 100Ω   
      - braun schwarz schwarz schwarz braun
    * - 220Ω 
      - rot rot schwarz schwarz braun
    * - 330Ω 
      - orange orange schwarz schwarz braun
    * - 1kΩ 
      - braun schwarz schwarz braun braun
    * - 2kΩ 
      - rot schwarz schwarz braun braun
    * - 5.1kΩ 
      - grün braun schwarz braun braun
    * - 10kΩ 
      - braun schwarz schwarz rot braun 
    * - 100kΩ 
      - braun schwarz schwarz orange braun 
    * - 1MΩ 
      - braun schwarz schwarz grün braun 

Weitere Informationen über Widerstände finden Sie auf Wiki: `Widerstand – Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_.

