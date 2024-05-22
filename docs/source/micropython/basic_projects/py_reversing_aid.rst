.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_reversing_aid:

6.4 Asistente de Reversa
===========================

Imagina esto: Estás en tu coche, a punto de aparcar en reversa en un lugar estrecho. Con nuestro proyecto, tendrás un módulo ultrasónico montado en la parte trasera de tu vehículo, actuando como un ojo digital. Al meter la marcha atrás, el módulo se activa, emitiendo pulsos ultrasónicos que rebotan en los obstáculos detrás de ti.

La magia ocurre cuando estos pulsos regresan al módulo. Calcula rápidamente la distancia entre tu coche y los objetos, transformando estos datos en retroalimentación visual en tiempo real mostrada en una vibrante pantalla LCD. Serás testigo de indicadores dinámicos y codificados por colores que representan la proximidad de los obstáculos, asegurando que tengas una comprensión cristalina del entorno circundante.

Pero no nos detuvimos ahí. Para sumergirte aún más en esta experiencia de conducción, incorporamos un zumbador animado. A medida que tu coche se acerca a un obstáculo, el tempo del zumbador se intensifica, creando una sinfonía auditiva de advertencias. Es como tener una orquesta personal guiándote a través de las complejidades del estacionamiento en reversa.

Este innovador proyecto combina tecnología de vanguardia con una interfaz de usuario interactiva, haciendo que tu experiencia de reversa sea segura y libre de estrés. Con el módulo ultrasónico, la pantalla LCD y el zumbador animado trabajando en armonía, te sentirás empoderado y confiado mientras maniobras en espacios estrechos, dejándote libre para concentrarte en el placer de conducir.

**Componentes Requeridos**

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Esquemático**

.. image:: ../../img/circuit/circuit_6.4_reversing_aid.png
    :width: 800
    :align: center


El sensor ultrasónico en el proyecto emite ondas de sonido de alta frecuencia y mide el tiempo que tardan en rebotar después de golpear un objeto. Analizando estos datos, se puede calcular la distancia entre el sensor y el objeto. Para proporcionar una advertencia cuando el objeto está demasiado cerca, se utiliza un zumbador para producir una señal audible. Además, la distancia medida se muestra en una pantalla LCD para una fácil visualización.

**Conexión**

.. image:: ../../img/wiring/6.4_aid_ultrasonic_bb.png
    :width: 800
    :align: center

**Código**

.. note::

    * Abra el archivo ``6.4_reversing_aid.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copie y pegue el código en Thonny. Luego, haga clic en "Ejecutar script actual" o presione F5 para ejecutarlo.
    * Asegúrese de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha.

.. code-block:: python

    # Import required libraries
    from machine import Pin
    import time
    from lcd1602 import LCD
    import _thread

    # Initialize the buzzer
    buzzer = Pin(14, Pin.OUT)

    # Initialize the ultrasonic module
    TRIG = Pin(26, Pin.OUT)
    ECHO = Pin(25, Pin.IN)

    # Initialize the LCD1602 display
    lcd = LCD()

    dis = 100

    # Calculate the distance
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

    # Thread to continuously update the ultrasonic sensor reading
    def ultrasonic_thread():
        global dis
        while True:
            dis = distance()
            
            # Clear the LCD screen
            lcd.clear()
            
            # Display the distance
            lcd.write(0, 0, 'Dis: %.2f cm' % dis)
            time.sleep(0.5)

    # Start the ultrasonic sensor reading thread
    _thread.start_new_thread(ultrasonic_thread, ())

    # Beep function for the buzzer
    def beep():
        buzzer.value(1)
        time.sleep(0.1)
        buzzer.value(0)
        time.sleep(0.1)

    # Initialize the intervals variable
    intervals = 10000000
    previousMills = time.ticks_ms()
    time.sleep(1)

    # Main loop
    while True:
        # Update intervals based on distance
        if dis < 0 and dis > 500:
            pass
        elif dis <= 10:
            intervals = 300
        elif dis <= 20:
            intervals = 500
        elif dis <= 50:
            intervals = 1000
        else:
            intervals = 2000

        # Print the distance if it's not -1
        if dis != -1:
            print('Distance: %.2f' % dis)
        time.sleep_ms(100)

        # Check if it's time to beep
        currentMills = time.ticks_ms()
        if time.ticks_diff(currentMills, previousMills) >= intervals:
            beep()
            previousMills = currentMills


* Cuando el script esté en ejecución, el módulo ultrasónico detectará continuamente la distancia de los obstáculos frente a él y mostrará la distancia en el Shell y en el LCD I2C 1602.
* A medida que el obstáculo se acerca, la frecuencia de los pitidos del zumbador se volverá más rápida.
* La función ``ultrasonic_thread()`` se ejecuta en un hilo separado para que pueda actualizar la medición de distancia continuamente sin bloquear el bucle principal.

.. note::

    Si el código y el cableado son correctos, pero el LCD aún no logra mostrar contenido, puede ajustar el potenciómetro en la parte trasera para aumentar el contraste.
