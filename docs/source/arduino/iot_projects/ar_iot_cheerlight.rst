.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_cheerlights:

8.5 CheerLights
===============================

CheerLights est un réseau mondial de lumières synchronisées qui peuvent être contrôlées par n'importe qui.

Rejoignez la communauté de changement de couleur de LED |link_cheerlights|, qui permet aux LEDs du monde entier de changer de couleur simultanément.

Vous pouvez placer vos LEDs dans un coin de votre bureau pour vous rappeler que vous n'êtes pas seul.

Dans ce projet, nous utilisons également MQTT, mais au lieu de publier nos propres messages, nous nous abonnons au sujet "cheerlights". Cela nous permet de recevoir les messages envoyés par d'autres au sujet "cheerlights" et d'utiliser ces informations pour changer la couleur de notre bande LED en conséquence.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|


**Comment faire ?**

#. Construisez le circuit.

    .. image:: ../../img/wiring/iot_5_cheerlight_bb.png

#. Ensuite, connectez l'ESP32-board à l'ordinateur à l'aide du câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Ouvrez le code.

    * Ouvrez le fichier ``iot_5_cheerlights.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\iot_5_cheerlights``, ou copiez le code dans l'IDE Arduino.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    * Les bibliothèques ``PubSubClient`` et ``Adafruit_NeoPixel`` sont utilisées ici, vous pouvez les installer depuis le **Library Manager**.

        .. image:: img/mqtt_lib.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4fc7b0ff-db8e-4bf3-ad34-d68c1857794b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Trouvez les lignes suivantes et modifiez-les avec votre ``SSID`` et ``PASSWORD``.

    .. code-block::  Arduino

        // Remplacez les variables suivantes par votre combinaison SSID/Mot de passe
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Trouvez la ligne suivante et modifiez votre ``unique_identifier``. Assurez-vous que votre ``unique_identifier`` est vraiment unique car des identifiants identiques essayant de se connecter au même **MQTT Broker** peuvent entraîner un échec de connexion.

    .. code-block::  Arduino

        // Ajoutez l'adresse de votre MQTT Broker :
        const char* mqtt_server = "mqtt.cheerlights.com";
        const char* unique_identifier = "sunfounder-client-sdgvsasdda";    

#. Après avoir sélectionné la carte correcte (ESP32 Dev Module) et le port, cliquez sur le bouton **Upload**.

#. À ce stade, vous pouvez voir que votre bande RGB affiche une certaine couleur. Placez-la sur votre bureau et vous remarquerez qu'elle change périodiquement de couleur. C'est parce que d'autres followers de @CheerLights changent la couleur de vos lumières !

#. Ouvrez le moniteur série. Vous verrez des messages similaires aux suivants :

    .. code-block:: 

        WiFi connected
        IP address: 
        192.168.18.77
        Attempting MQTT connection...connected
        Message arrived on topic: cheerlights. 
        Message: oldlace
        Changing color to oldlace

**Contrôler les appareils @CheerLights mondiaux**

#. Rejoignez le |link_discord_server| et utilisez le bot CheerLights pour définir la couleur. Il suffit de taper ``/cheerlights`` dans n'importe quel canal sur le **Serveur Discord CheerLights** pour activer le bot.

    .. image:: img/sp230511_163558.png

#. Suivez les instructions fournies par le bot pour définir la couleur. Cela vous permettra de contrôler les appareils CheerLights dans le monde entier.

    .. image:: img/sp230511_163849.png
