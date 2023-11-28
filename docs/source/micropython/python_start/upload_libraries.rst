.. _add_libraries_py:

1.4 ライブラリのアップロード（重要）
======================================

一部のプロジェクトでは、追加のライブラリが必要になることがあります。ここでは、これらのライブラリを先にESP32にアップロードしておき、後でコードを直接実行できるようにします。

#. 下記のリンクから関連するコードをダウンロードします。


   * :download:`SunFounder ESP32スターターキット <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`

#. Micro USBケーブルを使用して、ESP32 WROOM 32Eをコンピューターに接続します。

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Thonny IDEを開き、右下隅にある「MicroPython (ESP32).COMXX」インタープリタをクリックします。
    .. image:: img/sec_inter.png

#. 上部のナビゲーションバーで、 **View** -> **Files** をクリックします。

    .. image:: img/th_files.png

#. `コードパッケージ <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`_ をダウンロードしたフォルダへのパスを切り替え、その後で ``esp32-starter-kit-main\micropython\libs`` フォルダに進みます。

    .. image:: img/th_path.png

#. ``libs/`` フォルダ内の全てのファイルやフォルダを選択し、右クリックして **Upload to** をクリックします。アップロードには少し時間がかかります。

    .. image:: img/th_upload.png

#. これで、アップロードしたばかりのファイルが ``MicroPython device`` 内に表示されます。

    .. image:: img/th_done.png
