.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_blink:

2.1 Bonjour, LED ! 
=======================================

Tout comme imprimer "Hello, world!" est la première étape pour apprendre à programmer, utiliser un programme pour contrôler une LED est l'introduction traditionnelle à la programmation physique.

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

**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Broches disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schéma**

.. image:: ../../img/circuit/circuit_2.1_led.png

Ce circuit fonctionne sur un principe simple, et la direction du courant est montrée sur la figure. La LED s'allumera après la résistance de limitation de courant de 220 ohms lorsque la broche 26 sort un niveau haut. La LED s'éteindra lorsque la broche 26 sort un niveau bas.

**Câblage**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**Exécuter le code**

#. Ouvrez le fichier ``2.1_hello_led.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. 

    .. code-block:: python

        # Importer les bibliothèques nécessaires
        import machine
        import time

        # Configurer la LED sur la broche 26 comme broche de sortie
        led = machine.Pin(26, machine.Pin.OUT)

        # Démarrer une boucle infinie
        while True:
            # Allumer la LED en réglant sa valeur à 1 (HAUT)
            led.value(1)
            # Attendre 1 seconde (1000 millisecondes) pendant que la LED est allumée
            time.sleep(1)

            # Éteindre la LED en réglant sa valeur à 0 (BAS)
            led.value(0)
            # Attendre 0,5 seconde (500 millisecondes) pendant que la LED est éteinte
            time.sleep(0.5)

#. Connectez l'ESP32 board à votre ordinateur à l'aide d'un câble USB. 

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Ensuite, cliquez sur l'interpréteur "MicroPython (ESP32).COMXX" dans le coin inférieur droit.

   .. note::
   
      Si vous ne voyez aucune option autre que "Local Python 3", cela signifie que votre carte ESP32 n’a probablement pas été reconnue par votre ordinateur.  
      Dans ce cas, vous devrez peut-être :ref:`install_driver`.
   
   .. image:: ../python_start/img/sec_inter.png

#. Enfin, cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.

    .. image:: ../python_start/img/quick_guide2.png

#. Après l'exécution du code, vous verrez la LED clignoter.


**Comment ça fonctionne ?**

#. Il importe deux modules, ``machine`` et ``time``. Le module ``machine`` fournit un accès de bas niveau au matériel du microcontrôleur, tandis que le module ``time`` fournit des fonctions pour les opérations liées au temps.

    .. code-block:: python

        import machine
        import time

#. Ensuite, configurez la broche 26 comme broche de sortie en utilisant la fonction ``machine.Pin()`` avec l'argument ``machine.Pin.OUT``. 

    .. code-block:: python

        led = machine.Pin(26, machine.Pin.OUT)

#. Dans la boucle ``While True``, la LED est allumée pendant une seconde en réglant la valeur de la broche 26 à 1 en utilisant ``led.value(1)`` et ensuite réglée à 0 (``led.value(0)``) pour l'éteindre pendant une seconde, et ainsi de suite dans une boucle infinie.

    .. code-block:: python
        
        while True:
            # Allumer la LED en réglant sa valeur à 1 (HAUT)
            led.value(1)
            # Attendre 1 seconde (1000 millisecondes) pendant que la LED est allumée
            time.sleep(1)

            # Éteindre la LED en réglant sa valeur à 0 (BAS)
            led.value(0)
            # Attendre 0,5 seconde (500 millisecondes) pendant que la LED est éteinte
            time.sleep(0.5)




**En savoir plus**

Dans ce projet, nous avons utilisé les modules ``machine`` et ``time`` de MicroPython, vous pouvez trouver plus de façons de les utiliser ici.

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_

* `time <https://docs.micropython.org/en/latest/library/time.html>`_
