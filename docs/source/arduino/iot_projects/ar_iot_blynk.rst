.. _iot_intrusion_alert_system:

8.9 Blynk-basiertes Einbruchmeldesystem
=============================================

Dieses Projekt demonstriert ein einfaches Einbruchmeldesystem für Zuhause, das einen PIR-Bewegungssensor (HC-SR501) nutzt.
Wenn das System über die Blynk-App auf den Modus "Abwesend" eingestellt ist, überwacht der PIR-Sensor Bewegungen.
Jede erkannte Bewegung löst eine Benachrichtigung in der Blynk-App aus, die den Benutzer über einen möglichen Einbruch informiert.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link: 

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|


1. Schaltungs-Zusammenbau
-----------------------------

.. image:: ../../img/wiring/iot_9_blynk_bb.png
    :width: 60%
    :align: center

2. Blynk-Konfiguration
----------------------

**2.1 Blynk-Initialisierung**

#. Navigieren Sie zur |link_blynk| und wählen Sie **START FREE**. 

   .. image:: img/09_blynk_access.png
        :width: 90%

#. Geben Sie Ihre E-Mail-Adresse ein, um den Registrierungsprozess zu starten.

   .. image:: img/09_blynk_sign_in.png
        :width: 70%
        :align: center

#. Bestätigen Sie Ihre Registrierung per E-Mail.

    .. image:: img/09_blynk_password.png
        :width: 90%

#. Nach der Bestätigung erscheint die **Blynk Tour**. Es wird empfohlen, "Überspringen" zu wählen. Erscheint auch **Quick Start**, überlegen Sie, auch dies zu überspringen.
   
    .. image:: img/09_blynk_tour.png
        :width: 90%

**2.2 Template-Erstellung**

#. Erstellen Sie zunächst ein Template in Blynk. Folgen Sie den nachfolgenden Anweisungen, um das Template **Intrusion Alert System** zu erstellen.

    .. image:: img/09_create_template_1_shadow.png
        :width: 700
        :align: center

#. Geben Sie dem Template einen Namen, wählen Sie als Hardware **ESP32** und als **Connection Type** **WiFi**, dann wählen Sie **Done**.

    .. image:: img/09_create_template_2_shadow.png
        :width: 700
        :align: center

**2.3 Generierung von Datenströmen**

Öffnen Sie das gerade erstellte Template, um zwei Datenströme zu erstellen.

#. Klicken Sie auf **New Datastream**.

    .. image:: img/09_blynk_new_datastream.png
        :width: 700
        :align: center

#. Wählen Sie im Popup **Virtual Pin** aus.

    .. image:: img/09_blynk_datastream_virtual.png
        :width: 700
        :align: center

#. Benennen Sie den **Virtual Pin V0** als **AwayMode**. Setzen Sie den **DATA TYPE** auf **Integer** mit den **MIN**- und **MAX**-Werten **0** und **1**.

    .. image:: img/09_create_template_shadow.png
        :width: 700
        :align: center

#. Erstellen Sie ähnlich einen weiteren **Virtual Pin**-Datenstrom. Benennen Sie ihn **Current Status** und setzen Sie den **DATA TYPE** auf **String**.

    .. image:: img/09_datastream_1_shadow.png
        :width: 700
        :align: center

**2.4 Einrichten eines Ereignisses**

Als Nächstes richten wir ein Ereignis ein, das eine E-Mail-Benachrichtigung sendet, wenn ein Einbruch erkannt wird.

#. Klicken Sie auf **Add New Event**.

    .. image:: img/09_blynk_event_add.png

#. Definieren Sie den Namen des Ereignisses und dessen spezifischen Code. Wählen Sie für **TYPE** **Warning** und schreiben Sie eine kurze Beschreibung für die E-Mail, die gesendet werden soll, wenn das Ereignis eintritt. Sie können auch einstellen, wie oft Sie benachrichtigt werden.

    .. note::
        
        Stellen Sie sicher, dass der **EVENT CODE** als ``intrusion_detected`` festgelegt ist. Dies ist im Code vordefiniert, daher müssen Änderungen auch im Code vorgenommen werden.

    .. image:: img/09_event_1_shadow.png
        :width: 700
        :align: center

#. Gehen Sie zum Abschnitt **Notifications**, um Benachrichtigungen zu aktivieren und E-Mail-Details einzurichten.

    .. image:: img/09_event_2_shadow.png
        :width: 80%
        :align: center

.. raw:: html
    
    <br/> 

**2.5 Feinabstimmung des Web-Dashboards**

Es ist wichtig, dass das **Web Dashboard** perfekt mit dem Einbruchmeldesystem interagiert.

#. Ziehen Sie einfach sowohl das **Switch widget** als auch das **Label widget** auf das **Web Dashboard**.

    .. image:: img/09_web_dashboard_1_shadow.png
        :width: 100%
        :align: center

#. Wenn Sie mit der Maus über ein Widget fahren, erscheinen drei Symbole. Verwenden Sie das Einstellungssymbol, um die Eigenschaften des Widgets anzupassen.

    .. image:: img/09_blynk_dashboard_set.png
        :width: 100%
        :align: center

#. In den Einstellungen des **Switch widget** wählen Sie **Datastream** als **AwayMode(V0)**. Setzen Sie **ONLABEL** und **OFFLABEL** auf **"away"** bzw. **"home"**.

    .. image:: img/09_web_dashboard_2_shadow.png
        :width: 100%
        :align: center

#. In den Einstellungen des **Label widget** wählen Sie **Datastream** als **Current Status(V1)**.

    .. image:: img/09_web_dashboard_3_shadow.png
        :width: 100%
        :align: center

**2.6 Speichern des Templates**

Vergessen Sie zum Schluss nicht, Ihr Template zu speichern.

    .. image:: img/09_save_template_shadow.png
        :width: 100%
        :align: center

**2.7 Erstellen eines Geräts**

#. Jetzt ist es an der Zeit, ein neues Gerät zu erstellen.

    .. image:: img/09_blynk_device_new.png
        :width: 700
        :align: center

#. Klicken Sie auf **From template**, um mit einer neuen Einrichtung zu beginnen.

    .. image:: img/09_blynk_device_template.png
        :width: 700
        :align: center

#. Wählen Sie dann das Template **Intrusion Alert System** und klicken Sie auf **Create**.

    .. image:: img/09_blynk_device_template2.png
        :width: 700
        :align: center

#. Hier sehen Sie die ``Template ID``, den ``Device Name`` und den ``AuthToken``. Sie müssen diese in Ihren Code kopieren, damit der ESP32 mit Blynk arbeiten kann.

    .. image:: img/09_blynk_device_code.png
        :width: 700
        :align: center

3. Codeausführung
-----------------------------
#. Bevor Sie den Code ausführen, stellen Sie sicher, dass Sie die ``Blynk``-Bibliothek über den **Library Manager** in der Arduino IDE installiert haben.

    .. image:: img/09_blynk_add_library.png
        :width: 700
        :align: center

#. Öffnen Sie die Datei ``iot_9_intrusion_alert_system.ino``, die sich im Verzeichnis ``esp32-starter-kit-main\c\codes\iot_9_intrusion_alert_system`` befindet. Sie können auch deren Inhalt in die Arduino IDE kopieren.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/16bca228-64d7-4519-ac3b-833afecfcc65/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Ersetzen Sie die Platzhalter für ``BLYNK_TEMPLATE_ID``, ``BLYNK_TEMPLATE_NAME`` und ``BLYNK_AUTH_TOKEN`` mit Ihren eigenen einzigartigen IDs.

    .. code-block:: arduino
    
        #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

#. Geben Sie auch die ``ssid`` und das ``password`` Ihres WLAN-Netzwerks ein.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. Wählen Sie das richtige Board (**ESP32 Dev Module**) und den Port, und klicken Sie dann auf den **Upload**-Button.

#. Öffnen Sie den Seriellen Monitor (Baudrate auf 115200 einstellen) und warten Sie auf eine erfolgreiche Verbindungsmeldung.

    .. image:: img/09_blynk_upload_code.png
        :align: center

#. Nach einer erfolgreichen Verbindung startet das Aktivieren des Schalters in Blynk die Überwachung des PIR-Moduls. Wenn eine Bewegung erkannt wird (Zustand 1), wird „Jemand ist hier!“ angezeigt und eine Warnung an Ihre E-Mail gesendet.

    .. image:: img/09_blynk_code_alarm.png
        :width: 700
        :align: center

4. Code-Erklärung
-----------------------------

#. **Konfiguration & Bibliotheken**

   Hier richten Sie die Blynk-Konstanten und Zugangsdaten ein. Sie schließen auch die notwendigen Bibliotheken für den ESP32 und Blynk ein.

    .. code-block:: arduino

        /* Comment this out to disable prints and save space */
        #define BLYNK_PRINT Serial

        #define BLYNK_TEMPLATE_ID "xxxxxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"

        #include <WiFi.h>
        #include <WiFiClient.h>
        #include <BlynkSimpleEsp32.h>

#. **WiFi-Einrichtung**

   Geben Sie Ihre WLAN-Zugangsdaten ein.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. **PIR-Sensor-Konfiguration**

   Legen Sie den Pin fest, an dem der PIR-Sensor angeschlossen ist, und initialisieren Sie die Zustandsvariablen.

   .. code-block:: arduino

      const int sensorPin = 14;
      int state = 0;
      int awayHomeMode = 0;
      BlynkTimer timer;

#. **setup() Funktion**

   Diese Funktion initialisiert den PIR-Sensor als Eingang, richtet die serielle Kommunikation ein, verbindet sich mit WLAN und konfiguriert Blynk.

   - Wir verwenden ``timer.setInterval(1000L, myTimerEvent)`` um das Timer-Intervall in ``setup()`` zu setzen. Hier legen wir fest, dass die Funktion ``myTimerEvent()`` alle **1000ms** ausgeführt wird. Sie können den ersten Parameter von ``timer.setInterval(1000L, myTimerEvent)`` ändern, um das Intervall zwischen den Ausführungen von ``myTimerEvent`` zu variieren.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void setup() {

            pinMode(sensorPin, INPUT);  // Set PIR sensor pin as input
            Serial.begin(115200);           // Start serial communication at 115200 baud rate for debugging
            
            // Configure Blynk and connect to WiFi
            Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
            
            timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second
        }

#. **loop() Funktion**

   Die loop-Funktion führt kontinuierlich Blynk und die Blynk-Timer-Funktionen aus.

   .. code-block:: arduino

        void loop() {
           Blynk.run();
           timer.run();
        }

#. **Blynk-App-Interaktion**

   Diese Funktionen werden aufgerufen, wenn das Gerät sich mit Blynk verbindet und wenn sich der Zustand des virtuellen Pins V0 in der Blynk-App ändert.

   - Jedes Mal, wenn das Gerät sich mit dem Blynk-Server verbindet oder aufgrund schlechter Netzwerkbedingungen erneut verbindet, wird die Funktion ``BLYNK_CONNECTED()`` aufgerufen. Der Befehl ``Blynk.syncVirtual()`` fordert einen einzelnen virtuellen Pinwert an. Der angegebene virtuelle Pin führt einen ``BLYNK_WRITE()``-Aufruf durch. 

   - Immer wenn sich der Wert eines virtuellen Pins auf dem BLYNK-Server ändert, wird ``BLYNK_WRITE()`` ausgelöst.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino
      
        // This function is called every time the device is connected to the Blynk.Cloud
        BLYNK_CONNECTED() {
            Blynk.syncVirtual(V0);
        }
      
        // This function is called every time the Virtual Pin 0 state changes
        BLYNK_WRITE(V0) {
            awayHomeMode = param.asInt();
            // additional logic
        }

#. **Datenverarbeitung**

   Jede Sekunde ruft die Funktion ``myTimerEvent()`` die Funktion ``sendData()`` auf. Wenn der Abwesenheitsmodus in Blynk aktiviert ist, überprüft sie den PIR-Sensor und sendet eine Benachrichtigung an Blynk, wenn eine Bewegung erkannt wird.

   - Wir verwenden ``Blynk.virtualWrite(V1, "Jemand in Ihrem Haus! Bitte überprüfen!");`` um den Text eines Labels zu ändern.

   - Verwenden Sie ``Blynk.logEvent("intrusion_detected");``, um ein Ereignis in Blynk zu protokollieren.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void myTimerEvent() {
           sendData();
        }

        void sendData() {
           if (awayHomeMode == 1) {
              state = digitalRead(sensorPin);  // Read the state of the PIR sensor

              Serial.print("state:");
              Serial.println(state);

              // If the sensor detects movement, send an alert to the Blynk app
              if (state == HIGH) {
                Serial.println("Somebody here!");
                Blynk.virtualWrite(V1, "Somebody in your house! Please check!");
                Blynk.logEvent("intrusion_detected");
              }
           }
        }

**Referenz**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|
- |link_blynk_syncing| 
- |link_blynk_write|