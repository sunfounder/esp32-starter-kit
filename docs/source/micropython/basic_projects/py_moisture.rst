.. note::

    Bonjour, bienvenue dans la communauté SunFounder des passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_moisture:

5.9 Mesurer l'humidité du sol
===================================

Ce capteur capacitif d'humidité du sol est différent de la plupart des capteurs résistifs du marché, utilisant le principe de l'induction capacitive pour détecter l'humidité du sol.

En lisant visuellement les valeurs du capteur d'humidité du sol, nous pouvons recueillir des informations sur le niveau d'humidité du sol. Ces informations sont utiles pour diverses applications, telles que les systèmes d'irrigation automatique, la surveillance de la santé des plantes ou les projets de détection environnementale.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Broches disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Broches de configuration**

    Les broches suivantes sont des broches de configuration, qui affectent le processus de démarrage de l'ESP32 lors de la mise sous tension ou de la réinitialisation. Cependant, une fois que l'ESP32 a démarré avec succès, elles peuvent être utilisées comme des broches normales.

    .. list-table::
        :widths: 5 15

        *   - Broches de configuration
            - IO0, IO12

**Schéma**

.. image:: ../../img/circuit/circuit_5.9_soil_moisture.png

En insérant le module dans le sol et en l'arrosant, la valeur lue sur I35 diminuera.

**Câblage**

.. image:: ../../img/wiring/5.9_moisture_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.9_moisture.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    from machine import ADC, Pin
    import time

    # créer un objet ADC agissant sur une broche
    moisture = ADC(Pin(35, Pin.IN))

    # Configurer l'atténuation de l'ADC à 11dB pour une plage complète     
    moisture.atten(moisture.ATTN_11DB)

    while True:
        # lire une valeur analogique brute dans la plage de 0 à 4095
        value = moisture.read()  
        print(value)
        time.sleep(0.05)



Lorsque le script s'exécute, vous verrez la valeur de l'humidité du sol dans le Shell.

En insérant le module dans le sol et en l'arrosant, la valeur du capteur d'humidité du sol deviendra plus petite.
