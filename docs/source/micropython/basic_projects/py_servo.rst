.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_servo:

4.3 Schwingender Servomotor
================================

Ein Servomotor ist eine Art positionsbasiertes Gerät, das für seine Fähigkeit bekannt ist, spezifische Winkel zu halten und präzise Drehungen zu liefern. Dies macht ihn besonders wünschenswert für Steuerungssysteme, die konstante Winkelverstellungen verlangen. Es ist nicht überraschend, dass Servomotoren in hochwertigen ferngesteuerten Spielzeugen weit verbreitet sind, von Flugzeugmodellen bis hin zu U-Boot-Repliken und ausgeklügelten ferngesteuerten Robotern.

In diesem faszinierenden Abenteuer werden wir uns selbst herausfordern, den Servomotor auf eine einzigartige Weise zu manipulieren - indem wir ihn schwingen lassen! Dieses Projekt bietet eine hervorragende Gelegenheit, tiefer in die Dynamik von Servomotoren einzutauchen, Ihre Fähigkeiten in präzisen Steuerungssystemen zu schärfen und ein tieferes Verständnis für ihre Funktionsweise zu erlangen.

Sind Sie bereit, den Servomotor nach Ihren Melodien tanzen zu lassen? Lassen Sie uns auf diese spannende Reise gehen!

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können diese auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schaltplan**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**Verdrahtung**

* Das orangefarbene Kabel ist das Signal und wird an IO25 angeschlossen.
* Das rote Kabel ist VCC und wird an 5V angeschlossen.
* Das braune Kabel ist GND und wird an GND angeschlossen.

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``4.3_swinging_servo.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben.

.. code-block:: python

    import machine
    import time

    # Create a PWM (Pulse Width Modulation) object on Pin 25
    servo = machine.PWM(machine.Pin(25))

    # Set the frequency of the PWM signal to 50 Hz, common for servos
    servo.freq(50)

    # Define a function for interval mapping
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Define a function to write an angle to the servo
    def servo_write(pin, angle):
        
        pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculate the pulse width
        duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calculate the duty cycle
        pin.duty(duty) # Set the duty cycle of the PWM signal

    # Create an infinite loop
    while True:
        # Loop through angles from 0 to 180 degrees
        for angle in range(180):
            servo_write(servo, angle)
            time.sleep_ms(20)

        # Loop through angles from 180 to 0 degrees in reverse
        for angle in range(180, -1, -1):
            servo_write(servo, angle)
            time.sleep_ms(20)


Wenn Sie diesen Code ausführen, wird der Servomotor kontinuierlich zwischen 0 und 180 Grad hin und her schwenken.


**Wie funktioniert das?**


#. Importieren Sie die notwendigen Bibliotheken: ``machine`` zur Steuerung der Hardware des Mikrocontrollers und ``time`` für das Hinzufügen von Verzögerungen.


    .. code-block:: python

        import machine
        import time

#. Erstellen Sie ein PWM-Objekt (Pulsweitenmodulation) am Pin 25 und setzen Sie dessen Frequenz auf 50 Hz, was für Servos üblich ist.

    .. code-block:: python

        # Create a PWM (Pulse Width Modulation) object on Pin 25
        servo = machine.PWM(machine.Pin(25))

        # Set the frequency of the PWM signal to 50 Hz, common for servos
        servo.freq(50)

#. Definieren Sie eine ``interval_mapping``-Funktion, um Werte von einem Bereich in einen anderen zu übertragen. Diese wird verwendet, um den Winkel in die entsprechende Impulsbreite und den Tastgrad umzurechnen.

    .. code-block:: python

        def interval_mapping(x, in_min, in_max, out_min, out_max):
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

#. Definieren Sie eine ``servo_write``-Funktion, die ein PWM-Objekt und einen Winkel als Eingaben nimmt. Sie berechnet die Impulsbreite und den Tastgrad basierend auf dem gegebenen Winkel und setzt dann die PWM-Ausgabe entsprechend.

    .. code-block:: python
        
        def servo_write(pin, angle):
            
            pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculate the pulse width
            duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calculate the duty cycle
            pin.duty(duty) # Set the duty cycle of the PWM signal

    * In dieser Funktion wird ``interval_mapping()`` aufgerufen, um den Winkelbereich 0 ~ 180 auf den Impulsbreitenbereich 0,5 ~ 2,5 ms abzubilden.
    * Warum ist es 0,5~2,5? Dies wird durch den Arbeitsmodus des :ref:`Servo` bestimmt.
    * Als nächstes wird die Impulsbreite von der Periode in den Tastgrad umgewandelt.
    * Da ``duty()`` bei Verwendung keine Dezimalzahlen haben darf (der Wert darf kein Float-Typ sein), haben wir ``int()`` verwendet, um den Tastgrad in einen Int-Typ zu konvertieren.

#. Erstellen Sie eine unendliche Schleife mit zwei verschachtelten Schleifen.

    .. code-block:: python

        while True:
            # Loop through angles from 0 to 180 degrees
            for angle in range(180):
                servo_write(servo, angle)
                time.sleep_ms(20)

            # Loop through angles from 180 to 0 degrees in reverse
            for angle in range(180, -1, -1):
                servo_write(servo, angle)
                time.sleep_ms(20)
    
    * Die erste verschachtelte Schleife iteriert durch Winkel von 0 bis 180 Grad, und die zweite verschachtelte Schleife iteriert durch Winkel von 180 bis 0 Grad in umgekehrter Reihenfolge.
    * In jeder Iteration wird die Funktion ``servo_write`` mit dem aktuellen Winkel aufgerufen, und es wird eine Verzögerung von 20 Millisekunden hinzugefügt.
