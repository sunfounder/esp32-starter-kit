.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_take_photo_sd:


7.6 Scatta Foto e Salva su SD
=====================================

Questo documento descrive un progetto che prevede di scattare una foto utilizzando l'ESP32-CAM e di salvarla su una scheda SD. 
L'obiettivo del progetto è fornire una soluzione semplice per catturare immagini utilizzando l'ESP32-CAM e archiviarle su una scheda SD.

**Componenti Necessari**

In questo progetto, avremo bisogno dei seguenti componenti. 

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|


**Precauzioni Correlate**

Quando si utilizza l'ESP32-CAM, è importante notare che il pin GPIO 0 deve essere collegato a GND per caricare uno sketch. 
Inoltre, dopo aver collegato GPIO 0 a GND, è necessario premere il pulsante di RESET sull'ESP32-CAM per mettere la scheda in modalità flashing. 
È anche importante assicurarsi che la scheda SD sia correttamente montata prima di salvare le immagini.

**Passi Operativi**

#. Inserisci la tua scheda SD nel computer utilizzando un lettore di schede, e poi formatta la scheda. Puoi fare riferimento al tutorial su :ref:`format_sd_card`.

#. Quindi, rimuovi il lettore di schede e inserisci la scheda SD nell'espansione.

    .. image:: ../../img/insert_sd.png

#. Ora, collega la fotocamera.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Il tuo browser non supporta il tag video.
        </video>

#. Collega ESP32-WROOM-32E al computer utilizzando il cavo USB.

    .. image:: ../../img/plugin_esp32.png

#. Apri il codice.

    .. note::

        * Apri il file ``7.6_take_photo_sd.ino`` nel percorso ``esp32-starter-kit-main\c\codes\7.6_take_photo_sd``.
        * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4d698dc3-aef7-4aea-b8a3-7d143a4c7d3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Ora, abilita **PSRAM**.

    .. image:: img/sp230516_150554.png

#. Imposta lo schema delle partizioni su **Huge APP (3MB No OTA/1MB SPIFFS)**.

    .. image:: img/sp230516_150840.png   

#. Seleziona la porta e la scheda appropriate nell'Arduino IDE e carica il codice sul tuo ESP32.

#. Dopo il caricamento del codice, premi il pulsante **Reset** per scattare una foto. Inoltre, puoi controllare il Serial Monitor per vedere le seguenti informazioni che indicano l'avvenuta acquisizione.


    .. code-block:: arduino

        Picture file name: /picture9.jpg
        Saved file to path: /picture9.jpg
        Going to sleep now

    .. image:: img/press_reset.png

#. Ora, rimuovi la scheda SD dall'espansione e inseriscila nel computer. Potrai visualizzare le foto appena scattate.

    .. image:: img/take_photo1.png

**Come funziona?**

Questo codice utilizza un AI Thinker ESP32-CAM per scattare una foto, salvarla su una scheda SD e poi mettere l'ESP32-CAM in deep sleep. Ecco una descrizione delle parti chiave:

* **Librerie**: Il codice inizia con l'inclusione delle librerie necessarie per l'ESP32-CAM, il file system (FS), la scheda SD e l'EEPROM (utilizzata per memorizzare i dati tra i cicli di alimentazione).

    .. code-block:: arduino

        #include "esp_camera.h"
        #include "Arduino.h"
        #include "FS.h"                // SD Card ESP32
        #include "SD_MMC.h"            // SD Card ESP32
        #include "soc/soc.h"           // Disable brownour problems
        #include "soc/rtc_cntl_reg.h"  // Disable brownour problems
        #include "driver/rtc_io.h"
        #include <EEPROM.h>  // read and write from flash memory

* **Definizioni dei Pin**: Questa sezione imposta le costanti che rappresentano i collegamenti dei pin dell'ESP32-CAM al modulo fotocamera.

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


* **Variabili Globali**: Una variabile globale ``pictureNumber`` viene dichiarata per tenere traccia del numero di immagini scattate e salvate sulla scheda SD.

    .. code-block:: arduino

        int pictureNumber = 0;


* **Funzione Setup**: Nella funzione ``setup()``, vengono eseguite diverse operazioni:


    * Innanzitutto, il rilevatore di brown-out viene disabilitato per impedire il reset dell'ESP32-CAM durante alti consumi di corrente (come quando la fotocamera è in funzione).
    
        .. code-block:: arduino

            WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  //disable brownout detector

    * La comunicazione Serial viene inizializzata per il debug.

        .. code-block:: arduino

            Serial.begin(115200);

    * La configurazione della fotocamera viene impostata con ``camera_config_t``, inclusi i pin GPIO, la frequenza XCLK, il formato dei pixel, la dimensione del frame, la qualità JPEG e il numero di framebuffer.
    
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
    
    * La fotocamera viene quindi inizializzata con la configurazione e, in caso di fallimento, viene stampato un messaggio di errore.

        .. code-block:: arduino

            esp_err_t err = esp_camera_init(&config);
            if (err != ESP_OK) {
                Serial.printf("Camera init failed with error 0x%x", err);
                return;
            }

    * La scheda SD viene inizializzata e, in caso di fallimento, viene stampato un messaggio di errore.

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

    * Una foto viene catturata con la fotocamera e salvata nel framebuffer.

        .. code-block:: arduino

            fb = esp_camera_fb_get();
            if (!fb) {
                Serial.println("Camera capture failed");
                return;
            }

    * L'EEPROM viene letta per recuperare il numero dell'ultima immagine, quindi il numero della nuova immagine viene incrementato.

        .. code-block:: arduino

            EEPROM.begin(EEPROM_SIZE);
            pictureNumber = EEPROM.read(0) + 1;

    * Un percorso per la nuova immagine viene creato sulla scheda SD, con un nome file corrispondente al numero della foto.

        .. code-block:: arduino

            String path = "/picture" + String(pictureNumber) + ".jpg";

            fs::FS &fs = SD_MMC;
            Serial.printf("Picture file name: %s\n", path.c_str());

    * Dopo aver salvato la foto, il numero della foto viene memorizzato di nuovo nell'EEPROM per essere recuperato al prossimo ciclo di alimentazione.

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

    * Infine, il LED integrato (flash) viene spento e l'ESP32-CAM va in deep sleep.

        .. code-block:: arduino

            pinMode(4, OUTPUT);
            digitalWrite(4, LOW);
            rtc_gpio_hold_en(GPIO_NUM_4);

    * Modalità Sleep: L'ESP32-CAM va in deep sleep dopo aver scattato ogni foto per risparmiare energia. Può essere riattivato da un reset o da un segnale su pin specifici.

        .. code-block:: arduino

            delay(2000);
            Serial.println("Going to sleep now");
            delay(2000);
            esp_deep_sleep_start();
            Serial.println("This will never be printed");


* Funzione Loop: La funzione ``loop()`` è vuota perché dopo il processo di setup, l'ESP32-CAM va immediatamente in deep sleep.


Nota che affinché questo codice funzioni, devi assicurarti che GPIO 0 sia collegato a GND durante il caricamento dello sketch e potresti dover premere il pulsante di RESET integrato per mettere la tua scheda in modalità flashing. Inoltre, ricorda di sostituire "/picture" con il tuo nome file. La dimensione dell'EEPROM è impostata su 1, il che significa che può memorizzare valori da 0 a 255. Se intendi scattare più di 255 foto, dovrai aumentare la dimensione dell'EEPROM e regolare come memorizzi e leggi il ``pictureNumber``.
