.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_servo:

4.3 Servomoteur oscillant
==============================

Un servomoteur est un dispositif de positionnement connu pour sa capacité à maintenir des angles spécifiques et à offrir une rotation précise. Cela le rend très recherché pour les systèmes de contrôle nécessitant des ajustements d'angle constants. Il n'est donc pas surprenant que les servomoteurs soient largement utilisés dans les jouets télécommandés haut de gamme, des modèles d'avion aux répliques de sous-marins en passant par les robots télécommandés sophistiqués.

Dans cette aventure captivante, nous nous lancerons le défi de manipuler le servomoteur d'une manière unique - en le faisant osciller ! Ce projet offre une excellente occasion d'explorer la dynamique des servomoteurs, d'affiner vos compétences en systèmes de contrôle précis et de mieux comprendre leur fonctionnement.

Êtes-vous prêt à faire danser le servomoteur à votre rythme ? Embarquons pour ce voyage excitant !

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Broches disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schéma**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**Câblage**

* Le fil orange est le signal et est connecté à IO25.
* Le fil rouge est le VCC et est connecté à 5V.
* Le fil marron est la masse (GND) et est connecté à GND.

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``4.3_swinging_servo.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 




.. code-block:: python

    import machine
    import time

    # Créer un objet PWM (Pulse Width Modulation) sur la broche 25
    servo = machine.PWM(machine.Pin(25))

    # Définir la fréquence du signal PWM à 50 Hz, commun pour les servomoteurs
    servo.freq(50)

    # Définir une fonction de mappage d'intervalle
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Définir une fonction pour écrire un angle sur le servomoteur
    def servo_write(pin, angle):
        pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculer la largeur d'impulsion
        duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023)) # Calculer le cycle de service
        pin.duty(duty) # Définir le cycle de service du signal PWM

    # Créer une boucle infinie
    while True:
        # Boucler à travers les angles de 0 à 180 degrés
        for angle in range(180):
            servo_write(servo, angle)
            time.sleep_ms(20)

        # Boucler à travers les angles de 180 à 0 degrés en sens inverse
        for angle in range(180, -1, -1):
            servo_write(servo, angle)
            time.sleep_ms(20)

Lorsque ce code est exécuté, le servomoteur balayera continuellement d'avant en arrière entre 0 et 180 degrés.

**Comment ça marche ?**

#. Importer les bibliothèques nécessaires : ``machine`` pour contrôler le matériel du microcontrôleur et ``time`` pour ajouter des délais.

    .. code-block:: python

        import machine
        import time

#. Créer un objet PWM (Pulse Width Modulation) sur la broche 25 et définir sa fréquence à 50 Hz, courante pour les servomoteurs.

    .. code-block:: python

        # Créer un objet PWM (Pulse Width Modulation) sur la broche 25
        servo = machine.PWM(machine.Pin(25))

        # Définir la fréquence du signal PWM à 50 Hz, commun pour les servomoteurs
        servo.freq(50)

#. Définir une fonction ``interval_mapping`` pour mapper les valeurs d'une plage à une autre. Cela sera utilisé pour convertir l'angle en largeur d'impulsion et en cycle de service appropriés.

    .. code-block:: python

        def interval_mapping(x, in_min, in_max, out_min, out_max):
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

#. Définir une fonction ``servo_write`` qui prend un objet PWM et un angle comme entrées. Elle calcule la largeur d'impulsion et le cycle de service en fonction de l'angle donné, puis règle la sortie PWM en conséquence.

    .. code-block:: python
        
        def servo_write(pin, angle):
            pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculer la largeur d'impulsion
            duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023)) # Calculer le cycle de service
            pin.duty(duty) # Définir le cycle de service du signal PWM

    * Dans cette fonction, ``interval_mapping()`` est appelé pour mapper la plage d'angle de 0 à 180 à la plage de largeur d'impulsion de 0,5 à 2,5 ms.
    * Pourquoi 0,5~2,5 ms ? Cela est déterminé par le mode de fonctionnement du :ref:`Servo`.
    * Ensuite, convertir la largeur d'impulsion de la période en cycle de service.
    * Comme ``duty()`` ne peut pas avoir de décimales lors de son utilisation (la valeur ne peut pas être de type float), nous avons utilisé ``int()`` pour forcer la conversion de la largeur d'impulsion en type int.

#. Créer une boucle infinie avec deux boucles imbriquées.

    .. code-block:: python

        while True:
            # Boucler à travers les angles de 0 à 180 degrés
            for angle in range(180):
                servo_write(servo, angle)
                time.sleep_ms(20)

            # Boucler à travers les angles de 180 à 0 degrés en sens inverse
            for angle in range(180, -1, -1):
                servo_write(servo, angle)
                time.sleep_ms(20)

    * La première boucle imbriquée parcourt les angles de 0 à 180 degrés, et la seconde boucle imbriquée parcourt les angles de 180 à 0 degrés en sens inverse.
    * À chaque itération, la fonction ``servo_write`` est appelée avec l'angle actuel, et un délai de 20 millisecondes est ajouté.
