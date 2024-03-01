.. _cpn_servo:

Servo
===========

.. image:: img/servo.png
    :align: center

Un servo se compone generalmente de las siguientes partes: carcasa, eje, sistema de engranajes, potenciómetro, motor de corriente continua y placa embebida.

Funciona de la siguiente manera: el microcontrolador envía señales PWM al servo, y luego la placa embebida en el servo recibe las señales a través del pin de señal y controla el motor en su interior para girar. Como resultado, el motor impulsa el sistema de engranajes y luego motiva el eje después de la desaceleración. El eje y el potenciómetro del servo están conectados entre sí. Cuando el eje gira, impulsa el potenciómetro, por lo que el potenciómetro emite una señal de voltaje a la placa embebida. Luego, la placa determina la dirección y la velocidad de rotación según la posición actual, por lo que puede detenerse exactamente en la posición correcta definida y mantenerse allí.

.. image:: img/servo_internal.png
    :align: center

El ángulo está determinado por la duración de un pulso que se aplica al cable de control. Esto se llama Modulación por Ancho de Pulso (PWM, por sus siglas en inglés). El servo espera ver un pulso cada 20 ms. La longitud del pulso determinará cuánto gira el motor. Por ejemplo, un pulso de 1.5 ms hará que el motor gire hasta la posición de 90 grados (posición neutral).
Cuando se envía un pulso a un servo que es menor que 1.5 ms, el servo gira a una posición y mantiene su eje de salida un cierto número de grados en sentido antihorario desde el punto neutral. Cuando el pulso es más ancho que 1.5 ms, ocurre lo contrario. El ancho mínimo y el ancho máximo del pulso que ordenará al servo girar a una posición válida son funciones de cada servo. Generalmente, el pulso mínimo tendrá aproximadamente 0.5 ms de ancho y el pulso máximo tendrá 2.5 ms de ancho.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Ejemplo**

* :ref:`ar_servo` (Proyecto Arduino)
* :ref:`py_servo` (Proyecto MicroPython)

