
    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_balloon:

2.12 JEU - Gonfler le Ballon
=========================================

Ici, nous allons jouer à un jeu de gonflage de ballon.

Après avoir cliqué sur le drapeau vert, le ballon deviendra de plus en plus gros. Si le ballon devient trop gros, il éclatera ; si le ballon est trop petit, il tombera. Vous devez juger quand appuyer sur le bouton pour le faire monter.

.. image:: img/13_balloon0.png

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Ce que vous apprendrez
--------------------------

- Peindre un costume pour le sprite


Construire le circuit
--------------------------

Le bouton est un dispositif à 4 broches, puisque la broche 1 est connectée à la broche 2, et la broche 3 à la broche 4, lorsque le bouton est enfoncé, les 4 broches sont connectées, fermant ainsi le circuit.

.. image:: img/5_buttonc.png

Construisez le circuit selon le schéma suivant.

* Connectez l'une des broches du côté gauche du bouton à la broche 14, qui est connectée à une résistance de tirage vers le bas et à un condensateur de 0,1uF (104) (pour éliminer les interférences et obtenir un niveau stable lorsque le bouton fonctionne).
* Connectez l'autre extrémité de la résistance et du condensateur à la masse, et l'une des broches du côté droit du bouton à 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programmation
-----------------

**1. Ajouter un sprite et un arrière-plan**

Supprimez le sprite par défaut, cliquez sur le bouton **Choisir un Sprite** dans le coin inférieur droit de la zone des sprites, puis sélectionnez le sprite **Balloon1**.

.. image:: img/13_balloon1.png

Ajoutez un arrière-plan **Boardwalk** via le bouton **Choisir un arrière-plan**, ou un autre arrière-plan de votre choix.

.. image:: img/13_balloon2.png

**2. Peindre un costume pour le sprite Balloon1**

Nous allons maintenant dessiner un costume d'effet d'explosion pour le sprite du ballon.

Allez à la page **Costumes** pour le sprite **Balloon1**, cliquez sur le bouton **Choisir un Costume** dans le coin inférieur gauche et sélectionnez **Peindre** pour afficher un **Costume** vierge.

.. image:: img/13_balloon7.png

Sélectionnez une couleur, puis utilisez l'outil **Pinceau** pour dessiner un motif.

.. image:: img/13_balloon3.png

Sélectionnez à nouveau une couleur, cliquez sur l'outil Remplir et déplacez la souris à l'intérieur du motif pour le remplir de couleur.

.. image:: img/13_balloon4.png

Enfin, écrivez le texte BOOM, pour créer un costume d'effet d'explosion complet.

.. image:: img/13_balloon5.png

**3. Programmer le sprite du ballon**

Définissez la position initiale et la taille du sprite **Balloon1**.

.. image:: img/13_balloon6.png

Ensuite, laissez le sprite **Balloon** grossir lentement.

.. image:: img/13_balloon8.png

Lorsque le bouton est enfoncé (valeur égale à 1), la taille du sprite **Balloon1** cesse d'augmenter.

* Lorsque la taille est inférieure à 90, il tombera (la coordonnée y diminue).
* Lorsque la taille est supérieure à 90 et inférieure à 120, il montera dans le ciel (la coordonnée y augmente).

.. image:: img/13_balloon9.png

Si le bouton n'a pas été enfoncé, le ballon grossit lentement et lorsque la taille dépasse 120, il éclatera (changer de costume pour l'effet d'explosion).

.. image:: img/13_balloon10.png
