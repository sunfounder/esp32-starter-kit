.. _cpn_thermistor:

Thermistor
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Ein Thermistor ist eine Art Widerstand, dessen Widerstand stark temperaturabhängig ist, stärker als bei Standardwiderständen. Der Begriff ist eine Kombination aus „thermal“ und „resistor“. Thermistoren werden häufig als Einschaltstrombegrenzer, Temperatursensoren (typischerweise vom Typ mit negativem Temperaturkoeffizienten, NTC), selbst zurücksetzende Überstromschutzvorrichtungen und selbstregulierende Heizelemente (typischerweise vom Typ mit positivem Temperaturkoeffizienten, PTC) verwendet.

* `Thermistor – Wikipedia <https://en.wikipedia.org/wiki/Thermistor>`_

Hier ist das elektronische Symbol eines Thermistors.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

Es gibt zwei grundlegend entgegengesetzte Arten von Thermistoren:

* Bei NTC-Thermistoren nimmt der Widerstand mit steigender Temperatur ab, normalerweise aufgrund einer Zunahme der Leitungselektronen, die durch thermische Agitation aus dem Valenzband herausgestoßen werden. Ein NTC wird üblicherweise als Temperatursensor verwendet oder in Reihe mit einem Stromkreis als Einschaltstrombegrenzer.
* Bei PTC-Thermistoren steigt der Widerstand mit zunehmender Temperatur an, üblicherweise aufgrund verstärkter thermischer Gitterschwingungen, insbesondere von Verunreinigungen und Unvollkommenheiten. PTC-Thermistoren werden häufig in Reihe mit einem Stromkreis installiert und zum Schutz vor Überstrombedingungen als rückstellbare Sicherungen verwendet.

In diesem Kit verwenden wir einen NTC. Jeder Thermistor hat einen normalen Widerstand. Hier beträgt er 10k Ohm, gemessen bei 25 Grad Celsius.

Hier ist die Beziehung zwischen Widerstand und Temperatur:

    RT = RN * expB(1/TK - 1/TN)

* **RT** ist der Widerstand des NTC-Thermistors bei der Temperatur TK.
* **RN** ist der Widerstand des NTC-Thermistors bei der Nenntemperatur TN. Hier beträgt der numerische Wert von RN 10k.
* **TK** ist eine Kelvin-Temperatur und die Einheit ist K. Hier beträgt der numerische Wert von TK 273,15 + Grad Celsius.
* **TN** ist eine Nenn-Kelvin-Temperatur; die Einheit ist ebenfalls K. Hier beträgt der numerische Wert von TN 273,15+25.
* **B(Beta)**, die Materialkonstante des NTC-Thermistors, wird auch als Wärmeempfindlichkeitsindex bezeichnet und hat den numerischen Wert 3950.
* **exp** ist die Abkürzung für exponentiell, und die Basiszahl e ist eine natürliche Zahl, die ungefähr 2,7 beträgt.

Konvertieren Sie diese Formel TK=1/(ln(RT/RN)/B+1/TN), um die Kelvin-Temperatur zu erhalten, von der 273,15 abgezogen die Grad Celsius ergibt.

Diese Beziehung ist eine empirische Formel. Sie ist nur genau, wenn die Temperatur und der Widerstand innerhalb des wirksamen Bereichs liegen.

**Beispiele**

* :ref:`ar_thermistor` (Arduino-Projekt)
* :ref:`ar_iot_mqtt` (Arduino-Projekt)
* :ref:`py_thermistor` (MicroPython-Projekt)
* :ref:`sh_low_temperature` (Scratch-Projekt)

