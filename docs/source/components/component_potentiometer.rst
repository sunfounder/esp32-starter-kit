.. _cpn_pot:

Potenciómetro
===============

.. image:: img/potentiometer.png
    :align: center
    :width: 150

El potenciómetro es también un componente de resistencia con 3 terminales y su valor de resistencia puede ajustarse según alguna variación regular.

Los potenciómetros vienen en varias formas, tamaños y valores, pero todos tienen las siguientes características en común:

* Tienen tres terminales (o puntos de conexión).
* Tienen un botón, tornillo o deslizador que puede moverse para variar la resistencia entre el terminal central y cualquiera de los terminales exteriores.
* La resistencia entre el terminal central y cualquiera de los terminales exteriores varía desde 0 Ω hasta la resistencia máxima del potenciómetro a medida que se mueve el botón, tornillo o deslizador.

Aquí está el símbolo de circuito del potenciómetro.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400


Las funciones del potenciómetro en el circuito son las siguientes:

#. Servir como divisor de voltaje

    El potenciómetro es un resistor ajustable continuamente. Cuando ajustas el eje o la manija deslizante del potenciómetro, el contacto móvil se deslizará sobre el resistor. En este punto, se puede obtener un voltaje de salida dependiendo del voltaje aplicado al potenciómetro y el ángulo que el brazo móvil ha rotado o el recorrido que ha realizado.

#. Servir como reóstato

    Cuando el potenciómetro se utiliza como un reóstato, conecta el pin central y uno de los otros 2 pines en el circuito. Así puedes obtener un valor de resistencia cambiado suavemente y continuamente dentro del recorrido del contacto móvil.

#. Servir como controlador de corriente

    Cuando el potenciómetro actúa como un controlador de corriente, el terminal de contacto deslizante debe conectarse como uno de los terminales de salida.

Si deseas saber más sobre el potenciómetro, consulta: `Potenciómetro - Wikipedia <https://en.wikipedia.org/wiki/Potentiometer>`_

**Ejemplo**

* :ref:`ar_potentiometer` (Proyecto Arduino)
* :ref:`py_potentiometer` (Proyecto MicroPython)
* :ref:`sh_moving_mouse` (Proyecto Scratch)
* :ref:`sh_breakout_clone` (Proyecto Scratch)
