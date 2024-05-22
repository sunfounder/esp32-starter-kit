.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

Variables
==========
Las variables son contenedores utilizados para almacenar valores de datos.

Crear una variable es muy sencillo. Solo necesitas nombrarla y asignarle un valor. No es necesario especificar el tipo de dato de la variable al asignarla, porque la variable es una referencia y accede a objetos de diferentes tipos de datos mediante la asignación.

El nombramiento de variables debe seguir las siguientes reglas:

* Los nombres de variables solo pueden contener números, letras y guiones bajos
* El primer carácter del nombre de la variable debe ser una letra o un guion bajo
* Los nombres de las variables distinguen entre mayúsculas y minúsculas

Crear Variable
------------------
No hay un comando para declarar variables en MicroPython. Las variables se crean cuando se les asigna un valor por primera vez. No es necesario utilizar ningún tipo de declaración específica, e incluso puedes cambiar el tipo después de establecer la variable.



.. code-block:: python

    x = 8       # x is of type int
    x = "lily" # x is now of type str
    print(x)

>>> %Run -c $EDITOR_CONTENT
lily


Casting
-------------
Si deseas especificar el tipo de dato para la variable, puedes hacerlo mediante el casting.



.. code-block:: python

    x = int(5)    # y will be 5
    y = str(5)    # x will be '5'
    z = float(5)  # z will be 5.0
    print(x,y,z)

>>> %Run -c $EDITOR_CONTENT
5 5 5.0

Obtener el Tipo
-------------------
Puedes obtener el tipo de dato de una variable con la función ``type()``.



.. code-block:: python

    x = 5
    y = "hello"
    z = 5.0
    print(type(x),type(y),type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'int'> <class 'str'> <class 'float'>

¿Comillas simples o dobles?
------------------------------

En MicroPython, se pueden usar comillas simples o dobles para definir variables de cadena.



.. code-block:: python

    x = "hello"
    # is the same as
    x = 'hello'

Sensibilidad a Mayúsculas y Minúsculas
----------------------------------------------

Los nombres de las variables son sensibles a mayúsculas y minúsculas.



.. code-block:: python

    a = 5
    A = "lily"
    #A will not overwrite a
    print(a, A)

>>> %Run -c $EDITOR_CONTENT
5 lily


