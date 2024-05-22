.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_mp3_player_sd:

7.5 SDカード対応MP3プレーヤー
==============================================

ESP32で音楽の世界へようこそ！このプロジェクトでは、あなたの指先でオーディオ処理のパワーを体験できます。ESP32は計算用の素晴らしいマイクロコントローラーだけでなく、あなた専用の音楽プレーヤーにもなります。自分の部屋に入ると、この小さなデバイスからお気に入りのトラックが流れてくるのを想像してみてください。それが、今日、私たちがあなたに提供するパワーです。

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
    *   - :ref:`cpn_audio_speaker`
        - \-

**操作手順**

#. カードリーダーを使ってSDカードをコンピュータに挿入し、フォーマットしてください。 :ref:`format_sd_card` のチュートリアルを参照してください。

#. お気に入りのMP3ファイルをSDカードにコピーします。

    .. image:: img/mp3_music.png

#. SDカードを拡張ボードのSDカードスロットに挿入します。

    .. image:: ../../img/insert_sd.png

#. 回路を組み立てます。

    これはモノラルアンプなので、IO25をオーディオアンプモジュールのLまたはRピンに接続できます。

    10K抵抗は、高周波ノイズを減らし、オーディオボリュームを下げるために使用されます。これは、DACとオーディオアンプの寄生容量とのRCローパスフィルターを形成します。このフィルターは、高周波信号の振幅を減少させ、効果的に高周波ノイズを低減します。そのため、10K抵抗を加えることで、音楽を柔らかく聞こえさせ、望ましくない高周波ノイズを排除します。

    SDカードの音楽がすでに柔らかい場合、抵抗を取り外したり、より小さい値のものに交換できます。

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. USBケーブルを使ってESP32-WROOM-32Eをコンピュータに接続します。

    .. image:: ../../img/plugin_esp32.png

#. コードを変更します。

    ``file = new AudioFileSourceSD_MMC("/To Alice.mp3")`` の行を、あなたのファイル名とパスに合わせて変更してください。

    .. note::

        * ``esp32-starter-kit-main\c\codes\7.5_mp3_player_sd`` のパスの下にある ``7.5_mp3_player_sd.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。
        * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
        * :ref:`unknown_com_port`
        * ここでは ``ESP8266Audio`` ライブラリが使用されています。インストールのチュートリアルについては、 :ref:`install_lib_man` を参照してください。
        

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/13f5c757-9622-4735-aa1a-fdbe6fc46273/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. Arduino IDEで適切なポートとボードを選択し、ESP32にコードをアップロードします。

#. コードのアップロードに成功すると、お気に入りの音楽が再生されます。


**どのように動作するのか？**

* コードは ``ESP8266Audio`` ライブラリの複数のクラスを使用して、SDカードからMP3ファイルをI2Sを通じて再生します。

    .. code-block:: arduino

        #include "AudioFileSourceSD_MMC.h"
        #include "AudioOutputI2S.h"
        #include "AudioGeneratorMP3.h"
        #include "SD_MMC.h"
        #include "FS.h"

    * ``AudioGeneratorMP3`` はMP3オーディオをデコードするクラスです。
    * ``AudioFileSourceSD_MMC`` はSDカードからオーディオデータを読み取るクラスです。
    * ``AudioOutputI2S`` はオーディオデータをI2Sインターフェースに送信するクラスです。

* ``setup()`` 関数では、SDカードを初期化し、SDカードからMP3ファイルを開き、ESP32の内蔵DACでI2S出力を設定し、出力をモノラルに設定し、MP3ジェネレータを開始します。

    .. code-block:: arduino

        void setup() {
            // Start the serial communication.
            Serial.begin(115200);
            delay(1000);

            // Initialize the SD card. If it fails, print an error message.
            if (!SD_MMC.begin()) {
                Serial.println("SD card mount failed!");
            }

            // Open the MP3 file from the SD card. Replace "/To Alice.mp3" with your own MP3 file name.
            file = new AudioFileSourceSD_MMC("/To Alice.mp3");
            
            // Set up the I2S output on ESP32's internal DAC.
            out = new AudioOutputI2S(0, 1);
            
            // Set the output to mono.
            out->SetOutputModeMono(true);

            // Initialize the MP3 generator with the file and output.
            mp3 = new AudioGeneratorMP3();
            mp3->begin(file, out);
        }


* ``loop()`` 関数では、MP3ジェネレータが実行中であるかを確認します。実行中であれば、それを継続してループさせます。そうでない場合は、それを停止し、シリアルモニターに「MP3終了」と表示します。

    .. code-block:: arduino

        void loop() {
            // If the MP3 is running, loop it. Otherwise, stop it.
            if (mp3->isRunning()) {
                if (!mp3->loop()) mp3->stop();
            } 
            // If the MP3 is not running, print a message and wait for 1 second.
            else {
                Serial.println("MP3 done");
                delay(1000);
            }
        }


