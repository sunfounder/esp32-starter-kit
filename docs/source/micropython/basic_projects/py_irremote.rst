.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_receiver:

5.14 Télécommande infrarouge
================================

Un récepteur infrarouge est un composant qui reçoit des signaux infrarouges et peut détecter et sortir indépendamment des signaux compatibles avec le niveau TTL. Il est de taille similaire à un transistor encapsulé dans du plastique et est couramment utilisé dans diverses applications telles que la télécommande infrarouge et la transmission infrarouge.

Dans ce projet, nous allons utiliser un récepteur infrarouge pour détecter les signaux d'une télécommande. Lorsque vous appuyez sur un bouton de la télécommande et que le récepteur infrarouge reçoit le signal correspondant, il peut décoder ce signal pour déterminer quel bouton a été pressé. En décodant le signal reçu, nous pouvons identifier la touche ou la commande spécifique associée.

Le récepteur infrarouge nous permet d'intégrer la fonctionnalité de télécommande dans notre projet, nous permettant d'interagir et de contrôler des appareils en utilisant des signaux infrarouges.

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

Lorsque vous appuyez sur un bouton de la télécommande, le récepteur infrarouge détecte le signal, et vous pouvez utiliser une bibliothèque infrarouge pour le décoder. Ce processus de décodage vous permet d'obtenir la valeur de la touche associée à la pression du bouton.

**Câblage**

.. image:: ../../img/wiring/5.14_ir_receiver_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.14_ir_receiver.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 

    * Ici, vous devez utiliser les bibliothèques trouvées dans le dossier ``ir_rx``. Veuillez vous assurer qu'elles ont été téléchargées sur l'ESP32. Pour un tutoriel complet, reportez-vous à :ref:`add_libraries_py`.

.. code-block:: python

    import time
    from machine import Pin, freq
    from ir_rx.print_error import print_error
    from ir_rx.nec import NEC_8

    pin_ir = Pin(14, Pin.IN) # Récepteur IR

    # Décoder les données reçues et retourner le nom de la touche correspondante
    def decodeKeyValue(data):       
        if data == 0x16:
            return "0"
        if data == 0x0C:
            return "1"
        if data == 0x18:
            return "2"
        if data == 0x5E:
            return "3"
        if data == 0x08:
            return "4"
        if data == 0x1C:
            return "5"
        if data == 0x5A:
            return "6"
        if data == 0x42:
            return "7"
        if data == 0x52:
            return "8"
        if data == 0x4A:
            return "9"
        if data == 0x09:
            return "+"
        if data == 0x15:
            return "-"
        if data == 0x7:
            return "EQ"
        if data == 0x0D:
            return "U/SD"
        if data == 0x19:
            return "CYCLE"
        if data == 0x44:
            return "PLAY/PAUSE"
        if data == 0x43:
            return "FORWARD"
        if data == 0x40:
            return "BACKWARD"
        if data == 0x45:
            return "POWER"
        if data == 0x47:
            return "MUTE"
        if data == 0x46:
            return "MODE"
        return "ERROR"

    # Fonction de rappel utilisateur
    def callback(data, addr, ctrl):
        if data < 0:  # Le protocole NEC envoie des codes répétés.
            pass
        else:
            print(decodeKeyValue(data))
            

    ir = NEC_8(pin_ir, callback) # Instancier le récepteur NEC_8

    # Afficher les informations de débogage
    ir.error_function(print_error)  

    # Garder le script en cours d'exécution jusqu'à interruption par Ctrl+C
    try:
        while True:
            pass
    except KeyboardInterrupt:
        ir.close()  # Fermer le récepteur

Lorsque le programme s'exécute, appuyez sur la touche de la télécommande, la valeur et le nom de la touche apparaîtront dans le Shell.

.. note::
    La nouvelle télécommande est dotée d'une languette en plastique à l'extrémité pour isoler la batterie à l'intérieur. Pour alimenter la télécommande lors de son utilisation, retirez simplement cette languette en plastique.

**Comment ça marche ?**

#. Bien que ce programme puisse paraître un peu complexe à première vue, il accomplit en réalité les fonctions fondamentales du récepteur IR en seulement quelques lignes de code.


    .. code-block:: python

        import time
        from machine import Pin, freq
        from ir_rx.nec import NEC_8

        pin_ir = Pin(14, Pin.IN) # Récepteur IR

        # Fonction de rappel utilisateur
        def callback(data, addr, ctrl):
            if data < 0:  # Le protocole NEC envoie des codes répétés.
                pass
            else:
                print(decodeKeyValue(data))

        ir = NEC_8(pin_ir, callback)  # Instancier le récepteur

    * Dans ce code, un objet ``ir`` est instancié, lui permettant de lire les signaux capturés par le récepteur IR à tout moment.
    * Les informations résultantes sont ensuite stockées dans la variable ``data`` dans la fonction de rappel.

        * `Callback Function - Wikipedia <https://en.wikipedia.org/wiki/Callback_(computer_programming)>`_

    * Si le récepteur IR reçoit des valeurs dupliquées (par exemple, lorsqu'un bouton est maintenu enfoncé), les ``data`` seront inférieures à 0, et ces données doivent être filtrées.

    * Sinon, les ``data`` seraient une valeur utilisable, bien qu'en code non lisible. La fonction ``decodeKeyValue(data)`` est ensuite utilisée pour le décoder en un format plus compréhensible.

        .. code-block:: python

            def decodeKeyValue(data):
                if data == 0x16:
                    return "0"
                if data == 0x0C:
                    return "1"
                if data == 0x18:
                    return "2"
                if data == 0x5E:
                ...


#. Ensuite, nous incorporons plusieurs fonctions de débogage dans le programme. Bien que ces fonctions soient essentielles, elles ne sont pas directement liées au résultat souhaité.

    .. code-block:: python

        from ir_rx.print_error import print_error

        ir.error_function(print_error) # Afficher les informations de débogage

#. Enfin, nous utilisons une boucle vide pour le programme principal et implémentons une structure try-except pour garantir que le programme se termine correctement avec l'objet ``ir`` fermé.

    .. code-block:: python

        try:
            while True:
                pass
        except KeyboardInterrupt:
            ir.close()

    * `Try Statement - Python Docs <https://docs.python.org/3/reference/compound_stmts.html?#the-try-statement>`_