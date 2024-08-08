.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_potentiometer:

5.8 Girar el Pomo
===========================
Un potenciómetro es un dispositivo de tres terminales que se utiliza comúnmente para ajustar la resistencia en un circuito. Cuenta con un pomo o una palanca deslizante que se puede usar para variar el valor de la resistencia del potenciómetro. En este proyecto, lo utilizaremos para controlar el brillo de un LED, similar a una lámpara de escritorio en nuestra vida cotidiana. Al ajustar la posición del potenciómetro, podemos cambiar la resistencia en el circuito, regulando así la corriente que fluye a través del LED y ajustando su brillo en consecuencia. Esto nos permite crear una experiencia de iluminación personalizable y ajustable, similar a la de una lámpara de escritorio.

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 15

        *   - Pines Disponibles
            - IO14, IO25, I35, I34, I39, I36

* **Pines de Strapping**

    Los siguientes pines son pines de strapping, que afectan el proceso de arranque del ESP32 durante el encendido o el reinicio. Sin embargo, una vez que el ESP32 ha arrancado con éxito, pueden ser utilizados como pines regulares.

    .. list-table::
        :widths: 5 15

        *   - Pines de Strapping
            - IO0, IO12


**Esquemático**

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

Al girar el potenciómetro, el valor de I35 cambiará. Mediante programación, puedes usar el valor de I35 para controlar el brillo del LED. Por lo tanto, a medida que gires el potenciómetro, el brillo del LED también cambiará en consecuencia.


**Conexión**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**Código**


.. note::

    * Abre el archivo ``5.8_turn_the_knob.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    from machine import ADC, Pin, PWM
    import time

    pot = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      

    # Configure the ADC attenuation to 11dB for full range
    pot.atten(pot.ATTN_11DB)

    # Create a PWM object
    led = PWM(Pin(26), freq=1000)

    while True:
        # Read a raw analog value in the range of 0-4095
        value = pot.read()

        # Scale the value to the range of 0-1023 for ESP32 PWM duty cycle
        pwm_value = int(value * 1023 / 4095)

        # Update the LED brightness based on the potentiometer value
        led.duty(pwm_value)

        # Read the voltage in microvolts and convert it to volts
        voltage = pot.read_uv() / 1000000

        # Print the raw value and the voltage
        print(f"value: {value}, Voltage: {voltage}V")

        # Wait for 0.5 seconds before taking the next reading
        time.sleep(0.5)

Con este script ejecutado, el brillo del LED cambia a medida que se gira el potenciómetro, mientras que el valor analógico y el voltaje en este punto se muestran en el Shell.

* `machine.ADC - Documentación de MicroPython <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

