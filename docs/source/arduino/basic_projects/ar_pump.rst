.. _ar_pump:

4.2 水ポンプ制御
===================
この興味深いプロジェクトでは、L293Dを用いて水ポンプを制御する方法について探ります。

水ポンプ制御の領域では、他のモーター制御に比べて少しシンプルです。このプロジェクトの美点はその単純さにあります - 回転方向について心配する必要がありません。私たちの主目的は水ポンプを成功裏に活動させ、稼働させ続けることです。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式を購入することは確かに便利です。リンクはこちらです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

以下のリンクから個別に購入も可能です。

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
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-

**利用可能なピン**

このプロジェクトでESP32ボードで利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


**配線図**

.. note::

    ここではバッテリーを差し込み、その後拡張ボード上のスイッチをON位置にスライドして、バッテリー供給を有効にすることを推奨します。

.. image:: ../../img/wiring/4.2_pump_l293d_bb.png

**コード**

.. note::

  * ``esp32-starter-kit-main\c\codes\4.2_pump`` のパス下にある ``4.2_pump.ino`` ファイルを開きます。
  * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
  * :ref:`unknown_com_port`
   
.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/a56216f9-eba8-4fdc-8bbb-91337095e543/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

チュービングをポンプに接続し、水が満たされた容器内に置きます。コードが正常にアップロードされた後、容器内の水が徐々に排出される様子が観察できます。この実験中、電気回路が水に触れて短絡を引き起こさないように、水から離しておくことを確認してください！

