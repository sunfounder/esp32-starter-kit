.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_mp3_player_sd:

7.5 MP3-Player mit SD-Kartenunterstützung
==============================================

Willkommen in der aufregenden Welt der Musik mit Ihrem ESP32! Dieses Projekt bringt die Kraft der Audiobearbeitung in Ihre Hände und macht Ihren ESP32 nicht nur zu einem erstaunlichen Mikrocontroller für Computing, sondern auch zu Ihrem persönlichen Musikplayer. Stellen Sie sich vor, Sie betreten Ihr Zimmer und Ihr Lieblingslied spielt direkt von diesem kleinen Gerät. Das ist die Kraft, die wir Ihnen heute in die Hände legen.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_audio_speaker`
        - \-

**Betriebsschritte**

#. Stecken Sie Ihre SD-Karte in einen Kartenleser am Computer und formatieren Sie sie. Sie können sich auf das Tutorial unter :ref:`format_sd_card` beziehen.

#. Kopieren Sie Ihre Lieblings-MP3-Datei auf Ihre SD-Karte.

    .. image:: img/mp3_music.png

#. Stecken Sie die SD-Karte in den SD-Kartenslot des Erweiterungsboards.

    .. image:: ../../img/insert_sd.png

#. Bauen Sie den Schaltkreis auf.

    Da dies ein Mono-Verstärker ist, können Sie IO25 an den L- oder R-Pin des Audioverstärkermoduls anschließen.

    Der 10K-Widerstand wird verwendet, um hochfrequentes Rauschen zu reduzieren und die Lautstärke des Audios zu verringern. Er bildet zusammen mit der parasitären Kapazität des DAC und des Audioverstärkers einen RC-Tiefpassfilter. Dieser Filter verringert die Amplitude von Hochfrequenzsignalen und reduziert so effektiv hochfrequentes Rauschen. Das Hinzufügen des 10K-Widerstands macht die Musik weicher und eliminiert unerwünschtes Hochfrequenzrauschen.

    Wenn die Musik auf Ihrer SD-Karte bereits leise ist, können Sie den Widerstand entfernen oder durch einen kleineren Wert ersetzen.

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. Verbinden Sie ESP32-WROOM-32E mit dem Computer über das USB-Kabel.

    .. image:: ../../img/plugin_esp32.png


#. Ändern Sie den Code.

    Ändern Sie die Codezeile ``file = new AudioFileSourceSD_MMC("/To Alice.mp3")``; um den Namen und Pfad Ihrer Datei widerzuspiegeln.

    .. note::

        * Öffnen Sie die Datei ``7.5_mp3_player_sd.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\7.5_mp3_player_sd``. Oder kopieren Sie diesen Code in die **Arduino IDE**.
        * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
        * :ref:`unknown_com_port`
        * Hier wird die ``ESP8266Audio``-Bibliothek verwendet, siehe :ref:`install_lib_man` für eine Anleitung zur Installation.
        

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/13f5c757-9622-4735-aa1a-fdbe6fc46273/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. Wählen Sie den passenden Port und das Board in der Arduino IDE aus und laden Sie den Code auf Ihren ESP32.

#. Nachdem der Code erfolgreich hochgeladen wurde, hören Sie Ihre Lieblingsmusik spielen.


**Wie funktioniert das?**

* Der Code verwendet mehrere Klassen aus der ``ESP8266Audio``-Bibliothek, um eine MP3-Datei von einer SD-Karte über I2S abzuspielen:

    .. code-block:: arduino

        #include "AudioFileSourceSD_MMC.h"
        #include "AudioOutputI2S.h"
        #include "AudioGeneratorMP3.h"
        #include "SD_MMC.h"
        #include "FS.h"

    * ``AudioGeneratorMP3`` ist eine Klasse, die MP3-Audio dekodiert.
    * ``AudioFileSourceSD_MMC`` ist eine Klasse, die Audiodaten von einer SD-Karte liest.
    * ``AudioOutputI2S`` ist eine Klasse, die Audiodaten an die I2S-Schnittstelle sendet.

* In der ``setup()``-Funktion initialisieren wir die SD-Karte, öffnen die MP3-Datei von der SD-Karte, richten den I2S-Ausgang am internen DAC des ESP32 ein, stellen den Ausgang auf Mono ein und starten den MP3-Generator.

    .. code-block:: arduino

        void setup() {
            // Start the serial communication.
            Serial.begin(115200);
            delay(1000);

            // Initialize the SD card. If it fails, print an error message.
            if (!SD_MMC.begin()) {
                Serial.println("SD card mount failed!");
            }

            // Open the MP3 file from the SD card. Replace "/To Alice.mp3" with your own MP3 file name.
            file = new AudioFileSourceSD_MMC("/To Alice.mp3");
            
            // Set up the I2S output on ESP32's internal DAC.
            out = new AudioOutputI2S(0, 1);
            
            // Set the output to mono.
            out->SetOutputModeMono(true);

            // Initialize the MP3 generator with the file and output.
            mp3 = new AudioGeneratorMP3();
            mp3->begin(file, out);
        }

* In der ``loop()``-Funktion überprüfen wir, ob der MP3-Generator läuft. Wenn ja, führen wir ihn weiter aus; andernfalls stoppen wir ihn und drucken "MP3 fertig" auf den seriellen Monitor.

    .. code-block:: arduino

        void loop() {
            // If the MP3 is running, loop it. Otherwise, stop it.
            if (mp3->isRunning()) {
                if (!mp3->loop()) mp3->stop();
            } 
            // If the MP3 is not running, print a message and wait for 1 second.
            else {
                Serial.println("MP3 done");
                delay(1000);
            }
        }


