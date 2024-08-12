.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_7_segment:

Display a 7 Segmenti
=========================

.. image:: img/7_segment.png
    :width: 200
    :align: center

Un display a 7 segmenti è un componente a forma di 8 che racchiude 7 LED. Ogni LED è chiamato segmento - quando alimentato, un segmento forma parte di una cifra da visualizzare.

* Ciascuno dei LED nel display è associato a un segmento posizionale con uno dei suoi pin di connessione che fuoriesce dal pacchetto plastico rettangolare.
* Questi pin LED sono etichettati da "a" a "g" e rappresentano ciascun LED individuale.
* Gli altri pin LED sono collegati insieme formando un pin comune.
* Quindi, polarizzando in avanti i pin appropriati dei segmenti LED in un ordine specifico, alcuni segmenti si illumineranno mentre altri rimarranno spenti, mostrando così il carattere corrispondente sul display.

**Caratteristiche**

* Dimensioni: 19 x 12,7 x 13,8 mm (LxPxA, inclusi i pin)
* Schermo: 0,56''
* Colore: rosso
* Catodo comune
* Tensione diretta: 1,8V
* 10 pin
* Passo: standard 0,1" (2,54 mm)

**Catodo Comune (CC) o Anodo Comune (CA)**

Esistono due tipi di connessione dei pin: Catodo Comune (CC) e Anodo Comune (CA).
Come suggerisce il nome, un display CC ha tutti i catodi dei 7 LED collegati, mentre un display CA ha tutti gli anodi dei 7 segmenti collegati.

* Display a 7 Segmenti con Catodo Comune

.. image:: img/segment_cathode.png
    :width: 500

* Display a 7 Segmenti con Anodo Comune

.. image:: img/segment_anode.png
    :width: 500

**Come Riconoscere CC o CA?**

Di solito ci sarà un'etichetta sul lato del display a 7 segmenti, xxxAx o xxxBx. In generale, xxxAx indica un catodo comune e xxxBx indica un anodo comune.

.. image:: img/7_segment.png
    :width: 250

.. image:: img/7_segment_bs.png

Puoi anche utilizzare un multimetro per verificare il display a 7 segmenti se non c'è alcuna etichetta. Imposta il multimetro sulla modalità di test del diodo e collega il cavo nero al pin centrale del display a 7 segmenti e il cavo rosso a qualsiasi altro pin tranne quello centrale. Il display a 7 segmenti è a catodo comune se un segmento si illumina.

Inverti le sonde rosse e nere se non si illumina alcun segmento. Quando un segmento si illumina, ciò indica un anodo comune.

.. image:: img/7_segment_test.JPG
    :width: 600

**Codici di Visualizzazione**

Per aiutarti a capire come i display a 7 segmenti (Catodo Comune) visualizzano i numeri, abbiamo disegnato la seguente tabella.
I numeri rappresentano le cifre da 0 a F visualizzate sul display a 7 segmenti; (DP) GFEDCBA si riferisce ai LED corrispondenti impostati su 0 o 1.

.. image:: img/segment_code.png

Ad esempio, 01011011 significa che DP, F e C sono impostati su 0, mentre gli altri sono impostati su 1. Pertanto, il numero 2 viene visualizzato sul display a 7 segmenti.

.. image:: img/7segment_2.png


**Esempio**

* :ref:`ar_7_segment` (Progetto Arduino)
* :ref:`ar_dice` (Progetto Arduino)
* :ref:`py_7_segment` (Progetto MicroPython)
* :ref:`py_dice` (Progetto MicroPython)

