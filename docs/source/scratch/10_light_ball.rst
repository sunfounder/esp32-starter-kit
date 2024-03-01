.. _sh_light_ball:

2.10 Bola Sensible a la Luz
==============================

En este proyecto, usaremos una fotorresistencia para hacer que la bola en el escenario vuele hacia arriba. Coloca tu mano sobre la fotorresistencia para controlar la intensidad de luz que recibe. Cuanto más cerca esté tu mano de la fotorresistencia, menor será su valor y más alto volará la bola en el escenario, de lo contrario caerá. Cuando la bola toca la cuerda, produce un sonido agradable así como un parpadeo de estrellas.

.. image:: img/18_ball.png

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Lo Que Aprenderás
---------------------

- Rellenar el sprite con colores
- Toque entre los sprites

Construye el Circuito
-----------------------

Una fotorresistencia o célula fotoeléctrica es una resistencia variable controlada por la luz. La resistencia de una fotorresistencia disminuye con el aumento de la intensidad de luz incidente.

Construye el circuito según el siguiente diagrama.

Conecta un extremo de la fotorresistencia a 5V, el otro extremo al pin35, y conecta una resistencia de 10K en serie con GND en este extremo.

Así que cuando la intensidad de la luz aumenta, la resistencia de la fotorresistencia disminuye, la división de voltaje de la resistencia de 10K aumenta, y el valor obtenido por el pin35 se hace mayor.

.. image:: img/circuit/8_light_alarm_bb.png

Programación
------------------

El efecto que queremos obtener es que cuanto más cerca esté tu mano de la fotorresistencia, el sprite de la bola en el escenario sigue subiendo, de lo contrario caerá sobre el sprite del tazón. Si toca el sprite de la Línea mientras sube o cae, emitirá un sonido musical y lanzará sprites de estrella en todas direcciones.


**1. Seleccionar sprite y fondo**

Elimina el sprite predeterminado, selecciona los sprites **Bola**, **Tazón** y **Estrella**.

.. image:: img/18_ball1.png


Mueve el sprite **Tazón** al centro inferior del escenario y aumenta su tamaño.

.. image:: img/18_ball3.png

Como necesitamos moverlo hacia arriba, establece la dirección del sprite **Bola** a 0.

.. image:: img/18_ball4.png

Establece el tamaño y la dirección del sprite **Estrella** a 180 porque necesitamos que caiga, o puedes cambiarlo a otro ángulo.

.. image:: img/18_ball12.png

Ahora añade el fondo **Estrellas**.

.. image:: img/18_ball2.png

**2. Dibujar un sprite de Línea**

Añade un sprite de Línea.

.. image:: img/18_ball7.png

Ve a la página **Disfraces** del sprite **Línea**, reduce ligeramente el ancho de la línea roja en el lienzo, luego cópiala 5 veces y alinea las líneas.

.. image:: img/18_ball8.png

Ahora rellena las líneas con diferentes colores. Primero elige un color que te guste, luego haz clic en la herramienta **Rellenar** y mueve el ratón sobre la línea para llenarla de color.

.. image:: img/18_ball9.png

Sigue el mismo método para cambiar el color de las otras líneas.

.. image:: img/18_ball10.png


**3. Programación del sprite Bola**

Establece la posición inicial del sprite **Bola**, luego cuando el valor de luz sea menor a 1500 (puede ser cualquier otro valor, dependiendo de tu ambiente actual.), deja que la Bola se mueva hacia arriba.

Puedes hacer que la variable valor_luz se muestre en el escenario para observar el cambio de intensidad de luz en cualquier momento.

.. image:: img/18_ball5.png

De lo contrario, el sprite **Bola** caerá y limitará su coordenada Y a un mínimo de -100. Esto se puede modificar para que parezca que está cayendo sobre el sprite **Tazón**.

.. image:: img/18_ball6.png

Cuando el sprite **Línea** sea golpeado, la coordenada Y actual se guarda en la variable **coord_bola** y se difunde el mensaje **Bling**.

.. image:: img/18_ball11.png

**4. Programación del sprite Estrella**

Cuando el script comienza, primero oculta el sprite **Estrella**. Cuando se recibe el mensaje **Bling**, clona el sprite **Estrella**.

.. image:: img/18_ball13.png

Cuando el sprite **Estrella** aparece como un clon, reproduce el efecto de sonido y establece sus coordenadas para que estén sincronizadas con el sprite **Bola**.

.. image:: img/18_ball14.png

Crea el efecto de aparición del sprite **Estrella** y ajústalo según sea necesario.

.. image:: img/18_ball15.png
