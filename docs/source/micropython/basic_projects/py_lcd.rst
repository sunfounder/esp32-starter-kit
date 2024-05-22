.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_lcd1602:

2.6 Mostrar Caracteres
==================================================

Ahora, exploraremos el fascinante mundo de la visualización de caracteres utilizando el módulo LCD1602 I2C.

A través de este proyecto, aprenderemos cómo inicializar el módulo LCD, configurar los parámetros de visualización deseados y enviar datos de caracteres para ser mostrados en la pantalla. Podemos mostrar mensajes personalizados, exhibir lecturas de sensores o crear menús interactivos. ¡Las posibilidades son infinitas!

Dominando el arte de la visualización de caracteres en el LCD1602 I2C, desbloquearemos nuevas vías para la comunicación y la muestra de información en nuestros proyectos. Sumérgete en este emocionante viaje y da vida a tus caracteres en la pantalla del LCD.

**Componentes Requeridos**

Para este proyecto, necesitaremos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - Kit de Inicio ESP32
        - 320+
        - |link_esp32_starter_kit|

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Pines Disponibles
        - Descripción de Uso

    *   - IO21
        - SDA
    *   - IO22
        - SCL
    
**Esquemático**

.. image:: ../../img/circuit/circuit_2.6_lcd.png

**Conexión**

.. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
    :width: 800

**Código**

.. note::

    * Abre el archivo ``2.6_liquid_crystal_display.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 
    * Se utiliza aquí la biblioteca ``lcd1602.py`` y verifica si se ha cargado en el ESP32. Consulta :ref:`add_libraries_py` para obtener un tutorial.

.. code-block:: python

    # Import the LCD class from the lcd1602 module
    from lcd1602 import LCD

    import time

    # Create an instance of the LCD class and assign it to the lcd variable
    lcd = LCD()
    # Set the string " Hello!\n"
    string = " Hello!\n"
    # Display the string on the LCD screen
    lcd.message(string)

    time.sleep(2)
    # Set the string "    Sunfounder!"
    string = "    Sunfounder!"
    # Display the string on the LCD screen
    lcd.message(string)

    time.sleep(2)
    # Clear the LCD screen
    lcd.clear()


Después de ejecutar el script, podrás ver dos líneas de texto que aparecen en la pantalla LCD por turnos y luego desaparecen.


.. note:: 

    Si el código y la conexión son correctos, pero el LCD aún no muestra ningún contenido, puedes ajustar el potenciómetro en la parte posterior para aumentar el contraste.


**¿Cómo funciona?**

En la biblioteca ``lcd1602``, integramos las funciones relevantes del lcd1602 en la clase LCD.

#. Importa el módulo ``lcd1602``.

    .. code-block:: python

        from lcd1602 import LCD    

#. Declara un objeto de la clase ``LCD`` y nómbralo ``lcd``.

    .. code-block:: python

        lcd = LCD()

#. Esta instrucción mostrará el texto en el LCD. Es importante señalar que el argumento debe ser de tipo cadena. Si queremos pasar un entero o un flotante, debemos utilizar la instrucción de conversión forzada ``str()``.

    .. code-block:: python

        lcd.message(string)


#. Si llamas a esta instrucción varias veces, el LCD superpondrá los textos. Esto requiere el uso de la siguiente instrucción para limpiar la pantalla.

    .. code-block:: python

        lcd.clear()

