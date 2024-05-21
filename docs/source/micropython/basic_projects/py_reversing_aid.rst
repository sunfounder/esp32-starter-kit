.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_reversing_aid:

6.4 Einparkhilfe
======================

Stellen Sie sich Folgendes vor: Sie sitzen in Ihrem Auto und wollen in eine enge Parklücke zurücksetzen. Mit unserem Projekt haben Sie ein Ultraschallmodul am Heck Ihres Fahrzeugs montiert, das als digitales Auge fungiert. Sobald Sie den Rückwärtsgang einlegen, erwacht das Modul zum Leben, sendet Ultraschallimpulse aus, die von Hindernissen hinter Ihnen abprallen.

Das Magische passiert, wenn diese Impulse zum Modul zurückkehren. Es berechnet blitzschnell die Entfernung zwischen Ihrem Auto und den Objekten und verwandelt diese Daten in eine Echtzeit-Visuelle Rückmeldung, die auf einem lebendigen LCD-Bildschirm angezeigt wird. Sie erleben dynamische, farbcodierte Indikatoren, die die Nähe zu Hindernissen darstellen und sicherstellen, dass Sie ein kristallklares Verständnis der Umgebung haben.

Aber damit nicht genug. Um Sie noch weiter in dieses Fahrerlebnis einzutauchen, haben wir einen lebhaften Summer eingebaut. Nähert sich Ihr Auto einem Hindernis, intensiviert sich das Tempo des Summers und schafft eine akustische Symphonie von Warnungen. Es ist, als hätten Sie ein persönliches Orchester, das Sie durch die Komplexitäten des Einparkens leitet.

Dieses innovative Projekt kombiniert Spitzentechnologie mit einer interaktiven Benutzeroberfläche und macht Ihr Einparkerlebnis sicher und stressfrei. Mit dem Ultraschallmodul, dem LCD-Display und dem lebhaften Summer, die harmonisch zusammenarbeiten, fühlen Sie sich ermächtigt und sicher beim Manövrieren auf engem Raum und können sich auf die Freude am Fahren konzentrieren.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

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

Sie können sie auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.4_reversing_aid.png
    :width: 800
    :align: center

Der Ultraschallsensor im Projekt sendet hochfrequente Schallwellen aus und misst die Zeit, die diese Wellen benötigen, um nach dem Aufprall auf ein Objekt zurückzuprallen. Durch die Analyse dieser Daten kann die Entfernung zwischen dem Sensor und dem Objekt berechnet werden. Um eine Warnung zu geben, wenn das Objekt zu nahe ist, wird ein Summer verwendet, um ein hörbares Signal zu erzeugen. Zusätzlich wird die gemessene Entfernung auf einem LCD-Bildschirm zur einfachen Visualisierung angezeigt.

**Verdrahtung**

.. image:: ../../img/wiring/6.4_aid_ultrasonic_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``6.4_reversing_aid.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 

.. code-block:: python

    # Import required libraries
    from machine import Pin
    import time
    from lcd1602 import LCD
    import _thread

    # Initialize the buzzer
    buzzer = Pin(14, Pin.OUT)

    # Initialize the ultrasonic module
    TRIG = Pin(26, Pin.OUT)
    ECHO = Pin(25, Pin.IN)

    # Initialize the LCD1602 display
    lcd = LCD()

    dis = 100

    # Calculate the distance
    def distance():
        # Ensure trigger is off initially
        TRIG.off()
        time.sleep_us(2)  # Wait for 2 microseconds

        # Send a 10-microsecond pulse to the trigger pin
        TRIG.on()
        time.sleep_us(10)
        TRIG.off()

        # Wait for the echo pin to go high
        while not ECHO.value():
            pass

        # Record the time when the echo pin goes high
        time1 = time.ticks_us()

        # Wait for the echo pin to go low
        while ECHO.value():
            pass

        # Record the time when the echo pin goes low
        time2 = time.ticks_us()

        # Calculate the time difference between the two recorded times
        during = time.ticks_diff(time2, time1)

        # Calculate and return the distance (in cm) using the speed of sound (340 m/s)
        return during * 340 / 2 / 10000

    # Thread to continuously update the ultrasonic sensor reading
    def ultrasonic_thread():
        global dis
        while True:
            dis = distance()
            
            # Clear the LCD screen
            lcd.clear()
            
            # Display the distance
            lcd.write(0, 0, 'Dis: %.2f cm' % dis)
            time.sleep(0.5)

    # Start the ultrasonic sensor reading thread
    _thread.start_new_thread(ultrasonic_thread, ())

    # Beep function for the buzzer
    def beep():
        buzzer.value(1)
        time.sleep(0.1)
        buzzer.value(0)
        time.sleep(0.1)

    # Initialize the intervals variable
    intervals = 10000000
    previousMills = time.ticks_ms()
    time.sleep(1)

    # Main loop
    while True:
        # Update intervals based on distance
        if dis < 0 and dis > 500:
            pass
        elif dis <= 10:
            intervals = 300
        elif dis <= 20:
            intervals = 500
        elif dis <= 50:
            intervals = 1000
        else:
            intervals = 2000

        # Print the distance if it's not -1
        if dis != -1:
            print('Distance: %.2f' % dis)
        time.sleep_ms(100)

        # Check if it's time to beep
        currentMills = time.ticks_ms()
        if time.ticks_diff(currentMills, previousMills) >= intervals:
            beep()
            previousMills = currentMills


* Wenn das Skript läuft, wird das Ultraschallmodul kontinuierlich die Entfernung von Hindernissen vor ihm erkennen und die Entfernung sowohl auf der Shell als auch auf dem I2C LCD1602 anzeigen. 
* Je näher das Hindernis kommt, desto schneller wird die Piepfrequenz des Summers.
* Die Funktion ``ultrasonic_thread()`` läuft in einem separaten Thread, damit sie die Entfernungsmessung kontinuierlich aktualisieren kann, ohne die Hauptloop zu blockieren.

.. note:: 

    Wenn der Code und die Verdrahtung korrekt sind, das LCD jedoch immer noch keinen Inhalt anzeigt, können Sie das Potentiometer auf der Rückseite justieren, um den Kontrast zu erhöhen.

