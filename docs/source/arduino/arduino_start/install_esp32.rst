.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

1.3 Instalar la Placa ESP32 (Importante)
===========================================

Para programar el microcontrolador ESP32, necesitamos instalar el paquete de la placa ESP32 en el Arduino IDE. Sigue la guía paso a paso a continuación:

**Instalar la Placa ESP32**

.. #. Abre el Arduino IDE. Ve a **Archivo** y selecciona **Preferencias** en el menú desplegable.

..     .. image:: img/install_esp321.png

.. #. En la ventana de Preferencias, localiza el campo **URLs Adicionales de Gestores de Tarjetas**. Haz clic en él para activar el cuadro de texto.

..     .. image:: img/install_esp322.png

.. #. Añade la siguiente URL al campo **URLs Adicionales de Gestores de Tarjetas**: https://espressif.github.io/arduino-esp32/package_esp32_index.json. Esta URL apunta al archivo índice del paquete para las placas ESP32. Haz clic en el botón **OK** para guardar los cambios.

..     .. image:: img/install_esp323.png

#. En la ventana del **Gestor de Tarjetas**, escribe **ESP32** en la barra de búsqueda. Haz clic en el botón **Instalar** para comenzar el proceso de instalación. Esto descargará e instalará el paquete de la placa ESP32.

    .. image:: img/install_esp324.png

#. ¡Felicidades! Has instalado con éxito el paquete de la placa ESP32 en el Arduino IDE.

**Subir el Código**

#. Ahora, conecta el ESP32 WROOM 32E a tu computadora usando un cable Micro USB.

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Luego selecciona la placa correcta, **ESP32 Dev Module**, haciendo clic en **Herramientas** -> **Placa** -> **esp32**.

    .. image:: img/install_esp325.png

#. Si tu ESP32 está conectado a la computadora, puedes elegir el puerto correcto haciendo clic en **Herramientas** -> **Puerto**.

    .. image:: img/install_esp326.png

#. Además, Arduino 2.0 introdujo una nueva forma de seleccionar rápidamente la placa y el puerto. Para el ESP32, usualmente no se reconoce automáticamente, por lo que necesitas hacer clic en **Seleccionar otra placa y puerto**.

    .. image:: img/install_esp327.png

#. En el cuadro de búsqueda, escribe **ESP32 Dev Module** y selecciónalo cuando aparezca. Luego, elige el puerto correcto y haz clic en **OK**.

    .. image:: img/install_esp328.png

#. Después, puedes seleccionarlo a través de esta ventana de acceso rápido. Ten en cuenta que durante el uso subsiguiente, puede haber momentos en los que ESP32 no esté disponible en la ventana de acceso rápido, y necesitarás repetir los dos pasos anteriores.

    .. image:: img/install_esp329.png

#. Ambos métodos te permiten seleccionar la placa y el puerto correctos, así que elige el que mejor se adapte a ti. Ahora, todo está listo para subir el código al ESP32.
