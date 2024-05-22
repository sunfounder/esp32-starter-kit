.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_servo:

4.3 Servo Oscilante
===================

Un Servo es un tipo de dispositivo basado en la posición conocido por su capacidad para mantener ángulos específicos y proporcionar una rotación precisa. Esto lo hace altamente deseable para sistemas de control que demandan ajustes de ángulo consistentes. No es sorprendente que los Servos se hayan utilizado ampliamente en juguetes controlados remotamente de alta gama, desde modelos de aviones hasta réplicas de submarinos y robots controlados remotamente sofisticados.

En esta aventura intrigante, nos desafiaremos a manipular el Servo de una manera única: ¡haciéndolo balancearse! Este proyecto ofrece una brillante oportunidad para profundizar en la dinámica de los Servos, afilando tus habilidades en sistemas de control precisos y ofreciendo una comprensión más profunda de su operación.

¿Estás listo para hacer bailar al Servo a tu ritmo? ¡Embarquémonos en este emocionante viaje!

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**Conexión**

* El cable naranja es de señal y se conecta a IO25.
* El cable rojo es VCC y se conecta a 5V.
* El cable marrón es GND y se conecta a GND.

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png

**Código**

.. note::

    * Abre el archivo ``4.3_swinging_servo.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 




.. code-block:: python

    import machine
    import time

    # Create a PWM (Pulse Width Modulation) object on Pin 25
    servo = machine.PWM(machine.Pin(25))

    # Set the frequency of the PWM signal to 50 Hz, common for servos
    servo.freq(50)

    # Define a function for interval mapping
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Define a function to write an angle to the servo
    def servo_write(pin, angle):
        
        pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculate the pulse width
        duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calculate the duty cycle
        pin.duty(duty) # Set the duty cycle of the PWM signal

    # Create an infinite loop
    while True:
        # Loop through angles from 0 to 180 degrees
        for angle in range(180):
            servo_write(servo, angle)
            time.sleep_ms(20)

        # Loop through angles from 180 to 0 degrees in reverse
        for angle in range(180, -1, -1):
            servo_write(servo, angle)
            time.sleep_ms(20)


Al ejecutar este código, el servo oscilará continuamente de ida y vuelta entre 0 y 180 grados.


**¿Cómo funciona?**


#. Importar las bibliotecas necesarias: ``machine`` para controlar el hardware del microcontrolador, y ``time`` para agregar retrasos.


    .. code-block:: python

        import machine
        import time

#. Crear un objeto PWM (Modulación por Ancho de Pulso) en el Pin 25 y establecer su frecuencia a 50 Hz, que es común para servo.

    .. code-block:: python

        # Create a PWM (Pulse Width Modulation) object on Pin 25
        servo = machine.PWM(machine.Pin(25))

        # Set the frequency of the PWM signal to 50 Hz, common for servos
        servo.freq(50)

#. Definir una función ``interval_mapping`` para mapear valores de un rango a otro. Esto se usará para convertir el ángulo al ancho de pulso y ciclo de trabajo apropiados.

    .. code-block:: python

        def interval_mapping(x, in_min, in_max, out_min, out_max):
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

#. Definir una función ``servo_write`` que toma un objeto PWM y un ángulo como entradas. Calcula el ancho de pulso y ciclo de trabajo basado en el ángulo dado, y luego establece la salida PWM en consecuencia.

    .. code-block:: python
        
        def servo_write(pin, angle):
            
            pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculate the pulse width
            duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calculate the duty cycle
            pin.duty(duty) # Set the duty cycle of the PWM signal

    * En esta función, se llama a ``interval_mapping()`` para mapear el rango de ángulo 0 ~ 180 al rango de ancho de pulso 0.5 ~ 2.5ms.
    * ¿Por qué es 0.5~2.5? Esto está determinado por el modo de trabajo del :ref:`Servo`. 
    * Luego, convertir el ancho de pulso de período a ciclo de trabajo. 
    * Dado que ``duty()`` no puede tener decimales cuando se usa (el valor no puede ser de tipo flotante), usamos ``int()`` para forzar que el ciclo de trabajo se convierta a tipo entero.

#. Crear un bucle infinito con dos bucles anidados.

    .. code-block:: python

        while True:
            # Loop through angles from 0 to 180 degrees
            for angle in range(180):
                servo_write(servo, angle)
                time.sleep_ms(20)

            # Loop through angles from 180 to 0 degrees in reverse
            for angle in range(180, -1, -1):
                servo_write(servo, angle)
                time.sleep_ms(20)
    
    * El primer bucle anidado itera a través de ángulos de 0 a 180 grados, y el segundo bucle anidado itera a través de ángulos de 180 a 0 grados en reversa.
    * En cada iteración, se llama a la función ``servo_write`` con el ángulo actual, y se añade un retraso de 20 milisegundos.
