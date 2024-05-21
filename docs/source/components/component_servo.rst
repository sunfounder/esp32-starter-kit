.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_servo:

Servo
===========

.. image:: img/servo.png
    :align: center

Ein Servomotor besteht im Allgemeinen aus folgenden Teilen: Gehäuse, Welle, Getriebesystem, Potentiometer, Gleichstrommotor und integrierte Platine.

Die Funktionsweise ist wie folgt: Der Mikrocontroller sendet PWM-Signale an den Servo. Die integrierte Platine im Servo empfängt die Signale über den Signalpin und steuert den internen Motor. Daraufhin treibt der Motor das Getriebesystem an und bewegt nach Verlangsamung die Welle. Die Welle und das Potentiometer des Servos sind miteinander verbunden. Wenn die Welle sich dreht, treibt sie das Potentiometer an, sodass das Potentiometer ein Spannungssignal an die Platine sendet. Die Platine bestimmt dann basierend auf der aktuellen Position die Drehrichtung und -geschwindigkeit, um genau in der definierten Position zu stoppen und dort zu verharren.

.. image:: img/servo_internal.png
    :align: center

Der Winkel wird durch die Dauer eines Impulses bestimmt, der an das Steuerkabel angelegt wird. Dies wird als Pulsbreitenmodulation bezeichnet. Der Servo erwartet alle 20 ms einen Impuls. Die Länge des Impulses bestimmt, wie weit der Motor sich dreht. Ein 1,5-ms-Impuls beispielsweise lässt den Motor in die 90-Grad-Position (Neutrale Position) drehen.
Wenn ein Impuls, der kürzer als 1,5 ms ist, an einen Servo gesendet wird, dreht sich der Servo in eine Position und hält seine Ausgangswelle einige Grad gegen den Uhrzeigersinn von der neutralen Position. Wenn der Impuls länger als 1,5 ms ist, tritt das Gegenteil ein. Die minimale und maximale Impulsbreite, die den Servo dazu bringt, sich in eine gültige Position zu drehen, sind abhängig vom jeweiligen Servo. Allgemein wird die minimale Impulsbreite etwa 0,5 ms und die maximale etwa 2,5 ms betragen.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Beispiele**

* :ref:`ar_servo` (Arduino-Projekt)
* :ref:`py_servo` (MicroPython-Projekt)

