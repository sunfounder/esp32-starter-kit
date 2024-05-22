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

#. MicroPythonの公式ウェブサイトから |link_esp32_micropython_download| をダウンロードし、その後で最新バージョンのファームウェアをダウンロードします。

    .. image:: img/dowload_micropython_uf2.png

#. Micro USBケーブルを使用して、ESP32 WROOM 32Eをコンピューターに接続します。

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Thonny IDEの右下隅をクリックし、ポップアップメニューから **「MicroPython(ESP32).COMXX」** を選択し、 **「Configure interpreter」** を選択します。

    .. image:: img/install_micropython1.png

#. 新しいポップアップウィンドウで **「Install or Update MicroPython」** をクリックします。

    .. image:: img/install_micropython2.png

#. 正しいポートと先ほどダウンロードしたファームウェアを選択し、 **「Install」** をクリックします。

    .. image:: img/install_micropython3.png

#. インストールが成功した後、このページを閉じることができます。

    .. image:: img/install_micropython4.png

#. Thonnyのホームページに戻ると、赤いエラープロンプトの代わりにMicroPythonのバージョンとESP32関連のプロンプトが表示されます。

    .. image:: img/install_micropython5.png
