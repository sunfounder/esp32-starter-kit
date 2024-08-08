.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_parrot:

2.15 JUEGO - Loro Flappy
==============================

Aquí utilizamos el módulo ultrasónico para jugar un juego del loro flappy.

Después de ejecutar el script, el bambú verde se moverá lentamente de derecha a izquierda a una altura aleatoria. Ahora coloca tu mano sobre el módulo ultrasónico, si la distancia entre tu mano y el módulo ultrasónico es menor a 10, el loro volará hacia arriba, de lo contrario caerá hacia abajo.
Necesitas controlar la distancia entre tu mano y el módulo ultrasónico para que el Loro pueda evitar el bambú verde (Paleta), si lo toca, el juego termina.

.. image:: img/15_parrot.png

Componentes Requeridos
-------------------------

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

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Construir el Circuito
-----------------------

Un módulo sensor ultrasónico es un instrumento que mide la distancia a un objeto usando ondas sonoras ultrasónicas.
Tiene dos sondas. Una es para enviar ondas ultrasónicas y la otra es para recibir las ondas y transformar el tiempo de envío y recepción en una distancia, detectando así la distancia entre el dispositivo y un obstáculo.

Ahora construye el circuito según el siguiente diagrama.

.. image:: img/circuit/16_flappy_parrot_bb.png

Programación
------------------

El efecto que queremos lograr es usar el módulo ultrasónico para controlar la altura de vuelo del sprite **Loro**, evitando al mismo tiempo el sprite **Paleta**.


**1. Agregar un sprite**

Elimina el sprite predeterminado y utiliza el botón **Elegir un Sprite** para agregar el sprite **Loro**. Establece su tamaño al 50% y mueve su posición al centro izquierdo.

.. image:: img/15_sprite.png

Ahora agrega el sprite **Paleta**, establece su tamaño al 150%, su ángulo a 180 y mueve su posición inicial a la esquina superior derecha.

.. image:: img/15_sprite1.png

Ve a la página **Disfraces** del sprite **Paleta** y elimina el Contorno.

.. image:: img/15_sprite2.png

**2. Programación para el Sprite Loro**

Ahora programa el sprite **Loro**, que está en vuelo y la altitud de vuelo está determinada por la distancia de detección del módulo ultrasónico.


* Cuando se hace clic en la bandera verde, cambia el disfraz cada 0.2s para que siempre esté en vuelo.

.. image:: img/15_parr1.png

* Lee el valor del módulo ultrasónico y almacénalo en la variable **distancia** después de redondearlo con el bloque [redondear].


.. image:: img/15_parr2.png

* Si la distancia de detección ultrasónica es menor a 10cm, deja que la coordenada y aumente en 50, el sprite **Loro** volará hacia arriba. De lo contrario, el valor de la coordenada y disminuye en 40, **Loro** caerá.

.. image:: img/15_parr3.png

* Si el sprite **Loro** toca el sprite **Paleta**, el juego termina y el script deja de ejecutarse.

.. image:: img/15_parr4.png


**3. Scripting para el sprite Paddle**

Ahora escribe el script para el sprite **Paddle**, que necesita aparecer aleatoriamente en el escenario.

* Oculta el sprite **Paddle** cuando se haga clic en la bandera verde y clónalo al mismo tiempo. El bloque [`crear clon de <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`] es un bloque de control y un bloque de pila. Crea un clon del sprite en el argumento. También puede clonar el sprite en el que se está ejecutando, creando clones de clones, recursivamente.

.. image:: img/15_padd.png

* Cuando **Paddle** se presenta como un clon, su posición es 220 (el más a la derecha) para la coordenada x y su coordenada y en (-125 a 125) aleatorio (altura aleatoria).

.. image:: img/15_padd1.png

* Utiliza el bloque [repetir] para hacer que el valor de su coordenada x disminuya lentamente, para que puedas ver el clon del sprite **Paddle** moviéndose lentamente de la derecha hacia la izquierda hasta que desaparezca.

.. image:: img/15_padd2.png

* Reclona un nuevo sprite **Paddle** y elimina el clon anterior.

.. image:: img/15_padd3.png