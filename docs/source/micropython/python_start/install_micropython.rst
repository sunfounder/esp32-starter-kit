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

#. Descarga el |link_esp32_micropython_download| desde la página oficial de MicroPython y luego descarga la última versión del firmware.

    .. image:: img/dowload_micropython_uf2.png

#. Conecta el ESP32 WROOM 32E a tu computadora utilizando un cable Micro USB.

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Haz clic en la esquina inferior derecha del IDE de Thonny, selecciona **"MicroPython(ESP32).COMXX"** del menú emergente y luego selecciona **"Configurar intérprete"**.

    .. image:: img/install_micropython1.png

#. Haz clic en **"Instalar o Actualizar MicroPython"** en la nueva ventana emergente.

    .. image:: img/install_micropython2.png

#. Selecciona el puerto correcto y el firmware que descargaste anteriormente, y haz clic en **"Instalar"**.

    .. image:: img/install_micropython3.png

#. Después de una instalación exitosa, puedes cerrar esta página.

    .. image:: img/install_micropython4.png

#. Cuando regreses a la página principal de Thonny, verás la versión de MicroPython y los mensajes relacionados con ESP32, en lugar de mensajes de error en rojo.

    .. image:: img/install_micropython5.png
