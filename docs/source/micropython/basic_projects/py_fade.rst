.. _py_fading:

2.2 Atenuación de un LED
===================================

En el proyecto anterior, controlamos el LED encendiéndolo y apagándolo mediante salida digital. En este proyecto, crearemos un efecto de respiración en el LED utilizando la Modulación por Ancho de Pulso (PWM). PWM es una técnica que nos permite controlar el brillo de un LED o la velocidad de un motor variando el ciclo de trabajo de una señal de onda cuadrada.

Con PWM, en lugar de simplemente encender o apagar el LED, ajustaremos la cantidad de tiempo que el LED está encendido versus la cantidad de tiempo que está apagado en cada ciclo. Al cambiar rápidamente el LED de encendido a apagado en intervalos variables, podemos crear la ilusión de que el LED se ilumina y se atenúa gradualmente, simulando un efecto de respiración.

Utilizando las capacidades de PWM del ESP32 WROOM 32E, podemos lograr un control suave y preciso sobre el brillo del LED. Este efecto de respiración agrega un elemento dinámico y visualmente atractivo a tus proyectos, creando una exhibición llamativa o ambiente.

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí tienes el enlace:

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**Pines Disponibles**

Aquí tienes una lista de los pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Esquemático**

.. image:: ../../img/circuit/circuit_2.1_led.png

Este proyecto utiliza el mismo circuito que el primer proyecto :ref:`py_blink`, pero el tipo de señal es diferente. El primer proyecto es para emitir niveles altos y bajos digitales (0&1) directamente desde el pin26 para hacer que el LED se ilumine o se apague, este proyecto es para emitir una señal PWM desde el pin26 para controlar el brillo del LED.

**Cableado**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**Código**

.. note::

    * Abre el archivo ``2.2_fading_led.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 

.. code-block:: python

    # Import the necessary libraries
    from machine import Pin, PWM
    import time

    # Create a PWM object
    led = PWM(Pin(26), freq=1000)

    while True:
        # Gradually increase brightness
        for duty_cycle in range(0, 1024, 1):
            led.duty(duty_cycle)
            time.sleep(0.01)

        # Gradually decrease brightness
        for duty_cycle in range(1023, -1, -1):
            led.duty(duty_cycle)
            time.sleep(0.01)


The LED will gradually become brighter as the code runs.

**¿Cómo funciona?**

En general, este código demuestra cómo usar señales PWM para controlar el brillo de un LED.


#. Importa dos módulos, ``machine`` y ``time``. El módulo ``machine`` proporciona acceso de bajo nivel al hardware del microcontrolador, mientras que el módulo ``time`` proporciona funciones para operaciones relacionadas con el tiempo.

    .. code-block:: python

        import machine
        import time

#. Luego inicializa un objeto ``PWM`` para controlar el LED conectado al pin 26 y establece la frecuencia de la señal PWM a 1000 Hz.

    .. code-block:: python

        led = PWM(Pin(26), freq=1000)

#. Desvanece el LED de forma gradual usando un bucle: El bucle externo ``while True`` se ejecuta indefinidamente. Dos bucles ``for`` anidados se utilizan para aumentar y disminuir gradualmente el brillo del LED. El ciclo de trabajo varía de 0 a 1023, representando un ciclo de trabajo del 0% al 100%.

    .. code-block:: python

        # Import the necessary libraries
        from machine import Pin, PWM
        import time

        # Create a PWM object
        led = PWM(Pin(26), freq=1000)

        while True:
            # Gradually increase brightness
            for duty_cycle in range(0, 1024, 2):
                led.duty(duty_cycle)
                time.sleep(0.01)

            # Gradually decrease brightness
            for duty_cycle in range(1023, -1, -2):
                led.duty(duty_cycle)
                time.sleep(0.01)


    * ``range()``: Crea una secuencia de enteros de 0 a 1023. 
    * El ciclo de trabajo de la señal PWM se establece en cada valor de la secuencia usando el método ``duty()`` del objeto ``PWM``. 
    * ``time.sleep()``: Pausa la ejecución del programa durante 10 milisegundos entre cada iteración del bucle, creando un aumento gradual en el brillo con el tiempo.

    
