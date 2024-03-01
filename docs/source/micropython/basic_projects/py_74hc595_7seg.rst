.. _py_7_segment:

2.5 Visualización de Números
==============================

¡Bienvenidos a este fascinante proyecto! En este proyecto, exploraremos el encantador mundo de mostrar números del 0 al 9 en una pantalla de siete segmentos.

Imagina activar este proyecto y ser testigo de cómo una pequeña y compacta pantalla brilla intensamente mostrando cada número del 0 al 9. Es como tener una mini pantalla que exhibe los dígitos de una manera cautivadora. Controlando los pines de señal, puedes cambiar sin esfuerzo el número mostrado y crear varios efectos atractivos.

A través de conexiones de circuito simples y programación, aprenderás cómo interactuar con la pantalla de siete segmentos y dar vida a los números que desees. Ya sea un contador, un reloj o cualquier otra aplicación intrigante, la pantalla de siete segmentos será tu fiel compañera, añadiendo un toque de brillantez a tus proyectos.

**Componentes Requeridos**

Para este proyecto, necesitaremos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ARTÍCULOS EN ESTE KIT
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
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Pines Disponibles**

Aquí tienes una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_2.5_74hc595_7_segment.png

Aquí el principio de cableado es básicamente el mismo que en :ref:`py_74hc595`, la única diferencia es que Q0-Q7 están conectados a los pines a ~ g de la Pantalla de 7 Segmentos.

.. list-table:: Cableado
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - Pantalla de Segmento LED
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**Cableado**

.. image:: ../../img/wiring/2.5_segment_bb.png

**Código**

.. note::

    * Abre el archivo ``2.5_number_display.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Run Current Script" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 

.. code-block:: python

    import machine
    import time

    # Define the segment code for a common anode 7-segment display
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

    # Initialize the pins for the 74HC595 shift register
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    # Define the hc595_shift function to shift data into the 74HC595 shift register
    def hc595_shift(dat):
        # Set the RCLK pin to low
        rclk.off()
        
        # Iterate through each bit (from 7 to 0)
        for bit in range(7, -1, -1):
            # Extract the current bit from the input data
            value = 1 & (dat >> bit)
            
            # Set the SRCLK pin to low
            srclk.off()
            
            # Set the value of the SDI pin
            sdi.value(value)
            
            # Clock the current bit into the shift register by setting the SRCLK pin to high
            srclk.on()
            
        # Latch the data into the storage register by setting the RCLK pin to high
        rclk.on()

    # Continuously loop through the numbers 0 to 9 and display them on the 7-segment display
    while True:
        for num in range(10):
            hc595_shift(SEGCODE[num])  # Shift the segment code for the current number into the 74HC595
            time.sleep_ms(500)  # Wait 500 milliseconds before displaying the next number


    

Cuando el script esté en ejecución, podrás ver cómo el Display de Segmentos LED muestra los números del 0 al 9 en secuencia.

**¿Cómo funciona?**

En este proyecto, utilizamos la función ``hc595_shift()`` para escribir el número binario en el registro de desplazamiento.

Supongamos que el Display de 7 segmentos muestra el número "2". Este patrón de bits corresponde a los segmentos **f**, **c** y **dp** apagados (bajo), mientras que los segmentos **a**, **b**, **d**, **e** y **g** están encendidos (alto). Esto es "01011011" en binario y "0x5b" en notación hexadecimal.

Por lo tanto, necesitarías llamar a **hc595_shift(0x5b)** para mostrar el número "2" en el display de 7 segmentos.

.. image:: img/7_segment2.png


* `Hexadecimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `Conversor BinarioHex <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

La siguiente tabla muestra los patrones hexadecimales que deben escribirse en el registro de desplazamiento para mostrar los números del 0 al 9 en un display de 7 segmentos.


.. list-table:: Código de Glifo
    :widths: 20 20 20
    :header-rows: 1

    *   - Números	
        - Código Binario
        - Código Hex  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Escribe estos códigos en ``hc595_shift()`` para que el Display de Segmentos LED muestre los números correspondientes.
