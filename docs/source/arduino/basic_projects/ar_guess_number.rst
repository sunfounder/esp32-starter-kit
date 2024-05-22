.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_guess_number:

6.7 Adivina el Número
===========================
¿Te sientes con suerte? ¿Quieres probar tu intuición y ver si puedes adivinar el número correcto? ¡Entonces no busques más allá del juego Adivina el Número!

Con este proyecto, puedes jugar un juego divertido y emocionante de azar.

Usando un control remoto IR, los jugadores ingresan números entre 0 y 99 para intentar adivinar el número de punto de suerte generado aleatoriamente.
El sistema muestra el número de entrada del jugador en una pantalla LCD, junto con consejos de límite superior e inferior para ayudar a guiar al
jugador hacia la respuesta correcta. Con cada adivinanza, los jugadores se acercan al número de punto de suerte,
hasta que finalmente, alguien acierta y gana el juego.

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
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Esquemático**

.. image:: ../../img/circuit/circuit_6.7_guess_number.png

**Cableado**

.. image:: ../../img/wiring/6.7_guess_receiver_bb.png
    :width: 800

**Código**

.. note::

    * Puedes abrir el archivo ``6.7_guess_number.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\6.7_guess_number`` directamente.
    * Las bibliotecas ``LiquidCrystal_I2C`` y ``IRremoteESP8266`` se utilizan aquí, consulta :ref:`install_lib_man` para obtener un tutorial de instalación.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e4217f5-c1b7-4859-a34d-d791bbc5e57a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

* Después de que el código se haya cargado con éxito, presiona cualquier botón numérico en el control remoto para iniciar el juego.
* Ingresa un número usando los botones numéricos en el control remoto. Para ingresar un solo dígito, necesitas presionar la tecla **ciclo** para confirmar.
* El sistema mostrará el número de entrada y los consejos de límite superior e inferior en la pantalla LCD.
* Sigue adivinando hasta que adivines correctamente el número de punto de suerte.
* Después de una adivinanza exitosa, el sistema mostrará un mensaje de éxito y generará un nuevo número de punto de suerte.

.. note:: 

    Si el código y el cableado son correctos, pero la LCD aún no muestra ningún contenido, puedes ajustar el potenciómetro en la parte posterior para aumentar el contraste.


**¿Cómo funciona?**

#. En la función ``setup()``, la pantalla LCD I2C y el receptor IR se inicializan. Luego llama a la función ``initNewValue()`` para generar un nuevo número de suerte aleatorio, y se muestra un mensaje de bienvenida en la pantalla LCD.

    .. code-block:: arduino

        void setup() {
            // Initialize the LCD screen
            lcd.init();
            lcd.backlight();

            // Start the serial communication
            Serial.begin(9600);

            // Enable the IR receiver
            irrecv.enableIRIn();

            // Initialize a new lucky point value
            initNewValue();
        }

#. En la función ``loop``, el código espera una señal del receptor IR. Cuando se recibe una señal, la función ``decodeKeyValue`` se llama para decodificar la señal y obtener el valor del botón correspondiente.

    .. code-block:: arduino

        void loop() {
        // If a signal is received from the IR receiver
        if (irrecv.decode(&results)) {
            bool result = 0;
            String num = decodeKeyValue(results.value);

            // If the POWER button is pressed
            if (num == "POWER") {
                initNewValue(); // Initialize a new lucky point value
            }

            // If the CYCLE button is pressed
            else if (num == "CYCLE") {
                result = detectPoint(); // Detect the input number
                lcdShowInput(result); // Show the result on the LCD screen
            }

            // If a number button (0-9) is pressed, 
            //add the digit to the input number 
            //and detect the number if it is greater than or equal to 10
            else if (num >= "0" && num <= "9") {
                count = count * 10;
                count += num.toInt();
                if (count >= 10) {
                    result = detectPoint();
                }
                lcdShowInput(result);
            }
            irrecv.resume();
        }
        }

    * Dependiendo del valor del botón, se llama a la función apropiada. Si se presiona un botón numérico, la variable ``count`` se actualiza, y la función ``detectPoint`` se llama para detectar si el número de entrada es correcto. La función ``lcdShowInput`` se llama para mostrar el número de entrada y los consejos de límite superior e inferior en la pantalla LCD.
    * Si se presiona el botón ``POWER``, la función ``initNewValue`` se llama para generar un nuevo número de punto de suerte y mostrar el mensaje de bienvenida en la pantalla LCD.
    * Si se presiona el botón ``CYCLE``, la función ``detectPoint`` se llama para detectar si el número de entrada es correcto. La función ``lcdShowInput`` se llama para mostrar el número de entrada y los consejos de límite superior e inferior en la pantalla LCD.
