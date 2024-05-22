.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_avoid:

Módulo de Evitación de Obstáculos
===========================================


.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Alimentación, 3.3 ~ 5V DC.
* **GND**: Tierra
* **OUT**: Pin de señal, normalmente nivel alto, y nivel bajo cuando se detecta un obstáculo.


El módulo de evitación de obstáculos por infrarrojos tiene una gran adaptabilidad a la luz ambiental, cuenta con un par de tubos emisores y receptores de infrarrojos.

El tubo emisor emite frecuencia infrarroja, cuando la dirección de detección encuentra un obstáculo, la radiación infrarroja es recibida por el tubo receptor, 
después del procesamiento del circuito comparador, el indicador se iluminará y emitirá una señal de nivel bajo.

La distancia de detección se puede ajustar mediante un potenciómetro, el rango de distancia efectiva es de 2 a 30 cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Ejemplo**

* :ref:`ar_ir_obstacle` (Proyecto Arduino)
* :ref:`py_ir_obstacle` (Proyecto MicroPython)
* :ref:`sh_shooting` (Proyecto Scratch)
* :ref:`sh_tap_tile` (Proyecto Scratch)

