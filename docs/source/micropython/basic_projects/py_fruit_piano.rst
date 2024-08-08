.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_fruit_piano:

6.1 フルーツピアノ
============================

ピアノを弾いてみたいけれど、お金が足りない？ それとも自作のフルーツピアノで楽しみたいだけ？ このプロジェクトはあなたのためです！

ESP32ボードの数個のタッチセンサーを使えば、お気に入りの曲を弾いて、高価なピアノを購入することなくピアノ演奏の体験を楽しむことができます。

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**タッチピンについて**

ESP32マイクロコントローラは内蔵のタッチセンサ機能を持っており、ボード上の特定のピンをタッチ感知入力として使用することができます。タッチセンサは、人体の電気的特性によって引き起こされるタッチピン上の静電容量の変化を測定することによって動作します。

ESP32のタッチセンサの主な特徴は以下の通りです：

* **タッチピンの数**

    ESP32には、ボードによって最大10個のタッチピンがあります。タッチピンは通常、数字に続いて「T」とラベル付けされています。

    * GPIO4: TOUCH0
    * GPIO0：TOUCH1
    * GPIO2: TOUCH2
    * GPIO15: TOUCH3
    * GPIO13: TOUCH4
    * GPIO12: TOUCH5
    * GPIO14: TOUCH6
    * GPIO27: TOUCH7
    * GPIO33: TOUCH8
    * GPIO32: TOUCH9

    .. note::
        GPIO0およびGPIO2ピンは、それぞれESP32へのブートストラッピングとファームウェアのフラッシングに使用されます。これらのピンはオンボードのLEDとボタンにも接続されています。そのため、通常これらのピンを他の目的で使用することは推奨されず、ボードの通常の動作に干渉する可能性があります。

* **感度**

    ESP32のタッチセンサは非常に敏感で、わずかな静電容量の変化でも検出できます。感度はソフトウェア設定で調整できます。

* **ESD保護**

    ESP32のタッチピンには内蔵のESD（静電気放電）保護があり、静電気によるボードの損傷を防ぐのに役立ちます。

* **マルチタッチ**

    ESP32のタッチセンサはマルチタッチをサポートしており、複数のタッチイベントを同時に検出できます。



**回路図**

.. image:: ../../img/circuit/circuit_6.1_fruit_piano.png

このプロジェクトのアイデアは、ユーザーが特定のピンに触れたときに検出するためにタッチセンサーを使用することです。
各タッチピンは特定の音符と関連付けられており、ユーザーがピンに触れると、
対応する音符がパッシブブザーで演奏されます。
結果は、ピアノ演奏の体験をシンプルかつ手頃な価格で楽しむ方法です。


**配線図**

.. image:: ../../img/wiring/6.1_fruit_piano_bb.png

このプロジェクトでは、ESP32 WROOM 32Eを拡張ボードから取り外し、その後ブレッドボードに挿入する必要があります。これは、拡張ボード上の一部のピンが抵抗に接続されており、ピンの容量に影響を与えるためです。

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``6.1_fruit_piano.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。

.. code-block:: python

    from machine import Pin, PWM, TouchPad
    import time

    # Define the touch pins and their corresponding notes
    touch_pins = [4, 15, 13, 12, 14, 27, 33, 32]  # Use valid touch-capable pins
    notes = [262, 294, 330, 349, 392, 440, 494, 523]

    # Initialize the touch sensors
    touch_sensors = [TouchPad(Pin(pin)) for pin in touch_pins]

    # Initialize the buzzer
    buzzer = PWM(Pin(25), duty=0)

    # Function to play a tone
    def play_tone(frequency, duration):
        buzzer.freq(frequency)
        buzzer.duty(512)
        time.sleep_ms(duration)
        buzzer.duty(0)

    touch_threshold = 200

    # Main loop to check for touch inputs and play the corresponding note
    while True:
        for i, touch_sensor in enumerate(touch_sensors):
            value = touch_sensor.read()
            print(i,value)
            if value < touch_threshold:
                play_tone(notes[i], 100)
                time.sleep_ms(50)
            time.sleep(0.01)


これらのESP32のピンに果物を接続できます：4, 15, 13, 12, 14, 27, 33, 32。

スクリプトを実行すると、これらの果物に触れるとC, D, E, F, G, A, B, C5の音符が演奏されます。

.. note::
    ``Touch_threshold`` は、異なる果物の導電性に基づいて調整する必要があります。

    最初にスクリプトを実行して、シェルによって出力される値を確認できます。

    .. code-block::

        0 884
        1 801
        2 856
        3 964
        4 991
        5 989
        6 1072
        7 1058

    12, 14, 27番のピンにある果物に触れた後、出力される値は以下の通りです。したがって、200未満の値が検出されたときに触れたと見なされ、ブザーが異なる音符を発するように、 ``touch_threshold`` を200に設定しました。
    
    .. code-block::

        0 882
        1 810
        2 799
        3 109
        4 122
        5 156
        6 1068
        7 1055

