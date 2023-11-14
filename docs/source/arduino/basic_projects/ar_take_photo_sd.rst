7.6 Foto auf SD-Karte speichern
==================================

Dieses Dokument beschreibt ein Projekt, das darin besteht, ein Foto mit dem ESP32-CAM zu machen und es auf einer SD-Karte zu speichern.
Das Ziel des Projekts ist es, eine einfache Lösung für das Aufnehmen von Bildern mit dem ESP32-CAM und deren Speicherung auf einer SD-Karte bereitzustellen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link: 

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


**Verwandte Vorsichtsmaßnahmen**

Beim Einsatz des ESP32-CAM ist zu beachten, dass der GPIO 0-Pin mit GND verbunden sein muss, um einen Sketch hochzuladen. 
Außerdem muss nach der Verbindung von GPIO 0 mit GND der RESET-Knopf des ESP32-CAM gedrückt werden, um das Board in den Flash-Modus zu versetzen. 
Es ist auch wichtig sicherzustellen, dass die SD-Karte korrekt eingebunden ist, bevor Bilder darauf gespeichert werden.

**Betriebsschritte**

#. Stecken Sie Ihre SD-Karte in einen Kartenleser am Computer und formatieren Sie sie. Sie können sich auf das Tutorial unter :ref:`format_sd_card` beziehen.

#. Entfernen Sie dann den Kartenleser und stecken Sie die SD-Karte in das Erweiterungsboard.

    .. image:: ../../img/insert_sd.png

#. Stecken Sie jetzt die Kamera ein.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Verbinden Sie ESP32-WROOM-32E mit dem Computer über das USB-Kabel.

    .. image:: ../../img/plugin_esp32.png

#. Öffnen Sie den Code.

    .. note::

        * Öffnen Sie die Datei ``7.6_take_photo_sd.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\7.6_take_photo_sd``.
        * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4d698dc3-aef7-4aea-b8a3-7d143a4c7d3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Aktivieren Sie jetzt **PSRAM**.

    .. image:: img/sp230516_150554.png

#. Stellen Sie das Partitionsschema auf **Huge APP (3MB No OTA/1MB SPIFFS)** ein.

    .. image:: img/sp230516_150840.png   

#. Wählen Sie den passenden Port und das Board in der Arduino IDE aus und laden Sie den Code auf Ihren ESP32.

#. Nach dem erfolgreichen Hochladen des Codes drücken Sie den **Reset**-Knopf, um ein Foto zu machen. Zusätzlich können Sie den seriellen Monitor überprüfen, um die folgenden Informationen über die erfolgreiche Aufnahme zu sehen.


    .. code-block:: arduino

        Picture file name: /picture9.jpg
        Saved file to path: /picture9.jpg
        Going to sleep now

    .. image:: img/press_reset.PNG

#. Entfernen Sie jetzt die SD-Karte vom Erweiterungsboard und stecken Sie sie in Ihren Computer. Sie können die Fotos ansehen, die Sie gerade gemacht haben.

    .. image:: img/take_photo1.png

**Wie funktioniert das?**

Dieser Code betreibt eine AI Thinker ESP32-CAM, um ein Foto zu machen, es auf einer SD-Karte zu speichern und dann die ESP32-CAM in den Tiefschlaf zu versetzen. Hier ist eine Aufschlüsselung der wichtigsten Teile:

* **Libraries**: Der Code beginnt mit der Einbindung der notwendigen Bibliotheken für die ESP32-CAM, das Dateisystem (FS), die SD-Karte und das EEPROM (zum Speichern von Daten über Stromzyklen hinweg).

    .. code-block:: arduino

        #include "esp_camera.h"
        #include "Arduino.h"
        #include "FS.h"                // SD Card ESP32
        #include "SD_MMC.h"            // SD Card ESP32
        #include "soc/soc.h"           // Disable brownour problems
        #include "soc/rtc_cntl_reg.h"  // Disable brownour problems
        #include "driver/rtc_io.h"
        #include <EEPROM.h>  // read and write from flash memory

* **Pin Definitions**: Dieser Abschnitt richtet Konstanten ein, die die Pin-Verbindungen des ESP32-CAM zum Kameramodul darstellen.

    .. code-block:: arduino

        #define PWDN_GPIO_NUM 32
        #define RESET_GPIO_NUM -1
        #define XCLK_GPIO_NUM 0
        #define SIOD_GPIO_NUM 26
        #define SIOC_GPIO_NUM 27

        #define Y9_GPIO_NUM 35
        #define Y8_GPIO_NUM 34
        #define Y7_GPIO_NUM 39
        #define Y6_GPIO_NUM 36
        #define Y5_GPIO_NUM 21
        #define Y4_GPIO_NUM 19
        #define Y3_GPIO_NUM 18
        #define Y2_GPIO_NUM 5
        #define VSYNC_GPIO_NUM 25
        #define HREF_GPIO_NUM 23
        #define PCLK_GPIO_NUM 22


* **Global Variables**: Eine globale Variable ``pictureNumber`` wird deklariert, um die Anzahl der aufgenommenen und auf die SD-Karte gespeicherten Bilder nachzuverfolgen.

    .. code-block:: arduino

        int pictureNumber = 0;


* **Setup Function**: In der Funktion ``setup()`` werden mehrere Aufgaben erledigt:


    * Zuerst wird der Braunout-Detektor deaktiviert, um zu verhindern, dass die ESP32-CAM während hoher Stromabnahmen (wie beim Betrieb der Kamera) zurückgesetzt wird.
    
        .. code-block:: arduino

            WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  //disable brownout detector

    * Die serielle Kommunikation wird zur Fehlersuche initialisiert.

        .. code-block:: arduino

            Serial.begin(115200);

    * Die Kamerakonfiguration wird mit ``camera_config_t`` eingerichtet, einschließlich der GPIO-Pins, XCLK-Frequenz, Pixelformat, Bildgröße, JPEG-Qualität und Anzahl der Framebuffer.
    
        .. code-block:: arduino

            camera_config_t config;
            config.ledc_channel = LEDC_CHANNEL_0;
            config.ledc_timer = LEDC_TIMER_0;
            config.pin_d0 = Y2_GPIO_NUM;
            config.pin_d1 = Y3_GPIO_NUM;
            config.pin_d2 = Y4_GPIO_NUM;
            config.pin_d3 = Y5_GPIO_NUM;
            config.pin_d4 = Y6_GPIO_NUM;
            config.pin_d5 = Y7_GPIO_NUM;
            config.pin_d6 = Y8_GPIO_NUM;
            config.pin_d7 = Y9_GPIO_NUM;
            config.pin_xclk = XCLK_GPIO_NUM;
            config.pin_pclk = PCLK_GPIO_NUM;
            config.pin_vsync = VSYNC_GPIO_NUM;
            config.pin_href = HREF_GPIO_NUM;
            config.pin_sscb_sda = SIOD_GPIO_NUM;
            config.pin_sscb_scl = SIOC_GPIO_NUM;
            config.pin_pwdn = PWDN_GPIO_NUM;
            config.pin_reset = RESET_GPIO_NUM;
            config.xclk_freq_hz = 20000000;
            config.pixel_format = PIXFORMAT_JPEG;
    
    * Die Kamera wird dann mit der Konfiguration initialisiert und, falls dies fehlschlägt, wird eine Fehlermeldung gedruckt.

        .. code-block:: arduino

            esp_err_t err = esp_camera_init(&config);
            if (err != ESP_OK) {
                Serial.printf("Camera init failed with error 0x%x", err);
                return;
            }

    * Die SD-Karte wird initialisiert und, falls dies fehlschlägt, wird eine Fehlermeldung gedruckt.

           .. code-block:: arduino
            
            if (!SD_MMC.begin()) {
                Serial.println("SD Card Mount Failed");
                return;
            }   

            uint8_t cardType = SD_MMC.cardType();
            if (cardType == CARD_NONE) {
                Serial.println("No SD Card attached");
                return;
            }           

    * Ein Foto wird mit der Kamera aufgenommen und im Framebuffer gespeichert.

        .. code-block:: arduino

            fb = esp_camera_fb_get();
            if (!fb) {
                Serial.println("Camera capture failed");
                return;
            }

    * Das EEPROM wird ausgelesen, um die Nummer des letzten Bildes abzurufen, dann wird die Bildnummer für das neue Foto erhöht.

        .. code-block:: arduino

            EEPROM.begin(EEPROM_SIZE);
            pictureNumber = EEPROM.read(0) + 1;

    * Ein Pfad für das neue Bild wird auf der SD-Karte erstellt, mit einem Dateinamen, der der Bildnummer entspricht.

        .. code-block:: arduino

            String path = "/picture" + String(pictureNumber) + ".jpg";

            fs::FS &fs = SD_MMC;
            Serial.printf("Picture file name: %s\n", path.c_str());

    * Nach dem Speichern des Fotos wird die Bildnummer im EEPROM für das nächste Einschalten zurückgespeichert.

        .. code-block:: arduino

            File file = fs.open(path.c_str(), FILE_WRITE);
            if (!file) {
                Serial.println("Failed to open file in writing mode");
            } else {
                file.write(fb->buf, fb->len);  // payload (image), payload length
                Serial.printf("Saved file to path: %s\n", path.c_str());
                EEPROM.write(0, pictureNumber);
                EEPROM.commit();
            }
            file.close();
            esp_camera_fb_return(fb); 

    * Schließlich wird die Onboard-LED (Blitz) ausgeschaltet und die ESP32-CAM geht in den Tiefschlaf.

        .. code-block:: arduino

            pinMode(4, OUTPUT);
            digitalWrite(4, LOW);
            rtc_gpio_hold_en(GPIO_NUM_4);

    * Schlafmodus: Die ESP32-CAM geht nach jeder Fotoaufnahme in den Tiefschlaf, um Strom zu sparen. Sie kann durch einen Reset oder durch ein Signal an bestimmten Pins geweckt werden.

        .. code-block:: arduino

            delay(2000);
            Serial.println("Going to sleep now");
            delay(2000);
            esp_deep_sleep_start();
            Serial.println("This will never be printed");


* Loop-Funktion: Die ``loop()``-Funktion ist leer, weil die ESP32-CAM unmittelbar nach dem Setup-Prozess in den Tiefschlaf geht.


Beachten Sie, dass dieser Code nur funktioniert, wenn GPIO 0 beim Hochladen des Sketches mit GND verbunden ist, und Sie müssen möglicherweise den RESET-Knopf am Board drücken, um Ihr Board in den Flash-Modus zu versetzen. Denken Sie auch daran, "/picture" durch Ihren eigenen Dateinamen zu ersetzen. Die Größe des EEPROMs ist auf 1 gesetzt, was bedeutet, dass es Werte von 0 bis 255 speichern kann. Wenn Sie mehr als 255 Bilder aufnehmen möchten, müssen Sie die Größe des EEPROMs erhöhen und die Art und Weise, wie Sie die pictureNumber speichern und auslesen, anpassen.

