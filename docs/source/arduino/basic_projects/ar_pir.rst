.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_pir:

5.5 Détecter les mouvements humains
========================================

Le capteur infrarouge passif (capteur PIR) est un capteur courant qui peut mesurer la lumière infrarouge (IR) émise par les objets dans son champ de vision.
En termes simples, il reçoit le rayonnement infrarouge émis par le corps, détectant ainsi les mouvements des personnes et des autres animaux.
Plus précisément, il informe la carte de contrôle principale que quelqu'un est entré dans votre pièce.

**Composants requis**

Dans ce projet, nous avons besoin des composants suivants.

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

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Pins disponibles**

* **Pins disponibles**

    Voici une liste des pins disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Pour l'entrée
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Pour la sortie
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::
    
    IO32 ne peut pas être utilisé **comme pin d'entrée** dans ce projet car il est connecté en interne à une résistance de tirage vers le bas de 1K, ce qui fixe sa valeur par défaut à 0.

* **Pins de strapping (Entrée)**

    Les pins de strapping sont un ensemble spécial de pins utilisés pour déterminer des modes de démarrage spécifiques lors de la mise sous tension du dispositif.

    .. list-table::
        :widths: 5 15

        *   - Pins de strapping
            - IO5, IO0, IO2, IO12, IO15 
    

    

    En général, il est **non recommandé de les utiliser comme pins d'entrée**. Si vous souhaitez utiliser ces pins, considérez l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez vous référer à la section :ref:`esp32_strapping`.


**Schéma**

.. image:: ../../img/circuit/circuit_5.5_pir.png

Lorsque le module PIR détecte un mouvement, IO14 sera élevé, et la LED s'allumera. Sinon, lorsqu'aucun mouvement n'est détecté, IO14 sera bas, et la LED s'éteindra.

.. note::
    Le module PIR possède deux potentiomètres : l'un ajuste la sensibilité, l'autre ajuste la distance de détection. Pour améliorer le fonctionnement du module PIR, vous devez tourner les deux complètement dans le sens antihoraire.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**Câblage**

.. image:: ../../img/wiring/5.5_pir_bb.png

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``5.5_pir.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.5_pir``. 
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`  

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b5f0cc8-b732-4ed2-b68e-bb7d0a73a1b8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléversé le code avec succès, la LED s'allumera puis s'éteindra lorsque le module PIR détectera quelqu'un qui passe.

.. note::
    Le module PIR possède deux potentiomètres : l'un ajuste la sensibilité, l'autre ajuste la distance de détection. Pour améliorer le fonctionnement du module PIR, vous devez tourner les deux complètement dans le sens antihoraire.

    .. image:: img/pir_back.png
