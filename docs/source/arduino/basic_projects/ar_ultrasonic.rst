.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_ultrasonic:

5.12 Medición de Distancia
======================================
El módulo ultrasónico se utiliza para medir distancias o detectar objetos. En este proyecto, programaremos el módulo para obtener las distancias de los obstáculos. Enviando pulsos ultrasónicos y midiendo el tiempo que tardan en rebotar, podemos calcular distancias. Esto nos permite implementar acciones basadas en la distancia o comportamientos de evasión de obstáculos.

**Componentes Necesarios**

Para este proyecto necesitamos los siguientes componentes.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Para Entrada
            - IO13, IO14, IO27, IO26, IO25, IO33, IO32, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Para Salida
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Esquemático**

.. image:: ../../img/circuit/circuit_5.12_ultrasonic.png

El ESP32 envía un conjunto de señales de onda cuadrada al pin Trig del sensor ultrasónico cada 10 segundos. Esto induce al sensor ultrasónico a emitir una señal de ultrasonido de 40kHz hacia el exterior. Si hay un obstáculo enfrente, las ondas de ultrasonido serán reflejadas de vuelta.

Registrando el tiempo que tarda desde el envío hasta la recepción de la señal, dividiéndolo por 2 y multiplicándolo por la velocidad de la luz, puedes determinar la distancia al obstáculo.

**Conexión**

.. image:: ../../img/wiring/5.12_ultrasonic_bb.png

**Código**

.. note::

    * Abre el archivo ``5.12_ultrasonic.ino`` en la ruta ``esp32-starter-kit-main\c\codes\5.12_ultrasonic``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/28ded128-62a8-4b2b-b21a-450f03323cd8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Recuerda configurar la velocidad de comunicación serial a 115200.

Después de que el código se haya subido exitosamente, el monitor serie imprimirá la distancia entre el sensor ultrasónico y el obstáculo adelante.

**¿Cómo funciona?**

Acerca de la aplicación del sensor ultrasónico, podemos verificar directamente la subfunción.

.. code-block:: arduino

    float readSensorData(){// ...}

* El ``trigPin`` del módulo ultrasónico transmite una señal de onda cuadrada de 10us cada 2us.

    .. code-block:: arduino

        // Trigger a low signal before sending a high signal
        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2);
        // Send a 10-microsecond high signal to the trigPin
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10);
        // Return to low signal
        digitalWrite(trigPin, LOW);


* El ``echoPin`` recibe una señal de nivel alto si hay un obstáculo dentro del rango y usa la función ``pulseIn()`` para registrar el tiempo desde el envío hasta la recepción.

    .. code-block:: arduino

        unsigned long microsecond = pulseIn(echoPin, HIGH);

* La velocidad del sonido es 340 metros por segundo, lo que equivale a 29 microsegundos por centímetro. Midiendo el tiempo que tarda una onda cuadrada en viajar hacia un obstáculo y regresar, podemos calcular la distancia recorrida dividiendo el tiempo total por 2. Esto nos da la distancia del obstáculo desde la fuente de la onda sonora.

    .. code-block:: arduino

        float distance = microsecond / 29.00 / 2;  


Toma en cuenta que el sensor ultrasónico pausará el programa cuando esté trabajando, lo cual puede causar cierto retraso al escribir proyectos complejos.
