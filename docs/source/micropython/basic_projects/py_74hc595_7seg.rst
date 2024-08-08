.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_7_segment:

2.5 Affichage de Numéros 
=================================

Bienvenue dans ce projet fascinant ! Dans ce projet, nous explorerons le monde enchanteur de l'affichage des chiffres de 0 à 9 sur un afficheur à sept segments.

Imaginez déclencher ce projet et voir un petit afficheur compact s'illuminer avec chaque chiffre de 0 à 9. C'est comme avoir un mini-écran qui affiche les chiffres de manière captivante. En contrôlant les broches de signal, vous pouvez facilement changer le chiffre affiché et créer divers effets engageants.

Grâce à des connexions de circuit simples et à la programmation, vous apprendrez à interagir avec l'afficheur à sept segments et à donner vie aux chiffres souhaités. Que ce soit pour un compteur, une horloge ou toute autre application intrigante, l'afficheur à sept segments sera votre compagnon fiable, ajoutant une touche de brillance à vos projets.

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DU COMPOSANT
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
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Broches Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schéma**

.. image:: ../../img/circuit/circuit_2.5_74hc595_7_segment.png

Le principe de câblage est essentiellement le même que :ref:`py_74hc595`, la seule différence est que Q0-Q7 sont connectés aux broches a ~ g de l'afficheur à 7 segments.

.. list-table:: Câblage
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - Afficheur à Segment LED
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**Câblage**

.. image:: ../../img/wiring/2.5_segment_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``2.5_number_display.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit.

.. code-block:: python

    import machine
    import time

    # Définir le code segment pour un afficheur à 7 segments à anode commune
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

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
            
            # Envoyer le bit actuel dans le registre à décalage en mettant la broche SRCLK à haut
            srclk.on()
            
        # Verrouiller les données dans le registre de stockage en mettant la broche RCLK à haut
        rclk.on()

    # Boucler continuellement à travers les chiffres de 0 à 9 et les afficher sur l'afficheur à 7 segments
    while True:
        for num in range(10):
            hc595_shift(SEGCODE[num])  # Shift the segment code for the current number into the 74HC595
            time.sleep_ms(500)  # Wait 500 milliseconds before displaying the next number


Lorsque le script est en cours d'exécution, vous pourrez voir l'afficheur à segments LED afficher les chiffres de 0 à 9 en séquence.

**Comment ça marche ?**

Dans ce projet, nous utilisons la fonction ``hc595_shift()`` pour écrire le nombre binaire dans le registre à décalage.

Supposons que l'afficheur à 7 segments affiche le chiffre "2". Ce modèle de bits correspond aux segments **f**, **c** et **dp** éteints (bas), tandis que les segments **a**, **b**, **d**, **e** et **g** sont allumés (haut). Cela correspond à "01011011" en binaire et "0x5b" en notation hexadécimale.

Par conséquent, vous devez appeler **hc595_shift(0x5b)** pour afficher le chiffre "2" sur l'afficheur à 7 segments.

.. image:: img/7_segment2.png



* `Hexadecimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `BinaryHex Converter <https://www.binaryhexconverter.com/binary-to-hex-converter>`_


Le tableau suivant montre les motifs hexadécimaux à écrire dans le registre à décalage pour afficher les chiffres de 0 à 9 sur un afficheur à 7 segments.



.. list-table:: Glyph Code
    :widths: 20 20 20
    :header-rows: 1

    *   - Chiffres	
        - Code Binaire
        - Code Hexadécimal  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Écrivez ces codes dans ``hc595_shift()`` pour que l'afficheur à segments LED affiche les chiffres correspondants.
