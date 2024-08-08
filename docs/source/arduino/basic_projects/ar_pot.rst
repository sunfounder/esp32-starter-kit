.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_potentiometer:

5.8 ノブを回す
===================

ポテンショメータは、回路の抵抗を調節するために一般的に使用される3端子デバイスです。これにはノブまたはスライディングレバーが備えられており、ポテンショメータの抵抗値を変化させることができます。このプロジェクトでは、日常生活のデスクランプのように、LEDの明るさを制御するためにそれを活用します。ポテンショメータの位置を調整することにより、回路の抵抗を変更し、それによってLEDを流れる電流を調節し、その明るさを適宜調整することができます。これにより、デスクランプのようなカスタマイズ可能で調節可能な照明体験を作り出すことができます。

**必要な部品**

このプロジェクトには以下のコンポーネントが必要です。

全てのキットを購入するのは非常に便利です。こちらがリンクです：

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

**利用可能なピン**

* **利用可能なピン**

    こちらは、このプロジェクトのためのESP32ボード上の利用可能なピンのリストです。

    .. list-table::
        :widths: 5 15

        *   - 利用可能なピン
            - IO14, IO25, I35, I34, I39, I36

* **ストラッピングピン**

    以下のピンはストラッピングピンであり、電源オンまたはリセット時のESP32の起動プロセスに影響を与えます。しかし、ESP32が正常に起動した後、通常のピンとして使用できます。

    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO0, IO12


**回路図**

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

ポテンショメータを回すと、I35の値が変わります。プログラミングにより、I35の値を使用してLEDの明るさを制御できます。そのため、ポテンショメータを回すと、LEDの明るさもそれに応じて変化します。


**配線図**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**コード**


.. note::

    * ``esp32-starter-kit-main\c\codes\5.8_pot`` のパスの下にあるファイル ``5.8_pot.ino`` を開くことができます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
   
.. raw:: html
     
    <iframe src=https://create.arduino.cc/editor/sunfounder01/aadce2e7-fd5d-4608-a557-f1e4d07ba795/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、ポテンショメータを回すと、LEDの明るさがそれに応じて変わるのが見えます。同時に、シリアルモニタでポテンショメータのアナログ値と電圧値を確認できます。


**どのように動作するのか？**

#. ピン接続とPWM設定のための定数を定義します。

    .. code-block:: arduino

        const int potPin = 35; // Potentiometer connected to
        const int ledPin = 26; // LED connected to

        // PWM settings
        const int freq = 5000; // PWM frequency
        const int resolution = 12; // PWM resolution (bits)

    ここではPWMの解像度を12ビットに設定し、範囲は0-4095になります。

#. ``setup()`` 関数でシステムを構成します。

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);

            // Configure PWM
            ledcAttach(ledPin, freq, resolution);
        }

    * ``setup()`` 関数では、ボーレート115200でシリアル通信を開始します。
    * 指定されたLEDピンを指定された周波数と解像度で設定するために ``ledcAttach()`` 関数が呼び出されます。

#. ``loop()`` 関数のメインループ（繰り返し実行される）。

    .. code-block:: arduino

        void loop() {

            int potValue = analogRead(potPin); // read the value of the potentiometer
            uint32_t voltage_mV = analogReadMilliVolts(potPin); // Read the voltage in millivolts
            
            ledcWrite(channel, potValue);
            
            Serial.print("Potentiometer Value: ");
            Serial.print(potValue);
            Serial.print(", Voltage: ");
            Serial.print(voltage_mV / 1000.0); // Convert millivolts to volts
            Serial.println(" V");
            
            delay(100);
        }

    * ``uint32_t analogReadMilliVolts(uint8_t pin);``: この関数は指定されたピン/ADCチャンネルのADC値をミリボルト単位で取得するために使用されます。

        * ``pin`` アナログ値を読むGPIOピン。

    ポテンショメータの値は ``ledcWrite()`` 関数を通じてLEDの明るさを制御するPWMデューティサイクルとして直接使用されます。値の範囲も0から4095です。

