.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_plant_monitor:

6.8 植物モニター
===============================

植物モニタープロジェクトへようこそ！

このプロジェクトでは、ESP32ボードを使って、私たちの植物の世話を助けるシステムを作ります。このシステムを使えば、植物の温度、湿度、土壌の水分、そして光のレベルを監視し、植物が栄えるために必要なケアと注意を確実に提供できます。

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**回路図**

.. image:: ../../img/circuit/circuit_6.8_plant_monitor_l293d.png

このシステムは、DHT11センサーを使用して周囲環境の温度と湿度レベルを測定します。
一方、土壌水分モジュールは土壌の水分レベルを、フォトレジスターは光のレベルを測定するために使用されます。
これらのセンサーからの読み取り値はLCDスクリーンに表示され、必要に応じて植物に水をやるための水ポンプはボタンを使って制御することができます。

IO32には1Kの内部プルダウン抵抗があり、デフォルトではロジックレベルが低いです。ボタンを押すと、VCC（高電圧）への接続が確立され、IO32上でロジックレベルが高くなります。

**配線図**

.. note::

    ここでは、バッテリーを挿入してから、拡張ボード上のスイッチをON位置にスライドさせてバッテリー供給を有効にすることをお勧めします。

.. image:: ../../img/wiring/6.8_plant_monitor_l293d_bb.png
    :width: 800

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``6.8_plant_monitor.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。それから、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。

.. code-block:: python

      from machine import ADC, Pin
      import time
      import dht
      from lcd1602 import LCD

      # DHT11
      dht11 = dht.DHT11(Pin(13))

      # Soil moisture
      moisture_pin = ADC(Pin(14))
      moisture_pin.atten(ADC.ATTN_11DB)

      # Photoresistor
      photoresistor = ADC(Pin(35))
      photoresistor.atten(ADC.ATTN_11DB)

      # Button and pump
      button = Pin(32, Pin.IN)

      motor1A = Pin(27, Pin.OUT)
      motor2A = Pin(26, Pin.OUT)

      # I2C LCD1602 setup
      lcd = LCD()

      # Rotate the pump
      def rotate():
      motor1A.value(1)
      motor2A.value(0)

      # Stop the pump
      def stop():
      motor1A.value(0)
      motor2A.value(0)

      button_state = False

      # Define the button callback function to toggle the button state
      def button_callback(pin):
      global button_state
      button_state = not button_state

      # Attach the button callback function to the rising edge of the button pin
      button.irq(trigger=Pin.IRQ_RISING, handler=button_callback)

      page = 0
      temp = 0
      humi = 0
            
      try:
      while True:
            
            # If the button is pressed and button state is True
            if button_state:
                  print("rotate")
                  rotate()

            # If the button is pressed again and button state is False
            if not button_state:
                  print("stop")
                  stop()
            time.sleep(2)

            # Clear the LCD display
            lcd.clear()
            
            # Toggle the value of the page variable between 0 and 1
            page=(page+1)%2
            
            # When page is 1, display temperature and humidity on the LCD1602
            if page is 1:
                  try:
                  # Measure temperature and humidity
                  dht11.measure()

                  # Get temperature and humidity values
                  temp = dht11.temperature()
                  humi = dht11.humidity()
                  except Exception as e:
                  print("Error: ", e)         

                  # Display temperature and humidity
                  lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
                  lcd.write(0, 1, "Humi: {}%".format(humi))

            # If page is 0, display the soil moisture and light
            else:
                  light = photoresistor.read()
                  moisture = moisture_pin.read()

                  # Clear the LCD display
                  lcd.clear()

                  # Display the value of soil moisture and light
                  lcd.write(0, 0, f"Moisture: {moisture}")
                  lcd.write(0, 1, f"Light: {light}")

      except KeyboardInterrupt:
      # Stop the motor when KeyboardInterrupt is caught
      stop()



* コードが実行中の場合、I2C LCD1602は温度と湿度を交互に表示し、土壌の水分と光の強度のアナログ値を2秒間隔で表示します。
* ボタンを押して水ポンプを起動し、もう一度押して水ポンプを停止します。

.. note:: 

    コードと配線が正しいにも関わらず、LCDに何も表示されない場合は、背面のポテンショメータを調整してコントラストを上げることができます。
