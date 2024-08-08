
    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_light_ball:

2.10 Balle Sensible à la Lumière
====================================

Dans ce projet, nous utilisons une photoresistance pour faire voler la balle sur la scène. Placez votre main au-dessus de la photoresistance pour contrôler l'intensité lumineuse qu'elle reçoit. Plus votre main est proche de la photoresistance, plus sa valeur est faible et plus la balle monte haut sur la scène, sinon elle tombe. Lorsque la balle touche la corde, elle émet un joli son ainsi qu'une lumière étoilée scintillante.

.. image:: img/18_ball.png

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Vous apprendrez
---------------------

- Remplir le sprite avec des couleurs
- Interaction entre les sprites

Construire le circuit
---------------------

Une photoresistance ou photocellule est une résistance variable contrôlée par la lumière. La résistance d'une photoresistance diminue avec l'augmentation de l'intensité lumineuse incidente.

Construisez le circuit selon le schéma suivant.

Connectez une extrémité de la photoresistance à 5V, l'autre extrémité à la broche 35, et connectez une résistance de 10K en série avec la masse (GND) à cette extrémité.

Ainsi, lorsque l'intensité lumineuse augmente, la résistance de la photoresistance diminue, la division de tension de la résistance de 10K augmente, et la valeur obtenue par la broche 35 devient plus grande.

.. image:: img/circuit/8_light_alarm_bb.png

Programmation
-----------------

L'effet que nous voulons obtenir est que plus votre main est proche de la photoresistance, plus le sprite de la balle sur la scène monte, sinon il tombera sur le sprite du bol. S'il touche le sprite de la ligne en montant ou en descendant, il produira un son musical et émettra des sprites étoilés dans toutes les directions.


**1. Sélectionnez le sprite et le fond**

Supprimez le sprite par défaut, sélectionnez les sprites **Ball**, **Bowl** et **Star**.

.. image:: img/18_ball1.png

Déplacez le sprite **Bowl** en bas au centre de la scène et agrandissez sa taille.

.. image:: img/18_ball3.png

Comme nous devons le déplacer vers le haut, réglez la direction du sprite **Ball** à 0.

.. image:: img/18_ball4.png

Réglez la taille et la direction du sprite **Star** à 180 car nous avons besoin qu'il tombe, ou vous pouvez le changer pour un autre angle.

.. image:: img/18_ball12.png

Ajoutez maintenant le fond **Stars**.

.. image:: img/18_ball2.png

**2. Dessinez un sprite Ligne**

Ajoutez un sprite Ligne.

.. image:: img/18_ball7.png

Allez à la page **Costumes** du sprite **Line**, réduisez légèrement la largeur de la ligne rouge sur la toile, puis copiez-la 5 fois et alignez les lignes.

.. image:: img/18_ball8.png

Remplissez maintenant les lignes avec différentes couleurs. Choisissez d'abord une couleur que vous aimez, puis cliquez sur l'outil **Fill** et déplacez la souris sur la ligne pour la remplir de couleur.

.. image:: img/18_ball9.png

Suivez la même méthode pour changer la couleur des autres lignes.

.. image:: img/18_ball10.png


**3. Programmer le sprite Ball**

Réglez la position initiale du sprite **Ball**, puis lorsque la valeur de la lumière est inférieure à 1500 (cela peut être une autre valeur, en fonction de votre environnement actuel), laissez la balle monter.

Vous pouvez faire apparaître la variable light_value sur la scène pour observer le changement d'intensité lumineuse à tout moment.

.. image:: img/18_ball5.png

Sinon, le sprite **Ball** tombera et limitera sa coordonnée Y à un minimum de -100. Cela peut être modifié pour qu'il semble tomber sur le sprite **Bowl**.

.. image:: img/18_ball6.png

Lorsque le sprite **Line** est touché, la coordonnée Y actuelle est enregistrée dans la variable **ball_coor** et un message **Bling** est diffusé.

.. image:: img/18_ball11.png

**4. Programmer le sprite Star**

Lorsque le script démarre, cachez d'abord le sprite **Star**. Lorsque le message **Bling** est reçu, clonez le sprite **Star**.

.. image:: img/18_ball13.png

Lorsque le sprite **Star** apparaît comme un clone, jouez l'effet sonore et réglez ses coordonnées pour qu'elles soient synchronisées avec le sprite **Ball**.

.. image:: img/18_ball14.png

Créez l'effet d'apparition du sprite **Star**, et ajustez-le si nécessaire.

.. image:: img/18_ball15.png
