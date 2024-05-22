.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_tilt:

5.2 ¡Inclínalo!
==========================
El interruptor de inclinación es un dispositivo simple pero efectivo de 2 pines que contiene una bola metálica en su centro. Cuando el interruptor está en posición vertical, los dos pines están eléctricamente conectados, permitiendo que la corriente fluya. Sin embargo, cuando el interruptor se inclina o se inclina a cierto ángulo, la bola metálica se mueve y rompe la conexión eléctrica entre los pines.

En este proyecto, utilizaremos el interruptor de inclinación para controlar la iluminación de un LED. Posicionando el interruptor de manera que se active la acción de inclinación, podemos alternar el LED encendido y apagado basado en la orientación del interruptor.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_tilt`
        - \-

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Para Entrada
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Para Salida
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Pines de Uso Condicional (Entrada)**

    Los siguientes pines tienen resistencias de pull-up o pull-down integradas, por lo que no se requieren resistencias externas cuando **se usan como pines de entrada**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Pines de Uso Condicional
            - Descripción
        *   - IO13, IO15, IO2, IO4
            - Pull-up con una resistencia de 47K por defecto el valor es alto.
        *   - IO27, IO26, IO33
            - Pull-up con una resistencia de 4.7K por defecto el valor es alto.
        *   - IO32
            - Pull-down con una resistencia de 1K por defecto el valor es bajo.

* **Pines de Configuración (Entrada)**

    Los pines de configuración son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo 
    (es decir, reseteo al encender).

    
    .. list-table::
        :widths: 5 15

        *   - Pines de Configuración
            - IO5, IO0, IO2, IO12, IO15 
    

    

    Generalmente, **no se recomienda usarlos como pines de entrada**. Si deseas usar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, por favor consulta la sección :ref:`esp32_strapping`.


**Esquemático**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

Cuando el interruptor de inclinación está en posición vertical, IO14 se establecerá en alto, resultando en que el LED se ilumine. Por el contrario, cuando el interruptor de inclinación se inclina, IO14 se establecerá en bajo, causando que el LED se apague.

El propósito de la resistencia de 10K es mantener un estado bajo estable para IO14 cuando el interruptor de inclinación está en posición inclinada.


**Conexión**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

**Código**

.. note::

    * Abre el archivo ``5.2_tilt_switch.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    import machine
    import time

    switch = machine.Pin(14, machine.Pin.IN) # Tilt switch pin
    led = machine.Pin(26, machine.Pin.OUT) # LED pin

    while True:
        # Check if the switch is tilted by reading its value
        if switch.value() == 1:
            # Turn on the LED by setting its value to 1
            led.value(1)
        else:
            # Turn off the LED
            led.value(0)

Cuando el script está en ejecución, el LED se encenderá cuando el interruptor esté vertical y se apagará cuando el interruptor se incline.


