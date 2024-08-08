.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_tilt:

5.2 Kippen!
==========================

Der Kippschalter ist ein einfaches, aber effektives 2-Pin-Gerät, das eine Metallkugel in seiner Mitte enthält. Wenn der Schalter in einer aufrechten Position ist, sind die beiden Pins elektrisch verbunden, was den Stromfluss ermöglicht. Wenn der Schalter jedoch gekippt oder in einem bestimmten Winkel geneigt wird, bewegt sich die Metallkugel und unterbricht die elektrische Verbindung zwischen den Pins.

In diesem Projekt werden wir den Kippschalter nutzen, um die Beleuchtung einer LED zu steuern. Indem wir den Schalter so positionieren, dass die Kippaktion ausgelöst wird, können wir die LED basierend auf der Orientierung des Schalters ein- und ausschalten.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_tilt`
        - \-

**Verfügbare Pins**

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 20

        *   - Für Eingang
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Für Ausgang
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Bedingte Verwendung Pins (Eingang)**

    Die folgenden Pins haben eingebaute Pull-up- oder Pull-down-Widerstände, sodass externe Widerstände nicht erforderlich sind, wenn **sie als Eingangspins verwendet werden**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Bedingte Verwendung Pins
            - Beschreibung
        *   - IO13, IO15, IO2, IO4
            - Hochziehen mit einem 47K-Widerstand setzt den Wert standardmäßig auf hoch.
        *   - IO27, IO26, IO33
            - Hochziehen mit einem 4.7K-Widerstand setzt den Wert standardmäßig auf hoch.
        *   - IO32
            - Herunterziehen mit einem 1K-Widerstand setzt den Wert standardmäßig auf niedrig.

* **Strapping Pins (Eingang)**

    Strapping-Pins sind eine spezielle Gruppe von Pins, die verwendet werden, um bestimmte Boot-Modi während des Gerätestarts 
    (d.h., Einschalt-Reset) zu bestimmen.

    
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    
    

    Generell wird **nicht empfohlen, sie als Eingangspins zu verwenden**. Wenn Sie diese Pins verwenden möchten, berücksichtigen Sie den potenziellen Einfluss auf den Boot-Vorgang. Weitere Details finden Sie im Abschnitt :ref:`esp32_strapping`.


**Schaltplan**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

Wenn der Kippschalter in einer aufrechten Position ist, wird IO14 auf hoch gesetzt, was dazu führt, dass die LED aufleuchtet. Umgekehrt wird IO14 auf niedrig gesetzt, wenn der Kippschalter geneigt ist, wodurch die LED ausgeschaltet wird.

Der Zweck des 10K-Widerstands besteht darin, einen stabilen niedrigen Zustand für IO14 aufrechtzuerhalten, wenn der Kippschalter geneigt ist.


**Verdrahtung**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

**Code**

.. note::

    * Sie können die Datei ``5.2_tilt_switch.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\5.2_tilt_switch`` öffnen. 
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5ed2406f-185c-407c-ac29-42036f174a5d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    


Nachdem der Code erfolgreich hochgeladen wurde, leuchtet die LED auf, wenn der Schalter aufrecht steht, und geht aus, wenn der Schalter geneigt wird.

