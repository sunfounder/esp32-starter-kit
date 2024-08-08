.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _py_line_track:

5.4 Detección de Líneas
===================================

El módulo de seguimiento de líneas se utiliza para detectar la presencia de áreas negras en el suelo, como líneas negras pegadas con cinta aislante.

Su emisor emite luz infrarroja adecuada hacia el suelo, la cual es absorbida en mayor medida y reflejada débilmente por superficies negras. Lo contrario ocurre con las superficies blancas. Si se detecta luz reflejada, se indica que el suelo es blanco actualmente. Si no se detecta, se indica como negro.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|
        
**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Pines Disponibles
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Pines de Strapping (Entrada)**

    Los pines de strapping son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo 
    (es decir, reinicio por encendido).

        
    .. list-table::
        :widths: 5 15

        *   - Pines de Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    Generalmente, **no se recomienda usarlos como pines de entrada**. Si deseas usar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, por favor consulta la sección :ref:`esp32_strapping`.

**Esquemático**

.. image:: ../../img/circuit/circuit_5.4_line.png

Cuando el módulo de seguimiento de línea detecta una línea negra, IO14 devuelve un nivel alto. Por otro lado, cuando detecta una línea blanca, IO14 devuelve un nivel bajo. Puedes ajustar el potenciómetro azul para modificar la sensibilidad de detección de este módulo.


**Conexión**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**Código**

.. note::

    * Abre el archivo ``5.4_detect_the_line.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 


.. code-block:: python

    import machine
    import time

    # Create a pin object named greyscale, set pin number 14 as input
    line = machine.Pin(14, machine.Pin.IN)


    while True:
        # Check if the value is 1 (black)
        if line.value() == 1:
            # Print "black"
            print("black")
            time.sleep(0.5)
        # If the value is not 1 (it's 0, which means white)
        else :
            # Print "white"
            print("white")
            time.sleep(0.5)



Cuando el módulo de seguimiento de línea detecta que hay una línea negra, aparece "negro" en la consola; de lo contrario, se muestra "blanco".