.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_owm:

8.1 Météo en Temps Réel avec @OpenWeatherMap
====================================================

Le projet IoT Open Weather Display utilise la carte ESP32 et un module I2C LCD1602 pour créer un affichage des informations météorologiques récupérées depuis l'API OpenWeatherMap.

Ce projet est une excellente introduction à l'utilisation des API, à la connectivité Wi-Fi et à l'affichage des données sur un module LCD avec la carte ESP32. Avec l'IoT Open Weather Display, vous pouvez facilement accéder aux mises à jour météorologiques en temps réel, ce qui en fait une solution idéale pour les environnements domestiques ou professionnels.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Obtenez les Clés API OpenWeather**

|link_openweather| est un service en ligne, propriété de OpenWeather Ltd, qui fournit des données météorologiques mondiales via API, y compris les données météorologiques actuelles, les prévisions, les nowcasts et les données météorologiques historiques pour n'importe quel emplacement géographique.

#. Visitez |link_openweather| pour vous connecter/créer un compte.

    .. image:: img/OWM-1.png

#. Cliquez sur la page API depuis la barre de navigation.

    .. image:: img/OWM-2.png

#. Trouvez **Current Weather Data** et cliquez sur S'abonner.

    .. image:: img/OWM-3.png

#. Sous **Current weather and forecasts collection**, abonnez-vous au service approprié. Pour notre projet, la version gratuite suffit.

    .. image:: img/OWM-4.png

#. Copiez la clé depuis la page **API keys**.

    .. image:: img/OWM-5.png


**Complétez votre Appareil**

#. Montez le circuit.

    .. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
        :width: 800

#. Ouvrez le code.

    * Ouvrez le fichier ``iot_1_open_weather.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\iot_1_open_weather``, ou copiez le code dans l'Arduino IDE.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    * Les bibliothèques ``LiquidCrystal I2C`` et ``Arduino_JSON`` sont utilisées ici, vous pouvez les installer depuis le **Library Manager**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/71b196ce-8a84-4577-af76-43988c7d3f80/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
         

#. Trouvez les lignes suivantes et modifiez-les avec votre ``SSID`` et ``PASSWORD``.

    .. code-block::  Arduino

        // Remplacez les variables suivantes par votre combinaison SSID/Mot de passe
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Remplissez les clés API que vous avez copiées précédemment dans ``openWeatherMapApiKey``.

    .. code-block::  Arduino

        // Votre nom de domaine avec chemin URL ou adresse IP avec chemin
        String openWeatherMapApiKey = "<openWeatherMapApiKey>";

#. Remplacez par le code de votre pays et votre ville.

    .. code-block::  Arduino

        // Remplacez par le code de votre pays et votre ville
        // Trouvez le code de votre pays sur https://openweathermap.org/find
        String city = "CITY";
        String countryCode = "COUNTRY CODE";

#. Une fois le code exécuté, vous verrez l'heure et les informations météorologiques de votre localisation sur l'I2C LCD1602.

.. note::
   Lorsque le code s'exécute, si l'écran est vide, vous pouvez tourner le potentiomètre à l'arrière du module pour augmenter le contraste.

