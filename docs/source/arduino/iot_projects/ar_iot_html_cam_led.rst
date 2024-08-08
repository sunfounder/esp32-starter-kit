.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_html_cam:


8.3 Serveur Web de Streaming Vidéo Personnalisé
=====================================================

Le projet de serveur web de streaming vidéo personnalisé vous offre l'opportunité d'apprendre à créer une page web à partir de zéro et à la personnaliser pour diffuser des flux vidéo. De plus, vous pouvez y intégrer des boutons interactifs, tels que ON et OFF, pour contrôler la luminosité de la LED.

En réalisant ce projet, vous acquerrez une expérience pratique en développement web, HTML, CSS et JavaScript. Vous apprendrez à créer une page web responsive capable d'afficher des flux vidéo en temps réel. De plus, vous découvrirez comment intégrer des boutons interactifs pour contrôler l'état de la LED, offrant ainsi une expérience utilisateur dynamique.

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

**Comment faire ?**

#. Branchez d'abord la caméra.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Montez le circuit.

    .. image:: ../../img/wiring/iot_3_html_led_bb.png

#. Ensuite, connectez l'ESP32-WROOM-32E à l'ordinateur à l'aide du câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Ouvrez le code.

    * Ouvrez le fichier ``iot_3_html_cam_led.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\iot_3_html_cam_led``, ou copiez le code dans l'Arduino IDE.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a5e33c30-63dc-4987-94c3-89bc6a599e24/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Trouvez les lignes suivantes et modifiez-les avec votre ``SSID`` et ``PASSWORD``.

    .. code-block::  Arduino

        // Remplacez les variables suivantes par votre combinaison SSID/Mot de passe
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Après avoir sélectionné la carte correcte (ESP32 Dev Module) et le port, cliquez sur le bouton **Upload**.

#. Vous verrez un message de connexion WiFi réussie et l'adresse IP attribuée dans le moniteur série.

    .. code-block:: 

        WiFi connected
        Camera Stream Ready! Go to: http://192.168.18.77

#. Entrez l'adresse IP dans votre navigateur web. Vous serez dirigé vers la page web affichée ci-dessous, où vous pourrez utiliser les boutons personnalisés ON et OFF pour contrôler la LED.

    .. image:: img/sp230510_180503.png 

#. Insérez une batterie dans la carte d'extension et retirez le câble USB. Vous pouvez maintenant placer l'appareil n'importe où dans la portée du Wi-Fi.

    .. image:: ../../img/plugin_battery.png

