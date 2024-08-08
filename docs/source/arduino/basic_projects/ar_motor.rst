.. note::

    Bonjour, bienvenue dans la communauté des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder sur Facebook ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_motor:

4.1 Moteur
===========================

Dans ce projet captivant, nous allons explorer comment piloter un moteur en utilisant le L293D.

Le L293D est un circuit intégré (IC) polyvalent couramment utilisé pour le contrôle des moteurs dans les projets électroniques et robotiques. Il peut piloter deux moteurs dans les deux sens, ce qui en fait un choix populaire pour les applications nécessitant un contrôle précis des moteurs.

À la fin de ce projet fascinant, vous aurez acquis une compréhension approfondie de la manière dont les signaux numériques et les signaux PWM peuvent être utilisés efficacement pour contrôler les moteurs. Ces connaissances inestimables constitueront une base solide pour vos futures aventures en robotique et mécatronique. Attachez vos ceintures et préparez-vous à plonger dans le monde passionnant du contrôle des moteurs avec le L293D !

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
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_l293d`
        - \-

**Pins disponibles**

Voici une liste des pins disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Pins disponibles
      - IO13, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schéma**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


    
**Câblage**

.. note:: 

  Comme le moteur nécessite un courant relativement élevé, il est nécessaire d'insérer d'abord la batterie, puis de faire glisser l'interrupteur sur la carte d'extension en position ON pour activer l'alimentation de la batterie. 

.. image:: ../../img/wiring/4.1_motor_l293d_bb.png



**Code**

.. note::

    * Ouvrez le fichier ``4.1_motor.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\4.1_motor``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
  <iframe src=https://create.arduino.cc/editor/sunfounder01/13364fc5-5094-4a84-90ce-07a5f85556dc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



Une fois le code téléchargé avec succès, vous observerez le moteur tourner dans le sens horaire pendant une seconde, puis dans le sens antihoraire pendant une seconde, suivi d'une pause de deux secondes. Cette séquence d'actions se poursuivra en boucle infinie.


**En savoir plus**

En plus de simplement faire tourner le moteur dans le sens horaire et antihoraire, vous pouvez également contrôler la vitesse de rotation du moteur en utilisant la modulation de largeur d'impulsion (PWM) sur la broche de contrôle, comme montré ci-dessous.

.. note::

    * Ouvrez le fichier ``4.1_motor_pwm.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\4.1_motor_pwm``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/32c262fd-9975-4137-9973-8b62d7240fee/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Le code précédent définit directement les deux broches du moteur à des niveaux de tension haut ou bas pour contrôler la rotation et l'arrêt du moteur.

Ici, nous utilisons le périphérique de contrôle des LED (|link_ledc|) pour générer des signaux PWM afin de contrôler la vitesse du moteur. À travers deux boucles ``for``, le cycle de travail du canal A est augmenté ou diminué de 0 à 255 tandis que le canal B reste à 0.

De cette manière, vous pouvez observer le moteur augmenter progressivement sa vitesse jusqu'à 255, puis la diminuer à 0, en boucle infinie.

Si vous voulez que le moteur tourne dans le sens opposé, il vous suffit d'inverser les valeurs du canal A et du canal B.

