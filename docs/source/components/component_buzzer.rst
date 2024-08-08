.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_buzzer:

Buzzer
=======

.. image:: img/buzzer.png
    :width: 600

En tant que type de buzzer électronique à structure intégrée, les buzzers, alimentés par une source de courant continu, sont largement utilisés dans les ordinateurs, imprimantes, photocopieuses, alarmes, jouets électroniques, dispositifs électroniques automobiles, téléphones, minuteurs et autres produits électroniques ou dispositifs vocaux. 

Les buzzers peuvent être catégorisés comme actifs ou passifs (voir l'image suivante). Tournez le buzzer de manière à ce que ses broches soient orientées vers le haut ; le buzzer avec une carte de circuit imprimé verte est un buzzer passif, tandis que celui entouré d'un ruban noir est un buzzer actif.

La différence entre un buzzer actif et un buzzer passif :

Un buzzer actif a une source d'oscillation intégrée, il émet donc un son lorsqu'il est alimenté. Mais un buzzer passif n'a pas cette source, il ne bipera donc pas si des signaux continus sont utilisés ; à la place, vous devez utiliser des ondes carrées dont la fréquence est comprise entre 2K et 5K pour le faire fonctionner. Le buzzer actif est souvent plus coûteux que le passif en raison de ses circuits d'oscillation intégrés multiples.

Voici le symbole électrique d'un buzzer. Il a deux broches avec des pôles positif et négatif. Avec un + sur la surface représentant l'anode et l'autre étant la cathode.

.. image:: img/buzzer_symbol.png
    :width: 150

Vous pouvez vérifier les broches du buzzer, la plus longue est l'anode et la plus courte est la cathode. Ne les confondez pas lors de la connexion, sinon le buzzer ne fera pas de son.

`Buzzer - Wikipedia <https://en.wikipedia.org/wiki/Buzzer>`_

**Exemple**

* :ref:`ar_ac_buz` (Projet Arduino)
* :ref:`ar_pa_buz` (Projet Arduino)
* :ref:`ar_reversing_aid` (Projet Arduino)
* :ref:`py_pa_buz` (Projet MicroPython)
* :ref:`py_ac_buz` (Projet MicroPython)
* :ref:`py_reversing_aid` (Projet MicroPython)

