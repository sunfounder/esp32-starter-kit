.. _ar_guess_number:

6.7 数当てゲーム
==================
運試しをしたいですか？直感を試して、正しい番号を当てられるかどうか確かめたいですか？それなら、数当てゲームがぴったりです！

このプロジェクトでは、偶然性の高い楽しいゲームを楽しむことができます。

IRリモコンを使用して、プレイヤーは0から99の間の数字を入力し、ランダムに生成される幸運なポイントナンバーを当てます。
システムはLCDスクリーンにプレイヤーの入力した数字を表示し、上限と下限のヒントを提供して正解に導きます。
推測するたびに、プレイヤーは幸運なポイントナンバーに近づき、ついに誰かがジャックポットを当ててゲームに勝利します！

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キットを一式揃えると確かに便利です。こちらがリンクです：

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
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**回路図**

.. image:: ../../img/circuit/circuit_6.7_guess_number.png

**配線図**

.. image:: ../../img/wiring/6.7_guess_receiver_bb.png
    :width: 800

**コード**

.. note::

    * ``6.7_guess_number.ino`` ファイルを ``esp32-starter-kit-main\c\codes\6.7_guess_number`` のパスで直接開けます。
    * こちらでは ``LiquidCrystal_I2C`` と ``IRremoteESP8266`` ライブラリーを使用しています。インストール方法は :ref:`install_lib_man` を参照してください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e4217f5-c1b7-4859-a34d-d791bbc5e57a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* コードが正常にアップロードされた後、リモコンの任意の数字ボタンを押してゲームを開始します。
* リモコンの数字ボタンを使用して数字を入力します。1桁の数字を入力するには、 **サイクル** キーを押して確認する必要があります。
* システムは、入力された数字と上下限のヒントをLCDスクリーンに表示します。
* 幸運なポイントナンバーを正確に当てるまで推測を続けます。
* 正しい数字を当てると、システムは成功メッセージを表示し、新しい幸運なポイントナンバーを生成します。

.. note:: 

    コードと配線が正しいにもかかわらず、LCDが何も表示されない場合は、背面のポテンショメーターを調整してコントラストを高めることができます。


**どのように動作するのか？**

#. ``setup()`` 関数では、I2C LCD画面とIR受信機が初期化されます。次に ``initNewValue()`` 関数を呼び出して新しいランダムな幸運の番号を生成し、LCD画面に歓迎メッセージが表示されます。

    .. code-block:: arduino

        void setup() {
            // Initialize the LCD screen
            lcd.init();
            lcd.backlight();

            // Start the serial communication
            Serial.begin(9600);

            // Enable the IR receiver
            irrecv.enableIRIn();

            // Initialize a new lucky point value
            initNewValue();
        }

#. ``loop`` 関数では、IR受信機からの信号を待ちます。信号が受信された場合には、 ``decodeKeyValue`` 関数が呼び出されて信号をデコードし、対応するボタンの値を取得します。

    .. code-block:: arduino

        void loop() {
        // If a signal is received from the IR receiver
        if (irrecv.decode(&results)) {
            bool result = 0;
            String num = decodeKeyValue(results.value);

            // If the POWER button is pressed
            if (num == "POWER") {
                initNewValue(); // Initialize a new lucky point value
            }

            // If the CYCLE button is pressed
            else if (num == "CYCLE") {
                result = detectPoint(); // Detect the input number
                lcdShowInput(result); // Show the result on the LCD screen
            }

            // If a number button (0-9) is pressed, 
            //add the digit to the input number 
            //and detect the number if it is greater than or equal to 10
            else if (num >= "0" && num <= "9") {
                count = count * 10;
                count += num.toInt();
                if (count >= 10) {
                    result = detectPoint();
                }
                lcdShowInput(result);
            }
            irrecv.resume();
        }
        }

    * ボタンの値に応じて、適切な関数が呼び出されます。数字ボタンが押された場合は、 ``count`` 変数が更新され、 ``detectPoint`` 関数が呼び出されて入力された番号が正しいかどうかを検出します。 ``lcdShowInput`` 関数が呼び出され、LCD画面に入力された番号と上下限のヒントが表示されます。
    * ``POWER`` ボタンが押された場合は、 ``initNewValue`` 関数が呼び出されて新しい幸運のポイント番号を生成し、LCD画面に歓迎メッセージを表示します。
    * ``CYCLE`` ボタンが押された場合は、 ``detectPoint`` 関数が呼び出されて入力された番号が正しいかどうかを検出します。 ``lcdShowInput`` 関数が呼び出され、LCD画面に入力された番号と上下限のヒントが表示されます。


