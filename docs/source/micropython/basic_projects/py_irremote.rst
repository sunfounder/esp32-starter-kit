.. _py_receiver:

5.14 IR-Fernbedienung
================================

Ein Infrarotempfänger ist eine Komponente, die Infrarotsignale empfängt und Signale, die mit TTL-Pegel kompatibel sind, unabhängig erkennen und ausgeben kann. Er ist ähnlich groß wie ein regulärer, in Kunststoff verpackter Transistor und wird häufig in verschiedenen Anwendungen wie Infrarot-Fernbedienung und Infrarot-Übertragung eingesetzt.

In diesem Projekt werden wir einen Infrarotempfänger verwenden, um Signale von einer Fernbedienung zu erkennen. Wenn eine Taste auf der Fernbedienung gedrückt wird und der Infrarotempfänger das entsprechende Signal empfängt, kann er das Signal dekodieren, um zu bestimmen, welche Taste gedrückt wurde. Durch Dekodieren des empfangenen Signals können wir den spezifischen Schlüssel oder Befehl identifizieren, der damit verbunden ist.

Der Infrarotempfänger ermöglicht es uns, Fernbedienungsfunktionen in unser Projekt einzubauen, sodass wir Geräte mittels Infrarotsignalen interagieren und steuern können.

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
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|

**Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 20

        *   - Verfügbare Pins
            - IO13, IO12, IO14, IO27, IO26, IO25, IO15, IO0, IO5, IO18, IO19, IO21, IO22, IO23

**Schaltplan**

.. image:: ../../img/circuit/circuit_5.14_receiver.png

Wenn Sie eine Taste auf der Fernbedienung drücken, erkennt der Infrarotempfänger das Signal, und Sie können eine Infrarotbibliothek verwenden, um es zu dekodieren. Dieser Dekodierungsprozess ermöglicht es Ihnen, den Schlüsselwert zu erhalten, der mit dem Tastendruck verbunden ist.

**Verdrahtung**

.. image:: ../../img/wiring/5.14_ir_receiver_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.14_ir_receiver.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 

    * Hier müssen Sie die Bibliotheken im Ordner ``ir_rx`` verwenden. Stellen Sie bitte sicher, dass sie auf den ESP32 hochgeladen wurden. Für eine umfassende Anleitung siehe :ref:`add_libraries_py`.

.. code-block:: python

    import time
    from machine import Pin, freq
    from ir_rx.print_error import print_error
    from ir_rx.nec import NEC_8

    pin_ir = Pin(14, Pin.IN) # IR receiver

    # Decode the received data and return the corresponding key name
    def decodeKeyValue(data):       
        if data == 0x16:
            return "0"
        if data == 0x0C:
            return "1"
        if data == 0x18:
            return "2"
        if data == 0x5E:
            return "3"
        if data == 0x08:
            return "4"
        if data == 0x1C:
            return "5"
        if data == 0x5A:
            return "6"
        if data == 0x42:
            return "7"
        if data == 0x52:
            return "8"
        if data == 0x4A:
            return "9"
        if data == 0x09:
            return "+"
        if data == 0x15:
            return "-"
        if data == 0x7:
            return "EQ"
        if data == 0x0D:
            return "U/SD"
        if data == 0x19:
            return "CYCLE"
        if data == 0x44:
            return "PLAY/PAUSE"
        if data == 0x43:
            return "FORWARD"
        if data == 0x40:
            return "BACKWARD"
        if data == 0x45:
            return "POWER"
        if data == 0x47:
            return "MUTE"
        if data == 0x46:
            return "MODE"
        return "ERROR"

    # User callback
    def callback(data, addr, ctrl):
        if data < 0:  # NEC protocol sends repeat codes.
            pass
        else:
            print(decodeKeyValue(data))
            

    ir = NEC_8(pin_ir, callback) # Instantiate the NEC_8 receiver

    # Show debug information
    ir.error_function(print_error)  

    # keep the script running until interrupted by a keyboard interrupt (Ctrl+C)
    try:
        while True:
            pass
    except KeyboardInterrupt:
        ir.close()  # Close the receiver

Wenn das Programm läuft, drücken Sie die Taste auf der Fernbedienung, und der Wert sowie der Name der Taste erscheinen in der Shell.

.. note::
    Die neue Fernbedienung hat am Ende einen Kunststoffstreifen, um die Batterie im Inneren zu isolieren. Um die Fernbedienung zu aktivieren, entfernen Sie einfach dieses Kunststoffteil.

**Wie funktioniert das?**

#. Obwohl dieses Programm auf den ersten Blick etwas komplex erscheinen mag, erfüllt es tatsächlich die grundlegenden Funktionen des IR-Empfängers mit nur wenigen Codezeilen.


    .. code-block:: python

        import time
        from machine import Pin, freq
        from ir_rx.nec import NEC_8

        pin_ir = Pin(14, Pin.IN) # IR receiver

        # User callback
        def callback(data, addr, ctrl):
            if data < 0:  # NEC protocol sends repeat codes.
                pass
            else:
                print(decodeKeyValue(data))

        ir = NEC_8(pin_ir, callback)  # Instantiate receiver

    * In diesem Code wird ein ``ir``-Objekt instanziiert, das es ihm ermöglicht, die vom IR-Empfänger erfassten Signale jederzeit zu lesen.
    * Die resultierenden Informationen werden dann in der Variablen ``data`` innerhalb der Callback-Funktion gespeichert.

        * `Callback-Funktion - Wikipedia <https://en.wikipedia.org/wiki/Callback_(computer_programming)>`_

    * Wenn der IR-Empfänger doppelte Werte empfängt (z.B. wenn eine Taste gedrückt und gehalten wird), ist das ``data`` kleiner als 0, und diese ``data`` müssen herausgefiltert werden.

    * Andernfalls wäre das ``data`` ein nutzbarer Wert, allerdings in einem unlesbaren Code. Die Funktion ``decodeKeyValue(data)`` wird dann verwendet, um ihn in ein verständlicheres Format zu dekodieren.

        .. code-block:: python

            def decodeKeyValue(data):
                if data == 0x16:
                    return "0"
                if data == 0x0C:
                    return "1"
                if data == 0x18:
                    return "2"
                if data == 0x5E:
                ...


#. Als Nächstes integrieren wir mehrere Debug-Funktionen in das Programm. Während diese Funktionen wichtig sind, stehen sie nicht direkt mit dem gewünschten Ergebnis in Verbindung, das wir erreichen wollen.

    .. code-block:: python

        from ir_rx.print_error import print_error

        ir.error_function(print_error) # Show debug information

#. Schließlich verwenden wir eine leere Schleife für das Hauptprogramm und implementieren eine try-except-Struktur, um sicherzustellen, dass das Programm mit dem ordnungsgemäß beendeten ``ir``-Objekt abgeschlossen wird.

    .. code-block:: python

        try:
            while True:
                pass
        except KeyboardInterrupt:
            ir.close()

    * `Try-Anweisung - Python-Dokumentation <https://docs.python.org/3/reference/compound_stmts.html?#the-try-statement>`_
