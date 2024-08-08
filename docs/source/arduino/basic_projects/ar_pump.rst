.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_pump:

4.2 Pumpen
===================
In diesem faszinierenden Projekt werden wir uns mit der Steuerung einer Wasserpumpe mit dem L293D befassen.

Bei der Steuerung von Wasserpumpen ist es etwas einfacher als bei anderen Motoren. Die Schönheit dieses Projekts liegt in seiner Einfachheit - es besteht keine Notwendigkeit, sich um die Drehrichtung zu kümmern. Unser Hauptziel ist es, die Wasserpumpe erfolgreich zu aktivieren und in Betrieb zu halten.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-

**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schaltplan**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


**Verdrahtung**

.. note::

    Hier wird empfohlen, zuerst die Batterie einzulegen und dann den Schalter auf dem Erweiterungsboard auf die Position ON zu schieben, um die Batterieversorgung zu aktivieren.

.. image:: ../../img/wiring/4.2_pump_l293d_bb.png

**Code**

.. note::

  * Sie können die Datei ``4.2_pump.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\4.2_pump`` öffnen.
  * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
  * :ref:`unknown_com_port`
   
.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/a56216f9-eba8-4fdc-8bbb-91337095e543/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Verbinden Sie den Schlauch mit der Pumpe und platzieren Sie ihn im wassergefüllten Behälter. Sobald der Code erfolgreich hochgeladen wurde, werden Sie beobachten, wie das Wasser im Behälter allmählich abgepumpt wird. Während dieses Experiments stellen Sie bitte sicher, dass der elektrische Stromkreis von Wasser ferngehalten wird, um einen Kurzschluss zu verhindern!

