.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _unknown_com_port:

Toujours afficher "Unknown COMxx" ?
==========================================

Lors de la connexion de l'ESP32 à l'ordinateur, l'IDE Arduino affiche souvent ``Unknown COMxx``. Pourquoi cela se produit-il ?

.. note::

   Si « COMxx inconnu » ou aucun port n’apparaît, il est possible que votre ordinateur n’ait pas reconnu la carte. Voir :ref:`install_driver`.

.. image:: img/unknown_device.png

C'est parce que le pilote USB pour ESP32 est différent de celui des cartes Arduino classiques. L'IDE Arduino ne peut pas reconnaître automatiquement cette carte.

Dans un tel scénario, vous devez sélectionner manuellement la carte correcte en suivant ces étapes :

#. Cliquez sur **"Select the other board and port"**.

    .. image:: img/unknown_select.png

#. Dans la recherche, tapez **"esp32 dev module"**, puis sélectionnez la carte qui apparaît. Ensuite, sélectionnez le port correct et cliquez sur **OK**.

    .. image:: img/unknown_board.png

#. Maintenant, vous devriez pouvoir voir votre carte et votre port dans cette fenêtre de vue rapide.

    .. image:: img/unknown_correct.png