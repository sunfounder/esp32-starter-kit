.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_tilt:

5.2 傾けて操作！
==========================
傾斜スイッチは、その中心に金属球を含むシンプルで効果的な2ピンデバイスです。スイッチが垂直な位置にあるとき、2つのピンは電気的に接続されており、電流が流れます。しかし、スイッチが傾いたり一定の角度で傾いたりすると、金属球が動いてピン間の電気的接続を遮断します。

このプロジェクトでは、傾斜スイッチを使用してLEDの照明を制御します。傾斜動作を引き起こすようにスイッチを配置することで、スイッチの向きに基づいてLEDをオン/オフに切り替えることができます。

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
    *   - :ref:`cpn_tilt`
        - \-

**利用可能なピン**

* **利用可能なピン**

    このプロジェクトのESP32ボードに利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 入力用
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - 出力用
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
    

    

    一般的に、 **入力ピンとして使用することは推奨されません**。これらのピンを使用したい場合は、ブートプロセスへの潜在的な影響を考慮してください。詳細については、 :ref:`esp32_strapping` セクションを参照してください。


**回路図**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

傾斜スイッチが垂直な位置にあるとき、IO14はハイに設定され、その結果LEDが点灯します。逆に、傾斜スイッチが傾いたとき、IO14はローに設定され、LEDが消灯します。

10Kの抵抗器の目的は、傾斜スイッチが傾いた位置にあるときにIO14の安定したローステートを維持することです。


**配線図**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.2_tilt_switch.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。 



.. code-block:: python

    import machine
    import time

    switch = machine.Pin(14, machine.Pin.IN) # Tilt switch pin
    led = machine.Pin(26, machine.Pin.OUT) # LED pin

    while True:
        # Check if the switch is tilted by reading its value
        if switch.value() == 1:
            # Turn on the LED by setting its value to 1
            led.value(1)
        else:
            # Turn off the LED
            led.value(0)

スクリプトが実行中のとき、スイッチが垂直になっているとLEDが点灯し、傾いているとLEDが消えます。

