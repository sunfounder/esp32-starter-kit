.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_74hc595:

2.4 Microchip - 74HC595
===========================

Bienvenue dans ce projet passionnant ! Dans ce projet, nous allons utiliser la puce 74HC595 pour contrôler un affichage déroulant de 8 LED.

Imaginez déclencher ce projet et assister à un flux de lumière fascinant, comme un arc-en-ciel scintillant sautant entre les 8 LED. Chaque LED s'allumera une par une puis s'éteindra rapidement, tandis que la LED suivante continuera de briller, créant un effet magnifique et dynamique.

En utilisant habilement la puce 74HC595, nous pouvons contrôler l'état de marche et d'arrêt de plusieurs LED pour obtenir cet effet de flux. Cette puce possède plusieurs broches de sortie qui peuvent être connectées en série pour contrôler la séquence d'illumination des LED. De plus, grâce à l'extensibilité de la puce, nous pouvons facilement ajouter plus de LED à l'affichage déroulant, créant ainsi des effets encore plus spectaculaires.

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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Broches disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schéma**

.. image:: ../../img/circuit/circuit_2.4_74hc595_led.png
    :width: 600

* Lorsque MR (broche 10) est au niveau haut et CE (broche 13) est au niveau bas, les données sont entrées sur le front montant de SHcp et vont au registre de mémoire via le front montant de SHcp. 
* Si les deux horloges sont connectées ensemble, le registre à décalage est toujours une impulsion en avance sur le registre de mémoire. 
* Il y a une broche d'entrée de décalage série (DS), une broche de sortie série (Q7') et un bouton de réinitialisation asynchrone (niveau bas) dans le registre de mémoire. 
* Le registre de mémoire sort un bus avec un parallèle 8 bits et en trois états. 
* Lorsque OE est activé (niveau bas), les données dans le registre de mémoire sont sorties vers le bus (Q0 ~ Q7).

**Câblage**

.. image:: ../../img/wiring/2.4_74hc595_bb.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``2.4_microchip_74hc595.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 



.. code-block:: python

    import machine
    import time

    # Initialiser les broches pour le registre à décalage 74HC595
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

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

    num = 0

    # Décaler les données dans le 74HC595 pour créer un motif de LED en mouvement
    for i in range(16):
        if i < 8:
            num = (num << 1) + 1  # Décalage vers la gauche et définir le bit de poids faible à 1
        elif i >= 8:
            num = (num & 0b01111111) << 1  # Masquer le bit de poids fort et décaler vers la gauche
        hc595_shift(num)  # Décaler la valeur actuelle dans le 74HC595
        print("{:0>8b}".format(num))  # Afficher la valeur actuelle au format binaire
        time.sleep_ms(200)  # Attendre 200 millisecondes avant de décaler la valeur suivante




Pendant l'exécution du script, vous verrez les LED s'allumer une par une, puis s'éteindre dans l'ordre initial.

**Comment ça marche ?**

Ce code est utilisé pour contrôler un registre à décalage 8 bits (74595) et sortir différentes valeurs binaires vers le registre à décalage, chaque valeur étant affichée sur une LED pendant une certaine période de temps.

#. Le code importe les modules ``machine`` et ``time``, où le module ``machine`` est utilisé pour contrôler les E/S matérielles et le module ``time`` est utilisé pour implémenter des délais et d'autres fonctions.

    .. code-block:: python

        import machine
        import time

#. Trois ports de sortie sont initialisés à l'aide de la fonction ``machine.Pin()``, correspondant au port de données (SDI), au port d'horloge de stockage (RCLK) et au port d'horloge du registre à décalage (SRCLK) du registre à décalage.

    .. code-block:: python

        # Initialiser les broches pour le registre à décalage 74HC595
        sdi = machine.Pin(25, machine.Pin.OUT)  # DS
        rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
        srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

#. Une fonction appelée ``hc595_shift()`` est définie pour écrire des données de 8 bits dans le registre à décalage.

    .. code-block:: python

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

#. À propos de la boucle ``for``.

    .. code-block:: python

        for i in range(16):
                if i < 8:
                    num = (num << 1) + 1  # Décalage vers la gauche et définir le bit de poids faible à 1
                elif i >= 8:
                    num = (num & 0b01111111) << 1  # Masquer le bit de poids fort et décaler vers la gauche
                hc595_shift(num)  # Décaler la valeur actuelle dans le 74HC595
                print("{:0>8b}".format(num))  # Afficher la valeur actuelle au format binaire
                time.sleep_ms(200)  # Attendre 200 millisecondes avant de décaler la valeur suivante

    * La variable ``i`` est utilisée pour contrôler la valeur binaire de sortie. Lors des 8 premières itérations, la valeur de num sera successivement 00000001, 00000011, 00000111, ..., 11111111, qui est décalée d'un bit vers la gauche puis ajoutée de 1.
    * Lors des 9e à 16e itérations, le bit de poids fort de 1 est d'abord changé en 0, puis décalé d'un bit vers la gauche, ce qui donne les valeurs de sortie 00000010, 00000100, 00001000, ..., 10000000.
    * À chaque itération, la valeur de ``num`` est passée à la fonction ``hc595_shift()`` pour contrôler le registre à décalage afin de sortir la valeur binaire correspondante.
    * En même temps que la sortie de la valeur binaire, la fonction ``print()`` sort la valeur binaire sous forme de chaîne dans le terminal.
    * Après avoir sorti la valeur binaire, le programme fait une pause de 200 millisecondes en utilisant la fonction ``time.sleep_ms()``, afin que la valeur sur la LED reste affichée pendant une certaine période de temps.
