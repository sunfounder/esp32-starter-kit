.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_l293d:

L293D 
=================

L293D es un controlador de motor de 4 canales integrado en un chip con alta tensión y alta corriente. 
Está diseñado para conectarse a lógica estándar DTL, TTL, y para controlar cargas inductivas (como bobinas de relé, motores de CC, motores paso a paso) y transistores de conmutación de potencia, etc. 
Los motores de CC son dispositivos que convierten la energía eléctrica de CC en energía mecánica. Se utilizan ampliamente en accionamientos eléctricos por su excelente rendimiento de regulación de velocidad.

Vea la figura de los pines a continuación. L293D tiene dos pines (Vcc1 y Vcc2) para la fuente de alimentación. 
Vcc2 se utiliza para suministrar energía al motor, mientras que Vcc1 se utiliza para alimentar el chip. Dado que aquí se utiliza un motor de CC de pequeño tamaño, conecte ambos pines a +5V.

.. image:: img/l293d111.png

A continuación se muestra la estructura interna de L293D. 
El pin EN es un pin de habilitación y solo funciona con nivel alto; A representa la entrada y Y la salida. 
Puede ver la relación entre ellos en la esquina inferior derecha. 
Cuando el pin EN está en nivel alto, si A está en alto, Y emite un nivel alto; si A está en bajo, Y emite un nivel bajo. Cuando el pin EN está en nivel bajo, el L293D no funciona.

.. image:: img/l293d334.png

* `Hoja de datos de L293D <https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1627004062301&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D>`_


**Ejemplo**

* :ref:`ar_motor` (Proyecto Arduino)
* :ref:`ar_pump` (Proyecto Arduino)
* :ref:`py_motor` (Proyecto MicroPython)
* :ref:`py_pump` (Proyecto MicroPython)
* :ref:`sh_rotating_fan` (Proyecto Scratch)
