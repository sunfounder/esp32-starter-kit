.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_dht11:

5.13 温度・湿度センサー
=======================================

DHT11は、環境測定用によく使われる温度・湿度センサーです。このデジタルセンサーは、温度と湿度の値を提供するためにマイクロコントローラと通信します。

このプロジェクトでは、DHT11センサーからのデータを読み取り、検出された温度と湿度の値を表示します。

センサーから提供されたデータを読むことにより、現在の環境の温度と湿度の値を得ることができます。これらの値は、環境のリアルタイムモニタリング、天気観測、室内の気候制御、湿度レポートなどに使用できます。

**必要な部品**

このプロジェクトには以下のコンポーネントが必要です。

全キットを購入することは確かに便利です。こちらがリンクです:

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

**利用可能なピン**

こちらは、このプロジェクトのためにESP32ボードで利用可能なピンのリストです。

.. list-table::
    :widths: 5 20

    *   - 利用可能なピン
        - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_5.13_dht11.png


**配線図**

.. image:: ../../img/wiring/5.13_dht11_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\5.13_dht11`` のパスの下にある ``5.13_dht11.ino`` ファイルを開いてください。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``DHT sensor library`` ライブラリが使用されています。 **Library Manager** からインストールできます。

        .. image:: img/dht_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/95bef6dc-a4db-4315-9308-6663b77ddfa0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

シリアル通信のボーレートを115200に設定することを忘れないでください。

コードが正常にアップロードされた後、シリアルモニターには温度と湿度が連続して表示され、プログラムが安定して実行されるにつれて、これらの値はより正確になっていきます。


**どのように動作するのか？**

1. ``DHT.h`` ライブラリをインクルードし、DHTセンサーとのインタラクションに必要な機能を提供します。次に、DHTセンサーのピンとタイプを設定します。

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 14  // Set the pin connected to the DHT11 data pin
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

2. シリアル通信をボーレート115200で初期化し、DHTセンサーを初期化します。

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

3. ``loop()`` 関数内で、DHT11センサーから温度と湿度の値を読み取り、それらをシリアルモニターに出力します。

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * ``dht.readHumidity()`` 関数は、DHTセンサーから湿度値を読み取るために呼び出されます。
    * ``dht.readTemperature()`` 関数は、温度値を読み取るために呼び出されます。
    * ``isnan()`` 関数は、読み取り値が有効かどうかをチェックするために使用されます。湿度または温度の値がNaN（数値ではない）の場合、センサーからの読み取りが失敗したことを示し、エラーメッセージが出力されます。

**さらに学ぶ**

I2C LCD1602にも温度と湿度を表示できます。


.. note::

    * ``euler-kit/arduino/5.10_thermistor_lcd`` のパスの下にある ``5.10_thermistor_lcd.ino`` ファイルを開いてください。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``LiquidCrystal_I2C`` と ``DHT sensor library`` ライブラリが使用されています。 **Library Manager** からインストールできます。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fb46ba7e-0a09-4805-87ab-f733e23eb920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    