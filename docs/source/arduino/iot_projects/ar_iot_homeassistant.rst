.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

8.8 Caméra avec Home Assistant
======================================

Ce projet vous guidera dans la configuration d'un serveur web de flux vidéo pour la caméra ESP32 et son intégration avec la plateforme populaire d'automatisation domestique, Home Assistant. Cette intégration vous permettra d'accéder au serveur depuis n'importe quel appareil sur votre réseau.

.. note::
    
    Avant de plonger dans ce projet, vous devez avoir un système d'exploitation avec Home Assistant installé.
        
    Nous recommandons d'installer le système d'exploitation Home Assistant sur un Raspberry Pi.
        
    Si vous n'avez pas de Raspberry Pi, vous pouvez également l'installer sur une machine virtuelle fonctionnant sous Windows, macOS ou Linux.
        
    Pour les instructions d'installation, référez-vous au lien officiel : https://www.home-assistant.io/installation/
        
    Veuillez continuer ce projet uniquement après une installation réussie.

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


**1. Configuration dans ESPHome**

#. Branchez d'abord la caméra.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Connectez votre ESP32 à l'hôte où vous avez installé le système Home Assistant (par exemple, si installé sur un Raspberry Pi, connectez-vous au Pi).

    .. image:: ../../img/plugin_esp32.png

#. Installez l'addon ESPHome.

    .. image:: img/sp230629_145928.png

#. Cliquez sur **START**, puis **OPEN WEB UI**.

    .. image:: img/sp230629_172645.png
        :width: 700
        :align: center

#. Ajoutez de nouveaux appareils.

    .. image:: img/sp230629_172733.png

#. Une invite pourrait apparaître. Cliquez sur **CONTINUE**.

    .. image:: img/sp230629_172816.png
        :align: center

#. Créez une configuration. Ici, vous pouvez entrer le nom souhaité pour **Name**. Pour le WiFi, entrez les détails du réseau sur lequel se trouve votre système Home Assistant.

    .. image:: img/sp230629_172926.png

#. Sélectionnez **ESP32** comme type d'appareil.

    .. image:: img/sp230629_173043.png

#. Lorsque vous voyez une icône de célébration de feux d'artifice, cela signifie que vous avez créé l'appareil avec succès. Cliquez sur skip (NE CLIQUEZ PAS sur **INSTALL**).

    .. image:: img/sp230629_173151.png

    À ce stade, vous avez seulement ajouté l'appareil dans ESPHome. Pour intégrer le module ESP32 dans Home Assistant, des configurations supplémentaires sont nécessaires :

#. Cliquez sur **EDIT**.

    .. image:: img/sp230629_173322.png

#. Après être entré dans l'interface ``.yaml``, modifiez le ``ssid`` et le ``password`` avec les détails de votre WiFi.

    .. image:: img/sp230629_174301.png

#. Sous la section ``captive_portal``, collez le code suivant :

    .. code-block::

        # Example configuration entry
        esp32_camera:
            external_clock:
                pin: GPIO0
                frequency: 20MHz
            i2c_pins:
                sda: GPIO26
                scl: GPIO27
            data_pins: [GPIO5, GPIO18, GPIO19, GPIO21, GPIO36, GPIO39, GPIO34, GPIO35]
            vsync_pin: GPIO25
            href_pin: GPIO23
            pixel_clock_pin: GPIO22
            power_down_pin: GPIO32

            # Image settings
            name: My Camera
            # ...

    .. note:: 
        
        Pour plus de détails sur la configuration ``.yaml`` pour ESP32, vous pouvez consulter `ESP32 Camera - ESPHome <https://esphome.io/components/esp32_camera.html>`_.

#. **Sauvegardez**, puis cliquez sur **INSTALL**.

    .. image:: img/sp230629_174447.png

#. Choisissez la méthode de port USB pour l'installation.

    .. image:: img/sp230629_174852.png

    .. note:: 
        
        La compilation initiale téléchargera les packages de dépendance, ce qui pourrait prendre environ 10 minutes. Veuillez être patient. Si le processus reste bloqué longtemps, vérifiez s'il y a suffisamment d'espace disque sur votre système.

#. Attendez le message ``INFO Successfully compiled program.``, indiquant que la compilation du firmware est terminée.

    .. image:: img/sp230630_115109.png

    .. sp230630_114902.png

    .. note::

        À ce stade, vous devriez voir le nœud comme **ONLINE**. Si ce n'est pas le cas, assurez-vous que votre ESP32 est sur le même segment de réseau ou essayez de redémarrer l'appareil.

        .. image:: img/sp230630_153024.png

**2. Configuration dans Home Assistant**

Après l'intégration avec ESPHome, vous devez encore configurer la caméra dans Home Assistant. 

#. Allez dans **Settings** > **Devices & Services**.

    .. image:: img/sp230630_155917.png

#. Vous devriez maintenant voir l'onglet ESPHome. Cliquez sur **CONFIGURE**.

    .. image:: img/sp230630_155736.png

#. Cliquez sur **SUBMIT**.

    .. image:: img/sp230630_162218.png

#. Attendez le message de **Succès**.

    .. image:: img/sp230630_162311.png

#. Dans **Overview**, cliquez sur le menu en haut à droite et sélectionnez **Edit Dashboard**.

    .. image:: img/sp230630_164745.png

#. Cliquez sur **ADD CARD**.

    .. image:: img/sp230630_164850.png

#. Choisissez **Picture entity**.

    .. image:: img/sp230630_164935.png

#. Dans le champ entité, sélectionnez l'ESP32 que vous venez d'ajouter. Ensuite, **sauvegardez**.

    .. image:: img/sp230630_165019.png

#. Enfin, cliquez sur **DONE** pour quitter l'interface **EDIT**.

    .. image:: img/sp230630_165235.png

Maintenant, vous pouvez voir le flux de votre caméra sur Home Assistant.
