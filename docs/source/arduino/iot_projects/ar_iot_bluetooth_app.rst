.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_bluetooth_app:

8.10 アンドロイドアプリケーション - ArduinoとBluetoothを介したRGB LED操作
==========================================================================

このプロジェクトの目的は、Bluetooth技術を使ってスマートフォンでRGB LEDの色調を操作できるアンドロイドアプリケーションを開発することです。

このアンドロイドアプリケーションは、MIT App Inventor 2と呼ばれる無料のウェブベースプラットフォームを使用して構築されます。このプロジェクトは、Arduinoとスマートフォンのインターフェースに慣れる絶好の機会を提供します。

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../../_static/video/10_ble_app.mp4" type="video/mp4">
      ご使用のブラウザではビデオタグがサポートされていません。
   </video>

**必要な部品**

このプロジェクトには以下のコンポーネントが必要です。

キット全体を購入するのが便利です。以下がリンクです：

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**1. アンドロイドアプリケーションの作成**

アンドロイドアプリケーションは |link_appinventor| という無料のウェブアプリケーションを使用して作成されます。
MIT App Inventorは、直感的なドラッグ＆ドロップ機能を使用して簡単なアプリケーションを作成することができるため、アンドロイド開発において優れた出発点です。

さあ、始めましょう。

#. こちらがログインページです： http://ai2.appinventor.mit.edu。 MIT App Inventorに登録するにはGoogleアカウントが必要です。

#. ログインした後、 **Projects** -> **Import project (.aia) from my computer** に進み、 ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor`` パスにある ``control_rgb_led.aia`` ファイルをアップロードしてください。

   .. image:: img/10_ble_app_inventor1.png

#. ``.aia`` ファイルをアップロードすると、 **MIT App Inventor** ソフトウェア上でアプリケーションが表示されます。これは事前に設定されたテンプレートです。 **MIT App Inventor** に慣れた後、このテンプレートを変更することができます。

   .. image:: img/10_ble_app_inventor2.png

#. **MIT App Inventor** では、主に **Designer** と **Blocks** の2つのセクションがあります。

   .. image:: img/10_ble_app_inventor3.png

#. **Designer** を使用すると、ボタン、テキスト、画面を追加し、アプリケーションの全体的な美観を変更することができます。

   .. image:: img/10_ble_app_inventor2.png
   

#. 次に、 **Blocks** セクションがあります。 **Blocks** セクションは、アプリケーションのための特別な機能を作成するのに役立ちます。

   .. image:: img/10_ble_app_inventor5.png

#. スマートフォンにアプリケーションをインストールするには、 **Build** タブに移動します。

   .. image:: img/10_ble_app_inventor6.png

   * ``.apk`` ファイルを生成することができます。このオプションを選択すると、 ``.apk`` ファイルをダウンロードするか、QRコードをスキャンしてインストールするかを選択できるページが表示されます。インストールガイドに従ってアプリケーションのインストールを完了してください。
   * このアプリを **Google Play** や他のアプリマーケットにアップロードしたい場合は、 ``.aab`` ファイルを生成することができます。



**2. コードのアップロード**

#. 回路を組み立てます。

   .. image:: ../../components/img/rgb_pin.jpg
      :width: 200
      :align: center

   RGB LEDには4つのピンがあります：長いピンは共通カソードピンで、通常はGNDに接続されています。最長のピンの左にあるピンは赤を表し、右側の2つのピンは緑と青を象徴しています。

   .. image:: ../../img/wiring/2.3_color_light_bb.png

#. 次に、USBケーブルを使用してESP32-WROOM-32Eをコンピュータに接続します。

   .. image:: ../../img/plugin_esp32.png

#. ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor`` ディレクトリ内にある ``iot_10_bluetooth_app_inventor.ino`` ファイルを開くか、コードをArduino IDEにコピーします。

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/07622bb5-31eb-4a89-b6f2-085f3332051f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 適切なボード（ **ESP32 Dev Module** ）とポートを選択した後、 **Upload** ボタンをクリックします。

**3. アプリとESP32の接続**

以前に作成したアプリケーションがスマートフォンにインストールされていることを確認します。

#. 最初に、スマートフォンで **Bluetooth** を有効にします。

   .. image:: img/10_ble_mobile1.png
      :width: 500
      :align: center

#. スマートフォンの **Bluetooth settings** に移動し、 **ESP32RGB** を探します。

   .. image:: img/10_ble_mobile2.png
      :width: 500
      :align: center


#. クリックした後、ポップアップウィンドウで **Pair** 要求に同意します。

   .. image:: img/10_ble_mobile3.png
      :width: 500
      :align: center

#. 今、最近インストールした **Control_RGB_LED** APPを開きます。

   .. image:: img/10_ble_mobile4.png
      :align: center

#. APP内で **Connect Bluetooth** をクリックし、APPとESP32の間の接続を確立します。

   .. image:: img/10_ble_mobile5.png
      :width: 500
      :align: center

#. 表示される ``xx.xx.xx.xx.xx.xx ESP32RGB`` を選択します。もしコード内で ``SerialBT.begin("ESP32RGB");`` を変更した場合は、設定した名前を選択します。

   .. image:: img/10_ble_mobile6.png
      :width: 500
      :align: center

#. しばらく待ってもデバイス名が表示されない場合は、このAPPが周囲のデバイスをスキャンすることを許可されていない可能性があります。その場合は、手動で設定を調整する必要があります。

   * APPアイコンを長押しして、表示された **APP Info** をクリックします。他の方法でこのページにアクセスできる場合は、その方法に従ってください。

      .. image:: img/10_ble_mobile8.png
         :width: 500
         :align: center

   * **Permissions** ページに移動します。

      .. image:: img/10_ble_mobile9.png
         :width: 500
         :align: center

   * **Nearby devices** を探し、 **Always** を選択して、このAPPが近くのデバイスをスキャンできるようにします。

      .. image:: img/10_ble_mobile10.png
         :width: 500
         :align: center

   * 今、APPを再起動し、手順5と6を繰り返してBluetoothに成功裏に接続します。

#. 接続に成功すると、自動的にメインページに戻り、接続されたと表示されます。これで、 **Change Color** ボタンを押してRGB値を調整し、RGBディスプレイの色を変更することができます。

   .. image:: img/10_ble_mobile7.png
      :width: 500
      :align: center
