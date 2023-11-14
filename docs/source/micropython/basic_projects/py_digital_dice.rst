.. _py_dice:

6.6 Digitaler Würfel
================================

Dieses Projekt baut auf dem :ref:`py_7_segment`-Projekt auf, indem ein Knopf hinzugefügt wird, um die auf dem Siebensegment-Display angezeigte Zahl zu steuern.

Wenn der Knopf gedrückt wird, scrollt das Siebensegment-Display durch die Zahlen 1-6, und wenn der Knopf losgelassen wird, zeigt es eine zufällige Zahl an.

Dieser Zyklus setzt sich jedes Mal fort, wenn der Knopf gedrückt wird.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.6_electronic_dice.png

Dieses Projekt baut auf dem :ref:`py_7_segment`-Projekt auf, indem ein Knopf hinzugefügt wird, um die auf dem Siebensegment-Display angezeigte Zahl zu steuern.

Der Knopf ist direkt mit IO13 verbunden, ohne einen externen Pull-Up- oder Pull-Down-Widerstand, da IO13 einen internen Pull-Up-Widerstand von 47K hat, was den Bedarf an einem zusätzlichen externen Widerstand überflüssig macht.


**Verdrahtung**

.. image:: ../../img/wiring/6.6_DICE_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``6.6_digital_dice.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 

.. code-block:: python

    import machine
    import time
    import random

    # Define the segment code for a common anode 7-segment display
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

    # Initialize the pins for the 74HC595 shift register
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    button = machine.Pin(13, machine.Pin.IN) # Button pin

    # Define the hc595_shift function to shift data into the 74HC595 shift register
    def hc595_shift(dat):
        # Set the RCLK pin to low
        rclk.off()
        
        # Iterate through each bit (from 7 to 0)
        for bit in range(7, -1, -1):
            # Extract the current bit from the input data
            value = 1 & (dat >> bit)
            
            # Set the SRCLK pin to low
            srclk.off()
            
            # Set the value of the SDI pin
            sdi.value(value)
            
            # Clock the current bit into the shift register by setting the SRCLK pin to high
            srclk.on()
            
        # Latch the data into the storage register by setting the RCLK pin to high
        rclk.on()

    # Initialize the random seed
    random.seed(time.ticks_us())


    num = 1
    button_state = False

    # Define the button callback function to toggle the button state
    def button_callback(pin):
        global button_state
        button_state = not button_state

    # Attach the button callback function to the falling edge of the button pin
    button.irq(trigger=machine.Pin.IRQ_FALLING, handler=button_callback)

    # Continuously display the current digit on the 7-segment display, scrolling if button is not pressed
    while True:
        
        # Display the current digit on the 7-segment display
        hc595_shift(SEGCODE[num])
        
        # If the button is pressed and button state is True
        if button_state:
            pass

        # If the button is pressed again and button state is False, generate a new random digit
        if not button_state:
            num = random.randint(1, 6)
            time.sleep_ms(10) # Adjust this value to control the display refresh rate
        
Während das Programm läuft, wird durch das Drücken des Knopfes das Siebensegment-Display scrollen und zufällig eine Zahl zwischen 1 und 6 anzeigen.

Beim erneuten Drücken des Knopfes stoppt das Siebensegment-Display und zeigt eine bestimmte Zahl an. Drücken Sie den Knopf noch einmal, und das Siebensegment-Display wird das Durchlaufen der Ziffern fortsetzen.




