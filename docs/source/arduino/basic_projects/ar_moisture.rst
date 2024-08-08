.. note::

    Bonjour, bienvenue dans la communauté des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder sur Facebook ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_moisture:

5.9 Mesurer l'humidité du sol
====================================
Ce capteur d'humidité du sol capacitif est différent de la plupart des capteurs résistifs du marché, utilisant le principe de l'induction capacitive pour détecter l'humidité du sol.

En lisant visuellement les valeurs du capteur d'humidité du sol, nous pouvons recueillir des informations sur le niveau d'humidité du sol. Ces informations sont utiles pour diverses applications, telles que les systèmes d'irrigation automatique, la surveillance de la santé des plantes ou les projets de détection environnementale.

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Pins disponibles**

* **Pins disponibles**

    Voici une liste des pins disponibles sur la carte ESP32 pour ce projet.

    .. list-table::
        :widths: 5 15

        *   - Pins disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Pins de configuration**

    Les pins suivantes sont des pins de configuration, qui affectent le processus de démarrage de l'ESP32 lors de la mise sous tension ou de la réinitialisation. Cependant, une fois que l'ESP32 est démarré avec succès, elles peuvent être utilisées comme des pins régulières.

    .. list-table::
        :widths: 5 15

        *   - Pins de configuration
            - IO0, IO12

**Schéma**

.. image:: ../../img/circuit/circuit_5.9_soil_moisture.png

En insérant le module dans le sol et en l'arrosant, la valeur lue sur I35 diminuera.

**Câblage**

.. image:: ../../img/wiring/5.9_moisture_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.9_moisture.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\5.9_moisture``.
    * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Upload**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/431302c2-3579-4be6-8142-c91d28757004/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
N'oubliez pas de régler le taux de communication série à 115200 bauds.

Une fois le code téléchargé avec succès, le moniteur série affichera la valeur de l'humidité du sol.

En insérant le module dans le sol et en l'arrosant, la valeur du capteur d'humidité du sol deviendra plus petite.
