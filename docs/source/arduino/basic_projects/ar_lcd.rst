.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_lcd1602:

2.6 Mostrar Caracteres
===============================

Ahora, exploraremos el fascinante mundo de la visualización de caracteres usando el módulo I2C LCD1602.

A través de este proyecto, aprenderemos cómo inicializar el módulo LCD, establecer los parámetros de visualización deseados y enviar datos de caracteres para ser mostrados en la pantalla. Podemos exhibir mensajes personalizados, mostrar lecturas de sensores o crear menús interactivos. ¡Las posibilidades son infinitas!

Dominando el arte de la visualización de caracteres en el I2C LCD1602, desbloquearemos nuevas vías para la comunicación y la visualización de información en nuestros proyectos. Sumergámonos en este emocionante viaje y demos vida a nuestros caracteres en la pantalla LCD.

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

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

    *   - INTRODUCCIÓN DE COMPONENTES
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
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

**Cableado**

.. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
    :width: 800

**Código**

.. note::

    * Abre el archivo ``2.6_lcd1602.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\2.6_lcd1602``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * La biblioteca ``LiquidCrystal I2C`` se usa aquí, puedes instalarla desde el **Administrador de Bibliotecas**.

        .. image:: img/lcd_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/31e33e53-67b2-4e29-b78b-f647fd45fb0b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Cuando este programa se carga, el I2C LCD1602 mostrará el mensaje de bienvenida, "¡Hola, Sunfounder!", durante 3 segundos. Después de eso, la pantalla mostrará una etiqueta "CUENTA:" y el valor de cuenta, que se incrementa cada segundo.


.. note:: 

    Si el código y el cableado son correctos, pero el LCD todavía no muestra ningún contenido, puedes ajustar el potenciómetro en la parte trasera para aumentar el contraste.

**¿Cómo funciona?**

Al llamar a la biblioteca ``LiquidCrystal_I2C.h``, puedes manejar fácilmente el LCD. 

.. code-block:: arduino

    #include <LiquidCrystal_I2C.h>

Funciones de la Biblioteca:


* Crea una nueva instancia de la clase ``LiquidCrystal_I2C`` que representa un LCD particular adjunto a tu placa Arduino.

    .. code-block:: arduino

        LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

    * ``lcd_AddR``: La dirección del LCD por defecto es 0x27.
    * ``lcd_cols``: El LCD1602 tiene 16 columnas.
    * ``lcd_rows``: El LCD1602 tiene 2 filas.

* Inicializa el lcd.

    .. code-block:: arduino

        void init()

* Enciende la luz de fondo (opcional).

    .. code-block:: arduino

        void backlight()

* Apaga la luz de fondo (opcional) rápidamente.

    .. code-block:: arduino

        void nobacklight()

* Enciende la pantalla LCD.

    .. code-block:: arduino

        void display()

* Apaga la pantalla LCD rápidamente.

    .. code-block:: arduino

        void nodisplay()

* Limpia la pantalla, establece la posición del cursor en cero.

    .. code-block:: arduino

        void clear()

* Establece la posición del cursor en col,row.

    .. code-block:: arduino

        void setCursor(uint8_t col,uint8_t row)

* Imprime texto en el LCD.

    .. code-block:: arduino

        void print(data,BASE)

    * ``data``: Los datos a imprimir (char, byte, int, long, o string).
    * ``BASE (opcional)``: La base en la que imprimir números.

        * ``BIN`` para binario (base 2)
        * ``DEC`` para decimal (base 10)
        * ``OCT`` para octal (base 8)
        * ``HEX`` para hexadecimal (base 16).
