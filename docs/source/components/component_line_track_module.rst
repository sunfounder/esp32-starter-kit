.. _cpn_line_track:

Módulo de Seguimiento de Línea
================================

.. image:: img/line_track.png
    :width: 400
    :align: center

* S: Normalmente nivel bajo, nivel alto cuando se detecta la línea negra.
* V+: Suministro de energía, 3.3V~5V
* G: Tierra

Este es un módulo de seguimiento de línea de 1 canal que, como sugiere el nombre, sigue líneas negras sobre un fondo blanco o líneas blancas sobre un fondo negro.

.. image:: img/tcrt5000.jpg
    :width: 200
    :align: center

El módulo utiliza un sensor infrarrojo TCRT5000, que consta de un LED infrarrojo (azul) y un fototransistor fotosensible (negro).

* El LED infrarrojo azul, cuando se enciende, emite luz infrarroja que es invisible para el ojo humano.
* El fototransistor negro, que se utiliza para recibir luz infrarroja, tiene una resistencia interna cuya resistencia varía con la luz infrarroja recibida; cuanto más luz infrarroja recibe, menor es su resistencia y viceversa.

Hay un comparador LM393 en el módulo, que se utiliza para comparar el voltaje del fototransistor con el voltaje establecido (ajustado por potenciómetro); si es mayor que el voltaje establecido, la salida es 1; de lo contrario, la salida es 0.

Por lo tanto, cuando el tubo emisor infrarrojo brilla sobre una superficie negra, debido a que el negro absorberá la luz, el fototransistor fotosensible recibirá menos luz infrarroja, su resistencia aumentará (aumento de voltaje), después del comparador LM393, la salida será de alto nivel.

De manera similar, cuando brilla sobre una superficie blanca, la luz reflejada será mayor y la resistencia del fototransistor fotosensible disminuirá (disminución de voltaje); por lo tanto, el comparador emite un nivel bajo y el LED indicador se enciende.

* `TCRT5000 <https://www.vishay.com/docs/83760/tcrt5000.pdf>`_

**Características**

* Utiliza el sensor de emisión infrarroja TCRT5000
* Distancia de detección: 1-8mm, distancia focal de 2.5mm
* Señal de salida del comparador limpia, buena forma de onda, capacidad de conducción mayor a 15mA
* Utiliza un potenciómetro para ajuste de sensibilidad
* Voltaje de funcionamiento: 3.3V-5V
* Salida digital: 0 (blanco) y 1 (negro)
* Utiliza un comparador LM393 de voltaje amplio.
* Tamaño: 42mmx10mm

**Ejemplo**

* :ref:`ar_line_track` (Proyecto Arduino)
* :ref:`py_line_track` (Proyecto MicroPython)
* :ref:`sh_protect_heart` (Proyecto Scratch)
