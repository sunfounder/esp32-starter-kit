.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_bluetooth_led:

7.2 Control de LED RGB por Bluetooth
======================================

Este proyecto es una extensión de un proyecto anterior(:ref:`ar_bluetooth`), añadiendo configuraciones de LED RGB y comandos personalizados como "led_off", "red", "green", etc. Estos comandos permiten controlar el LED RGB enviando comandos desde un dispositivo móvil usando LightBlue.

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**Pasos Operativos**

#. Construye el circuito.

    .. image:: ../../components/img/rgb_pin.jpg
        :width: 200
        :align: center

    El LED RGB tiene 4 pines: el pin largo es el pin común cátodo, que generalmente se conecta a GND; el pin izquierdo junto al pin más largo es Rojo; y los dos pines a la derecha son Verde y Azul.

    .. image:: ../../img/wiring/2.3_color_light_bb.png

#. Abre el archivo ``7.2_bluetooth_rgb_led.ino`` ubicado en el directorio ``esp32-starter-kit-main\c\codes\7.2_bluetooth_rgb_led``, o copia el código en el IDE de Arduino.

    .. raw:: html
         
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b9331c9d-e9ea-4970-87ce-bf2ca8c231b2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Para evitar conflictos de UUID, se recomienda generar aleatoriamente tres nuevos UUIDs usando el |link_uuid| proporcionado por el Bluetooth SIG, y rellenarlos en las siguientes líneas de código.

    .. note::
        Si ya has generado tres nuevos UUIDs en el proyecto :ref:`ar_bluetooth`, entonces puedes continuar usándolos.


    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png

#. Selecciona la placa y el puerto correctos, luego haz clic en el botón **Subir**.

#. Después de que el código se haya cargado con éxito, activa el **Bluetooth** en tu dispositivo móvil y abre la aplicación **LightBlue**.

    .. image:: img/bluetooth_open.png

#. En la página de **Scan**, busca **ESP32-Bluetooth** y haz clic en **CONNECTAR**. Si no lo ves, intenta actualizar la página unas cuantas veces. Cuando aparezca **"Conectado al dispositivo!"**, la conexión Bluetooth es exitosa. Desplázate hacia abajo para ver los tres UUIDs configurados en el código.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Toca el UUID de envío, luego configura el formato de datos a "Cadena UTF-8". Ahora puedes escribir estos comandos: "led_off", "red", "green", "blue", "yellow" y "purple" para ver si el LED RGB responde a estas instrucciones.

    .. image:: img/bluetooth_send_rgb.png
    

**¿Cómo funciona?**

Este código es una extensión de un proyecto anterior(:ref:`ar_bluetooth`), añadiendo configuraciones de LED RGB y comandos personalizados como "led_off", "red", "green", etc. Estos comandos permiten controlar el LED RGB enviando comandos desde un dispositivo móvil usando LightBlue.

Desglosemos el código paso a paso:

* Añadir nuevas variables globales para los pines del LED RGB, canales PWM, frecuencia y resolución.

    .. code-block:: arduino

        ...

        // Define RGB LED pins
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        ...

* Dentro de la función ``setup()``, los canales PWM se inicializan con la frecuencia y resolución predefinidas. Los pines del LED RGB se conectan luego a sus respectivos canales PWM.

    .. code-block:: arduino
        
        void setup() {
            ...

            // Set up PWM channels
            ledcAttach(redPin, freq, resolution);
            ledcAttach(greenPin, freq, resolution);
            ledcAttach(bluePin, freq, resolution);

        }

* Modificar el método ``onWrite`` en la clase ``MyCharacteristicCallbacks``. Esta función escucha los datos que llegan de la conexión Bluetooth. Basándose en la cadena recibida (como ``"led_off"``, ``"red"``, ``"green"``, etc.), controla el LED RGB.

    .. code-block:: arduino

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                std::string value = std::string(pCharacteristic->getValue().c_str());
                if (value == "led_off") {
                    setColor(0, 0, 0); // turn the RGB LED off
                    Serial.println("RGB LED turned off");
                } else if (value == "red") {
                    setColor(255, 0, 0); // Red
                    Serial.println("red");
                }
                else if (value == "green") {
                    setColor(0, 255, 0); // green
                    Serial.println("green");
                }
                else if (value == "blue") {
                    setColor(0, 0, 255); // blue
                    Serial.println("blue");
                }
                else if (value == "yellow") {
                    setColor(255, 150, 0); // yellow
                    Serial.println("yellow");
                }
                else if (value == "purple") {
                    setColor(80, 0, 80); // purple
                    Serial.println("purple");
                }
            }
        };

* Finalmente, se añade una función para establecer el color del LED RGB.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // For common-anode RGB LEDs, use 255 minus the color value
            ledcWrite(redPin, red);
            ledcWrite(greenPin, green);
            ledcWrite(bluePin, blue);
        }

En resumen, este script habilita un modelo de interacción de control remoto, donde el ESP32 opera como un servidor de Energía Baja de Bluetooth (BLE).

El cliente BLE conectado (como un smartphone) puede enviar comandos de cadena para cambiar el color de un LED RGB. El ESP32 también da retroalimentación al cliente enviando de vuelta la cadena recibida, permitiendo al cliente saber qué operación se realizó.
