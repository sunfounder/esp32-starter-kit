.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_flowing_light:

6.2 流れる光
=================================

あなたの居間に楽しさとインタラクティブな要素を加えたいと思ったことはありませんか？
このプロジェクトでは、WS2812 LEDストリップと障害物回避モジュールを使用して走行する光を作ります。
障害物が検出されると光の方向が変わり、家やオフィスの装飾にエキサイティングな追加をすることができます。

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**回路図**

.. image:: ../../img/circuit/circuit_6.2_flowing_led.png
    :align: center

WS2812 LEDストリップは、異なる色やパターンを表示できる一連の個別LEDで構成されています。
このプロジェクトでは、ストリップは特定の方向に動く走行光を表示するように設定されており、
障害物回避モジュールによって障害物が検出されると方向が変わります。

**配線図**

.. image:: ../../img/wiring/6.2_flowing_light_bb.png
    :width: 800

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``6.2_flowing_led.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。

.. code-block:: python

      from machine import Pin
      import neopixel
      import time
      import random

      # Set the number of pixels for the running light
      num_pixels = 8

      # Set the data pin for the RGB LED strip
      data_pin = Pin(14, Pin.OUT)

      # Initialize the RGB LED strip object
      pixels = neopixel.NeoPixel(data_pin, num_pixels)

      # Initialize the avoid sensor
      avoid = Pin(25, Pin.IN)

      # Initialize the direction variable
      direction_forward = True

      # Initialize the reverse direction flag
      reverse_direction = False

      # Continuously loop the running light
      while True:
      
      # Read the input from the infrared sensor
      avoid_value = avoid.value()
      
      # Generate a random color for the current pixel
      color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
                  
      # If no obstacle is detected
      if avoid_value:
            for i in range(num_pixels):
                  
                  # Turn on the current pixel with the random color
                  pixels[i] = color
                  
                  # Update the RGB LED strip display
                  pixels.write()
                  
                  # Turn off the current pixel
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)
                  
      # If detects an obstacle, change the direction of the LED strip
      else:
            for i in range(num_pixels-1, -1, -1):
                  
                  pixels[i] = color
                  pixels.write()
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)

スクリプトが実行されると、RGB ストリップの LED が 1 つずつ点灯します。 障害物回避モジュールの前に物体が置かれるとすぐに、RGB ストリップ上の LED が反対方向に 1 つずつ点灯します。