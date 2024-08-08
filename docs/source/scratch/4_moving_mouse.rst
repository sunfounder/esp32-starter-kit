
    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_moving_mouse:

2.4 Souris en Mouvement
===========================

Aujourd'hui, nous allons fabriquer un jouet de souris contrôlé par un potentiomètre.

Lorsque le drapeau vert est cliqué, la souris sur la scène avance, et lorsque vous tournez le potentiomètre, la souris change de direction.

.. image:: img/6_mouse.png

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

Vous apprendrez
------------------

- Principe du potentiomètre
- Lire la broche analogique et les plages de valeurs
- Mapper une plage à une autre
- Déplacer et changer la direction du sprite

Construire le circuit
-----------------------

Le potentiomètre est un élément résistif à 3 bornes, les 2 broches latérales sont connectées à 5V et GND, et la broche centrale est connectée à la broche 35. Après conversion par le convertisseur ADC de l'ESP32, la plage de valeurs est de 0 à 4095.

.. image:: img/circuit/5_moving_mouse_bb.png

Programmation
-------------

**1. Choisir un sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choisir un sprite** dans le coin inférieur droit de la zone de sprites, entrez **mouse** dans la barre de recherche, puis cliquez pour l'ajouter.

.. image:: img/6_sprite.png

**2. Créer une variable**

Créez une variable appelée **value** pour stocker la valeur lue par le potentiomètre.

Une fois créée, vous verrez **value** apparaître dans la palette **Variables** et en état coché, ce qui signifie que cette variable apparaîtra sur la scène.

.. image:: img/6_value.png

**3. Lire la valeur de la broche 35**

Stockez la valeur lue de la broche 35 dans la variable **value**.

* [set my variable to 0] : Définit la valeur de la variable.
* [read analog pin ()] : Lit la valeur des broches dans la plage de 0 à 4095.

.. image:: img/6_read_a0.png

Pour pouvoir lire en continu, vous devez utiliser le bloc [forever]. Cliquez sur ce script pour le faire fonctionner, tournez le potentiomètre dans les deux sens, et vous verrez que la plage de valeurs est de 0 à 1023.

.. image:: img/6_1023.png

**4. Déplacer le sprite**

Utilisez le bloc [move steps] pour déplacer le sprite, exécutez le script et vous verrez le sprite se déplacer du milieu vers la droite.

.. image:: img/6_move.png

**5. Changer la direction du sprite**

Maintenant, changez la direction du mouvement du sprite en fonction de la valeur de la broche 35. Étant donné que la valeur de la broche 35 varie de 0 à 4095, mais que la direction de rotation du sprite est de -180 à 180, un bloc [map] doit être utilisé.

Ajoutez également [when green flag clicked] au début pour démarrer le script.

* [`point in direction <https://en.scratch-wiki.info/wiki/Point_in_Direction_()_(block)>`_] : Définit l'angle de direction du sprite, de la palette **Mouvement**.
* [map from to] : Mappe une plage à une autre.

.. image:: img/6_direction.png
