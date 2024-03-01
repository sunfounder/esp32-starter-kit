.. _sh_low_temperature:

2.6 Alarma de Baja Temperatura
==================================

En este proyecto, haremos un sistema de alarma de baja temperatura, cuando la temperatura esté por debajo del umbral, el sprite **Copito de Nieve** aparecerá en el escenario.

.. image:: img/9_tem.png

Componentes necesarios
------------------------

En este proyecto, necesitamos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - Kit de inicio ESP32
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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

Lo que aprenderás
---------------------

- Principio de funcionamiento del termistor
- Operaciones multivariables y sustractivas

Construir el circuito
-----------------------

Un termistor es un tipo de resistencia cuya resistencia depende fuertemente de la temperatura, más que en las resistencias estándar, y hay dos tipos de resistencias, PTC (la resistencia aumenta a medida que aumenta la temperatura) y PTC (la resistencia disminuye a medida que aumenta la temperatura).

Construye el circuito según el siguiente diagrama.

Un extremo del termistor está conectado a GND, el otro extremo está conectado al pin35, y una resistencia de 10K está conectada en serie a 5V.

Aquí se utiliza el termistor NTC, así que cuando la temperatura sube, la resistencia del termistor disminuye, la división de voltaje del pin35 disminuye, y el valor obtenido del pin35 disminuye, y viceversa aumenta.

.. image:: img/circuit/7_low_temp_bb.png

Programación
------------------

**1. Seleccionar un sprite**

Elimina el sprite predeterminado, haz clic en el botón **Elegir un Sprite** en la esquina inferior derecha del área de sprites, introduce **Copito de Nieve** en la caja de búsqueda y luego haz clic para añadirlo.

.. image:: img/9_snow.png

**2. Crear 2 variables**

Crea dos variables, **antes** y **actual**, para almacenar el valor del pin35 en diferentes casos.

.. image:: img/9_va.png

**3. Leer el valor del pin35**

Cuando se hace clic en la bandera verde, se lee y almacena el valor del pin35 en la variable **antes**.

.. image:: img/9_before.png

**4. Leer nuevamente el valor del pin35**

En [siempre], lee nuevamente el valor del pin35 y almacénalo en la variable **actual**.

.. image:: img/9_current.png

**5. Determinar los cambios de temperatura**

Usando el bloque [si sino], determina si el valor actual del pin35 es 200 mayor que el anterior, lo que representa una disminución de la temperatura. En este punto, deja que el sprite **Copito de Nieve** se muestre, de lo contrario, ocúltalo.

* [-] y [>]: operadores de sustracción y comparación de la paleta **Operadores**.

.. image:: img/9_show.png
