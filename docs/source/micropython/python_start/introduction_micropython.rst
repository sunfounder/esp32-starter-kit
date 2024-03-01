1.1 Introducción a MicroPython
======================================

MicroPython es una implementación de software de un lenguaje de programación ampliamente compatible con Python 3, escrito en C, que está optimizado para ejecutarse en un microcontrolador.[3][4]

MicroPython consta de un compilador de Python a bytecode y un intérprete en tiempo de ejecución de ese bytecode. El usuario se presenta con un prompt interactivo (el REPL) para ejecutar comandos compatibles inmediatamente. Incluye una selección de bibliotecas centrales de Python; MicroPython incluye módulos que brindan al programador acceso a hardware de bajo nivel.

* Referencia: `MicroPython - Wikipedia <https://en.wikipedia.org/wiki/MicroPython>`_

La Historia Comienza Aquí
--------------------------------

Las cosas cambiaron en 2013 cuando Damien George lanzó una campaña de crowdfunding (Kickstarter).

Damien era un estudiante de pregrado en la Universidad de Cambridge y un apasionado programador de robótica. Quería reducir el mundo de Python de una máquina de gigabytes a una de kilobytes. Su campaña de Kickstarter fue para apoyar su desarrollo mientras convertía su prueba de concepto en una implementación finalizada.

MicroPython está respaldado por una diversa comunidad de Pythonistas que tiene un gran interés en ver el proyecto tener éxito.

Aparte de probar y apoyar la base de código, los desarrolladores proporcionaron tutoriales, bibliotecas de código y portabilidad de hardware, por lo que Damien pudo enfocarse en otros aspectos del proyecto.

* Referencia: `realpython <https://realpython.com/micropython/>`_

¿Por qué MicroPython？
------------------------------

Aunque la campaña de Kickstarter original lanzó MicroPython como una placa de desarrollo "pyboard" con STM32F4, MicroPython admite muchas arquitecturas de productos basadas en ARM. Los puertos principales soportados son ARM Cortex-M (muchas placas STM32, TI CC3200/WiPy, placas Teensy, series Nordic nRF, SAMD21 y SAMD51), ESP8266, ESP32, PIC de 16 bits, Unix, Windows, Zephyr y JavaScript.
En segundo lugar, MicroPython permite una retroalimentación rápida. Esto se debe a que puedes usar REPL para ingresar comandos de manera interactiva y obtener respuestas. Incluso puedes ajustar el código y ejecutarlo inmediatamente en lugar de atravesar el ciclo de codificar-compilar-subir-ejecutar.

Mientras que Python tiene las mismas ventajas, para algunas placas de microcontroladores como el ESP32, son pequeñas, simples y tienen poca memoria para ejecutar el lenguaje Python en absoluto. Es por eso que MicroPython ha evolucionado, manteniendo las principales características de Python y agregando un montón de nuevas para trabajar con estas placas de microcontroladores.

A continuación, aprenderás a instalar MicroPython en el ESP32.

* Referencia: `MicroPython - Wikipedia <https://en.wikipedia.org/wiki/MicroPython>`_
* Referencia: `realpython <https://realpython.com/micropython/>`_

