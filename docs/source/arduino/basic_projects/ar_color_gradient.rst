.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_color_gradient:

6.5 Gradiente di Colore
==============================================
Sei pronto a immergerti in un mondo di colori? Questo progetto ti porterà in un viaggio magico dove potrai controllare un 
LED RGB e ottenere transizioni di colore fluide. Che tu stia cercando di aggiungere un tocco di colore alla tua decorazione domestica o 
desideri un progetto di programmazione divertente, questo progetto ha tutto ciò di cui hai bisogno. Immergiamoci insieme in questo mondo colorato!

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Schema**

.. image:: ../../img/circuit/circuit_6.5_color_gradient_ar.png


**Cablaggio**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

Il LED RGB ha 4 pin: il pin lungo è il catodo comune, che di solito è collegato a GND; il pin a sinistra accanto al pin più lungo è Rosso; e i due pin a destra sono Verde e Blu.

.. image:: ../../img/wiring/6.5_color_rgb_bb.png

**Codice**


.. note::

    * Puoi aprire il file ``6.5_color_gradient.ino`` sotto il percorso ``esp32-starter-kit-main\c\codes\6.5_color_gradient``. 
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * :ref:`unknown_com_port`

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a8402b92-8884-4ba0-b09c-e596e97e0af8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Questo progetto utilizza un LED RGB e un potenziometro per creare un effetto di miscelazione dei colori. Il potenziometro viene utilizzato per regolare il valore di tonalità del LED, che viene poi convertito in valori RGB utilizzando una funzione di conversione del colore. I valori RGB vengono poi utilizzati per aggiornare il colore del LED.

**Come funziona?**

Questo progetto si basa sul progetto :ref:`ar_rgb`, aggiungendo un potenziometro per regolare il valore di tonalità del LED. Il valore di tonalità viene poi convertito in valori RGB utilizzando una funzione di conversione del colore.

#. Nella funzione loop, leggi il valore del potenziometro e convertilo in un valore di tonalità (0-360).

    .. code-block:: arduino

        int knobValue = analogRead(KNOB_PIN);
        float hueValue = (float) knobValue / 4095.0;
        int hue = (int) (hueValue * 360);

#. Converti il valore di tonalità in valori RGB utilizzando la funzione ``HUEtoRGB()``, e aggiorna il LED con i nuovi valori di colore.

    .. code-block:: arduino

        int red, green, blue;
        HUEtoRGB(hue, &red, &green, &blue);
        setColor(red, green, blue);

#. La funzione ``setColor()`` imposta il valore dei canali rosso, verde e blu utilizzando la libreria ``LEDC``.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            ledcWrite(redPin, red);
            ledcWrite(greenPin, green);
            ledcWrite(bluePin, blue);
        }

    
#. La funzione ``HUEtoRGB`` converte un valore di tonalità in valori RGB utilizzando il modello di colore HSL.

    .. code-block:: arduino

        void HUEtoRGB(int hue, int* red, int* green, int* blue) {
            float h = (float) hue / 60.0;
            float c = 1.0;
            float x = c * (1.0 - fabs(fmod(h, 2.0) - 1.0));
            float r, g, b;
            if (h < 1.0) {
                r = c;
                g = x;
                b = 0;
        ...

