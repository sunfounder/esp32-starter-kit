
    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_shooting:

2.11 JEU - Tir
=============================

Avez-vous déjà vu ces jeux de tir à la télévision ? Plus un concurrent tire une balle près du centre de la cible, plus son score est élevé.

Aujourd'hui, nous allons également créer un jeu de tir dans Scratch. Dans le jeu, laissez la lunette de visée tirer le plus près possible du centre de la cible pour obtenir un score plus élevé.

Cliquez sur le drapeau vert pour commencer. Utilisez le module d'évitement d'obstacles pour tirer une balle.

.. image:: img/14_shooting.png

Composants nécessaires
-----------------------

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
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

Ce que vous apprendrez
-------------------------

- Comment fonctionne le module d'évitement d'obstacles et la plage d'angle
- Peindre différents sprites
- Toucher des couleurs

Construire le circuit
------------------------

Le module d'évitement d'obstacles est un capteur de proximité infrarouge ajustable en distance dont la sortie est normalement haute et basse lorsqu'un obstacle est détecté.

Construisez maintenant le circuit selon le schéma ci-dessous.

.. image:: img/circuit/12_shooting_bb.png

Programmation
-----------------

**1. Peindre le sprite de la lunette de visée**

Supprimez le sprite par défaut, sélectionnez le bouton **Sprite** et cliquez sur **Peindre**, un sprite vierge **Sprite1** apparaîtra et nommez-le **Lunette de visée**.

.. image:: img/14_shooting0.png

Allez à la page **Costumes** du sprite **Lunette de visée**. Cliquez sur l'outil **Cercle**, retirez la couleur de remplissage, et définissez la couleur et la largeur du contour.

.. image:: img/14_shooting02.png

Dessinez maintenant un cercle avec l'outil **Cercle**. Après avoir dessiné, vous pouvez cliquer sur l'outil **Sélectionner** et déplacer le cercle pour que le point d'origine soit aligné avec le centre de la toile.

.. image:: img/14_shooting03.png

En utilisant l'outil **Ligne**, dessinez une croix à l'intérieur du cercle.

.. image:: img/14_shooting033.png

**Peindre le sprite de la cible**

Créez un nouveau sprite appelé **Cible**.

.. image:: img/14_shooting01.png

Allez à la page **Costumes** du sprite **Cible**, cliquez sur l'outil **Cercle**, sélectionnez une couleur de remplissage et retirez le contour, puis peignez un grand cercle.

.. image:: img/14_shooting05.png

Utilisez la même méthode pour dessiner des cercles supplémentaires, chacun avec une couleur différente, et vous pouvez utiliser l'outil **Avancer** ou **Reculer** pour changer la position des cercles superposés. Notez que vous devez également sélectionner l'outil pour déplacer les cercles, de sorte que l'origine de tous les cercles et le centre de la toile soient alignés.

.. image:: img/14_shooting04.png

**3. Ajouter un fond**

Ajoutez un fond approprié, de préférence sans trop de couleurs et qui ne correspond pas aux couleurs du sprite **Cible**. Ici, j'ai choisi le fond **Wall1**.

.. image:: img/14_shooting06.png

**4. Programmer le sprite de la lunette de visée**

Définissez la position aléatoire et la taille du sprite **Lunette de visée**, et laissez-le se déplacer de manière aléatoire.

.. image:: img/14_shooting4.png

Lorsqu'une main est placée devant le module d'évitement d'obstacles, il émettra un niveau bas comme signal de transmission.

.. image:: img/14_shooting5.png

Lorsque le message **tir** est reçu, le sprite cesse de bouger et se rétrécit lentement, simulant ainsi l'effet d'une balle tirée.

.. image:: img/14_shooting6.png

Utilisez le bloc [Toucher la couleur ()] pour déterminer la position du tir.

.. image:: img/14_shooting7.png

Lorsque le tir est à l'intérieur du cercle jaune, un score de 10 est rapporté.

.. image:: img/14_shooting8.png

Utilisez la même méthode pour déterminer la position du tir de la balle, si elle n'est pas réglée sur le sprite **Cible**, cela signifie qu'elle est hors du cercle.

.. image:: img/14_shooting9.png
