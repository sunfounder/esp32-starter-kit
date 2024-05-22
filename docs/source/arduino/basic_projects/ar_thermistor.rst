.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_thermistor:

5.10 Termómetro
===========================

Un termistor es un sensor de temperatura que muestra una fuerte dependencia con la temperatura y puede clasificarse en dos tipos: Coeficiente de Temperatura Negativo (NTC) y Coeficiente de Temperatura Positivo (PTC). La resistencia de un termistor NTC disminuye con el aumento de la temperatura, mientras que la resistencia de un termistor PTC aumenta con el incremento de la temperatura.

En este proyecto, utilizaremos un termistor NTC. Al conectar el termistor NTC a un pin de entrada analógica del microcontrolador ESP32, podemos medir su resistencia, que es directamente proporcional a la temperatura.

Incorporando el termistor NTC y realizando los cálculos necesarios, podemos medir la temperatura con precisión y mostrarla en el módulo LCD1602 I2C. Este proyecto permite el monitoreo de la temperatura en tiempo real y proporciona una interfaz visual para la visualización de la temperatura.

**Componentes Necesarios**

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|


**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 15

        *   - Pines Disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Pines de Configuración**

    Los siguientes pines son pines de configuración, los cuales afectan el proceso de inicio del ESP32 durante el encendido o el reinicio. Sin embargo, una vez que el ESP32 se ha iniciado correctamente, pueden ser utilizados como pines regulares.

    .. list-table::
        :widths: 5 15

        *   - Pines de Configuración
            - IO0, IO12


**Esquemático**

.. image:: ../../img/circuit/circuit_5.10_thermistor.png

Cuando la temperatura aumenta, la resistencia del termistor disminuye, causando que el valor leído en I35 disminuya. Además, utilizando una fórmula, puedes convertir el valor analógico en temperatura y luego imprimirlo.

**Conexión**

.. image:: ../../img/wiring/5.10_thermistor_bb.png


.. note::
    * El termistor es negro y está marcado con 103.
    * El anillo de color del resistor de 10K ohmios es rojo, negro, negro, rojo y marrón.

**Código**

.. note::

    * Abre el archivo ``5.10_thermistor.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.10_thermistor``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d0407e3b-cd1e-4f5e-a7b6-391da394339b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Después de que el código se haya subido con éxito, el Monitor Serial imprimirá las temperaturas en Celsius y Fahrenheit.

**¿Cómo funciona?**

Cada termistor tiene una resistencia normal. Aquí es de 10k ohmios, medida bajo 25 grados Celsius.

Cuando la temperatura aumenta, la resistencia del termistor disminuye. Luego, los datos de voltaje se convierten en cantidades digitales por el adaptador A/D.

La temperatura en Celsius o Fahrenheit se muestra mediante programación.

Aquí está la relación entre la resistencia y la temperatura:

    **RT = RN expB(1/TK - 1/TN)**

    * **RT** es la resistencia del termistor NTC cuando la temperatura es **TK**.
    * **RN** es la resistencia del termistor NTC bajo la temperatura nominal TN. Aquí, el valor numérico de RN es 10k.
    * **TK** es una temperatura en Kelvin y su unidad es K. Aquí, el valor numérico de **TK** es ``373.15 + grados Celsius``.
    * **TN** es una temperatura nominal en Kelvin; su unidad también es K. Aquí, el valor numérico de TN es ``373.15+25``.
    * Y **B(beta)**, la constante de material del termistor NTC, también se llama índice de sensibilidad al calor con un valor numérico ``4950``.
    * **exp** es la abreviatura de exponencial, y el número base ``e`` es un número natural que equivale aproximadamente a 2.7.

    Convierte esta fórmula ``TK=1/(ln(RT/RN)/B+1/TN)`` para obtener la temperatura en Kelvin que menos 273.15 equivale a grados Celsius.

    Esta relación es una fórmula empírica. Solo es precisa cuando la temperatura y la resistencia están dentro del rango efectivo.

**Aprender Más**

También puedes mostrar las temperaturas en Celsius y Fahrenheit calculadas en el LCD I2C LCD1602.


.. note::

    * Puedes abrir el archivo ``5.10_thermistor_lcd.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.10_thermistor_lcd``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/09107b4f-69d1-4f29-bf7f-5f2ff4b810e5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


