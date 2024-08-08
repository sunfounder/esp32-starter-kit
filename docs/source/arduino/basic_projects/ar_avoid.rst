.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_ir_obstacle:

5.3 障害物の検出
===================================

このモジュールは一般的に車やロボットに設置され、前方の障害物の有無を判定するために使用されます。また、携帯型デバイスや自動水栓などにも広く利用されています。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全キットを購入すると大変便利です。こちらがリンクです：

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
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|


**利用可能なピン**

* **利用可能なピン**

    このプロジェクトにおいてESP32ボードで利用可能なピンのリストです。

    .. list-table::
        :widths: 5 20

        *   - 利用可能なピン
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **ストラッピングピン（入力用）**

    ストラッピングピンは、デバイス起動時（電源オン時のリセット）に特定のブートモードを決定するために使用される特別なピンのセットです。
        
    .. list-table::
        :widths: 5 15

        *   - ストラッピングピン
            - IO5, IO0, IO2, IO12, IO15 
    
    一般的に、これらのピンを入力用として使用することは **お勧めできません**。これらのピンを使用する場合は、ブートプロセスへの影響を考慮してください。詳細は :ref:`esp32_strapping` セクションを参照してください。

**回路図**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

障害物回避モジュールが障害物を検出しない場合、IO14はハイレベルを返します。しかし、障害物を検出するとローレベルを返します。このモジュールの検出距離は青色のポテンショメータを調整して変更することができます。

**配線図**


.. image:: ../../img/wiring/5.3_avoid_bb.png


**コード**

.. note::

    * ファイル ``5.3.detect_the_obstacle.ino`` をパス ``esp32-starter-kit-main\c\codes\5.3.detect_the_obstacle`` から開くことができます。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b0f22caa-3c77-4dc1-9a33-20ff23d04a5e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

シリアル通信のボーレートを115200に設定することを忘れないでください。

コードが正常にアップロードされた後、IR障害物回避モジュールが何かを検出してブロックしている場合は、シリアルモニターに「0」が表示されます。それ以外の場合は「1」が表示されます。
