.. _ar_reversing_aid:

6.3 バックアップ支援
======================
想像してみてください：車に乗っていて、狭い駐車スペースにバックで入るところです。当プロジェクトを使えば、あなたの車の後部に取り付けられた超音波モジュールがデジタルアイとして機能します。リバースギアに入れると、このモジュールが活動を開始し、あなたの後ろの障害物から跳ね返る超音波パルスを発します。

魔法のようなことが起こります。これらのパルスがモジュールに戻ると、モジュールは迅速にあなたの車と物体との距離を計算し、このデータをリアルタイムの視覚フィードバックに変換し、鮮やかなLCD画面に表示します。動的なカラーコード付きインジケーターが障害物の近接を描き、周囲環境をクリスタルクリアに理解できるようになります。

しかし、私たちはそこで止まりませんでした。あなたをさらに運転体験に没入させるために、生き生きとしたブザーを組み込みました。車が障害物に近づくにつれて、ブザーのテンポは激しくなり、警告の交響曲を奏でます。それは、バック駐車の複雑さをナビゲートする個人オーケストラを持っているようなものです。

この革新的なプロジェクトは、最先端の技術とインタラクティブなユーザーインターフェイスを組み合わせており、あなたのバック駐車を安全でストレスフリーなものにします。超音波モジュール、LCDディスプレイ、活気のあるブザーが調和して動作し、狭いスペースでの操縦時にあなたを力強く自信を持たせ、運転の喜びに集中させます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全キットを購入することは間違いなく便利です。こちらがリンクです：

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**回路図**

.. image:: ../../img/circuit/circuit_6.4_reversing_aid.png
    :width: 800
    :align: center


プロジェクトにおける超音波センサーは、高周波の音波を発し、物体にぶつかって跳ね返ってくるまでの時間を測定します。このデータを分析することで、センサーと物体との距離が計算できます。物体が近すぎる場合の警告として、聴覚信号を発するブザーが使用されます。さらに、測定された距離は簡単な可視化のためにLCD画面に表示されます。

**配線図**

.. image:: ../../img/wiring/6.4_aid_ultrasonic_bb.png


**コード**

.. note::

    * ファイル ``6.3_reversing_aid.ino`` をパス ``esp32-starter-kit-main\c\codes\6.3_reversing_aid`` から直接開くことができます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``LiquidCrystal I2C`` ライブラリが使用されています。 **Library Manager** からインストールできます。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c06deba0-36fd-4f17-8290-c7a39202e089/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

コードが正常にアップロードされた後、LCDに現在検出されている距離が表示されます。そして、ブザーは距離に応じて音の周波数を変更します。

.. note:: 

    コードと配線が正しくてもLCDに何も表示されない場合は、背面のポテンショメータを調整してコントラストを上げてください。

**どのように動作するのか？**

このコードは、物体間の距離を測定し、LCDディスプレイとブザーを通じてフィードバックを提供する簡単な距離測定装置を作成するのに役立ちます。

``loop()`` 関数にはプログラムの主なロジックが含まれており、連続して実行されます。 ``loop()`` 関数をもう少し詳しく見てみましょう。

#. 距離を読み取り、パラメータを更新するループ

    ``loop`` 内では、まず超音波モジュールによって測定された距離を読み取り、その距離に基づいて間隔パラメータを更新します。

    .. code-block:: arduino

        // Update the distance
        distance = readDistance();

        // Update intervals based on distance
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. ビープ音を鳴らすタイミングをチェック

    コードは、現在の時刻と前回のビープ音の時刻との差を計算し、その差が間隔時間以上であればブザーを鳴らし、前回のビープ音の時刻を更新します。

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. LCDディスプレイを更新

    コードはLCDディスプレイをクリアし、その後、1行目に「Dis:」と現在の距離（センチメートル）を表示します。

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);
