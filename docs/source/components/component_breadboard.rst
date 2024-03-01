
.. _cpn_breadboard:

Protoboard
==============

**¿Qué es un protoboard "sin soldadura"?**

.. image:: img/breadboard.png
    :width: 600
    :align: center

Un protoboard es una placa rectangular de plástico con muchos pequeños agujeros. Estos pequeños agujeros te permiten insertar fácilmente componentes electrónicos para construir circuitos. Técnicamente hablando, estos protoboards son conocidos como protoboards sin soldadura porque no requieren soldadura para hacer conexiones.

**Características**

* Tamaño: 163 x 54 x 8 mm
* Protoboard de 830 puntos de conexión: área de circuito integrado de 630 puntos de conexión más 2x100 tiras de distribución de puntos de conexión proporcionando 4 rieles de alimentación.
* Tamaño del cable: Adecuado para cables de 20-29 AWG.
* Material: Panel de plástico ABS, hoja de contacto de bronce fosforado estañado.
* Voltaje / Corriente: 300V/3-5A.
* Con Cinta Adhesiva en la Parte Posterior

**¿Qué hay dentro del protoboard?**

.. image:: img/breadboard_internal.png
    :width: 600
    :align: center

El interior del protoboard está compuesto por filas de pequeños clips metálicos. Cuando insertas los cables de un componente en los agujeros del protoboard, uno de los clips lo sujeta. Algunos protoboards están hechos de plástico transparente, por lo que puedes ver los clips en su interior.

**¿Qué significan las letras y números en un protoboard?**

.. image:: img/breadboard_internal2.png
    :width: 500
    :align: center

La mayoría de los protoboards tienen algunos números, letras y signos más y menos. Aunque las etiquetas variarán de un protoboard a otro, la función es básicamente la misma. Estas etiquetas te permiten encontrar más rápidamente los agujeros correspondientes al construir tu circuito.

Los números de fila y las letras de columna te ayudan a localizar con precisión los agujeros en el protoboard, por ejemplo, el agujero "C12" es donde la columna C se cruza con la fila 12.


**¿Qué significan las líneas de colores y los signos más y menos?**

.. image:: img/breadboard_internal3.png
    :width: 500
    :align: center

Los lados del protoboard suelen estar diferenciados por rojo y azul (u otros colores), así como por los signos más y menos, y suelen utilizarse para conectarse a la fuente de alimentación, conocida como bus de alimentación.

Al construir un circuito, es común conectar el terminal negativo a la columna azul (-) y el terminal positivo a la columna roja (+).


**¿Cómo están conectados los agujeros?**

.. image:: img/breadboard_internal4.png
    :width: 500
    :align: center

Como se muestra en el diagrama, cada conjunto de cinco agujeros en la sección central, columnas A-E o F-J, está eléctricamente conectado. Esto significa, por ejemplo, que el agujero A1 está eléctricamente conectado a los agujeros B1, C1, D1 y E1.

No está conectado al agujero A2 porque ese agujero está en una fila diferente con un conjunto separado de clips metálicos. Tampoco está conectado a los agujeros F1, G1, H1, I1 o J1 porque están ubicados en la otra "mitad" del protoboard; los clips no están conectados a través del espacio central.

A diferencia de la sección central, que está agrupada por cinco agujeros, los buses en los lados están conectados eléctricamente por separado. Por ejemplo, la columna marcada en azul (-) está eléctricamente conectada en su totalidad, y la columna marcada en rojo (+) también está eléctricamente conectada.

**¿Qué partes electrónicas son compatibles con los protoboards?**

.. image:: img/breadboard_pins.jpg
    :width: 600
    :align: center

Muchos componentes electrónicos tienen patas de metal largas llamadas terminales. Casi todos los componentes con terminales funcionarán con un protoboard. Componentes como resistencias, condensadores, interruptores, diodos, etc., se pueden insertar en cualquiera de las filas, pero los IC deben colocarse a través de la brecha central.

