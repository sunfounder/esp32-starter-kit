.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_potentiometer:

5.8 Regola la Manopola
============================

Un potenziometro è un dispositivo a tre terminali comunemente utilizzato per regolare la resistenza in un circuito. Dispone di una manopola o di una leva scorrevole che può essere utilizzata per variare il valore di resistenza del potenziometro. In questo progetto, lo utilizzeremo per controllare la luminosità di un LED, simile a una lampada da scrivania nella nostra vita quotidiana. Regolando la posizione del potenziometro, possiamo cambiare la resistenza nel circuito, regolando così la corrente che scorre attraverso il LED e adattandone la luminosità di conseguenza. Questo ci permette di creare un'esperienza di illuminazione personalizzabile e regolabile, simile a quella di una lampada da scrivania.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 15

        *   - Pin Disponibili
            - IO14, IO25, I35, I34, I39, I36

* **Pin Strapping**

    I seguenti pin sono pin di strapping, che influenzano il processo di avvio dell'ESP32 durante l'accensione o il reset. Tuttavia, una volta che l'ESP32 è avviato correttamente, possono essere utilizzati come pin normali.

    .. list-table::
        :widths: 5 15

        *   - Pin Strapping
            - IO0, IO12

**Schema**

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

Ruotando il potenziometro, il valore di I35 cambierà. Attraverso la programmazione, puoi utilizzare il valore di I35 per controllare la luminosità del LED. Pertanto, ruotando il potenziometro, la luminosità del LED cambierà di conseguenza.

**Collegamento**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**Codice**

.. note::

    * Puoi aprire il file ``5.8_pot.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.8_pot``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`

.. raw:: html
     
    <iframe src=https://create.arduino.cc/editor/sunfounder01/aadce2e7-fd5d-4608-a557-f1e4d07ba795/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo che il codice è stato caricato con successo, ruota il potenziometro e vedrai la luminosità del LED cambiare di conseguenza. Allo stesso tempo, puoi vedere i valori analogici e di tensione del potenziometro nel monitor seriale.

**Come funziona?**

#. Definisci le costanti per le connessioni dei pin e le impostazioni PWM.

    .. code-block:: arduino

        const int potPin = 35; // Potenziometro collegato a
        const int ledPin = 26; // LED collegato a

        // Impostazioni PWM
        const int freq = 5000; // Frequenza PWM
        const int resolution = 12; // Risoluzione PWM (bit)

    Qui la risoluzione PWM è impostata a 12 bit e l'intervallo è 0-4095.

#. Configura il sistema nella funzione ``setup()``.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);

            // Configura PWM
            ledcAttach(ledPin, freq, resolution);
        }

    * Nella funzione ``setup()``, la comunicazione seriale viene avviata a una velocità di 115200 baud.
    * La funzione ``ledcAttach()`` viene chiamata per configurare il pin LED specificato con la frequenza e la risoluzione specificate.

#. Loop principale (eseguito ripetutamente) nella funzione ``loop()``.

    .. code-block:: arduino

        void loop() {

            int potValue = analogRead(potPin); // leggi il valore del potenziometro
            uint32_t voltage_mV = analogReadMilliVolts(potPin); // Leggi la tensione in millivolt
            
            ledcWrite(ledPin, potValue);
            
            Serial.print("Potentiometer Value: ");
            Serial.print(potValue);
            Serial.print(", Voltage: ");
            Serial.print(voltage_mV / 1000.0); // Convert millivolts to volts
            Serial.println(" V");
            
            delay(100);
        }

    * ``uint32_t analogReadMilliVolts(uint8_t pin);``: Questa funzione viene utilizzata per ottenere il valore ADC per un determinato pin/canale ADC in millivolt.

        * ``pin`` seleziona il pin GPIO per leggere il valore analogico.

    Il valore del potenziometro viene utilizzato direttamente come ciclo di lavoro PWM per controllare la luminosità del LED tramite la funzione ``ledcWrite()``, poiché l'intervallo di valori è anch'esso compreso tra 0 e 4095.

