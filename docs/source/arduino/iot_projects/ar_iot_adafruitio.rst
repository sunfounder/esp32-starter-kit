.. _ar_adafruit_io:

8.6 Monitoreo de Temperatura y Humedad con Adafruit IO
=============================================================

En este proyecto, te guiaremos sobre cómo usar una plataforma de IoT popular. Hay muchas plataformas gratuitas (o de bajo costo) disponibles en línea para los entusiastas de la programación. Algunos ejemplos son Adafruit IO, Blynk, Arduino Cloud, ThingSpeak, etc. El uso de estas plataformas es bastante similar. Aquí, nos centraremos en Adafruit IO.

Escribiremos un programa de Arduino que utiliza el sensor DHT11 para enviar lecturas de temperatura y humedad al tablero de Adafruit IO. También puedes controlar un LED en el circuito a través de un interruptor en el tablero.

**Componentes Requeridos**

Para este proyecto, necesitaremos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ARTÍCULOS EN ESTE KIT
        - ENLACE
    *   - Kit de Inicio ESP32
        - 320+
        - |link_esp32_starter_kit|

También puedes comprarlos por separado desde los enlaces a continuación.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

**Configuración del Tablero**

#. Visita |link_adafruit_io|, luego haz clic en **Comenzar gratis** para crear una cuenta gratuita.

    .. image:: img/sp230516_102503.png

#. Completa el formulario para crear una cuenta.

    .. image:: img/sp230516_102629.png

#. Después de crear una cuenta en Adafruit, necesitarás reabrir Adafruit io. Haz clic en **Tableros**, luego en **Nuevo Tablero**.

    .. image:: img/sp230516_103347.png

#. Crea un **Nuevo Tablero**.

    .. image:: img/sp230516_103744.png

#. Ingresa al **Tablero** recién creado y crea un nuevo bloque.

    .. image:: img/sp230516_104234.png

#. Crea 1 bloque **Interruptor**.

    .. image:: img/sp230516_105727.png

#. A continuación, necesitarás crear un nuevo canal aquí. Este interruptor se utilizará para controlar el LED, y nombraremos este canal "LED".

    .. image:: img/sp230516_105641.png

#. Verifica el canal **LED**, luego avanza al siguiente paso.

    .. image:: img/sp230516_105925.png

#. Completa la configuración del bloque (principalmente Título del Bloque, Texto de Encendido y Texto de Apagado), luego haz clic en el botón **Crear bloque** en la parte inferior derecha para finalizar.

    .. image:: img/sp230516_110124.png

#. También necesitaremos crear dos **Bloques de Texto** a continuación. Se utilizarán para mostrar la temperatura y la humedad. Por lo tanto, crea dos canales denominados **temperatura** y **humedad**.

    .. image:: img/sp230516_110657.png

#. Después de la creación, tu Tablero debería verse algo así:

    .. image:: img/sp230516_111134.png

#. Puedes ajustar el diseño utilizando la opción **Editar Diseño** en el Tablero.

    .. image:: img/sp230516_111240.png

#. Haz clic en **CLAVE API**, y verás tu nombre de usuario y **CLAVE API** mostrados. Anótalos, ya que los necesitarás para tu código.

    .. image:: img/sp230516_111641.png

**Ejecutando el Código**

#. Construye el circuito.

    .. image:: ../../img/wiring/iot_6_adafruit_io_bb.png

#. Luego, conecta el ESP32-WROOM-32E al ordenador mediante el cable USB.

    .. image:: ../../img/plugin_esp32.png

#. Abre el código.

    * Abre el archivo ``iot_6_adafruit_io.ino`` ubicado en el directorio ``esp32-starter-kit-main\c\codes\iot_6_adafruit_io``, o copia el código en el IDE de Arduino.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * Aquí se utilizan la ``Biblioteca Adafruit_MQTT`` y la ``Biblioteca del sensor DHT``, puedes instalarlas desde el **Gestor de Bibliotecas**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4cf6ad03-250e-4fe9-aa04-0ca73b997843/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Encuentra las siguientes líneas y reemplaza ``<SSID>`` y ``<PASSWORD>`` con los detalles específicos de tu red WiFi.

    .. code-block::  Arduino

        /************************* WiFi Access Point *********************************/

        #define WLAN_SSID "<SSID>"
        #define WLAN_PASS "<PASSWORD>"

#. Luego reemplaza ``<TU_NOMBRE_DE_USUARIO_ADAFRUIT_IO>`` con tu nombre de usuario de Adafruit IO y ``<TU_CLAVE_ADAFRUIT_IO>`` con la **CLAVE API** que acabas de copiar.

    .. code-block::  Arduino

        // Adafruit IO Account Configuration
        // (to obtain these values, visit https://io.adafruit.com and click on Active Key)
        #define AIO_USERNAME "<YOUR_ADAFRUIT_IO_USERNAME>"
        #define AIO_KEY      "<YOUR_ADAFRUIT_IO_KEY>"

#. Después de seleccionar la placa correcta (ESP32 Dev Module) y el puerto correspondiente, haz clic en el botón **Subir** para cargar el programa a tu ESP32.

#. Una vez que el código se haya subido con éxito, observarás el siguiente mensaje en el monitor serial, indicando una comunicación exitosa con Adafruit IO.
    
    .. code-block::

        Adafruit IO MQTTS (SSL/TLS) Example


        Connecting to xxxxx
        WiFi connected
        IP address: 
        192.168.18.76
        Connecting to MQTT... MQTT Connected!
        Temperature: 27.10
        Humidity: 61.00

#. Regresa a Adafruit IO. Ahora puedes observar las lecturas de temperatura y humedad en el tablero de control, o utilizar el interruptor de palanca LED para controlar el estado de encendido/apagado del LED externo conectado al circuito.

    .. image:: img/sp230516_143220.png

