.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_soil_moisture:

Module de Détection d'Humidité du Sol
==========================================

.. image:: img/soil_mositure.png

* GND : Masse
* VCC : Alimentation, 3.3V ~ 5V
* AOUT : Sortie de la valeur d'humidité du sol, plus le sol est humide, plus la valeur est faible.

Ce capteur d'humidité du sol capacitif est différent de la plupart des capteurs résistifs disponibles sur le marché. Il utilise le principe de l'induction capacitive pour détecter l'humidité du sol. Il évite le problème de la corrosion auquel les capteurs résistifs sont très sensibles et prolonge considérablement sa durée de vie.

Fabriqué avec des matériaux résistants à la corrosion, il a une excellente durée de vie. Insérez-le dans le sol autour des plantes et surveillez en temps réel les données d'humidité du sol. Le module comprend un régulateur de tension intégré qui lui permet de fonctionner sur une plage de tension de 3.3 ~ 5.5 V. Il est idéal pour les microcontrôleurs basse tension avec des alimentations de 3.3 V et 5 V.

Le schéma matériel du capteur d'humidité du sol capacitif est montré ci-dessous.

.. image:: img/solid_schematic.png

Il y a un oscillateur à fréquence fixe, construit avec un CI temporisateur 555. L'onde carrée générée est ensuite envoyée au capteur comme un condensateur. Cependant, pour le signal d'onde carrée, le condensateur a une certaine réactance ou, pour simplifier, une résistance pure (résistance de 10k sur la broche 3) pour former un diviseur de tension.

Plus l'humidité du sol est élevée, plus la capacité du capteur est grande. En conséquence, l'onde carrée a moins de réactance, ce qui réduit la tension sur la ligne de signal, et plus la valeur de l'entrée analogique via le microcontrôleur est faible.


**Spécifications**

* Tension de fonctionnement : 3.3 ~ 5.5 VDC
* Tension de sortie : 0 ~ 3.0 VDC
* Courant de fonctionnement : 5 mA
* Interface : PH2.0-3P
* Dimensions : 3.86 x 0.905 pouces (L x l)
* Poids : 15 g

**Exemple**

* :ref:`ar_moisture` (Projet Arduino)
* :ref:`ar_plant_monitor` (Projet Arduino)
* :ref:`py_moisture` (Projet MicroPython)
* :ref:`py_plant_monitor` (Projet MicroPython)

