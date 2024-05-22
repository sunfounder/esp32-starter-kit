.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_pa_buz:

3.2 Tono Personalizado
==========================================

Hemos utilizado un zumbador activo en el proyecto anterior, esta vez usaremos un zumbador pasivo.

Al igual que el zumbador activo, el zumbador pasivo también utiliza el fenómeno de inducción electromagnética para funcionar. La diferencia es que un zumbador pasivo no tiene fuente oscilante, por lo que no emitirá un pitido si se utilizan señales de CC.
Pero esto permite que el zumbador pasivo ajuste su propia frecuencia de oscilación y pueda emitir diferentes notas como "do, re, mi, fa, sol, la, si".

¡Hagamos que el zumbador pasivo emita una melodía!

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Esquemático**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

Cuando la salida IO14 es alta, después de la resistencia limitadora de corriente de 1K (para proteger el transistor), el S8050 (transistor NPN) conducirá, haciendo que el zumbador suene.

El papel de S8050 (transistor NPN) es amplificar la corriente y hacer que el zumbador suene más fuerte. De hecho, también puedes conectar el zumbador directamente a IO14, pero encontrarás que el sonido del zumbador es más bajo.

**Conexión**

El kit incluye dos tipos de zumbadores.
Necesitamos usar el zumbador activo. Voltéalos, el lado sellado (no el PCB expuesto) es el que queremos.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

El zumbador necesita usar un transistor cuando funciona, aquí usamos S8050 (Transistor NPN).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Código**

.. note::

    * Abre el archivo ``3.2_custom_tone.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 

.. code-block:: python

    import machine
    import time

    # Define the frequencies of several musical notes in Hz
    C4 = 262
    D4 = 294
    E4 = 330
    F4 = 349
    G4 = 392
    A4 = 440
    B4 = 494

    # Create a PWM object representing pin 14 and assign it to the buzzer variable
    buzzer = machine.PWM(machine.Pin(14))

    # Define a tone function that takes as input a Pin object representing the buzzer, a frequency in Hz, and a duration in milliseconds
    def tone(pin, frequency, duration):
        pin.freq(frequency) # Set the frequency
        pin.duty(512) # Set the duty cycle
        time.sleep_ms(duration) # Pause for the duration in milliseconds
        pin.duty(0) # Set the duty cycle to 0 to stop the tone

    # Play a sequence of notes with different frequency inputs and durations
    tone(buzzer, C4, 250)
    time.sleep_ms(500)
    tone(buzzer, D4, 250)
    time.sleep_ms(500)
    tone(buzzer, E4, 250)
    time.sleep_ms(500)
    tone(buzzer, F4, 250)
    time.sleep_ms(500)
    tone(buzzer, G4, 250)
    time.sleep_ms(500)
    tone(buzzer, A4, 250)
    time.sleep_ms(500)
    tone(buzzer, B4, 250)


**¿Cómo funciona?**

Si al zumbador pasivo se le da una señal digital, solo puede continuar empujando el diafragma sin producir sonido.

Por lo tanto, utilizamos la función ``tone()`` para generar la señal PWM y hacer que el zumbador pasivo emita sonido.

Esta función tiene tres parámetros:

* ``pin``: El pin que controla el zumbador.
* ``frecuencia``: El tono del zumbador está determinado por la frecuencia; cuanto mayor sea la frecuencia, más alto será el tono.
* ``Duración``: La duración del tono.

Usamos la función ``duty()`` para establecer el ciclo de trabajo en 512 (alrededor del 50%). Puede ser otros números, y solo necesita generar una señal eléctrica discontinua para oscilar.



**Aprender Más**



Podemos simular tonos específicos y así reproducir una pieza musical completa.


.. note::

    * Abre el archivo ``3.2_custom_tone_music.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha.



.. code-block:: python

    import machine
    import time

    # Define the GPIO pin that is connected to the buzzer
    buzzer = machine.PWM(machine.Pin(14))

    # Define the frequencies of the notes in Hz
    C5 = 523
    D5 = 587
    E5 = 659
    F5 = 698
    G5 = 784
    A5 = 880
    B5 = 988

    # Define the durations of the notes in milliseconds
    quarter_note = 250
    half_note = 300
    whole_note = 1000

    # Define the melody as a list of tuples (note, duration)
    melody = [
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (E5, quarter_note),
        (D5, quarter_note),
        (D5, half_note),
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (D5, quarter_note),
        (C5, quarter_note),
        (C5, half_note),

    ]

    # Define a function to play a note with the given frequency and duration
    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty(512)
        time.sleep_ms(duration)
        pin.duty(0)

    # Play the melody
    for note in melody:
        tone(buzzer, note[0], note[1])
        time.sleep_ms(50)


* La función ``tone`` establece la frecuencia del pin al valor de ``frecuencia`` usando el método ``freq`` del objeto ``pin``.
* Luego establece el ciclo de trabajo del pin en 512 usando el método ``duty`` del objeto ``pin``.
* Esto hará que el pin produzca un tono con la frecuencia y volumen especificados durante la duración de ``duración`` en milisegundos usando el método ``sleep_ms`` del módulo de tiempo.
* El código luego reproduce una melodía iterando a través de una secuencia llamada ``melody`` y llamando a la función ``tone`` para cada nota en la melodía con la frecuencia y duración de la nota.
* También inserta una breve pausa de 50 milisegundos entre cada nota usando el método ``sleep_ms`` del módulo de tiempo.
