.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_joystick:

Module Joystick
=======================

.. image:: img/joystick_pic.png
    :align: center
    :width: 600

* **GND** : Masse.
* **+5V** : Alimentation, accepte de 3,3V à 5V.
* **VRX** : Sortie analogique correspondant à la position horizontale (axe X) du joystick.
* **VRY** : Sortie analogique correspondant à la position verticale (axe Y) du joystick.
* **SW** : Sortie du bouton-poussoir, activée lorsque le joystick est enfoncé. Pour un fonctionnement correct, une résistance de tirage externe est nécessaire. Avec la résistance en place, la broche SW délivre un niveau haut au repos et passe au niveau bas lorsque le joystick est pressé.

L'idée de base d'un joystick est de traduire le mouvement d'un manche en informations électroniques qu'un ordinateur peut traiter.

Pour communiquer toute la gamme de mouvements à l'ordinateur, un joystick doit mesurer la position du manche sur deux axes - l'axe X (de gauche à droite) et l'axe Y (de haut en bas). Tout comme en géométrie de base, les coordonnées X-Y déterminent la position exacte du manche.

Pour déterminer la position du manche, le système de contrôle du joystick surveille simplement la position de chaque axe. La conception classique du joystick analogique réalise cela avec deux potentiomètres, ou résistances variables.

Le joystick dispose également d'une entrée numérique qui est activée lorsque le joystick est enfoncé.

.. image:: img/joystick318.png
    :align: center
    :width: 600
	
**Exemple**

* :ref:`ar_joystick` (Projet Arduino)
* :ref:`py_joystick` (Projet MicroPython)
* :ref:`sh_star_crossed` (Projet Scratch)
* :ref:`sh_dragon` (Projet Scratch)
