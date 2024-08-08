.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_flowing_light:

6.2 Lumière Courante
===========================

Avez-vous déjà voulu ajouter un élément amusant et interactif à votre espace de vie ? 
Ce projet consiste à créer une lumière courante en utilisant une bande LED WS2812 et un module d'évitement d'obstacles. 
La lumière courante change de direction lorsqu'un obstacle est détecté, ce qui en fait un ajout excitant à votre décoration intérieure ou de bureau.

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants. 

Il est définitivement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION AUX COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.2_flowing_led.png
    :align: center

La bande LED WS2812 est composée d'une série de LED individuelles pouvant être programmées pour afficher différentes couleurs et motifs. 
Dans ce projet, la bande est configurée pour afficher une lumière courante qui se déplace dans une direction particulière et 
change de direction lorsqu'un obstacle est détecté par le module d'évitement d'obstacles.

**Câblage**

.. image:: ../../img/wiring/6.2_flowing_light_bb.png

**Code**

.. note::

    * Vous pouvez ouvrir directement le fichier ``6.2_flowing_led.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\6.2_flowing_led``.
    * Ou copiez ce code dans l'IDE Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ff625cb6-2efd-436a-9b59-5dd967191338/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ce projet étend les fonctionnalités du projet :ref:`ar_rgb_strip` en ajoutant la capacité d'afficher des couleurs aléatoires sur la bande LED. 
De plus, un module d'évitement d'obstacles a été inclus pour changer dynamiquement la direction de la lumière courante.
