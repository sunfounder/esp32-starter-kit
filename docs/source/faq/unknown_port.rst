.. _unknown_com_port:

"Unknown COMxx"が常に表示されますか？
-------------------------------------------

ESP32をコンピュータに接続すると、Arduino IDEはよく ``Unknown COMxx`` と表示します。これはなぜでしょうか？

.. image:: img/unknown_device.png

これは、ESP32のUSBドライバが通常のArduinoボードとは異なるためです。Arduino IDEはこのボードを自動的に認識することができません。

このような状況では、以下の手順に従って正しいボードを手動で選択する必要があります：

#. **Select the other board and port** をクリックします。

    .. image:: img/unknown_select.png

#. 検索窓に **esp32 dev module** と入力し、表示されるボードを選択します。その後、正しいポートを選択し、 **OK** をクリックします。

    .. image:: img/unknown_board.png

#. これで、クイックビューウィンドウでボードとポートを確認することができるはずです。

    .. image:: img/unknown_correct.png
