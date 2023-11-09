.. _ar_receiver:

5.14 赤外線受信機
=========================
赤外線受信機は、赤外線信号を受信し、TTLレベルと互換性のある信号を独立して検出・出力することができる部品です。一般的なプラスチックパッケージのトランジスタと同じサイズで、赤外線リモコンや赤外線伝送など、様々な応用に利用されています。

このプロジェクトでは、リモコンからの信号を検出するために赤外線受信機を使用します。リモコンのボタンを押すと、赤外線受信機が対応する信号を受信し、どのボタンが押されたかを判断するために信号をデコードします。受信した信号をデコードすることで、それに関連する特定のキーまたはコマンドを識別することができます。

赤外線受信機を用いることで、プロジェクトにリモコン機能を組み込み、赤外線信号を使用してデバイスを操作したり、対話することが可能になります。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入するのが便利です。以下がリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

個別に以下のリンクから購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    * - コンポーネントの紹介
      - 購入リンク

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|


**利用可能なピン**

    このプロジェクトにおいてESP32ボード上で利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        * - 利用可能なピン
          - IO13, IO12, IO14, IO27, IO26, IO25, IO15, IO0, IO5, IO18, IO19, IO21, IO22, IO23

**回路図**

.. image:: ../../img/circuit/circuit_5.14_receiver.png

リモコンのボタンを押すと、赤外線受信機が信号を検出し、赤外線ライブラリを使用してデコードできます。このデコードプロセスにより、ボタンプレスに関連するキー値を取得できます。

**配線図**

.. image:: ../../img/wiring/5.14_ir_receiver_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\5.14_ir_receiver`` のパスの下にある ``5.14_ir_receiver.ino`` ファイルを開きます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``IRremoteESP8266`` ライブラリを使用しています。 **Library Manager** からインストールできます。

        .. image:: img/receiver_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/463c8894-00bd-4035-a81c-cad99a7f3731/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、リモコンの異なるキーを押すと、そのキーの名前がシリアルモニターに表示されます。

.. note::
    * ``IRremoteESP8266`` ライブラリには多くの異なる赤外線プロトコルとデバイスの実装が含まれているため、ライブラリのサイズは比較的大きいです。コンパイラがより多くのコードを処理する必要があると、コンパイル時間もそれに応じて長くなります。コンパイルが終了するまで、辛抱強くお待ちください。
    * 新しいリモコンには、内蔵されている電池を絶縁するためのプラスチックタブが端にあります。リモコンを使用する際には、このプラスチック片を取り外すだけです。

**どのように動作するのか？**

#. このコードでは ``IRremoteESP8266`` ライブラリを使用して赤外線（IR）信号を赤外線受信モジュールを用いて受信します。

    .. code-block:: arduino

        #include <IRremoteESP8266.h>
        #include <IRrecv.h>

        // Define the IR receiver pin
        const uint16_t IR_RECEIVE_PIN = 14;

        // Create an IRrecv object
        IRrecv irrecv(IR_RECEIVE_PIN);

        // Create a decode_results object
        decode_results results;
    
#. ``setup()`` 関数では、シリアル通信を115200のボーレートで開始し、 ``irrecv.enableIRIn()`` を使用してIRレシーバを有効にします。

    .. code-block:: arduino

        void setup() {
            // Start serial communication
            Serial.begin(115200);
            
            // Start the IR receiver
            irrecv.enableIRIn();
        }

#. リモコンのキーを押すと、IRレシーバが信号を受信した場合にシリアルモニタにキー名が表示されます。

    .. code-block:: arduino

        void loop() {
            // If an IR signal is received
            if (irrecv.decode(&results)) {
                String key = decodeKeyValue(results.value);
                if (key != "ERROR") {
                    // Print the value of the signal to the serial monitor
                    Serial.println(key);
                }
                irrecv.resume(); // Continue to receive the next signal
            }
        }

    * 最初に、 ``irrecv.decode()`` 関数を使ってIR信号が受信されたかどうかを確認します。
    * 信号が受信された場合は、 ``decodeKeyValue()`` 関数を呼び出して信号の値をデコードします。
    * 信号が正常にデコードされた場合は、 ``Serial.println()`` を使用してシリアルモニタにデコードされた値が出力されます。
    * 最後に、 ``irrecv.resume()`` を呼び出して次の信号の受信を続けます。

#. ``decodeKeyValue()`` 関数は、IR信号のデコードされた値を引数として取り、リモコンの押されたキーに対応する文字列を返します。

    .. code-block:: arduino

        String decodeKeyValue(long result)
        {
            switch(result){
                case 0xFF6897:
                return "0";
                case 0xFF30CF:
                return "1"; 
                case 0xFF18E7:
                return "2"; 
                case 0xFF7A85:
                ...

    * この関数はswitch文を使ってデコードされた値を対応するキーと照合し、そのキーの文字列表現を返します。
    * デコードされた値が既知のキーに一致しない場合、関数は文字列 "ERROR" を返します。
