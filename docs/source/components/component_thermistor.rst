.. _cpn_thermistor:

Termistor
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Un termistor es un tipo de resistor cuya resistencia depende fuertemente de la temperatura, más que en los resistores estándar. La palabra es una combinación de térmico y resistor. Los termistores se utilizan ampliamente como limitadores de corriente de arranque, sensores de temperatura (generalmente de coeficiente de temperatura negativo o NTC), protectores de sobrecorriente autorreajustables y elementos calefactores autorregulados (generalmente de coeficiente de temperatura positivo o PTC).

* `Termistor - Wikipedia <https://es.wikipedia.org/wiki/Termistor>`_

Aquí está el símbolo electrónico del termistor.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

Los termistores son de dos tipos fundamentales opuestos:

* Con los termistores NTC, la resistencia disminuye a medida que aumenta la temperatura, generalmente debido a un aumento de los electrones de conducción estimulados por la agitación térmica desde la banda de valencia. Un NTC se utiliza comúnmente como sensor de temperatura o en serie con un circuito como limitador de corriente de arranque.
* Con los termistores PTC, la resistencia aumenta a medida que aumenta la temperatura, generalmente debido al aumento de las agitaciones térmicas de la red, especialmente las de impurezas e imperfecciones. Los termistores PTC se instalan comúnmente en serie con un circuito y se utilizan para proteger contra condiciones de sobrecorriente, como fusibles rearmables.

En este kit usamos uno NTC. Cada termistor tiene una resistencia normal. Aquí es de 10k ohmios, que se mide a 25 grados Celsius.

Aquí está la relación entre la resistencia y la temperatura:

    RT = RN * expB(1/TK - 1/TN)   

* **RT** es la resistencia del termistor NTC cuando la temperatura es TK. 
* **RN** es la resistencia del termistor NTC bajo la temperatura nominal TN. Aquí, el valor numérico de RN es 10k.
* **TK** es una temperatura en Kelvin y la unidad es K. Aquí, el valor numérico de TK es 273.15 + grados Celsius.
* **TN** es una temperatura nominal en Kelvin; la unidad es también K. Aquí, el valor numérico de TN es 273.15+25.
* Y **B (beta)**, la constante de material del termistor NTC, también se llama índice de sensibilidad al calor con un valor numérico de 3950.      
* **exp** es la abreviatura de exponencial, y el número base e es un número natural y es aproximadamente igual a 2.7.  

Convertir esta fórmula TK=1/(ln(RT/RN)/B+1/TN) para obtener la temperatura en Kelvin que menos 273.15 es igual a grados Celsius.

Esta relación es una fórmula empírica. Es precisa solo cuando la temperatura y la resistencia están dentro del rango efectivo.

**Ejemplo**

* :ref:`ar_thermistor` (Proyecto Arduino)
* :ref:`ar_iot_mqtt` (Proyecto Arduino)
* :ref:`py_thermistor` (Proyecto MicroPython)
* :ref:`sh_low_temperature` (Proyecto Scratch)

