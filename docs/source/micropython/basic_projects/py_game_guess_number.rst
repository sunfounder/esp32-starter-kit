.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_guess_number:

6.7 Devine le Nombre
==============================

Vous vous sentez chanceux ? Voulez-vous tester votre intuition et voir si vous pouvez deviner le bon numéro ? Alors, ne cherchez pas plus loin que le jeu Devine le Nombre ! 

Avec ce projet, vous pouvez jouer à un jeu de hasard amusant et excitant.

En utilisant une télécommande IR, les joueurs saisissent des chiffres entre 0 et 99 pour essayer de deviner le numéro chanceux généré aléatoirement. 
Le système affiche le numéro saisi par le joueur sur un écran LCD, avec des indications de limites supérieures et inférieures pour guider le joueur vers la bonne réponse. À chaque tentative, les joueurs se rapprochent du numéro chanceux, 
jusqu'à ce que finalement, quelqu'un touche le jackpot et gagne la partie !

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
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|


**Schéma**

.. image:: ../../img/circuit/circuit_6.7_guess_number.png

**Câblage**

.. image:: ../../img/wiring/6.7_guess_receiver_bb.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``6.7_game_guess_number.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 
    * Les bibliothèques ``lcd1602.py`` et ``ir_rx`` sont utilisées ici et vérifiez si elles sont téléchargées sur l'ESP32. Reportez-vous à :ref:`add_libraries_py` pour un tutoriel.

.. code-block:: python

    from lcd1602 import LCD
    import machine
    import time
    import urandom
    from machine import Pin
    from ir_rx.print_error import print_error
    from ir_rx.nec import NEC_8

    # Configuration du récepteur IR
    pin_ir = Pin(14, Pin.IN)

    # Initialisation des variables du jeu de devinettes
    lower = 0
    upper = 99
    pointValue = int(urandom.uniform(lower, upper))
    count = 0

    # Initialisation de l'affichage LCD1602
    lcd = LCD()

    # Initialiser une nouvelle valeur aléatoire pour le jeu
    def init_new_value():
        global pointValue, upper, lower, count
        pointValue = int(urandom.uniform(lower, upper))
        print(pointValue)
        upper = 99
        lower = 0
        count = 0
        return False

    # Afficher les messages sur le LCD en fonction de l'état du jeu
    def lcd_show(result):
        global count
        lcd.clear()
        if result == True: 
            string = "GAME OVER!\n"
            string += "Point is " + str(pointValue)
        else: 
            string = "Enter number: " + str(count) + "\n"
            string += str(lower) + " < Point < " + str(upper)
        lcd.message(string)
        return

    # Traiter le numéro saisi et mettre à jour l'état du jeu
    def number_processing():
        global upper, count, lower
        if count > pointValue:
            if count < upper:
                upper = count
        elif count < pointValue:
            if count > lower:
                lower = count
        elif count == pointValue:
            return True
        count = 0
        return False

    # Traiter les entrées de touches de la télécommande IR
    def process_key(key):
        global count, lower, upper, pointValue, result
        if key == "Power":
            init_new_value()
            lcd_show(False)
        elif key == "+":
            result = number_processing()
            lcd_show(result)
            if result:
                time.sleep(5)
                init_new_value()
                lcd_show(False)
            else:
                lcd_show(False)
        elif key.isdigit():
            count = count * 10 + int(key) if count * 10 + int(key) <= 99 else count
            lcd_show(False)

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

    def callback(data, addr, ctrl):
        if data < 0:
            pass
        else:
            key = decodeKeyValue(data)
            if key != "ERROR":
                process_key(key)

    # Initialiser l'objet récepteur IR avec la fonction de rappel
    ir = NEC_8(pin_ir, callback)

    # ir.error_function(print_error)

    # Initialiser le jeu avec une nouvelle valeur aléatoire
    init_new_value()

    # Afficher l'état initial du jeu sur le LCD
    lcd_show(False)

    try:
        while True:
            pass
    except KeyboardInterrupt:
        ir.close()



* Lorsque le code s'exécute, un numéro secret est produit mais non affiché sur le LCD, et ce que vous devez faire est de le deviner. 
* Appuyez sur le numéro que vous avez deviné sur la télécommande, puis appuyez sur la touche ``+`` pour confirmer.
* Simultanément, la plage affichée sur le LCD I2C1602 diminuera, et vous devrez appuyer sur le numéro approprié en fonction de cette nouvelle plage.
* Si vous avez trouvé le numéro chanceux, ``GAME OVER!`` apparaîtra.

.. note:: 

    Si le code et le câblage sont corrects, mais que le LCD n'affiche toujours aucun contenu, vous pouvez ajuster le potentiomètre à l'arrière pour augmenter le contraste.

**Comment ça marche ?**

Voici une analyse détaillée d'une partie du code.

#. Initialiser les variables du jeu de devinettes.

    .. code-block:: python
    
        lower = 0
        upper = 99
        pointValue = int(urandom.uniform(lower, upper))
        count = 0


    * Limites ``lower`` et ``upper`` pour le numéro secret.
    * Le numéro secret (``pointValue``) généré aléatoirement entre les limites ``lower`` et ``upper``.
    * La devinette actuelle de l'utilisateur (``count``).

#. Cette fonction réinitialise les valeurs du jeu de devinettes et génère un nouveau numéro secret.

    .. code-block:: python
    
        def init_new_value():
            global pointValue, upper, lower, count
            pointValue = int(urandom.uniform(lower, upper))
            print(pointValue)
            upper = 99
            lower = 0
            count = 0
            return False

#. Cette fonction affiche l'état actuel du jeu sur l'écran LCD.

    .. code-block:: python

        def lcd_show(result):
            global count
            lcd.clear()
            if result == True: 
                string = "GAME OVER!\n"
                string += "Point is " + str(pointValue)
            else: 
                string = "Enter number: " + str(count) + "\n"
                string += str(lower) + " < Point < " + str(upper)
            lcd.message(string)
            return

    * Si le jeu est terminé (``result=True``), il affiche ``GAME OVER!`` et le numéro secret.
    * Sinon, il affiche la devinette actuelle (``count``) et la plage de devinettes actuelle (``lower`` à ``upper``)

#. Cette fonction traite la devinette actuelle de l'utilisateur (``count``) et met à jour la plage de devinettes.

    .. code-block:: python

        def number_processing():
            global upper, count, lower
            if count > pointValue:
                if count < upper:
                    upper = count
            elif count < pointValue:
                if count > lower:
                    lower = count
            elif count == pointValue:
                return True
            count = 0
            return False
    
    * Si la devinette actuelle (``count``) est supérieure au numéro secret, la limite supérieure est mise à jour.
    * Si la devinette actuelle (``count``) est inférieure au numéro secret, la limite inférieure est mise à jour.
    * Si la devinette actuelle (``count``) est égale au numéro secret, la fonction retourne ``True`` (jeu terminé).

#. Cette fonction traite les événements de touche reçus de la télécommande IR.

    .. code-block:: python

        def process_key(key):
            global count, lower, upper, pointValue, result
            if key == "Power":
                init_new_value()
                lcd_show(False)
            elif key == "+":
                result = number_processing()
                lcd_show(result)
                if result:
                    time.sleep(5)
                    init_new_value()
                    lcd_show(False)
                else:
                    lcd_show(False)
            elif key.isdigit():
                count = count * 10 + int(key) if count * 10 + int(key) <= 99 else count
                lcd_show(False)

    * Si la touche ``Power`` est pressée, le jeu est réinitialisé.
    * Si la touche ``+`` est pressée, la devinette actuelle (``count``) est traitée et l'état du jeu est mis à jour.
    * Si une touche numérique est pressée, la devinette actuelle (``count``) est mise à jour avec le nouveau chiffre.

#. Cette fonction de rappel est déclenchée lorsque le récepteur IR reçoit des données.

    .. code-block:: python

        def callback(data, addr, ctrl):
            if data < 0:
                pass
            else:
                key = decodeKeyValue(data)
                if key != "ERROR":
                    process_key(key)
