.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_motor:

Gleichstrommotor
===================

.. image:: img/image114.jpeg
    :align: center

Hier handelt es sich um einen 3V-Gleichstrommotor. Wenn Sie an jeden der beiden Anschlüsse einen hohen und einen niedrigen Pegel anlegen, wird er sich drehen.

* **Länge**: 25mm
* **Durchmesser**: 21mm
* **Wellendurchmesser**: 2mm
* **Wellenlänge**: 8mm
* **Spannung**: 3-6V
* **Strom**: 0.35-0.4A
* **Geschwindigkeit bei 3V**: 19000 U/min (Umdrehungen pro Minute)
* **Gewicht**: Ungefähr 14g (für eine Einheit)

Ein Gleichstrommotor (DC-Motor) ist ein kontinuierlicher Aktuator, der elektrische Energie in mechanische Energie umwandelt. DC-Motoren ermöglichen es, dass rotierende Pumpen, Ventilatoren, Kompressoren, Impeller und andere Geräte durch kontinuierliche Drehbewegungen funktionieren.

Ein DC-Motor besteht aus zwei Teilen: dem feststehenden Teil des Motors, dem **Stator**, und dem internen Teil des Motors, dem **Rotor** (oder **Anker** eines Gleichstrommotors), der sich dreht, um Bewegung zu erzeugen.
Der Schlüssel zur Bewegungserzeugung ist die Positionierung des Ankers innerhalb des Magnetfelds des Permanentmagneten (dessen Feld sich vom Nordpol zum Südpol erstreckt). Die Wechselwirkung des Magnetfelds und der bewegten geladenen Partikel (der stromführende Draht erzeugt das Magnetfeld) erzeugt das Drehmoment, das den Anker dreht.

.. image:: img/motor_sche.png
    :align: center

Der Strom fließt vom positiven Pol der Batterie durch den Schaltkreis, über die Kupferbürsten zum Kommutator und dann zum Anker.
Durch die beiden Lücken im Kommutator kehrt sich dieser Fluss jedoch bei jeder vollständigen Drehung zur Hälfte um.

Diese kontinuierliche Umkehrung wandelt die Gleichstromleistung der Batterie im Wesentlichen in Wechselstrom um, wodurch der Anker das Drehmoment in der richtigen Richtung zur richtigen Zeit erfährt, um die Drehung aufrechtzuerhalten.

.. image:: img/motor_rotate.gif
    :align: center

**Beispiele**

* :ref:`ar_motor` (Arduino-Projekt)
* :ref:`py_motor` (MicroPython-Projekt)
* :ref:`sh_rotating_fan` (Scratch-Projekt)
