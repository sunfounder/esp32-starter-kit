.. _ar_transistor:

5.6 Dos Tipos de Transistores
==========================================
Este kit viene equipado con dos tipos de transistores, S8550 y S8050, siendo el primero PNP y el segundo NPN. Aunque se parecen mucho, necesitamos examinar cuidadosamente para ver sus etiquetas.
Cuando una señal de nivel Alto pasa a través de un transistor NPN, este se activa. Pero uno PNP necesita una señal de nivel Bajo para activarse. Ambos tipos de transistores se usan frecuentemente para interruptores sin contacto, como en este experimento.

¡Vamos a usar un LED y un botón para entender cómo usar un transistor!

**Componentes Necesarios**

Para este proyecto necesitamos los siguientes componentes.

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

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Pines Disponibles**

* **Pines Disponibles**

    Aquí hay una lista de pines disponibles en la placa ESP32 para este proyecto.

    .. list-table::
        :widths: 5 20

        *   - Para Entrada
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Para Salida
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

* **Pines de Uso Condicional (Entrada)**

    Los siguientes pines tienen resistencias de pull-up o pull-down incorporadas, por lo que no se requieren resistencias externas cuando **se utilizan como pines de entrada**:

    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Pines de Uso Condicional
            - Descripción
        *   - IO13, IO15, IO2, IO4
            - Pull-up con una resistencia de 47K por defecto el valor es alto.
        *   - IO27, IO26, IO33
            - Pull-up con una resistencia de 4.7K por defecto el valor es alto.
        *   - IO32
            - Pull-down con una resistencia de 1K por defecto el valor es bajo.

* **Pines de Configuración (Entrada)**

    Los pines de configuración son un conjunto especial de pines que se utilizan para determinar modos de arranque específicos durante el inicio del dispositivo 
    (es decir, reinicio por encendido).

    .. list-table::
        :widths: 5 15

        *   - Pines de Configuración
            - IO5, IO0, IO2, IO12, IO15 

    Generalmente, **no se recomienda usarlos como pines de entrada**. Si deseas utilizar estos pines, considera el impacto potencial en el proceso de arranque. Para más detalles, por favor consulta la sección :ref:`esp32_strapping`.

**Cómo Conectar el Transistor NPN (S8050)**

.. image:: ../../img/circuit/circuit_5.6_S8050.png

En este circuito, cuando se presiona el botón, IO14 está en alto.

Programando IO26 para que emita **alto**, tras una resistencia limitadora de corriente de 1k (para proteger el transistor), se permite que el S8050 (transistor NPN) conduzca, permitiendo así que el LED se ilumine.

.. image:: ../../img/wiring/5.6_s8050_bb.png

**Cómo Conectar el Transistor PNP(S8550)**

.. image:: ../../img/circuit/circuit_5.6_S8550.png

En este circuito, IO14 está en bajo por defecto y cambiará a alto cuando se presione el botón.

Programando IO26 para que emita **bajo**, tras una resistencia limitadora de corriente de 1k (para proteger el transistor), se permite que el S8550 (transistor PNP) conduzca, permitiendo así que el LED se ilumine.

La única diferencia que notarás entre este circuito y el anterior es que en el circuito anterior el cátodo del LED está conectado al **colector** del **S8050 (transistor NPN)**, mientras que en este está conectado al **emisor** del **S8550 (transistor PNP)**.

.. image:: ../../img/wiring/5.6_s8550_bb.png

**Código**

.. note::

    * Puedes abrir el archivo ``5.6_transistor.ino`` en la ruta ``esp32-starter-kit-main\c\codes\5.6_transistor``. 
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto apropiado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/3ab778b4-642d-4a5d-8b71-05bc089389e5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Se pueden controlar dos tipos de transistores utilizando el mismo código. 
Cuando presionamos el botón, el ESP32 enviará una señal de alto nivel al transistor; 
cuando lo soltemos, enviará una señal de bajo nivel.

* El circuito que utiliza el S8050 (transistor NPN) se iluminará al presionar el botón, indicando que se encuentra en un estado de conducción de alto nivel;
* El circuito que utiliza el S8550 (transistor PNP) se iluminará al soltar el botón, indicando que se encuentra en un estado de conducción de bajo nivel.
