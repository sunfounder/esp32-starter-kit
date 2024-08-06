.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_adafruit_io:

8.6 Adafruit IOを使った温度と湿度のモニタリング
=============================================================

このプロジェクトでは、人気のあるIoTプラットフォームの使用方法を案内します。プログラミング愛好家向けに、オンラインで多くの無料（または低コスト）プラットフォームが利用可能です。例としてはAdafruit IO、Blynk、Arduino Cloud、ThingSpeakなどがあります。これらのプラットフォームの使用方法は非常に似ています。ここでは、Adafruit IOに焦点を当てます。

DHT11センサーを使用して温度と湿度の読み取りをAdafruit IOのダッシュボードに送信するArduinoプログラムを書きます。また、ダッシュボードのスイッチを通じて回路上のLEDを制御することもできます。

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

**ダッシュボードの設定**

#. |link_adafruit_io| にアクセスし、 **Start for free** をクリックして無料アカウントを作成します。

    .. image:: img/sp230516_102503.png

#. フォームに記入してアカウントを作成します。

    .. image:: img/sp230516_102629.png

#. Adafruitアカウントを作成した後、Adafruit ioを再度開いてください。 **Dashboards** をクリックし、次に **New Dashboard** をクリックします。

    .. image:: img/sp230516_103347.png

#. **New Dashboard** を作成します。

    .. image:: img/sp230516_103744.png

#. 新しく作成された **Dashboard** に入り、新しいブロックを作成します。

    .. image:: img/sp230516_104234.png

#. 1つの **Toggle** ブロックを作成します。

    .. image:: img/sp230516_105727.png

#. ここで新しいフィードを作成する必要があります。このトグルはLEDの制御に使用されるので、このフィードには「LED」という名前を付けます。

    .. image:: img/sp230516_105641.png

#. **LED** フィードを確認し、次のステップに進みます。

    .. image:: img/sp230516_105925.png

#. ブロック設定（主にブロックタイトル、オンテキスト、オフテキスト）を完了し、右下の **Create block** ボタンをクリックして終了します。

    .. image:: img/sp230516_110124.png

#. 次に、温度と湿度を表示するために使用される **Text Blocks** を2つ作成する必要があります。したがって、 **temperature** と **humidity** という名前の2つのフィードを作成します。

    .. image:: img/sp230516_110657.png

#. 作成後、ダッシュボードは以下のようになります。

    .. image:: img/sp230516_111134.png

#. ダッシュボードの **Edit Layout** オプションを使用してレイアウトを調整できます。

    .. image:: img/sp230516_111240.png

#. **API KEY** をクリックすると、ユーザー名と **API KEY** が表示されます。これらはコードで必要になるのでメモしておきます。

    .. image:: img/sp230516_111641.png

**コードの実行**

#. 回路を組み立てます。

    .. image:: ../../img/wiring/iot_6_adafruit_io_bb.png

#. 次に、USBケーブルを使ってESP32-WROOM-32Eをコンピュータに接続します。

    .. image:: ../../img/plugin_esp32.png

#. コードを開きます。

    * ``esp32-starter-kit-main\c\codes\iot_6_adafruit_io`` ディレクトリにある ``iot_6_adafruit_io.ino`` ファイルを開くか、Arduino IDEにコードをコピーします。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``Adafruit_MQTT Library`` と ``DHT sensor library`` が使用されており、 **Library Manager** からインストールできます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4cf6ad03-250e-4fe9-aa04-0ca73b997843/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 次の行を見つけて、 ``SSID`` と ``PASSWORD`` をあなたのWiFiネットワークの詳細に置き換えます。

    .. code-block::  Arduino

        /************************* WiFi Access Point *********************************/

        #define WLAN_SSID "SSID"
        #define WLAN_PASS "PASSWORD"

#. そして、 ``YOUR_ADAFRUIT_IO_USERNAME`` をあなたのAdafruit IOのユーザー名に、 ``YOUR_ADAFRUIT_IO_KEY`` を先ほどコピーした **API KEY** に置き換えます。

    .. code-block::  Arduino

        // Adafruit IO Account Configuration
        // (to obtain these values, visit https://io.adafruit.com and click on Active Key)
        #define AIO_USERNAME "YOUR_ADAFRUIT_IO_USERNAME"
        #define AIO_KEY      "YOUR_ADAFRUIT_IO_KEY"

#. 正しいボード（ESP32 Dev Module）とポートを選択した後、 **アップロード** ボタンをクリックします。

#. コードが正常にアップロードされると、シリアルモニターに次のメッセージが表示され、Adafruit IOとの通信が成功したことがわかります。

    .. code-block::

        Adafruit IO MQTTS (SSL/TLS) Example


        Connecting to xxxxx
        WiFi connected
        IP address: 
        192.168.18.76
        Connecting to MQTT... MQTT Connected!
        Temperature: 27.10
        Humidity: 61.00

#. Adafruit IOに戻ります。これで、ダッシュボード上で温度と湿度の読み取りを観察することができますし、LEDトグルスイッチを利用して回路に接続された外部LEDのオン/オフ状態を制御することもできます。

    .. image:: img/sp230516_143220.png


