.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_sd_write:

7.4 Escritura y Lectura de Tarjeta SD
=================================================
Este proyecto demuestra las capacidades esenciales de usar una tarjeta SD con el microcontrolador ESP32.
Muestra operaciones fundamentales como montar la tarjeta SD, crear un archivo, escribir datos en el archivo,
y listar todos los archivos dentro del directorio raíz. Estas operaciones forman la base de muchas aplicaciones de registro y almacenamiento de datos, haciendo de este proyecto un pilar crucial en la comprensión y utilización del periférico SDMMC host integrado del ESP32.

**Componentes Requeridos**

En este proyecto, necesitamos los siguientes componentes.

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

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|


**Pasos Operativos**

#. Antes de conectar el cable USB, inserta la tarjeta SD en la ranura de la tarjeta SD de la placa de extensión.

    .. image:: ../../img/insert_sd.png

#. Conecta ESP32-WROOM-32E al ordenador usando el cable USB.

    .. image:: ../../img/plugin_esp32.png

#. Selecciona el puerto y la placa adecuados en el IDE de Arduino y sube el código a tu ESP32.

    .. note::

        * Abre el archivo ``7.4_sd_read_write.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\7.4_sd_read_write``.
        * Después de seleccionar la placa (ESP32 Dev Module) y el puerto adecuado, haz clic en el botón **Subir**.
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/912df4b8-a7b6-43dc-95b5-8206801cc9c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Una vez subido el código con éxito, verás un mensaje indicando la escritura de archivo exitosa, junto con una lista de todos los nombres de archivos y tamaños en la tarjeta SD. Si no ves ningún mensaje después de abrir el monitor serie, necesitas presionar el botón EN (RST) para volver a ejecutar el código.

    .. image:: img/sd_write_read.png

    .. note::

        Si ves la siguiente información.

        .. code-block::

            E (528) vfs_fat_sdmmc: mount_to_vfs failed (0xffffffff).
            Failed to mount SD card

        Primero, verifica si tu tarjeta SD está correctamente insertada en la placa de extensión.

        Si está insertada correctamente, podría haber un problema con tu tarjeta SD. Puedes intentar usar una goma de borrar para limpiar los contactos metálicos.

        Si el problema persiste, se recomienda formatear la tarjeta SD, consulta :ref:`format_sd_card`.


**Cómo funciona?**

El propósito de este proyecto es demostrar el uso de la tarjeta SD con la placa ESP32. Se utiliza el periférico SDMMC host integrado del ESP32 para conectarse con la tarjeta SD.

El proyecto comienza inicializando la comunicación serie y luego intenta montar la tarjeta SD. Si la tarjeta SD no se monta con éxito, el programa imprimirá un mensaje de error y saldrá de la función de configuración.

Una vez que la tarjeta SD se monta con éxito, el programa procede a crear un archivo llamado "test.txt" en el directorio raíz de la tarjeta SD. Si el archivo se abre con éxito en modo de escritura, el programa escribe una línea de texto - "Hello, world!" en el archivo. El programa imprimirá un mensaje de éxito si la operación de escritura es exitosa, de lo contrario, se imprimirá un mensaje de error.

Después de la operación de escritura, el programa cierra el archivo y luego abre el directorio raíz de la tarjeta SD. Comienza a recorrer todos los archivos en el directorio raíz, imprimiendo el nombre y el tamaño del archivo de cada archivo encontrado.

En la función de bucle principal, no hay operaciones. Este proyecto se centra en operaciones de tarjeta SD como montar la tarjeta, crear un archivo, escribir en un archivo y leer el directorio del archivo, todas las cuales se ejecutan en la función de configuración.

Este proyecto sirve como una útil introducción al manejo de tarjetas SD con el ESP32, lo cual puede ser crucial en aplicaciones que requieren registro o almacenamiento de datos.


Aquí hay un análisis del código:

#. Incluye la biblioteca ``SD_MMC``, que es necesaria para trabajar con tarjetas SD usando el periférico SDMMC host integrado del ESP32.

    .. code-block:: arduino

        #include "SD_MMC.h"

#. Dentro de la función ``setup()``, se realizan las siguientes tareas.

    * **Inicializar la tarjeta SD**

    Inicializa y monta la tarjeta SD. Si la tarjeta SD no se monta, imprimirá "Failed to mount SD card" en el monitor serie y detendrá la ejecución.

    .. code-block:: arduino
        
        if(!SD_MMC.begin()) { // Intenta montar la tarjeta SD
            Serial.println("Failed to mount card"); // Si el montaje falla, imprime en serie y sale de la configuración
            return;
        } 
      
    * **Abrir el archivo**

    Abre un archivo llamado ``"test.txt"`` ubicado en el directorio raíz de la tarjeta SD en modo de escritura. Si el archivo no se abre, imprime "Failed to open file for writing" y regresa.

    .. code-block:: arduino

        File file = SD_MMC.open("/test.txt", FILE_WRITE); 
        if (!file) {
            Serial.println("Failed to open file for writing"); // Print error message if file failed to open
            return;
        }


    * **Escribir datos en el archivo**

    Escribe el texto "Test file write" en el archivo. 
    Si la operación de escritura es exitosa, imprime "File write successful"; de lo contrario, imprime "File write failed".

    
    .. code-block:: arduino

        if(file.print("Test file write")) { // Write the message to the file
            Serial.println("File write success"); // If write succeeds, print to serial
        } else {
            Serial.println("File write failed"); // If write fails, print to serial
        } 

    * **Cerrar el archivo**
        
    Cierra el archivo abierto. Esto asegura que cualquier dato almacenado en el búfer se escriba en el archivo y que el archivo se cierre correctamente.

    .. code-block:: arduino

        file.close(); // Close the file

    * **Abrir el directorio raíz**

    Abre el directorio raíz de la tarjeta SD. Si el directorio no se abre, imprime "Failed to open directory" y regresa.

    .. code-block:: arduino

        File root = SD_MMC.open("/"); // Open the root directory of SD card
        if (!root) {
            Serial.println("Failed to open directory"); // Print error message if directory failed to open
            return;
        }

    * **Imprimir el nombre y tamaño de cada archivo**
    
    El bucle que comienza con while (``File file = root.openNextFile()``) itera sobre todos los archivos en el directorio raíz, 
    imprimiendo el nombre y el tamaño de cada archivo en el monitor serie.

    .. code-block:: arduino
    
        Serial.println("Files found in root directory:"); // Print the list of files found in the root directory
        while (File file = root.openNextFile()) { // Loop through all the files in the root directory
              Serial.print("  ");
              Serial.print(file.name()); // Print the filename
              Serial.print("\t");
              Serial.println(file.size()); // Print the filesize
              file.close(); // Close the file
        }

#.  Esta función ``loop()`` es un bucle vacío y no hace nada en el programa actual. Sin embargo, en un programa típico de Arduino, esta función repetiría continuamente y ejecutaría el código dentro de ella. En este caso, ya que todas las tareas requeridas se han realizado en la función de configuración, la función de bucle no es necesaria.

    .. code-block:: arduino

        void loop() {} // Empty loop function, does nothing
