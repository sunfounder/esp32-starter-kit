.. _sh_breakout_clone:

2.16 JUEGO - Clon de Breakout
===============================

Aquí utilizamos el potenciómetro para jugar a un clon del juego Breakout.

Después de hacer clic en la bandera verde, necesitarás usar el potenciómetro para controlar la paleta en el escenario y atrapar la bola para que pueda subir y golpear los ladrillos. Si desaparecen todos los ladrillos, ganas el juego; si no atrapas la bola, pierdes.

.. image:: img/17_brick.png

Componentes Necesarios
--------------------------

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

Construir el Circuito
-----------------------

El potenciómetro es un elemento resistivo con 3 terminales, los 2 pines laterales están conectados a 5V y GND, y el pin central está conectado al pin35. Después de la conversión por el convertidor ADC de la placa esp32, el rango de valores es de 0-4095.

.. image:: img/circuit/5_moving_mouse_bb.png

Programación
------------------

Hay 3 sprites en el escenario.

**1. Sprite de la Paleta**

El efecto que se busca con la **Paleta** es que la posición inicial esté en el medio de la parte inferior del escenario, y sea controlada por un potenciómetro para moverla hacia la izquierda o hacia la derecha.

* Elimina el sprite predeterminado, usa el botón **Elegir un Sprite** para añadir el sprite **Paleta**, y ajusta sus coordenadas x e y a (0, -140).

    .. image:: img/17_padd1.png

* Ve a la página de **Disfraces**, elimina el contorno y cambia su color a gris oscuro.

    .. image:: img/17_padd3.png

* Ahora programa el sprite **Paleta** para establecer su posición inicial a (0, -140) cuando se haga clic en la bandera verde, y lee el valor del pin35 (potenciómetro) en la variable **a0**. Dado que el sprite **Paleta** se mueve de izquierda a derecha en el escenario en las coordenadas x de -195 a 195, necesitas usar el bloque [map] para mapear el rango de la variable **a0** de 0~4095 a -195~195.

    .. image:: img/17_padd2.png

* Ahora puedes girar el potenciómetro para ver si la **Paleta** puede moverse hacia la izquierda y hacia la derecha en el escenario.

**2. Sprite de la Bola**

El efecto del sprite de la bola es que se mueva por el escenario y rebote cuando toque el borde; rebota hacia abajo si toca el bloque sobre el escenario; rebota hacia arriba si toca el sprite de la **Paleta** durante su caída; si no, el script deja de ejecutarse y el juego termina.

* Añade el sprite **Bola**.

    .. image:: img/17_ball1.png

* Cuando se haga clic en la bandera verde, establece el ángulo del sprite **Bola** a 45° y la posición inicial a (0, -120).

    .. image:: img/17_ball2.png

* Ahora deja que el sprite **Bola** se mueva por el escenario y rebote cuando toque el borde, y puedes hacer clic en la bandera verde para ver el efecto.

    .. image:: img/17_ball3.png

* Cuando el sprite **Bola** toca el sprite **Paleta**, realiza un reflejo. La forma fácil de hacer esto es dejar que el ángulo se invierta directamente, pero entonces encontrarás que la trayectoria de la bola es completamente fija, lo cual es demasiado aburrido. Por lo tanto, usamos el centro de los dos sprites para calcular y hacer que la bola rebote en la dirección opuesta al centro del baffle.

    .. image:: img/17_ball4.png

    .. image:: img/17_ball6.png

* Cuando el sprite **Bola** cae al borde del escenario, el script deja de ejecutarse y el juego termina.

    .. image:: img/17_ball5.png

**3. Sprite del Bloque1**

El sprite **Bloque1** aparece con el efecto de clonarse a sí mismo 4x8 veces sobre el escenario en un color aleatorio, y eliminar un clon si es tocado por el sprite **Bola**.

El sprite **Bloque1** no está disponible en la biblioteca **PictoBlox**, necesitas dibujarlo tú mismo o modificarlo con un sprite existente. Aquí vamos a modificarlo con el sprite **Botón3**.

* Después de añadir el sprite **Botón3**, ve a la página de **Disfraces**. Ahora elimina primero **botón-a**, luego reduce tanto el ancho como el alto de **botón-b**, y cambia el nombre del sprite a **Bloque1**, como se muestra en la siguiente imagen.

    .. note::

        * Para el ancho de **Bloque1**, puedes simularlo en la pantalla para ver si puedes colocar 8 en fila, si no, entonces reduce el ancho apropiadamente.
        * En el proceso de reducir el sprite **Bloque1**, necesitas mantener el punto central en el medio del sprite.

    .. image:: img/17_bri2.png

* Ahora crea primero 2 variables, **bloque** para almacenar el número de bloques y **fila** para almacenar el número de filas.

    .. image:: img/17_bri3.png

* Necesitamos hacer un clon del sprite **Bloque1** para que se muestre de izquierda a derecha, de arriba abajo, uno por uno, en total 4x8, con colores aleatorios.

    .. image:: img/17_bri4.png

* Después de escribir el script, haz clic en la bandera verde y observa la presentación en el escenario, si es demasiado compacta o pequeña, puedes cambiar el tamaño.

    .. image:: img/17_bri5.png

* Ahora escribe el evento desencadenante. Si el clon del sprite **Bloque1** toca el sprite **Bola**, elimina el clon y emite el mensaje **crush**.

    .. image:: img/17_bri6.png

* Vuelve al sprite **Bola**, cuando se recibe la emisión **crush** (el sprite **Bola** toca el clon del sprite **Bloque1**), la **Bola** es expulsada en la dirección opuesta.

    .. image:: img/17_ball7.png
