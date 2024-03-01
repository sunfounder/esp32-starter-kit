.. _ar_iot_mqtt:

8.4 Comunicación IoT con MQTT
=======================================

Este proyecto se centra en el uso de MQTT, un protocolo de comunicación popular en el dominio de Internet de las Cosas (IoT). MQTT permite a los dispositivos IoT intercambiar datos mediante un modelo de publicación/suscripción, donde los dispositivos comunican a través de temas.

En este proyecto, exploramos la implementación de MQTT construyendo un circuito que incluye un LED, un botón y un termistor. Se utiliza el microcontrolador ESP32-WROOM-32E para establecer una conexión WiFi y comunicarse con un broker MQTT. El código permite al microcontrolador suscribirse a temas específicos, recibir mensajes y controlar el LED basado en la información recibida. Adicionalmente, el proyecto demuestra la publicación de datos de temperatura del termistor a un tema designado cuando se presiona el botón.

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

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

También puedes comprarlos por separado desde los siguientes enlaces.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Carga del Código**

#. Construye el circuito.

    .. note:: 
        Al establecer una conexión WiFi, solo se pueden emplear los pines 36, 39, 34, 35, 32, 33 para la lectura analógica. Por favor, asegúrate de que el termistor esté conectado a estos pines designados.

    .. image:: ../../img/wiring/iot_4_matt_bb.png

#. Luego, conecta el ESP32-WROOM-32E al computador usando el cable USB.

    .. image:: ../../img/plugin_esp32.png

#. Abre el código.

    * Abre el archivo ``iot_4_mqtt.ino`` ubicado en el directorio ``esp32-starter-kit-main\c\codes\iot_4_mqtt``, o copia el código en el IDE de Arduino.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Upload**.
    * :ref:`unknown_com_port`
    * Aquí se utiliza la biblioteca ``PubSubClient``, la puedes instalar desde el **Administrador de Bibliotecas**.

        .. image:: img/mqtt_lib.png
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/e45a4bd6-9b35-47f0-af5e-92d802004087/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Localiza las siguientes líneas y modifícalas con tu ``<SSID>`` y ``<PASSWORD>``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. Encuentra la siguiente línea y modifica tu ``unique_identifier``. Asegúrate de que tu ``identificador_único`` sea realmente único ya que cualquier ID que sea idéntico intentando iniciar sesión en el mismo broker MQTT puede resultar en un fallo de inicio de sesión.

    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";
        const char* unique_identifier = "sunfounder-client-sdgvsda";  

**Suscripción a Temas**

#. Para evitar interferencias de mensajes enviados por otros participantes, puedes configurarlo como una cadena oscura o poco común. Simplemente reemplaza el tema actual ``SF/LED`` con el nombre de tema que desees.

    .. note:: 
        Tienes la libertad de establecer el Tema con cualquier carácter que desees. Cualquier dispositivo MQTT que se haya suscrito al mismo Tema podrá recibir el mismo mensaje. También puedes suscribirte simultáneamente a múltiples Temas.

    .. code-block::  Arduino
        :emphasize-lines: 9

        void reconnect() {
            // Loop until we're reconnected
            while (!client.connected()) {
                Serial.print("Attempting MQTT connection...");
                // Attempt to connect
                if (client.connect(unique_identifier)) {
                    Serial.println("connected");
                    // Subscribe
                    client.subscribe("SF/LED");
                } else {
                    Serial.print("failed, rc=");
                    Serial.print(client.state());
                    Serial.println(" try again in 5 seconds");
                    // Wait 5 seconds before retrying
                    delay(5000);
                }
            }
        }

#. Modifica la funcionalidad para responder al tema suscrito. En el código proporcionado, si se recibe un mensaje en el tema ``SF/LED``, verifica si el mensaje es ``on`` o ``off``. Dependiendo del mensaje recibido, cambia el estado de salida para controlar el estado de encendido o apagado del LED.

    .. note::
       Puedes modificarlo para cualquier tema al que estés suscrito, y puedes escribir múltiples declaraciones if para responder a múltiples temas.

    .. code-block::  arduino
        :emphasize-lines: 15

        void callback(char* topic, byte* message, unsigned int length) {
            Serial.print("Message arrived on topic: ");
            Serial.print(topic);
            Serial.print(". Message: ");
            String messageTemp;

            for (int i = 0; i < length; i++) {
                Serial.print((char)message[i]);
                messageTemp += (char)message[i];
            }
            Serial.println();
          
            // If a message is received on the topic "SF/LED", you check if the message is either "on" or "off".
            // Changes the output state according to the message
            if (String(topic) == "SF/LED") {
                Serial.print("Changing state to ");
                if (messageTemp == "on") {
                    Serial.println("on");
                    digitalWrite(ledPin, HIGH);
                } else if (messageTemp == "off") {
                    Serial.println("off");
                    digitalWrite(ledPin, LOW);
                }
            }
        }

#. Tras seleccionar la placa correcta (ESP32 Dev Module) y puerto, haz clic en el botón **Subir**.

#. Abre el monitor serial y si se imprime la siguiente información, indica una conexión exitosa al servidor MQTT.

    .. code-block::

        WiFi connected
        IP address: 
        192.168.18.77
        Attempting MQTT connection...connected

**Publicación de Mensajes via HiveMQ**

HiveMQ es una plataforma de mensajería que funciona como un broker MQTT, facilitando la transferencia de datos rápida, eficiente y fiable a dispositivos IoT.

Nuestro código utiliza específicamente el broker MQTT proporcionado por HiveMQ. Hemos incluido la dirección del broker MQTT de HiveMQ en el código de la siguiente manera:


    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";

#. Actualmente, abre el |link_hivemq| en tu navegador web.

#. Conecta el cliente al proxy público predeterminado.

    .. image:: img/sp230512_092258.png

#. Publica un mensaje en el Tema al que te has suscrito. En este proyecto, puedes publicar ``on`` o ``off`` para controlar tu LED.

    .. image:: img/sp230512_140234.png

**Publicación de Mensajes a MQTT**

También podemos utilizar el código para publicar información en el Tema. En esta demostración, hemos codificado una característica que envía la temperatura medida por el termistor al Tema cuando presionas el botón.

#. Haz clic en **Añadir Nueva Suscripción al Tema**.

    .. image:: img/sp230512_092341.png

#. Rellena los temas que deseas seguir y haz clic en **Suscribirse**. En el código, enviamos información de la temperatura al tema ``SF/TEMP``.

    .. code-block::  Arduino
        :emphasize-lines: 14

        void loop() {
            if (!client.connected()) {
                reconnect();
            }
            client.loop();

            // if the button pressed, publish the temperature to topic "SF/TEMP"
            if (digitalRead(buttonPin)) {
                    long now = millis();
                    if (now - lastMsg > 5000) {
                    lastMsg = now;
                    char tempString[8];
                    dtostrf(thermistor(), 1, 2, tempString);
                    client.publish("SF/TEMP", tempString);
                }
            }
        }

#. Por lo tanto, podemos monitorear este Tema en HiveMQ, permitiéndonos ver la información que has publicado.

    .. image:: img/sp230512_154342.png
