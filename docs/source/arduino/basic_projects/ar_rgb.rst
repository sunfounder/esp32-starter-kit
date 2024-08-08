.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_rgb:

2.3 Lumière Colorée
==============================================

Dans ce projet, nous allons plonger dans le monde fascinant du mélange de couleurs additives en utilisant une LED RGB.

La LED RGB combine trois couleurs primaires, à savoir le rouge, le vert et le bleu, dans un seul boîtier. Ces trois LED partagent une broche cathode commune, tandis que chaque broche anode contrôle l'intensité de la couleur correspondante.

En variant l'intensité du signal électrique appliqué à chaque anode, nous pouvons créer une large gamme de couleurs. Par exemple, en mélangeant une lumière rouge et verte à haute intensité, nous obtiendrons une lumière jaune, tandis qu'en combinant la lumière bleue et verte, nous produirons du cyan.

À travers ce projet, nous allons explorer les principes du mélange de couleurs additives et libérer notre créativité en manipulant la LED RGB pour afficher des couleurs captivantes et vibrantes.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

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

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

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


**Pins disponibles**

Voici une liste des pins disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Pins disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schéma**

.. image:: ../../img/circuit/circuit_2.3_rgb.png

Les pins PWM pin27, pin26 et pin25 contrôlent respectivement les broches Rouge, Vert et Bleu de la LED RGB et connectent la broche cathode commune à la masse. Cela permet à la LED RGB d'afficher une couleur spécifique en superposant la lumière sur ces broches avec différentes valeurs PWM.


**Câblage**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

La LED RGB a 4 broches : la broche la plus longue est la broche cathode commune, qui est généralement connectée à la masse ; la broche gauche à côté de la plus longue est rouge ; et les deux broches à droite sont vert et bleu.

.. image:: ../../img/wiring/2.3_color_light_bb.png


**Code**

Ici, nous pouvons choisir notre couleur préférée dans un logiciel de dessin (tel que paint) et l'afficher avec la LED RGB.

.. note::

    * Vous pouvez ouvrir le fichier ``2.3_rgb_led.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\2.3_rgb_led``. 
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/49a579a1-ae9b-4e23-b6cd-c20e5695191b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

.. image:: img/edit_colors.png

Écrivez la valeur RGB dans ``color_set()``, vous pourrez voir la LED RGB afficher les couleurs que vous souhaitez.


**Comment ça marche ?**

#. Définir les broches GPIO, les canaux PWM et la fréquence (en Hz) et la résolution (en bits).

    .. code-block:: arduino

        // Définir les broches de la LED RGB
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        // Définir la fréquence PWM et la résolution
        const int freq = 5000;
        const int resolution = 8;


#. La fonction ``setup()`` initialise les canaux PWM avec la fréquence et la résolution spécifiées, puis attache les broches LED à leurs canaux PWM correspondants.

    .. code-block:: arduino

        void setup() {
          // Configurer les broches PWM
          ledcAttach(redPin, freq, resolution);
          ledcAttach(greenPin, freq, resolution);
          ledcAttach(bluePin, freq, resolution);
        }
    
    Ici, nous utilisons le |link_ledc| (contrôle LED) périphérique qui est principalement conçu pour contrôler l'intensité des LED, bien qu'il puisse également être utilisé pour générer des signaux PWM à d'autres fins.

    * ``bool ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);``: Cette fonction est utilisée pour configurer la broche LEDC avec la fréquence et la résolution données. Le canal LEDC sera sélectionné automatiquement.

        * ``pin`` sélectionner la broche GPIO.
        * ``freq`` sélectionner la fréquence du pwm.
        * ``resolution_bits`` sélectionner la résolution pour le canal ledc. La plage est de 1 à 14 bits (1 à 20 bits pour ESP32).


#. La fonction ``loop()`` parcourt diverses couleurs (rouge, vert, bleu, jaune, violet et cyan) avec des intervalles d'une seconde entre chaque changement de couleur.

    .. code-block:: arduino

        void loop() {
            setColor(255, 0, 0); // Rouge
            delay(1000);
            setColor(0, 255, 0); // Vert
            delay(1000);
            setColor(0, 0, 255); // Bleu
            delay(1000);
            setColor(255, 255, 0); // Jaune
            delay(1000);
            setColor(80, 0, 80); // Violet
            delay(1000);
            setColor(0, 255, 255); // Cyan
            delay(1000);
        }


#. La fonction ``setColor()`` définit la couleur désirée en écrivant les valeurs de cycle de service appropriées à chaque canal PWM. La fonction prend trois arguments entiers pour les valeurs des couleurs rouge, verte et bleue.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
          ledcWrite(redPin, red);
          ledcWrite(greenPin, green);
          ledcWrite(bluePin, blue);
        }
    
    * ``bool ledcWrite(uint8_t pin, uint32_t duty);``: Cette fonction est utilisée pour définir le cycle de service pour la broche LEDC.
        
        * ``pin`` sélectionner la broche LEDC.
        * ``duty`` sélectionner le cycle de service à définir pour le canal sélectionné.
