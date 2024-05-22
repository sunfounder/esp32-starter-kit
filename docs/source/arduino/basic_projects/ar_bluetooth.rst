.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_bluetooth:

7.1 Bluetooth
===================

このプロジェクトでは、ESP32マイクロコントローラーを使用して、シンプルなBluetooth Low Energy（BLE）シリアル通信アプリケーションを開発するためのガイドを提供します。ESP32はWi-FiとBluetoothの接続機能を統合した強力なマイクロコントローラーであり、無線アプリケーションの開発に最適です。BLEは短距離通信のために設計された低消費電力の無線通信プロトコルです。この文書では、ESP32をBLEサーバーとして設定し、シリアル接続を介してBLEクライアントと通信する手順を説明します。


**Bluetooth機能について**

ESP32 WROOM 32Eは、Wi-FiとBluetoothの接続機能を一つのチップに統合するモジュールです。これはBLEおよびクラシックBluetoothプロトコルをサポートしています。

このモジュールはBluetoothクライアントまたはサーバーとして使用することができます。Bluetoothクライアントとして、他のBluetoothデバイスに接続し、データの交換を行うことができます。Bluetoothサーバーとしては、他のBluetoothデバイスにサービスを提供します。

ESP32 WROOM 32Eは、Generic Access Profile（GAP）、Generic Attribute Profile（GATT）、Serial Port Profile（SPP）など、さまざまなBluetoothプロファイルをサポートしています。SPPプロファイルを使用すると、モジュールはBluetooth経由でシリアルポートをエミュレートし、他のBluetoothデバイスとのシリアル通信を可能にします。

ESP32 WROOM 32EのBluetooth機能を使用するには、適切なソフトウェア開発キット（SDK）を使うか、Arduino IDEとESP32 BLEライブラリを使ってプログラムする必要があります。ESP32 BLEライブラリはBLE作業を容易にするための高レベルインターフェースを提供し、モジュールをBLEクライアントおよびサーバーとして使用する方法を示す例を含んでいます。

全体として、ESP32 WROOM 32EのBluetooth機能は、プロジェクトで無線通信を容易かつ低電力で可能にする便利な方法を提供します。

**操作手順**

以下は、LightBlueアプリを使用してESP32とモバイルデバイス間のBluetooth通信を設定するための手順です：

#. **App Store** （iOS用）または **Google Play** （Android用）からLightBlueアプリをダウンロードします。

    .. image:: img/bluetooth_lightblue.png

#. ``esp32-starter-kit-main\c\codes\7.1_bluetooth`` ディレクトリにある ``7.1_bluetooth.ino`` ファイルを開くか、コードをArduino IDEにコピーします。

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/388f6d9d-65bf-4eaa-b29a-7cebf0b92f74/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. UUIDの競合を避けるため、 |link_uuid| を使用して新しいUUIDをランダムに3つ生成し、以下のコード行にそれらを入力することを推奨します。

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png


#. 正しいボードとポートを選択し、 **Upload** ボタンをクリックします。

    .. image:: img/bluetooth_upload.png

#. コードが正常にアップロードされたら、モバイルデバイスの **Bluetooth** をオンにし、 **LightBlue** アプリを開きます。

    .. image:: img/bluetooth_open.png

#. **Scan** ページで **ESP32-Bluetooth** を見つけて **CONNECT** をクリックします。見つからない場合は、数回ページを更新してみてください。 **「Connected to device!」** と表示されれば、Bluetooth接続が成功しています。コード内で設定した3つのUUIDを確認するには、下にスクロールします。

    .. image:: img/bluetooth_connect.png
        :width: 800

#. **Receive** UUIDをクリックします。右の **Data Format** ボックスで適切なデータフォーマットを選択します。例えば、「HEX」を16進数、「UTF-8 String」を文字、「Binary」を2進数などに設定します。その後、 **SUBSCRIBE** をクリックします。

    .. image:: img/bluetooth_read.png
        :width: 300

#. Arduino IDEに戻り、シリアルモニターを開いて、ボーレートを115200に設定し、「welcome」と入力してEnterキーを押します。

    .. image:: img/bluetooth_serial.png

#. これで、「welcome」というメッセージがLightBlueアプリに表示されるはずです。

    .. image:: img/bluetooth_welcome.png
        :width: 400

#. モバイルデバイスからシリアルモニターへ情報を送信するには、Send UUIDをクリックし、データフォーマットを「UTF-8 String」に設定してメッセージを書き込みます。

    .. image:: img/bluetooth_send.png


#. すると、シリアルモニターでそのメッセージが表示されるはずです。

    .. image:: img/bluetooth_receive.png

**どのように動作するのか？**

このArduinoコードはESP32マイクロコントローラー向けに書かれており、Bluetooth Low Energy（BLE）デバイスと通信するために設定されます。

コードの簡単な要約は以下の通りです：

* **必要なライブラリをインクルード**：コードはESP32でBluetooth Low Energy（BLE）を操作するために必要なライブラリをインクルードすることから始まります。

    .. code-block:: arduino

        #include "BLEDevice.h"
        #include "BLEServer.h"
        #include "BLEUtils.h"
        #include "BLE2902.h"

* **グローバル変数**：Bluetoothデバイス名(``bleName``)、受信テキストと最後のメッセージの時間を追跡するための変数、サービスとキャラクタリスティックのUUID、 ``BLECharacteristic`` オブジェクト(``pCharacteristic``)を含む一連のグローバル変数が定義されます。

    .. code-block:: arduino

        // Define the Bluetooth device name
        const char *bleName = "ESP32_Bluetooth";

        // Define the received text and the time of the last message
        String receivedText = "";
        unsigned long lastMessageTime = 0;

        // Define the UUIDs of the service and characteristics
        #define SERVICE_UUID           "your_service_uuid_here"
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

        // Define the Bluetooth characteristic
        BLECharacteristic *pCharacteristic;

* **セットアップ**： ``setup()`` 関数では、シリアルポートが115200のボーレートで初期化され、Bluetooth BLEの設定を行う ``setupBLE()`` 関数が呼び出されます。

    .. code-block:: arduino
    
        void setup() {
            Serial.begin(115200);  // Initialize the serial port
            setupBLE();            // Initialize the Bluetooth BLE
        }

* **メインループ**： ``loop()`` 関数では、BLE経由で文字列が受信された（つまり、 ``receivedText`` が空でない）場合、最後のメッセージから少なくとも1秒が経過しているとき、コードは受信した文字列をシリアルモニターに表示し、キャラクタリスティックの値を受信文字列に設定し、通知を送信し、その後で受信文字列をクリアします。シリアルポートでデータが利用可能な場合、改行文字が現れるまで文字列を読み取り、キャラクタリスティックの値をこの文字列に設定し、通知を送信します。

    .. code-block:: arduino

        void loop() {
            // When the received text is not empty and the time since the last message is over 1 second
            // Send a notification and print the received text
            if (receivedText.length() > 0 && millis() - lastMessageTime > 1000) {
                Serial.print("Received message: ");
                Serial.println(receivedText);
                pCharacteristic->setValue(receivedText.c_str());
                pCharacteristic->notify();
                receivedText = "";
            }

            // Read data from the serial port and send it to BLE characteristic
            if (Serial.available() > 0) {
                String str = Serial.readStringUntil('\n');
                const char *newValue = str.c_str();
                pCharacteristic->setValue(newValue);
                pCharacteristic->notify();
            }
        }

* **コールバック**: ブルートゥース通信に関連するイベントを処理するための2つのコールバッククラス(``MyServerCallbacks`` と ``MyCharacteristicCallbacks``)が定義されています。 ``MyServerCallbacks`` はBLEサーバーの接続状態（接続されているか切断されているか）に関連するイベントを処理するために使用されます。 ``MyCharacteristicCallbacks`` はBLEキャラクタリスティック上での書き込みイベントを処理するために使用され、つまり、接続されたデバイスがBLE経由でESP32に文字列を送信すると、それがキャプチャされ ``receivedText`` に格納され、現在の時刻が ``lastMessageTime`` に記録されます。

    .. code-block:: arduino

        // Define the BLE server callbacks
        class MyServerCallbacks : public BLEServerCallbacks {
            // Print the connection message when a client is connected
            void onConnect(BLEServer *pServer) {
            Serial.println("Connected");
            }
            // Print the disconnection message when a client is disconnected
            void onDisconnect(BLEServer *pServer) {
            Serial.println("Disconnected");
            }
        };

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                // When data is received, get the data and save it to receivedText, and record the time
                std::string value = pCharacteristic->getValue();
                receivedText = String(value.c_str());
                lastMessageTime = millis();
                Serial.print("Received: ");
                Serial.println(receivedText);
            }
        };

* **BLEのセットアップ**: ``setupBLE()`` 関数では、BLEデバイスとサーバーが初期化され、サーバーのコールバックが設定され、定義されたUUIDを使用してBLEサービスが作成され、通知送信とデータ受信用のキャラクタリスティックが作成されサービスに追加され、キャラクタリスティックのコールバックが設定されます。最後に、サービスが開始され、サーバーがアドバタイジングを開始します。

    .. code-block:: arduino

        // Initialize the Bluetooth BLE
        void setupBLE() {
            BLEDevice::init(bleName);                        // Initialize the BLE device
            BLEServer *pServer = BLEDevice::createServer();  // Create the BLE server
            // Print the error message if the BLE server creation fails
            if (pServer == nullptr) {
                Serial.println("Error creating BLE server");
                return;
            }
            pServer->setCallbacks(new MyServerCallbacks());  // Set the BLE server callbacks

            // Create the BLE service
            BLEService *pService = pServer->createService(SERVICE_UUID);
            // Print the error message if the BLE service creation fails
            if (pService == nullptr) {
                Serial.println("Error creating BLE service");
                return;
            }
            // Create the BLE characteristic for sending notifications
            pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
            pCharacteristic->addDecodeor(new BLE2902());  // Add the decodeor
            // Create the BLE characteristic for receiving data
            BLECharacteristic *pCharacteristicRX = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
            pCharacteristicRX->setCallbacks(new MyCharacteristicCallbacks());  // Set the BLE characteristic callbacks
            pService->start();                                                 // Start the BLE service
            pServer->getAdvertising()->start();                                // Start advertising
            Serial.println("Waiting for a client connection...");              // Wait for a client connection
        }

このコードにより、BLEを介してデータの双方向通信が可能です。しかし、LEDのオン/オフのような特定のハードウェアとのインタラクションには、受信した文字列を処理し、それに応じて動作する追加のコードが必要です。





