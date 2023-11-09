.. _py_rgb:

2.3 カラフルライト
==============================================

このプロジェクトでは、RGB LEDを使用して加法色混合の魅力的な世界について探ります。

RGB LEDは、赤、緑、青の3つの基本色を一つのパッケージに組み合わせています。これら3つのLEDは共通のカソードピンを共有しており、各アノードピンが対応する色の強度を制御します。

各アノードに適用される電気信号の強度を変えることで、幅広い色を作り出すことができます。例えば、高強度の赤色光と緑色光を混ぜると黄色光になり、青色と緑色の光を組み合わせるとシアンが生まれます。

このプロジェクトを通じて、加法色混合の原理を探求し、RGB LEDを操作して魅力的で生き生きとした色を表示することで、私たちの創造性を解き放ちます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全てのキットを購入すると便利ですが、こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

以下のリンクから別々に購入することもできます。

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**利用可能なピン**

このプロジェクトのESP32ボードにある利用可能なピンのリストはこちらです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_2.3_rgb.png

PWMピンのpin27、pin26、pin25は、それぞれRGB LEDの赤、緑、青のピンを制御し、共通カソードピンをGNDに接続します。これにより、異なるPWM値をこれらのピンに重ねて特定の色をRGB LEDに表示させることができます。


**配線図**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

RGB LEDには4本のピンがあります。長いピンは共通のカソードピンで、通常GNDに接続されます。最長のピンの隣の左ピンは赤、右側の2本のピンは緑と青です。

.. image:: ../../img/wiring/2.3_color_light_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``2.3_colorful_light.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。その後、「現在のスクリプトを実行」をクリックするかF5キーを押して実行します。
    * 右下の角にある「MicroPython (ESP32).COMxx」インタープリターを選択してください。 

.. code-block:: python

    from machine import Pin, PWM
    import time

    # Define the GPIO pins for the RGB LED
    RED_PIN = 27
    GREEN_PIN = 26
    BLUE_PIN = 25


    # Set up the PWM channels
    red = PWM(Pin(RED_PIN))
    green = PWM(Pin(GREEN_PIN))
    blue = PWM(Pin(BLUE_PIN))

    # Set the PWM frequency
    red.freq(1000)
    green.freq(1000)
    blue.freq(1000)

    def set_color(r, g, b):
        red.duty(r)
        green.duty(g)
        blue.duty(b)

    while True:
        # Set different colors and wait for a while
        set_color(1023, 0, 0) # Red
        time.sleep(1)
        set_color(0, 1023, 0) # Green
        time.sleep(1)
        set_color(0, 0, 1023) # Blue
        time.sleep(1)
        set_color(1023, 0, 1023) # purple
        time.sleep(1)

スクリプトを実行すると、RGB LEDが赤、緑、青、紫などの色を表示します。

**詳細を知る**

以下のコードで、0～255の馴染みのある色値を使って、任意の色を設定することもできます。

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``2.3_colorful_light_rgb.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。その後、「現在のスクリプトを実行」をクリックするかF5キーを押して実行します。
    * 右下の角にある「MicroPython (ESP32).COMxx」インタープリターを選択してください。


.. code-block:: python

    from machine import Pin, PWM
    import time

    # Define the GPIO pins for the RGB LED
    RED_PIN = 27
    GREEN_PIN = 26
    BLUE_PIN = 25

    # Set up the PWM channels
    red = PWM(Pin(RED_PIN))
    green = PWM(Pin(GREEN_PIN))
    blue = PWM(Pin(BLUE_PIN))

    # Set the PWM frequency
    red.freq(1000)
    green.freq(1000)
    blue.freq(1000)

    # Map input values from one range to another
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Convert color values (0-255) to duty cycle values (0-1023)
    def color_to_duty(rgb_value):
        rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
        return rgb_value

    def set_color(red_value,green_value,blue_value):
        red.duty(color_to_duty(red_value))
        green.duty(color_to_duty(green_value))
        blue.duty(color_to_duty(blue_value))

    while True:
        # Set different colors and wait for a while
        set_color(255, 0, 0) # Red
        time.sleep(1)
        set_color(0, 255, 0) # Green
        time.sleep(1)
        set_color(0, 0, 255) # Blue
        time.sleep(1)
        set_color(255, 0, 255) # purple
        time.sleep(1)

このコードは前の例に基づいていますが、0から255の色値を0から1023のデューティサイクル範囲にマッピングします。

* ``interval_mapping`` 関数は、ある範囲から別の範囲への値をマッピングするユーティリティ関数です。入力値、入力範囲の最小値と最大値、出力範囲の最小値と最大値の5つの引数を取ります。入力値を出力範囲にマッピングした値を返します。

    .. code-block:: python

        def color_to_duty(rgb_value):
            rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
            return rgb_value

* ``color_to_duty`` 関数は、整数RGB値（例：255,0,255）を取り、PWMピンに適したデューティサイクル値にマッピングします。入力RGB値は最初に ``interval_mapping`` 関数を使用して0-255の範囲から0-1023の範囲にマッピングされます。その後、 ``interval_mapping`` の出力がデューティサイクル値として返されます。

    .. code-block:: python

        def color_to_duty(rgb_value):
            rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
            return rgb_value

* ``color_set`` 関数は、LEDの赤、緑、青の値を表す3つの整数引数を取ります。これらの値は ``color_to_duty`` に渡されて、PWMピンのデューティサイクル値を取得します。デューティサイクル値は、 ``duty`` メソッドを使用して対応するピンに設定されます。

    .. code-block:: python

        def set_color(red_value,green_value,blue_value):
            red.duty(color_to_duty(red_value))
            green.duty(color_to_duty(green_value))
            blue.duty(color_to_duty(blue_value))
