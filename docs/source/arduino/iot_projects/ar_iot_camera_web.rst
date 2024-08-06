.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _iot_camera_web:

8.2 Servidor Web de Cámara
=============================

Este proyecto combina la placa ESP32 con un módulo de cámara para transmitir video de alta calidad a través de una red local.
Configura tu propio sistema de cámaras sin esfuerzo y monitorea cualquier lugar en tiempo real.

Con la interfaz web del proyecto, puedes acceder y controlar el flujo de la cámara desde cualquier dispositivo conectado a la red.
Personaliza la configuración de la cámara para optimizar la experiencia de transmisión y ajusta fácilmente los ajustes con la interfaz amigable.

Mejora tus capacidades de vigilancia o transmisión en vivo con el versátil proyecto de Transmisión de Cámara ESP32. Monitorea tu hogar, oficina o cualquier lugar deseado con facilidad y fiabilidad.

**Componentes Requeridos**

Para este proyecto, necesitaremos los siguientes componentes.

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

**¿Cómo hacerlo?**

#. Primero conecta la cámara.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Tu navegador no soporta el tag de video.
        </video>

#. Luego, conecta el ESP32-WROOM-32E al ordenador usando el cable USB.

    .. image:: ../../img/plugin_esp32.png

#. Abre el código.

    * Abre el archivo ``iot_2_camera_server.ino`` ubicado en el directorio ``esp32-starter-kit-main\c\codes\iot_2_camera_server``, o copia el código en el IDE de Arduino.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto adecuado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/15e00b39-34e1-49f9-b039-f10053d31407/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Localiza las siguientes líneas y modifícalas con tu ``SSID`` y ``CONTRASEÑA``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Ahora, habilita **PSRAM**.

    .. image:: img/sp230516_150554.png

#. Establece el esquema de partición a **Huge APP (3MB No OTA/1MB SPIFFS)**.

    .. image:: img/sp230516_150840.png

#. Después de seleccionar la placa correcta (ESP32 Dev Module) y puerto, haz clic en el botón "Subir".

#. Verás un mensaje de conexión WiFi exitosa y la dirección IP asignada en el Monitor Serial.

    .. code-block::

        .....
        WiFi connected
        Starting web server on port: '80'
        Starting stream server on port: '81'
        Camera Ready! Use 'http://192.168.18.77' to connect

#. Ingresa la dirección IP en tu navegador web. Verás una interfaz web donde puedes hacer clic en **Iniciar Transmisión** para ver el flujo de la cámara.

    .. image:: img/sp230516_151521.png

#. Desplázate de vuelta al inicio de la página, donde verás el flujo de la cámara en vivo. Puedes ajustar la configuración en el lado izquierdo de la interfaz.

    .. image:: img/sp230516_180520.png

.. note:: 

    * Este módulo ESP32 soporta Detección de Rostros. Para habilitarlo, ajusta la resolución a 240x240 y activa la opción de Detección de Rostros en la parte inferior de la interfaz.
    * Este módulo ESP32 no soporta Reconocimiento de Rostros.