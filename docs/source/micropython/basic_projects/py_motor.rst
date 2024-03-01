.. _py_motor:

4.1 Pequeño Ventilador
=======================

En este proyecto apasionante, exploraremos cómo manejar un motor utilizando el L293D.

El L293D es un circuito integrado (CI) versátil comúnmente utilizado para el control de motores en proyectos de electrónica y robótica. Puede manejar dos motores en direcciones hacia adelante y hacia atrás, lo que lo convierte en una opción popular para aplicaciones que requieren un control preciso del motor.

Al final de este proyecto fascinante, habrás ganado una comprensión profunda de cómo se pueden utilizar eficazmente las señales digitales y las señales PWM para controlar motores. Este conocimiento invaluable será una base sólida para tus futuros empeños en robótica y mecatrónica. ¡Prepárate y sumérgete en el emocionante mundo del control de motores con el L293D!

**Componentes Requeridos**

Para este proyecto, necesitamos los siguientes componentes.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_l293d`
        - \-

**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Esquemático**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png

**Conexión**

.. note:: 

    Dado que el motor requiere una corriente relativamente alta, es necesario primero insertar la batería y luego deslizar el interruptor en la placa de expansión a la posición ON para activar el suministro de batería. 

.. image:: ../../img/wiring/4.1_motor_l293d_bb.png

**Código**

.. note::

    * Abre el archivo ``4.1_motor_turn.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 

.. code-block:: python

    import machine
    import time

    # Create Pin objects representing the motor control pins and set them to output mode
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Define a function to rotate the motor clockwise
    def clockwise():
        motor1A.value(1)
        motor2A.value(0)

    # Define a function to rotate the motor anticlockwise
    def anticlockwise():
        motor1A.value(0)
        motor2A.value(1)

    # Define a function to stop the motor
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    # Enter an infinite loop

    try:
        while True:
            clockwise() # Rotate the motor clockwise
            time.sleep(1) # Pause for 1 second
            anticlockwise() # Rotate the motor anticlockwise
            time.sleep(1)
            stop() # Stop the motor
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Stop the motor when KeyboardInterrupt is caught



Durante la ejecución del script, verás el motor girando alternativamente en el sentido de las agujas del reloj y en sentido contrario cada segundo.


**Aprender Más**

Además de simplemente hacer girar el motor en sentido horario y antihorario, también puedes controlar la velocidad de rotación del motor utilizando modulación por ancho de pulso (PWM) en el pin de control, como se muestra a continuación.

.. note::

    * Abre el archivo ``4.1_motor_turn_pwm.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    from machine import Pin, PWM
    import time

    # Create PWM objects representing the motor control pins and set their frequency to 1000 Hz
    motor1A = PWM(Pin(13, Pin.OUT))
    motor2A = PWM(Pin(14, Pin.OUT))
    motor1A.freq(500)
    motor2A.freq(500)

    # Enter an infinite loop
    while True:
        # Rotate the motor forward by gradually increasing the power on the motor1A pin
        for power in range(0, 1023, 20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Decreasing the power on the motor1A pin
        for power in range(1023, 0, -20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Rotate the motor in the opposite direction by gradually increasing the power on the motor2A pin
        for power in range(0, 1023, 20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)
        # Decreasing the power on the motor2A pin
        for power in range(1023, 0, -20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)




A diferencia del script anterior, aquí el motor es controlado por señales PWM con una frecuencia de 1000 Hz, lo cual determina la velocidad del motor.

* El código utiliza un bucle ``while True`` para funcionar continuamente. Dentro del bucle, hay cuatro bucles ``for`` que controlan los motores en secuencia. 
* Los primeros dos bucles ``for`` aumentan y disminuyen la velocidad de IN1 manteniendo IN2 a 0 de velocidad. 
* Los siguientes dos bucles ``for`` aumentan y disminuyen la velocidad de IN2 manteniendo IN1 a 0 de velocidad.
* La función ``range`` en cada bucle ``for`` produce una serie de números que sirve como el ciclo de trabajo de la señal PWM. Esto se envía luego a IN1 o IN2 a través del método ``duty``. El ciclo de trabajo determina el porcentaje de tiempo que la señal PWM está alta, lo que a su vez determina el voltaje promedio aplicado al motor, y por lo tanto la velocidad del motor.
* La función ``time.sleep`` se utiliza para introducir un retraso de 0.1 segundos entre cada paso en la secuencia, lo que permite que el motor cambie de velocidad gradualmente, en lugar de saltar de una velocidad a otra instantáneamente.
