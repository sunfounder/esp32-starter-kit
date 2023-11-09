.. _py_motor:

4.1 小型扇風機
=======================

この魅力的なプロジェクトでは、L293Dを使用してモーターを駆動する方法を探求します。

L293Dは、電子工学やロボティクスのプロジェクトでモーター制御によく使用される多目的な集積回路（IC）です。前進および後退の両方向で2つのモーターを駆動できるため、正確なモーター制御を必要とするアプリケーションに人気があります。

この魅力的なプロジェクトを終える頃には、デジタル信号とPWM信号を効果的に使用してモーターを制御する方法について十分な理解を得ることができます。この貴重な知識は、ロボティクスやメカトロニクスへの将来的な取り組みにおいて、しっかりとした基盤となるでしょう。L293Dを使ったモーター制御のエキサイティングな世界に飛び込む準備をしてください！

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
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
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

    モーターは比較的高い電流を必要とするため、まずバッテリーを挿入し、その後拡張ボードのスイッチをON位置にスライドしてバッテリー供給をアクティブにする必要があります。

.. image:: ../../img/wiring/4.1_motor_l293d_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``4.1_motor_turn.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。 

.. code-block:: python

    import machine
    import time

    # Create Pin objects representing the motor control pins and set them to output mode
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Define a function to rotate the motor clockwise
    def clockwise():
        motor1A.value(1)
        motor2A.value(0)

    # Define a function to rotate the motor anticlockwise
    def anticlockwise():
        motor1A.value(0)
        motor2A.value(1)

    # Define a function to stop the motor
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    # Enter an infinite loop

    try:
        while True:
            clockwise() # Rotate the motor clockwise
            time.sleep(1) # Pause for 1 second
            anticlockwise() # Rotate the motor anticlockwise
            time.sleep(1)
            stop() # Stop the motor
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Stop the motor when KeyboardInterrupt is caught



スクリプト実行中は、モーターが毎秒時計回りと反時計回りに交互に回転するのを見ることができます。

**もっと学ぶ**

モーターを単純に時計回りと反時計回りに回転させるだけでなく、以下に示すように制御ピンにパルス幅変調（PWM）を使用してモーターの回転速度を制御することもできます。

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``4.1_motor_turn_pwm.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。

.. code-block:: python

    from machine import Pin, PWM
    import time

    # Create PWM objects representing the motor control pins and set their frequency to 1000 Hz
    motor1A = PWM(Pin(13, Pin.OUT))
    motor2A = PWM(Pin(14, Pin.OUT))
    motor1A.freq(500)
    motor2A.freq(500)

    # Enter an infinite loop
    while True:
        # Rotate the motor forward by gradually increasing the power on the motor1A pin
        for power in range(0, 1023, 20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Decreasing the power on the motor1A pin
        for power in range(1023, 0, -20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Rotate the motor in the opposite direction by gradually increasing the power on the motor2A pin
        for power in range(0, 1023, 20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)
        # Decreasing the power on the motor2A pin
        for power in range(1023, 0, -20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)

以前のスクリプトとは異なり、ここでは1000Hzの周波数を持つPWM信号でモーターを制御しており、これがモーターの速度を決定します。

* コードでは ``while True`` ループを使用して連続して実行します。ループ内には、モーターを制御する4つの ``for`` ループがあります。
* 最初の2つの ``for`` ループは、IN2を0の速度で維持しながらIN1の速度を上げ下げします。
* 次の2つの ``for`` ループは、IN1を0の速度で維持しながらIN2の速度を上げ下げします。
* 各 ``for`` ループの ``range`` 関数は、PWM信号のデューティサイクルとして機能する一連の数字を生成します。これは、 ``duty`` メソッドを介してIN1またはIN2に出力されます。デューティサイクルは、PWM信号が高い状態である時間の割合を決定し、これによりモーターに適用される平均電圧、そしてモーターの速度を決定します。
*  ``time.sleep`` 関数は、シーケンスの各ステップの間に0.1秒の遅延を導入するために使用され、モーターが瞬間的に一つの速度から別の速度にジャンプするのではなく、徐々に速度を変更することができます。
