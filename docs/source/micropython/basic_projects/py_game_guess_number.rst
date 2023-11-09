.. _py_guess_number:

6.7 数当てゲーム
==============================

運試しに挑戦してみませんか？自分の直感を試して、正しい番号を当てられるか見てみたいですか？それなら、この数当てゲームがぴったりです！

このプロジェクトでは、運と勘を試す楽しくワクワクするゲームを楽しむことができます。

IRリモコンを使用して、プレイヤーは0から99までの数字を入力し、ランダムに生成されたラッキーポイントの数字を当てます。
システムはプレイヤーが入力した数字をLCDスクリーンに表示し、上限と下限のヒントを提供して正しい答えに導きます。
推測するごとに、プレイヤーはラッキーポイントの数字に近づき、最終的に誰かがジャックポットを当ててゲームに勝利します！

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

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``6.7_game_guess_number.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。それから、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。
    * ここでは ``lcd1602.py`` と ``ir_rx`` ライブラリを使用します。ESP32にアップロードされているか確認してください。チュートリアルについては :ref:`add_libraries_py` を参照してください。


.. code-block:: python

    from lcd1602 import LCD
    import machine
    import time
    import urandom
    from machine import Pin
    from ir_rx.print_error import print_error
    from ir_rx.nec import NEC_8

    # IR receiver configuration
    pin_ir = Pin(14, Pin.IN)

    # Initialize the guessing game variables
    lower = 0
    upper = 99
    pointValue = int(urandom.uniform(lower, upper))
    count = 0

    # Initialize the LCD1602 display
    lcd = LCD()

    # Initialize a new random value for the game
    def init_new_value():
        global pointValue, upper, lower, count
        pointValue = int(urandom.uniform(lower, upper))
        print(pointValue)
        upper = 99
        lower = 0
        count = 0
        return False

    # Display messages on the LCD based on the game state
    def lcd_show(result):
        global count
        lcd.clear()
        if result == True: 
            string = "GAME OVER!\n"
            string += "Point is " + str(pointValue)
        else: 
            string = "Enter number: " + str(count) + "\n"
            string += str(lower) + " < Point < " + str(upper)
        lcd.message(string)
        return

    # Process the entered number and update the game state
    def number_processing():
        global upper, count, lower
        if count > pointValue:
            if count < upper:
                upper = count
        elif count < pointValue:
            if count > lower:
                lower = count
        elif count == pointValue:
            return True
        count = 0
        return False

    # Process the key inputs from the IR remote control
    def process_key(key):
        global count, lower, upper, pointValue, result
        if key == "Power":
            init_new_value()
            lcd_show(False)
        elif key == "+":
            result = number_processing()
            lcd_show(result)
            if result:
                time.sleep(5)
                init_new_value()
                lcd_show(False)
            else:
                lcd_show(False)
        elif key.isdigit():
            count = count * 10 + int(key) if count * 10 + int(key) <= 99 else count
            lcd_show(False)

    # Decode the received data and return the corresponding key name
    def decodeKeyValue(data):       
        if data == 0x16:
            return "0"
        if data == 0x0C:
            return "1"
        if data == 0x18:
            return "2"
        if data == 0x5E:
            return "3"
        if data == 0x08:
            return "4"
        if data == 0x1C:
            return "5"
        if data == 0x5A:
            return "6"
        if data == 0x42:
            return "7"
        if data == 0x52:
            return "8"
        if data == 0x4A:
            return "9"
        if data == 0x09:
            return "+"
        if data == 0x15:
            return "-"
        if data == 0x7:
            return "EQ"
        if data == 0x0D:
            return "U/SD"
        if data == 0x19:
            return "CYCLE"
        if data == 0x44:
            return "PLAY/PAUSE"
        if data == 0x43:
            return "FORWARD"
        if data == 0x40:
            return "BACKWARD"
        if data == 0x45:
            return "POWER"
        if data == 0x47:
            return "MUTE"
        if data == 0x46:
            return "MODE"
        return "ERROR"

    def callback(data, addr, ctrl):
        if data < 0:
            pass
        else:
            key = decodeKeyValue(data)
            if key != "ERROR":
                process_key(key)

    # Initialize the IR receiver object with the callback function
    ir = NEC_8(pin_ir, callback)

    # ir.error_function(print_error)

    # Initialize the game with a new random value
    init_new_value()

    # Show the initial game state on the LCD
    lcd_show(False)

    try:
        while True:
            pass
    except KeyboardInterrupt:
        ir.close()



* コードが実行されると、秘密の数字が生成されますが、LCDには表示されません。あなたが行うべきことは、それを推測することです。
* リモコンで推測した数字を押し、 ``+`` キーを押して確認します。
* 同時に、I2C LCD1602に表示される範囲が狭まり、この新しい範囲に基づいて適切な数字を押す必要があります。
* 幸運にも不運にも正解の数字を押すと、 ``GAME OVER!`` と表示されます。

.. note:: 

    コードと配線が正しくてもLCDに内容が表示されない場合は、背面のポテンショメータを調整してコントラストを上げることができます。

**どのように機能するのか？**

以下は、コードの一部の詳細な分析です。

#. 数当てゲームの変数を初期化します。

    .. code-block:: python
    
        lower = 0
        upper = 99
        pointValue = int(urandom.uniform(lower, upper))
        count = 0


    * 秘密の数字のための ``lower`` と ``upper`` の境界値。
    * ``lower`` と ``upper`` の境界値の間でランダムに生成される秘密の数字（ ``pointValue`` ）。
    * ユーザーの現在の推測（ ``count`` ）。

#. この関数は数当てゲームの値をリセットし、新しい秘密の数字を生成します。

    .. code-block:: python
    
        def init_new_value():
            global pointValue, upper, lower, count
            pointValue = int(urandom.uniform(lower, upper))
            print(pointValue)
            upper = 99
            lower = 0
            count = 0
            return False

#. この関数は現在のゲームの状態をLCD画面に表示します。

    .. code-block:: python

        def lcd_show(result):
            global count
            lcd.clear()
            if result == True: 
                string = "GAME OVER!\n"
                string += "Point is " + str(pointValue)
            else: 
                string = "Enter number: " + str(count) + "\n"
                string += str(lower) + " < Point < " + str(upper)
            lcd.message(string)
            return

    * ゲームが終了した場合（ ``result=True`` ）、 ``GAME OVER!`` と秘密の数字を表示します。
    * それ以外の場合、現在の推測（ ``count`` ）と現在の推測範囲（ ``lower`` から ``upper``）を表示します。

#. この関数はユーザーの現在の推測（ ``count`` ）を処理し、推測範囲を更新します。

    .. code-block:: python

        def number_processing():
            global upper, count, lower
            if count > pointValue:
                if count < upper:
                    upper = count
            elif count < pointValue:
                if count > lower:
                    lower = count
            elif count == pointValue:
                return True
            count = 0
            return False
    
    * 現在の推測（ ``count`` ）が秘密の数字より高い場合、上限が更新されます。
    * 現在の推測（ ``count`` ）が秘密の数字より低い場合、下限が更新されます。
    * 現在の推測（ ``count`` ）が秘密の数字と等しい場合、関数は ``True`` （ゲーム終了）を返します。

#. IRリモコンから受け取ったキー押下イベントを処理する関数です。

    .. code-block:: python

        def process_key(key):
            global count, lower, upper, pointValue, result
            if key == "Power":
                init_new_value()
                lcd_show(False)
            elif key == "+":
                result = number_processing()
                lcd_show(result)
                if result:
                    time.sleep(5)
                    init_new_value()
                    lcd_show(False)
                else:
                    lcd_show(False)
            elif key.isdigit():
                count = count * 10 + int(key) if count * 10 + int(key) <= 99 else count
                lcd_show(False)

    * ``Power`` キーが押されると、ゲームがリセットされます。
    * ``+`` キーが押されると、現在の推測（ ``count`` ）が処理され、ゲームの状態が更新されます。
    * 数字キーが押されると、現在の推測（ ``count`` ）が新しい数字で更新されます。

#. IRレシーバーが信号を受信するとトリガーされるコールバック関数です。

    .. code-block:: python

        def callback(data, addr, ctrl):
            if data < 0:
                pass
            else:
                key = decodeKeyValue(data)
                if key != "ERROR":
                    process_key(key)