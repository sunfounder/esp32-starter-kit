8.8 Home Assistantを使ったカメラ
======================================

このプロジェクトでは、ESP32カメラのビデオストリームウェブサーバーを設定し、人気のあるホームオートメーションプラットフォームであるHome Assistantと統合する方法を案内します。この統合により、ネットワーク上の任意のデバイスからサーバーにアクセスできます。

.. note::
    
    このプロジェクトに取り組む前に、Home Assistantがインストールされたオペレーティングシステムを用意する必要があります。
        
    Raspberry PiにHome Assistant OSをインストールすることをおすすめします。
        
    Raspberry Piを持っていない場合は、Windows、macOS、Linuxで動作する仮想マシンにインストールすることもできます。
        
    インストール手順については、公式ウェブサイトのリンクを参照してください： https://www.home-assistant.io/installation/
        
    インストールが成功した後にこのプロジェクトを進めてください。

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


**1. ESPHomeでの設定**

#. まずカメラを接続します。

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            お使いのブラウザーはビデオタグをサポートしていません。
        </video>

#. Home AssistantシステムをインストールしたホストにESP32を接続します（例えば、Raspberry Piにインストールした場合は、Piに接続します）。

    .. image:: ../../img/plugin_esp32.png

#. ESPHomeアドオンをインストールします。

    .. image:: img/sp230629_145928.png

#. **START** をクリックし、次に **OPEN WEB UI** をクリックします。

    .. image:: img/sp230629_172645.png
        :width: 700
        :align: center

#. 新しいデバイスを追加します。

    .. image:: img/sp230629_172733.png

#. プロンプトが表示される場合があります。 **CONTINUE** をクリックします。

    .. image:: img/sp230629_172816.png
        :align: center


#. 設定を作成します。ここでは、 **Name** に任意の名前を入力できます。WiFiについては、Home Assistantシステムが存在するネットワークの詳細を入力します。

    .. image:: img/sp230629_172926.png

#. デバイスタイプとして **ESP32** を選択します。

    .. image:: img/sp230629_173043.png

#. 花火のアイコンが表示されたら、デバイスの作成に成功したことを意味します。スキップをクリックします(**INSTALL** をクリックしないでください)。

    .. image:: img/sp230629_173151.png

    この時点で、デバイスをESPHomeに追加しただけです。ESP32モジュールをHome Assistantに統合するには、追加の設定が必要です：

#. **EDIT** をクリックします。

    .. image:: img/sp230629_173322.png

#. ``.yaml`` インターフェースに入ったら、あなたのWiFiの詳細で ``ssid`` と ``password`` を変更します。

    .. image:: img/sp230629_174301.png

#. ``captive_portal`` セクションの下に、次のコードを貼り付けます：

    .. code-block::

        # Example configuration entry
        esp32_camera:
            external_clock:
                pin: GPIO0
                frequency: 20MHz
            i2c_pins:
                sda: GPIO26
                scl: GPIO27
            data_pins: [GPIO5, GPIO18, GPIO19, GPIO21, GPIO36, GPIO39, GPIO34, GPIO35]
            vsync_pin: GPIO25
            href_pin: GPIO23
            pixel_clock_pin: GPIO22
            power_down_pin: GPIO32

            # Image settings
            name: My Camera
            # ...

    .. note:: 
        
        ESP32の ``.yaml`` 設定の詳細については、 `ESP32 Camera - ESPHome <https://esphome.io/components/esp32_camera.html>`_ を参照してください。

#. **Save** してから、 **INSTALL** をクリックします。

    .. image:: img/sp230629_174447.png

#. インストール方法としてUSBポートを選択します。

    .. image:: img/sp230629_174852.png

    .. note:: 
        
        初回のコンパイルでは依存パッケージをダウンロードするため、約10分かかる場合があります。ご忍耐ください。プロセスが長時間停止する場合は、システムに十分なディスクスペースがあるか確認してください。

#. ``INFO Successfully compiled program.`` のメッセージが表示されるまで待ちます。これはファームウェアのコンパイルが完了したことを示しています。

    .. image:: img/sp230630_115109.png

    .. sp230630_114902.png

    .. note::

        この時点で、ノードが **ONLINE** として表示されるはずです。そうでない場合は、ESP32が同じネットワークセグメントにあることを確認するか、デバイスの再起動を試してください。

        .. image:: img/sp230630_153024.png

**2. Home Assistantでの設定**

Esphomeと統合した後、Home Assistantでカメラを設定する必要があります。

#. **Settings** > **Devices & Services** に移動します。

    .. image:: img/sp230630_155917.png

#. ここでesphomeタブが表示されるはずです。 **CONFIGURE** をクリックします。

    .. image:: img/sp230630_155736.png

#. **SUBMIT** をクリックします。

    .. image:: img/sp230630_162218.png

#. **Success** メッセージが表示されるまで待ちます。

    .. image:: img/sp230630_162311.png

#. **Overview** で、右上のメニューをクリックし、 **Edit Dashboard** を選択します。

    .. image:: img/sp230630_164745.png

#. **ADD CARD** をクリックします。

    .. image:: img/sp230630_164850.png

#. **Picture entity** を選択します。

    .. image:: img/sp230630_164935.png

#. エンティティフィールドで、ただ今追加したESP32を選択します。そして **save**。

    .. image:: img/sp230630_165019.png

#. 最後に、 **EDIT** インターフェースを終了するために **DONE** をクリックします。

    .. image:: img/sp230630_165235.png

これで、Home Assistantでカメラフィードを視聴できます。

