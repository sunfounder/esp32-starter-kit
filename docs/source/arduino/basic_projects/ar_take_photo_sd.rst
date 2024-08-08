.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_take_photo_sd:


7.6 Prendre une Photo et Enregistrer sur SD
=================================================

Ce document décrit un projet qui consiste à prendre une photo avec l'ESP32-CAM et à l'enregistrer sur une carte SD. 
L'objectif du projet est de fournir une solution simple pour capturer des images en utilisant l'ESP32-CAM et les stocker sur une carte SD.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|


**Précautions à prendre**

Lors de l'utilisation de l'ESP32-CAM, il est important de noter que la broche GPIO 0 doit être connectée à la masse (GND) pour télécharger un sketch. 
De plus, après avoir connecté GPIO 0 à GND, il faut appuyer sur le bouton RESET de l'ESP32-CAM pour mettre la carte en mode flash. 
Il est également important de s'assurer que la carte SD est correctement montée avant d'y enregistrer des images.

**Étapes de fonctionnement**

#. Insérez votre carte SD dans l'ordinateur à l'aide d'un lecteur de cartes, puis formatez-la. Vous pouvez vous référer au tutoriel à :ref:`format_sd_card`.

#. Ensuite, retirez le lecteur de cartes et insérez la carte SD dans la carte d'extension.

    .. image:: ../../img/insert_sd.png

#. Maintenant, branchez la caméra.

    .. raw:: html

        <video loop autoplay muted style="max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Connectez l'ESP32-WROOM-32E à l'ordinateur à l'aide du câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Ouvrez le code.

    .. note::

        * Ouvrez le fichier ``7.6_take_photo_sd.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\7.6_take_photo_sd``.
        * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4d698dc3-aef7-4aea-b8a3-7d143a4c7d3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Maintenant, activez **PSRAM**.

    .. image:: img/sp230516_150554.png

#. Définissez le schéma de partition sur **Huge APP (3MB No OTA/1MB SPIFFS)**.

    .. image:: img/sp230516_150840.png   

#. Sélectionnez le port et la carte appropriés dans l'IDE Arduino et téléversez le code sur votre ESP32.

#. Après le téléversement réussi du code, appuyez sur le bouton **Reset** pour prendre une photo. De plus, vous pouvez vérifier le moniteur série pour voir les informations suivantes indiquant la capture réussie.

    .. code-block:: arduino

        Picture file name: /picture9.jpg
        Saved file to path: /picture9.jpg
        Going to sleep now

    .. image:: img/press_reset.png

#. Maintenant, retirez la carte SD de la carte d'extension et insérez-la dans votre ordinateur. Vous pourrez voir les photos que vous venez de prendre.

    .. image:: img/take_photo1.png

**Comment ça marche ?**

Ce code fonctionne avec une ESP32-CAM AI Thinker pour prendre une photo, l'enregistrer sur une carte SD, puis mettre l'ESP32-CAM en sommeil profond. Voici une explication des parties clés :

* **Bibliothèques** : Le code commence par l'inclusion des bibliothèques nécessaires pour l'ESP32-CAM, le système de fichiers (FS), la carte SD et l'EEPROM (utilisée pour stocker des données entre les cycles d'alimentation).

    .. code-block:: arduino

        #include "esp_camera.h"
        #include "Arduino.h"
        #include "FS.h"                // Carte SD ESP32
        #include "SD_MMC.h"            // Carte SD ESP32
        #include "soc/soc.h"           // Désactiver les problèmes de brownout
        #include "soc/rtc_cntl_reg.h"  // Désactiver les problèmes de brownout
        #include "driver/rtc_io.h"
        #include <EEPROM.h>  // lire et écrire depuis la mémoire flash

* **Définitions des Pins** : Cette section configure les constantes représentant les connexions des broches de l'ESP32-CAM au module caméra.

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


* **Variables Globales** : Une variable globale ``pictureNumber`` est déclarée pour suivre le nombre de photos prises et sauvegardées sur la carte SD.

    .. code-block:: arduino

        int pictureNumber = 0;


* **Fonction Setup** : Dans la fonction ``setup()``, plusieurs tâches sont effectuées :

    * Tout d'abord, le détecteur de chute de tension est désactivé pour éviter que l'ESP32-CAM ne se réinitialise pendant les fortes consommations de courant (comme lors du fonctionnement de la caméra).
    
        .. code-block:: arduino

            WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  // Désactiver le détecteur de chute de tension

    * La communication série est initialisée pour le débogage.

        .. code-block:: arduino

            Serial.begin(115200);

    * La configuration de la caméra est définie avec ``camera_config_t``, y compris les broches GPIO, la fréquence XCLK, le format des pixels, la taille de l'image, la qualité JPEG et le nombre de tampons de trame.
    
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
    
    * La caméra est ensuite initialisée avec la configuration, et en cas d'échec, un message d'erreur est imprimé.

        .. code-block:: arduino

            esp_err_t err = esp_camera_init(&config);
            if (err != ESP_OK) {
                Serial.printf("Camera init failed with error 0x%x", err);
                return;
            }

    * La carte SD est initialisée, et en cas d'échec, un message d'erreur est imprimé.

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

    * Une photo est capturée avec la caméra et stockée dans le tampon de trame.

        .. code-block:: arduino

            fb = esp_camera_fb_get();
            if (!fb) {
                Serial.println("Camera capture failed");
                return;
            }

    * L'EEPROM est lue pour récupérer le numéro de la dernière photo, puis le numéro de la photo pour la nouvelle capture est incrémenté.

        .. code-block:: arduino

            EEPROM.begin(EEPROM_SIZE);
            pictureNumber = EEPROM.read(0) + 1;

    * Un chemin pour la nouvelle photo est créé sur la carte SD, avec un nom de fichier correspondant au numéro de la photo.

        .. code-block:: arduino

            String path = "/picture" + String(pictureNumber) + ".jpg";

            fs::FS &fs = SD_MMC;
            Serial.printf("Picture file name: %s\n", path.c_str());

    * Après avoir sauvegardé la photo, le numéro de la photo est stocké dans l'EEPROM pour récupération lors du prochain cycle d'alimentation.

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

    * Enfin, la LED intégrée (flash) est éteinte et l'ESP32-CAM passe en mode sommeil profond.

        .. code-block:: arduino

            pinMode(4, OUTPUT);
            digitalWrite(4, LOW);
            rtc_gpio_hold_en(GPIO_NUM_4);

    * Mode Veille : L'ESP32-CAM passe en mode sommeil profond après chaque photo pour économiser de l'énergie. Elle peut être réveillée par une réinitialisation ou par un signal sur des broches spécifiques.

        .. code-block:: arduino

            delay(2000);
            Serial.println("Going to sleep now");
            delay(2000);
            esp_deep_sleep_start();
            Serial.println("This will never be printed");


* Fonction Loop : La fonction ``loop()`` est vide car après le processus de configuration, l'ESP32-CAM passe immédiatement en mode sommeil profond.


Notez que pour que ce code fonctionne, vous devez vous assurer que GPIO 0 est connecté à GND lors du téléchargement du sketch, et vous devrez peut-être appuyer sur le bouton RESET intégré pour mettre votre carte en mode flash. N'oubliez pas non plus de remplacer "/picture" par votre propre nom de fichier. La taille de l'EEPROM est définie à 1, ce qui signifie qu'elle peut stocker des valeurs de 0 à 255. Si vous prévoyez de prendre plus de 255 photos, vous devrez augmenter la taille de l'EEPROM et ajuster la manière dont vous stockez et lisez le ``pictureNumber``.

