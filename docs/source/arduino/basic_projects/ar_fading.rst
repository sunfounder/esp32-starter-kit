.. _ar_fading:

2.2 Desvanecimiento
========================

En el proyecto anterior, controlamos el LED encendiéndolo y apagándolo usando salida digital. En este proyecto, crearemos un efecto de respiración en el LED utilizando Modulación por Ancho de Pulso (PWM). PWM es una técnica que nos permite controlar el brillo de un LED o la velocidad de un motor variando el ciclo de trabajo de una señal de onda cuadrada.

Con PWM, en lugar de simplemente encender o apagar el LED, estaremos ajustando la cantidad de tiempo que el LED está encendido versus la cantidad de tiempo que está apagado dentro de cada ciclo. Al cambiar rápidamente el LED de encendido a apagado en intervalos variables, podemos crear la ilusión de que el LED se ilumina y se atenúa gradualmente, simulando un efecto de respiración.

Usando las capacidades de PWM del ESP32 WROOM 32E, podemos lograr un control suave y preciso sobre el brillo del LED. Este efecto de respiración añade un elemento dinámico y visualmente atractivo a tus proyectos, creando una exhibición llamativa o un ambiente.

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**Pines Disponibles**

Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_2.1_led.png

Este proyecto es el mismo circuito que el primer proyecto :ref:`ar_blink`, pero el tipo de señal es diferente. El primer proyecto es para emitir niveles altos y bajos digitales (0&1) directamente desde el pin26 para hacer que el LED se ilumine o se apague, este proyecto es para emitir señal PWM desde el pin26 para controlar el brillo del LED.



**Cableado**

.. image:: ../../img/wiring/2.1_hello_led_bb.png


**Código**

.. note::

    * Puedes abrir el archivo ``2.2_fading_led.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\2.2_fading_led``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/aa898b09-be86-473b-9bfe-317556c696bb/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de que el código se haya subido con éxito, puedes ver el LED respirando.

**¿Cómo funciona?**


#. Define constantes y variables。

    .. code-block:: arduino

        const int ledPin = 26; // The GPIO pin for the LED
        int brightness = 0;
        int fadeAmount = 5;
   
    * ``ledPin``: El número de pin GPIO donde está conectado el LED (en este caso, GPIO 26).
    * ``brightness``: El nivel actual de brillo del LED (inicialmente establecido en 0).
    * ``fadeAmount``: La cantidad por la cual el brillo del LED cambiará en cada paso (establecido en 5).

#. Inicializa el canal PWM y configura el pin del LED.

    .. code-block:: arduino

        void setup() {
            ledcSetup(0, 5000, 8); // Configure the PWM channel (0) with 5000Hz frequency and 8-bit resolution
            ledcAttachPin(ledPin, 0); // Attach the LED pin to the PWM channel
        }

    Aquí usamos el periférico |link_ledc| (control LED) que está diseñado principalmente para controlar la intensidad de los LEDs, aunque también se puede usar para generar señales PWM para otros fines.

    * ``uint32_t ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);``: Esta función se utiliza para configurar la frecuencia y resolución del canal LEDC. Devolverá la ``frecuencia`` configurada para el canal LEDC. Si se devuelve 0, ocurre un error y el canal ledc no fue configurado.
            
        * ``channel`` selecciona el canal LEDC para configurar.
        * ``freq`` selecciona la frecuencia del pwm.
        * ``resolution_bits`` selecciona la resolución para el canal ledc. El rango es de 1-14 bits (1-20 bits para ESP32).


    * ``void ledcAttachPin(uint8_t pin, uint8_t chan);``: Esta función se utiliza para asociar el pin al canal LEDC.

        * ``pin`` selecciona el pin GPIO.
        * ``chan`` selecciona el canal LEDC.

#. La función ``loop()`` contiene la lógica principal del programa y se ejecuta continuamente. Actualiza el brillo del LED, invierte la cantidad de desvanecimiento cuando el brillo alcanza el valor mínimo o máximo, e introduce un retraso.

    .. code-block:: arduino

        void loop() {
            ledcWrite(0, brightness); // Write the new brightness value to the PWM channel
            brightness = brightness + fadeAmount;

            if (brightness <= 0 || brightness >= 255) {
                fadeAmount = -fadeAmount;
            }
            
            delay(50); // Wait for 20 milliseconds
            }

    * ``void ledcWrite(uint8_t chan, uint32_t duty);``: Esta función se utiliza para establecer el deber para el canal LEDC.
        
        * ``chan`` selecciona el canal LEDC para escribir el deber.
        * ``duty`` selecciona el deber a ser establecido para el canal seleccionado.
