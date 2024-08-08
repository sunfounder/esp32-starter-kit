.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_tilt:

5.2 Interrupteur d'inclinaison
======================================

L'interrupteur d'inclinaison est un dispositif simple mais efficace à 2 broches qui contient une bille métallique en son centre. Lorsque l'interrupteur est en position verticale, les deux broches sont électriquement connectées, permettant au courant de passer. Cependant, lorsque l'interrupteur est incliné ou penché à un certain angle, la bille métallique se déplace et rompt la connexion électrique entre les broches.

Dans ce projet, nous utiliserons l'interrupteur d'inclinaison pour contrôler l'éclairage d'une LED. En positionnant l'interrupteur de manière à déclencher l'action d'inclinaison, nous pouvons allumer et éteindre la LED en fonction de l'orientation de l'interrupteur.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants.

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
    *   - :ref:`cpn_tilt`
        - \-

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Pour entrée
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Pour sortie
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Broches d'utilisation conditionnelle (entrée)**

    Les broches suivantes ont des résistances de pull-up ou pull-down intégrées, donc des résistances externes ne sont pas nécessaires lorsque **vous les utilisez comme broches d'entrée** :

    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Broches d'utilisation conditionnelle
            - Description
        *   - IO13, IO15, IO2, IO4
            - Tirer vers le haut avec une résistance de 47K par défaut.
        *   - IO27, IO26, IO33
            - Tirer vers le haut avec une résistance de 4.7K par défaut.
        *   - IO32
            - Tirer vers le bas avec une résistance de 1K par défaut.

* **Broches de strap (entrée)**

    Les broches de strap sont un ensemble spécial de broches utilisées pour déterminer des modes de démarrage spécifiques lors de la mise sous tension de l'appareil 
    (c'est-à-dire réinitialisation par mise sous tension).

    .. list-table::
        :widths: 5 15

        *   - Broches de strap
            - IO5, IO0, IO2, IO12, IO15 

    En général, il est **non recommandé de les utiliser comme broches d'entrée**. Si vous souhaitez utiliser ces broches, prenez en compte l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez vous référer à la section :ref:`esp32_strapping`.


**Schéma**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

Lorsque l'interrupteur d'inclinaison est en position verticale, IO14 sera réglé sur haut, ce qui allumera la LED. À l'inverse, lorsque l'interrupteur d'inclinaison est incliné, IO14 sera réglé sur bas, ce qui éteindra la LED.

Le but de la résistance de 10K est de maintenir un état bas stable pour IO14 lorsque l'interrupteur d'inclinaison est en position inclinée.


**Câblage**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.2_tilt_switch.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit.

.. code-block:: python

    import machine
    import time

    switch = machine.Pin(14, machine.Pin.IN) # Broche de l'interrupteur d'inclinaison
    led = machine.Pin(26, machine.Pin.OUT) # Broche de la LED

    while True:
        # Vérifiez si l'interrupteur est incliné en lisant sa valeur
        if switch.value() == 1:
            # Allumez la LED en réglant sa valeur sur 1
            led.value(1)
        else:
            # Éteignez la LED
            led.value(0)

Lorsque le script est en cours d'exécution, la LED s'allumera lorsque l'interrupteur est en position verticale et s'éteindra lorsque l'interrupteur est incliné.
