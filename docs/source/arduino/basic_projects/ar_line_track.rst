.. _ar_line_track:

5.4 ライン検出
===================================

ライン追跡モジュールは、電気テープで貼られた黒線のような地面の黒いエリアの存在を検出するために使用されます。

その発光体は地面に適切な赤外線を放射し、黒い面はそれを吸収し反射が弱まります。白い面の場合はその逆です。反射光が検出された場合、その部分は白とみなされます。検出されない場合は黒とみなされます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全キットを購入するととても便利です。こちらがリンクです：

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
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

**利用可能なピン**

* **利用可能なピン**

    このプロジェクトでESP32ボードにて利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 利用可能なピン
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **ストラッピングピン（入力用）**

    ストラッピングピンは、デバイスの起動時（電源オンリセット時）に特定のブートモードを決定するための特別なピンセットです。

        
    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15 

    通常、これらのピンを入力ピンとして使用することは **お勧めできません**。これらのピンを使用する場合は、ブートプロセスに与える影響を考慮してください。詳細は :ref:`esp32_strapping` セクションを参照してください。

**回路図**

.. image:: ../../img/circuit/circuit_5.4_line.png

ライン追跡モジュールが黒い線を検出した場合、IO14はハイレベルを返します。白い線を検出した場合、IO14はローレベルを返します。このモジュールの感度を変更するには、青いポテンショメータを調整してください。

**配線図**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\5.4_detect_the_line`` パスの下にあるファイル ``5.4_detect_the_line.ino`` を開いてください。
    * ボード（ESP32 Dev Module）を選択し、適切なポートを指定した後、 **アップロード** ボタンをクリックしてください。
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fc7f3fe9-179a-4a3a-acbf-a4014faf3920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、ライン追跡モジュールが黒い線を検出すると、シリアルモニターに「Black」と表示されます。それ以外の場合は「White」と表示されます。
