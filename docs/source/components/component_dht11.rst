.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_dht11:

Capteur de Température et d'Humidité DHT11
===============================================

Le capteur numérique de température et d'humidité DHT11 est un capteur composite qui contient une sortie de signal numérique calibrée pour la température et l'humidité. La technologie de collecte de modules numériques dédiés et la technologie de détection de température et d'humidité sont appliquées pour garantir que le produit a une haute fiabilité et une excellente stabilité à long terme.

Le capteur comprend un composant de détection de l'humidité résistif et un dispositif de mesure de la température NTC, et est connecté à un microcontrôleur 8 bits haute performance.

Seules trois broches sont disponibles : VCC, GND et DATA. Le processus de communication commence avec la ligne DATA envoyant des signaux de démarrage au DHT11, et le DHT11 reçoit les signaux et renvoie un signal de réponse. Ensuite, l'hôte reçoit le signal de réponse et commence à recevoir les données d'humiture de 40 bits (8 bits d'humidité entière + 8 bits de décimale d'humidité + 8 bits de température entière + 8 bits de décimale de température + 8 bits de somme de contrôle).

.. image:: img/dht11.png

**Caractéristiques**

    #. Plage de mesure de l'humidité : 20 - 90% RH
    #. Plage de mesure de la température : 0 - 60℃
    #. Sortie de signaux numériques indiquant la température et l'humidité
    #. Tension de fonctionnement : DC 5V ; Taille du PCB : 2,0 x 2,0 cm
    #. Précision de mesure de l'humidité : ±5% RH
    #. Précision de mesure de la température : ±2℃


* `DHT11 Datasheet <http://wiki.sunfounder.cc/images/c/c7/DHT11_datasheet.pdf>`_

**Exemple**

* :ref:`ar_dht11` (Projet Arduino)
* :ref:`ar_plant_monitor` (Projet Arduino)
* :ref:`ar_adafruit_io` (Projet Arduino)
* :ref:`py_dht11` (Projet MicroPython)
* :ref:`py_plant_monitor` (Projet MicroPython)

