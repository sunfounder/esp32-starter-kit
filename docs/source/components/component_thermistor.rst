.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_thermistor:

Thermistance
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Une thermistance est un type de résistance dont la valeur est fortement dépendante de la température, beaucoup plus que les résistances standard. Le mot est une combinaison de thermique et résistance. Les thermistances sont largement utilisées comme limiteurs de courant d'appel, capteurs de température (généralement de type à coefficient de température négatif ou NTC), protecteurs de surintensité réarmables et éléments chauffants auto-régulés (généralement de type à coefficient de température positif ou PTC).

* `Thermistor - Wikipedia <https://en.wikipedia.org/wiki/Thermistor>`_

Voici le symbole électronique de la thermistance.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

Il existe deux types fondamentaux de thermistances :

* Avec les thermistances NTC, la résistance diminue à mesure que la température augmente, généralement en raison d'une augmentation des électrons de conduction stimulés par l'agitation thermique depuis la bande de valence. Un NTC est couramment utilisé comme capteur de température, ou en série avec un circuit comme limiteur de courant d'appel.
* Avec les thermistances PTC, la résistance augmente à mesure que la température augmente, généralement en raison des agitations thermiques accrues du réseau, notamment celles des impuretés et des imperfections. Les thermistances PTC sont couramment installées en série avec un circuit et utilisées pour protéger contre les conditions de surintensité, comme fusibles réarmables.

Dans ce kit, nous utilisons une thermistance NTC. Chaque thermistance a une résistance nominale. Ici, elle est de 10k ohms, mesurée à 25 degrés Celsius.

Voici la relation entre la résistance et la température :

    RT = RN * expB(1/TK - 1/TN)   

* **RT** est la résistance de la thermistance NTC lorsque la température est TK. 
* **RN** est la résistance de la thermistance NTC sous la température nominale TN. Ici, la valeur numérique de RN est 10k.
* **TK** est une température en Kelvin et l'unité est K. Ici, la valeur numérique de TK est 273,15 + degrés Celsius.
* **TN** est une température nominale en Kelvin ; l'unité est également K. Ici, la valeur numérique de TN est 273,15 + 25.
* Et **B(beta)**, la constante matérielle de la thermistance NTC, est également appelée indice de sensibilité thermique avec une valeur numérique de 3950.      
* **exp** est l'abréviation de l'exponentielle, et le nombre de base e est un nombre naturel et vaut environ 2,7.  

Convertissez cette formule TK=1/(ln(RT/RN)/B+1/TN) pour obtenir la température en Kelvin moins 273,15, ce qui donne la température en degrés Celsius.

Cette relation est une formule empirique. Elle est précise uniquement lorsque la température et la résistance sont dans la plage effective.

**Exemple**

* :ref:`ar_thermistor` (Projet Arduino)
* :ref:`ar_iot_mqtt` (Projet Arduino)
* :ref:`py_thermistor` (Projet MicroPython)
* :ref:`sh_low_temperature` (Projet Scratch)
