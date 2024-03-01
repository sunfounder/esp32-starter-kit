.. _py_thermistor:

5.10 Detección de Temperatura
================================

Un termistor es un sensor de temperatura que muestra una fuerte dependencia de la temperatura, y puede clasificarse en dos tipos: Coeficiente de Temperatura Negativo (NTC) y Coeficiente de Temperatura Positivo (PTC). La resistencia de un termistor NTC disminuye con el aumento de la temperatura, mientras que la resistencia de un termistor PTC aumenta con el aumento de la temperatura.

En este proyecto, usaremos un termistor NTC. Al conectar el termistor NTC a un pin de entrada analógica del microcontrolador ESP32, podemos medir su resistencia, que es directamente proporcional a la temperatura.

Incorporando el termistor NTC y realizando los cálculos necesarios, podemos medir con precisión la temperatura y mostrarla en el módulo I2C LCD1602. Este proyecto permite la monitorización de la temperatura en tiempo real y proporciona una interfaz visual para la visualización de la temperatura.

**Componentes Requeridos**

Para este proyecto, necesitaremos los siguientes componentes.

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

    *   - INTRODUCCIÓN AL COMPONENTE
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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 15

        *   - Pines Disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Pines de Configuración**

    Los siguientes pines son pines de configuración, que afectan el proceso de arranque del ESP32 durante el encendido o el reinicio. Sin embargo, una vez que el ESP32 ha arrancado con éxito, se pueden usar como pines regulares.

    .. list-table::
        :widths: 5 15

        *   - Pines de Configuración
            - IO0, IO12


**Esquemático**

.. image:: ../../img/circuit/circuit_5.10_thermistor.png

Cuando la temperatura aumenta, la resistencia del termistor disminuye, causando que el valor leído en I35 disminuya. Además, utilizando una fórmula, puedes convertir el valor analógico en temperatura y luego imprimirlo.

**Conexión**

.. image:: ../../img/wiring/5.10_thermistor_bb.png


.. note::
    * El termistor es negro y está marcado con 103.
    * El anillo de color de la resistencia de 10K ohm es rojo, negro, negro, rojo y marrón.

**Código**

.. note::

    * Abre el archivo ``5.10_thermistor.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 




.. code-block:: python

    # Import the necessary libraries
    from machine import ADC, Pin
    import time
    import math

    # Define the beta value of the thermistor, typically provided in the datasheet
    beta = 3950

    # Create an ADC object (thermistor)
    thermistor = ADC(Pin(35, Pin.IN))

    # Set the attenuation
    thermistor.atten(thermistor.ATTN_11DB)

    # Start an infinite loop to continuously monitor the temperature
    while True:
        # Read the voltage in microvolts and convert it to volts
        Vr = thermistor.read_uv() / 1000000

        # Calculate the resistance of the thermistor based on the measured voltage
        Rt = 10000 * Vr / (3.3 - Vr)

        # Use the beta parameter and resistance value to calculate the temperature in Kelvin
        temp = 1 / (((math.log(Rt / 10000)) / beta) + (1 / (273.15 + 25)))

        # Convert to Celsius
        Cel = temp - 273.15

        # Convert to Fahrenheit
        Fah = Cel * 1.8 + 32

        # Print the temperature values in both Celsius and Fahrenheit
        print('Celsius: %.2f C  Fahrenheit: %.2f F' % (Cel, Fah))
        time.sleep(0.5)

Cuando se ejecuta el código, la Shell imprimirá las temperaturas en Celsius y Fahrenheit.

**¿Cómo funciona?**

Cada termistor tiene una resistencia normal. Aquí es de 10k ohmios, medida a 25 grados Celsius.

Cuando la temperatura aumenta, la resistencia del termistor disminuye. Luego, los datos de voltaje se convierten a cantidades digitales por el adaptador A/D.

La temperatura en Celsius o Fahrenheit se muestra mediante programación.

Aquí está la relación entre la resistencia y la temperatura:

    **RT = RN expB(1/TK - 1/TN)**

    * **RT** es la resistencia del termistor NTC cuando la temperatura es **TK**.
    * **RN** es la resistencia del termistor NTC bajo la temperatura nominal TN. Aquí, el valor numérico de RN es 10k.
    * **TK** es una temperatura Kelvin y la unidad es K. Aquí, el valor numérico de **TK** es ``373.15 + grado Celsius``.
    * **TN** es una temperatura Kelvin nominal; la unidad también es K. Aquí, el valor numérico de TN es ``373.15+25``.
    * Y **B(beta)**, la constante material del termistor NTC, también se llama índice de sensibilidad al calor con un valor numérico ``4950``.
    * **exp** es la abreviatura de exponencial, y el número base ``e`` es un número natural y equivale aproximadamente a 2.7.

    Convierte esta fórmula ``TK = 1/(ln(RT/RN)/B + 1/TN)`` para obtener la temperatura Kelvin que menos 273.15 equivale a grados Celsius.

    Esta relación es una fórmula empírica. Es precisa solo cuando la temperatura y la resistencia están dentro del rango efectivo.

**Aprender Más**

También puedes mostrar las temperaturas Celsius y Fahrenheit calculadas en el I2C LCD1602.

.. image:: ../../img/wiring/5.10_thermistor_lcd_bb.png

.. note::

    * Abre el archivo ``5.10_thermistor_lcd.py`` ubicado en el camino ``esp32-starter-kit-main\micropython\codes`` o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha.

    * Aquí necesitas usar la biblioteca llamada ``lcd1602.py``, por favor verifica si ha sido cargada en ESP32, para un tutorial detallado consulta :ref:`add_libraries_py`.


.. code-block:: python

    # Import the necessary libraries
    from machine import ADC, Pin
    from lcd1602 import LCD
    import time
    import math

    # Define the beta value of the thermistor, typically provided in the datasheet
    beta = 3950

    # Create an ADC object (thermistor)
    thermistor = ADC(Pin(35, Pin.IN))

    # Set the attenuation
    thermistor.atten(thermistor.ATTN_11DB)

    lcd = LCD()

    # Start an infinite loop to continuously monitor the temperature
    while True:
        # Read the voltage in microvolts and convert it to volts
        Vr = thermistor.read_uv() / 1000000

        # Calculate the resistance of the thermistor based on the measured voltage
        Rt = 10000 * Vr / (3.3 - Vr)

        # Use the beta parameter and resistance value to calculate the temperature in Kelvin
        temp = 1 / (((math.log(Rt / 10000)) / beta) + (1 / (273.15 + 25)))

        # Convert to Celsius
        Cel = temp - 273.15

        # Convert to Fahrenheit
        Fah = Cel * 1.8 + 32

        # Print the temperature values in both Celsius and Fahrenheit
        print('Celsius: %.2f C  Fahrenheit: %.2f F' % (Cel, Fah))

        # Clear the LCD screen
        lcd.clear()
        
        # Display the temperature values in both Celsius and Fahrenheit
        lcd.message('Cel: %.2f \xDFC \n' % Cel)
        lcd.message('Fah: %.2f \xDFF' % Fah)
        time.sleep(1)


