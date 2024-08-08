.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_lcd:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND** : Masse
* **VCC** : Alimentation, 5V.
* **SDA** : Ligne de données série. Connectez-la à VCC via une résistance de tirage.
* **SCL** : Ligne d'horloge série. Connectez-la à VCC via une résistance de tirage.

Comme nous le savons tous, bien que les écrans LCD et certains autres affichages enrichissent considérablement l'interaction homme-machine, ils partagent une faiblesse commune. Lorsqu'ils sont connectés à un contrôleur, plusieurs ports E/S sont occupés, limitant ainsi les autres fonctions du contrôleur.

Par conséquent, le LCD1602 avec un module I2C a été développé pour résoudre ce problème. Le module I2C intègre une puce PCF8574 qui convertit les données série I2C en données parallèles pour l'affichage LCD.

* `PCF8574 Datasheet <https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204&ref_url=https%253A%252F%252Fwww.google.com%252F>`_

**Adresse I2C**

L'adresse par défaut est généralement 0x27, dans quelques cas elle peut être 0x3F.

En prenant l'adresse par défaut de 0x27 comme exemple, l'adresse de l'appareil peut être modifiée en court-circuitant les pads A0/A1/A2 ; à l'état par défaut, A0/A1/A2 est à 1, et si le pad est court-circuité, A0/A1/A2 est à 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Rétroéclairage/Contraste**

Le rétroéclairage peut être activé par un capuchon de cavalier, débranchez le capuchon pour désactiver le rétroéclairage. Le potentiomètre bleu à l'arrière est utilisé pour ajuster le contraste (le rapport de luminosité entre le blanc le plus brillant et le noir le plus sombre).

.. image:: img/back_lcd1602.jpg

* **Capuchon de cavalier** : Le rétroéclairage peut être activé par ce capuchon, débranchez-le pour désactiver le rétroéclairage.
* **Potentiomètre** : Il est utilisé pour ajuster le contraste (la clarté du texte affiché), qui augmente dans le sens des aiguilles d'une montre et diminue dans le sens inverse.

**Exemple**

* :ref:`ar_lcd1602` (Projet Arduino)
* :ref:`ar_guess_number` (Projet Arduino)
* :ref:`py_lcd1602` (Projet MicroPython)
* :ref:`py_guess_number` (Projet MicroPython)
