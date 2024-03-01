.. _py_flowing_light:

6.2 Luz Fluyente
=================================

¿Alguna vez has querido añadir un elemento divertido e interactivo a tu espacio vital?
Este proyecto implica crear una luz corriente usando una tira de LED WS2812 y un módulo de evitación de obstáculos.
La luz corriente cambia de dirección cuando se detecta un obstáculo, convirtiéndola en una adición emocionante a tu decoración del hogar u oficina.

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí tienes el enlace:

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Diagrama Esquemático**

.. image:: ../../img/circuit/circuit_6.2_flowing_led.png
    :align: center

La tira de LED WS2812 está compuesta por una serie de LEDs individuales que pueden ser programados para mostrar diferentes colores y patrones.
En este proyecto, la tira está configurada para mostrar una luz corriente que se mueve en una dirección particular y
cambia de dirección cuando un obstáculo es detectado por el módulo de evitación de obstáculos.


**Cableado**

.. image:: ../../img/wiring/6.2_flowing_light_bb.png
    :width: 800

**Código**

.. note::

    * Abre el archivo ``6.2_flowing_led.py`` ubicado en la ruta ``esp32-starter-kit-main\micropython\codes``, o copia y pega el código en Thonny. Luego, haz clic en "Ejecutar Script Actual" o presiona F5 para ejecutarlo.
    * Asegúrate de seleccionar el intérprete "MicroPython (ESP32).COMxx" en la esquina inferior derecha. 

    
.. code-block:: python

      from machine import Pin
      import neopixel
      import time
      import random

      # Set the number of pixels for the running light
      num_pixels = 8

      # Set the data pin for the RGB LED strip
      data_pin = Pin(14, Pin.OUT)

      # Initialize the RGB LED strip object
      pixels = neopixel.NeoPixel(data_pin, num_pixels)

      # Initialize the avoid sensor
      avoid = Pin(25, Pin.IN)

      # Initialize the direction variable
      direction_forward = True

      # Initialize the reverse direction flag
      reverse_direction = False

      # Continuously loop the running light
      while True:
      
      # Read the input from the infrared sensor
      avoid_value = avoid.value()
      
      # Generate a random color for the current pixel
      color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
                  
      # If no obstacle is detected
      if avoid_value:
            for i in range(num_pixels):
                  
                  # Turn on the current pixel with the random color
                  pixels[i] = color
                  
                  # Update the RGB LED strip display
                  pixels.write()
                  
                  # Turn off the current pixel
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)
                  
      # If detects an obstacle, change the direction of the LED strip
      else:
            for i in range(num_pixels-1, -1, -1):
                  
                  pixels[i] = color
                  pixels.write()
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)

Los LEDs en la Tira RGB se iluminan uno por uno cuando se ejecuta el script. Tan pronto como se coloca un objeto frente al módulo de evitación de obstáculos, los LEDs en la Tira RGB se iluminan uno por uno en la dirección opuesta.
