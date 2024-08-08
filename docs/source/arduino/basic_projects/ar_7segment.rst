.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_7_segment:

2.5 Afficheur 7 Segments
===================================

Bienvenue dans ce projet fascinant ! Dans ce projet, nous explorerons le monde enchanteur de l'affichage des chiffres de 0 à 9 sur un afficheur à sept segments.

Imaginez déclencher ce projet et voir un petit écran compact briller de mille feux avec chaque chiffre de 0 à 9. C'est comme avoir un écran miniature qui affiche les chiffres de manière captivante. En contrôlant les broches de signal, vous pouvez changer facilement le chiffre affiché et créer divers effets engageants.

Grâce à des connexions de circuit simples et à la programmation, vous apprendrez à interagir avec l'afficheur à sept segments et à donner vie aux chiffres souhaités. Que ce soit un compteur, une horloge ou toute autre application intrigante, l'afficheur à sept segments sera votre compagnon fiable, ajoutant une touche de brillance à vos projets.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Broches disponibles**

Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

.. list-table::
    :widths: 5 20 

    * - Broches disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schéma**

.. image:: ../../img/circuit/circuit_2.5_74hc595_7_segment.png

Le principe de câblage est essentiellement le même que celui de :ref:`ar_74hc595`, la seule différence est que Q0-Q7 sont connectés aux broches a ~ g de l'afficheur 7 segments.

.. list-table:: Câblage
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - Afficheur à segments LED
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**Câblage**

.. image:: ../../img/wiring/2.5_segment_bb.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``2.5_7segment.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\2.5_7segment``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/937f5e3f-2d9e-4c75-8331-ace3c0876182/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code avec succès, vous verrez l'afficheur à segments LED afficher 0~9 en séquence.

**Comment ça marche ?**

Dans ce projet, nous utilisons la fonction ``shiftOut()`` pour écrire le nombre binaire dans le registre à décalage. 

Supposons que l'afficheur 7 segments affiche le chiffre "2". Ce modèle binaire correspond aux segments **f**, **c** et **dp** étant éteints (bas), tandis que les segments **a**, **b**, **d**, **e** et **g** sont allumés (haut). Cela correspond à "01011011" en binaire et "0x5b" en notation hexadécimale. 

Par conséquent, vous devez appeler ``shiftOut(DS, SHcp, MSBFIRST, 0x5b)
```` pour afficher le chiffre "2" sur l'afficheur 7 segments.

.. image:: img/7_segment2.png

* `Hexadecimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `BinaryHex Converter <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

Le tableau suivant montre les modèles hexadécimaux à écrire dans le registre à décalage pour afficher les chiffres de 0 à 9 sur un afficheur 7 segments.


.. list-table:: Glyph Code
    :widths: 20 20 20
    :header-rows: 1

    *   - Chiffres	
        - Code binaire
        - Code hexadécimal  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Écrivez ces codes dans ``shiftOut()`` pour que l'afficheur à segments LED affiche les chiffres correspondants.
