.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_camera_web:

8.2 Serveur Web de Caméra
=============================

Ce projet combine la carte ESP32 avec un module caméra pour diffuser une vidéo de haute qualité sur un réseau local.
Configurez facilement votre propre système de caméra et surveillez n'importe quel endroit en temps réel.

Avec l'interface web du projet, vous pouvez accéder et contrôler le flux de la caméra depuis n'importe quel appareil connecté au réseau.
Personnalisez les paramètres de la caméra pour optimiser l'expérience de streaming et ajustez facilement les réglages grâce à l'interface conviviale.

Améliorez vos capacités de surveillance ou de streaming en direct avec le projet polyvalent ESP32 Camera Streaming. Surveillez votre maison, bureau ou tout autre lieu souhaité avec aisance et fiabilité.

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

**Comment faire ?**

#. Branchez d'abord la caméra.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Ensuite, connectez l'ESP32-WROOM-32E à l'ordinateur à l'aide du câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Ouvrez le code.

    * Ouvrez le fichier ``iot_2_camera_server.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\iot_2_camera_server``, ou copiez le code dans l'IDE Arduino.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/15e00b39-34e1-49f9-b039-f10053d31407/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Trouvez les lignes suivantes et modifiez-les avec votre ``SSID`` et ``PASSWORD``.

    .. code-block::  Arduino

        // Remplacez les variables suivantes par votre combinaison SSID/Mot de passe
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Maintenant, activez **PSRAM**.

    .. image:: img/sp230516_150554.png

#. Réglez le schéma de partition sur **Huge APP (3MB No OTA/1MB SPIFFS)**.

    .. image:: img/sp230516_150840.png

#. Après avoir sélectionné la carte correcte (ESP32 Dev Module) et le port, cliquez sur le bouton "Upload".

#. Vous verrez un message de connexion WiFi réussie et l'adresse IP assignée dans le moniteur série.

    .. code-block::

        .....
        WiFi connected
        Starting web server on port: '80'
        Starting stream server on port: '81'
        Camera Ready! Use 'http://192.168.18.77' to connect

#. Entrez l'adresse IP dans votre navigateur web. Vous verrez une interface web où vous pourrez cliquer sur **Start Stream** pour voir le flux de la caméra.

    .. image:: img/sp230516_151521.png

#. Faites défiler vers le haut de la page, où vous verrez le flux de la caméra en direct. Vous pouvez ajuster les paramètres sur le côté gauche de l'interface.

    .. image:: img/sp230516_180520.png

.. note:: 

    * Ce module ESP32 prend en charge la détection de visages. Pour l'activer, réglez la résolution sur 240x240 et activez l'option de détection de visages en bas de l'interface.
    * Ce module ESP32 ne prend pas en charge la reconnaissance faciale.
