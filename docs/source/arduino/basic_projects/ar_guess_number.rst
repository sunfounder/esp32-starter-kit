.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_guess_number:

6.7 Indovina il Numero
===============================
Ti senti fortunato? Vuoi mettere alla prova la tua intuizione e vedere se riesci a indovinare il numero giusto? Allora il gioco "Indovina il Numero" fa al caso tuo! 

Con questo progetto, puoi giocare a un divertente e appassionante gioco di fortuna.

Utilizzando un telecomando IR, i giocatori inseriscono numeri compresi tra 0 e 99 per cercare di indovinare il numero fortunato generato casualmente. 
Il sistema mostra il numero inserito dal giocatore su uno schermo LCD, insieme a suggerimenti sul limite superiore e inferiore per aiutare 
il giocatore a trovare la risposta giusta. Con ogni tentativo, i giocatori si avvicinano sempre di più al numero fortunato, 
fino a quando finalmente qualcuno colpisce il jackpot e vince il gioco!

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_6.7_guess_number.png

**Cablaggio**

.. image:: ../../img/wiring/6.7_guess_receiver_bb.png
    :width: 800

**Codice**

.. note::

    * Puoi aprire direttamente il file ``6.7_guess_number.ino`` nel percorso ``esp32-starter-kit-main\c\codes\6.7_guess_number``.
    * Le librerie ``LiquidCrystal_I2C`` e ``IRremoteESP8266`` sono utilizzate qui, fai riferimento a :ref:`install_lib_man` per un tutorial sull'installazione.

.. warning::

    Se stai utilizzando una scheda di sviluppo ESP32 versione 3.0.0 o superiore, potresti incontrare errori durante il processo di compilazione.
    Questo problema è generalmente dovuto al fatto che le versioni più recenti della scheda non supportano più la libreria ``IRremoteESP8266``.
    Per eseguire correttamente questo esempio, si consiglia di effettuare il downgrade del firmware della tua scheda ESP32 alla versione 2.0.17. 
    Dopo aver completato questo esempio, aggiorna nuovamente all'ultima versione.

    .. image:: ../../faq/img/version_2.0.17.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e4217f5-c1b7-4859-a34d-d791bbc5e57a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

    
* Dopo che il codice è stato caricato con successo, premi un qualsiasi tasto numerico sul telecomando per avviare il gioco.
* Inserisci un numero utilizzando i tasti numerici sul telecomando. Per inserire una singola cifra, devi premere il tasto **ciclo** per confermare.
* Il sistema mostrerà il numero inserito e i suggerimenti sul limite superiore e inferiore sullo schermo LCD.
* Continua a indovinare finché non indovini correttamente il numero fortunato.
* Dopo un indovinello riuscito, il sistema mostrerà un messaggio di successo e genererà un nuovo numero fortunato.

.. note:: 

    Se il codice e il cablaggio sono corretti, ma l'LCD non visualizza ancora alcun contenuto, puoi regolare il potenziometro sul retro per aumentare il contrasto.


**Come funziona?**

#. Nella funzione ``setup()``, vengono inizializzati lo schermo LCD I2C e il ricevitore IR. Quindi viene chiamata la funzione ``initNewValue()`` per generare un nuovo numero fortunato casuale, e un messaggio di benvenuto viene visualizzato sullo schermo LCD.

    .. code-block:: arduino

        void setup() {
            // Inizializza lo schermo LCD
            lcd.init();
            lcd.backlight();

            // Avvia la comunicazione seriale
            Serial.begin(9600);

            // Abilita il ricevitore IR
            irrecv.enableIRIn();

            // Inizializza un nuovo valore fortunato
            initNewValue();
        }

#. Nella funzione ``loop``, il codice attende un segnale dal ricevitore IR. Quando viene ricevuto un segnale, viene chiamata la funzione ``decodeKeyValue`` per decodificare il segnale e ottenere il valore del pulsante corrispondente.

    .. code-block:: arduino

        void loop() {
        // Se viene ricevuto un segnale dal ricevitore IR
        if (irrecv.decode(&results)) {
            bool result = 0;
            String num = decodeKeyValue(results.value);

            // Se viene premuto il tasto POWER
            if (num == "POWER") {
                initNewValue(); // Inizializza un nuovo valore fortunato
            }

            // Se viene premuto il tasto CYCLE
            else if (num == "CYCLE") {
                result = detectPoint(); // Rileva il numero inserito
                lcdShowInput(result); // Mostra il risultato sullo schermo LCD
            }

            // Se viene premuto un tasto numerico (0-9), 
            //aggiungi la cifra al numero inserito 
            //e rileva il numero se è maggiore o uguale a 10
            else if (num >= "0" && num <= "9") {
                count = count * 10;
                count += num.toInt();
                if (count >= 10) {
                    result = detectPoint();
                }
                lcdShowInput(result);
            }
            irrecv.resume();
        }
        }

    * A seconda del valore del pulsante, viene chiamata la funzione appropriata. Se viene premuto un tasto numerico, la variabile ``count`` viene aggiornata, e viene chiamata la funzione ``detectPoint`` per rilevare se il numero inserito è corretto. La funzione ``lcdShowInput`` viene chiamata per mostrare il numero inserito e i suggerimenti sul limite superiore e inferiore sullo schermo LCD.
    * Se viene premuto il tasto ``POWER``, viene chiamata la funzione ``initNewValue`` per generare un nuovo numero fortunato e mostrare il messaggio di benvenuto sullo schermo LCD.
    * Se viene premuto il tasto ``CYCLE``, viene chiamata la funzione ``detectPoint`` per rilevare se il numero inserito è corretto. La funzione ``lcdShowInput`` viene chiamata per mostrare il numero inserito e i suggerimenti sul limite superiore e inferiore sullo schermo LCD.

