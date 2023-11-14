.. _cpn_audio_speaker:

Audio-Modul und Lautsprecher
===============================

**Audio-Verstärkermodul**

.. image:: img/audio_module.jpg
    :width: 500
    :align: center

Das Audio-Verstärkermodul enthält einen HXJ8002 Audio-Leistungsverstärkerchip. Dieser Chip ist ein Leistungsverstärker mit geringer Stromversorgung, der 3W durchschnittliche Audiokraft für eine 3Ω BTL-Last bei niedriger harmonischer Verzerrung (unter 10% Schwellenverzerrung bei 1 kHz) aus einer 5V Gleichstromquelle liefern kann. Dieser Chip kann Audiosignale ohne jegliche Koppelkondensatoren oder Bootstrap-Kondensatoren verstärken.

Das Modul kann mit einer Gleichstromquelle von 2,0V bis 5,5V und 10mA Betriebsstrom (0,6uA für typischen Standby-Strom) betrieben werden und erzeugt einen leistungsstarken, verstärkten Klang in einem 3Ω, 4Ω oder 8Ω Impedanz-Lautsprecher. Dieses Modul verfügt über verbesserte Knack- und Knall-Schaltkreise, die das Übergangsrauschen beim Ein- und Ausschalten erheblich reduzieren. Die winzige Größe neben hoher Effizienz und geringer Stromversorgung macht es weit verbreitet in tragbaren und batteriebetriebenen Projekten und Mikrocontrollern einsetzbar.

* **IC**: HXJ8002
* **Eingangsspannung**: 2V ~ 5,5V
* **Standby-Modus Strom**: 0,6uA (typischer Wert)
* **Ausgangsleistung**: 3W (3Ω Last), 2,5W (4Ω Last), 1,5W (8Ω Last)
* **Ausgangsimpedanz des Lautsprechers**: 3Ω, 4Ω, 8Ω
* **Größe**: 19,8mm x 14,2mm

**Lautsprecher**

.. image:: img/speaker_pic.png
    :width: 300
    :align: center

* **Größe**: 20x30x7mm
* **Impedanz**: 8ohm
* **Nennleistung**: 1,5W 
* **Maximale Eingangsleistung**: 2,0W
* **Kabellänge**: 10cm

.. image:: img/2030_speaker.png

Die Größentabelle ist wie folgt：

* :download:`Datenblatt des 2030 Lautsprechers <https://github.com/sunfounder/sf-pdf/raw/master/datasheet/2030-speaker-datasheet.pdf>`

**Beispiel**

* :ref:`bluetooth_audio_player` (Arduino-Projekt)
* :ref:`ar_mp3_player_sd` (Arduino-Projekt)
