.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_protect_heart:

2.19 JUEGO - Protege Tu Corazón
=====================================

En este proyecto, hagamos un juego que ponga a prueba la velocidad de reacción.

En el escenario, hay un corazón protegido en una caja rectangular, y hay flechas volando hacia este corazón desde cualquier posición en el escenario. El color de la flecha alternará entre negro y blanco al azar y la flecha volará cada vez más rápido.

Si el color de la caja rectangular y el color de la flecha son los mismos, la flecha se bloquea afuera y se suma 1 al nivel; si el color de ambos no es el mismo, la flecha atravesará el corazón y el juego terminará.

Aquí el color de la caja rectangular está controlado por el módulo de Seguimiento de Línea. Cuando el módulo se coloca sobre una superficie negra (una superficie que refleja), el color de la caja rectangular es negro, de lo contrario, es blanco.

Así que necesitas decidir si colocar el módulo de Seguimiento de Línea sobre una superficie blanca o negra según el color de la flecha.

.. image:: img/22_heart.png

Componentes Necesarios
-------------------------

Para este proyecto, necesitaremos los siguientes componentes.

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

    *   - INTRODUCCIÓN AL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

Construir el Circuito
-----------------------

Este es un módulo digital de Seguimiento de Línea, cuando detecta una línea negra, emite 1; cuando detecta una línea blanca, emite un valor de 0. Además, puedes ajustar su distancia de detección a través del potenciómetro en el módulo.

Ahora construye el circuito según el diagrama a continuación.

.. image:: img/circuit/20_protect_heart_bb.png

.. note::

    Antes de empezar el proyecto, necesitas ajustar la sensibilidad del módulo.

    Conecta según el diagrama anterior, luego enciende la placa R3 (ya sea directamente en el cable USB o el cable de botón de batería de 9V), sin subir el código.

    Ahora pega una cinta eléctrica negra en el escritorio, coloca el módulo de Seguimiento de Línea a una altura de 2cm del escritorio.

    Con el sensor mirando hacia abajo, observa el LED de señal en el módulo para asegurarte de que se ilumina en la mesa blanca y se apaga en la cinta negra.

    Si no, necesitas ajustar el potenciómetro en el módulo, para que pueda hacer el efecto anterior.


Programación
------------------

Aquí necesitamos crear 3 sprites, **Corazón**, **Caja Cuadrada** y **Flecha1**.

* **Corazón**: se detiene en medio del escenario, si es tocado por el sprite **Flecha1**, el juego termina.
* **Caja Cuadrada**: Hay dos tipos de disfraces, negro y blanco, y cambiará de disfraz según el valor del módulo de Seguimiento de Línea.
* **Flecha**: vuela hacia el centro del escenario desde cualquier posición en negro/blanco; si su color coincide con el color del sprite **Caja Cuadrada**, se bloquea y vuelve a volar hacia el centro del escenario desde una posición aleatoria; si su color no coincide con el color del sprite **Caja Cuadrada**, pasa a través del sprite **Corazón** y el juego termina.

**1. Añade el sprite Caja Cuadrada**

Dado que el sprite Flecha1 y Caja Cuadrada ambos tienen disfraces blancos, para que se puedan mostrar en el escenario, ahora llena el fondo con un color que puede ser cualquier color excepto negro, blanco y rojo.

* Haz clic en **Backdrop1** para ir a su página de **Fondos**.
* Selecciona el color que quieras llenar.
* Usa la herramienta **Rectángulo** para dibujar un rectángulo del mismo tamaño que el tablero de dibujo.

.. image:: img/22_heart0.png

Elimina el sprite predeterminado, usa el botón **Elegir un Sprite** para añadir el sprite **Caja Cuadrada** y ajusta sus coordenadas x e y a (0, 0).

.. image:: img/22_heart1.png

Ve a la página de **Disfraces** del sprite **Caja Cuadrada** y configura los disfraces negro y blanco.

* Haz clic en la herramienta de selección
* Selecciona el rectángulo en el lienzo
* Selecciona el color de relleno como negro
* y nombra el disfraz **Negro**

.. image:: img/22_heart2.png

Selecciona el segundo disfraz, configura el color de relleno a blanco, nómbralo Blanco y elimina el resto del disfraz.

.. image:: img/22_heart3.png

**2. Añade el sprite Corazón**

También añade un sprite **Corazón**, ajusta su posición a (0, 0) y reduce su tamaño para que parezca estar ubicado dentro de la Caja Cuadrada.

.. image:: img/22_heart5.png

En la página de **Disfraces**, ajusta el disfraz morado del corazón para que parezca estar roto.

.. image:: img/22_heart6.png

**3. Añade el sprite Flecha1**

Añade un sprite **Flecha1**.

.. image:: img/22_heart7.png

En la página de **Disfraces**, mantén y copia el disfraz que mira hacia la derecha y configura su color a negro y blanco.

.. image:: img/22_heart8.png


**4. Programación para el sprite Caja Cuadrada**

Vuelve a la página de **Bloques** y programa el sprite **Caja Cuadrada**.

* Así que cuando el valor del pin digital 2 (módulo de Seguimiento de Línea) es 1 (línea negra detectada), entonces cambia el disfraz a **Negro**.
* De lo contrario, cambia el disfraz a **Blanco**.

.. image:: img/22_heart4.png


**5. Programación para el sprite Corazón**

El sprite **Corazón** está protegido dentro de **Caja Cuadrada**, y por defecto es un disfraz rojo. Cuando el sprite Flecha1 lo toca, el juego termina.

.. image:: img/22_heart9.png

**6. Programación para el sprite Flecha1**

Haz que el sprite **Flecha1** se oculte y cree un clon cuando se haga clic en la bandera verde.

.. image:: img/22_heart10.png

Crea un bloque [init] para inicializar la posición, orientación y color del sprite **Flecha1**.

Aparece en una ubicación aleatoria, y si la distancia entre él y el sprite **Corazón** es menor de 200, se mueve hacia afuera hasta que la distancia sea mayor de 200.

.. image:: img/22_heart11.png

Configura su dirección para enfrentar al sprite **Corazón**.

.. image:: img/22_heart12.png

Haz que su color alterne aleatoriamente entre negro/blanco.

* Variable color es 0, cambia el disfraz a **Blanco**.
* Variable color es 1, cambia el disfraz a **Negro**.

.. image:: img/22_heart14.png

Ahora deja que comience a moverse, se moverá más rápido a medida que aumenta el valor de la variable **nivel**.

.. image:: img/22_heart13.png

Ahora configura su efecto de colisión con el sprite **Caja Cuadrada**.

* Si el sprite **Flecha1** y el sprite **Caja Cuadrada** tienen el mismo color (que se modificará según el valor del módulo de Seguimiento de Línea), ya sea negro o blanco, se crea un nuevo clon y el juego continúa.
* Si sus colores no coinciden, el sprite **Flecha1** continúa moviéndose y el juego termina cuando golpea al sprite **Corazón**.

.. image:: img/22_heart15.png

.. note::
    Los dos bloques [tocar color()] necesitan recoger los disfraces negro/blanco de Caja Cuadrada por separado.

    .. image:: img/22_heart16.png
