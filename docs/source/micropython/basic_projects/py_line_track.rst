.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_line_track:

5.4 ラインの検出
===================================

ライントラッキングモジュールは、地面にある黒いエリア、例えば電気テープで貼られた黒い線を検出するために使用されます。

その発光部は適切な赤外線を地面に放射し、それは黒い表面によって相対的に吸収され弱く反射されます。白い表面では反対のことが真です。反射光が検出された場合、現在の地面は白として示されます。検出されなかった場合は、黒として示されます。

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

**利用可能なピン**

* **利用可能なピン**

    このプロジェクトのESP32ボードに利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 利用可能なピン
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **ストラッピングピン（入力）**

    ストラッピングピンは、デバイスの起動時に特定のブートモードを決定するために使用される特別なセットのピンです
    （つまり、電源オンリセット）。
   
    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15 
    
    一般的に、 **入力ピンとして使用することは推奨されません**。これらのピンを使用したい場合は、ブートプロセスへの潜在的な影響を考慮してください。詳細については、 :ref:`esp32_strapping` セクションを参照してください。

**回路図**

.. image:: ../../img/circuit/circuit_5.4_line.png

ライントラッキングモジュールが黒い線を検出すると、IO14はハイレベルを返します。一方、白い線を検出すると、IO14はローレベルを返します。青いポテンショメータを調整して、このモジュールの感度を変更できます。


**配線図**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.4_detect_the_line.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストしてください。次に、「現在のスクリプトを実行」をクリックするか、F5キーを押して実行します。
    * 右下のコーナーで「MicroPython (ESP32).COMxx」インタープリタを選択してください。


.. code-block:: python

    import machine
    import time

    # Create a pin object named greyscale, set pin number 14 as input
    line = machine.Pin(14, machine.Pin.IN)


    while True:
        # Check if the value is 1 (black)
        if line.value() == 1:
            # Print "black"
            print("black")
            time.sleep(0.5)
        # If the value is not 1 (it's 0, which means white)
        else :
            # Print "white"
            print("white")
            time.sleep(0.5)



プログラムが実行中の場合、ライントラッキングモジュールが黒い線を検出すると、シェルに「black」と表示されます。それ以外の場合は、「white」と表示されます。

