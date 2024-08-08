.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_photoresistor:

5.7 Siente la Luz
===========================

La fotorresistencia es un dispositivo comúnmente utilizado para entradas analógicas, similar a un potenciómetro. Su valor de resistencia cambia según la intensidad de la luz que recibe. Cuando se expone a una luz fuerte, la resistencia de la fotorresistencia disminuye, y a medida que la intensidad de la luz disminuye, la resistencia aumenta.

Al leer el valor de la fotorresistencia, podemos recopilar información sobre las condiciones de luz ambiental. Esta información puede ser utilizada para tareas como controlar el brillo de un LED, ajustar la sensibilidad de un sensor o implementar acciones dependientes de la luz en un proyecto.

**Componentes Necesarios**

En este proyecto, necesitaremos los siguientes componentes.

Es definitivamente conveniente comprar todo el kit, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    * - Nombre
      - ARTÍCULOS EN ESTE KIT
      - ENLACE
    * - Kit de Inicio ESP32
      - 320+
      - |link_esp32_starter_kit|

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    * - INTRODUCCIÓN DE COMPONENTES
      - ENLACE DE COMPRA

    * - :ref:`cpn_esp32_wroom_32e`
      - |link_esp32_wroom_32e_buy|
    * - :ref:`cpn_esp32_camera_extension`
      - |link_esp32_extension_board|
    * - :ref:`cpn_breadboard`
      - |link_breadboard_buy|
    * - :ref:`cpn_wires`
      - |link_wires_buy|
    * - :ref:`cpn_resistor`
      - |link_resistor_buy|
    * - :ref:`cpn_photoresistor`
      - |link_photoresistor_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 15

        * - Pines Disponibles
          - IO14, IO25, I35, I34, I39, I36


* **Pines de Arranque**

    Los siguientes pines son pines de arranque, los cuales afectan el proceso de inicio del ESP32 durante el encendido o el reinicio. Sin embargo, una vez que el ESP32 se ha iniciado con éxito, pueden ser utilizados como pines regulares.

    .. list-table::
        :widths: 5 15

        * - Pines de Arranque
          - IO0, IO12

**Esquemático**

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

A medida que aumenta la intensidad de la luz, la resistencia del resistor dependiente de la luz (LDR) disminuye, resultando en una disminución del valor leído en I35.

**Cableado**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

**Código**

.. note::

    * Abre el archivo ``5.7_feel_the_light.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.7_feel_the_light``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/58b494c7-eef4-4476-af65-4823cef13f90/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de subir con éxito el código, el Monitor Serial imprime los valores de la fotorresistencia de 0 ~ 4095. 
Cuanto más fuerte es el brillo ambiental actual, mayor es el valor mostrado en el monitor serial.

.. note::
    Para el ESP32, la resolución está entre 9 y 12 y cambiará la resolución de hardware ADC. De lo contrario, el valor se desplazará.

    El valor predeterminado es de 12 bits (rango de 0 a 4096) para todos los chips excepto ESP32S3 donde el predeterminado es de 13 bits (rango de 0 a 8192).

    Puedes agregar ``analogReadResolution(10);`` a la función ``setup()`` para establecer una resolución diferente, como ``20``.
