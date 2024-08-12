.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _format_sd_card:

Come formattare la scheda SD?
====================================

I passaggi per garantire che la tua scheda SD sia formattata correttamente possono variare a seconda del sistema operativo. Di seguito sono riportati i semplici passaggi per formattare una scheda SD su Windows, MacOS e Linux:

**Windows**

   #. Inserisci la tua scheda SD nel computer, quindi apri "Risorse del Computer" o "Questo PC". Fai clic con il pulsante destro del mouse sulla tua scheda SD e seleziona "Formatta".

        .. image:: img/sd_format_win1.png

   #. Nel menu a discesa del file system, seleziona il file system desiderato (di solito scegli FAT32, oppure per schede SD superiori a 32GB, potrebbe essere necessario scegliere exFAT). Spunta "Formattazione veloce" e quindi fai clic su "Avvia".

        .. image:: img/sd_format_win2.png

**MacOS**
   
   #. Inserisci la tua scheda SD nel computer. Apri l'applicazione "Utility Disco" (si trova nella cartella "Utility").

        .. image:: img/sd_format_mac1.png
    
   #. Seleziona la tua scheda SD dall'elenco a sinistra e poi clicca su "Inizializza".

        .. image:: img/sd_format_mac2.png

   #. Dal menu a discesa del formato, scegli il file system desiderato (di solito scegli MS-DOS (FAT) per FAT32, oppure ExFAT per schede SD superiori a 32GB) e poi clicca su "Inizializza".

        .. image:: img/sd_format_mac3.png

   #. Infine, attendi il completamento della formattazione.

        .. image:: img/sd_format_mac3.png

**Linux**

   * Innanzitutto, inserisci la tua scheda SD e apri un terminale.
   * Digita ``lsblk`` e trova il nome della tua scheda SD nell'elenco dei dispositivi (ad esempio, potrebbe essere ``sdb``).
   * Utilizza il comando ``umount`` per smontare la scheda SD, come ``sudo umount /dev/sdb*``.
   * Utilizza il comando ``mkfs`` per formattare la scheda SD. Ad esempio, ``sudo mkfs.vfat /dev/sdb1`` formatterà la scheda SD in un file system FAT32 (per schede SD superiori a 32GB, potrebbe essere necessario utilizzare ``mkfs.exfat``).

Prima di formattare la tua scheda SD, assicurati di eseguire il backup di eventuali dati importanti sulla scheda, poiché l'operazione di formattazione cancellerà tutti i file presenti sulla scheda SD.
