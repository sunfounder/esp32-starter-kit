8.5 CheerLights
===============================
CheerLightsは、誰でも制御できる同期したライトのグローバルネットワークです。

|link_cheerlights| のLEDカラーチェンジコミュニティに参加し、世界中のLEDが同時に色を変えることができます。

オフィスの一角にLEDを置いて、自分が一人ではないことを思い出せます。

このケースでは、MQTTを利用しますが、自分自身のメッセージを公開する代わりに、「cheerlights」トピックをサブスクライブします。これにより、「cheerlights」トピックに他の人が送信したメッセージを受信し、その情報に基づいて自分のLEDストリップの色を変更することができます。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが間違いなく便利です。リンクはこちらです：

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|


**どのように実行しますか？**

#. 回路を組み立てます。

    .. image:: ../../img/wiring/iot_5_cheerlight_bb.png

#. 次に、USBケーブルを使ってESP32-WROOM-32Eをコンピュータに接続します。

    .. image:: ../../img/plugin_esp32.png

#. コードを開きます。

    * ``esp32-starter-kit-main\c\codes\iot_5_cheerlights`` ディレクトリにある ``iot_5_cheerlights.ino`` ファイルを開くか、Arduino IDEにコードをコピーします。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``PubSubClient`` と ``Adafruit_NeoPixel`` ライブラリが使用されており、 **Library Manager** からインストールできます。

        .. image:: img/mqtt_lib.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4fc7b0ff-db8e-4bf3-ad34-d68c1857794b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 次の行を見つけて、あなたの ``<SSID>`` と ``<PASSWORD>`` で修正してください。

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. 次の行を見つけて、あなたの ``unique_identifier`` で修正してください。 ``unique_identifier`` が本当にユニークであることを保証してください。同一のIDを持つデバイスが同じ **MQTT Broker** にログインしようとすると、ログインに失敗する可能性があります。

    .. code-block::  Arduino

        // Add your MQTT Broker address:
        const char* mqtt_server = "mqtt.cheerlights.com";
        const char* unique_identifier = "sunfounder-client-sdgvsasdda";    

#. 正しいボード（ESP32 Dev Module）とポートを選択した後、 **アップロード** ボタンをクリックします。

#. この時点で、RGBストリップが特定の色を表示していることがわかります。デスクに置いてみると、定期的に色が変わるのが分かります。これは他の@CheerLightsフォロワーがあなたのライトの色を変えているからです！

#. シリアルモニターを開きます。次のようなメッセージが表示されます：

.. code-block:: 
  
    WiFi connected
    IP address: 
    192.168.18.77
    Attempting MQTT connection...connected
    Message arrived on topic: cheerlights. 
    Message: oldlace
    Changing color to oldlace

**グローバルな@CheerLightsデバイスを制御する**

#. |link_discord_server| に参加して、CheerLightsボットを使用して色を設定してください。 **CheerLights Discordサーバー** のチャンネルで ``/cheerlights`` と入力するだけでボットが起動します。

    .. image:: img/sp230511_163558.png

#. ボットが提供する指示に従って色を設定してください。これにより、グローバルにCheerLightsデバイスを制御できます。

    .. image:: img/sp230511_163849.png
