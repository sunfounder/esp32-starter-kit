.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_rgb:

2.3 Luce Colorata
==============================================

In questo progetto, esploreremo il mondo affascinante della miscelazione additiva dei colori utilizzando un LED RGB.

Il LED RGB combina tre colori primari, ovvero Rosso, Verde e Blu, in un unico modulo. Questi tre LED condividono un pin di catodo comune, mentre ogni pin di anodo controlla l'intensità del colore corrispondente.

Variando l'intensità del segnale elettrico applicato a ciascun anodo, possiamo creare una vasta gamma di colori. Ad esempio, mescolando luce rossa e verde ad alta intensità otterremo luce gialla, mentre combinando luce blu e verde si otterrà il ciano.

Attraverso questo progetto, esploreremo i principi della miscelazione additiva dei colori e daremo libero sfogo alla nostra creatività manipolando il LED RGB per visualizzare colori accattivanti e vibranti.

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Pin Disponibili**

Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schema**

.. image:: ../../img/circuit/circuit_2.3_rgb.png

I pin PWM pin27, pin26 e pin25 controllano rispettivamente i pin Rosso, Verde e Blu del LED RGB e collegano il pin di catodo comune a GND. Questo consente al LED RGB di visualizzare un colore specifico sovrapponendo la luce su questi pin con diversi valori PWM.


**Collegamento**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

Il LED RGB ha 4 pin: il pin lungo è il pin di catodo comune, che solitamente è collegato a GND; il pin sinistro accanto al pin più lungo è Rosso; e i due pin a destra sono Verde e Blu.

.. image:: ../../img/wiring/2.3_color_light_bb.png


**Codice**

Qui, possiamo scegliere il nostro colore preferito in un software di disegno (come Paint) e visualizzarlo con il LED RGB.

.. note::

    * Puoi aprire il file ``2.3_rgb_led.ino`` nel percorso ``esp32-starter-kit-main\c\codes\2.3_rgb_led``. 
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/49a579a1-ae9b-4e23-b6cd-c20e5695191b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

.. image:: img/edit_colors.png

Scrivi il valore RGB in ``color_set()``, e potrai vedere il LED RGB illuminarsi nei colori desiderati.


**Come funziona?**

#. Definisci i pin GPIO, i canali PWM e la frequenza (in Hz) e la risoluzione (in bit).

    .. code-block:: arduino

        // Definisci i pin del LED RGB
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        // Definisci frequenza PWM e risoluzione
        const int freq = 5000;
        const int resolution = 8;


#. La funzione ``setup()`` inizializza i canali PWM con la frequenza e la risoluzione specificate, e poi associa i pin del LED ai rispettivi canali PWM.

    .. code-block:: arduino

        void setup() {
          // Configura i pin PWM
          ledcAttach(redPin, freq, resolution);
          ledcAttach(greenPin, freq, resolution);
          ledcAttach(bluePin, freq, resolution);
        }
    
    Qui utilizziamo il |link_ledc| (controllo LED) periferico che è progettato principalmente per controllare l'intensità dei LED, sebbene possa essere utilizzato anche per generare segnali PWM per altri scopi.

    * ``bool ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);``: Questa funzione viene utilizzata per configurare il pin LEDC con la frequenza e la risoluzione specificate. Il canale LEDC verrà selezionato automaticamente.

        * ``pin`` seleziona il pin GPIO.
        * ``freq`` seleziona la frequenza del pwm.
        * ``resolution_bits`` seleziona la risoluzione per il canale ledc. L'intervallo è 1-14 bit (1-20 bit per ESP32).


#. La funzione ``loop()`` cicla attraverso vari colori (rosso, verde, blu, giallo, viola e ciano) con intervalli di un secondo tra ogni cambio di colore.

    .. code-block:: arduino

        void loop() {
            setColor(255, 0, 0); // Rosso
            delay(1000);
            setColor(0, 255, 0); // Verde
            delay(1000);
            setColor(0, 0, 255); // Blu
            delay(1000);
            setColor(255, 255, 0); // Giallo
            delay(1000);
            setColor(80, 0, 80); // Viola
            delay(1000);
            setColor(0, 255, 255); // Ciano
            delay(1000);
        }


#. La funzione ``setColor()`` imposta il colore desiderato scrivendo i valori del ciclo di lavoro appropriati su ciascun canale PWM. La funzione prende tre argomenti interi per i valori dei colori rosso, verde e blu.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
          ledcWrite(redPin, red);
          ledcWrite(greenPin, green);
          ledcWrite(bluePin, blue);
        }
    
    * ``bool ledcWrite(uint8_t pin, uint32_t duty);``: Questa funzione viene utilizzata per impostare il duty per il pin LEDC.
        
        * ``pin`` seleziona il pin LEDC.
        * ``duty`` seleziona il duty da impostare per il canale selezionato.
