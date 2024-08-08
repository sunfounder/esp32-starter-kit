.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_rgb:

LED RVB
=================

.. image:: img/rgb_led.png
    :width: 200
    :align: center

Les LED RVB émettent de la lumière dans diverses couleurs. Une LED RVB regroupe trois LED rouge, vert et bleu dans une coque en plastique transparent ou semi-transparent. Elle peut afficher différentes couleurs en modifiant la tension d'entrée des trois broches et en les superposant, ce qui, selon les statistiques, peut créer 16 777 216 couleurs différentes.

**Caractéristiques**

* Couleur : Tri-couleur (Rouge/Vert/Bleu)
* Cathode commune
* Lentille ronde claire de 5 mm
* Tension directe : Rouge : DC 2,0 - 2,2V ; Bleu et Vert : DC 3,0 - 3,2V (IF=20mA) 
* LED RVB DIP de 0,06 Watts
* Luminosité augmentée jusqu'à +20%
* Angle de vision : 30°

**Anode commune et cathode commune**

Les LED RVB peuvent être catégorisées en anode commune et cathode commune. 

* Dans une LED RVB à cathode commune, les trois LED partagent une connexion négative (cathode).
* Dans une LED RVB à anode commune, les trois LED partagent une connexion positive (anode).

.. image:: img/rgb_cc_ca.jpg

.. note::
    Nous utilisons le modèle à cathode commune.

**Broches de la LED RVB**

Une LED RVB a 4 broches : la plus longue est la GND ; les autres sont Rouge, Vert et Bleu. Placez les LED RVB comme indiqué, de sorte que la plus longue patte soit la deuxième à partir de la gauche. Ensuite, les numéros des broches de la LED RVB devraient être Rouge, GND, Vert et Bleu.

.. image:: img/rgb_pin.jpg
    :width: 200

Vous pouvez également utiliser le multimètre en mode Test de diode, puis connecter comme indiqué ci-dessous pour mesurer la couleur de chaque broche.

.. image:: img/rgb_test.png

**Mélange de couleurs**

Pour générer des couleurs supplémentaires, vous pouvez combiner les trois couleurs à différentes intensités. Pour ajuster l'intensité de chaque LED, vous pouvez utiliser un signal PWM.

Parce que les LED sont si proches les unes des autres, nos yeux voient le résultat de la combinaison des couleurs plutôt que les trois couleurs individuellement.

Consultez le tableau ci-dessous pour voir comment les couleurs sont combinées. Cela vous donnera une idée de comment fonctionne le mélange des couleurs et comment différentes couleurs sont produites.

.. image:: img/rgb_mix.png

**Exemple**

* :ref:`ar_rgb` (Projet Arduino)
* :ref:`ar_color_gradient` (Projet Arduino)
* :ref:`py_rgb` (Projet MicroPython)
* :ref:`sh_colorful_ball` (Projet Scratch)

