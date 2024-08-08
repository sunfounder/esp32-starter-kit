
    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_fishing:

2.17 JEU - Pêche
====================

Ici, nous jouons à un jeu de pêche avec un bouton.

Lorsque le script est en cours d'exécution, les poissons nagent de gauche à droite sur la scène, vous devez appuyer sur le bouton lorsque le poisson est presque proche de l'hameçon (il est recommandé de l'appuyer plus longtemps) pour attraper le poisson, et le nombre de poissons capturés sera enregistré automatiquement.

.. image:: img/18_fish.png

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Construire le circuit
-------------------------

Le bouton est un dispositif à 4 broches, puisque la broche 1 est connectée à la broche 2, et la broche 3 à la broche 4, lorsque le bouton est pressé, les 4 broches sont connectées, fermant ainsi le circuit.

.. image:: img/5_buttonc.png

Construisez le circuit selon le schéma suivant.

* Connectez l'une des broches du côté gauche du bouton à la broche 14, qui est connectée à une résistance pull-down et un condensateur de 0,1uF (104) (pour éliminer les interférences et fournir un niveau stable lorsque le bouton est activé).
* Connectez l'autre extrémité de la résistance et du condensateur à la masse (GND), et l'une des broches du côté droit du bouton à 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programmation
-----------------

Nous devons d'abord sélectionner un décor **Sous-marin**, puis ajouter un sprite **Poisson** et le faire nager de gauche à droite sur la scène. Ensuite, dessinez un sprite **Hameçon** et contrôlez-le avec un bouton pour commencer à pêcher. Lorsque le sprite **Poisson** touche le sprite **Hameçon** dans l'état de pêche (devient rouge), il sera capturé.

**1. Ajout d'un décor**

Utilisez le bouton **Choisir un décor** pour ajouter un décor **Sous-marin**.

.. image:: img/18_under.png

**2. Sprite Hameçon**

Le sprite **Hameçon** reste généralement sous l'eau en état jaune ; lorsque le bouton est pressé, il est en état de pêche (rouge) et se déplace au-dessus de la scène.

Il n'y a pas de sprite **Hameçon** dans Pictoblox, nous pouvons modifier le sprite **Glow-J** pour ressembler à un hameçon.

* Ajoutez le sprite **Glow-J** via **Choisir un Sprite**.

.. image:: img/18_hook.png

* Allez maintenant à la page **Costumes** du sprite **Glow-J**, sélectionnez le remplissage cyan à l'écran et supprimez-le. Ensuite, changez la couleur du J en rouge et réduisez également sa largeur. Le point le plus important à noter est que vous devez avoir le sommet juste au point central.

.. image:: img/18_hook1.png

* Utilisez l'outil **Ligne** pour dessiner une ligne aussi longue que possible depuis le point central vers le haut (ligne hors de la scène). Une fois le sprite dessiné, renommez-le **Hameçon** et déplacez-le à la bonne position.

.. image:: img/18_hook2.png

* Lorsque le drapeau vert est cliqué, définissez l'effet de couleur du sprite à 30 (jaune) et définissez sa position initiale.

.. image:: img/18_hook3.png

* Si le bouton est pressé, définissez l'effet de couleur à 0 (rouge, état de pêche), attendez 0,1 seconde puis déplacez le sprite **Hameçon** vers le haut de la scène. Relâchez le bouton et laissez l'**Hameçon** revenir à sa position initiale.

.. image:: img/18_hook4.png

**3. Sprite Poisson**

L'effet à obtenir pour le sprite **Poisson** est qu'il se déplace de gauche à droite sur la scène, et lorsqu'il rencontre un sprite **Hameçon** en état de pêche, il rétrécit et se déplace vers une position spécifique avant de disparaître, puis clone un nouveau sprite **Poisson**.

* Ajoutez maintenant le sprite **Poisson** et ajustez sa taille et sa position.

.. image:: img/18_fish1.png

* Créez une variable **score** pour stocker le nombre de poissons capturés, cachez ce sprite et clonez-le.

.. image:: img/18_fish2.png

* Affichez le clone du sprite **Poisson**, changez son costume et enfin définissez la position initiale.

.. image:: img/18_fish3.png

* Faites en sorte que le clone du sprite **Poisson** se déplace de gauche à droite et rebondisse lorsqu'il touche le bord.

.. image:: img/18_fish4.png

* Le sprite **Poisson** (du clone) ne réagira pas lorsqu'il passe devant le sprite **Hameçon** ; lorsqu'il touche le sprite **Hameçon** en état de pêche (devient rouge), il sera capturé, à ce moment-là, le score (variable score) +1, et il affichera également une animation de score (rétrécit de 40%, se déplace rapidement vers la position du tableau de score et disparaît). En même temps, un nouveau poisson est créé (un nouveau clone de sprite Poisson) et le jeu continue.

.. note::

    Vous devez cliquer sur la zone de couleur dans le bloc [Toucher la couleur], puis sélectionner l'outil pipette pour choisir la couleur rouge du sprite **Hameçon** sur la scène. Si vous choisissez une couleur arbitrairement, ce bloc [Toucher la couleur] ne fonctionnera pas.

.. image:: img/18_fish5.png
