.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _format_sd_card:

Comment formater la carte SD ?
====================================

Les étapes pour s'assurer que votre carte SD est correctement formatée peuvent varier en fonction de votre système d'exploitation. Voici des étapes simples pour formater une carte SD sous Windows, MacOS et Linux :

**Windows**

   #. Insérez votre carte SD dans l'ordinateur, puis ouvrez "Ordinateur" ou "Ce PC". Faites un clic droit sur votre carte SD et sélectionnez "Formater".

        .. image:: img/sd_format_win1.png

   #. Dans le menu déroulant du système de fichiers, sélectionnez le système de fichiers souhaité (choisissez généralement FAT32, ou pour les cartes SD de plus de 32 Go, vous devrez peut-être choisir exFAT). Cochez "Formatage rapide" puis cliquez sur "Démarrer".

        .. image:: img/sd_format_win2.png

**MacOS**
   
   #. Insérez votre carte SD dans l'ordinateur. Ouvrez l'application "Utilitaire de disque" (que vous trouverez dans le dossier "Utilitaires").

        .. image:: img/sd_format_mac1.png
    
   #. Sélectionnez votre carte SD dans la liste à gauche, puis cliquez sur "Effacer".

        .. image:: img/sd_format_mac2.png

   #. Dans le menu déroulant du format, choisissez le système de fichiers souhaité (choisissez généralement MS-DOS (FAT) pour FAT32, ou ExFAT pour les cartes SD de plus de 32 Go), puis cliquez sur "Effacer".

        .. image:: img/sd_format_mac3.png

   #. Enfin, attendez que le formatage soit terminé.

        .. image:: img/sd_format_mac3.png

**Linux**

   * Tout d'abord, insérez votre carte SD puis ouvrez un terminal.
   * Tapez ``lsblk`` et trouvez le nom de votre carte SD dans la liste des périphériques (par exemple, il peut s'agir de ``sdb``).
   * Utilisez la commande ``umount`` pour démonter la carte SD, comme ``sudo umount /dev/sdb*``.
   * Utilisez la commande ``mkfs`` pour formater la carte SD. Par exemple, ``sudo mkfs.vfat /dev/sdb1`` formatera la carte SD en système de fichiers FAT32 (pour les cartes SD de plus de 32 Go, vous devrez peut-être utiliser ``mkfs.exfat``).

Avant de formater votre carte SD, assurez-vous de sauvegarder toutes les données importantes sur la carte SD, car l'opération de formatage effacera tous les fichiers sur la carte SD.
