.. _ar_motor:

4.1 Motor
===========================

In diesem spannenden Projekt werden wir erforschen, wie man einen Motor mit dem L293D antreibt.

Der L293D ist ein vielseitiger integrierter Schaltkreis (IC), der häufig für die Motorsteuerung in Elektronik- und Robotikprojekten verwendet wird. Er kann zwei Motoren sowohl vorwärts als auch rückwärts antreiben, was ihn zu einer beliebten Wahl für Anwendungen macht, die eine präzise Motorsteuerung erfordern.

Am Ende dieses fesselnden Projekts werden Sie ein gründliches Verständnis dafür haben, wie digitale Signale und PWM-Signale effektiv zur Steuerung von Motoren eingesetzt werden können. Dieses unschätzbare Wissen wird eine solide Grundlage für Ihre zukünftigen Unternehmungen in Robotik und Mechatronik sein. Schnallen Sie sich an und machen Sie sich bereit, in die aufregende Welt der Motorsteuerung mit dem L293D einzutauchen!

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
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

  Da der Motor einen relativ hohen Strom benötigt, ist es notwendig, zuerst die Batterie einzulegen und dann den Schalter auf dem Erweiterungsboard auf die Position ON zu schieben, um die Batterieversorgung zu aktivieren.

.. image:: ../../img/wiring/4.1_motor_l293d_bb.png



**Code**

.. note::

    * Öffnen Sie die Datei ``4.1_motor.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\4.1_motor``.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
  <iframe src=https://create.arduino.cc/editor/sunfounder01/13364fc5-5094-4a84-90ce-07a5f85556dc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



Nachdem der Code erfolgreich hochgeladen wurde, werden Sie beobachten, dass der Motor sich eine Sekunde lang im Uhrzeigersinn dreht, dann eine Sekunde lang gegen den Uhrzeigersinn, gefolgt von einer zweisekündigen Pause. Diese Sequenz von Aktionen wird in einer endlosen Schleife fortgesetzt.


**Mehr erfahren**

Zusätzlich zum einfachen Drehen des Motors im und gegen den Uhrzeigersinn können Sie auch die Geschwindigkeit der Motordrehung steuern, indem Sie auf dem Steuerpin eine Pulsweitenmodulation (PWM) verwenden, wie unten gezeigt.

.. note::

    * Öffnen Sie die Datei ``4.1_motor_pwm.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\4.1_motor_pwm``.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/32c262fd-9975-4137-9973-8b62d7240fee/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Der vorherige Code setzt direkt die beiden Pins des Motors auf hohe oder niedrige Spannungspegel, um die Drehung und das Anhalten des Motors zu steuern.

Hier verwenden wir das |link_ledc| (LED-Steuerung) Peripheriegerät, um PWM-Signale zu erzeugen, um die Motorgeschwindigkeit zu steuern. Durch zwei ``for`` Schleifen wird der Tastgrad von Kanal A von 0 auf 255 erhöht oder verringert, während Kanal B bei 0 bleibt.

Auf diese Weise können Sie beobachten, wie der Motor seine Geschwindigkeit allmählich auf 255 erhöht und dann auf 0 verringert, unendlich so weiterlaufend.

Wenn Sie möchten, dass der Motor sich in die entgegengesetzte Richtung dreht, tauschen Sie einfach die Werte von Kanal A und Kanal B.

