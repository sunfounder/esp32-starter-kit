.. _format_sd_card:

¿Cómo formatear la tarjeta SD?
====================================

Los pasos para asegurar que tu tarjeta SD esté formateada correctamente pueden variar dependiendo de tu sistema operativo. Aquí te mostramos pasos sencillos sobre cómo formatear una tarjeta SD en Windows, MacOS y Linux:

**Windows**

   #. Inserta tu tarjeta SD en el ordenador, luego abre "Mi PC" o "Este Equipo". Haz clic derecho en tu tarjeta SD y selecciona "Formatear".

        .. image:: img/sd_format_win1.png

   #. En el menú desplegable de sistema de archivos, selecciona el sistema de archivos deseado (usualmente elige FAT32, o para tarjetas SD mayores de 32GB, podrías necesitar elegir exFAT). Marca "Formato rápido" y luego haz clic en "Iniciar".

        .. image:: img/sd_format_win2.png

**MacOS**
   
   #. Inserta tu tarjeta SD en el ordenador. Abre la aplicación "Utilidad de Discos" (se puede encontrar en la carpeta "Utilidades").

        .. image:: img/sd_format_mac1.png
    
   #. Selecciona tu tarjeta SD de la lista a la izquierda y luego haz clic en "Borrar".

        .. image:: img/sd_format_mac2.png

   #. Del menú desplegable de formato, elige tu sistema de archivos deseado (usualmente elige MS-DOS (FAT) para FAT32, o ExFAT para tarjetas SD mayores de 32GB) y luego haz clic en "Borrar".

        .. image:: img/sd_format_mac3.png

   #. Finalmente, espera a que se complete el formateo.

        .. image:: img/sd_format_mac3.png

**Linux**

   * Primero, inserta tu tarjeta SD y luego abre una terminal.
   * Escribe ``lsblk`` y encuentra el nombre de tu tarjeta SD en la lista de dispositivos (por ejemplo, podría ser ``sdb``).
   * Usa el comando ``umount`` para desmontar la tarjeta SD, como ``sudo umount /dev/sdb*``.
   * Usa el comando ``mkfs`` para formatear la tarjeta SD. Por ejemplo, ``sudo mkfs.vfat /dev/sdb1`` formateará la tarjeta SD a un sistema de archivos FAT32 (para tarjetas SD mayores de 32GB, podrías necesitar usar ``mkfs.exfat``).

Antes de formatear tu tarjeta SD, asegúrate de respaldar cualquier dato importante en la tarjeta SD, ya que la operación de formateo borrará todos los archivos en la tarjeta SD.
