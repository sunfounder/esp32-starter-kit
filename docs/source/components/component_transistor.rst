.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_transistor:

Transistor
==============

.. image:: img/npn_pnp.png

Le transistor est un dispositif semi-conducteur qui contrôle le courant par le courant. Il fonctionne en amplifiant un signal faible en un signal de plus grande amplitude et est également utilisé comme interrupteur sans contact.

Un transistor est une structure à trois couches composée de semi-conducteurs de type P et de type N. Ils forment trois régions internes. La région la plus fine au milieu est la région de base ; les deux autres sont soit de type N, soit de type P - la région plus petite avec une majorité de porteurs est la région de l'émetteur, tandis que l'autre est la région du collecteur. Cette composition permet au transistor d'être un amplificateur.
À partir de ces trois régions, trois pôles sont générés respectivement, à savoir la base (b), l'émetteur (e) et le collecteur (c). Ils forment deux jonctions P-N, à savoir la jonction de l'émetteur et la jonction du collecteur. La direction de la flèche dans le symbole du circuit du transistor indique celle de la jonction de l'émetteur.

* `P-N junction - Wikipedia <https://en.wikipedia.org/wiki/P-n_junction>`_

En fonction du type de semi-conducteur, les transistors peuvent être divisés en deux groupes, les NPN et les PNP. D'après l'abréviation, nous pouvons dire que le premier est constitué de deux semi-conducteurs de type N et d'un de type P, et que le second est l'inverse. Voir la figure ci-dessous.

.. note::
    Le s8550 est un transistor PNP et le s8050 est un NPN. Ils se ressemblent beaucoup, et nous devons vérifier attentivement pour voir leurs étiquettes.

.. image:: img/transistor_symbol.png


Lorsqu'un signal de niveau haut traverse un transistor NPN, il est activé. Mais un transistor PNP nécessite un signal de niveau bas pour le gérer. Les deux types de transistors sont fréquemment utilisés comme interrupteurs sans contact, comme dans cette expérience.


* `S8050 Transistor Datasheet <https://components101.com/asset/sites/default/files/component_datasheet/S8050%20Transistor%20Datasheet.pdf>`_
* `S8550 Transistor Datasheet <https://www.mouser.com/datasheet/2/149/SS8550-118608.pdf>`_

Placez l'étiquette face à nous et les broches vers le bas. Les broches de gauche à droite sont l'émetteur (e), la base (b) et le collecteur (c).

.. image:: img/ebc.png

.. note::
    * La base est le dispositif de contrôle de la porte pour la plus grande alimentation électrique.
    * Dans le transistor NPN, le collecteur est la plus grande alimentation électrique et l'émetteur est la sortie de cette alimentation, le transistor PNP est juste l'inverse.

.. Example
.. -------------------

.. :ref:`Two Kinds of Transistors`


**Exemple**

* :ref:`ar_transistor` (Projet Arduino)
* :ref:`ar_ac_buz` (Projet Arduino)
* :ref:`ar_fruit_piano` (Projet Arduino)
* :ref:`py_transistor` (Projet MicroPython)
* :ref:`py_pa_buz` (Projet MicroPython)
* :ref:`py_light_theremin` (Projet MicroPython)

