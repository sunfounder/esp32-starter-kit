.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _install_micropython_on_esp32:

1.3 ESP32にMicroPythonをインストールする(重要)
==================================================

#. USBケーブルを使用して、ESP32 WROOM 32E をコンピュータに接続します。

   .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Thonny IDE の右下隅をクリックし、ポップアップメニューから **"MicroPython(ESP32).xxxCOMXX"** を選択し、**"Configure interpreter"** をクリックします。

   .. note::

      「Local Python 3」以外のオプションが表示されない場合は、ESP32 ボードがコンピュータに認識されていない可能性があります。  
      その場合は、:ref:`install_driver` を実行する必要があるかもしれません。

   .. image:: img/install_micropython1.png

#. 新しく表示されたウィンドウで **"Install or Update MicroPython"** をクリックします。

   .. image:: img/install_micropython2.png

#. 正しいポート、MicroPython ファミリー、バリアント、ボードを選択し、**"Install"** をクリックします。

   * :ref:`download_mode`
   
   .. image:: img/install_micropython3.png

#. インストールが成功したら、Thonny のホーム画面に戻ります。赤いエラーメッセージの代わりに、MicroPython のバージョンや ESP32 に関するプロンプトが表示されます。

   .. image:: img/install_micropython5.png
