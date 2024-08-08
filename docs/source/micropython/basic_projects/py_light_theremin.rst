.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_light_theremin:

6.3 Thérémine lumineux
=========================

Le thérémine est un instrument de musique électronique qui ne nécessite pas de contact physique. En fonction de la position de la main du joueur, il produit différents tons.

Sa partie de contrôle est généralement composée de deux antennes métalliques qui détectent la position des mains du théréministe et contrôlent les oscillateurs avec une main et le volume avec l'autre. Les signaux électriques du thérémine sont amplifiés et envoyés à un haut-parleur.

Nous ne pouvons pas reproduire le même instrument avec l'ESP32, mais nous pouvons utiliser une photo-résistance et un buzzer passif pour obtenir un gameplay similaire.

* `Theremin - Wikipedia <https://en.wikipedia.org/wiki/Theremin>`_

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.3_light_theremin.png

Avant de commencer le projet, calibrez la plage d'intensité lumineuse en agitant votre main au-dessus de la photo-résistance. La LED connectée à IO26 est utilisée comme indicateur pendant le processus de calibration. Lorsque la LED s'allume, cela signifie le début de la calibration, et lorsqu'elle s'éteint, cela indique la fin de la calibration.

En agitant votre main au-dessus de la photo-résistance, la valeur de cette dernière 
changera en conséquence. Utilisez ce changement pour contrôler le buzzer et jouer 
différentes notes de musique. Chaque variation de la valeur de la photo-résistance 
peut être associée à une note musicale spécifique, permettant au buzzer de produire 
une mélodie lorsque vous agitez votre main au-dessus de la photo-résistance.


**Câblage**

.. image:: ../../img/wiring/6.3_theremin_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``6.3_light_theremin.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 


.. code-block:: python

    from machine import Pin, PWM, ADC
    import time

    # Initialiser la broche LED
    led = Pin(26, Pin.OUT)

    # Initialiser le capteur de lumière
    sensor = ADC(Pin(35))
    sensor.atten(ADC.ATTN_11DB)

    # Initialiser le buzzer
    buzzer = PWM(Pin(13), freq=440, duty=0)

    light_low=4095
    light_high=0

    # Mapper l'intervalle des valeurs d'entrée aux valeurs de sortie
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Créer une tonalité en utilisant la broche spécifiée, la fréquence et la durée
    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty(512)
        time.sleep_ms(duration)
        pin.duty(0)

    # Calibrer les valeurs maximum et minimum de la photo-résistance en 5 secondes.
    timer_init_start = time.ticks_ms()
    led.value(1) # allumer la LED   
    while time.ticks_diff(time.ticks_ms(), timer_init_start)<5000:
        light_value = sensor.read()
        if light_value > light_high:
            light_high = light_value
        if light_value < light_low:
            light_low = light_value   
    led.value(0) # éteindre la LED 

    # Jouer les tonalités en fonction des valeurs de lumière
    while True:
        light_value  = sensor.read()
        pitch = int(interval_mapping(light_value,light_low,light_high,50,6000))
        if pitch > 50 :
            tone(buzzer,pitch,20)
        time.sleep_ms(10)


Au démarrage du programme, la LED s'allume, nous offrant une fenêtre de cinq secondes 
pour calibrer la plage de détection de la photo-résistance.

La calibration est une étape cruciale car elle prend en compte les diverses conditions 
d'éclairage que nous pouvons rencontrer lors de l'utilisation de l'appareil, telles que 
les différentes intensités lumineuses pendant les différentes heures de la journée. De 
plus, le processus de calibration prend en compte la distance entre nos mains et la 
photo-résistance, ce qui détermine la plage de jeu de l'instrument.

Une fois la période de calibration terminée, la LED s'éteint, indiquant que nous 
pouvons maintenant jouer de l'instrument en agitant nos mains au-dessus de la 
photo-résistance. Cette configuration nous permet de créer de la musique en ajustant 
la hauteur de nos mains, offrant une expérience interactive et agréable.
