.. _sh_balloon:

2.12 JUEGO - Inflando el Globo
=========================================

Aquí, jugaremos un juego de inflar globos.

Después de hacer clic en la bandera verde, el globo se hará más y más grande. Si el globo es demasiado grande, explotará; si el globo es demasiado pequeño, caerá; necesitas juzgar cuándo presionar el botón para hacerlo volar hacia arriba.

.. image:: img/13_balloon0.png

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Lo Que Aprenderás
---------------------

- Pintar disfraz para el sprite


Construye el Circuito
-----------------------

El botón es un dispositivo de 4 pines, ya que el pin 1 está conectado al pin 2, y el pin 3 al pin 4, cuando se presiona el botón, los 4 pines se conectan, cerrando así el circuito.

.. image:: img/5_buttonc.png

Construye el circuito según el siguiente diagrama.

* Conecta uno de los pines en el lado izquierdo del botón al pin14, que está conectado a una resistencia de pull-down y un capacitor de 0.1uF (104) (para eliminar la fluctuación y emitir un nivel estable cuando el botón está funcionando).
* Conecta el otro extremo de la resistencia y el capacitor a GND, y uno de los pines en el lado derecho del botón a 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programación
------------------

**1. Añadir un sprite y un fondo**

Elimina el sprite predeterminado, haz clic en el botón **Elegir un Sprite** en la esquina inferior derecha del área de sprites, luego selecciona el sprite **Globo1**.

.. image:: img/13_balloon1.png

Añade un fondo **Paseo Marítimo** a través del botón **Elegir un fondo**, o cualquier otro fondo que te guste.

.. image:: img/13_balloon2.png

**2. Pintar un disfraz para el sprite Globo1**

Ahora vamos a dibujar un disfraz de efecto de explosión para el sprite del globo.

Ve a la página **Disfraces** del sprite **Globo1**, haz clic en el botón **Elegir un Disfraz** en la esquina inferior izquierda, y selecciona **Pintar** para abrir un **Disfraz** en blanco.

.. image:: img/13_balloon7.png

Selecciona un color y luego usa la herramienta **Pincel** para dibujar un patrón.

.. image:: img/13_balloon3.png

Selecciona nuevamente un color, haz clic en la herramienta Rellenar y mueve el ratón dentro del patrón para llenarlo de color.

.. image:: img/13_balloon4.png

Finalmente, escribe el texto BOOM, para que el disfraz de efecto de explosión esté completo.

.. image:: img/13_balloon5.png

**3. Programación del sprite Globo**

Establece la posición inicial y el tamaño del sprite **Globo1**.

.. image:: img/13_balloon6.png

Luego, permite que el sprite **Globo** se haga lentamente más grande.

.. image:: img/13_balloon8.png

Cuando se presiona el botón (el valor es 1), el tamaño del sprite **Globo1** deja de aumentar.

* Cuando el tamaño es menor a 90, caerá (la coordenada y disminuye).
* Cuando el tamaño es mayor a 90 y menor a 120, volará hacia el cielo (la coordenada y aumenta).

.. image:: img/13_balloon9.png

Si el botón no ha sido presionado, el globo se hace lentamente más grande y cuando el tamaño es mayor a 120, explotará (cambia al disfraz de efecto de explosión).

.. image:: img/13_balloon10.png

