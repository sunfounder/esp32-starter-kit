.. _ar_photoresistor:

5.7 光を感じる
===========================

フォトレジスタは、ポテンショメータに似た、アナログ入力用の一般的なデバイスです。受ける光の強度によって抵抗値が変わります。強い光を浴びるとフォトレジスタの抵抗は減少し、光の強度が弱まると抵抗は増加します。

フォトレジスタの値を読むことによって、周囲の光の条件に関する情報を得ることができます。この情報は、LEDの明るさを制御したり、センサーの感度を調節したり、プロジェクトで光に依存するアクションを実装するために使用できます。

**必要な部品**

このプロジェクトには以下のコンポーネントが必要です。

全てのキットを購入するのは非常に便利です。こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

また、以下のリンクから個別に購入することもできます。

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**利用可能なピン**

* **利用可能なピン**

    こちらは、このプロジェクトのためのESP32ボード上の利用可能なピンのリストです。

    .. list-table::
        :widths: 5 15

        *   - 利用可能なピン
            - IO14, IO25, I35, I34, I39, I36


* **ストラッピングピン**

    以下のピンはストラッピングピンであり、電源オンまたはリセット時のESP32の起動プロセスに影響を与えます。しかし、ESP32が正常に起動した後、通常のピンとして使用できます。

    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO0, IO12

**回路図**

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

光の強度が増すと、光依存抵抗（LDR）の抵抗が減少し、I35で読む値が下がります。

**配線図**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\5.7_feel_the_light`` のパスにある ``5.7_feel_the_light.ino`` ファイルを開いてください。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックしてください。
    * :ref:`unknown_com_port`
    
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/58b494c7-eef4-4476-af65-4823cef13f90/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、シリアルモニターは0から4095までのフォトレジスタの値を出力します。
現在の周囲の明るさが強ければ強いほど、シリアルモニターに表示される値が大きくなります。

.. note::
    ESP32では、解像度は9ビットから12ビットの間で、ADCハードウェアの解像度を変更します。それ以外の場合は値がシフトされます。

    デフォルトは12ビット（0から4096の範囲）で、ESP32S3以外の全てのチップに適用されます。ESP32S3ではデフォルトは13ビット（0から8192の範囲）です。

    ``setup()`` 関数に ``analogReadResolution(10);`` を追加することで、たとえば ``20`` のような異なる解像度を設定することができます。

