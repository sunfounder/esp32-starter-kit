.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_thermistor:

5.10 Détection de la température
======================================

Un thermistor est un capteur de température qui présente une forte dépendance à la température. Il peut être classé en deux types : Coefficient de Température Négatif (NTC) et Coefficient de Température Positif (PTC). La résistance d'un thermistor NTC diminue avec l'augmentation de la température, tandis que celle d'un thermistor PTC augmente avec l'augmentation de la température.

Dans ce projet, nous utiliserons un thermistor NTC. En connectant le thermistor NTC à une broche d'entrée analogique du microcontrôleur ESP32, nous pouvons mesurer sa résistance, qui est directement proportionnelle à la température.

En intégrant le thermistor NTC et en effectuant les calculs nécessaires, nous pouvons mesurer avec précision la température et l'afficher sur le module I2C LCD1602. Ce projet permet une surveillance en temps réel de la température et offre une interface visuelle pour l'affichage de la température.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Broches disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Broches de strap**

    Les broches de strap suivantes affectent le processus de démarrage de l'ESP32 lors de la mise sous tension ou de la réinitialisation. Cependant, une fois l'ESP32 démarrée avec succès, elles peuvent être utilisées comme broches normales.

    .. list-table::
        :widths: 5 15

        *   - Broches de strap
            - IO0, IO12


**Schéma**

.. image:: ../../img/circuit/circuit_5.10_thermistor.png

Lorsque la température augmente, la résistance du thermistor diminue, ce qui provoque une diminution de la valeur lue sur I35. De plus, en utilisant une formule, vous pouvez convertir la valeur analogique en température puis l'afficher.

**Câblage**

.. image:: ../../img/wiring/5.10_thermistor_bb.png


.. note::
    * Le thermistor est noir et marqué 103.
    * La couleur de l'anneau de la résistance de 10K ohms est rouge, noir, noir, rouge et marron.

**Code**

.. note::

    * Ouvrez le fichier ``5.10_thermistor.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 




.. code-block:: python

    # Importer les bibliothèques nécessaires
    from machine import ADC, Pin
    import time
    import math

    # Définir la valeur bêta du thermistor, généralement fournie dans la fiche technique
    beta = 3950

    # Créer un objet ADC (thermistor)
    thermistor = ADC(Pin(35, Pin.IN))

    # Régler l'atténuation
    thermistor.atten(thermistor.ATTN_11DB)

    # Démarrer une boucle infinie pour surveiller continuellement la température
    while True:
        # Lire la tension en microvolts et la convertir en volts
        Vr = thermistor.read_uv() / 1000000

        # Calculer la résistance du thermistor en fonction de la tension mesurée
        Rt = 10000 * Vr / (3.3 - Vr)

        # Utiliser la valeur bêta et la valeur de résistance pour calculer la température en Kelvin
        temp = 1 / (((math.log(Rt / 10000)) / beta) + (1 / (273.15 + 25)))

        # Convertir en Celsius
        Cel = temp - 273.15

        # Convertir en Fahrenheit
        Fah = Cel * 1.8 + 32

        # Afficher les valeurs de température en Celsius et en Fahrenheit
        print('Celsius: %.2f C  Fahrenheit: %.2f F' % (Cel, Fah))
        time.sleep(0.5)

Lorsque le code est exécuté, le Shell affiche les températures en Celsius et en Fahrenheit.

**Comment ça marche ?**

Chaque thermistor a une résistance normale. Ici, elle est de 10k ohms, mesurée à 25 degrés Celsius.

Lorsque la température augmente, la résistance du thermistor diminue. Ensuite, les données de tension sont converties en quantités numériques par l'adaptateur A/D.

La température en Celsius ou en Fahrenheit est sortie via la programmation.

Voici la relation entre la résistance et la température :

    **RT =RN expB(1/TK - 1/TN)** 

    * **RT** est la résistance du thermistor NTC lorsque la température est **TK**. 
    * **RN** est la résistance du thermistor NTC à la température nominale TN. Ici, la valeur numérique de RN est 10k. 
    * **TK** est une température en Kelvin et l'unité est K. Ici, la valeur numérique de **TK** est ``373.15 + degré Celsius``. 
    * **TN** est une température nominale en Kelvin; l'unité est aussi K. Ici, la valeur numérique de TN est ``373.15+25``.
    * Et **B(bêta)**, la constante matérielle du thermistor NTC, est également appelée indice de sensibilité thermique avec une valeur numérique ``4950``. 
    * **exp** est l'abréviation de exponentielle, et la base ``e`` est un nombre naturel et vaut environ 2,7. 

    Convertissez cette formule ``TK=1/(ln(RT/RN)/B+1/TN)`` pour obtenir la température en Kelvin qui moins 273,15 égale le degré Celsius.

    Cette relation est une formule empirique. Elle est précise uniquement lorsque la température et la résistance sont dans la plage effective.


**En savoir plus**

Vous pouvez également afficher les températures calculées en Celsius et en Fahrenheit sur l'écran I2C LCD1602.

.. image:: ../../img/wiring/5.10_thermistor_lcd_bb.png

.. note::

    * Ouvrez le fichier ``5.10_thermistor_lcd.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 
    * Ici, vous devez utiliser la bibliothèque appelée ``lcd1602.py``, veuillez vérifier si elle a été téléchargée sur ESP32, pour un tutoriel détaillé, reportez-vous à :ref:`add_libraries_py`.


.. code-block:: python

    # Importer les bibliothèques nécessaires
    from machine import ADC, Pin
    from lcd1602 import LCD
    import time
    import math

    # Définir la valeur bêta du thermistor, généralement fournie dans la fiche technique
    beta = 3950

    # Créer un objet ADC (thermistor)
    thermistor = ADC(Pin(35, Pin.IN))

    # Régler l'atténuation
    thermistor.atten(thermistor.ATTN_11DB)

    lcd = LCD()

    # Démarrer une boucle infinie pour surveiller continuellement la température
    while True:
        # Lire la tension en microvolts et la convertir en volts
        Vr = thermistor.read_uv() / 1000000

        # Calculer la résistance du thermistor en fonction de la tension mesurée
        Rt = 10000 * Vr / (3.3 - Vr)

        # Utiliser la valeur bêta et la valeur de résistance pour calculer la température en Kelvin
        temp = 1 / (((math.log(Rt / 10000)) / beta) + (1 / (273.15 + 25)))

        # Convertir en Celsius
        Cel = temp - 273.15

        # Convertir en Fahrenheit
        Fah = Cel * 1.8 + 32

        # Afficher les valeurs de température en Celsius et en Fahrenheit
        print('Celsius: %.2f C  Fahrenheit: %.2f F' % (Cel, Fah))

        # Effacer l'écran LCD
        lcd.clear()
        
        # Afficher les valeurs de température en Celsius et en Fahrenheit
        lcd.message('Cel: %.2f \xDFC \n' % Cel)
        lcd.message('Fah: %.2f \xDFF' % Fah)
        time.sleep(1)

