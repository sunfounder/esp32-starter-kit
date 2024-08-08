.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_servo:

4.3 Servo Oscillant
=========================
Un servo est un dispositif de positionnement connu pour sa capacité à maintenir des angles spécifiques et à offrir une rotation précise. Cela le rend très prisé pour les systèmes de contrôle nécessitant des ajustements angulaires constants. Il n'est pas surprenant que les servos soient largement utilisés dans les jouets télécommandés haut de gamme, des modèles d'avions aux répliques de sous-marins et aux robots télécommandés sophistiqués.

Dans cette aventure intrigante, nous allons nous lancer le défi de manipuler le servo de manière unique - en le faisant osciller ! Ce projet offre une excellente occasion de plonger plus profondément dans la dynamique des servos, d'affiner vos compétences en systèmes de contrôle précis et de mieux comprendre leur fonctionnement.

Êtes-vous prêt à faire danser le servo au rythme de vos envies ? Embarquons ensemble dans cette aventure passionnante !

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


**Pins disponibles**

Voici une liste des pins disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Pins disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schéma**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**Câblage**

* Le fil orange est le signal et est connecté à IO25.
* Le fil rouge est le VCC et est connecté à 5V.
* Le fil marron est la masse (GND) et est connecté à GND.

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``4.3_servo.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\4.3_servo``. Ou copiez ce code dans **Arduino IDE**.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`
    * La bibliothèque ``ESP32Servo`` est utilisée ici, vous pouvez l'installer à partir du **Gestionnaire de Bibliothèques**.

        .. image:: img/servo_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/34c7969e-fee3-413c-9fe7-9d38ca6fb906/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois le code téléversé, vous pouvez voir le bras du servo osciller dans une plage de 0° à 180°.

**Comment ça marche ?**

#. Inclure la bibliothèque |link_esp32servo| : Cette ligne importe la bibliothèque ESP32Servo, nécessaire pour contrôler le servo-moteur.

    .. code-block:: arduino

        #include <ESP32Servo.h>

#. Définir le servo et la broche à laquelle il est connecté : Cette section déclare un objet Servo (``myServo``) et un entier constant (``servoPin``) pour représenter la broche à laquelle le servo-moteur est connecté (broche 25).

    .. code-block:: arduino

        // Définir le servo et la broche à laquelle il est connecté
        Servo myServo;
        const int servoPin = 25;

#. Définir les largeurs d'impulsion minimales et maximales pour le servo : Cette section définit les largeurs d'impulsion minimales et maximales pour le servo-moteur (0,5 ms et 2,5 ms, respectivement).

    .. code-block:: arduino

        // Définir les largeurs d'impulsion minimales et maximales pour le servo
        const int minPulseWidth = 500; // 0.5 ms
        const int maxPulseWidth = 2500; // 2.5 ms


#. La fonction ``setup`` initialise le servo-moteur en l'attachant à la broche spécifiée et en définissant sa plage de largeur d'impulsion. Elle définit également la fréquence PWM du servo à la norme de 50Hz.

    .. code-block:: arduino

        void setup() {
            // Attacher le servo à la broche spécifiée et définir sa plage de largeur d'impulsion
            myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

            // Définir la fréquence PWM du servo
            myServo.setPeriodHertz(50); // Servo standard 50Hz
        }
    
    * ``attach (int pin, int min, int max)``: Cette fonction attache le servo-moteur à la broche GPIO spécifiée et définit les largeurs d'impulsion minimales et maximales pour le servo.

        * ``pin``: Le numéro de la broche GPIO à laquelle le servo est connecté. 
        * Les ``min`` et ``max``: les largeurs d'impulsion minimales et maximales, respectivement, en microsecondes. Ces valeurs définissent la plage de mouvement du servo-moteur.

    * ``setPeriodHertz(int hertz)``: Cette fonction définit la fréquence PWM du servo-moteur en hertz.

        * ``hertz``: La fréquence PWM souhaitée en hertz. La fréquence PWM par défaut pour les servos est de 50Hz, ce qui convient à la plupart des applications. 


#. La fonction ``loop`` est la partie principale du code qui s'exécute en continu. Elle fait osciller le servo-moteur de 0 à 180 degrés, puis de nouveau à 0 degrés. Cela se fait en mappant l'angle à la largeur d'impulsion correspondante et en mettant à jour le servo-moteur avec la nouvelle valeur de largeur d'impulsion.

    .. code-block:: arduino

        void loop() {
            // Faire osciller le servo de 0 à 180 degrés
            for (int angle = 0; angle <= 180; angle++) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }
    
            // Faire osciller le servo de 180 à 0 degrés
            for (int angle = 180; angle >= 0; angle--) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }
        }

    * ``writeMicroseconds(int value)``: Cette fonction définit la largeur d'impulsion du servo-moteur en microsecondes. 
    
        * ``value``: La largeur d'impulsion souhaitée en microsecondes. 
        
        La fonction ``writeMicroseconds(int value)`` prend un entier en argument, représentant la largeur d'impulsion souhaitée en microsecondes. Cette valeur doit généralement se situer dans la plage spécifiée par les largeurs d'impulsion minimales et maximales (``minPulseWidth`` et ``maxPulseWidth``) définies plus tôt dans le code. La fonction définit ensuite la largeur d'impulsion pour le servo-moteur, le faisant ainsi se déplacer à la position correspondante.
