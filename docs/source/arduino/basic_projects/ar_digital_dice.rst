.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_dice:

6.4 Dados Digitales
=============================

Este proyecto se basa en el proyecto :ref:`py_7_segment` agregando un botón para controlar el dígito mostrado en el display de siete segmentos.

En este proyecto, se genera un número aleatorio y se muestra en el display de siete segmentos para simular un lanzamiento de dados. Cuando se presiona el botón, se muestra un número estable (seleccionado al azar de 1 a 6) en el display de siete segmentos. Presionar el botón nuevamente iniciará la simulación de un lanzamiento de dados, generando números aleatorios como antes. Este ciclo continúa cada vez que se presiona el botón.

**Componentes Necesarios**

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

    *   - INTRODUCCIÓN DE COMPONENTES
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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Esquemático**

.. image:: ../../img/circuit/circuit_6.6_electronic_dice.png

Este proyecto se basa en el proyecto :ref:`ar_7_segment` agregando un botón para controlar el dígito mostrado en el display de siete segmentos.

El botón está conectado directamente a IO13 sin una resistencia de pull-up o pull-down externa porque IO13 tiene una resistencia de pull-up interna de 47K, eliminando la necesidad de una resistencia externa adicional.

**Cableado**

.. image:: ../../img/wiring/6.6_DICE_bb.png

**Código**

.. note::

    * Abre el archivo ``6.4_digital_dice.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\6.4_digital_dice``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ad904f48-cd24-49ce-ad92-91b1fb76364d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Este proyecto se basa en :ref:`ar_7_segment` con un botón para iniciar/pausar el desplazamiento de la pantalla en el Display de 7 segmentos.

Cuando se presiona el botón, el display de 7 segmentos desplaza los números del 1-6, y cuando se suelta el botón, muestra un número aleatorio.
