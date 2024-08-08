.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_ultrasonic:

5.12 Mesure de distance
======================================
Le module ultrasonique est utilisé pour la mesure de distance ou la détection d'objets. Dans ce projet, nous allons programmer le module pour obtenir les distances des obstacles. En envoyant des impulsions ultrasoniques et en mesurant le temps qu'il faut pour qu'elles rebondissent, nous pouvons calculer les distances. Cela nous permet de mettre en œuvre des actions basées sur la distance ou des comportements d'évitement d'obstacles.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Pins disponibles**

* **Pins disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Pour l'entrée
            - IO13, IO14, IO27, IO26, IO25, IO33, IO32, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Pour la sortie
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schéma**

.. image:: ../../img/circuit/circuit_5.12_ultrasonic.png

L'ESP32 envoie un ensemble de signaux carrés à la broche Trig du capteur ultrasonique toutes les 10 secondes. Cela incite le capteur ultrasonique à émettre un signal ultrasonore de 40kHz. S'il y a un obstacle devant, les ondes ultrasonores seront réfléchies.

En enregistrant le temps écoulé entre l'envoi et la réception du signal, en le divisant par 2 et en le multipliant par la vitesse du son, vous pouvez déterminer la distance jusqu'à l'obstacle.

**Câblage**

.. image:: ../../img/wiring/5.12_ultrasonic_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.12_ultrasonic.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.12_ultrasonic``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/28ded128-62a8-4b2b-b21a-450f03323cd8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


N'oubliez pas de définir le taux de communication série à 115200 baud.

Après le téléversement réussi du code, le moniteur série affichera la distance entre le capteur ultrasonique et l'obstacle devant.

**Comment ça marche ?**

Concernant l'application du capteur ultrasonique, nous pouvons vérifier directement la sous-fonction.

.. code-block:: arduino

    float readSensorData(){// ...}

* La broche ``trigPin`` du module ultrasonique transmet un signal carré de 10µs toutes les 2µs.

    .. code-block:: arduino

        // Déclencher un signal bas avant d'envoyer un signal haut
        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2);
        // Envoyer un signal haut de 10 microsecondes à la broche trigPin
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10);
        // Retourner au signal bas
        digitalWrite(trigPin, LOW);

* La broche ``echoPin`` reçoit un signal de niveau haut s'il y a un obstacle dans la portée et utilise la fonction ``pulseIn()`` pour enregistrer le temps écoulé entre l'envoi et la réception.

    .. code-block:: arduino

        unsigned long microsecond = pulseIn(echoPin, HIGH);

* La vitesse du son est de 340 mètres par seconde, ce qui équivaut à 29 microsecondes par centimètre. En mesurant le temps qu'il faut pour qu'une onde carrée atteigne un obstacle et revienne, nous pouvons calculer la distance parcourue en divisant le temps total par 2. Cela nous donne la distance de l'obstacle à la source de l'onde sonore.

    .. code-block:: arduino

        float distance = microsecond / 29.00 / 2;  

Notez que le capteur ultrasonique mettra en pause le programme lorsqu'il est en fonctionnement, ce qui peut causer des retards lors de l'écriture de projets complexes.

