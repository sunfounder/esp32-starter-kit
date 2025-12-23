Einige Projektcodes lassen sich nicht kompilieren?
==============================================================

Q1: ``'ledcAttach' was not declared in this scope``
-----------------------------------------------------

Beim Verwenden von LEDs, RGB-LEDs oder passiven Summern benötigen Sie das |link_ledc| Peripheriegerät des ESP32-Platines, um PWM-Signale zu erzeugen. Das ESP32-Platine wurde jedoch kürzlich auf Version 3.0 aktualisiert, was Änderungen an den Funktionsnamen und der Nutzung innerhalb des |link_ledc| Peripheriegeräts verursacht hat.

Daher haben wir unseren Code entsprechend aktualisiert. Wenn Sie beim Kompilieren auf ledc-bezogene Probleme stoßen, aktualisieren Sie bitte Ihr ESP32-Platine auf Version 3.0 oder höher.

.. image:: img/version_3.0.3.png


Q2: Fehler in Bluetooth- und IR-Empfänger-bezogenen Projekten nach dem Upgrade des ESP32 auf Version 3.0?
-----------------------------------------------------------------------------------------------------------------

Das ESP32-Platine wurde auf Version 3.0 aktualisiert, aber die in Bluetooth- und IR-Empfänger-bezogenen Projekten verwendeten Bibliotheken sind noch nicht mit Version 3.0 kompatibel.

Um diese Projekte auszuführen, wird empfohlen, die ESP32-Version vorübergehend auf Version 2.0 herunterzustufen, speziell auf Version 2.0.17.

Wir werden die Updates dieser Bibliotheken kontinuierlich überwachen und sobald sie mit Version 3.0 des ESP32 kompatibel sind, werden wir unseren Code und unsere Dokumentation umgehend aktualisieren.

.. image:: img/version_2.0.17.png

.. _download_mode:

Q3: „Wrong boot mode detected (0x13)“-Fehler beim Flashen der ESP32-Firmware?
--------------------------------------------------------------------------------------

Beim Flashen der ESP32-Firmware mit Thonny oder beim Hochladen von Code auf den ESP32 über die Arduino IDE kann der folgende Fehler auftreten:

.. code-block:: text

    A fatal error occurred: Failed to connect to ESP32: Wrong boot mode detected (0x13)! The chip needs to be in download mode.

Dies weist nicht auf ein Hardwareproblem mit Ihrem ESP32-Platine hin.  
Dieses Problem kann auftreten, wenn der Computer den ESP32 während des Flasch-Vorgangs nicht automatisch in den **Download-Modus** versetzt.

**Ursache**

Der ESP32 muss sich im **Download-Modus** befinden, um die Firmware erfolgreich flashen zu können.  
In einigen Umgebungen funktioniert der automatische Download-Trigger möglicherweise aufgrund von Timing-Unterschieden in USB-Treibern, dem Verhalten des USB-Anschlusses oder der Art und Weise, wie das Betriebssystem DTR/RTS-Signale verarbeitet, nicht wie erwartet.  
Infolgedessen bleibt der ESP32 im normalen Ausführungsmodus, was das Flashen fehlschlagen lässt.

**Lösung**

Wenn Sie auf diesen Fehler stoßen, können Sie den Download-Modus vor dem Flashen manuell starten:

* **Verwendung von Tasten (BOOT + EN/RST):**  
  Halten Sie die ``BOOT``-Taste gedrückt, drücken Sie kurz auf ``EN`` (oder ``RST``) und lassen Sie dann die ``BOOT``-Taste los.  
  Dies zwingt den ESP32 in den Download-Modus.

* **Verwendung eines Jumper-Kabels:**  
  Verbinden Sie ``GPIO0`` mit ``GND`` mit einem Jumper-Kabel und drücken Sie dann auf ``EN`` (oder schalten Sie das Board aus und wieder ein), um in den Download-Modus zu gelangen.  
  Entfernen Sie nach dem Flashen das Jumper-Kabel, um den normalen Start zu ermöglichen.

**Hinweise**

* Stellen Sie sicher, dass Sie ein geeignetes **Datenkabel** verwenden (kein reines Ladekabel).  
* Wenn das Problem weiterhin besteht, versuchen Sie, den USB-Anschluss zu wechseln, den USB-zu-Serial-Treiber zu aktualisieren oder die Baudrate zu verringern (z. B. auf ``115200``).  
