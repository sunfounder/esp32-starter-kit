.. _ar_7_segment:

2.5 7セグメントディスプレイ
===================================

この魅力的なプロジェクトへようこそ！このプロジェクトでは、7セグメントディスプレイに0から9までの数字を表示する方法を探求します。

このプロジェクトを始動させると、0から9までの各数字が小さくコンパクトなディスプレイに鮮やかに光る様子を目にすることでしょう。まるで魅力的な方法で数字を紹介するミニチュアスクリーンを持っているかのようです。信号ピンを制御することで、表示される数字を簡単に変更し、さまざまな引き込まれるような効果を作り出すことができます。

シンプルな回路接続とプログラミングを通じて、7セグメントディスプレイとのやり取りの方法を学び、希望する数字を実際に表示させる方法を習得します。カウンターであれ、時計であれ、または他の面白い応用であれ、7セグメントディスプレイはあなたのプロジェクトに輝きを添える信頼できる仲間となるでしょう。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

一式を購入するのが便利です。こちらがリンクです:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

もちろん、以下のリンクから個別に購入することもできます。

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
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**利用可能なピン**

このプロジェクトでESP32ボードに利用可能なピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_2.5_74hc595_7_segment.png

ここでは、配線の原理は基本的に :ref:`ar_74hc595` と同じですが、唯一の違いは Q0-Q7 が7セグメントディスプレイの a 〜 g ピンに接続されている点です。

.. list-table:: 回路図
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - LED Segment Display
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**配線図**


.. image:: ../../img/wiring/2.5_segment_bb.png
    :width: 800

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\2.5_7segment`` のパスの下にある ``2.5_7segment.ino`` ファイルを開きます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/937f5e3f-2d9e-4c75-8331-ace3c0876182/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、LEDセグメントディスプレイが0～9までの数字を順番に表示するのが見られるでしょう。

**どのように機能するのか？**

このプロジェクトでは、``shiftOut()`` 関数を使用して、バイナリ数をシフトレジスタに書き込んでいます。

7セグメントディスプレイが "2" という数字を表示するとします。このビットパターンは、セグメント **f**、 **c**、 **dp** がオフ（低）で、セグメント **a**、 **b**、 **d**、 **e**、 **g** がオン（高）であることに対応しています。これはバイナリで "01011011"、16進数表記で "0x5b" です。

したがって、7セグメントディスプレイに "2" と表示するためには ``shiftOut(DS,SHcp,MSBFIRST,0x5b)`` を呼び出す必要があります。

.. image:: img/7_segment2.png

* `16進数 <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `バイナリー・ヘックス変換器 <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

以下の表は、7セグメントディスプレイに0から9までの数字を表示するためにシフトレジスタに書き込む必要がある16進数のパターンを示しています。

.. list-table:: Glyph Code
    :widths: 20 20 20
    :header-rows: 1

    *   - Numbers	
        - Binary Code
        - Hex Code  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

これらのコードを ``shiftOut()`` に書き込むと、LED セグメント ディスプレイに対応する数字が表示されます。