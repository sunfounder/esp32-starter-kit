.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_7_segment:

2.5 数字表示
=======================

皆さん、この魅力的なプロジェクトへようこそ！このプロジェクトでは、0から9までの数字を7セグメントディスプレイに表示する世界を探求します。

このプロジェクトを起動し、0から9までの各数字が鮮やかに光る小型のコンパクトなディスプレイを目の当たりにすることを想像してみてください。それは、魅力的な方法で数字をショーケースするミニチュアスクリーンを持っているようなものです。信号ピンを制御することで、表示される数字を簡単に変更し、さまざまな魅力的なエフェクトを作成することができます。

シンプルな回路接続とプログラミングを通じて、7セグメントディスプレイと対話し、望む数字を実現する方法を学びます。カウンターであろうと、時計であろうと、または他の魅力的なアプリケーションであろうと、7セグメントディスプレイはあなたのプロジェクトに輝きを加える信頼できるコンパニオンになります。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全キットを購入するのが間違いなく便利です。こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**利用可能なピン**

こちらはこのプロジェクトのESP32ボードで利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_2.5_74hc595_7_segment.png

こちらの配線原理は基本的に :ref:`py_74hc595` と同じですが、唯一の違いはQ0-Q7が7セグメントディスプレイのa〜gピンに接続されていることです。

.. list-table:: 配線図
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - LEDセグメント表示
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**配線図**

.. image:: ../../img/wiring/2.5_segment_bb.png

**コード**

.. note::

    * ``2.5_number_display.py`` ファイルを ``esp32-starter-kit-main\micropython\codes`` パスから開くか、またはコードをThonnyにコピーして貼り付けます。その後、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタープリターを選択してください。

.. code-block:: python

    import machine
    import time

    # Define the segment code for a common anode 7-segment display
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

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

    # Continuously loop through the numbers 0 to 9 and display them on the 7-segment display
    while True:
        for num in range(10):
            hc595_shift(SEGCODE[num])  # Shift the segment code for the current number into the 74HC595
            time.sleep_ms(500)  # Wait 500 milliseconds before displaying the next number


    

スクリプトが実行されると、LEDセグメントディスプレイが0から9までの数字を順に表示します。

**どのように動作するのか？**

このプロジェクトでは、 ``hc595_shift()`` 関数を用いてバイナリ数値をシフトレジスタに書き込んでいます。

7セグメントディスプレイが数字の「2」を表示する場合を想定します。このビットパターンでは、セグメント **f**、 **c**、 **dp** がオフ（ロー）で、 **a**、 **b**、 **d**、 **e**、 **g** がオン（ハイ）です。これはバイナリでは「01011011」、16進数では「0x5b」となります。

従って、7セグメントディスプレイに「2」を表示するには、 **hc595_shift(0x5b)** を呼び出す必要があります。

.. image:: img/7_segment2.png

* `16進数 <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `バイナリー・ヘックス変換器 <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

以下の表には、7セグメントディスプレイに0から9までの数字を表示するためにシフトレジスタに書き込む必要がある16進数のパターンが示されています。

.. list-table:: グリフコード
    :widths: 20 20 20
    :header-rows: 1

    *   - 数字
        - バイナリーコード
        - ヘックスコード
    *   - 0
        - 00111111
        - 0x3f
    *   - 1
        - 00000110
        - 0x06
    *   - 2
        - 01011011
        - 0x5b
    *   - 3
        - 01001111
        - 0x4f
    *   - 4
        - 01100110
        - 0x66
    *   - 5
        - 01101101
        - 0x6d
    *   - 6
        - 01111101
        - 0x7d
    *   - 7
        - 00000111
        - 0x07
    *   - 8
        - 01111111
        - 0x7f
    *   - 9
        - 01101111
        - 0x6f

これらのコードを ``hc595_shift()`` に書き込むことで、LEDセグメントディスプレイに対応する数字を表示させます。
