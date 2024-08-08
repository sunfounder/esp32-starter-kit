.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_pir:

5.5 人間の動きを検出する
========================================

受動赤外線センサー（PIRセンサー）は、視野内の物体から放出される赤外線（IR）を測定する一般的なセンサーです。
簡単に言うと、人体から放出される赤外線を受け取り、人や他の動物の動きを検出します。
より具体的には、誰かがあなたの部屋に入ったことをメインコントロールボードに知らせます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全キットを購入すると確かに便利です。こちらがリンクです：

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**利用可能なピン**

* **利用可能なピン**

    このプロジェクトでESP32ボードにて利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 入力用
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - 出力用
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::
    
    IO32は内部に1Kプルダウン抵抗が接続されているため、このプロジェクトでは **入力ピンとして使用できません**。デフォルト値が0に設定されます。

* **ストラッピングピン（入力用）**

    ストラッピングピンは、デバイスの起動時（電源オンリセット時）に特定のブートモードを決定するための特別なピンセットです。

    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15 
    

    通常、これらのピンを入力ピンとして使用することは **お勧めできません**。これらのピンを使用する場合は、ブートプロセスに与える影響を考慮してください。詳細は :ref:`esp32_strapping` セクションを参照してください。


**回路図**

.. image:: ../../img/circuit/circuit_5.5_pir.png

PIRモジュールが動きを検出すると、IO14が高くなり、LEDが点灯します。動きが検出されない場合、IO14は低くなり、LEDは消灯します。

.. note::
    PIRモジュールには2つのポテンショメータがあります。一つは感度を、もう一つは検出距離を調整します。PIRモジュールをより良く機能させるために、両方を反時計回りに最後まで回してください。

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**配線図**

.. image:: ../../img/wiring/5.5_pir_bb.png

**コード**

.. note::

    * パス ``esp32-starter-kit-main\c\codes\5.5_pir`` の下にあるファイル ``5.5_pir.ino`` を開いてください。
    * ボード（ESP32 Dev Module）を選択し、適切なポートを指定した後、 **アップロード** ボタンをクリックしてください。
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b5f0cc8-b732-4ed2-b68e-bb7d0a73a1b8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされた後、PIRモジュールが誰かの通過を検出すると、LEDが点灯し、その後消えます。

.. note::
    PIRモジュールには2つのポテンショメータがあります。一つは感度を、もう一つは検出距離を調整します。PIRモジュールをより良く機能させるために、両方を反時計回りに最後まで回してください。

    .. image:: img/pir_back.png

