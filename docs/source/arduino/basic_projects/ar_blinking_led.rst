.. _ar_blink:

2.1 ¡Hola, LED! 
=======================================

Así como imprimir "¡Hola, mundo!" es el primer paso para aprender a programar, usar un programa para encender un LED es la introducción tradicional para aprender programación física.

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

Aquí está una lista de los pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Esquemático**

.. image:: ../../img/circuit/circuit_2.1_led.png

Este circuito funciona sobre un principio simple, y la dirección de la corriente se muestra en la figura. El LED se encenderá después de la resistencia limitadora de corriente de 220ohm cuando el pin26 emita un nivel alto. El LED se apagará cuando el pin26 emita un nivel bajo.

**Cableado**

.. image:: ../../img/wiring/2.1_hello_led_bb.png



**Subir Código**

#. Puedes abrir el archivo ``2.1_hello_led.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\2.1_hello_led``. O copia este código directamente en el IDE de Arduino.
    
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/1bff2463-40ad-43c1-8815-9f448bab3735/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
#. Luego conecta el ESP32 WROOM 32E a tu computadora usando un cable Micro USB. 

    * :ref:`unknown_com_port`

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Selecciona la placa (ESP32 Dev Module) y el puerto apropiado.

    .. image:: img/choose_board.png

#. Ahora, haz clic en el botón **Subir** para cargar el código a la placa ESP32.
    
    .. image:: img/click_upload.png

#. Después de que el código se haya subido con éxito, verás el LED parpadeando.

**¿Cómo funciona?**

#. Declara una constante entera llamada ``ledPin`` y asígnale el valor 26. 

    .. code-block:: arduino

        const int ledPin = 26;  // The GPIO pin for the LED


#. Ahora, inicializa el pin en la función ``setup()``, donde necesitas inicializar el pin a modo ``OUTPUT``.

    .. code-block:: arduino

        void setup() {
            pinMode(ledPin, OUTPUT);
        }

    * ``void pinMode(uint8_t pin, uint8_t mode);``: Esta función se utiliza para definir el modo de operación GPIO para un pin específico.

        * ``pin`` define el número de pin GPIO.
        * ``mode`` establece el modo de operación.

        Los siguientes modos son compatibles para la entrada y salida básicas:

        * ``INPUT`` configura el GPIO como entrada sin pullup ni pulldown (alta impedancia).
        * ``OUTPUT`` configura el GPIO como modo de salida/lectura.
        * ``INPUT_PULLDOWN`` configura el GPIO como entrada con el pull-down interno.
        * ``INPUT_PULLUP`` configura el GPIO como entrada con el pull-up interno.

#. La función ``loop()`` contiene la lógica principal del programa y se ejecuta continuamente. Alterna entre establecer el pin en alto y bajo, con intervalos de un segundo entre los cambios.

    .. code-block:: arduino

        void loop() {
            digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(1000);                       // wait for a second
            digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
            delay(1000);                       // wait for a second
        }

    * ``void digitalWrite(uint8_t pin, uint8_t val);``: Esta función establece el estado del GPIO seleccionado en ``HIGH`` o ``LOW``. Esta función solo se utiliza si el ``pinMode`` se configuró como ``OUTPUT``.
    
        * ``pin`` define el número de pin GPIO.
        * ``val`` establece el estado digital de salida en ``HIGH`` o ``LOW``.
