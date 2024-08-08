.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_pa_buz:

3.2 Tonalité Personnalisée
==========================================

Nous avons utilisé un buzzer actif dans le projet précédent, cette fois nous utiliserons un buzzer passif.

Comme le buzzer actif, le buzzer passif utilise également le phénomène d'induction électromagnétique pour fonctionner. La différence est qu'un buzzer passif n'a pas de source d'oscillation, il ne bipera donc pas si des signaux continus sont utilisés. Mais cela permet au buzzer passif d'ajuster sa propre fréquence d'oscillation et peut émettre différentes notes telles que "do, ré, mi, fa, sol, la, si".

Faisons jouer une mélodie au buzzer passif !

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Broches disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schéma**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

Lorsque la sortie IO14 est haute, après la résistance de limitation de courant de 1K (pour protéger le transistor), le S8050 (transistor NPN) sera conducteur, de sorte que le buzzer sonnera.

Le rôle du S8050 (transistor NPN) est d'amplifier le courant et de rendre le buzzer plus fort. En fait, vous pouvez également connecter directement le buzzer à IO14, mais vous constaterez que le son du buzzer est plus faible.

**Câblage**

Deux types de buzzers sont inclus dans le kit. 
Nous devons utiliser le buzzer passif. Tournez-les, le PCB exposé est celui que nous voulons.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

Le buzzer doit utiliser un transistor lorsqu'il fonctionne, ici nous utilisons le S8050 (transistor NPN).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``3.2_custom_tone.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\3.2_custom_tone``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/09a319a6-6861-40e1-ba1b-e7027bc0383d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléchargé le code avec succès, vous entendrez le buzzer passif jouer une séquence de 7 notes musicales.


**Comment ça marche ?**

#. Définir les constantes pour la broche du buzzer et la résolution PWM.

    .. code-block:: arduino

        const int buzzerPin = 14; // broche du buzzer
        const int resolution = 8; 

#. Définir un tableau contenant les fréquences des 7 notes musicales en Hz.

    .. code-block:: arduino

        int frequencies[] = {262, 294, 330, 349, 392, 440, 494};

#. Créer une fonction pour jouer une fréquence donnée sur le buzzer pendant une durée spécifiée.

    .. code-block:: arduino

        void playFrequency(int frequency, int duration) {
            ledcWriteTone(buzzerPin, frequency); // Démarrer la tonalité
            delay(duration); // Attendre la durée spécifiée
            ledcWriteTone(buzzerPin, 0); // Arrêter le buzzer
        }

    * ``uint32_t ledcWriteTone(uint8_t pin, uint32_t freq);`` : Cette fonction est utilisée pour configurer la broche à 50 % de la tonalité PWM sur la fréquence sélectionnée.

        * ``pin`` sélectionner la broche LEDC.
        * ``freq`` sélectionner la fréquence du signal pwm.

    Cette fonction retournera ``frequency`` définie pour le canal. Si ``0`` est retourné, une erreur se produit et le canal LEDC n'a pas été configuré.

#. Configurer le canal PWM et attacher la broche du buzzer dans la fonction ``setup()``.

    .. code-block:: arduino

        void setup() {
            ledcAttach(buzzerPin, 2000, resolution); // Configurer la broche PWM
        }

    * ``bool ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);`` : Cette fonction est utilisée pour configurer la broche LEDC avec la fréquence et la résolution données. Le canal LEDC sera sélectionné automatiquement.
            
        * ``pin`` sélectionner la broche GPIO.
        * ``freq`` sélectionner la fréquence du pwm.
        * ``resolution_bits`` sélectionner la résolution pour le canal LEDC. La plage est de 1 à 14 bits (1-20 bits pour ESP32).

#. Dans la fonction ``loop()``, jouer la séquence de 7 notes avec une pause brève entre chaque note et une pause d'une seconde avant de répéter la séquence.

    .. code-block:: arduino

        void loop() {
            for (int i = 0; i < 7; i++) {
                playFrequency(frequencies[i], 300); // Jouer chaque note pendant 300ms
                delay(50); // Ajouter une pause brève entre les notes
            }
            delay(1000); // Attendre 1 seconde avant de rejouer la séquence
        }
