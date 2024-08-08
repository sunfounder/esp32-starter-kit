.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_photoresistor:

5.7 Sentir la lumière
===========================

La photoresistance est un dispositif couramment utilisé pour les entrées analogiques, similaire à un potentiomètre. Sa valeur de résistance change en fonction de l'intensité de la lumière qu'elle reçoit. Lorsqu'elle est exposée à une lumière forte, la résistance de la photoresistance diminue, et à mesure que l'intensité lumineuse diminue, la résistance augmente.

En lisant la valeur de la photoresistance, nous pouvons recueillir des informations sur les conditions de lumière ambiante. Ces informations peuvent être utilisées pour des tâches telles que le contrôle de la luminosité d'une LED, l'ajustement de la sensibilité d'un capteur, ou la mise en œuvre d'actions dépendantes de la lumière dans un projet.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Broches disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Broches de configuration**

    Les broches suivantes sont des broches de configuration, qui affectent le processus de démarrage de l'ESP32 lors de la mise sous tension ou du réinitialisation. Cependant, une fois l'ESP32 démarré avec succès, elles peuvent être utilisées comme des broches normales.

    .. list-table::
        :widths: 5 15

        *   - Broches de configuration
            - IO0, IO12

**Schéma**

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

À mesure que l'intensité lumineuse augmente, la résistance de la photoresistance (LDR) diminue, entraînant une diminution de la valeur lue sur I35.

**Câblage**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.7_feel_the_light.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.7_feel_the_light``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/58b494c7-eef4-4476-af65-4823cef13f90/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléchargé le code avec succès, le Moniteur Série affiche les valeurs de la photoresistance de 0 à 4095. 
Plus la luminosité ambiante actuelle est forte, plus la valeur affichée sur le moniteur série est élevée.

.. note::
    Pour l'ESP32, la résolution est comprise entre 9 et 12 bits et cela changera la résolution matérielle de l'ADC. Sinon, la valeur sera décalée.

    Par défaut, la résolution est de 12 bits (allant de 0 à 4096) pour toutes les puces, sauf pour l'ESP32S3 où la valeur par défaut est de 13 bits (allant de 0 à 8192).

    Vous pouvez ajouter ``analogReadResolution(10);`` à la fonction ``setup()`` pour définir une résolution différente, telle que ``10``.

    
