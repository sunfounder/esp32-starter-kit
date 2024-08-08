.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_potentiometer:

5.8 Gira el Potenciómetro
==============================

Un potenciómetro es un dispositivo de tres terminales que se utiliza comúnmente para ajustar la resistencia en un circuito. Cuenta con un botón o una palanca deslizante que se puede utilizar para variar el valor de resistencia del potenciómetro. En este proyecto, lo utilizaremos para controlar el brillo de un LED, similar a una lámpara de escritorio en nuestra vida diaria. Al ajustar la posición del potenciómetro, podemos cambiar la resistencia en el circuito, regulando así la corriente que fluye a través del LED y ajustando su brillo en consecuencia. Esto nos permite crear una experiencia de iluminación personalizable y ajustable, similar a la de una lámpara de escritorio.

**Componentes Necesarios**

En este proyecto, necesitaremos los siguientes componentes.

Es definitivamente conveniente comprar todo el kit, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    * - Nombre
      - ARTÍCULOS EN ESTE KIT
      - ENLACE
    * - Kit de Inicio ESP32
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
    * - :ref:`cpn_led`
      - |link_led_buy|
    * - :ref:`cpn_pot`
      - |link_potentiometer_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí está la lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 15

        * - Pines Disponibles
          - IO14, IO25, I35, I34, I39, I36

* **Pines de Arranque**

    Los siguientes pines son pines de arranque, que afectan el proceso de inicio del ESP32 durante el encendido o el restablecimiento. Sin embargo, una vez que el ESP32 se ha iniciado correctamente, se pueden utilizar como pines regulares.

    .. list-table::
        :widths: 5 15

        * - Pines de Arranque
          - IO0, IO12


**Esquemático**

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

Al girar el potenciómetro, el valor de I35 cambiará. Mediante programación, puedes usar el valor de I35 para controlar el brillo del LED. Por lo tanto, al girar el potenciómetro, el brillo del LED también cambiará en consecuencia.


**Cableado**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**Código**

.. note::

    * Puedes abrir el archivo ``5.8_pot.ino`` en la ruta ``esp32-starter-kit-main\c\codes\5.8_pot``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
   
.. raw:: html
     
    <iframe src=https://create.arduino.cc/editor/sunfounder01/aadce2e7-fd5d-4608-a557-f1e4d07ba795/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de subir el código con éxito, gira el potenciómetro y verás el brillo del LED cambiar en consecuencia. Al mismo tiempo, puedes ver los valores analógicos y de voltaje del potenciómetro en el monitor serie.

**Cómo funciona?**

1. Define constantes para las conexiones de pines y configuraciones PWM.

    .. code-block:: arduino

        const int potPin = 35; // Potentiometer connected to
        const int ledPin = 26; // LED connected to

        // PWM settings
        const int freq = 5000; // PWM frequency
        const int resolution = 12; // PWM resolution (bits)

    Here the PWM resolution is set to 12 bits and the range is 0-4095.

2. Configura el sistema en la función ``setup()``.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);

            // Configure PWM
            ledcAttach(ledPin, freq, resolution);
        }

    * En la función ``setup()``, se inicia la comunicación Serial a una tasa de baudios de 115200. 
    * La función ``ledcAttach()`` se llama para configurar el pin LED especificado con la frecuencia y resolución especificadas.

3. Bucle principal (ejecutado repetidamente) en la función loop().

    .. code-block:: arduino

        void loop() {

            int potValue = analogRead(potPin); // read the value of the potentiometer
            uint32_t voltage_mV = analogReadMilliVolts(potPin); // Read the voltage in millivolts
            
            ledcWrite(ledPin, potValue);
            
            Serial.print("Potentiometer Value: ");
            Serial.print(potValue);
            Serial.print(", Voltaje: ");
            Serial.print(voltage_mV / 1000.0); // Convierte milivoltios a voltios
            Serial.println(" V");
            
            delay(100);
        }

    * ``uint32_t analogReadMilliVolts(uint8_t pin);``: Esta función se utiliza para obtener el valor de ADC para un pin/canal de ADC dado en milivoltios.

        * ``pin`` Pin GPIO para leer el valor analógico.

El valor del potenciómetro se utiliza directamente como el ciclo de trabajo PWM para controlar el brillo del LED a través de la función ``ledcWrite()``, ya que el rango de valores también es de 0 a 4095.

    