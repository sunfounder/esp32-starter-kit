.. _ar_button:

5.1 Lectura del Valor del Botón
==============================================
En este proyecto interactivo, nos aventuraremos en el ámbito de los controles de botones y la manipulación de LEDs.

El concepto es sencillo pero efectivo. Estaremos leyendo el estado de un botón. Cuando el botón está presionado, registra un nivel de voltaje alto, o 'estado alto'. Esta acción entonces hará que un LED se ilumine.

**Componentes Necesarios**

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

**Pines Disponibles**

* **Pines Disponibles**

    Aquí está una lista de los pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Para Entrada
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Para Salida
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Uso Condicional de Pines (Entrada)**

    Los siguientes pines tienen resistencias de pull-up o pull-down incorporadas, por lo que no se requieren resistencias externas cuando **se usan como pines de entrada**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Pines de Uso Condicional
            - Descripción
        *   - IO13, IO15, IO2, IO4
            - Pull-up con una resistencia de 47K por defecto el valor a alto.
        *   - IO27, IO26, IO33
            - Pull-up con una resistencia de 4.7K por defecto el valor a alto.
        *   - IO32
            - Pull-down con una resistencia de 1K por defecto el valor a bajo.

* **Pines de Strapping (Entrada)**

    Los pines de strapping son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo (es decir, reset por encendido).
     
    .. list-table::
        :widths: 5 15

        *   - Pines de Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    Generalmente, **no se recomienda usarlos como pines de entrada**. Si deseas usar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, consulta la sección :ref:`esp32_strapping`.

**Esquemático**

.. image:: ../../img/circuit/circuit_5.1_button.png

Para asegurar una funcionalidad adecuada, conecta un lado del pin del botón a 3.3V y el otro lado a IO14. Cuando el botón es presionado, IO14 se establece en alto, haciendo que el LED se ilumine. Cuando el botón es liberado, IO14 regresa a su estado suspendido, que puede ser alto o bajo. Para asegurar un nivel bajo estable cuando el botón no está presionado, IO14 debe conectarse a GND a través de una resistencia de pull-down de 10K.

**Cableado**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::
    
    Un botón de cuatro pines está diseñado en forma de H. Cuando el botón no está presionado, los pines izquierdo y derecho están desconectados, y la corriente no puede fluir entre ellos. Sin embargo, cuando el botón es presionado, los pines izquierdo y derecho están conectados, creando un camino para que la corriente fluya.

**Código**

.. note::

    * Puedes abrir el archivo ``5.1_button.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.1_button``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/702c5a70-78e7-4a8b-a0c7-10c0acebfc12/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una vez que el código se ha subido con éxito, el LED se ilumina cuando presionas el botón y se apaga cuando lo sueltas.

Al mismo tiempo, puedes abrir el Monitor Serial en la esquina superior derecha para observar el valor del botón, cuando el botón está presionado, se imprimirá "1", de lo contrario se imprimirá "0".

.. image:: img/button_serial.png


**Cómo funciona**

Los proyectos anteriores todos involucraron emitir señales, ya sea en forma de señales digitales o señales PWM.

Este proyecto involucra recibir señales de entrada de un componente externo hacia la placa ESP32. Puedes ver la señal de entrada a través del Monitor Serial en el IDE de Arduino.


#. En la función ``setup()``, el pin del botón se inicializa como una ``entrada`` y el pin del LED se inicializa como una ``salida``. La comunicación Serial también se inicia con una tasa de baudios de 115200.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            // initialize the button pin as an input
            pinMode(buttonPin, INPUT);
            // initialize the LED pin as an output
            pinMode(ledPin, OUTPUT);
        }
    
    * ``Serial.begin(velocidad)``: Establece la tasa de datos en bits por segundo (baudios) para la transmisión de datos serial.

        * ``velocidad``: en bits por segundo (baudios). Tipos de datos permitidos: ``long``.

#. En la función ``loop()``, se lee el estado del botón y se almacena en la variable ``buttonState``. El valor de ``buttonState`` se imprime en el Monitor Serial usando ``Serial.println()``.

    .. code-block:: arduino

        void loop() {
            // read the state of the button value
            buttonState = digitalRead(buttonPin);
            Serial.println(buttonState);
            delay(100);
            // if the button is pressed, the buttonState is HIGH
            if (buttonState == HIGH) {
                // turn LED on
                digitalWrite(ledPin, HIGH);

            } else {
                // turn LED off
                digitalWrite(ledPin, LOW);
            }
        }

    Si el botón está presionado y el ``buttonState`` es HIGH, el LED se enciende estableciendo el ``ledPin`` en ``HIGH``. De lo contrario, apaga el LED.

    * ``int digitalRead(uint8_t pin);``: Para leer el estado de un pin dado configurado como INPUT, se usa la función digitalRead. Esta función devolverá el estado lógico del pin seleccionado como ``HIGH`` o ``LOW``.

        * ``pin`` selecciona GPIO

    * ``Serial.println()``: Imprime datos al puerto serial como texto ASCII legible por humanos seguido de un carácter de retorno de carro (ASCII 13, o '\r') y un carácter de nueva línea (ASCII 10, o '\n').









