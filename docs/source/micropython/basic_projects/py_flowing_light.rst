.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_flowing_light:

6.2 Luce Scorrevole
=================================

Hai mai desiderato aggiungere un elemento divertente e interattivo al tuo spazio abitativo? 
Questo progetto prevede la creazione di una luce scorrevole utilizzando una striscia LED WS2812 e un modulo di evitamento ostacoli. 
La luce scorrevole cambia direzione quando viene rilevato un ostacolo, rendendola un'aggiunta entusiasmante all'arredamento della tua casa o del tuo ufficio.

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Kit di Partenza ESP32
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK DI ACQUISTO

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_6.2_flowing_led.png
    :align: center

La striscia LED WS2812 è composta da una serie di LED individuali che possono essere programmati per visualizzare diversi colori e schemi. 
In questo progetto, la striscia è configurata per visualizzare una luce scorrevole che si muove in una direzione specifica e 
cambia direzione quando un ostacolo viene rilevato dal modulo di evitamento ostacoli.


**Cablaggio**

.. image:: ../../img/wiring/6.2_flowing_light_bb.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``6.2_flowing_led.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

    
.. code-block:: python

      from machine import Pin
      import neopixel
      import time
      import random

      # Imposta il numero di pixel per la luce scorrevole
      num_pixels = 8

      # Imposta il pin dati per la striscia LED RGB
      data_pin = Pin(14, Pin.OUT)

      # Inizializza l'oggetto striscia LED RGB
      pixels = neopixel.NeoPixel(data_pin, num_pixels)

      # Inizializza il sensore di evitamento
      avoid = Pin(25, Pin.IN)

      # Inizializza la variabile di direzione
      direction_forward = True

      # Inizializza il flag di direzione inversa
      reverse_direction = False

      # Ciclo continuo della luce scorrevole
      while True:
      
      # Leggi l'input dal sensore a infrarossi
      avoid_value = avoid.value()
      
      # Genera un colore casuale per il pixel corrente
      color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
                  
      # Se non viene rilevato alcun ostacolo
      if avoid_value:
            for i in range(num_pixels):
                  
                  # Accendi il pixel corrente con il colore casuale
                  pixels[i] = color
                  
                  # Aggiorna il display della striscia LED RGB
                  pixels.write()
                  
                  # Spegni il pixel corrente
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)
                  
      # Se viene rilevato un ostacolo, cambia la direzione della striscia LED
      else:
            for i in range(num_pixels-1, -1, -1):
                  
                  pixels[i] = color
                  pixels.write()
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)

I LED sulla striscia RGB si accendono uno per uno quando lo script è in esecuzione. Non appena un oggetto viene posizionato davanti al modulo di evitamento ostacoli, i LED sulla striscia RGB si accendono uno per uno nella direzione opposta.
