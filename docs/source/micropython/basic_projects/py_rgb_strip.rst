.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_rgb_strip:

2.7 Tira de LED RGB
======================

En este proyecto, nos adentraremos en el fascinante mundo de controlar tiras de LED WS2812, dando vida a un vibrante espectáculo de colores. Con la capacidad de controlar individualmente cada LED de la tira, podemos crear efectos de iluminación cautivadores que deslumbrarán los sentidos.

Además, hemos incluido una extensión emocionante a este proyecto, donde exploraremos el reino de la aleatoriedad. Introduciendo colores aleatorios y implementando un efecto de luz fluida, podemos crear una experiencia visual hipnotizante que cautiva y encanta.

**Componentes Requeridos**

Para este proyecto, necesitaremos los siguientes componentes.

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

    *   - INTRODUCCIÓN AL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Esquemático**

.. image:: ../../img/circuit/circuit_2.7_ws2812.png
    :width: 500
    :align: center


**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


.. note::

    IO33 no está disponible para este proyecto.

    La tira de LED WS2812 es un tipo de tira de LED que requiere una señal precisa de modulación por ancho de pulso (PWM). La señal PWM tiene requisitos precisos tanto en tiempo como en voltaje. Por ejemplo, un bit "0" para el WS2812 corresponde a un pulso de alto nivel de aproximadamente 0.4 microsegundos, mientras que un bit "1" corresponde a un pulso de alto nivel de aproximadamente 0.8 microsegundos. Esto significa que la tira necesita recibir cambios de voltaje de alta frecuencia.

    Sin embargo, con una resistencia de pull-up de 4.7K y un condensador de pull-down de 100nf en IO33, se crea un filtro pasa bajo simple. Este tipo de circuito "suaviza" las señales de alta frecuencia, porque el condensador necesita algún tiempo para cargar y descargar cuando recibe cambios de voltaje. Por lo tanto, si la señal cambia demasiado rápido (es decir, es de alta frecuencia), el condensador no podrá seguir el ritmo. Esto resulta en que la señal de salida se vuelva borrosa e irreconocible para la tira.

**Conexión**

.. image:: ../../img/wiring/2.7_rgb_strip_bb.png
    :width: 800

**Código**

.. note::

    * Abre el archivo ``2.7_rgb_strip.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 

.. code-block:: python

    from machine import Pin
    from neopixel import NeoPixel

    pin = Pin(14, Pin.OUT)   # set a pin to output to drive NeoPixels
    pixels = NeoPixel(pin, 8)   # create NeoPixel driver on pin for 8 pixels

    pixels[0] = [64,154,227]    # set the pixel
    pixels[1] = [128,0,128]
    pixels[2] = [50,150,50]
    pixels[3] = [255,30,30]
    pixels[4] = [0,128,255]
    pixels[5] = [99,199,0]
    pixels[6] = [128,128,128]
    pixels[7] = [255,100,0]

    pixels.write()              # write data to all pixels

¡Seleccionemos algunos colores favoritos y mostrémoslos en la Tira de LED RGB!

**¿Cómo funciona?**

#. En el módulo ``neopixel``, hemos integrado funciones relacionadas en la clase ``NeoPixel``.

.. code-block:: python

    from neopixel import NeoPixel

#. Utiliza la clase ``NeoPixel`` del módulo ``neopixel`` para inicializar el objeto ``pixels``, especificando el pin de datos y el número de LEDs.

.. code-block:: python

    pixels = NeoPixel(pin, 8)   # create NeoPixel driver on pin for 8 pixels

#. Configura el color de cada LED y usa el método ``write()`` para enviar los datos al LED WS2812 y actualizar su visualización.

.. code-block:: python

    pixels[0] = [64,154,227]    # set the pixel
    pixels[1] = [128,0,128]
    pixels[2] = [50,150,50]
    pixels[3] = [255,30,30]
    pixels[4] = [0,128,255]
    pixels[5] = [99,199,0]
    pixels[6] = [128,128,128]
    pixels[7] = [255,100,0]

    pixels.write()              # write data to all pixels

**Aprende Más**

Podemos generar colores aleatoriamente y hacer una luz fluida colorida.

.. note::

    * Abre el archivo ``2.7_rgb_strip_random.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 

.. code-block:: python

    from machine import Pin
    import neopixel
    import time
    import random

    # Set the number of pixels for the running light
    num_pixels = 8

    # Set the data pin for the RGB LED strip
    data_pin = Pin(14, Pin.OUT)

    # Initialize the RGB LED strip object
    pixels = neopixel.NeoPixel(data_pin, num_pixels)

    # Continuously loop the running light
    while True:
        for i in range(num_pixels):
            # Generate a random color for the current pixel
            color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
            
            # Turn on the current pixel with the random color
            pixels[i] = color
            
            # Update the RGB LED strip display
            pixels.write()
            
            # Turn off the current pixel
            pixels[i] = (0, 0, 0)
            
            # Wait for a period of time to control the speed of the running light
            time.sleep_ms(100)

* En el bucle ``while``, usamos un bucle ``for`` para encender cada píxel de la tira de LED RGB uno por uno.
* Primero usa la función ``random.randint()`` para generar un color aleatorio para el píxel actual.
* Luego enciende el píxel actual con el color aleatorio, usa el método ``write()`` del objeto ``NeoPixel`` para enviar los datos de color a la tira de LED RGB y actualizar su visualización.
* Finalmente, apaga el píxel actual configurando su color a (0, 0, 0), y espera un período de tiempo para controlar la velocidad de la luz corriente.
