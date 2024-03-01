.. _ar_pir:

5.5 Detección de Movimiento Humano
========================================

El sensor infrarrojo pasivo (sensor PIR) es un sensor común que puede medir la luz infrarroja (IR) emitida por objetos en su campo de visión. En pocas palabras, recibirá la radiación infrarroja emitida por el cuerpo, detectando así el movimiento de personas y otros animales. Más específicamente, le indica a la placa de control principal que alguien ha entrado en su habitación.

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
      - \-
    * - :ref:`cpn_breadboard`
      - |link_breadboard_buy|
    * - :ref:`cpn_wires`
      - |link_wires_buy|
    * - :ref:`cpn_resistor`
      - |link_resistor_buy|
    * - :ref:`cpn_led`
      - |link_led_buy|
    * - :ref:`cpn_pir`
      - |link_pir_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        * - Para Entrada
          - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        * - Para Salida
          - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::
    
    IO32 no puede ser utilizado **como pin de entrada** en este proyecto porque está internamente conectado a una resistencia de pull-down de 1K, lo que establece su valor predeterminado en 0.

* **Pines de Arranque (Entrada)**

    Los pines de arranque son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo (es decir, el reinicio por encendido).

    
    .. list-table::
        :widths: 5 15

        * - Pines de Arranque
          - IO5, IO0, IO2, IO12, IO15 
    

    

    Generalmente, **no se recomienda utilizarlos como pines de entrada**. Si deseas utilizar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, por favor consulta la sección :ref:`esp32_strapping`.

**Esquemático**

.. image:: ../../img/circuit/circuit_5.5_pir.png

Cuando el módulo PIR detecta movimiento, IO14 se activará, y el LED se encenderá. De lo contrario, cuando no se detecta movimiento, IO14 estará en bajo, y el LED se apagará.

.. note::
    El módulo PIR tiene dos potenciómetros: uno ajusta la sensibilidad, el otro ajusta la distancia de detección. Para hacer que el módulo PIR funcione mejor, necesitas girar ambos en sentido antihorario hasta el final.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**Cableado**

.. image:: ../../img/wiring/5.5_pir_bb.png

**Código**

.. note::

    * Puedes abrir el archivo ``5.5_pir.ino`` en la ruta ``esp32-starter-kit-main\c\codes\5.5_pir``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`  

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b5f0cc8-b732-4ed2-b68e-bb7d0a73a1b8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de haber subido el código con éxito, el LED se encenderá y luego se apagará cuando el módulo PIR detecte a alguien pasando.

.. note::
    El módulo PIR tiene dos potenciómetros: uno ajusta la sensibilidad, el otro ajusta la distancia de detección. Para hacer que el módulo PIR funcione mejor, necesitas girar ambos en sentido antihorario hasta el final.

    .. image:: img/pir_back.png
