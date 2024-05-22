.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_rotating_fan:

2.9 Ventilador Rotativo
========================

En este proyecto, haremos una estrella giratoria y un ventilador.

Al hacer clic en los sprites de flecha izquierda y derecha en el escenario, controlaremos la rotación en el sentido de las agujas del reloj y en sentido contrario del motor y del sprite de la estrella, haz clic en el sprite de la estrella para detener la rotación.

.. image:: img/13_fan.png

Componentes Necesarios
-------------------------

Para este proyecto, necesitaremos los siguientes componentes.

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
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_l293d`
        - \-

Lo Que Aprenderás
---------------------

- Principio de funcionamiento del motor
- Función de difusión
- Detener otros scripts en el bloque de sprite

Construye el Circuito
-----------------------

.. image:: img/circuit/10_rotaing_fan_bb.png

Programación
------------------
El efecto que queremos lograr es usar 2 sprites de flecha para controlar la rotación en el sentido de las agujas del reloj y en sentido contrario del motor y del sprite de la estrella respectivamente, haciendo clic en el sprite de la estrella se detendrá la rotación del motor.

**1. Añadir sprites**

Elimina el sprite predeterminado, luego selecciona el sprite **Estrella** y el sprite **Flecha1**, y copia **Flecha1** una vez.

.. image:: img/13_star.png

En la opción **Disfraces**, cambia el sprite **Flecha1** a un disfraz de dirección diferente.

.. image:: img/13_star1.png

Ajusta el tamaño y la posición del sprite adecuadamente.

.. image:: img/13_star2.png

**2. Sprite de flecha izquierda**

Cuando se hace clic en este sprite, transmite un mensaje - girar, luego establece el pin digital12 en bajo y el pin14 en alto, y establece la variable **flag** en 1. Si haces clic en el sprite de flecha izquierda, encontrarás que el motor gira en sentido antihorario, si tu giro es en sentido horario, entonces intercambia las posiciones de pin12 y pin14.

Hay 2 puntos a tener en cuenta aquí.

* `[difundir <https://en.scratch-wiki.info/wiki/Broadcast>`_]: de la paleta **Eventos**, se utiliza para transmitir un mensaje a los otros sprites, cuando los otros sprites reciben este mensaje, realizará un evento específico. Por ejemplo, aquí es **girar**, cuando el sprite **estrella** recibe este mensaje, ejecuta el script de rotación.
* variable flag: La dirección de rotación del sprite estrella está determinada por el valor de flag. Por lo tanto, cuando crees la variable **flag**, necesitas hacer que se aplique a todos los sprites.

.. image:: img/13_left.png
    :width: 600

**3. Sprite de flecha derecha**

Cuando se hace clic en este sprite, transmite un mensaje girar, luego establece el pin digital12 en alto y el pin14 en bajo para hacer que el motor gire en sentido horario y establece la variable **flag** en 0.

.. image:: img/13_right.png

**4. Sprite de estrella**

Aquí se incluyen 2 eventos.

* Cuando el sprite **estrella** recibe el mensaje transmitido girar, determina el valor de flag; si flag es 1, gira 10 grados a la izquierda, de lo contrario, se invierte. Dado que está en [SIEMPRE], seguirá girando.
* Cuando se hace clic en este sprite, se establecen ambos pines del motor en alto para hacer que deje de girar y detener los otros scripts en este sprite.

.. image:: img/13_broadcast.png

