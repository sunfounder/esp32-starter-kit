.. _ar_servo:

4.3 Schwingender Servo
======================
Ein Servo ist eine Art positionsbasiertes Gerät, das für seine Fähigkeit bekannt ist, spezifische Winkel zu halten und präzise Drehungen zu liefern. Dies macht es besonders wünschenswert für Steuerungssysteme, die eine konstante Winkelverstellung erfordern. Es ist nicht verwunderlich, dass Servos in hochwertigem ferngesteuertem Spielzeug weit verbreitet sind, von Flugzeugmodellen bis hin zu U-Boot-Repliken und anspruchsvollen ferngesteuerten Robotern.

In diesem faszinierenden Abenteuer werden wir uns der Herausforderung stellen, den Servo auf eine einzigartige Weise zu manipulieren - indem wir ihn schwingen lassen! Dieses Projekt bietet eine hervorragende Gelegenheit, tiefer in die Dynamik der Servos einzutauchen, Ihre Fähigkeiten in präzisen Steuerungssystemen zu schärfen und ein tieferes Verständnis für ihre Funktionsweise zu erlangen.

Sind Sie bereit, den Servo nach Ihrer Melodie tanzen zu lassen? Dann begeben wir uns auf diese spannende Reise!

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

* Orangefarbenes Kabel ist das Signal und an IO25 angeschlossen.
* Rotes Kabel ist VCC und an 5V angeschlossen.
* Braunes Kabel ist GND und an GND angeschlossen.

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``4.3_servo.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\4.3_servo``. Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    * Hier wird die ``ESP32Servo``-Bibliothek verwendet, die Sie über den **Library Manager** installieren können.

        .. image:: img/servo_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/34c7969e-fee3-413c-9fe7-9d38ca6fb906/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem Sie den Code erfolgreich hochgeladen haben, können Sie sehen, wie der Servoarm im Bereich von 0°~180° rotiert.


**Wie funktioniert das?**

#. Die |link_esp32servo| Bibliothek einbinden: Diese Zeile importiert die ESP32Servo-Bibliothek, die erforderlich ist, um den Servomotor zu steuern.

    .. code-block:: arduino

        #include <ESP32Servo.h>

#. Den Servo und den Pin, an den er angeschlossen ist, definieren: Dieser Abschnitt deklariert ein Servo-Objekt (``myServo``) und eine konstante Ganzzahl (``servoPin``), um den Pin darzustellen, an den der Servomotor angeschlossen ist (Pin 25).

    .. code-block:: arduino

        // Define the servo and the pin it is connected to
        Servo myServo;
        const int servoPin = 25;

#. Die minimalen und maximalen Pulsbreiten für den Servo definieren: Dieser Abschnitt legt die minimalen und maximalen Pulsbreiten für den Servomotor fest (0,5 ms und 2,5 ms).

    .. code-block:: arduino

        // Define the minimum and maximum pulse widths for the servo
        const int minPulseWidth = 500; // 0.5 ms
        const int maxPulseWidth = 2500; // 2.5 ms


#. Die ``setup`` Funktion initialisiert den Servomotor, indem sie ihn an den angegebenen Pin anhängt und seinen Pulsbreitenbereich festlegt. Sie stellt auch die PWM-Frequenz für den Servo auf die Standardfrequenz von 50 Hz ein.

    .. code-block:: arduino

        void setup() {
            // Attach the servo to the specified pin and set its pulse width range
            myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

            // Set the PWM frequency for the servo
            myServo.setPeriodHertz(50); // Standard 50Hz servo
        }
    
    * ``attach (int pin, int min, int max)``: Diese Funktion hängt den Servomotor an den angegebenen GPIO-Pin und legt die minimalen und maximalen Pulsbreiten für den Servo fest.

        * ``pin``: Die GPIO-Pinnummer, an die der Servo angeschlossen ist.
        * ``min`` und ``max``: Die minimalen und maximalen Pulsbreiten in Mikrosekunden. Diese Werte definieren den Bewegungsbereich des Servomotors.

    * ``setPeriodHertz(int hertz)``: Diese Funktion legt die PWM-Frequenz für den Servomotor in Hertz fest.

        * ``hertz``: Die gewünschte PWM-Frequenz in Hertz. Die Standard-PWM-Frequenz für Servos beträgt 50Hz, was für die meisten Anwendungen geeignet ist.


#. Die ``loop`` Funktion ist der Hauptteil des Codes, der kontinuierlich läuft. Sie dreht den Servomotor von 0 bis 180 Grad und dann wieder zurück auf 0 Grad. Dies geschieht, indem der Winkel in die entsprechende Pulsbreite umgerechnet und der Servomotor mit dem neuen Pulsbreitenwert aktualisiert wird.

    .. code-block:: arduino

        void loop() {
            // Rotate the servo from 0 to 180 degrees
            for (int angle = 0; angle <= 180; angle++) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }
    
            // Rotate the servo from 180 to 0 degrees
            for (int angle = 180; angle >= 0; angle--) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }
        }

    * ``writeMicroseconds(int value)``: Diese Funktion setzt die Pulsbreite des Servomotors in Mikrosekunden.

        * ``value``: Die gewünschte Pulsbreite in Mikrosekunden.

        Die Funktion ``writeMicroseconds(int value)`` nimmt einen Ganzzahlwert als Argument, der die gewünschte Pulsbreite in Mikrosekunden darstellt. Dieser Wert sollte typischerweise innerhalb des Bereichs liegen, der durch die zuvor im Code definierten minimalen und maximalen Pulsbreiten (``minPulseWidth`` und ``maxPulseWidth``) festgelegt wurde. Die Funktion stellt dann die Pulsbreite für den Servomotor ein, wodurch dieser sich in die entsprechende Position bewegt.
        
