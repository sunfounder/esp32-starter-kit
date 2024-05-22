.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_lcd1602:

2.6 文字の表示
==================================================

ここでは、I2C LCD1602モジュールを使用した文字表示の魅力的な世界を探究します。

このプロジェクトを通じて、LCDモジュールの初期化、表示パラメータの設定、そして画面に表示する文字データの送信方法を学びます。カスタムメッセージのショーケース、センサー読み取りの表示、インタラクティブなメニューの作成など、可能性は無限大です！

I2C LCD1602で文字表示の技術をマスターすることで、プロジェクトでのコミュニケーションと情報表示の新たな道を開くことになります。このワクワクする旅に飛び込んで、LCDスクリーンにキャラクターを生き生きとさせましょう。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入することは非常に便利です。こちらがリンクです：

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
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**利用可能なピン**

このプロジェクトのESP32ボードに利用可能なピンのリストです。

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

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``2.6_liquid_crystal_display.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。
    * ここでは ``lcd1602.py`` ライブラリを使用しています。ESP32にアップロードされているか確認してください。チュートリアルについては :ref:`add_libraries_py` を参照してください。

.. code-block:: python

    # Import the LCD class from the lcd1602 module
    from lcd1602 import LCD

    import time

    # Create an instance of the LCD class and assign it to the lcd variable
    lcd = LCD()
    # Set the string " Hello!\n"
    string = " Hello!\n"
    # Display the string on the LCD screen
    lcd.message(string)

    time.sleep(2)
    # Set the string "    Sunfounder!"
    string = "    Sunfounder!"
    # Display the string on the LCD screen
    lcd.message(string)

    time.sleep(2)
    # Clear the LCD screen
    lcd.clear()


スクリプトを実行した後、LCDスクリーンには2行のテキストが順番に表示され、その後消えます。

.. note:: 

    コードと配線が正しいにもかかわらず、LCDが内容を表示しない場合は、背面のポテンショメータを調整してコントラストを上げてください。

**どのように動作するのか？**

``lcd1602`` ライブラリでは、lcd1602の関連機能をLCDクラスに統合しています。

#. ``lcd1602`` モジュールをインポートします。

    .. code-block:: python

        from lcd1602 import LCD    

#. ``LCD`` クラスのオブジェクトを宣言し、 ``lcd`` と名付けます。

    .. code-block:: python

        lcd = LCD()

#. この文は、テキストをLCDに表示します。引数は文字列型である必要があります。整数や浮動小数点数を渡したい場合は、強制変換文 ``str()`` を使用する必要があります。

    .. code-block:: python

        lcd.message(string)


#. この文を複数回呼び出すと、lcdはテキストを重ね合わせます。これには、表示をクリアするための以下の文を使用する必要があります。

    .. code-block:: python

        lcd.clear()

