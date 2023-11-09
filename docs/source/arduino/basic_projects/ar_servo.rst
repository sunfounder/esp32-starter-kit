.. _ar_servo:

4.3 サーボモータのスイング
===========================
サーボモータは特定の角度を維持し、正確な回転を実現する位置制御デバイスとして知られています。これは、一貫した角度調整を要求する制御システムにとって非常に望ましい特性です。そのため、サーボは高品質な遠隔操作玩具、飛行機モデルから潜水艦のレプリカ、高度な遠隔操作ロボットに至るまで、幅広く使用されています。

この魅力的なプロジェクトでは、サーボモータを独自の方法で操作する挑戦をします - スイングさせるのです！このプロジェクトはサーボモータの動きをより深く理解し、精密な制御システムのスキルを磨く絶好の機会を提供します。

サーボモータをあなたのリズムに合わせて踊らせる準備はできましたか？さあ、このエキサイティングな冒険に出発しましょう！

**必要な部品**

このプロジェクトには、以下の部品が必要です。

全てをセットで購入するのが便利ですが、こちらがリンクです：

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


**利用可能なピン**

このプロジェクトでESP32ボードで利用できるピンのリストです。

.. list-table::
    :widths: 5 20 

    * - 利用可能なピン
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**回路図**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**配線図**

* オレンジ色のワイヤーはシグナルで、IO25に接続します。
* 赤いワイヤーはVCCで、5Vに接続します。
* 茶色のワイヤーはGNDで、GNDに接続します。

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png

**コード**

.. note::

    * ``esp32-starter-kit-main\c\codes\4.3_servo`` のパスから ``4.3_servo.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーしてください。
    * ボード（ESP32 Dev Module）と適切なポートを選んだ後、 **アップロード** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``ESP32Servo`` ライブラリを使用します。 **Library Manager** からインストールできます。

        .. image:: img/servo_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/34c7969e-fee3-413c-9fe7-9d38ca6fb906/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードのアップロードが完了すると、サーボモータのアームが0°〜180°の範囲で回転するのが見られます。

**どのように動作するのか？**

#. |link_esp32servo| ライブラリを含める: ESP32Servoライブラリをインポートし、サーボモータの制御に必要な設定を行います。

    .. code-block:: arduino

        #include <ESP32Servo.h>

#. サーボとそれが接続されているピンを定義する: このセクションでは、サーボオブジェクト(``myServo``)とサーボモータが接続されているピンを表す定数整数(``servoPin``)を宣言します（ピン25に接続）。

    .. code-block:: arduino

        // Define the servo and the pin it is connected to
        Servo myServo;
        const int servoPin = 25;

#. サーボの最小および最大パルス幅を定義する: このセクションでは、サーボモータの最小および最大パルス幅（それぞれ0.5ミリ秒と2.5ミリ秒）を設定します。

    .. code-block:: arduino

        // Define the minimum and maximum pulse widths for the servo
        const int minPulseWidth = 500; // 0.5 ms
        const int maxPulseWidth = 2500; // 2.5 ms

#. ``setup`` 関数は、指定されたピンにサーボモータを接続し、そのパルス幅範囲を設定することでサーボモータの初期化を行います。また、サーボのPWM周波数を標準の50Hzに設定します。

    .. code-block:: arduino

        void setup() {
            // Attach the servo to the specified pin and set its pulse width range
            myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

            // Set the PWM frequency for the servo
            myServo.setPeriodHertz(50); // Standard 50Hz servo
        }

    * ``attach (int pin, int min, int max)``: この関数は、サーボモータを指定されたGPIOピンに接続し、サーボの最小および最大パルス幅を設定します。

        * ``pin``: サーボが接続されているGPIOピン番号。
        * ``min`` と ``max``: それぞれ最小および最大パルス幅（マイクロ秒単位）。これらの値はサーボモータの運動範囲を定義します。

    * ``setPeriodHertz(int hertz)``: この関数はサーボモータのPWM周波数をヘルツで設定します。

        * ``hertz``: 希望のPWM周波数（ヘルツ）。サーボのデフォルトPWM周波数は50Hzであり、ほとんどのアプリケーションに適しています。

#. ``loop`` 関数はコードの主要部分で、継続的に実行されます。これにより、サーボモータは0度から180度、そして0度に戻るように回転します。これは、角度を対応するパルス幅にマッピングし、新しいパルス幅値でサーボモータを更新することで行われます。

    .. code-block:: arduino

        void loop() {
            // Rotate the servo from 0 to 180 degrees
            for (int angle = 0; angle <= 180; angle++) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }
    
            // Rotate the servo from 180 to 0 degrees
            for (int angle = 180; angle >= 0; angle--) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }
        }

    * ``writeMicroseconds(int value)``: この関数は、マイクロ秒単位でサーボモータのパルス幅を設定します。
    
        * ``value``: 希望のパルス幅（マイクロ秒単位）。

        ``writeMicroseconds(int value)`` 関数は、希望のパルス幅をマイクロ秒単位で表す整数値を引数として取ります。この値は通常、コードの初めに定義された最小および最大パルス幅（ ``minPulseWidth`` および ``maxPulseWidth`` ）で指定された範囲内にあるべきです。そして、関数はサーボモータのパルス幅を設定し、それに応じて位置を移動させます。

        