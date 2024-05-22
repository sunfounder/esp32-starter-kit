.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_blink:

2.1 こんにちは、LED！ 
=======================================

プログラム学習の最初の一歩として「Hello, world!」を出力するように、プログラムを使ってLEDを操作することは物理的プログラミング学習の伝統的な導入です。

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

この回路はシンプルな原理で動作し、電流の方向は図に示されています。pin26がハイレベルを出力した後に220オームの電流制限抵抗を通過するとLEDが点灯します。pin26がローレベルを出力するとLEDが消えます。

**配線図**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**コードを実行する**

#. ``esp32-starter-kit-main\micropython\codes`` パスにある ``2.1_hello_led.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。

    .. code-block:: python

        # Import the necessary libraries
        import machine
        import time

        # Set up the LED on pin 26 as an output pin
        led = machine.Pin(26, machine.Pin.OUT)

        # Start an infinite loop
        while True:
            # Turn on the LED by setting its value to 1 (HIGH)
            led.value(1)
            # Wait for 1 second (1000 milliseconds) while the LED is on
            time.sleep(1)

            # Turn off the LED by setting its value to 0 (LOW)
            led.value(0)
            # Wait for 0.5 seconds (500 milliseconds) while the LED is off
            time.sleep(0.5)

#. Micro USBケーブルを使用してESP32 WROOM 32Eをコンピューターに接続します。

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. その後、右下隅にある「MicroPython (ESP32).COMXX」インタープリタをクリックします。

    .. image:: ../python_start/img/sec_inter.png

#. 最後に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。

    .. image:: ../python_start/img/quick_guide2.png

#. コードを実行した後、LEDが点滅するのが見えます。


**どのように動作するのか？**

#. ``machine`` と ``time`` の2つのモジュールをインポートします。  ``machine`` モジュールはマイクロコントローラのハードウェアに低レベルでアクセスするためのものであり、 ``time`` モジュールは時間に関連する操作のための関数を提供します。

    .. code-block:: python

        import machine
        import time

#. 次に、 ``machine.Pin()`` 関数を ``machine.Pin.OUT`` 引数とともに使用してpin26を出力ピンとして設定します。

    .. code-block:: python

        led = machine.Pin(26, machine.Pin.OUT)

#. ``While True`` ループでは、 ``led.value(1)`` を使用してpin26の値を1に設定し、1秒間LEDを点灯させ、その後0に設定して(``led.value(0)``)1秒間消灯し、無限ループでこれを繰り返します。

    .. code-block:: python
        
        while True:
            # Turn on the LED by setting its value to 1 (HIGH)
            led.value(1)
            # Wait for 1 second (1000 milliseconds) while the LED is on
            time.sleep(1)

            # Turn off the LED by setting its value to 0 (LOW)
            led.value(0)
            # Wait for 0.5 seconds (500 milliseconds) while the LED is off
            time.sleep(0.5)




**もっと学ぶ**

このプロジェクトでは、MicroPythonの「machine」と「time」モジュールを使用しました。これらのモジュールをさらに使いこなす方法はこちらで見つけることができます。

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_

* `time <https://docs.micropython.org/en/latest/library/time.html>`_
