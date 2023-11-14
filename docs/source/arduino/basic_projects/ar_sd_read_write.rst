.. _ar_sd_write:

7.4 SD-Karten Schreiben und Lesen
====================================
Dieses Projekt demonstriert die Kernfähigkeiten der Verwendung einer SD-Karte mit dem Mikrocontroller ESP32. 
Es zeigt wesentliche Operationen wie das Einbinden der SD-Karte, das Erstellen einer Datei, das Schreiben von Daten in die Datei 
und das Auflisten aller Dateien im Root-Verzeichnis. Diese Operationen bilden die Grundlage vieler Datenprotokollierungs- und Speicheranwendungen 
und machen dieses Projekt zu einem entscheidenden Schritt im Verständnis und in der Nutzung des eingebauten SDMMC-Host-Peripheriegeräts des ESP32.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-


**Betriebsschritte**

#. Bevor Sie das USB-Kabel anschließen, stecken Sie die SD-Karte in den SD-Kartenslot des Erweiterungsboards.

    .. image:: ../../img/insert_sd.png

#. Verbinden Sie ESP32-WROOM-32E mit dem Computer über das USB-Kabel.

    .. image:: ../../img/plugin_esp32.png

#. Wählen Sie den passenden Port und das Board in der Arduino IDE aus und laden Sie den Code auf Ihren ESP32.

    .. note::

        * Öffnen Sie die Datei ``7.4_sd_read_write.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\7.4_sd_read_write``.
        * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/912df4b8-a7b6-43dc-95b5-8206801cc9c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Nachdem der Code erfolgreich hochgeladen wurde, sehen Sie eine Aufforderung, die auf den erfolgreichen Dateischreibvorgang hinweist, zusammen mit einer Liste aller Dateinamen und -größen auf der SD-Karte. Wenn Sie nach dem Öffnen des seriellen Monitors keine Ausgabe sehen, müssen Sie den EN (RST)-Knopf drücken, um den Code erneut auszuführen.

    .. image:: img/sd_write_read.png

    .. note::

        Wenn Sie folgende Informationen sehen.

        .. code-block::

            E (528) vfs_fat_sdmmc: mount_to_vfs failed (0xffffffff).
            Failed to mount SD card

        Überprüfen Sie zuerst, ob Ihre SD-Karte richtig in das Erweiterungsboard eingelegt ist.

        Wenn sie richtig eingelegt ist, könnte es ein Problem mit Ihrer SD-Karte geben. Sie können versuchen, die Metallkontakte mit einem Radiergummi zu reinigen.

        Wenn das Problem weiterhin besteht, wird empfohlen, die SD-Karte zu formatieren. Bitte beachten Sie :ref:`format_sd_card`.


**Wie funktioniert das?**

Der Zweck dieses Projekts ist es, die Verwendung einer SD-Karte mit dem ESP32-Board zu demonstrieren. Das eingebaute SDMMC-Host-Peripheriegerät des ESP32 wird verwendet, um eine Verbindung mit der SD-Karte herzustellen.

Das Projekt beginnt mit der Initialisierung der seriellen Kommunikation und versucht dann, die SD-Karte einzubinden. Wenn das Einbinden der SD-Karte nicht erfolgreich ist, druckt das Programm eine Fehlermeldung und beendet die Setup-Funktion.

Sobald die SD-Karte erfolgreich eingebunden ist, erstellt das Programm eine Datei mit dem Namen "test.txt" im Root-Verzeichnis der SD-Karte. Wenn die Datei erfolgreich im Schreibmodus geöffnet wird, schreibt das Programm eine Zeile Text - "Hello, world!" in die Datei. Das Programm druckt eine Erfolgsmeldung, wenn der Schreibvorgang erfolgreich ist, andernfalls wird eine Fehlermeldung gedruckt.

Nachdem der Schreibvorgang abgeschlossen ist, schließt das Programm die Datei und öffnet dann das Root-Verzeichnis der SD-Karte. Anschließend beginnt es, alle Dateien im Root-Verzeichnis zu durchlaufen und druckt den Dateinamen und die Dateigröße jeder gefundenen Datei.

In der Hauptschleifenfunktion gibt es keine Operationen. Dieses Projekt konzentriert sich auf SD-Kartenoperationen wie das Einbinden der Karte, das Erstellen einer Datei, das Schreiben in eine Datei und das Lesen des Dateiverzeichnisses, die alle in der Setup-Funktion ausgeführt werden.

Dieses Projekt dient als nützliche Einführung in den Umgang mit SD-Karten mit dem ESP32, was in Anwendungen, die Datenprotokollierung oder Speicherung erfordern, entscheidend sein kann.


Hier ist eine Analyse des Codes:

#. Binden Sie die ``SD_MMC``-Bibliothek ein, die benötigt wird, um mit SD-Karten mit dem eingebauten SDMMC-Host-Peripheriegerät des ESP32 zu arbeiten.

    .. code-block:: arduino

        #include "SD_MMC.h"

#. Innerhalb der ``setup()``-Funktion werden die folgenden Aufgaben ausgeführt.

    * **Initialisieren Sie die SD-Karte**

    Initialisieren und binden Sie die SD-Karte ein. Wenn das Einbinden der SD-Karte fehlschlägt, druckt sie "Failed to mount SD card" auf den seriellen Monitor und stoppt die Ausführung.

    .. code-block:: arduino
        
        if(!SD_MMC.begin()) { // Attempt to mount the SD card
            Serial.println("Failed to mount card"); // If mount fails, print to serial and exit setup
            return;
        } 
      
    * **Öffnen Sie die Datei**

    Öffnen Sie eine Datei mit dem Namen ``"test.txt"`` im Root-Verzeichnis der SD 
    -Karte im Schreibmodus. Wenn die Datei nicht geöffnet werden kann, druckt sie "Failed to open file for writing" und kehrt zurück.

    .. code-block:: arduino

        File file = SD_MMC.open("/test.txt", FILE_WRITE); 
        if (!file) {
            Serial.println("Failed to open file for writing"); // Print error message if file failed to open
            return;
        }


    * **Schreiben Sie Daten in die Datei**

    Schreiben Sie den Text "Test file write" in die Datei. 
    Wenn der Schreibvorgang erfolgreich ist, druckt sie "File write successful"; andernfalls druckt sie "File write failed".

    .. code-block:: arduino

        if(file.print("Test file write")) { // Write the message to the file
            Serial.println("File write success"); // If write succeeds, print to serial
        } else {
            Serial.println("File write failed"); // If write fails, print to serial
        } 

    * **Schließen Sie die Datei**

    Schließen Sie die geöffnete Datei. Dadurch wird sichergestellt, dass alle gepufferten Daten in die Datei geschrieben und die Datei ordnungsgemäß geschlossen wird.

    .. code-block:: arduino

        file.close(); // Close the file

    * **Öffnen Sie das Root-Verzeichnis**

    Öffnen Sie das Root-Verzeichnis der SD-Karte. Wenn das Verzeichnis nicht geöffnet werden kann, druckt es "Failed to open directory" und kehrt zurück.

    .. code-block:: arduino

        File root = SD_MMC.open("/"); // Open the root directory of SD card
        if (!root) {
            Serial.println("Failed to open directory"); // Print error message if directory failed to open
            return;
        }

    * **Drucken Sie den Namen und die Größe jeder Datei**
    
    Die Schleife, die mit while (``File file = root.openNextFile()``) beginnt, iteriert über alle Dateien im Root-Verzeichnis und 
    druckt den Namen und die Größe jeder Datei auf den seriellen Monitor.

    .. code-block:: arduino
    
        Serial.println("Files found in root directory:"); // Print the list of files found in the root directory
        while (File file = root.openNextFile()) { // Loop through all the files in the root directory
              Serial.print("  ");
              Serial.print(file.name()); // Print the filename
              Serial.print("\t");
              Serial.println(file.size()); // Print the filesize
              file.close(); // Close the file
        }

#.  Diese ``loop()``-Funktion ist eine leere Schleife und tut in diesem Programm nichts. Allerdings würde in einem typischen Arduino-Programm diese Funktion kontinuierlich überlaufen und den Code in ihr ausführen. In diesem Fall sind jedoch alle erforderlichen Aufgaben in der Setup-Funktion ausgeführt worden, daher wird die Loop-Funktion nicht benötigt.

    .. code-block:: arduino

        void loop() {} // Empty loop function, does nothing
