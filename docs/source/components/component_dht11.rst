.. _cpn_dht11:

Sensor de Humedad y Temperatura DHT11
==============================================

El sensor digital de temperatura y humedad DHT11 es un sensor compuesto que contiene una salida de señal digital calibrada de temperatura y humedad.
Se aplica la tecnología de una colección de módulos digitales dedicados y la tecnología de detección de temperatura y humedad para garantizar que el producto tenga una alta fiabilidad y una excelente estabilidad a largo plazo.

El sensor incluye un componente sensible a la humedad resistivo y un dispositivo de medición de temperatura NTC, y está conectado con un microcontrolador de 8 bits de alto rendimiento.

Solo hay tres pines disponibles para su uso: VCC, GND y DATA.
El proceso de comunicación comienza con la línea de datos enviando señales de inicio al DHT11, y el DHT11 recibe las señales y devuelve una señal de respuesta.
Luego, el host recibe la señal de respuesta y comienza a recibir datos de humedad y temperatura de 40 bits (entero de humedad de 8 bits + decimal de humedad de 8 bits + entero de temperatura de 8 bits + decimal de temperatura de 8 bits + suma de verificación de 8 bits).

.. image:: img/dht11.png

**Características**

    #. Rango de medición de humedad: 20 - 90%RH
    #. Rango de medición de temperatura: 0 - 60℃
    #. Señales digitales de salida que indican temperatura y humedad
    #. Voltaje de trabajo: DC 5V; Tamaño de la placa de circuito impreso: 2.0 x 2.0 cm
    #. Precisión de la medición de humedad: ±5%RH
    #. Precisión de la medición de temperatura: ±2℃


* `Hoja de datos del DHT11 <http://wiki.sunfounder.cc/images/c/c7/DHT11_datasheet.pdf>`_

**Ejemplo**

* :ref:`ar_dht11` (Proyecto Arduino)
* :ref:`ar_plant_monitor` (Proyecto Arduino)
* :ref:`ar_adafruit_io` (Proyecto Arduino)
* :ref:`py_dht11` (Proyecto MicroPython)
* :ref:`py_plant_monitor` (Proyecto MicroPython)



