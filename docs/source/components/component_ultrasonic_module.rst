.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_ultrasonic:

Module Ultrasonique
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG** : Entrée d'impulsion de déclenchement
* **ECHO** : Sortie d'impulsion d'écho
* **GND** : Masse
* **VCC** : Alimentation 5V

Ceci est le capteur de distance ultrasonique HC-SR04, offrant une mesure sans contact de 2 cm à 400 cm avec une précision de portée allant jusqu'à 3 mm. Le module comprend un émetteur ultrasonique, un récepteur et un circuit de contrôle.

Vous n'avez besoin de connecter que 4 broches : VCC (alimentation), Trig (déclencheur), Echo (réception) et GND (masse) pour l'utiliser facilement dans vos projets de mesure.

**Caractéristiques**

* Tension de fonctionnement : DC5V
* Courant de fonctionnement : 16mA
* Fréquence de fonctionnement : 40Hz
* Portée maximale : 500cm
* Portée minimale : 2cm
* Signal d'entrée de déclenchement : impulsion TTL de 10uS
* Signal de sortie d'écho : signal niveau TTL et portée proportionnelle
* Connecteur : XH2.54-4P
* Dimensions : 46x20.5x15 mm

**Principe**

Les principes de base sont les suivants :

* Utiliser la broche IO pour déclencher un signal haut d'au moins 10us.

* Le module envoie une rafale de 8 cycles d'ultrasons à 40 kHz et détecte si un signal d'impulsion est reçu.

* Echo sortira un niveau haut si un signal est renvoyé ; la durée du niveau haut est le temps écoulé entre l'émission et le retour.

* Distance = (temps du niveau haut x vitesse du son (340M/S)) / 2

.. image:: img/ultrasonic_prin.jpg

Formule :

* us / 58 = distance en centimètres
* us / 148 = distance en pouces
* distance = temps du niveau haut x vitesse (340M/S) / 2

.. note::

    Ce module ne doit pas être connecté sous tension, si nécessaire, connectez d'abord la masse du module. Sinon, cela affectera le fonctionnement du module.

    La surface de l'objet à mesurer doit être d'au moins 0,5 mètre carré et aussi plate que possible. Sinon, cela affectera les résultats.

**Exemple**

* :ref:`ar_ultrasonic` (Projet Arduino)
* :ref:`ar_reversing_aid` (Projet Arduino)
* :ref:`py_ultrasonic` (Projet MicroPython)
* :ref:`py_reversing_aid` (Projet MicroPython)
* :ref:`sh_parrot` (Projet Scratch)

