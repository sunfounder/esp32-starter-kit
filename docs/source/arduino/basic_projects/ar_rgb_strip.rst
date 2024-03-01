.. _ar_rgb_strip:

2.7 Tira de LEDs RGB
======================

En este proyecto, exploraremos el fascinante mundo de controlar tiras de LEDs WS2812 y daremos vida a una vibrante exhibición de colores. Con la capacidad de controlar individualmente cada LED en la tira, podemos crear efectos de iluminación cautivadores que deslumbrarán los sentidos.

Además, hemos incluido una extensión emocionante a este proyecto, donde exploraremos el reino de la aleatoriedad. Introduciendo colores aleatorios y implementando un efecto de luz fluida, podemos crear una experiencia visual hipnotizante que cautiva y encanta.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Esquema**

.. image:: ../../img/circuit/circuit_2.7_ws2812.png
    :width: 500
    :align: center


**Pines Disponibles**

Aquí está la lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


.. note::

    IO33 no está disponible para este proyecto.

    La tira LED WS2812 es un tipo de tira LED que requiere una señal de modulación de ancho de pulso (PWM) precisa. La señal PWM tiene requisitos precisos tanto en tiempo como en voltaje. Por ejemplo, un bit "0" para el WS2812 corresponde a un pulso de nivel alto de aproximadamente 0.4 microsegundos, mientras que un bit "1" corresponde a un pulso de nivel alto de aproximadamente 0.8 microsegundos. Esto significa que la tira necesita recibir cambios de voltaje de alta frecuencia.

    Sin embargo, con una resistencia de pull-up de 4.7K y un condensador de pull-down de 100nf en IO33, se crea un filtro de paso bajo simple. Este tipo de circuito "suaviza" las señales de alta frecuencia, porque el condensador necesita algo de tiempo para cargarse y descargarse cuando recibe cambios de voltaje. Por lo tanto, si la señal cambia demasiado rápido (es decir, es de alta frecuencia), el condensador no podrá seguir el ritmo. Esto resulta en que la señal de salida se vuelva borrosa y no reconocible para la tira.

**Cableado**

.. image:: ../../img/wiring/2.7_rgb_strip_bb.png
    :width: 800

**Código**

.. note::

    * Puedes abrir el archivo ``2.7_rgb_strip.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\2.7_rgb_strip``. O copiar este código en **Arduino IDE**.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto adecuado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * La biblioteca ``Adafruit NeoPixel`` se utiliza aquí, puedes instalarla desde el **Administrador de Bibliotecas**.

        .. image:: img/rgb_strip_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/bccd25f6-4e3e-45e2-b9f5-76a1b0866794/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Cuando el código se haya subido con éxito, los LEDs en la tira se encenderán secuencialmente con un color amarillo y luego se apagarán, creando un simple efecto de persecución.

**¿Cómo funciona?**

1. Incluye la biblioteca Adafruit NeoPixel: Esta línea importa la biblioteca Adafruit NeoPixel para que el boceto pueda usar sus funciones y clases para controlar la tira de LED.

    .. code-block:: arduino

        #include <Adafruit_NeoPixel.h> // Include the Adafruit NeoPixel library

2. Define constantes para la tira LED.

    .. code-block:: arduino

        #define LED_PIN 13 // NeoPixel LED strip
        #define NUM_LEDS 8 // Number of LEDs

3. Crea una instancia de la clase Adafruit_NeoPixel.

    .. code-block:: arduino

       // Create an instance of the Adafruit_NeoPixel class
        Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

    Esta línea crea una instancia de la clase ``Adafruit_NeoPixel`` llamada ``strip`` y la configura con el número de LEDs, el pin conectado a la tira de LED y los parámetros de señal (orden de color GRB y tasa de datos de 800 kHz).


    * ``Adafruit_NeoPixel (uint16_t n, int16_t p = 6, neoPixelType t = NEO_GRB + NEO_KHZ800)``	

    Constructor de NeoPixel cuando la longitud, el pin y el tipo de píxel se conocen en tiempo de compilación. Devuelve un objeto Adafruit_NeoPixel. Llamar a la función ``begin()`` antes de usar.

        * ``n``: Número de NeoPixels en la tira.
        * ``p``: Número de pin de Arduino que conducirá los datos de NeoPixel.
        * ``t``: Tipo de píxel - suma las constantes ``NEO_*`` definidas en ``Adafruit_NeoPixel.h``, por ejemplo, ``NEO_GRB+NEO_KHZ800`` para NeoPixels que esperan un flujo de datos de 800 KHz (vs 400 KHz) con bytes de color expresados en orden verde, rojo, azul por píxel.

4. Inicializa la tira RGB WS2812 y establece el color inicial de la tira en negro (apagado).

    .. code-block:: arduino

        void setup() {
            strip.begin(); // Initialize the NeoPixel strip
            strip.show(); // Set initial color to black
        }

    * ``void begin (void)``: Configura el pin de NeoPixel para salida.
    * ``void show (void)``: Transmite datos de píxeles en RAM a NeoPixels.

5. En la función ``loop()``, los LEDs en la tira se encenderán secuencialmente con un color amarillo y luego se apagarán, creando un simple efecto de persecución.

    .. code-block:: arduino

        void loop() {
        // Turn on LEDs one by one
        for (int i = 0; i < NUM_LEDS; i++) {
            strip.setPixelColor(i, 100, 45, 0); // Set the color of the i-th LED to red
            strip.show(); // Update the LED strip with the new colors
            delay(100); // Wait for 100 milliseconds
        }
        
        // Turn off LEDs one by one
        for (int i = 0; i < NUM_LEDS; i++) {
            strip.setPixelColor(i, 0, 0, 0); // Set the color of the i-th LED to black (turn it off)
            strip.show(); // Update the LED strip with the new colors
            delay(100); // Wait for 100 milliseconds
        }
        }

    * ``void setPixelColor (uint16_t n, uint8_t r, uint8_t g, uint8_t b)``

    Establece el color de un píxel usando componentes rojos, verdes y azules separados. Si se usan píxeles RGBW, el blanco se establecerá en 0.

        ``n``: Índice del píxel, comenzando desde 0.
        ``r``: Brillo rojo, 0 = mínimo (apagado), 255 = máximo.
        ``g``: Brillo verde, 0 = mínimo (apagado), 255 = máximo.
        ``b``: Brillo azul, 0 = mínimo (apagado), 255 = máximo.
