.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_lcd:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND**: Tierra
* **VCC**: Suministro de voltaje, 5V.
* **SDA**: Línea de datos serial. Conectar a VCC a través de una resistencia pull-up.
* **SCL**: Línea de reloj serial. Conectar a VCC a través de una resistencia pull-up.

Como todos sabemos, aunque las pantallas LCD y algunas otras pantallas enriquecen enormemente la interacción hombre-máquina, comparten una debilidad común. Cuando están conectadas a un controlador, múltiples E/S serán ocupadas del controlador que no tiene tantos puertos externos. También restringe otras funciones del controlador.

Por lo tanto, se desarrolla el LCD1602 con un módulo I2C para resolver el problema. El módulo I2C tiene un chip PCF8574 I2C incorporado que convierte los datos seriales I2C en datos paralelos para la pantalla LCD.

* `Hoja de datos de PCF8574 <https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204&ref_url=https%253A%252F%252Fwww.google.com%252F>`_

**Dirección I2C**

La dirección predeterminada es básicamente 0x27, en algunos casos puede ser 0x3F.

Tomando la dirección predeterminada de 0x27 como ejemplo, la dirección del dispositivo se puede modificar cortocircuitando las almohadillas A0/A1/A2; en el estado predeterminado, A0/A1/A2 es 1, y si la almohadilla está cortocircuitada, A0/A1/A2 es 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Retroiluminación/Contraste**

La retroiluminación se puede habilitar mediante un puente, desconecte el puente para deshabilitar la retroiluminación. El potenciómetro azul en la parte posterior se utiliza para ajustar el contraste (la relación de brillo entre el blanco más brillante y el negro más oscuro).


.. image:: img/back_lcd1602.jpg

* **Puente Cortocircuitado**: La retroiluminación se puede habilitar mediante este puente, desenchufando este puente se deshabilita la retroiluminación.
* **Potenciómetro**: Se utiliza para ajustar el contraste (la claridad del texto mostrado), que se aumenta en dirección de las agujas del reloj y se disminuye en dirección contraria a las agujas del reloj.


**Ejemplo**

* :ref:`ar_lcd1602` (Proyecto Arduino)
* :ref:`ar_guess_number` (Proyecto Arduino)
* :ref:`py_lcd1602` (Proyecto MicroPython)
* :ref:`py_guess_number` (Proyecto MicroPython)


