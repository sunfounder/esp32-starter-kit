.. _py_74hc595:

2.4 Microchip - 74HC595
===========================

¡Bienvenidos a este emocionante proyecto! En este proyecto, utilizaremos el chip 74HC595 para controlar una secuencia fluida de 8 LEDs.

Imagina activar este proyecto y ser testigo de un flujo hipnotizante de luz, como si un arcoíris chispeante saltara entre los 8 LEDs. Cada LED se iluminará uno tras otro y se apagará rápidamente, mientras el siguiente LED sigue brillando, creando un efecto dinámico y espléndido.

Mediante el uso ingenioso del chip 74HC595, podemos controlar los estados de encendido y apagado de múltiples LEDs para lograr el efecto fluido. Este chip tiene múltiples pines de salida que pueden conectarse en serie para controlar la secuencia de iluminación de los LEDs. Además, gracias a la capacidad de expansión del chip, podemos añadir fácilmente más LEDs a la secuencia, creando efectos aún más espectaculares.

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

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DE COMPONENTES
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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Pines Disponibles**

Aquí tienes una lista de los pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_2.4_74hc595_led.png
    :width: 600

* Cuando MR (pin10) está en alto y CE (pin13) en bajo, los datos se ingresan en el flanco ascendente de SHcp y pasan al registro de memoria a través del flanco ascendente de SHcp. 
* Si los dos relojes están conectados juntos, el registro de desplazamiento siempre está un pulso antes que el registro de memoria. 
* Hay un pin de entrada de desplazamiento serial (DS), un pin de salida serial (Q7') y un botón de reinicio asincrónico (nivel bajo) en el registro de memoria. 
* El registro de memoria produce un Bus con 8 bits paralelos y en tres estados. 
* Cuando OE está activado (nivel bajo), los datos en el registro de memoria se envían al bus (Q0 ~ Q7).

**Cableado**

.. image:: ../../img/wiring/2.4_74hc595_bb.png
    :width: 800

**Código**

.. note::

    * Abre el archivo ``2.4_microchip_74hc595.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 

.. code-block:: python

    import machine
    import time

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

    num = 0

    # Shift data into the 74HC595 to create a moving LED pattern
    for i in range(16):
        if i < 8:
            num = (num << 1) + 1  # Shift left and set the least significant bit to 1
        elif i >= 8:
            num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
        hc595_shift(num)  # Shift the current value into the 74HC595
        print("{:0>8b}".format(num))  # Print the current value in binary format
        time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value




Durante la ejecución del script, verás cómo se iluminan los LEDs uno por uno y luego se apagan en el orden original.

**¿Cómo funciona?**

Este código se utiliza para controlar un registro de desplazamiento de 8 bits (74595) y emitir diferentes valores binarios al registro de desplazamiento, con cada valor mostrado en un LED por un cierto período de tiempo.

#. El código importa los módulos ``machine`` y ``time``, donde el módulo ``machine`` se utiliza para controlar E/S de hardware, y el módulo ``time`` se utiliza para implementar retrasos de tiempo y otras funciones.

    .. code-block:: python

        import machine
        import time

#. Tres puertos de salida se inicializan usando la función ``machine.Pin()``, correspondiendo al puerto de datos (SDI), puerto de reloj de almacenamiento (RCLK) y puerto de reloj del registro de desplazamiento (SRCLK) del registro de desplazamiento.

    .. code-block:: python

        # Initialize the pins for the 74HC595 shift register
        sdi = machine.Pin(25, machine.Pin.OUT)  # DS
        rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
        srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

#. Se define una función llamada ``hc595_shift()`` para escribir un dato de 8 bits en el registro de desplazamiento.

    .. code-block:: python

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

#. Acerca del bucle ``for``.

    .. code-block:: python

        for i in range(16):
                if i < 8:
                    num = (num << 1) + 1  # Shift left and set the least significant bit to 1
                elif i >= 8:
                    num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
                hc595_shift(num)  # Shift the current value into the 74HC595
                print("{:0>8b}".format(num))  # Print the current value in binary format
                time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value

    * La variable ``i`` se utiliza para controlar el valor binario de salida. En las primeras 8 iteraciones, el valor de num será sucesivamente 00000001, 00000011, 00000111, ..., 11111111, que se desplaza a la izquierda por un bit y luego se suma 1.
    * En las iteraciones del 9 al 16, el bit más alto de 1 se cambia primero a 0, y luego se desplaza a la izquierda por un bit, resultando en los valores de salida de 00000010, 00000100, 00001000, ..., 10000000.
    * En cada iteración, el valor de ``num`` se pasa a la función ``hc595_shift()`` para controlar el registro de desplazamiento para emitir el valor binario correspondiente.
    * Al mismo tiempo que se emite el valor binario, la función ``print()`` muestra el valor binario como una cadena en el terminal.
    * Después de emitir el valor binario, el programa hace una pausa durante 200 milisegundos usando la función ``time.sleep_ms()``, para que el valor en el LED permanezca mostrado por un cierto período de tiempo.
