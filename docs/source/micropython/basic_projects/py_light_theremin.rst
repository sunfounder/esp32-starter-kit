.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_light_theremin:

6.3 Teremín de Luz
=========================

El teremín es un instrumento musical electrónico que no requiere contacto físico. Basado en la posición de la mano del intérprete, produce diferentes tonos.

Su sección de control usualmente está compuesta por dos antenas metálicas que detectan la posición de las manos del tereminista y controlan los osciladores con una mano y el volumen con la otra. Las señales eléctricas del teremín se amplifican y envían a un altavoz.

No podemos reproducir el mismo instrumento a través del ESP32, pero podemos usar un fotorresistor y un zumbador pasivo para lograr una jugabilidad similar.

* `Teremín - Wikipedia <https://en.wikipedia.org/wiki/Theremin>`_

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Esquemático**

.. image:: ../../img/circuit/circuit_6.3_light_theremin.png

Antes de comenzar el proyecto, calibra el rango de intensidad de luz moviendo tu mano sobre el fotorresistor. El LED conectado a IO26 se usa como indicador durante el proceso de calibración. Cuando el LED se enciende, significa el inicio de la calibración, y cuando se apaga, indica el fin de la calibración.

A medida que mueves tu mano sobre el fotorresistor, el valor de este cambiará en consecuencia.
Utiliza este cambio para controlar el zumbador y reproducir diferentes notas musicales.
Cada variación en el valor del fotorresistor puede mapearse a una nota musical específica, permitiendo
que el zumbador produzca una melodía mientras mueves tu mano sobre el fotorresistor.


**Conexión**

.. image:: ../../img/wiring/6.3_theremin_bb.png

**Código**

.. note::

    * Abre el archivo ``6.3_light_theremin.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 


.. code-block:: python

    from machine import Pin, PWM, ADC
    import time

    # Inicializar el pin del LED
    led = Pin(26, Pin.OUT)

    # Inicializar el sensor de luz
    sensor = ADC(Pin(35))
    sensor.atten(ADC.ATTN_11DB)

    # Inicializar el zumbador
    buzzer = PWM(Pin(13), freq=440, duty=0)

    light_low=4095
    light_high=0

    # Mapear el intervalo de valores de entrada a valores de salida
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Crear un tono usando el pin especificado, frecuencia y duración
    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty(512)
        time.sleep_ms(duration)
        pin.duty(0)

    # Calibrar los valores máximos y mínimos del fotorresistor en 5 segundos.
    timer_init_start = time.ticks_ms()
    led.value(1) # encender el LED   
    while time.ticks_diff(time.ticks_ms(), timer_init_start)<5000:
        light_value = sensor.read()
        if light_value > light_high:
            light_high = light_value
        if light_value < light_low:
            light_low = light_value   
    led.value(0) # apagar el LED 

    # Reproducir los tonos basados en los valores de luz
    while True:
        light_value  = sensor.read()
        pitch = int(interval_mapping(light_value,light_low,light_high,50,6000))
        if pitch > 50 :
            tone(buzzer,pitch,20)
        time.sleep_ms(10)


Al iniciar el programa, el LED se enciende, brindándonos una ventana de cinco segundos para calibrar el rango de detección del fotorresistor.

La calibración es un paso crucial ya que tiene en cuenta las diferentes condiciones de iluminación que podemos encontrar mientras usamos el dispositivo, 
como las variaciones de intensidad de luz durante diferentes momentos del día. 
Además, el proceso de calibración toma en cuenta la distancia entre nuestras manos 
y el fotorresistor, lo que determina el rango de juego del instrumento.

Una vez que el período de calibración termina, el LED se apaga, indicando que ahora podemos tocar el instrumento moviendo nuestras manos sobre el fotorresistor. 
Esta configuración nos permite crear música ajustando la altura de nuestras manos, proporcionando una experiencia interactiva y disfrutable.
