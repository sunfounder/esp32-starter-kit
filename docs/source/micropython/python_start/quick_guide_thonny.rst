1.5 Schnelle Anleitung zu Thonny
==================================

.. _open_run_code_py:

Code Direkt Öffnen und Ausführen
---------------------------------------------

Der Codeabschnitt in den Projekten zeigt genau an, welcher Code verwendet wird. Doppelklicken Sie daher auf die Datei ``.py`` mit der Seriennummer im Pfad ``esp32-starter-kit-main\micropython\codes\``, um sie zu öffnen.

Zuvor müssen Sie jedoch das Paket herunterladen und die Bibliotheken hochladen, wie in :ref:`add_libraries_py` beschrieben.

1. Code öffnen.

    Zum Beispiel ``1.1_hello_led.py``.

    Wenn Sie darauf doppelklicken, öffnet sich ein neues Fenster auf der rechten Seite. Sie können gleichzeitig mehr als einen Code öffnen.

    .. image:: img/quick_guide1.png

2. Stecken Sie den esp32 mit einem Mikro-USB-Kabel in Ihren Computer.

    .. image:: ../../img/plugin_esp32.png

3. Richtigen Interpreter auswählen

    Wählen Sie den Interpreter "MicroPython (ESP32).COMxx".

    .. image:: img/sec_inter.png

4. Den Code ausführen

    Um das Skript auszuführen, klicken Sie auf die Schaltfläche **Run current script** oder drücken Sie F5.

    .. image:: img/quick_guide2.png

    Wenn der Code Informationen enthält, die gedruckt werden müssen, erscheinen sie in der Shell; ansonsten erscheint nur die folgende Information.

    Klicken Sie auf **View** -> **Edit**, um das Shell-Fenster zu öffnen, wenn es in Ihrem Thonny nicht erscheint.

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; ESP32 module with ESP32

            Type "help()" for more information.

            >>> %Run -c $EDITOR_CONTENT

    * Die erste Zeile zeigt die Version von MicroPython, das Datum und Informationen zu Ihrem Gerät.
    * Die zweite Zeile fordert Sie auf, "help()" einzugeben, um Hilfe zu erhalten.
    * Die dritte Zeile ist ein Befehl von Thonny, der den MicroPython-Interpreter auf Ihrem Pico W anweist, den Inhalt des Skriptbereichs - "EDITOR_CONTENT" - auszuführen.
    * Wenn nach der dritten Zeile eine Nachricht erscheint, handelt es sich normalerweise um eine Nachricht, die Sie MicroPython ausdrucken lassen, oder um eine Fehlermeldung für den Code.


5. Ausführung stoppen

    .. image:: img/quick_guide3.png

    Um den laufenden Code zu stoppen, klicken Sie auf die Schaltfläche **Stop/Restart backend**. Der Befehl **%RUN -c $EDITOR_CONTENT** verschwindet nach dem Stoppen.

6. Speichern oder Speichern unter

    Sie können Änderungen, die Sie am geöffneten Beispiel vorgenommen haben, speichern, indem Sie **Ctrl+S** drücken oder auf die Schaltfläche **Save** in Thonny klicken.

    Der Code kann als separate Datei innerhalb des **MicroPython drive(ESP32)** gespeichert werden, indem Sie auf **File** -> **Save As** klicken.

    .. image:: img/quick_guide4.png

    Wählen Sie **MicroPython drive**.

    .. image:: img/quick_guide5.png
        
    Klicken Sie dann auf **OK**, nachdem Sie den Dateinamen und die Erweiterung **.py** eingegeben haben. Auf dem MicroPython-Laufwerk sehen Sie Ihre gespeicherte Datei.

    .. image:: img/quick_guide6.png

    .. note::
        Unabhängig davon, welchen Namen Sie Ihrem Code geben, ist es am besten, zu beschreiben, um welche Art von Code es sich handelt, und ihm keinen bedeutungslosen Namen wie ``abc.py`` zu geben.
        Wenn Sie den Code als ``main.py`` speichern, wird er automatisch ausgeführt, wenn der Strom eingeschaltet wird.


Datei Erstellen und Ausführen
-----------------------------

Der Code wird direkt im Codeabschnitt angezeigt. Sie können ihn in Thonny kopieren und wie folgt ausführen.

1. Eine neue Datei erstellen

    Öffnen Sie die Thonny IDE, klicken Sie auf die Schaltfläche **New**, um eine neue leere Datei zu erstellen.

    .. image:: img/quick_guide7.png

2. Code kopieren

    Kopieren Sie den Code aus dem Projekt in die Thonny IDE.

    .. image:: img/quick_guide8.png

3. Stecken Sie den esp32 mit einem Mikro-USB-Kabel in Ihren Computer.

    .. image:: ../../img/plugin_esp32.png

4. Richtigen Interpreter auswählen

    Wählen Sie in der unteren rechten Ecke den Interpreter "MicroPython (ESP32).COMxx".

    .. image:: img/sec_inter.png

5. Den Code ausführen

    Sie müssen auf **Run Current Script** klicken oder einfach „F5“ drücken, um es auszuführen.

    .. image:: img/quick_guide9.png

    Wenn der Code Informationen enthält, die gedruckt werden müssen, erscheinen sie in der Shell; ansonsten erscheint nur die folgende Information.

    Klicken Sie auf **View** -> **Edit**, um das Shell-Fenster zu öffnen, wenn es in Ihrem Thonny nicht erscheint.

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; ESP32 module with ESP32

            Type "help()" for more information.

            >>> %Run -c $EDITOR_CONTENT

    * Die erste Zeile zeigt die Version von MicroPython, das Datum und Informationen zu Ihrem Gerät.
    * Die zweite Zeile fordert Sie auf, "help()" einzugeben, um Hilfe zu erhalten.
    * Die dritte Zeile ist ein Befehl von Thonny, der den MicroPython-Interpreter auf Ihrem Pico W anweist, den Inhalt des Skriptbereichs - "EDITOR_CONTENT" - auszuführen.
    * Wenn nach der dritten Zeile eine Nachricht erscheint, handelt es sich normalerweise um eine Nachricht, die Sie MicroPython ausdrucken lassen, oder um eine Fehlermeldung für den Code.


6. Ausführung stoppen

    .. image:: img/quick_guide3.png

    Um den laufenden Code zu stoppen, klicken Sie auf die Schaltfläche **Stop/Restart backend**. Der Befehl **%RUN -c $EDITOR_CONTENT** verschwindet nach dem Stoppen.

7. Speichern oder Speichern unter

    Sie können den Code speichern, indem Sie **Ctrl+S** drücken oder auf die Schaltfläche **Save** in Thonny klicken. Im aufpoppenden Fenster wählen Sie den Ort, an dem Sie die Datei speichern möchten.

    .. image:: img/quick_guide5.png
        
    Klicken Sie dann nach Eingabe des Dateinamens und der Erweiterung **.py** auf **OK** oder **Save**.

    .. image:: img/quick_guide6.png

    .. note::
        Unabhängig davon, welchen Namen Sie Ihrem Code geben, ist es am besten, zu beschreiben, um welche Art von Code es sich handelt, und ihm keinen bedeutungslosen Namen wie ``abc.py`` zu geben.
        Wenn Sie den Code als ``main.py`` speichern, wird er automatisch ausgeführt, wenn der Strom eingeschaltet wird.

8. Datei öffnen

    Hier sind zwei Möglichkeiten, eine gespeicherte Code-Datei zu öffnen.

    * Die erste Methode besteht darin, auf das Öffnen-Symbol in der Thonny-Toolbar zu klicken, genau wie beim Speichern eines Programms. Sie werden gefragt, ob Sie es von **this computer** oder **MicroPython device** öffnen möchten, zum Beispiel klicken Sie auf **MicroPython device** und Sie sehen eine Liste aller Programme, die Sie auf dem ESP32 gespeichert haben.
    * Die zweite besteht darin, die Dateivorschau direkt zu öffnen, indem Sie auf **View** -> **Files** klicken und dann auf die entsprechende ``.py``-Datei doppelklicken, um sie zu öffnen.

