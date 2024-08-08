.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_l293d:

L293D
=================

Le L293D est un pilote de moteur 4 canaux intégré par puce avec une haute tension et un courant élevé. 
Il est conçu pour se connecter à des niveaux logiques DTL, TTL standard et pour entraîner des charges inductives (telles que des bobines de relais, des moteurs à courant continu, des moteurs pas à pas) et des transistors de commutation de puissance, etc. 
Les moteurs à courant continu sont des dispositifs qui convertissent l'énergie électrique continue en énergie mécanique. Ils sont largement utilisés dans les entraînements électriques pour leur performance supérieure de régulation de la vitesse.

Voir la figure des broches ci-dessous. Le L293D dispose de deux broches (Vcc1 et Vcc2) pour l'alimentation. 
Vcc2 est utilisé pour alimenter le moteur, tandis que Vcc1 pour alimenter la puce. Étant donné qu'un moteur à courant continu de petite taille est utilisé ici, connectez les deux broches au +5V.

.. image:: img/l293d111.png

Voici la structure interne du L293D. 
La broche EN est une broche d'activation qui ne fonctionne qu'avec un niveau haut ; A représente l'entrée et Y la sortie. 
Vous pouvez voir la relation entre elles en bas à droite. 
Lorsque la broche EN est à un niveau haut, si A est haut, Y sort un niveau haut ; si A est bas, Y sort un niveau bas. Lorsque la broche EN est à un niveau bas, le L293D ne fonctionne pas.

.. image:: img/l293d334.png

* `L293D Datasheet <https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1627004062301&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D>`_

**Exemple**

* :ref:`ar_motor` (Projet Arduino)
* :ref:`ar_pump` (Projet Arduino)
* :ref:`py_motor` (Projet MicroPython)
* :ref:`py_pump` (Projet MicroPython)
* :ref:`sh_rotating_fan` (Projet Scratch)
