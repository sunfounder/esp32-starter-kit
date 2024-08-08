.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_bluetooth_led:


7.2 Contrôle Bluetooth de LED RGB
======================================

Ce projet est une extension d'un projet précédent (:ref:`ar_bluetooth`), ajoutant des configurations de LED RGB et des commandes personnalisées telles que "led_off", "red", "green", etc. Ces commandes permettent de contrôler la LED RGB en envoyant des commandes depuis un appareil mobile utilisant LightBlue.

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**Étapes de fonctionnement**

#. Construisez le circuit.

    .. image:: ../../components/img/rgb_pin.jpg
        :width: 200
        :align: center

    La LED RGB a 4 broches : la broche longue est la cathode commune, qui est généralement connectée à la masse ; la broche gauche à côté de la broche la plus longue est le rouge ; et les deux broches à droite sont le vert et le bleu.

    .. image:: ../../img/wiring/2.3_color_light_bb.png

#. Ouvrez le fichier ``7.2_bluetooth_rgb_led.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\7.2_bluetooth_rgb_led``, ou copiez le code dans l'IDE Arduino.

    .. raw:: html
         
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b9331c9d-e9ea-4970-87ce-bf2ca8c231b2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Pour éviter les conflits de UUID, il est recommandé de générer aléatoirement trois nouveaux UUID en utilisant le |link_uuid| fourni par le Bluetooth SIG, et de les remplir dans les lignes de code suivantes.

    .. note::
        Si vous avez déjà généré trois nouveaux UUID dans le projet :ref:`ar_bluetooth`, alors vous pouvez continuer à les utiliser.


    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png

#. Sélectionnez la carte et le port corrects, puis cliquez sur le bouton **Upload**.

#. Après avoir téléchargé le code avec succès, activez le **Bluetooth** sur votre appareil mobile et ouvrez l'application **LightBlue**.

    .. image:: img/bluetooth_open.png

#. Sur la page **Scan**, trouvez **ESP32-Bluetooth** et cliquez sur **CONNECT**. Si vous ne le voyez pas, essayez de rafraîchir la page plusieurs fois. Lorsque **"Connected to device!"** apparaît, la connexion Bluetooth est réussie. Faites défiler vers le bas pour voir les trois UUID définis dans le code.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Appuyez sur l'UUID d'envoi, puis définissez le format des données sur "UTF-8 String". Vous pouvez maintenant écrire ces commandes : "led_off", "red", "green", "blue", "yellow" et "purple" pour voir si la LED RGB répond à ces instructions.

    .. image:: img/bluetooth_send_rgb.png
    

**Comment ça marche ?**

Ce code est une extension d'un projet précédent (:ref:`ar_bluetooth`), ajoutant des configurations de LED RGB et des commandes personnalisées telles que "led_off", "red", "green", etc. Ces commandes permettent de contrôler la LED RGB en envoyant des commandes depuis un appareil mobile utilisant LightBlue.

Analysons le code étape par étape :

* Ajoutez de nouvelles variables globales pour les broches LED RGB, les canaux PWM, la fréquence et la résolution.

    .. code-block:: arduino

        ...

        // Définir les broches de la LED RGB
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        ...

* Dans la fonction ``setup()``, les canaux PWM sont initialisés avec la fréquence et la résolution prédéfinies. Les broches LED RGB sont ensuite attachées à leurs canaux PWM respectifs.

    .. code-block:: arduino
        
        void setup() {
            ...

            ledcAttach(redPin, freq, resolution);
            ledcAttach(greenPin, freq, resolution);
            ledcAttach(bluePin, freq, resolution);
        }

* Modifiez la méthode ``onWrite`` dans la classe ``MyCharacteristicCallbacks``. Cette fonction écoute les données provenant de la connexion Bluetooth. En fonction de la chaîne reçue (comme ``"led_off"``, ``"red"``, ``"green"``, etc.), elle contrôle la LED RGB.

    .. code-block:: arduino

        // Définir les callbacks de la caractéristique BLE
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                std::string value = std::string(pCharacteristic->getValue().c_str());
                if (value == "led_off") {
                    setColor(0, 0, 0); // éteindre la LED RGB
                    Serial.println("RGB LED turned off");
                } else if (value == "red") {
                    setColor(255, 0, 0); // Rouge
                    Serial.println("red");
                }
                else if (value == "green") {
                    setColor(0, 255, 0); // Vert
                    Serial.println("green");
                }
                else if (value == "blue") {
                    setColor(0, 0, 255); // Bleu
                    Serial.println("blue");
                }
                else if (value == "yellow") {
                    setColor(255, 150, 0); // Jaune
                    Serial.println("yellow");
                }
                else if (value == "purple") {
                    setColor(80, 0, 80); // Violet
                    Serial.println("purple");
                }
            }
        };

* Enfin, une fonction est ajoutée pour définir la couleur de la LED RGB.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // Pour les LEDs RGB à anode commune, utilisez 255 moins la valeur de la couleur
            ledcWrite(redPin, red);
            ledcWrite(greenPin, green);
            ledcWrite(bluePin, blue);
        }


En résumé, ce script permet un modèle d'interaction de contrôle à distance, où l'ESP32 fonctionne comme un serveur Bluetooth Low Energy (BLE).


Le client BLE connecté (comme un smartphone) peut envoyer des commandes sous forme de chaînes pour changer la couleur d'une LED RGB. L'ESP32 renvoie également la chaîne reçue au client, permettant à ce dernier de savoir quelle opération a été effectuée.

