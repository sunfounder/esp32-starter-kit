.. _ar_moisture:

5.9 Medir la Humedad del Suelo
===============================
Este sensor de humedad del suelo capacitivo es diferente de la mayoría de los sensores resistivos en el mercado, utilizando el principio de inducción capacitiva para detectar la humedad del suelo.

Al leer visualmente los valores del sensor de humedad del suelo, podemos recopilar información sobre el nivel de humedad en el suelo. Esta información es útil para varias aplicaciones, como sistemas de riego automático, monitoreo de la salud de las plantas o proyectos de detección ambiental.

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
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 15

        *   - Pines Disponibles
            - IO14, IO25, I35, I34, I39, I36


* **Pines de Strapping**

    Los siguientes pines son pines de strapping, que afectan el proceso de arranque del ESP32 durante el encendido o el reinicio. Sin embargo, una vez que el ESP32 se ha iniciado con éxito, se pueden usar como pines regulares.

    .. list-table::
        :widths: 5 15

        *   - Pines de Strapping
            - IO0, IO12

**Esquemático**

.. image:: ../../img/circuit/circuit_5.9_soil_moisture.png

Al insertar el módulo en el suelo y regarlo, el valor leído en I35 disminuirá.

**Cableado**

.. image:: ../../img/wiring/5.9_moisture_bb.png

**Código**

.. note::

    * Abre el archivo ``5.9_moisture.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.9_moisture``.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/431302c2-3579-4be6-8142-c91d28757004/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Una vez que el código se haya cargado con éxito, el monitor serie imprimirá el valor de la humedad del suelo.

Al insertar el módulo en el suelo y regarlo, el valor del sensor de humedad del suelo se volverá más pequeño.
