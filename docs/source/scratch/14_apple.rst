.. _sh_eat_apple:

2.14 JUEGO - Comer Manzana
==============================

En este proyecto, jugaremos un juego que utiliza un botón para controlar a un Escarabajo para que coma manzanas.

Al hacer clic en la bandera verde, presiona el botón y el Escarabajo girará, presiona el botón nuevamente y el Escarabajo se detiene y avanza en ese ángulo. Necesitas controlar el ángulo del Escarabajo para que avance sin tocar la línea negra en el mapa hasta que coma la manzana. Si toca la línea negra, el juego termina.

.. image:: img/14_apple.png

Componentes Necesarios
--------------------------

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
El efecto que queremos lograr es usar el botón para controlar la dirección del sprite **Escarabajo** para moverse hacia adelante y comer la manzana sin tocar la línea negra en el fondo **Laberinto**, lo cual cambiará el fondo al ser comido.

Ahora añade los fondos y sprites relevantes.

**1. Añadiendo fondos y sprites**

Añade un fondo **Laberinto** mediante el botón **Elegir un fondo**.

.. image:: img/14_backdrop.png

Elimina el sprite predeterminado, luego selecciona el sprite **Escarabajo**.

.. image:: img/14_sprite.png

Coloca el sprite **Escarabajo** en la entrada del fondo **Laberinto**, recordando los valores de coordenadas x,y en este punto, y redimensiona el sprite al 40%.

.. image:: img/14_sprite1.png

**2. Dibujar un fondo**

Ahora es el momento de dibujar simplemente un fondo con el personaje WIN! apareciendo en él.

Primero haz clic en la miniatura del fondo para ir a la página **Fondos** y haz clic en el fondo en blanco backdrop1.

.. image:: img/14_paint_back.png
    :width: 800

Ahora comienza a dibujar, puedes referirte a la imagen de abajo para dibujar, o también puedes crear tu propio fondo, siempre y cuando la expresión transmita victoria.

* Utilizando la herramienta **Círculo**, dibuja una elipse con el color establecido en rojo y sin contorno.
* Luego, con la herramienta **Texto**, escribe el carácter \"¡GANASTE!\", establece el color del carácter en negro y ajusta el tamaño y la posición del carácter.
* Nombra el fondo como **Ganar**.

.. image:: img/14_win.png

**3. Programación para el fondo**

El fondo debe cambiarse a **Laberinto** cada vez que comience el juego.

.. image:: img/14_switchback.png

**4. Escribir guiones para el sprite Escarabajo**

Ahora escribe un guion para el sprite **Escarabajo** para que pueda moverse hacia adelante y cambiar de dirección bajo el control de un botón. El flujo de trabajo es el siguiente.

* Al hacer clic en la bandera verde, establece el ángulo del **Escarabajo** a 90, y la posición a (-134, -134), o reemplázalo con el valor de coordenadas de tu propia posición colocada. Crea la variable **bandera** y establece el valor inicial en -1.

.. image:: img/14_bee1.png

A continuación, en el bloque [siempre], se utilizan cuatro bloques [si] para determinar varios escenarios posibles.

* Si el botón es 1 (presionado), usa el bloque [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] para alternar el valor de la variable **bandera** entre 0 y 1 (alternando entre 0 para esta presión y 1 para la próxima presión).

.. image:: img/14_bee2.png

* Si bandera=0 (esta presión de botón), permite que el sprite **Escarabajo** gire en sentido horario. Luego determina si bandera es igual a 1 (botón presionado de nuevo), el sprite **Escarabajo** se mueve hacia adelante. De lo contrario, sigue girando en sentido horario.

.. image:: img/14_bee3.png

* Si el sprite Escarabajo toca el negro (la línea negra en el fondo **Laberinto**), el juego termina y el guion deja de ejecutarse.

.. note::
    
    Necesitas hacer clic en el área de color en el bloque [Tocar color], y luego seleccionar la herramienta cuentagotas para recoger el color de la línea negra en el escenario. Si eliges un negro arbitrariamente, este bloque [Tocar color] no funcionará.


.. image:: img/14_bee5.png

* Si Escarabajo toca rojo (Usa también la herramienta de paja para recoger el color rojo de la manzana), el fondo se cambiará a **Ganar**, lo que significa que el juego tiene éxito y se detiene la ejecución del guion.


.. image:: img/14_bee4.png





