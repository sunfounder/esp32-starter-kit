.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_dice:

6.4 Digitaler Würfel
=============================

Dieses Projekt baut auf dem :ref:`py_7_segment` Projekt auf, indem ein Knopf hinzugefügt wird, um die auf dem Siebensegment-Display angezeigte Ziffer zu steuern.

In diesem Projekt wird eine zufällige Zahl erzeugt und auf dem Siebensegment-Display angezeigt, um einen Würfelwurf zu simulieren. Wenn der Knopf gedrückt wird, wird eine stabile Zahl (zufällig ausgewählt von 1 bis 6) auf dem Siebensegment-Display angezeigt. Ein erneutes Drücken des Knopfes startet die Simulation eines Würfelwurfs, wobei wieder zufällige Zahlen generiert werden. Dieser Zyklus setzt sich bei jedem Drücken des Knopfes fort.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen. Hier ist der Link:

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.6_electronic_dice.png

Dieses Projekt baut auf dem :ref:`ar_7_segment` Projekt auf, indem ein Knopf hinzugefügt wird, um die auf dem Siebensegment-Display angezeigte Ziffer zu steuern.

Der Knopf ist direkt an IO13 angeschlossen, ohne einen externen Pull-up- oder Pull-down-Widerstand, da IO13 einen internen Pull-up-Widerstand von 47K besitzt, wodurch ein zusätzlicher externer Widerstand nicht notwendig ist.


**Verdrahtung**

.. image:: ../../img/wiring/6.6_DICE_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``6.4_digital_dice.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\6.4_digital_dice``.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ad904f48-cd24-49ce-ad92-91b1fb76364d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dieses Projekt basiert auf :ref:`ar_7_segment` mit einem Knopf, um die scrollende Anzeige auf dem 7-Segment-Display zu starten/pausieren.

Wenn der Knopf gedrückt wird, scrollt das 7-Segment-Display durch die Zahlen 1-6, und wenn der Knopf losgelassen wird, zeigt es eine zufällige Zahl an.

