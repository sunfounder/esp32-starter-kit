.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_receiver:

IR-Empfänger
===========================

**IR-Empfänger**

.. image:: img/ir_receiver_sl838.png
    :width: 400
    :align: center

* OUT: Signalausgang
* GND: Erdung
* VCC: Stromversorgung, 3,3V~5V

SL838 Infrarot-Empfänger ist eine Komponente, die Infrarotsignale empfängt und in der Lage ist, eigenständig Infrarotstrahlen zu empfangen und Signale auszugeben, die mit dem TTL-Niveau kompatibel sind. Er ähnelt in der Größe einem normalen in Plastik verpackten Transistor und eignet sich für alle Arten von Infrarot-Fernbedienungen und Infrarot-Übertragungen.

Infrarot, oder IR, Kommunikation ist eine beliebte, kostengünstige und leicht zu verwendende drahtlose Kommunikationstechnologie. Infrarotlicht hat eine etwas längere Wellenlänge als sichtbares Licht, daher ist es für das menschliche Auge nicht wahrnehmbar - ideal für drahtlose Kommunikation. Ein gängiges Modulationsschema für die Infrarotkommunikation ist die 38kHz-Modulation.


* Kann für Fernsteuerung verwendet werden
* Breiter Betriebsspannungsbereich: 2,7~5V
* Interner Filter für PCM-Frequenz
* TTL- und CMOS-Kompatibilität
* Starke Störunterdrückungsfähigkeit
* RoHS-konform


**Fernbedienung**

.. image:: img/image186.jpeg
    :width: 400

Dies ist eine Mini-Dünne Infrarot-Fernbedienung mit 21 Funktionstasten und einer Übertragungsreichweite von bis zu 8 Metern, geeignet für die Bedienung einer Vielzahl von Geräten in einem Kinderzimmer.

* Größe: 85x39x6mm
* Fernbedienungsreichweite: 8-10m
* Batterie: 3V Knopfzellen-Lithium-Mangan-Batterie
* Infrarot-Trägerfrequenz: 38KHz
* Oberflächenklebstoffmaterial: 0,125mm PET
* Effektive Lebensdauer: mehr als 20.000 Mal


**Beispiele**

* :ref:`ar_receiver` (Arduino-Projekt)
* :ref:`ar_guess_number` (Arduino-Projekt)
* :ref:`py_receiver` (MicroPython-Projekt)
* :ref:`py_guess_number` (MicroPython-Projekt)

