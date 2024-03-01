.. _cpn_transistor:

Transistor
============

.. image:: img/npn_pnp.png

El transistor es un dispositivo semiconductor que controla la corriente mediante corriente. Funciona amplificando una señal débil a una señal de mayor amplitud y también se utiliza como interruptor sin contacto.

Un transistor es una estructura de tres capas compuesta por semiconductores de tipo P y N. Internamente forman las tres regiones. La más delgada en el medio es la región de la base; las otras dos son ambas de tipo N o P: la región más pequeña con portadores de mayoría intensos es la región del emisor, mientras que la otra es la región del colector. Esta composición permite que el transistor sea un amplificador. 
De estas tres regiones se generan tres polos respectivamente, que son base (b), emisor (e) y colector (c). Forman dos uniones P-N, a saber, la unión del emisor y la unión de recolección. La dirección de la flecha en el símbolo del circuito del transistor indica la dirección de la unión del emisor.

* `Unión P-N - Wikipedia <https://es.wikipedia.org/wiki/Unión_p-n>`_

Según el tipo de semiconductor, los transistores se pueden dividir en dos grupos, los NPN y PNP. Por la abreviatura, podemos deducir que el primero está hecho de dos semiconductores de tipo N y uno de tipo P, y que el segundo es lo contrario. Consulte la siguiente figura. 

.. note::
    El s8550 es un transistor PNP y el s8050 es un transistor NPN, se parecen mucho, y debemos verificar cuidadosamente para ver sus etiquetas.

.. image:: img/transistor_symbol.png

Cuando una señal de nivel alto atraviesa un transistor NPN, se energiza. Pero uno PNP necesita una señal de nivel bajo para gestionarlo. Ambos tipos de transistores se utilizan con frecuencia para interruptores sin contacto, al igual que en este experimento.

* `Hoja de datos del transistor S8050 <https://components101.com/asset/sites/default/files/component_datasheet/S8050%20Transistor%20Datasheet.pdf>`_
* `Hoja de datos del transistor S8550 <https://www.mouser.com/datasheet/2/149/SS8550-118608.pdf>`_

Coloque el lado de la etiqueta hacia nosotros y los pines hacia abajo. Los pines de izquierda a derecha son emisor (e), base (b) y colector (c).

.. image:: img/ebc.png

.. note::
    * La base es el dispositivo controlador de puerta para el suministro eléctrico más grande. 
    * En el transistor NPN, el colector es el suministro eléctrico más grande y el emisor es la salida para ese suministro, en el transistor PNP es justo lo contrario.


.. Example
.. -------------------

.. :ref:`Dos Tipos de Transistores`


**Ejemplo**

* :ref:`ar_transistor` (Proyecto Arduino)
* :ref:`ar_ac_buz` (Proyecto Arduino)
* :ref:`ar_fruit_piano` (Proyecto Arduino)
* :ref:`py_transistor` (Proyecto MicroPython)
* :ref:`py_pa_buz` (Proyecto MicroPython)
* :ref:`py_light_theremin` (Proyecto MicroPython)
