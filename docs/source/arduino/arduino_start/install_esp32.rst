1.3 ESP32-Board installieren (Wichtig)
===========================================

Um den ESP32-Mikrocontroller zu programmieren, müssen wir das ESP32-Board-Paket in der Arduino-IDE installieren. Befolgen Sie die folgende Schritt-für-Schritt-Anleitung:

**ESP32-Board installieren**

#. Öffnen Sie die Arduino-IDE. Gehen Sie zu **File** und wählen Sie **Preferences** aus dem Dropdown-Menü.

    .. image:: img/install_esp321.png

#. In dem Einstellungen-Fenster finden Sie das Feld **Additional Board Manager URLs**. Klicken Sie darauf, um das Textfeld zu aktivieren.

    .. image:: img/install_esp322.png

#. Fügen Sie die folgende URL in das Feld **Additional Board Manager URLs** ein: https://espressif.github.io/arduino-esp32/package_esp32_index.json. Diese URL verweist auf die Paketindexdatei für die ESP32-Boards. Klicken Sie auf die Schaltfläche **OK**, um die Änderungen zu speichern.

    .. image:: img/install_esp323.png

#. Geben Sie im **Boards Manager**-Fenster **ESP32** in die Suchleiste ein. Klicken Sie auf die Schaltfläche **Install**, um den Installationsprozess zu starten. Dadurch wird das ESP32-Board-Paket heruntergeladen und installiert.

    .. image:: img/install_esp324.png

#. Herzlichen Glückwunsch! Sie haben das ESP32-Board-Paket erfolgreich in der Arduino-IDE installiert. 


**Laden Sie den Code hoch**

#. Verbinden Sie jetzt das ESP32 WROOM 32E mit Ihrem Computer über ein Micro-USB-Kabel.

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Wählen Sie dann das richtige Board, ESP32 Dev Module, aus, indem Sie auf Werkzeuge -> Board -> esp32 klicken.

    .. image:: img/install_esp325.png

#. Wenn Ihr ESP32 mit dem Computer verbunden ist, können Sie den richtigen Port auswählen, indem Sie auf **Tools** -> **Port** klicken.

    .. image:: img/install_esp326.png

#. Zusätzlich wurde in Arduino 2.0 eine neue Möglichkeit eingeführt, das Board und den Port schnell auszuwählen. Für ESP32 wird es normalerweise nicht automatisch erkannt, daher müssen Sie auf **Select other board and port** klicken.

    .. image:: img/install_esp327.png

#. Geben Sie im Suchfeld **ESP32 Dev Module** ein und wählen Sie es aus, wenn es angezeigt wird. Wählen Sie dann den richtigen Port und klicken Sie auf **OK**.

    .. image:: img/install_esp328.png

#. Danach können Sie es über dieses Schnellzugriffsfenster auswählen. Beachten Sie, dass es bei der späteren Verwendung Zeiten geben kann, in denen ESP32 im Schnellzugriffsfenster nicht verfügbar ist und Sie die oben genannten beiden Schritte wiederholen müssen.

    .. image:: img/install_esp329.png

#. Beide Methoden ermöglichen Ihnen die Auswahl des richtigen Boards und Ports. Wählen Sie diejenige, die Ihnen am besten gefällt. Jetzt ist alles bereit, um den Code auf den ESP32 hochzuladen.