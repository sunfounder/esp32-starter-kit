.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_rgb_strip:

2.7 RGB LEDストリップ
======================

このプロジェクトでは、WS2812 LEDストリップの駆動と、鮮やかな色彩の展示を目指します。ストリップ上の各LEDを個別に制御する能力により、視覚を魅了するライティングエフェクトを作り出すことができます。

さらに、このプロジェクトにはランダム性の世界を探求するというワクワクする拡張機能を含んでいます。ランダムな色を導入し、流れるような光のエフェクトを実装することで、見る者を魅了する幻想的なビジュアル体験を創出します。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

一式を購入するのが便利です。こちらがリンクです：

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

    * - コンポーネントの紹介
      - 購入リンク

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**回路図**

.. image:: ../../img/circuit/circuit_2.7_ws2812.png
    :width: 500
    :align: center


**利用可能なピン**

こちらはこのプロジェクトのためのESP32ボード上で利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


.. note::

    IO33はこのプロジェクトでは使用できません。

    WS2812 LEDストリップは、正確なパルス幅変調（PWM）信号を要求するタイプのLEDストリップです。PWM信号は時間と電圧の両方で厳密な要求があります。例えば、WS2812の「0」ビットは約0.4マイクロ秒のハイレベルパルスに対応し、「1」ビットは約0.8マイクロ秒のハイレベルパルスに対応します。これは、ストリップが高周波の電圧変化を受け取る必要があることを意味します。

    しかし、IO33に4.7Kのプルアップ抵抗と100nfのプルダウンコンデンサーをつけると、簡単なローパスフィルターが作成されます。このタイプの回路は、コンデンサーが電圧変化を受けたときに充電と放電をする時間が必要なため、高周波信号を「平滑化」します。そのため、信号があまりにも速く変化する（つまり、高周波である）場合、コンデンサーは追い付けず、結果として出力信号がぼやけて、ストリップに認識不可能になります。

**配線図**

.. image:: ../../img/wiring/2.7_rgb_strip_bb.png
    :width: 800

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\2.7_rgb_strip`` のパスの下にあるファイル ``2.7_rgb_strip.ino`` を開くか、このコードを **Arduino IDE** にコピーしてください。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``Adafruit NeoPixel`` ライブラリが使用されています。これは **Library Manager** からインストールできます。

        .. image:: img/rgb_strip_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/bccd25f6-4e3e-45e2-b9f5-76a1b0866794/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


コードが正常にアップロードされると、ストリップのLEDが順に黄色で点灯し、次に消灯し、単純なチェイス効果を作り出します。


**どのように動作するのか？**


#. Adafruit NeoPixelライブラリを含める：この行はAdafruit NeoPixelライブラリをインポートし、LEDストリップを制御するためにその関数やクラスをスケッチで使用できるようにします。

    .. code-block:: arduino

        #include <Adafruit_NeoPixel.h> // Include the Adafruit NeoPixel library

#. LEDストリップのための定数を定義します。

    .. code-block:: arduino

        #define LED_PIN 13 // NeoPixel LED strip
        #define NUM_LEDS 8 // Number of LEDs

#. Adafruit_NeoPixelクラスのインスタンスを作成します。

    .. code-block:: arduino

       // Create an instance of the Adafruit_NeoPixel class
        Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

    この行は ``Adafruit_NeoPixel`` クラスの ``strip`` というインスタンスを作成し、LEDの数、LEDストリップに接続されたピン、および信号パラメータ（GRBカラーオーダーと800 kHzのデータレート）で設定します。


    * ``Adafruit_NeoPixel (uint16_t n, int16_t p = 6, neoPixelType t = NEO_GRB + NEO_KHZ800)``	

    長さ、ピン、ピクセルタイプがコンパイル時に既知の場合のNeoPixelコンストラクタ。Adafruit_NeoPixelオブジェクトを返します。使用前に ``begin()`` 関数を呼び出してください。

        * ``n``: ストランド内のNeoPixelの数。
        * ``p``: NeoPixelデータを駆動するArduinoピン番号。
        * ``t``: ピクセルタイプ - ``Adafruit_NeoPixel.h`` で定義された ``NEO_*`` 定数を加算します。例えば ``NEO_GRB+NEO_KHZ800`` は、800 KHz（対400 KHz）データストリームを期待するNeoPixelと、ピクセルごとに緑、赤、青の順番で表現されるカラーバイトのためです。

#. WS2812 RGBストリップを初期化し、ストリップの初期色を黒（オフ）に設定します。

    .. code-block:: arduino

        void setup() {
            strip.begin(); // Initialize the NeoPixel strip
            strip.show(); // Set initial color to black
        }

    * ``void begin (void)``: NeoPixelピンを出力用に設定します。
    * ``void show (void)``: RAM内のピクセルデータをNeoPixelsに送信します。

#. ``loop()`` 関数では、LEDストリップ上のLEDが順に黄色で点灯し、その後消灯します。これによりシンプルな追跡効果が作成されます。

    .. code-block:: arduino

        void loop() {
            // Turn on LEDs one by one
            for (int i = 0; i < NUM_LEDS; i++) {
                strip.setPixelColor(i, 100, 45, 0); // Set the color of the i-th LED to red
                strip.show(); // Update the LED strip with the new colors
                delay(100); // Wait for 100 milliseconds
            }
            
            // Turn off LEDs one by one
            for (int i = 0; i < NUM_LEDS; i++) {
                strip.setPixelColor(i, 0, 0, 0); // Set the color of the i-th LED to black (turn it off)
                strip.show(); // Update the LED strip with the new colors
                delay(100); // Wait for 100 milliseconds
            }
        }

    * ``void setPixelColor (uint16_t n, uint8_t r, uint8_t g, uint8_t b)``

    赤、緑、青のそれぞれの成分を使用してピクセルの色を設定します。RGBWピクセルを使用する場合、白は0に設定されます。

        * ``n``: ピクセルのインデックスで、0から始まります。
        * ``r``: 赤の明るさで、0は最小（オフ）、255は最大です。
        * ``g``: 緑の明るさで、0は最小（オフ）、255は最大です。
        * ``b``: 青の明るさで、0は最小（オフ）、255は最大です。

