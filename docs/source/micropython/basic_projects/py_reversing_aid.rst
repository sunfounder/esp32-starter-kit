.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_reversing_aid:

6.4 リバースエイド
======================

想像してみてください：狭い駐車スペースに車をバックで入れようとしています。このプロジェクトでは、あなたの車の後部に取り付けられた超音波モジュールがデジタルアイとして機能します。リバースギアに入れると、モジュールが活動を開始し、後ろの障害物に跳ね返る超音波パルスを放出します。

これらのパルスがモジュールに戻ってくるときに魔法が起きます。それは迅速にあなたの車と物体の間の距離を計算し、このデータを鮮やかなLCDスクリーンに表示されるリアルタイムの視覚フィードバックに変換します。障害物の接近を色分けして示す動的なインジケータを目の当たりにし、周囲の環境をクリスタルクリアに理解できます。

しかし、私たちはそこで止まりませんでした。さらに没入するドライビング体験を提供するために、活発なブザーを取り入れました。あなたの車が障害物に近づくにつれて、ブザーのテンポが強まり、警告のオーケストラを作り出します。それはまるで個人的なオーケストラが逆駐車の複雑さをナビゲートしてくれるようなものです。

この革新的なプロジェクトは、最先端の技術とインタラクティブなユーザーインターフェースを組み合わせており、リバース時の経験を安全でストレスフリーにします。超音波モジュール、LCDディスプレイ、活発なブザーが調和して動作し、狭いスペースでの操作時に自信と力を感じさせ、運転の喜びに集中させてくれます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入すると確かに便利です。こちらがリンクです：

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

プロジェクトで使用される超音波センサーは、高周波の音波を発し、物体に当たって跳ね返ってくるまでの時間を測定します。このデータを分析することで、センサーと物体の間の距離を計算できます。物体があまりにも近い場合に警告を提供するために、聴覚信号を生成するためにブザーが使用されます。さらに、測定された距離は簡単な視覚化のためにLCD画面に表示されます。

**配線図**

.. image:: ../../img/wiring/6.4_aid_ultrasonic_bb.png
    :width: 800
    :align: center

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``6.4_reversing_aid.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。 

.. code-block:: python

    # Import required libraries
    from machine import Pin
    import time
    from lcd1602 import LCD
    import _thread

    # Initialize the buzzer
    buzzer = Pin(14, Pin.OUT)

    # Initialize the ultrasonic module
    TRIG = Pin(26, Pin.OUT)
    ECHO = Pin(25, Pin.IN)

    # Initialize the LCD1602 display
    lcd = LCD()

    dis = 100

    # Calculate the distance
    def distance():
        # Ensure trigger is off initially
        TRIG.off()
        time.sleep_us(2)  # Wait for 2 microseconds

        # Send a 10-microsecond pulse to the trigger pin
        TRIG.on()
        time.sleep_us(10)
        TRIG.off()

        # Wait for the echo pin to go high
        while not ECHO.value():
            pass

        # Record the time when the echo pin goes high
        time1 = time.ticks_us()

        # Wait for the echo pin to go low
        while ECHO.value():
            pass

        # Record the time when the echo pin goes low
        time2 = time.ticks_us()

        # Calculate the time difference between the two recorded times
        during = time.ticks_diff(time2, time1)

        # Calculate and return the distance (in cm) using the speed of sound (340 m/s)
        return during * 340 / 2 / 10000

    # Thread to continuously update the ultrasonic sensor reading
    def ultrasonic_thread():
        global dis
        while True:
            dis = distance()
            
            # Clear the LCD screen
            lcd.clear()
            
            # Display the distance
            lcd.write(0, 0, 'Dis: %.2f cm' % dis)
            time.sleep(0.5)

    # Start the ultrasonic sensor reading thread
    _thread.start_new_thread(ultrasonic_thread, ())

    # Beep function for the buzzer
    def beep():
        buzzer.value(1)
        time.sleep(0.1)
        buzzer.value(0)
        time.sleep(0.1)

    # Initialize the intervals variable
    intervals = 10000000
    previousMills = time.ticks_ms()
    time.sleep(1)

    # Main loop
    while True:
        # Update intervals based on distance
        if dis < 0 and dis > 500:
            pass
        elif dis <= 10:
            intervals = 300
        elif dis <= 20:
            intervals = 500
        elif dis <= 50:
            intervals = 1000
        else:
            intervals = 2000

        # Print the distance if it's not -1
        if dis != -1:
            print('Distance: %.2f' % dis)
        time.sleep_ms(100)

        # Check if it's time to beep
        currentMills = time.ticks_ms()
        if time.ticks_diff(currentMills, previousMills) >= intervals:
            beep()
            previousMills = currentMills


* スクリプトが実行されている間、超音波モジュールは前方の障害物の距離を連続的に検出し、その距離をシェルとI2C LCD1602に表示します。
* 障害物が近づくにつれて、ブザーのビープ音の頻度が速くなります。
* ``ultrasonic_thread()`` 関数は別のスレッドで実行されるため、メインループをブロックすることなく、距離測定を連続的に更新することができます。

.. note::

    コードと配線が正しくてもLCDに内容が表示されない場合は、背面のポテンショメータを調整してコントラストを上げることができます。
