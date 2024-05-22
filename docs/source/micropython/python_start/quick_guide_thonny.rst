.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

1.5 Guía Rápida sobre Thonny
==================================

.. _open_run_code_py:

Abrir y Ejecutar Código Directamente
---------------------------------------------

La sección de código en los proyectos te indica exactamente qué código se utiliza, así que haz doble clic en el archivo ``.py`` con el número de serie en el camino ``esp32-starter-kit-main\micropython\codes\`` para abrirlo.

Sin embargo, primero debes descargar el paquete y subir las bibliotecas, como se describe en :ref:`add_libraries_py`.

#. Abrir código.

    Por ejemplo, ``1.1_hello_led.py``.

    Si haces doble clic en él, se abrirá una nueva ventana a la derecha. Puedes abrir más de un código al mismo tiempo.

    .. image:: img/quick_guide1.png

#. Conecta el esp32 a tu computadora con un cable micro USB.

    .. image:: ../../img/plugin_esp32.png

#. Seleccionar el intérprete correcto

    Selecciona el intérprete "MicroPython (ESP32).COMxx".

    .. image:: img/sec_inter.png

#. Ejecutar el código

    Para ejecutar el script, haz clic en el botón **Ejecutar script actual** o presiona F5.

    .. image:: img/quick_guide2.png

    Si el código contiene alguna información que necesite ser impresa, aparecerá en la Shell; de lo contrario, solo aparecerá la siguiente información.

    Haz clic en **Ver** -> **Editar** para abrir la ventana de Shell si no aparece en tu Thonny.

        .. code-block::

            MicroPython v1.19.1 el 2022-06-18; módulo ESP32 con ESP32

            Escribe "help()" para más información.

            >>> %Run -c $EDITOR_CONTENT

    * La primera línea muestra la versión de MicroPython, la fecha y la información de tu dispositivo.
    * La segunda línea te invita a ingresar "help()" para obtener ayuda.
    * La tercera línea es un comando de Thonny indicando al intérprete de MicroPython en tu Pico W ejecutar el contenido del área del script - "EDITOR_CONTENT".
    * Si hay algún mensaje después de la tercera línea, usualmente es un mensaje que le indicas a MicroPython imprimir, o un mensaje de error para el código.


#. Detener la ejecución

    .. image:: img/quick_guide3.png

    Para detener el código en ejecución, haz clic en el botón **Detener/Reiniciar backend**. El comando **%RUN -c $EDITOR_CONTENT** desaparecerá después de detener.

#. Guardar o guardar como

    Puedes guardar los cambios realizados en el ejemplo abierto presionando **Ctrl+S** o haciendo clic en el botón **Guardar** en Thonny.

    El código se puede guardar como un archivo separado dentro del **disco MicroPython(ESP32)** haciendo clic en **Archivo** -> **Guardar como**.

    .. image:: img/quick_guide4.png

    Selecciona **disco MicroPython**.

    .. image:: img/quick_guide5.png
        
    Luego haz clic en **Aceptar** después de ingresar el nombre del archivo y la extensión **.py**. En el disco MicroPython, verás tu archivo guardado.

    .. image:: img/quick_guide6.png

    .. note::
        Independientemente del nombre que le des a tu código, es mejor describir qué tipo de código es, y no darle un nombre sin sentido como ``abc.py``.
        Cuando guardas el código como ``main.py``, se ejecutará automáticamente cuando se encienda la alimentación.


Crear Archivo y Ejecutarlo
------------------------------


El código se muestra directamente en la sección de código. Puedes copiarlo en Thonny y ejecutarlo de la siguiente manera.

#. Crear un nuevo archivo

    Abre Thonny IDE, haz clic en el botón **Nuevo** para crear un nuevo archivo en blanco.

    .. image:: img/quick_guide7.png

#. Copiar código

    Copia el código del proyecto al IDE de Thonny.

    .. image:: img/quick_guide8.png

#. Conecta el esp32 a tu computadora con un cable micro USB.

    .. image:: ../../img/plugin_esp32.png

#. Seleccionar el intérprete correcto

    Selecciona el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha.

    .. image:: img/sec_inter.png

#. Ejecutar el código

    Necesitas hacer clic en **Ejecutar Script Actual** o simplemente presionar ``F5`` para ejecutarlo.

    .. image:: img/quick_guide9.png

    Si el código contiene alguna información que necesite ser impresa, aparecerá en la Shell; de lo contrario, solo aparecerá la siguiente información.

    Haz clic en **Ver** -> **Editar** para abrir la ventana de Shell si no aparece en tu Thonny.

        .. code-block::

            MicroPython v1.19.1 el 2022-06-18; módulo ESP32 con ESP32

            Escribe "help()" para más información.

            >>> %Run -c $EDITOR_CONTENT

    * La primera línea muestra la versión de MicroPython, la fecha y la información de tu dispositivo.
    * La segunda línea te invita a ingresar "help()" para obtener ayuda.
    * La tercera línea es un comando de Thonny indicando al intérprete de MicroPython en tu Pico W ejecutar el contenido del área del script - "EDITOR_CONTENT".
    * Si hay algún mensaje después de la tercera línea, usualmente es un mensaje que le indicas a MicroPython imprimir, o un mensaje de error para el código.


#. Detener la ejecución

    .. image:: img/quick_guide3.png

    Para detener el código en ejecución, haz clic en el botón **Detener/Reiniciar backend**. El comando **%RUN -c $EDITOR_CONTENT** desaparecerá después de detener.

#. Guardar o guardar como

    Puedes guardar el código presionando **Ctrl+S** o haciendo clic en el botón **Guardar** en Thonny. En la ventana emergente, selecciona el lugar donde quieres guardar el archivo.

    .. image:: img/quick_guide5.png
        
    Luego haz clic en **Aceptar** o **Guardar** después de ingresar el nombre del archivo y la extensión **.py**.

    .. image:: img/quick_guide6.png

    .. note::
        Independientemente del nombre que le des a tu código, es mejor describir qué tipo de código es, y no darle un nombre sin sentido como ``abc.py``.
        Cuando guardas el código como ``main.py``, se ejecutará automáticamente cuando se encienda la alimentación.

#. Abrir archivo

    Aquí hay dos maneras de abrir un archivo de código guardado.

    * El primer método es hacer clic en el icono de abrir en la barra de herramientas de Thonny, igual que cuando guardas un programa, se te preguntará si quieres abrirlo desde **este computador** o **dispositivo MicroPython**, por ejemplo, haz clic en **dispositivo MicroPython** y verás una lista de todos los programas que has guardado en el ESP32.
    * El segundo es abrir la vista previa del archivo directamente haciendo clic en **Ver** -> **Archivos** -> y luego hacer doble clic en el correspondiente archivo ``.py`` para abrirlo.


