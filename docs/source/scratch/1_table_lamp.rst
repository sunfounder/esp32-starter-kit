.. _sh_table_lamp:

2.1 Lámpara de Mesa
=====================

Aquí, conectamos un LED en la protoboard y hacemos que el sprite controle el parpadeo de este LED.

Cuando se hace clic en el sprite del Botón en el escenario, el LED parpadeará 5 veces y luego se detendrá.

.. image:: img/2_button.png

Componentes Necesarios
---------------------------

Para este proyecto, necesitaremos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

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

Lo Que Aprenderás
---------------------

- Protoboard, LEDs y Resistencias
- Construir un circuito en una protoboard
- Eliminar y seleccionar sprites
- Cambiar disfraces


- Establecer un número limitado de bucles de repetición

Construir el Circuito
-----------------------

Sigue el diagrama a continuación para construir el circuito en la protoboard.

Dado que el ánodo del LED (el pin más largo) está conectado al pin 26 a través de una resistencia de 220Ω, y el cátodo del LED está conectado a GND, puedes encender el LED dando un nivel alto al pin 9.

.. image:: img/circuit/1_hello_led_bb.png

Programación
------------------

La programación completa se divide en 3 partes, la primera parte es seleccionar el sprite deseado, la segunda parte es cambiar el disfraz del sprite para que parezca clickeable, y la tercera parte es hacer que el LED parpadee.

**1. Seleccionar el sprite Button3**

Elimina el sprite de Tobi existente utilizando el botón Eliminar en la esquina superior derecha, y selecciona un sprite de nuevo.

.. image:: img/2_tobi.png

Aquí, seleccionamos el sprite **Button3**.

.. image:: img/2_button3.png

Haz clic en Disfraces en la esquina superior derecha y verás que el sprite Button3 tiene 2 disfraces, establecemos **button3-a** como liberado y **button3-b** como presionado.

.. image:: img/2_button3_2.png

**2. Cambiando disfraces**.

Cuando se hace clic en el sprite (**paleta de Eventos**), cambia al disfraz para **button3-b** (**paleta de Apariencias**).

.. image:: img/2_switch.png

**3. Hacer que el LED parpadee 5 veces**

Usa el bloque [Repetir] para hacer que el LED parpadee 5 veces (ciclo Alto -> Bajo) y finalmente cambia el disfraz de vuelta a **button3-a**.

* [Repetir 10]: número limitado de bucles de repetición, puedes establecer el número de repeticiones tú mismo, de la **paleta de Control**.

.. image:: img/2_led_on_off.png

