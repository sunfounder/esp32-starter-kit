.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_7_segment:

2.5 Pantalla de 7 Segmentos
===================================

¡Bienvenido a este fascinante proyecto! En este proyecto, exploraremos el encantador mundo de mostrar números del 0 al 9 en una pantalla de siete segmentos.

Imagina activar este proyecto y ser testigo de cómo una pequeña y compacta pantalla brilla intensamente con cada número del 0 al 9. Es como tener una pantalla en miniatura que muestra los dígitos de una manera cautivadora. Controlando los pines de señal, puedes cambiar fácilmente el número mostrado y crear varios efectos atractivos.

A través de conexiones de circuito simples y programación, aprenderás cómo interactuar con la pantalla de siete segmentos y dar vida a los números deseados. Ya sea un contador, un reloj o cualquier otra aplicación intrigante, la pantalla de siete segmentos será tu compañero confiable, añadiendo un toque de brillantez a tus proyectos.

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
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Pines Disponibles**

Aquí está una lista de los pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_2.5_74hc595_7_segment.png

Aquí, el principio de cableado es básicamente el mismo que en :ref:`ar_74hc595`, la única diferencia es que Q0-Q7 están conectados a los pines a ~ g de la Pantalla de 7 Segmentos.

.. list-table:: Cableado
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - Pantalla LED de Segmento
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**Cableado**


.. image:: ../../img/wiring/2.5_segment_bb.png
    :width: 800

**Código**

.. note::

    * Abre el archivo ``2.5_7segment.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\2.5_7segment``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/937f5e3f-2d9e-4c75-8331-ace3c0876182/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de subir el código con éxito, podrás ver la Pantalla de Segmento LED mostrar 0~9 en secuencia.

**¿Cómo funciona?**

En este proyecto, estamos usando la función ``shiftOut()`` para escribir el número binario en el registro de desplazamiento.

Supongamos que la Pantalla de 7 Segmentos muestra el número "2". Este patrón de bits corresponde a los segmentos **f**, **c** y **dp** apagados (bajo), mientras que los segmentos **a**, **b**, **d**, **e** y **g** están encendidos (alto). Esto es "01011011" en binario y "0x5b" en notación hexadecimal.

Por lo tanto, necesitarías llamar a ``shiftOut(DS,SHcp,MSBFIRST,0x5b)`` para mostrar el número "2" en la pantalla de 7 segmentos.

.. image:: img/7_segment2.png

* `Hexadecimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `Convertidor Binario a Hexadecimal <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

La siguiente tabla muestra los patrones hexadecimales que necesitan ser escritos en el registro de desplazamiento para mostrar los números del 0 al 9 en una pantalla de 7 segmentos.


.. list-table:: Código de Glifo
    :widths: 20 20 20
    :header-rows: 1

    *   - Números	
        - Código Binario
        - Código Hex  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Escribe estos códigos en ``shiftOut()`` para hacer que la Pantalla de Segmento LED muestre los números correspondientes.
