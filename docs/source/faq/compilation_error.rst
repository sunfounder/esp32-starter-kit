Einige Projektcodes lassen sich nicht kompilieren?
==============================================================

Q1: ``'ledcAttach' was not declared in this scope``
-----------------------------------------------------

Beim Verwenden von LEDs, RGB-LEDs oder passiven Summern benötigen Sie das |link_ledc| Peripheriegerät des ESP32-Boards, um PWM-Signale zu erzeugen. Das ESP32-Board wurde jedoch kürzlich auf Version 3.0 aktualisiert, was Änderungen an den Funktionsnamen und der Nutzung innerhalb des |link_ledc| Peripheriegeräts verursacht hat.

Daher haben wir unseren Code entsprechend aktualisiert. Wenn Sie beim Kompilieren auf ledc-bezogene Probleme stoßen, aktualisieren Sie bitte Ihr ESP32-Board auf Version 3.0 oder höher.

.. image:: img/version_3.0.3.png


Q2: Fehler in Bluetooth- und IR-Empfänger-bezogenen Projekten nach dem Upgrade des ESP32 auf Version 3.0?
-----------------------------------------------------------------------------------------------------------------

Das ESP32-Board wurde auf Version 3.0 aktualisiert, aber die in Bluetooth- und IR-Empfänger-bezogenen Projekten verwendeten Bibliotheken sind noch nicht mit Version 3.0 kompatibel.

Um diese Projekte auszuführen, wird empfohlen, die ESP32-Version vorübergehend auf Version 2.0 herunterzustufen, speziell auf Version 2.0.17.

Wir werden die Updates dieser Bibliotheken kontinuierlich überwachen und sobald sie mit Version 3.0 des ESP32 kompatibel sind, werden wir unseren Code und unsere Dokumentation umgehend aktualisieren.

.. image:: img/version_2.0.17.png
