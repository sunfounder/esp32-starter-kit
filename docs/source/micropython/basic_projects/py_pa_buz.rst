.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_pa_buz:

3.2 カスタムトーン
==========================================

前回のプロジェクトではアクティブブザーを使用しましたが、今回はパッシブブザーを使用します。

アクティブブザーと同様に、パッシブブザーも電磁誘導の現象を利用して動作します。違いは、パッシブブザーには発振源がないため、直流信号を使用してもビープ音を鳴らすことはありません。
しかし、これによりパッシブブザーは自身の発振周波数を調整でき、「ド、レ、ミ、ファ、ソ、ラ、シ」といった異なる音符を出すことができます。

パッシブブザーでメロディーを鳴らしましょう！

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**利用可能なピン**

このプロジェクトのESP32ボードに利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**回路図**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

IO14の出力が高いと、1Kの電流制限抵抗（トランジスタを保護するため）を経由して、S8050（NPNトランジスタ）が導通し、ブザーが鳴ります。

S8050（NPNトランジスタ）の役割は、電流を増幅してブザーの音を大きくすることです。実際には、ブザーを直接IO14に接続しても問題ありませんが、ブザーの音が小さくなることがわかります。

**配線図**

キットには2種類のブザーが含まれています。
アクティブブザーを使用する必要があります。それらを裏返すと、シールドされた背面（露出したPCBではない方）が必要なものです。

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

ブザーは動作時にトランジスタを使用する必要がありますが、ここではS8050（NPNトランジスタ）を使用します。

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``3.2_custom_tone.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。 

.. code-block:: python

    import machine
    import time

    # Define the frequencies of several musical notes in Hz
    C4 = 262
    D4 = 294
    E4 = 330
    F4 = 349
    G4 = 392
    A4 = 440
    B4 = 494

    # Create a PWM object representing pin 14 and assign it to the buzzer variable
    buzzer = machine.PWM(machine.Pin(14))

    # Define a tone function that takes as input a Pin object representing the buzzer, a frequency in Hz, and a duration in milliseconds
    def tone(pin, frequency, duration):
        pin.freq(frequency) # Set the frequency
        pin.duty(512) # Set the duty cycle
        time.sleep_ms(duration) # Pause for the duration in milliseconds
        pin.duty(0) # Set the duty cycle to 0 to stop the tone

    # Play a sequence of notes with different frequency inputs and durations
    tone(buzzer, C4, 250)
    time.sleep_ms(500)
    tone(buzzer, D4, 250)
    time.sleep_ms(500)
    tone(buzzer, E4, 250)
    time.sleep_ms(500)
    tone(buzzer, F4, 250)
    time.sleep_ms(500)
    tone(buzzer, G4, 250)
    time.sleep_ms(500)
    tone(buzzer, A4, 250)
    time.sleep_ms(500)
    tone(buzzer, B4, 250)


**どのように動作するのか？**

パッシブブザーにデジタル信号を与えると、音を発生させることなくダイヤフラムを押し続けるだけです。

そのため、 ``tone()`` 関数を使用してPWM信号を生成し、パッシブブザーに音を出させます。

この関数には3つのパラメーターがあります：

* ``pin``: ブザーを制御するピン。
* ``frequency``: ブザーの音程は周波数によって決まり、周波数が高いほど音程も高くなります。
* ``Duration``: 音の持続時間。

``duty()`` 関数を使用してデューティサイクルを512(約50%)に設定します。他の数値でも構いませんが、不連続な電気信号を生成して振動させる必要があります。

**もっと学ぶ**

特定のピッチをシミュレートし、完全な音楽曲を演奏することができます。

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``3.2_custom_tone_music.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。

.. code-block:: python

    import machine
    import time

    # Define the GPIO pin that is connected to the buzzer
    buzzer = machine.PWM(machine.Pin(14))

    # Define the frequencies of the notes in Hz
    C5 = 523
    D5 = 587
    E5 = 659
    F5 = 698
    G5 = 784
    A5 = 880
    B5 = 988

    # Define the durations of the notes in milliseconds
    quarter_note = 250
    half_note = 300
    whole_note = 1000

    # Define the melody as a list of tuples (note, duration)
    melody = [
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (E5, quarter_note),
        (D5, quarter_note),
        (D5, half_note),
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (D5, quarter_note),
        (C5, quarter_note),
        (C5, half_note),

    ]

    # Define a function to play a note with the given frequency and duration
    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty(512)
        time.sleep_ms(duration)
        pin.duty(0)

    # Play the melody
    for note in melody:
        tone(buzzer, note[0], note[1])
        time.sleep_ms(50)


* ``tone`` 関数は、 ``pin`` オブジェクトの ``freq`` メソッドを使用して、ピンの周波数を ``frequency`` の値に設定します。
* 次に、 ``pin`` オブジェクトの ``duty`` メソッドを使用して、ピンのデューティサイクルを512に設定します。
* これにより、ピンは指定された周波数と音量で ``duration`` ミリ秒の間音を出すことになります。これは、timeモジュールの ``sleep_ms`` メソッドを使用します。
* コードは、 ``melody`` と呼ばれるシーケンスを通じて反復し、メロディの各ノートに対してそのノートの周波数と持続時間で ``tone`` 関数を呼び出すことにより、メロディを演奏します。
* また、timeモジュールの ``sleep_ms`` メソッドを使用して、各ノートの間に50ミリ秒の短い休止を挿入します。

