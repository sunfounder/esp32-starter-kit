.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_audio_speaker:

Módulo de Audio y Altavoz
===========================

**Módulo Amplificador de Audio**

.. image:: img/audio_module.jpg
    :width: 500
    :align: center

El Módulo Amplificador de Audio contiene un chip amplificador de potencia HXJ8002. Este chip es un amplificador de potencia con bajo consumo, que puede proporcionar una potencia de audio promedio de 3W para una carga BTL de 3Ω con baja distorsión armónica (por debajo del 10% de distorsión umbral a 1 kHz) desde una fuente de alimentación de 5V DC. Este chip puede amplificar señales de audio sin ningún condensador de acoplamiento o condensadores bootstrap.

El módulo puede ser alimentado por una fuente de alimentación de 2.0V hasta 5.5V DC con una corriente de funcionamiento de 10mA (0.6uA para la corriente de espera típica) y producir un sonido amplificado potente en un altavoz de impedancia de 3Ω, 4Ω o 8Ω. Este módulo tiene una circuitería mejorada de pop y clicks para reducir significativamente el ruido de transición en el momento del encendido y apagado. Su tamaño reducido además de su alta eficiencia y baja alimentación lo hacen aplicable en una amplia gama de proyectos portátiles y alimentados por batería y microcontroladores.

* **IC**: HXJ8002
* **Voltaje de Entrada**: 2V ~ 5.5V
* **Corriente en Modo de Espera**: 0.6uA (valor típico)
* **Potencia de Salida**: 3W (carga de 3Ω), 2.5W (carga de 4Ω), 1.5W (carga de 8Ω)
* **Impedancia del Altavoz de Salida**: 3Ω, 4Ω, 8Ω
* **Tamaño**: 19.8mm x 14.2mm

**Altavoz**

.. image:: img/speaker_pic.png
    :width: 300
    :align: center

* **Tamaño**: 20x30x7mm
* **Impedancia**: 8ohm
* **Potencia de Entrada Nominal**: 1.5W
* **Potencia de Entrada Máxima**: 2.0W
* **Longitud del Cable**: 10cm

.. image:: img/2030_speaker.png

La tabla de tamaños es la siguiente:

* :download:`Hoja de Datos del Altavoz 2030 <https://github.com/sunfounder/sf-pdf/raw/master/datasheet/2030-speaker-datasheet.pdf>`

**Ejemplo**

* :ref:`ar_mp3_player_sd` (Proyecto Arduino)
* :ref:`bluetooth_audio_player` (Proyecto Arduino)

