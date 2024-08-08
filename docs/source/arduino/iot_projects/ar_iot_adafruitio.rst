.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_adafruit_io:

8.6 Surveillance de la température et de l'humidité avec Adafruit IO
=========================================================================

Dans ce projet, nous vous guiderons sur l'utilisation d'une plateforme IoT populaire. Il existe de nombreuses plateformes gratuites (ou peu coûteuses) disponibles en ligne pour les passionnés de programmation. Quelques exemples sont Adafruit IO, Blynk, Arduino Cloud, ThingSpeak, etc. L'utilisation de ces plateformes est assez similaire. Ici, nous nous concentrerons sur Adafruit IO.

Nous allons écrire un programme Arduino qui utilise le capteur DHT11 pour envoyer les relevés de température et d'humidité au tableau de bord d'Adafruit IO. Vous pouvez également contrôler une LED sur le circuit via un interrupteur sur le tableau de bord.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

**Configuration du tableau de bord**

#. Visitez |link_adafruit_io|, puis cliquez sur **Start for free** pour créer un compte gratuit.

    .. image:: img/sp230516_102503.png

#. Remplissez le formulaire pour créer un compte.

    .. image:: img/sp230516_102629.png

#. Après avoir créé un compte Adafruit, vous devrez rouvrir Adafruit IO. Cliquez sur **Dashboards**, puis cliquez sur **New Dashboard**.

    .. image:: img/sp230516_103347.png

#. Créez un **New Dashboard**.

    .. image:: img/sp230516_103744.png

#. Entrez dans le **Dashboard** nouvellement créé et créez un nouveau bloc.

    .. image:: img/sp230516_104234.png

#. Créez un bloc **Toggle**.

    .. image:: img/sp230516_105727.png

#. Ensuite, vous devrez créer un nouveau flux ici. Ce toggle sera utilisé pour contrôler la LED, et nous nommerons ce flux "LED".

    .. image:: img/sp230516_105641.png

#. Cochez le flux **LED**, puis passez à l'étape suivante.

    .. image:: img/sp230516_105925.png

#. Complétez les paramètres du bloc (principalement le titre du bloc, le texte "On" et le texte "Off"), puis cliquez sur le bouton **Create block** en bas à droite pour terminer.

    .. image:: img/sp230516_110124.png

#. Nous devons également créer deux blocs **Text** ensuite. Ils seront utilisés pour afficher la température et l'humidité. Créez donc deux flux nommés **temperature** et **humidity**.

    .. image:: img/sp230516_110657.png

#. Après création, votre tableau de bord devrait ressembler à ceci :

    .. image:: img/sp230516_111134.png

#. Vous pouvez ajuster la mise en page en utilisant l'option **Edit Layout** sur le tableau de bord.

    .. image:: img/sp230516_111240.png

#. Cliquez sur **API KEY**, et vous verrez votre nom d'utilisateur et **API KEY** affichés. Notez-les car vous en aurez besoin pour votre code.

    .. image:: img/sp230516_111641.png

**Exécution du code**

#. Construisez le circuit. 

    .. image:: ../../img/wiring/iot_6_adafruit_io_bb.png

#. Ensuite, connectez l'ESP32-WROOM-32E à l'ordinateur à l'aide du câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Ouvrez le code.

    * Ouvrez le fichier ``iot_6_adafruit_io.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\iot_6_adafruit_io``, ou copiez le code dans l'Arduino IDE.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    * Les bibliothèques ``Adafruit_MQTT Library`` et ``DHT sensor library`` sont utilisées ici, vous pouvez les installer depuis le **Library Manager**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4cf6ad03-250e-4fe9-aa04-0ca73b997843/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Trouvez les lignes suivantes et remplacez ``SSID`` et ``PASSWORD`` par les détails spécifiques de votre réseau WiFi.

    .. code-block::  Arduino

        /************************* Point d'accès WiFi *********************************/

        #define WLAN_SSID "SSID"
        #define WLAN_PASS "PASSWORD"

#. Remplacez ensuite ``YOUR_ADAFRUIT_IO_USERNAME`` par votre nom d'utilisateur Adafruit IO et ``YOUR_ADAFRUIT_IO_KEY`` par la **API KEY** que vous venez de copier.

    .. code-block::  Arduino

        // Configuration du compte Adafruit IO
        // (pour obtenir ces valeurs, visitez https://io.adafruit.com et cliquez sur Active Key)
        #define AIO_USERNAME "YOUR_ADAFRUIT_IO_USERNAME"
        #define AIO_KEY      "YOUR_ADAFRUIT_IO_KEY"

#. Après avoir sélectionné la carte correcte (ESP32 Dev Module) et le port, cliquez sur le bouton **Upload**.

#. Une fois le code téléversé avec succès, vous verrez le message suivant dans le moniteur série, indiquant une communication réussie avec Adafruit IO.
    
    .. code-block::

        Adafruit IO MQTTS (SSL/TLS) Example


        Connecting to xxxxx
        WiFi connected
        IP address: 
        192.168.18.76
        Connecting to MQTT... MQTT Connected!
        Temperature: 27.10
        Humidity: 61.00

#. Retournez sur Adafruit IO. Vous pouvez maintenant observer les relevés de température et d'humidité sur le tableau de bord, ou utiliser l'interrupteur à bascule LED pour contrôler l'état de marche/arrêt de la LED externe connectée au circuit.

    .. image:: img/sp230516_143220.png


