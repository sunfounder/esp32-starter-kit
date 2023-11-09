8.2 カメラウェブサーバー
=============================

このプロジェクトは、ESP32ボードとカメラモジュールを組み合わせて、ローカルネットワーク上で高品質のビデオをストリーム配信します。
自分だけのカメラシステムを簡単に設定し、リアルタイムで任意の場所を監視できます。

プロジェクトのウェブインターフェイスを使用すると、ネットワークに接続された任意のデバイスからカメラのフィードにアクセスして制御できます。
カメラ設定をカスタマイズしてストリーミング体験を最適化し、ユーザーフレンドリーなインターフェイスで設定を簡単に調整できます。

多用途に対応したESP32カメラストリーミングプロジェクトで、監視またはライブストリーミングの機能を向上させましょう。自宅、オフィス、または任意の場所を容易にかつ確実に監視できます。

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

**どうやって行うのか？**

#. まず、カメラを接続します。

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. 次に、USBケーブルを使ってESP32-WROOM-32Eをコンピューターに接続します。

    .. image:: ../../img/plugin_esp32.png

#. コードを開きます。

    * ``esp32-starter-kit-main\c\codes\iot_2_camera_server`` ディレクトリ内にある ``iot_2_camera_server.ino`` ファイルを開くか、Arduino IDEにコードをコピーします。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/15e00b39-34e1-49f9-b039-f10053d31407/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. 次の行を見つけて、あなたの ``<SSID>`` と ``<PASSWORD>`` で修正してください。

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. 今度は、 **PSRAM** を有効にします。

    .. image:: img/sp230516_150554.png

#. パーティションスキームを **Huge APP (3MB No OTA/1MB SPIFFS)** に設定します。

    .. image:: img/sp230516_150840.png

#. 正しいボード（ESP32 Dev Module）とポートを選択した後、"アップロード"ボタンをクリックします。

#. シリアルモニターで成功したWiFi接続のメッセージと割り当てられたIPアドレスが表示されます。

    .. code-block::

        .....
        WiFi connected
        Starting web server on port: '80'
        Starting stream server on port: '81'
        Camera Ready! Use 'http://192.168.18.77' to connect

#. WebブラウザでIPアドレスを入力します。 **Start Stream** をクリックしてカメラのフィードを表示できるウェブインターフェイスが表示されます。

    .. image:: img/sp230516_151521.png

#. ページの一番上までスクロールバックします。そこでは、ライブカメラフィードが見られます。インターフェイスの左側で設定を調整できます。

    .. image:: img/sp230516_180520.png

.. note:: 

    * このESP32モジュールは顔検出をサポートしています。有効にするには、解像度を240x240に設定し、インターフェイスの下部にある顔検出オプションを切り替えます。
    * このESP32モジュールは顔認識をサポートしていません。
