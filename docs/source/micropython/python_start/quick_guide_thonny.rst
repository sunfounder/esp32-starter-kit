1.5 Thonnyのクイックガイド
==================================

.. _open_run_code_py:

直接コードを開いて実行する
---------------------------------------------

プロジェクトのコードセクションでは、使用する正確なコードが示されているので、 ``esp32-starter-kit-main\micropython\codes\`` パスのシリアル番号が付いた ``.py`` ファイルをダブルクリックして開きます。

ただし、 :ref:`add_libraries_py` で説明されているように、まずパッケージをダウンロードしてライブラリをアップロードする必要があります。

#. コードを開く。

    例えば、 ``1.1_hello_led.py`` です。

    ダブルクリックすると、右側に新しいウィンドウが開きます。複数のコードを同時に開くことができます。

    .. image:: img/quick_guide1.png

#. マイクロUSBケーブルでESP32をコンピュータに接続します。

    .. image:: ../../img/plugin_esp32.png

#. 正しいインタプリタを選択

    「MicroPython (ESP32).COMxx」インタプリタを選択します。

    .. image:: img/sec_inter.png

#. コードを実行

    スクリプトを実行するには、 **Run current script** ボタンをクリックするかF5キーを押します。

    .. image:: img/quick_guide2.png

    コードに印刷が必要な情報が含まれている場合は、シェルに表示されます。それ以外の場合は、以下の情報のみが表示されます。

    シェルウィンドウがThonnyに表示されない場合は、 **View** -> **Edit** をクリックして開きます。

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; ESP32 module with ESP32

            詳しい情報は「help()」と入力してください。

            >>> %Run -c $EDITOR_CONTENT

    * 最初の行には、MicroPythonのバージョン、日付、およびデバイス情報が表示されます。
    * 2行目には、「help()」を入力してヘルプを取得するように促されます。
    * 3行目は、スクリプトエリアの「EDITOR_CONTENT」の内容をPico WのMicroPythonインタプリタに実行させるThonnyからのコマンドです。
    * 3行目の後にメッセージがある場合、通常はMicroPythonに印刷するように指示したメッセージ、またはコードのエラーメッセージです。


#. 実行を停止

    .. image:: img/quick_guide3.png

    実行中のコードを停止するには、 **Stop/Restart backend** ボタンをクリックします。 **%RUN -c $EDITOR_CONTENT** コマンドは停止後に消えます。

#. 保存または名前を付けて保存

    Thonnyで開いた例の変更を保存するには、 **Ctrl+S** を押すか、Thonnyの **Save** ボタンをクリックします。

    **File** -> **Save As** をクリックして、 **MicroPython drive(ESP32)** 内の別のファイルとしてコードを保存することができます。

    .. image:: img/quick_guide4.png

    **MicroPython drive** を選択します。

    .. image:: img/quick_guide5.png
        
    ファイル名と拡張子 **.py** を入力した後、 **OK** をクリックします。MicroPythonドライブに保存されたファイルが表示されます。

    .. image:: img/quick_guide6.png

    .. note::
        コードにどんな名前を付けても、コードの種類を記述することが最善です。意味のない名前（例： ``abc.py`` ）は避けましょう。
        コードを ``main.py`` として保存すると、電源を入れたときに自動的に実行されます。


ファイルを作成して実行する
---------------------------

コードはコードセクションで直接示されています。Thonnyにコピーして以下のように実行できます。

#. 新しいファイルを作成する

    Thonny IDEを開き、 **New** ボタンをクリックして新しい空のファイルを作成します。

    .. image:: img/quick_guide7.png

#. コードをコピー

    プロジェクトからのコードをThonny IDEにコピーします。

    .. image:: img/quick_guide8.png

#. マイクロUSBケーブルでESP32をコンピュータに接続します。

    .. image:: ../../img/plugin_esp32.png

#. 正しいインタプリタを選択

    右下隅にある「MicroPython (ESP32).COMxx」インタプリタを選択します。

    .. image:: img/sec_inter.png

#. コードを実行

    **Run Current Script** をクリックするか、単に ``F5`` キーを押して実行します。

    .. image:: img/quick_guide9.png

    コードに印刷が必要な情報が含まれている場合は、シェルに表示されます。それ以外の場合は、以下の情報のみが表示されます。

    シェルウィンドウがThonnyに表示されない場合は、 **View** -> **Edit** をクリックして開きます。

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; ESP32 module with ESP32

            詳しい情報は「help()」と入力してください。

            >>> %Run -c $EDITOR_CONTENT

    * 最初の行には、MicroPythonのバージョン、日付、およびデバイス情報が表示されます。
    * 2行目には、「help()」を入力してヘルプを取得するように促されます。
    * 3行目は、スクリプトエリアの「EDITOR_CONTENT」の内容をPico WのMicroPythonインタプリタに実行させるThonnyからのコマンドです。
    * 3行目の後にメッセージがある場合、通常はMicroPythonに印刷するように指示したメッセージ、またはコードのエラーメッセージです。


#. 実行を停止する

    .. image:: img/quick_guide3.png

    実行中のコードを停止するには、 **Stop/Restart backend** ボタンをクリックします。 **%RUN -c $EDITOR_CONTENT** コマンドは停止後に消えます。

#. 保存または名前を付けて保存

    **Ctrl+S** を押すか、Thonnyの **Save** ボタンをクリックしてコードを保存できます。ポップアップウィンドウで、ファイルを保存する場所を選択します。

    .. image:: img/quick_guide5.png
        
    ファイル名と拡張子 **.py** を入力した後、 **OK** または **Save** をクリックします。

    .. image:: img/quick_guide6.png

    .. note::
        コードにどんな名前を付けても、コードの種類を記述することが最善です。意味のない名前（例： ``abc.py`` ）は避けましょう。
        コードを ``main.py`` として保存すると、電源を入れたときに自動的に実行されます。

#. ファイルを開く

    保存されたコードファイルを開く方法は2つあります。

    * 一つ目の方法は、Thonnyのツールバーにある開くアイコンをクリックすることです。プログラムを保存する時と同じように、 **this computer** から開くか、 **MicroPython device** から開くかを尋ねられます。例えば、 **MicroPython device** をクリックすると、ESP32に保存されている全てのプログラムのリストが表示されます。
    * 二つ目の方法は、 **View** -> **Files** をクリックし、対応する ``.py`` ファイルをダブルクリックして直接ファイルプレビューを開くことです。
