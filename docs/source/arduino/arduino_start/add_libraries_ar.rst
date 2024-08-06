.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _add_libraries_ar:

1.4 Instalación de librerías (Importante)
===================================================

Una librería es una colección de código o funciones preescritas que amplían las capacidades del IDE de Arduino. Las librerías proporcionan código listo para usar en diversas funcionalidades, permitiéndote ahorrar tiempo y esfuerzo en la codificación de características complejas.

Existen dos maneras principales de instalar librerías:

Instalación desde el Gestor de Librerías
---------------------------------------------

Muchas librerías están disponibles directamente a través del Gestor de Librerías de Arduino. Puedes acceder al Gestor de Librerías siguiendo estos pasos:

#. En el **Gestor de Librerías**, puedes buscar la librería deseada por nombre o navegar a través de diferentes categorías.

   .. note::

      En proyectos donde se requiere la instalación de librerías, habrá indicaciones sobre qué librerías instalar. Sigue las instrucciones proporcionadas, como "Se utiliza aquí la librería del sensor DHT, puedes instalarla desde el Gestor de Librerías." Simplemente instala las librerías recomendadas según se indica.

   .. image:: img/install_lib3.png

#. Una vez que encuentres la librería que deseas instalar, haz clic en ella y luego en el botón **Instalar**.

   .. image:: img/install_lib2.png

#. El IDE de Arduino descargará e instalará automáticamente la librería para ti.

.. _install_lib_man:

Instalación Manual
--------------------------

Algunas librerías no están disponibles a través del **Gestor de Librerías** y necesitan ser instaladas manualmente. Para instalar estas librerías, sigue estos pasos:


#. Abre el IDE de Arduino y ve a **Sketch** -> **Incluir Librería** -> **Añadir Librería .ZIP**.

   .. image:: img/a2dp_add_zip.png

#. Navega al directorio donde se encuentran los archivos de la librería, como la carpeta ``esp32-starter-kit\c\libraries``, y selecciona el archivo de librería deseado, como ``ESP32-A2DP.zip``. Luego, haz clic en **Abrir**.

   * :download:`SunFounder ESP32 Starter Kit <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`

   .. image:: img/a2dp_choose.png

#. Después de un corto tiempo, recibirás una notificación indicando una instalación exitosa.

   .. image:: img/a2dp_success.png

#. Repite el mismo proceso para añadir la librería ``ESP8266Audio.zip``.


.. note::

   Las librerías instaladas usando cualquiera de los métodos anteriores se pueden encontrar en el directorio de librerías predeterminado del IDE de Arduino, que generalmente está ubicado en ``C:\Usuarios\xxx\Documentos\Arduino\libraries``.

   Si tu directorio de librerías es diferente, puedes verificarlo yendo a **Archivo** -> **Preferencias**.

      .. image:: img/install_lib1.png
