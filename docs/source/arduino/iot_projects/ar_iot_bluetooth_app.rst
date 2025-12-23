.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_bluetooth_app:

8.10 Application Android - Contrôle d'une LED RGB via Arduino et Bluetooth
================================================================================

L'objectif de ce projet est de développer une application Android capable de manipuler la teinte d'une LED RGB via un smartphone en utilisant la technologie Bluetooth.

Cette application Android sera construite en utilisant une plateforme web gratuite connue sous le nom de MIT App Inventor 2. Ce projet est une excellente opportunité pour se familiariser avec l'interfaçage d'un Arduino avec un smartphone.

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../../_static/video/10_ble_app.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants. 

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

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**1. Création de l'application Android**

L'application Android sera créée en utilisant une application web gratuite connue sous le nom de |link_appinventor|. 
MIT App Inventor est un excellent point de départ pour le développement Android, grâce à ses fonctionnalités intuitives de glisser-déposer permettant de créer des applications simples.

Commençons.

#. Voici la page de connexion : http://ai2.appinventor.mit.edu. Vous aurez besoin d'un compte Google pour vous inscrire à MIT App Inventor.

#. Après vous être connecté, allez dans **Projects** -> **Import project (.aia) from my computer**. Ensuite, téléchargez le fichier ``control_rgb_led.aia`` situé dans le chemin ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor``.

   .. image:: img/10_ble_app_inventor1.png

#. Après avoir téléchargé le fichier ``.aia``, vous verrez l'application sur le logiciel **MIT App Inventor**. Il s'agit d'un modèle préconfiguré. Vous pouvez modifier ce modèle après vous être familiarisé avec **MIT App Inventor** en suivant les étapes ci-dessous.

   .. image:: img/10_ble_app_inventor2.png

#. Dans **MIT App Inventor**, vous avez 2 sections principales : le **Designer** et les **Blocks**.

   .. image:: img/10_ble_app_inventor3.png

#. Le **Designer** vous permet d'ajouter des boutons, du texte, des écrans et de modifier l'esthétique générale de votre application.

   .. image:: img/10_ble_app_inventor2.png
   

#. Ensuite, vous avez la section **Blocks**. La section **Blocks** facilite la création de fonctions sur mesure pour votre application.

   .. image:: img/10_ble_app_inventor5.png

#. Pour installer l'application sur un smartphone, allez dans l'onglet **Build**.

   .. image:: img/10_ble_app_inventor6.png

   * Vous pouvez générer un fichier ``.apk``. Après avoir sélectionné cette option, une page apparaîtra vous permettant de choisir entre télécharger un fichier ``.apk`` ou scanner un code QR pour l'installation. Suivez le guide d'installation pour terminer l'installation de l'application.
   * Si vous souhaitez télécharger cette application sur **Google Play** ou une autre marketplace d'applications, vous pouvez générer un fichier ``.aab``.


**2. Téléversez le code**

#. Construisez le circuit.

   .. image:: ../../components/img/rgb_pin.jpg
      :width: 200
      :align: center

   La LED RGB comprend 4 broches : la broche allongée est la broche cathode commune, généralement connectée à la masse (GND) ; la broche à gauche de la plus longue broche représente le rouge ; et les deux broches à droite symbolisent le vert et le bleu.

   .. image:: ../../img/wiring/2.3_color_light_bb.png

#. Ensuite, connectez l'ESP32 carte à votre ordinateur à l'aide d'un câble USB.

   .. image:: ../../img/plugin_esp32.png

#. Ouvrez le fichier ``iot_10_bluetooth_app_inventor.ino`` situé dans le répertoire ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor``, ou copiez le code dans l'Arduino IDE.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/07622bb5-31eb-4a89-b6f2-085f3332051f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Après avoir sélectionné la carte appropriée (**ESP32 Dev Module**) et le port, cliquez sur le bouton **Upload**.

**3. Connexion de l'application et de l'ESP32**

Assurez-vous que l'application créée précédemment est installée sur votre smartphone.

#. Initialement, activez **Bluetooth** sur votre smartphone.

   .. image:: img/10_ble_mobile1.png
      :width: 500
      :align: center

#. Allez dans les **paramètres Bluetooth** de votre smartphone et trouvez **ESP32RGB**.

   .. image:: img/10_ble_mobile2.png
      :width: 500
      :align: center

#. Après avoir cliqué dessus, acceptez la demande de **jumelage** dans la fenêtre pop-up.

   .. image:: img/10_ble_mobile3.png
      :width: 500
      :align: center

#. Maintenant, ouvrez l'application **Control_RGB_LED** récemment installée.

   .. image:: img/10_ble_mobile4.png
      :align: center

#. Dans l'application, cliquez sur **Connect Bluetooth** pour établir une connexion entre l'application et l'ESP32.

   .. image:: img/10_ble_mobile5.png
      :width: 500
      :align: center

#. Sélectionnez le ``xx.xx.xx.xx.xx.xx ESP32RGB`` qui apparaît. Si vous avez changé ``SerialBT.begin("ESP32RGB");`` dans le code, sélectionnez simplement le nom de votre paramètre.

   .. image:: img/10_ble_mobile6.png
      :width: 500
      :align: center

#. Si vous attendez depuis un moment et que vous ne voyez toujours aucun nom de dispositif, il se peut que cette application ne soit pas autorisée à scanner les dispositifs environnants. Dans ce cas, vous devez ajuster les paramètres manuellement.

   * Appuyez longuement sur l'icône de l'application et cliquez sur **Infos sur l'application**. Si vous avez une autre méthode pour accéder à cette page, suivez-la.

      .. image:: img/10_ble_mobile8.png
         :width: 500
         :align: center

   * Allez dans la page **Autorisations**.

      .. image:: img/10_ble_mobile9.png
         :width: 500
         :align: center

   * Localisez **Appareils à proximité**, et sélectionnez **Toujours** pour permettre à cette application de scanner les dispositifs environnants.

      .. image:: img/10_ble_mobile10.png
         :width: 500
         :align: center

   * Maintenant, redémarrez l'application et répétez les étapes 5 et 6 pour vous connecter avec succès au Bluetooth.

#. Une fois la connexion réussie, vous retournerez automatiquement à la page principale, où il sera indiqué connecté. Maintenant, vous pouvez ajuster les valeurs RGB et changer la couleur de l'affichage RGB en appuyant sur le bouton **Change Color**.

   .. image:: img/10_ble_mobile7.png
      :width: 500
      :align: center

