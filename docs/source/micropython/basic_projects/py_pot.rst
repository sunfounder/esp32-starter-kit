.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_potentiometer:

5.8 Tourner le bouton
===========================

Un potentiomètre est un dispositif à trois bornes couramment utilisé pour ajuster la résistance dans un circuit. Il est équipé d'un bouton ou d'un levier coulissant permettant de varier la valeur de la résistance du potentiomètre. Dans ce projet, nous l'utiliserons pour contrôler la luminosité d'une LED, de manière similaire à une lampe de bureau. En ajustant la position du potentiomètre, nous pouvons changer la résistance dans le circuit, régulant ainsi le courant traversant la LED et ajustant sa luminosité en conséquence. Cela nous permet de créer une expérience d'éclairage personnalisable et ajustable, semblable à celle d'une lampe de bureau.

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Broches disponibles
            - IO14, IO25, I35, I34, I39, I36

* **Broches de strapping**

    Les broches suivantes sont des broches de strapping, qui affectent le processus de démarrage de l'ESP32 lors de la mise sous tension ou de la réinitialisation. Cependant, une fois que l'ESP32 est démarrée avec succès, elles peuvent être utilisées comme broches normales.

    .. list-table::
        :widths: 5 15

        *   - Broches de strapping
            - IO0, IO12


**Schéma**

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

Lorsque vous tournez le potentiomètre, la valeur de I35 changera. En programmant, vous pouvez utiliser la valeur de I35 pour contrôler la luminosité de la LED. Ainsi, en tournant le potentiomètre, la luminosité de la LED changera également en conséquence.

**Câblage**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**Code**


.. note::

    * Ouvrez le fichier ``5.8_turn_the_knob.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 



.. code-block:: python

    from machine import ADC, Pin, PWM
    import time

    pot = ADC(Pin(35, Pin.IN)) # créer un objet ADC agissant sur une broche      

    # Configurer l'atténuation de l'ADC à 11dB pour la pleine échelle
    pot.atten(pot.ATTN_11DB)

    # Créer un objet PWM
    led = PWM(Pin(26), freq=1000)

    while True:
        # Lire une valeur analogique brute dans la plage de 0 à 4095
        value = pot.read()

        # Échelonner la valeur à la plage de 0 à 1023 pour le cycle de travail PWM de l'ESP32
        pwm_value = int(value * 1023 / 4095)

        # Mettre à jour la luminosité de la LED en fonction de la valeur du potentiomètre
        led.duty(pwm_value)

        # Lire la tension en microvolts et la convertir en volts
        voltage = pot.read_uv() / 1000000

        # Imprimer la valeur brute et la tension
        print(f"value: {value}, Voltage: {voltage}V")

        # Attendre 0.5 secondes avant de prendre la prochaine lecture
        time.sleep(0.5)

Avec ce script, la luminosité de la LED change lorsque le potentiomètre est tourné, tandis que la valeur analogique et la tension à ce point sont affichées dans le Shell.

* `machine.ADC - MicroPython Docs <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

