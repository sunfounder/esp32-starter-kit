.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_rgb_strip:

2.7 Bande LED RGB
=========================

Dans ce projet, nous allons plonger dans le monde fascinant des bandes LED WS2812 et donner vie à un affichage vibrant de couleurs. Avec la capacité de contrôler individuellement chaque LED de la bande, nous pouvons créer des effets lumineux captivants qui éblouiront les sens.

De plus, nous avons inclus une extension passionnante à ce projet, où nous explorerons le domaine du hasard. En introduisant des couleurs aléatoires et en implémentant un effet de lumière fluide, nous pouvons créer une expérience visuelle envoûtante et captivante.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_2.7_ws2812.png
    :width: 500
    :align: center


**Pins disponibles**

Voici une liste des pins disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Pins disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


.. note::

    IO33 n'est pas disponible pour ce projet.

    La bande LED WS2812 est un type de bande LED qui nécessite un signal de modulation de largeur d'impulsion (PWM) précis. Le signal PWM a des exigences précises en termes de temps et de tension. Par exemple, un bit "0" pour le WS2812 correspond à une impulsion de niveau haut d'environ 0,4 microsecondes, tandis qu'un bit "1" correspond à une impulsion de niveau haut d'environ 0,8 microsecondes. Cela signifie que la bande doit recevoir des changements de tension à haute fréquence.

    Cependant, avec une résistance pull-up de 4,7K et un condensateur pull-down de 100nF sur IO33, un simple filtre passe-bas est créé. Ce type de circuit "lisse" les signaux haute fréquence, car le condensateur a besoin de temps pour se charger et se décharger lorsqu'il reçoit des changements de tension. Par conséquent, si le signal change trop rapidement (c'est-à-dire à haute fréquence), le condensateur ne pourra pas suivre. Cela entraîne un flou du signal de sortie et le rend méconnaissable pour la bande.

**Câblage**

.. image:: ../../img/wiring/2.7_rgb_strip_bb.png
    :width: 800

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``2.7_rgb_strip.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\2.7_rgb_strip``. Ou copiez ce code dans **Arduino IDE**.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`
    * La bibliothèque ``Adafruit NeoPixel`` est utilisée ici, vous pouvez l'installer à partir du **Gestionnaire de Bibliothèques**.

        .. image:: img/rgb_strip_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/bccd25f6-4e3e-45e2-b9f5-76a1b0866794/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Lorsque le code est téléversé avec succès, les LED de la bande s'allumeront séquentiellement avec une couleur jaune puis s'éteindront, créant un simple effet de poursuite.


**Comment ça marche ?**


#. Inclure la bibliothèque Adafruit NeoPixel : Cette ligne importe la bibliothèque Adafruit NeoPixel afin que le croquis puisse utiliser ses fonctions et classes pour contrôler la bande LED.

    .. code-block:: arduino

        #include <Adafruit_NeoPixel.h> // Inclure la bibliothèque Adafruit NeoPixel

#. Définir les constantes pour la bande LED.

    .. code-block:: arduino

        #define LED_PIN 13 // Bande LED NeoPixel
        #define NUM_LEDS 8 // Nombre de LEDs

#. Créer une instance de la classe Adafruit_NeoPixel.

    .. code-block:: arduino

       // Créer une instance de la classe Adafruit_NeoPixel
        Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

    Cette ligne crée une instance de la classe ``Adafruit_NeoPixel`` appelée ``strip`` et la configure avec le nombre de LEDs, la pin connectée à la bande LED et les paramètres du signal (ordre des couleurs GRB et fréquence de données de 800 kHz).


    * ``Adafruit_NeoPixel (uint16_t n, int16_t p = 6, neoPixelType t = NEO_GRB + NEO_KHZ800)``	

    Constructeur NeoPixel lorsque la longueur, la pin et le type de pixel sont connus au moment de la compilation. Retourne un objet Adafruit_NeoPixel. Appelez la fonction ``begin()`` avant utilisation.

        * ``n``: Nombre de NeoPixels dans la bande.
        * ``p``: Numéro de la pin Arduino qui pilotera les données NeoPixel.
        * ``t``: Type de pixel - additionnez les constantes ``NEO_*`` définies dans ``Adafruit_NeoPixel.h``, par exemple ``NEO_GRB+NEO_KHZ800`` pour les NeoPixels nécessitant un flux de données de 800 KHz (vs 400 KHz) avec des octets de couleur exprimés dans l'ordre vert, rouge, bleu par pixel.

#. Initialiser la bande RGB WS2812 et définir la couleur initiale de la bande sur noir (éteint).

    .. code-block:: arduino

        void setup() {
            strip.begin(); // Initialiser la bande NeoPixel
            strip.show(); // Définir la couleur initiale sur noir
        }

    * ``void begin (void)``: Configure la pin NeoPixel pour la sortie.
    * ``void show (void)``: Transmet les données des pixels en RAM aux NeoPixels.

#. Dans la fonction ``loop()``, les LED de la bande s'allumeront séquentiellement avec une couleur jaune puis s'éteindront, créant un simple effet de poursuite.

    .. code-block:: arduino

        void loop() {
        // Allumer les LEDs une par une
        for (int i = 0; i < NUM_LEDS; i++) {
            strip.setPixelColor(i, 100, 45, 0); // Définir la couleur de la ième LED en rouge
            strip.show(); // Mettre à jour la bande LED avec les nouvelles couleurs
            delay(100); // Attendre 100 millisecondes
        }
        
        // Éteindre les LEDs une par une
        for (int i = 0; i < NUM_LEDS; i++) {
            strip.setPixelColor(i, 0, 0, 0); // Définir la couleur de la ième LED en noir (éteindre)
            strip.show(); // Mettre à jour la bande LED avec les nouvelles couleurs
            delay(100); // Attendre 100 millisecondes
        }
        }

    * ``void setPixelColor (uint16_t n, uint8_t r, uint8_t g, uint8_t b)``

    Définir la couleur d'un pixel en utilisant des composantes rouge, verte et bleue séparées. Si vous utilisez des pixels RGBW, le blanc sera défini sur 0.

        * ``n``: Index du pixel, en commençant par 0.
        * ``r``: Luminosité du rouge, 0 = minimum (éteint), 255 = maximum.
        * ``g``: Luminosité du vert, 0 = minimum (éteint), 255 = maximum.
        * ``b``: Luminosité du bleu, 0 = minimum (éteint), 255 = maximum.

