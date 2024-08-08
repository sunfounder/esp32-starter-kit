.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_ac_buz:

3.1 Bip
==================
Voici un projet simple pour faire biper un buzzer actif rapidement quatre fois par seconde.

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

Lorsque la sortie IO14 est haute, après la résistance de limitation de courant de 1K (pour protéger le transistor), le S8050 (transistor NPN) conduira, ce qui fera sonner le buzzer.

Le rôle du S8050 (transistor NPN) est d'amplifier le courant et de rendre le son du buzzer plus fort. En fait, vous pouvez également connecter le buzzer directement à IO14, mais vous constaterez que le son du buzzer est plus faible.

**Câblage**

Deux types de buzzers sont inclus dans le kit. 
Nous devons utiliser un buzzer actif. Tournez-les, le dos scellé (non le PCB exposé) est celui que nous voulons.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

Le buzzer doit utiliser un transistor pour fonctionner, ici nous utilisons un S8050 (transistor NPN).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``3.1_beep.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 




.. code-block:: python

    import machine
    import time

    # Créez un objet Pin représentant la broche 14 et définissez-le en mode sortie
    buzzer = machine.Pin(14, machine.Pin.OUT)

    # Entrez dans une boucle infinie
    while True:
        # Itérez sur les valeurs de 0 à 3 en utilisant une boucle for
        for i in range(4):
            # Allumez le buzzer en réglant sa valeur à 1
            buzzer.value(1)
            # Pause de 0,2 secondes
            time.sleep(0.2)
            # Éteignez le buzzer
            buzzer.value(0)
            # Pause de 0,2 secondes
            time.sleep(0.2)
        # Pause de 1 seconde avant de redémarrer la boucle for
        time.sleep(1)



Lorsque le script est en cours d'exécution, le buzzer émettra un bip rapide quatre fois par seconde.
