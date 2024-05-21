.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_7_segment:

7-Segment-Anzeige
======================

.. image:: img/7_segment.png
    :width: 200
    :align: center

Eine 7-Segment-Anzeige ist eine 8-förmige Komponente, die 7 LEDs umfasst. Jede LED wird als Segment bezeichnet - bei Energiezufuhr bildet ein Segment einen Teil einer anzuzeigenden Ziffer.

* Jede der LEDs in der Anzeige erhält ein positionelles Segment, wobei einer ihrer Anschlussstifte aus dem rechteckigen Kunststoffgehäuse herausgeführt wird.
* Diese LED-Stifte sind von "a" bis "g" beschriftet und repräsentieren jede einzelne LED.
* Die anderen LED-Stifte sind miteinander verbunden und bilden einen gemeinsamen Stift.
* Durch das Vorschalten der geeigneten Stifte der LED-Segmente in einer bestimmten Reihenfolge leuchten einige Segmente auf, während andere dunkel bleiben, wodurch der entsprechende Charakter auf der Anzeige dargestellt wird.

**Eigenschaften**

* Größe: 19 x 12,7 x 13,8mm(LxBxH, einschließlich der Stifte)
* Bildschirm: 0,56''
* Farbe: rot
* Gemeinsame Kathode
* Vorwärtsspannung: 1,8V
* 10 Stifte
* Abstand: standard 0,1" (2,54mm)

**Gemeinsame Kathode (CC) oder Gemeinsame Anode (CA)**

Es gibt zwei Arten von Stiftverbindungen: Gemeinsame Kathode (CC) und Gemeinsame Anode (CA).
Wie der Name andeutet, hat eine CC-Anzeige alle Kathoden der 7 LEDs verbunden, während eine CA-Anzeige alle Anoden der 7 Segmente verbunden hat.

* Gemeinsame Kathoden 7-Segment-Anzeige

.. image:: img/segment_cathode.png
    :width: 500

* Gemeinsame Anoden 7-Segment-Anzeige

.. image:: img/segment_anode.png
    :width: 500

**Wie erkennt man CC oder CA?**

Normalerweise gibt es eine Beschriftung auf der Seite der 7-Segment-Anzeige, xxxAx oder xxxBx. Allgemein steht xxxAx für gemeinsame Kathode und xxxBx für gemeinsame Anode.

.. image:: img/7_segment.png
    :width: 250

.. image:: img/7_segment_bs.png

Sie können auch ein Multimeter verwenden, um die 7-Segment-Anzeige zu überprüfen, wenn keine Beschriftung vorhanden ist. Stellen Sie das Multimeter auf Diodentestmodus ein und verbinden Sie das schwarze Kabel mit dem mittleren Stift der 7-Segment-Anzeige und das rote Kabel mit einem beliebigen anderen Stift außer dem mittleren. Die 7-Segment-Anzeige ist eine gemeinsame Kathode, wenn ein Segment aufleuchtet.

Wechseln Sie die roten und schwarzen Messköpfe, wenn kein Segment leuchtet. Wenn ein Segment aufleuchtet, deutet dies auf eine gemeinsame Anode hin.

.. image:: img/7_segment_test.JPG
    :width: 600


**Anzeigecodes**

Um Ihnen zu veranschaulichen, wie 7-Segment-Anzeigen (Gemeinsame Kathode) Zahlen darstellen, haben wir die folgende Tabelle erstellt. 
Die Zahlen sind die Nummern 0-F, die auf der 7-Segment-Anzeige dargestellt werden; (DP) GFEDCBA bezieht sich auf die entsprechende LED, die auf 0 oder 1 gesetzt ist.

.. image:: img/segment_code.png

Zum Beispiel bedeutet 01011011, dass DP, F und C auf 0 gesetzt sind, während die anderen auf 1 gesetzt sind. Daher wird die Zahl 2 auf der 7-Segment-Anzeige angezeigt.

.. image:: img/7segment_2.png


**Beispiele**

* :ref:`ar_7_segment` (Arduino-Projekt)
* :ref:`ar_dice` (Arduino-Projekt)
* :ref:`py_7_segment` (MicroPython-Projekt)
* :ref:`py_dice` (MicroPython-Projekt)

