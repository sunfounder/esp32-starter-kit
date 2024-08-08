.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Explorez plus en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et giveaways** : Participez à des giveaways et à des promotions de fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_bluetooth:

7.1 Bluetooth
===================

Ce projet fournit un guide pour développer une application simple de communication série Bluetooth Low Energy (BLE) 
en utilisant le microcontrôleur ESP32. L'ESP32 est un microcontrôleur puissant qui intègre une connectivité Wi-Fi et Bluetooth, 
ce qui en fait un candidat idéal pour développer des applications sans fil. Le BLE est 
un protocole de communication sans fil à faible consommation conçu pour les communications à courte portée. 
Ce document couvrira les étapes de configuration de l'ESP32 pour agir en tant que serveur BLE et communiquer avec un client BLE via une connexion série.


**À propos de la fonction Bluetooth**

L'ESP32 WROOM 32E est un module qui intègre la connectivité Wi-Fi et Bluetooth dans une seule puce. 
Il prend en charge les protocoles Bluetooth Low Energy (BLE) et Bluetooth classique.

Le module peut être utilisé comme client ou serveur Bluetooth. En tant que client Bluetooth, le module peut se connecter à 
d'autres appareils Bluetooth et échanger des données avec eux. En tant que serveur Bluetooth, le module peut fournir 
des services à d'autres appareils Bluetooth.

L'ESP32 WROOM 32E prend en charge divers profils Bluetooth, y compris le profil d'accès générique (GAP), le profil d'attribut générique (GATT), 
et le profil de port série (SPP). Le profil SPP permet au module d'émuler un port série via Bluetooth, 
permettant une communication série avec d'autres appareils Bluetooth.

Pour utiliser la fonction Bluetooth de l'ESP32 WROOM 32E, vous devez le programmer en utilisant un kit de développement logiciel approprié (SDK) ou en utilisant l'IDE Arduino avec la bibliothèque ESP32 BLE. 
La bibliothèque ESP32 BLE fournit une interface de haut niveau pour travailler avec le BLE. Elle comprend des exemples qui démontrent 
comment utiliser le module en tant que client et serveur BLE.

Dans l'ensemble, la fonction Bluetooth de l'ESP32 WROOM 32E offre un moyen pratique et à faible consommation pour permettre la communication sans fil dans vos projets.

**Étapes de fonctionnement**

Voici les instructions étape par étape pour configurer la communication Bluetooth entre votre ESP32 et un appareil mobile utilisant l'application LightBlue :

#. Téléchargez l'application LightBlue depuis l'**App Store** (pour iOS) ou **Google Play** (pour Android).

    .. image:: img/bluetooth_lightblue.png

#. Ouvrez le fichier ``7.1_bluetooth.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\7.1_bluetooth``, ou copiez le code dans l'IDE Arduino.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/388f6d9d-65bf-4eaa-b29a-7cebf0b92f74/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Pour éviter les conflits d'UUID, il est recommandé de générer trois nouveaux UUID aléatoires en utilisant le |link_uuid|, et de les remplir dans les lignes de code suivantes.

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png


#. Sélectionnez la carte et le port corrects, puis cliquez sur le bouton **Upload**.

    .. image:: img/bluetooth_upload.png

#. Après avoir téléchargé le code avec succès, activez le **Bluetooth** sur votre appareil mobile et ouvrez l'application **LightBlue**.

    .. image:: img/bluetooth_open.png

#. Sur la page **Scan**, trouvez **ESP32-Bluetooth** et cliquez sur **CONNECT**. Si vous ne le voyez pas, essayez de rafraîchir la page plusieurs fois. Lorsque **"Connected to device!"** apparaît, la connexion Bluetooth est réussie. Faites défiler vers le bas pour voir les trois UUID définis dans le code.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Cliquez sur l'UUID **Receive**. Sélectionnez le format de données approprié dans la boîte à droite de **Data Format**, comme "HEX" pour hexadécimal, "UTF-8 String" pour caractère, ou "Binary" pour binaire, etc. Puis cliquez sur **SUBSCRIBE**.

    .. image:: img/bluetooth_read.png
        :width: 300

#. Retournez à l'IDE Arduino, ouvrez le Moniteur Série, réglez le débit en bauds à 115200, puis tapez "welcome" et appuyez sur Entrée.

    .. image:: img/bluetooth_serial.png

#. Vous devriez maintenant voir le message "welcome" dans l'application LightBlue.

    .. image:: img/bluetooth_welcome.png
        :width: 400

#. Pour envoyer des informations de l'appareil mobile au Moniteur Série, cliquez sur l'UUID Send, réglez le format des données sur "UTF-8 String", et écrivez un message.

    .. image:: img/bluetooth_send.png


#. Vous devriez voir le message dans le Moniteur Série.

    .. image:: img/bluetooth_receive.png

**Comment ça marche ?**

Ce code Arduino est écrit pour le microcontrôleur ESP32 et le configure pour communiquer avec un appareil Bluetooth Low Energy (BLE).

Voici un résumé du code :

* **Inclure les bibliothèques nécessaires** : Le code commence par inclure les bibliothèques nécessaires pour travailler avec le Bluetooth Low Energy (BLE) sur l'ESP32.

    .. code-block:: arduino

        #include "BLEDevice.h"
        #include "BLEServer.h"
        #include "BLEUtils.h"
        #include "BLE2902.h"

* **Variables globales** : Le code définit un ensemble de variables globales, y compris le nom du périphérique Bluetooth (``bleName``), des variables pour suivre le texte reçu et l'heure du dernier message, les UUID pour le service et les caractéristiques, et un objet ``BLECharacteristic`` (``pCharacteristic``).

    .. code-block:: arduino

        // Définir le nom du périphérique Bluetooth
        const char *bleName = "ESP32_Bluetooth";

        // Définir le texte reçu et l'heure du dernier message
        String receivedText = "";
        unsigned long lastMessageTime = 0;

        // Définir les UUID du service et des caractéristiques
        #define SERVICE_UUID           "your_service_uuid_here"
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

        // Définir la caractéristique Bluetooth
        BLECharacteristic *pCharacteristic;

* **Configuration** : Dans la fonction ``setup()``, le port série est initialisé avec un débit en bauds de 115200 et la fonction ``setupBLE()`` est appelée pour configurer le Bluetooth BLE.

    .. code-block:: arduino
    
        void setup() {
            Serial.begin(115200);  // Initialiser le port série
            setupBLE();            // Initialiser le Bluetooth BLE
        }

* **Boucle principale** : Dans la fonction ``loop()``, si une chaîne a été reçue via BLE (c'est-à-dire que ``receivedText`` n'est pas vide) et qu'au moins 1 seconde s'est écoulée depuis le dernier message, le code imprime la chaîne reçue sur le moniteur série, définit la valeur de la caractéristique sur la chaîne reçue, envoie une notification, puis efface la chaîne reçue. Si des données sont disponibles sur le port série, il lit la chaîne jusqu'à ce qu'un caractère de nouvelle ligne soit rencontré, définit la valeur de la caractéristique sur cette chaîne et envoie une notification.

    .. code-block:: arduino

        void loop() {
            // Lorsque le texte reçu n'est pas vide et que le temps écoulé depuis le dernier message est supérieur à 1 seconde
            // Envoyer une notification et imprimer le texte reçu
            if (receivedText.length() > 0 && millis() - lastMessageTime > 1000) {
                Serial.print("Received message: ");
                Serial.println(receivedText);
                pCharacteristic->setValue(receivedText.c_str());
                pCharacteristic->notify();
                receivedText = "";
            }

            // Lire les données du port série et les envoyer à la caractéristique BLE
            if (Serial.available() > 0) {
                String str = Serial.readStringUntil('\n');
                const char *newValue = str.c_str();
                pCharacteristic->setValue(newValue);
                pCharacteristic->notify();
            }
        }

* **Callbacks** : Deux classes de rappel (``MyServerCallbacks`` et ``MyCharacteristicCallbacks``) sont définies pour gérer les événements liés à la communication Bluetooth. ``MyServerCallbacks`` est utilisée pour gérer les événements liés à l'état de connexion (connecté ou déconnecté) du serveur BLE. ``MyCharacteristicCallbacks`` est utilisée pour gérer les événements d'écriture sur la caractéristique BLE, c'est-à-dire lorsque qu'un appareil connecté envoie une chaîne à l'ESP32 via BLE, elle est capturée et stockée dans ``receivedText``, et l'heure actuelle est enregistrée dans ``lastMessageTime``.

    .. code-block:: arduino

        // Définir les callbacks du serveur BLE
        class MyServerCallbacks : public BLEServerCallbacks {
            // Imprimer le message de connexion lorsqu'un client est connecté
            void onConnect(BLEServer *pServer) {
                Serial.println("Connected");
            }
            // Imprimer le message de déconnexion lorsqu'un client est déconnecté
            void onDisconnect(BLEServer *pServer) {
                Serial.println("Disconnected");
            }
        };

        // Définir les callbacks de la caractéristique BLE
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                // Lors de la réception de données, obtenir les données et les enregistrer dans receivedText, et enregistrer l'heure
                std::string value = std::string(pCharacteristic->getValue().c_str());
                receivedText = String(value.c_str());
                lastMessageTime = millis();
                Serial.print("Received: ");
                Serial.println(receivedText);
            }
        };

* **Configuration du BLE** : Dans la fonction ``setupBLE()``, le périphérique et le serveur BLE sont initialisés, les callbacks du serveur sont définis, le service BLE est créé en utilisant l'UUID défini, les caractéristiques pour l'envoi de notifications et la réception de données sont créées et ajoutées au service, et les callbacks des caractéristiques sont définis. Enfin, le service est démarré et le serveur commence à faire de la publicité.

    .. code-block:: arduino

        // Initialiser le Bluetooth BLE
        void setupBLE() {
            BLEDevice::init(bleName);                        // Initialiser le périphérique BLE
            BLEServer *pServer = BLEDevice::createServer();  // Créer le serveur BLE
            // Imprimer le message d'erreur si la création du serveur BLE échoue
            if (pServer == nullptr) {
                Serial.println("Error creating BLE server");
                return;
            }
            pServer->setCallbacks(new MyServerCallbacks());  // Définir les callbacks du serveur BLE

            // Créer le service BLE
            BLEService *pService = pServer->createService(SERVICE_UUID);
            // Imprimer le message d'erreur si la création du service BLE échoue
            if (pService == nullptr) {
                Serial.println("Error creating BLE service");
                return;
            }
            // Créer la caractéristique BLE pour l'envoi de notifications
            pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
            pCharacteristic->addDescriptor(new BLE2902());  // Ajouter le descripteur
            // Créer la caractéristique BLE pour la réception de données
            BLECharacteristic *pCharacteristicRX = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
            pCharacteristicRX->setCallbacks(new MyCharacteristicCallbacks());  // Définir les callbacks de la caractéristique BLE
            pService->start();                                                 // Démarrer le service BLE
            pServer->getAdvertising()->start();                                // Commencer à faire de la publicité
            Serial.println("Waiting for a client connection...");              // Attendre une connexion client
        }


Notez que ce code permet une communication bidirectionnelle - il peut envoyer et recevoir des données via BLE. 
Cependant, pour interagir avec des matériels spécifiques, comme allumer/éteindre une LED, un code supplémentaire doit être ajouté pour traiter 
les chaînes reçues et agir en conséquence.
