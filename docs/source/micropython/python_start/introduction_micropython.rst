.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

1.1 Introduction à MicroPython
======================================

MicroPython est une implémentation logicielle d’un langage de programmation largement compatible avec Python 3, écrite en C, et optimisée pour fonctionner sur un microcontrôleur.

MicroPython comprend un compilateur Python en bytecode et un interpréteur d’exécution pour ce bytecode. L’utilisateur dispose d’une invite interactive (le REPL) pour exécuter immédiatement les commandes prises en charge. Il inclut une sélection de bibliothèques Python de base ; MicroPython propose également des modules permettant d’accéder au matériel bas niveau.

* Référence : `MicroPython - Wikipedia <https://fr.wikipedia.org/wiki/MicroPython>`_

L’histoire commence ici
--------------------------------

Les choses ont changé en 2013, lorsque Damien George a lancé une campagne de financement participatif (Kickstarter).

Damien était étudiant de premier cycle à l’Université de Cambridge et passionné de programmation robotique. Il voulait réduire le monde de Python d’un ordinateur en gigaoctets à un microcontrôleur en kilo-octets. Sa campagne Kickstarter visait à financer le développement d’une preuve de concept vers une implémentation complète.

MicroPython est soutenu par une communauté diversifiée de Pythonistas motivés à faire avancer le projet.

En plus des tests et du support du code, les développeurs ont fourni des tutoriels, bibliothèques de code et ports matériels, permettant à Damien de se concentrer sur d’autres aspects du projet.

* Référence : `realpython <https://realpython.com/micropython/>`_

Pourquoi MicroPython ?
---------------------------------

Bien que la campagne Kickstarter originale ait lancé MicroPython sous forme d’une carte de développement "pyboard" basée sur STM32F4, MicroPython prend en charge de nombreuses architectures de produits basées sur ARM. Les ports officiellement pris en charge sont ARM Cortex-M (nombreuses cartes STM32, TI CC3200/WiPy, Teensy, série Nordic nRF, SAMD21 et SAMD51), ESP8266, ESP32, PIC 16 bits, Unix, Windows, Zephyr et JavaScript.

Ensuite, MicroPython permet un retour rapide, car vous pouvez utiliser le REPL pour entrer des commandes de manière interactive et obtenir des réponses instantanées. Vous pouvez même ajuster du code et l’exécuter immédiatement sans passer par le cycle traditionnel coder-compiler-téléverser-exécuter.

Bien que Python offre les mêmes avantages, certaines cartes microcontrôleurs comme l’ESP32 sont trop petites ou limitées en mémoire pour faire tourner Python directement. C’est pourquoi MicroPython a évolué, conservant les principales fonctionnalités de Python tout en ajoutant de nombreuses fonctions spécifiques pour ces cartes.

Ensuite, vous apprendrez à installer MicroPython sur l’ESP32.

* Référence : `MicroPython - Wikipedia <https://fr.wikipedia.org/wiki/MicroPython>`_
* Référence : `realpython <https://realpython.com/micropython/>`_
