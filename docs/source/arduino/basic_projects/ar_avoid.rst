.. _ar_ir_obstacle:

5.3 Detectar el Obstáculo
===================================

Este módulo se instala comúnmente en coches y robots para juzgar la existencia de obstáculos adelante. También se utiliza ampliamente en dispositivos portátiles, grifos de agua y más.

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
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|


**Pines Disponibles**

* **Pines Disponibles**

    Aquí está una lista de los pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Pines Disponibles
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Pines de Strapping (Entrada)**

    Los pines de strapping son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo 
    (es decir, reset por encendido).
        
    .. list-table::
        :widths: 5 15

        *   - Pines de Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    Generalmente, **no se recomienda usarlos como pines de entrada**. Si deseas usar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, por favor refiérete a la sección :ref:`esp32_strapping`.

**Esquemático**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

Cuando el módulo de evitación de obstáculos no detecta ningún obstáculo, IO14 devuelve un nivel alto. Sin embargo, cuando detecta un obstáculo, devuelve un nivel bajo. Puedes ajustar el potenciómetro azul para modificar la distancia de detección de este módulo.

**Cableado**


.. image:: ../../img/wiring/5.3_avoid_bb.png


**Código**

.. note::

    * Puedes abrir el archivo ``5.3.detect_the_obstacle.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.3.detect_the_obstacle``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b0f22caa-3c77-4dc1-9a33-20ff23d04a5e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Después de subir el código con éxito, si el módulo de evitación de obstáculos IR detecta algo bloqueando frente a él, aparecerá "0" en el monitor serial, de lo contrario se mostrará "1".
