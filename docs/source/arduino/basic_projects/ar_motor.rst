.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_motor:

4.1 Motor
===========================

En este proyecto atractivo, exploraremos cómo manejar un motor usando el L293D.

El L293D es un circuito integrado (CI) versátil comúnmente utilizado para el control de motores en proyectos de electrónica y robótica. Puede manejar dos motores en direcciones hacia adelante y hacia atrás, lo que lo hace una opción popular para aplicaciones que requieren un control preciso del motor.

Al finalizar este proyecto fascinante, habrás adquirido un conocimiento profundo de cómo las señales digitales y las señales PWM pueden ser utilizadas efectivamente para controlar motores. Este valioso conocimiento será una base sólida para tus futuros empeños en robótica y mecatrónica. ¡Prepárate para sumergirte en el emocionante mundo del control de motores con el L293D!

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

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

    *   - INTRODUCCIÓN DE COMPONENTES
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_l293d`
        - \-

**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


    
**Cableado**

.. note:: 

  Dado que el motor requiere una corriente relativamente alta, es necesario primero insertar el Power Pack y luego deslizar el interruptor en la placa de expansión a la posición ON para activar el suministro de energía. 

.. image:: ../../img/wiring/4.1_motor_l293d_bb.png



**Código**

.. note::

    * Abre el archivo ``4.1_motor.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\4.1_motor``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
  <iframe src=https://create.arduino.cc/editor/sunfounder01/13364fc5-5094-4a84-90ce-07a5f85556dc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



Una vez que el código se haya cargado con éxito, observarás el motor girando en el sentido de las agujas del reloj durante un segundo, luego en sentido contrario durante un segundo, seguido por una pausa de dos segundos. Esta secuencia de acciones continuará en un bucle sin fin.


**Aprende Más**

Además de simplemente hacer girar el motor en el sentido de las agujas del reloj y en sentido contrario, también puedes controlar la velocidad de rotación del motor utilizando la modulación por ancho de pulso (PWM) en el pin de control, como se muestra a continuación.

.. note::

    * Abre el archivo ``4.1_motor_pwm.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\4.1_motor_pwm``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/32c262fd-9975-4137-9973-8b62d7240fee/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


El código anterior establece directamente los dos pines del motor a niveles de alto o bajo voltaje para controlar la rotación y la detención del motor.

Aquí usamos el |link_ledc| (control de LED) periférico para generar señales PWM para controlar la velocidad del motor. A través de dos bucles ``for``, el ciclo de trabajo del canal A se aumenta o disminuye de 0 a 255 mientras se mantiene el canal B en 0.

De esta manera, puedes observar cómo el motor aumenta gradualmente su velocidad a 255, luego disminuye a 0, repitiéndose infinitamente de esta manera.

Si deseas que el motor gire en la dirección opuesta, simplemente intercambia los valores de los canales A y B.
