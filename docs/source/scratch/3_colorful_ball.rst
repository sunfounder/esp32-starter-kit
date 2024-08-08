.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_colorful_ball:

2.3 Boules Colorées
=========================

Dans ce projet, nous allons faire afficher différentes couleurs par les LED RVB.

Cliquer sur les différentes boules colorées dans la zone de scène fera s'allumer la LED RVB avec les couleurs correspondantes.

.. image:: img/4_color.png

Composants nécessaires
---------------------------

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

    *   - INTRODUCTION AUX COMPOSANTS
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

Ce que vous allez apprendre
--------------------------------

- Le principe des LED RVB
- Copier des sprites et sélectionner différents costumes
- Superposition des trois couleurs primaires


Construire le circuit
---------------------------

Une LED RVB regroupe trois LED rouge, verte et bleue dans un boîtier en plastique transparent ou semi-transparent. Elle peut afficher diverses couleurs en changeant la tension d'entrée des trois broches et en les superposant, ce qui, selon les statistiques, peut créer 16 777 216 couleurs différentes.

.. image:: img/4_rgb.png
    :width: 300

.. image:: img/circuit/3_color_ball_bb.png

Programmation
------------------

**1. Sélectionner un sprite**

Supprimez le sprite par défaut, puis choisissez le sprite **Ball**.

.. image:: img/4_ball.png

Dupliquez-le 5 fois.

.. image:: img/4_duplicate_ball.png

Choisissez différents costumes pour ces 5 sprites **Ball** et placez-les aux positions correspondantes.

.. note::

    Le costume du sprite **Ball3** doit être changé manuellement en rouge.

.. image:: img/4_rgb1.png
    :width: 800

**2. Faire s'allumer les LED RVB dans la couleur appropriée**

Avant de comprendre le code, nous devons comprendre le `modèle de couleur RVB <https://fr.wikipedia.org/wiki/RVB>`_.

Le modèle de couleur RVB est un modèle de couleur additive dans lequel les lumières rouge, verte et bleue sont ajoutées ensemble de différentes manières pour reproduire un large éventail de couleurs. 

Mélange des couleurs additives : ajouter du rouge au vert donne du jaune ; ajouter du vert au bleu donne du cyan ; ajouter du bleu au rouge donne du magenta ; ajouter les trois couleurs primaires ensemble donne du blanc.

.. image:: img/4_rgb_addition.png
  :width: 400

Voici le code pour faire s'allumer la LED RVB en jaune.

.. image:: img/4_yellow.png


Lorsque le sprite Ball (balle jaune) est cliqué, nous réglons la broche 27 sur haut (LED rouge allumée), la broche 26 sur haut (LED verte allumée) et la broche 25 sur bas (LED bleue éteinte), de sorte que la LED RVB s'allume en jaune.

Vous pouvez écrire les codes pour les autres sprites de la même manière pour faire s'allumer les LED RVB dans les couleurs correspondantes.


**3. Sprite Ball2 (bleu clair)**

.. image:: img/4_blue.png

**4. Sprite Ball3 (rouge)**

.. image:: img/4_red.png

**5. Sprite Ball4 (vert)**

.. image:: img/4_green.png

**6. Sprite Ball5 (violet)**

.. image:: img/4_purple.png
