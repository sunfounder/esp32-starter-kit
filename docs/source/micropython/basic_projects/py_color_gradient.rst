.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_color_gradient:

6.5 Dégradé de Couleur
=============================

Êtes-vous prêt à découvrir un monde de couleurs ? Ce projet vous emmènera 
dans un voyage magique où vous pourrez contrôler une bande LED et obtenir 
des transitions de couleur en douceur. Que vous cherchiez à ajouter de la 
couleur à votre décoration intérieure ou à vous lancer dans un projet de 
programmation amusant, ce projet est fait pour vous. Plongeons ensemble dans 
ce monde coloré !

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.5_color_gradient.png

Ce projet utilise une bande LED et un potentiomètre pour créer un effet de mélange de couleurs. Le potentiomètre est utilisé pour ajuster la valeur de la teinte de la LED, qui est ensuite convertie en valeurs RVB à l'aide d'une fonction de conversion de couleur. Les valeurs RVB sont ensuite utilisées pour mettre à jour la couleur de la LED.

**Câblage**

.. image:: ../../img/wiring/6.5_color_strip_bb.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``6.5_color_gradient.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    from machine import Pin, ADC, PWM
    import neopixel
    import time

    NUM_LEDS = 8  # Nombre de LEDs dans la bande
    PIN_NUM = 26  # Bande LED
    POT_PIN = 14  # Potentiomètre

    # Initialiser le potentiomètre
    potentiometer = ADC(Pin(POT_PIN))
    potentiometer.atten(ADC.ATTN_11DB)

    # Initialiser la bande LED NeoPixel
    np = neopixel.NeoPixel(Pin(PIN_NUM), NUM_LEDS)

    # Fonction pour convertir l'espace colorimétrique HSL en espace RVB
    def hsl_to_rgb(h, s, l):
        # Fonction auxiliaire pour convertir la teinte en RVB
        def hue_to_rgb(p, q, t):
            if t < 0:
                t += 1
            if t > 1:
                t -= 1
            if t < 1/6:
                return p + (q - p) * 6 * t
            if t < 1/2:
                return q
            if t < 2/3:
                return p + (q - p) * (2/3 - t) * 6
            return p

        if s == 0:
            r = g = b = l
        else:
            q = l * (1 + s) if l < 0.5 else l + s - l * s
            p = 2 * l - q
            r = hue_to_rgb(p, q, h + 1/3)
            g = hue_to_rgb(p, q, h)
            b = hue_to_rgb(p, q, h - 1/3)

        return (int(r * 255), int(g * 255), int(b * 255))

    # Fonction pour définir la couleur de toutes les LEDs dans la bande
    def set_color(np, color):
        for i in range(NUM_LEDS):
            np[i] = color
        np.write()

    # Boucle principale
    while True:
        # Lire la valeur du potentiomètre et la normaliser dans la plage [0, 1]
        pot_value = potentiometer.read() / 4095.0
        hue = pot_value  # Définir la valeur de la teinte en fonction de la position du potentiomètre
        saturation = 1  # Définir la saturation à 1 (complètement saturée)
        lightness = 0.5  # Définir la luminosité à 0.5 (à mi-chemin entre le noir et le blanc)

        # Convertir la couleur HSL en RVB
        current_color = hsl_to_rgb(hue, saturation, lightness)

        # Définir la couleur de la bande LED en fonction de la valeur RVB convertie
        set_color(np, current_color)

        # Pause pour permettre des transitions en douceur
        time.sleep(0.1)


Lorsque le code s'exécute, tournez lentement le potentiomètre et vous verrez la couleur de la bande LED RGB passer du rouge au violet.

