8.3 カスタムビデオストリーミングウェブサーバー
===============================================

カスタムビデオストリーミングウェブサーバープロジェクトは、ウェブページをゼロから作成し、ビデオストリームを再生するためのカスタマイズ方法を学ぶ機会を提供します。さらに、LEDの明るさを制御するためのONとOFFのようなインタラクティブなボタンを取り入れることができます。

このプロジェクトを構築することで、ウェブ開発、HTML、CSS、JavaScriptの実践経験を得ることができます。リアルタイムでビデオストリームを表示できるレスポンシブなウェブページを作成する方法を学びます。さらに、インタラクティブなボタンを統合してLEDの状態を制御し、ダイナミックなユーザーエクスペリエンスを提供する方法を発見します。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが確かに便利です。リンクはこちらです：

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

**どのように実行しますか？**

#. まずカメラを接続します。

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. 回路を組み立てます。

    .. image:: ../../img/wiring/iot_3_html_led_bb.png

#. 次に、USBケーブルを使ってESP32-WROOM-32Eをコンピュータに接続します。

    .. image:: ../../img/plugin_esp32.png

#. コードを開きます。

    * ``esp32-starter-kit-main\c\codes\iot_3_html_cam_led`` ディレクトリにある ``iot_3_html_cam_led.ino`` ファイルを開くか、Arduino IDEにコードをコピーします。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a5e33c30-63dc-4987-94c3-89bc6a599e24/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 次の行を見つけて、あなたの ``<SSID>`` と ``<PASSWORD>`` で修正してください。

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. 正しいボード（ESP32 Dev Module）とポートを選択した後、 **アップロード** ボタンをクリックします。

#. シリアルモニタで成功したWiFi接続のメッセージと割り当てられたIPアドレスが表示されます。

    .. code-block:: 

        WiFi connected
        Camera Stream Ready! Go to: http://192.168.18.77

#. WebブラウザでIPアドレスを入力します。下記のウェブページが表示され、カスタマイズされたONとOFFボタンを使用してLEDを制御できます。

    .. image:: img/sp230510_180503.png 

#. バッテリーを拡張ボードに挿入し、USBケーブルを取り外します。これで、Wi-Fi範囲内であればどこにでもデバイスを設置できます。

    .. image:: ../../img/plugin_battery.png

