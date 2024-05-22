.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_pir:

Módulo Sensor de Movimiento PIR
====================================

.. image:: img/pir_pic.png
    :width: 300
    :align: center

El sensor PIR detecta radiación de calor infrarrojo que puede utilizarse para detectar la presencia de organismos que emiten radiación de calor infrarrojo.

El sensor PIR está dividido en dos ranuras que están conectadas a un amplificador diferencial. Cuando un objeto estacionario está frente al sensor, las dos ranuras reciben la misma cantidad de radiación y la salida es cero. Cuando un objeto en movimiento está frente al sensor, una de las ranuras recibe más radiación que la otra, lo que hace que la salida fluctúe alta o baja. Este cambio en el voltaje de salida es el resultado de la detección de movimiento.

.. image:: img/PIR_working_principle.jpg
    :width: 800

Después de que el módulo de detección esté cableado, hay una inicialización de un minuto. Durante la inicialización, el módulo emitirá de 0 a 3 veces a intervalos. Luego, el módulo estará en modo de espera. Mantenga la interferencia de fuentes de luz y otras fuentes alejadas de la superficie del módulo para evitar el mal funcionamiento causado por la señal de interferencia. Incluso es mejor utilizar el módulo sin demasiado viento, ya que el viento también puede interferir con el sensor.

.. image:: img/pir_back.png
    :width: 600
    :align: center

**Ajuste de Distancia**

Girando el botón del potenciómetro de ajuste de distancia en el sentido de las agujas del reloj, aumenta el rango de distancia de detección, y el rango máximo de distancia de detección es de aproximadamente 0 a 7 metros. Si lo gira en sentido contrario a las agujas del reloj, el rango de distancia de detección se reduce, y el rango de distancia de detección mínimo es de aproximadamente 0 a 3 metros.

**Ajuste de Retardo**

Gire el botón del potenciómetro de ajuste de retardo en el sentido de las agujas del reloj, también puede ver cómo aumenta el retardo de detección. El máximo del retardo de detección puede alcanzar hasta 300s. Por el contrario, si lo gira en sentido contrario a las agujas del reloj, puede acortar el retardo con un mínimo de 5s.

**Dos Modos de Disparo**

Elija diferentes modos usando la tapa del jumper.

* **H**: Modo de disparo repetible, después de detectar el cuerpo humano, el módulo emite un nivel alto. Durante el período de retardo subsiguiente, si alguien entra en el rango de detección, la salida seguirá siendo de nivel alto.

* **L**: Modo de disparo no repetible, emite un nivel alto cuando detecta el cuerpo humano. Después del retardo, la salida cambiará automáticamente de nivel alto a nivel bajo.

**Ejemplo**

* :ref:`ar_pir` (Proyecto Arduino)
* :ref:`iot_telegram` (Proyecto Arduino)
* :ref:`py_pir` (Proyecto MicroPython)
