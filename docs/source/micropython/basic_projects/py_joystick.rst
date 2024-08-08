.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_joystick:

5.11 Manipuler le Joystick
================================

Si vous jouez beaucoup aux jeux vidéo, alors vous devriez être très familier avec le Joystick.
Il est généralement utilisé pour déplacer le personnage, faire tourner l'écran, etc.

Le principe qui permet au Joystick de transmettre nos actions à l'ordinateur est très simple.
On peut le considérer comme étant composé de deux potentiomètres perpendiculaires l'un à l'autre.
Ces deux potentiomètres mesurent la valeur analogique du joystick verticalement et horizontalement, résultant en une valeur (x,y) dans un système de coordonnées planes.

Le joystick de ce kit possède également une entrée numérique, qui est activée lorsque le joystick est pressé.

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Pour entrée analogique
            - IO14, IO25, I35, I34, I39, I36
        *   - Pour entrée numérique
            - IO13, IO14, IO27, IO26, IO25, IO33, IO4, IO18, IO19, IO21, IO22, IO23

* **Broches de strap (entrée)**

    Les broches de strap sont un ensemble spécial de broches utilisées pour déterminer des modes de démarrage spécifiques lors du démarrage de l'appareil (c'est-à-dire la réinitialisation à la mise sous tension).

    .. list-table::
        :widths: 5 15

        *   - Broches de strap
            - IO5, IO0, IO2, IO12, IO15 
    
    En général, il n'est **pas recommandé de les utiliser comme broches d'entrée**. Si vous souhaitez utiliser ces broches, tenez compte de l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez vous référer à la section :ref:`esp32_strapping`.

**Schéma**

.. image:: ../../img/circuit/circuit_5.11_joystick.png

La broche SW (axe Z) est connectée à IO33, qui a une résistance de pull-up intégrée de 4,7K. Par conséquent, lorsque le bouton SW n'est pas pressé, il émet un niveau haut. Lorsque le bouton est pressé, il émet un niveau bas.

Les broches I34 et I35 changeront leurs valeurs en fonction de la manipulation du joystick. La plage de valeurs est de 0 à 4095.

**Câblage**

.. image:: ../../img/wiring/5.11_joystick_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.11_joystick.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    from machine import ADC, Pin
    import time

    xAxis = ADC(Pin(34, Pin.IN)) # créer un objet ADC agissant sur une broche      
    xAxis.atten(xAxis.ATTN_11DB)
    yAxis = ADC(Pin(35, Pin.IN)) # créer un objet ADC agissant sur une broche      
    yAxis.atten(yAxis.ATTN_11DB)
    button = Pin(33, Pin.IN, Pin.PULL_UP)

    while True:
        xValue = xAxis.read()  # lire une valeur analogique brute dans la plage 0-4095
        yValue = yAxis.read()  # lire une valeur analogique brute dans la plage 0-4095
        btnValue = button.value()
        print(f"X:{xValue}, Y:{yValue}, Button:{btnValue}")
        time.sleep(0.1)

Lorsque le programme s'exécute, la Shell affiche les valeurs x, y et du bouton du joystick.

.. code-block:: 

    X:1921, Y:1775, Button:0
    X:1921, Y:1775, Button:0
    X:1923, Y:1775, Button:0
    X:1924, Y:1776, Button:0
    X:1926, Y:1777, Button:0
    X:1925, Y:1776, Button:0
    X:1924, Y:1776, Button:0


* Les valeurs des axes x et y sont des valeurs analogiques variant de 0 à 4095.
* Le bouton est une valeur numérique avec un état de 1 (relâché) ou 0 (pressé).

    .. image:: img/joystick_direction.png
