.. _py_potentiometer:

5.8 ノブを回す
===========================
ポテンショメータは、回路内の抵抗を調整するために一般的に使用される3端子デバイスです。ノブやスライドレバーが特徴で、これを動かすことでポテンショメータの抵抗値を変化させることができます。このプロジェクトでは、日常生活で使われるデスクランプのように、LEDの明るさを制御するために使用します。ポテンショメータの位置を調整することで、回路内の抵抗を変え、それによりLEDを流れる電流を調節し、その明るさを変更します。これにより、デスクランプのようなカスタマイズ可能で調整可能な照明体験を作り出すことができます。

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

**利用可能なピン**

* **利用可能なピン**

    こちらは、このプロジェクトのためのESP32ボード上の利用可能なピンのリストです。

    .. list-table::
        :widths: 5 15

        *   - 利用可能なピン
            - IO14, IO25, I35, I34, I39, I36

* **ストラッピングピン**

    以下のピンはストラッピングピンで、電源オンまたはリセット時のESP32の起動プロセスに影響します。しかし、ESP32が正常に起動した後は、通常のピンとして使用できます。

    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO0, IO12


**回路図**

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

ポテンショメータを回すと、I35の値が変わります。プログラミングにより、I35の値を使用してLEDの明るさを制御できます。そのため、ポテンショメータを回すと、LEDの明るさもそれに応じて変わります。


**配線図**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**コード**


.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.8_turn_the_knob.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。



.. code-block:: python

    from machine import ADC, Pin, PWM
    import time

    pot = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      

    # Configure the ADC attenuation to 11dB for full range
    pot.atten(pot.ATTN_11DB)

    # Create a PWM object
    led = PWM(Pin(26), freq=1000)

    while True:
        # Read a raw analog value in the range of 0-4095
        value = pot.read()

        # Scale the value to the range of 0-1023 for ESP32 PWM duty cycle
        pwm_value = int(value * 1023 / 4095)

        # Update the LED brightness based on the potentiometer value
        led.duty(pwm_value)

        # Read the voltage in microvolts and convert it to volts
        voltage = pot.read_uv() / 1000000

        # Print the raw value and the voltage
        print(f"value: {value}, Voltage: {voltage}V")

        # Wait for 0.5 seconds before taking the next reading
        time.sleep(0.5)

このスクリプトを実行すると、ポテンショメータを回すとLEDの明るさが変わり、その時点でのアナログ値と電圧がシェルに表示されます。

* `machine.ADC - MicroPythonドキュメント <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_


