.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_7_segment:

Afficheur 7 segments
==========================

.. image:: img/7_segment.png
    :width: 200
    :align: center

Un afficheur 7 segments est un composant en forme de 8 qui regroupe 7 LED. Chaque LED est appelée segment - lorsqu'elle est alimentée, un segment forme une partie d'un chiffre à afficher.

* Chacune des LED de l'afficheur est associée à un segment positionnel dont l'une des broches de connexion est sortie du boîtier en plastique rectangulaire.
* Ces broches de LED sont étiquetées de "a" à "g", représentant chaque LED individuelle.
* Les autres broches de LED sont connectées ensemble pour former une broche commune.
* En polarisant les broches appropriées des segments LED dans un ordre particulier, certains segments s'allument et d'autres restent éteints, affichant ainsi le caractère correspondant sur l'afficheur.

**Caractéristiques**

* Taille : 19 x 12,7 x 13,8 mm (LxLxH, incluant les broches)
* Écran : 0,56''
* Couleur : rouge
* Cathode commune
* Tension directe : 1,8 V
* 10 broches
* Pas : standard 0,1" (2,54 mm)

**Cathode Commune (CC) ou Anode Commune (CA)**

Il existe deux types de connexion de broches : Cathode Commune (CC) et Anode Commune
 (CA). Comme le nom l'indique, un afficheur CC a toutes les cathodes des 7 LED connectées, 
 tandis qu'un afficheur CA a toutes les anodes des 7 segments connectées.

* Afficheur 7 segments à cathode commune

.. image:: img/segment_cathode.png
    :width: 500

* Afficheur 7 segments à anode commune

.. image:: img/segment_anode.png
    :width: 500

**Comment savoir si CC ou CA ?**

En général, il y aura une étiquette sur le côté de l'afficheur 7 segments, xxxAx ou xxxBx. En règle générale, xxxAx signifie cathode commune et xxxBx signifie anode commune.

.. image:: img/7_segment.png
    :width: 250

.. image:: img/7_segment_bs.png

Vous pouvez également utiliser un multimètre pour vérifier l'afficheur 7 segments s'il n'y a pas d'étiquette. Réglez le multimètre en mode test de diode et connectez la sonde noire à la broche centrale de l'afficheur 7 segments, et la sonde rouge à n'importe quelle autre broche sauf la centrale. L'afficheur 7 segments est à cathode commune si un segment s'allume.

Inversez les sondes rouge et noire si aucun segment ne s'allume. Lorsque qu'un segment s'allume, cela indique une anode commune.

.. image:: img/7_segment_test.JPG
    :width: 600

**Codes d'affichage**

Pour vous aider à comprendre comment les afficheurs 7 segments (cathode commune) affichent les chiffres, nous avons dessiné le tableau suivant. Les chiffres sont les nombres de 0 à F affichés sur l'afficheur 7 segments ; (DP) GFEDCBA se réfère aux LED correspondantes réglées sur 0 ou 1.

.. image:: img/segment_code.png

Par exemple, 01011011 signifie que DP, F et C sont réglés sur 0, tandis que les autres sont réglés sur 1. Par conséquent, le chiffre 2 est affiché sur l'afficheur 7 segments.

.. image:: img/7segment_2.png

**Exemples**

* :ref:`ar_7_segment` (Projet Arduino)
* :ref:`ar_dice` (Projet Arduino)
* :ref:`py_7_segment` (Projet MicroPython)
* :ref:`py_dice` (Projet MicroPython)

