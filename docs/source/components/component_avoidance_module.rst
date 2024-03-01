.. _cpn_avoid:

Módulo de Evitación de Obstáculos
===========================================


.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Alimentación, 3.3 ~ 5V DC.
* **GND**: Tierra
* **OUT**: Pin de señal, normalmente nivel alto, y nivel bajo cuando se detecta un obstáculo.


El módulo de evitación de obstáculos por infrarrojos tiene una gran adaptabilidad a la luz ambiental, cuenta con un par de tubos emisores y receptores de infrarrojos.

El tubo emisor emite frecuencia infrarroja, cuando la dirección de detección encuentra un obstáculo, la radiación infrarroja es recibida por el tubo receptor, 
después del procesamiento del circuito comparador, el indicador se iluminará y emitirá una señal de nivel bajo.

La distancia de detección se puede ajustar mediante un potenciómetro, el rango de distancia efectiva es de 2 a 30 cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Ejemplo**

* :ref:`ar_ir_obstacle` (Proyecto Arduino)
* :ref:`py_ir_obstacle` (Proyecto MicroPython)
* :ref:`sh_shooting` (Proyecto Scratch)
* :ref:`sh_tap_tile` (Proyecto Scratch)

