.. _py_74hc595:

2.4 マイクロチップ - 74HC595
===============================

このプロジェクトへようこそ！このプロジェクトでは、74HC595チップを使用して、8つのLEDの流れるような表示を制御します。

このプロジェクトを実行して、8つのLEDの間で跳ねるようなキラキラとした虹のような流れる光を目の当たりにすることを想像してください。一つ一つのLEDが次々に点灯し、すぐに消えていき、次のLEDが輝き続けることで、美しくダイナミックな効果を生み出します。

74HC595チップを巧みに利用することで、複数のLEDのオン・オフ状態を制御し、流れる効果を実現できます。このチップには複数の出力ピンがあり、LEDの照明順序を制御するために直列に接続することができます。また、チップの拡張性のおかげで、より多くのLEDを流れる表示に簡単に追加することができ、さらに壮観な効果を作り出すことができます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入すると便利ですが、以下のリンクからも別々に購入できます。

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**利用可能なピン**

このプロジェクトに利用可能なESP32ボードのピンのリストは以下の通りです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**回路図**

.. image:: ../../img/circuit/circuit_2.4_74hc595_led.png
    :width: 600

* MR（ピン10）がハイレベルでCE（ピン13）がローレベルの場合、SHcpの立ち上がりエッジでデータが入力され、SHcpの立ち上がりエッジでメモリレジスタへ移行します。
* 二つのクロックが一緒に接続されている場合、シフトレジスタはメモリレジスタよりも常に一つのパルス分先行します。
* メモリレジスタには、シリアルシフト入力ピン（DS）、シリアル出力ピン（Q7'）および非同期リセットボタン（ローレベル）があります。
* メモリレジスタは、パラレル8ビットで三状態のバスを出力します。
* OEが有効（ローレベル）の場合、メモリレジスタ内のデータがバス（Q0 ～ Q7）に出力されます。

**配線図**

.. image:: ../../img/wiring/2.4_74hc595_bb.png
    :width: 800

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``2.4_microchip_74hc595.py`` ファイルを開くか、Thonnyにコードをコピー＆ペーストしてください。その後、「現在のスクリプトを実行」をクリックするかF5キーを押して実行します。
    * 右下の角にある「MicroPython (ESP32).COMxx」インタープリターを選択してください。 

.. code-block:: python

    import machine
    import time

    # Initialize the pins for the 74HC595 shift register
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

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

    num = 0

    # Shift data into the 74HC595 to create a moving LED pattern
    for i in range(16):
        if i < 8:
            num = (num << 1) + 1  # Shift left and set the least significant bit to 1
        elif i >= 8:
            num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
        hc595_shift(num)  # Shift the current value into the 74HC595
        print("{:0>8b}".format(num))  # Print the current value in binary format
        time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value




このスクリプトを実行すると、LEDが順番に点灯し、元の順序で消灯します。

**どのように動作するのか？**

このコードは8ビットのシフトレジスタ（74595）を制御し、シフトレジスタに異なるバイナリ値を出力し、各値を一定時間LEDに表示します。

#. ``machine`` と ``time`` モジュールをインポートしています。 ``machine`` モジュールはハードウェアI/Oを制御するために、 ``time`` モジュールはタイムディレイやその他の機能を実装するために使用されます。

    .. code-block:: python

        import machine
        import time

#. ``machine.Pin()`` 関数を使用して、データポート（SDI）、ストレージクロックポート（RCLK）、シフトレジスタクロックポート（SRCLK）に対応する三つの出力ポートを初期化します。

    .. code-block:: python

        # Initialize the pins for the 74HC595 shift register
        sdi = machine.Pin(25, machine.Pin.OUT)  # DS
        rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
        srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

#. シフトレジスタに8ビットデータを書き込むための関数 ``hc595_shift()`` を定義します。

    .. code-block:: python

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

#. ``for`` ループについて。

    .. code-block:: python

        for i in range(16):
                if i < 8:
                    num = (num << 1) + 1  # Shift left and set the least significant bit to 1
                elif i >= 8:
                    num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
                hc595_shift(num)  # Shift the current value into the 74HC595
                print("{:0>8b}".format(num))  # Print the current value in binary format
                time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value

    * 変数 ``i`` は出力バイナリ値を制御するために使用されます。最初の8回の反復では、numの値は次々に00000001, 00000011, 00000111, ..., 11111111になり、1ビット左にシフトされてから1を加算します。
    * 9回目から16回目の反復では、最高位の1を最初に0に変更し、それから1ビット左にシフトします。これにより、00000010, 00000100, 00001000, ..., 10000000の出力値が生成されます。
    * 各反復で、 ``num`` の値は ``hc595_shift()`` 関数に渡され、シフトレジスタが対応するバイナリ値を出力するように制御されます。
    * バイナリ値を出力すると同時に、 ``print()`` 関数はバイナリ値を文字列としてターミナルに出力します。
    * バイナリ値を出力した後、 ``time.sleep_ms()`` 関数を使用してプログラムを200ミリ秒一時停止し、LED上の値が一定期間表示されるようにします。