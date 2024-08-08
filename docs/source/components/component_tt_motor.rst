.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_tt_motor:

Moteur TT
==============

.. image:: img/tt_motor.jpg
    :width: 400
    :align: center

Il s'agit d'un moteur à engrenages CC TT avec un rapport de réduction de 1:48, équipé de 2 fils de 200 mm avec des connecteurs mâles de 0,1" qui s'insèrent dans une breadboard. Parfait pour être branché dans une breadboard ou un bloc terminal.

Vous pouvez alimenter ces moteurs avec une tension de 3 à 6VDC, mais bien sûr, ils iront un peu plus vite à des tensions plus élevées.

Notez que ce sont des moteurs très basiques sans encodeur intégré, contrôle de vitesse ou retour de position. La tension entre et la rotation sort. Il y aura des variations d'un moteur à l'autre, donc si vous avez besoin d'un mouvement précis, vous aurez besoin d'un système de retour séparé.

**Détails techniques**

* Tension nominale : 3~6V
* Courant continu à vide : 150mA +/- 10%
* Vitesse minimale en fonctionnement (3V) : 90+/- 10% RPM
* Vitesse minimale en fonctionnement (6V) : 200+/- 10% RPM
* Couple de blocage (3V) : 0.4kg.cm
* Couple de blocage (6V) : 0.8kg.cm
* Rapport de réduction : 1:48
* Dimensions du corps : 70 x 22 x 18mm
* Longueur des fils : 200mm & 28 AWG
* Poids : 30.6g

**Schéma dimensionnel**

.. image:: img/motor_size.jpg

**Exemple**

* :ref:`ar_motor` (Projet Arduino)
* :ref:`py_motor` (Projet MicroPython)
* :ref:`sh_rotating_fan` (Projet Scratch)
