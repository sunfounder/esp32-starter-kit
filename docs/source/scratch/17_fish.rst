.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_fishing:

2.17 JUEGO - Pesca
===========================

Aquí, jugamos a un juego de pesca con un botón.

Cuando el script está en ejecución, los peces nadan de izquierda a derecha en el escenario. Debes presionar el botón cuando el pez esté casi cerca del anzuelo (se recomienda presionarlo durante más tiempo) para atrapar al pez, y el número de peces capturados se registrará automáticamente.

.. image:: img/18_fish.png

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Construir el Circuito
-----------------------

El botón es un dispositivo de 4 pines, ya que el pin 1 está conectado al pin 2, y el pin 3 al pin 4. Cuando se presiona el botón, los 4 pines se conectan, cerrando así el circuito.

.. image:: img/5_buttonc.png

Construye el circuito según el siguiente diagrama.

* Conecta uno de los pines del lado izquierdo del botón al pin14, que está conectado a una resistencia de pull-down y un condensador de 0.1uF (104) (para eliminar jitter y producir un nivel estable cuando el botón está funcionando).
* Conecta el otro extremo de la resistencia y el condensador a GND, y uno de los pines del lado derecho del botón a 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programación
------------------

Primero necesitamos seleccionar un fondo **Subacuático**, luego añadir un sprite **Pez** y permitir que nade de un lado a otro en el escenario. Después, dibujar un sprite **Anzuelo** y controlarlo con un botón para comenzar a pescar. Cuando el sprite **Pez** toque el sprite **Anzuelo** en estado de pesca (se vuelve rojo), quedará enganchado.

**1. Añadir un fondo**

Usa el botón **Elegir un Fondo** para añadir un fondo **Subacuático**.

.. image:: img/18_under.png

**2. Sprite Anzuelo**

El sprite **Anzuelo** generalmente permanece bajo el agua en estado amarillo; cuando se presiona el botón, está en estado de pesca (rojo) y se mueve por encima del escenario.

No hay un sprite **Anzuelo** en Pictoblox, podemos modificar el sprite **Glow-J** para que parezca un anzuelo.

* Añade el sprite **Glow-J** a través de **Elegir un Sprite**.

.. image:: img/18_hook.png

* Ahora ve a la página de **Disfraces** del sprite **Glow-J**, selecciona el relleno Cyan en la pantalla y elimínalo. Luego cambia el color de J a rojo y también reduce su ancho. El punto más importante a tener en cuenta es que necesitas que la parte superior esté justo en el punto central.

.. image:: img/18_hook1.png

* Usa la **Herramienta de Línea** para dibujar una línea lo más larga posible desde el punto central hacia arriba (línea fuera del escenario). Ahora que el sprite está dibujado, establece el nombre del sprite a **Anzuelo** y muévelo a la posición correcta.

.. image:: img/18_hook2.png

* Cuando se haga clic en la bandera verde, establece el efecto de color del sprite a 30 (amarillo) y establece su posición inicial.

.. image:: img/18_hook3.png

* Si se presiona el botón, establece el efecto de color a 0 (rojo, estado de inicio de pesca), espera 0.1 y luego mueve el sprite **Anzuelo** hacia la parte superior del escenario. Suelta el botón y permite que el **Anzuelo** regrese a su posición inicial.

.. image:: img/18_hook4.png

**3. Sprite Pez**

El efecto que se busca con el sprite **Pez** es moverse de izquierda a derecha en el escenario, y cuando se encuentra con un sprite **Anzuelo** en estado de pesca, se encoge y se mueve a una posición específica y luego desaparece, para luego clonar un nuevo sprite **pez** nuevamente.

* Ahora añade el sprite **pez** y ajusta su tamaño y posición.

.. image:: img/18_fish1.png

* Crea una variable **puntuación** para almacenar el número de peces capturados, oculta este sprite y clónalo.

.. image:: img/18_fish2.png

* Muestra el clon del sprite **pez**, cambia su disfraz y finalmente establece la posición inicial.

.. image:: img/18_fish3.png

* Haz que el clon del sprite **pez** se mueva de izquierda a derecha y rebote cuando toque el borde.

.. image:: img/18_fish4.png

* El sprite **pez** (del clon) no reaccionará cuando pase el sprite **Anzuelo**; cuando toque el sprite **Anzuelo** en estado de pesca (se vuelve rojo), será capturado, en este punto la puntuación (variable puntuación) +1, y también mostrará una animación de puntuación (se encoge un 40%, se mueve rápidamente a la posición del marcador y desaparece). Al mismo tiempo, se crea un nuevo pez (un nuevo clon del sprite pez) y el juego continúa.

.. note::
    
    Necesitas hacer clic en el área de color en el bloque [Tocar color] y luego seleccionar la herramienta cuentagotas para recoger el color rojo del sprite **Anzuelo** en el escenario. Si eliges un color arbitrariamente, este bloque [Tocar color] no funcionará.

.. image:: img/18_fish5.png
