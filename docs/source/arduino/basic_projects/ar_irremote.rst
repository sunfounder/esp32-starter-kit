.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_receiver:

5.14 Récepteur IR
=========================
Un récepteur infrarouge est un composant qui reçoit des signaux infrarouges et peut détecter et sortir indépendamment des signaux compatibles avec le niveau TTL. Il est de taille similaire à un transistor en plastique standard et est couramment utilisé dans diverses applications telles que les télécommandes infrarouges et la transmission infrarouge.

Dans ce projet, nous allons utiliser un récepteur infrarouge pour détecter les signaux d'une télécommande. Lorsqu'un bouton de la télécommande est pressé et que le récepteur infrarouge reçoit le signal correspondant, il peut décoder le signal pour déterminer quel bouton a été pressé. En décodant le signal reçu, nous pouvons identifier la touche ou la commande spécifique associée.

Le récepteur infrarouge nous permet d'incorporer des fonctionnalités de télécommande dans notre projet, nous permettant ainsi d'interagir avec et de contrôler des dispositifs à l'aide de signaux infrarouges.

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants.

Il est très pratique d'acheter un kit complet, voici le lien :

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
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|


**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20

    *   - Broches disponibles
        - IO13, IO12, IO14, IO27, IO26, IO25, IO15, IO0, IO5, IO18, IO19, IO21, IO22, IO23

**Schéma**

.. image:: ../../img/circuit/circuit_5.14_receiver.png

Lorsque vous appuyez sur un bouton de la télécommande, le récepteur infrarouge détecte le signal, et vous pouvez utiliser une bibliothèque infrarouge pour le décoder. Ce processus de décodage vous permet d'obtenir la valeur de la touche associée à l'appui sur le bouton.

**Câblage**

.. image:: ../../img/wiring/5.14_ir_receiver_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.14_ir_receiver.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.14_ir_receiver``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    * La bibliothèque ``IRremoteESP8266`` est utilisée ici, vous pouvez l'installer à partir du **Gestionnaire de Bibliothèques**.

        .. image:: img/receiver_lib.png


.. warning::

    Si vous utilisez une carte de développement ESP32 version 3.0.0 ou supérieure, vous pouvez rencontrer des erreurs lors du processus de compilation.
    Ce problème est généralement dû au fait que les versions plus récentes de la carte ne prennent plus en charge la bibliothèque ``IRremoteESP8266``.
    Pour exécuter correctement cet exemple, il est recommandé de rétrograder la version du firmware de votre carte ESP32 à 2.0.17. 
    Après avoir terminé cet exemple, mettez à jour à la dernière version.

    .. image:: ../../faq/img/version_2.0.17.png


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/463c8894-00bd-4035-a81c-cad99a7f3731/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

N'oubliez pas de régler le taux de communication série à 115200 bauds.

Après le téléchargement réussi du code, appuyez sur les différentes touches de la télécommande et vous verrez les noms de ces touches apparaître dans le moniteur série.

.. note::
    * La bibliothèque ``IRremoteESP8266`` comprend des implémentations pour de nombreux protocoles et appareils infrarouges différents, donc la taille de la bibliothèque est relativement grande. Lorsque le compilateur doit traiter plus de code, le temps de compilation augmentera également en conséquence. Veuillez être patient et attendre la fin de la compilation.
    * La nouvelle télécommande comporte une languette en plastique à l'extrémité pour isoler la batterie à l'intérieur. Pour alimenter la télécommande lors de son utilisation, retirez simplement cette pièce en plastique.


**Comment ça marche ?**

#. Ce code utilise la bibliothèque ``IRremoteESP8266`` pour recevoir des signaux infrarouges (IR) à l'aide d'un module récepteur IR.

    .. code-block:: arduino

        #include <IRremoteESP8266.h>
        #include <IRrecv.h>

        // Définir la broche du récepteur IR
        const uint16_t IR_RECEIVE_PIN = 14;

        // Créer un objet IRrecv
        IRrecv irrecv(IR_RECEIVE_PIN);

        // Créer un objet decode_results
        decode_results results;
    
#. Dans la fonction ``setup()``, la communication série est démarrée à un débit de 115200 bauds, et le récepteur IR est activé à l'aide de ``irrecv.enableIRIn()``.

    .. code-block:: arduino

        void setup() {
            // Démarrer la communication série
            Serial.begin(115200);
            
            // Démarrer le récepteur IR
            irrecv.enableIRIn();
        }

#. Lorsque vous appuyez sur une touche de la télécommande, le moniteur série affichera le nom de la touche si elle est reçue par le récepteur IR.

    .. code-block:: arduino

        void loop() {
            // Si un signal IR est reçu
            if (irrecv.decode(&results)) {
                String key = decodeKeyValue(results.value);
                if (key != "ERROR") {
                    // Afficher la valeur du signal dans le moniteur série
                    Serial.println(key);
                }
                irrecv.resume(); // Continuer à recevoir le prochain signal
            }
        }

    * Tout d'abord, vérifiez si un signal IR est reçu à l'aide de la fonction ``irrecv.decode()``.
    * Si un signal est reçu, appelez ensuite la fonction ``decodeKeyValue()`` pour décoder la valeur du signal.
    * Si le signal est décodé avec succès, la valeur décodée est affichée dans le moniteur série à l'aide de ``Serial.println()``.
    * Enfin, ``irrecv.resume()`` est appelé pour continuer à recevoir le prochain signal.

#. La fonction ``decodeKeyValue()`` prend la valeur décodée du signal IR en argument et renvoie une chaîne représentant la touche pressée sur la télécommande. 

    .. code-block:: arduino

        String decodeKeyValue(long result)
        {
            switch(result){
                case 0xFF6897:
                return "0";
                case 0xFF30CF:
                return "1"; 
                case 0xFF18E7:
                return "2"; 
                case 0xFF7A85:
                ...

    * La fonction utilise une instruction switch pour faire correspondre la valeur décodée à la touche correspondante et renvoie la représentation en chaîne de la touche.
    * Si la valeur décodée ne correspond à aucune touche connue, la fonction renvoie la chaîne "ERROR".
