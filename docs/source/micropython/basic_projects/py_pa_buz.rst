.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Sei pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _py_pa_buz:

3.2 Tonalità Personalizzata
==========================================

Nel progetto precedente abbiamo utilizzato un buzzer attivo, questa volta utilizzeremo un buzzer passivo.

Come il buzzer attivo, anche il buzzer passivo sfrutta il fenomeno dell'induzione 
elettromagnetica per funzionare. La differenza è che un buzzer passivo non ha una 
sorgente oscillante, quindi non emetterà suoni se vengono utilizzati segnali DC. 
Tuttavia, questo permette al buzzer passivo di regolare la propria frequenza di 
oscillazione ed emettere diverse note come "do, re, mi, fa, sol, la, si".

Facciamo emettere una melodia al buzzer passivo!

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - COMPONENTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTE
        - LINK PER L'ACQUISTO

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Pin Disponibili**

Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

Quando l'uscita di IO14 è alta, dopo il resistore limitatore di corrente da 1K (per proteggere il transistor), l'S8050 (transistor NPN) condurrà, facendo suonare il buzzer.

Il ruolo dell'S8050 (transistor NPN) è di amplificare la corrente e rendere il suono del buzzer più forte. In realtà, puoi anche collegare direttamente il buzzer a IO14, ma noterai che il suono del buzzer sarà più debole.
**Cablaggio**

Nel kit sono inclusi due tipi di buzzer. 
Dobbiamo utilizzare il buzzer attivo. Girateli, quello con il retro sigillato (non il PCB esposto) è quello che ci serve.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

Il buzzer necessita di un transistor per funzionare, qui utilizziamo l'S8050 (Transistor NPN).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Codice**

.. note::

    * Apri il file ``3.2_custom_tone.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.

.. code-block:: python

    import machine
    import time

    # Definisci le frequenze di alcune note musicali in Hz
    C4 = 262
    D4 = 294
    E4 = 330
    F4 = 349
    G4 = 392
    A4 = 440
    B4 = 494

    # Crea un oggetto PWM che rappresenta il pin 14 e assegnalo alla variabile buzzer
    buzzer = machine.PWM(machine.Pin(14))

    # Definisci una funzione tone che prende come input un oggetto Pin che rappresenta il buzzer, una frequenza in Hz e una durata in millisecondi
    def tone(pin, frequency, duration):
        pin.freq(frequency) # Imposta la frequenza
        pin.duty(512) # Imposta il ciclo di lavoro
        time.sleep_ms(duration) # Pausa per la durata in millisecondi
        pin.duty(0) # Imposta il ciclo di lavoro a 0 per interrompere il tono

    # Esegui una sequenza di note con diverse frequenze e durate
    tone(buzzer, C4, 250)
    time.sleep_ms(500)
    tone(buzzer, D4, 250)
    time.sleep_ms(500)
    tone(buzzer, E4, 250)
    time.sleep_ms(500)
    tone(buzzer, F4, 250)
    time.sleep_ms(500)
    tone(buzzer, G4, 250)
    time.sleep_ms(500)
    tone(buzzer, A4, 250)
    time.sleep_ms(500)
    tone(buzzer, B4, 250)

**Come funziona?**

Se al buzzer passivo viene fornito un segnale digitale, esso può solo continuare a spingere il diaframma senza produrre suono.

Per questo motivo, utilizziamo la funzione ``tone()`` per generare il segnale PWM e far suonare il buzzer passivo.

Questa funzione ha tre parametri:

* ``pin``: Il pin che controlla il buzzer.
* ``frequency``: L'intonazione del buzzer è determinata dalla frequenza, maggiore è la frequenza, più alta sarà l'intonazione.
* ``duration``: La durata del tono.

Utilizziamo la funzione ``duty()`` per impostare il ciclo di lavoro a 512 (circa il 50%). Può essere impostato su altri valori, e serve solo a generare un segnale elettrico discontinuo per far oscillare il buzzer.


**Per Saperne di Più**

Possiamo simulare tonalità specifiche e quindi suonare un intero brano musicale.

.. note::

    * Apri il file ``3.2_custom_tone_music.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.

.. code-block:: python

    import machine
    import time

    # Definisci il pin GPIO collegato al buzzer
    buzzer = machine.PWM(machine.Pin(14))

    # Definisci le frequenze delle note in Hz
    C5 = 523
    D5 = 587
    E5 = 659
    F5 = 698
    G5 = 784
    A5 = 880
    B5 = 988

    # Define the durations of the notes in milliseconds
    quarter_note = 250
    half_note = 300
    whole_note = 1000

    # Define the melody as a list of tuples (note, duration)
    melody = [
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (E5, quarter_note),
        (D5, quarter_note),
        (D5, half_note),
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (D5, quarter_note),
        (C5, quarter_note),
        (C5, half_note),

    ]

    # Definisci una funzione per suonare una nota con la frequenza e la durata specificate
    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty(512)
        time.sleep_ms(duration)
        pin.duty(0)

    # Esegui la melodia
    for note in melody:
        tone(buzzer, note[0], note[1])
        time.sleep_ms(50)

* La funzione ``tone`` imposta la frequenza del pin al valore di ``frequency`` utilizzando il metodo ``freq`` dell'oggetto ``pin``.
* Quindi imposta il ciclo di lavoro del pin a 512 utilizzando il metodo ``duty`` dell'oggetto ``pin``.
* Questo farà sì che il pin produca un tono con la frequenza e il volume specificati per la durata di ``duration`` in millisecondi utilizzando il metodo ``sleep_ms`` del modulo time.
* Il codice esegue poi una melodia iterando attraverso una sequenza chiamata ``melodia`` e chiamando la funzione ``tone`` per ciascuna nota della melodia con la frequenza e la durata della nota.
* Viene inoltre inserita una breve pausa di 50 millisecondi tra ogni nota utilizzando il metodo ``sleep_ms`` del modulo time.
