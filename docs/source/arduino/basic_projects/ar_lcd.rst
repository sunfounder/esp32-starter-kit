.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_lcd1602:

2.6 Affichage de Caractères
===============================

Nous allons maintenant explorer le monde fascinant de l'affichage de caractères en utilisant le module I2C LCD1602.

À travers ce projet, nous apprendrons à initialiser le module LCD, à définir les paramètres d'affichage souhaités et à envoyer des données de caractères à afficher à l'écran. Nous pourrons afficher des messages personnalisés, des relevés de capteurs ou créer des menus interactifs. Les possibilités sont infinies !

En maîtrisant l'art de l'affichage de caractères sur le I2C LCD1602, nous ouvrirons de nouvelles voies de communication et d'affichage d'informations dans nos projets. Plongeons dans cette aventure passionnante et donnons vie à nos caractères sur l'écran LCD.

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants.

Il est très pratique d'acheter un kit complet, voici le lien :

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

    * Ouvrez le fichier ``2.6_lcd1602.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\2.6_lcd1602``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    * La bibliothèque ``LiquidCrystal I2C`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

        .. image:: img/lcd_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/31e33e53-67b2-4e29-b78b-f647fd45fb0b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois ce programme téléversé, le I2C LCD1602 affichera le message de bienvenue "Hello, Sunfounder!" pendant 3 secondes. Ensuite, l'écran affichera l'étiquette "COUNT:" et la valeur du compteur, qui s'incrémente chaque seconde.

.. note:: 

    Si le code et le câblage sont corrects, mais que le LCD n'affiche toujours aucun contenu, vous pouvez ajuster le potentiomètre à l'arrière pour augmenter le contraste.

**Comment ça marche ?**

En appelant la bibliothèque ``LiquidCrystal_I2C.h``, vous pouvez facilement piloter le LCD. 

.. code-block:: arduino

    #include <LiquidCrystal_I2C.h>

Fonctions de la bibliothèque :

* Crée une nouvelle instance de la classe ``LiquidCrystal_I2C`` qui représente un LCD particulier attaché à votre carte Arduino.

    .. code-block:: arduino

        LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

    * ``lcd_Addr`` : L'adresse du LCD, par défaut 0x27.
    * ``lcd_cols`` : Le LCD1602 a 16 colonnes.
    * ``lcd_rows`` : Le LCD1602 a 2 rangées.

* Initialiser le LCD.

    .. code-block:: arduino

        void init()

* Allumer le rétroéclairage (optionnel).

    .. code-block:: arduino

        void backlight()

* Éteindre le rétroéclairage (optionnel).

    .. code-block:: arduino

        void nobacklight()

* Allumer l'affichage du LCD.

    .. code-block:: arduino

        void display()

* Éteindre rapidement l'affichage du LCD.

    .. code-block:: arduino

        void nodisplay()

* Effacer l'affichage, positionner le curseur à zéro.

    .. code-block:: arduino

        void clear()

* Positionner le curseur à la colonne et rangée spécifiées.

    .. code-block:: arduino

        void setCursor(uint8_t col,uint8_t row)

* Afficher du texte sur le LCD.

    .. code-block:: arduino

        void print(data,BASE)

    * ``data`` : Les données à afficher (char, byte, int, long, ou string).
    * ``BASE (optionnel)`` : La base dans laquelle afficher les nombres.

        * ``BIN`` pour binaire (base 2)
        * ``DEC`` pour décimal (base 10)
        * ``OCT`` pour octal (base 8)
        * ``HEX`` pour hexadécimal (base 16).
