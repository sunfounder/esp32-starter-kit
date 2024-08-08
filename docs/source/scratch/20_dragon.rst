
    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_dragon:

2.20 JEU - Tuez le Dragon
===============================

Ici, nous utilisons le joystick pour jouer à un jeu de tuer le dragon.

En cliquant sur le drapeau vert, le dragon flottera de haut en bas sur le côté droit et crachera du feu par intermittence. Vous devez utiliser le joystick pour contrôler le mouvement de la baguette magique et lancer des attaques d'étoiles sur le dragon, tout en évitant les flammes qu'il tire, et finalement le vaincre.

.. image:: img/19_dragon.png

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

Construire le circuit
-------------------------

Un joystick est un dispositif d'entrée constitué d'un bâton qui pivote sur une base et indique son angle ou sa direction à l'appareil qu'il contrôle. Les joysticks sont souvent utilisés pour contrôler les jeux vidéo et les robots.

Pour communiquer une gamme complète de mouvements à l'ordinateur, un joystick doit mesurer la position du bâton sur deux axes - l'axe X (de gauche à droite) et l'axe Y (de haut en bas).

Les coordonnées de mouvement du joystick sont montrées dans la figure suivante.

.. note::

    * La coordonnée x va de gauche à droite, la plage est de 0-1023.
    * La coordonnée y va de haut en bas, la plage est de 0-1023.

.. image:: img/16_joystick.png


Construisez maintenant le circuit selon le schéma ci-dessous.

.. image:: img/circuit/14_star_crossed_bb.png

Programmation
-----------------

**1. Dragon**

Ajoutez le décor **Woods** via le bouton **Choisir un décor**.

.. image:: img/19_dragon01.png

* Supprimez le sprite par défaut et ajoutez le sprite **Dragon**.

.. image:: img/19_dragon0.png

* Allez à la page **Costumes** et inversez horizontalement les costumes dragon-b et dragon-c.

.. image:: img/19_dragon1.png

* Réglez la taille à 50%.

.. image:: img/19_dragon3.png

* Créez maintenant une variable - **dragon** pour enregistrer les points de vie du dragon, et définissez la valeur initiale à 50.

.. image:: img/19_dragon2.png

* Ensuite, changez le costume du sprite en **dragon-b** et faites en sorte que le sprite **Dragon** monte et descende dans une certaine plage.

.. image:: img/19_dragon4.png


* Ajoutez un sprite **Lightning** pour représenter le feu craché par le sprite **Dragon**. Vous devez le faire pivoter de 90° dans le sens des aiguilles d'une montre sur la page Costumes, afin que le sprite **Lightning** se déplace dans la bonne direction.

.. note::
    Lors de l'ajustement du costume du sprite **Lightning**, il peut se déplacer hors du centre, ce qui doit être évité ! Le point central doit être exactement au milieu du sprite !

.. image:: img/19_lightning1.png



* Ensuite, ajustez le costume **dragon-c** du sprite **Dragon** pour que son point central soit à la queue du feu. Cela rendra les positions du sprite **Dragon** et du sprite **Lightning** correctes, et empêchera **Lightning** de tirer depuis les pieds du dragon. 

.. image:: img/19_dragon5.png

* Correspondamment, **dragon-b** doit faire en sorte que la tête du dragon coïncide avec le point central.

.. image:: img/19_dragon5.png

* Ajustez la taille et l'orientation du sprite **Lightning** pour rendre l'image plus harmonieuse.

.. image:: img/19_lightning3.png

* Maintenant, script le sprite **Lightning**. C'est facile, il suffit de le faire suivre le sprite **Dragon** en permanence. À ce stade, cliquez sur le drapeau vert et vous verrez **Dragon** se déplacer avec des éclairs dans sa bouche.

.. image:: img/19_lightning4.png

* Retournez au sprite **Dragon**, maintenant faites-le cracher du feu, en veillant à ne pas laisser le feu dans sa bouche tirer, mais à créer un clone pour le sprite **Lightning**.

.. image:: img/19_dragon6.png

* Cliquez sur le sprite **Lightning** et laissez le clone **Lightning** tirer à un angle aléatoire, il rebondira sur le mur et disparaîtra après un certain temps.

.. image:: img/19_lightning5.png

* Dans le sprite **Lightning**, cachez son corps et montrez le clone.

.. image:: img/19_lightning6.png

Maintenant, le dragon peut monter et descendre et cracher du feu.


**2. Baguette**

* Créez un sprite **Wand** et faites-le pivoter de 180 pour pointer vers la droite.

.. image:: img/19_wand1.png

* Créez maintenant une variable **hp** pour enregistrer sa valeur de vie, initialement définie à 3. Ensuite, lisez la valeur du Joystick, qui est utilisée pour contrôler le mouvement de la baguette.

.. image:: img/19_wand2.png

* Le dragon a des éclairs, et la baguette qui le combat a ses "balles magiques" ! Créez un sprite **Star**, redimensionnez-le et script-le pour qu'il suive toujours le sprite **Wand**, et limitez le nombre d'étoiles à trois.

.. image:: img/19_star2.png

* Faites en sorte que le sprite **Wand** tire des étoiles automatiquement. Le sprite **Wand** tire des étoiles de la même manière que le dragon crache du feu -- en créant des clones.

.. image:: img/19_wand3.png


* Retournez au sprite **Star** et script son clone pour tourner et tirer vers la droite, disparaître après avoir dépassé la scène et restaurer le nombre d'étoiles. Comme le sprite **Lightning**, cachez le corps et montrez le clone.

.. image:: img/19_star3.png

Maintenant, nous avons une baguette qui tire des balles d'étoiles.

**3. Combattez !**

La baguette et le dragon sont actuellement encore en désaccord, et nous allons les faire se battre. Le dragon est puissant, et la baguette est le héros qui le combat. L'interaction entre eux se compose des parties suivantes.


1. si la baguette touche le dragon, elle sera repoussée et perdra des points de vie.
2. si l'éclair frappe la baguette, celle-ci perdra des points de vie.
3. si la balle d'étoile frappe le dragon, celui-ci perdra des points de vie.


Une fois cela clarifié, passons à la modification des scripts de chaque sprite.

* Si la **Wand** touche le **Dragon**, elle sera repoussée et perdra des points de vie.

.. image:: img/19_wand4.png

* Si **Lightning** (un clone du sprite **Lightning**) touche le sprite **Wand**, il fera un bruit de pop et disparaîtra, et la **Wand** perdra des points de vie.

.. image:: img/19_lightning7.png

* Si une **Star** (clone du sprite **Star**) touche le **Dragon**, elle émettra un son de collecte et disparaîtra, tout en restaurant le nombre de **Star**, et le **Dragon** perdra des points de vie.

.. image:: img/19_star4.png


**4. Scène**

Le combat entre la **Wand** et le **Dragon** se terminera par une victoire ou une défaite, que nous représenterons par la scène.

* Ajoutez le décor **Blue Sky**, et écrivez le caractère "WIN!" dessus pour représenter que le dragon a été vaincu et que l'aube est arrivée.


.. image:: img/19_sky0.png

* Et modifiez le décor vierge comme suit, pour représenter que le jeu a échoué et que tout sera dans l'obscurité.

.. image:: img/19_night.png

* Écrivez maintenant un script pour changer ces décors, lorsque le drapeau vert est cliqué, passez au décor **Woods** ; si le point de vie du dragon est inférieur à 1 , alors le jeu réussit et passe au décor **Blue Sky** ; si la valeur de vie de la **Wand** est inférieure à 1, alors passez au décor **Night** et le jeu échoue.


.. image:: img/19_sky1.png

