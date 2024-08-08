.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_intrusion_alert_system:

8.9 Système de notification d'intrusion basé sur Blynk
===============================================================

Ce projet démontre un simple système de détection d'intrusion à domicile utilisant un capteur de mouvement PIR (HC-SR501).
Lorsque le système est réglé en mode "Absence" via l'application Blynk, le capteur PIR surveille les mouvements.
Tout mouvement détecté déclenche une notification sur l'application Blynk, alertant l'utilisateur d'une intrusion potentielle.

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|


1. Assemblage du circuit
----------------------------

.. image:: ../../img/wiring/iot_9_blynk_bb.png
    :width: 60%
    :align: center

2. Configuration de Blynk
-------------------------------

**2.1 Initialisation de Blynk**

1. Allez sur la page |link_blynk| et sélectionnez **Sign Up FREE** ou **Enterprise Solution**.

    .. image:: img/09_blynk_access.png
        :width: 600
        :align: center

2. Entrez votre email pour commencer le processus d'inscription.

    .. image:: img/09_blynk_sign_in.png
        :align: center

3. Vérifiez votre email pour une invitation et cliquez sur le lien **Create Password** dans l'email pour définir votre mot de passe.

    .. image:: img/09_blynk_password.png
        :align: center

4. Après confirmation, un **Blynk Tour** commencera où vous pourrez rapidement apprendre certaines des fonctionnalités clés de Blynk.

    .. image:: img/09_blynk_tour.png
        :width: 600
        :align: center

5. Après avoir complété le Blynk Tour, une fenêtre apparaîtra où vous pourrez choisir d'explorer les Blueprints ou de cliquer sur Quick Start pour connecter rapidement votre appareil. Cependant, dans ce cas, nous sélectionnerons "Have a look around first".

    .. image:: img/09_blynk_skip.png
        :align: center

**2.2 Création d'un template**

1. Commencez par créer un template dans Blynk. Suivez les étapes pour configurer le template **Intrusion Alert System**.

    .. image:: img/09_create_template_1_shadow.png
        :width: 600
        :align: center

2. Nommez votre template, choisissez **ESP32** comme matériel, sélectionnez **WiFi** comme **Type de connexion**, puis cliquez sur **Done**.

   .. image:: img/09_create_template_2_shadow.png
        :width: 600
        :align: center

3. Entrez dans le template, où vous serez invité aux prochaines étapes. Cliquez sur **Configure template** pour télécharger une image de couverture, améliorer la description, et plus encore. Suivez les trois étapes restantes pour compléter la configuration.

    .. image:: img/09_blynk_temp_steps.png
        :width: 600
        :align: center

**2.3 Configuration des flux de données (Datastreams)**

1. Ouvrez le nouveau template créé et allez à la page de configuration des flux de données.

   .. image:: img/09_blynk_new_datastream.png
        :width: 600
        :align: center

2. Cliquez sur **New Datastream**, et dans la popup, sélectionnez **Virtual Pin**.

   .. image:: img/09_blynk_datastream_virtual.png
        :width: 600
        :align: center

3. Nommez le **Virtual Pin V0** comme **AwayMode** et réglez le **TYPE DE DONNÉES** sur **Integer**, avec des valeurs **MIN** et **MAX** de **0** et **1**.

   .. image:: img/09_create_template_shadow.png
        :width: 600
        :align: center

4. De la même manière, créez un autre **Virtual Pin** nommé **Current Status** et réglez le **TYPE DE DONNÉES** sur **String**.

   .. image:: img/09_datastream_1_shadow.png
        :width: 600
        :align: center

**2.4 Configuration du tableau de bord web**

1. Faites glisser et déposez le **widget Switch** et le **widget Label** sur le **tableau de bord web**.

   .. image:: img/09_web_dashboard_1_shadow.png
        :width: 600
        :align: center

2. Survolez un widget pour voir trois icônes. Utilisez l'icône **Paramètres** pour configurer les propriétés du widget.

   .. image:: img/09_blynk_dashboard_set.png
        :width: 600
        :align: center

3. Configurez le **widget Switch** pour le lier au flux de données **AwayMode(V0)**, en réglant les **ONLABEL** et **OFFLABEL** pour afficher **"away home"** et **"at home"**, respectivement.

   .. image:: img/09_web_dashboard_2_shadow.png
        :width: 600
        :align: center

4. Dans les paramètres du **widget Label**, liez-le au flux de données **Current Status(V1)**.

   .. image:: img/09_web_dashboard_3_shadow.png
        :width: 600
        :align: center

**2.5 Configuration d'un événement**

1. Cliquez sur **Events & Notifications** puis sur **Create Event**.

   .. image:: img/09_blynk_event_add.png
        :width: 600
        :align: center
    
2. Nommez l'événement et spécifiez son code. Choisissez **Warning** pour le **TYPE** et fournissez une brève description pour l'email de notification. Ajustez la fréquence des notifications selon vos préférences.

   .. note::
   
      Assurez-vous que le **CODE DE L'ÉVÉNEMENT** est défini comme ``intrusion_detected``. Tout changement ici nécessite des ajustements correspondants dans le code.

   .. image:: img/09_event_1_shadow.png
        :width: 600
        :align: center

3. Allez dans la section **Notifications** pour activer les notifications et configurer les paramètres d'email.

   .. image:: img/09_event_2_shadow.png
        :width: 600
        :align: center

4. Dans **Settings**, définissez la fréquence de déclenchement des notifications et définissez les intervalles selon vos préférences. N'oubliez pas de cliquer sur **Create** pour enregistrer vos paramètres.

   .. image:: img/09_event_3_shadow.png
        :width: 600
        :align: center

**2.6 Enregistrement du template**

1. N'oubliez pas d'enregistrer vos modifications sur le template.

   .. image:: img/09_save_template_shadow.png
        :width: 600
        :align: center

**2.7 Création d'un appareil**

1. Il est temps de créer un nouvel appareil à partir du template.

   .. image:: img/09_blynk_device_new.png
        :width: 600
        :align: center

2. Sélectionnez **From template** pour commencer.

   .. image:: img/09_blynk_device_template.png
        :width: 600
        :align: center

3. Choisissez le template **Intrusion Alert System** et cliquez sur **Create**.

   .. image:: img/09_blynk_device_template2.png
        :width: 600
        :align: center

4. Notez l'**Template ID**, le **Device Name**, et l'**AuthToken** pour l'intégration avec votre ESP32.

   .. image:: img/09_blynk_device_code.png
        :width: 600
        :align: center

3. Exécution du code
-----------------------------

#. Avant d'exécuter le code, assurez-vous d'installer la bibliothèque ``Blynk`` depuis le **Library Manager** sur l'Arduino IDE.

    .. image:: img/09_blynk_add_library.png
        :width: 700
        :align: center

#. Ouvrez le fichier ``iot_9_intrusion_alert_system.ino``, situé dans le répertoire ``esp32-starter-kit-main\c\codes\iot_9_intrusion_alert_system``. Vous pouvez également copier son contenu dans l'Arduino IDE.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/16bca228-64d7-4519-ac3b-833afecfcc65/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Remplacez les espaces réservés pour ``BLYNK_TEMPLATE_ID``, ``BLYNK_TEMPLATE_NAME``, et ``BLYNK_AUTH_TOKEN`` par vos propres identifiants uniques.

    .. code-block:: arduino
    
        #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

#. Vous devez également entrer le ``ssid`` et le ``password`` de votre réseau WiFi.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. Choisissez la carte correcte (**ESP32 Dev Module**) et le port, puis cliquez sur le bouton **Upload**.

#. Ouvrez le moniteur série (réglez le débit en bauds à 115200) et attendez un message de connexion réussie.

    .. image:: img/09_blynk_upload_code.png
        :align: center

#. Après une connexion réussie, l'activation de l'interrupteur dans Blynk démarre la surveillance du module PIR. Lorsque le mouvement est détecté (état de 1), il indiquera "Somebody here!" et enverra une alerte à votre email.

    .. image:: img/09_blynk_code_alarm.png
        :width: 700
        :align: center

4. Explication du code
-----------------------------

#. **Configuration & Bibliothèques**

   Ici, vous configurez les constantes et les identifiants de Blynk. Vous incluez également les bibliothèques nécessaires pour l'ESP32 et Blynk.

    .. code-block:: arduino

        /* Commentez ceci pour désactiver les impressions et économiser de l'espace */
        #define BLYNK_PRINT Serial

        #define BLYNK_TEMPLATE_ID "xxxxxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"

        #include <WiFi.h>
        #include <WiFiClient.h>
        #include <BlynkSimpleEsp32.h>

#. **Configuration WiFi**

   Entrez vos identifiants WiFi.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. **Configuration du capteur PIR**

   Définissez la broche où le capteur PIR est connecté et initialisez les variables d'état.

   .. code-block:: arduino

      const int sensorPin = 14;
      int state = 0;
      int awayHomeMode = 0;
      BlynkTimer timer;

#. **Fonction setup()**

   Cette fonction initialise le capteur PIR en tant qu'entrée, configure la communication série, se connecte au WiFi et configure Blynk.

   - Nous utilisons ``timer.setInterval(1000L, myTimerEvent)`` pour définir l'intervalle du timer dans ``setup()``, ici nous réglons pour exécuter la fonction ``myTimerEvent()`` toutes les **1000ms**. Vous pouvez modifier le premier paramètre de ``timer.setInterval(1000L, myTimerEvent)`` pour changer l'intervalle entre les exécutions de ``myTimerEvent``.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void setup() {

            pinMode(sensorPin, INPUT);  // Définir la broche du capteur PIR comme entrée
            Serial.begin(115200);           // Démarrer la communication série à 115200 bauds pour le débogage
            
            // Configurer Blynk et se connecter au WiFi
            Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
            
            timer.setInterval(1000L, myTimerEvent);  // Configurer une fonction à appeler toutes les secondes
        }

#. **Fonction loop()**

   La fonction loop exécute continuellement les fonctions Blynk et Blynk timer.

   .. code-block:: arduino

        void loop() {
           Blynk.run();
           timer.run();
        }

#. **Interaction avec l'application Blynk**

   Ces fonctions sont appelées lorsque l'appareil se connecte à Blynk et lorsqu'il y a un changement d'état de la broche virtuelle V0 sur l'application Blynk.

   - Chaque fois que l'appareil se connecte au serveur Blynk, ou se reconnecte en raison de mauvaises conditions réseau, la fonction ``BLYNK_CONNECTED()`` est appelée. La commande ``Blynk.syncVirtual()`` demande une valeur de broche virtuelle unique. La broche virtuelle spécifiée exécutera l'appel ``BLYNK_WRITE()``.

   - Chaque fois que la valeur d'une broche virtuelle sur le serveur Blynk change, elle déclenchera ``BLYNK_WRITE()``.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino
      
        // Cette fonction est appelée chaque fois que l'appareil est connecté à Blynk.Cloud
        BLYNK_CONNECTED() {
            Blynk.syncVirtual(V0);
        }
      
        // Cette fonction est appelée chaque fois que l'état de la broche virtuelle 0 change
        BLYNK_WRITE(V0) {
            awayHomeMode = param.asInt();
            // logique supplémentaire
        }

#. **Gestion des données**

   Chaque seconde, la fonction ``myTimerEvent()`` appelle ``sendData()``. Si le mode absence est activé sur Blynk, il vérifie le capteur PIR et envoie une notification à Blynk si un mouvement est détecté.

   - Nous utilisons ``Blynk.virtualWrite(V1, "Somebody in your house! Please check!");`` pour changer le texte d'une étiquette.

   - Utilisez ``Blynk.logEvent("intrusion_detected");`` pour enregistrer l'événement sur Blynk.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void myTimerEvent() {
           sendData();
        }

        void sendData() {
           if (awayHomeMode == 1) {
              state = digitalRead(sensorPin);  // Lire l'état du capteur PIR

              Serial.print("state:");
              Serial.println(state);

              // Si le capteur détecte un mouvement, envoyer une alerte à l'application Blynk
              if (state == HIGH) {
                Serial.println("Somebody here!");
                Blynk.virtualWrite(V1, "Somebody in your house! Please check!");
                Blynk.logEvent("intrusion_detected");
              }
           }
        }

**Références**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|
- |link_blynk_syncing| 
- |link_blynk_write|
