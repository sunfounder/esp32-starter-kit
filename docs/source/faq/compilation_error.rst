¿Algunos códigos de proyecto no se compilan?
===============================================

Q1: ``'ledcAttach' was not declared in this scope``
-----------------------------------------------------

Al usar LEDs, RGB LEDs o zumbadores pasivos, necesitarás el periférico |link_ledc| de la placa ESP32 para generar señales PWM. Sin embargo, la placa ESP32 se actualizó recientemente a la versión 3.0, lo que causó cambios en los nombres de las funciones y el uso dentro del periférico |link_ledc|.

Por lo tanto, hemos actualizado nuestro código en consecuencia. Si encuentras problemas relacionados con ledc durante la compilación, actualiza tu placa ESP32 a la versión 3.0 o superior.

.. image:: img/version_3.0.3.png


Q2: ¿Errores en proyectos relacionados con Bluetooth y receptor IR después de actualizar ESP32 a la versión 3.0?
-----------------------------------------------------------------------------------------------------------------------

La placa ESP32 se ha actualizado a la versión 3.0, pero las bibliotecas utilizadas en proyectos relacionados con Bluetooth y receptor IR aún no son compatibles con la versión 3.0.

Para ejecutar estos proyectos, se recomienda degradar temporalmente la versión de ESP32 a 2.0, específicamente la versión 2.0.17.

Monitorizaremos continuamente las actualizaciones de estas bibliotecas, y una vez que sean compatibles con la versión 3.0 de ESP32, actualizaremos rápidamente nuestro código y documentación.

.. image:: img/version_2.0.17.png

.. _download_mode:

P3: Error “Wrong boot mode detected (0x13)” al flashear el firmware de ESP32
--------------------------------------------------------------------------------------

Al flashear el firmware del ESP32 con Thonny o al subir código al ESP32 usando el IDE de Arduino, puedes encontrarte con el siguiente error:

.. code-block:: text

    A fatal error occurred: Failed to connect to ESP32: Wrong boot mode detected (0x13)! The chip needs to be in download mode.

Este error **no indica** un problema de hardware con tu placa ESP32.  
Este problema puede ocurrir cuando el ordenador no logra poner automáticamente el ESP32 en **modo de descarga** durante el proceso de flasheo.

**Causa**

El ESP32 debe estar en **modo de descarga** para poder flashear el firmware correctamente.  
En algunos entornos, el disparador automático del modo de descarga puede no funcionar como se espera debido a diferencias de sincronización en los controladores USB, el comportamiento del puerto USB o la forma en que el sistema operativo maneja las señales DTR/RTS.  
Como resultado, el ESP32 permanece en modo de ejecución normal, provocando que el flasheo falle.

**Solución**

Si te encuentras con este error, puedes ingresar manualmente al modo de descarga antes de flashear:

* **Usando botones (BOOT + EN/RST):**  
  Mantén presionado el botón ``BOOT``, luego presiona brevemente ``EN`` (o ``RST``), y finalmente suelta ``BOOT``.  
  Esto fuerza al ESP32 a entrar en modo de descarga.

* **Usando un cable jumper:**  
  Conecta ``GPIO0`` a ``GND`` con un jumper, luego presiona ``EN`` (o reinicia la placa) para entrar en modo de descarga.  
  Después del flasheo, retira el jumper para permitir un arranque normal.

**Notas**

* Asegúrate de usar un **cable de datos** adecuado (no solo de carga).  
* Si el problema persiste, intenta cambiar de puerto USB, actualizar el controlador USB a serie o reducir la velocidad en baudios (por ejemplo, ``115200``).
