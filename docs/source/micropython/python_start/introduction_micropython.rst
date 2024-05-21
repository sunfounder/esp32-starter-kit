.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

1.1 Einführung in MicroPython
======================================

MicroPython ist eine Softwareimplementierung einer Programmiersprache, die weitgehend mit Python 3 kompatibel ist, in C geschrieben und optimiert, um auf einem Mikrocontroller zu laufen.[3][4]

MicroPython besteht aus einem Python-Compiler zu Bytecode und einem Laufzeitinterpreter dieses Bytecodes. Dem Benutzer wird eine interaktive Aufforderung (das REPL) präsentiert, um unterstützte Befehle sofort auszuführen. Enthalten ist eine Auswahl an Kern-Python-Bibliotheken; MicroPython umfasst Module, die dem Programmierer Zugriff auf hardwarenahe Funktionen ermöglichen.

* Referenz: `MicroPython - Wikipedia <https://en.wikipedia.org/wiki/MicroPython>`_

Hier beginnt die Geschichte
--------------------------------

2013 änderte sich alles, als Damien George eine Crowdfunding-Kampagne (Kickstarter) startete.

Damien war ein Student an der Universität Cambridge und ein begeisterter Robotik-Programmierer. Er wollte die Welt von Python von einer Gigabyte-Maschine auf ein Kilobyte reduzieren. Seine Kickstarter-Kampagne sollte seine Entwicklung unterstützen, während er seinen Proof of Concept in eine fertige Implementierung umwandelte.

MicroPython wird von einer vielfältigen Pythonista-Community unterstützt, die großes Interesse am Erfolg des Projekts hat.

Neben dem Testen und Unterstützen der Codebasis lieferten die Entwickler Tutorials, Codebibliotheken und Hardware-Portierungen, sodass sich Damien auf andere Aspekte des Projekts konzentrieren konnte.

* Referenz: `realpython <https://realpython.com/micropython/>`_

Warum MicroPython？
---------------------

Obwohl die ursprüngliche Kickstarter-Kampagne MicroPython als Entwicklungsboard "pyboard" mit STM32F4 veröffentlichte, unterstützt MicroPython viele auf ARM basierende Produktarchitekturen. Die wichtigsten unterstützten Ports sind ARM Cortex-M (viele STM32-Boards, TI CC3200/WiPy, Teensy-Boards, Nordic nRF-Serie, SAMD21 und SAMD51), ESP8266, ESP32, 16-Bit-PIC, Unix, Windows, Zephyr und JavaScript.
Zweitens ermöglicht MicroPython schnelles Feedback. Dies liegt daran, dass Sie REPL verwenden können, um Befehle interaktiv einzugeben und Antworten zu erhalten. Sie können sogar Code anpassen und sofort ausführen, anstatt den Zyklus Code-Kompilieren-Upload-Ausführen zu durchlaufen.

Während Python dieselben Vorteile bietet, sind einige Mikrocontroller-Boards wie das ESP32 klein, einfach und haben zu wenig Speicher, um überhaupt die Python-Sprache auszuführen. Deshalb hat sich MicroPython entwickelt, wobei die Hauptmerkmale von Python beibehalten und eine Reihe neuer Funktionen hinzugefügt wurden, um mit diesen Mikrocontroller-Boards zu arbeiten.

Als Nächstes lernen Sie, MicroPython auf das ESP32 zu installieren.

* Referenz: `MicroPython - Wikipedia <https://en.wikipedia.org/wiki/MicroPython>`_
* Referenz: `realpython <https://realpython.com/micropython/>`_

