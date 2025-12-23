.. note::

    Bonjour, bienvenue dans la communauté des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder sur Facebook ! Plongez dans l'univers du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_mp3_player_sd:

7.5 Lecteur MP3 avec carte SD
==============================================

Bienvenue dans le monde passionnant de la musique avec votre ESP32 ! Ce projet vous permet de transformer votre ESP32 en un lecteur de musique personnalisé, en plus de ses capacités de microcontrôleur. Imaginez entrer dans votre pièce et entendre votre morceau préféré joué directement depuis ce petit appareil. C'est la puissance que nous vous apportons aujourd'hui.

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants. 

Il est certainement pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément aux liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

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
    *   - :ref:`cpn_audio_speaker`
        - \-

**Étapes de fonctionnement**

#. Insérez votre carte SD dans l'ordinateur à l'aide d'un lecteur de cartes, puis formatez-la. Vous pouvez vous référer au tutoriel à :ref:`format_sd_card`.

#. Copiez votre fichier MP3 préféré sur votre carte SD.

    .. image:: img/mp3_music.png

#. Insérez la carte SD dans le slot SD de la carte d'extension.

    .. image:: ../../img/insert_sd.png

#. Construisez le circuit.

    Comme il s'agit d'un amplificateur mono, vous pouvez connecter IO25 à la broche L ou R du module amplificateur audio.

    La résistance de 10K est utilisée pour réduire le bruit haute fréquence et diminuer le volume audio. Elle forme un filtre passe-bas RC avec la capacité parasite du DAC et de l'amplificateur audio. Ce filtre diminue l'amplitude des signaux haute fréquence, réduisant ainsi efficacement le bruit haute fréquence. Ainsi, ajouter la résistance de 10K rend la musique plus douce et élimine les bruits haute fréquence indésirables.

    Si la musique de votre carte SD est déjà douce, vous pouvez retirer ou remplacer la résistance par une valeur plus petite.

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. Connectez l'ESP32-board à l'ordinateur à l'aide du câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Modifiez le code.

    Modifiez la ligne de code ``file = new AudioFileSourceSD_MMC("/To Alice.mp3")``; pour refléter le nom et le chemin de votre fichier.

    .. note::

        * Ouvrez le fichier ``7.5_mp3_player_sd.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\7.5_mp3_player_sd``. Ou copiez ce code dans l'**Arduino IDE**.
        * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
        * :ref:`unknown_com_port`
        * La bibliothèque ``ESP8266Audio`` est utilisée ici, référez-vous à :ref:`install_lib_man` pour un tutoriel d'installation.
        
    .. warning::

        Si vous utilisez une carte de développement ESP32 version 3.0.0 ou supérieure, vous pouvez rencontrer des erreurs lors du processus de compilation.
        Ce problème est généralement dû au fait que les versions plus récentes de la carte ne prennent plus en charge la bibliothèque ``ESP8266Audio``.
        Pour exécuter correctement cet exemple, il est recommandé de rétrograder la version du firmware de votre carte ESP32 à 2.0.17. 
        Après avoir terminé cet exemple, mettez à jour vers la dernière version.

        .. image:: ../../faq/img/version_2.0.17.png


    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/13f5c757-9622-4735-aa1a-fdbe6fc46273/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. Sélectionnez le port et la carte appropriés dans l'Arduino IDE et téléchargez le code sur votre ESP32.

#. Après avoir téléchargé le code avec succès, vous entendrez votre musique préférée.


**Comment ça marche ?**

* Le code utilise plusieurs classes de la bibliothèque ``ESP8266Audio`` pour lire un fichier MP3 depuis une carte SD via I2S :

    .. code-block:: arduino

        #include "AudioFileSourceSD_MMC.h"
        #include "AudioOutputI2S.h"
        #include "AudioGeneratorMP3.h"
        #include "SD_MMC.h"
        #include "FS.h"

    * ``AudioGeneratorMP3`` est une classe qui décode l'audio MP3.
    * ``AudioFileSourceSD_MMC`` est une classe qui lit les données audio depuis une carte SD.
    * ``AudioOutputI2S`` est une classe qui envoie les données audio à l'interface I2S.

* Dans la fonction ``setup()``, nous initialisons la carte SD, ouvrons le fichier MP3 depuis la carte SD, configurons la sortie I2S sur le DAC interne de l'ESP32, réglons la sortie en mono et démarrons le générateur MP3.

    .. code-block:: arduino

        void setup() {
            // Commencez la communication série.
            Serial.begin(115200);
            delay(1000);

            // Initialisez la carte SD. En cas d'échec, imprimez un message d'erreur.
            if (!SD_MMC.begin()) {
                Serial.println("Échec du montage de la carte SD !");
            }

            // Ouvrez le fichier MP3 depuis la carte SD. Remplacez "/To Alice.mp3" par le nom de votre fichier MP3.
            file = new AudioFileSourceSD_MMC("/To Alice.mp3");
            
            // Configurez la sortie I2S sur le DAC interne de l'ESP32.
            out = new AudioOutputI2S(0, 1);
            
            // Réglez la sortie en mono.
            out->SetOutputModeMono(true);

            // Initialisez le générateur MP3 avec le fichier et la sortie.
            mp3 = new AudioGeneratorMP3();
            mp3->begin(file, out);
        }


* Dans la fonction ``loop()``, nous vérifions si le générateur MP3 est en cours d'exécution. Si c'est le cas, nous continuons à le boucler ; sinon, nous l'arrêtons et imprimons "MP3 terminé" dans le moniteur série.

    .. code-block:: arduino

        void loop() {
            // Si le MP3 est en cours d'exécution, bouclez-le. Sinon, arrêtez-le.
            if (mp3->isRunning()) {
                if (!mp3->loop()) mp3->stop();
            } 
            // Si le MP3 n'est pas en cours d'exécution, imprimez un message et attendez 1 seconde.
            else {
                Serial.println("MP3 done");
                delay(1000);
            }
        }


