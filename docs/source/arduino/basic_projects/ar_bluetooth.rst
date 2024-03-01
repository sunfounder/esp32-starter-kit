.. _ar_bluetooth:

7.1 Bluetooth
===================

Este proyecto proporciona una guía para desarrollar una aplicación simple de comunicación serial Bluetooth Low Energy (BLE) utilizando el microcontrolador ESP32. El ESP32 es un microcontrolador potente que integra conectividad Wi-Fi y Bluetooth, lo que lo hace un candidato ideal para desarrollar aplicaciones inalámbricas. BLE es un protocolo de comunicación inalámbrica de baja potencia diseñado para la comunicación de corto alcance. Este documento cubrirá los pasos para configurar el ESP32 para actuar como un servidor BLE y comunicarse con un cliente BLE a través de una conexión serial.

**Acerca de la Función Bluetooth**

El ESP32 WROOM 32E es un módulo que integra conectividad Wi-Fi y Bluetooth en un solo chip. Soporta los protocolos Bluetooth Low Energy (BLE) y Bluetooth Clásico.

El módulo puede usarse como cliente o servidor Bluetooth. Como cliente Bluetooth, el módulo puede conectarse a otros dispositivos Bluetooth e intercambiar datos con ellos. Como servidor Bluetooth, el módulo puede proporcionar servicios a otros dispositivos Bluetooth.

El ESP32 WROOM 32E soporta varios perfiles Bluetooth, incluyendo el Perfil de Acceso Genérico (GAP), Perfil de Atributo Genérico (GATT) y Perfil de Puerto Serie (SPP). El perfil SPP permite que el módulo emule un puerto serie a través de Bluetooth, habilitando la comunicación serial con otros dispositivos Bluetooth.

Para usar la función Bluetooth del ESP32 WROOM 32E, necesitas programarlo usando un Kit de Desarrollo de Software (SDK) apropiado o usando el IDE de Arduino con la biblioteca BLE de ESP32. La biblioteca BLE de ESP32 proporciona una interfaz de alto nivel para trabajar con BLE. Incluye ejemplos que demuestran cómo usar el módulo como cliente y servidor BLE.

En general, la función Bluetooth del ESP32 WROOM 32E proporciona una forma conveniente y de baja potencia para habilitar la comunicación inalámbrica en tus proyectos.

**Pasos Operativos**

Aquí están las instrucciones paso a paso para configurar la comunicación Bluetooth entre tu ESP32 y un dispositivo móvil usando la aplicación LightBlue:

#. Descarga la aplicación LightBlue desde el **App Store** (para iOS) o **Google Play** (para Android).

    .. image:: img/bluetooth_lightblue.png

#. Abre el archivo ``7.1_bluetooth.ino`` ubicado en el directorio ``esp32-starter-kit-main\c\codes\7.1_bluetooth``, o copia el código en el IDE de Arduino.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/388f6d9d-65bf-4eaa-b29a-7cebf0b92f74/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Para evitar conflictos de UUID, se recomienda generar aleatoriamente tres nuevos UUIDs usando el |link_uuid|, y rellenarlos en las siguientes líneas de código.

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png


#. Selecciona la placa y el puerto correctos, luego haz clic en el botón **Subir**.

    .. image:: img/bluetooth_upload.png

#. Después de que el código se haya cargado con éxito, activa el **Bluetooth** en tu dispositivo móvil y abre la aplicación **LightBlue**.

    .. image:: img/bluetooth_open.png

#. En la página de **Scan**, encuentra **ESP32-Bluetooth** y haz clic en **CONECTAR**. Si no lo ves, intenta actualizar la página unas cuantas veces. Cuando aparezca **"Conectado al dispositivo!"**, la conexión Bluetooth es exitosa. Desplázate hacia abajo para ver los tres UUIDs configurados en el código.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Haz clic en el UUID de **Recibir**. Selecciona el formato de datos apropiado en el cuadro a la derecha de **Formato de Datos**, como "HEX" para hexadecimal, "Cadena UTF-8" para carácter o "Binario" para binario, etc. Luego haz clic en **SUSCRIBIRSE**.

    .. image:: img/bluetooth_read.png
        :width: 300

#. Regresa al IDE de Arduino, abre el Monitor Serial, establece la tasa de baudios a 115200, luego escribe "welcome" y presiona Enter.

    .. image:: img/bluetooth_serial.png

#. Ahora deberías ver el mensaje "welcome" en la aplicación LightBlue.

    .. image:: img/bluetooth_welcome.png
        :width: 400

#. Para enviar información desde el dispositivo móvil al Monitor Serial, haz clic en el UUID de **Enviar**, establece el formato de datos a "Cadena UTF-8" y escribe un mensaje.

    .. image:: img/bluetooth_send.png


#. Deberías ver el mensaje en el Monitor Serial.

    .. image:: img/bluetooth_receive.png

**¿Cómo funciona?**

Este código de Arduino está escrito para el microcontrolador ESP32 y lo configura para comunicarse con un dispositivo Bluetooth Low Energy (BLE).

El siguiente es un resumen breve del código:

* **Incluir las bibliotecas necesarias**: El código comienza incluyendo las bibliotecas necesarias para trabajar con Bluetooth Low Energy (BLE) en el ESP32.

    .. code-block:: arduino

        #include "BLEDevice.h"
        #include "BLEServer.h"
        #include "BLEUtils.h"
        #include "BLE2902.h"

* **Variables Globales**: El código define un conjunto de variables globales incluyendo el nombre del dispositivo Bluetooth (``bleName``), variables para llevar el seguimiento del texto recibido y el tiempo del último mensaje, UUIDs para el servicio y las características, y un objeto ``BLECharacteristic`` (``pCharacteristic``).
    
    .. code-block:: arduino

        // Define the Bluetooth device name
        const char *bleName = "ESP32_Bluetooth";

        // Define the received text and the time of the last message
        String receivedText = "";
        unsigned long lastMessageTime = 0;

        // Define the UUIDs of the service and characteristics
        #define SERVICE_UUID           "your_service_uuid_here"
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

        // Define the Bluetooth characteristic
        BLECharacteristic *pCharacteristic;

* **Configuración**: En la función ``setup()``, se inicializa el puerto serial con una tasa de baudios de 115200 y se llama a la función ``setupBLE()`` para configurar el Bluetooth BLE.

    .. code-block:: arduino
    
        void setup() {
            Serial.begin(115200);  // Initialize the serial port
            setupBLE();            // Initialize the Bluetooth BLE
        }

* **Bucle Principal**: En la función ``loop()``, si se recibió una cadena a través de BLE (es decir, ``receivedText`` no está vacío) y ha pasado al menos 1 segundo desde el último mensaje, el código imprime la cadena recibida en el monitor serial, establece el valor de la característica a la cadena recibida, envía una notificación y luego borra la cadena recibida. Si hay datos disponibles en el puerto serial, lee la cadena hasta encontrar un carácter de nueva línea, establece el valor de la característica a esta cadena y envía una notificación.

    .. code-block:: arduino

        void loop() {
            // When the received text is not empty and the time since the last message is over 1 second
            // Send a notification and print the received text
            if (receivedText.length() > 0 && millis() - lastMessageTime > 1000) {
                Serial.print("Received message: ");
                Serial.println(receivedText);
                pCharacteristic->setValue(receivedText.c_str());
                pCharacteristic->notify();
                receivedText = "";
            }

            // Read data from the serial port and send it to BLE characteristic
            if (Serial.available() > 0) {
                String str = Serial.readStringUntil('\n');
                const char *newValue = str.c_str();
                pCharacteristic->setValue(newValue);
                pCharacteristic->notify();
            }
        }

* **Callbacks**: Se definen dos clases de callbacks (``MyServerCallbacks`` y ``MyCharacteristicCallbacks``) para manejar eventos relacionados con la comunicación Bluetooth. ``MyServerCallbacks`` se usa para manejar eventos relacionados con el estado de conexión (conectado o desconectado) del servidor BLE. ``MyCharacteristicCallbacks`` se usa para manejar eventos de escritura en la característica BLE, es decir, cuando un dispositivo conectado envía una cadena al ESP32 a través de BLE, se captura y almacena en ``receivedText``, y se registra el tiempo actual en ``lastMessageTime``.

    .. code-block:: arduino

        // Define the BLE server callbacks
        class MyServerCallbacks : public BLEServerCallbacks {
            // Print the connection message when a client is connected
            void onConnect(BLEServer *pServer) {
            Serial.println("Connected");
            }
            // Print the disconnection message when a client is disconnected
            void onDisconnect(BLEServer *pServer) {
            Serial.println("Disconnected");
            }
        };

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                // When data is received, get the data and save it to receivedText, and record the time
                std::string value = pCharacteristic->getValue();
                receivedText = String(value.c_str());
                lastMessageTime = millis();
                Serial.print("Received: ");
                Serial.println(receivedText);
            }
        };

* **Configurar BLE**: En la función ``setupBLE()``, el dispositivo BLE y el servidor se inicializan, se establecen los callbacks del servidor, se crea el servicio BLE usando el UUID definido, se crean y añaden al servicio las características para enviar notificaciones y recibir datos, y se establecen los callbacks de la característica. Finalmente, el servicio se inicia y el servidor comienza a anunciarse.

    .. code-block:: arduino

        // Initialize the Bluetooth BLE
        void setupBLE() {
            BLEDevice::init(bleName);                        // Initialize the BLE device
            BLEServer *pServer = BLEDevice::createServer();  // Create the BLE server
            // Print the error message if the BLE server creation fails
            if (pServer == nullptr) {
                Serial.println("Error creating BLE server");
                return;
            }
            pServer->setCallbacks(new MyServerCallbacks());  // Set the BLE server callbacks

            // Create the BLE service
            BLEService *pService = pServer->createService(SERVICE_UUID);
            // Print the error message if the BLE service creation fails
            if (pService == nullptr) {
                Serial.println("Error creating BLE service");
                return;
            }
            // Create the BLE characteristic for sending notifications
            pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
            pCharacteristic->addDecodeor(new BLE2902());  // Add the decodeor
            // Create the BLE characteristic for receiving data
            BLECharacteristic *pCharacteristicRX = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
            pCharacteristicRX->setCallbacks(new MyCharacteristicCallbacks());  // Set the BLE characteristic callbacks
            pService->start();                                                 // Start the BLE service
            pServer->getAdvertising()->start();                                // Start advertising
            Serial.println("Waiting for a client connection...");              // Wait for a client connection
        }


Ten en cuenta que este código permite la comunicación bidireccional: puede enviar y recibir datos a través de BLE.
Sin embargo, para interactuar con hardware específico como encender/apagar un LED, se debe agregar código adicional para procesar
las cadenas recibidas y actuar en consecuencia.




