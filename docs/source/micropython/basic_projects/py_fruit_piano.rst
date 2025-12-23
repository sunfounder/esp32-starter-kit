.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_fruit_piano:

6.1 Piano en Fruits
============================

Avez-vous déjà voulu jouer du piano mais ne pouviez pas vous le permettre ? Ou peut-être voulez-vous simplement vous amuser avec un piano en fruits fait maison ? Alors ce projet est pour vous ! 

Avec seulement quelques capteurs tactiles sur la carte ESP32, vous pouvez maintenant jouer vos airs préférés et profiter de l'expérience de jouer du piano sans vous ruiner.

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**À propos des broches tactiles**

Le microcontrôleur ESP32 dispose d'une fonctionnalité de capteur tactile intégrée, qui vous permet d'utiliser certaines broches de la carte 
comme entrées sensibles au toucher. Le capteur tactile fonctionne en mesurant les changements de capacitance sur les broches tactiles, 
provoqués par les propriétés électriques du corps humain.

Voici quelques caractéristiques clés du capteur tactile sur l'ESP32 :

* **Nombre de broches tactiles**

    L'ESP32 dispose de jusqu'à 10 broches tactiles, selon la carte spécifique. Les broches tactiles sont généralement étiquetées avec un "T" suivi d'un numéro.

    * GPIO4: TOUCH0
    * GPIO0：TOUCH1
    * GPIO2: TOUCH2
    * GPIO15: TOUCH3
    * GPIO13: TOUCH4
    * GPIO12: TOUCH5
    * GPIO14: TOUCH6
    * GPIO27: TOUCH7
    * GPIO33: TOUCH8
    * GPIO32: TOUCH9

    .. note::
        Les broches GPIO0 et GPIO2 sont utilisées respectivement pour le démarrage et le flashage du firmware sur l'ESP32. Ces broches sont également connectées à la LED et au bouton intégrés. Par conséquent, il est généralement déconseillé d'utiliser ces broches à d'autres fins, car cela pourrait interférer avec le fonctionnement normal de la carte.

* **Sensibilité**

    Le capteur tactile de l'ESP32 est très sensible et peut détecter même de petits changements de capacitance. La sensibilité peut être ajustée à l'aide de paramètres logiciels.

* **Protection ESD**

    Les broches tactiles de l'ESP32 sont équipées d'une protection ESD (décharge électrostatique) intégrée, qui aide à prévenir les dommages à la carte causés par l'électricité statique.

* **Multitouch**

    Le capteur tactile de l'ESP32 prend en charge le multitouch, ce qui signifie que vous pouvez détecter plusieurs événements tactiles simultanément.

**Schéma**

.. image:: ../../img/circuit/circuit_6.1_fruit_piano.png

L'idée derrière ce projet est d'utiliser des capteurs tactiles pour détecter quand un utilisateur touche une broche spécifique. 
Chaque broche tactile est associée à une note spécifique, et lorsque l'utilisateur touche une broche, 
la note correspondante est jouée sur le buzzer passif. 
Le résultat est une manière simple et abordable de profiter de l'expérience de jouer du piano.

**Câblage**

.. image:: ../../img/wiring/6.1_fruit_piano_bb.png

Dans ce projet, vous devez retirer l'ESP32 carte de la carte d'extension, puis l'insérer dans la plaque d'expérimentation. En effet, certaines broches de la carte d'extension sont connectées à des résistances, ce qui affectera la capacitance des broches.

**Code**

.. note::

    * Ouvrez le fichier ``6.1_fruit_piano.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    from machine import Pin, PWM, TouchPad
    import time

    # Définir les broches tactiles et leurs notes correspondantes
    touch_pins = [4, 15, 13, 12, 14, 27, 33, 32]  # Utiliser des broches tactiles valides
    notes = [262, 294, 330, 349, 392, 440, 494, 523]

    # Initialiser les capteurs tactiles
    touch_sensors = [TouchPad(Pin(pin)) for pin in touch_pins]

    # Initialiser le buzzer
    buzzer = PWM(Pin(25), duty=0)

    # Fonction pour jouer une tonalité
    def play_tone(frequency, duration):
        buzzer.freq(frequency)
        buzzer.duty(512)
        time.sleep_ms(duration)
        buzzer.duty(0)

    touch_threshold = 200

    # Boucle principale pour vérifier les entrées tactiles et jouer la note correspondante
    while True:
        for i, touch_sensor in enumerate(touch_sensors):
            value = touch_sensor.read()
            print(i,value)
            if value < touch_threshold:
                play_tone(notes[i], 100)
                time.sleep_ms(50)
            time.sleep(0.01)


Vous pouvez connecter des fruits à ces broches de l'ESP32 : 4, 15, 13, 12, 14, 27, 33, 32.

Lorsque le script s'exécute, toucher ces fruits jouera les notes C, D, E, F, G, A, B et C5.

.. note::
    Le ``touch_threshold`` doit être ajusté en fonction de la conductivité des différents fruits. 
    
    Vous pouvez d'abord exécuter le script pour voir les valeurs imprimées par le terminal.

    .. code-block::

        0 884
        1 801
        2 856
        3 964
        4 991
        5 989
        6 1072
        7 1058

    Après avoir touché les fruits sur les broches 12, 14 et 27, les valeurs imprimées sont les suivantes. Par conséquent, j'ai réglé le ``touch_threshold`` à 200, ce qui signifie que lorsqu'une valeur inférieure à 200 est détectée, elle est considérée comme touchée et le buzzer émettra différentes notes.
    
    .. code-block::

        0 882
        1 810
        2 799
        3 109
        4 122
        5 156
        6 1068
        7 1055


