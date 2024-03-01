.. _py_transistor:

5.6 Dos Tipos de Transistores
==========================================
Este kit está equipado con dos tipos de transistores, S8550 y S8050, siendo el primero PNP y el segundo NPN. Se parecen mucho, y necesitamos verificar cuidadosamente para ver sus etiquetas.
Cuando una señal de nivel alto pasa a través de un transistor NPN, se activa. Pero uno PNP necesita una señal de nivel bajo para gestionarlo. Ambos tipos de transistor se usan frecuentemente para interruptores sin contacto, justo como en este experimento.

¡Usemos un LED y un botón para entender cómo usar un transistor!

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

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



**Forma de conectar el transistor NPN (S8050)**

.. image:: ../../img/circuit/circuit_5.6_S8050.png

En este circuito, cuando se presiona el botón, IO14 está alto.

Programando IO26 para que emita **alto**, después de una resistencia limitadora de corriente de 1k (para proteger el transistor), se permite que el S8050 (transistor NPN) conduzca, permitiendo así que el LED se ilumine.


.. image:: ../../img/wiring/5.6_s8050_bb.png

**Forma de conectar el transistor PNP(S8550)**

.. image:: ../../img/circuit/circuit_5.6_S8550.png

En este circuito, IO14 está bajo por defecto y cambiará a alto cuando se presione el botón.

Programando IO26 para que emita **bajo**, después de una resistencia limitadora de corriente de 1k (para proteger el transistor), se permite que el S8550 (transistor PNP) conduzca, permitiendo así que el LED se ilumine.

La única diferencia que notarás entre este circuito y el anterior es que en el circuito anterior el cátodo del LED está conectado al **colector** del **S8050 (transistor NPN)**, mientras que en este está conectado al **emisor** del **S8550 (transistor PNP)**.

.. image:: ../../img/wiring/5.6_s8550_bb.png

**Código**

.. note::

    * Abre el archivo ``5.6_transistor.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    import machine 

    button = machine.Pin(14, machine.Pin.IN)   # Button
    led = machine.Pin(26, machine.Pin.OUT)  # LED

    # Start an infinite loop
    while True:  
        # Read the current value of the 'button' object (0 or 1) and store it in the 'button_status' variable
        button_status = button.value() 
        # If the button is pressed (value is 1)
        if button_status == 1: 
            led.value(1) # Turn the LED on
        # If the button is not pressed (value is 0)
        else:       
            led.value(0)            # turn the LED off



Two types of transistors can be controlled using the same code. 
When we press the button, the ESP32 will send a high-level signal to the transistor; 
when we release it, it will send a low-level signal.

* El circuito usando el S8050 (transistor NPN) se iluminará cuando se presione el botón, indicando que está en un estado de conducción de nivel alto;
* El circuito usando el S8550 (transistor PNP) se iluminará cuando se suelte el botón, indicando que está en un estado de conducción de nivel bajo.
