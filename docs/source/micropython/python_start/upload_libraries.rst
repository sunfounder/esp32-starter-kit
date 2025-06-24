.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _add_libraries_py:

1.4 Télécharger les bibliothèques (Important)
==============================================

Dans certains projets, des bibliothèques supplémentaires sont nécessaires. Nous allons donc d’abord les transférer vers l’ESP32, ce qui nous permettra d’exécuter le code directement par la suite.

#. Téléchargez le code correspondant depuis le lien ci-dessous.

   * :download:`Kit de démarrage SunFounder ESP32 <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`

#. Connectez l’ESP32 WROOM 32E à votre ordinateur à l’aide d’un câble USB.

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Ouvrez l’IDE Thonny et cliquez sur l’interpréteur "MicroPython (ESP32).COMXX" dans le coin inférieur droit.

    .. image:: img/sec_inter.png

#. Dans la barre de navigation supérieure, cliquez sur **Affichage** -> **Fichiers**.

    .. image:: img/th_files.png

#. Accédez au dossier dans lequel vous avez téléchargé le `paquet de code <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`_, puis ouvrez le dossier ``esp32-starter-kit-main\micropython\libs``.

    .. image:: img/th_path.png

#. Sélectionnez tous les fichiers ou dossiers dans le dossier ``libs/``, faites un clic droit, puis cliquez sur **Téléverser vers**. Le transfert peut prendre un moment.

    .. image:: img/th_upload.png

#. Vous verrez maintenant les fichiers que vous venez de téléverser dans le lecteur ``MicroPython device``.

    .. image:: img/th_done.png
