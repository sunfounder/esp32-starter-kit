.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _bluetooth_audio_player:

7.3 Lecteur audio Bluetooth
=================================

Le but de ce projet est de fournir une solution simple pour lire de l'audio depuis 
un appareil compatible Bluetooth en utilisant le DAC intégré de l'ESP32.

Le projet implique l'utilisation de la bibliothèque ``ESP32-A2DP`` pour recevoir les 
données audio d'un appareil Bluetooth. Les données audio reçues sont ensuite transmises 
au DAC interne de l'ESP32 en utilisant l'interface I2S. L'interface I2S est configurée 
pour fonctionner en mode maître, en mode transmission et en mode DAC intégré. Les données 
audio sont ensuite diffusées via le haut-parleur connecté au DAC.

Lors de l'utilisation du DAC interne de l'ESP32, il est important de noter que le niveau 
de tension de sortie est limité à 1,1V. Il est donc recommandé d'utiliser un amplificateur 
externe pour augmenter le niveau de tension de sortie au niveau souhaité. Il est également 
important de s'assurer que les données audio sont au bon format et au bon taux d'échantillonnage 
pour éviter toute distorsion ou bruit lors de la lecture.

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

#. Construisez le circuit.

    Comme il s'agit d'un amplificateur mono, vous pouvez connecter IO25 à la broche L ou R du module amplificateur audio.

    La résistance de 10K est utilisée pour réduire le bruit haute fréquence et diminuer le volume audio. Elle forme un filtre passe-bas RC avec la capacité parasite du DAC et de l'amplificateur audio. Ce filtre diminue l'amplitude des signaux haute fréquence, réduisant efficacement le bruit haute fréquence. Ainsi, l'ajout de la résistance de 10K rend la musique plus douce et élimine les bruits indésirables haute fréquence.

    Si la musique de votre carte SD est déjà douce, vous pouvez retirer ou remplacer la résistance par une valeur plus petite.

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. Ouvrez le code.

    * Ouvrez le fichier ``7.3_bluetooth_audio_player.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\7.3_bluetooth_audio_player``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`
    * La bibliothèque ``ESP32-A2DP`` est utilisée ici, reportez-vous à :ref:`install_lib_man` pour un tutoriel d'installation.

    .. warning::

        Si vous utilisez une carte de développement ESP32 version 3.0.0 ou supérieure, vous pouvez rencontrer des erreurs lors du processus de compilation.
        Ce problème est généralement dû au fait que les versions plus récentes de la carte ne supportent plus la bibliothèque ``ESP32-A2DP``.
        Pour exécuter correctement cet exemple, il est recommandé de rétrograder la version du firmware de votre carte ESP32 à 2.0.17. 
        Après avoir terminé cet exemple, mettez à jour vers la dernière version.

        .. image:: ../../faq/img/version_2.0.17.png



    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/7bb7d6dd-72d4-4529-bb42-033b38558347/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. Après avoir sélectionné la bonne carte et le bon port, cliquez sur le bouton Téléverser.

#. Une fois le code téléversé avec succès, allumez l'appareil compatible Bluetooth et recherchez les appareils disponibles, puis connectez-vous au ``ESP32_Bluetooth``.

    .. image:: img/connect_bluetooth.png

#. Lisez l'audio sur l'appareil et l'audio devrait être diffusé via le haut-parleur connecté à l'ESP32.


**Explication du code**

#. Le code commence par inclure la bibliothèque ``BluetoothA2DPSink.h``, qui est utilisée pour recevoir les données audio de l'appareil Bluetooth. L'objet ``BluetoothA2DPSink`` est ensuite créé et configuré avec les paramètres de l'interface I2S. 

    .. code-block:: arduino

        #include "BluetoothA2DPSink.h"

        BluetoothA2DPSink a2dp_sink;


#. Dans la fonction setup, le code initialise une ``struct i2s_config_t`` avec la configuration souhaitée pour l'interface I2S (Inter-IC Sound). 

    .. code-block:: arduino

        void setup() {
        const i2s_config_t i2s_config = {
            .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
            .sample_rate = 44100, // corrigé par les informations du Bluetooth
            .bits_per_sample = (i2s_bits_per_sample_t) 16, // le module DAC ne prendra que les 8 bits du MSB
            .channel_format =  I2S_CHANNEL_FMT_RIGHT_LEFT,
            .communication_format = (i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
            .intr_alloc_flags = 0, // priorité d'interruption par défaut
            .dma_buf_count = 8,
            .dma_buf_len = 64,
            .use_apll = false
        };

        a2dp_sink.set_i2s_config(i2s_config);  
        a2dp_sink.start("ESP32_Bluetooth");  

        }

    * L'interface I2S est utilisée pour transférer des données audio numériques entre les appareils. 
    * La configuration comprend le ``mode I2S``, le ``taux d'échantillonnage``, les ``bits par échantillon``, le ``format de canal``, le ``format de communication``, les ``drapeaux d'allocation d'interruption``, le ``nombre de tampons DMA``, la ``longueur du tampon DMA``, et s'il faut utiliser ou non l'APLL (Audio PLL).
    * La ``struct i2s_config_t`` est ensuite passée en argument à la fonction ``set_i2s_config`` de l'objet ``BluetoothA2DPSink`` pour configurer l'interface I2S pour la lecture audio.
    * La fonction ``start`` de l'objet ``BluetoothA2DPSink`` est appelée pour démarrer le récepteur audio Bluetooth et commencer à diffuser l'audio via le DAC intégré.

