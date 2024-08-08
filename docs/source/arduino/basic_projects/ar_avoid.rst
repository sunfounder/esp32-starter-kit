.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_ir_obstacle:

5.3 Détecter les Objets
=============================

Ce module est couramment installé sur les voitures et les robots pour détecter 
la présence d'obstacles devant eux. Il est également largement utilisé dans les 
dispositifs portables, les robinets d'eau, etc.

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants. 

Il est certainement pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément aux liens ci-dessous.

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

* **Broches de Strapping (Entrée)**

    Les broches de strapping sont un ensemble spécial de broches utilisées pour déterminer des modes de démarrage spécifiques lors du démarrage de l'appareil 
    (c'est-à-dire lors de la réinitialisation à la mise sous tension).
        
    .. list-table::
        :widths: 5 15

        *   - Broches de Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    En général, il n'est **pas recommandé de les utiliser comme broches d'entrée**. Si vous souhaitez utiliser ces broches, tenez compte de l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez vous référer à la section :ref:`esp32_strapping`.

**Schéma**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

Lorsque le module d'évitement d'obstacles ne détecte aucun obstacle, IO14 renvoie un niveau haut. Cependant, lorsqu'il détecte un obstacle, il renvoie un niveau bas. Vous pouvez ajuster le potentiomètre bleu pour modifier la distance de détection de ce module.

**Câblage**

.. image:: ../../img/wiring/5.3_avoid_bb.png

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``5.3.detect_the_obstacle.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.3.detect_the_obstacle``. 
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b0f22caa-3c77-4dc1-9a33-20ff23d04a5e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Réglez le taux de communication série sur 115200 bauds.
Après avoir téléversé le code avec succès, si le module d'évitement d'obstacles IR détecte quelque chose devant lui, "0" apparaîtra sur le moniteur série, sinon "1" sera affiché.
