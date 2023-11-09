.. _py_joystick:

5.11 ジョイスティックの切り替え
===================================

ビデオゲームをよくプレイする人なら、ジョイスティックに非常に慣れているはずです。
キャラクターを動かしたり、画面を回転させたりするのに通常使用されます。

コンピュータが私たちのアクションを読み取ることを可能にするジョイスティックの原理は非常にシンプルです。
それは互いに垂直な二つのポテンショメータから成り立っていると考えることができます。
これら二つのポテンショメータは、ジョイスティックの垂直方向と水平方向のアナログ値を測定し、平面直角座標系での値（x, y）を結果として出力します。


このキットのジョイスティックには、ジョイスティックが押されたときにアクティブになるデジタル入力もあります。

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

* **利用可能なピン**

    こちらは、このプロジェクトのためのESP32ボード上の利用可能なピンのリストです。

    .. list-table::
        :widths: 5 15

        *   - アナログ入力用
            - IO14, IO25, I35, I34, I39, I36
        *   - デジタル入力用
            - IO13, IO14, IO27, IO26, IO25, IO33, IO4, IO18, IO19, IO21, IO22, IO23

* **ストラッピングピン（入力）**

    ストラッピングピンは、デバイスの起動時に特定のブートモードを決定するために使用される特別なピンのセットです
    （つまり、電源オンリセット）。

        
    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15 
    
    一般に、これらを入力ピンとして使用することは **推奨されません**。これらのピンを使用したい場合は、ブートプロセスへの影響を考慮してください。詳細は :ref:`esp32_strapping` セクションを参照してください。

**回路図**

.. image:: ../../img/circuit/circuit_5.11_joystick.png

SW（Z軸）ピンはIO33に接続されており、内蔵の4.7Kプルアップ抵抗があります。そのため、SWボタンが押されていない時は、高レベルを出力します。ボタンが押されると、低レベルを出力します。

I34とI35は、ジョイスティックを操作するとその値が変わります。値の範囲は0から4095です。

**配線図**

.. image:: ../../img/wiring/5.11_joystick_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.11_joystick.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。 

.. code-block:: python

    from machine import ADC,Pin
    import time

    xAxis = ADC(Pin(34, Pin.IN)) # create an ADC object acting on a pin      
    xAxis.atten(xAxis.ATTN_11DB)
    yAxis = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      
    yAxis.atten(yAxis.ATTN_11DB)
    button = Pin(33, Pin.IN, Pin.PULL_UP)

    while True:
        xValue = xAxis.read()  # read a raw analog value in the range 0-4095
        yValue = yAxis.read()  # read a raw analog value in the range 0-4095
        btnValue = button.value()
        print(f"X:{xValue}, Y:{yValue}, Button:{btnValue}")
        time.sleep(0.1)

プログラムを実行すると、シェルはジョイスティックのx、y、ボタンの値を出力します。

.. code-block:: 

    X:1921, Y:1775, Button:0
    X:1921, Y:1775, Button:0
    X:1923, Y:1775, Button:0
    X:1924, Y:1776, Button:0
    X:1926, Y:1777, Button:0
    X:1925, Y:1776, Button:0
    X:1924, Y:1776, Button:0


* x軸とy軸の値は、0から4095まで変化するアナログ値です。
* ボタンはデジタル値で、1（リリース）または0（プレス）の状態を持ちます。

    .. image:: img/joystick_direction.png
