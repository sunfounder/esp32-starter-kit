.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_tilt:

Interrupteur à bascule
=============================

.. image:: img/tilt_switch.png
    :width: 80
    :align: center

L'interrupteur à bascule utilisé ici est un modèle à bille avec une bille en métal à l'intérieur. Il est utilisé pour détecter des inclinaisons de petits angles.

Le principe est très simple. Lorsque l'interrupteur est incliné à un certain angle, la bille à l'intérieur roule et touche les deux contacts reliés aux broches extérieures, déclenchant ainsi les circuits. Sinon, la bille reste éloignée des contacts, interrompant ainsi les circuits.

.. image:: img/tilt_symbol.png
    :width: 600

* `SW520D Tilt Switch Datasheet <https://www.tme.com/Document/f1e6cedd8cb7feeb250b353b6213ec6c/SW-520D.pdf>`_

**Exemple**


* :ref:`ar_tilt` (Projet Arduino)
* :ref:`py_tilt` (Projet MicroPython)

