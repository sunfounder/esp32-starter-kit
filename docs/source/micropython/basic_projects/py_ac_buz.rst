.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_ac_buz:

3.1 Pitido
==================
Este es un proyecto simple para hacer que un zumbador activo emita un pitido rápidamente cuatro veces cada segundo.

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
        - |link_esp32_extension_board|
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

Aquí tienes una lista de los pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

Cuando la salida IO14 es alta, después de la resistencia limitadora de corriente de 1K (para proteger el transistor), el S8050 (transistor NPN) conducirá, haciendo que el zumbador suene.

El rol del S8050 (transistor NPN) es amplificar la corriente y hacer que el zumbador suene más fuerte. De hecho, también puedes conectar el zumbador directamente a IO14, pero encontrarás que el sonido del zumbador es menor.

**Cableado**


El kit incluye dos tipos de zumbadores.
Necesitamos usar el zumbador activo. Gíralos, el que tiene la parte trasera sellada (no el PCB expuesto) es el que queremos.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

El zumbador necesita usar un transistor para funcionar, aquí usamos S8050 (Transistor NPN).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Código**

.. note::

    * Abre el archivo ``3.1_beep.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 




.. code-block:: python

    import machine
    import time

    # Create a Pin object representing pin 14 and set it to output mode
    buzzer = machine.Pin(14, machine.Pin.OUT)

    # Enter an infinite loop
    while True:
        # Iterate over the values 0 to 3 using a for loop
        for i in range(4):
            # Turn on the buzzer by setting its value to 1
            buzzer.value(1)
            # Pause for 0.2 seconds
            time.sleep(0.2)
            # Turn off the buzzer
            buzzer.value(0)
            # Pause for 0.2 seconds
            time.sleep(0.2)
        # Pause for 1 second before restarting the for loop
        time.sleep(1)


Cuando el script está en ejecución, el zumbador emitirá un pitido rápidamente cuatro veces cada segundo.