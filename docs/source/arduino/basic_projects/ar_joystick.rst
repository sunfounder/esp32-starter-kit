.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_joystick:

5.11 Alternar el Joystick
================================
Si juegas muchos videojuegos, entonces deberías estar muy familiarizado con el Joystick.
Se suele utilizar para mover el personaje, rotar la pantalla, etc.

El principio detrás de la capacidad del Joystick para permitir que la computadora lea nuestras acciones es muy simple.
Se puede pensar como compuesto por dos potenciómetros que están perpendiculares entre sí.
Estos dos potenciómetros miden el valor analógico del joystick vertical y horizontalmente, resultando en un valor (x,y) en un sistema de coordenadas rectangulares planas.


El joystick de este kit también tiene una entrada digital, que se activa cuando se presiona el joystick.

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 15

        *   - Para Entrada Analógica
            - IO14, IO25, I35, I34, I39, I36
        *   - Para Entrada Digital
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
            
**Esquemático**

.. image:: ../../img/circuit/circuit_5.11_joystick.png

El pin SW (eje Z) está conectado a IO33, que tiene una resistencia de pull-up de 4.7K incorporada. Por lo tanto, cuando no se presiona el botón SW, emitirá un nivel alto. Cuando se presiona el botón, emitirá un nivel bajo.

I34 e I35 cambiarán sus valores a medida que manipules el joystick. El rango de valores es de 0 a 4095.

**Cableado**

.. image:: ../../img/wiring/5.11_joystick_bb.png

**Código**

.. note::

    * Abre el archivo ``5.11_joystick.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.11_joystick``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a2065d70-d207-4e51-b03e-ffd2a26597ef/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Abre el monitor serie después de que el código se haya cargado con éxito para ver los valores x, y, z del joystick.

Recuerda configurar la velocidad de comunicación serial a 115200.

* Los valores de los ejes x e y son valores analógicos que varían de 0 a 4095.
* El eje Z es un valor digital con un estado de 1 o 0 (cuando se presiona, es 0).
