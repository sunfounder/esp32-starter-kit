.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_take_photo_sd:

7.6 Tomar foto y guardar en SD
================================

Este documento describe un proyecto que implica tomar una foto usando la ESP32-CAM y guardarla en una tarjeta SD.
El objetivo del proyecto es proporcionar una solución simple para capturar imágenes con la ESP32-CAM y almacenarlas en una tarjeta SD.

**Componentes necesarios**

Para este proyecto, necesitaremos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - Kit de inicio ESP32
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
        - |link_esp32_extension_board|


**Precauciones relacionadas**

Al usar la ESP32-CAM, es importante notar que el pin GPIO 0 debe estar conectado a GND para subir un sketch.
Además, después de conectar GPIO 0 a GND, se debe presionar el botón de RESET en la ESP32-CAM para poner la placa en modo de carga.
También es importante asegurarse de que la tarjeta SD esté correctamente montada antes de guardar imágenes en ella.

**Pasos operativos**

#. Inserta tu tarjeta SD en la computadora usando un lector de tarjetas y luego formátela. Puedes referirte al tutorial en :ref:`format_sd_card`.

#. Luego, retira el lector de tarjetas e inserta la tarjeta SD en la placa de expansión.

    .. image:: ../../img/insert_sd.png

#. Ahora, conecta la cámara.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>

#. Conecta el ESP32-WROOM-32E a la computadora usando el cable USB.

    .. image:: ../../img/plugin_esp32.png

#. Abre el código.

    .. note::

        * Abre el archivo ``7.6_take_photo_sd.ino`` en la ruta ``esp32-starter-kit-main\c\codes\7.6_take_photo_sd``.
        * Después de seleccionar la placa (ESP32 Dev Module) y el puerto adecuado, haz clic en el botón **Subir**.
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4d698dc3-aef7-4aea-b8a3-7d143a4c7d3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Ahora, habilita **PSRAM**.

    .. image:: img/sp230516_150554.png

#. Establece el esquema de partición a **Gran APP (3MB Sin OTA/1MB SPIFFS)**.

    .. image:: img/sp230516_150840.png   

#. Selecciona el puerto y la placa apropiados en el IDE de Arduino y sube el código a tu ESP32.

#. Después de la carga exitosa del código, presiona el botón **Reset** para tomar una foto. Además, puedes verificar el Monitor Serial para ver la siguiente información indicando la captura exitosa.

    .. code-block:: arduino

        Picture file name: /picture9.jpg
        Saved file to path: /picture9.jpg
        Going to sleep now

    .. image:: img/press_reset.png

#. Ahora, retira la tarjeta SD de la placa de expansión e insértala en tu computadora. Podrás ver las fotos que acabas de tomar.

    .. image:: img/take_photo1.png

**¿Cómo funciona?**

Este código controla una cámara AI Thinker ESP32-CAM para tomar una foto, guardarla en una tarjeta SD y luego poner la ESP32-CAM en modo de sueño profundo. Aquí se detallan las partes clave:

* **Bibliotecas**: El código inicia con la inclusión de las bibliotecas necesarias para la ESP32-CAM, sistema de archivos (FS), tarjeta SD y EEPROM (usada para almacenar datos entre ciclos de energía).

    .. code-block:: arduino

        #include "esp_camera.h"
        #include "Arduino.h"
        #include "FS.h"                // SD Card ESP32
        #include "SD_MMC.h"            // SD Card ESP32
        #include "soc/soc.h"           // Disable brownour problems
        #include "soc/rtc_cntl_reg.h"  // Disable brownour problems
        #include "driver/rtc_io.h"
        #include <EEPROM.h>  // read and write from flash memory

* **Definiciones de Pines**: Esta sección configura constantes que representan las conexiones de pines de la ESP32-CAM al módulo de la cámara.

    .. code-block:: arduino

        #define PWDN_GPIO_NUM 32
        #define RESET_GPIO_NUM -1
        #define XCLK_GPIO_NUM 0
        #define SIOD_GPIO_NUM 26
        #define SIOC_GPIO_NUM 27

        #define Y9_GPIO_NUM 35
        #define Y8_GPIO_NUM 34
        #define Y7_GPIO_NUM 39
        #define Y6_GPIO_NUM 36
        #define Y5_GPIO_NUM 21
        #define Y4_GPIO_NUM 19
        #define Y3_GPIO_NUM 18
        #define Y2_GPIO_NUM 5
        #define VSYNC_GPIO_NUM 25
        #define HREF_GPIO_NUM 23
        #define PCLK_GPIO_NUM 22
    
* **Variables Globales**: Se declara una variable global ``pictureNumber`` para llevar el registro del número de fotos tomadas y guardadas en la tarjeta SD.

    .. code-block:: arduino

        int pictureNumber = 0;
    
* **Función de Configuración**: En la función ``setup()``, se realizan varias tareas:


    * Primero, se desactiva el detector de brown-out para prevenir que la ESP32-CAM se reinicie durante consumos altos de corriente (como cuando la cámara está operando).
    
        .. code-block:: arduino
        
            WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  //disable brownout detector

    * Se inicializa la comunicación Serial para depuración.

        .. code-block:: arduino

            Serial.begin(115200);
        
    * La configuración de la cámara se establece con ``camera_config_t``, incluyendo los pines GPIO, frecuencia XCLK, formato de píxel, tamaño de cuadro, calidad de jpeg y conteo de búfer de cuadros.
    
        .. code-block:: arduino

        camera_config_t config;
        config.ledc_channel = LEDC_CHANNEL_0;
        config.ledc_timer = LEDC_TIMER_0;
        config.pin_d0 = Y2_GPIO_NUM;
        config.pin_d1 = Y3_GPIO_NUM;
        config.pin_d2 = Y4_GPIO_NUM;
        config.pin_d3 = Y5_GPIO_NUM;
        config.pin_d4 = Y6_GPIO_NUM;
        config.pin_d5 = Y7_GPIO_NUM;
        config.pin_d6 = Y8_GPIO_NUM;
        config.pin_d7 = Y9_GPIO_NUM;
        config.pin_xclk = XCLK_GPIO_NUM;
        config.pin_pclk = PCLK_GPIO_NUM;
        config.pin_vsync = VSYNC_GPIO_NUM;
        config.pin_href = HREF_GPIO_NUM;
        config.pin_sscb_sda = SIOD_GPIO_NUM;
        config.pin_sscb_scl = SIOC_GPIO_NUM;
        config.pin_pwdn = PWDN_GPIO_NUM;
        config.pin_reset = RESET_GPIO_NUM;
        config.xclk_freq_hz = 20000000;
        config.pixel_format = PIXFORMAT_JPEG;
        
    * Luego, la cámara se inicializa con la configuración, y si falla, se imprime un mensaje de error.

        .. code-block:: arduino

            esp_err_t err = esp_camera_init(&config);
            if (err != ESP_OK) {
                Serial.printf("Camera init failed with error 0x%x", err);
                return;
            }
        
    * La tarjeta SD se inicializa y, si falla, se imprime un mensaje de error.

        .. code-block:: arduino

            if (!SD_MMC.begin()) {
               Serial.println("SD Card Mount Failed");
               return;
            }   

            uint8_t cardType = SD_MMC.cardType();
            if (cardType == CARD_NONE) {
                Serial.println("No SD Card attached");
                return;
            }
           
    * Se captura una foto con la cámara y se almacena en el búfer de cuadros.

        .. code-block:: arduino

            fb = esp_camera_fb_get();
            if (!fb) {
                Serial.println("Camera capture failed");
                return;
            }
        
    * Se lee el EEPROM para recuperar el número de la última foto, luego se incrementa el número de la foto para la nueva foto.

        .. code-block:: arduino

            EEPROM.begin(EEPROM_SIZE);
            pictureNumber = EEPROM.read(0) + 1;
        
    * Se crea una ruta para la nueva foto en la tarjeta SD, con un nombre de archivo correspondiente al número de la foto.

        .. code-block:: arduino

            String path = "/picture" + String(pictureNumber) + ".jpg";

            fs::FS &fs = SD_MMC;
            Serial.printf("Picture file name: %s\n", path.c_str());
        
    * Después de guardar la foto, el número de la foto se almacena de nuevo en el EEPROM para su recuperación en el próximo ciclo de energía.

        .. code-block:: arduino

            File file = fs.open(path.c_str(), FILE_WRITE);
            if (!file) {
                Serial.println("Failed to open file in writing mode");
            } else {
                file.write(fb->buf, fb->len);  // payload (image), payload length
                Serial.printf("Saved file to path: %s\n", path.c_str());
                EEPROM.write(0, pictureNumber);
                EEPROM.commit();
            }
            file.close();
            esp_camera_fb_return(fb);
        
    * Finalmente, se apaga el LED a bordo (flash) y la ESP32-CAM entra en sueño profundo.

        .. code-block:: arduino

            pinMode(4, OUTPUT);
            digitalWrite(4, LOW);
            rtc_gpio_hold_en(GPIO_NUM_4);
    
    * Modo de sueño profundo: La ESP32-CAM se pone en modo de sueño profundo para conservar energía. La duración del sueño se puede ajustar según sea necesario. En este ejemplo, no se especifica un tiempo de sueño, por lo que se espera un despertar externo.

        .. code-block:: arduino
        
            delay(2000);
            Serial.println("Going to sleep now");
            delay(2000);
            esp_deep_sleep_start();
            Serial.println("This will never be printed");


* Función Loop: La función ``loop()`` está vacía porque después del proceso de configuración, el ESP32-CAM entra inmediatamente en modo de sueño profundo.


Ten en cuenta que para que este código funcione, necesitas asegurarte de que el GPIO 0 esté conectado a GND al cargar el sketch, y puede que tengas que presionar el botón de RESET en la placa para poner tu placa en modo de carga. Además, recuerda reemplazar "/picture" con tu propio nombre de archivo. El tamaño de la EEPROM se establece en 1, lo que significa que puede almacenar valores de 0 a 255. Si planeas tomar más de 255 fotos, necesitarás aumentar el tamaño de la EEPROM y ajustar cómo almacenas y lees el número de la foto.