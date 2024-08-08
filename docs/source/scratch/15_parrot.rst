
    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_parrot:

2.15 JEU - Flappy Parrot
===========================

Ici, nous utilisons le module ultrason pour jouer à un jeu de flappy parrot.

Après avoir lancé le script, le bambou vert se déplacera lentement de droite à 
gauche à une hauteur aléatoire. Placez votre main au-dessus du module ultrason, 
si la distance entre votre main et le module ultrason est inférieure à 10 cm, le 
perroquet s'envolera vers le haut, sinon il tombera vers le bas. Vous devez contrôler 
la distance entre votre main et le module ultrason afin que le perroquet puisse éviter 
le bambou vert (Paddle). S'il le touche, le jeu est terminé.

.. image:: img/15_parrot.png

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Construire le circuit
-----------------------

Un module capteur ultrason est un instrument qui mesure la distance à un objet en utilisant des ondes sonores ultrasoniques. Il a deux sondes. L'une est pour envoyer des ondes ultrasoniques et l'autre pour recevoir les ondes et transformer le temps d'émission et de réception en une distance, détectant ainsi la distance entre l'appareil et un obstacle.

Construisez maintenant le circuit selon le schéma suivant.

.. image:: img/circuit/16_flappy_parrot_bb.png

Programmation
-----------------

L'effet que nous voulons obtenir est d'utiliser le module ultrason pour contrôler la hauteur de vol du sprite **Parrot**, tout en évitant le sprite **Paddle**.


**1. Ajouter un sprite**

Supprimez le sprite par défaut et utilisez le bouton **Choisir un Sprite** pour ajouter le sprite **Parrot**. Réglez sa taille à 50 % et déplacez-le au centre gauche.

.. image:: img/15_sprite.png

Ajoutez maintenant le sprite **Paddle**, réglez sa taille à 150 %, son angle à 180 et déplacez sa position initiale dans le coin supérieur droit.

.. image:: img/15_sprite1.png

Allez à la page **Costumes** du sprite **Paddle** et supprimez le contour.

.. image:: img/15_sprite2.png

**2. Script pour le sprite Parrot**

Écrivez maintenant le script pour le sprite **Parrot**, qui est en vol et dont l'altitude est déterminée par la distance de détection du module ultrason.


* Lorsque le drapeau vert est cliqué, changez de costume toutes les 0,2s pour qu'il soit toujours en vol.

.. image:: img/15_parr1.png

* Lisez la valeur du module ultrason et stockez-la dans la variable **distance** après l'avoir arrondie avec le bloc [arrondir].

.. image:: img/15_parr2.png

* Si la distance de détection ultrason est inférieure à 10 cm, laissez la coordonnée y augmenter de 50, le sprite **Parrot** s'envolera vers le haut. Sinon, la valeur de la coordonnée y diminue de 40, **Parrot** tombera.

.. image:: img/15_parr3.png

* Si le sprite **Parrot** touche le sprite **Paddle**, le jeu se termine et le script cesse de fonctionner.

.. image:: img/15_parr4.png


**3. Script pour le sprite Paddle**

Écrivez maintenant le script pour le sprite **Paddle**, qui doit apparaître de manière aléatoire sur la scène.

* Cachez le sprite **Paddle** lorsque le drapeau vert est cliqué et clonez-le en même temps. Le bloc [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] est un bloc de contrôle et un bloc empilable. Il crée un clone du sprite dans l'argument. Il peut également cloner le sprite dans lequel il est exécuté, créant des clones de clones, de manière récursive.

.. image:: img/15_padd.png

* Lorsque **Paddle** est présenté comme un clone, sa position est 220 (extrême droite) pour la coordonnée x et sa coordonnée y est aléatoire (-125 à 125) (hauteur aléatoire).

.. image:: img/15_padd1.png

* Utilisez le bloc [répéter] pour que la valeur de sa coordonnée x diminue lentement, de sorte que vous puissiez voir le clone du sprite **Paddle** se déplacer lentement de droite à gauche jusqu'à ce qu'il disparaisse.

.. image:: img/15_padd2.png

* Reclonez un nouveau sprite **Paddle** et supprimez le clone précédent.

.. image:: img/15_padd3.png
