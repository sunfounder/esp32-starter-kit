
    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_doorbell:

2.5 Sonnette
======================

Ici, nous allons utiliser le bouton et la cloche sur la scène pour fabriquer une sonnette.

Après avoir cliqué sur le drapeau vert, vous pouvez appuyer sur le bouton et la cloche sur la scène émettra un son.

.. image:: img/7_doorbell.png

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Vous apprendrez
-------------------

- Fonctionnement du bouton
- Lecture des broches numériques et plages de valeurs
- Création d'une boucle conditionnelle
- Ajout d'un décor
- Lecture d'un son

Construire le circuit
-----------------------

Le bouton est un dispositif à 4 broches, puisque la broche 1 est connectée à la broche 2, et la broche 3 à la broche 4, lorsque le bouton est pressé, les 4 broches sont connectées, fermant ainsi le circuit.

.. image:: img/5_buttonc.png

Construisez le circuit selon le schéma suivant.

* Connectez l'une des broches du côté gauche du bouton à la broche 14, qui est connectée à une résistance de tirage et à un condensateur de 0,1uF (104) (pour éliminer le jitter et obtenir un niveau stable lorsque le bouton fonctionne).
* Connectez l'autre extrémité de la résistance et du condensateur à la masse, et l'une des broches du côté droit du bouton à 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programmation
-----------------

**1. Ajouter un décor**

Cliquez sur le bouton **Choisir un décor** dans le coin inférieur droit.

.. image:: img/7_backdrop.png

Choisissez **Chambre 1**.

.. image:: img/7_bedroom2.png

**2. Sélectionner le sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choisir un sprite** dans le coin inférieur droit de la zone des sprites, entrez **cloche** dans la barre de recherche, puis cliquez pour l'ajouter.

.. image:: img/7_sprite.png

Ensuite, sélectionnez le sprite **cloche** sur la scène et déplacez-le à la position souhaitée.

.. image:: img/7_doorbell.png

**3. Appuyer sur le bouton et la cloche émet un son**

Utilisez [si alors] pour créer une instruction conditionnelle indiquant que lorsque la valeur de la broche 14 lue est égale à 1 (le bouton est pressé), le son **xylo1** sera joué.

* [lire le statut de la broche numérique] : Ce bloc provient de la palette **ESP32** et est utilisé pour lire la valeur d'une broche numérique, le résultat est 0 ou 1.
* [`if then <https://en.scratch-wiki.info/wiki/If_()_Then_(block)>`_] : Ce bloc est un bloc de contrôle provenant de la palette **Contrôle**. Si sa condition booléenne est vraie, les blocs contenus à l'intérieur s'exécuteront, puis le script impliqué continuera. Si la condition est fausse, les scripts à l'intérieur du bloc seront ignorés. La condition n'est vérifiée qu'une seule fois ; si la condition devient fausse pendant l'exécution du script à l'intérieur du bloc, celui-ci continuera à s'exécuter jusqu'à ce qu'il soit terminé.
* [jouer le son jusqu'à la fin] : Ce bloc provient de la palette Son, utilisé pour jouer des sons spécifiques.

.. image:: img/7_bell.png
