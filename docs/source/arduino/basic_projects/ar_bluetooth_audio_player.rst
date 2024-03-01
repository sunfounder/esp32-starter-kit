
.. _bluetooth_audio_player:

7.3 Reproductor de Audio Bluetooth
=========================================

El objetivo del proyecto es proporcionar una solución simple para reproducir audio desde un dispositivo habilitado para Bluetooth usando el DAC interno del ESP32.

El proyecto involucra el uso de la biblioteca ``ESP32-A2DP`` para recibir datos de audio desde un dispositivo habilitado para Bluetooth. Los datos de audio recibidos se transmiten al DAC interno del ESP32 usando la interfaz I2S. La interfaz I2S está configurada para operar en modo maestro, modo de transmisión y modo DAC integrado. Los datos de audio se reproducen luego a través del altavoz conectado al DAC.

Al usar el DAC interno del ESP32, es importante tener en cuenta que el nivel de voltaje de salida está limitado a 1.1V. Por lo tanto, se recomienda usar un amplificador externo para aumentar el nivel de voltaje de salida al nivel deseado. También es importante asegurar que los datos de audio estén en el formato y la tasa de muestreo correctos para evitar distorsiones o ruidos durante la reproducción.

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
    *   - :ref:`cpn_audio_speaker`
        - \-


**Pasos Operativos**

#. Construye el circuito.

    Como este es un amplificador mono, puedes conectar IO25 al pin L o R del módulo amplificador de audio.

    La resistencia de 10K se utiliza para reducir el ruido de alta frecuencia y bajar el volumen del audio. Forma un filtro pasabajos RC con la capacitancia parásita del DAC y el amplificador de audio. Este filtro disminuye la amplitud de las señales de alta frecuencia, reduciendo efectivamente el ruido de alta frecuencia. Por lo tanto, agregar la resistencia de 10K hace que la música suene más suave y elimina el ruido de alta frecuencia no deseado.

    Si la música de tu tarjeta SD ya es suave, puedes quitar o reemplazar la resistencia con un valor más pequeño.

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. Abre el código.

    * Abre el archivo ``7.3_bluetooth_audio_player.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\7.3_bluetooth_audio_player``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * Aquí se utiliza la biblioteca ``ESP32-A2DP``, consulta :ref:`install_lib_man` para obtener un tutorial para instalar.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/7bb7d6dd-72d4-4529-bb42-033b38558347/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. Después de seleccionar la placa y el puerto correctos, haz clic en el botón Subir.

#. Una vez que el código se haya subido con éxito, enciende el dispositivo habilitado para Bluetooth y busca dispositivos disponibles, luego conéctate al ``ESP32_Bluetooth``.

    .. image:: img/connect_bluetooth.png

#. Reproduce audio en el dispositivo y el audio debería reproducirse a través del altavoz conectado al ESP32.


**Explicación del Código**

#. El código comienza incluyendo la biblioteca ``BluetoothA2DPSink.h``, que se utiliza para recibir datos de audio desde el dispositivo habilitado para Bluetooth. Luego se crea y configura el objeto ``BluetoothA2DPSink`` con los ajustes de la interfaz I2S. 

    .. code-block:: arduino

        #include "BluetoothA2DPSink.h"

        BluetoothA2DPSink a2dp_sink;


#. En la función setup, el código inicializa una estructura ``i2s_config_t`` con la configuración deseada para la interfaz I2S (Inter-IC Sound). 

    .. code-block:: arduino

        void setup() {
        const i2s_config_t i2s_config = {
            .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
            .sample_rate = 44100, // corrected by info from bluetooth
            .bits_per_sample = (i2s_bits_per_sample_t) 16, // the DAC module will only take the 8bits from MSB
            .channel_format =  I2S_CHANNEL_FMT_RIGHT_LEFT,
            .communication_format = (i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
            .intr_alloc_flags = 0, // default interrupt priority
            .dma_buf_count = 8,
            .dma_buf_len = 64,
            .use_apll = false
        };

        a2dp_sink.set_i2s_config(i2s_config);  
        a2dp_sink.start("ESP32_Bluetooth");  

        }

    * La interfaz I2S se utiliza para transferir datos de audio digital entre dispositivos. 
    * La configuración incluye el ``modo I2S``, ``tasa de muestreo``, ``bits por muestra``, ``formato de canal``, ``formato de comunicación``, ``flags de asignación de interrupción``, ``conteo de buffer DMA``, ``longitud del buffer DMA`` y si usar o no el APLL (Audio PLL).
    * La estructura ``i2s_config_t`` se pasa luego como argumento a la función ``set_i2s_config`` del objeto ``BluetoothA2DPSink`` para configurar la interfaz I2S para la reproducción de audio.
    * La función ``start`` del objeto ``BluetoothA2DPSink`` se llama para iniciar el receptor de audio Bluetooth y comenzar a reproducir audio a través del DAC integrado.
