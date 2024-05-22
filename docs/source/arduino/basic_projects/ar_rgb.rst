.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_rgb:

2.3 カラフルライト
==============================================

このプロジェクトでは、RGB LEDを使用した加法色混合の魅力的な世界について探求します。

RGB LEDは、赤、緑、青の三原色を一つのパッケージに組み合わせています。これら三つのLEDは共通のカソードピンを共有し、各アノードピンが対応する色の強度を制御します。

各アノードに加える電気信号の強度を変えることで、幅広い色を作り出すことができます。たとえば、高強度の赤と緑の光を混ぜると黄色の光が、青と緑の光を混ぜるとシアンが生成されます。

このプロジェクトを通じて、加法色混合の原理を学び、RGB LEDを操作して魅力的で活発な色を表示させることで、私たちの創造力を解き放ちます。

**必要な部品**

このプロジェクトには以下のコンポーネントが必要です。

キット全体を購入することは非常に便利です。リンクはこちらです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

下記のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネント紹介
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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**利用可能なピン**

こちらは、このプロジェクトのためにESP32ボード上で利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_2.3_rgb.png

PWMピンのpin27、pin26、pin25はそれぞれRGB LEDの赤、緑、青のピンを制御し、共通カソードピンをGNDに接続します。これにより、異なるPWM値をこれらのピンに重ねて特定の色をRGB LEDに表示させることができます。


**配線図**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

RGB LEDには4つのピンがあります：長いピンが共通のカソードピンで、通常はGNDに接続されています。最も長いピンの隣の左側のピンが赤で、右側の二つのピンが緑と青です。

.. image:: ../../img/wiring/2.3_color_light_bb.png


**コード**

ここでは、お好きな色を描画ソフト（たとえばペイント）で選び、RGB LEDで表示させます。

.. note::

    * ``esp32-starter-kit-main\c\codes\2.3_rgb_led`` のパスの下にあるファイル ``2.3_rgb_led.ino`` を開けます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/49a579a1-ae9b-4e23-b6cd-c20e5695191b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

.. image:: img/edit_colors.png

``color_set()`` にRGB値を書き込むと、ご希望の色をRGB LEDで点灯させることができます。


**どのように動作するのか？**

#. GPIOピン、PWMチャネル、周波数（Hz）、解像度（ビット）を定義します。

    .. code-block:: arduino

        // Define RGB LED pins
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        // Define PWM channels
        const int redChannel = 0;
        const int greenChannel = 1;
        const int blueChannel = 2;

        // Define PWM frequency and resolution
        const int freq = 5000;
        const int resolution = 8;


#. ``setup()`` 関数では、指定された周波数と解像度でPWMチャネルを初期化し、その後、LEDピンを対応するPWMチャネルにアタッチします。

    .. code-block:: arduino

        void setup() {
            // Set up PWM channels
            ledcSetup(redChannel, freq, resolution);
            ledcSetup(greenChannel, freq, resolution);
            ledcSetup(blueChannel, freq, resolution);
            
            // Attach pins to corresponding PWM channels
            ledcAttachPin(redPin, redChannel);
            ledcAttachPin(greenPin, greenChannel);
            ledcAttachPin(bluePin, blueChannel);
        }
    
    ここでは |link_ledc| （LED制御）ペリフェラルを使用しており、主にLEDの輝度を制御するために設計されていますが、他の目的でPWM信号を生成するためにも使用できます。

    * ``uint32_t ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);``: この関数はLEDCチャネルの周波数と解像度を設定するために使用されます。LEDCチャネルに設定された ``frequency`` を返します。0が返された場合はエラーが発生し、LEDCチャネルは設定されませんでした。
            
        * ``channel`` LEDCチャネルの選択。
        * ``freq`` PWMの周波数の選択。
        * ``resolution_bits`` LEDCチャネルの解像度の選択。範囲は1-14ビット（ESP32の場合は1-20ビット）です。


    * ``void ledcAttachPin(uint8_t pin, uint8_t chan);``: この関数はピンをLEDCチャネルにアタッチするために使用されます。

        * ``pin`` GPIOピンの選択。
        * ``chan`` LEDCチャネルの選択。


#. ``loop()`` 関数は、各色（赤、緑、青、黄色、紫、シアン）を順に切り替え、各色の変更間に1秒のインターバルを設けています。

    .. code-block:: arduino

        void loop() {
            setColor(255, 0, 0); // Red
            delay(1000);
            setColor(0, 255, 0); // Green
            delay(1000);
            setColor(0, 0, 255); // Blue
            delay(1000);
            setColor(255, 255, 0); // Yellow
            delay(1000);
            setColor(80, 0, 80); // Purple
            delay(1000);
            setColor(0, 255, 255); // Cyan
            delay(1000);
        }


#. ``setColor()`` 関数は、それぞれのPWMチャネルに適切なデューティサイクル値を書き込むことにより、希望の色を設定します。この関数は赤、緑、青の色の値を整数で3つ受け取ります。

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // For common-anode RGB LEDs, use 255 minus the color value
            ledcWrite(redChannel, red);
            ledcWrite(greenChannel, green);
            ledcWrite(blueChannel, blue);
        }
    
    * ``void ledcWrite(uint8_t chan, uint32_t duty);``: この関数はLEDCチャネルのデューティを設定するために使用されます。
        
        * ``chan`` デューティを書き込むLEDCチャネルの選択。
        * ``duty`` 選択されたチャネルに設定するデューティ。
