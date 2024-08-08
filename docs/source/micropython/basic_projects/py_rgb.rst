.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_rgb:

2.3 Lumière Colorée
===========================

Dans ce projet, nous allons explorer le monde fascinant du mélange de couleurs additives en utilisant une LED RGB.

La LED RGB combine trois couleurs primaires, à savoir le rouge, le vert et le bleu, dans un seul boîtier. Ces trois LEDs partagent une broche cathode commune, tandis que chaque broche anode contrôle l'intensité de la couleur correspondante.

En variant l'intensité du signal électrique appliqué à chaque anode, nous pouvons créer une large gamme de couleurs. Par exemple, le mélange de lumières rouge et verte à haute intensité donnera une lumière jaune, tandis que la combinaison de lumières bleue et verte produira du cyan.

À travers ce projet, nous allons explorer les principes du mélange de couleurs additives et libérer notre créativité en manipulant la LED RGB pour afficher des couleurs captivantes et vibrantes.

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Broches disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schéma**

.. image:: ../../img/circuit/circuit_2.3_rgb.png

Les broches PWM pin27, pin26 et pin25 contrôlent respectivement les broches rouge, vert et bleu de la LED RGB, et connectent la broche cathode commune à la masse (GND). Cela permet à la LED RGB d'afficher une couleur spécifique en superposant la lumière sur ces broches avec différentes valeurs PWM.

**Câblage**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

La LED RGB a 4 broches : la broche longue est la cathode commune, qui est généralement connectée à la masse (GND) ; la broche gauche à côté de la broche la plus longue est rouge ; et les deux broches à droite sont vert et bleu.

.. image:: ../../img/wiring/2.3_color_light_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``2.3_colorful_light.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    from machine import Pin, PWM
    import time

    # Définir les broches GPIO pour la LED RGB
    RED_PIN = 27
    GREEN_PIN = 26
    BLUE_PIN = 25

    # Configurer les canaux PWM
    red = PWM(Pin(RED_PIN))
    green = PWM(Pin(GREEN_PIN))
    blue = PWM(Pin(BLUE_PIN))

    # Définir la fréquence PWM
    red.freq(1000)
    green.freq(1000)
    blue.freq(1000)

    def set_color(r, g, b):
        red.duty(r)
        green.duty(g)
        blue.duty(b)

    while True:
        # Définir différentes couleurs et attendre un moment
        set_color(1023, 0, 0) # Rouge
        time.sleep(1)
        set_color(0, 1023, 0) # Vert
        time.sleep(1)
        set_color(0, 0, 1023) # Bleu
        time.sleep(1)
        set_color(1023, 0, 1023) # Violet
        time.sleep(1)

Lorsque le script s'exécute, vous verrez les LEDs RGB afficher rouge, vert, bleu, violet, etc.

**En savoir plus**

Vous pouvez également définir la couleur que vous souhaitez avec le code suivant avec les valeurs de couleur familières de 0 à 255.

.. note::

    * Ouvrez le fichier ``2.3_colorful_light_rgb.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    from machine import Pin, PWM
    import time

    # Définir les broches GPIO pour la LED RGB
    RED_PIN = 27
    GREEN_PIN = 26
    BLUE_PIN = 25

    # Configurer les canaux PWM
    red = PWM(Pin(RED_PIN))
    green = PWM(Pin(GREEN_PIN))
    blue = PWM(Pin(BLUE_PIN))

    # Définir la fréquence PWM
    red.freq(1000)
    green.freq(1000)
    blue.freq(1000)

    # Mappage des valeurs d'entrée d'une plage à une autre
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Convertir les valeurs de couleur (0-255) en valeurs de cycle de service (0-1023)
    def color_to_duty(rgb_value):
        rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
        return rgb_value

    def set_color(red_value,green_value,blue_value):
        red.duty(color_to_duty(red_value))
        green.duty(color_to_duty(green_value))
        blue.duty(color_to_duty(blue_value))

    while True:
        # Définir différentes couleurs et attendre un moment
        set_color(255, 0, 0) # Rouge
        time.sleep(1)
        set_color(0, 255, 0) # Vert
        time.sleep(1)
        set_color(0, 0, 255) # Bleu
        time.sleep(1)
        set_color(255, 0, 255) # Violet
        time.sleep(1)

Ce code est basé sur l'exemple précédent, mais il mappe les valeurs de couleur de 0 à 255 à une plage de cycle de service de 0 à 1023.

* La fonction ``interval_mapping`` est une fonction utilitaire qui mappe une valeur d'une plage à une autre. Elle prend cinq arguments : la valeur d'entrée, les valeurs minimales et maximales de la plage d'entrée, et les valeurs minimales et maximales de la plage de sortie. Elle renvoie la valeur d'entrée mappée à la plage de sortie.

    .. code-block:: python

        def color_to_duty(rgb_value):
            rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
            return rgb_value

* La fonction ``color_to_duty`` prend une valeur RGB entière (par exemple 255,0,255) et la mappe à une valeur de cycle de service adaptée aux broches PWM. La valeur RGB d'entrée est d'abord mappée de la plage 0-255 à la plage 0-1023 en utilisant la fonction ``interval_mapping``. La sortie de ``interval_mapping`` est ensuite renvoyée comme valeur de cycle de service.

    .. code-block:: python

        def color_to_duty(rgb_value):
            rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
            return rgb_value

* La fonction ``color_set`` prend trois arguments entiers : les valeurs rouge, vert et bleu pour la LED. Ces valeurs sont passées à ``color_to_duty`` pour obtenir les valeurs de cycle de service pour les broches PWM. Les valeurs de cycle de service sont ensuite définies pour les broches correspondantes en utilisant la méthode ``duty``.

    .. code-block:: python

        def set_color(red_value,green_value,blue_value):
            red.duty(color_to_duty(red_value))
            green.duty(color_to_duty(green_value))
            blue.duty(color_to_duty(blue_value))

