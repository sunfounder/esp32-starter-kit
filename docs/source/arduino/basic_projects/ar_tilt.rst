.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_tilt:

5.2 Inclinez-le！
==========================

Le détecteur d'inclinaison est un dispositif simple mais efficace à 2 broches qui contient une bille métallique en son centre. Lorsque l'interrupteur est en position verticale, les deux broches sont électriquement connectées, permettant au courant de passer. Cependant, lorsque l'interrupteur est incliné ou basculé à un certain angle, la bille métallique se déplace et interrompt la connexion électrique entre les broches.

Dans ce projet, nous utiliserons le détecteur d'inclinaison pour contrôler l'éclairage d'une LED. En positionnant l'interrupteur de manière à déclencher l'action d'inclinaison, nous pouvons allumer et éteindre la LED en fonction de l'orientation de l'interrupteur.

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
    *   - :ref:`cpn_tilt`
        - \-

**Pins disponibles**

* **Pins disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Pour l'entrée
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Pour la sortie
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

* **Pins à usage conditionnel (entrée)**

    Les broches suivantes ont des résistances de tirage intégrées, donc des résistances externes ne sont pas nécessaires lorsqu'elles sont **utilisées comme broches d'entrée** :

    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Pins à usage conditionnel
            - Description
        *   - IO13, IO15, IO2, IO4
            - Tirée vers le haut avec une résistance de 47K par défaut à haute valeur.
        *   - IO27, IO26, IO33
            - Tirée vers le haut avec une résistance de 4.7K par défaut à haute valeur.
        *   - IO32
            - Tirée vers le bas avec une résistance de 1K par défaut à basse valeur.

* **Pins de configuration (entrée)**

    Les broches de configuration sont un ensemble spécial de broches utilisées pour déterminer des modes de démarrage spécifiques lors de la mise sous tension de l'appareil (c'est-à-dire le redémarrage).

    .. list-table::
        :widths: 5 15

        *   - Pins de configuration
            - IO5, IO0, IO2, IO12, IO15

    En général, il est **non recommandé de les utiliser comme broches d'entrée**. Si vous souhaitez utiliser ces broches, tenez compte de l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez vous référer à la section :ref:`esp32_strapping`.

**Schéma**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

Lorsque le détecteur d'inclinaison est en position verticale, IO14 sera réglé sur haut, ce qui allumera la LED. Inversement, lorsque le détecteur d'inclinaison est incliné, IO14 sera réglé sur bas, ce qui éteindra la LED.

Le but de la résistance de 10K est de maintenir un état bas stable pour IO14 lorsque le détecteur d'inclinaison est incliné.

**Câblage**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``5.2_tilt_switch.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.2_tilt_switch``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5ed2406f-185c-407c-ac29-42036f174a5d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code avec succès, la LED s'allumera lorsque l'interrupteur sera en position verticale, et s'éteindra lorsque l'interrupteur sera incliné.

