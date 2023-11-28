.. _add_libraries_py:

1.4 Bibliotheken Hochladen (Wichtig)
====================================

In manchen Projekten benötigt man zusätzliche Bibliotheken. Daher laden wir diese zuerst auf den ESP32 hoch, sodass wir den Code später direkt ausführen können.

#. Laden Sie den relevanten Code von dem folgenden Link herunter.


   * :download:`SunFounder ESP32 Starter Kit <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`

#. Verbinden Sie das ESP32 WROOM 32E mit Ihrem Computer über ein Micro-USB-Kabel.
    
    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Öffnen Sie die Thonny IDE und klicken Sie in der unteren rechten Ecke auf den Interpreter **"MicroPython (ESP32).COMXX"**.

    .. image:: img/sec_inter.png

#. Klicken Sie in der oberen Navigationsleiste auf **View** -> **Files**.

    .. image:: img/th_files.png

#. Wechseln Sie den Pfad zum Ordner, in dem Sie zuvor das `Codepaket <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`_ heruntergeladen haben, und gehen Sie dann zum Ordner ``esp32-starter-kit-main\micropython\libs``.

    .. image:: img/th_path.png

#. Wählen Sie alle Dateien oder Ordner im Ordner ``libs/``, klicken Sie mit der rechten Maustaste und wählen Sie **Upload to**, das Hochladen dauert einen Moment.

    .. image:: img/th_upload.png

#. Jetzt sehen Sie die Dateien, die Sie gerade in Ihrem Laufwerk ``MicroPython device`` hochgeladen haben.

    .. image:: img/th_done.png
