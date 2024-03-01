.. _ar_rgb:

2.3 Luz Colorida
==============================================

En este proyecto, nos adentraremos en el fascinante mundo de la mezcla de colores aditiva utilizando un LED RGB.

El LED RGB combina tres colores primarios, a saber, Rojo, Verde y Azul, en un solo paquete. Estos tres LEDs comparten un pin de cátodo común, mientras que cada pin de ánodo controla la intensidad del color correspondiente.

Variando la intensidad de la señal eléctrica aplicada a cada ánodo, podemos crear una amplia gama de colores. Por ejemplo, mezclar luz roja y verde de alta intensidad resultará en luz amarilla, mientras que combinar luz azul y verde producirá cian.

A través de este proyecto, exploraremos los principios de la mezcla de colores aditiva y desataremos nuestra creatividad manipulando el LED RGB para mostrar colores cautivadores y vibrantes.

**Componentes Requeridos**

En este proyecto, necesitamos los siguientes componentes.

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

También puedes comprarlos por separado en los siguientes enlaces.

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Pines Disponibles**

Aquí está la lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquema**

.. image:: ../../img/circuit/circuit_2.3_rgb.png

Los pines PWM pin27, pin26 y pin25 controlan los pines Rojo, Verde y Azul del LED RGB respectivamente, y conectan el pin de cátodo común a GND. Esto permite que el LED RGB muestre un color específico superponiendo luz en estos pines con diferentes valores PWM.


**Cableado**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

El LED RGB tiene 4 pines: el pin largo es el pin de cátodo común, que generalmente se conecta a GND; el pin izquierdo junto al pin más largo es Rojo; y los dos pines a la derecha son Verde y Azul.

.. image:: ../../img/wiring/2.3_color_light_bb.png


**Código**

Aquí, podemos elegir nuestro color favorito en software de dibujo (como paint) y mostrarlo con el LED RGB.

.. note::

    * Puedes abrir el archivo ``2.3_rgb_led.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\2.3_rgb_led``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto adecuado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/49a579a1-ae9b-4e23-b6cd-c20e5695191b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

.. image:: img/edit_colors.png

Escribe el valor RGB en ``color_set()``, podrás ver el LED RGB iluminar los colores que deseas.


**¿Cómo funciona?**

#. Define los pines GPIO, los canales PWM y la frecuencia (en Hz) y resolución (en bits).

    .. code-block:: arduino

            // Define RGB LED pins
            const int redPin = 27;
            const int greenPin = 26;
            const int bluePin = 25;

            // Define PWM channels
            const int redChannel = 0;
            const int greenChannel = 1;
            const int blueChannel = 2;

            // Define PWM frequency and resolution
            const int freq = 5000;
            const int resolution = 8;

2. La función ``setup()`` inicializa los canales PWM con la frecuencia y resolución especificadas, y luego asocia los pines del LED a sus respectivos canales PWM.

    .. code-block:: arduino

        void setup() {
            // Set up PWM channels
            ledcSetup(redChannel, freq, resolution);
            ledcSetup(greenChannel, freq, resolution);
            ledcSetup(blueChannel, freq, resolution);
            
            // Attach pins to corresponding PWM channels
            ledcAttachPin(redPin, redChannel);
            ledcAttachPin(greenPin, greenChannel);
            ledcAttachPin(bluePin, blueChannel);
        }

    Aquí utilizamos el periférico |link_ledc| (control de LED), diseñado primordialmente para controlar la intensidad de los LEDs, aunque también puede ser usado para generar señales PWM para otros propósitos.
    * ``uint32_t ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);``: Esta función se utiliza para configurar la frecuencia y resolución del canal LEDC. Devolverá la ``frecuencia`` configurada para el canal LEDC. Si se devuelve 0, se produce un error y el canal LEDC no fue configurado.
        
        * ``channel``: selecciona el canal LEDC a configurar.
        * ``freq``: selecciona la frecuencia del PWM.
        * ``resolution_bits``: selecciona la resolución para el canal LEDC. El rango es de 1-14 bits (1-20 bits para ESP32).

    * ``void ledcAttachPin(uint8_t pin, uint8_t chan);``: Esta función se utiliza para asociar el pin al canal LEDC.
    
        * ``pin``: selecciona el pin GPIO.
        * ``chan``: selecciona el canal LEDC.


3. La función ``loop()`` cicla a través de varios colores (rojo, verde, azul, amarillo, púrpura y cian) con intervalos de un segundo entre cada cambio de color.

    .. code-block:: arduino

            void loop() {
                setColor(255, 0, 0); // Red
                delay(1000);
                setColor(0, 255, 0); // Green
                delay(1000);
                setColor(0, 0, 255); // Blue
                delay(1000);
                setColor(255, 255, 0); // Yellow
                delay(1000);
                setColor(80, 0, 80); // Purple
                delay(1000);
                setColor(0, 255, 255); // Cyan
                delay(1000);
            }

4. La función ``setColor()`` establece el color deseado escribiendo los valores de ciclo de trabajo apropiados en cada canal PWM. La función toma tres argumentos enteros para los valores de color rojo, verde y azul.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // For common-anode RGB LEDs, use 255 minus the color value
            ledcWrite(redChannel, red);
            ledcWrite(greenChannel, green);
            ledcWrite(blueChannel, blue);
        }

    * ``void ledcWrite(uint8_t chan, uint32_t duty);``: Esta función se utiliza para establecer el ciclo de trabajo para el canal LEDC.
        
        * ``chan``: selecciona el canal LEDC para escribir el ciclo de trabajo.
        * ``duty``: selecciona el ciclo de trabajo a establecer para el canal seleccionado.