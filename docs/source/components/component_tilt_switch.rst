.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_tilt:

Interruttore a inclinazione
=================================

.. image:: img/tilt_switch.png
    :width: 80
    :align: center

L'interruttore a inclinazione utilizzato qui è di tipo a sfera con una pallina metallica all'interno. È impiegato per rilevare inclinazioni di piccoli angoli.

Il principio è molto semplice. Quando l'interruttore viene inclinato a un certo angolo, la pallina all'interno rotola e tocca i due contatti collegati ai pin esterni, chiudendo così il circuito. Altrimenti, la pallina rimarrà lontana dai contatti, interrompendo il circuito.

.. image:: img/tilt_symbol.png
    :width: 600

* `SW520D Tilt Switch Datasheet <https://www.tme.com/Document/f1e6cedd8cb7feeb250b353b6213ec6c/SW-520D.pdf>`_


**Esempio**

* :ref:`ar_tilt` (Progetto Arduino)
* :ref:`py_tilt` (Progetto MicroPython)

