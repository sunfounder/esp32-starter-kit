.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_motor:

4.1 Petit Ventilateur
============================

Dans ce projet captivant, nous allons explorer comment piloter un moteur à l'aide du L293D.

Le L293D est un circuit intégré (IC) polyvalent couramment utilisé pour le contrôle des moteurs dans les projets électroniques et robotiques. Il peut piloter deux moteurs dans les deux sens, ce qui en fait un choix populaire pour les applications nécessitant un contrôle précis des moteurs.

À la fin de ce projet passionnant, vous aurez acquis une compréhension approfondie de la manière dont les signaux numériques et les signaux PWM peuvent être utilisés efficacement pour contrôler les moteurs. Ces connaissances inestimables constitueront une base solide pour vos futures aventures en robotique et en mécatronique. Préparez-vous à plonger dans le monde passionnant du contrôle des moteurs avec le L293D !

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
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
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

    Comme le moteur nécessite un courant relativement élevé, il est nécessaire d'insérer d'abord la batterie, puis de faire glisser l'interrupteur sur la carte d'extension en position ON pour activer l'alimentation de la batterie. 

.. image:: ../../img/wiring/4.1_motor_l293d_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``4.1_motor_turn.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    import machine
    import time

    # Créer des objets Pin représentant les broches de contrôle du moteur et les configurer en mode sortie
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Définir une fonction pour faire tourner le moteur dans le sens horaire
    def clockwise():
        motor1A.value(1)
        motor2A.value(0)

    # Définir une fonction pour faire tourner le moteur dans le sens antihoraire
    def anticlockwise():
        motor1A.value(0)
        motor2A.value(1)

    # Définir une fonction pour arrêter le moteur
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    # Entrer dans une boucle infinie

    try:
        while True:
            clockwise() # Faire tourner le moteur dans le sens horaire
            time.sleep(1) # Pause pendant 1 seconde
            anticlockwise() # Faire tourner le moteur dans le sens antihoraire
            time.sleep(1)
            stop() # Arrêter le moteur
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Arrêter le moteur en cas d'interruption clavier



Pendant l'exécution du script, vous verrez le moteur tourner alternativement dans le sens horaire et antihoraire toutes les secondes.


**En savoir plus**

En plus de simplement faire tourner le moteur dans le sens horaire et antihoraire, vous pouvez également contrôler la vitesse de rotation du moteur en utilisant la modulation de largeur d'impulsion (PWM) sur la broche de contrôle, comme indiqué ci-dessous.

.. note::

    * Ouvrez le fichier ``4.1_motor_turn_pwm.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 



.. code-block:: python

    from machine import Pin, PWM
    import time

    # Créer des objets PWM représentant les broches de contrôle du moteur et configurer leur fréquence à 1000 Hz
    motor1A = PWM(Pin(13, Pin.OUT))
    motor2A = PWM(Pin(14, Pin.OUT))
    motor1A.freq(500)
    motor2A.freq(500)

    # Entrer dans une boucle infinie
    while True:
        # Faire tourner le moteur vers l'avant en augmentant progressivement la puissance sur la broche motor1A
        for power in range(0, 1023, 20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Diminuer la puissance sur la broche motor1A
        for power in range(1023, 0, -20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Faire tourner le moteur dans la direction opposée en augmentant progressivement la puissance sur la broche motor2A
        for power in range(0, 1023, 20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)
        # Diminuer la puissance sur la broche motor2A
        for power in range(1023, 0, -20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)





Contrairement au script précédent, ici le moteur est contrôlé par des signaux PWM avec une fréquence de 1000 Hz, ce qui détermine la vitesse du moteur.

* Le code utilise une boucle ``while True`` pour s'exécuter en continu. À l'intérieur de la boucle, il y a quatre boucles ``for`` qui contrôlent les moteurs dans une séquence. 
* Les deux premières boucles ``for`` augmentent et diminuent la vitesse de IN1 tout en maintenant IN2 à 0 vitesse. 
* Les deux boucles ``for`` suivantes augmentent et diminuent la vitesse de IN2 tout en maintenant IN1 à 0 vitesse.
* La fonction ``range`` dans chaque boucle ``for`` produit une chaîne de nombres qui sert de cycle de service du signal PWM. Ceci est ensuite envoyé à IN1 ou IN2 via la méthode ``duty``. Le cycle de service détermine le pourcentage de temps pendant lequel le signal PWM est élevé, ce qui détermine à son tour la tension moyenne appliquée au moteur, et donc la vitesse du moteur.
* La fonction ``time.sleep`` est utilisée pour introduire un délai de 0,1 seconde entre chaque étape de la séquence, ce qui permet au moteur de changer de vitesse progressivement, plutôt que de passer instantanément d'une vitesse à une autre.
