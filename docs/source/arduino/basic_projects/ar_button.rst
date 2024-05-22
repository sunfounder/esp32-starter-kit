.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_button:

5.1 ボタン値の読み取り
==============================================
このインタラクティブなプロジェクトでは、ボタンの制御とLEDの操作について学びます。

そのコンセプトはシンプルでありながら効果的です。ボタンの状態を読み取り、ボタンが押されると高電圧レベル（'high state'）が登録され、これがLEDが点灯するトリガーとなります。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

一式を購入すると便利です。こちらがリンクです：

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**利用可能なピン**

* **利用可能なピン**

    このプロジェクトのESP32ボード上で利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 入力用
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - 出力用
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **条件付き使用ピン（入力）**

    以下のピンには内蔵のプルアップまたはプルダウン抵抗があるため、 **入力ピンとして使用する場合** 外部抵抗は不要です：


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - 条件付き使用ピン
            - 説明
        *   - IO13, IO15, IO2, IO4
            - 47K抵抗でプルアップし、デフォルト値を高にします。
        *   - IO27, IO26, IO33
            - 4.7K抵抗でプルアップし、デフォルト値を高にします。
        *   - IO32
            - 1K抵抗でプルダウンし、デフォルト値を低にします。

* **ストラッピングピン（入力）**

    ストラッピングピンは、デバイスの起動時（電源オンリセット時）に特定のブートモードを決定するために使用される特別なピンのセットです。
     
    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15 
    
    一般に、これらのピンを入力ピンとして使用することは **お勧めしません**。これらのピンを使用する場合は、ブートプロセスに与える潜在的な影響を考慮してください。詳細については、 :ref:`esp32_strapping` セクションを参照してください。

**回路図**

.. image:: ../../img/circuit/circuit_5.1_button.png

ボタンの一方の端子を3.3Vに、もう一方の端子をIO14に接続してください。ボタンを押すとIO14がハイ状態になり、LEDが点灯します。ボタンを離すとIO14は浮遊状態に戻りますが、これはハイまたはローのいずれかになります。ボタンが押されていないときに安定したローレベルを確保するために、IO14は10Kのプルダウン抵抗を介してGNDに接続されるべきです。

**配線図**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::
    
    4ピンボタンはH型に設計されています。ボタンが押されていない状態では、左右のピンが接続されておらず、電流が流れません。しかし、ボタンを押すと左右のピンが接続され、電流が流れる経路が作られます。

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\5.1_button`` のパスの下にあるファイル ``5.1_button.ino`` を開くことができます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/702c5a70-78e7-4a8b-a0c7-10c0acebfc12/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、ボタンを押すとLEDが点灯し、離すと消灯します。

同時にArduino IDEのシリアルモニタを開き、ボタンの値を観察することができます。ボタンが押されている場合は「1」が印刷され、そうでない場合は「0」が印刷されます。

.. image:: img/button_serial.png


**どのように動作するのか？**

これまでのプロジェクトでは、デジタルまたはPWM信号の形で信号を出力することに関与していました。

このプロジェクトでは、外部コンポーネントからESP32ボードへの入力信号を受信します。Arduino IDEのシリアルモニタで入力信号を確認することができます。


#. ``setup()`` 関数では、ボタンピンを ``input`` として、LEDピンを ``output`` として初期化します。シリアル通信も115200のボーレートで開始します。

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            // initialize the button pin as an input
            pinMode(buttonPin, INPUT);
            // initialize the LED pin as an output
            pinMode(ledPin, OUTPUT);
        }
    
    * ``Serial.begin(speed)``: シリアルデータ通信のためのビット毎秒（ボーレート）のデータレートを設定します。

        * ``speed``: ビット毎秒（ボーレート）。許可されるデータ型: ``long``。

#. ``loop()`` 関数では、ボタンの状態を読み取り、変数 ``buttonState`` に格納します。 ``buttonState`` の値は ``Serial.println()`` を使用してシリアルモニタに出力します。

    .. code-block:: arduino

        void loop() {
            // read the state of the button value
            buttonState = digitalRead(buttonPin);
            Serial.println(buttonState);
            delay(100);
            // if the button is pressed, the buttonState is HIGH
            if (buttonState == HIGH) {
                // turn LED on
                digitalWrite(ledPin, HIGH);

            } else {
                // turn LED off
                digitalWrite(ledPin, LOW);
            }
        }

    ボタンが押されて ``buttonState`` がHIGHの場合、 ``ledPin`` を ``HIGH`` に設定することでLEDを点灯させます。それ以外の場合はLEDを消灯させます。

    * ``int digitalRead(uint8_t pin);``: 入力として設定された指定のピンの状態を読み取るために、digitalRead関数が使用されます。この関数は選択されたピンの論理状態を ``HIGH`` または ``LOW`` で返します。

        * ``pin`` GPIOを選択します

    * ``Serial.println()``: ASCIIテキストとして人が読めるデータをシリアルポートに出力し、その後にキャリッジリターン文字（ASCII 13, '\r'）と改行文字（ASCII 10, '\n'）を追加します。

