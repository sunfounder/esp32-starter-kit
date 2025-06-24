.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _install_micropython_on_esp32:

1.3 Instalar MicroPython en el ESP32(Importante)
==================================================

..     .. image:: img/dowload_micropython_uf2.png

#. Conecta el ESP32 WROOM 32E a tu ordenador usando un cable USB.

   .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Haz clic en la esquina inferior derecha del IDE de Thonny, selecciona **"MicroPython(ESP32).xxxCOMXX"** en el menú emergente y luego selecciona **"Configurar intérprete"**.

   .. note::

      Si no ves ninguna opción aparte de "Local Python 3", es posible que tu ordenador no haya reconocido la placa ESP32.  
      En ese caso, puede que necesites :ref:`install_driver`.

   .. image:: img/install_micropython1.png

#. Haz clic en **"Install or Update MicroPython"** en la nueva ventana emergente.

   .. image:: img/install_micropython2.png

#. Selecciona el puerto correcto, la familia de MicroPython, la variante y la placa, luego haz clic en **"Install"**.

   .. image:: img/install_micropython3.png

#. Tras una instalación exitosa, vuelve a la pantalla principal de Thonny. Verás la versión de MicroPython y mensajes relacionados con ESP32, en lugar de errores en rojo.

   .. image:: img/install_micropython5.png
