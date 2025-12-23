.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _install_driver:

Manuelle Treiberinstallation für ESP32
======================================

Wenn Sie Ihr ESP32-Platine per USB an den Computer angeschlossen haben, aber **kein Port** in der Arduino-IDE oder Thonny-IDE angezeigt wird (oder nur **COM1**), erkennt Ihr Computer das Board wahrscheinlich nicht.  
In diesem Fall müssen Sie den USB-Treiber manuell installieren.

Wir bieten zwei Arten von ESP32-Platines an, die sich nur durch den USB-zu-Seriell-Chip unterscheiden:

- **CP2102**  
- **CH340**

Funktionsmäßig sind sie identisch – der einzige Unterschied liegt im benötigten USB-Treiber.

.. image:: img/driver_ch340_cp2102.jpg
   :width: 400
   :align: center

* Wenn Ihr ESP32-Platine den **CH340**-USB-Chip verwendet, folgen Sie dieser Anleitung zur Treiberinstallation:

  * :ref:`driver_ch340`

* Wenn Ihr ESP32-Platine den **CP2102**-USB-Chip verwendet, folgen Sie dieser Anleitung:

  * :ref:`driver_cp2102`


.. _driver_ch340:

So installieren Sie den CH340-Treiber
--------------------------------------

In diesem Tutorial zeigen wir Ihnen, wie Sie den CH340-Treiber auf verschiedenen Betriebssystemen installieren. Bei vielen Systemen wird der Treiber automatisch installiert. Je nach System oder Updates kann jedoch eine manuelle Installation erforderlich sein, wenn Sie den CH340-Chip erstmals anschließen.

Treiber
^^^^^^^

Der CH340-Chip stammt von WCH. Unten finden Sie die offiziellen Treiberlinks für verschiedene Systeme von der WCH-Website:

* `Windows (ZIP) <https://www.wch.cn/download/file?id=5>`_ – Treiber v3.4 (16.10.2024)  
* `Windows (EXE) <https://www.wch.cn/download/file?id=65>`_ – ausführbare Installationsdatei  
* `Mac (ZIP) <https://www.wch.cn/download/file?id=178>`_ – Treiber v1.5 (26.02.2025)  
* `Linux (ZIP) <https://www.wch.cn/download/file?id=177>`_ – Treiber v1.5 (24.10.2024)

Besuchen Sie auch die WCH-Website, um die aktuellsten Treiber herunterzuladen. Zum Zeitpunkt der Erstellung finden Sie die neueste Version auf ihrer chinesischsprachigen Seite:

* `WCH Treiber-Download <https://www.wch.cn/downloads/CH343SER_EXE.html>`_

Wenn Sie Google Chrome nutzen, können Sie die Seite automatisch übersetzen lassen.

Im Folgenden zeigen wir, wie Sie den CH340-Treiber auf den verschiedenen Systemen installieren.

Windows 7/11
^^^^^^^^^^^^^

#. Laden Sie den Treiber herunter:

   * `Windows (ZIP) <https://www.wch.cn/download/file?id=5>`_ – Treiber v3.4 (16.10.2024)  
   * `Windows (EXE) <https://www.wch.cn/download/file?id=65>`_ – ausführbare Installationsdatei

#. Doppelklicken Sie auf die ``.exe``-Datei. Wenn Sie die ZIP-Version heruntergeladen haben, entpacken Sie sie zuerst und führen dann die ``.exe`` im Inneren aus.

#. Klicken Sie zuerst auf **Deinstallieren**, um vorhandene Treiber zu entfernen, und dann auf **Installieren**.

   .. image:: img/driver_ch340_install.png

#. Nach der Installation öffnen Sie den **Geräte-Manager**. Klicken Sie dazu auf Start oder drücken Sie ⊞ Win und geben Sie „Geräte-Manager“ ein.

   .. image:: img/driver_ch340_device.png

#. Erweitern Sie den Abschnitt **Anschlüsse (COM & LPT)**. Dort sollte **USB‑SERIAL CH340 (COM##)** angezeigt werden — die genaue COM-Nummer variiert.

   .. image:: img/driver_ch340_com.png

macOS
^^^^^^

#. Laden Sie das Treiberpaket herunter und entpacken Sie es:

   * `Mac (ZIP) <https://www.wch.cn/download/file?id=178>`_ – Treiber v1.5 (26.02.2025)

#. Öffnen Sie den entpackten Ordner und doppelklicken Sie auf die ``.pkg``-Datei. Folgen Sie den Anweisungen zur Installation.

   .. note::

      Bei macOS 10.13 oder neuer kann die Installation blockiert werden.  
      Gehen Sie dann zu **Systemeinstellungen > Datenschutz & Sicherheit** und klicken Sie auf **Zulassen** neben der blockierten Erweiterung.  
      Möglicherweise müssen Sie das Schloss-Symbol entsperren und Ihr Passwort eingeben.  
      Starten Sie anschließend Ihren Mac neu, um die Installation abzuschließen.

   .. image:: img/driver_ch340_install_mac.png
      :width: 500
      :align: center

#. Um zu prüfen, ob der Treiber installiert wurde, schließen Sie das CH340-Gerät an und öffnen ein Terminal, dann führen Sie aus:

   .. code-block::

      ls /dev/cu*

#. Sie sollten ein Gerät wie ``/dev/cu.usbserial*****`` sehen. Die genaue Bezeichnung kann leicht abweichen.

   .. image:: img/driver_ch340_mac_port.png
      :width: 500
      :align: center

Linux
^^^^^^

#. Die meisten Linux-Distributionen enthalten bereits Unterstützung für den CH340-Treiber. Verbinden Sie das Gerät einfach, und es sollte automatisch erkannt werden.  

#. Wenn das Gerät nicht erkannt wird, aktualisieren Sie Ihr System:

   .. code-block::

      sudo apt-get update
      sudo apt-get upgrade

#. Alternativ können Sie den Linux-Treiber manuell installieren:

   * `Linux (ZIP) <https://www.wch.cn/download/file?id=177>`_ – Treiber v1.5 (24.10.2024)

#. Schließen Sie das ESP32-Platine erneut an und führen Sie im Terminal aus:

   .. code-block::

      ls /dev/ttyUSB*

#. Bei erfolgreicher Erkennung sollte eine Ausgabe wie folgt erscheinen:

   .. code-block::

      /dev/ttyUSB0

.. _driver_cp2102:

So installieren Sie den CH2102‑Treiber
--------------------------------------

Diese Anleitung zeigt Ihnen, wie Sie den CH2102 USB‑zu‑Seriell‑Treiber unter verschiedenen Betriebssystemen installieren.  
In vielen Fällen wird der Treiber automatisch vom Betriebssystem installiert. Je nach Systemversion oder Konfiguration kann es jedoch erforderlich sein, den Treiber manuell zu installieren, sobald Sie ein CH2102‑Gerät zum ersten Mal anschließen.

Windows
^^^^^^^

#. Rufen Sie die Seite `Silicon Labs USB to UART Bridge VCP Drivers <https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads>`_ auf und laden Sie den **CP210x_Universal_Windows_Driver** herunter.

#. Entpacken Sie die ZIP-Datei, klicken Sie mit der rechten Maustaste auf die ``.inf``-Datei und wählen Sie **Installieren**. Folgen Sie den Anweisungen auf dem Bildschirm, um die Treiberinstallation abzuschließen.

   .. image:: img/driver_cp2102_install.png

#. Nach der Installation schließen Sie Ihr CP2102-Gerät an einen USB‑Port an. Öffnen Sie den **Geräte‑Manager** (drücken Sie ⊞ Win + R, geben Sie ``devmgmt.msc`` ein und drücken Sie Enter).

#. Erweitern Sie den Abschnitt **Anschlüsse (COM & LPT)**. Dort sollte ein Eintrag wie ``Silicon Labs CP210x USB to UART Bridge (COM#)`` erscheinen.

   .. image:: img/driver_cp2102_com.png

#. Wenn das Gerät ohne Fehlersymbol angezeigt wird, wurde der Treiber erfolgreich installiert und funktioniert korrekt.

macOS
^^^^^^

Der CH2102 USB‑zu‑UART-Bridge‑Chipsatz stammt von Silicon Labs. Aktuelle macOS-Versionen bieten meist Basissupport, jedoch wird für volle Stabilität die offizielle Treiberversion von Silicon Labs empfohlen.

#. Rufen Sie die Seite `USB to UART Bridge VCP Drivers <https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads>`_ auf und laden Sie den **CP210x VCP Mac OSX Driver** passend für Ihr System (Apple Silicon oder Intel) herunter.

#. Entpacken Sie die ZIP-Datei und doppelklicken Sie auf die enthaltene ``.dmg``-Datei, um sie zu mounten.

#. Im gemounteten Volume öffnen Sie **Install CP210x VCP Driver.app**.

#. Folgen Sie den Anweisungen im Installationsassistenten.

   .. image:: img/driver_cp2102_mac_install.png
      :width: 500

#. Unter macOS 10.13 oder neuer kann die Treibererweiterung blockiert werden. Wenn Sie dazu aufgefordert werden:

   * Öffnen Sie **Systemeinstellungen > Datenschutz & Sicherheit**
   * Klicken Sie auf **Zulassen** neben der Silicon Labs Erweiterung
   * Entsperren Sie die Einstellungen bei Bedarf (Schloss anklicken und Passwort eingeben)
   * Starten Sie Ihren Mac neu, um die Änderungen zu übernehmen

#. Nach der Installation starten Sie Ihren Mac **neu**, falls noch nicht geschehen.

#. Um zu überprüfen, ob der Treiber installiert ist, öffnen Sie das Terminal und führen Sie aus:

   .. code-block::

      ls /dev/cu.*

#. Sie sollten ein Gerät wie das folgende sehen, was bestätigt, dass der Treiber korrekt funktioniert:

   .. code-block::

      /dev/cu.SLAB_USBtoUART

Linux
^^^^^^

#. Die meisten Linux-Distributionen (z. B. Ubuntu, Debian, Fedora) enthalten bereits Unterstützung für den CP2102-Treiber. In den meisten Fällen wird das Gerät automatisch erkannt, sobald es angeschlossen wird.

#. Wird das Gerät nicht erkannt, aktualisieren Sie Ihr System mit:

   .. code-block::

      sudo apt-get update
      sudo apt-get upgrade

#. Schließen Sie das CP2102-Gerät erneut an und führen Sie im Terminal aus:

   .. code-block::

      ls /dev/ttyUSB*

#. Wenn der Treiber korrekt funktioniert, sollte ein Gerät wie dieses angezeigt werden:

   .. code-block::

      /dev/ttyUSB0

#. Zur zusätzlichen Überprüfung können Sie auch die Kernel-Protokolle ansehen:

   .. code-block::

      dmesg | grep ttyUSB
