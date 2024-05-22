.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_ws2812:

Tira de 8 LEDs RGB WS2812
============================

.. image:: img/ws2812b.png

La tira de 8 LEDs RGB WS2812 está compuesta por 8 LEDs RGB.
Solo se requiere un pin para controlar todos los LEDs. Cada LED RGB tiene un chip WS2812, que puede ser controlado de manera independiente.
Puede realizar una visualización de brillo de 256 niveles y una visualización de color real de 16,777,216 colores.
Al mismo tiempo, el píxel contiene una interfaz digital inteligente de datos de interfaz de bloqueo de señal de amplificador de conformación de señal,
y un circuito de conformación de señal está integrado para garantizar efectivamente la altura del color del píxel de luz de punto consistente.

Es flexible, se puede conectar, doblar y cortar a voluntad, y la parte posterior está equipada con cinta adhesiva, que se puede fijar en la superficie irregular a voluntad y se puede instalar en un espacio estrecho.

**Características**

* Voltaje de trabajo: DC5V
* IC: Un IC controla un LED RGB
* Consumo: 0.3w por cada LED
* Temperatura de trabajo: -15-50
* Color: RGB a todo color
* Tipo de RGB: 5050RGB (IC incorporado WS2812B)
* Grosor de la tira de luz: 2mm
* Cada LED se puede controlar individualmente

**Introducción WS2812B**

* `Hoja de datos WS2812B <https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf>`_

WS2812B es una fuente de luz LED de control inteligente en la que el circuito de control y el chip RGB están integrados en un paquete de componentes 5050. Internamente incluye una traba de datos de puerto digital inteligente y un circuito de amplificación de conformación de señal. También incluye un oscilador interno de precisión y una parte de control de corriente constante programable de 12V, lo que garantiza efectivamente la consistencia del color de la luz del punto del píxel.

El protocolo de transferencia de datos utiliza un modo de comunicación NZR único. Después del reinicio de alimentación del píxel, el puerto DIN recibe datos del controlador, el primer píxel recoge datos iniciales de 24 bits y luego los envía al latch de datos interno, los otros datos que son reformados por el circuito de amplificación de conformación de señal interno se envían al siguiente píxel en cascada a través del puerto DO. Después de la transmisión para cada píxel, la señal se reduce en 24 bits. El píxel adopta una tecnología de transmisión de reestructuración automática, lo que hace que el número de cascadas de píxeles no esté limitado a la transmisión de señales, solo depende de la velocidad de transmisión de la señal.

LED con bajo voltaje de conducción, protección del medio ambiente y ahorro de energía, alta luminosidad, ángulo de dispersión grande, buena consistencia, bajo consumo de energía, larga vida útil y otras ventajas. El chip de control integrado en el LED por encima se convierte en un circuito más simple, de pequeño volumen y de instalación conveniente.

**Ejemplo**

* :ref:`ar_rgb_strip` (Proyecto Arduino)
* :ref:`ar_flowing_light` (Proyecto Arduino)
* :ref:`py_rgb_strip` (Proyecto MicroPython)
* :ref:`py_flowing_light` (Proyecto MicroPython)
* :ref:`py_color_gradient` (Proyecto MicroPython)
