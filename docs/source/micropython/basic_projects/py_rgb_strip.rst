.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_rgb_strip:

2.7 Bande LED RGB
======================

Dans ce projet, nous explorerons le monde fascinant des bandes LED WS2812 et donnerons vie à un affichage vibrant de couleurs. Avec la capacité de contrôler individuellement chaque LED de la bande, nous pouvons créer des effets lumineux captivants qui éblouiront les sens.

De plus, nous avons inclus une extension excitante à ce projet, où nous explorerons le domaine de l'aléatoire. En introduisant des couleurs aléatoires et en implémentant un effet de lumière fluide, nous pouvons créer une expérience visuelle envoûtante et captivante.

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
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_2.7_ws2812.png
    :width: 500
    :align: center


**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Broches disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


.. note::

    IO33 n'est pas disponible pour ce projet.

    La bande LED WS2812 est un type de bande LED qui nécessite un signal de modulation de largeur d'impulsion (PWM) précis. Le signal PWM a des exigences précises en termes de temps et de tension. Par exemple, un bit "0" pour le WS2812 correspond à une impulsion de niveau haut d'environ 0,4 microsecondes, tandis qu'un bit "1" correspond à une impulsion de niveau haut d'environ 0,8 microsecondes. Cela signifie que la bande doit recevoir des changements de tension à haute fréquence.

    Cependant, avec une résistance pull-up de 4,7K et un condensateur pull-down de 100nf sur IO33, un simple filtre passe-bas est créé. Ce type de circuit "lisse" les signaux haute fréquence, car le condensateur a besoin de temps pour se charger et se décharger lorsqu'il reçoit des changements de tension. Par conséquent, si le signal change trop rapidement (c'est-à-dire à haute fréquence), le condensateur ne pourra pas suivre. Cela entraîne un signal de sortie flou et méconnaissable pour la bande.

**Câblage**

.. image:: ../../img/wiring/2.7_rgb_strip_bb.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``2.7_rgb_strip.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

    
.. code-block:: python

    from machine import Pin
    from neopixel import NeoPixel

    pin = Pin(14, Pin.OUT)   # définir une broche en sortie pour piloter les NeoPixels
    pixels = NeoPixel(pin, 8)   # créer un pilote NeoPixel sur la broche pour 8 pixels

    pixels[0] = [64,154,227]    # définir la couleur du pixel
    pixels[1] = [128,0,128]
    pixels[2] = [50,150,50]
    pixels[3] = [255,30,30]
    pixels[4] = [0,128,255]
    pixels[5] = [99,199,0]
    pixels[6] = [128,128,128]
    pixels[7] = [255,100,0]

    pixels.write()              # envoyer les données à tous les pixels


Sélectionnons quelques couleurs préférées et affichons-les sur la bande LED RGB !

**Comment ça marche ?**

#. Dans le module ``neopixel``, nous avons intégré des fonctions liées dans la classe ``NeoPixel``.

    .. code-block:: python

        from neopixel import NeoPixel

#. Utilisez la classe ``NeoPixel`` du module ``neopixel`` pour initialiser l'objet ``pixels``, en spécifiant la broche de données et le nombre de LEDs.

    .. code-block:: python

        pixels = NeoPixel(pin, 8)   # créer un pilote NeoPixel sur la broche pour 8 pixels

#. Définissez la couleur de chaque LED et utilisez la méthode ``write()`` pour envoyer les données à la LED WS2812 afin de mettre à jour son affichage.

    .. code-block:: python

        pixels[0] = [64,154,227]    # définir la couleur du pixel
        pixels[1] = [128,0,128]
        pixels[2] = [50,150,50]
        pixels[3] = [255,30,30]
        pixels[4] = [0,128,255]
        pixels[5] = [99,199,0]
        pixels[6] = [128,128,128]
        pixels[7] = [255,100,0]

        pixels.write()              # envoyer les données à tous les pixels

**En savoir plus**

Nous pouvons générer des couleurs aléatoires et créer une lumière fluide colorée.

.. note::

    * Ouvrez le fichier ``2.7_rgb_strip_random.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 


.. code-block:: python

    from machine import Pin
    import neopixel
    import time
    import random

    # Définir le nombre de pixels pour la lumière courante
    num_pixels = 8

    # Définir la broche de données pour la bande LED RGB
    data_pin = Pin(14, Pin.OUT)

    # Initialiser l'objet bande LED RGB
    pixels = neopixel.NeoPixel(data_pin, num_pixels)

    # Boucle continue de la lumière courante
    while True:
        for i in range(num_pixels):
            # Générer une couleur aléatoire pour le pixel actuel
            color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
            
            # Allumer le pixel actuel avec la couleur aléatoire
            pixels[i] = color
            
            # Mettre à jour l'affichage de la bande LED RGB
            pixels.write()
            
            # Éteindre le pixel actuel
            pixels[i] = (0, 0, 0)
            
            # Attendre une période de temps pour contrôler la vitesse de la lumière courante
            time.sleep_ms(100)


* Dans la boucle ``while``, nous utilisons une boucle ``for`` pour allumer chaque pixel de la bande LED RGB un par un.
* Utilisez d'abord la fonction ``random.randint()`` pour générer une couleur aléatoire pour le pixel actuel.
* Ensuite, allumez le pixel actuel avec la couleur aléatoire, utilisez la méthode ``write()`` de l'objet ``NeoPixel`` pour envoyer les données de couleur à la bande LED RGB afin de mettre à jour son affichage.
* Enfin, éteignez le pixel actuel en réglant sa couleur sur (0, 0, 0), et attendez une période de temps pour contrôler la vitesse de la lumière courante.

