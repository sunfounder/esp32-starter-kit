.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_pir:

5.5 Détecter les mouvements humains
========================================

Le capteur infrarouge passif (capteur PIR) est un capteur courant qui peut mesurer la lumière infrarouge (IR) émise par les objets dans son champ de vision.
En termes simples, il détecte le rayonnement infrarouge émis par le corps, permettant ainsi de détecter les mouvements des personnes et autres animaux.
Plus spécifiquement, il informe la carte de contrôle principale que quelqu'un est entré dans votre pièce.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Pour entrée
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Pour sortie
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::
    
    IO32 ne peut pas être utilisée **comme broche d'entrée** dans ce projet car elle est connectée en interne à une résistance de tirage vers le bas de 1K, ce qui définit sa valeur par défaut à 0.

* **Broches de Strapping (entrée)**

    Les broches de strapping sont un ensemble spécial de broches utilisées pour déterminer des modes de démarrage spécifiques pendant le démarrage de l'appareil 
    (c'est-à-dire, la réinitialisation lors de la mise sous tension).

    
    .. list-table::
        :widths: 5 15

        *   - Broches de Strapping
            - IO5, IO0, IO2, IO12, IO15 
    

    

    En général, il est **déconseillé de les utiliser comme broches d'entrée**. Si vous souhaitez utiliser ces broches, tenez compte de l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez vous référer à la section :ref:`esp32_strapping`.

**Schéma**

.. image:: ../../img/circuit/circuit_5.5_pir.png

Lorsque le module PIR détecte un mouvement, IO14 passe à un niveau haut et la LED s'allume. Sinon, lorsque aucun mouvement n'est détecté, IO14 reste à un niveau bas et la LED s'éteint.

.. note::
    Le module PIR dispose de deux potentiomètres : l'un ajuste la sensibilité, l'autre ajuste la distance de détection. Pour optimiser le fonctionnement du module PIR, il est nécessaire de tourner les deux à fond dans le sens antihoraire.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**Câblage**

.. image:: ../../img/wiring/5.5_pir_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.5_detect_human_movement.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 



.. code-block:: python

    import machine
    import time

    # Définir les broches
    PIR_PIN = 14    # Capteur PIR
    LED_PIN = 26    # LED

    # Initialiser la broche du capteur PIR comme une broche d'entrée
    pir_sensor = machine.Pin(PIR_PIN, machine.Pin.IN, machine.Pin.PULL_DOWN)
    # Initialiser la broche LED comme une broche de sortie
    led = machine.Pin(LED_PIN, machine.Pin.OUT)

    # Indicateur global pour détecter un mouvement
    motion_detected_flag = False

    # Fonction pour gérer l'interruption
    def motion_detected(pin):
        global motion_detected_flag
        print("Motion detected!")
        motion_detected_flag = True

    # Attacher l'interruption à la broche du capteur PIR
    pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    # Boucle principale
    while True:
        if motion_detected_flag:
            led.value(1)  # Allumer la LED
            time.sleep(5)  # Garder la LED allumée pendant 5 secondes
            led.value(0)  # Éteindre la LED
            motion_detected_flag = False

Lorsque le script est en cours d'exécution, la LED s'allumera pendant 5 secondes puis s'éteindra lorsque le module PIR détectera quelqu'un qui passe.

.. note::

    Le module PIR dispose de deux potentiomètres : l'un ajuste la sensibilité, l'autre ajuste la distance de détection. Pour optimiser le fonctionnement du module PIR, il est nécessaire de tourner les deux à fond dans le sens antihoraire.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center




**Comment ça marche ?**


Ce code configure un système de détection de mouvement simple utilisant un capteur PIR et une LED. Lorsqu'un mouvement est détecté, la LED s'allume pendant 5 secondes. 

Voici une explication détaillée du code :

#. Définir la fonction de gestion de l'interruption qui sera exécutée lorsque le mouvement est détecté :

    .. code-block:: python

        def motion_detected(pin):
            global motion_detected_flag
            print("Motion detected!")
            motion_detected_flag = True

#. Attacher l'interruption à la broche du capteur PIR, avec le déclenchement réglé sur "montée" (c'est-à-dire lorsque la broche passe d'une basse à une haute tension) :

    .. code-block:: python

        pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    Cela configure une interruption sur la broche ``pir_sensor``, qui est connectée au capteur de mouvement PIR.

    Voici une explication détaillée des paramètres :

    * ``trigger=machine.Pin.IRQ_RISING`` : Ce paramètre définit la condition de déclenchement de l'interruption. Dans ce cas, l'interruption sera déclenchée sur un front montant. Un front montant est lorsque la tension sur la broche passe d'un état bas (0V) à un état haut (typiquement 3,3V ou 5V, selon votre matériel). Pour un capteur de mouvement PIR, lorsque le mouvement est détecté, la broche de sortie passe généralement de bas à haut, ce qui fait du front montant une condition de déclenchement appropriée.

    * ``handler=motion_detected`` : Ce paramètre spécifie la fonction qui sera exécutée lorsque l'interruption est déclenchée. Dans ce cas, la fonction ``motion_detected`` est fournie en tant que gestionnaire d'interruption. Cette fonction sera appelée automatiquement lorsque la condition d'interruption (front montant) est détectée sur la broche ``pir_sensor``.

    Ainsi, cette ligne de code configure le capteur PIR pour appeler la fonction ``motion_detected`` chaque fois qu'un mouvement est détecté par le capteur, en raison du passage de la broche de sortie d'un état bas à un état haut.



#. Dans la boucle principale, si le ``motion_detected_flag`` est réglé sur ``True``, la LED sera allumée pendant 5 secondes, puis éteinte. Le drapeau est ensuite réinitialisé à ``False`` pour attendre le prochain événement de mouvement.

    .. code-block:: python

        while True:
            if motion_detected_flag:
                led.value(1)  # Allumer la LED
                time.sleep(5)  # Garder la LED allumée pendant 5 secondes
                led.value(0)  # Éteindre la LED
                motion_detected_flag = False

