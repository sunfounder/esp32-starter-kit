.. _ar_pa_buz:

3.2 カスタムトーン
==========================================

前回のプロジェクトではアクティブブザーを使用しましたが、今回はパッシブブザーを使います。

アクティブブザーと同様に、パッシブブザーも電磁誘導の現象を利用して動作します。違いは、パッシブブザーには発振源がないため、直流信号を使ってもビープ音は鳴りません。
しかし、これによりパッシブブザーは自分の発振周波数を調整でき、「ド、レ、ミ、ファ、ソ、ラ、シ」といった異なる音符を出すことができます。

パッシブブザーにメロディを鳴らしてみましょう！

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入することは非常に便利です。こちらがリンクです:

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

このプロジェクトのESP32ボードで利用可能なピンのリストはこちらです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**回路図**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

IO14の出力がハイの場合、1Kの電流制限抵抗を経てS8050（NPNトランジスタ）が導通し、ブザーが鳴ります。

S8050（NPNトランジスタ）の役割は電流を増幅し、ブザーの音を大きくすることです。実際には、ブザーを直接IO14に接続することもできますが、ブザーの音が小さいことがわかるでしょう。

**配線図**

キットには2種類のブザーが含まれています。
私たちが必要とするのはアクティブブザーです。裏返すと、密封された背面（露出したPCBではない）が見えるはずです。

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

ブザーの動作にはトランジスタが必要で、ここではS8050（NPNトランジスタ）を使用します。

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\3.2_custom_tone`` のパスの下にある ``3.2_custom_tone.ino`` ファイルを開きます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/09a319a6-6861-40e1-ba1b-e7027bc0383d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、パッシブブザーが7つの音符のシーケンスを演奏するのが聞こえます。


**どのように動作するのか？**

#. ブザーピンとPWM解像度のための定数を定義します。

    .. code-block:: arduino

        const int buzzerPin = 14; //buzzer pin
        const int resolution = 8; 

#. 7つの音階の周波数をHzで含む配列を定義します。

    .. code-block:: arduino

        int frequencies[] = {262, 294, 330, 349, 392, 440, 494};

#. 指定した周波数を指定した期間、ブザーで鳴らすための関数を作成します。

    .. code-block:: arduino

        void playFrequency(int frequency, int duration) {
            ledcWriteTone(0, frequency); // Start the tone
            delay(duration); // Wait for the specified duration
            ledcWriteTone(0, 0); // Stop the buzzer
        }
    
    * ``uint32_t ledcWriteTone(uint8_t chan, uint32_t freq);``: この関数は、選択された周波数で50% PWM音をLEDCチャネルに設定するために使用されます。

        * ``chan`` LEDCチャネルの選択。
        * ``freq`` PWM信号の周波数の選択。

    この関数はチャネルの設定 ``frequency`` を返します。 ``0`` が返された場合、エラーが発生しLEDCチャネルが設定されませんでした。

#. ``setup()`` 関数内でPWMチャネルを設定し、ブザーピンをアタッチします。

    .. code-block:: arduino

        void setup() {
            ledcSetup(0, 2000, resolution); // Set up the PWM channel
            ledcAttachPin(buzzerPin, 0); // Attach the buzzer pin to the PWM channel
        }

    * ``uint32_t ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);``: この関数はLEDCチャネルの周波数と解像度を設定するために使用されます。LEDCチャネルに設定された周波数を返します。0が返された場合、エラーが発生しLEDCチャネルが設定されませんでした。
            
        * ``channel`` 設定するLEDCチャネルの選択。
        * ``freq`` PWMの周波数の選択。
        * ``resolution_bits`` LEDCチャネルの解像度を選択。範囲は1-14ビット（ESP32の場合は1-20ビット）。

    * ``void ledcAttachPin(uint8_t pin, uint8_t chan);``: この関数はピンをLEDCチャネルにアタッチするために使用されます。

        * ``pin`` GPIOピンの選択。
        * ``chan`` LEDCチャネルの選択。

#. ``loop()`` 関数内で、各音符の間に短い休止を置き、シーケンスを繰り返す前に1秒間の休止を置いて、7つの音階を順に鳴らします。

    .. code-block:: arduino

        void loop() {
            for (int i = 0; i < 7; i++) {
                playFrequency(frequencies[i], 300); // Play each note for 300ms
                delay(50); // Add a brief pause between the notes
            }
            delay(1000); // Wait for 1 second before replaying the sequence
            }

