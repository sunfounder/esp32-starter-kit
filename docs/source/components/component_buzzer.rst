.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_buzzer:

Summer
=======

.. image:: img/buzzer.png
    :width: 600

Als eine Art elektronischer Summer mit integrierter Struktur werden Summer, die mit Gleichstrom betrieben werden, häufig in Computern, Druckern, Kopierern, Alarmen, elektronischen Spielzeugen, automobilen Elektronikgeräten, Telefonen, Zeitgebern und anderen elektronischen Produkten oder Sprachgeräten eingesetzt.

Summer können in aktive und passive Summer unterteilt werden (siehe folgendes Bild). Wenn Sie den Summer so drehen, dass seine Pins nach oben zeigen, ist der Summer mit einer grünen Leiterplatte ein passiver Summer, während der mit schwarzem Klebeband umschlossene ein aktiver Summer ist.

Der Unterschied zwischen einem aktiven und einem passiven Summer:

Ein aktiver Summer verfügt über eine eingebaute Oszillationsquelle und erzeugt daher beim Anlegen von Strom einen Ton. Ein passiver Summer hat jedoch keine solche Quelle, daher gibt er keinen Ton von sich, wenn Gleichstromsignale verwendet werden; stattdessen müssen Sie ihn mit Rechteckwellen antreiben, deren Frequenz zwischen 2K und 5K liegt. Der aktive Summer ist oft teurer als der passive, aufgrund der mehrfach eingebauten Oszillationskreise.

Folgend ist das elektrische Symbol eines Summers dargestellt. Er hat zwei Pins mit positiven und negativen Polen. Ein + auf der Oberfläche zeigt den Anodenpol und der andere ist der Kathodenpol.

.. image:: img/buzzer_symbol.png
    :width: 150

Sie können die Pins des Summers überprüfen, der längere ist die Anode und der kürzere die Kathode. Bitte verwechseln Sie diese nicht beim Anschließen, da sonst der Summer keinen Ton erzeugt.

`Summer - Wikipedia <https://en.wikipedia.org/wiki/Buzzer>`_

**Beispiel**

* :ref:`ar_ac_buz` (Arduino-Projekt)
* :ref:`ar_pa_buz` (Arduino-Projekt)
* :ref:`ar_reversing_aid` (Arduino-Projekt)
* :ref:`py_pa_buz` (MicroPython-Projekt)
* :ref:`py_ac_buz` (MicroPython-Projekt)
* :ref:`py_reversing_aid` (MicroPython-Projekt)

