.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_reversing_aid:

6.3 Aide au stationnement en marche arrière
==================================================

Imaginez ceci : Vous êtes dans votre voiture, sur le point de reculer dans une place de parking étroite. Avec notre projet, vous aurez un module ultrasonique monté à l'arrière de votre véhicule, agissant comme un œil numérique. Lorsque vous engagez la marche arrière, le module s'anime, émettant des impulsions ultrasoniques qui rebondissent sur les obstacles derrière vous.

La magie opère lorsque ces impulsions reviennent au module. Il calcule rapidement la distance entre votre voiture et les objets, transformant ces données en un retour visuel en temps réel affiché sur un écran LCD vibrant. Vous verrez des indicateurs dynamiques, codés par couleur, représentant la proximité des obstacles, vous assurant une compréhension claire de l'environnement.

Mais nous ne nous sommes pas arrêtés là. Pour vous immerger davantage dans cette expérience de conduite, nous avons incorporé un buzzer animé. À mesure que votre voiture se rapproche d'un obstacle, le rythme du buzzer s'intensifie, créant une symphonie auditive d'avertissements. C'est comme avoir un orchestre personnel vous guidant à travers les complexités du stationnement en marche arrière.

Ce projet innovant combine une technologie de pointe avec une interface utilisateur interactive, rendant votre expérience de recul sécurisée et sans stress. Avec le module ultrasonique, l'écran LCD et le buzzer animé travaillant en harmonie, vous vous sentirez autonome et confiant en manœuvrant dans des espaces restreints, vous laissant libre de vous concentrer sur le plaisir de conduire.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.4_reversing_aid.png
    :width: 800
    :align: center

Le capteur ultrasonique du projet émet des ondes sonores à haute fréquence et mesure le temps nécessaire pour que ces ondes rebondissent après avoir frappé un objet. En analysant ces données, la distance entre le capteur et l'objet peut être calculée. Pour avertir lorsque l'objet est trop proche, un buzzer est utilisé pour produire un signal sonore. De plus, la distance mesurée est affichée sur un écran LCD pour une visualisation facile.

**Câblage**

.. image:: ../../img/wiring/6.4_aid_ultrasonic_bb.png

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``6.3_reversing_aid.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\6.3_reversing_aid`` directement.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`
    * La bibliothèque ``LiquidCrystal I2C`` est utilisée ici, vous pouvez l'installer à partir du **Gestionnaire de Bibliothèques**.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c06deba0-36fd-4f17-8290-c7a39202e089/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Après avoir téléversé le code avec succès, la distance détectée actuelle sera affichée sur le LCD. Ensuite, le buzzer changera la fréquence sonore en fonction des différentes distances.

.. note:: 

    Si le code et le câblage sont corrects, mais que le LCD n'affiche toujours aucun contenu, vous pouvez ajuster le potentiomètre à l'arrière pour augmenter le contraste.


**Comment ça marche ?**

Ce code nous aide à créer un dispositif de mesure de distance simple qui peut mesurer la distance entre les objets et fournir un retour d'information via un écran LCD et un buzzer.

La fonction ``loop()`` contient la logique principale du programme et s'exécute en continu. Regardons de plus près la fonction ``loop()``.

#. Boucle pour lire la distance et mettre à jour les paramètres

    Dans la ``loop``, le code lit d'abord la distance mesurée par le module ultrasonique et met à jour le paramètre d'intervalle en fonction de la distance.

    .. code-block:: arduino

        // Mise à jour de la distance
        distance = readDistance();

        // Mise à jour des intervalles en fonction de la distance
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. Vérifier s'il est temps de biper

    Le code calcule la différence entre l'heure actuelle et l'heure précédente du bip, et si la différence est supérieure ou égale au temps d'intervalle, il déclenche le buzzer et met à jour l'heure précédente du bip.

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. Mettre à jour l'affichage LCD

    Le code efface l'affichage LCD, puis affiche "Dis:" et la distance actuelle en centimètres sur la première ligne.

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);





