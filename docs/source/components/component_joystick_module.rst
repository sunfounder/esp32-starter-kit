.. _cpn_joystick:

Módulo de Joystick
=======================

.. image:: img/joystick_pic.png
    :align: center
    :width: 600

* **GND**: Tierra.
* **+5V**: Suministro de energía, acepta de 3.3V a 5V.
* **VRX**: Salida analógica correspondiente a la posición horizontal (eje X) del joystick.
* **VRY**: Salida analógica correspondiente a la posición vertical (eje Y) del joystick.
* **SW**: Salida del interruptor de botón, activado cuando se presiona el joystick hacia abajo. Para un funcionamiento adecuado, se requiere una resistencia pull-up externa. Con la resistencia en su lugar, el pin SW emite un nivel alto cuando está inactivo y se vuelve bajo cuando se presiona el joystick.


La idea básica de un joystick es traducir el movimiento de un palo en información electrónica que una computadora puede procesar.

Para comunicar un rango completo de movimiento a la computadora, un joystick necesita medir la posición del palo en dos ejes: el eje X (de izquierda a derecha) y el eje Y (arriba y abajo). Al igual que en la geometría básica, las coordenadas X-Y señalan exactamente la posición del palo.

Para determinar la ubicación del palo, el sistema de control del joystick simplemente monitorea la posición de cada eje. El diseño convencional de joystick analógico hace esto con dos potenciómetros, o resistencias variables.

El joystick también tiene una entrada digital que se activa cuando se presiona el joystick hacia abajo.

.. image:: img/joystick318.png
    :align: center
    :width: 600
	
**Ejemplo**

* :ref:`ar_joystick` (Proyecto Arduino)
* :ref:`py_joystick` (Proyecto MicroPython)
* :ref:`sh_star_crossed` (Proyecto Scratch)
* :ref:`sh_dragon` (Proyecto Scratch)
