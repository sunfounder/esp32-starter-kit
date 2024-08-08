
    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_breakout_clone:

2.16 JEU - Breakout Clone
============================

Ici, nous utilisons le potentiomètre pour jouer à un jeu Breakout Clone.

Après avoir cliqué sur le drapeau vert, vous devez utiliser le potentiomètre pour contrôler la raquette sur la scène afin d'attraper la balle pour qu'elle monte et frappe les briques. Si toutes les briques disparaissent, le jeu est gagné ; si vous ne parvenez pas à attraper la balle, le jeu est perdu.

.. image:: img/17_brick.png

Composants nécessaires
---------------------------

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

Construire le circuit
-----------------------

Le potentiomètre est un élément résistif à 3 bornes, les 2 broches latérales sont connectées à 5V et GND, et la broche centrale est connectée à la broche 35. Après conversion par le convertisseur ADC de la carte esp32, la plage de valeurs est de 0 à 4095.

.. image:: img/circuit/5_moving_mouse_bb.png

Programmation
-----------------

Il y a 3 sprites sur la scène.

**1. Sprite de la raquette**

L'effet à obtenir pour la **Raquette** est que sa position initiale soit au milieu du bas de la scène, et qu'elle soit contrôlée par un potentiomètre pour se déplacer vers la gauche ou vers la droite.

* Supprimez le sprite par défaut, utilisez le bouton **Choisir un Sprite** pour ajouter le sprite **Raquette**, et définissez ses coordonnées x et y à (0, -140).

    .. image:: img/17_padd1.png

* Allez à la page **Costumes**, retirez le contour et changez sa couleur en gris foncé.

    .. image:: img/17_padd3.png

* Maintenant, script le sprite **Raquette** pour définir sa position initiale à (0, -140) lorsque le drapeau vert est cliqué, et lisez la valeur de la broche 35 (potentiomètre) dans la variable **a0**. Étant donné que le sprite **Raquette** se déplace de gauche à droite sur la scène avec des coordonnées x de -195 à 195, vous devez utiliser le bloc [map] pour mapper la plage de la variable **a0** de 0 à 4095 à -195 à 195.

    .. image:: img/17_padd2.png

* Maintenant, vous pouvez tourner le potentiomètre pour voir si la **Raquette** peut se déplacer à gauche et à droite sur la scène.

**2. Sprite de la balle**

L'effet du sprite de la balle est qu'il se déplace autour de la scène et rebondit lorsqu'il touche le bord ; il rebondit vers le bas s'il touche le bloc au-dessus de la scène ; il rebondit vers le haut s'il touche le sprite Raquette pendant sa chute ; sinon, le script cesse de fonctionner et le jeu se termine.

* Ajoutez le sprite **Balle**.

    .. image:: img/17_ball1.png

* Lorsque le drapeau vert est cliqué, définissez l'angle du sprite **Balle** à 45° et définissez la position initiale à (0, -120).

    .. image:: img/17_ball2.png

* Maintenant, laissez le sprite **Balle** se déplacer autour de la scène et rebondir lorsqu'il touche le bord, et vous pouvez cliquer sur le drapeau vert pour voir l'effet.

    .. image:: img/17_ball3.png

* Lorsque le sprite **Balle** touche le sprite **Raquette**, faites une réflexion. La façon simple de le faire est de laisser l'angle être directement inversé, mais vous constaterez alors que le chemin de la balle est complètement fixe, ce qui est trop ennuyeux. Par conséquent, nous utilisons le centre des deux sprites pour calculer et faire rebondir la balle dans la direction opposée au centre de la raquette.

    .. image:: img/17_ball4.png

    .. image:: img/17_ball6.png

* Lorsque le sprite **Balle** tombe sur le bord de la scène, le script cesse de fonctionner et le jeu se termine.

    .. image:: img/17_ball5.png
        

**3. Sprite Block1**

Le sprite **Block1** doit apparaître avec l'effet de clonage de 4x8 d'elle-même au-dessus de la scène dans une couleur aléatoire, et supprimer un clone s'il est touché par le sprite **Balle**.

Le sprite **Block1** n'est pas disponible dans la bibliothèque **PictoBlox**, vous devez le dessiner vous-même ou le modifier avec un sprite existant. Ici, nous allons le modifier avec le sprite **Button3**.

* Après avoir ajouté le sprite **Button3**, allez à la page **Costumes**. Supprimez d'abord **button-a**, puis réduisez à la fois la largeur et la hauteur de **button-b**, et changez le nom du sprite en **Block1**, comme montré dans l'image suivante.

    .. note::

        * Pour la largeur de **Block1**, vous pouvez probablement la simuler à l'écran pour voir si vous pouvez en mettre 8 dans une rangée. Sinon, réduisez la largeur de manière appropriée.
        * Pendant le processus de réduction du sprite **Block1**, vous devez maintenir le point central au milieu du sprite.

    .. image:: img/17_bri2.png

* Créez maintenant d'abord 2 variables, **block** pour stocker le nombre de blocs et **roll** pour stocker le nombre de rangées.

    .. image:: img/17_bri3.png

* Nous devons créer un clone du sprite **Block1**, de sorte qu'il s'affiche de gauche à droite, de haut en bas, un par un, 4x8 au total, avec des couleurs aléatoires.

    .. image:: img/17_bri4.png

* Une fois le script écrit, cliquez sur le drapeau vert et regardez l'affichage sur la scène. Si c'est trop compact ou trop petit, vous pouvez changer la taille.

    .. image:: img/17_bri5.png

* Maintenant, écrivez l'événement déclencheur. Si le sprite cloné **Block1** touche le sprite **Balle**, supprimez le clone et diffusez le message **crush**.

    .. image:: img/17_bri6.png

* Retournez au sprite **Balle**, lorsque le message **crush** est reçu (le sprite **Balle** touche le clone du sprite **Block1**), la **Balle** est renvoyée dans la direction opposée.

    .. image:: img/17_ball7.png
