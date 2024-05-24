.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_receiver:

Receptor de Infrarrojos
===========================

**Receptor de Infrarrojos**

.. image:: img/ir_receiver_sl838.png
    :width: 400
    :align: center

* **S**: Salida de señal
* **-**: Tierra
* **+**: Fuente de alimentación, 3.3v~5V

El receptor de infrarrojos SL838 es un componente que recibe señales infrarrojas y puede recibir independientemente rayos infrarrojos y emitir señales compatibles con el nivel TTL. Es similar a un transistor normal encapsulado en plástico en tamaño y es adecuado para todo tipo de control remoto infrarrojo y transmisión infrarroja.

La comunicación infrarroja, o IR, es una tecnología de comunicación inalámbrica popular, de bajo costo y fácil de usar. La luz infrarroja tiene una longitud de onda ligeramente más larga que la luz visible, por lo que es imperceptible para el ojo humano, lo que la hace ideal para la comunicación inalámbrica. Un esquema de modulación común para la comunicación infrarroja es la modulación de 38 kHz.


* Puede ser utilizado para control remoto
* Amplio rango de voltaje de funcionamiento: 2.7~5V
* Filtro interno para frecuencia PCM
* Compatibilidad TTL y CMOS
* Fuerte capacidad antiinterferencias
* Cumple con RoHS


**Control Remoto**

.. image:: img/image186.jpeg
    :width: 400

Este es un control remoto inalámbrico de infrarrojos delgado y miniatura con 21 botones de función y una distancia de transmisión de hasta 8 metros, que es adecuado para operar una amplia gama de dispositivos en la habitación de un niño.

* Tamaño: 85x39x6mm
* Rango de control remoto: 8-10m
* Batería: Pila de litio de tipo botón de 3V
* Frecuencia portadora infrarroja: 38 kHz
* Material de adhesión superficial: PET de 0.125mm
* Vida útil efectiva: más de 20,000 veces


**Ejemplo**

* :ref:`ar_receiver` (Proyecto Arduino)
* :ref:`ar_guess_number` (Proyecto Arduino)
* :ref:`py_receiver` (Proyecto MicroPython)
* :ref:`py_guess_number` (Proyecto MicroPython)

