.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_avoid:

Module d'évitement d'obstacles
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Alimentation, 3.3 ~ 5V DC.
* **GND**: Masse
* **OUT**: Broche de signal, généralement à haut niveau, et à bas niveau lorsqu'un obstacle est détecté.

Le module d'évitement d'obstacles IR a une forte adaptabilité à la lumière ambiante, il est équipé d'une paire de tubes émetteurs et récepteurs infrarouges.

Le tube émetteur émet une fréquence infrarouge, lorsque la direction de détection rencontre un obstacle, le rayonnement infrarouge est reçu par le tube récepteur. Après traitement par le circuit comparateur, l'indicateur s'allume et un signal de bas niveau est émis.

La distance de détection peut être ajustée par potentiomètre, la plage de distance efficace étant de 2 à 30 cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Exemple**

* :ref:`ar_ir_obstacle` (Projet Arduino)
* :ref:`py_ir_obstacle` (Projet MicroPython)
* :ref:`sh_shooting` (Projet Scratch)
* :ref:`sh_tap_tile` (Projet Scratch)
