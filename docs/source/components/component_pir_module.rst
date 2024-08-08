.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_pir:

Module de capteur de mouvement PIR
=======================================

.. image:: img/pir_pic.png
    :width: 300
    :align: center

Le capteur PIR détecte les radiations de chaleur infrarouge pouvant être utilisées pour détecter la présence d'organismes émettant des radiations de chaleur infrarouge.

Le capteur PIR est divisé en deux fentes connectées à un amplificateur différentiel. Lorsqu'un objet stationnaire se trouve devant le capteur, les deux fentes reçoivent la même quantité de radiation et la sortie est nulle. Lorsqu'un objet en mouvement se trouve devant le capteur, une des fentes reçoit plus de radiation que l'autre, ce qui fait fluctuer la sortie vers le haut ou vers le bas. Ce changement de tension de sortie est le résultat de la détection de mouvement.

.. image:: img/PIR_working_principle.jpg
    :width: 800

Après le câblage du module de détection, il y a une minute d'initialisation. Pendant l'initialisation, le module sortira de 0 à 3 fois à intervalles réguliers. Ensuite, le module sera en mode veille. Veuillez éloigner les sources de lumière et autres sources d'interférence de la surface du module afin d'éviter les erreurs de fonctionnement causées par le signal d'interférence. Il est même préférable d'utiliser le module sans trop de vent, car le vent peut également interférer avec le capteur.

.. image:: img/pir_back.png
    :width: 600
    :align: center

**Réglage de la distance**

En tournant le bouton du potentiomètre de réglage de la distance dans le sens des aiguilles d'une montre, la plage de distance de détection augmente, et la plage maximale de détection est d'environ 0-7 mètres. Si vous le tournez dans le sens inverse des aiguilles d'une montre, la plage de distance de détection diminue, et la plage minimale de détection est d'environ 0-3 mètres.

**Réglage du délai**

En tournant le bouton du potentiomètre de réglage du délai dans le sens des aiguilles d'une montre, vous pouvez également voir le délai de détection augmenter. Le délai de détection maximum peut atteindre jusqu'à 300s. À l'inverse, si vous le tournez dans le sens inverse des aiguilles d'une montre, vous pouvez raccourcir le délai avec un minimum de 5s. 

**Deux modes de déclenchement**

Choisissez différents modes en utilisant le capuchon de cavalier.

* **H** : Mode de déclenchement répétable, après détection du corps humain, le module sort un niveau haut. Pendant la période de délai suivante, si quelqu'un entre dans la plage de détection, la sortie restera à un niveau haut.

* **L** : Mode de déclenchement non répétable, sort un niveau haut lorsqu'il détecte le corps humain. Après le délai, la sortie passera automatiquement du niveau haut au niveau bas. 

**Exemple**

* :ref:`ar_pir` (Projet Arduino)
* :ref:`iot_telegram` (Projet Arduino)
* :ref:`py_pir` (Projet MicroPython)
