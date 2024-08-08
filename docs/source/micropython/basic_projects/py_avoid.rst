.. note::

    Bonjour, bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_ir_obstacle:

5.3 Détection d'Obstacle
===================================

Ce module est couramment installé sur les voitures et les robots pour détecter 
la présence d'obstacles devant eux. Il est également largement utilisé dans les 
appareils portatifs, les robinets d'eau, etc.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants. 

Il est définitivement pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Broches disponibles
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Broches de démarrage (entrée)**

    Les broches de démarrage sont un ensemble spécial de broches utilisées pour déterminer les modes de démarrage spécifiques lors du démarrage de l'appareil 
    (c'est-à-dire, reset à la mise sous tension).
   
    .. list-table::
        :widths: 5 15

        *   - Broches de démarrage
            - IO5, IO0, IO2, IO12, IO15 
    
    En général, il est **non recommandé de les utiliser comme broches d'entrée**. Si vous souhaitez utiliser ces broches, considérez l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez consulter la section :ref:`esp32_strapping`.

**Schéma**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

Lorsque le module d'évitement d'obstacles ne détecte aucun obstacle, IO14 renvoie un niveau haut. Cependant, lorsqu'il détecte un obstacle, il renvoie un niveau bas. Vous pouvez ajuster le potentiomètre bleu pour modifier la distance de détection de ce module.

**Câblage**

.. image:: ../../img/wiring/5.3_avoid_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.3_avoid.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Ensuite, cliquez sur "Exécuter le script actuel" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 



.. code-block:: python

    import machine
    import time

    ir_avoid = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_UP) # pin du module d'évitement

    while True:

        # Afficher les valeurs du module d'évitement d'obstacles 
        print(ir_avoid.value()) 
        time.sleep(0.1)


Lorsque le programme est en cours d'exécution, si le module d'évitement d'obstacles IR détecte un obstacle devant lui, la valeur "0" sera affichée sur le Moniteur Série, sinon la valeur "1" sera affichée.
