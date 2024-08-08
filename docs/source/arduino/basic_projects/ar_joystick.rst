.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_joystick:

5.11 Utiliser le Joystick
================================
Si vous jouez beaucoup aux jeux vidéo, alors vous devriez être très familier 
avec le Joystick. Il est généralement utilisé pour déplacer le personnage, 
faire pivoter l'écran, etc.

Le principe qui permet au Joystick de transmettre nos actions à l'ordinateur est 
très simple. Il peut être considéré comme constitué de deux potentiomètres perpendiculaires 
l'un à l'autre. Ces deux potentiomètres mesurent la valeur analogique du joystick 
verticalement et horizontalement, résultant en une valeur (x,y) dans un système de 
coordonnées cartésiennes.

Le joystick de ce kit possède également une entrée numérique, activée lorsque le joystick 
est pressé.

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants.

Il est très pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage ESP32
        - 320+
        - |link_esp32_starter_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION AUX COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Pour entrée analogique
            - IO14, IO25, I35, I34, I39, I36
        *   - Pour entrée numérique
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
            
**Schéma**

.. image:: ../../img/circuit/circuit_5.11_joystick.png

La broche SW (axe Z) est connectée à IO33, qui possède une résistance pull-up intégrée de 4.7K. Par conséquent, lorsque le bouton SW n'est pas pressé, il produira un niveau haut. Lorsqu'il est pressé, il produira un niveau bas.

I34 et I35 changeront leurs valeurs au fur et à mesure que vous manipulez le joystick. La plage des valeurs est de 0 à 4095.

**Câblage**

.. image:: ../../img/wiring/5.11_joystick_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.11_joystick.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.11_joystick``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a2065d70-d207-4e51-b03e-ffd2a26597ef/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Ouvrez le moniteur série après le téléchargement réussi du code pour voir les valeurs x,y,z du joystick.

N'oubliez pas de régler le taux de communication série à 115200 bauds.

* Les valeurs de l'axe x et de l'axe y sont des valeurs analogiques variant de 0 à 4095.
* L'axe Z est une valeur numérique avec un statut de 1 ou 0 (lorsqu'il est pressé, il est à 0).
