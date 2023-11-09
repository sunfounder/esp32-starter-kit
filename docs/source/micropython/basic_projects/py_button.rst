.. _py_button:

5.1 ボタンの値の読み取り
==============================================

この対話型プロジェクトでは、ボタン制御とLED操作の領域に挑戦します。

コンセプトはシンプルですが効果的です。ボタンの状態を読み取ります。ボタンが押されると、高電圧レベル、つまり「ハイ状態」として登録されます。このアクションによってLEDが点灯します。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入することは非常に便利です。こちらがリンクです：

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**利用可能なピン**

* **利用可能なピン**

    このプロジェクトのESP32ボードに利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - For Input
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - For Output
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **条件付き使用ピン（入力）**

    以下のピンには内蔵のプルアップまたはプルダウン抵抗があり、 **入力ピンとして使用する場合** に外部抵抗器は必要ありません：

    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - 条件付き使用ピン
            - 説明
        *   - IO13, IO15, IO2, IO4
            - 47Kの抵抗器でプルアップし、デフォルトで値をハイにします。
        *   - IO27, IO26, IO33
            - 4.7Kの抵抗器でプルアップし、デフォルトで値をハイにします。
        *   - IO32
            - 1Kの抵抗器でプルダウンし、デフォルトで値をローにします。

* **ストラッピングピン（入力）**

    ストラッピングピンは、デバイスの起動時に特定のブートモードを決定するために使用される特別なセットのピンです
    （つまり、電源オンリセット）。

        
    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15 
    
    一般的に、 **入力ピンとして使用することは推奨されません**。これらのピンを使用したい場合は、ブートプロセスへの潜在的な影響を考慮してください。詳細については、:ref:`esp32_strapping` セクションを参照してください。


**回路図**

.. image:: ../../img/circuit/circuit_5.1_button.png

適切な機能を確保するために、ボタンピンの片側を3.3Vに、もう片側をIO14に接続します。ボタンが押されるとIO14がハイに設定され、LEDが点灯します。ボタンが放されるとIO14は中断状態に戻り、これはハイでもローでもありえます。ボタンが押されていないときに安定したローレベルを保証するために、IO14は10Kのプルダウン抵抗器を介してGNDに接続されるべきです。

**配線図**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::
    
    4ピンボタンはH形状で設計されています。ボタンが押されていないとき、左右のピンは切断され、電流はそれらの間を流れません。しかし、ボタンが押されると、左右のピンが接続され、電流が流れる経路が作成されます。

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.1_read_button_value.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。



.. code-block:: python

    import machine
    import time

    button = machine.Pin(14, machine.Pin.IN) # Button pin
    led = machine.Pin(26, machine.Pin.OUT) # LED pin


    while True:
        # If the button is pressed by reading its value
        if button.value() == 1:
            # Turn on the LED by setting its value to 1
            led.value(1)
            # time.sleep(0.5)
        else:
            # Turn off the LED
            led.value(0)

スクリプト実行中は、ボタンを押すとLEDが点灯し、放すと消えます。

