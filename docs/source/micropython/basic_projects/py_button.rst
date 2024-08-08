.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_button:

5.1 Lecture de la valeur du bouton
==============================================

Dans ce projet interactif, nous allons explorer le contrôle de boutons et la manipulation de LED.

Le concept est simple mais efficace. Nous allons lire l'état d'un bouton. Lorsque le bouton est enfoncé, il enregistre un niveau de tension élevé, ou "état haut". Cette action déclenchera ensuite l'allumage d'une LED.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants. 

Il est définitivement pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

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

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Pour l'entrée
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Pour la sortie
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

* **Broches à usage conditionnel (entrée)**

    Les broches suivantes possèdent des résistances pull-up ou pull-down intégrées, donc des résistances externes ne sont pas nécessaires lorsqu'elles sont **utilisées comme broches d'entrée** :

    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Broches à usage conditionnel
            - Description
        *   - IO13, IO15, IO2, IO4
            - Pull-up avec une résistance de 47K par défaut à un niveau élevé.
        *   - IO27, IO26, IO33
            - Pull-up avec une résistance de 4.7K par défaut à un niveau élevé.
        *   - IO32
            - Pull-down avec une résistance de 1K par défaut à un niveau bas.

* **Broches de démarrage (entrée)**

    Les broches de démarrage sont un ensemble spécial de broches utilisées pour déterminer les modes de démarrage spécifiques lors du démarrage de l'appareil 
    (c'est-à-dire, reset à la mise sous tension).

    .. list-table::
        :widths: 5 15

        *   - Broches de démarrage
            - IO5, IO0, IO2, IO12, IO15 

    En général, il est **non recommandé de les utiliser comme broches d'entrée**. Si vous souhaitez utiliser ces broches, considérez l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez consulter la section :ref:`esp32_strapping`.

**Schéma**

.. image:: ../../img/circuit/circuit_5.1_button.png

Pour assurer un bon fonctionnement, connectez un côté de la broche du bouton à 3.3V et l'autre côté à IO14. Lorsque le bouton est enfoncé, IO14 sera réglé sur haut, ce qui allumera la LED. Lorsque le bouton est relâché, IO14 reviendra à son état suspendu, qui peut être soit haut soit bas. Pour assurer un niveau bas stable lorsque le bouton n'est pas enfoncé, IO14 doit être connecté à la terre via une résistance pull-down de 10K.

**Câblage**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::

    Un bouton à quatre broches est conçu en forme de H. Lorsque le bouton n'est pas enfoncé, les broches gauche et droite sont déconnectées, et le courant ne peut pas circuler entre elles. Cependant, lorsque le bouton est enfoncé, les broches gauche et droite sont connectées, créant un chemin pour que le courant circule.

**Code**

.. note::

    * Ouvrez le fichier ``5.1_read_button_value.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

.. code-block:: python

    import machine
    import time

    button = machine.Pin(14, machine.Pin.IN) # Broche du bouton
    led = machine.Pin(26, machine.Pin.OUT) # Broche de la LED

    while True:
        # Si le bouton est enfoncé en lisant sa valeur
        if button.value() == 1:
            # Allumer la LED en réglant sa valeur à 1
            led.value(1)
        else:
            # Éteindre la LED
            led.value(0)

Pendant l'exécution du script, la LED s'allume lorsque vous appuyez sur le bouton et s'éteint lorsque vous le relâchez.
