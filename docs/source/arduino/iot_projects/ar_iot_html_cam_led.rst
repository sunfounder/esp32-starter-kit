.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _iot_html_cam:

8.3 Servidor Web de Transmisión de Video Personalizado
======================================================

El proyecto de Servidor Web de Transmisión de Video Personalizado ofrece una oportunidad para aprender cómo crear una página web desde cero y personalizarla para reproducir transmisiones de video. Además, podrás incorporar botones interactivos, como ENCENDER y APAGAR, para controlar la intensidad del LED.

Al construir este proyecto, ganarás experiencia práctica en desarrollo web, HTML, CSS y JavaScript. Aprenderás cómo crear una página web responsive que pueda mostrar transmisiones de video en tiempo real. Además, descubrirás cómo integrar botones interactivos para controlar el estado del LED, proporcionando una experiencia de usuario dinámica.

**Componentes Requeridos**

Para este proyecto, necesitamos los siguientes componentes.

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

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
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
    *   - :ref:`cpn_led`
        - |link_led_buy|

**¿Cómo hacerlo?**

#. Primero conecta la cámara.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>

#. Construye el circuito.

    .. image:: ../../img/wiring/iot_3_html_led_bb.png

#. Luego, conecta el ESP32-WROOM-32E al ordenador mediante el cable USB.

    .. image:: ../../img/plugin_esp32.png

#. Abre el código.

    * Abre el archivo ``iot_3_html_cam_led.ino`` ubicado en el directorio ``esp32-starter-kit-main\c\codes\iot_3_html_cam_led``, o copia el código en el IDE de Arduino.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a5e33c30-63dc-4987-94c3-89bc6a599e24/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Localiza las siguientes líneas y modifícalas con tu ``SSID`` y ``PASSWORD``.

    .. code-block::  Arduino

        // Reemplaza las siguientes variables con tu combinación de SSID/Contraseña
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Después de seleccionar la placa correcta (ESP32 Dev Module) y el puerto, haz clic en el botón **Subir**.

#. Verás un mensaje de conexión exitosa a WiFi y la dirección IP asignada en el Monitor Serie.

    .. code-block:: 

        Conexión WiFi exitosa
        ¡Transmisión de Cámara Lista! Ve a: http://192.168.18.77

#. Ingresa la dirección IP en tu navegador web. Serás dirigido a la página web mostrada a continuación, donde podrás usar los botones personalizados de ENCENDER y APAGAR para controlar el LED.

    .. image:: img/sp230510_180503.png 

#. Inserta una batería en la placa de expansión y retira el cable USB. Ahora puedes colocar el dispositivo en cualquier lugar que desees dentro del alcance del Wi-Fi.

    .. image:: ../../img/plugin_battery.png
