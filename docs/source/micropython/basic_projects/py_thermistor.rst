.. _py_thermistor:

5.10 温度センシング
===========================

サーミスタは温度に強く依存する温度センサーで、負の温度係数（NTC）と正の温度係数（PTC）の2種類に分類されます。NTCサーミスタの抵抗は温度が上昇すると減少し、PTCサーミスタの抵抗は温度が上昇すると増加します。

このプロジェクトでは、NTCサーミスタを使用します。NTCサーミスタをESP32マイクロコントローラのアナログ入力ピンに接続することで、抵抗を測定し、それが直接温度に比例することができます。

NTCサーミスタを組み込み、必要な計算を行うことで、正確に温度を測定し、I2C LCD1602モジュールに表示することができます。このプロジェクトにより、リアルタイムで温度監視を行い、温度表示のための視覚的インターフェースを提供します。

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

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

.. image:: ../../img/circuit/circuit_5.10_thermistor.png

温度が上昇すると、サーミスタの抵抗が減少し、I35で読み取られる値が減少します。さらに、式を使用してアナログ値を温度に変換し、出力することができます。

**配線図**

.. image:: ../../img/wiring/5.10_thermistor_bb.png


.. note::
    * サーミスタは黒色で、103とマークされています。
    * 10Kオーム抵抗のカラーリングは赤、黒、黒、赤、茶色です。

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.10_thermistor.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。 

.. code-block:: python

    # Import the necessary libraries
    from machine import ADC, Pin
    import time
    import math

    # Define the beta value of the thermistor, typically provided in the datasheet
    beta = 3950

    # Create an ADC object (thermistor)
    thermistor = ADC(Pin(35, Pin.IN))

    # Set the attenuation
    thermistor.atten(thermistor.ATTN_11DB)

    # Start an infinite loop to continuously monitor the temperature
    while True:
        # Read the voltage in microvolts and convert it to volts
        Vr = thermistor.read_uv() / 1000000

        # Calculate the resistance of the thermistor based on the measured voltage
        Rt = 10000 * Vr / (3.3 - Vr)

        # Use the beta parameter and resistance value to calculate the temperature in Kelvin
        temp = 1 / (((math.log(Rt / 10000)) / beta) + (1 / (273.15 + 25)))

        # Convert to Celsius
        Cel = temp - 273.15

        # Convert to Fahrenheit
        Fah = Cel * 1.8 + 32

        # Print the temperature values in both Celsius and Fahrenheit
        print('Celsius: %.2f C  Fahrenheit: %.2f F' % (Cel, Fah))
        time.sleep(0.5)

コードを実行すると、シェルは摂氏と華氏の温度を出力します。

**どのように動作するのか？**

各サーミスタには、通常の抵抗値があります。ここでは25度摂氏で測定された10kオームです。

温度が高くなると、サーミスタの抵抗値が減少します。次に、A/D変換器により電圧データがデジタル量に変換されます。

摂氏または華氏の温度は、プログラミングを通じて出力されます。

ここに抵抗と温度の関係があります：

    **RT =RN expB(1/TK - 1/TN)** 

    * **RT** は温度 **TK** のときのNTCサーミスタの抵抗値です。
    * **RN** は定格温度 TN 下のNTCサーミスタの抵抗値です。ここでは、RNの数値は10kです。
    * **TK** はケルビン温度で、単位はKです。ここでは、**TK** の数値は ``373.15 + 摂氏度数`` です。
    * **TN** は定格ケルビン温度で、単位もKです。ここでは、TNの数値は ``373.15+25`` です。
    * そして **B（ベータ）**、NTCサーミスタの材料定数であり、熱感受性指数とも呼ばれ、数値は ``4950`` です。
    * **exp** は指数の略で、基数 ``e`` は自然数で、約2.7に等しいです。

    この式 ``TK=1/(ln(RT/RN)/B+1/TN)`` を変換してケルビン温度を求め、273.15を引くと摂氏度が求まります。

    この関係は経験式です。温度と抵抗値が有効範囲内にあるときのみ正確です。

**もっと学ぶ**

計算された摂氏および華氏の温度をI2C LCD1602に表示することもできます。

.. image:: ../../img/wiring/5.10_thermistor_lcd_bb.png

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.10_thermistor_lcd.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。

    * ここでは ``lcd1602.py`` というライブラリを使用する必要があります。ESP32にアップロードされていることを確認してください。詳しいチュートリアルは :ref:`add_libraries_py` を参照してください。

.. code-block:: python

    # Import the necessary libraries
    from machine import ADC, Pin
    from lcd1602 import LCD
    import time
    import math

    # Define the beta value of the thermistor, typically provided in the datasheet
    beta = 3950

    # Create an ADC object (thermistor)
    thermistor = ADC(Pin(35, Pin.IN))

    # Set the attenuation
    thermistor.atten(thermistor.ATTN_11DB)

    lcd = LCD()

    # Start an infinite loop to continuously monitor the temperature
    while True:
        # Read the voltage in microvolts and convert it to volts
        Vr = thermistor.read_uv() / 1000000

        # Calculate the resistance of the thermistor based on the measured voltage
        Rt = 10000 * Vr / (3.3 - Vr)

        # Use the beta parameter and resistance value to calculate the temperature in Kelvin
        temp = 1 / (((math.log(Rt / 10000)) / beta) + (1 / (273.15 + 25)))

        # Convert to Celsius
        Cel = temp - 273.15

        # Convert to Fahrenheit
        Fah = Cel * 1.8 + 32

        # Print the temperature values in both Celsius and Fahrenheit
        print('Celsius: %.2f C  Fahrenheit: %.2f F' % (Cel, Fah))

        # Clear the LCD screen
        lcd.clear()
        
        # Display the temperature values in both Celsius and Fahrenheit
        lcd.message('Cel: %.2f \xDFC \n' % Cel)
        lcd.message('Fah: %.2f \xDFF' % Fah)
        time.sleep(1)


