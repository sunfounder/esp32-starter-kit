.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_pot:

Potentiomètre
=================

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Le potentiomètre est également un composant résistif avec 3 bornes dont la valeur de résistance peut être ajustée selon une variation régulière.

Les potentiomètres existent en différentes formes, tailles et valeurs, mais ils ont tous les points communs suivants :

* Ils ont trois bornes (ou points de connexion).
* Ils ont un bouton, une vis ou un curseur qui peut être déplacé pour faire varier la résistance entre la borne centrale et l'une des bornes extérieures.
* La résistance entre la borne centrale et l'une des bornes extérieures varie de 0 Ω à la résistance maximale du potentiomètre lorsque le bouton, la vis ou le curseur est déplacé.

Voici le symbole de circuit du potentiomètre.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Les fonctions du potentiomètre dans le circuit sont les suivantes :

#. Servir de diviseur de tension

    Le potentiomètre est une résistance ajustable en continu. Lorsque vous ajustez l'arbre ou la poignée coulissante du potentiomètre, le contact mobile glisse sur la résistance. À ce moment, une tension peut être sortie en fonction de la tension appliquée sur le potentiomètre et de l'angle de rotation du bras mobile ou du déplacement effectué.

#. Servir de rhéostat

    Lorsque le potentiomètre est utilisé comme rhéostat, connectez la borne centrale et l'une des deux autres bornes dans le circuit. Ainsi, vous pouvez obtenir une valeur de résistance modifiée de manière fluide et continue dans le déplacement du contact mobile.

#. Servir de contrôleur de courant

    Lorsque le potentiomètre agit comme contrôleur de courant, la borne de contact coulissante doit être connectée comme l'une des bornes de sortie.

Si vous souhaitez en savoir plus sur le potentiomètre, consultez : `Potentiomètre - Wikipedia <https://fr.wikipedia.org/wiki/Potentiom%C3%A8tre>`_

**Exemple**

* :ref:`ar_potentiometer` (Projet Arduino)
* :ref:`py_potentiometer` (Projet MicroPython)
* :ref:`sh_moving_mouse` (Projet Scratch)
* :ref:`sh_breakout_clone` (Projet Scratch)
