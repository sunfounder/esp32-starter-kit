.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_potentiometer:

5.8 Tourner le bouton
===========================

Un potentiomètre est un dispositif à trois bornes couramment utilisé pour ajuster la résistance dans un circuit. Il dispose d'un bouton ou d'un levier coulissant qui permet de varier la valeur de résistance du potentiomètre. Dans ce projet, nous l'utiliserons pour contrôler la luminosité d'une LED, de manière similaire à une lampe de bureau dans notre vie quotidienne. En ajustant la position du potentiomètre, nous pouvons changer la résistance dans le circuit, régulant ainsi le courant traversant la LED et ajustant sa luminosité en conséquence. Cela nous permet de créer une expérience d'éclairage personnalisable et réglable, similaire à celle d'une lampe de bureau.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

**Pins disponibles**

* **Pins disponibles**

    Voici une liste des pins disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Pins disponibles
            - IO14, IO25, I35, I34, I39, I36

* **Pins de strapping**

    Les pins suivantes sont des pins de strapping, qui affectent le processus de démarrage de l'ESP32 lors de la mise sous tension ou du réinitialisation. Cependant, une fois l'ESP32 démarré avec succès, elles peuvent être utilisées comme des pins normales.

    .. list-table::
        :widths: 5 15

        *   - Pins de strapping
            - IO0, IO12


**Schéma**

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

Lorsque vous tournez le potentiomètre, la valeur de I35 changera. En programmant, vous pouvez utiliser la valeur de I35 pour contrôler la luminosité de la LED. Ainsi, lorsque vous tournez le potentiomètre, la luminosité de la LED changera en conséquence.


**Câblage**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**Code**


.. note::

    * Vous pouvez ouvrir le fichier ``5.8_pot.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.8_pot``. 
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`
   
.. raw:: html
     
    <iframe src=https://create.arduino.cc/editor/sunfounder01/aadce2e7-fd5d-4608-a557-f1e4d07ba795/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code avec succès, tournez le potentiomètre et vous verrez la luminosité de la LED changer en conséquence. En même temps, vous pouvez voir les valeurs analogiques et de tension du potentiomètre dans le moniteur série.


**Comment ça marche ?**

#. Définir les constantes pour les connexions des pins et les paramètres PWM.

    .. code-block:: arduino

        const int potPin = 35; // Potentiomètre connecté à
        const int ledPin = 26; // LED connectée à

        // Paramètres PWM
        const int freq = 5000; // Fréquence PWM
        const int resolution = 12; // Résolution PWM (bits)


    Ici, la résolution PWM est définie sur 12 bits et la plage est de 0-4095.

#. Configurer le système dans la fonction ``setup()``.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);

            // Configurer PWM
            ledcAttach(ledPin, freq, resolution);
        }

    * Dans la fonction ``setup()``, la communication série est démarrée à un débit de 115200 bauds. 
    * La fonction ``ledcAttach()`` est appelée pour configurer la pin LED spécifiée avec la fréquence et la résolution spécifiées.

#. Boucle principale (exécutée en continu) dans la fonction ``loop()``.

    .. code-block:: arduino

        void loop() {

            int potValue = analogRead(potPin); // lire la valeur du potentiomètre
            uint32_t voltage_mV = analogReadMilliVolts(potPin); // Lire la tension en millivolts
            
            ledcWrite(ledPin, potValue);
            
            Serial.print("Potentiometer Value: ");
            Serial.print(potValue);
            Serial.print(", Voltage: ");
            Serial.print(voltage_mV / 1000.0); // Convert millivolts to volts
            Serial.println(" V");
            
            delay(100);
        }

    * ``uint32_t analogReadMilliVolts(uint8_t pin);``: Cette fonction est utilisée pour obtenir la valeur ADC pour une pin/canal ADC donnée en millivolts.

        * ``pin`` GPIO pin pour lire la valeur analogique.

    La valeur du potentiomètre est directement utilisée comme cycle de travail PWM pour contrôler la luminosité de la LED via la fonction ``ledcWrite()``, car la plage des valeurs est également de 0 à 4095.
