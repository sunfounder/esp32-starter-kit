.. _py_pump:

4.2 ポンピング
=======================

この興味深いプロジェクトでは、L293Dを使用して水ポンプを制御する方法について掘り下げていきます。

水ポンプ制御の領域では、他のモーターを制御するよりも少し単純です。このプロジェクトの美しさはそのシンプルさにあります - 回転の方向について心配する必要はありません。私たちの主な目標は、水ポンプを成功させて稼働させ続けることです。

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
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-

**利用可能なピン**

このプロジェクトのESP32ボードに利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**回路図**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


**配線図**

.. note::

    バッテリーを挿入し、拡張ボード上のスイッチをON位置にスライドしてバッテリー供給をアクティブにすることを推奨します。

.. image:: ../../img/wiring/4.2_pump_l293d_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``4.2_pumping.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。



.. code-block:: python

    import machine
    import time

    # Create Pin objects representing the motor control pins and set them to output mode
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Define a function to rotate the pump
    def rotate():
        motor1A.value(1)
        motor2A.value(0)

    # Define a function to stop the pump
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    try:
        while True:
            rotate()  # Rotate the motor clockwise
            time.sleep(5)  # Pause for 5 seconds
            stop()  # Stop the motor
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Stop the motor when KeyboardInterrupt is caught



スクリプト実行中は、ポンプが稼働し、チューブから水が出てきて、2秒間停止した後、再び稼働を開始するのを見ることができます。

