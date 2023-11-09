7.6 SDカードで写真を撮る
============================

この文書は、ESP32-CAMを使用して写真を撮り、SDカードに保存するプロジェクトについて説明しています。
このプロジェクトの目的は、ESP32-CAMを使用して画像をキャプチャし、SDカードに保存する簡単なソリューションを提供することです。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが確かに便利です。リンクはこちらです：

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


**関連する注意事項**

ESP32-CAMを使用する際には、スケッチをアップロードするためにGPIO 0ピンをGNDに接続する必要があることに注意してください。
また、GPIO 0をGNDに接続した後、ESP32-CAMのオンボードRESETボタンを押して、ボードをフラッシュモードにする必要があります。
画像をSDカードに保存する前に、SDカードが適切にマウントされていることも重要です。

**操作手順**

#. カードリーダーを使ってSDカードをコンピュータに挿入し、その後フォーマットします。 :ref:`format_sd_card` のチュートリアルを参照してください。

#. カードリーダーを取り外し、SDカードを拡張ボードに挿入します。

    .. image:: ../../img/insert_sd.png

#. 今度は、カメラを接続します。

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. USBケーブルを使ってESP32-WROOM-32Eをコンピュータに接続します。

    .. image:: ../../img/plugin_esp32.png

#. コードを開きます。

    .. note::

        * ``esp32-starter-kit-main\c\codes\7.6_take_photo_sd`` のパスの下にある ``7.6_take_photo_sd.ino`` ファイルを開きます。
        * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
        * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4d698dc3-aef7-4aea-b8a3-7d143a4c7d3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. 今度は、 **PSRAM** を有効にします。

    .. image:: img/sp230516_150554.png

#. パーティションスキームを **Huge APP (3MB No OTA/1MB SPIFFS)** に設定します。

    .. image:: img/sp230516_150840.png   

#. Arduino IDEで適切なポートとボードを選択し、ESP32にコードをアップロードします。

#. コードのアップロードに成功したら、 **Reset** ボタンを押して写真を撮ります。また、シリアルモニターで以下の情報が表示されていることを確認して、成功したキャプチャを見ることができます。


    .. code-block:: arduino

        Picture file name: /picture9.jpg
        Saved file to path: /picture9.jpg
        Going to sleep now

    .. image:: img/press_reset.PNG

#. 今度は、拡張ボードからSDカードを取り外し、コンピュータに挿入します。撮ったばかりの写真を見ることができます。

    .. image:: img/take_photo1.png

**どのように動作するのか？**

このコードは、AI Thinker ESP32-CAMを操作して写真を撮り、SDカードに保存し、その後ESP32-CAMをディープスリープ状態にします。主な部分の概要は以下の通りです：

* **Libraries**：コードは、ESP32-CAM、ファイルシステム（FS）、SDカード、EEPROM（電源サイクルをまたいでデータを保存するために使用）に必要なライブラリを含めて開始します。

    .. code-block:: arduino

        #include "esp_camera.h"
        #include "Arduino.h"
        #include "FS.h"                // SD Card ESP32
        #include "SD_MMC.h"            // SD Card ESP32
        #include "soc/soc.h"           // Disable brownour problems
        #include "soc/rtc_cntl_reg.h"  // Disable brownour problems
        #include "driver/rtc_io.h"
        #include <EEPROM.h>  // read and write from flash memory

* **Pin Definitions**：このセクションでは、ESP32-CAMのカメラモジュールへのピン接続を表す定数を設定します。

    .. code-block:: arduino

        #define PWDN_GPIO_NUM 32
        #define RESET_GPIO_NUM -1
        #define XCLK_GPIO_NUM 0
        #define SIOD_GPIO_NUM 26
        #define SIOC_GPIO_NUM 27

        #define Y9_GPIO_NUM 35
        #define Y8_GPIO_NUM 34
        #define Y7_GPIO_NUM 39
        #define Y6_GPIO_NUM 36
        #define Y5_GPIO_NUM 21
        #define Y4_GPIO_NUM 19
        #define Y3_GPIO_NUM 18
        #define Y2_GPIO_NUM 5
        #define VSYNC_GPIO_NUM 25
        #define HREF_GPIO_NUM 23
        #define PCLK_GPIO_NUM 22


* **Global Variables**: グローバル変数 ``pictureNumber`` は、撮影してSDカードに保存した写真の枚数を追跡するために宣言されています。

    .. code-block:: arduino

        int pictureNumber = 0;


* **Setup Function**: ``setup()`` 関数では、いくつかのタスクが達成されます：


    * まず、カメラが操作中にESP32-CAMがリセットされるのを防ぐために、ブラウンアウト検出器を無効にします。
    
        .. code-block:: arduino

            WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  //disable brownout detector

    * デバッグ用にシリアル通信を初期化します。

        .. code-block:: arduino

            Serial.begin(115200);

    * GPIOピン、XCLK周波数、ピクセルフォーマット、フレームサイズ、JPEG品質、フレームバッファカウントなどを含むカメラ設定が ``camera_config_t`` で設定されます。
    
        .. code-block:: arduino

            camera_config_t config;
            config.ledc_channel = LEDC_CHANNEL_0;
            config.ledc_timer = LEDC_TIMER_0;
            config.pin_d0 = Y2_GPIO_NUM;
            config.pin_d1 = Y3_GPIO_NUM;
            config.pin_d2 = Y4_GPIO_NUM;
            config.pin_d3 = Y5_GPIO_NUM;
            config.pin_d4 = Y6_GPIO_NUM;
            config.pin_d5 = Y7_GPIO_NUM;
            config.pin_d6 = Y8_GPIO_NUM;
            config.pin_d7 = Y9_GPIO_NUM;
            config.pin_xclk = XCLK_GPIO_NUM;
            config.pin_pclk = PCLK_GPIO_NUM;
            config.pin_vsync = VSYNC_GPIO_NUM;
            config.pin_href = HREF_GPIO_NUM;
            config.pin_sscb_sda = SIOD_GPIO_NUM;
            config.pin_sscb_scl = SIOC_GPIO_NUM;
            config.pin_pwdn = PWDN_GPIO_NUM;
            config.pin_reset = RESET_GPIO_NUM;
            config.xclk_freq_hz = 20000000;
            config.pixel_format = PIXFORMAT_JPEG;
    
    * 次に、設定でカメラを初期化し、失敗した場合はエラーメッセージを出力します。

        .. code-block:: arduino

            esp_err_t err = esp_camera_init(&config);
            if (err != ESP_OK) {
                Serial.printf("Camera init failed with error 0x%x", err);
                return;
            }

    * SDカードを初期化し、失敗した場合はエラーメッセージを出力します。

           .. code-block:: arduino
            
            if (!SD_MMC.begin()) {
                Serial.println("SD Card Mount Failed");
                return;
            }   

            uint8_t cardType = SD_MMC.cardType();
            if (cardType == CARD_NONE) {
                Serial.println("No SD Card attached");
                return;
            }         

    * カメラで写真を撮り、フレームバッファに保存します。

        .. code-block:: arduino

            fb = esp_camera_fb_get();
            if (!fb) {
                Serial.println("Camera capture failed");
                return;
            }

    * EEPROMを読み出して最後の写真の番号を取得し、新しい写真の番号を増やします。

        .. code-block:: arduino

            EEPROM.begin(EEPROM_SIZE);
            pictureNumber = EEPROM.read(0) + 1;

    * 新しい写真のためにSDカード上にパスを作成し、写真番号に対応するファイル名で保存します。

        .. code-block:: arduino

            String path = "/picture" + String(pictureNumber) + ".jpg";

            fs::FS &fs = SD_MMC;
            Serial.printf("Picture file name: %s\n", path.c_str());

    * 写真を保存した後、次の電源サイクルで取得するために写真番号をEEPROMに戻して保存します。

        .. code-block:: arduino

            File file = fs.open(path.c_str(), FILE_WRITE);
            if (!file) {
                Serial.println("Failed to open file in writing mode");
            } else {
                file.write(fb->buf, fb->len);  // payload (image), payload length
                Serial.printf("Saved file to path: %s\n", path.c_str());
                EEPROM.write(0, pictureNumber);
                EEPROM.commit();
            }
            file.close();
            esp_camera_fb_return(fb); 

    * 最後に、オンボードLED（フラッシュ）を消して、ESP32-CAMをディープスリープ状態にします。

        .. code-block:: arduino

            pinMode(4, OUTPUT);
            digitalWrite(4, LOW);
            rtc_gpio_hold_en(GPIO_NUM_4);

    * スリープモード: ESP32-CAMは、各写真を撮った後に電力を節約するためにディープスリープに入ります。リセットボタンを押すか、特定のピンにシグナルを送ることで起動できます。

        .. code-block:: arduino

            delay(2000);
            Serial.println("Going to sleep now");
            delay(2000);
            esp_deep_sleep_start();
            Serial.println("This will never be printed");


* ループ関数: ``loop()`` 関数は空です。セットアッププロセスの後で、ESP32-CAMはすぐにディープスリープに入ります。


このコードが機能するためには、スケッチをアップロードする時にGPIO 0がGNDに接続されていることを確認し、ボードをフラッシュモードにするためにオンボードRESETボタンを押す必要があるかもしれません。また、"/picture"をあなたのファイル名に置き換えてください。EEPROMのサイズは1に設定されており、0から255までの値を保存できます。255枚以上の写真を撮る予定がある場合は、EEPROMのサイズを増やし、写真番号をどのように保存し、読み出すかを調整する必要があります。

