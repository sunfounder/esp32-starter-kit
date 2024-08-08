.. note::

    Bonjour, bienvenue dans la communauté des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder sur Facebook ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_line_track:

5.4 Détection de ligne
===============================

Le module de suivi de ligne est utilisé pour détecter la présence de zones noires sur le sol, telles que des lignes noires collées avec du ruban adhésif électrique.

Son émetteur émet une lumière infrarouge appropriée sur le sol, qui est relativement absorbée et faiblement réfléchie par les surfaces noires. L'inverse est vrai pour les surfaces blanches. Si une lumière réfléchie est détectée, cela indique que le sol est actuellement blanc. Si elle n'est pas détectée, cela indique que le sol est noir.

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
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

**Pins disponibles**

* **Pins disponibles**

    Voici une liste des pins disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Pins disponibles
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Pins de configuration (Entrée)**

    Les pins de configuration sont un ensemble spécial de pins qui sont utilisés pour déterminer des modes de démarrage spécifiques lors du démarrage de l'appareil (c'est-à-dire, réinitialisation à la mise sous tension).

        
    .. list-table::
        :widths: 5 15

        *   - Pins de configuration
            - IO5, IO0, IO2, IO12, IO15 

    En général, il est **déconseillé de les utiliser comme pins d'entrée**. Si vous souhaitez utiliser ces pins, tenez compte de l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez consulter la section :ref:`esp32_strapping`.

**Schéma**

.. image:: ../../img/circuit/circuit_5.4_line.png

Lorsque le module de suivi de ligne détecte une ligne noire, IO14 renvoie un niveau haut. En revanche, lorsqu'il détecte une ligne blanche, IO14 renvoie un niveau bas. Vous pouvez ajuster le potentiomètre bleu pour modifier la sensibilité de détection de ce module.

**Câblage**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``5.4_detect_the_line.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.4_detect_the_line``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fc7f3fe9-179a-4a3a-acbf-a4014faf3920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Réglez le taux de communication série à 115200 bauds.

Si le module de suivi de ligne détecte une ligne noire après le téléchargement réussi du code, "Black" sera affiché dans le moniteur série. Sinon, "White" sera imprimé.
