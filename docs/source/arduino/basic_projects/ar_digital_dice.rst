.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_dice:

6.4 Dé numérique
=============================

Ce projet s'appuie sur le projet :ref:`py_7_segment` en ajoutant un bouton pour contrôler le chiffre affiché sur l'afficheur à sept segments.

Dans ce projet, un nombre aléatoire est généré et affiché sur l'afficheur à sept segments pour simuler un lancer de dé. Lorsque le bouton est enfoncé, un nombre stable (sélectionné aléatoirement de 1 à 6) est affiché sur l'afficheur à sept segments. En appuyant de nouveau sur le bouton, la simulation d'un lancer de dé est relancée, générant à nouveau des nombres aléatoires. Ce cycle se poursuit à chaque fois que le bouton est pressé.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.6_electronic_dice.png

Ce projet s'appuie sur le projet :ref:`ar_7_segment` en ajoutant un bouton pour contrôler le chiffre affiché sur l'afficheur à sept segments.

Le bouton est directement connecté à IO13 sans résistance pull-up ou pull-down externe car IO13 possède une résistance pull-up interne de 47K, éliminant ainsi le besoin d'une résistance externe supplémentaire.

**Câblage**

.. image:: ../../img/wiring/6.6_DICE_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``6.4_digital_dice.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\6.4_digital_dice``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ad904f48-cd24-49ce-ad92-91b1fb76364d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Ce projet est basé sur :ref:`ar_7_segment` avec un bouton pour démarrer/mettre en pause l'affichage défilant sur l'afficheur à 7 segments.

Lorsque le bouton est pressé, l'afficheur à 7 segments défile les chiffres de 1 à 6, et lorsque le bouton est relâché, il affiche un nombre aléatoire.

