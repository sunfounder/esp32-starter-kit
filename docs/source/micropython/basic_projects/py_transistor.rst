.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_transistor:

5.6 Deux types de transistors
==========================================

Ce kit est équipé de deux types de transistors, le S8550 et le S8050, le premier étant un PNP et le second un NPN. Ils se ressemblent beaucoup, et il faut les examiner attentivement pour voir leurs étiquettes.
Lorsqu'un signal de niveau haut traverse un transistor NPN, il est activé. Mais un transistor PNP nécessite un signal de niveau bas pour être activé. Les deux types de transistors sont fréquemment utilisés pour des interrupteurs sans contact, comme dans cette expérience.

Utilisons une LED et un bouton pour comprendre comment utiliser un transistor !

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

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


**Connexion du transistor NPN (S8050)**

.. image:: ../../img/circuit/circuit_5.6_S8050.png

Dans ce circuit, lorsque le bouton est pressé, IO14 est haut.

En programmant IO26 pour qu'il sorte un niveau **haut**, après une résistance de limitation de courant de 1k (pour protéger le transistor), le S8050 (transistor NPN) est autorisé à conduire, permettant ainsi à la LED de s'allumer.

.. image:: ../../img/wiring/5.6_s8050_bb.png

**Connexion du transistor PNP (S8550)**

.. image:: ../../img/circuit/circuit_5.6_S8550.png

Dans ce circuit, IO14 est bas par défaut et passera à haut lorsque le bouton est pressé.

En programmant IO26 pour qu'il sorte un niveau **bas**, après une résistance de limitation de courant de 1k (pour protéger le transistor), le S8550 (transistor PNP) est autorisé à conduire, permettant ainsi à la LED de s'allumer.

La seule différence que vous remarquerez entre ce circuit et le précédent est que dans le circuit précédent, la cathode de la LED est connectée au **collecteur** du **S8050 (transistor NPN)**, tandis que dans celui-ci, elle est connectée à l'**émetteur** du **S8550 (transistor PNP)**.

.. image:: ../../img/wiring/5.6_s8550_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.6_transistor.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit.

.. code-block:: python

    import machine 

    button = machine.Pin(14, machine.Pin.IN)   # Bouton
    led = machine.Pin(26, machine.Pin.OUT)  # LED

    # Démarrer une boucle infinie
    while True:  
        # Lire la valeur actuelle de l'objet 'button' (0 ou 1) et la stocker dans la variable 'button_status'
        button_status = button.value() 
        # Si le bouton est pressé (valeur est 1)
        if button_status == 1: 
            led.value(1) # Allumer la LED
        # Si le bouton n'est pas pressé (valeur est 0)
        else:       
            led.value(0) # Éteindre la LED

Les deux types de transistors peuvent être contrôlés en utilisant le même code.
Lorsque nous pressons le bouton, l'ESP32 enverra un signal de niveau haut au transistor ;
lorsque nous le relâchons, il enverra un signal de niveau bas.

* Le circuit utilisant le S8050 (transistor NPN) s'allumera lorsque le bouton est pressé, indiquant qu'il est en état de conduction de niveau haut ;
* Le circuit utilisant le S8550 (transistor PNP) s'allumera lorsque le bouton est relâché, indiquant qu'il est en état de conduction de niveau bas.
