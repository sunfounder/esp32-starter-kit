.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_led:

LED
==========

**Qu'est-ce qu'une LED ?**

.. image:: img/led_pin.jpg
    :width: 200

.. image:: img/led_polarity.jpg
    :width: 400

Les LEDs sont des dispositifs électroniques très courants qui peuvent être utilisés pour décorer votre pièce pendant les fêtes, et vous pouvez également les utiliser comme indicateurs pour diverses choses, comme pour savoir si vos appareils électroménagers sont allumés ou éteints. Elles existent en dizaines de formes et de tailles différentes, et les plus courantes sont les LEDs à trou traversant, qui ont généralement de longues pattes et peuvent être branchées sur une plaque d'essai.

Le nom complet de la LED est diode électroluminescente, elle a donc les caractéristiques d'une diode, où le courant circule dans une seule direction, de l'anode (positive) vers la cathode (négative).

Voici les symboles électriques des LEDs.

.. image:: img/led_symbol.png

**Différentes tailles et couleurs**

.. image:: img/led_color.png

Le rouge, le jaune, le bleu, le vert et le blanc sont les couleurs de LED les plus courantes, et la lumière émise est généralement de la même couleur que l'apparence.

Nous utilisons rarement des LEDs qui sont transparentes ou mates en apparence, mais la lumière émise peut être d'une couleur autre que blanche.

Les LEDs existent en quatre tailles : 3mm, 5mm, 8mm et 10mm, le 5mm étant la taille la plus courante.

.. image:: img/led_type.jpg

Voici la taille de la LED de 5mm en mm.

.. image:: img/led_size.png

**Tension directe**

La tension directe est un paramètre très important à connaître lors de l'utilisation des LEDs, car elle détermine la quantité d'énergie utilisée et la taille de la résistance de limitation de courant.

La tension directe est la tension que la LED doit utiliser lorsqu'elle s'allume. Pour la plupart des LEDs rouges, jaunes, oranges et vert clair, elles utilisent généralement une tension comprise entre 1,9V et 2,1V.

.. image:: img/led_voltage.jpg
    :width: 400
    :align: center

Selon la loi d'Ohm, le courant passant par ce circuit diminue à mesure que la résistance augmente, ce qui fait que la LED s'assombrit.

    I = (Vp-Vl)/R

Pour que les LEDs s'allument en toute sécurité et avec la bonne luminosité, quelle résistance devons-nous utiliser dans le circuit ?

Pour 99% des LEDs de 5mm, le courant recommandé est de 20mA, comme vous pouvez le voir dans la colonne Conditions de sa fiche technique.

.. image:: img/led_datasheet.png

Maintenant, convertissons la formule ci-dessus comme indiqué ci-dessous.

    R = (Vp-Vl)/I


Si ``Vp`` est 5V, ``Vl`` (tension directe) est 2V, et ``I`` est 20mA, alors ``R`` est 150Ω.

Nous pouvons donc rendre la LED plus lumineuse en réduisant la résistance de la résistance, mais il n'est pas recommandé de descendre en dessous de 150Ω (cette résistance peut ne pas être très précise, car les LEDs de différents fournisseurs peuvent présenter des différences).

Voici les tensions directes et les longueurs d'onde des différentes couleurs de LEDs que vous pouvez utiliser comme référence.

.. list-table::
   :widths: 25 25 50
   :header-rows: 1

   * - Couleur de la LED
     - Tension directe
     - Longueur d'onde
   * - Rouge
     - 1.8V ~ 2.1V
     - 620 ~ 625
   * - Jaune
     - 1.9V ~ 2.2V
     - 580 ~ 590
   * - Vert
     - 1.9V ~ 2.2V
     - 520 ~ 530
   * - Bleu
     - 3.0V ~ 3.2V
     - 460 ~ 465
   * - Blanc
     - 3.0V ~ 3.2V
     - 8000 ~ 9000

**Exemple**

* :ref:`ar_blink` (Projet Arduino)
* :ref:`ar_fading` (Projet Arduino)
* :ref:`py_blink` (Projet MicroPython)
* :ref:`py_fading` (Projet MicroPython)
* :ref:`sh_breathing_led` (Projet Scratch)
* :ref:`sh_table_lamp` (Projet Scratch)

