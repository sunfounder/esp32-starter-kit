.. _ar_receiver:

5.14 Receptor IR
=========================
Un receptor infrarrojo es un componente que recibe señales infrarrojas y puede detectar y emitir señales compatibles con el nivel TTL de forma independiente. Es similar en tamaño a un transistor empaquetado en plástico regular y se utiliza comúnmente en diversas aplicaciones como control remoto infrarrojo y transmisión infrarroja.

En este proyecto, usaremos un receptor infrarrojo para detectar señales de un control remoto. Cuando se presiona un botón en el control remoto y el receptor infrarrojo recibe la señal correspondiente, puede decodificar la señal para determinar qué botón se presionó. Al decodificar la señal recibida, podemos identificar la tecla o comando específico asociado con ella.

El receptor infrarrojo nos permite incorporar funcionalidad de control remoto en nuestro proyecto, permitiéndonos interactuar con y controlar dispositivos usando señales infrarrojas.

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

Cuando presionas un botón en el control remoto, el receptor infrarrojo detecta la señal, y puedes usar una biblioteca infrarroja para decodificarla. Este proceso de decodificación te permite obtener el valor de la tecla asociada con la presión del botón.

**Cableado**

.. image:: ../../img/wiring/5.14_ir_receiver_bb.png

**Código**

.. note::

    * Abre el archivo ``5.14_ir_receiver.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.14_ir_receiver``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * La biblioteca ``IRremoteESP8266`` se usa aquí, puedes instalarla desde el **Administrador de Bibliotecas**.

        .. image:: img/receiver_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/463c8894-00bd-4035-a81c-cad99a7f3731/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de que el código se haya cargado con éxito, presiona los diferentes botones en el control remoto y verás aparecer los nombres de estas teclas en el monitor serie.

.. note::
    * La biblioteca ``IRremoteESP8266`` incluye implementaciones para muchos protocolos y dispositivos infrarrojos diferentes, por lo que el tamaño de la biblioteca es relativamente grande. Cuando el compilador tiene que procesar más código, el tiempo de compilación también aumentará en consecuencia. Por favor, sé paciente y espera a que finalice la compilación.
    * El control remoto nuevo cuenta con una lengüeta de plástico en el extremo para aislar la batería en su interior. Para activar el control al usarlo, simplemente retira esta pieza de plástico.


**¿Cómo funciona?**

#. Este código utiliza la biblioteca ``IRremoteESP8266`` para recibir señales infrarrojas (IR) usando un módulo receptor IR.

    .. code-block:: arduino

        #include <IRremoteESP8266.h>
        #include <IRrecv.h>

        // Define the IR receiver pin
        const uint16_t IR_RECEIVE_PIN = 14;

        // Create an IRrecv object
        IRrecv irrecv(IR_RECEIVE_PIN);

        // Create a decode_results object
        decode_results results;
    
#. En la función ``setup()``, la comunicación serie se inicia a una tasa de baudios de 115200, y el receptor IR se habilita usando ``irrecv.enableIRIn()``.

    .. code-block:: arduino

        void setup() {
            // Start serial communication
            Serial.begin(115200);
            
            // Start the IR receiver
            irrecv.enableIRIn();
        }

#. Cuando presionas una tecla en el control remoto, el monitor serie imprimirá el nombre de la tecla si es recibido por el receptor IR.

    .. code-block:: arduino

        void loop() {
            // If an IR signal is received
            if (irrecv.decode(&results)) {
                String key = decodeKeyValue(results.value);
                if (key != "ERROR") {
                    // Print the value of the signal to the serial monitor
                    Serial.println(key);
                }
                irrecv.resume(); // Continue to receive the next signal
            }
        }

    * Primero, verifica si se recibió una señal IR usando la función ``irrecv.decode()``. 
    * Si se recibe una señal, entonces llama a la función ``decodeKeyValue()`` para decodificar el valor de la señal. 
    * Si la señal se decodifica con éxito, el valor decodificado se imprime en el monitor serie usando ``Serial.println()``.
    * Finalmente, ``irrecv.resume()`` se llama para continuar recibiendo la siguiente señal.

#. La función ``decodeKeyValue()`` toma el valor decodificado de la señal IR como argumento y devuelve una cadena que representa la tecla presionada en el control remoto. 

    .. code-block:: arduino

        String decodeKeyValue(long result)
        {
            switch(result){
                case 0xFF6897:
                return "0";
                case 0xFF30CF:
                return "1"; 
                case 0xFF18E7:
                return "2"; 
                case 0xFF7A85:
                ...

    * La función utiliza una instrucción switch para hacer coincidir el valor decodificado con la tecla correspondiente y devuelve la representación en cadena de la tecla. 
    * Si el valor decodificado no coincide con ninguna tecla conocida, la función devuelve la cadena "ERROR".
