.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_soil_moisture:

Módulo de Humedad del Suelo
================================

.. image:: img/soil_mositure.png

* GND: Tierra
* VCC: Suministro de energía, 3.3v~5V
* AOUT: Devuelve el valor de humedad del suelo, cuanto más húmedo esté el suelo, menor será su valor.

Este sensor de humedad del suelo capacitivo difiere de la mayoría de los sensores resistivos en el mercado, utilizando el principio de inducción capacitiva para detectar la humedad del suelo. Evita el problema de que los sensores resistivos sean altamente susceptibles a la corrosión y extiende considerablemente su vida útil.

Está hecho de materiales resistentes a la corrosión y tiene una excelente vida útil. Inscríbelo en el suelo alrededor de las plantas y monitorea datos de humedad del suelo en tiempo real. El módulo incluye un regulador de voltaje incorporado que le permite operar en un rango de voltaje de 3.3 ~ 5.5 V. Es ideal para microcontroladores de baja tensión con suministros de 3.3 V y 5 V.

El esquemático de hardware del sensor de humedad del suelo capacitivo se muestra a continuación.

.. image:: img/solid_schematic.png

Hay un oscilador de frecuencia fija, que está construido con un circuito integrado temporizador 555. La onda cuadrada generada se alimenta luego al sensor como un condensador. Sin embargo, para la señal de onda cuadrada, el condensador tiene cierta reactancia o, para hablar claro, una resistencia con una resistencia ohmica pura (resistencia de 10k en el pin 3) para formar un divisor de voltaje.

Cuanto mayor sea la humedad del suelo, mayor será la capacitancia del sensor. Como resultado, la onda cuadrada tiene menos reactancia, lo que reduce el voltaje en la línea de señal, y menor es el valor de la entrada analógica a través del microcontrolador.


**Especificaciones**

* Voltaje de Operación: 3.3 ~ 5.5 VDC
* Voltaje de Salida: 0 ~ 3.0VDC
* Corriente de Operación: 5mA
* Interfaz: PH2.0-3P
* Dimensiones: 3.86 x 0.905 pulgadas (L x A)
* Peso: 15g

**Ejemplo**

* :ref:`ar_moisture` (Proyecto Arduino)
* :ref:`ar_plant_monitor` (Proyecto Arduino)
* :ref:`py_moisture` (Proyecto MicroPython)
* :ref:`py_plant_monitor` (Proyecto MicroPython)
