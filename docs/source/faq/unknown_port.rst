.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _unknown_com_port:

¿Siempre aparece "COMxx desconocido"?
=========================================

Cuando conectas el ESP32 al ordenador, el IDE de Arduino a menudo muestra ``COMxx desconocido``. ¿Por qué sucede esto?

.. note::

   Si aparece ``COMxx desconocido`` o ningún puerto, es posible que tu ordenador no haya reconocido la placa. Consulta :ref:`install_driver`.

.. image:: img/unknown_device.png

Esto se debe a que el controlador USB del ESP32 es diferente al de las placas Arduino regulares. El IDE de Arduino no puede reconocer automáticamente esta placa.

En tal escenario, necesitas seleccionar manualmente la placa correcta siguiendo estos pasos:

#. Haz clic en **"Seleccionar otra placa y puerto"**.

    .. image:: img/unknown_select.png

#. En la búsqueda, escribe **"esp32 dev module"**, luego selecciona la placa que aparece. Después, selecciona el puerto correcto y haz clic en **OK**.

    .. image:: img/unknown_board.png

#. Ahora, deberías poder ver tu placa y puerto en esta ventana de vista rápida.

    .. image:: img/unknown_correct.png
