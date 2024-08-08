.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_rgb:

2.3 Luz Colorida
==============================================

En este proyecto, exploraremos el fascinante mundo de la mezcla de colores aditivos usando un LED RGB.

El LED RGB combina tres colores primarios, que son Rojo, Verde y Azul, en un solo paquete. Estos tres LEDs comparten un pin de cátodo común, mientras que cada pin de ánodo controla la intensidad del color correspondiente.

Variando la intensidad de la señal eléctrica aplicada a cada ánodo, podemos crear una amplia gama de colores. Por ejemplo, mezclar luz roja y verde de alta intensidad resultará en luz amarilla, mientras que combinar luz azul y verde producirá cian.

A través de este proyecto, exploraremos los principios de la mezcla de colores aditivos y desataremos nuestra creatividad manipulando el LED RGB para mostrar colores vibrantes y cautivadores.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_2.3_rgb.png

Los pines PWM pin27, pin26 y pin25 controlan los pines Rojo, Verde y Azul del LED RGB respectivamente, y conectan el pin de cátodo común a GND. Esto permite que el LED RGB muestre un color específico superponiendo luz en estos pines con diferentes valores PWM.


**Conexión**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

El LED RGB tiene 4 pines: el pin largo es el pin de cátodo común, que usualmente se conecta a GND; el pin izquierdo junto al pin más largo es Rojo; y los dos pines a la derecha son Verde y Azul.

.. image:: ../../img/wiring/2.3_color_light_bb.png

**Código**

.. note::

    * Abre el archivo ``2.3_colorful_light.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    from machine import Pin, PWM
    import time

    # Define the GPIO pins for the RGB LED
    RED_PIN = 27
    GREEN_PIN = 26
    BLUE_PIN = 25


    # Set up the PWM channels
    red = PWM(Pin(RED_PIN))
    green = PWM(Pin(GREEN_PIN))
    blue = PWM(Pin(BLUE_PIN))

    # Set the PWM frequency
    red.freq(1000)
    green.freq(1000)
    blue.freq(1000)

    def set_color(r, g, b):
        red.duty(r)
        green.duty(g)
        blue.duty(b)

    while True:
        # Set different colors and wait for a while
        set_color(1023, 0, 0) # Red
        time.sleep(1)
        set_color(0, 1023, 0) # Green
        time.sleep(1)
        set_color(0, 0, 1023) # Blue
        time.sleep(1)
        set_color(1023, 0, 1023) # purple
        time.sleep(1)

Cuando se ejecute el script, verás que los LEDs RGB muestran rojo, verde, azul y morado, y así sucesivamente.

**Aprende Más**

También puedes establecer el color que desees con el siguiente código con los valores de color familiares de 0~255.

.. note::

    * Abre el archivo ``2.3_colorful_light_rgb.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    from machine import Pin, PWM
    import time

    # Define the GPIO pins for the RGB LED
    RED_PIN = 27
    GREEN_PIN = 26
    BLUE_PIN = 25

    # Set up the PWM channels
    red = PWM(Pin(RED_PIN))
    green = PWM(Pin(GREEN_PIN))
    blue = PWM(Pin(BLUE_PIN))

    # Set the PWM frequency
    red.freq(1000)
    green.freq(1000)
    blue.freq(1000)

    # Map input values from one range to another
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Convert color values (0-255) to duty cycle values (0-1023)
    def color_to_duty(rgb_value):
        rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
        return rgb_value

    def set_color(red_value,green_value,blue_value):
        red.duty(color_to_duty(red_value))
        green.duty(color_to_duty(green_value))
        blue.duty(color_to_duty(blue_value))

    while True:
        # Set different colors and wait for a while
        set_color(255, 0, 0) # Red
        time.sleep(1)
        set_color(0, 255, 0) # Green
        time.sleep(1)
        set_color(0, 0, 255) # Blue
        time.sleep(1)
        set_color(255, 0, 255) # purple
        time.sleep(1)

Este código se basa en el ejemplo anterior, pero mapea los valores de color de 0 a 255 a un rango de ciclo de trabajo de 0 a 1023.

* La función ``interval_mapping`` es una función de utilidad que mapea un valor de un rango a otro. Toma cinco argumentos: el valor de entrada, los valores mínimos y máximos del rango de entrada, y los valores mínimos y máximos del rango de salida. Devuelve el valor de entrada mapeado al rango de salida.

    .. code-block:: python

        def color_to_duty(rgb_value):
            rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
            return rgb_value

* La función ``color_to_duty`` toma un valor RGB entero (por ejemplo, 255,0,255) y lo mapea a un valor de ciclo de trabajo adecuado para los pines PWM. El valor RGB de entrada se mapea primero del rango 0-255 al rango 0-1023 usando la función ``interval_mapping``. El resultado de ``interval_mapping`` se devuelve entonces como el valor del ciclo de trabajo.

    .. code-block:: python

        def color_to_duty(rgb_value):
            rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
            return rgb_value

* La función ``set_color`` toma tres argumentos enteros: los valores rojo, verde y azul para el LED. Estos valores se pasan a ``color_to_duty`` para obtener los valores del ciclo de trabajo para los pines PWM. Los valores del ciclo de trabajo se establecen entonces para los pines correspondientes usando el método ``duty``.

    .. code-block:: python

        def set_color(red_value,green_value,blue_value):
            red.duty(color_to_duty(red_value))
            green.duty(color_to_duty(green_value))
            blue.duty(color_to_duty(blue_value))
