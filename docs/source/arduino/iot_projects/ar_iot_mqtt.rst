.. _ar_iot_mqtt:

8.4 IoT通信とMQTT
=======================================

このプロジェクトは、IoT（モノのインターネット）分野で人気のある通信プロトコルであるMQTTを活用することに焦点を当てています。MQTTは、IoTデバイスがトピックを通じてデータを交換するパブリッシュ/サブスクライブモデルを可能にします。

このプロジェクトでは、LED、ボタン、サーミスタを含む回路を構築することでMQTTの実装を探求します。ESP32-WROOM-32Eマイクロコントローラーは、Wi-Fiへの接続を確立し、MQTTブローカーと通信するために使用されます。コードにより、マイクロコントローラーは特定のトピックをサブスクライブし、メッセージを受信し、受信した情報に基づいてLEDを制御することができます。さらに、このプロジェクトは、ボタンが押されたときにサーミスタからの温度データを指定されたトピックに公開することを示しています。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが非常に便利です。リンクはこちらです：

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**コードアップロード**

#. 回路を組み立てます。

    .. note:: 
        Wi-Fiへの接続を確立する際には、36, 39, 34, 35, 32, 33ピンのみがアナログ読取りに使用できます。サーミスタがこれら指定されたピンに接続されていることを確認してください。

    .. image:: ../../img/wiring/iot_4_matt_bb.png

#. 次に、USBケーブルを使ってESP32-WROOM-32Eをコンピュータに接続します。

    .. image:: ../../img/plugin_esp32.png

#. コードを開きます。

    * ``esp32-starter-kit-main\c\codes\iot_4_mqtt`` ディレクトリにある ``iot_4_mqtt.ino`` ファイルを開くか、Arduino IDEにコードをコピーします。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``PubSubClient`` ライブラリが使用されており、 **Library Manager** からインストールできます。

        .. image:: img/mqtt_lib.png
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/e45a4bd6-9b35-47f0-af5e-92d802004087/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 次の行を見つけて、あなたの ``<SSID>`` と ``<PASSWORD>`` で修正してください。

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. 次の行を見つけて、あなたの ``unique_identifier`` で修正してください。あなたの ``unique_identifier`` が本当にユニークであることを保証してください。同一のIDを持つデバイスが同じMQTTブローカーにログインしようとすると、ログインに失敗する可能性があります。

    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";
        const char* unique_identifier = "sunfounder-client-sdgvsda";  

**トピックのサブスクリプション**

#. 他の参加者からのメッセージの干渉を避けるために、目立たない、または一般的でない文字列として設定できます。現在のトピック ``SF/LED`` を、あなたの望むトピック名に単純に置き換えてください。

    .. note:: 
        トピックは、あなたが望むどんな文字にも設定できます。同じトピックにサブスクライブしたMQTTデバイスは、同じメッセージを受け取ることができます。また、複数のトピックに同時にサブスクライブすることもできます。

    .. code-block::  Arduino
        :emphasize-lines: 9

        void reconnect() {
            // Loop until we're reconnected
            while (!client.connected()) {
                Serial.print("Attempting MQTT connection...");
                // Attempt to connect
                if (client.connect(unique_identifier)) {
                    Serial.println("connected");
                    // Subscribe
                    client.subscribe("SF/LED");
                } else {
                    Serial.print("failed, rc=");
                    Serial.print(client.state());
                    Serial.println(" try again in 5 seconds");
                    // Wait 5 seconds before retrying
                    delay(5000);
                }
            }
        }

#. サブスクライブしているトピックに応答する機能を変更します。提供されたコードでは、トピック ``SF/LED`` でメッセージを受信すると、 ``on`` または ``off`` かどうかを確認します。受信したメッセージに応じて、LEDのオン/オフ状態を制御する出力状態を変更します。

    .. note::
       サブスクライブしている任意のトピックに対して変更できますし、複数のトピックに対応するために複数のif文を書くこともできます。

    .. code-block::  arduino
        :emphasize-lines: 15

        void callback(char* topic, byte* message, unsigned int length) {
            Serial.print("Message arrived on topic: ");
            Serial.print(topic);
            Serial.print(". Message: ");
            String messageTemp;

            for (int i = 0; i < length; i++) {
                Serial.print((char)message[i]);
                messageTemp += (char)message[i];
            }
            Serial.println();

            // If a message is received on the topic "SF/LED", you check if the message is either "on" or "off".
            // Changes the output state according to the message
            if (String(topic) == "SF/LED") {
                Serial.print("Changing state to ");
                if (messageTemp == "on") {
                    Serial.println("on");
                    digitalWrite(ledPin, HIGH);
                } else if (messageTemp == "off") {
                    Serial.println("off");
                    digitalWrite(ledPin, LOW);
                }
            }
        }

#. 正しいボード（ESP32 Dev Module）とポートを選択した後、 **アップロード** ボタンをクリックします。

#. シリアルモニターを開いて、以下の情報が表示されれば、MQTTサーバーへの接続が成功したことを意味します。

    .. code-block:: 

        WiFi connected
        IP address: 
        192.168.18.77
        Attempting MQTT connection...connected

**HiveMQを通じたメッセージ公開**

HiveMQは、MQTTブローカーとして機能するメッセージングプラットフォームで、IoTデバイスへの迅速で効率的かつ信頼性の高いデータ転送を促進します。

私たちのコードは、HiveMQが提供するMQTTブローカーを具体的に利用しています。コード内には、HiveMQのMQTTブローカーのアドレスが次のように含まれています：


    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";

#. 現在、Webブラウザで |link_hivemq| を開きます。

#. クライアントをデフォルトの公開プロキシに接続します。

    .. image:: img/sp230512_092258.png

#. サブスクライブしたトピックでメッセージを公開します。このプロジェクトでは、 ``on`` または ``off`` を公開してLEDを制御できます。

    .. image:: img/sp230512_140234.png

**MQTTへのメッセージ公開**

コードを使用してトピックに情報を公開することもできます。このデモでは、ボタンを押したときにサーミスタで測定した温度をトピックに送信する機能をコーディングしました。

#. **Add New Topic Subscription** をクリックします。

    .. image:: img/sp230512_092341.png

#. フォローしたいトピックを入力して、 **サブスクライブ** をクリックします。コードでは、温度情報をトピック ``SF/TEMP`` に送信しています。

    .. code-block::  Arduino
        :emphasize-lines: 14

        void loop() {
            if (!client.connected()) {
                reconnect();
            }
            client.loop();

            // if the button pressed, publish the temperature to topic "SF/TEMP"
            if (digitalRead(buttonPin)) {
                    long now = millis();
                    if (now - lastMsg > 5000) {
                    lastMsg = now;
                    char tempString[8];
                    dtostrf(thermistor(), 1, 2, tempString);
                    client.publish("SF/TEMP", tempString);
                }
            }
        }

#. これで、HiveMQでこのトピックを監視することができ、公開した情報を見ることができます。

    .. image:: img/sp230512_154342.png
