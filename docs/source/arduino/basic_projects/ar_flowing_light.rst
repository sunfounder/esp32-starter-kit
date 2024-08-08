.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_flowing_light:

6.2 Luz Fluyente
=======================

¿Alguna vez has querido añadir un elemento divertido e interactivo a tu espacio vital?
Este proyecto implica crear una luz corriente usando una tira de LED WS2812 y un módulo de evitación de obstáculos.
La luz corriente cambia de dirección cuando se detecta un obstáculo, lo que la convierte en una adición emocionante a la decoración de tu hogar u oficina.

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Diagrama Esquemático**

.. image:: ../../img/circuit/circuit_6.2_flowing_led.png
    :align: center

La tira de LED WS2812 está compuesta por una serie de LEDs individuales que pueden ser programados para mostrar diferentes colores y patrones.
En este proyecto, la tira está configurada para mostrar una luz corriente que se mueve en una dirección particular y
cambia de dirección cuando un obstáculo es detectado por el módulo de evitación de obstáculos.

**Cableado**

.. image:: ../../img/wiring/6.2_flowing_light_bb.png
    

**Código**

.. note::

    * Puedes abrir el archivo ``6.2_flowing_led.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\6.2_flowing_led`` directamente.
    * O copia este código en el IDE de Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ff625cb6-2efd-436a-9b59-5dd967191338/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Este proyecto extiende la funcionalidad del proyecto :ref:`ar_rgb_strip` añadiendo la capacidad de mostrar colores aleatorios en la tira de LED.
Adicionalmente, se ha incluido un módulo de evitación de obstáculos para cambiar dinámicamente la dirección de la luz corriente.
