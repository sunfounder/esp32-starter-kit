.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _install_micropython_on_esp32:

1.3 Installation von MicroPython auf dem ESP32(Wichtig)
========================================================

#. Laden Sie die |link_esp32_micropython_download| von der offiziellen MicroPython-Website herunter und anschließend die neueste Version der Firmware.

    .. image:: img/dowload_micropython_uf2.png

#. Verbinden Sie das ESP32 WROOM 32E mit Ihrem Computer über ein Micro-USB-Kabel.
    
    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Klicken Sie in der unteren rechten Ecke der Thonny IDE, wählen Sie im aufklappenden Menü **"MicroPython(ESP32).COMXX"** aus und dann **"Configure interpreter"**.

    .. image:: img/install_micropython1.png

#. Klicken Sie im neuen Popup-Fenster auf **"Install or Update MicroPython"**.

    .. image:: img/install_micropython2.png

#. Wählen Sie den korrekten Port und die zuvor heruntergeladene Firmware aus und klicken Sie auf **"Install"**.

    .. image:: img/install_micropython3.png

#. Nach einer erfolgreichen Installation können Sie diese Seite schließen.

    .. image:: img/install_micropython4.png

#. Wenn Sie zur Thonny-Startseite zurückkehren, sehen Sie die MicroPython-Version und ESP32-bezogene Hinweise anstelle von roten Fehlermeldungen.

    .. image:: img/install_micropython5.png
