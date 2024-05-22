.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_fading:

2.2 LEDのフェード効果
===================================

前回のプロジェクトでは、デジタル出力を使ってLEDの点灯と消灯を制御しました。今回のプロジェクトでは、パルス幅変調（PWM）を利用してLEDに呼吸効果を作り出します。PWMは、正方形波信号のデューティサイクルを変化させることで、LEDの明るさやモーターの速度を制御する技術です。

PWMを使うことで、単にLEDをオンまたはオフにするのではなく、各サイクル内でLEDがオンになる時間とオフになる時間の割合を調整します。LEDを高速にオンとオフを繰り返すことで、LEDが徐々に明るくなったり暗くなったりする錯覚を作り出し、呼吸のような効果をシミュレートします。

ESP32 WROOM 32EのPWM機能を使用することで、LEDの明るさを滑らかで正確に制御することができます。この呼吸効果はプロジェクトにダイナミックで視覚的に魅力的な要素を加え、目を引くディスプレイや雰囲気を作り出します。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全てのキットを購入すると便利ですが、こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

以下のリンクから別々に購入することもできます。

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

**利用可能なピン**

このプロジェクトのESP32ボードにある利用可能なピンのリストはこちらです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**回路図**

.. image:: ../../img/circuit/circuit_2.1_led.png

このプロジェクトは最初のプロジェクト :ref:`py_blink` と同じ回路ですが、信号の種類が異なります。最初のプロジェクトではpin26から直接デジタルの高低レベル（0&1）を出力してLEDを点灯または消灯させますが、このプロジェクトではpin26からPWM信号を出力してLEDの明るさを制御します。

**配線図**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``2.2_fading_led.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。その後、「現在のスクリプトを実行」をクリックするかF5キーを押して実行します。
    * 右下の角にある「MicroPython (ESP32).COMxx」インタープリターを選択してください。 

.. code-block:: python

    # Import the necessary libraries
    from machine import Pin, PWM
    import time

    # Create a PWM object
    led = PWM(Pin(26), freq=1000)

    while True:
        # Gradually increase brightness
        for duty_cycle in range(0, 1024, 1):
            led.duty(duty_cycle)
            time.sleep(0.01)

        # Gradually decrease brightness
        for duty_cycle in range(1023, -1, -1):
            led.duty(duty_cycle)
            time.sleep(0.01)


コードが実行されると、LEDは徐々に明るくなります。

**どのように動作するのか？**

このコードは、PWM信号を使用してLEDの明るさを制御する方法を示しています。

#. ``machine`` と ``time`` の2つのモジュールをインポートします。  ``machine`` モジュールはマイクロコントローラのハードウェアに低レベルでアクセスするためのものであり、 ``time`` モジュールは時間に関連する操作のための関数を提供します。

    .. code-block:: python

        import machine
        import time

#. 次に、ピン26に接続されたLEDを制御するための ``PWM`` オブジェクトを初期化し、PWM信号の周波数を1000 Hzに設定します。

    .. code-block:: python

        led = PWM(Pin(26), freq=1000)

#. ループを使用してLEDを徐々に明るくしたり暗くしたりします：外側の ``while True`` ループは無限に実行されます。2つのネストされた ``for`` ループを使用して、LEDの明るさを徐々に増減します。デューティサイクルは0から1023の範囲で、0％から100％のデューティサイクルを表します。

    .. code-block:: python

        # Import the necessary libraries
        from machine import Pin, PWM
        import time

        # Create a PWM object
        led = PWM(Pin(26), freq=1000)

        while True:
            # Gradually increase brightness
            for duty_cycle in range(0, 1024, 2):
                led.duty(duty_cycle)
                time.sleep(0.01)

            # Gradually decrease brightness
            for duty_cycle in range(1023, -1, -2):
                led.duty(duty_cycle)
                time.sleep(0.01)


    * ``range()``: 0から1023までの整数のシーケンスを作成します。
    * ``PWM`` オブジェクトの ``duty()`` メソッドを使用して、シーケンスの各値にPWM信号のデューティサイクルを設定します。
    * ``time.sleep()``: ループの各反復の間にプログラムの実行を10ミリ秒間一時停止し、時間の経過とともに徐々に明るさを増加させます。

    
