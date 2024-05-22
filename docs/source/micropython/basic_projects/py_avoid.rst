.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_ir_obstacle:

5.3 Detección de Obstáculos
===================================

Este módulo se instala comúnmente en coches y robots para determinar la
existencia de obstáculos adelante. También se utiliza ampliamente en dispositivos portátiles, grifos de agua y otros.

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
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí tienes una lista de los pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Pines Disponibles
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Pines de Arranque (Entrada)**

    Los pines de arranque son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo 
    (es decir, reseteo por encendido).
   
    .. list-table::
        :widths: 5 15

        *   - Pines de Arranque
            - IO5, IO0, IO2, IO12, IO15 
    
    Generalmente, **no se recomienda usarlos como pines de entrada**. Si deseas utilizar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, por favor refiérete a la sección :ref:`esp32_strapping`.

**Esquemático**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

Cuando el módulo de evitación de obstáculos no detecta ningún obstáculo, IO14 devuelve un nivel alto. Sin embargo, cuando detecta un obstáculo, devuelve un nivel bajo. Puedes ajustar el potenciómetro azul para modificar la distancia de detección de este módulo.

**Cableado**


.. image:: ../../img/wiring/5.3_avoid_bb.png

**Código**

.. note::

    * Abre el archivo ``5.3_avoid.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    import machine
    import time

    ir_avoid = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_UP) # pin del módulo de evitación

    while True:

        # Imprime los valores del módulo de evitación de obstáculos
        print(ir_avoid.value()) 
        time.sleep(0.1)


Mientras el programa esté en ejecución, si el módulo IR de evitación de obstáculos detecta un obstáculo frente a él, el valor "0" se mostrará en el Monitor Serial, de lo contrario, se mostrará el valor "1".
