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