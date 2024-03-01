.. _iot_telegram:

8.7 Cámara ESP con Bot de Telegram
====================================

En este proyecto, demostraremos cómo integrar el ESP32 con tu aplicación de mensajería favorita. Para esta demostración, usaremos Telegram.

Crea un Bot de Telegram, permitiéndote controlar tu circuito desde cualquier lugar, capturar fotos y gestionar el flash. Además, cada vez que alguien pase por tu dispositivo, tomará una nueva foto y enviará una notificación a tu cuenta de Telegram.

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Creando un Bot de Telegram**

#. Dirígete a **Google Play** o a la **App Store** y descarga e instala **Telegram**.

#. Busca ``botfather`` en la aplicación de **Telegram** y una vez que aparezca, haz clic en él para abrirlo. O puedes acceder directamente a este enlace: t.me/botfather.

    .. image:: img/sp230515_135927.png

#. Al abrirlo, se presentará una ventana de chat. Envía el comando ``/start``.

    .. image:: img/sp230515_140149.png

#. Introduce ``/newbot`` y sigue las instrucciones proporcionadas para crear tu bot. Una vez exitoso, el BotFather te proporcionará el enlace de acceso y la API para tu nuevo bot.

    .. image:: img/sp230515_140830.png

**Autorizando Usuarios de Telegram**

Como cualquiera puede interactuar con el bot que has creado, existe un riesgo de fuga de información. Para solucionar esto, queremos que el bot solo responda a usuarios autorizados.

#. En tu cuenta de **Telegram**, busca ``IDBot`` o abre el enlace: t.me/myidbot.

    .. image:: img/sp230515_144241.png

#. Envía el comando ``/getid``. Guarda el ID proporcionado para su uso posterior en nuestro programa.

    .. image:: img/sp230515_144614.png

**Subir el Código**

#. Primero conecta la cámara.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Tu navegador no soporta el video.
        </video>

#. Construye el circuito.

    .. image:: ../../img/wiring/iot_7_cam_telegram_bb.png
        
#. Abre el código.

    * Abre el archivo ``iot_7_cam_telegram.ino`` ubicado en el directorio ``esp32-starter-kit-main\c\codes\iot_7_cam_telegram`` o copia el código en el IDE de Arduino.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * Se utilizan las bibliotecas ``UniversalTelegramBot`` y ``ArduinoJson``, puedes instalarlas desde el **Administrador de Bibliotecas**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/d7c439b0-fca3-4648-9714-900a2859740c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Localiza y modifica las siguientes líneas con los detalles de tu WiFi, reemplazando ``<SSID>`` y ``<PASSWORD>``:

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

5. Actualiza la siguiente línea, reemplazando ``<CHATID>`` con tu ID de Telegram, que obtuviste de @IDBot.

    .. code-block:: Arduino

        // Use @myidbot to find out the chat ID of an individual or a group
        // Also note that you need to click "start" on a bot before it can
        // message you
        String chatId = "<CHATID>";

#. Actualiza la siguiente línea, sustituyendo ``<BOTTOKEN>`` con el token de tu BOT de Telegram, que fue proporcionado por @BotFather.

    .. code-block:: Arduino

        // Initialize Telegram BOT
        String BOTtoken = "<BOTTOKEN>";

#. Después de seleccionar la placa correcta (ESP32 Dev Module) y el puerto, haz clic en el botón **Subir**.
#. Abre el Monitor Serial. Si se imprime una dirección IP, esto indica una ejecución exitosa.

    .. code-block::

        Connecting to xxxx
        ESP32-CAM IP Address: 192.168.18.76
        Init Done!

#. Ahora, puedes interactuar con tu ESP32 a través de Telegram.

    .. image:: img/sp230515_161237.png
