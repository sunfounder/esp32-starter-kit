.. _py_photoresistor:

5.7 Siente la Luz
=============================

El fotoresistor es un dispositivo comúnmente utilizado para entradas analógicas, similar a un potenciómetro. Su valor de resistencia cambia basado en la intensidad de la luz que recibe. Cuando está expuesto a luz fuerte, la resistencia del fotoresistor disminuye, y a medida que la intensidad de la luz disminuye, la resistencia aumenta.

Al leer el valor del fotoresistor, podemos recopilar información sobre las condiciones de luz ambiental. Esta información puede ser utilizada para tareas tales como controlar el brillo de un LED, ajustar la sensibilidad de un sensor, o implementar acciones dependientes de la luz en un proyecto.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 15

        *   - Pines Disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Pines de Amarrado**

    Los siguientes pines son pines de amarrado, que afectan el proceso de arranque del ESP32 durante el encendido o reinicio. Sin embargo, una vez que el ESP32 se ha iniciado correctamente, pueden ser utilizados como pines regulares.

    .. list-table::
        :widths: 5 15

        *   - Pines de Amarrado
            - IO0, IO12

**Esquemático**

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

A medida que aumenta la intensidad de la luz, la resistencia del resistor dependiente de la luz (LDR) disminuye, resultando en una disminución en el valor leído en I35.

**Conexión**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

**Código**

.. note::

    * Abre el archivo ``5.7_feel_the_light.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 



.. code-block:: python

    from machine import ADC,Pin
    import time

    # create an ADC object acting on a pin
    photoresistor = ADC(Pin(35, Pin.IN))

    # Configure the ADC attenuation to 11dB for full range     
    photoresistor.atten(photoresistor.ATTN_11DB)

    while True:

        # read a raw analog value in the range 0-4095
        value = photoresistor.read()  
        print(value)
        time.sleep(0.05)


Después de ejecutar el programa, la consola muestra los valores del fotoresistor. Puedes iluminarlo con una linterna o cubrirlo con tu mano para ver cómo cambia el valor.


* ``atten(photoresistor.ATTN_11DB)``: Configura la atenuación del ADC a 11dB para el rango completo.

    Para leer voltajes por encima del voltaje de referencia, aplica la atenuación de entrada con el argumento de palabra clave atten.

    Valores válidos (y rangos de medición lineal aproximados) son:

    * ADC.ATTN_0DB: Sin atenuación (100mV - 950mV)
    * ADC.ATTN_2_5DB: Atenuación de 2.5dB (100mV - 1250mV)
    * ADC.ATTN_6DB: Atenuación de 6dB (150mV - 1750mV)
    * ADC.ATTN_11DB: Atenuación de 11dB (150mV - 2450mV)

* `machine.ADC - MicroPython Docs <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

