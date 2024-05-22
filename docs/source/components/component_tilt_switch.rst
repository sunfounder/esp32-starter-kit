.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_tilt:

Interruptor de Inclinación
=============================


.. image:: img/tilt_switch.png
    :width: 80
    :align: center

El interruptor de inclinación utilizado aquí es una bola con un interruptor de contacto en su interior. Se utiliza para detectar inclinaciones de ángulos pequeños.

El principio es muy simple. Cuando el interruptor se inclina en un cierto ángulo, la bola en su interior rueda hacia abajo y toca los dos contactos conectados a los pines exteriores, activando así los circuitos. De lo contrario, la bola se mantendrá alejada de los contactos, interrumpiendo así los circuitos.

.. image:: img/tilt_symbol.png
    :width: 600

* `Hoja de datos del interruptor de inclinación SW520D <https://www.tme.com/Document/f1e6cedd8cb7feeb250b353b6213ec6c/SW-520D.pdf>`_

**Ejemplo**

* :ref:`ar_tilt` (Proyecto Arduino)
* :ref:`py_tilt` (Proyecto MicroPython)
