.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _sh_breathing_led:

2.2 LED Respirante
========================

Nous allons maintenant utiliser une autre méthode pour contrôler la luminosité de la LED. Contrairement au projet précédent, ici, la luminosité de la LED diminue lentement jusqu'à disparaître.

Lorsque le sprite sur la scène est cliqué, la luminosité de la LED augmente lentement puis s'éteint instantanément.

.. image:: img/3_ap.png

Composants nécessaires
---------------------------

Pour ce projet, nous avons besoin des composants suivants. 

Il est certainement pratique d'acheter un kit complet, voici le lien : 

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

    *   - INTRODUCTION AUX COMPOSANTS
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

Vous apprendrez
---------------------

- Définir la valeur de sortie de la broche PWM
- Créer des variables
- Changer la luminosité du sprite

Construisez le circuit
-----------------------

Ce projet utilise le même circuit que le projet précédent :ref:`sh_table_lamp`, mais au lieu d'utiliser HIGH/LOW pour allumer ou éteindre les LED, ce projet utilise le signal `PWM - Wikipedia <https://en.wikipedia.org/wiki/Pulse-width_modulation>`_ pour allumer lentement ou diminuer la luminosité de la LED.

La plage du signal PWM est de 0 à 255. Sur la carte ESP32, les broches 2, 5, 12~15, 18, 19, 21, 22, 25, 26 et 27 peuvent émettre un signal PWM.

.. image:: img/circuit/1_hello_led_bb.png

Programmation
--------------------

**1. Sélectionner un sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choisir un sprite** dans le coin inférieur droit de la zone des sprites, entrez **button3** dans la zone de recherche, puis cliquez pour l'ajouter.

.. image:: img/3_sprite.png

**2. Créer une variable**

Créez une variable appelée **pwm** pour stocker la valeur de la variation du pwm.

Cliquez sur la palette **Variables** et sélectionnez **Créer une variable**.

.. image:: img/3_ap_va.png

Entrez le nom de la variable, il peut être n'importe quel nom, mais il est recommandé de décrire sa fonction. Le type de données est un nombre et pour tous les sprites.

.. image:: img/3_ap_pwm.png

Une fois créée, vous verrez **pwm** dans la palette **Variables** et dans l'état coché, ce qui signifie que cette variable apparaîtra sur la scène. Vous pouvez essayer de décocher pour voir si pwm est toujours présent sur la scène.

.. image:: img/3_ap_0.png

**3. Définir l'état initial**

Lorsque le sprite **button3** est cliqué, changez le costume en **button-b** (état cliqué), et définissez la valeur initiale de la variable **pwm** à 0.

* [définir pwm à 0] : de la palette **Variables**, utilisé pour définir la valeur de la variable.

.. image:: img/3_ap_brightness.png

**4. Faire augmenter progressivement la luminosité de la LED**

Puisque la plage de pwm est de 255, utilisez le bloc [répéter], la variable **pwm** est accumulée jusqu'à 255 par 5, puis mise dans le bloc [définir la broche PWM], de sorte que vous pouvez voir la LED s'allumer lentement.

* [changer pwm de 5] : de la palette **Variables**, laissez la variable changer d'un nombre spécifique à chaque fois. Il peut s'agir d'un nombre positif ou négatif, positif augmente à chaque fois, négatif diminue à chaque fois, par exemple, ici la variable pwm augmente de 5 à chaque fois.
* [définir la broche PWM] : de la palette **ESP32**, utilisé pour définir la valeur de sortie de la broche pwm.

.. image:: img/3_ap_1.png

Enfin, changez le costume de button3 à **button-a** et définissez la valeur de la broche PWM à 0, afin que la LED s'allume lentement puis s'éteigne à nouveau.

.. image:: img/3_ap_2.png
