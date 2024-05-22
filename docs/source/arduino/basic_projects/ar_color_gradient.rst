.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_color_gradient:

6.5 カラーグラデーション
==============================================
色彩の世界を体験する準備はできていますか？このプロジェクトでは、RGB LEDを制御し、滑らかな色の遷移を実現することができます。自宅の装飾に色を加えたい方や、楽しいプログラミングプロジェクトを探している方にもぴったりです。さあ、このカラフルな世界に一緒に飛び込みましょう！

**必要な部品**

このプロジェクトには以下のコンポーネントが必要です。

キットを一式購入すると便利です。こちらがリンクです：

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**回路図**

.. image:: ../../img/circuit/circuit_6.5_color_gradient_ar.png


**配線図**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

RGB LEDには4本のピンがあります。一番長いピンが共通カソードピンで、通常はGNDに接続されます。最も長いピンの隣の左ピンが赤、右側の2ピンが緑と青です。

.. image:: ../../img/wiring/6.5_color_rgb_bb.png

**コード**


.. note::

    * ファイル ``6.5_color_gradient.ino`` をパス ``esp32-starter-kit-main\c\codes\6.5_color_gradient`` から開いてください。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a8402b92-8884-4ba0-b09c-e596e97e0af8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
このプロジェクトでは、RGB LEDとポテンショメータを使用して色混合効果を作り出します。ポテンショメータはLEDの色相値を調整するために使用され、その色相値は色変換関数を使用してRGB値に変換されます。そして、RGB値を使用してLEDの色を更新します。

**どのように動作するのか？**

このプロジェクトは、 :ref:`ar_rgb` プロジェクトに基づいており、LEDの色相値を調整するためのポテンショメータを追加しています。色相値は色変換関数を使用してRGB値に変換されます。

#. ループ関数内で、ポテンショメータの値を読み取り、色相値（0-360）に変換します。

    .. code-block:: arduino

        int knobValue = analogRead(KNOB_PIN);
        float hueValue = (float) knobValue / 4095.0;
        int hue = (int) (hueValue * 360);

#. ``HUEtoRGB()`` 関数を使用して色相値をRGB値に変換し、新しい色値でLEDを更新します。

    .. code-block:: arduino

        int red, green, blue;
        HUEtoRGB(hue, &red, &green, &blue);
        setColor(red, green, blue);

#. ``setColor()`` 関数は ``LEDC`` ライブラリを使用して赤、緑、青チャンネルの値を設定します。

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            ledcWrite(redChannel, red);
            ledcWrite(greenChannel, green);
            ledcWrite(blueChannel, blue);
        }
    
#. ``HUEtoRGB`` 関数は、HSLカラーモデルを使用して色相値をRGB値に変換します。

    .. code-block:: arduino

        void HUEtoRGB(int hue, int* red, int* green, int* blue) {
            float h = (float) hue / 60.0;
            float c = 1.0;
            float x = c * (1.0 - fabs(fmod(h, 2.0) - 1.0));
            float r, g, b;
            if (h < 1.0) {
                r = c;
                g = x;
                b = 0;
        ...

