.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_fading:

2.2 LED à intensité variable
===================================

Dans le projet précédent, nous avons contrôlé la LED en l'allumant et en l'éteignant à l'aide d'une sortie numérique. Dans ce projet, nous allons créer un effet de respiration sur la LED en utilisant la modulation de largeur d'impulsion (PWM). Le PWM est une technique qui nous permet de contrôler la luminosité d'une LED ou la vitesse d'un moteur en faisant varier le rapport cyclique d'un signal carré.

Avec le PWM, au lieu de simplement allumer ou éteindre la LED, nous allons ajuster le temps pendant lequel la LED est allumée par rapport au temps pendant lequel elle est éteinte à chaque cycle. En allumant et éteignant rapidement la LED à des intervalles variables, nous pouvons créer l'illusion que la LED s'allume et s'éteint progressivement, simulant un effet de respiration.

En utilisant les capacités PWM de l'ESP32 board, nous pouvons obtenir un contrôle précis et fluide de la luminosité de la LED. Cet effet de respiration ajoute un élément dynamique et visuellement attrayant à vos projets, créant un affichage accrocheur ou une ambiance.

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

Ce projet utilise le même circuit que le premier projet :ref:`py_blink`, mais le type de signal est différent. Dans le premier projet, nous avons utilisé une sortie numérique haute et basse (0 et 1) directement à partir de la broche 26 pour allumer ou éteindre la LED. Dans ce projet, nous utilisons un signal PWM provenant de la broche 26 pour contrôler la luminosité de la LED.

**Câblage**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``2.2_fading_led.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    # Importer les bibliothèques nécessaires
    from machine import Pin, PWM
    import time

    # Créer un objet PWM
    led = PWM(Pin(26), freq=1000)

    while True:
        # Augmenter progressivement la luminosité
        for duty_cycle in range(0, 1024, 1):
            led.duty(duty_cycle)
            time.sleep(0.01)

        # Diminuer progressivement la luminosité
        for duty_cycle in range(1023, -1, -1):
            led.duty(duty_cycle)
            time.sleep(0.01)


La LED deviendra progressivement plus lumineuse à mesure que le code s'exécute.

**Comment ça marche ?**

Dans l'ensemble, ce code montre comment utiliser les signaux PWM pour contrôler la luminosité d'une LED.

#. Il importe deux modules, ``machine`` et ``time``. Le module ``machine`` fournit un accès de bas niveau au matériel du microcontrôleur, tandis que le module ``time`` fournit des fonctions pour les opérations liées au temps.

    .. code-block:: python

        import machine
        import time

#. Ensuite, il initialise un objet ``PWM`` pour contrôler la LED connectée à la broche 26 et définit la fréquence du signal PWM à 1000 Hz.

    .. code-block:: python

        led = PWM(Pin(26), freq=1000)

#. Faire varier l'intensité de la LED à l'aide d'une boucle : La boucle extérieure ``while True`` s'exécute indéfiniment. Deux boucles ``for`` imbriquées sont utilisées pour augmenter et diminuer progressivement la luminosité de la LED. Le cycle de travail varie de 0 à 1023, représentant un cycle de travail de 0% à 100%.

    .. code-block:: python

        # Importer les bibliothèques nécessaires
        from machine import Pin, PWM
        import time

        # Créer un objet PWM
        led = PWM(Pin(26), freq=1000)

        while True:
            # Augmenter progressivement la luminosité
            for duty_cycle in range(0, 1024, 2):
                led.duty(duty_cycle)
                time.sleep(0.01)

            # Diminuer progressivement la luminosité
            for duty_cycle in range(1023, -1, -2):
                led.duty(duty_cycle)
                time.sleep(0.01)


    * ``range()`` : Crée une séquence d'entiers de 0 à 1023. 
    * Le cycle de travail du signal PWM est défini sur chaque valeur de la séquence à l'aide de la méthode ``duty()`` de l'objet ``PWM``. 
    * ``time.sleep()`` : Met en pause l'exécution du programme pendant 10 millisecondes entre chaque itération de la boucle, créant une augmentation progressive de la luminosité au fil du temps.

    
