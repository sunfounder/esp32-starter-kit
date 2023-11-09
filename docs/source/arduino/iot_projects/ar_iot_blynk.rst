.. _iot_intrusion_alert_system:

8.9 Blynkを利用した侵入通知システム
=============================================

このプロジェクトでは、PIRモーションセンサー（HC-SR501）を使用したシンプルな自宅侵入検出システムを紹介します。
Blynkアプリを通じてシステムを「外出」モードに設定すると、PIRセンサーが動きを監視します。
検出された動きはBlynkアプリに通知を送り、ユーザーに潜在的な侵入を警告します。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

全てのキットを購入することは非常に便利です。リンクはこちらです：

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|


1. 回路組立
--------------------

.. image:: ../../img/wiring/iot_9_blynk_bb.png
    :width: 60%
    :align: center

2. Blynk設定
----------------------

**2.1 Blynkの初期化**

#. |link_blynk| にアクセスし、 **START FREE** を選択します。

   .. image:: img/09_blynk_access.png
        :width: 90%

#. メールアドレスを入力して登録プロセスを開始します。

   .. image:: img/09_blynk_sign_in.png
        :width: 70%
        :align: center

#. メールで登録を確認します。

    .. image:: img/09_blynk_password.png
        :width: 90%

#. 確認後、 **Blynk Tour** が表示されます。「スキップ」を選択することをおすすめします。 **Quick Start** も表示された場合は、これもスキップすることを検討してください。
   
    .. image:: img/09_blynk_tour.png
        :width: 90%

**2.2 テンプレートの作成**

#. Blynkでテンプレートを作成します。次の指示に従って **Intrusion Alert System** テンプレートを作成します。

    .. image:: img/09_create_template_1_shadow.png
        :width: 700
        :align: center

#. テンプレートに名前を割り当て、ハードウェアを **ESP32** として選択し、 **Connection Type** を **WiFi** として選択し、 **Done** を選択します。

    .. image:: img/09_create_template_2_shadow.png
        :width: 700
        :align: center

**2.3 データストリームの生成**

設定したテンプレートを開き、2つのデータストリームを作成しましょう。

#. **New Datastream** をクリックします。

    .. image:: img/09_blynk_new_datastream.png
        :width: 700
        :align: center

#. ポップアップで **Virtual Pin** を選択します。

    .. image:: img/09_blynk_datastream_virtual.png
        :width: 700
        :align: center

#. **Virtual Pin V0** に **AwayMode** と名付けます。 **DATA TYPE** を **Integer** とし、 **MIN** と **MAX** の値を **0** と **1** に設定します。

    .. image:: img/09_create_template_shadow.png
        :width: 700
        :align: center

#. 同様に、別の **Virtual Pin** データストリームを作成します。 **Current Status** と名付け、 **DATA TYPE** を **String** に設定します。

    .. image:: img/09_datastream_1_shadow.png
        :width: 700
        :align: center

**2.4 イベントの設定**

次に、侵入が検出された場合にメール通知を送信するイベントを設定します。

#. **Add New Event** をクリックします。

    .. image:: img/09_blynk_event_add.png

#. イベントの名前と特定のコードを定義します。 **TYPE** には **Warning** を選択し、イベント発生時に送信されるメールの短い説明を書きます。通知の頻度も調整できます。

    .. note::
        
        **EVENT CODE** は ``intrusion_detected`` として設定されていることを確認してください。これはコードで事前に定義されているため、変更がある場合はコードも調整する必要があります。

    .. image:: img/09_event_1_shadow.png
        :width: 700
        :align: center

#. **Notifications** セクションに移動して通知をオンにし、メールの詳細を設定します。

    .. image:: img/09_event_2_shadow.png
        :width: 80%
        :align: center

.. raw:: html
    
    <br/> 

**2.5 Webダッシュボードの微調整**

侵入アラートシステムと **Web Dashboard** が完璧に連動するようにすることが重要です。

#. **Switch widget** と **Label widget** を **Web Dashboard** にドラッグ＆ドロップします。

    .. image:: img/09_web_dashboard_1_shadow.png
        :width: 100%
        :align: center

#. ウィジェット上にカーソルを合わせると、3つのアイコンが表示されます。設定アイコンを使用してウィジェットのプロパティを調整します。

    .. image:: img/09_blynk_dashboard_set.png
        :width: 100%
        :align: center

#. **Switch widget** の設定で、 **Datastream** を **AwayMode(V0)** に設定します。 **ONLABEL** と **OFFLABEL** にそれぞれ **「away」** と **「home」** を表示するように設定します。

    .. image:: img/09_web_dashboard_2_shadow.png
        :width: 100%
        :align: center

#. **Label widget** の設定で、 **Datastream** を **Current Status(V1)** に設定します。

    .. image:: img/09_web_dashboard_3_shadow.png
        :width: 100%
        :align: center

**2.6 テンプレートの保存**

最後に、テンプレートを保存するのを忘れないでください。

    .. image:: img/09_save_template_shadow.png
        :width: 100%
        :align: center

**2.7 デバイスの作成**

#. 新しいデバイスを作成する時が来ました。

    .. image:: img/09_blynk_device_new.png
        :width: 700
        :align: center

#. **From template** をクリックして新しいセットアップを開始します。

    .. image:: img/09_blynk_device_template.png
        :width: 700
        :align: center


#. 次に、 **Intrusion Alert System** テンプレートを選択し、 **Create** をクリックします。

    .. image:: img/09_blynk_device_template2.png
        :width: 700
        :align: center

#. ここでは、 ``Template ID``、 ``Device Name``、 ``AuthToken`` が表示されます。これらをコードにコピーして、ESP32がBlynkと連携できるようにします。

    .. image:: img/09_blynk_device_code.png
        :width: 700
        :align: center

3. コードの実行
-----------------------------
#. コードを実行する前に、Arduino IDEの **Library Manager** から ``Blynk`` ライブラリをインストールしてください。

    .. image:: img/09_blynk_add_library.png
        :width: 700
        :align: center

#.  ``iot_9_intrusion_alert_system.ino`` ファイルを開きます。このファイルは、 ``esp32-starter-kit-main\c\codes\iot_9_intrusion_alert_system`` ディレクトリ内にあります。内容をArduino IDEにコピーすることもできます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/16bca228-64d7-4519-ac3b-833afecfcc65/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#.  ``BLYNK_TEMPLATE_ID``、 ``BLYNK_TEMPLATE_NAME``、 ``BLYNK_AUTH_TOKEN`` のプレースホルダーを独自のIDに置き換えてください。

    .. code-block:: arduino
    
        #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

#. また、WiFiネットワークの ``ssid`` と ``password`` を入力する必要があります。

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. 正しいボード(**ESP32 Dev Module**)とポートを選択し、 **Upload** ボタンをクリックしてください。

#. シリアルモニターを開き（ボーレートを115200に設定）、成功した接続メッセージが表示されるのを待ちます。

    .. image:: img/09_blynk_upload_code.png
        :align: center

#. 接続に成功したら、Blynkでスイッチをアクティブにすると、PIRモジュールの監視が開始されます。動きが検出されると（状態が1になる）、"誰かがここにいる！"と表示され、あなたのメールにアラートが送信されます。

    .. image:: img/09_blynk_code_alarm.png
        :width: 700
        :align: center

4. コードの説明
-----------------------------

#. **設定とライブラリ**

   ここでは、Blynkの定数と資格情報を設定します。また、ESP32とBlynkに必要なライブラリを含めます。

    .. code-block:: arduino

        /* Comment this out to disable prints and save space */
        #define BLYNK_PRINT Serial

        #define BLYNK_TEMPLATE_ID "xxxxxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"

        #include <WiFi.h>
        #include <WiFiClient.h>
        #include <BlynkSimpleEsp32.h>

#. **WiFi設定**

   あなたのWiFiの資格情報を入力してください。

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. **PIRセンサー設定**

   PIRセンサーが接続されているピンを設定し、状態変数を初期化します。

   .. code-block:: arduino

      const int sensorPin = 14;
      int state = 0;
      int awayHomeMode = 0;
      BlynkTimer timer;

#. **setup()関数**

   この関数はPIRセンサーを入力として初期化し、シリアル通信を設定し、WiFiに接続し、Blynkを設定します。

   - ``setup()`` で ``timer.setInterval(1000L, myTimerEvent)`` を使用してタイマーの間隔を設定します。ここでは ``myTimerEvent()`` 関数を毎 **1000ms** 実行するように設定しています。 ``timer.setInterval(1000L, myTimerEvent)`` の最初のパラメータを変更することで ``myTimerEvent`` 実行の間隔を変更できます。

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void setup() {

            pinMode(sensorPin, INPUT);  // Set PIR sensor pin as input
            Serial.begin(115200);           // Start serial communication at 115200 baud rate for debugging
            
            // Configure Blynk and connect to WiFi
            Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
            
            timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second
        }

#. **loop()関数**

   loop関数はBlynkとBlynkタイマー関数を継続的に実行します。

   .. code-block:: arduino

        void loop() {
           Blynk.run();
           timer.run();
        }

#. **Blynkアプリとのやり取り**

   これらの関数は、デバイスがBlynkに接続したとき、またはBlynkアプリの仮想ピンV0の状態に変更があったときに呼び出されます。

   - デバイスがBlynkサーバーに接続するたび、またはネットワーク状況が悪いために再接続するたびに、 ``BLYNK_CONNECTED()`` 関数が呼び出されます。 ``Blynk.syncVirtual()`` コマンドは単一の仮想ピン値のリクエストを行います。指定された仮想ピンは ``BLYNK_WRITE()`` コールを実行します。

   - BLYNKサーバー上の仮想ピンの値が変更されると、 ``BLYNK_WRITE()`` がトリガされます。

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino
      
        // This function is called every time the device is connected to the Blynk.Cloud
        BLYNK_CONNECTED() {
            Blynk.syncVirtual(V0);
        }
      
        // This function is called every time the Virtual Pin 0 state changes
        BLYNK_WRITE(V0) {
            awayHomeMode = param.asInt();
            // additional logic
        }

#. **データ処理**

   ``myTimerEvent()`` 関数は毎秒 ``sendData()`` を呼び出します。Blynkで外出モードが有効になっている場合、PIRセンサーをチェックし、動きが検出された場合にBlynkに通知を送ります。

   - ラベルのテキストを変更するには、 ``Blynk.virtualWrite(V1, "Somebody in your house! Please check!");`` を使用します。

   - イベントをBlynkに記録するには、 ``Blynk.logEvent("intrusion_detected");`` を使用します。

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void myTimerEvent() {
           sendData();
        }

        void sendData() {
           if (awayHomeMode == 1) {
              state = digitalRead(sensorPin);  // Read the state of the PIR sensor

              Serial.print("state:");
              Serial.println(state);

              // If the sensor detects movement, send an alert to the Blynk app
              if (state == HIGH) {
                Serial.println("Somebody here!");
                Blynk.virtualWrite(V1, "Somebody in your house! Please check!");
                Blynk.logEvent("intrusion_detected");
              }
           }
        }

**参考文献**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|
- |link_blynk_syncing| 
- |link_blynk_write|