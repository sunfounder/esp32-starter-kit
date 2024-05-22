.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_ultrasonic:

5.12 Medición de Distancia
======================================

El módulo ultrasónico se utiliza para la medición de distancia o la detección de objetos. En este proyecto, programaremos el módulo para obtener las distancias de los obstáculos. Enviando pulsos ultrasónicos y midiendo el tiempo que tardan en rebotar, podemos calcular distancias. Esto nos permite implementar acciones basadas en la distancia o comportamientos de evasión de obstáculos.

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
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Para Entrada
            - IO13, IO14, IO27, IO26, IO25, IO33, IO32, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Para Salida
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Esquemático**

.. image:: ../../img/circuit/circuit_5.12_ultrasonic.png

El ESP32 envía un conjunto de señales de onda cuadrada al pin Trig del sensor ultrasónico cada 10 segundos. Esto incita al sensor ultrasónico a emitir una señal de ultrasonido de 40kHz hacia afuera. Si hay un obstáculo al frente, las ondas de ultrasonido se reflejarán hacia atrás.

Registrando el tiempo que toma desde el envío hasta la recepción de la señal, dividiéndolo por 2 y multiplicándolo por la velocidad de la luz, se puede determinar la distancia al obstáculo.

**Conexión**

.. image:: ../../img/wiring/5.12_ultrasonic_bb.png

**Código**

.. note::

    * Abre el archivo ``5.12_ultrasonic.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    import machine
    import time

    # Define the trigger and echo pins for the distance sensor
    TRIG = machine.Pin(26, machine.Pin.OUT)
    ECHO = machine.Pin(25, machine.Pin.IN)

    # Calculate the distance using the ultrasonic sensor
    def distance():
        # Ensure trigger is off initially
        TRIG.off()
        time.sleep_us(2)  # Wait for 2 microseconds

        # Send a 10-microsecond pulse to the trigger pin
        TRIG.on()
        time.sleep_us(10)
        TRIG.off()

        # Wait for the echo pin to go high
        while not ECHO.value():
            pass

        # Record the time when the echo pin goes high
        time1 = time.ticks_us()

        # Wait for the echo pin to go low
        while ECHO.value():
            pass

        # Record the time when the echo pin goes low
        time2 = time.ticks_us()

        # Calculate the time difference between the two recorded times
        during = time.ticks_diff(time2, time1)

        # Calculate and return the distance (in cm) using the speed of sound (340 m/s)
        return during * 340 / 2 / 10000

    # Continuously measure and print the distance
    while True:
        dis = distance()
        print('Distance: %.2f' % dis)
        time.sleep_ms(300)  # Wait for 300 milliseconds before repeating


Una vez que el programa esté en ejecución, la Shell imprimirá la distancia del sensor ultrasónico al obstáculo adelante.

