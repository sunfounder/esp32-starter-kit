.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _format_sd_card:

Wie formatiert man eine SD-Karte?
====================================

Die Schritte, um sicherzustellen, dass Ihre SD-Karte korrekt formatiert wird, können je nach Betriebssystem variieren. Hier sind einfache Anweisungen, wie man eine SD-Karte unter Windows, MacOS und Linux formatiert:

**Windows**

   #. Legen Sie Ihre SD-Karte in den Computer ein, öffnen Sie dann "Mein Computer" oder "Dieser PC". Klicken Sie mit der rechten Maustaste auf Ihre SD-Karte und wählen Sie "Formatieren".

        .. image:: img/sd_format_win1.png

   #. Wählen Sie im Dropdown-Menü des Dateisystems das gewünschte Dateisystem aus (normalerweise wählen Sie FAT32, oder für SD-Karten größer als 32 GB, müssen Sie möglicherweise exFAT wählen). Markieren Sie "Schnellformatierung" und klicken Sie dann auf "Start".

        .. image:: img/sd_format_win2.png

**MacOS**
   
   #. Legen Sie Ihre SD-Karte in den Computer ein. Öffnen Sie die Anwendung "Festplattendienstprogramm" (zu finden im Ordner "Dienstprogramme").

        .. image:: img/sd_format_mac1.png
    
   #. Wählen Sie Ihre SD-Karte aus der Liste links und klicken Sie dann auf "Löschen".

        .. image:: img/sd_format_mac2.png

   #. Wählen Sie aus dem Dropdown-Menü Format Ihr gewünschtes Dateisystem aus (normalerweise wählen Sie MS-DOS (FAT) für FAT32, oder ExFAT für SD-Karten größer als 32 GB) und klicken Sie dann auf "Löschen".

        .. image:: img/sd_format_mac3.png

   #. Warten Sie schließlich, bis die Formatierung abgeschlossen ist.

        .. image:: img/sd_format_mac3.png

**Linux**

   * Fügen Sie zuerst Ihre SD-Karte ein und öffnen Sie dann ein Terminal.
   * Geben Sie ``lsblk`` ein und finden Sie den Namen Ihrer SD-Karte in der Geräteliste (z.B. könnte es ``sdb`` sein).
   * Verwenden Sie den Befehl ``umount``, um die SD-Karte auszuhängen, wie z.B. ``sudo umount /dev/sdb*``.
   * Verwenden Sie den Befehl ``mkfs``, um die SD-Karte zu formatieren. Zum Beispiel wird ``sudo mkfs.vfat /dev/sdb1`` die SD-Karte mit einem FAT32-Dateisystem formatieren (für SD-Karten größer als 32 GB, müssen Sie möglicherweise ``mkfs.exfat`` verwenden).

Bevor Sie Ihre SD-Karte formatieren, stellen Sie sicher, dass Sie alle wichtigen Daten auf der SD-Karte sichern, da der Formatierungsvorgang alle Dateien auf der SD-Karte löschen wird.
