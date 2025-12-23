.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

1.3 Installer la carte ESP32 (Important)
===========================================

Pour programmer le microcontrôleur ESP32, nous devons installer le package de la carte ESP32 dans l'IDE Arduino. Suivez le guide étape par étape ci-dessous :

**Installer la carte ESP32**

.. #. Open the Arduino IDE. Go to **File** and select **Preferences** from the drop-down menu.

..     .. image:: img/install_esp321.png

.. #. In the Preferences window, locate the **Additional Board Manager URLs** field. Click on it to activate the text box.

..     .. image:: img/install_esp322.png

.. #. Add the following URL to the **Additional Board Manager URLs** field: https://espressif.github.io/arduino-esp32/package_esp32_index.json. This URL points to the package index file for the ESP32 cartes. Click the **OK** button to save the changes.

..     .. image:: img/install_esp323.png

#. Dans la fenêtre **Gestionnaire de cartes**, tapez **ESP32** dans la barre de recherche. Cliquez sur le bouton **Installer** pour démarrer le processus d'installation. Cela téléchargera et installera le package de la carte ESP32.

    .. image:: img/install_esp324.png

#. Félicitations ! Vous avez installé avec succès le package de la carte ESP32 dans l'IDE Arduino. 

**Télécharger le code**

#. Connectez maintenant l'ESP32 à votre ordinateur à l'aide d'un câble USB. 

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Ensuite, sélectionnez la carte correcte, **ESP32 Dev Module**, en cliquant sur **Outils** -> **Carte** -> **esp32**.

    .. image:: img/install_esp325.png

#. Si votre ESP32 est connecté à l'ordinateur, vous pouvez choisir le port correct en cliquant sur **Outils** -> **Port**.

   .. note::
   
      Si seul COM1 est affiché ou si aucun port n’apparaît, il est possible que votre ordinateur n’ait pas reconnu la carte. Voir :ref:`install_driver`.
   
   .. image:: img/install_esp326.png


#. De plus, Arduino 2.0 a introduit une nouvelle façon de sélectionner rapidement la carte et le port. Pour ESP32, il n'est généralement pas reconnu automatiquement, donc vous devez cliquer sur **Sélectionner une autre carte et un autre port**.

    .. image:: img/install_esp327.png

#. Dans la boîte de recherche, tapez **ESP32 Dev Module** et sélectionnez-le lorsqu'il apparaît. Ensuite, choisissez le port correct et cliquez sur **OK**.

    .. image:: img/install_esp328.png

#. Par la suite, vous pouvez le sélectionner via cette fenêtre d'accès rapide. Notez que lors d'utilisations ultérieures, il peut arriver que l'ESP32 ne soit pas disponible dans la fenêtre d'accès rapide, et vous devrez répéter les deux étapes ci-dessus.

    .. image:: img/install_esp329.png

#. Les deux méthodes vous permettent de sélectionner la carte et le port corrects, alors choisissez celle qui vous convient le mieux. Maintenant, tout est prêt pour télécharger le code vers l'ESP32.
