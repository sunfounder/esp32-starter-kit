.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_ws2812:

WS2812 RGB 8 LEDs Leiste
============================

.. image:: img/ws2812b.png

Der WS2812 RGB 8 LEDs Strip besteht aus 8 RGB-LEDs. 
Es wird nur ein Pin benötigt, um alle LEDs zu steuern. Jede RGB-LED hat einen WS2812-Chip, der unabhängig gesteuert werden kann. 
Er kann eine 256-stufige Helligkeitsanzeige und eine vollständige Echtfarbanzeige von 16.777.216 Farben realisieren. 
Gleichzeitig enthält das Pixel einen intelligenten digitalen Schnittstellen-Datenlatch-Signalformungs-Verstärker-Treiberschaltkreis, 
und eine Signalformungsschaltung ist eingebaut, um die Farbhöhe des Pixelpunktlichts effektiv zu gewährleisten Konsistent.

Es ist flexibel, kann nach Belieben angedockt, gebogen und geschnitten werden, und die Rückseite ist mit Klebeband ausgestattet, das auf der unebenen Oberfläche nach Belieben befestigt werden kann, und kann in einem engen Raum installiert werden.

**Merkmale**

* Arbeitsspannung: DC5V
* IC: Ein IC steuert eine RGB-LED
* Verbrauch: 0.3w jede LED
* Arbeitstemperatur: -15-50
* Farbe: Vollfarbe RGB
* RGB-Typ：5050RGB（Built-in IC WS2812B）
* Dicke des Lichtstreifens: 2mm
* Jede LED kann einzeln gesteuert werden

**WS2812B Einführung**

* `WS2812B Datenblatt <https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf>`_

WS2812B ist eine intelligente Steuer-LED-Lichtquelle, bei der die Steuerschaltung und der RGB-Chip in einem
einem Paket von 5050 Komponenten integriert sind. Intern sind ein intelligenter digitaler Port-Datenspeicher und ein Signalumformungs-Verstärker
fikationsschaltung. Außerdem sind ein interner Präzisionsoszillator und ein programmierbarer 12V-Spannungskonstanthalter enthalten.
e-nt Steuerteil, effektiv sicherzustellen, die Pixel Punkt Licht Farbhöhe konsistent.

Das Datenübertragungsprotokoll verwendet den einfachen NZR-Kommunikationsmodus. Nach dem Einschalt-Reset des Pixels empfängt der DIN
Port die Daten vom Controller, das erste Pixel sammelt die ersten 24-Bit-Daten und sendet sie an den internen Daten-Latch,
die anderen Daten, die durch den internen Signalumformungs-Verstärkungsschaltkreis umgestaltet werden, werden über den DO-Port an das nächste Kaskadenpixel gesendet.
Pixel durch den DO-Port. Nach der Übertragung für jedes Pixel, das Signal zu reduzieren 24bit. Pixel verabschieden Auto resha
Übertragungstechnik, so dass die Pixel-Kaskade Zahl ist nicht begrenzt die Signalübertragung, nur abhängig
von der Geschwindigkeit der Signalübertragung ab.

LED mit niedriger Betriebsspannung, Umweltschutz und Energieeinsparung, hohe Helligkeit, großer Streuwinkel
e ist groß, gute Konsistenz, geringe Leistung, lange Lebensdauer und andere Vorteile. Der in die LED integrierte Steuerchip
oben immer mehr einfache Schaltung, kleines Volumen, bequeme Installation.



**Beispiel**

* :ref:`ar_rgb_strip` (Arduino-Projekt)
* :ref:`ar_flowing_light` (Arduino-Projekt)
* :ref:`py_rgb_strip` (MicroPython-Projekt)
* :ref:`py_flowing_light` (MicroPython-Projekt)
* :ref:`py_color_gradient` (MicroPython-Projekt)
