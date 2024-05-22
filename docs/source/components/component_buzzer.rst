.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_buzzer:

Zumbador
==========

.. image:: img/buzzer.png
    :width: 600

Como un tipo de zumbador electrónico con una estructura integrada, los zumbadores, que son alimentados por corriente continua, son ampliamente utilizados en computadoras, impresoras, fotocopiadoras, alarmas, juguetes electrónicos, dispositivos electrónicos automotrices, teléfonos, temporizadores y otros productos electrónicos o dispositivos de voz.

Los zumbadores pueden clasificarse como activos y pasivos (ver la siguiente imagen). Gira el zumbador para que sus pines estén hacia arriba, y el zumbador con una placa de circuito verde es un zumbador pasivo, mientras que el que está envuelto con una cinta negra es un zumbador activo.

La diferencia entre un zumbador activo y un zumbador pasivo:

Un zumbador activo tiene una fuente de oscilación incorporada, por lo que emitirá sonidos cuando esté electrificado. Pero un zumbador pasivo no tiene tal fuente, por lo que no emitirá pitidos si se usan señales de corriente continua; en su lugar, necesitas usar ondas cuadradas cuya frecuencia esté entre 2K y 5K para conducirlo. El zumbador activo suele ser más caro que el pasivo debido a los múltiples circuitos oscilantes incorporados.

Lo siguiente es el símbolo eléctrico de un zumbador. Tiene dos pines con polos positivos y negativos. Con un + en la superficie representa el ánodo y el otro es el cátodo.

.. image:: img/buzzer_symbol.png
    :width: 150

Puedes verificar los pines del zumbador, el más largo es el ánodo y el más corto es el cátodo. Por favor, no los mezcles al conectarlos, de lo contrario, el zumbador no emitirá sonido.

`Zumbador - Wikipedia <https://en.wikipedia.org/wiki/Buzzer>`_

**Ejemplo**

* :ref:`ar_ac_buz` (Proyecto Arduino)
* :ref:`ar_pa_buz` (Proyecto Arduino)
* :ref:`ar_reversing_aid` (Proyecto Arduino)
* :ref:`py_pa_buz` (Proyecto MicroPython)
* :ref:`py_ac_buz` (Proyecto MicroPython)
* :ref:`py_reversing_aid` (Proyecto MicroPython)

