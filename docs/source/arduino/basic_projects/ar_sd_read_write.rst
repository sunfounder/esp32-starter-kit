.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_sd_write:

7.4 Écriture et Lecture de Carte SD
========================================
Ce projet démontre les capacités essentielles de l'utilisation d'une carte SD avec le microcontrôleur ESP32. 
Il met en avant des opérations essentielles telles que le montage de la carte SD, la création d'un fichier, 
l'écriture de données dans le fichier et la liste de tous les fichiers dans le répertoire racine. Ces opérations forment la base de nombreuses applications de journalisation et de stockage de données, faisant de ce projet une étape cruciale pour comprendre et utiliser le périphérique hôte SDMMC intégré de l'ESP32.

**Composants requis**

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

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|


**Étapes de fonctionnement**

#. Avant de connecter le câble USB, insérez la carte SD dans le slot de carte SD de la carte d'extension.

    .. image:: ../../img/insert_sd.png

#. Connectez l'ESP32 carte à l'ordinateur à l'aide du câble USB.

    .. image:: ../../img/plugin_esp32.png

#. Sélectionnez le port et la carte appropriés dans l'IDE Arduino et téléversez le code sur votre ESP32.

    .. note::

        * Ouvrez le fichier ``7.4_sd_read_write.ino`` sous le chemin ``esp32-starter-kit-main\c\codes\7.4_sd_read_write``.
        * Après avoir sélectionné la carte (ESP32 Dev Module) et le port approprié, cliquez sur le bouton **Téléverser**.
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/912df4b8-a7b6-43dc-95b5-8206801cc9c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Après que le code a été téléversé avec succès, vous verrez une invite indiquant l'écriture réussie du fichier, ainsi qu'une liste de tous les noms de fichiers et tailles sur la carte SD. Si vous ne voyez aucune sortie après avoir ouvert le moniteur série, vous devez appuyer sur le bouton EN (RST) pour relancer le code.

    .. image:: img/sd_write_read.png

    .. note::

        Si vous voyez les informations suivantes.

        .. code-block::

            E (528) vfs_fat_sdmmc: mount_to_vfs failed (0xffffffff).
            Failed to mount SD card

        Vérifiez d'abord si votre carte SD est correctement insérée dans la carte d'extension.

        Si elle est insérée correctement, il pourrait y avoir un problème avec votre carte SD. Vous pouvez essayer d'utiliser une gomme pour nettoyer les contacts métalliques.

        Si le problème persiste, il est recommandé de formater la carte SD, veuillez vous référer à :ref:`format_sd_card`.


**Comment ça marche ?**

Le but de ce projet est de démontrer l'utilisation de la carte SD avec la carte ESP32. Le périphérique hôte SDMMC intégré de l'ESP32 est utilisé pour se connecter à la carte SD.

Le projet commence par initialiser la communication série, puis tente de monter la carte SD. Si la carte SD ne parvient pas à monter correctement, le programme imprimera un message d'erreur et quittera la fonction setup.

Une fois la carte SD montée avec succès, le programme procède à la création d'un fichier nommé "test.txt" dans le répertoire racine de la carte SD. Si le fichier est ouvert avec succès en mode écriture, le programme écrit une ligne de texte - "Hello, world!" dans le fichier. Le programme imprimera un message de succès si l'opération d'écriture est réussie, sinon un message d'erreur sera imprimé.

Après l'opération d'écriture, le programme ferme le fichier puis ouvre le répertoire racine de la carte SD. Il commence ensuite à parcourir tous les fichiers du répertoire racine, en imprimant le nom et la taille de chaque fichier trouvé.

Dans la fonction loop principale, il n'y a pas d'opérations. Ce projet se concentre sur les opérations de carte SD telles que le montage de la carte, la création d'un fichier, l'écriture dans un fichier et la lecture du répertoire, qui sont toutes exécutées dans la fonction setup.

Ce projet sert d'introduction utile à la gestion des cartes SD avec l'ESP32, ce qui peut être crucial dans les applications nécessitant une journalisation ou un stockage de données.


Voici une analyse du code :

#. Inclure la bibliothèque ``SD_MMC``, qui est nécessaire pour travailler avec les cartes SD en utilisant le périphérique hôte SDMMC intégré de l'ESP32.

    .. code-block:: arduino

        #include "SD_MMC.h"

#. Dans la fonction ``setup()``, les tâches suivantes sont effectuées.

    * **Initialiser la carte SD**

    Initialiser et monter la carte SD. Si la carte SD ne parvient pas à monter, elle imprimera "Failed to mount SD card" sur le moniteur série et arrêtera l'exécution.

    .. code-block:: arduino
        
        if(!SD_MMC.begin()) { // Tentative de monter la carte SD
            Serial.println("Failed to mount card"); // Si le montage échoue, imprimer sur le moniteur série et quitter setup
            return;
        } 
      
    * **Ouvrir le fichier**

    Ouvrir un fichier nommé ``"test.txt"`` situé dans le répertoire racine de la carte SD en mode écriture. Si le fichier ne parvient pas à s'ouvrir, il imprime "Failed to open file for writing" et retourne.

    .. code-block:: arduino

        File file = SD_MMC.open("/test.txt", FILE_WRITE); 
        if (!file) {
            Serial.println("Failed to open file for writing"); // Imprimer un message d'erreur si le fichier n'a pas pu s'ouvrir
            return;
        }


    * **Écrire des données dans le fichier**

    Écrire le texte "Test file write" dans le fichier. 
    Si l'opération d'écriture est réussie, elle imprime "File write success"; sinon, elle imprime "File write failed".

    
    .. code-block:: arduino

        if(file.print("Test file write")) { // Écrire le message dans le fichier
            Serial.println("File write success"); // Si l'écriture réussit, imprimer sur le moniteur série
        } else {
            Serial.println("File write failed"); // Si l'écriture échoue, imprimer sur le moniteur série
        } 

    * **Fermer le fichier**
        
    Fermer le fichier ouvert. Cela garantit que toutes les données mises en mémoire tampon sont écrites dans le fichier et que le fichier est correctement fermé.

    .. code-block:: arduino

        file.close(); // Fermer le fichier

    * **Ouvrir le répertoire racine**

    Ouvrir le répertoire racine de la carte SD. Si le répertoire ne parvient pas à s'ouvrir, il imprime "Failed to open directory" et retourne.

    .. code-block:: arduino

        File root = SD_MMC.open("/"); // Ouvrir le répertoire racine de la carte SD
        if (!root) {
            Serial.println("Failed to open directory"); // Imprimer un message d'erreur si le répertoire n'a pas pu s'ouvrir
            return;
        }

    * **Imprimer le nom et la taille de chaque fichier**
    
    La boucle commençant par while (``File file = root.openNextFile()``) parcourt tous les fichiers du répertoire racine, en imprimant le nom et la taille de chaque fichier trouvé sur le moniteur série.

    .. code-block:: arduino
    
        Serial.println("Files found in root directory:"); // Imprimer la liste des fichiers trouvés dans le répertoire racine
        while (File file = root.openNextFile()) { // Parcourir tous les fichiers du répertoire racine
              Serial.print("  ");
              Serial.print(file.name()); // Imprimer le nom du fichier
              Serial.print("\t");
              Serial.println(file.size()); // Imprimer la taille du fichier
              file.close(); // Fermer le fichier
        }

#.  Cette fonction ``loop()`` est une boucle vide et ne fait rien dans le programme actuel. Cependant, dans un programme Arduino typique, cette fonction bouclerait en continu et exécuterait le code à l'intérieur. Dans ce cas, puisque toutes les tâches requises ont été effectuées dans la fonction setup, la fonction loop n'est pas nécessaire.

    .. code-block:: arduino

        void loop() {} // Fonction loop vide, ne fait rien

