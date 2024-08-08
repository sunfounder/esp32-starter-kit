.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_lcd1602:

2.6 文字の表示
===============================

ここでは、I2C LCD1602モジュールを使用した文字表示の魅力的な世界について探求します。

このプロジェクトを通じて、LCDモジュールの初期化、希望の表示パラメータの設定、画面に表示する文字データの送信方法を学びます。カスタムメッセージのショーケース、センサーの読み取りの表示、インタラクティブなメニューの作成などが可能です。可能性は無限大です！

I2C LCD1602で文字表示の技術を習得することにより、プロジェクトでの通信と情報表示の新たな道が開けます。このワクワクする旅に飛び込んで、LCDスクリーンにキャラクターを生き生きと表示しましょう。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

一式を購入するのが便利ですが、こちらがリンクです：

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|


**利用可能なピン**

こちらは、このプロジェクトにおけるESP32ボードの利用可能なピンのリストです。

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - 利用可能なピン
        - 使用説明

    *   - IO21
        - SDA
    *   - IO22
        - SCL
    
**回路図**

.. image:: ../../img/circuit/circuit_2.6_lcd.png

**配線図**

.. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
    :width: 800

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\2.6_lcd1602`` のパスの下にある ``2.6_lcd1602.ino`` ファイルを開きます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``LiquidCrystal I2C`` ライブラリを使用しています。 **Library Manager** からインストールできます。

        .. image:: img/lcd_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/31e33e53-67b2-4e29-b78b-f647fd45fb0b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

このプログラムをアップロードすると、I2C LCD1602は「Hello, Sunfounder!」という歓迎メッセージを3秒間表示します。その後、画面には「COUNT:」というラベルと、1秒ごとにインクリメントされるカウント値が表示されます。

.. note:: 

    コードと配疚が正しくてもLCDに何も表示されない場合は、背面のポテンショメータを調整してコントラストを上げてください。

**どのように動作するのか？**

``LiquidCrystal_I2C.h`` ライブラリを呼び出すことで、LCDを簡単に操作できます。

.. code-block:: arduino

    #include <LiquidCrystal_I2C.h>

ライブラリ関数：


* Arduinoボードに接続された特定のLCDを表す ``LiquidCrystal_I2C`` クラスの新しいインスタンスを作成します。

    .. code-block:: arduino

        LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

    * ``lcd_AddR``: The address of the LCD defaults to 0x27.
    * ``lcd_cols``: The LCD1602 has 16 columns.
    * ``lcd_rows``: The LCD1602 has 2 rows.

* LCDを初期化します。

    .. code-block:: arduino

        void init()

* （オプションの）バックライトを点灯します。

    .. code-block:: arduino

        void backlight()

* （オプションの）バックライトを消灯します。

    .. code-block:: arduino

        void nobacklight()

* LCDディスプレイを点灯します。

    .. code-block:: arduino

        void display()

* LCDディスプレイをすばやく消灯します。

    .. code-block:: arduino

        void nodisplay()

* ディスプレイをクリアし、カーソル位置をゼロに設定します。

    .. code-block:: arduino

        void clear()

* カーソル位置をcol,rowに設定します。

    .. code-block:: arduino

        void setCursor(uint8_t col,uint8_t row)

* テキストをLCDに表示します。

    .. code-block:: arduino

        void print(data,BASE)

    * ``data``: 表示するデータ（char, byte, int, long, string）。
    * ``BASE (オプション)``: 数字を表示する基数。

        * ``BIN`` はバイナリ（基数2）
        * ``DEC`` は10進数（基数10）
        * ``OCT`` は8進数（基数8）
        * ``HEX`` は16進数（基数16）。

