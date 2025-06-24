.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

1.5 Guide rapide sur Thonny
==================================

.. _open_run_code_py:

Ouvrir et exécuter du code directement
---------------------------------------------

La section code des projets vous indique exactement quel code utiliser, alors double-cliquez sur le fichier ``.py`` avec le numéro de série dans le chemin ``esp32-starter-kit-main\micropython\codes\`` pour l’ouvrir.

Cependant, vous devez d’abord télécharger le package et téléverser les bibliothèques, comme décrit dans :ref:`add_libraries_py`.

#. Ouvrir le code.

    Par exemple, ``1.1_hello_led.py``.

    Si vous double-cliquez dessus, une nouvelle fenêtre s’ouvrira à droite. Vous pouvez ouvrir plusieurs fichiers de code en même temps.

    .. image:: img/quick_guide1.png

#. Branchez l’ESP32 à votre ordinateur via un câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Sélectionner l’interpréteur correct

    Sélectionnez l’interpréteur "MicroPython (ESP32).COMxx".

    .. image:: img/sec_inter.png

#. Exécuter le code

    Pour exécuter le script, cliquez sur le bouton **Exécuter le script actuel** ou appuyez sur F5.

    .. image:: img/quick_guide2.png

    Si le code contient des instructions d’impression, elles apparaîtront dans le Shell ; sinon, seule l’information suivante apparaîtra.

    Cliquez sur **Affichage** -> **Éditer** pour ouvrir la fenêtre du Shell si elle n’apparaît pas dans Thonny.

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; ESP32 module with ESP32

            Type "help()" for more information.

            >>> %Run -c $EDITOR_CONTENT

    * La première ligne affiche la version de MicroPython, la date et les informations de votre appareil.
    * La deuxième ligne suggère de taper "help()" pour obtenir de l’aide.
    * La troisième ligne est une commande de Thonny indiquant à l’interpréteur MicroPython de votre Pico W d’exécuter le contenu de l’éditeur de script — "EDITOR_CONTENT".
    * S’il y a un message après la troisième ligne, c’est généralement un message que vous avez demandé à MicroPython d’imprimer ou un message d’erreur du code.

#. Arrêter l’exécution

    .. image:: img/quick_guide3.png

    Pour arrêter l’exécution du code, cliquez sur le bouton **Arrêter/Redémarrer le backend**. La commande **%RUN -c $EDITOR_CONTENT** disparaîtra après l’arrêt.

#. Enregistrer ou enregistrer sous

    Vous pouvez enregistrer les modifications apportées à l’exemple ouvert en appuyant sur **Ctrl+S** ou en cliquant sur le bouton **Enregistrer** dans Thonny.

    Le code peut être enregistré comme fichier séparé sur le **lecteur MicroPython (ESP32)** en cliquant sur **Fichier** -> **Enregistrer sous**.

    .. image:: img/quick_guide4.png

    Sélectionnez **lecteur MicroPython**.

    .. image:: img/quick_guide5.png
        
    Ensuite, cliquez sur **OK** après avoir saisi le nom du fichier et l’extension **.py**. Sur le lecteur MicroPython, vous verrez votre fichier sauvegardé.

    .. image:: img/quick_guide6.png

    .. note::
        Quel que soit le nom que vous donnez à votre code, il est préférable de le nommer de manière descriptive, plutôt que d’utiliser un nom inutile comme ``abc.py``.
        Lorsque vous enregistrez le code sous ``main.py``, il s’exécutera automatiquement à l’allumage.

Créer et exécuter un fichier
-----------------------------

Le code est présenté directement dans la section du projet. Vous pouvez le copier dans Thonny et l’exécuter comme suit.

#. Créer un nouveau fichier

    Ouvrez l’IDE Thonny, cliquez sur le bouton **Nouveau** pour créer un fichier vide.

    .. image:: img/quick_guide7.png

#. Copier le code

    Copiez le code du projet dans l’IDE Thonny.

    .. image:: img/quick_guide8.png

#. Branchez l’ESP32 à votre ordinateur via un câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Sélectionner l’interpréteur correct

    Sélectionnez l’interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit.

    .. image:: img/sec_inter.png

#. Exécuter le code

    Cliquez sur **Exécuter le script actuel** ou appuyez simplement sur ``F5`` pour l’exécuter.

    .. image:: img/quick_guide9.png

    Si le code contient des instructions d’impression, elles s’afficheront dans le Shell ; sinon, seules les informations suivantes apparaîtront.

    Cliquez sur **Affichage** -> **Éditer** pour ouvrir la fenêtre du Shell si elle n’apparaît pas dans Thonny.

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; ESP32 module with ESP32

            Type "help()" for more information.

            >>> %Run -c $EDITOR_CONTENT

    * La première ligne affiche la version de MicroPython, la date et les informations de votre appareil.
    * La deuxième ligne vous invite à entrer "help()" pour obtenir de l’aide.
    * La troisième ligne est une commande de Thonny indiquant à l’interpréteur MicroPython d’exécuter le contenu de l’éditeur de script – "EDITOR_CONTENT".
    * Si un message s’affiche après cette ligne, il s’agit généralement d’une instruction ``print`` ou d’un message d’erreur du code.

#. Arrêter l’exécution

    .. image:: img/quick_guide3.png

    Pour arrêter le code en cours d’exécution, cliquez sur le bouton **Arrêter/Redémarrer le backend**. La commande **%RUN -c $EDITOR_CONTENT** disparaîtra après l’arrêt.

#. Enregistrer ou enregistrer sous

    Vous pouvez enregistrer le code en appuyant sur **Ctrl+S** ou en cliquant sur le bouton **Enregistrer** dans Thonny. Dans la fenêtre qui s’ouvre, sélectionnez l’emplacement où enregistrer le fichier.

    .. image:: img/quick_guide5.png

    Ensuite, cliquez sur **OK** ou **Enregistrer** après avoir saisi le nom du fichier avec l’extension **.py**.

    .. image:: img/quick_guide6.png

    .. note::
        Quel que soit le nom que vous donnez à votre code, il est préférable d’utiliser un nom descriptif plutôt qu’un nom inutile comme ``abc.py``.
        Si vous enregistrez le code sous ``main.py``, il s’exécutera automatiquement à l’allumage.

#. Ouvrir un fichier

    Voici deux façons d’ouvrir un fichier de code enregistré.

    * La première méthode consiste à cliquer sur l’icône d’ouverture dans la barre d’outils de Thonny. Comme lors de l’enregistrement, il vous sera demandé si vous souhaitez l’ouvrir depuis **cet ordinateur** ou **l’appareil MicroPython** ; par exemple, cliquez sur **appareil MicroPython** pour voir la liste des programmes enregistrés sur l’ESP32.
    * La seconde consiste à activer l’aperçu des fichiers en cliquant sur **Affichage** -> **Fichiers**, puis double-cliquez sur le fichier ``.py`` correspondant pour l’ouvrir.
