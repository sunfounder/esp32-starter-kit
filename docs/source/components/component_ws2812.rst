.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_ws2812:

Bande LED RGB WS2812 8 LEDs
================================

.. image:: img/ws2812b.png

La bande LED RGB WS2812 8 LEDs est composée de 8 LEDs RGB.
Un seul pin est nécessaire pour contrôler toutes les LEDs. Chaque LED RGB possède une puce WS2812, qui peut être contrôlée indépendamment.
Elle peut réaliser un affichage de luminosité à 256 niveaux et un affichage en vraie couleur complet de 16 777 216 couleurs.
De plus, le pixel contient un circuit de commande de verrouillage de données d'interface numérique intelligent avec un amplificateur de signal de mise en forme,
et un circuit de mise en forme du signal intégré pour garantir efficacement une haute cohérence de la couleur des points lumineux des pixels.

Elle est flexible, peut être raccordée, pliée et coupée à volonté, et le dos est équipé d'un ruban adhésif, ce qui permet de la fixer sur une surface irrégulière et de l'installer dans un espace restreint.

**Caractéristiques**

* Tension de fonctionnement : DC5V
* IC : Un IC pour chaque LED RGB
* Consommation : 0,3W par LED
* Température de fonctionnement : -15-50°C
* Couleur : RGB pleine couleur
* Type de LED : 5050RGB (IC intégré WS2812B)
* Épaisseur de la bande lumineuse : 2mm
* Chaque LED peut être contrôlée individuellement

**Présentation du WS2812B**

* `WS2812B Datasheet <https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf>`_

Le WS2812B est une source de lumière LED à commande intelligente dont le circuit de commande et la puce RGB sont intégrés dans
un composant de type 5050. Il comprend un port de données numérique intelligent de verrouillage et un circuit d'amplification de mise en forme du signal.
Il inclut également un oscillateur interne de précision et une partie de commande de courant constant programmable de 12V,
assurant efficacement une haute cohérence de la couleur des points lumineux des pixels.


Le protocole de transfert de données utilise un mode de communication NZR unique. Après la réinitialisation de la puissance du pixel, le port DIN
reçoit les données du contrôleur, le premier pixel collecte les premières 24 bits de données puis les envoie au verrouillage de données interne,
les autres données mises en forme par le circuit d'amplification de mise en forme du signal interne sont envoyées au pixel suivant en cascade
via le port DO. Après transmission pour chaque pixel, le signal est réduit de 24 bits. Le pixel adopte une technologie de transmission auto-mise en forme,
ce qui rend le nombre de pixels en cascade non limité par la transmission du signal, dépendant uniquement de la vitesse de transmission du signal.


Les LED avec une faible tension de fonctionnement, une protection de l'environnement et une économie d'énergie, une haute luminosité, un angle de diffusion large,
une bonne cohérence, une faible consommation d'énergie, une longue durée de vie et d'autres avantages. Le circuit de commande intégré à la LED
simplifie davantage le circuit, réduit le volume et facilite l'installation.

**Exemple**

* :ref:`ar_rgb_strip` (Projet Arduino)
* :ref:`ar_flowing_light` (Projet Arduino)
* :ref:`py_rgb_strip` (Projet MicroPython)
* :ref:`py_flowing_light` (Projet MicroPython)
* :ref:`py_color_gradient` (Projet MicroPython)

