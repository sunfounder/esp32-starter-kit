.. _sh_shooting:

2.11 JUEGO - Disparos
====================================

¿Has visto esos juegos de disparos en la televisión? Cuanto más cerca un concursante dispare una bala al blanco cerca del centro, mayor será su puntuación.

Hoy también haremos un juego de disparos en Scratch. En el juego, permite que la Mira dispare lo más cerca posible al centro para obtener una puntuación más alta.

Haz clic en la bandera verde para empezar. Usa el módulo de Evitación de Obstáculos para disparar una bala.

.. image:: img/14_shooting.png

Componentes Necesarios
------------------------

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

Lo Que Aprenderás
---------------------

- Cómo funciona el módulo de Evitación de Obstáculos y el rango de ángulo
- Pintar diferentes sprites
- Tocar colores

Construye el Circuito
-----------------------

El módulo de evitación de obstáculos es un sensor de proximidad infrarrojo con distancia ajustable cuya salida es normalmente alta y baja cuando se detecta un obstáculo.

Ahora construye el circuito según el diagrama a continuación.

.. image:: img/circuit/12_shooting_bb.png

Programación
------------------

**1. Pintar el sprite de la Mira**

Elimina el sprite predeterminado, selecciona el botón **Sprite** y haz clic en **Pintar**, aparecerá un sprite en blanco **Sprite1** y nómbralo **Mira**.

.. image:: img/14_shooting0.png


Ve a la página **Disfraces** del sprite **Mira**. Haz clic en la herramienta **Círculo**, elimina el color de relleno y configura el color y el ancho del contorno.

.. image:: img/14_shooting02.png

Ahora dibuja un círculo con la herramienta **Círculo**. Después de dibujar, puedes hacer clic en la herramienta **Seleccionar** y mover el círculo para que el punto original se alinee con el centro del lienzo.

.. image:: img/14_shooting03.png

Usando la herramienta **Línea**, dibuja una cruz dentro del círculo.

.. image:: img/14_shooting033.png

**Pintar el sprite del Objetivo**

Crea un nuevo sprite llamado **Objetivo**.

.. image:: img/14_shooting01.png

Ve a la página de Disfraces del sprite **Objetivo**, haz clic en la herramienta **Círculo**, selecciona un color de relleno y elimina el Contorno y pinta un círculo grande.

.. image:: img/14_shooting05.png

Usa el mismo método para dibujar círculos adicionales, cada uno con un color diferente, y puedes usar la herramienta **Adelante** o **Atrás** para cambiar la posición de los círculos superpuestos. Ten en cuenta que también necesitas seleccionar la herramienta para mover los círculos, para que el origen de todos los círculos y el centro del lienzo estén alineados.

.. image:: img/14_shooting04.png

**3. Añadir un fondo**

Añade un fondo adecuado que preferiblemente no tenga demasiados colores y no coincida con los colores en el sprite **Objetivo**. Aquí he elegido el fondo **Pared1**.

.. image:: img/14_shooting06.png

**4. Programar el sprite de la Mira**

Establece la posición y el tamaño aleatorios del sprite **Mira**, y déjalo moverse aleatoriamente.

.. image:: img/14_shooting4.png

Cuando se coloca una mano frente al módulo de evitación de obstáculos, emitirá un nivel bajo como señal de transmisión.

.. image:: img/14_shooting5.png

Cuando se recibe el mensaje de **disparo**, el sprite deja de moverse y se encoge lentamente, simulando así el efecto de disparar una bala.

.. image:: img/14_shooting6.png

Usa el bloque [Tocar color ()] para determinar la posición del disparo.

.. image:: img/14_shooting7.png

Cuando el disparo está dentro del círculo amarillo, se informa 10.

.. image:: img/14_shooting8.png

Usa el mismo método para determinar la posición del disparo de la bala, si no se establece en el sprite **Objetivo**, significa que está fuera del círculo.

.. image:: img/14_shooting9.png
