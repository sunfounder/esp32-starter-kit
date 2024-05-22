.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_tilt:

5.2 ¡Inclínalo!
==========================

El interruptor de inclinación es un dispositivo de 2 pines simple pero efectivo que contiene una bola de metal en su centro. Cuando el interruptor está en posición vertical, los dos pines están eléctricamente conectados, permitiendo el paso de la corriente. Sin embargo, cuando el interruptor se inclina o se coloca en un cierto ángulo, la bola de metal se mueve y rompe la conexión eléctrica entre los pines.

En este proyecto, utilizaremos el interruptor de inclinación para controlar la iluminación de un LED. Posicionando el interruptor de manera que active la acción de inclinación, podemos encender y apagar el LED basándonos en la orientación del interruptor.

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

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
    *   - :ref:`cpn_tilt`
        - \-

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Para Entrada
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Para Salida
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Pines de Uso Condicional (Entrada)**

    Los siguientes pines tienen resistencias de pull-up o pull-down incorporadas, por lo que no se requieren resistencias externas cuando **se usan como pines de entrada**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Pines de Uso Condicional
            - Descripción
        *   - IO13, IO15, IO2, IO4
            - Con una resistencia de 47K haciendo pull-up por defecto el valor es alto.
        *   - IO27, IO26, IO33
            - Con una resistencia de 4.7K haciendo pull-up por defecto el valor es alto.
        *   - IO32
            - Con una resistencia de 1K haciendo pull-down por defecto el valor es bajo.

* **Pines de Arranque (Entrada)**

    Los pines de arranque son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo 
    (es decir, reinicio por encendido).

    
    .. list-table::
        :widths: 5 15

        *   - Pines de Arranque
            - IO5, IO0, IO2, IO12, IO15 
    

    

    Generalmente, **no se recomienda usarlos como pines de entrada**. Si deseas usar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, por favor consulta la sección :ref:`esp32_strapping`.


**Esquemático**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

Cuando el interruptor de inclinación está en posición vertical, IO14 se establecerá en alto, resultando en el LED encendido. Por el contrario, cuando el interruptor de inclinación se inclina, IO14 se establecerá en bajo, causando que el LED se apague.

El propósito de la resistencia de 10K es mantener un estado bajo estable para IO14 cuando el interruptor de inclinación está en posición inclinada.


**Cableado**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

**Código**

.. note::

    * Puedes abrir el archivo ``5.2_tilt_switch.ino`` en la ruta de ``esp32-starter-kit-main\c\codes\5.2_tilt_switch``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5ed2406f-185c-407c-ac29-42036f174a5d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    


Después de subir el código con éxito, el LED se encenderá cuando el interruptor esté en posición vertical y se apagará cuando el interruptor esté inclinado.