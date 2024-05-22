.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_esp32_wroom_32e:

ESP32 WROOM 32E
=================

El ESP32 WROOM-32E es un módulo versátil y potente construido en torno al chipset ESP32 de Espressif. Ofrece procesamiento de doble núcleo, conectividad integrada Wi-Fi y Bluetooth, y cuenta con una amplia gama de interfaces periféricas. Conocido por su bajo consumo de energía, el módulo es ideal para aplicaciones de IoT, lo que permite una conectividad inteligente y un rendimiento robusto en formatos compactos.

.. image:: img/esp32_wroom_32e.jpg
    :width: 600
    :align: center


Entre sus características clave se encuentran:

* **Potencia de Procesamiento**: Equipado con un microprocesador de doble núcleo Xtensa® 32-bit LX6, ofrece escalabilidad y flexibilidad.
* **Capacidades Inalámbricas**: Con Wi-Fi integrado de 2.4 GHz y Bluetooth de doble modo, es perfecto para aplicaciones que demandan una comunicación inalámbrica estable.
* **Memoria y Almacenamiento**: Viene con amplio SRAM y almacenamiento flash de alto rendimiento, satisfaciendo las necesidades de programas de usuario y almacenamiento de datos.
* **GPIO**: Ofrece hasta 38 pines GPIO, soportando una variedad de dispositivos y sensores externos.
* **Bajo Consumo de Energía**: Dispone de varios modos de ahorro de energía, haciéndolo ideal para escenarios con batería o eficientes en energía.
* **Seguridad**: Cuenta con encriptación integrada y características de seguridad para asegurar que los datos del usuario y la privacidad estén bien protegidos.
* **Versatilidad**: Desde electrodomésticos simples hasta maquinaria industrial compleja, el WROOM-32E ofrece un rendimiento consistente y eficiente.

En resumen, el ESP32 WROOM-32E no solo ofrece sólidas capacidades de procesamiento y diversas opciones de conectividad, sino que también cuenta con una variedad de características que lo convierten en la opción preferida en los sectores de IoT y dispositivos inteligentes.

* |link_esp32_datasheet|

.. _esp32_pinout:

Diagrama de Pinout
-------------------------

El ESP32 tiene algunas limitaciones de uso de pines debido a que varias funcionalidades comparten ciertos pines. Al diseñar un proyecto, es buena práctica planificar cuidadosamente el uso de pines y verificar posibles conflictos para garantizar un funcionamiento adecuado y evitar problemas.


.. image:: img/esp32_pinout.jpg
    :width: 800
    :align: center

Aquí hay algunas de las restricciones y consideraciones clave:

* **ADC1 y ADC2**: ADC2 no se puede utilizar cuando el WiFi o el Bluetooth están activos. Sin embargo, ADC1 se puede utilizar sin restricciones.
* **Pines de Bootstrap**: GPIO0, GPIO2, GPIO5, GPIO12 y GPIO15 se utilizan para el arranque durante el proceso de inicio. Se debe tener cuidado de no conectar componentes externos que puedan interferir con el proceso de arranque en estos pines.
* **Pines JTAG**: GPIO12, GPIO13, GPIO14 y GPIO15 se pueden utilizar como pines JTAG para propósitos de depuración. Si la depuración JTAG no es necesaria, estos pines se pueden utilizar como GPIO regulares.
* **Pines de Táctiles**: Algunos pines admiten funcionalidades táctiles. Estos pines deben usarse con cuidado si se planea utilizarlos para sensibilidad táctil.
* **Pines de Alimentación**: Algunos pines están reservados para funciones relacionadas con la alimentación y deben usarse en consecuencia. Por ejemplo, evite extraer corriente excesiva de pines de alimentación como 3V3 y GND.
* **Pines de Solo Entrada**: Algunos pines son solo de entrada y no deben usarse como salidas.


.. _esp32_strapping:

**Pines de Estrapeo**
--------------------------

ESP32 tiene cinco pines de estrapeo:

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Pines de Estrapeo
        - Descripción
    *   - IO5
        - Por defecto en pull-up, el nivel de voltaje de IO5 y IO15 afecta el Tiempo de SDIO Slave.
    *   - IO0
        - Por defecto en pull-up, si se baja, entra en modo de descarga.
    *   - IO2
        - Por defecto en pull-down, IO0 e IO2 harán que ESP32 entre en modo de descarga.
    *   - IO12(MTDI)
        - Por defecto en pull-down, si se sube, ESP32 no se iniciará correctamente.
    *   - IO15(MTDO)
        - Por defecto en pull-up, si se baja, el registro de depuración no será visible. Además, el nivel de voltaje de IO5 e IO15 afecta el Tiempo de SDIO Slave.


El software puede leer los valores de estos cinco bits del registro "GPIO_STRAPPING".
Durante la liberación del reinicio del sistema del chip (reinicio por encendido, reinicio por vigilante RTC y reinicio por caída de tensión), los latches de los pines de estrapeo muestrean el nivel de voltaje como bits de estrapeo de "0" o "1", y mantienen estos bits hasta que el chip se apague o se reinicie. Los bits de estrapeo configuran el modo de arranque del dispositivo, el voltaje de operación de VDD_SDIO y otras configuraciones iniciales del sistema.

Cada pin de estrapeo está conectado a su resistencia interna de pull-up/pull-down durante el reinicio del chip. En consecuencia, si un pin de estrapeo no está conectado o el circuito externo conectado tiene una alta impedancia, la resistencia interna débil de pull-up/pull-down determinará el nivel de entrada predeterminado de los pines de estrapeo.

Para cambiar los valores de bits de estrapeo, los usuarios pueden aplicar resistencias externas de pull-down/pull-up, o utilizar los GPIOs de la MCU host para controlar el nivel de voltaje de estos pines al encender ESP32.

Después de la liberación del reinicio, los pines de estrapeo funcionan como pines de función normal.
Consulte la siguiente tabla para obtener una configuración detallada del modo de arranque por pines de estrapeo.

.. image:: img/esp32_strapping.png

* FE: flanco de bajada, RE: flanco de subida
* El firmware puede configurar los bits del registro para cambiar la configuración de "Voltaje del LDO Interno (VDD_SDIO)" y "Tiempo del Esclavo SDIO", después del arranque.
* El módulo integra una memoria flash SPI de 3.3 V, por lo que el pin MTDI no puede configurarse en 1 cuando el módulo está encendido.

.. _cpn_esp32_camera_extension:

Extensión de Cámara ESP32
----------------------------

Hemos diseñado una placa de expansión que le permite aprovechar al máximo las funcionalidades de la cámara y la tarjeta SD del ESP32 WROOM 32E. Al combinar la cámara OV2640, Micro SD y ESP32 WROOM 32E, obtiene una placa de expansión todo en uno.

La placa proporciona dos tipos de cabeceras GPIO: una con cabeceras hembra, perfecta para proyectos de prototipado rápido. El otro tipo cuenta con terminales de tornillo, asegurando conexiones de cable estables y haciéndolo adecuado para proyectos de IoT.

Además, puede alimentar su proyecto con una sola batería de 3.7V 18650. Si la batería se agota, puede cargarla convenientemente simplemente conectando un cable Micro USB de 5V. Esto lo convierte en una excelente herramienta para proyectos al aire libre y aplicaciones remotas.

.. image:: img/esp32_camera_extension.jpg
    :width: 600
    :align: center

Introducción de la Interfaz
------------------------------------

.. image:: img/esp32_camera_extension_pinout.jpg
    :width: 800
    :align: center

* **Interruptor de Encendido**
    * Controla el suministro de energía de la batería, alternándolo entre encendido y apagado.

* **Puerto de Carga**
    * Al conectar un cable Micro USB de 5V, la batería puede cargarse.

* **Puerto de Batería**
    * Cuenta con una interfaz PH2.0-2P, compatible con baterías de litio 18650 de 3.7V.
    * Proporciona energía tanto al ESP32 WROOM 32E como a la Extensión de Cámara ESP32.

* **Cabeceras de Pines ESP32**
    * Destinadas para el módulo ESP32 WROOM 32E. Preste atención a su orientación; asegúrese de que ambos puertos Micro USB estén orientados hacia el mismo lado para evitar una colocación incorrecta.

* **Cabeceras GPIO**
    * **Hembras**: Utilizadas para conectar varios componentes al ESP32, perfectas para proyectos de prototipado rápido.
    * **Terminal de Tornillo**: Terminal de tornillo de 14 pines con paso de 3.5mm, asegurando conexiones de cable estables y haciéndolo adecuado para proyectos de IoT.

* **Luces Indicadoras**
    * **PWR**: Se enciende cuando la batería está alimentada o cuando se conecta un Micro USB directamente al ESP32.
    * **CHG**: Se ilumina al conectar un Micro USB al puerto de carga de la placa, indicando el inicio de la carga. Se apagará una vez que la batería esté completamente cargada.

* **Conector Micro SD**
    * Ranura de resorte para la inserción y eyección fácil de la tarjeta Micro SD.

* **Conector FFC / FPC de 24 pines de 0.5mm**
    * Diseñado para la cámara OV2640, haciéndolo adecuado para varios proyectos relacionados con la visión.


Pinout de la Extensión de Cámara ESP32
-------------------------------------------------

El diagrama de pinout del ESP32 WROOM 32E se puede encontrar en :ref:`esp32_pinout`.

Sin embargo, cuando el ESP32 WROOM 32E está insertado en la placa de extensión, algunos de sus pines también se pueden utilizar para manejar la tarjeta Micro SD o una cámara.

Consecuentemente, se han añadido resistencias de pull-up o pull-down a estos pines. Si está utilizando estos pines como entradas, es crucial tener en cuenta estas resistencias ya que pueden afectar los niveles de entrada.

Aquí está la tabla de pinout para los pines del lado derecho:

    .. image:: img/esp32_extension_pinout1.jpg
        :width: 100%
        :align: center

Aquí está la tabla de pinout para los pines del lado izquierdo:

    .. image:: img/esp32_extension_pinout2.jpg
        :width: 100%
        :align: center

    .. note::

        Hay algunas restricciones específicas:

        * **IO33** está conectado a una resistencia de pull-up de 4.7K y un capacitor de filtrado, lo que evita que maneje la tira RGB WS2812.

Guía de Inserción de la Interfaz
-------------------------------------

**Cargar Código**

    Cuando necesite cargar código en el ESP32 WROOM 32E, conéctelo a su computadora usando un cable Micro USB.

    .. image:: ../img/plugin_esp32.png
        :width: 600
        :align: center

**Insertar la Tarjeta Micro SD**

    Empuje suavemente la tarjeta Micro SD para asegurarla en su lugar. Presionarla nuevamente la ejectará.

    .. image:: ../img/insert_sd.png
        :width: 600
        :align: center

**Conexión de la Cámara**

    Al conectar la cámara, asegúrese de que la raya negra del cable FPC esté hacia arriba y esté completamente insertada en el conector.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../_static/video/plugin_camera.mp4" type="video/mp4">
            Su navegador no admite la etiqueta de video.
        </video>

**Alimentación de la Batería y Carga**

    Inserte cuidadosamente el cable de la batería en el puerto de la batería, evitando aplicar demasiada fuerza para evitar empujar hacia arriba el terminal de la batería. Si el terminal se empuja hacia arriba, está bien siempre y cuando los pines no estén rotos; simplemente puede presionarlo nuevamente hacia abajo.

    .. image:: ../img/plugin_battery.png
        :width: 600
        :align: center

    Si la batería se agota, conecte un cable Micro USB de 5V para cargarla.

    .. image:: ../img/battery_charge.png
        :width: 600
        :align: center

