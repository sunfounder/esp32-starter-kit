.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_l9110:

L9110 Module de Pilotage de Moteur
=====================================

Le module de pilotage de moteur L9110 est compétent pour piloter deux moteurs simultanément. Il abrite une paire de puces de pilote L9110S indépendantes, 
chaque canal offrant un courant de sortie stable allant jusqu'à 800 mA.

Avec une plage de tension allant de 2,5V à 12V, le module s'adapte confortablement aux microcontrôleurs de 3,3V et 5V.

En tant que solution simplifiée, le module de pilotage de moteur L9110 facilite le contrôle des moteurs dans diverses applications. 
Grâce à son architecture à deux canaux, il permet l'orchestration indépendante de deux moteurs, idéal pour les projets nécessitant des opérations de moteur double.

Compte tenu de sa sortie de courant continue puissante, ce module alimente en toute confiance des moteurs allant des petits aux moyennement grands, 
ouvrant la voie à diverses entreprises robotiques, d'automatisation et centrées sur les moteurs. Sa large plage de tension injecte davantage d'adaptabilité, s'alignant avec diverses configurations d'alimentation.

Conçu pour être convivial, le module offre des terminaux d'entrée et de sortie intuitifs, simplifiant les connexions aux microcontrôleurs 
ou à des dispositifs de contrôle similaires. De plus, il ne lésine pas sur la sécurité, avec des protections intégrées contre les surintensités et les surchauffes renforçant la fiabilité 
et la sécurité des opérations moteur.

.. image:: img/l9110s.jpg
    :width: 600
    :align: center

* **B-1A & B-1B** : Broches d'entrée pour contrôler la direction de rotation du moteur B.
* **A-1A & A-1B** : Broches d'entrée pour contrôler la direction de rotation du moteur A.
* **0A & OB(A)** : Broches de sortie du moteur A.
* **0A & OB(B)** : Broches de sortie du moteur B.
* **VCC** : Broche d'alimentation (2,5V-12V).
* **GND** : Broche de masse.

**Caractéristiques**

* Deux puces de contrôle de moteur L9110S embarquées
* Contrôle de moteur à deux canaux
* Contrôle indépendant de la direction de rotation du moteur
* Sortie de courant élevée (800 mA par canal)
* Large plage de tension (2,5V-12V)
* Conception compacte
* Terminaux d'entrée et de sortie pratiques
* Fonctions de protection intégrées
* Applications polyvalentes
* Taille du PCB : 29,2 mm x 23 mm
* Température de fonctionnement : -20°C à 80°C
* Indicateur LED d'alimentation

**Principe de fonctionnement**

Voici la table de vérité du moteur B :

Cette table de vérité montre les différents états du moteur B en fonction des valeurs des broches d'entrée B-1A et B-1B. Elle indique la direction de rotation (sens horaire ou antihoraire), le freinage ou l'arrêt du moteur B.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B
      - État du moteur B
    * - 1
      - 0
      - Rotation horaire
    * - 0
      - 1
      - Rotation antihoraire
    * - 0
      - 0
      - Frein
    * - 1
      - 1
      - Arrêt

Voici la table de vérité du moteur A :

Cette table de vérité montre les différents états du moteur A en fonction des valeurs des broches d'entrée A-1A et A-1B. Elle indique la direction de rotation (sens horaire ou antihoraire), le freinage ou l'arrêt du moteur A.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - État du moteur A
    * - 1
      - 0
      - Rotation horaire
    * - 0
      - 1
      - Rotation antihoraire
    * - 0
      - 0
      - Frein
    * - 1
      - 1
      - Arrêt

**Exemple**

* :ref:`ar_motor` (Projet Arduino)
* :ref:`ar_pump` (Projet Arduino)
* :ref:`py_motor` (Projet MicroPython)
* :ref:`py_pump` (Projet MicroPython)
* :ref:`sh_rotating_fan` (Projet Scratch)
