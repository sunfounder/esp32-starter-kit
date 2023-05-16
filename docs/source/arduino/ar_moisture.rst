.. _ar_moisture:

5.9 Measure Soil Moisture
==========================

In the planting industry, the crops themselves cannot directly obtain the inorganic elements in the soil,
Water in the soil acts as a solvent for dissolving these inorganic elements.

Crops absorb soil moisture through the root system, obtain nutrients, and promote growth.

In the process of crop growth and development, the requirements for soil temperature are also different.
Therefore, a soil moisture sensor is required.




**Schematic**

.. image:: img/circuit_5.4_soil.png

**Wiring**



.. image:: img/measure_the_moisture_bb.jpg
    :width: 800
    :align: center

* :ref:`cpn_uno`
* :ref:`cpn_wires`
* :ref:`cpn_soil_moisture`

**Code**

.. note::

    * Open the ``5.9_moisture.ino`` file under the path of ``esp32-ultimate-kit\c\codes\5.9_moisture``.
    * Or copy this code into **Arduino IDE**.
    
    
.. raw:: html


Once the code is successfully uploaded, the serial monitor will print out the soil moisture value.

By inserting the module into the soil and watering it, the value of the soil moisture sensor will become smaller.