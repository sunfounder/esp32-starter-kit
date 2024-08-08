.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_transistor:

5.6 Zwei Arten von Transistoren
==========================================
Dieses Kit ist mit zwei Arten von Transistoren ausgestattet, S8550 und S8050, wobei ersterer ein PNP- und letzterer ein NPN-Transistor ist. Sie sehen sehr ähnlich aus, und wir müssen sorgfältig prüfen, um ihre Beschriftungen zu sehen.
Wenn ein High-Level-Signal durch einen NPN-Transistor fließt, wird er aktiviert. Aber ein PNP-Transistor benötigt ein Low-Level-Signal, um ihn zu steuern. Beide Arten von Transistoren werden häufig für kontaktlose Schalter verwendet, genau wie in diesem Experiment.

Lassen Sie uns LED und Taster verwenden, um zu verstehen, wie man Transistoren einsetzt!

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

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



**Verbindungsmöglichkeit des NPN (S8050) Transistors**

.. image:: ../../img/circuit/circuit_5.6_S8050.png

In diesem Schaltkreis wird IO14 hoch, wenn der Taster gedrückt wird.

Indem IO26 programmiert wird, um **high** auszugeben, nach einem 1k-Strombegrenzungswiderstand (um den Transistor zu schützen), wird der S8050 (NPN-Transistor) leitfähig, wodurch die LED aufleuchten kann.


.. image:: ../../img/wiring/5.6_s8050_bb.png

**Verbindungsmöglichkeit des PNP(S8550) Transistors**

.. image:: ../../img/circuit/circuit_5.6_S8550.png

In diesem Schaltkreis ist IO14 standardmäßig niedrig und wird hoch, wenn der Taster gedrückt wird.

Indem IO26 programmiert wird, um **low** auszugeben, nach einem 1k-Strombegrenzungswiderstand (um den Transistor zu schützen), wird der S8550 (PNP-Transistor) leitfähig, wodurch die LED aufleuchten kann.

Der einzige Unterschied, den Sie zwischen diesem Schaltkreis und dem vorherigen feststellen werden, ist, dass in dem vorherigen Schaltkreis die Kathode der LED mit dem **collector** des **S8050 (NPN transistor)** verbunden ist, während sie in diesem mit dem **emitter** des **S8550 (PNP transistor)** verbunden ist.

.. image:: ../../img/wiring/5.6_s8550_bb.png

**Code**

.. note::

    * Sie können die Datei ``5.6_transistor.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\5.6_transistor`` öffnen. 
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/3ab778b4-642d-4a5d-8b71-05bc089389e5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Beide Arten von Transistoren können mit demselben Code gesteuert werden. 
Wenn wir den Taster drücken, sendet der ESP32 ein Hochpegel-Signal an den Transistor; 
wenn wir ihn loslassen, sendet er ein Niedrigpegel-Signal.

* Der Schaltkreis mit dem S8050 (NPN-Transistor) leuchtet auf, wenn der Taster gedrückt wird, was darauf hindeutet, dass er sich in einem Hochpegel-Leitzustand befindet;
* Der Schaltkreis mit dem S8550 (PNP-Transistor) leuchtet auf, wenn der Taster losgelassen wird, was darauf hindeutet, dass er sich in einem Niedrigpegel-Leitzustand befindet.
