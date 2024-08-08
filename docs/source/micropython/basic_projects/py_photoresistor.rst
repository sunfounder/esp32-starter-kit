.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_photoresistor:

5.7 Ressentir la Lumière
=============================

La photo-résistance est un dispositif couramment utilisé pour les entrées analogiques, similaire à un potentiomètre. Sa valeur de résistance change en fonction de l'intensité lumineuse qu'elle reçoit. Lorsqu'elle est exposée à une forte lumière, la résistance de la photo-résistance diminue, et à mesure que l'intensité lumineuse diminue, la résistance augmente.

En lisant la valeur de la photo-résistance, nous pouvons recueillir des informations sur les conditions de lumière ambiante. Ces informations peuvent être utilisées pour des tâches telles que le contrôle de la luminosité d'une LED, l'ajustement de la sensibilité d'un capteur, ou la mise en œuvre d'actions dépendantes de la lumière dans un projet.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Broches disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Broches de Strapping**

    Les broches suivantes sont des broches de strapping, qui affectent le processus de démarrage de l'ESP32 lors de la mise sous tension ou de la réinitialisation. Cependant, une fois l'ESP32 démarré avec succès, elles peuvent être utilisées comme des broches régulières.

    .. list-table::
        :widths: 5 15

        *   - Broches de Strapping
            - IO0, IO12

**Schéma**

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

À mesure que l'intensité lumineuse augmente, la résistance de la photo-résistance (LDR) diminue, entraînant une diminution de la valeur lue sur I35.

**Câblage**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.7_feel_the_light.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 



.. code-block:: python

    from machine import ADC, Pin
    import time

    # créer un objet ADC agissant sur une broche
    photoresistor = ADC(Pin(35, Pin.IN))

    # Configurer l'atténuation ADC à 11dB pour la pleine échelle     
    photoresistor.atten(photoresistor.ATTN_11DB)

    while True:

        # lire une valeur analogique brute dans la plage 0-4095
        value = photoresistor.read()  
        print(value)
        time.sleep(0.05)


Après l'exécution du programme, les valeurs de la photo-résistance seront affichées dans le Shell. Vous pouvez éclairer celle-ci avec une lampe de poche ou la couvrir avec votre main pour voir comment la valeur change.


* ``atten(photoresistor.ATTN_11DB)`` : Configurer l'atténuation de l'ADC à 11dB pour la pleine échelle.

    Pour lire des tensions supérieures à la tension de référence, appliquez une atténuation d'entrée avec l'argument de mot-clé atten. 

    Les valeurs valides (et les plages de mesure linéaire approximatives) sont :

    * ADC.ATTN_0DB : Pas d'atténuation (100mV - 950mV)
    * ADC.ATTN_2_5DB : Atténuation de 2,5 dB (100mV - 1250mV)
    * ADC.ATTN_6DB : Atténuation de 6 dB (150mV - 1750mV)
    * ADC.ATTN_11DB : Atténuation de 11 dB (150mV - 2450mV)

* `machine.ADC - MicroPython Docs <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

