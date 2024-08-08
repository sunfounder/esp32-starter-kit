.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_lcd1602:

2.6 Afficher des caractères
==================================================

Nous allons maintenant explorer le monde fascinant de l'affichage de caractères en utilisant le module I2C LCD1602.

À travers ce projet, nous apprendrons comment initialiser le module LCD, définir les paramètres d'affichage souhaités et envoyer des données de caractères à afficher à l'écran. Nous pourrons afficher des messages personnalisés, afficher des relevés de capteurs ou créer des menus interactifs. Les possibilités sont infinies !

En maîtrisant l'art de l'affichage de caractères sur l'I2C LCD1602, nous ouvrirons de nouvelles voies pour la communication et l'affichage d'informations dans nos projets. Plongeons dans ce voyage passionnant et donnons vie à nos caractères sur l'écran LCD.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Broches disponibles
        - Description d'utilisation

    *   - IO21
        - SDA
    *   - IO22
        - SCL
    
**Schéma**

.. image:: ../../img/circuit/circuit_2.6_lcd.png

**Câblage**

.. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``2.6_liquid_crystal_display.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 
    * La bibliothèque ``lcd1602.py`` est utilisée ici, assurez-vous qu'elle est téléchargée sur l'ESP32. Pour un tutoriel détaillé, consultez :ref:`add_libraries_py`.

.. code-block:: python

    # Importer la classe LCD du module lcd1602
    from lcd1602 import LCD

    import time

    # Créer une instance de la classe LCD et l'assigner à la variable lcd
    lcd = LCD()
    # Définir la chaîne " Hello!\n"
    string = " Hello!\n"
    # Afficher la chaîne sur l'écran LCD
    lcd.message(string)

    time.sleep(2)
    # Définir la chaîne " Sunfounder!"
    string = "    Sunfounder!"
    # Afficher la chaîne sur l'écran LCD
    lcd.message(string)

    time.sleep(2)
    # Effacer l'écran LCD
    lcd.clear()


Après l'exécution du script, vous pourrez voir deux lignes de texte apparaître sur l'écran LCD à tour de rôle, puis disparaître.


.. note:: 

    Si le code et le câblage sont corrects mais que l'écran LCD ne parvient toujours pas à afficher du contenu, vous pouvez ajuster le potentiomètre à l'arrière pour augmenter le contraste.


**Comment ça fonctionne ?**

Dans la bibliothèque ``lcd1602``, nous intégrons les fonctions pertinentes de lcd1602 dans la classe LCD.

#. Importer le module ``lcd1602``.

    .. code-block:: python

        from lcd1602 import LCD    

#. Déclarer un objet de la classe ``LCD`` et le nommer ``lcd``.

    .. code-block:: python

        lcd = LCD()

#. Cette instruction affichera le texte sur le LCD. Il convient de noter que l'argument doit être de type chaîne. Si nous voulons passer un entier ou un flottant, nous devons utiliser l'instruction de conversion forcée ``str()``.

    .. code-block:: python

        lcd.message(string)


#. Si vous appelez cette instruction plusieurs fois, le LCD superposera les textes. Il est donc nécessaire d'utiliser l'instruction suivante pour effacer l'affichage.

    .. code-block:: python

        lcd.clear()
