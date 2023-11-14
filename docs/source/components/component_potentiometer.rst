.. _cpn_pot:

Potentiometer
===============

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Ein Potentiometer ist ebenfalls ein Widerstandsbauteil mit drei Anschlüssen, dessen Widerstandswert entsprechend einer regelmäßigen Variation angepasst werden kann.

Potentiometer gibt es in verschiedenen Formen, Größen und Werten, aber sie haben alle Folgendes gemeinsam:

* Sie verfügen über drei Anschlüsse (oder Verbindungspunkte).
* Sie besitzen einen Drehknopf, eine Schraube oder einen Schieber, der bewegt werden kann, um den Widerstand zwischen dem mittleren Anschluss und einem der beiden äußeren Anschlüsse zu variieren.
* Der Widerstand zwischen dem mittleren Anschluss und einem der beiden äußeren Anschlüsse variiert von 0 Ω bis zum maximalen Widerstand des Potentiometers, je nachdem wie weit der Drehknopf, die Schraube oder der Schieber bewegt wird.

Hier ist das Schaltungssymbol des Potentiometers.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Die Funktionen des Potentiometers in einer Schaltung sind wie folgt:

#. Als Spannungsteiler

    Das Potentiometer ist ein kontinuierlich einstellbarer Widerstand. Wenn Sie die Welle oder den Schiebegriff des Potentiometers einstellen, wird der bewegliche Kontakt auf dem Widerstand gleiten. An diesem Punkt kann eine Spannung ausgegeben werden, abhängig von der am Potentiometer angelegten Spannung und dem Winkel, den der bewegliche Arm gedreht hat, oder dem Weg, den er zurückgelegt hat.

#. Als Rheostat

    Wird das Potentiometer als Rheostat verwendet, verbinden Sie den mittleren Pin mit einem der beiden anderen Pins im Schaltkreis. Dadurch erhalten Sie einen sanft und kontinuierlich veränderbaren Widerstandswert innerhalb des Weges des beweglichen Kontakts.

#. Als Stromregler

    Wenn das Potentiometer als Stromregler wirkt, muss der Schleifkontakt als einer der Ausgangsanschlüsse verbunden werden.

Wenn Sie mehr über Potentiometer erfahren möchten, siehe: `Potentiometer - Wikipedia <https://en.wikipedia.org/wiki/Potentiometer>`_

**Beispiele**

* :ref:`ar_potentiometer` (Arduino-Projekt)
* :ref:`py_potentiometer` (MicroPython-Projekt)
* :ref:`sh_moving_mouse` (Scratch-Projekt)
* :ref:`sh_breakout_clone` (Scratch-Projekt)

