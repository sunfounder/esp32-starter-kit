.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _py_line_track:

5.4 Détection de ligne
===================================

Le module de suivi de ligne est utilisé pour détecter la présence de zones noires sur le sol, telles que des lignes noires tracées avec du ruban adhésif électrique.

Son émetteur émet une lumière infrarouge appropriée vers le sol, qui est relativement absorbée et faiblement réfléchie par les surfaces noires. L'inverse est vrai pour les surfaces blanches. Si la lumière réfléchie est détectée, le sol est indiqué comme blanc. Si elle n'est pas détectée, il est indiqué comme noir.

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
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

**Broches disponibles**

* **Broches disponibles**

    Voici une liste des broches disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 20

        *   - Broches disponibles
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Broches de configuration (Entrée)**

    Les broches de configuration sont un ensemble spécial de broches utilisées pour déterminer des modes de démarrage spécifiques lors du démarrage de l'appareil (c'est-à-dire, réinitialisation à la mise sous tension).

        
    .. list-table::
        :widths: 5 15

        *   - Broches de configuration
            - IO5, IO0, IO2, IO12, IO15 
    
    Généralement, il est **non recommandé de les utiliser comme broches d'entrée**. Si vous souhaitez utiliser ces broches, tenez compte de l'impact potentiel sur le processus de démarrage. Pour plus de détails, veuillez vous référer à la section :ref:`esp32_strapping`.

**Schéma**

.. image:: ../../img/circuit/circuit_5.4_line.png

Lorsque le module de suivi de ligne détecte une ligne noire, IO14 renvoie un niveau élevé. En revanche, lorsqu'il détecte une ligne blanche, IO14 renvoie un niveau bas. Vous pouvez ajuster le potentiomètre bleu pour modifier la sensibilité de détection de ce module.


**Câblage**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**Code**

.. note::

    * Ouvrez le fichier ``5.4_detect_the_line.py`` situé dans le chemin ``esp32-starter-kit-main\micropython\codes``, ou copiez et collez le code dans Thonny. Puis cliquez sur "Run Current Script" ou appuyez sur F5 pour l'exécuter.
    * Assurez-vous de sélectionner l'interpréteur "MicroPython (ESP32).COMxx" dans le coin inférieur droit. 


.. code-block:: python

    import machine
    import time

    # Créer un objet pin nommé line, définir le numéro de pin 14 comme entrée
    line = machine.Pin(14, machine.Pin.IN)


    while True:
        # Vérifier si la valeur est 1 (noir)
        if line.value() == 1:
            # Imprimer "noir"
            print("black")
            time.sleep(0.5)
        # Si la valeur n'est pas 1 (c'est 0, ce qui signifie blanc)
        else :
            # Imprimer "blanc"
            print("white")
            time.sleep(0.5)



Lorsque le module de suivi de ligne détecte une ligne noire, "noir" apparaît dans le Shell ; sinon, "blanc" s'affiche.

