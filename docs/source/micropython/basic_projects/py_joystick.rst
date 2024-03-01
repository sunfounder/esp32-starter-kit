.. _py_joystick:

5.11 Alternar el Joystick
================================

Si juegas muchos videojuegos, entonces deberías estar muy familiarizado con el Joystick.
Se utiliza habitualmente para mover el personaje, rotar la pantalla, etc.

El principio detrás de la capacidad del Joystick para permitir que la computadora lea nuestras acciones es muy simple.
Se puede pensar como compuesto por dos potenciómetros que están perpendiculares entre sí.
Estos dos potenciómetros miden el valor analógico del joystick vertical y horizontalmente, resultando en un valor (x,y) en un sistema de coordenadas planas en ángulo recto.


El joystick de este kit también tiene una entrada digital, que se activa cuando se presiona el joystick.

**Componentes Requeridos**

Para este proyecto, necesitaremos los siguientes componentes.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 15

        *   - Para Entrada Analógica
            - IO14, IO25, I35, I34, I39, I36
        *   - Para Entrada Digital
            - IO13, IO14, IO27, IO26, IO25, IO33, IO4, IO18, IO19, IO21, IO22, IO23

* **Pines de Strapping (Entrada)**

    Los pines de strapping son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo 
    (es decir, reinicio por encendido).

        
    .. list-table::
        :widths: 5 15

        *   - Pines de Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    Generalmente, **no se recomienda usarlos como pines de entrada**. Si deseas usar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, por favor refiérete a la sección :ref:`esp32_strapping`.

**Esquemático**

.. image:: ../../img/circuit/circuit_5.11_joystick.png

El pin SW (eje Z) está conectado a IO33, que tiene una resistencia pull-up de 4.7K incorporada. Por lo tanto, cuando el botón SW no está presionado, emitirá un nivel alto. Cuando el botón está presionado, emitirá un nivel bajo.

I34 e I35 cambiarán sus valores a medida que manipules el joystick. El rango de valores es de 0 a 4095.

**Conexión**

.. image:: ../../img/wiring/5.11_joystick_bb.png

**Código**

.. note::

    * Abre el archivo ``5.11_joystick.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 

.. code-block:: python

    from machine import ADC,Pin
    import time

    xAxis = ADC(Pin(34, Pin.IN)) # create an ADC object acting on a pin      
    xAxis.atten(xAxis.ATTN_11DB)
    yAxis = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      
    yAxis.atten(yAxis.ATTN_11DB)
    button = Pin(33, Pin.IN, Pin.PULL_UP)

    while True:
        xValue = xAxis.read()  # read a raw analog value in the range 0-4095
        yValue = yAxis.read()  # read a raw analog value in the range 0-4095
        btnValue = button.value()
        print(f"X:{xValue}, Y:{yValue}, Button:{btnValue}")
        time.sleep(0.1)

Cuando el programa se ejecuta, la Shell imprime los valores x, y y del botón del joystick.

.. code-block:: 

    X:1921, Y:1775, Button:0
    X:1921, Y:1775, Button:0
    X:1923, Y:1775, Button:0
    X:1924, Y:1776, Button:0
    X:1926, Y:1777, Button:0
    X:1925, Y:1776, Button:0
    X:1924, Y:1776, Button:0


* Los valores de los ejes x e y son valores analógicos que varían de 0 a 4095.
* El botón es un valor digital con un estado de 1(suelto) o 0(presionado).

    .. image:: img/joystick_direction.png