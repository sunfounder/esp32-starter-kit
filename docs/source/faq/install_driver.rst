.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _install_driver:

Installation manuelle du pilote pour ESP32
===========================================

Si vous avez connecté votre carte ESP32 à votre ordinateur via USB mais **qu’aucun port n’apparaît** dans l’IDE Arduino ou Thonny (ou si seul **COM1** est visible), cela signifie que votre ordinateur n’a pas reconnu la carte.  
Dans ce cas, vous devrez installer manuellement le pilote USB.

Nous proposons deux types de cartes ESP32, qui diffèrent uniquement par leur puce de conversion USB-série :

- **CP2102**
- **CH340**

Fonctionnellement, elles sont identiques — seule la version du pilote diffère.

.. image:: img/driver_ch340_cp2102.jpg
   :width: 400
   :align: center

* Si votre carte ESP32 utilise la puce **CH340**, suivez ce guide pour installer le pilote :

  * :ref:`driver_ch340`

* Si votre carte ESP32 utilise la puce **CP2102**, suivez plutôt ce guide :

  * :ref:`driver_cp2102`


.. _driver_ch340:

Comment installer le pilote CH340 ?
------------------------------------

Dans ce tutoriel, nous vous expliquons comment installer les pilotes CH340 sur différents systèmes d’exploitation. Pour de nombreux utilisateurs, le pilote s’installe automatiquement. Cependant, selon votre système et ses mises à jour, une installation manuelle peut être nécessaire lors de la première connexion de la puce CH340 à votre ordinateur.

Pilotes
^^^^^^^^^^^^

La puce CH340 est fabriquée par WCH. Voici des liens vers les pilotes pour différents systèmes, depuis le site officiel de WCH :

* `Windows (ZIP) <https://www.wch.cn/download/file?id=5>`_ -- Pilote v3.4 (2024-10-16)
* `Windows (EXE) <https://www.wch.cn/download/file?id=65>`_ -- Installateur exécutable
* `Mac (ZIP) <https://www.wch.cn/download/file?id=178>`_ -- Pilote v1.5 (2025-02-26)
* `Linux (ZIP) <https://www.wch.cn/download/file?id=177>`_ -- Pilote v1.5 (2024-10-24)

Vous pouvez également visiter le site officiel WCH pour télécharger les derniers pilotes. À l’heure actuelle, la dernière version est disponible sur leur page en chinois :

* `Téléchargement des pilotes WCH <https://www.wch.cn/downloads/CH343SER_EXE.html>`_

Si vous utilisez Google Chrome, vous pouvez activer la traduction automatique de la page.

Nous allons maintenant voir comment installer le pilote CH340 selon le système.

Windows 7/11
^^^^^^^^^^^^^^^^^^^^^

#. Téléchargez le pilote.

   * `Windows (ZIP) <https://www.wch.cn/download/file?id=5>`_ -- Pilote v3.4 (2024-10-16)
   * `Windows (EXE) <https://www.wch.cn/download/file?id=65>`_ -- Installateur exécutable

#. Double-cliquez sur le fichier ``.exe``. Si vous avez téléchargé la version ``.zip``, extrayez-la d’abord puis double-cliquez sur le ``.exe`` à l’intérieur.

#. Cliquez d’abord sur "Uninstall" pour supprimer les anciens pilotes, puis cliquez sur "Install".

   .. image:: img/driver_ch340_install.png

#. Après l’installation, ouvrez le **Gestionnaire de périphériques**. Cliquez sur le bouton **Démarrer** ou ⊞ (Windows), tapez "gestionnaire de périphériques" et appuyez sur Entrée.

   .. image:: img/driver_ch340_device.png

#. Dans le gestionnaire, développez la section "Ports (COM & LPT)". Vous devriez voir **USB-SERIAL CH340 (COM##)**. Le numéro COM peut varier.

   .. image:: img/driver_ch340_com.png

macOS
^^^^^^^^^^^^

#. Téléchargez et extrayez le paquet du pilote.

   * `Mac (ZIP) <https://www.wch.cn/download/file?id=178>`_ -- Pilote v1.5 (2025-02-26)

#. Ouvrez le dossier extrait et double-cliquez sur le fichier ``.pkg``. Suivez les instructions pour installer.

   .. note::

      Si un message "Extension système bloquée" ou "Développeur non vérifié" apparaît, allez dans **Réglages système > Confidentialité et sécurité** et cliquez sur **Autoriser** à côté de l’extension bloquée.  
      Vous devrez peut-être déverrouiller les réglages avec votre mot de passe. Redémarrez ensuite votre Mac.

   .. image:: img/driver_ch340_install_mac.png
      :width: 500
      :align: center

#. Pour vérifier que le pilote fonctionne, connectez l’appareil CH340 et ouvrez une fenêtre de Terminal. Exécutez ensuite :

   .. code-block::

      ls /dev/cu*

#. Vous devriez voir un appareil du type ``/dev/cu.usbserial*****``. Le nom exact peut varier.

   .. image:: img/driver_ch340_mac_port.png
      :width: 500
      :align: center

Linux
^^^^^^^^^^^

#. La plupart des distributions Linux incluent déjà le pilote CH340. Il fonctionne automatiquement après branchement. Sinon, mettez à jour votre système :

   .. code-block::

      sudo apt-get update
      sudo apt-get upgrade

#. Vous pouvez aussi télécharger et installer manuellement le pilote CH340 pour Linux :

   * `Linux (ZIP) <https://www.wch.cn/download/file?id=177>`_ -- Pilote v1.5 (2024-10-24)

#. Reconnectez la carte ESP32 à un port USB. Ensuite, exécutez cette commande dans votre terminal :

   .. code-block::

      ls /dev/ttyUSB*

#. Vous devriez voir un résultat du type ``/dev/ttyUSB0``.

.. _driver_cp2102:

Comment installer le pilote CH2102 ?
---------------------------------------

Ce guide vous expliquera comment installer le pilote USB vers série CH2102 sur différents systèmes d’exploitation.  
Dans de nombreux cas, le pilote est installé automatiquement par le système d’exploitation. Toutefois, selon la version ou la configuration de votre système, vous devrez peut-être installer le pilote manuellement lors de la première connexion d’un appareil CH2102 à votre ordinateur.

Windows
^^^^^^^^^^^^^

#. Rendez-vous sur la page `Silicon Labs USB to UART Bridge VCP Drivers <https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads>`_ et téléchargez le **CP210x_Universal_Windows_Driver**.

#. Extrayez le fichier ZIP, puis faites un clic droit sur le fichier ``.inf`` et sélectionnez **Installer**. Suivez les instructions à l’écran pour terminer l’installation du pilote.

   .. image:: img/driver_cp2102_install.png

#. Une fois installé, connectez votre appareil CP2102 à un port USB. Ouvrez le **Gestionnaire de périphériques** (appuyez sur ⊞ Win + R, tapez ``devmgmt.msc`` et appuyez sur Entrée).

#. Développez la section **Ports (COM & LPT)**. Vous devriez voir une entrée comme ``Silicon Labs CP210x USB to UART Bridge (COM#)``.

   .. image:: img/driver_cp2102_com.png

#. Si le périphérique apparaît sans icône d’avertissement, le pilote a été installé avec succès et fonctionne correctement.

macOS
^^^^^^^^^^^^

Le pont USB-vers-UART CP2102 est fabriqué par Silicon Labs. Sur les versions récentes de macOS, le système peut inclure une prise en charge de base, mais pour une compatibilité et une stabilité complètes, il est recommandé d’installer le pilote officiel de Silicon Labs.

#. Rendez-vous sur la page `USB to UART Bridge VCP Drivers <https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads>`_ et téléchargez le **CP210x VCP Mac OSX Driver** correspondant à votre système (Apple Silicon ou Intel).

#. Extrayez le fichier ZIP téléchargé, puis double-cliquez sur le fichier ``.dmg`` pour le monter.

#. Dans le volume monté, ouvrez et exécutez **Install CP210x VCP Driver.app**.

#. Suivez les instructions à l’écran pour terminer l’installation.

   .. image:: img/driver_cp2102_mac_install.png
      :width: 500

#. Sur macOS 10.13 ou version ultérieure, le système peut bloquer l’extension du pilote. Si cela se produit :

   * Allez dans **Réglages système > Confidentialité et sécurité**
   * Cliquez sur **Autoriser** à côté de l’extension Silicon Labs
   * Déverrouillez les réglages si nécessaire (cliquez sur l’icône de cadenas et entrez votre mot de passe)
   * Redémarrez votre Mac pour appliquer les modifications

#. Après l’installation, **redémarrez votre Mac** si ce n’est pas déjà fait.

#. Pour vérifier que le pilote est bien installé, ouvrez le Terminal et exécutez :

   .. code-block::

      ls /dev/cu.*

#. Vous devriez voir un périphérique comme ceci, ce qui indique que le pilote fonctionne correctement :

   .. code-block::

      /dev/cu.SLAB_USBtoUART

Linux
^^^^^^^^^^^^^

#. La plupart des distributions Linux (par exemple, Ubuntu, Debian, Fedora) incluent une prise en charge intégrée du pilote CP2102. Dans la majorité des cas, il suffit de brancher l’appareil pour qu’il soit reconnu automatiquement.

#. Si l’appareil n’est pas reconnu, essayez de mettre à jour votre système :

   .. code-block::

      sudo apt-get update
      sudo apt-get upgrade

#. Après la mise à jour, reconnectez l’appareil CP2102 et exécutez la commande suivante dans un terminal :

   .. code-block::

      ls /dev/ttyUSB*

#. Si le pilote fonctionne correctement, vous devriez voir un périphérique comme :

   .. code-block::

      /dev/ttyUSB0

#. Vous pouvez également vérifier les journaux du noyau pour confirmer la détection :

   .. code-block::

      dmesg | grep ttyUSB
