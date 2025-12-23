.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_blink:

2.1 ¡Hola, LED!
=======================================

Así como imprimir "¡Hola, mundo!" es el primer paso para aprender a programar, utilizar un programa para controlar un LED es la introducción tradicional al aprendizaje de la programación física.

**Componentes Requeridos**

En este proyecto, necesitamos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre
        - ARTÍCULOS EN ESTE KIT
        - ENLACE
    *   - Kit de inicio ESP32
        - 320+
        - |link_esp32_starter_kit|

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - DESCRIPCIÓN DEL COMPONENTE
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

**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Esquemático**

.. image:: ../../img/circuit/circuit_2.1_led.png

Este circuito funciona bajo un principio simple, y la dirección de la corriente se muestra en la figura. El LED se encenderá después de la resistencia limitadora de corriente de 220 ohmios cuando el pin26 emita un nivel alto. El LED se apagará cuando el pin26 emita un nivel bajo.

**Conexiones**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**Ejecutar el Código**

#. Abre el archivo ``2.1_hello_led.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny.

    .. code-block:: python

        # Importar las librerías necesarias
        import machine
        import time

        # Configurar el LED en el pin 26 como un pin de salida
        led = machine.Pin(26, machine.Pin.OUT)

        # Iniciar un bucle infinito
        while True:
            # Encender el LED estableciendo su valor en 1 (ALTO)
            led.value(1)
            # Esperar 1 segundo (1000 milisegundos) mientras el LED está encendido
            time.sleep(1)

            # Apagar el LED estableciendo su valor en 0 (BAJO)
            led.value(0)
            # Esperar 0.5 segundos (500 milisegundos) mientras el LED está apagado
            time.sleep(0.5)

#. Conecta la placa ESP32 board a tu computadora usando un cable USB.

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Luego, haz clic en el intérprete "MicroPython (ESP32).COMXX" en la esquina inferior derecha.

   .. note::

      Si no ves otras opciones además de "Local Python 3", es posible que tu computadora no haya reconocido la placa ESP32.
      En ese caso, puede que necesites :ref:`install_driver`.

   .. image:: ../python_start/img/sec_inter.png

#. Finalmente, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.

    .. image:: ../python_start/img/quick_guide2.png

#. Después de que se ejecute el código, verás el LED parpadeando.


**¿Cómo funciona?**

#. Importa dos módulos, ``machine`` y ``time``. El módulo ``machine`` proporciona acceso de bajo nivel al hardware del microcontrolador, mientras que el módulo ``time`` proporciona funciones para operaciones relacionadas con el tiempo.

    .. code-block:: python

        import machine
        import time

#. Luego, configura el pin26 como un pin de salida usando la función ``machine.Pin()`` con el argumento ``machine.Pin.OUT``.

    .. code-block:: python

        led = machine.Pin(26, machine.Pin.OUT)

#. En el bucle ``While True``, el LED se enciende durante un segundo estableciendo el valor del pin26 a 1 usando ``led.value(1)`` y luego se establece a 0 (``led.value(0)``) para apagarlo durante 0.5 segundos, y así sucesivamente en un bucle infinito.

    .. code-block:: python

        while True:
            # Encender el LED estableciendo su valor en 1 (ALTO)
            led.value(1)
            # Esperar 1 segundo (1000 milisegundos) mientras el LED está encendido
            time.sleep(1)

            # Apagar el LED estableciendo su valor en 0 (BAJO)
            led.value(0)
            # Esperar 0.5 segundos (500 milisegundos) mientras el LED está apagado
            time.sleep(0.5)

**Aprende Más**

En este proyecto, utilizamos los módulos ``machine`` y ``time`` de MicroPython. Podemos encontrar más formas de usarlos aquí.

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_

* `time <https://docs.micropython.org/en/latest/library/time.html>`_

