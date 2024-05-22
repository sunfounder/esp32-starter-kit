.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_light_alarm:

2.7 Reloj Despertador Luminoso
===================================

En la vida, existen varios tipos de relojes despertadores. Ahora, vamos a crear un reloj despertador controlado por la luz. Cuando llega la mañana, la intensidad de la luz aumenta y este reloj despertador controlado por la luz te recordará que es hora de levantarte.

.. image:: img/10_clock.png

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Lo Que Aprenderás
---------------------

- Principio de funcionamiento de la fotorresistencia
- Cómo detener la reproducción de sonido y la ejecución de scripts

Construye el Circuito
-----------------------

Una fotorresistencia o célula fotoeléctrica es una resistencia variable controlada por la luz. La resistencia de una fotorresistencia disminuye con el aumento de la intensidad de luz incidente.

Construye el circuito según el siguiente diagrama.

Conecta un extremo de la fotorresistencia a 5V, el otro extremo al pin35, y conecta una resistencia de 10K en serie con GND en este extremo.

Así que cuando la intensidad de la luz aumenta, la resistencia de la fotorresistencia disminuye, la división de voltaje de la resistencia de 10K aumenta, y el valor obtenido por el pin35 se hace mayor.

.. image:: img/circuit/8_light_alarm_bb.png

Programación
------------------

**1. Selecciona un sprite**

Elimina el sprite predeterminado, haz clic en el botón **Elegir un Sprite** en la esquina inferior derecha del área de sprites, introduce **campana** en la caja de búsqueda y luego haz clic para añadirlo.

.. image:: img/10_sprite.png

**2. Lee el valor del pin35**

Crea dos variables **anterior** y **actual**. Al hacer clic en la bandera verde, lee el valor del pin35 y almacénalo en la variable **anterior** como valor de referencia. En [siempre], lee nuevamente el valor del pin35, almacénalo en la variable **actual**.

.. image:: img/10_reada0.png

**3. Haz un sonido**

Cuando el valor del pin35 actual es mayor que el anterior en 50, lo que representa que la intensidad de la luz actual es mayor que el umbral, entonces haz que el sprite emita un sonido.

.. image:: img/10_sound.png

**4. Girando el sprite**

Usa [bloque de giro] para hacer que el sprite **campana** gire hacia la izquierda y hacia la derecha para lograr el efecto de alarma.

.. image:: img/10_turn.png

**5. detener todo**

Detiene la alarma después de que ha estado sonando por un tiempo.

.. image:: img/10_stop.png

