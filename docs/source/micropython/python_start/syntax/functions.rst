.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

Funciones
==============

En MicroPython, una función es un grupo de declaraciones relacionadas que realizan una tarea específica.

Las funciones ayudan a descomponer nuestro programa en bloques modulares más pequeños. A medida que nuestro proyecto se hace más grande, las funciones lo hacen más organizado y manejable.

Además, evitan la duplicación y hacen que el código sea reutilizable.

Crear una Función
--------------------

.. code-block::

    def function_name（parameters)：
        """docstring"""
        statement(s)

* Una función se define usando la palabra clave ``def``.

* Un nombre de función para identificarla de manera única. La nomenclatura de funciones es la misma que la de las variables, y ambas siguen las siguientes reglas.
    
   * Solo pueden contener números, letras y guiones bajos.
   * El primer carácter debe ser una letra o un guión bajo.
   * Sensible a mayúsculas y minúsculas.

* Parámetros (argumentos) a través de los cuales pasamos valores a la función. Son opcionales.

* El dos puntos (:) marca el final del encabezado de la función.

* Docstring opcional, utilizado para describir la función de la función. Usualmente utilizamos comillas triples para que el docstring pueda extenderse a múltiples líneas.

* Una o más declaraciones válidas de Micropython que conforman el cuerpo de la función. Las declaraciones deben tener el mismo nivel de indentación (generalmente 4 espacios).

* Cada función necesita al menos una declaración, pero si por alguna razón hay una función que no contiene ninguna declaración, por favor, inserte la declaración pass para evitar errores.

* Una declaración ``return`` opcional para devolver un valor de la función.

Llamar a una Función
-----------------------

Para llamar a una función, añade paréntesis después del nombre de la función.



.. code-block:: python

    def my_function():
        print("Your first function")

    my_function()

>>> %Run -c $EDITOR_CONTENT
Your first function

La declaración return
-----------------------

La declaración return se utiliza para salir de una función y volver al lugar donde fue llamada.

**Sintaxis de return**

.. code-block:: python

    return [expression_list]

La declaración puede contener una expresión que se evalúa y devuelve un valor. Si no hay una expresión en la declaración, o la declaración ``return`` en sí misma no existe en la función, la función devolverá un objeto ``None``.



.. code-block:: python

    def my_function():
            print("Your first function")

    print(my_function())

>>> %Run -c $EDITOR_CONTENT
Your first function
None

Aquí, ``None`` es el valor de retorno, porque la declaración ``return`` no se utilizó.

Argumentos
-------------

La información puede pasarse a la función como argumentos.

Especifica argumentos entre paréntesis después del nombre de la función. Puedes añadir tantos argumentos como necesites, solo sepáralos con comas.



.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!


Número de Argumentos
*************************

Por defecto, una función debe ser llamada con el número correcto de argumentos. Esto significa que si tu función espera 2 parámetros, tienes que llamar a la función con 2 argumentos, ni más ni menos.



.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

Aquí, la función ``welcome()`` tiene 2 parámetros.

Dado que llamamos a esta función con dos argumentos, la función funciona sin problemas sin errores.

Si se llama con un número diferente de argumentos, el intérprete mostrará un mensaje de error.

A continuación, se muestra la llamada a esta función, que contiene uno y ningún argumento y sus respectivos mensajes de error.

.. code-block::

    welcome("Lily")＃Only one argument

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 1 were given

.. code-block::

    welcome()＃No arguments

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 0 were given


Argumentos por Defecto
*************************

En MicroPython, podemos usar el operador de asignación (=) para proporcionar un valor por defecto para el parámetro.

Si llamamos a la función sin argumento, utiliza el valor por defecto.



.. code-block:: python

    def welcome(name, msg = "Welcome to China!"):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)
    welcome("Lily")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!

En esta función, el parámetro ``name`` no tiene un valor por defecto y es requerido (obligatorio) durante la llamada.

Por otro lado, el valor por defecto del parámetro ``msg`` es "¡Bienvenido a China!". Por lo tanto, es opcional durante la llamada. Si se proporciona un valor, sobrescribirá el valor por defecto.

Cualquier número de argumentos en la función puede tener un valor por defecto. Sin embargo, una vez que hay un argumento por defecto, todos los argumentos a su derecha también deben tener valores por defecto.

Esto significa que los argumentos no por defecto no pueden seguir a los argumentos por defecto.

Por ejemplo, si definimos el encabezado de la función anterior como:

.. code-block:: python

    def welcome(name = "Lily", msg):

We will receive the following error message:

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
SyntaxError: non-default argument follows default argument


Argumentos de Palabra Clave
*******************************

Cuando llamamos a una función con ciertos valores, estos valores se asignarán a los argumentos basándose en su posición.

Por ejemplo, en la función ``welcome()`` anterior, cuando la llamamos como bienvenida("Lily", "¡Bienvenido a China!"), el valor "Lily" se asigna al ``nombre`` y de manera similar "¡Bienvenido a China!" al parámetro ``msg``.

MicroPython permite llamar a funciones con argumentos de palabra clave. Cuando llamamos a la función de esta manera, el orden (posición) de los argumentos puede cambiarse.

.. code-block:: python

    # keyword arguments
    welcome(name = "Lily",msg = "Welcome to China!")

    # keyword arguments (out of order)
    welcome(msg = "Welcome to China！",name = "Lily") 

    # 1 argumento posicional, 1 argumento de palabra clave
    bienvenida("Lily", msg = "¡Bienvenido a China!")

Como podemos ver, podemos mezclar argumentos posicionales y argumentos de palabra clave durante las llamadas a funciones. Pero debemos recordar que los argumentos de palabra clave deben venir después de los argumentos posicionales.

Tener un argumento posicional después de un argumento de palabra clave resultará en un error.

Por ejemplo, si la llamada a la función es como sigue:

.. code-block:: python

    bienvenida(nombre="Lily", "¡Bienvenido a China!")

Resultará en un error:

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 5, in <module>
SyntaxError: arg no-keyword después de arg keyword


Argumentos Arbitrarios
*************************

A veces, si no sabes el número de argumentos que se pasarán a la función de antemano.

En la definición de la función, podemos añadir un asterisco (*) antes del nombre del parámetro.



.. code-block:: python

    def welcome(*names):
        """This function welcomes all the person
        in the name tuple"""
        #names is a tuple with arguments
        for name in names:
            print("Welcome to China!", name)
            
    welcome("Lily","John","Wendy")

>>> %Run -c $EDITOR_CONTENT
Welcome to China! Lily
Welcome to China! John
Welcome to China! Wendy

Aquí, hemos llamado a la función con múltiples argumentos. Estos argumentos se empaquetan en una tupla antes de ser pasados a la función.

Dentro de la función, usamos un bucle for para recuperar todos los argumentos.

Recursión
----------------
En Python, sabemos que una función puede llamar a otras funciones. Incluso es posible que la función se llame a sí misma. A este tipo de construcciones se les denomina funciones recursivas.

Esto tiene la ventaja de significar que puedes iterar a través de los datos para alcanzar un resultado.

El desarrollador debe ser muy cuidadoso con la recursión ya que puede ser bastante fácil caer en la escritura de una función que nunca termina, o una que usa cantidades excesivas de memoria o potencia del procesador. Sin embargo, cuando se escribe correctamente, la recursión puede ser un enfoque muy eficiente y matemáticamente elegante para la programación.

.. code-block:: python

    def rec_func(i):
        if(i > 0):
            result = i + rec_func(i - 1)
            print(result)
        else:
            result = 0
        return result

    rec_func(6)

>>> %Run -c $EDITOR_CONTENT
1
3
6
10
15
21

En este ejemplo, ``rec_func()`` es una función que hemos definido para llamarse a sí misma ("recursión"). Utilizamos la variable ``i`` como los datos, y se decrementará (-1) cada vez que recursamos. Cuando la condición no es mayor que 0 (es decir, 0), la recursión termina.

Para los desarrolladores nuevos, puede tomar algún tiempo determinar cómo funciona, y la mejor manera de probarlo es experimentar y modificarlo.

**Ventajas de la Recursión**

* Las funciones recursivas hacen que el código se vea limpio y elegante.
* Una tarea compleja puede desglosarse en subproblemas más simples usando recursión.
* La generación de secuencias es más fácil con la recursión que usando alguna iteración anidada.

**Desventajas de la Recursión**

* A veces, la lógica detrás de la recursión es difícil de seguir.
* Las llamadas recursivas son costosas (ineficientes) ya que ocupan mucha memoria y tiempo.
* Las funciones recursivas son difíciles de depurar.
