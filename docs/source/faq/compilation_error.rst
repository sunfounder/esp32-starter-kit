Alcuni codici di progetto non riescono a compilarsi?
==========================================================

Q1: ``'ledcAttach' non è stato dichiarato in questo ambito``
-----------------------------------------------------------------

Quando si utilizzano LED, LED RGB o buzzer passivi, sarà necessario utilizzare la periferica |link_ledc| della scheda ESP32 per generare segnali PWM. Tuttavia, la scheda ESP32 è stata recentemente aggiornata alla versione 3.0, che ha comportato cambiamenti nei nomi delle funzioni e nel loro utilizzo all'interno della periferica |link_ledc|.

Pertanto, abbiamo aggiornato il nostro codice di conseguenza. Se riscontri problemi relativi a ledc durante la compilazione, ti consigliamo di aggiornare la tua scheda ESP32 alla versione 3.0 o superiore.

.. image:: img/version_3.0.3.png


Q2: Errori nei progetti relativi a Bluetooth e ricevitore IR dopo l'aggiornamento della ESP32 alla versione 3.0?
---------------------------------------------------------------------------------------------------------------------

La scheda ESP32 è stata aggiornata alla versione 3.0, ma le librerie utilizzate nei progetti relativi a Bluetooth e ricevitore IR non sono ancora compatibili con la versione 3.0.

Per eseguire questi progetti, si consiglia di effettuare un downgrade temporaneo della versione ESP32 alla 2.0, specificamente alla versione 2.0.17.

Monitoreremo continuamente gli aggiornamenti di queste librerie e, non appena saranno compatibili con la versione 3.0 della ESP32, aggiorneremo prontamente il nostro codice e la nostra documentazione.

.. image:: img/version_2.0.17.png

