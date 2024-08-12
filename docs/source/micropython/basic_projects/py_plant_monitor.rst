.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché Unirsi?**

    - **Supporto Esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa ai giveaway e alle promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_plant_monitor:

6.8 Monitor per le Piante
===============================

Benvenuto nel progetto Monitor per le Piante!

In questo progetto utilizzeremo una scheda ESP32 per creare un sistema che ci aiuterà a prenderci cura delle nostre piante. Con questo sistema, potremo monitorare la temperatura, l'umidità, l'umidità del suolo e i livelli di luce delle nostre piante, assicurandoci che ricevano la cura e l'attenzione necessarie per prosperare.

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - OGGETTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schema**

.. image:: ../../img/circuit/circuit_6.8_plant_monitor_l293d.png

Il sistema utilizza un sensore DHT11 per misurare i livelli di temperatura 
e umidità dell'ambiente circostante. 
Nel frattempo, un modulo per l'umidità del suolo viene utilizzato per misurare 
il livello di umidità del suolo e una fotoresistenza viene utilizzata per 
misurare il livello di luce. Le letture di questi sensori vengono visualizzate 
su uno schermo LCD, e una pompa d'acqua può essere controllata tramite un 
pulsante per irrigare la pianta quando necessario.

IO32 ha una resistenza pull-down interna di 1K, e per impostazione predefinita, 
si trova a un livello logico basso. Quando il pulsante viene premuto, stabilisce 
una connessione a VCC (alta tensione), risultando in un livello logico alto su IO32.

**Cablatura**

.. note::

    Si consiglia di inserire la batteria e poi far scorrere l'interruttore sulla scheda di espansione nella posizione ON per attivare l'alimentazione della batteria.

.. image:: ../../img/wiring/6.8_plant_monitor_l293d_bb.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``6.8_plant_monitor.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.

.. code-block:: python

      from machine import ADC, Pin
      import time
      import dht
      from lcd1602 import LCD

      # DHT11
      dht11 = dht.DHT11(Pin(13))

      # Umidità del suolo
      moisture_pin = ADC(Pin(14))
      moisture_pin.atten(ADC.ATTN_11DB)

      # Fotoresistenza
      photoresistor = ADC(Pin(35))
      photoresistor.atten(ADC.ATTN_11DB)

      # Pulsante e pompa
      button = Pin(32, Pin.IN)

      motor1A = Pin(27, Pin.OUT)
      motor2A = Pin(26, Pin.OUT)

      # Configurazione I2C LCD1602
      lcd = LCD()

      # Ruota la pompa
      def rotate():
      motor1A.value(1)
      motor2A.value(0)

      # Ferma la pompa
      def stop():
      motor1A.value(0)
      motor2A.value(0)

      button_state = False

      # Definisci la funzione di callback del pulsante per alternare lo stato del pulsante
      def button_callback(pin):
      global button_state
      button_state = not button_state

      # Collega la funzione di callback del pulsante al fronte di salita del pin del pulsante
      button.irq(trigger=Pin.IRQ_RISING, handler=button_callback)

      page = 0
      temp = 0
      humi = 0
            
      try:
      while True:
            
            # Se il pulsante viene premuto e lo stato del pulsante è True
            if button_state:
                  print("rotate")
                  rotate()

            # Se il pulsante viene premuto di nuovo e lo stato del pulsante è False
            if not button_state:
                  print("stop")
                  stop()
            time.sleep(2)

            # Cancella il display LCD
            lcd.clear()
            
            # Alterna il valore della variabile page tra 0 e 1
            page=(page+1)%2
            
            # Quando page è 1, visualizza temperatura e umidità sul LCD1602
            if page is 1:
                  try:
                  # Misura temperatura e umidità
                  dht11.measure()

                  # Ottieni i valori di temperatura e umidità
                  temp = dht11.temperature()
                  humi = dht11.humidity()
                  except Exception as e:
                  print("Error: ", e)         

                  # Visualizza temperatura e umidità
                  lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
                  lcd.write(0, 1, "Humi: {}%".format(humi))

            # Se page è 0, visualizza l'umidità del suolo e la luce
            else:
                  light = photoresistor.read()
                  moisture = moisture_pin.read()

                  # Cancella il display LCD
                  lcd.clear()

                  # Visualizza il valore di umidità del suolo e luce
                  lcd.write(0, 0, f"Moisture: {moisture}")
                  lcd.write(0, 1, f"Light: {light}")

      except KeyboardInterrupt:
      # Ferma il motore quando viene catturato un KeyboardInterrupt
      stop()

* Quando il codice è in esecuzione, l'I2C LCD1602 visualizza alternativamente temperatura e umidità, così come i valori analogici di umidità del suolo e intensità della luce, con un intervallo di 2 secondi.
* Premi il pulsante per avviare la pompa dell'acqua e premilo di nuovo per fermarla.

.. note:: 

    Se il codice e la cablatura sono corretti, ma l'LCD non riesce ancora a visualizzare alcun contenuto, puoi regolare il potenziometro sul retro per aumentare il contrasto.

