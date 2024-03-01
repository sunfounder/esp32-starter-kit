.. _add_libraries_py:

1.4 Subir las Bibliotecas (Importante)
======================================

En algunos proyectos, necesitarás bibliotecas adicionales. Así que aquí subimos estas bibliotecas al ESP32 primero, y luego podemos ejecutar el código directamente después.

#. Descarga el código relevante desde el enlace a continuación.


   * :download:`Kit de inicio ESP32 de SunFounder <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`

#. Conecta el ESP32 WROOM 32E a tu computadora usando un cable Micro USB.

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Abre Thonny IDE y haz clic en el intérprete "MicroPython (ESP32).COMXX" en la esquina inferior derecha.

    .. image:: img/sec_inter.png

#. En la barra de navegación superior, haz clic en **Ver** -> **Archivos**.

    .. image:: img/th_files.png

#. Cambia la ruta a la carpeta donde descargaste el `paquete de código <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`_ antes, y luego ve a la carpeta ``esp32-starter-kit-main\micropython\libs``.

    .. image:: img/th_path.png

#. Selecciona todos los archivos o carpetas en la carpeta ``libs/``, haz clic derecho y haz clic en **Subir a**, tomará un tiempo subir.

    .. image:: img/th_upload.png

#. Ahora verás los archivos que acabas de subir dentro de tu unidad ``Dispositivo MicroPython``.

    .. image:: img/th_done.png
