.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_blink:

2.1 Bonjour, LED ! 
============================

Tout comme imprimer "Hello, world!" est la première étape pour apprendre à programmer, utiliser un programme pour contrôler une LED est l'introduction traditionnelle à l'apprentissage de la programmation physique.

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants. 

Il est certainement pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément aux liens ci-dessous.

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

Ce circuit fonctionne sur un principe simple, et la direction du courant est montrée dans la figure. La LED s'allumera après la résistance de limitation de courant de 220 ohms lorsque la broche 26 sort un niveau haut. La LED s'éteindra lorsque la broche 26 sort un niveau bas.

**Câblage**

.. image:: ../../img/wiring/2.1_hello_led_bb.png



**Téléverser le Code**

#. Vous pouvez ouvrir le fichier ``2.1_hello_led.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\2.1_hello_led``. Ou copiez ce code directement dans l'IDE Arduino.
    
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/1bff2463-40ad-43c1-8815-9f448bab3735/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
#. Ensuite, connectez l'ESP32 WROOM 32E à votre ordinateur en utilisant un câble Micro USB. 

    * :ref:`unknown_com_port`

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Sélectionnez la carte (ESP32 Dev Module) et le port approprié.

    .. image:: img/choose_board.png

#. Maintenant, cliquez sur le bouton **Téléverser** pour téléverser le code sur la carte ESP32.
    
    .. image:: img/click_upload.png

#. Après que le code a été téléversé avec succès, vous verrez la LED clignoter.

**Comment ça marche ?**

#. Déclarez une constante entière nommée ``ledPin`` et attribuez-lui la valeur 26. 

    .. code-block:: arduino

        const int ledPin = 26;  // La broche GPIO pour la LED

#. Maintenant, initialisez la broche dans la fonction ``setup()``, où vous devez initialiser la broche en mode ``OUTPUT``.

    .. code-block:: arduino

        void setup() {
            pinMode(ledPin, OUTPUT);
        }

    * ``void pinMode(uint8_t pin, uint8_t mode);``: Cette fonction est utilisée pour définir le mode de fonctionnement GPIO pour une broche spécifique.

        * ``pin`` définit le numéro de la broche GPIO.
        * ``mode`` définit le mode de fonctionnement.

        Les modes suivants sont pris en charge pour l'entrée et la sortie de base :

        * ``INPUT`` définit le GPIO comme entrée sans pullup ni pulldown (haute impédance).
        * ``OUTPUT`` définit le GPIO comme mode sortie/lecture.
        * ``INPUT_PULLDOWN`` définit le GPIO comme entrée avec le pulldown interne.
        * ``INPUT_PULLUP`` définit le GPIO comme entrée avec le pullup interne.

#. La fonction ``loop()`` contient la logique principale du programme et s'exécute en continu. Elle alterne entre le réglage de la broche haut et bas, avec des intervalles d'une seconde entre les changements.

    .. code-block:: arduino

        void loop() {
            digitalWrite(ledPin, HIGH);   // allume la LED (HIGH est le niveau de tension)
            delay(1000);                       // attend une seconde
            digitalWrite(ledPin, LOW);    // éteint la LED en mettant la tension à LOW
            delay(1000);                       // attend une seconde
        }

    * ``void digitalWrite(uint8_t pin, uint8_t val);``: Cette fonction définit l'état du GPIO sélectionné à ``HIGH`` ou ``LOW``. Cette fonction est uniquement utilisée si le ``pinMode`` a été configuré en ``OUTPUT``.
    
        * ``pin`` définit le numéro de la broche GPIO.
        * ``val`` définit l'état de sortie numérique à ``HIGH`` ou ``LOW``.
