.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_mp3_player_sd:

7.5 Reproductor MP3 con Soporte de Tarjeta SD
==============================================

¡Bienvenido al emocionante mundo de la música con tu ESP32! Este proyecto lleva el poder del procesamiento de audio a tus manos, convirtiendo tu ESP32 no solo en un microcontrolador increíble para la computación, sino también en tu reproductor de música personalizado. Imagina entrar a tu habitación y tener tu pista favorita sonando directamente desde este pequeño dispositivo. Ese es el poder que estamos trayendo a tus manos hoy.

**Componentes Necesarios**

En este proyecto, necesitaremos los siguientes componentes.

Es definitivamente conveniente comprar todo el kit, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    * - Nombre
      - ARTÍCULOS EN ESTE KIT
      - ENLACE
    * - Kit de inicio ESP32
      - 320+
      - |link_esp32_starter_kit|

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    * - INTRODUCCIÓN DE COMPONENTES
      - ENLACE DE COMPRA

    * - :ref:`cpn_esp32_wroom_32e`
      - |link_esp32_wroom_32e_buy|
    * - :ref:`cpn_esp32_camera_extension`
      - |link_esp32_extension_board|
    * - :ref:`cpn_breadboard`
      - |link_breadboard_buy|
    * - :ref:`cpn_wires`
      - |link_wires_buy|
    * - :ref:`cpn_resistor`
      - |link_resistor_buy|
    * - :ref:`cpn_audio_speaker`
      - \-

**Pasos Operativos**

1. Inserta tu tarjeta SD en la computadora usando un lector de tarjetas, y luego formátela. Puedes referirte al tutorial en :ref:`format_sd_card`.

2. Copia tu archivo MP3 favorito a tu tarjeta SD.

    .. image:: img/mp3_music.png

3. Inserta la tarjeta SD en la ranura para tarjetas SD de la placa de expansión.

    .. image:: ../../img/insert_sd.png

4. Construye el circuito.

    Como esto es un amplificador mono, puedes conectar IO25 al pin L o R del módulo de amplificador de audio.

    La resistencia de 10K se utiliza para reducir el ruido de alta frecuencia y bajar el volumen del audio. Forma un filtro pasa bajos RC con la capacitancia parasitaria del DAC y el amplificador de audio. Este filtro disminuye la amplitud de las señales de alta frecuencia, reduciendo efectivamente el ruido de alta frecuencia. Por lo tanto, agregar la resistencia de 10K hace que la música suene más suave y elimina el ruido de alta frecuencia no deseado.

    Si la música de tu tarjeta SD ya es suave, puedes quitar o reemplazar la resistencia por un valor menor.

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

5. Conecta el ESP32-WROOM-32E a la computadora usando el cable USB.

    .. image:: ../../img/plugin_esp32.png

6. Modifica el código.

    Modifica la línea de código ``file = new AudioFileSourceSD_MMC("/To Alice.mp3")``; para reflejar el nombre y ruta de tu archivo.

    .. note::

        * Abre el archivo ``7.5_mp3_player_sd.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\7.5_mp3_player_sd``. O copia este código en **Arduino IDE**.
        * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
        * :ref:`unknown_com_port`
        * La biblioteca ``ESP8266Audio`` se utiliza aquí, consulta :ref:`install_lib_man` para un tutorial de instalación.

    .. warning::

        Si estás utilizando una placa de desarrollo ESP32 versión 3.0.0 o superior, puedes encontrar errores durante el proceso de compilación.
        Este problema se debe generalmente a que las versiones más recientes de la placa ya no son compatibles con la biblioteca ``ESP8266Audio``.
        Para ejecutar correctamente este ejemplo, se recomienda degradar la versión del firmware de tu placa ESP32 a la 2.0.17.
        Después de completar este ejemplo, actualiza nuevamente a la versión más reciente.

        .. image:: ../../faq/img/version_2.0.17.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/13f5c757-9622-4735-aa1a-fdbe6fc46273/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

7. Selecciona el puerto y la placa apropiados en el IDE de Arduino y sube el código a tu ESP32.

8. Después de subir exitosamente el código, escucharás tu música favorita sonando.


**¿Cómo funciona?**

* El código utiliza varias clases de la biblioteca ``ESP8266Audio`` para reproducir un archivo MP3 desde una tarjeta SD a través de I2S:

    .. code-block:: arduino

        #include "AudioFileSourceSD_MMC.h"
        #include "AudioOutputI2S.h"
        #include "AudioGeneratorMP3.h"
        #include "SD_MMC.h"
        #include "FS.h"

    * ``AudioGeneratorMP3`` es una clase que decodifica audio MP3.
    * ``AudioFileSourceSD_MMC`` es una clase que lee datos de audio desde una tarjeta SD.
    * ``AudioOutputI2S`` es una clase que envía datos de audio a la interfaz I2S.

* En la función ``setup()``, inicializamos la tarjeta SD, abrimos el archivo MP3 desde la tarjeta SD, configuramos la salida I2S en el DAC interno del ESP32, configuramos la salida a mono y comenzamos el generador MP3.

    .. code-block:: arduino

        void setup() {
            // Start the serial communication.
            Serial.begin(115200);
            delay(1000);

            // Initialize the SD card. If it fails, print an error message.
            if (!SD_MMC.begin()) {
                Serial.println("SD card mount failed!");
            }

            // Open the MP3 file from the SD card. Replace "/To Alice.mp3" with your own MP3 file name.
            file = new AudioFileSourceSD_MMC("/To Alice.mp3");
            
            // Set up the I2S output on ESP32's internal DAC.
            out = new AudioOutputI2S(0, 1);
            
            // Set the output to mono.
            out->SetOutputModeMono(true);

            // Initialize the MP3 generator with the file and output.
            mp3 = new AudioGeneratorMP3();
            mp3->begin(file, out);
        }


* En la función ``loop()``, verificamos si el generador MP3 está funcionando. Si es así, continuamos en bucle; de lo contrario, lo detenemos e imprimimos "MP3 terminado" en el monitor serial.

    .. code-block:: arduino

        void loop() {
            // If the MP3 is running, loop it. Otherwise, stop it.
            if (mp3->isRunning()) {
                if (!mp3->loop()) mp3->stop();
            } 
            // If the MP3 is not running, print a message and wait for 1 second.
            else {
                Serial.println("MP3 done");
                delay(1000);
            }
        }

