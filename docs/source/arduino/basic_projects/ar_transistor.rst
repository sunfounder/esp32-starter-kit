.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_transistor:

5.6 トランジスタの二種類
==========================================
本キットには、S8550（PNPタイプ）とS8050（NPNタイプ）の2種類のトランジスタが含まれています。見た目は非常に似ているため、ラベルを注意深く確認する必要があります。
NPNトランジスタはハイレベル信号を受け取ると動作しますが、PNPトランジスタはローレベル信号で制御する必要があります。これらのトランジスタは、この実験のように、非接触スイッチに頻繁に使用されます。

トランジスタの使用方法をLEDとボタンを使って理解しましょう！

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全キットを購入すると非常に便利です。こちらがリンクです：

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**利用可能なピン**

* **利用可能なピン**

    このプロジェクトでESP32ボードにて利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 入力用
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - 出力用
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

* **条件付き使用ピン（入力用）**

    以下のピンには内蔵のプルアップ抵抗またはプルダウン抵抗があるため、 **入力ピンとして使用する場合**、外部抵抗は不要です：

    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Conditional Usage Pins
            - Description
        *   - IO13, IO15, IO2, IO4
            - Pulling up with a 47K resistor defaults the value to high.
        *   - IO27, IO26, IO33
            - Pulling up with a 4.7K resistor defaults the value to high.
        *   - IO32
            - Pulling down with a 1K resistor defaults the value to low.

* **ストラッピングピン（入力用）**

    ストラッピングピンは、デバイスの起動時（つまり、電源オンリセット時）に特定のブートモードを決定するために使用される特別なピンのセットです。

    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15

    通常、これらのピンを入力ピンとして使用することは **推奨されません**。これらのピンを使用する場合は、ブートプロセスに与える可能性のある影響を考慮してください。詳細については、 :ref:`esp32_strapping` セクションを参照してください。

**NPN（S8050）トランジスタの接続方法**

.. image:: ../../img/circuit/circuit_5.6_S8050.png

この回路では、ボタンが押されるとIO14がハイになります。

IO26を **ハイ** に設定してプログラムし、1kの電流制限抵抗器（トランジスタを保護するため）を介して、S8050（NPNトランジスタ）が導通することを許可することで、LEDが点灯します。

.. image:: ../../img/wiring/5.6_s8050_bb.png

**PNP（S8550）トランジスタの接続方法**

.. image:: ../../img/circuit/circuit_5.6_S8550.png

この回路では、デフォルトではIO14はローであり、ボタンが押されるとハイに変わります。

IO26を **ロー** に設定してプログラムし、1kの電流制限抵抗器（トランジスタを保護するため）を介して、S8550（PNPトランジスタ）が導通することを許可することで、LEDが点灯します。

この回路と前の回路の唯一の違いは、前の回路ではLEDのカソードが **S8050（NPNトランジスタ）** の **コレクター** に接続されているのに対し、こちらの回路では **S8550（PNPトランジスタ）** の **エミッター** に接続されている点です。

.. image:: ../../img/wiring/5.6_s8550_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\5.6_transistor`` のパスの下にあるファイル ``5.6_transistor.ino`` を開くことができます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/3ab778b4-642d-4a5d-8b71-05bc089389e5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

同じコードを使用して2種類のトランジスタを制御することができます。
ボタンを押すと、ESP32はトランジスタにハイレベルの信号を送信し、
それを放すと、ローレベルの信号を送信します。

* S8050（NPNトランジスタ）を使用した回路は、ボタンを押すと点灯し、ハイレベルの導通状態であることを示します。
* S8550（PNPトランジスタ）を使用した回路は、ボタンを放すと点灯し、ローレベルの導通状態であることを示します。
