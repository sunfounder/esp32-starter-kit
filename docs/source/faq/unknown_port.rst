.. _unknown_com_port:

¿Siempre aparece "COMxx desconocido"?
-------------------------------------------

Cuando conectas el ESP32 al ordenador, el IDE de Arduino a menudo muestra ``COMxx desconocido``. ¿Por qué sucede esto?

.. image:: img/unknown_device.png

Esto se debe a que el controlador USB del ESP32 es diferente al de las placas Arduino regulares. El IDE de Arduino no puede reconocer automáticamente esta placa.

En tal escenario, necesitas seleccionar manualmente la placa correcta siguiendo estos pasos:

#. Haz clic en **"Seleccionar otra placa y puerto"**.

    .. image:: img/unknown_select.png

#. En la búsqueda, escribe **"esp32 dev module"**, luego selecciona la placa que aparece. Después, selecciona el puerto correcto y haz clic en **OK**.

    .. image:: img/unknown_board.png

#. Ahora, deberías poder ver tu placa y puerto en esta ventana de vista rápida.

    .. image:: img/unknown_correct.png
