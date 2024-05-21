.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_breathing_led:

2.2 Atmende LED
========================

Nun verwenden wir eine andere Methode, um die Helligkeit der LED zu steuern. Im Gegensatz zum vorherigen Projekt wird hier die Helligkeit der LED langsam verringert, bis sie verschwindet.

Wenn das Sprite auf der Bühne angeklickt wird, nimmt die Helligkeit der LED langsam zu und erlischt dann sofort.

.. image:: img/3_ap.png

Benötigte Komponenten
-------------------------

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

Sie können die Komponenten auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
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
    *   - :ref:`cpn_led`
        - |link_led_buy|

Was Sie Lernen Werden
---------------------

- Setzen des Ausgabewerts des PWM-Pins
- Erstellen von Variablen
- Ändern der Helligkeit des Sprites

Schaltung Aufbauen
-----------------------

Dieses Projekt verwendet dieselbe Schaltung wie das vorherige Projekt :ref:`sh_table_lamp`, verwendet jedoch statt HIGH/LOW, um die LEDs zum Leuchten oder Ausschalten zu bringen, das `PWM-Signal - Wikipedia <https://en.wikipedia.org/wiki/Pulse-width_modulation>`_, um die LED langsam aufleuchten oder dimmen zu lassen.

Der PWM-Signalbereich ist 0-255, auf dem ESP32-Board können die Pins 2, 5, 12~15, 18, 19, 21, 22, 25, 26 und 27 ein PWM-Signal ausgeben.

.. image:: img/circuit/1_hello_led_bb.png

Programmierung
------------------

**1. Ein Sprite auswählen**

Löschen Sie das Standard-Sprite, klicken Sie auf den Button **Choose a Sprite** in der unteren rechten Ecke des Sprite-Bereichs, geben Sie **button3** in das Suchfeld ein und klicken Sie dann darauf, um es hinzuzufügen.

.. image:: img/3_sprite.png

**2. Eine Variable erstellen**.

Erstellen Sie eine Variable namens **pwm**, um den Wert der PWM-Änderung zu speichern.

Klicken Sie auf die **Variables**-Palette und wählen Sie **Make a Variable**.

.. image:: img/3_ap_va.png

Geben Sie den Namen der Variablen ein, es kann jeder Name sein, aber es wird empfohlen, seine Funktion zu beschreiben. Der Datentyp ist Zahl und Für alle Sprites.

.. image:: img/3_ap_pwm.png

Sobald erstellt, sehen Sie **pwm** in der **Variables**-Palette und im angekreuzten Zustand, was bedeutet, dass diese Variable auf der Bühne erscheinen wird. Sie können versuchen, es abzuwählen, um zu sehen, ob pwm noch auf der Bühne vorhanden ist.

.. image:: img/3_ap_0.png

**3. Den Anfangszustand festlegen**

Wenn das **button3**-Sprite angeklickt wird, wechseln Sie das Kostüm zu **button-b** (angeklickter Zustand) und setzen Sie den Anfangswert der Variablen **pwm** auf 0.

* [set pwm to 0]: aus der **Variables**-Palette, verwendet, um den Wert der Variablen festzulegen.

.. image:: img/3_ap_brightness.png

**4. Die LED immer heller machen**

Da der Bereich von pwm 255 ist, wird durch den [repeat]-Block die Variable **pwm** um 5 auf 255 erhöht und dann in den Block [set PWM pin] eingesetzt, sodass Sie sehen können, wie die LED langsam aufleuchtet.

* [change pwm by 5]: aus der **Variables**-Palette, lässt die Variable jedes Mal eine bestimmte Zahl ändern. Es kann eine positive oder negative Zahl sein, positiv bedeutet jedes Mal eine Zunahme, negativ bedeutet jedes Mal eine Abnahme, zum Beispiel wird hier die Variable pwm jedes Mal um 5 erhöht.
* [set PWM pin]: aus der **ESP32**-Palette, verwendet, um den Ausgabewert des PWM-Pins festzulegen.

.. image:: img/3_ap_1.png


Schließlich wechseln Sie das Kostüm von button3 zurück zu **button-a** und machen den PWM-Pin-Wert 0, sodass die LED langsam aufleuchtet und dann wieder erlischt.

.. image:: img/3_ap_2.png

