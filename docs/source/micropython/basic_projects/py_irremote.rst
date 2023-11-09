.. _py_receiver:

5.14 赤外線リモコン
================================

赤外線受信機は、赤外線信号を受信し、TTLレベルに対応した信号を独立して検出・出力するコンポーネントです。サイズは通常のプラスチック製トランジスタと似ており、赤外線リモコンや赤外線伝送など様々なアプリケーションに使用されています。

このプロジェクトでは、赤外線受信機を使用してリモコンからの信号を検出します。リモコンのボタンを押すと、赤外線受信機が対応する信号を受信し、どのボタンが押されたかを判断するための信号をデコードできます。受信した信号をデコードすることで、それに関連する特定のキーやコマンドを識別できます。

赤外線受信機を使用することで、私たちのプロジェクトにリモコン機能を組み込むことができ、赤外線信号を使用してデバイスと対話し、制御することが可能になります。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入すると確かに便利です。こちらがリンクです：

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|

* **利用可能なピン**

    こちらは、このプロジェクトのためのESP32ボード上の利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 利用可能なピン
            - IO13, IO12, IO14, IO27, IO26, IO25, IO15, IO0, IO5, IO18, IO19, IO21, IO22, IO23

**回路図**

.. image:: ../../img/circuit/circuit_5.14_receiver.png

リモコンのボタンを押すと、赤外線受信機が信号を検出し、赤外線ライブラリを使用してデコードすることができます。このデコードプロセスにより、ボタン押下に関連するキー値を取得できます。

**配線図**

.. image:: ../../img/wiring/5.14_ir_receiver_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.14_ir_receiver.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。

    * ここでは、 ``ir_rx`` フォルダにあるライブラリを使用する必要があります。ESP32にアップロードされていることを確認してください。包括的なチュートリアルについては :ref:`add_libraries_py` を参照してください。


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

プログラムが実行されている間、リモコンのキーを押すと、キーの値と名前がシェルに表示されます。

.. note::
    新しいリモコンには、内部の電池を絶縁するためのプラスチックタブが端に付いています。リモコンを使用する際には、このプラスチック片を取り除くだけでリモコンの電源が入ります。

**どのように動作するのか？**

#. このプログラムは一見複雑に見えるかもしれませんが、実際には赤外線受信機の基本的な機能をいくつかのコード行で実現しています。


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

    * このコードでは、 ``ir`` オブジェクトがインスタンス化され、任意の時点で赤外線受信機によってキャプチャされた信号を読み取ることができます。
    * 結果として得られる情報はコールバック関数内の ``data`` 変数に格納されます。

        * `コールバック関数 - Wikipedia <https://en.wikipedia.org/wiki/Callback_(computer_programming)>`_

    * 赤外線受信機が重複した値を受信した場合（例えば、ボタンを押したままの場合）、 ``data`` は0未満になります。この ``data`` はフィルタリングする必要があります。

    * それ以外の場合は、 ``data`` は使用可能な値ですが、読み取り不可能なコードであるため、 ``decodeKeyValue(data)`` 関数を使用してより理解しやすい形式にデコードします。

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


#. 次に、いくつかのデバッグ機能をプログラムに組み込みます。これらの機能は不可欠ですが、目指す結果とは直接関連していません。

    .. code-block:: python

        from ir_rx.print_error import print_error

        ir.error_function(print_error) # Show debug information

#. 最後に、メインプログラムに空のループを使用し、try-except構造を実装して、プログラムが ``ir`` オブジェクトを適切に終了して終了することを保証します。

    .. code-block:: python

        try:
            while True:
                pass
        except KeyboardInterrupt:
            ir.close()

    * `Try文 - Pythonドキュメント <https://docs.python.org/3/reference/compound_stmts.html?#the-try-statement>`_
