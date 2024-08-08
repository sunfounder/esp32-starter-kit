
    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_low_temperature:

2.6 Alarme de Basse Température
====================================

Dans ce projet, nous allons créer un système d'alarme de basse température. Lorsque la température descend en dessous du seuil, le sprite **Flocon de neige** apparaîtra sur la scène.

.. image:: img/9_tem.png

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

Vous apprendrez
------------------

- Principe de fonctionnement du thermistor
- Opérations multivariables et soustractives

Construire le circuit
--------------------------

Un thermistor est un type de résistance dont la résistance dépend fortement de la température, plus que dans les résistances standard. Il existe deux types de résistances : PTC (la résistance augmente avec la température) et NTC (la résistance diminue avec la température).

Construisez le circuit selon le schéma suivant.

Une extrémité du thermistor est connectée à la masse (GND), l'autre extrémité est connectée à la broche 35, et une résistance de 10K est connectée en série à 5V.

Le thermistor NTC est utilisé ici, donc lorsque la température augmente, la résistance du thermistor diminue, la division de tension de la broche 35 diminue, et la valeur obtenue de la broche 35 diminue, et vice versa augmente.

.. image:: img/circuit/7_low_temp_bb.png

Programmation
------------------

**1. Sélectionner un sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choisir un sprite** dans le coin inférieur droit de la zone des sprites, entrez **Flocon de neige** dans la barre de recherche, puis cliquez pour l'ajouter.

.. image:: img/9_snow.png

**2. Créer 2 variables**

Créez deux variables, **avant** et **actuel**, pour stocker la valeur de la broche 35 dans différents cas.

.. image:: img/9_va.png

**3. Lire la valeur de la broche 35**

Lorsque le drapeau vert est cliqué, la valeur de la broche 35 est lue et stockée dans la variable **avant**.

.. image:: img/9_before.png

**4. Lire à nouveau la valeur de la broche 35**

Dans [toujours], lisez à nouveau la valeur de la broche 35 et stockez-la dans la variable **actuel**.

.. image:: img/9_current.png

**5. Déterminer les changements de température**

En utilisant le bloc [si alors], déterminez si la valeur actuelle de la broche 35 est supérieure de 200 à la valeur précédente, ce qui représente une baisse de température. À ce moment, laissez le sprite **Flocon de neige** apparaître, sinon, cachez-le.

* [-] & [>] : opérateurs de soustraction et de comparaison de la palette **Opérateurs**.

.. image:: img/9_show.png
