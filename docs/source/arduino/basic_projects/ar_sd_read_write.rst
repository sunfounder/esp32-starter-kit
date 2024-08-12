.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_sd_write:

7.4 Scrittura e Lettura su SD Card
========================================

Questo progetto dimostra le capacità fondamentali dell'utilizzo di una scheda SD con il microcontrollore ESP32. 
Mostra operazioni essenziali come il montaggio della scheda SD, la creazione di un file, la scrittura di dati nel file 
e l'elenco di tutti i file presenti nella directory radice. Queste operazioni costituiscono la base di molte applicazioni di registrazione e archiviazione dati, rendendo questo progetto un passaggio cruciale per comprendere e utilizzare la periferica SDMMC integrata nell'ESP32.

**Componenti Necessari**

In questo progetto, avremo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|


**Passaggi Operativi**

#. Prima di collegare il cavo USB, inserisci la scheda SD nello slot della scheda SD della scheda di espansione.

    .. image:: ../../img/insert_sd.png

#. Collega l'ESP32-WROOM-32E al computer utilizzando il cavo USB.

    .. image:: ../../img/plugin_esp32.png

#. Seleziona la porta e la scheda appropriate nell'IDE di Arduino e carica il codice sul tuo ESP32.

    .. note::

        * Apri il file ``7.4_sd_read_write.ino`` nel percorso ``esp32-starter-kit-main\c\codes\7.4_sd_read_write``.
        * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/912df4b8-a7b6-43dc-95b5-8206801cc9c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Dopo che il codice è stato caricato correttamente, vedrai un messaggio che indica la scrittura del file avvenuta con successo, insieme a un elenco di tutti i nomi dei file e delle dimensioni sulla scheda SD. Se non vedi alcuna stampa dopo aver aperto il monitor seriale, devi premere il pulsante EN (RST) per rieseguire il codice.

    .. image:: img/sd_write_read.png

    .. note::

        Se visualizzi le seguenti informazioni.

        .. code-block::

            E (528) vfs_fat_sdmmc: mount_to_vfs failed (0xffffffff).
            Failed to mount SD card

        Prima, verifica se la tua scheda SD è inserita correttamente nella scheda di espansione.

        Se è inserita correttamente, potrebbe esserci un problema con la tua scheda SD. Puoi provare a pulire i contatti metallici con una gomma.

        Se il problema persiste, si consiglia di formattare la scheda SD, consulta :ref:`format_sd_card`.


**Come funziona?**

Lo scopo di questo progetto è dimostrare l'utilizzo della scheda SD con la scheda ESP32. La periferica SDMMC integrata nell'ESP32 viene utilizzata per collegarsi alla scheda SD.

Il progetto inizia inizializzando la comunicazione seriale e poi tenta di montare la scheda SD. Se la scheda SD non viene montata correttamente, il programma stamperà un messaggio di errore e uscirà dalla funzione setup.

Una volta che la scheda SD è stata montata con successo, il programma procede a creare un file chiamato "test.txt" nella directory radice della scheda SD. Se il file viene aperto con successo in modalità scrittura, il programma scrive una riga di testo - "Hello, world!" nel file. Il programma stamperà un messaggio di successo se l'operazione di scrittura riesce, altrimenti verrà stampato un messaggio di errore.

Dopo che l'operazione di scrittura è completa, il programma chiude il file e poi apre la directory radice della scheda SD. Quindi inizia a scorrere tutti i file nella directory radice, stampando il nome del file e la dimensione di ciascun file trovato.

Nella funzione loop principale, non ci sono operazioni. Questo progetto si concentra sulle operazioni della scheda SD come il montaggio della scheda, la creazione di un file, la scrittura di un file e la lettura della directory dei file, tutte eseguite nella funzione setup.

Questo progetto è un'introduzione utile alla gestione delle schede SD con l'ESP32, che può essere cruciale nelle applicazioni che richiedono la registrazione o l'archiviazione dei dati.


Ecco un'analisi del codice:

#. Includere la libreria ``SD_MMC``, necessaria per lavorare con le schede SD utilizzando la periferica SDMMC integrata dell'ESP32.

    .. code-block:: arduino

        #include "SD_MMC.h"

#. All'interno della funzione ``setup()``, vengono eseguite le seguenti operazioni.

    * **Inizializza la scheda SD**

    Inizializza e monta la scheda SD. Se la scheda SD non riesce a montarsi, stamperà "Failed to mount SD card" sul monitor seriale e interromperà l'esecuzione.

    .. code-block:: arduino
        
        if(!SD_MMC.begin()) { // Tentativo di montare la scheda SD
            Serial.println("Failed to mount card"); // Se il montaggio fallisce, stampa sul seriale ed esce dal setup
            return;
        } 
      
    * **Apri il file**

    Apri un file chiamato ``"test.txt"`` situato nella directory radice della scheda SD in modalità scrittura. Se il file non riesce ad aprirsi, stampa "Failed to open file for writing" e ritorna.

    .. code-block:: arduino

        File file = SD_MMC.open("/test.txt", FILE_WRITE); 
        if (!file) {
            Serial.println("Failed to open file for writing"); // Stampa il messaggio di errore se il file non riesce ad aprirsi
            return;
        }


    * **Scrivere dati nel file**

    Scrivi il testo "Test file write" nel file. 
    Se l'operazione di scrittura riesce, stampa "File write successful"; altrimenti, stampa "File write failed".

    
    .. code-block:: arduino

        if(file.print("Test file write")) { // Scrivi il messaggio nel file
            Serial.println("File write success"); // Se la scrittura riesce, stampa sul seriale
        } else {
            Serial.println("File write failed"); // Se la scrittura fallisce, stampa sul seriale
        } 

    * **Chiudi il file**
        
    Chiudi il file aperto. Questo assicura che i dati bufferizzati siano scritti nel file e che il file sia chiuso correttamente.

    .. code-block:: arduino

        file.close(); // Chiudi il file

    * **Apri la directory radice**

    Apri la directory radice della scheda SD. Se la directory non riesce ad aprirsi, stampa "Failed to open directory" e ritorna.

    .. code-block:: arduino

        File root = SD_MMC.open("/"); // Apri la directory radice della scheda SD
        if (!root) {
            Serial.println("Failed to open directory"); // Stampa il messaggio di errore se la directory non riesce ad aprirsi
            return;
        }

    * **Stampa il nome e la dimensione di ciascun file**
    
    Il ciclo che inizia con while (``File file = root.openNextFile()``) itera su tutti i file nella directory radice, 
    stampando il nome e la dimensione di ciascun file sul monitor seriale.

    .. code-block:: arduino
    
        Serial.println("Files found in root directory:"); // Stampa l'elenco dei file trovati nella directory radice
        while (File file = root.openNextFile()) { // Ciclo su tutti i file nella directory radice
              Serial.print("  ");
              Serial.print(file.name()); // Stampa il nome del file
              Serial.print("\t");
              Serial.println(file.size()); // Stampa la dimensione del file
              file.close(); // Chiudi il file
        }

#.  Questa funzione ``loop()`` è un ciclo vuoto e non fa nulla nel programma attuale. Tuttavia, in un tipico programma Arduino, questa funzione ciclerebbe continuamente ed eseguirebbe il codice al suo interno. In questo caso, poiché tutte le operazioni richieste sono state eseguite nella funzione setup, la funzione loop non è necessaria.

    .. code-block:: arduino

        void loop() {} // Funzione loop vuota, non fa nulla

