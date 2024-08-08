.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_telegram:

8.7 Caméra ESP avec Bot Telegram
=====================================

Dans ce projet, nous allons montrer comment intégrer l'ESP32 avec votre application de messagerie préférée. Pour cette démonstration, nous utilisons Telegram.

Créez un bot Telegram qui vous permet de contrôler votre circuit de n'importe où, de capturer des photos et de gérer le flash. De plus, chaque fois que quelqu'un passe devant votre appareil, il prendra une nouvelle photo et enverra une notification à votre compte Telegram.

**Composants Requis**

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Création d'un Bot Telegram**

#. Allez sur **Google Play** ou l'**App Store** et téléchargez et installez **Telegram**.

#. Recherchez ``botfather`` dans l'application **Telegram**, et une fois qu'il apparaît, cliquez dessus pour l'ouvrir. Ou vous pouvez accéder directement à ce lien : t.me/botfather.

    .. image:: img/sp230515_135927.png

#. En ouvrant, une fenêtre de chat s'affiche. Envoyez la commande ``/start``.

    .. image:: img/sp230515_140149.png

#. Entrez ``/newbot`` et suivez les instructions fournies pour créer votre bot. Une fois terminé, le BotFather vous fournira le lien d'accès et l'API pour votre nouveau bot.

    .. image:: img/sp230515_140830.png

**Autorisation des Utilisateurs Telegram**

Comme tout le monde peut interagir avec le bot que vous avez créé, il existe un risque de fuite d'informations. Pour y remédier, nous voulons que le bot ne réponde qu'aux utilisateurs autorisés.

#. Dans votre compte **Telegram**, recherchez ``IDBot`` ou ouvrez le lien : t.me/myidbot.

    .. image:: img/sp230515_144241.png

#. Envoyez la commande ``/getid``. Enregistrez l'ID fourni pour une utilisation ultérieure dans notre programme.

    .. image:: img/sp230515_144614.png

**Téléversez le Code**

#. Branchez d'abord la caméra.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Montez le circuit.

    .. image:: ../../img/wiring/iot_7_cam_telegram_bb.png
        
#. Ouvrez le code.

    * Ouvrez le fichier ``iot_7_cam_telegram.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\iot_7_cam_telegram``, ou copiez le code dans l'Arduino IDE.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    * Les bibliothèques ``UniversalTelegramBot`` et ``ArduinoJson`` sont utilisées ici, vous pouvez les installer depuis le **Library Manager**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/d7c439b0-fca3-4648-9714-900a2859740c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Trouvez et modifiez les lignes suivantes avec vos informations WiFi, en remplaçant ``SSID`` et ``PASSWORD`` :

    .. code-block::  Arduino

        // Remplacez les variables suivantes par votre combinaison SSID/Mot de passe
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Mettez à jour la ligne suivante, en remplaçant ``CHATID`` par votre ID Telegram, que vous avez obtenu de @IDBot.

    .. code-block:: Arduino

        // Utilisez @myidbot pour trouver l'ID de chat d'un individu ou d'un groupe
        // Notez également que vous devez cliquer sur "start" sur un bot avant qu'il puisse
        // vous envoyer des messages
        String chatId = "CHATID";

#. Mettez à jour la ligne suivante, en remplaçant ``BOTTOKEN`` par le token de votre bot Telegram, fourni par @BotFather.

    .. code-block:: Arduino

        // Initialiser le bot Telegram
        String BOTtoken = "BOTTOKEN";

#. Après avoir sélectionné la carte correcte (ESP32 Dev Module) et le port, cliquez sur le bouton **Upload**.

#. Ouvrez le Moniteur Série. Si une adresse IP est imprimée, cela indique une exécution réussie.

    .. code-block::

        Connecting to xxxx
        ESP32-CAM IP Address: 192.168.18.76
        Init Done!

#. Maintenant, vous pouvez interagir avec votre ESP32 via Telegram.

    .. image:: img/sp230515_161237.png

