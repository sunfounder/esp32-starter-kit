.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_ultrasonic:

Módulo Ultrasonido
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Entrada de Pulso de Disparo
* **ECHO**: Salida de Pulso de Eco
* **GND**: Tierra
* **VCC**: Suministro de 5V

Este es el sensor de distancia ultrasónico HC-SR04, que proporciona mediciones sin contacto desde 2 cm hasta 400 cm con una precisión de rango de hasta 3 mm. Incluido en el módulo hay un transmisor ultrasónico, un receptor y un circuito de control.

Solo necesitas conectar 4 pines: VCC (alimentación), Trig (disparador), Echo (recepción) y GND (tierra) para facilitar su uso en tus proyectos de medición.

**Características**

* Voltaje de Trabajo: DC5V
* Corriente de Trabajo: 16mA
* Frecuencia de Trabajo: 40Hz
* Rango Máximo: 500cm
* Rango Mínimo: 2cm
* Señal de Entrada de Disparo: Pulso TTL de 10uS
* Señal de Salida de Eco: Señal de nivel TTL de entrada y el rango en proporción
* Conector: XH2.54-4P
* Dimensiones: 46x20.5x15 mm

**Principio**

Los principios básicos son los siguientes:

* Usando el disparador de IO durante al menos 10us con una señal de nivel alto.

* El módulo envía una ráfaga de ultrasonido de 8 ciclos a 40 kHz y detecta si se recibe una señal de pulso.

* Echo emitirá un nivel alto si se recibe una señal; la duración del nivel alto es el tiempo desde la emisión hasta el retorno.

* Distancia = (tiempo de nivel alto x velocidad del sonido (340M/S)) / 2

.. image:: img/ultrasonic_prin.jpg


Fórmula:

* us / 58 = distancia en centímetros
* us / 148 = distancia en pulgadas
* distancia = tiempo de nivel alto x velocidad (340M/S) / 2

.. note::

    Este módulo no debe estar conectado bajo encendido, si es necesario, deja que la GND del módulo se conecte primero. De lo contrario, afectará el funcionamiento del módulo.

    El área del objeto a medir debe ser al menos de 0.5 metros cuadrados y lo más plana posible. De lo contrario, afectará los resultados.



**Ejemplo**

* :ref:`ar_ultrasonic` (Proyecto Arduino)
* :ref:`ar_reversing_aid` (Proyecto Arduino)
* :ref:`py_ultrasonic` (Proyecto MicroPython)
* :ref:`py_reversing_aid` (Proyecto MicroPython)
* :ref:`sh_parrot` (Proyecto Scratch)