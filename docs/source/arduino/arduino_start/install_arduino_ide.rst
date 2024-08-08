.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _install_arduino:

1.1 Installer Arduino IDE (Important)
==========================================

L'Arduino IDE, connu sous le nom d'Environnement de Développement Intégré Arduino, fournit tout le support logiciel nécessaire pour réaliser un projet Arduino. Il s'agit d'un logiciel de programmation spécialement conçu pour Arduino, fourni par l'équipe Arduino, qui nous permet d'écrire des programmes et de les télécharger sur la carte Arduino.

L'Arduino IDE 2.0 est un projet open-source. Il représente une grande avancée par rapport à son robuste prédécesseur, Arduino IDE 1.x, et est livré avec une interface utilisateur repensée, un gestionnaire de cartes et de bibliothèques amélioré, un débogueur, une fonction de complétion automatique, et bien plus encore.

Dans ce tutoriel, nous allons montrer comment télécharger et installer l'Arduino IDE 2.0 sur votre ordinateur Windows, Mac ou Linux.

Exigences
---------------------

* Windows - Win 10 et plus récent, 64 bits
* Linux - 64 bits
* Mac OS X - Version 10.14 : "Mojave" ou plus récent, 64 bits

Télécharger l'Arduino IDE 2.0
----------------------------------

#. Visitez |link_download_arduino|.

#. Téléchargez l'IDE pour votre version de système d'exploitation.

    .. image:: img/sp_001.png

Installation
------------------------------

Windows
^^^^^^^^^^^^^

#. Double-cliquez sur le fichier ``arduino-ide_xxxx.exe`` pour exécuter le fichier téléchargé.

#. Lisez le contrat de licence et acceptez-le.

    .. image:: img/sp_002.png

#. Choisissez les options d'installation.

    .. image:: img/sp_003.png

#. Choisissez le lieu d'installation. Il est recommandé d'installer le logiciel sur un disque autre que le disque système.

    .. image:: img/sp_004.png

#. Puis Terminez.

    .. image:: img/sp_005.png

macOS
^^^^^^^^^^^^^^^^

Double-cliquez sur le fichier téléchargé ``arduino_ide_xxxx.dmg`` et suivez les instructions pour copier **Arduino IDE.app** dans le dossier **Applications**. Vous verrez que l'Arduino IDE s'installe avec succès après quelques secondes.

.. image:: img/macos_install_ide.png
    :width: 800

Linux
^^^^^^^^^^^^

Pour le tutoriel sur l'installation de l'Arduino IDE 2.0 sur un système Linux, veuillez vous référer à : https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux

Ouvrir l'IDE
-----------------

#. Lorsque vous ouvrez pour la première fois Arduino IDE 2.0, il installe automatiquement les cartes Arduino AVR, les bibliothèques intégrées et d'autres fichiers nécessaires.

    .. image:: img/sp_901.png

#. De plus, votre pare-feu ou centre de sécurité peut s'ouvrir plusieurs fois pour vous demander si vous souhaitez installer certains pilotes de périphérique. Veuillez tous les installer.

    .. image:: img/sp_104.png

#. Maintenant, votre Arduino IDE est prêt !

    .. note::
        Dans le cas où certaines installations n'ont pas fonctionné en raison de problèmes de réseau ou d'autres raisons, vous pouvez rouvrir l'Arduino IDE et il terminera le reste de l'installation. La fenêtre de sortie ne s'ouvrira pas automatiquement après la fin de toutes les installations à moins que vous ne cliquiez sur Vérifier ou Télécharger.
