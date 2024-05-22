.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_dht11:

5.13 温湿度計測
=======================================
DHT11は、環境測定に一般的に使用される温湿度センサーです。これはデジタルセンサーであり、マイクロコントローラーと通信して温度と湿度の読み取りを提供します。

このプロジェクトでは、DHT11センサーを読み取り、検出した温度と湿度の値を出力します。

センサーから提供されるデータを読み取ることで、環境の現在の温度と湿度の値を取得できます。これらの値は、環境条件のリアルタイムモニタリング、天気観測、室内の気候制御、湿度レポートなどに使用できます。

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

* **利用可能なピン**

    こちらは、このプロジェクトのためのESP32ボード上の利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 利用可能なピン
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_5.13_dht11.png


**配線図**

.. image:: ../../img/wiring/5.13_dht11_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.13_dht11.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。

.. code-block:: python

    import dht
    import machine
    import time

    # Initialize the DHT11 sensor and connect it to pin 14
    sensor = dht.DHT11(machine.Pin(14))

    # Loop indefinitely to continuously measure temperature and humidity
    while True:
        try:
            # Measure temperature and humidity
            sensor.measure()

            # Get temperature and humidity values
            temp = sensor.temperature()
            humi = sensor.humidity()

            # Print temperature and humidity
            print("Temperature: {}, Humidity: {}".format(temp, humi))

            # Wait for 1 second between measurements
            time.sleep(1)
        except Exception as e:
            print("Error: ", e)
            time.sleep(1)


コードが実行されているとき、シェルが連続して温度と湿度を出力するのを見ることができます。プログラムが安定して実行されると、これら二つの値はより正確になっていきます。

**もっと学ぶ**

I2C LCD1602に温度と湿度を表示することもできます。

.. image:: ../../img/wiring/5.13_dht11_lcd_bb.png

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.13_dht11_lcd.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。
    * ここでは ``lcd1602.py`` というライブラリを使用する必要があります。ESP32にアップロードされているかどうかを確認してください。詳しいチュートリアルは :ref:`add_libraries_py` を参照してください。


.. code-block:: python

    import dht
    import machine
    import time
    from lcd1602 import LCD

    # Initialize the DHT11 sensor and connect it to pin 14
    sensor = dht.DHT11(machine.Pin(14))

    # Initialize the LCD1602 display
    lcd = LCD()

    # Loop to measure temperature and humidity
    while True:
        try:
            # Measure temperature and humidity
            sensor.measure()

            # Get temperature and humidity values
            temp = sensor.temperature()
            humi = sensor.humidity()

            # Print temperature and humidity
            print("Temperature: {}, Humidity: {}".format(temp, humi))

            # Clear the LCD display
            lcd.clear()

            # Display temperature and humidity on the LCD1602 screen
            lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
            lcd.write(0, 1, "Humi: {}%".format(humi))

            # Wait for 2 seconds before measuring again
            time.sleep(2)

        except Exception as e:
            print("Error: ", e)
            time.sleep(2)

