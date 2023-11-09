.. _py_dice:

6.6 デジタルダイス
================================

このプロジェクトは、 :ref:`py_7_segment` プロジェクトを基にして、セブンセグメントディスプレイに表示される数字を制御するボタンを追加します。

ボタンを押すと、7セグメントディスプレイは1から6までの数字をスクロールし、ボタンを離すとランダムな数字が表示されます。

このサイクルはボタンを押すたびに続きます。

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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**回路図**

.. image:: ../../img/circuit/circuit_6.6_electronic_dice.png

このプロジェクトは、 :ref:`py_7_segment` プロジェクトを基にして、セブンセグメントディスプレイに表示される数字を制御するボタンを追加するものです。

ボタンは外部のプルアップまたはプルダウン抵抗なしでIO13に直接接続されています。IO13には47Kの内部プルアップ抵抗があり、追加の外部抵抗が不要です。

**配線図**

.. image:: ../../img/wiring/6.6_DICE_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``6.6_digital_dice.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。それから、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。

.. code-block:: python

    import machine
    import time
    import random

    # Define the segment code for a common anode 7-segment display
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

    # Initialize the pins for the 74HC595 shift register
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    button = machine.Pin(13, machine.Pin.IN) # Button pin

    # Define the hc595_shift function to shift data into the 74HC595 shift register
    def hc595_shift(dat):
        # Set the RCLK pin to low
        rclk.off()
        
        # Iterate through each bit (from 7 to 0)
        for bit in range(7, -1, -1):
            # Extract the current bit from the input data
            value = 1 & (dat >> bit)
            
            # Set the SRCLK pin to low
            srclk.off()
            
            # Set the value of the SDI pin
            sdi.value(value)
            
            # Clock the current bit into the shift register by setting the SRCLK pin to high
            srclk.on()
            
        # Latch the data into the storage register by setting the RCLK pin to high
        rclk.on()

    # Initialize the random seed
    random.seed(time.ticks_us())


    num = 1
    button_state = False

    # Define the button callback function to toggle the button state
    def button_callback(pin):
        global button_state
        button_state = not button_state

    # Attach the button callback function to the falling edge of the button pin
    button.irq(trigger=machine.Pin.IRQ_FALLING, handler=button_callback)

    # Continuously display the current digit on the 7-segment display, scrolling if button is not pressed
    while True:
        
        # Display the current digit on the 7-segment display
        hc595_shift(SEGCODE[num])
        
        # If the button is pressed and button state is True
        if button_state:
            pass

        # If the button is pressed again and button state is False, generate a new random digit
        if not button_state:
            num = random.randint(1, 6)
            time.sleep_ms(10) # Adjust this value to control the display refresh rate
        
プログラムが実行中の間、ボタンを押すと7セグメントディスプレイがスクロールして1から6の間のランダムな数字を表示します。

ボタンを再度押すと、7セグメントディスプレイは停止し、特定の数字を表示します。もう一度ボタンを押すと、7セグメントディスプレイは数字をスクロールし続けます。




