.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_ac_buz:

3.1 ビープ音
==================
これは、アクティブブザーを毎秒4回速くビープ音を鳴らすシンプルなプロジェクトです。

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**利用可能なピン**

このプロジェクトのESP32ボードに利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

IO14の出力が高いと、1Kの電流制限抵抗（トランジスタを保護するため）を経由して、S8050（NPNトランジスタ）が導通し、ブザーが鳴ります。

S8050（NPNトランジスタ）の役割は、電流を増幅してブザーの音を大きくすることです。実際には、ブザーを直接IO14に接続しても問題ありませんが、ブザーの音が小さくなることがわかります。

**配線図**

キットには2種類のブザーが含まれています。
アクティブブザーを使用する必要があります。それらを裏返すと、シールドされた背面（露出したPCBではない方）が必要なものです。

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

ブザーは動作時にトランジスタを使用する必要がありますが、ここではS8050（NPNトランジスタ）を使用します。

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``3.1_beep.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。 

.. code-block:: python

    import machine
    import time

    # Create a Pin object representing pin 14 and set it to output mode
    buzzer = machine.Pin(14, machine.Pin.OUT)

    # Enter an infinite loop
    while True:
        # Iterate over the values 0 to 3 using a for loop
        for i in range(4):
            # Turn on the buzzer by setting its value to 1
            buzzer.value(1)
            # Pause for 0.2 seconds
            time.sleep(0.2)
            # Turn off the buzzer
            buzzer.value(0)
            # Pause for 0.2 seconds
            time.sleep(0.2)
        # Pause for 1 second before restarting the for loop
        time.sleep(1)



スクリプトが実行されると、ブザーは毎秒4回速くビープ音を鳴らします。

