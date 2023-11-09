.. _ar_sd_write:

7.4 SDカードの書き込みと読み込み
=================================
このプロジェクトは、ESP32マイクロコントローラを使用してSDカードを操作する基本機能を実演しています。
SDカードのマウント、ファイルの作成、データのファイルへの書き込み、
ルートディレクトリ内の全ファイルのリストアップなどの基本操作を紹介します。これらの操作は多くのデータロギングやストレージ
アプリケーションの基盤となるため、ESP32の内蔵SDMMCホスト周辺機器の理解と活用において、このプロジェクトは重要なステップです。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが間違いなく便利です。リンクはこちらです：

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


**操作手順**

#. USBケーブルを接続する前に、SDカードを拡張ボードのSDカードスロットに挿入します。

    .. image:: ../../img/insert_sd.png

#. USBケーブルを使ってESP32-WROOM-32Eをコンピュータに接続します。

    .. image:: ../../img/plugin_esp32.png

#. Arduino IDEで適切なポートとボードを選択し、コードをESP32にアップロードします。

    .. note::

        * ``esp32-starter-kit-main\c\codes\7.4_sd_read_write`` のパスの下にある ``7.4_sd_read_write.ino`` ファイルを開きます。
        * ボード（ESP32 Dev Module）と適切なポートを選択したら、 **アップロード** ボタンをクリックします。
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/912df4b8-a7b6-43dc-95b5-8206801cc9c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. コードが正常にアップロードされると、成功したファイルの書き込みを示すプロンプトが表示され、SDカードにあるすべてのファイル名とサイズのリストが表示されます。シリアルモニタを開いても何も表示されない場合は、EN（RST）ボタンを押してコードを再実行する必要があります。

    .. image:: img/sd_write_read.png

    .. note::

        以下の情報が表示された場合。

        .. code-block::

            E (528) vfs_fat_sdmmc: mount_to_vfs failed (0xffffffff).
            SDカードのマウントに失敗しました

        まず、SDカードが拡張ボードに適切に挿入されているか確認してください。

        正しく挿入されている場合、SDカードに問題がある可能性があります。金属接点を消しゴムできれいにするとよいでしょう。

        問題が解決しない場合は、SDカードをフォーマットすることをお勧めします。詳細は :ref:`format_sd_card` を参照してください。


**どのように動作するのか？**

このプロジェクトの目的は、ESP32ボードとSDカードを使用する方法を実演することです。ESP32の内蔵SDMMCホスト周辺機器を使用してSDカードに接続します。

プロジェクトはシリアル通信の初期化から始まり、次にSDカードのマウントを試みます。SDカードが正常にマウントされない場合、プログラムはエラーメッセージを出力し、セットアップ機能を終了します。

SDカードが正常にマウントされると、プログラムはSDカードのルートディレクトリに"test.txt"という名前のファイルを作成します。ファイルが書き込みモードで正常に開かれた場合、プログラムはファイルに「Hello, world!」というテキスト行を書き込みます。書き込み操作が成功すると、プログラムは成功メッセージを出力します。そうでない場合は、エラーメッセージが出力されます。

書き込み操作が完了すると、プログラムはファイルを閉じ、次にSDカードのルートディレクトリを開きます。そして、ルートディレクトリのすべてのファイルをループし、見つかった各ファイルのファイル名とファイルサイズを出力します。

メインループ機能には操作はありません。このプロジェクトは、カードのマウント、ファイルの作成、ファイルへの書き込み、ファイルディレクトリの読み取りなど、セットアップ機能で実行されるSDカード操作に焦点を当てています。

このプロジェクトは、データログやストレージが必要なアプリケーションでのESP32を使用したSDカードの取り扱いについての有用な導入となります。

以下はコードの分析です：

#. ``SD_MMC`` ライブラリを含めます。これはESP32の内蔵SDMMCホスト周辺機器を使用してSDカードを操作するために必要です。

    .. code-block:: arduino

        #include "SD_MMC.h"

#. ``setup()`` 関数内では、以下のタスクが実行されます。

    * **SDカードの初期化**

    SDカードを初期化し、マウントします。SDカードがマウントに失敗した場合、シリアルモニターに「SDカードのマウントに失敗しました」と表示し、実行を停止します。

    .. code-block:: arduino
        
        if(!SD_MMC.begin()) { // Attempt to mount the SD card
            Serial.println("Failed to mount card"); // If mount fails, print to serial and exit setup
            return;
        } 
      
    * **ファイルを開く**

    SDカードのルートディレクトリにある ``「test.txt」`` という名前のファイルを書き込みモードで開きます。ファイルが開けなかった場合、「書き込み用ファイルを開けませんでした」と表示し、処理を戻します。

    .. code-block:: arduino

        File file = SD_MMC.open("/test.txt", FILE_WRITE); 
        if (!file) {
            Serial.println("Failed to open file for writing"); // Print error message if file failed to open
            return;
        }


    * **ファイルにデータを書き込む**

    「Test file write」というテキストをファイルに書き込みます。
    書き込み操作が成功した場合は、「ファイルの書き込みに成功しました」と表示されます。そうでない場合は、「ファイルの書き込みに失敗しました」と表示されます。

    
    .. code-block:: arduino

        if(file.print("Test file write")) { // Write the message to the file
            Serial.println("File write success"); // If write succeeds, print to serial
        } else {
            Serial.println("File write failed"); // If write fails, print to serial
        } 

    * **ファイルを閉じる**
        
    開いたファイルを閉じます。これにより、バッファリングされたデータがファイルに書き込まれ、ファイルが適切に閉じられます。

    .. code-block:: arduino

        file.close(); // Close the file

    * **ルートディレクトリを開く**

    SDカードのルートディレクトリを開きます。ディレクトリが開けなかった場合、「ディレクトリを開けませんでした」と表示し、処理を戻します。

    .. code-block:: arduino

        File root = SD_MMC.open("/"); // Open the root directory of SD card
        if (!root) {
            Serial.println("Failed to open directory"); // Print error message if directory failed to open
            return;
        }

    * **各ファイルの名前とサイズを出力する**
    
    while (``File file = root.openNextFile()``) で始まるループは、ルートディレクトリ内の全ファイルを繰り返し処理し、
    各ファイルの名前とサイズをシリアルモニターに出力します。

    .. code-block:: arduino
    
        Serial.println("Files found in root directory:"); // Print the list of files found in the root directory
        while (File file = root.openNextFile()) { // Loop through all the files in the root directory
              Serial.print("  ");
              Serial.print(file.name()); // Print the filename
              Serial.print("\t");
              Serial.println(file.size()); // Print the filesize
              file.close(); // Close the file
        }

#. この ``loop()`` 関数は空のループであり、現在のプログラムでは何も行いません。通常のArduinoプログラムでは、この関数は繰り返しコードを実行します。しかし、必要なタスクはすべてsetup関数で実行されているため、loop関数は不要です。

    .. code-block:: arduino

        void loop() {} // Empty loop function, does nothing
