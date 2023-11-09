1.3 ESP32ボードのインストール（重要）
===========================================

ESP32マイクロコントローラをプログラムするためには、Arduino IDEにESP32ボードパッケージをインストールする必要があります。以下のステップバイステップガイドに従ってください：

#. Arduino IDEを開きます。 **File** を選択し、ドロップダウンメニューから **Preferences** を選びます。

    .. image:: img/install_esp321.png

#. 環境設定ウィンドウで、 **Additional Board Manager URLs** フィールドを探します。クリックしてテキストボックスをアクティブにします。

    .. image:: img/install_esp322.png

#. 次のURLを **Additional Board Manager URLs** フィールドに追加します： https://dl.espressif.com/dl/package_esp32_index.json。このURLはESP32ボードのパッケージインデックスファイルを指します。 **OK** ボタンをクリックして変更を保存します。

    .. image:: img/install_esp323.png

#. **Boards Manager** ウィンドウで、検索バーに **ESP32** と入力します。 **Install** ボタンをクリックしてインストールプロセスを開始します。これにより、ESP32ボードパッケージがダウンロードおよびインストールされます。

    .. image:: img/install_esp324.png

#. おめでとうございます！Arduino IDEにESP32ボードパッケージを正常にインストールしました。これで、 **Tools** -> **Board** -> **esp32** に進んで、正しいボード **ESP32 Dev Module** を選択できます。

    .. image:: img/install_esp325.png

#. ESP32がコンピュータに接続されている場合は、 **Tools** -> **Port** に進んで正しいポートを選択できます。

    .. image:: img/install_esp326.png

#. さらに、Arduino 2.0では、ボードとポートを迅速に選択する新しい方法が導入されました。ESP32の場合、通常は自動的に認識されないため、 **Select other board and port** をクリックする必要があります。

    .. image:: img/install_esp327.png

#. 検索ボックスに **ESP32 Dev Module** と入力し、表示されたら選択します。次に、正しいポートを選択し **OK** をクリックします。

    .. image:: img/install_esp328.png

#. その後、このクイックアクセスウィンドウを通じて選択できます。ただし、後続の使用時には、ESP32がクイックアクセスウィンドウで利用できない場合があり、上記の2ステップを繰り返す必要があることに注意してください。

    .. image:: img/install_esp329.png

#. これらの方法のどちらも、正しいボードとポートを選択するために利用できますので、最も適した方法を選んでください。これで、ESP32にコードをアップロードする準備が整いました。



