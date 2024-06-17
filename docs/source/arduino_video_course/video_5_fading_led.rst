.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebookへようこそ！Raspberry Pi、Arduino、ESP32の世界を他の愛好家たちと一緒に深く探求しましょう。

    **参加する理由**

    - **専門的なサポート**：購入後の問題や技術的な課題を、コミュニティとチームの助けを借りて解決します。
    - **学びと共有**：スキル向上のためのヒントやチュートリアルを交換します。
    - **限定プレビュー**：新製品の発表やプレビューをいち早く入手できます。
    - **特別割引**：最新製品の限定割引を享受できます。
    - **フェスティブプロモーションとギブアウェイ**：ギブアウェイやフェスティブプロモーションに参加できます。

    👉 私たちと一緒に探索し、創造する準備はできましたか？[|link_sf_facebook|]をクリックして、今日参加しましょう！

Video 5: LEDフェード - LEDの明るさを制御する
=======================================================

このチュートリアルでは、SunFounder ESP32モジュールを使用してLEDの明るさをフェードインまたはフェードアウトする方法を説明します。

* **LEDの明るさ制御**：PWM（パルス幅変調）を使用してLEDの明るさを制御する方法を説明します。デジタル信号、デューティサイクル、およびデューティサイクルの変化がLEDの明るさをどのように制御するかを解説します。
* **配線図とセットアップ**：220オームの抵抗を使ってESP32にLEDを接続するための詳細な配線図を提供し、ブレッドボード上での実際のセットアップを示します。
* **コードの説明**：LEDをフェードさせるためのArduinoコードを説明します。 ``ledcSetup`` 、 ``ledcAttachPin`` 、および ``ledcWrite`` といった関数について、パラメータと使用方法を詳しく説明します。
* **実際のデモンストレーション**：コードをESP32にアップロードし、配線を確認し、LEDのフェード効果を観察する方法を示します。フェード速度と明るさのレベルを調整するためのヒントも提供します。

この包括的なガイドは、ESP32を使用したLED制御について初心者に学んでいただくのに最適で、ステップバイステップの指示、コードの詳細、および実際のデモンストレーションを提供します。

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/O_tk0itHccs?si=rO9GmMaJpdHvDuEY" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**関連オンラインチュートリアル**

* :ref:`ar_fading`
