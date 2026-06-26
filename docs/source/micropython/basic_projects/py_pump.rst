.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_pump:

4.2 Pompe
=======================

Dans ce projet fascinant, nous allons explorer le contrôle d'une pompe à eau en utilisant le L293D.

Dans le domaine du contrôle des pompes à eau, les choses sont un peu plus simples par rapport au contrôle d'autres moteurs. La beauté de ce projet réside dans sa simplicité - il n'est pas nécessaire de se soucier de la direction de rotation. Notre objectif principal est de réussir à activer la pompe à eau et à la maintenir en marche.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants. 

Il est définitivement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-

**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Broches disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schéma**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


**Câblage**

.. note::

    Il est recommandé ici d'insérer le Power Pack puis de glisser l'interrupteur sur la carte d'extension en position ON pour activer l'alimentation électrique.


.. image:: ../../img/wiring/4.2_pump_l293d_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``4.2_pumping.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 



.. code-block:: python

    import machine
    import time

    # Créez des objets Pin représentant les broches de contrôle du moteur et définissez-les en mode sortie
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Définir une fonction pour faire tourner la pompe
    def rotate():
        motor1A.value(1)
        motor2A.value(0)

    # Définir une fonction pour arrêter la pompe
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    try:
        while True:
            rotate()  # Faire tourner le moteur dans le sens des aiguilles d'une montre
            time.sleep(5)  # Pause pendant 5 secondes
            stop()  # Arrêter le moteur
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Arrêter le moteur en cas d'interruption clavier



Pendant l'exécution du script, vous verrez la pompe fonctionner et l'eau sortir du tuyau, puis s'arrêter pendant 2 secondes avant de recommencer à fonctionner.

