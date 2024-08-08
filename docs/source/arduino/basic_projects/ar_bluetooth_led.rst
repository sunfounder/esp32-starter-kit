.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_bluetooth_led:

7.2 Bluetoothを用いたRGB LEDの制御
=====================================

このプロジェクトは以前のプロジェクト（:ref:`ar_bluetooth`）を拡張したもので、RGB LEDの設定と「led_off」、「red」、「green」などのカスタムコマンドを追加しています。これらのコマンドにより、LightBlueを使用してモバイルデバイスからのコマンドを送信することでRGB LEDを制御できます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入することは間違いなく便利です。こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

または、以下のリンクから個別に購入することもできます。

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**操作手順**

#. 回路を組み立てます。

    .. image:: ../../components/img/rgb_pin.jpg
        :width: 200
        :align: center

    RGB LEDには4本のピンがあります。一番長いピンは共通カソードピンで、通常GNDに接続されます。一番長いピンの隣の左ピンが赤、右側の二本が緑と青です。

    .. image:: ../../img/wiring/2.3_color_light_bb.png

#. ``esp32-starter-kit-main\c\codes\7.2_bluetooth_rgb_led`` ディレクトリにある ``7.2_bluetooth_rgb_led.ino`` ファイルを開くか、コードをArduino IDEにコピーします。

    .. raw:: html
         
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b9331c9d-e9ea-4970-87ce-bf2ca8c231b2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. UUIDの衝突を避けるため、Bluetooth SIGが提供する |link_uuid| を使ってランダムに3つの新しいUUIDを生成し、コードの以下の行に記入することをお勧めします。

    .. note::
        もし :ref:`ar_bluetooth` プロジェクトで既に3つの新しいUUIDを生成している場合は、それらを引き続き使用できます。

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png

#. 正しいボードとポートを選択し、 **アップロード** ボタンをクリックします。

#. コードが正常にアップロードされた後、モバイルデバイスの **Bluetooth** をオンにし、 **LightBlue** アプリを開きます。

    .. image:: img/bluetooth_open.png

#. **Scan** ページで **ESP32-Bluetooth** を見つけ、 **CONNECT** をクリックします。見つからない場合は、数回ページを更新してみてください。 **「Connected to device!」** と表示されると、Bluetooth接続が成功しています。コードで設定された3つのUUIDを見るために下にスクロールします。

    .. image:: img/bluetooth_connect.png
        :width: 800

#. 送信用UUIDをタップし、データ形式を"UTF-8 String"に設定します。これで、「led_off」、「red」、「green」、「blue」、「yellow」、「purple」というコマンドを書き込んで、RGB LEDがこれらの指示に反応するかどうかを確認できます。

    .. image:: img/bluetooth_send_rgb.png
    

**どのように動作するのか？**

このコードは、以前のプロジェクト(:ref:`ar_bluetooth`)の拡張版であり、RGB LED設定と「led_off」、「red」、「green」などのカスタムコマンドを追加しています。これらのコマンドにより、LightBlueを使用してモバイルデバイスからのコマンドを送信することでRGB LEDを制御できます。

コードをステップバイステップで分解してみましょう：

* RGB LEDピン、PWMチャンネル、周波数、解像度に関する新しいグローバル変数を追加します。

    .. code-block:: arduino

        ...

        // Define RGB LED pins
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;
        ...

* ``setup()`` 関数内では、PWMチャンネルが定義済みの周波数と解像度で初期化されます。次に、RGB LEDのピンをそれぞれのPWMチャンネルに割り当てます。

    .. code-block:: arduino
        
        void setup() {
            ...
            ledcAttach(redPin, freq, resolution);
            ledcAttach(greenPin, freq, resolution);
            ledcAttach(bluePin, freq, resolution);

        }

* ``MyCharacteristicCallbacks`` クラスの ``onWrite`` メソッドを変更します。この関数は、Bluetooth接続から来るデータを監視します。受信した文字列（ ``「led_off」``, ``「red」``, ``「green」`` など）に基づいて、RGB LEDを制御します。

    .. code-block:: arduino

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                std::string value = std::string(pCharacteristic->getValue().c_str());
                if (value == "led_off") {
                    setColor(0, 0, 0); // turn the RGB LED off
                    Serial.println("RGB LED turned off");
                } else if (value == "red") {
                    setColor(255, 0, 0); // Red
                    Serial.println("red");
                }
                else if (value == "green") {
                    setColor(0, 255, 0); // green
                    Serial.println("green");
                }
                else if (value == "blue") {
                    setColor(0, 0, 255); // blue
                    Serial.println("blue");
                }
                else if (value == "yellow") {
                    setColor(255, 150, 0); // yellow
                    Serial.println("yellow");
                }
                else if (value == "purple") {
                    setColor(80, 0, 80); // purple
                    Serial.println("purple");
                }
            }
        };

* 最後に、RGB LEDの色を設定する関数を追加します。

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // For common-anode RGB LEDs, use 255 minus the color value
            ledcWrite(redPin, red);
            ledcWrite(greenPin, green);
            ledcWrite(bluePin, blue);
        }

要約すると、このスクリプトはリモートコントロールの対話モデルを実現します。ここではESP32がBluetooth Low Energy (BLE) サーバーとして動作します。

接続されたBLEクライアント（スマートフォンなど）は文字列のコマンドを送信してRGB LEDの色を変更することができます。ESP32は実行された操作をクライアントに知らせるために受信した文字列をクライアントに返信し、フィードバックを与えます。

