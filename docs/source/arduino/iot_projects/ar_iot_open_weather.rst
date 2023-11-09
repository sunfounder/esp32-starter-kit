8.1 @OpenWeatherMapからのリアルタイム天気情報
====================================================

IoTオープンウェザーディスプレイプロジェクトは、ESP32ボードとI2C LCD1602モジュールを使用して、OpenWeatherMap APIからデータを取得する天気情報ディスプレイを作成します。

このプロジェクトは、APIの使用、Wi-Fi接続、ESP32ボードを使用したLCDモジュール上でのデータ表示に関する素晴らしい入門となります。IoTオープンウェザーディスプレイを使用すれば、一目でリアルタイムの天気更新情報にアクセスできるため、家庭やオフィス環境に理想的なソリューションです。

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**OpenWeather APIキーを取得**

|link_openweather| は、OpenWeather Ltdが所有するオンラインサービスで、APIを介して現在の天気データ、予報、今予報、任意の地理的位置の過去の天気データなど、グローバルな天気データを提供しています。

#. |link_openweather| にアクセスして、ログイン/アカウントを作成します。

    .. image:: img/OWM-1.png

#. ナビゲーションバーからAPIページに移動します。

    .. image:: img/OWM-2.png

#. **Current Weather Data** を見つけてサブスクライブをクリックします。

    .. image:: img/OWM-3.png

#. **Current weather and forecasts collection** の下で、適切なサービスにサブスクライブします。このプロジェクトでは無料プランで十分です。

    .. image:: img/OWM-4.png

#. **API keys** ページからキーをコピーします。

    .. image:: img/OWM-5.png


**デバイスを完成させる**

#. 回路を組み立てます。

    .. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
        :width: 800

#. コードを開きます。

    * ``esp32-starter-kit-main\c\codes\iot_1_open_weather`` ディレクトリ内にある ``iot_1_open_weather.ino`` ファイルを開くか、Arduino IDEにコードをコピーします。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``LiquidCrystal I2C`` と ``Arduino_JSON`` ライブラリが使用されており、 **Library Manager** からインストールできます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/71b196ce-8a84-4577-af76-43988c7d3f80/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
         

#. 次の行を見つけて、あなたの ``<SSID>`` と ``<PASSWORD>`` で修正してください。


    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. 以前にコピーしたAPIキーを ``openWeatherMapApiKey`` に入力してください。

    .. code-block::  Arduino

        // Your Domain name with URL path or IP address with path
        String openWeatherMapApiKey = "<openWeatherMapApiKey>";

#. あなたの国コードと市を置き換えてください。

    .. code-block::  Arduino

        // Replace with your country code and city
        // Fine the country code by https://openweathermap.org/find
        String city = "<CITY>";
        String countryCode = "<COUNTRY CODE>";

#. コードが実行された後、I2C LCD1602にあなたの位置の時間と天気情報が表示されます。

.. note::
   コードが実行されているとき、画面が空白の場合は、モジュールの背面にあるポテンショメーターを回してコントラストを上げることができます。

