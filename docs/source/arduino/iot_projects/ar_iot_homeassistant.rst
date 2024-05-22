.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

8.8 Cámara con Home Assistant
======================================

Este proyecto te guiará en la configuración de un servidor de transmisión de video para la cámara ESP32 e integrarlo con la popular plataforma de automatización del hogar, Home Assistant. Esta integración te permitirá acceder al servidor desde cualquier dispositivo en tu red.

.. note::
    
    Antes de sumergirte en este proyecto, necesitas tener un sistema operativo con Home Assistant instalado.
        
    Recomendamos instalar Home Assistant OS en un Raspberry Pi.
        
    Si no tienes un Raspberry Pi, también puedes instalarlo en una máquina virtual que funcione en Windows, macOS o Linux.
        
    Para instrucciones de instalación, consulta el enlace oficial: https://www.home-assistant.io/installation/
        
    Por favor, procede con este proyecto solo después de una instalación exitosa.

**Componentes Requeridos**

En este proyecto, necesitaremos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí tienes el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ÍTEMS EN ESTE KIT
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
        - \-


**1. Configuración en ESP Home**

#. Primero conecta la cámara.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>

#. Conecta tu ESP32 al host donde has instalado el sistema Home Assistant (por ejemplo, si está instalado en un Raspberry Pi, conéctalo al Pi).

    .. image:: ../../img/plugin_esp32.png

#. Instala el Addon ESPHome.

    .. image:: img/sp230629_145928.png

#. Haz clic en **START**, luego en **OPEN WEB UI**.

    .. image:: img/sp230629_172645.png
        :width: 700
        :align: center

#. Agrega nuevos dispositivos.

    .. image:: img/sp230629_172733.png

#. Podría aparecer un aviso. Haz clic en **CONTINUE**.

    .. image:: img/sp230629_172816.png
        :align: center


#. Crea una configuración. Aquí, puedes ingresar cualquier nombre deseado para **Name**. Para WiFi, ingresa los detalles de la red en la que tu sistema Home Assistant está presente.

    .. image:: img/sp230629_172926.png

#. Selecciona **ESP32** como el tipo de dispositivo.

    .. image:: img/sp230629_173043.png

#. Cuando veas un icono de celebración con fuegos artificiales, significa que has creado exitosamente el dispositivo. Haz clic en omitir (NO hagas clic en **INSTALL**).

    .. image:: img/sp230629_173151.png

    En este punto, solo has agregado el dispositivo en ESPHome. Para integrar el módulo ESP32 en Home Assistant, se necesitan configuraciones adicionales:

#. Haz clic en **EDIT**.

    .. image:: img/sp230629_173322.png

#. Después de entrar a la interfaz ``.yaml``, modifica el ``ssid`` y ``password`` con los detalles de tu WiFi.

    .. image:: img/sp230629_174301.png

#. Bajo la sección ``captive_portal``, pega el siguiente código:

    .. code-block::

        # Example configuration entry
        esp32_camera:
            external_clock:
                pin: GPIO0
                frequency: 20MHz
            i2c_pins:
                sda: GPIO26
                scl: GPIO27
            data_pins: [GPIO5, GPIO18, GPIO19, GPIO21, GPIO36, GPIO39, GPIO34, GPIO35]
            vsync_pin: GPIO25
            href_pin: GPIO23
            pixel_clock_pin: GPIO22
            power_down_pin: GPIO32

            # Image settings
            name: My Camera
            # ...

    .. note:: 
        
        Para más detalles sobre la configuración ``.yaml`` para ESP32, puedes referirte a `ESP32 Camera - ESPHome <https://esphome.io/components/esp32_camera.html>`_.

#. **Guarda**, luego haz clic en **INSTALL**.

    .. image:: img/sp230629_174447.png

#. Elige el método de puerto USB para la instalación.

    .. image:: img/sp230629_174852.png

    .. note:: 
        
        La compilación inicial descargará paquetes de dependencia, lo cual podría tomar alrededor de 10 minutos. Por favor, ten paciencia. Si el proceso se estanca por mucho tiempo, verifica si hay suficiente espacio en disco en tu sistema.

#. Espera el mensaje ``INFO Successfully compiled program.``, indicando que la compilación del firmware está completa.

    .. image:: img/sp230630_115109.png

    .. sp230630_114902.png

    .. note::

        En este punto, deberías ver el nodo como **ONLINE**. Si no, asegúrate de que tu ESP32 esté en el mismo segmento de red o intenta reiniciar el dispositivo.

        .. image:: img/sp230630_153024.png

**2. Configuración en Home Assistant**

Después de integrarlo con Esphome, aún necesitas configurar la cámara en homeassistant.

#. Ve a **Settings** > **Devices & Services**.

    .. image:: img/sp230630_155917.png

#. Ahora deberías ver la pestaña de esphome. Haz clic en **CONFIGURE**.

    .. image:: img/sp230630_155736.png

#. Haz clic en **SUBMIT**.

    .. image:: img/sp230630_162218.png

#. Espera el mensaje de **Success**.

    .. image:: img/sp230630_162311.png

#. En **Overview**, haz clic en el menú superior derecho y selecciona **Edit Dashboard**.

    .. image:: img/sp230630_164745.png

#. Haz clic en **ADD CARD**.

    .. image:: img/sp230630_164850.png

#. Elige **Picture entity**.

    .. image:: img/sp230630_164935.png

#. En **Entity**, selecciona la cámara que acabas de agregar. Luego haz clic en **SAVE**.

    .. image:: img/sp230630_165019.png

#. Ahora deberías ser capaz de ver la transmisión en vivo de tu cámara en Home Assistant.

    .. image:: img/sp230630_165235.png

Ahora, puedes ver el contenido de tu cámara en el Asistente en Casa.

