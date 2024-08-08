.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_thermistor:

5.10 Thermomètre
===========================

Un thermistor est un capteur de température qui montre une forte dépendance à la température. Il peut être classé en deux types : Coefficient de Température Négatif (NTC) et Coefficient de Température Positif (PTC). La résistance d'un thermistor NTC diminue avec l'augmentation de la température, tandis que la résistance d'un thermistor PTC augmente avec l'augmentation de la température.

Dans ce projet, nous utiliserons un thermistor NTC. En connectant le thermistor NTC à une broche d'entrée analogique du microcontrôleur ESP32, nous pouvons mesurer sa résistance, qui est directement proportionnelle à la température.

En incorporant le thermistor NTC et en effectuant les calculs nécessaires, nous pouvons mesurer avec précision la température et l'afficher sur le module I2C LCD1602. Ce projet permet la surveillance en temps réel de la température et offre une interface visuelle pour l'affichage de la température.

**Composants requis**

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

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

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


**Pins disponibles**

* **Pins disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Pins disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Strapping Pins**

    Les broches suivantes sont des broches de configuration, qui affectent le processus de démarrage de l'ESP32 lors de la mise sous tension ou de la réinitialisation. Cependant, une fois que l'ESP32 a démarré avec succès, elles peuvent être utilisées comme broches ordinaires.

    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO0, IO12


**Schéma**

.. image:: ../../img/circuit/circuit_5.10_thermistor.png

Lorsque la température augmente, la résistance du thermistor diminue, ce qui fait diminuer la valeur lue sur I35. De plus, en utilisant une formule, vous pouvez convertir la valeur analogique en température et l'afficher.

**Câblage**

.. image:: ../../img/wiring/5.10_thermistor_bb.png


.. note::
    * Le thermistor est noir et marqué 103.
    * Les anneaux de couleur de la résistance de 10K ohms sont rouge, noir, noir, rouge et marron.

**Code**

.. note::

    * Ouvrez le fichier ``5.10_thermistor.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.10_thermistor``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d0407e3b-cd1e-4f5e-a7b6-391da394339b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après le téléversement réussi du code, le moniteur série affichera les températures en Celsius et Fahrenheit.

**Comment ça marche ?**

Chaque thermistor a une résistance normale. Ici, elle est de 10k ohms, mesurée à 25 degrés Celsius.

Lorsque la température augmente, la résistance du thermistor diminue. Ensuite, les données de tension sont converties en quantités numériques par l'adaptateur A/D.

La température en Celsius ou Fahrenheit est obtenue via la programmation.

Voici la relation entre la résistance et la température :

    **RT =RN expB(1/TK - 1/TN)** 

    * **RT** est la résistance du thermistor NTC lorsque la température est **TK**.
    * **RN** est la résistance du thermistor NTC à la température nominale TN. Ici, la valeur de RN est de 10k.
    * **TK** est une température en Kelvin et l'unité est K. Ici, la valeur de **TK** est ``273.15 + degré Celsius``.
    * **TN** est une température nominale en Kelvin; l'unité est également K. Ici, la valeur de TN est ``273.15+25``.
    * Et **B(beta)**, la constante matérielle du thermistor NTC, est également appelée indice de sensibilité thermique avec une valeur numérique de ``3950``.
    * **exp** est l'abréviation de l'exponentielle, et le nombre de base ``e`` est un nombre naturel et vaut environ 2.7.

    Convertissez cette formule ``TK=1/(ln(RT/RN)/B+1/TN)`` pour obtenir la température en Kelvin, moins 273.15 pour obtenir les degrés Celsius.

Cette relation est une formule empirique. Elle est précise uniquement lorsque la température et la résistance sont dans la plage effective.

**En savoir plus**

Vous pouvez également afficher les températures calculées en Celsius et Fahrenheit sur le module I2C LCD1602.

.. note::

    * Vous pouvez ouvrir le fichier ``5.10_thermistor_lcd.ino`` sous le chemin ``euler-kit/arduino/5.10_thermistor_lcd``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`
    * La bibliothèque ``LiquidCrystal I2C`` est utilisée ici, vous pouvez l'installer à partir du **Gestionnaire de Bibliothèques**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/93344677-8c5d-41d7-a833-f6365495d344/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

