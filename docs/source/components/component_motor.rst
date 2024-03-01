.. _cpn_motor:

Motor de Corriente Continua (DC)
=======================================

.. image:: img/image114.jpeg
    :align: center

Este es un motor de corriente continua (DC) de 3V. Cuando aplicas un nivel alto y un nivel bajo a cada uno de los 2 terminales, girará.

* **Longitud**: 25mm
* **Diámetro**: 21mm
* **Diámetro del Eje**: 2mm
* **Longitud del Eje**: 8mm
* **Voltaje**: 3-6V
* **Corriente**: 0.35-0.4A
* **Velocidad a 3V**: 19000 RPM (Rotaciones Por Minuto)
* **Peso**: Aproximadamente 14g (por unidad)

El motor de corriente continua (DC) es un actuador continuo que convierte la energía eléctrica en energía mecánica. Los motores de corriente continua hacen que funcionen bombas rotativas, ventiladores, compresores, impulsores y otros dispositivos al producir una rotación angular continua.

Un motor de corriente continua consta de dos partes, la parte fija del motor llamada el **estator** y la parte interna del motor llamada el **rotor** (o **inducido** de un motor de corriente continua) que gira para producir movimiento.
La clave para generar movimiento es posicionar el inducido dentro del campo magnético del imán permanente (cuyo campo se extiende desde el polo norte hasta el polo sur). La interacción del campo magnético y las partículas cargadas en movimiento (el alambre conductor de corriente genera el campo magnético) produce el par de torsión que hace girar el inducido.

.. image:: img/motor_sche.png
    :align: center

La corriente fluye desde el terminal positivo de la batería a través del circuito, pasando por los cepillos de cobre hasta el conmutador, y luego al inducido.
Pero debido a las dos brechas en el conmutador, este flujo se invierte a mitad de cada rotación completa.

Esta inversión continua básicamente convierte la energía eléctrica de corriente continua de la batería en corriente alterna, permitiendo que el inducido experimente un par de torsión en la dirección correcta en el momento adecuado para mantener la rotación.

.. image:: img/motor_rotate.gif
    :align: center

**Ejemplo**

* :ref:`ar_motor` (Proyecto Arduino)
* :ref:`py_motor` (Proyecto MicroPython)
* :ref:`sh_rotating_fan` (Proyecto Scratch)
