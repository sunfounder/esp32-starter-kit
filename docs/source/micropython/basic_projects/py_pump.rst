.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_pump:

4.2 Bombeo
=======================

En este intrigante proyecto, exploraremos cómo controlar una bomba de agua usando el L293D.

En el ámbito del control de bombas de agua, las cosas son un poco más sencillas en comparación con el control de otros motores. La belleza de este proyecto radica en su simplicidad: no hay necesidad de preocuparse por la dirección de rotación. Nuestro objetivo principal es activar con éxito la bomba de agua y mantenerla funcionando.

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
    *   - :ref:`cpn_pump`
        - \-
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

    Se recomienda aquí insertar la batería y luego deslizar el interruptor en la placa de expansión a la posición ON para activar el suministro de la batería.


.. image:: ../../img/wiring/4.2_pump_l293d_bb.png

**Código**

.. note::

    * Abre el archivo ``4.2_pumping.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    import machine
    import time

    # Crear objetos Pin que representan los pines de control del motor y configurarlos en modo de salida
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Definir una función para rotar la bomba
    def rotate():
        motor1A.value(1)
        motor2A.value(0)

    # Definir una función para detener la bomba
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    try:
        while True:
            rotate()  # Rotar el motor en sentido horario
            time.sleep(5)  # Pausar durante 5 segundos
            stop()  # Detener el motor
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Detener el motor cuando se captura KeyboardInterrupt




Durante la ejecución del script, verás la bomba funcionando y el agua saliendo del tubo, luego se detendrá durante 2 segundos antes de comenzar a funcionar de nuevo.
