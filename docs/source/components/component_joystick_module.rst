.. _cpn_joystick:

Joystick-Modul
=======================

.. image:: img/joystick_pic.png
    :align: center
    :width: 600

* **GND**: Masse.
* **+5V**: Stromversorgung, akzeptiert 3,3V bis 5V.
* **VRX**: Analoger Ausgang entsprechend der horizontalen (X-Achse) Position des Joysticks.
* **VRY**: Analoger Ausgang entsprechend der vertikalen (Y-Achse) Position des Joysticks.
* **SW**: Schalterausgang, wird aktiviert, wenn der Joystick nach unten gedrückt wird. Für eine ordnungsgemäße Funktion ist ein externer Pull-Up-Widerstand erforderlich. Mit dem Widerstand gibt der SW-Pin im Leerlauf ein hohes Signal aus und wird niedrig, wenn der Joystick gedrückt wird.

Die Grundidee eines Joysticks besteht darin, die Bewegung eines Sticks in elektronische Informationen umzusetzen, die ein Computer verarbeiten kann.

Um dem Computer eine vollständige Bewegungspalette zu übermitteln, muss ein Joystick die Position des Sticks auf zwei Achsen messen - der X-Achse (links nach rechts) und der Y-Achse (oben nach unten). Wie in der Grundgeometrie geben die X-Y-Koordinaten genau die Position des Sticks an.

Um die Position des Sticks zu bestimmen, überwacht das Joystick-Steuerungssystem einfach die Position jeder Achse. Das konventionelle analoge Joystick-Design macht dies mit zwei Potentiometern oder variablen Widerständen.

Der Joystick verfügt auch über einen digitalen Eingang, der aktiviert wird, wenn der Joystick nach unten gedrückt wird.

.. image:: img/joystick318.png
    :align: center
    :width: 600
	
**Beispiele**

* :ref:`ar_joystick` (Arduino-Projekt)
* :ref:`py_joystick` (MicroPython-Projekt)
* :ref:`sh_star_crossed` (Scratch-Projekt)
* :ref:`sh_dragon` (Scratch-Projekt)
