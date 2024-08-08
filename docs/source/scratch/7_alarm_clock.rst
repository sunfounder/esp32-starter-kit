
    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_light_alarm:

2.7 Réveil Lumineux
========================

Dans ce projet, nous allons créer un réveil contrôlé par la lumière. Lorsque le matin arrive et que la luminosité augmente, ce réveil lumineux vous rappellera qu'il est temps de vous lever.

.. image:: img/10_clock.png

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|


Vous apprendrez
---------------


- Principe de fonctionnement de la photorésistance
- Arrêt de la lecture du son et arrêt des scripts en cours

Construire le circuit
---------------------

Une photorésistance ou cellule photoélectrique est une résistance variable contrôlée 
par la lumière. La résistance d'une photorésistance diminue avec l'augmentation de l'intensité lumineuse incidente.

Construisez le circuit selon le schéma suivant.

Connectez une extrémité de la photorésistance à 5V, l'autre extrémité à la broche 35, et connectez une résistance de 10K en série avec la masse (GND) à cette extrémité.

Ainsi, lorsque l'intensité lumineuse augmente, la résistance de la photorésistance diminue, la division de tension de la résistance de 10K augmente, et la valeur obtenue par la broche 35 devient plus grande.

.. image:: img/circuit/8_light_alarm_bb.png

Programmation
-----------------

**1. Sélectionner un sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choisir un sprite** dans le coin inférieur droit de la zone des sprites, entrez **cloche** dans la barre de recherche, puis cliquez pour l'ajouter.

.. image:: img/10_sprite.png

**2. Lire la valeur de la broche 35**

Créez deux variables **avant** et **actuel**. Lorsque le drapeau vert est cliqué, lisez la valeur de la broche 35 et stockez-la dans la variable **avant** comme valeur de référence. Dans [toujours], lisez à nouveau la valeur de la broche 35 et stockez-la dans la variable **actuel**.

.. image:: img/10_reada0.png

**3. Émettre un son**

Lorsque la valeur actuelle de la broche 35 est supérieure de 50 à la valeur précédente, ce qui représente une intensité lumineuse actuelle supérieure au seuil, faites émettre un son au sprite.

.. image:: img/10_sound.png

**4. Faire tourner le sprite**

Utilisez le bloc [tourner] pour faire tourner le sprite **cloche** à gauche et à droite afin de créer un effet d'alarme.

.. image:: img/10_turn.png

**5. Tout arrêter**

Arrêtez l'alarme lorsqu'elle a sonné pendant un certain temps.

.. image:: img/10_stop.png
