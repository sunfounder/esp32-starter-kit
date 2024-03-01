.. _py_pir:

5.5 Detección de Movimiento Humano
========================================

El sensor infrarrojo pasivo (sensor PIR) es un sensor común que puede medir la luz infrarroja (IR) emitida por objetos en su campo de visión.
En términos simples, recibe la radiación infrarroja emitida por el cuerpo, detectando así el movimiento de personas y otros animales.
Más específicamente, le indica a la placa de control principal que alguien ha entrado a su habitación.

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

También puede comprarlos por separado en los enlaces a continuación.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Para Entrada
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Para Salida
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::
    
    El pin IO32 no se puede usar **como pin de entrada** en este proyecto porque está internamente conectado a una resistencia de pull-down de 1K, lo que establece su valor predeterminado en 0.

* **Pines de Strapping (Entrada)**

    Los pines de strapping son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo 
    (es decir, reseteo por encendido).

    
    .. list-table::
        :widths: 5 15

        *   - Pines de Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    

    Generalmente, **no se recomienda usarlos como pines de entrada**. Si desea usar estos pines, considere el impacto potencial en el proceso de arranque. Para más detalles, por favor refiérase a la sección :ref:`esp32_strapping`.


**Esquemático**

.. image:: ../../img/circuit/circuit_5.5_pir.png

Cuando el módulo PIR detecta movimiento, IO14 se activará, y el LED se encenderá. De lo contrario, cuando no se detecta movimiento, IO14 estará bajo, y el LED se apagará.

.. note::
    El módulo PIR tiene dos potenciómetros: uno ajusta la sensibilidad, el otro ajusta la distancia de detección. Para que el módulo PIR funcione mejor, necesita girar ambos en sentido antihorario hasta el final.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**Conexión**

.. image:: ../../img/wiring/5.5_pir_bb.png

**Código**

.. note::

    * Abra el archivo ``5.5_detect_human_movement.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copie y pegue el código en Thonny. Luego, haga clic en "Ejecutar script actual" o presione F5 para ejecutarlo.
    * Asegúrese de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    import machine
    import time

    # Define pins
    PIR_PIN = 14    # PIR sensor
    LED_PIN = 26    # LED

    # Initialize the PIR sensor pin as an input pin
    pir_sensor = machine.Pin(PIR_PIN, machine.Pin.IN, machine.Pin.PULL_DOWN)
    # Initialize the LED pin as an output pin
    led = machine.Pin(LED_PIN, machine.Pin.OUT)

    # Global flag to indicate motion detected
    motion_detected_flag = False

    # Function to handle the interrupt
    def motion_detected(pin):
        global motion_detected_flag
        print("Motion detected!")
        motion_detected_flag = True

    # Attach the interrupt to the PIR sensor pin
    pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    # Main loop
    while True:
        if motion_detected_flag:
            led.value(1)  # Turn on the LED
            time.sleep(5)  # Keep the LED on for 5 seconds
            led.value(0)  # Turn off the LED
            motion_detected_flag = False

Cuando el script esté ejecutándose, el LED se encenderá durante 5 segundos y luego se apagará cuando el módulo PIR detecte a alguien pasando.

.. note::

    El módulo PIR tiene dos potenciómetros: uno ajusta la sensibilidad, el otro ajusta la distancia de detección. Para que el módulo PIR funcione mejor, necesita girar ambos en sentido antihorario hasta el final.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center




**¿Cómo funciona?**


Este código establece un sistema simple de detección de movimiento usando un sensor PIR y un LED. Cuando se detecta movimiento, el LED se encenderá durante 5 segundos.

Aquí hay un desglose del código:

#. Definir la función del manejador de interrupción que se ejecutará cuando se detecte movimiento:

    .. code-block:: python

        def motion_detected(pin):
            global motion_detected_flag
            print("Motion detected!")
            motion_detected_flag = True

#. Adjuntar la interrupción al pin del sensor PIR, con el disparador establecido en "ascendente" (es decir, cuando el pin pasa de un voltaje bajo a alto):

    .. code-block:: python

        pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    Esto configura una interrupción en el pin ``pir_sensor``, que está conectado al sensor de movimiento PIR.

    Aquí hay una explicación detallada de los parámetros:

    * ``trigger=machine.Pin.IRQ_RISING``: Este parámetro establece la condición de disparo para la interrupción. En este caso, la interrupción se disparará en un borde ascendente. Un borde ascendente es cuando el voltaje en el pin cambia de un estado bajo (0V) a un estado alto (típicamente 3.3V o 5V, dependiendo de su hardware). Para un sensor de movimiento PIR, cuando se detecta movimiento, el pin de salida generalmente pasa de bajo a alto, haciendo que el borde ascendente sea una condición de disparo adecuada.

    * ``handler=motion_detected``: Este parámetro especifica la función que se ejecutará cuando se dispare la interrupción. En este caso, la función ``motion_detected`` se proporciona como el manejador de interrupción. Esta función será llamada automáticamente cuando se detecte la condición de interrupción (borde ascendente) en el pin ``pir_sensor``.

    Entonces, esta línea de código configura el sensor PIR para llamar a la función ``motion_detected`` siempre que el sensor detecte movimiento, debido a que el pin de salida pasa de un estado bajo a un estado alto.



#. En el bucle principal, si la ``motion_detected_flag`` se establece en ``True``, el LED se encenderá durante 5 segundos y luego se apagará. La bandera luego se restablece a ``False`` para esperar el próximo evento de movimiento.

    .. code-block:: python

        while True:
            if motion_detected_flag:
                led.value(1)  # Turn on the LED
                time.sleep(5)  # Keep the LED on for 5 seconds
                led.value(0)  # Turn off the LED
                motion_detected_flag = False
