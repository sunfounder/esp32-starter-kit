.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_dht11:

5.13 Température - Humidité
=======================================

Le DHT11 est un capteur de température et d'humidité couramment utilisé pour les mesures environnementales. C'est un capteur numérique qui communique avec un microcontrôleur pour fournir des relevés de température et d'humidité.

Dans ce projet, nous allons lire les données du capteur DHT11 et afficher les valeurs de température et d'humidité qu'il détecte.

En lisant les données fournies par le capteur, nous pouvons obtenir les valeurs actuelles de température et d'humidité de l'environnement. Ces valeurs peuvent être utilisées pour la surveillance en temps réel des conditions environnementales, les observations météorologiques, le contrôle du climat intérieur, les rapports d'humidité, et plus encore.

**Composants Nécessaires**

Pour ce projet, nous avons besoin des composants suivants. 

Il est définitivement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION AUX COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

* **Broches Disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Broches Disponibles
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schéma**

.. image:: ../../img/circuit/circuit_5.13_dht11.png

**Câblage**

.. image:: ../../img/wiring/5.13_dht11_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.13_dht11.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.13_dht11``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    * La bibliothèque ``DHT sensor library`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

        .. image:: img/dht_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/95bef6dc-a4db-4315-9308-6663b77ddfa0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

N'oubliez pas de définir le taux de communication série à 115200 bauds.

Une fois le code téléversé avec succès, vous verrez le Moniteur Série imprimer continuellement la température et l'humidité, et à mesure que le programme se stabilise, ces deux valeurs deviendront de plus en plus précises.

**Comment ça marche ?**

#. Inclut la bibliothèque ``DHT.h``, qui fournit des fonctions pour interagir avec les capteurs DHT. Ensuite, configurez la broche et le type pour le capteur DHT.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 14  // Configurez la broche connectée à la broche de données du DHT11
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Initialise la communication série à un débit de 115200 bauds et initialise le capteur DHT.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. Dans la fonction ``loop()``, lisez les valeurs de température et d'humidité du capteur DHT11, et imprimez-les sur le moniteur série.

    .. code-block:: arduino

        void loop() {
            // Attendre quelques secondes entre les mesures.
            delay(2000);

            // Lire la température ou l'humidité prend environ 250 millisecondes !
            // Les lectures du capteur peuvent également être vieilles de 2 secondes (c'est un capteur très lent)
            float humidity = dht.readHumidity();
            // Lire la température en Celsius (par défaut)
            float temperture = dht.readTemperature();

            // Vérifiez si les lectures ont échoué et sortez tôt (pour réessayer).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * La fonction ``dht.readHumidity()`` est appelée pour lire la valeur de l'humidité du capteur DHT.
    * La fonction ``dht.readTemperature()`` est appelée pour lire la valeur de la température du capteur DHT.
    * La fonction ``isnan()`` est utilisée pour vérifier si les lectures sont valides. Si la valeur de l'humidité ou de la température est NaN (not a number), cela indique un échec de lecture du capteur, et un message d'erreur est imprimé.

**En savoir plus**

Vous pouvez également afficher la température et l'humidité sur le I2C LCD1602.

.. note::

    * Vous pouvez ouvrir le fichier ``5.10_thermistor_lcd.ino`` sous le chemin ``euler-kit/arduino/5.10_thermistor_lcd``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    * Les bibliothèques ``LiquidCrystal_I2C`` et ``DHT sensor library`` sont utilisées ici, vous pouvez les installer depuis le **Library Manager**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fb46ba7e-0a09-4805-87ab-f733e23eb920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
