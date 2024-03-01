.. _sh_colorful_ball:

2.3 Bolas Coloridas
=====================

En este proyecto, haremos que los LED RGB muestren diferentes colores.

Al hacer clic en bolas de diferentes colores en el área de escenario, causará que el LED RGB se ilumine en diferentes colores.

.. image:: img/4_color.png

Componentes Necesarios
------------------------

En este proyecto, necesitamos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - Kit de inicio ESP32
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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

Lo que aprenderás
---------------------

- El principio del LED RGB
- Copiar sprites y seleccionar diferentes disfraces
- Superposición de los tres colores primarios


Construir el circuito
------------------------

Un LED RGB empaqueta tres LEDs de rojo, verde y azul en una cáscara de plástico transparente o semitransparente. Puede mostrar varios colores cambiando el voltaje de entrada de los tres pines y superponiéndolos, lo que, según las estadísticas, puede crear 16,777,216 colores diferentes.

.. image:: img/4_rgb.png
    :width: 300

.. image:: img/circuit/3_color_ball_bb.png

Programación
------------------

**1. Seleccionar sprite**


Elimina el sprite predeterminado, luego elige el sprite **Bola**.

.. image:: img/4_ball.png

Y duplícalo 5 veces.

.. image:: img/4_duplicate_ball.png

Elige diferentes disfraces para estos 5 sprites **Bola** y muévelos a las posiciones correspondientes.

.. note::

    El color del disfraz del sprite **Bola3** necesita ser cambiado manualmente a rojo.

.. image:: img/4_rgb1.png
    :width: 800

**2. Hacer que los LED RGB se iluminen en el color apropiado**

Antes de entender el código, necesitamos entender el `modelo de color RGB <https://en.wikipedia.org/wiki/RGB_color_model>`_.

El modelo de color RGB es un modelo de color aditivo en el cual la luz roja, verde y azul se suman de diversas maneras para reproducir una amplia gama de colores.

Mezcla de colores aditiva: añadir rojo a verde produce amarillo; añadir verde a azul produce cian; añadir azul a rojo produce magenta; añadir los tres colores primarios juntos produce blanco.

.. image:: img/4_rgb_addition.png
  :width: 400

Entonces, el código para hacer que el LED RGB se ilumine de amarillo es el siguiente.

.. image:: img/4_yellow.png


Cuando se hace clic en el sprite Bola (bola amarilla), configuramos el pin 27 en alto (LED rojo encendido), el pin 26 en alto (LED verde encendido) y el pin 25 en bajo (LED azul apagado) para que el LED RGB se ilumine de amarillo.

Puedes escribir códigos para otros sprites de la misma manera para hacer que los LED RGB se iluminen en los colores correspondientes.

**3. Sprite Bola2 (azul claro)**

.. image:: img/4_blue.png

**4. Sprite Bola3 (rojo)**

.. image:: img/4_red.png

**5. Sprite Bola4 (verde)**

.. image:: img/4_green.png

**6. Sprite Bola5 (morado)**

.. image:: img/4_purple.png

