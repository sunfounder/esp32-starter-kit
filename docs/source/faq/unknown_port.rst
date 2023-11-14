.. _unknown_com_port:

"Unbekanntes COMxx" wird immer angezeigt?
-------------------------------------------

Wenn Sie den ESP32 an den Computer anschließen, zeigt die Arduino IDE oft ``Unbekanntes COMxx`` an. Warum passiert das?

.. image:: img/unknown_device.png

Dies liegt daran, dass der USB-Treiber für den ESP32 anders ist als bei den regulären Arduino-Boards. Die Arduino IDE kann dieses Board nicht automatisch erkennen.

In einem solchen Szenario müssen Sie das richtige Board manuell auswählen, indem Sie diese Schritte befolgen:

#. Klicken Sie auf **"Select the other board and port"**.

    .. image:: img/unknown_select.png

#. Geben Sie in der Suche **"esp32 dev module"** ein, wählen Sie dann das erscheinende Board aus. Wählen Sie anschließend den richtigen Port und klicken Sie auf **OK**.

    .. image:: img/unknown_board.png

#. Jetzt sollten Sie Ihr Board und Port in diesem Schnellansichtsfenster sehen können.

    .. image:: img/unknown_correct.png
