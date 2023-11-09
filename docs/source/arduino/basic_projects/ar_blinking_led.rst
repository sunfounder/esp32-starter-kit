.. _ar_blink:

2.1 LEDを点灯させよう
=======================================

プログラム学習の最初の一歩として"Hello, world!"を出力するように、LEDをプログラムで制御することは物理プログラミングを学ぶための伝統的な入門です。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全キットを購入することは非常に便利です。以下のリンクから購入できます：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

また、以下のリンクから個別に購入することもできます。

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

このプロジェクトで使用可能なESP32ボード上のピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**回路図**

.. image:: ../../img/circuit/circuit_2.1_led.png

この回路は簡単な原理で動作し、図に示されているように電流の方向があります。ピン26が高レベルを出力すると220オームの電流制限抵抗を通過してLEDが点灯します。ピン26が低レベルを出力するとLEDが消えます。

**配線図**

.. image:: ../../img/wiring/2.1_hello_led_bb.png



**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\2.1_hello_led`` のパス下にあるファイル ``2.1_hello_led.ino`` を開くことができます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **Upload** ボタンをクリックします。
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1bff2463-40ad-43c1-8815-9f448bab3735/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



コードが正常にアップロードされた後、LEDが点滅するのを見ることができます。

**どのように動作するのか？**

#. ``ledPin`` という名前の整数定数を宣言し、それに26という値を割り当てます。

    .. code-block:: arduino

        const int ledPin = 26;  // The GPIO pin for the LED

#. 次に、 ``setup()`` 関数でピンを初期化します。ここで、ピンを ``OUTPUT`` モードに初期化する必要があります。

    .. code-block:: arduino

        void setup() {
            pinMode(ledPin, OUTPUT);
        }

    * ``void pinMode(uint8_t pin, uint8_t mode);``: この関数は、特定のピンのGPIO動作モードを定義するために使用されます。

        * ``pin`` はGPIOピン番号を定義します。
        * ``mode`` は動作モードを設定します。

        基本入出力のために、以下のモードがサポートされています：

        * ``INPUT`` はプルアップもプルダウンもない入力（高インピーダンス）としてGPIOを設定します。
        * ``OUTPUT`` は出力/読み取りモードとしてGPIOを設定します。
        * ``INPUT_PULLDOWN`` は内部プルダウン付きでGPIOを入力として設定します。
        * ``INPUT_PULLUP`` は内部プルアップ付きでGPIOを入力として設定します。

#. ``loop()`` 関数にはプログラムの主なロジックが含まれ、変更間の一秒の間隔を置いて、ピンを高低に交互に設定します。

    .. code-block:: arduino

        void loop() {
            digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(1000);                       // wait for a second
            digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
            delay(1000);                       // wait for a second
        }

    * ``void digitalWrite(uint8_t pin, uint8_t val);``: この関数は、選択したGPIOの状態を ``HIGH`` または ``LOW`` に設定します。この関数は、 ``pinMode`` が ``OUTPUT`` として設定されている場合のみ使用されます。
    
        * ``pin`` はGPIOピン番号を定義します。
        * ``val`` は出力デジタル状態を ``HIGH`` または ``LOW`` に設定します。
