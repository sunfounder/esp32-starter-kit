.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de saison.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_resistor:

Résistance
================

.. image:: img/resistor.png
    :width: 300

Une résistance est un élément électronique qui peut limiter le courant de branchement. 
Une résistance fixe est un type de résistance dont la valeur ne peut être changée, tandis que celle d'un potentiomètre ou d'une résistance variable peut être ajustée. 

Deux symboles de circuit généralement utilisés pour la résistance. Normalement, la valeur de la résistance est indiquée dessus. Donc, si vous voyez ces symboles dans un circuit, cela représente une résistance. 

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** est l'unité de résistance et les unités plus grandes incluent KΩ, MΩ, etc. 
Leur relation est la suivante : 1 MΩ = 1000 KΩ, 1 KΩ = 1000 Ω. Normalement, la valeur de la résistance est indiquée dessus. 

Lors de l'utilisation d'une résistance, il est nécessaire de connaître sa valeur de résistance. Voici deux méthodes : vous pouvez observer les bandes sur la résistance ou utiliser un multimètre pour mesurer la résistance. Il est recommandé d'utiliser la première méthode car elle est plus pratique et rapide. 

.. image:: img/resistance_card.jpg

Comme indiqué sur la carte, chaque couleur représente un chiffre. 

.. list-table::

   * - Noir
     - Marron
     - Rouge
     - Orange
     - Jaune
     - Vert
     - Bleu
     - Violet
     - Gris
     - Blanc
     - Or
     - Argent
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0.1
     - 0.01

Les résistances à 4 et 5 bandes sont fréquemment utilisées, sur lesquelles il y a 4 et 5 bandes colorées. 

Normalement, lorsque vous obtenez une résistance, vous pouvez trouver difficile de décider de quel côté commencer la lecture des couleurs. 
Le truc est que l'écart entre la 4ème et la 5ème bande sera comparativement plus large.

Par conséquent, vous pouvez observer l'écart entre les deux bandes colorées à une extrémité de la résistance ; 
si c'est plus large que tout autre écart entre les bandes, alors vous pouvez lire à partir du côté opposé. 

Voyons comment lire la valeur de résistance d'une résistance à 5 bandes comme indiqué ci-dessous.

.. image:: img/220ohm.jpg
    :width: 500

Donc pour cette résistance, la valeur doit être lue de gauche à droite. 
La valeur doit être dans ce format : 1ère Bande 2ème Bande 3ème Bande x 10^Multiplicateur (Ω) et l'erreur admissible est ±Tolérance%. 
Donc, la valeur de résistance de cette résistance est 2(rouge) 2(rouge) 0(noir) x 10^0(noir) Ω = 220 Ω, 
et l'erreur admissible est ± 1% (marron). 

.. list-table::Code des couleurs des résistances courantes
    :header-rows: 1

    * - Résistance 
      - Code des couleurs  
    * - 10Ω   
      - marron noir noir argent marron
    * - 100Ω   
      - marron noir noir noir marron
    * - 220Ω 
      - rouge rouge noir noir marron
    * - 330Ω 
      - orange orange noir noir marron
    * - 1kΩ 
      - marron noir noir marron marron
    * - 2kΩ 
      - rouge noir noir marron marron
    * - 5.1kΩ 
      - vert marron noir marron marron
    * - 10kΩ 
      - marron noir noir rouge marron 
    * - 100kΩ 
      - marron noir noir orange marron 
    * - 1MΩ 
      - marron noir noir vert marron 




Vous pouvez en apprendre davantage sur les résistances sur Wiki : `Resistor - Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_.

