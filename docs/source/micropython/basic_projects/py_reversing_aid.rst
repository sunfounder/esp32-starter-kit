.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_reversing_aid:

6.4 Assistance au Recul
===============================

Imaginez ceci : Vous êtes dans votre voiture, prêt à reculer dans une place de parking étroite. Avec notre projet, vous aurez un module ultrasonique monté à l'arrière de votre véhicule, agissant comme un œil numérique. Lorsque vous engagez la marche arrière, le module s'active, émettant des impulsions ultrasoniques qui rebondissent sur les obstacles derrière vous.

La magie opère lorsque ces impulsions reviennent au module. Il calcule rapidement la distance entre votre voiture et les objets, transformant ces données en retour visuel en temps réel affiché sur un écran LCD vibrant. Vous verrez des indicateurs dynamiques et colorés représentant la proximité des obstacles, vous offrant une compréhension claire de l'environnement qui vous entoure.

Mais nous ne nous sommes pas arrêtés là. Pour vous immerger davantage dans cette expérience de conduite, nous avons incorporé un buzzer. À mesure que votre voiture s'approche d'un obstacle, le tempo du buzzer s'intensifie, créant une symphonie d'avertissements auditifs. C'est comme avoir un orchestre personnel vous guidant à travers les complexités du stationnement en marche arrière.

Ce projet innovant combine une technologie de pointe avec une interface utilisateur interactive, rendant votre expérience de recul sécurisée et sans stress. Avec le module ultrasonique, l'écran LCD et le buzzer travaillant harmonieusement, vous vous sentirez puissant et confiant en manœuvrant dans des espaces restreints, vous permettant de vous concentrer sur le plaisir de conduire.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.4_reversing_aid.png
    :width: 800
    :align: center


Le capteur ultrasonique du projet émet des ondes sonores haute fréquence et mesure le temps que mettent les ondes pour rebondir après avoir heurté un objet. En analysant ces données, la distance entre le capteur et l'objet peut être calculée. Pour avertir lorsque l'objet est trop proche, un buzzer est utilisé pour produire un signal sonore. De plus, la distance mesurée est affichée sur un écran LCD pour une visualisation facile.

**Câblage**

.. image:: ../../img/wiring/6.4_aid_ultrasonic_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``6.4_reversing_aid.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    # Importer les bibliothèques nécessaires
    from machine import Pin
    import time
    from lcd1602 import LCD
    import _thread

    # Initialiser le buzzer
    buzzer = Pin(14, Pin.OUT)

    # Initialiser le module ultrasonique
    TRIG = Pin(26, Pin.OUT)
    ECHO = Pin(25, Pin.IN)

    # Initialiser l'écran LCD1602
    lcd = LCD()

    dis = 100

    # Calculer la distance
    def distance():
        # S'assurer que le déclencheur est initialement désactivé
        TRIG.off()
        time.sleep_us(2)  # Attendre 2 microsecondes

        # Envoyer une impulsion de 10 microsecondes à la broche de déclenchement
        TRIG.on()
        time.sleep_us(10)
        TRIG.off()

        # Attendre que la broche d'écho devienne haute
        while not ECHO.value():
            pass

        # Enregistrer l'heure où la broche d'écho devient haute
        time1 = time.ticks_us()

        # Attendre que la broche d'écho devienne basse
        while ECHO.value():
            pass

        # Enregistrer l'heure où la broche d'écho devient basse
        time2 = time.ticks_us()

        # Calculer la différence de temps entre les deux temps enregistrés
        during = time.ticks_diff(time2, time1)

        # Calculer et retourner la distance (en cm) en utilisant la vitesse du son (340 m/s)
        return during * 340 / 2 / 10000

    # Thread pour mettre à jour continuellement la lecture du capteur ultrasonique
    def ultrasonic_thread():
        global dis
        while True:
            dis = distance()
            
            # Effacer l'écran LCD
            lcd.clear()
            
            # Afficher la distance
            lcd.write(0, 0, 'Dis: %.2f cm' % dis)
            time.sleep(0.5)

    # Démarrer le thread de lecture du capteur ultrasonique
    _thread.start_new_thread(ultrasonic_thread, ())

    # Fonction de bip pour le buzzer
    def beep():
        buzzer.value(1)
        time.sleep(0.1)
        buzzer.value(0)
        time.sleep(0.1)

    # Initialiser la variable d'intervalles
    intervals = 10000000
    previousMills = time.ticks_ms()
    time.sleep(1)

    # Boucle principale
    while True:
        # Mettre à jour les intervalles en fonction de la distance
        if dis < 0 and dis > 500:
            pass
        elif dis <= 10:
            intervals = 300
        elif dis <= 20:
            intervals = 500
        elif dis <= 50:
            intervals = 1000
        else:
            intervals = 2000

        # Imprimer la distance si elle n'est pas -1
        if dis != -1:
            print('Distance: %.2f' % dis)
        time.sleep_ms(100)

        # Vérifier s'il est temps de biper
        currentMills = time.ticks_ms()
        if time.ticks_diff(currentMills, previousMills) >= intervals:
            beep()
            previousMills = currentMills


* Lorsque le script est en cours d'exécution, le module ultrasonique détecte continuellement la distance des obstacles devant lui et affiche la distance sur la console et l'écran I2C LCD1602. 
* À mesure que l'obstacle se rapproche, la fréquence des bips du buzzer augmente.
* La fonction ``ultrasonic_thread()`` s'exécute dans un thread séparé pour permettre une mise à jour continue de la mesure de distance sans bloquer la boucle principale.

.. note:: 

    Si le code et le câblage sont corrects, mais que l'écran LCD ne parvient toujours pas à afficher du contenu, vous pouvez ajuster le potentiomètre à l'arrière pour augmenter le contraste.

