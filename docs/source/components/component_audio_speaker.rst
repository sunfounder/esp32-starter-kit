.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_audio_speaker:

Module Amplificateur Audio et Haut-parleur
===============================================

**Module Amplificateur Audio**

.. image:: img/audio_module.jpg
    :width: 500
    :align: center

Le module amplificateur audio contient une puce amplificatrice audio HXJ8002. Cette puce est un amplificateur de puissance à faible alimentation, capable de fournir une puissance audio moyenne de 3W pour une charge BTL de 3Ω avec une faible distorsion harmonique (moins de 10% de distorsion de seuil à 1KHz) à partir d'une alimentation de 5V DC. Cette puce peut amplifier des signaux audio sans aucun condensateur de couplage ou de bootstrap.

Le module peut être alimenté par une source de 2,0V à 5,5V DC avec un courant de fonctionnement de 10mA (0,6uA pour un courant de veille typique) et produire un son amplifié puissant dans un haut-parleur d'impédance de 3Ω, 4Ω ou 8Ω. Ce module dispose d'un circuit amélioré pour réduire considérablement le bruit de transition lors de la mise sous tension et hors tension. Sa petite taille, sa haute efficacité et sa faible consommation d'énergie le rendent applicable dans de nombreux projets portables alimentés par batterie et microcontrôleurs.

* **IC**: HXJ8002
* **Tension d'entrée**: 2V ~ 5.5V
* **Courant en mode veille**: 0.6uA (valeur typique)
* **Puissance de sortie**: 3W (charge 3Ω), 2.5W (charge 4Ω), 1.5W (charge 8Ω)
* **Impédance du haut-parleur de sortie**: 3Ω, 4Ω, 8Ω
* **Dimensions**: 19.8mm x 14.2mm

**Haut-parleur**

.. image:: img/speaker_pic.png
    :width: 300
    :align: center

* **Dimensions**: 20x30x7mm
* **Impédance** : 8 ohms
* **Puissance d'entrée nominale**: 1.5W 
* **Puissance d'entrée maximale**: 2.0W
* **Longueur du fil**: 10 cm

.. image:: img/2030_speaker.png

Le tableau des dimensions est le suivant：

* :download:`2030 Speaker Datasheet <https://github.com/sunfounder/sf-pdf/raw/master/datasheet/2030-speaker-datasheet.pdf>`


**Exemple**

* :ref:`ar_mp3_player_sd` (Projet Arduino)
* :ref:`bluetooth_audio_player` (Projet Arduino)

