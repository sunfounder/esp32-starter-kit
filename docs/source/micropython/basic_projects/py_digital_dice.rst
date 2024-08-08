.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_dice:

6.6 Dé numérique
================================

Ce projet est une extension du projet :ref:`py_7_segment` en ajoutant un bouton pour contrôler le chiffre affiché sur l'afficheur à sept segments.

Lorsque le bouton est pressé, l'afficheur à 7 segments fait défiler les chiffres de 1 à 6, et lorsque le bouton est relâché, il affiche un chiffre aléatoire.

Ce cycle se répète à chaque fois que le bouton est pressé.

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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.6_electronic_dice.png

Ce projet est une extension du projet :ref:`py_7_segment` en ajoutant un bouton pour contrôler le chiffre affiché sur l'afficheur à sept segments.

Le bouton est directement connecté à IO13 sans résistance de pull-up ou pull-down externe car IO13 a une résistance de pull-up interne de 47K, éliminant ainsi le besoin d'une résistance externe supplémentaire.

**Câblage**

.. image:: ../../img/wiring/6.6_DICE_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``6.6_digital_dice.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    import machine
    import time
    import random

    # Définir le code des segments pour un afficheur à sept segments à anode commune
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

    # Initialiser les broches pour le registre à décalage 74HC595
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    button = machine.Pin(13, machine.Pin.IN) # Broche du bouton

    # Définir la fonction hc595_shift pour décaler les données dans le registre à décalage 74HC595
    def hc595_shift(dat):
        # Mettre la broche RCLK à bas
        rclk.off()
        
        # Itérer à travers chaque bit (de 7 à 0)
        for bit in range(7, -1, -1):
            # Extraire le bit actuel des données d'entrée
            value = 1 & (dat >> bit)
            
            # Mettre la broche SRCLK à bas
            srclk.off()
            
            # Définir la valeur de la broche SDI
            sdi.value(value)
            
            # Synchroniser le bit actuel dans le registre à décalage en mettant la broche SRCLK à haut
            srclk.on()
            
        # Verrouiller les données dans le registre de stockage en mettant la broche RCLK à haut
        rclk.on()

    # Initialiser la graine aléatoire
    random.seed(time.ticks_us())

    num = 1
    button_state = False

    # Définir la fonction de rappel du bouton pour basculer l'état du bouton
    def button_callback(pin):
        global button_state
        button_state = not button_state

    # Attacher la fonction de rappel du bouton au front descendant de la broche du bouton
    button.irq(trigger=machine.Pin.IRQ_FALLING, handler=button_callback)

    # Afficher continuellement le chiffre actuel sur l'afficheur à 7 segments, défilement si le bouton n'est pas pressé
    while True:
        
        # Afficher le chiffre actuel sur l'afficheur à 7 segments
        hc595_shift(SEGCODE[num])
        
        # Si le bouton est pressé et que l'état du bouton est True
        if button_state:
            pass

        # Si le bouton est pressé à nouveau et que l'état du bouton est False, générer un nouveau chiffre aléatoire
        if not button_state:
            num = random.randint(1, 6)
            time.sleep_ms(10) # Ajustez cette valeur pour contrôler la fréquence de rafraîchissement de l'affichage
        
Lorsque le programme est en cours d'exécution, appuyer sur le bouton fera défiler l'afficheur à 7 segments et affichera aléatoirement un chiffre entre 1 et 6. 

En appuyant à nouveau sur le bouton, l'afficheur à 7 segments s'arrêtera et révélera un chiffre spécifique. Appuyez une fois de plus sur le bouton, et l'afficheur à 7 segments reprendra le défilement des chiffres.

