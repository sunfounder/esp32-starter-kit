.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_owm:

8.1 Meteo in Tempo Reale da @OpenWeatherMap
====================================================

Il progetto IoT Open Weather Display utilizza la scheda ESP32 e un modulo LCD1602 I2C per creare un display di informazioni meteo che recupera i dati dall'API OpenWeatherMap.

Questo progetto rappresenta un'eccellente introduzione al lavoro con le API, alla connettività Wi-Fi e alla visualizzazione dei dati su un modulo LCD utilizzando la scheda ESP32. Con l'IoT Open Weather Display, puoi accedere comodamente agli aggiornamenti meteo in tempo reale con un colpo d'occhio, rendendolo una soluzione ideale per ambienti domestici o lavorativi.

**Componenti Necessari**

In questo progetto, avremo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Kit Iniziale ESP32
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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Ottieni le chiavi API di OpenWeather**

|link_openweather| è un servizio online, di proprietà di OpenWeather Ltd, che fornisce dati meteorologici globali tramite API, inclusi dati meteo attuali, previsioni, nowcast e dati meteorologici storici per qualsiasi località geografica.

#. Visita |link_openweather| per accedere/creare un account.

    .. image:: img/OWM-1.png

#. Clicca sulla pagina delle API dalla barra di navigazione.

    .. image:: img/OWM-2.png

#. Trova **Current Weather Data** e clicca su Subscribe.

    .. image:: img/OWM-3.png

#. Sotto **Current weather and forecasts collection**, iscriviti al servizio appropriato. Nel nostro progetto, la versione gratuita è sufficiente.

    .. image:: img/OWM-4.png

#. Copia la Chiave dalla pagina **API keys**.

    .. image:: img/OWM-5.png


**Completa il Tuo Dispositivo**

#. Assembla il circuito.

    .. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
        :width: 800

#. Apri il codice.

    * Apri il file ``iot_1_open_weather.ino`` situato nella directory ``esp32-starter-kit-main\c\codes\iot_1_open_weather``, oppure copia il codice nell'IDE di Arduino.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriate, clicca sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    * Le librerie ``LiquidCrystal I2C`` e ``Arduino_JSON`` sono utilizzate qui, puoi installarle dal **Library Manager**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/71b196ce-8a84-4577-af76-43988c7d3f80/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
         

#. Individua le seguenti righe e modificale con il tuo ``SSID`` e ``PASSWORD``.

    .. code-block::  Arduino

        // Sostituisci le prossime variabili con la combinazione SSID/Password
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Inserisci le chiavi API che hai copiato in precedenza in ``openWeatherMapApiKey``.

    .. code-block::  Arduino

        // Il tuo nome di dominio con il percorso URL o indirizzo IP con percorso
        String openWeatherMapApiKey = "<openWeatherMapApiKey>";

#. Sostituisci con il codice del tuo paese e città.

    .. code-block::  Arduino

        // Sostituisci con il codice del tuo paese e città
        // Trova il codice del paese su https://openweathermap.org/find
        String city = "CITY";
        String countryCode = "COUNTRY CODE";

#. Dopo l'esecuzione del codice, vedrai l'ora e le informazioni meteorologiche della tua posizione sul display LCD I2C1602.

.. note::
   Quando il codice è in esecuzione, se lo schermo è vuoto, puoi girare il potenziometro sul retro del modulo per aumentare il contrasto.
