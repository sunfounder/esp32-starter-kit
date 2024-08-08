.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_telegram:

8.7 ESPカメラとTelegramボット
====================================

このプロジェクトでは、お気に入りのメッセージングアプリケーションとESP32を統合する方法をデモンストレーションします。今回はTelegramを使用します。

Telegramボットを作成し、どこからでも回路を制御したり、写真を撮影したり、フラッシュを管理することができます。さらに、誰かがデバイスのそばを通るたびに、新しい写真を撮影してTelegramアカウントに通知を送信します。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

全てのキットを購入することは非常に便利です。リンクはこちらです：

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Telegramボットの作成**

#. **Google Play** または **App Store** にアクセスして **Telegram** をダウンロードしてインストールします。

#. **Telegram** アプリで ``botfather`` を検索し、表示されたらクリックして開きます。または、このリンクに直接アクセスします：t.me/botfather。

    .. image:: img/sp230515_135927.png

#. 開くと、チャットウィンドウが表示されます。コマンド ``/start`` を送信します。

    .. image:: img/sp230515_140149.png

#. ``/newbot`` と入力し、指示に従ってボットを作成します。成功すると、BotFatherは新しいボットのアクセスリンクとAPIを提供します。

    .. image:: img/sp230515_140830.png

**Telegramユーザーの承認**

誰でも作成したボットとやりとりできるため、情報が漏洩するリスクがあります。これに対処するため、承認されたユーザーにのみボットが応答するようにしたいと考えています。

#. **Telegram** アカウントで ``IDBot`` を検索するか、リンクを開きます：t.me/myidbot。

    .. image:: img/sp230515_144241.png

#. コマンド ``/getid`` を送信します。後でプログラムで使用するために、提供されたIDを保存します。

    .. image:: img/sp230515_144614.png

**コードのアップロード**

#. まずカメラを接続します。

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            お使いのブラウザーはビデオタグをサポートしていません。
        </video>

#. 回路を組み立てます。

    .. image:: ../../img/wiring/iot_7_cam_telegram_bb.png
        
#. コードを開きます。

    * ``esp32-starter-kit-main\c\codes\iot_7_cam_telegram`` ディレクトリにある ``iot_7_cam_telegram.ino`` ファイルを開くか、Arduino IDEにコードをコピーします。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``UniversalTelegramBot`` と ``ArduinoJson`` ライブラリを使用しており、 **Library Manager** からインストールできます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/d7c439b0-fca3-4648-9714-900a2859740c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 次の行を見つけて、あなたのWiFiの詳細に ``SSID`` と ``PASSWORD`` を置き換えます。

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

5. 次の行を更新し、@IDBotから取得したTelegram IDで ``CHATID`` を置き換えます。

    .. code-block:: Arduino

        // Use @myidbot to find out the chat ID of an individual or a group
        // Also note that you need to click "start" on a bot before it can
        // message you
        String chatId = "CHATID";

#. 次の行を更新し、@BotFatherから提供されたTelegram BOTのトークンで ``BOTTOKEN`` を置き換えます。

    .. code-block:: Arduino

        // Initialize Telegram BOT
        String BOTtoken = "BOTTOKEN";

#. 正しいボード（ESP32 Dev Module）とポートを選択した後、 **アップロード** ボタンをクリックします。
#. シリアルモニターを開きます。IPアドレスが表示されれば、正常に実行されたことを意味します。

    .. code-block::

        Connecting to xxxx
        ESP32-CAM IP Address: 192.168.18.76
        Init Done!

#. これで、Telegramを通じてESP32とやり取りすることができます。

    .. image:: img/sp230515_161237.png

