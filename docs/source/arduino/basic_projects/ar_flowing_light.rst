.. _ar_flowing_light:

6.2 流れる光
=======================

あなたの居住空間に楽しさとインタラクティブな要素を加えたいと思ったことはありませんか？
このプロジェクトでは、WS2812 LEDストリップと障害物回避モジュールを使用して走行光を作成します。
障害物が検出されると走行光の方向が変わり、家やオフィスの装飾にエキサイティングな追加をすることができます。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

全てのキットを購入することは非常に便利です。リンクはこちらです:

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
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**回路図**

.. image:: ../../img/circuit/circuit_6.2_flowing_led.png
    :align: center

WS2812 LEDストリップは、異なる色やパターンを表示するようにプログラムできる一連の個別LEDで構成されています。
このプロジェクトでは、ストリップは特定の方向に動く走行光を表示するように設定され、
障害物回避モジュールによって障害物が検出されたときに方向が変わります。


**配線図**

.. image:: ../../img/wiring/6.2_flowing_light_bb.png
    

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\6.2_flowing_led`` のパスの下にあるファイル ``6.2_flowing_led.ino`` を直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ff625cb6-2efd-436a-9b59-5dd967191338/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

このプロジェクトは、:ref:`ar_rgb_strip` プロジェクトの機能を拡張し、LEDストリップにランダムな色を表示する機能を追加しています。
さらに、障害物回避モジュールが含まれており、走行光の方向を動的に変更できます。

