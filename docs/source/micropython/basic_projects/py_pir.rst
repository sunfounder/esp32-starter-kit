.. _py_pir:

5.5 人の動きを検出する
========================================

受動赤外線センサー（PIRセンサー）は、視野内の物体から放出される赤外線（IR）光を測定する一般的なセンサーです。
簡単に言えば、体から放出される赤外線を受け取り、人やその他の動物の動きを検出します。
より具体的には、誰かがあなたの部屋に入ったことをメインコントロールボードに伝えます。

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**利用可能なピン**

* **利用可能なピン**

    このプロジェクトのESP32ボードに利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 入力用
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - 出力用
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::
    
    このプロジェクトでは、内部で1Kのプルダウン抵抗器に接続されているため、IO32は **入力ピンとして使用できません**。デフォルトの値は0に設定されています。

* **ストラッピングピン（入力）**

    ストラッピングピンは、デバイスの起動時に特定のブートモードを決定するために使用される特別なセットのピンです
    （つまり、電源オンリセット）。

    
    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15 
    
    

    一般的に、 **入力ピンとして使用することは推奨されません**。これらのピンを使用したい場合は、ブートプロセスへの潜在的な影響を考慮してください。詳細については、 :ref:`esp32_strapping` セクションを参照してください。

**回路図**

.. image:: ../../img/circuit/circuit_5.5_pir.png

PIRモジュールが動きを検出すると、IO14がハイになり、LEDが点灯します。動きが検出されない場合、IO14はローになり、LEDは消灯します。

.. note::
    PIRモジュールには感度を調整するポテンショメーターと検出距離を調整するポテンショメーターが2つあります。PIRモジュールをより良く動作させるためには、両方を反時計回りに最後まで回す必要があります。

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**配線図**

.. image:: ../../img/wiring/5.5_pir_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.5_detect_human_movement.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。
 
.. code-block:: python

    import machine
    import time

    # Define pins
    PIR_PIN = 14    # PIR sensor
    LED_PIN = 26    # LED

    # Initialize the PIR sensor pin as an input pin
    pir_sensor = machine.Pin(PIR_PIN, machine.Pin.IN, machine.Pin.PULL_DOWN)
    # Initialize the LED pin as an output pin
    led = machine.Pin(LED_PIN, machine.Pin.OUT)

    # Global flag to indicate motion detected
    motion_detected_flag = False

    # Function to handle the interrupt
    def motion_detected(pin):
        global motion_detected_flag
        print("Motion detected!")
        motion_detected_flag = True

    # Attach the interrupt to the PIR sensor pin
    pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    # Main loop
    while True:
        if motion_detected_flag:
            led.value(1)  # Turn on the LED
            time.sleep(5)  # Keep the LED on for 5 seconds
            led.value(0)  # Turn off the LED
            motion_detected_flag = False

スクリプトが実行されると、PIRモジュールが誰かを検出するとLEDが5秒間点灯し、その後消灯します。

.. note::

    PIRモジュールには2つのポテンショメータがあります：1つは感度を、もう1つは検出距離を調整します。PIRモジュールをより良く機能させるためには、両方を反時計回りに最後まで回す必要があります。

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center




**どのように動作するのか？**


このコードはPIRセンサーとLEDを使用したシンプルな動作検出システムを設定します。動作が検出されると、LEDが5秒間点灯します。

コードの詳細は以下の通りです：

#. 動きが検出されたときに実行される割り込みハンドラ関数を定義します：

    .. code-block:: python

        def motion_detected(pin):
            global motion_detected_flag
            print("Motion detected!")
            motion_detected_flag = True

#. PIRセンサーピンに割り込みをアタッチし、トリガーを"rising"（つまり、ピンが低電圧から高電圧に変わるとき）に設定します：

    .. code-block:: python

        pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    これにより、PIRモーションセンサーに接続された ``pir_sensor`` ピンに割り込みが設定されます。

    パラメータの詳細な説明は以下の通りです：

    * ``trigger=machine.Pin.IRQ_RISING``: このパラメータは割り込みのトリガー条件を設定します。この場合、割り込みは立ち上がりエッジでトリガーされます。立ち上がりエッジとは、ピンの電圧が低状態（0V）から高状態（ハードウェアによって異なりますが、通常は3.3Vまたは5V）に変わるときです。PIRモーションセンサーの場合、動作が検出されると、出力ピンは通常低から高になるため、立ち上がりエッジは適切なトリガー条件です。

    * ``handler=motion_detected``: このパラメータは割り込みがトリガーされたときに実行される関数を指定します。この場合は、``motion_detected`` 関数が割り込みハンドラとして提供されています。この関数は ``pir_sensor`` ピンで割り込み条件（立ち上がりエッジ）が検出されたときに自動的に呼び出されます。

    したがって、このコード行は、センサーによって動作が検出されるたびに、出力ピンが低状態から高状態に変わるため、``motion_detected`` 関数を呼び出すようPIRセンサーを設定します。



#. メインループでは、 ``motion_detected_flag`` が ``True`` に設定されている場合、LEDが5秒間点灯してから消灯します。次の動作イベントを待つためにフラグは再び ``False`` にリセットされます。

    .. code-block:: python

        while True:
            if motion_detected_flag:
                led.value(1)  # Turn on the LED
                time.sleep(5)  # Keep the LED on for 5 seconds
                led.value(0)  # Turn off the LED
                motion_detected_flag = False
