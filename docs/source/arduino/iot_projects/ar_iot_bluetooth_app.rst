.. _iot_bluetooth_app:

8.10 Aplicación Android - Operación de LED RGB mediante Arduino y Bluetooth
===============================================================================

El objetivo de este proyecto es desarrollar una aplicación Android capaz de manipular el tono de un LED RGB a través de un smartphone utilizando tecnología Bluetooth.

Esta aplicación Android se construirá utilizando una plataforma web complementaria conocida como MIT App Inventor 2. El proyecto presenta una excelente oportunidad para familiarizarse con la interfaz de un Arduino con un smartphone.

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../../_static/video/10_ble_app.mp4" type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>

**Componentes Requeridos**

Para este proyecto, necesitaremos los siguientes componentes.

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

    *   - INTRODUCCIÓN AL COMPONENTE
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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**1. Creación de la Aplicación Android**

La aplicación Android se diseñará utilizando una aplicación web gratuita conocida como |link_appinventor|.
MIT App Inventor sirve como un excelente punto de partida para el desarrollo de Android, gracias a sus intuitivas características de arrastrar y soltar que permiten la creación de aplicaciones sencillas.

Ahora, comencemos.

#. Aquí está la página de inicio de sesión: http://ai2.appinventor.mit.edu. Necesitarás una cuenta de Google para registrarte en MIT App Inventor.

#. Después de iniciar sesión, navega a **Proyectos** -> **Importar proyecto (.aia) desde mi computadora**. Posteriormente, sube el archivo ``control_rgb_led.aia`` ubicado en la ruta ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor``.

   .. image:: img/10_ble_app_inventor1.png

#. Al subir el archivo ``.aia``, verás la aplicación en el software **MIT App Inventor**. Esta es una plantilla preconfigurada. Puedes modificar esta plantilla después de haberte familiarizado con **MIT App Inventor** a través de los siguientes pasos.

   .. image:: img/10_ble_app_inventor2.png

#. En **MIT App Inventor**, tienes 2 secciones principales: el **Diseñador** y los **Bloques**.

   .. image:: img/10_ble_app_inventor3.png

#. El **Diseñador** te permite agregar botones, texto, pantallas y modificar la estética general de tu aplicación.

   .. image:: img/10_ble_app_inventor2.png


#. Posteriormente, tienes la sección de **Bloques**. La sección de **Bloques** facilita la creación de funciones a medida para tu aplicación.

   .. image:: img/10_ble_app_inventor5.png

#. Para instalar la aplicación en un smartphone, navega a la pestaña **Construir**.

   .. image:: img/10_ble_app_inventor6.png

   * Puedes generar un archivo ``.apk``. Después de seleccionar esta opción, aparecerá una página que te permitirá elegir entre descargar un archivo ``.apk`` o escanear un código QR para la instalación. Sigue la guía de instalación para completar la instalación de la aplicación.
   * Si deseas subir esta app a **Google Play** u otro mercado de aplicaciones, puedes generar un archivo ``.aab``.


**2. Subida del código**

#. Construye el circuito.

   .. image:: ../../components/img/rgb_pin.jpg
      :width: 200
      :align: center

   El LED RGB consta de 4 pines: el pin alargado es el pin cátodo común, típicamente conectado a GND; el pin a la izquierda del pin más largo representa el Rojo; y los dos pines a la derecha simbolizan el Verde y el Azul.

   .. image:: ../../img/wiring/2.3_color_light_bb.png

#. Posteriormente, conecta el ESP32-WROOM-32E a tu computadora utilizando un cable USB.

   .. image:: ../../img/plugin_esp32.png

#. Abre el archivo ``iot_10_bluetooth_app_inventor.ino`` situado en la carpeta ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor``, o copia el código en el IDE de Arduino.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/07622bb5-31eb-4a89-b6f2-085f3332051f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Tras seleccionar la placa adecuada (**ESP32 Dev Module**) y el puerto, haz clic en el botón **Subir**.

**3. Conexión de la App y ESP32**

Asegúrate de que la aplicación creada anteriormente esté instalada en tu smartphone.

#. Inicialmente, activa el **Bluetooth** en tu smartphone.

   .. image:: img/10_ble_mobile1.png
      :width: 500
      :align: center

#. Navega a los **Ajustes de Bluetooth** en tu smartphone y busca **ESP32RGB**.

   .. image:: img/10_ble_mobile2.png
      :width: 500
      :align: center

#. Tras hacer clic, acepta la solicitud de **Emparejamiento** en la ventana emergente.

   .. image:: img/10_ble_mobile3.png
      :width: 500
      :align: center

#. Ahora abre la aplicación **Control_RGB_LED** que acabas de instalar.

   .. image:: img/10_ble_mobile4.png
      :align: center

#. En la aplicación, haz clic en **Conectar Bluetooth** para establecer una conexión entre la aplicación y el ESP32.

   .. image:: img/10_ble_mobile5.png
      :width: 500
      :align: center

#. Selecciona el ``xx.xx.xx.xx.xx.xx ESP32RGB`` que aparezca. Si cambiaste ``SerialBT.begin("ESP32RGB");`` en el código, entonces selecciona el nombre que configuraste.

   .. image:: img/10_ble_mobile6.png
      :width: 500
      :align: center

#. Si has esperado un rato y aún no puedes ver ningún nombre de dispositivo, puede ser que esta aplicación no tenga permiso para escanear dispositivos cercanos. En este caso, necesitarás ajustar los ajustes manualmente.

   * Mantén presionado el icono de la aplicación y haz clic en **Información de la APP** que aparece. Si tienes otro método para acceder a esta página, síguelo.

      .. image:: img/10_ble_mobile8.png
         :width: 500
         :align: center

   * Navega a la página de **Permisos**.

      .. image:: img/10_ble_mobile9.png
         :width: 500
         :align: center

   * Localiza **Dispositivos cercanos**, y selecciona **Siempre** para permitir que esta aplicación escanee dispositivos cercanos.

      .. image:: img/10_ble_mobile10.png
         :width: 500
         :align: center

   * Ahora, reinicia la aplicación y repite los pasos 5 y 6 para conectarte exitosamente al Bluetooth.

#. Una vez establecida la conexión exitosamente, volverás automáticamente a la página principal, donde se mostrará como conectado. Ahora puedes ajustar los valores RGB y cambiar el color de la pantalla RGB presionando el botón **Cambiar Color**.

   .. image:: img/10_ble_mobile7.png
      :width: 500
      :align: center

