.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _add_libraries_ar:

1.4 Installer des bibliothèques (Important)
===============================================

Une bibliothèque est un ensemble de code ou de fonctions pré-écrits qui étendent les capacités de l'IDE Arduino. Les bibliothèques fournissent du code prêt à l'emploi pour diverses fonctionnalités, vous permettant de gagner du temps et des efforts dans la programmation de fonctionnalités complexes.

Il existe deux principales façons d'installer des bibliothèques :

Installation depuis le gestionnaire de bibliothèques
--------------------------------------------------------

De nombreuses bibliothèques sont disponibles directement via le gestionnaire de bibliothèques Arduino. Vous pouvez accéder au gestionnaire de bibliothèques en suivant ces étapes :

#. Dans le **gestionnaire de bibliothèques**, vous pouvez rechercher la bibliothèque souhaitée par nom ou parcourir différentes catégories.

   .. note::

      Dans les projets nécessitant l'installation de bibliothèques, des invites indiqueront quelles bibliothèques installer. Suivez les instructions fournies, telles que "La bibliothèque de capteurs DHT est utilisée ici, vous pouvez l'installer depuis le gestionnaire de bibliothèques." Il suffit d'installer les bibliothèques recommandées comme indiqué.

   .. image:: img/install_lib3.png

#. Une fois que vous trouvez la bibliothèque que vous souhaitez installer, cliquez dessus puis cliquez sur le bouton **Installer**.

   .. image:: img/install_lib2.png

#. L'IDE Arduino téléchargera et installera automatiquement la bibliothèque pour vous.

.. _install_lib_man:

Installation manuelle
-------------------------

Certaines bibliothèques ne sont pas disponibles via le **gestionnaire de bibliothèques** et doivent être installées manuellement. Pour installer ces bibliothèques, suivez ces étapes :

#. Ouvrez l'IDE Arduino et allez à **Sketch** -> **Include Library** -> **Add .ZIP Library**.

   .. image:: img/a2dp_add_zip.png

#. Naviguez jusqu'au répertoire où se trouvent les fichiers de la bibliothèque, comme le dossier ``esp32-starter-kit\c\libraries``, et sélectionnez le fichier de bibliothèque souhaité, comme ``ESP32-A2DP.zip``. Ensuite, cliquez sur **Open**.

    * :download:`SunFounder ESP32 Starter Kit <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`

   .. image:: img/a2dp_choose.png

#. Après un court instant, vous recevrez une notification indiquant une installation réussie.

   .. image:: img/a2dp_success.png

#. Répétez le même processus pour ajouter la bibliothèque ``ESP8266Audio.zip``.

.. note::

   Les bibliothèques installées en utilisant l'une ou l'autre des méthodes ci-dessus peuvent être trouvées dans le répertoire de bibliothèques par défaut de l'IDE Arduino, qui est généralement situé à ``C:\Users\xxx\Documents\Arduino\libraries``.

   Si votre répertoire de bibliothèques est différent, vous pouvez le vérifier en allant dans **Fichier** -> **Préférences**.

      .. image:: img/install_lib1.png
