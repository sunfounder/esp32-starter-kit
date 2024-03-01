.. _iot_cheerlights:


8.5 CheerLights
===============================
CheerLights es una red global de luces sincronizadas que pueden ser controladas por cualquiera.

Únete a la comunidad de cambio de color de LEDs |link_cheerlights|, que permite a los LEDs alrededor del mundo cambiar de color simultáneamente.

Puedes colocar tus LEDs en un rincón de tu oficina para recordarte que no estás solo.

En este caso, también utilizamos MQTT, pero en lugar de publicar nuestros propios mensajes, nos suscribimos al tema "cheerlights". Esto nos permite recibir mensajes enviados por otros al tema "cheerlights" y usar esa información para cambiar el color de nuestra tira de LED en consecuencia.

**Componentes Requeridos**

Para este proyecto, necesitaremos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|


**¿Cómo hacerlo?**

#. Construye el circuito.

    .. image:: ../../img/wiring/iot_5_cheerlight_bb.png

#. Luego, conecta el ESP32-WROOM-32E al computador usando el cable USB.

    .. image:: ../../img/plugin_esp32.png

#. Abre el código.

    * Abre el archivo ``iot_5_cheerlights.ino`` ubicado en el directorio ``esp32-starter-kit-main\c\codes\iot_5_cheerlights``, o copia el código en el IDE de Arduino.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * Aquí se utilizan las bibliotecas ``PubSubClient`` y ``Adafruit_NeoPixel``, puedes instalarlas desde el **Gestor de Bibliotecas**.

        .. image:: img/mqtt_lib.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4fc7b0ff-db8e-4bf3-ad34-d68c1857794b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Localiza las siguientes líneas y modifícalas con tu ``<SSID>`` y ``<PASSWORD>``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. Encuentra la siguiente línea y modifica tu ``identificador_único``. Asegúrate de que tu ``identificador_único`` sea verdaderamente único ya que cualquier ID idéntico que intente iniciar sesión en el mismo **Broker MQTT** puede resultar en un fallo de inicio de sesión.

    .. code-block::  Arduino

        // Add your MQTT Broker address:
        const char* mqtt_server = "mqtt.cheerlights.com";
        const char* unique_identifier = "sunfounder-client-sdgvsasdda";    

#. Después de seleccionar la placa correcta (ESP32 Dev Module) y el puerto, haz clic en el botón **Subir**.

#. En este punto, puedes ver que tu tira RGB muestra un cierto color. Colócala en tu escritorio y notarás que cambia de color periódicamente. ¡Esto se debe a que otros seguidores de @CheerLights están cambiando el color de tus luces!

#. Abre el Monitor Serie. Verás mensajes similares a los siguientes:

.. code-block:: 
  
    WiFi connected
    IP address: 
    192.168.18.77
    Attempting MQTT connection...connected
    Message arrived on topic: cheerlights. 
    Message: oldlace
    Changing color to oldlace

**Controla los dispositivos globales @CheerLights**

#. Únete al |link_discord_server| y utiliza el bot de CheerLights para establecer el color. Simplemente escribe ``/cheerlights`` en cualquiera de los canales del **Servidor de Discord de CheerLights** para activar el bot.

    .. image:: img/sp230511_163558.png

#. Sigue las instrucciones proporcionadas por el bot para establecer el color. Esto te permitirá controlar dispositivos CheerLights globalmente.

    .. image:: img/sp230511_163849.png