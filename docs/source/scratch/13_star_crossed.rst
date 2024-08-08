
    Bonjour, bienvenue dans la communauté des passionnés SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_star_crossed:

2.13 JEU - Star-Crossed
============================

Dans les prochains projets, nous jouerons à quelques mini-jeux amusants dans PictoBlox.

Ici, nous utilisons le module Joystick pour jouer à un jeu Star-Crossed.

Après le lancement du script, des étoiles apparaîtront aléatoirement sur la scène. Vous devez utiliser le Joystick pour contrôler le vaisseau spatial et éviter les étoiles. Si vous les touchez, le jeu est terminé.

.. image:: img/16_rocket.png

Composants nécessaires
-------------------------

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

Vous pouvez également les acheter séparément via les liens ci-dessous.

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

Ce que vous apprendrez
----------------------------

- Fonctionnement du module Joystick
- Définir les coordonnées x et y du sprite

Construire le circuit
----------------------

Un joystick est un dispositif d'entrée constitué d'un bâton qui pivote sur une base et rapporte son angle ou sa direction à l'appareil qu'il contrôle. Les joysticks sont souvent utilisés pour contrôler les jeux vidéo et les robots.

Pour communiquer une gamme complète de mouvements à l'ordinateur, un joystick doit mesurer la position du bâton sur deux axes - l'axe X (de gauche à droite) et l'axe Y (de haut en bas).

Les coordonnées de mouvement du joystick sont montrées dans la figure suivante.

.. note::

    * La coordonnée x est de gauche à droite, la plage est de 0 à 4095.
    * La coordonnée y est de haut en bas, la plage est de 0 à 4095.

.. image:: img/16_joystick.png

Construisez maintenant le circuit selon le schéma suivant.

.. image:: img/circuit/14_star_crossed_bb.png

Programmation
-----------------
L'ensemble du script vise à obtenir l'effet suivant : lorsque le drapeau vert est cliqué, le sprite **Stars** se déplace en courbe sur la scène et vous devez utiliser le joystick pour déplacer le **Rocketship**, de manière à ce qu'il ne soit pas touché par le sprite **Star**.

**1. Ajouter des sprites et des arrière-plans**

Supprimez le sprite par défaut, et utilisez le bouton **Choisir un Sprite** pour ajouter le sprite **Rocketship** et le sprite **Star**. Notez que la taille du sprite **Rocket** est définie à 50 %.

.. image:: img/16_sprite.png

Ajoutez maintenant l'arrière-plan **Stars** en utilisant le bouton **Choisir un arrière-plan**.

.. image:: img/16_sprite1.png

**2. Script pour Rocketship**

Le sprite **Rocketship** doit apparaître à une position aléatoire puis être contrôlé par le joystick pour le déplacer vers le haut, le bas, la gauche et la droite.

Le flux de travail est le suivant.

* Lorsque le drapeau vert est cliqué, faites aller le sprite à un emplacement aléatoire et créez 2 variables **x** et **y**, qui stockent les valeurs lues depuis la broche 33 (VRX du Joystick) et la broche 35 (VRY du Joystick), respectivement. Vous pouvez laisser le script s'exécuter, en basculant le joystick de haut en bas, de gauche à droite, pour voir la plage de valeurs pour x et y.

.. image:: img/16_roc2.png

* La valeur de la broche 33 est dans la plage 0-4095 (le milieu est d'environ 1800). Utilisez ``x-1800>200`` pour déterminer si le Joystick est basculé vers la droite, et si c'est le cas, faites que la coordonnée x du sprite soit +30 (pour déplacer le sprite vers la droite).

.. image:: img/16_roc3.png

* Si le Joystick est basculé vers la gauche, faites que la coordonnée x du sprite soit -30 (pour déplacer le sprite vers la gauche).

.. image:: img/16_roc4.png

* Comme la coordonnée y du Joystick est de haut (0) en bas (4095), et que la coordonnée y du sprite est de bas en haut. Donc, pour déplacer le Joystick vers le haut et le sprite vers le haut, la coordonnée y doit être -30 dans le script.

.. image:: img/16_roc5.png

* Si le joystick est basculé vers le bas, la coordonnée y du sprite est +30.

.. image:: img/16_roc6.png

**3. Script pour Star**

L'effet recherché pour le sprite **Star** est d'apparaître à un emplacement aléatoire, et s'il touche **Rocketship**, le script s'arrête et le jeu se termine.

* Lorsque le drapeau vert est cliqué et que le sprite va à un emplacement aléatoire, le bloc [tourner de degrés] permet au sprite **Star** d'avancer avec un léger changement d'angle afin que vous puissiez voir qu'il se déplace en courbe et rebondit s'il touche le bord.

.. image:: img/16_star1.png

* Si le sprite touche le sprite **Rocketship** pendant qu'il se déplace, arrêtez l'exécution du script.

.. image:: img/16_star2.png