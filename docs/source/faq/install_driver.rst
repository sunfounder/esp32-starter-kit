.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _install_driver:

Installation manuelle du pilote pour ESP32
==========================================

Si vous avez connecté votre carte ESP32 à votre ordinateur via USB mais que **vous ne voyez aucun port** dans l’IDE Arduino ou Thonny IDE (ou que seul **COM1** apparaît), cela signifie que votre ordinateur n’a pas reconnu la carte.  
Dans ce cas, vous devez installer manuellement le pilote USB.

Nous proposons deux variantes de cartes ESP32, qui ne diffèrent que par leur puce USB-serial :

- **CP2102**
- **CH340**

Fonctionnellement, elles sont identiques : la seule différence réside dans le pilote USB requis.

.. image:: img/driver_ch340_cp2102.jpg
   :width: 400
   :align: center

* Si votre carte ESP32 utilise la puce USB **CH340**, suivez ce guide pour installer le pilote :

  * :ref:`driver_ch340`

* Si elle utilise la puce USB **CP2102**, consultez plutôt ce guide :

  * :ref:`driver_cp2102`


.. _driver_ch340:

Installation du pilote CH340
----------------------------

Dans ce tutoriel, nous vous expliquons comment installer le pilote CH340 sur différents systèmes d’exploitation. Dans de nombreux cas, le pilote est installé automatiquement. Toutefois, selon la version ou la configuration du système, une installation manuelle peut être nécessaire lors de la première connexion d’un appareil CH340.

Pilotes
^^^^^^^

La puce CH340 est fabriquée par WCH. Voici les liens vers les pilotes officiels disponibles sur leur site :

* `Windows (ZIP) <https://www.wch.cn/download/file?id=5>`_ – pilote v3.4 (16/10/2024)  
* `Windows (EXE) <https://www.wch.cn/download/file?id=65>`_ – installateur exécutable  
* `Mac (ZIP) <https://www.wch.cn/download/file?id=178>`_ – pilote v1.5 (26/02/2025)  
* `Linux (ZIP) <https://www.wch.cn/download/file?id=177>`_ – pilote v1.5 (24/10/2024)

Vous pouvez également visiter le site officiel de WCH pour télécharger la dernière version. Au moment de la rédaction, elle est accessible sur cette page en chinois :

* `Téléchargement pilote WCH <https://www.wch.cn/downloads/CH343SER_EXE.html>`_

Si vous utilisez Chrome, vous pouvez demander la traduction automatique de la page.

Voici comment installer le pilote CH340 selon votre système :

Windows 7/11
^^^^^^^^^^^^^

#. Téléchargez le pilote :

   * `Windows (ZIP) <https://www.wch.cn/download/file?id=5>`_ – v3.4 (16/10/2024)  
   * `Windows (EXE) <https://www.wch.cn/download/file?id=65>`_ – installateur

#. Double-cliquez sur le fichier ``.exe``. Si vous avez téléchargé l’archive ZIP, décompressez-la d’abord, puis exécutez l’``.exe``.

#. Cliquez d’abord sur **Désinstaller** pour supprimer d’éventuels anciens pilotes, puis sur **Installer**.

   .. image:: img/driver_ch340_install.png

#. Une fois l’installation terminée, ouvrez le **Gestionnaire de périphériques** (appuyez sur ⊞ Win + R, tapez ``devmgmt.msc`` puis validez).

   .. image:: img/driver_ch340_device.png

#. Développez la section **Ports (COM & LPT)**. Vous devriez voir **USB-SERIAL CH340 (COM##)** s’afficher (le numéro COM peut varier).

   .. image:: img/driver_ch340_com.png

macOS
^^^^^^

#. Téléchargez et décompressez le paquet :

   * `Mac (ZIP) <https://www.wch.cn/download/file?id=178>`_ – v1.5 (26/02/2025)

#. Ouvrez le dossier extrait et double-cliquez sur le fichier ``.pkg`` pour lancer l’installation.

   .. note::

      Sur macOS 10.13 et ultérieur, l’extension système peut être bloquée.  
      Si cela se produit, allez dans **Réglages Système > Confidentialité et sécurité**, puis cliquez sur **Autoriser** à côté de l’extension bloquée.  
      Vous devrez peut-être déverrouiller (icône de cadenas + mot de passe) et redémarrer votre Mac.

   .. image:: img/driver_ch340_install_mac.png
      :width: 500
      :align: center

#. Pour vérifier le bon fonctionnement, branchez le périphérique CH340 et ouvrez le Terminal :

   .. code-block::

      ls /dev/cu*

#. Vous devriez voir apparaître un port comme ``/dev/cu.usbserial*****`` (le nom peut varier).

   .. image:: img/driver_ch340_mac_port.png
      :width: 500
      :align: center

Linux
^^^^^^

#. La plupart des distributions Linux intègrent déjà le pilote CH340. Branchez simplement l’appareil : il devrait être reconnu.

#. Si ce n’est pas le cas, mettez à jour votre système :

   .. code-block::

      sudo apt-get update
      sudo apt-get upgrade

#. Pour une installation manuelle, téléchargez :

   * `Linux (ZIP) <https://www.wch.cn/download/file?id=177>`_ – v1.5 (24/10/2024)

#. Rebranchez votre ESP32 et exécutez :

   .. code-block::

      ls /dev/ttyUSB*

#. Si le pilote fonctionne, vous devriez voir apparaître quelque chose comme :

   .. code-block::

      /dev/ttyUSB0

.. _driver_cp2102:

Comment installer le pilote CH2102 ?
------------------------------------

Ce guide vous expliquera comment installer le pilote USB-série CH2102 sur différents systèmes d’exploitation.  
Dans de nombreux cas, le pilote est automatiquement installé par le système. Cependant, selon la version ou la configuration de votre système, une installation manuelle peut être nécessaire lors de la première connexion d’un appareil CH2102 à votre ordinateur.

Windows
^^^^^^^^^^^^^

#. Rendez-vous sur la page `Silicon Labs USB to UART Bridge VCP Drivers <https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads>`_ et téléchargez le **CP210x_Universal_Windows_Driver**.

#. Extrayez le fichier ZIP, puis faites un clic droit sur le fichier ``.inf`` et sélectionnez **Installer**. Suivez les instructions à l’écran pour terminer l’installation.

   .. image:: img/driver_cp2102_install.png

#. Une fois installé, connectez votre appareil CP2102 à un port USB. Ouvrez le **Gestionnaire de périphériques** (appuyez sur ⊞ Win + R, tapez ``devmgmt.msc`` et appuyez sur Entrée).

#. Développez la section **Ports (COM & LPT)**. Vous devriez voir une entrée du type : ``Silicon Labs CP210x USB to UART Bridge (COM#)``.

   .. image:: img/driver_cp2102_com.png

#. Si le périphérique apparaît sans icône d’avertissement, le pilote a bien été installé et fonctionne correctement.

macOS
^^^^^^^^^^^^

Le pont USB-UART CP2102 est fabriqué par Silicon Labs. Sur les versions récentes de macOS, un support de base peut être intégré, mais pour une compatibilité et une stabilité optimales, il est recommandé d’installer le pilote officiel de Silicon Labs.

#. Rendez-vous sur la page `USB to UART Bridge VCP Drivers <https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads>`_ et téléchargez le **CP210x VCP Mac OSX Driver** adapté à votre système (Apple Silicon ou Intel).

#. Extrayez le fichier ZIP téléchargé, puis double-cliquez sur le fichier ``.dmg`` pour le monter.

#. Dans le volume monté, ouvrez et exécutez **Install CP210x VCP Driver.app**.

#. Suivez les instructions à l’écran pour terminer l’installation.

   .. image:: img/driver_cp2102_mac_install.png
      :width: 500

#. Sur macOS 10.13 ou version ultérieure, le système peut bloquer l’extension du pilote. Si c’est le cas :

   * Allez dans **Réglages système > Sécurité et confidentialité**
   * Cliquez sur **Autoriser** à côté de l’extension Silicon Labs
   * Déverrouillez les réglages si nécessaire (cliquez sur le cadenas et entrez votre mot de passe)
   * Redémarrez votre Mac pour appliquer les modifications

#. Après l’installation, **redémarrez votre Mac** si ce n’est pas déjà fait.

#. Pour vérifier que le pilote est bien installé, ouvrez le Terminal et exécutez :

   .. code-block::

      ls /dev/cu.*

#. Vous devriez voir un appareil semblable à ceci, ce qui indique que le pilote fonctionne :

   .. code-block::

      /dev/cu.SLAB_USBtoUART

Linux
^^^^^^^^^^^^^

#. La plupart des distributions Linux (par exemple Ubuntu, Debian, Fedora) incluent nativement le support du pilote CP2102. Dans la majorité des cas, il suffit de brancher l’appareil pour qu’il soit reconnu.

#. Si l’appareil n’est pas détecté, essayez de mettre à jour votre système :

   .. code-block::

      sudo apt-get update
      sudo apt-get upgrade

#. Après la mise à jour, reconnectez
