.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _bluetooth_audio_player:

7.3 Bluetooth Audio Player
==============================

このプロジェクトの目的は、ESP32の内蔵DACを使ってBluetooth対応デバイスから音声を再生するシンプルな解決策を提供することです。

このプロジェクトでは、 ``ESP32-A2DP`` ライブラリを使用してBluetooth対応デバイスから音声データを受信します。受信した音声データは、I2Sインターフェイスを使用してESP32の内部DACに送信されます。I2Sインターフェイスは、マスターモード、トランスミットモード、DAC内蔵モードで動作するように設定されます。その後、DACに接続されたスピーカーから音声データが再生されます。

ESP32の内部DACを使用する場合、出力電圧レベルは1.1Vに限定されていることに注意が必要です。そのため、出力電圧レベルを望ましいレベルまで増幅するために外部アンプを使用することを推奨します。また、再生時に歪みやノイズが発生しないように、音声データが正しい形式とサンプルレートであることを確認することも重要です。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

全てのキットを買うのが便利です。こちらがリンクです：

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

#. 回路を組み立てます。

    これはモノラルアンプなので、オーディオアンプモジュールのLまたはRピンにIO25を接続できます。

    10K抵抗は、高周波ノイズを低減し、オーディオのボリュームを下げるために使用されます。これはDACとオーディオアンプの寄生容量とRCローパスフィルタを形成し、高周波信号の振幅を減少させ、高周波ノイズを効果的に減少させます。そのため、10K抵抗を追加すると音楽がより柔らかく聞こえ、望ましくない高周波ノイズを排除します。

    SDカードの音楽が既に十分に柔らかい場合は、抵抗を取り外すか、小さい値の抵抗に置き換えることができます。

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. コードを開きます。

    * ``esp32-starter-kit-main\c\codes\7.3_bluetooth_audio_player`` のパスの下にある ``7.3_bluetooth_audio_player.ino`` ファイルを開きます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``ESP32-A2DP`` ライブラリを使用しています。インストールのチュートリアルについては :ref:`install_lib_man` を参照してください。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/7bb7d6dd-72d4-4529-bb42-033b38558347/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. 正しいボードとポートを選択した後、アップロードボタンをクリックします。

#. コードのアップロードが成功したら、Bluetooth対応デバイスをオンにして利用可能なデバイスを検索し、 ``ESP32_Bluetooth`` に接続します。

    .. image:: img/connect_bluetooth.png

#. デバイスで音声を再生すると、ESP32に接続されたスピーカーから音声が出力されるはずです。


**コードの説明**

#. このコードは、Bluetooth対応デバイスからのオーディオデータを受信するために使用される ``BluetoothA2DPSink.h`` ライブラリを含めることから始まります。そして、I2Sインターフェースの設定で ``BluetoothA2DPSink`` オブジェクトが作成され、構成されます。

    .. code-block:: arduino

        #include "BluetoothA2DPSink.h"

        BluetoothA2DPSink a2dp_sink;

#. setup関数内では、I2S（Inter-IC Sound）インターフェース用の望ましい構成で ``i2s_config_t struct`` が初期化されます。

    .. code-block:: arduino

        void setup() {
        const i2s_config_t i2s_config = {
            .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
            .sample_rate = 44100, // corrected by info from bluetooth
            .bits_per_sample = (i2s_bits_per_sample_t) 16, // the DAC module will only take the 8bits from MSB
            .channel_format =  I2S_CHANNEL_FMT_RIGHT_LEFT,
            .communication_format = (i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
            .intr_alloc_flags = 0, // default interrupt priority
            .dma_buf_count = 8,
            .dma_buf_len = 64,
            .use_apll = false
        };

        a2dp_sink.set_i2s_config(i2s_config);
         a2dp_sink.start("ESP32_Bluetooth");

        }

    * I2Sインターフェースは、デバイス間でデジタルオーディオデータを転送するために使用されます。
    * 構成には ``I2S mode``、 ``sample rate``、 ``bits per sample``、 ``channel format``、 ``communication format``、 ``interrupt allocation flags``、 ``DMA buffer count``、 ``DMA buffer length``、およびAPLL（オーディオPLL）を使用するかどうかが含まれます。
    * この ``i2s_config_t struct`` は、オーディオ再生用のI2Sインターフェースを設定するために ``BluetoothA2DPSink`` オブジェクトの ``set_i2s_config`` 関数に引数として渡されます。
    * ``BluetoothA2DPSink`` オブジェクトの ``start`` 関数が呼び出され、Bluetoothオーディオシンクが開始され、内蔵DACを通じてオーディオの再生が始まります。

