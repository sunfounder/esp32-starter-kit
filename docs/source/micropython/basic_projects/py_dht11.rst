.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_dht11:

5.13 Température - Humidité
=======================================
Le DHT11 est un capteur de température et d'humidité couramment utilisé pour les mesures environnementales. Il s'agit d'un capteur numérique qui communique avec un microcontrôleur pour fournir des relevés de température et d'humidité.

Dans ce projet, nous allons lire les données du capteur DHT11 et afficher les valeurs de température et d'humidité qu'il détecte.

En lisant les données fournies par le capteur, nous pouvons obtenir les valeurs actuelles de la température et de l'humidité dans l'environnement. Ces valeurs peuvent être utilisées pour la surveillance en temps réel des conditions environnementales, les observations météorologiques, le contrôle du climat intérieur, les rapports d'humidité, etc.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Broches disponibles
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schéma**

.. image:: ../../img/circuit/circuit_5.13_dht11.png


**Câblage**

.. image:: ../../img/wiring/5.13_dht11_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.13_dht11.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    import dht
    import machine
    import time

    # Initialiser le capteur DHT11 et le connecter à la broche 14
    sensor = dht.DHT11(machine.Pin(14))

    # Boucle infinie pour mesurer continuellement la température et l'humidité
    while True:
        try:
            # Mesurer la température et l'humidité
            sensor.measure()

            # Obtenir les valeurs de température et d'humidité
            temp = sensor.temperature()
            humi = sensor.humidity()

            # Afficher la température et l'humidité
            print("Temperature: {}, Humidity: {}".format(temp, humi))

            # Attendre 1 seconde entre les mesures
            time.sleep(1)
        except Exception as e:
            print("Error: ", e)
            time.sleep(1)


Lorsque le code s'exécute, vous verrez la console afficher continuellement la température et l'humidité. Au fur et à mesure que le programme tourne, ces deux valeurs deviendront de plus en plus précises.


**En savoir plus**

Vous pouvez également afficher la température et l'humidité sur l'écran LCD1602 I2C.

.. image:: ../../img/wiring/5.13_dht11_lcd_bb.png

.. note::

    * Ouvrez le fichier ``5.13_dht11_lcd.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 
    * Ici, vous devez utiliser la bibliothèque appelée ``lcd1602.py``, veuillez vérifier si elle a été téléchargée sur l'ESP32. Pour un tutoriel détaillé, consultez la section :ref:`add_libraries_py`.

.. code-block:: python

    import dht
    import machine
    import time
    from lcd1602 import LCD

    # Initialiser le capteur DHT11 et le connecter à la broche 14
    sensor = dht.DHT11(machine.Pin(14))

    # Initialiser l'écran LCD1602
    lcd = LCD()

    # Boucle pour mesurer la température et l'humidité
    while True:
        try:
            # Mesurer la température et l'humidité
            sensor.measure()

            # Obtenir les valeurs de température et d'humidité
            temp = sensor.temperature()
            humi = sensor.humidity()

            # Afficher la température et l'humidité
            print("Temperature: {}, Humidity: {}".format(temp, humi))

            # Effacer l'affichage LCD
            lcd.clear()

            # Afficher la température et l'humidité sur l'écran LCD1602
            lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
            lcd.write(0, 1, "Humi: {}%".format(humi))

            # Attendre 2 secondes avant de mesurer à nouveau
            time.sleep(2)

        except Exception as e:
            print("Error: ", e)
            time.sleep(2)

