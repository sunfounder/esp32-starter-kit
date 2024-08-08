.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_flowing_light:

6.2 Lumière Défilante
=================================

Avez-vous déjà voulu ajouter un élément amusant et interactif à votre espace de vie ? 
Ce projet consiste à créer une lumière défilante en utilisant une bande LED WS2812 et un module d'évitement d'obstacles. 
La lumière défilante change de direction lorsqu'un obstacle est détecté, ce qui en fait un ajout excitant à votre décoration intérieure ou de bureau.

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
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.2_flowing_led.png
    :align: center

La bande LED WS2812 est composée d'une série de LEDs individuelles qui peuvent être programmées pour afficher différentes couleurs et motifs. 
Dans ce projet, la bande est configurée pour afficher une lumière défilante qui se déplace dans une direction particulière et 
change de direction lorsqu'un obstacle est détecté par le module d'évitement d'obstacles.

**Câblage**

.. image:: ../../img/wiring/6.2_flowing_light_bb.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``6.2_flowing_led.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

    
.. code-block:: python

      from machine import Pin
      import neopixel
      import time
      import random

      # Définir le nombre de pixels pour la lumière défilante
      num_pixels = 8

      # Définir la broche de données pour la bande LED RGB
      data_pin = Pin(14, Pin.OUT)

      # Initialiser l'objet bande LED RGB
      pixels = neopixel.NeoPixel(data_pin, num_pixels)

      # Initialiser le capteur d'évitement
      avoid = Pin(25, Pin.IN)

      # Initialiser la variable de direction
      direction_forward = True

      # Initialiser le drapeau de direction inverse
      reverse_direction = False

      # Boucle continue de la lumière défilante
      while True:
      
      # Lire l'entrée du capteur infrarouge
      avoid_value = avoid.value()
      
      # Générer une couleur aléatoire pour le pixel actuel
      color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
                  
      # Si aucun obstacle n'est détecté
      if avoid_value:
            for i in range(num_pixels):
                  
                  # Allumer le pixel actuel avec la couleur aléatoire
                  pixels[i] = color
                  
                  # Mettre à jour l'affichage de la bande LED RGB
                  pixels.write()
                  
                  # Éteindre le pixel actuel
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)
                  
      # Si un obstacle est détecté, changer la direction de la bande LED
      else:
            for i in range(num_pixels-1, -1, -1):
                  
                  pixels[i] = color
                  pixels.write()
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)

Les LEDs de la bande RGB s'allument une par une lorsque le script s'exécute. Dès qu'un objet est placé devant le module d'évitement d'obstacles, les LEDs de la bande RGB s'allument une par une dans la direction opposée.
