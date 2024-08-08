
    Bonjour, bienvenue dans la communauté des passionnés SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_eat_apple:

2.14 JEU - Manger la Pomme
==========================

Dans ce projet, nous jouons à un jeu où nous utilisons un bouton pour contrôler un scarabée afin qu'il mange une pomme.

Lorsque le drapeau vert est cliqué, appuyez sur le bouton et le scarabée tournera, appuyez à nouveau sur le bouton et le scarabée s'arrêtera et avancera dans cette direction. Vous devez contrôler l'angle du scarabée afin qu'il avance sans toucher la ligne noire du labyrinthe jusqu'à ce qu'il mange la pomme. S'il touche la ligne noire, le jeu est terminé.

.. image:: img/14_apple.png

Composants nécessaires
--------------------------

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Construire le circuit
-------------------------

Le bouton est un dispositif à 4 broches, car la broche 1 est connectée à la broche 2, et la broche 3 à la broche 4, lorsque le bouton est enfoncé, les 4 broches sont connectées, fermant ainsi le circuit.

.. image:: img/5_buttonc.png

Construisez le circuit selon le schéma suivant.

* Connectez l'une des broches du côté gauche du bouton à la broche 14, qui est reliée à une résistance de tirage et à un condensateur de 0,1uF (104) (pour éliminer les interférences et obtenir un niveau stable lorsque le bouton fonctionne).
* Connectez l'autre extrémité de la résistance et du condensateur à la masse, et l'une des broches du côté droit du bouton à 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programmation
-----------------
L'effet que nous voulons obtenir est d'utiliser le bouton pour contrôler la direction du sprite **Beetle** afin qu'il avance et mange la pomme sans toucher la ligne noire sur l'arrière-plan **Maze**, qui changera l'arrière-plan lorsqu'elle est mangée.

Ajoutez maintenant les arrière-plans et les sprites pertinents.

**1. Ajouter des arrière-plans et des sprites**

Ajoutez un arrière-plan **Maze** via le bouton **Choisir un arrière-plan**.

.. image:: img/14_backdrop.png

Supprimez le sprite par défaut, puis sélectionnez le sprite **Beetle**.

.. image:: img/14_sprite.png

Placez le sprite **Beetle** à l'entrée de l'arrière-plan **Maze**, en vous souvenant des valeurs des coordonnées x,y à ce moment-là, et redimensionnez le sprite à 40 %.

.. image:: img/14_sprite1.png

**2. Dessiner un arrière-plan**

Il est maintenant temps de dessiner simplement un arrière-plan avec le personnage WIN! qui y apparaît.

Cliquez d'abord sur la vignette de l'arrière-plan pour accéder à la page **Arrière-plans** et cliquez sur l'arrière-plan vierge 1.

.. image:: img/14_paint_back.png
    :width: 800

Commencez maintenant à dessiner, vous pouvez vous référer à l'image ci-dessous pour dessiner, ou vous pouvez dessiner un arrière-plan vous-même, tant que l'expression est gagnante.

* En utilisant l'outil **Cercle**, dessinez une ellipse avec la couleur définie sur le rouge et sans contour.
* Ensuite, utilisez l'outil **Texte**, écrivez le caractère "WIN!", définissez la couleur du caractère en noir et ajustez la taille et la position du caractère.
* Nommez l'arrière-plan **Win**.

.. image:: img/14_win.png

**3. Script pour l'arrière-plan**

L'arrière-plan doit être changé en **Maze** à chaque début de jeu.

.. image:: img/14_switchback.png

**4. Écrire des scripts pour le sprite Beetle**

Écrivez maintenant un script pour le sprite **Beetle** afin qu'il puisse avancer et changer de direction sous le contrôle d'un bouton. Le flux de travail est le suivant.

* Lorsque le drapeau vert est cliqué, définissez l'angle du **Beetle** à 90, et la position à (-134, -134), ou remplacez-la par la valeur des coordonnées de votre propre position. Créez la variable **flag** et définissez la valeur initiale à -1.

.. image:: img/14_bee1.png

Ensuite, dans le bloc [forever], quatre blocs [if] sont utilisés pour déterminer divers scénarios possibles.

* Si le bouton est 1 (enfoncé), utilisez le bloc [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] pour basculer la valeur de la variable **flag** entre 0 et 1 (alternant entre 0 pour cette pression et 1 pour la prochaine pression).

.. image:: img/14_bee2.png

* Si flag=0 (cette pression de bouton), laissez le sprite **Beetle** tourner dans le sens horaire. Ensuite, déterminez si flag est égal à 1 (bouton pressé à nouveau), le sprite **Beetle** avance. Sinon, il continue de tourner dans le sens horaire.

.. image:: img/14_bee3.png

* Si le sprite Beetle touche le noir (la ligne noire sur l'arrière-plan **Maze**), le jeu se termine et le script cesse de fonctionner.

.. note::
    
    Vous devez cliquer sur la zone de couleur dans le bloc [Toucher la couleur], puis sélectionner l'outil pipette pour choisir la couleur de la ligne noire sur la scène. Si vous choisissez un noir de manière arbitraire, ce bloc [Toucher la couleur] ne fonctionnera pas.

.. image:: img/14_bee5.png

* Si le scarabée touche le rouge (utilisez également l'outil pipette pour choisir la couleur rouge de la pomme), l'arrière-plan sera changé en **Win**, ce qui signifie que le jeu réussit et arrête le script de fonctionner.

.. image:: img/14_bee4.png
