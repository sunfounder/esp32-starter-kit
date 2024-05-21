.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_avoid:

Modul zur Hindernisvermeidung
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Stromversorgung, 3,3 ~ 5V DC.
* **GND**: Masse
* **OUT**: Signalpin, normalerweise auf hohem Pegel, und auf niedrigem Pegel, wenn ein Hindernis erkannt wird.

Das IR-Hindernisvermeidungsmodul passt sich gut an die Umgebungslichtverhältnisse an und verfügt über ein Paar Infrarot-Sendungs- und Empfangsröhren.

Die Sendungsröhre strahlt Infrarotfrequenz aus, wenn in der Erkennungsrichtung ein Hindernis auftritt, wird die Infrarotstrahlung von der Empfangsröhre aufgenommen. 
Nach der Verarbeitung durch den Komparatorschaltkreis leuchtet die Anzeige auf und gibt ein Niedrigpegelsignal aus.

Die Erkennungsdistanz kann mittels eines Potentiometers eingestellt werden, der wirksame Distanzbereich liegt bei 2-30cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Beispiel**

* :ref:`ar_ir_obstacle` (Arduino-Projekt)
* :ref:`py_ir_obstacle` (MicroPython-Projekt)
* :ref:`sh_shooting` (Scratch-Projekt)
* :ref:`sh_tap_tile` (Scratch-Projekt)
