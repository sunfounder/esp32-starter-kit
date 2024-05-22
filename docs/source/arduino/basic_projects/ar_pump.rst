.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_pump:

4.2 Bombeo
===================
En este fascinante proyecto, exploraremos cómo controlar una bomba de agua utilizando el L293D.

En el ámbito del control de bombas de agua, las cosas son un poco más sencillas en comparación con el control de otros motores. La belleza de este proyecto radica en su simplicidad: no hay que preocuparse por la dirección de rotación. Nuestro objetivo principal es activar con éxito la bomba de agua y mantenerla funcionando.

**Componentes Necesarios**

En este proyecto, necesitaremos los siguientes componentes.

Es definitivamente conveniente comprar todo el kit, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    * - Nombre
      - ARTÍCULOS EN ESTE KIT
      - ENLACE
    * - Kit de Inicio ESP32
      - 320+
      - |link_esp32_starter_kit|

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    * - INTRODUCCIÓN DE COMPONENTES
      - ENLACE DE COMPRA

    * - :ref:`cpn_esp32_wroom_32e`
      - |link_esp32_wroom_32e_buy|
    * - :ref:`cpn_esp32_camera_extension`
      - \-
    * - :ref:`cpn_breadboard`
      - |link_breadboard_buy|
    * - :ref:`cpn_wires`
      - |link_wires_buy|
    * - :ref:`cpn_pump`
      - \-
    * - :ref:`cpn_l293d`
      - \-

**Pines Disponibles**

Aquí está la lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


**Cableado**

.. note::

    Se recomienda aquí insertar la batería y luego deslizar el interruptor en la placa de expansión a la posición ON para activar el suministro de la batería.

.. image:: ../../img/wiring/4.2_pump_l293d_bb.png

**Código**

.. note::

  * Puedes abrir el archivo ``4.2_pump.ino`` en la ruta ``esp32-starter-kit-main\c\codes\4.2_pump``. 
  * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
  * :ref:`unknown_com_port`
   
.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/a56216f9-eba8-4fdc-8bbb-91337095e543/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Conecta el tubo a la bomba y colócala dentro del contenedor lleno de agua. Una vez que el código haya sido subido con éxito, observarás que el agua del contenedor se drena gradualmente. Durante este experimento, por favor asegúrate de que el circuito eléctrico se mantenga alejado del agua para evitar cortocircuitos!
