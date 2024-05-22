.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _py_transistor:

5.6 トランジスタの二種類
==========================================
このキットには、二種類のトランジスタ、S8550とS8050が装備されており、前者がPNP型で、後者がNPN型です。外見はとても似ているため、ラベルを注意深く確認する必要があります。
Highレベルの信号がNPNトランジスタを通ると、エネルギーが供給されます。しかし、PNP型はLowレベルの信号で制御が必要です。これらのトランジスタは、この実験のように、非接触型スイッチで頻繁に使用されます。

トランジスタの使用方法を理解するために、LEDとボタンを使いましょう！

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**利用可能なピン**

* **利用可能なピン**

    こちらは、このプロジェクトのためのESP32ボード上の利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 入力用
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - 出力用
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

* **条件付き使用ピン（入力）**

    以下のピンは内蔵のプルアップまたはプルダウン抵抗があるため、 **入力ピンとして使用する場合** 

    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - 条件付き使用ピン
            - 説明
        *   - IO13, IO15, IO2, IO4
            - 47Kの抵抗でプルアップし、デフォルト値を高にします。
        *   - IO27, IO26, IO33
            - 4.7Kの抵抗でプルアップし、デフォルト値を高にします。
        *   - IO32
            - 1Kの抵抗でプルダウンし、デフォルト値を低にします。


* **ストラッピングピン（入力用）**

    ストラッピングピンは、デバイスの起動時（つまり、電源オンリセット時）に特定のブートモードを決定するために使用される特別なピンのセットです。

    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15

    一般に、これらを入力ピンとして使用することは **推奨されません**。これらのピンを使用したい場合は、ブートプロセスへの影響を考慮してください。詳細は :ref:`esp32_strapping` セクションを参照してください。



**NPN（S8050）トランジスタの接続方法**

.. image:: ../../img/circuit/circuit_5.6_S8050.png

この回路では、ボタンを押すとIO14が高くなります。

IO26をプログラムして **high** を出力することで、1kの電流制限抵抗（トランジスタを保護するため）を経て、S8050（NPNトランジスタ）が導通し、LEDが点灯します。


.. image:: ../../img/wiring/5.6_s8050_bb.png

**PNP（S8550）トランジスタの接続方法**

.. image:: ../../img/circuit/circuit_5.6_S8550.png

この回路では、IO14はデフォルトで低く、ボタンを押すと高くなります。

IO26をプログラムして **low** を出力することで、1kの電流制限抵抗（トランジスタを保護するため）を経て、S8550（PNPトランジスタ）が導通し、LEDが点灯します。

この回路と前の回路の唯一の違いは、前の回路ではLEDのカソードが **S8050（NPNトランジスタ）** の **コレクタ** に接続されているのに対し、この回路では **エミッタ** に接続されていることです。

.. image:: ../../img/wiring/5.6_s8550_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\micropython\codes`` パスにある ``5.6_transistor.py`` ファイルを開くか、コードをThonnyにコピー＆ペーストします。次に、「Run Current Script」をクリックするかF5キーを押して実行します。
    * 右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択してください。



.. code-block:: python

    import machine 

    button = machine.Pin(14, machine.Pin.IN)   # Button
    led = machine.Pin(26, machine.Pin.OUT)  # LED

    # Start an infinite loop
    while True:  
        # Read the current value of the 'button' object (0 or 1) and store it in the 'button_status' variable
        button_status = button.value() 
        # If the button is pressed (value is 1)
        if button_status == 1: 
            led.value(1) # Turn the LED on
        # If the button is not pressed (value is 0)
        else:       
            led.value(0)            # turn the LED off



二種類のトランジスタは同じコードを使用して制御できます。
ボタンを押すと、ESP32はトランジスタに高レベルの信号を送ります。
それを放すと、低レベルの信号を送ります。

* S8050（NPNトランジスタ）を使用した回路は、ボタンを押すと点灯し、高レベル導通状態であることを示します。
* S8550（PNPトランジスタ）を使用した回路は、ボタンを放すと点灯し、低レベル導通状態であることを示します。
