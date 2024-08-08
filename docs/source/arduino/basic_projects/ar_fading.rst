.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_fading:

2.2 フェーディング
=====================

前回のプロジェクトでは、デジタル出力を使用してLEDをオン/オフすることで制御しました。今回のプロジェクトでは、パルス幅変調（PWM）を活用してLEDに呼吸効果を作り出します。PWMは、正方形波信号のデューティ比を変えることで、LEDの明るさやモーターの速度を制御する技術です。

PWMでは、LEDを単純にオン/オフする代わりに、各サイクル内でLEDがオンになる時間とオフになる時間の割合を調整します。LEDを迅速にオン/オフする間隔を変えながら切り替えることで、LEDが徐々に明るくなったり暗くなったりする錯覚を生み出し、呼吸効果を模倣します。

ESP32 WROOM 32EのPWM機能を使用することで、LEDの明るさをスムーズかつ正確に制御できます。この呼吸効果は、プロジェクトにダイナミックで視覚的に魅力的な要素を加え、目を引くディスプレイや雰囲気を作り出します。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式を購入することは非常に便利です。こちらがリンクです：

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

**利用可能なピン**

こちらは、このプロジェクトのためのESP32ボード上で利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_2.1_led.png

このプロジェクトは最初のプロジェクト :ref:`ar_blink` と同じ回路ですが、シグナルタイプが異なります。最初のプロジェクトはピン26からデジタルの高/低レベル（0&1）を直接出力してLEDを点灯/消灯させるもので、このプロジェクトはピン26からPWM信号を出力してLEDの明るさを制御します。



**配線図**

.. image:: ../../img/wiring/2.1_hello_led_bb.png


**コード**

.. note::

    * ファイル ``2.2_fading_led.ino`` をパス ``esp32-starter-kit-main\c\codes\2.2_fading_led`` 以下から開けます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **Upload** ボタンをクリックします。
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/aa898b09-be86-473b-9bfe-317556c696bb/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードのアップロードに成功すると、LEDが呼吸するのを見ることができます。

**どのように動作するのか？**


#. 定数と変数を定義します。

    .. code-block:: arduino

        const int ledPin = 26; // The GPIO pin for the LED
        int brightness = 0;
        int fadeAmount = 5;
   
    * ``ledPin``: LEDが接続されているGPIOピン番号（ここではGPIO 26）。
    * ``brightness``: LEDの現在の明るさレベル（初期設定は0）。
    * ``fadeAmount``: 各ステップでLEDの明るさが変わる量（5に設定）。

#. PWMチャンネルを初期化し、LEDピンを設定します。

    .. code-block:: arduino

        void setup() {
            ledcSetup(0, 5000, 8); // Configure the PWM channel (0) with 5000Hz frequency and 8-bit resolution
            ledcAttachPin(ledPin, 0); // Attach the LED pin to the PWM channel
        }

    ここでは |link_ledc| （LED制御）周辺機器を使用します。これは主にLEDの明るさを制御するために設計されていますが、他の目的でPWM信号を生成するためにも使用できます。

    * ``uint32_t ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);``: この関数はLEDCチャンネルの周波数と解像度を設定するために使用されます。LEDCチャンネルに対して設定された``frequency``を返します。0が返された場合はエラーが発生し、LEDCチャンネルが設定されませんでした。
            
        * ``channel`` 設定するLEDCチャンネルを選択します。
        * ``freq`` PWMの周波数を選択します。
        * ``resolution_bits`` LEDCチャンネルの解像度を選択します。範囲は1-14ビットです（ESP32の場合は1-20ビット）。

    * ``void ledcAttachPin(uint8_t pin, uint8_t chan);``: この関数はピンをLEDCチャンネルにアタッチするために使用されます。

        * ``pin`` GPIOピンを選択します。
        * ``chan`` LEDCチャンネルを選択します。

#. ``loop()`` 関数にはプログラムの主要なロジックが含まれており、連続して実行されます。LEDの明るさを更新し、明るさが最小値または最大値に到達した際にfadeAmountを反転させ、遅延を導入します。

    .. code-block:: arduino

       void loop() {
            ledcWrite(0, brightness); // Write the new brightness value to the PWM channel
            brightness = brightness + fadeAmount;

            if (brightness <= 0 || brightness >= 255) {
                fadeAmount = -fadeAmount;
            }
            
            delay(50); // Wait for 20 milliseconds
            }

    * ``void ledcWrite(uint8_t chan, uint32_t duty);``: この関数はLEDCチャンネルのデューティを設定するために使用されます。
        
        * ``chan`` デューティを設定するLEDCチャンネルを選択します。
        * ``duty`` 選択されたチャンネルに設定するデューティを選択します。
