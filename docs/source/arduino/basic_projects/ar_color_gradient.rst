.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_color_gradient:

6.5 Dégradé de Couleurs
==============================================
Êtes-vous prêt à découvrir un monde de couleurs ? Ce projet vous emmènera 
dans un voyage magique où vous pourrez contrôler une LED RGB et obtenir 
des transitions de couleurs fluides. Que vous cherchiez à ajouter des couleurs 
à votre décoration intérieure ou que vous souhaitiez un projet de programmation 
amusant, ce projet est fait pour vous. Plongeons ensemble dans ce monde coloré !

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**Schéma**

.. image:: ../../img/circuit/circuit_6.5_color_gradient_ar.png

**Câblage**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

La LED RGB a 4 broches : la broche la plus longue est la cathode commune, qui est généralement connectée à la masse (GND); la broche à gauche de la plus longue est la Rouge; et les deux broches à droite sont la Verte et la Bleue.

.. image:: ../../img/wiring/6.5_color_rgb_bb.png


**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``6.5_color_gradient.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\6.5_color_gradient``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a8402b92-8884-4ba0-b09c-e596e97e0af8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Ce projet utilise une LED RGB et un potentiomètre pour créer un effet de mélange de couleurs. Le potentiomètre est utilisé pour ajuster la valeur de teinte de la LED, qui est ensuite convertie en valeurs RGB à l'aide d'une fonction de conversion des couleurs. Les valeurs RGB sont ensuite utilisées pour mettre à jour la couleur de la LED.

**Comment ça marche ?**

Ce projet se base sur le projet :ref:`ar_rgb` en ajoutant un potentiomètre pour ajuster la valeur de teinte de la LED. La valeur de teinte est ensuite convertie en valeurs RGB à l'aide d'une fonction de conversion des couleurs.

#. Dans la fonction loop, lisez la valeur du potentiomètre et convertissez-la en valeur de teinte (0-360).

    .. code-block:: arduino

        int knobValue = analogRead(KNOB_PIN);
        float hueValue = (float) knobValue / 4095.0;
        int hue = (int) (hueValue * 360);

#. Convertissez la valeur de teinte en valeurs RGB à l'aide de la fonction ``HUEtoRGB()``, et mettez à jour la LED avec les nouvelles valeurs de couleur.

    .. code-block:: arduino

        int red, green, blue;
        HUEtoRGB(hue, &red, &green, &blue);
        setColor(red, green, blue);

#. La fonction ``setColor()`` définit la valeur des canaux rouge, vert et bleu à l'aide de la bibliothèque ``LEDC``.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            ledcWrite(redPin, red);
            ledcWrite(greenPin, green);
            ledcWrite(bluePin, blue);
        }

    
#. La fonction ``HUEtoRGB`` convertit une valeur de teinte en valeurs RGB en utilisant le modèle de couleur HSL.

    .. code-block:: arduino

        void HUEtoRGB(int hue, int* red, int* green, int* blue) {
            float h = (float) hue / 60.0;
            float c = 1.0;
            float x = c * (1.0 - fabs(fmod(h, 2.0) - 1.0));
            float r, g, b;
            if (h < 1.0) {
                r = c;
                g = x;
                b = 0;
        ...

