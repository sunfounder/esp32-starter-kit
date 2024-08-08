.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_color_gradient:

6.5 Degradado de Color
==============================================
¿Estás listo para experimentar un mundo de color? Este proyecto te llevará en un viaje mágico donde podrás controlar un LED RGB y lograr transiciones suaves de color. Ya sea que busques añadir algo de color a tu decoración del hogar o buscando un proyecto de programación divertido, este proyecto lo tiene todo. ¡Sumérgete juntos en este mundo colorido!

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - Kit de Inicio ESP32
        - 320+
        - |link_esp32_starter_kit|

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DE COMPONENTES
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Esquemático**

.. image:: ../../img/circuit/circuit_6.5_color_gradient_ar.png


**Cableado**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

El LED RGB tiene 4 pines: el pin largo es el pin cátodo común, que generalmente se conecta a GND; el pin izquierdo al lado del pin más largo es Rojo; y los dos pines a la derecha son Verde y Azul.

.. image:: ../../img/wiring/6.5_color_rgb_bb.png

**Código**


.. note::

    * Puedes abrir el archivo ``6.5_color_gradient.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\6.5_color_gradient``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a8402b92-8884-4ba0-b09c-e596e97e0af8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Este proyecto utiliza un LED RGB y un potenciómetro para crear un efecto de mezcla de colores. El potenciómetro se utiliza para ajustar el valor del tono del LED, que luego se convierte en valores RGB utilizando una función de conversión de color. Los valores RGB se utilizan luego para actualizar el color del LED.

**¿Cómo funciona?**

Este proyecto se basa en el proyecto :ref:`ar_rgb` añadiendo un potenciómetro para ajustar el valor del tono del LED. El valor del tono se convierte a valores RGB utilizando la función ``HUEtoRGB()``.

#. En la función loop, lee el valor del potenciómetro y conviértelo a un valor de tono (0-360).

    .. code-block:: arduino

        int knobValue = analogRead(KNOB_PIN);
        float hueValue = (float) knobValue / 4095.0;
        int hue = (int) (hueValue * 360);

#. Convierte el valor del tono a valores RGB utilizando la función ``HUEtoRGB()``, y actualiza el LED con los nuevos valores de color.

    .. code-block:: arduino

        int red, green, blue;
        HUEtoRGB(hue, &red, &green, &blue);
        setColor(red, green, blue);

#. La función ``setColor()`` establece el valor de los canales rojo, verde y azul utilizando la biblioteca ``LEDC``.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            ledcWrite(redPin, red);
            ledcWrite(greenPin, green);
            ledcWrite(bluePin, blue);
        }
    
#. La función ``HUEtoRGB`` convierte un valor de tono a valores RGB utilizando el modelo de color HSL.

    .. code-block:: arduino

        void HUEtoRGB(int hue, int* red, int* green, int* blue) {
            float h = (float) hue / 60.0;
            float c = 1.0;
            float x = c * (1.0 - fabs(fmod(h, 2.0) - 1.0));
            float r, g, b;
            if (h < 1.0) {
                r = c;
                g = x;
                b = 0;
        ...
