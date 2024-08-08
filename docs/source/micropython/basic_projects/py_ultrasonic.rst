.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_ultrasonic:

5.12 Mesure de distance
======================================

Le module ultrasonique est utilisé pour la mesure de distance ou la détection d'objets. Dans ce projet, nous allons programmer le module pour obtenir les distances des obstacles. En envoyant des impulsions ultrasoniques et en mesurant le temps qu'elles mettent pour rebondir, nous pouvons calculer les distances. Cela nous permet de mettre en œuvre des actions basées sur la distance ou des comportements d'évitement d'obstacles.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Pour entrée
            - IO13, IO14, IO27, IO26, IO25, IO33, IO32, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Pour sortie
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schéma**

.. image:: ../../img/circuit/circuit_5.12_ultrasonic.png

L'ESP32 envoie une série de signaux carrés à la broche Trig du capteur ultrasonique toutes les 10 secondes. Cela incite le capteur ultrasonique à émettre un signal ultrasonique de 40 kHz. S'il y a un obstacle devant, les ondes ultrasoniques seront réfléchies.

En enregistrant le temps écoulé entre l'envoi et la réception du signal, en le divisant par 2 et en le multipliant par la vitesse du son, vous pouvez déterminer la distance de l'obstacle.

**Câblage**

.. image:: ../../img/wiring/5.12_ultrasonic_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.12_ultrasonic.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit.

.. code-block:: python

    import machine
    import time

    # Définir les broches de déclenchement et d'écho pour le capteur de distance
    TRIG = machine.Pin(26, machine.Pin.OUT)
    ECHO = machine.Pin(25, machine.Pin.IN)

    # Calculer la distance à l'aide du capteur ultrasonique
    def distance():
        # Assurez-vous que le déclencheur est initialement éteint
        TRIG.off()
        time.sleep_us(2)  # Attendre 2 microsecondes

        # Envoyer une impulsion de 10 microsecondes à la broche de déclenchement
        TRIG.on()
        time.sleep_us(10)
        TRIG.off()

        # Attendre que la broche d'écho passe à l'état haut
        while not ECHO.value():
            pass

        # Enregistrer le temps lorsque la broche d'écho passe à l'état haut
        time1 = time.ticks_us()

        # Attendre que la broche d'écho passe à l'état bas
        while ECHO.value():
            pass

        # Enregistrer le temps lorsque la broche d'écho passe à l'état bas
        time2 = time.ticks_us()

        # Calculer la différence de temps entre les deux temps enregistrés
        during = time.ticks_diff(time2, time1)

        # Calculer et retourner la distance (en cm) en utilisant la vitesse du son (340 m/s)
        return during * 340 / 2 / 10000

    # Mesurer et afficher continuellement la distance
    while True:
        dis = distance()
        print('Distance: %.2f' % dis)
        time.sleep_ms(300)  # Attendre 300 millisecondes avant de répéter

Une fois le programme en cours d'exécution, le Shell affichera la distance entre le capteur ultrasonique et l'obstacle devant lui.
