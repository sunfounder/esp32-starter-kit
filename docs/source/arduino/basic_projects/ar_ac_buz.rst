.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_ac_buz:

3.1 ビープ音
==================
このシンプルなプロジェクトでは、アクティブブザーを使って毎秒4回速くビープ音を鳴らします。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

一式を購入することは非常に便利です。こちらがリンクです:

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**利用可能なピン**

ここでは、このプロジェクトでESP32ボードに利用可能なピンのリストを示します。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

IO14の出力がハイのとき、1Kの電流制限抵抗を通って、S8050（NPNトランジスタ）が導通し、ブザーが鳴ります。

S8050（NPNトランジスタ）の役割は電流を増幅して、ブザーの音を大きくすることです。実際には、ブザーを直接IO14に接続することもできますが、ブザーの音が小さいことに気づくでしょう。

**配線図**


キットには2種類のブザーが含まれています。
アクティブブザーを使用する必要があります。それらをひっくり返すと、密封された背面（露出したPCBではない）が私たちが必要とするものです。

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

ブザーの動作にはトランジスタが必要で、ここではS8050（NPNトランジスタ）を使用します。

.. image:: ../../img/wiring/3.1_buzzer_bb.png


**コード**


.. note::

    * ファイル ``3.1_beep.ino`` をパス ``esp32-starter-kit-main\c\codes\3.1_beep`` から開いてください。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
   
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f17a663c-2941-407e-9137-6f6eacd28c23/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、毎秒ビープ音が聞こえます。
