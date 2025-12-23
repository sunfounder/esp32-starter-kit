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

.. #. Laden Sie die |link_esp32_micropython_download| von der offiziellen MicroPython-Website herunter und anschließend die neueste Version der Firmware.

..     .. image:: img/dowload_micropython_uf2.png

#. Verbinde das ESP32 board mit deinem Computer über ein USB-Kabel.

   .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Klicke in der rechten unteren Ecke der Thonny-IDE und wähle **„MicroPython(ESP32).xxxCOMXX“** aus dem Dropdown-Menü. Danach wähle **„Interpreter konfigurieren“**.

   .. note::

      Wenn außer „Local Python 3“ keine weiteren Optionen angezeigt werden, wurde dein ESP32-Board möglicherweise nicht vom Computer erkannt.  
      In diesem Fall musst du eventuell den :ref:`install_driver` installieren.

   .. image:: img/install_micropython1.png

#. Klicke im neuen Fenster auf **„MicroPython installieren oder aktualisieren“**.

   .. image:: img/install_micropython2.png

#. Wähle den richtigen Port, die MicroPython-Familie, die Variante und das Board aus und klicke dann auf **„Installieren“**.

   * :ref:`download_mode`

   .. image:: img/install_micropython3.png

#. Nach erfolgreicher Installation kehrst du zur Thonny-Startseite zurück.  
   Dort siehst du nun die MicroPython-Version und ESP32-bezogene Ausgaben anstelle roter Fehlermeldungen.

   .. image:: img/install_micropython5.png
