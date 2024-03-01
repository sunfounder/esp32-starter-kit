.. _ar_dht11:

5.13 Temperatura - Humedad
=======================================

El DHT11 es un sensor de temperatura y humedad comúnmente utilizado para mediciones ambientales. Es un sensor digital que se comunica con un microcontrolador para proporcionar lecturas de temperatura y humedad.

En este proyecto, estaremos leyendo el sensor DHT11 e imprimiendo los valores de temperatura y humedad que detecta.

Al leer los datos proporcionados por el sensor, podemos obtener los valores actuales de temperatura y humedad en el ambiente. Estos valores pueden usarse para el monitoreo en tiempo real de condiciones ambientales, observaciones meteorológicas, control del clima interior, informes de humedad y más.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí está una lista de los pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Pines Disponibles
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_5.13_dht11.png


**Cableado**

.. image:: ../../img/wiring/5.13_dht11_bb.png

**Código**

.. note::

    * Abre el archivo ``5.13_dht11.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.13_dht11``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * Se utiliza aquí la biblioteca ``DHT sensor library``, puedes instalarla desde el **Administrador de Bibliotecas**.

        .. image:: img/dht_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/95bef6dc-a4db-4315-9308-6663b77ddfa0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de que el código se haya subido con éxito, verás el Monitor Serial imprimiendo continuamente la temperatura y humedad, y a medida que el programa se ejecute de manera estable, estos dos valores se volverán más y más precisos.

**¿Cómo funciona?**

#.  Incluye la biblioteca ``DHT.h``, que proporciona funciones para interactuar con los sensores DHT. Luego, establece el pin y tipo para el sensor DHT.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 14  // Set the pin connected to the DHT11 data pin
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Inicializa la comunicación serial a una tasa de baudios de 115200 e inicializa el sensor DHT.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. En la función ``loop()``, lee los valores de temperatura y humedad del sensor DHT11 e imprímelos en el monitor serial.

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * La función ``dht.readHumidity()`` se llama para leer el valor de humedad del sensor DHT.
    * La función ``dht.readTemperature()`` se llama para leer el valor de temperatura del sensor DHT.
    * La función ``isnan()`` se usa para verificar si las lecturas son válidas. Si el valor de humedad o temperatura es NaN (no es un número), indica una lectura fallida del sensor, y se imprime un mensaje de error.

**Aprende Más**

También puedes mostrar la temperatura y humedad en el LCD I2C1602.


.. note::

    * Puedes abrir el archivo ``5.10_thermistor_lcd.ino`` bajo la ruta de ``euler-kit/arduino/5.10_thermistor_lcd``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * Se utilizan aquí las bibliotecas ``LiquidCrystal_I2C`` y  ``DHT sensor library``, puedes instalarlas desde el **Administrador de Bibliotecas**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fb46ba7e-0a09-4805-87ab-f733e23eb920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
