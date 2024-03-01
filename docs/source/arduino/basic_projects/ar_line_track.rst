.. _ar_line_track:

5.4 Detectar la Línea
===================================

El módulo de seguimiento de línea se utiliza para detectar la presencia de áreas negras en el suelo, como líneas negras pegadas con cinta eléctrica.

Su emisor emite luz infrarroja adecuada hacia el suelo, la cual es absorbida relativamente y reflejada débilmente por superficies negras. Lo opuesto ocurre con las superficies blancas. Si se detecta luz reflejada, el suelo se indica actualmente como blanco. Si no se detecta, se indica como negro.

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
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Pines Disponibles
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Pines de Strapping (Entrada)**

    Los pines de strapping son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo 
    (es decir, reinicio de encendido).

        
    .. list-table::
        :widths: 5 15

        *   - Pines de Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    Generalmente, **no se recomienda usarlos como pines de entrada**. Si deseas usar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, por favor consulta la sección :ref:`esp32_strapping`.


**Esquemático**

.. image:: ../../img/circuit/circuit_5.4_line.png

Cuando el módulo de seguimiento de línea detecta una línea negra, IO14 retorna un nivel alto. Por otro lado, cuando detecta una línea blanca, IO14 retorna un nivel bajo. Puedes ajustar el potenciómetro azul para modificar la sensibilidad de la detección de este módulo.


**Cableado**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**Código**

.. note::

    * Puedes abrir el archivo ``5.4_detect_the_line.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\5.4_detect_the_line``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fc7f3fe9-179a-4a3a-acbf-a4014faf3920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Si el módulo de seguimiento de línea detecta una línea negra después de que el código se haya cargado con éxito, "Negro" se mostrará en el Monitor Serie. De lo contrario, se imprimirá "Blanco".
