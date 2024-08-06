.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _iot_owm:

8.1 Información del Tiempo en Tiempo Real de @OpenWeatherMap
============================================================

El proyecto de Pantalla del Tiempo IoT utiliza la placa ESP32 y un módulo LCD1602 I2C para crear una pantalla de información meteorológica que recupera datos de la API de OpenWeatherMap.

Este proyecto sirve como una excelente introducción al trabajo con APIs, conectividad Wi-Fi y visualización de datos en un módulo LCD utilizando la placa ESP32. Con la Pantalla del Tiempo IoT, puedes acceder cómodamente a actualizaciones del tiempo en tiempo real de un vistazo, lo que la convierte en una solución ideal para ambientes domésticos o de oficina.

**Componentes Requeridos**

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Obtener las Claves API de OpenWeather**

|link_openweather| es un servicio en línea, propiedad de OpenWeather Ltd, que proporciona datos meteorológicos globales a través de API, incluyendo datos meteorológicos actuales, pronósticos, nowcasts y datos meteorológicos históricos para cualquier ubicación geográfica.

#. Visita |link_openweather| para iniciar sesión/crear una cuenta.

    .. image:: img/OWM-1.png

#. Haz clic en la página de API desde la barra de navegación.

    .. image:: img/OWM-2.png

#. Encuentra **Datos Meteorológicos Actuales** y haz clic en Suscribirse.

    .. image:: img/OWM-3.png

#. Bajo **Colección de datos meteorológicos actuales y pronósticos**, suscríbete al servicio apropiado. En nuestro proyecto, Gratis es suficiente.

    .. image:: img/OWM-4.png

#. Copia la clave desde la página de **Claves API**.

    .. image:: img/OWM-5.png


**Completa Tu Dispositivo**

#. Construye el circuito.

    .. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
        :width: 800

#. Abre el código.

    * Abre el archivo ``iot_1_open_weather.ino`` ubicado en el directorio ``esp32-starter-kit-main\c\codes\iot_1_open_weather``, o copia el código en el IDE de Arduino.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * Las bibliotecas ``LiquidCrystal I2C`` y ``Arduino_JSON`` se utilizan aquí, puedes instalarlas desde el **Administrador de Bibliotecas**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/71b196ce-8a84-4577-af76-43988c7d3f80/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
         

#. Localiza las siguientes líneas y modifícalas con tu ``SSID`` y ``PASSWORD``.


    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Rellena las claves API que copiaste anteriormente en ``openWeatherMapApiKey``.

    .. code-block::  Arduino

        // Your Domain name with URL path or IP address with path
        String openWeatherMapApiKey = "openWeatherMapApiKey";

#. Reemplaza con tu código de país y ciudad.

    .. code-block::  Arduino

        // Replace with your country code and city
        // Fine the country code by https://openweathermap.org/find
        String city = "CITY";
        String countryCode = "COUNTRY CODE";

#. Después de que el código se ejecute, verás la información del tiempo y la hora de tu ubicación en el I2C LCD1602.

.. note::
   Cuando el código esté corriendo, si la pantalla está en blanco, puedes girar el potenciómetro en la parte trasera del módulo para aumentar el contraste.