.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_plant_monitor:

6.8 Moniteur de plantes
===============================

Bienvenue dans le projet Moniteur de plantes ! 

Dans ce projet, nous allons utiliser une carte ESP32 pour créer un système qui nous aidera à prendre soin de nos plantes. Grâce à ce système, nous pourrons surveiller la température, l'humidité, l'humidité du sol et les niveaux de lumière de nos plantes, et nous assurer qu'elles reçoivent les soins et l'attention nécessaires pour prospérer.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.8_plant_monitor_l293d.png

Le système utilise un capteur DHT11 pour mesurer les niveaux de température et d'humidité de l'environnement. 
Pendant ce temps, un module d'humidité du sol est utilisé pour mesurer le niveau d'humidité du sol et une 
photoresistance est utilisée pour mesurer le niveau de lumière. Les lectures de ces capteurs sont affichées sur 
un écran LCD, et une pompe à eau peut être contrôlée à l'aide d'un bouton pour arroser la plante si nécessaire.

IO32 possède une résistance de tirage vers le bas interne de 1K, et par défaut, il est à un niveau logique bas. 
Lorsque le bouton est pressé, il établit une connexion avec VCC (haute tension), ce qui entraîne un niveau logique haut sur IO32.

**Câblage**

.. note::

    Il est recommandé ici d'insérer la batterie puis de faire glisser l'interrupteur sur la carte d'extension en position ON pour activer l'alimentation de la batterie.


.. image:: ../../img/wiring/6.8_plant_monitor_l293d_bb.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``6.8_plant_monitor.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    from machine import ADC, Pin
    import time
    import dht
    from lcd1602 import LCD

    # DHT11
    dht11 = dht.DHT11(Pin(13))

    # Humidité du sol
    moisture_pin = ADC(Pin(14))
    moisture_pin.atten(ADC.ATTN_11DB)

    # Photoresistance
    photoresistor = ADC(Pin(35))
    photoresistor.atten(ADC.ATTN_11DB)

    # Bouton et pompe
    button = Pin(32, Pin.IN)

    motor1A = Pin(27, Pin.OUT)
    motor2A = Pin(26, Pin.OUT)

    # Configuration du LCD1602 I2C
    lcd = LCD()

    # Faire tourner la pompe
    def rotate():
        motor1A.value(1)
        motor2A.value(0)

    # Arrêter la pompe
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    button_state = False

    # Définir la fonction de rappel du bouton pour basculer l'état du bouton
    def button_callback(pin):
        global button_state
        button_state = not button_state

    # Attacher la fonction de rappel du bouton au front montant de la broche du bouton
    button.irq(trigger=Pin.IRQ_RISING, handler=button_callback)

    page = 0
    temp = 0
    humi = 0
            
    try:
        while True:
            # Si le bouton est pressé et que l'état du bouton est True
            if button_state:
                print("rotate")
                rotate()

            # Si le bouton est pressé à nouveau et que l'état du bouton est False
            if not button_state:
                print("stop")
                stop()
            time.sleep(2)

            # Effacer l'affichage du LCD
            lcd.clear()
            
            # Basculer la valeur de la variable page entre 0 et 1
            page = (page + 1) % 2
            
            # Lorsque page vaut 1, afficher la température et l'humidité sur le LCD1602
            if page == 1:
                try:
                    # Mesurer la température et l'humidité
                    dht11.measure()

                    # Obtenir les valeurs de température et d'humidité
                    temp = dht11.temperature()
                    humi = dht11.humidity()
                except Exception as e:
                    print("Error: ", e)         

                # Afficher la température et l'humidité
                lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
                lcd.write(0, 1, "Humi: {}%".format(humi))

            # Si page vaut 0, afficher l'humidité du sol et la lumière
            else:
                light = photoresistor.read()
                moisture = moisture_pin.read()

                # Effacer l'affichage du LCD
                lcd.clear()

                # Afficher la valeur de l'humidité du sol et de la lumière
                lcd.write(0, 0, f"Moisture: {moisture}")
                lcd.write(0, 1, f"Light: {light}")

    except KeyboardInterrupt:
        # Arrêter le moteur en cas d'interruption clavier
        stop()

* Lorsque le code est exécuté, le LCD1602 I2C affiche alternativement la température et l'humidité, ainsi que les valeurs analogiques de l'humidité du sol et de l'intensité lumineuse, avec un intervalle de 2 secondes.
* Appuyez sur le bouton pour démarrer la pompe à eau, et appuyez de nouveau pour arrêter la pompe à eau.

.. note:: 

    Si le code et le câblage sont corrects, mais que le LCD n'affiche toujours aucun contenu, vous pouvez ajuster le potentiomètre à l'arrière pour augmenter le contraste.

