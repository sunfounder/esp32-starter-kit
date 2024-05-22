.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_servo:

4.3 スイングサーボ
===================

サーボは位置ベースのデバイスの一種で、特定の角度を維持し、正確な回転を行う能力で知られています。これにより、一貫した角度調整を必要とする制御システムに非常に望ましいものとなっています。サーボが、飛行機モデルから潜水艦のレプリカ、洗練されたリモートコントロールロボットに至るまで、高級遠隔制御玩具に広く使用されているのは驚くことではありません。

この魅力的な冒険では、サーボを独自の方法で操作することに挑戦します - スイングさせることによってです！このプロジェクトは、サーボのダイナミクスをより深く掘り下げ、正確な制御システムのスキルを磨き、その操作に関するより深い理解を得る絶好の機会を提供します。

サーボを自分の曲に合わせて踊らせる準備はできましたか？このエキサイティングな旅に出発しましょう！

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**利用可能なピン**

このプロジェクトのESP32ボードに利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**配線図**

* オレンジ色の線はシグナルで、IO25に接続されています。
* 赤色の線はVCCで、5Vに接続されています。
* 茶色の線はGNDで、GNDに接続されています。

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``4.3_swinging_servo.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。 

.. code-block:: python

    import machine
    import time

    # Create a PWM (Pulse Width Modulation) object on Pin 25
    servo = machine.PWM(machine.Pin(25))

    # Set the frequency of the PWM signal to 50 Hz, common for servos
    servo.freq(50)

    # Define a function for interval mapping
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Define a function to write an angle to the servo
    def servo_write(pin, angle):
        
        pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculate the pulse width
        duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calculate the duty cycle
        pin.duty(duty) # Set the duty cycle of the PWM signal

    # Create an infinite loop
    while True:
        # Loop through angles from 0 to 180 degrees
        for angle in range(180):
            servo_write(servo, angle)
            time.sleep_ms(20)

        # Loop through angles from 180 to 0 degrees in reverse
        for angle in range(180, -1, -1):
            servo_write(servo, angle)
            time.sleep_ms(20)


このコードを実行すると、サーボは0度から180度までの間を絶えず往復するようにスウィープします。

**どのように動作するのか？**

#. マイクロコントローラーのハードウェアを制御するための ``machine`` ライブラリと、遅延を追加するための ``time`` ライブラリをインポートします。

    .. code-block:: python

        import machine
        import time

#. ピン25にPWM（パルス幅変調）オブジェクトを作成し、サーボに一般的な50 Hzにその周波数を設定します。

    .. code-block:: python

        # Create a PWM (Pulse Width Modulation) object on Pin 25
        servo = machine.PWM(machine.Pin(25))

        # Set the frequency of the PWM signal to 50 Hz, common for servos
        servo.freq(50)

#. ある範囲から別の範囲に値をマッピングする ``interval_mapping`` 関数を定義します。これは、角度を適切なパルス幅とデューティサイクルに変換するために使用されます。

    .. code-block:: python

        def interval_mapping(x, in_min, in_max, out_min, out_max):
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

#. PWMオブジェクトと角度を入力として受け取る ``servo_write`` 関数を定義します。与えられた角度に基づいてパルス幅とデューティサイクルを計算し、それに応じてPWM出力を設定します。

    .. code-block:: python
        
        def servo_write(pin, angle):
            
            pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculate the pulse width
            duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calculate the duty cycle
            pin.duty(duty) # Set the duty cycle of the PWM signal

    * この関数では、 ``interval_mapping()`` を呼び出して、角度の範囲0〜180をパルス幅の範囲0.5〜2.5msにマッピングします。
    * なぜ0.5~2.5msなのか？これは :ref:`サーボ` の動作モードによって決まります。
    * 次に、パルス幅を周期からデューティに変換します。
    * ``duty()`` は使用時に小数を持つことができない（値がfloat型であってはならない）ため、 ``int()`` を使用してデューティをint型に変換しました。

#. 二つのネストしたループを持つ無限ループを作成します。

    .. code-block:: python

        while True:
            # Loop through angles from 0 to 180 degrees
            for angle in range(180):
                servo_write(servo, angle)
                time.sleep_ms(20)

            # Loop through angles from 180 to 0 degrees in reverse
            for angle in range(180, -1, -1):
                servo_write(servo, angle)
                time.sleep_ms(20)
    
    * 最初のネストしたループは0度から180度までの角度を反復し、二番目のネストしたループは180度から0度までの角度を逆順で反復します。
    * 各反復で、 ``servo_write`` 関数が現在の角度で呼び出され、20ミリ秒の遅延が追加されます。
