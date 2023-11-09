.. _py_ir_obstacle:

5.3 障害物の検出
===================================

このモジュールは一般に、前方に障害物があるかどうかを判断するために車やロボットに取り付けられています。また、ハンドヘルドデバイス、水道の蛇口などにも広く使用されています。

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

**利用可能なピン**

* **利用可能なピン**

    このプロジェクトのESP32ボードに利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 利用可能なピン
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **ストラッピングピン（入力）**

    ストラッピングピンは、デバイスの起動時に特定のブートモードを決定するために使用される特別なセットのピンです
    （つまり、電源オンリセット）。
   
    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15 
    
    一般的に、 **入力ピンとして使用することは推奨されません**。これらのピンを使用したい場合は、ブートプロセスへの潜在的な影響を考慮してください。詳細については、 :ref:`esp32_strapping` セクションを参照してください。

**回路図**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

障害物回避モジュールが障害物を検出しない場合、IO14はハイレベルを返します。しかし、障害物を検出した場合は、ローレベルを返します。青色のポテンショメータを調整して、このモジュールの検出距離を変更できます。

**配線図**

.. image:: ../../img/wiring/5.3_avoid_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.3_avoid.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。



.. code-block:: python

    import machine
    import time

    ir_avoid = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_UP) # avoid module pin

    while True:

        # Print values of the obstacle avoidance module 
        print(ir_avoid.value()) 
        time.sleep(0.1)


プログラムが実行中の場合、IR障害物回避モジュールが前方に障害物を検出すると、シリアルモニターに「0」が表示されます。それ以外の場合は「1」が表示されます。
