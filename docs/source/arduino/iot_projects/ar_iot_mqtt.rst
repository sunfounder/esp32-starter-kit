.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_iot_mqtt:

8.4 Communication IoT avec MQTT
=======================================

Ce projet se concentre sur l'utilisation de MQTT, un protocole de communication populaire dans le domaine de l'Internet des Objets (IoT). MQTT permet aux appareils IoT d'échanger des données en utilisant un modèle de publication/abonnement, où les appareils communiquent via des sujets.

Dans ce projet, nous explorons la mise en œuvre de MQTT en construisant un circuit incluant une LED, un bouton et un thermistor. Le microcontrôleur ESP32-WROOM-32E est utilisé pour établir une connexion WiFi et communiquer avec un courtier MQTT. Le code permet au microcontrôleur de s'abonner à des sujets spécifiques, de recevoir des messages et de contrôler la LED en fonction des informations reçues. De plus, le projet montre comment publier des données de température du thermistor sur un sujet désigné lorsque le bouton est pressé.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Téléchargement du code**

#. Montez le circuit.

    .. note:: 
        Lors de l'établissement d'une connexion WiFi, seuls les broches 36, 39, 34, 35, 32, 33 peuvent être utilisées pour la lecture analogique. Assurez-vous que le thermistor est connecté à ces broches désignées.

    .. image:: ../../img/wiring/iot_4_matt_bb.png

#. Ensuite, connectez l'ESP32-WROOM-32E à l'ordinateur à l'aide du câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Ouvrez le code.

    * Ouvrez le fichier ``iot_4_mqtt.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\iot_4_mqtt``, ou copiez le code dans l'Arduino IDE.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    * La bibliothèque ``PubSubClient`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

        .. image:: img/mqtt_lib.png
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/e45a4bd6-9b35-47f0-af5e-92d802004087/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Trouvez les lignes suivantes et modifiez-les avec votre ``SSID`` et ``PASSWORD``.

    .. code-block::  Arduino

        // Remplacez les variables suivantes par votre combinaison SSID/Mot de passe
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Trouvez la ligne suivante et modifiez votre ``unique_identifier``. Assurez-vous que votre ``unique_identifier`` est vraiment unique car tout identifiant identique tentant de se connecter au même courtier MQTT peut entraîner un échec de connexion.

    .. code-block::  Arduino

        // Ajoutez l'adresse de votre courtier MQTT, exemple :
        const char* mqtt_server = "broker.hivemq.com";
        const char* unique_identifier = "sunfounder-client-sdgvsda";  

**Abonnement au sujet**

#. Pour éviter les interférences des messages envoyés par d'autres participants, vous pouvez le définir comme une chaîne obscure ou peu commune. Remplacez simplement le sujet actuel ``SF/LED`` par le nom de sujet souhaité.

    .. note:: 
        Vous avez la liberté de définir le sujet comme n'importe quel caractère souhaité. Tout appareil MQTT qui s'est abonné au même sujet pourra recevoir le même message. Vous pouvez également vous abonner simultanément à plusieurs sujets.

    .. code-block::  Arduino
        :emphasize-lines: 9

        void reconnect() {
            // Boucle jusqu'à ce que nous soyons reconnectés
            while (!client.connected()) {
                Serial.print("Attempting MQTT connection...");
                // Tentative de connexion
                if (client.connect(unique_identifier)) {
                    Serial.println("connected");
                    // S'abonner
                    client.subscribe("SF/LED");
                } else {
                    Serial.print("failed, rc=");
                    Serial.print(client.state());
                    Serial.println(" try again in 5 seconds");
                    // Attendre 5 secondes avant de réessayer
                    delay(5000);
                }
            }
        }

#. Modifiez la fonctionnalité pour répondre au sujet abonné. Dans le code fourni, si un message est reçu sur le sujet ``SF/LED``, il vérifie si le message est ``on`` ou ``off``. En fonction du message reçu, il modifie l'état de sortie pour contrôler l'allumage ou l'extinction de la LED.

    .. note::
       Vous pouvez le modifier pour n'importe quel sujet auquel vous êtes abonné, et vous pouvez écrire plusieurs instructions if pour répondre à plusieurs sujets.

    .. code-block::  arduino
        :emphasize-lines: 15

        void callback(char* topic, byte* message, unsigned int length) {
            Serial.print("Message arrived on topic: ");
            Serial.print(topic);
            Serial.print(". Message: ");
            String messageTemp;

            for (int i = 0; i < length; i++) {
                Serial.print((char)message[i]);
                messageTemp += (char)message[i];
            }
            Serial.println();

            // Si un message est reçu sur le sujet "SF/LED", vérifiez si le message est "on" ou "off".
            // Change l'état de sortie en fonction du message
            if (String(topic) == "SF/LED") {
                Serial.print("Changing state to ");
                if (messageTemp == "on") {
                    Serial.println("on");
                    digitalWrite(ledPin, HIGH);
                } else if (messageTemp == "off") {
                    Serial.println("off");
                    digitalWrite(ledPin, LOW);
                }
            }
        }

#. Après avoir sélectionné la carte correcte (ESP32 Dev Module) et le port, cliquez sur le bouton **Upload**.

#. Ouvrez le moniteur série et si les informations suivantes sont imprimées, cela indique une connexion réussie au serveur MQTT.

    .. code-block:: 

        WiFi connecté
        Adresse IP : 
        192.168.18.77
        Tentative de connexion MQTT...connecté

**Publication de messages via HiveMQ**

HiveMQ est une plateforme de messagerie qui fonctionne comme un courtier MQTT, facilitant le transfert de données rapide, efficace et fiable vers les appareils IoT.

Notre code utilise spécifiquement le courtier MQTT fourni par HiveMQ. Nous avons inclus l'adresse du courtier MQTT HiveMQ dans le code comme suit :

    .. code-block::  Arduino

        // Ajoutez l'adresse de votre courtier MQTT, exemple :
        const char* mqtt_server = "broker.hivemq.com";

#. À présent, ouvrez le |link_hivemq| dans votre navigateur web.

#. Connectez le client au proxy public par défaut.

    .. image:: img/sp230512_092258.png

#. Publiez un message dans le sujet auquel vous vous êtes abonné. Dans ce projet, vous pouvez publier ``on`` ou ``off`` pour contrôler votre LED.

    .. image:: img/sp230512_140234.png

**Publication de messages vers MQTT**

Nous pouvons également utiliser le code pour publier des informations sur le sujet. Dans cette démonstration, nous avons codé une fonctionnalité qui envoie la température mesurée par le thermistor sur le sujet lorsque vous appuyez sur le bouton.

#. Cliquez sur **Ajouter une nouvelle abonnement au sujet**.

    .. image:: img/sp230512_092341.png

#. Remplissez les sujets que vous souhaitez suivre et cliquez sur **S'abonner**. Dans le code, nous envoyons des informations de température sur le sujet ``SF/TEMP``.

    .. code-block::  Arduino
        :emphasize-lines: 14

        void loop() {
            if (!client.connected()) {
                reconnect();
            }
            client.loop();

            // si le bouton est pressé, publier la température sur le sujet "SF/TEMP"
            if (digitalRead(buttonPin)) {
                    long now = millis();
                    if (now - lastMsg > 5000) {
                    lastMsg = now;
                    char tempString[8];
                    dtostrf(thermistor(), 1, 2, tempString);
                    client.publish("SF/TEMP", tempString);
                }
            }
        }

#. Ainsi, nous pouvons surveiller ce sujet sur HiveMQ, nous permettant de voir les informations que vous avez publiées.

    .. image:: img/sp230512_154342.png

