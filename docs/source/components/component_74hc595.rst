.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

¿Alguna vez te has encontrado queriendo controlar una gran cantidad de LED, o simplemente necesitas más pines de E/S para controlar botones, sensores y servos al mismo tiempo? Bueno, puedes conectar algunos sensores a los pines de Arduino, pero pronto comenzarás a quedarte sin pines en el Arduino.

La solución es usar "registros de desplazamiento". Los registros de desplazamiento te permiten expandir el número de pines de E/S que puedes usar desde el Arduino (o cualquier microcontrolador). El registro de desplazamiento 74HC595 es uno de los más famosos.

El 74HC595 básicamente controla ocho pines de salida independientes y utiliza solo tres pines de entrada. Si necesitas más de ocho líneas de E/S adicionales, puedes fácilmente concatenar cualquier número de registros de desplazamiento y crear un gran número de líneas de E/S. Todo esto se hace mediante el llamado desplazamiento.

**Características**

* Registro de desplazamiento serial de 8 bits, paralelo de salida
* Amplio rango de voltaje de operación de 2 V a 6 V
* Las salidas de 3 estados de alta corriente pueden manejar hasta 15 cargas LSTTL
* Bajo consumo de energía, máx. 80 µA de corriente de CC
* tPD típico = 14 ns
* Salida de ±6 mA a 5 V
* Baja corriente de entrada de 1 µA máx.
* Registro de desplazamiento con limpieza directa

**Pines de 74HC595 y sus funciones:**

.. image:: img/74hc595_pin.png
    :width: 600

* **Q0-Q7**: Pines de salida de datos paralelos de 8 bits, capaces de controlar 8 LED o 8 pines de un display de 7 segmentos directamente.
* **Q7'**: Pin de salida en serie, conectado a DS de otro 74HC595 para conectar múltiples 74HC595 en serie.
* **MR**: Pin de reset, activo en nivel bajo;
* **SHcp**: Entrada de secuencia de tiempo del registro de desplazamiento. En el flanco ascendente, los datos en el registro de desplazamiento se desplazan sucesivamente un bit, es decir, los datos en Q1 se desplazan a Q2, y así sucesivamente. Mientras que en el flanco descendente, los datos en el registro de desplazamiento permanecen sin cambios.
* **STcp**: Entrada de secuencia de tiempo del registro de almacenamiento. En el flanco ascendente, los datos en el registro de desplazamiento se mueven al registro de memoria.
* **CE**: Pin de habilitación de salida, activo en nivel bajo.
* **DS**: Pin de entrada de datos en serie
* **VCC**: Voltaje de alimentación positivo.
* **GND**: Tierra.

**Diagrama Funcional**

.. image:: img/74hc595_functional_diagram.png


**Principio de Funcionamiento**

Cuando MR (pin 10) está en nivel alto y OE (pin 13) está en nivel bajo, 
los datos se ingresan en el flanco ascendente de SHcp y pasan al registro de memoria a través del flanco ascendente de STcp.


* Registro de Desplazamiento

    * Supongamos que queremos ingresar los datos binarios 1110 1110 en el registro de desplazamiento del 74hc595.
    * Los datos se ingresan desde el bit 0 del registro de desplazamiento.
    * Cada vez que el reloj del registro de desplazamiento es un flanco ascendente, los bits en el registro de desplazamiento se desplazan un paso. Por ejemplo, el bit 7 acepta el valor anterior en el bit 6, el bit 6 obtiene el valor del bit 5, etc.


.. image:: img/74hc595_shift.png

* Registro de Almacenamiento

    * Cuando el registro de almacenamiento está en estado de flanco ascendente, los datos del registro de desplazamiento se transferirán al registro de almacenamiento.
    * El registro de almacenamiento está conectado directamente a los 8 pines de salida, Q0 ~ Q7 podrá recibir un byte de datos.
    * El llamado registro de almacenamiento significa que los datos pueden existir en este registro y no desaparecerán con una salida.
    * Los datos permanecerán válidos e inalterados siempre que el 74HC595 esté alimentado continuamente.
    * Cuando llegan nuevos datos, los datos en el registro de almacenamiento serán sobrescritos y actualizados.

.. image:: img/74hc595_storage.png

**Ejemplo**

* :ref:`ar_74hc595` (Proyecto Arduino)
* :ref:`ar_7_segment` (Proyecto Arduino)
* :ref:`ar_dice` (Proyecto Arduino)
* :ref:`py_74hc595` (Proyecto MicroPython)
* :ref:`py_7_segment` (Proyecto MicroPython)
* :ref:`py_dice` (Proyecto MicroPython)

