.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_line_track:

Module de Suivi de Ligne
================================

.. image:: img/line_track.png
    :width: 400
    :align: center

* S : Habituellement bas, haut lorsqu'une ligne noire est détectée.
* V+ : Alimentation, 3.3V~5V.
* G : Masse.

Il s'agit d'un module de suivi de ligne à 1 canal qui, comme son nom l'indique, suit les lignes noires sur un fond blanc ou les lignes blanches sur un fond noir.

.. image:: img/tcrt5000.jpg
    :width: 200
    :align: center

Le module utilise un capteur infrarouge TCRT5000, qui se compose d'une LED infrarouge (bleue) et d'un triplet photosensible (noir).

* La LED infrarouge bleue, lorsqu'elle est alimentée, émet une lumière infrarouge invisible à l'œil humain.
* Le phototransistor noir, utilisé pour recevoir la lumière infrarouge, possède une résistance interne qui varie en fonction de la lumière infrarouge reçue ; plus il reçoit de lumière infrarouge, plus sa résistance diminue et vice versa.

Le module comprend un comparateur LM393, qui compare la tension du phototransistor avec la tension réglée (ajustée par le potentiomètre) ; si elle est supérieure à la tension réglée, la sortie est de 1, sinon la sortie est de 0.

Ainsi, lorsque le tube émetteur infrarouge éclaire une surface noire, celle-ci absorbe la lumière, le phototransistor reçoit moins de lumière infrarouge, sa résistance augmente (tension augmente) et, après le comparateur LM393, la sortie est au niveau haut.

De même, lorsqu'il éclaire une surface blanche, la lumière réfléchie augmente et la résistance du phototransistor diminue (tension diminue) ; par conséquent, le comparateur délivre un niveau bas et la LED d'indication s'allume.

* `TCRT5000 <https://www.vishay.com/docs/83760/tcrt5000.pdf>`_

**Caractéristiques**

* Utilisation du capteur d'émission infrarouge TCRT5000.
* Distance de détection : 1-8mm, focale de 2.5mm.
* Signal de sortie du comparateur propre, bonne forme d'onde, capacité de conduite supérieure à 15mA.
* Utilisation d'un potentiomètre pour le réglage de la sensibilité.
* Tension de fonctionnement : 3.3V-5V.
* Sortie numérique : 0 (blanc) et 1 (noir).
* Utilisation du comparateur LM393 à large tension.
* Taille : 42mm x 10mm.

**Exemple**

* :ref:`ar_line_track` (Projet Arduino)
* :ref:`py_line_track` (Projet MicroPython)
* :ref:`sh_protect_heart` (Projet Scratch)

