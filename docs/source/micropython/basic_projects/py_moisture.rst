.. _py_moisture:

5.9 土壌水分を測定する
==========================

この容量性土壌水分センサーは市場に出回っているほとんどの抵抗型センサーとは異なり、容量性誘導の原理を用いて土壌の水分を検出します。

土壌水分センサーからの値を視覚的に読み取ることで、土壌の水分レベルに関する情報を収集できます。この情報は、自動灌漑システム、植物の健康監視、環境センシングプロジェクトなど、様々なアプリケーションに有用です。

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

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

.. image:: ../../img/circuit/circuit_5.9_soil_moisture.png

モジュールを土壌に挿入し、水やりをすると、I35で読み取られる値が減少します。

**配線図**

.. image:: ../../img/wiring/5.9_moisture_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.9_moisture.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。



.. code-block:: python


    from machine import ADC,Pin
    import time

    # create an ADC object acting on a pin
    moisture = ADC(Pin(35, Pin.IN))

    # Configure the ADC attenuation to 11dB for full range     
    moisture.atten(moisture.ATTN_11DB)

    while True:

        # read a raw analog value in the range 0-4095
        value = moisture.read()  
        print(value)
        time.sleep(0.05)



スクリプトを実行すると、土壌の水分値がシェルに表示されます。

モジュールを土壌に挿入し、水やりをすると、土壌水分センサーの値は小さくなります。
