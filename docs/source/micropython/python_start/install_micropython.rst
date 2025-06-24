.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _install_micropython_on_esp32:

1.3 Install MicroPython on the ESP32(Important)
==================================================
#. Connectez l’ESP32 WROOM 32E à votre ordinateur à l’aide d’un câble USB.

   .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Cliquez dans le coin inférieur droit de l’IDE Thonny, sélectionnez **"MicroPython(ESP32).xxxCOMXX"** dans le menu déroulant, puis cliquez sur **"Configurer l’interpréteur"**.

   .. note::

      Si vous ne voyez aucune option autre que "Local Python 3", cela signifie que votre carte ESP32 n’a probablement pas été reconnue par votre ordinateur.  
      Dans ce cas, vous devrez peut-être :ref:`install_driver`.

   .. image:: img/install_micropython1.png

#. Cliquez sur **"Installer ou mettre à jour MicroPython"** dans la nouvelle fenêtre contextuelle.

   .. image:: img/install_micropython2.png

#. Sélectionnez le port correct, la famille MicroPython, la variante et la carte, puis cliquez sur **"Installer"**.

   .. image:: img/install_micropython3.png

#. Après une installation réussie, retournez à la page d’accueil de Thonny. Vous verrez la version de MicroPython et des messages liés à l’ESP32, au lieu de messages d’erreur en rouge.

   .. image:: img/install_micropython5.png
