.. _py_receiver:

5.14 Control Remoto por Infrarrojos
========================================

Un receptor de infrarrojos es un componente que recibe señales infrarrojas y puede detectar y emitir señales compatibles con el nivel TTL de forma independiente. Su tamaño es similar al de un transistor empaquetado en plástico convencional y se utiliza comúnmente en diversas aplicaciones como el control remoto por infrarrojos y la transmisión infrarroja.

En este proyecto, utilizaremos un receptor de infrarrojos para detectar señales de un control remoto. Cuando se presiona un botón en el control remoto y el receptor de infrarrojos recibe la señal correspondiente, puede decodificar la señal para determinar qué botón fue presionado. Decodificando la señal recibida, podemos identificar la tecla o comando específico asociado con ella.

El receptor de infrarrojos nos permite incorporar la funcionalidad de control remoto en nuestro proyecto, permitiéndonos interactuar con y controlar dispositivos usando señales infrarrojas.

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
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|

**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20

    *   - Pines Disponibles
        - IO13, IO12, IO14, IO27, IO26, IO25, IO15, IO0, IO5, IO18, IO19, IO21, IO22, IO23

**Esquemático**

.. image:: ../../img/circuit/circuit_5.14_receiver.png

Cuando presionas un botón en el control remoto, el receptor de infrarrojos detecta la señal y puedes usar una biblioteca de infrarrojos para decodificarla. Este proceso de decodificación te permite obtener el valor de la tecla asociada con la presión del botón.

**Conexión**

.. image:: ../../img/wiring/5.14_ir_receiver_bb.png

**Código**

.. note::

    * Abre el archivo ``5.14_ir_receiver.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar script actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha.

    * Aquí, necesitas utilizar las bibliotecas encontradas en la carpeta ``ir_rx``. Por favor, asegúrate de que hayan sido cargadas al ESP32. Para un tutorial completo, consulta :ref:`add_libraries_py`.

.. code-block:: python

    import time
    from machine import Pin, freq
    from ir_rx.print_error import print_error
    from ir_rx.nec import NEC_8

    pin_ir = Pin(14, Pin.IN) # IR receiver

    # Decode the received data and return the corresponding key name
    def decodeKeyValue(data):       
        if data == 0x16:
            return "0"
        if data == 0x0C:
            return "1"
        if data == 0x18:
            return "2"
        if data == 0x5E:
            return "3"
        if data == 0x08:
            return "4"
        if data == 0x1C:
            return "5"
        if data == 0x5A:
            return "6"
        if data == 0x42:
            return "7"
        if data == 0x52:
            return "8"
        if data == 0x4A:
            return "9"
        if data == 0x09:
            return "+"
        if data == 0x15:
            return "-"
        if data == 0x7:
            return "EQ"
        if data == 0x0D:
            return "U/SD"
        if data == 0x19:
            return "CYCLE"
        if data == 0x44:
            return "PLAY/PAUSE"
        if data == 0x43:
            return "FORWARD"
        if data == 0x40:
            return "BACKWARD"
        if data == 0x45:
            return "POWER"
        if data == 0x47:
            return "MUTE"
        if data == 0x46:
            return "MODE"
        return "ERROR"

    # User callback
    def callback(data, addr, ctrl):
        if data < 0:  # NEC protocol sends repeat codes.
            pass
        else:
            print(decodeKeyValue(data))
            

    ir = NEC_8(pin_ir, callback) # Instantiate the NEC_8 receiver

    # Show debug information
    ir.error_function(print_error)  

    # keep the script running until interrupted by a keyboard interrupt (Ctrl+C)
    try:
        while True:
            pass
    except KeyboardInterrupt:
        ir.close()  # Close the receiver

Cuando el programa esté en ejecución, presiona la tecla en el control remoto, el valor y el nombre de la tecla aparecerán en la Shell.

.. note::
    El nuevo control remoto cuenta con una lengüeta de plástico en el extremo para aislar la batería en su interior. Para activar el control remoto al usarlo, simplemente retira esta pieza de plástico.

**¿Cómo funciona?**

#. Aunque este programa pueda parecer algo complejo a primera vista, en realidad realiza las funciones fundamentales del receptor IR utilizando solo unas pocas líneas de código.


    .. code-block:: python

        import time
        from machine import Pin, freq
        from ir_rx.nec import NEC_8

        pin_ir = Pin(14, Pin.IN) # IR receiver

        # User callback
        def callback(data, addr, ctrl):
            if data < 0:  # NEC protocol sends repeat codes.
                pass
            else:
                print(decodeKeyValue(data))

        ir = NEC_8(pin_ir, callback)  # Instantiate receiver

    * En este código, se instancia un objeto ``ir``, permitiéndole leer las señales capturadas por el receptor IR en cualquier momento.
    * La información resultante se almacena entonces en la variable ``data`` dentro de la función de callback.

        * `Función de Callback - Wikipedia <https://en.wikipedia.org/wiki/Callback_(computer_programming)>`_

    * Si el receptor IR recibe valores duplicados (por ejemplo, cuando se presiona un botón y se mantiene presionado), el ``data`` será menor que 0, y este ``data`` necesita ser filtrado.

    * De lo contrario, el ``data`` sería un valor utilizable, aunque en un código ilegible. La función ``decodeKeyValue(data)`` se utiliza entonces para decodificarlo en un formato más comprensible.

        .. code-block:: python

            def decodeKeyValue(data):
                if data == 0x16:
                    return "0"
                if data == 0x0C:
                    return "1"
                if data == 0x18:
                    return "2"
                if data == 0x5E:
                ...


#. A continuación, incorporamos varias funciones de depuración en el programa. Aunque estas funciones son esenciales, no están directamente relacionadas con el resultado deseado que buscamos lograr.

    .. code-block:: python

        from ir_rx.print_error import print_error

        ir.error_function(print_error) # Show debug information

#. Por último, utilizamos un bucle vacío para el programa principal e implementamos una estructura try-except para asegurar que el programa salga con el objeto ``ir`` correctamente terminado.

    .. code-block:: python

        try:
            while True:
                pass
        except KeyboardInterrupt:
            ir.close()

    * `Try Statement - Python Docs <https://docs.python.org/3/reference/compound_stmts.html?#the-try-statement>`_