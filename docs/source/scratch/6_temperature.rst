.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_low_temperature:

2.6 Niedrigtemperaturalarm
=============================

In diesem Projekt werden wir ein Niedrigtemperaturalarmsystem erstellen, bei dem das **Snowflake**-Sprite auf der Bühne erscheint, wenn die Temperatur unter den Schwellenwert fällt.

.. image:: img/9_tem.png

Benötigte Komponenten
---------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

Was Sie Lernen Werden
---------------------

- Funktionsprinzip des Thermistors
- Multivariable und subtraktive Operationen


Schaltung Aufbauen
-----------------------

Ein Thermistor ist ein Typ von Widerstand, dessen Widerstand stark temperaturabhängig ist, stärker als bei Standardwiderständen, und es gibt zwei Arten von Widerständen, PTC (Widerstand erhöht sich mit steigender Temperatur) und PTC (Widerstand verringert sich mit steigender Temperatur).

Bauen Sie die Schaltung gemäß dem folgenden Diagramm auf.

Ein Ende des Thermistors ist mit GND verbunden, das andere Ende mit Pin35, und ein 10K-Widerstand ist in Serie zu 5V geschaltet.

Hier wird der NTC-Thermistor verwendet, so dass, wenn die Temperatur steigt, der Widerstand des Thermistors abnimmt, die Spannungsteilung an Pin35 abnimmt und der von Pin35 erhaltene Wert sinkt und umgekehrt steigt.

.. image:: img/circuit/7_low_temp_bb.png

Programmierung
------------------

**1. Wähle ein Sprite aus**

Lösche das Standard-Sprite, klicke auf den **Choose a Sprite**-Button in der unteren rechten Ecke des Sprite-Bereichs, gib **Snowflake** in das Suchfeld ein und klicke dann darauf, um es hinzuzufügen.

.. image:: img/9_snow.png

**2. Erstelle 2 Variablen**

Erstelle zwei Variablen, **before** und **current**, um den Wert von Pin35 in unterschiedlichen Fällen zu speichern.

.. image:: img/9_va.png

**3. Lies den Wert von Pin35**

Wenn die grüne Flagge angeklickt wird, wird der Wert von Pin35 gelesen und in der Variablen **before** gespeichert.

.. image:: img/9_before.png

**4. Lies den Wert von Pin35 erneut**

In [forever], lese den Wert von Pin35 erneut und speichere ihn in der Variablen **current**.

.. image:: img/9_current.png

**5. Bestimmung von Temperaturänderungen**

Verwende den [if else]-Block, um festzustellen, ob der aktuelle Wert von Pin35 um 200 größer als zuvor ist, was einen Temperaturrückgang darstellt. In diesem Fall lasse das **Snowflake**-Sprite erscheinen, andernfalls verstecke es.

* [-] & [>]: Subtraktions- und Vergleichsoperatoren aus der **Operators**-Palette.

.. image:: img/9_show.png
