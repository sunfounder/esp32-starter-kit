.. _ar_adafruit_io:

8.6 Temperatur- und Feuchtigkeitsüberwachung mit Adafruit IO
=============================================================

In diesem Projekt werden wir Ihnen zeigen, wie Sie eine beliebte IoT-Plattform verwenden können. Es gibt viele kostenlose (oder kostengünstige) Plattformen online für Programmierbegeisterte. Einige Beispiele sind Adafruit IO, Blynk, Arduino Cloud, ThingSpeak und so weiter. Die Nutzung dieser Plattformen ist recht ähnlich. Hier konzentrieren wir uns auf Adafruit IO.

Wir werden ein Arduino-Programm schreiben, das den DHT11-Sensor verwendet, um Temperatur- und Feuchtigkeitsmessungen an das Dashboard von Adafruit IO zu senden. Sie können auch eine LED im Schaltkreis über einen Schalter im Dashboard steuern.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

**Einrichten des Dashboards**

#. Besuchen Sie |link_adafruit_io| und klicken Sie auf **Start for free**, um ein kostenloses Konto zu erstellen.

    .. image:: img/sp230516_102503.png

#. Füllen Sie das Formular aus, um ein Konto zu erstellen.

    .. image:: img/sp230516_102629.png

#. Nachdem Sie ein Adafruit-Konto erstellt haben, müssen Sie Adafruit io erneut öffnen. Klicken Sie auf **Dashboards** und dann auf **New Dashboard**.

    .. image:: img/sp230516_103347.png

#. Erstellen Sie ein **New Dashboard**.

    .. image:: img/sp230516_103744.png

#. Betreten Sie das neu erstellte **Dashboard** und erstellen Sie einen neuen Block.

    .. image:: img/sp230516_104234.png

#. Erstellen Sie 1 **Toggle**-Block.

    .. image:: img/sp230516_105727.png

#. Als Nächstes müssen Sie hier einen neuen Feed erstellen. Dieser Toggle wird verwendet, um die LED zu steuern, und wir nennen diesen Feed "LED".

    .. image:: img/sp230516_105641.png

#. Überprüfen Sie den **LED**-Feed und gehen Sie dann zum nächsten Schritt über.

    .. image:: img/sp230516_105925.png

#. Vervollständigen Sie die Blockeinstellungen (hauptsächlich Blocktitel, On-Text und Off-Text) und klicken Sie dann unten rechts auf den Button **Create block**, um den Vorgang abzuschließen.

    .. image:: img/sp230516_110124.png

#. Als Nächstes müssen wir zwei **Text Blocks** erstellen. Sie werden verwendet, um Temperatur und Luftfeuchtigkeit anzuzeigen. Erstellen Sie also zwei Feeds mit den Namen **temperature** und **humidity**.

    .. image:: img/sp230516_110657.png

#. Nach der Erstellung sollte Ihr Dashboard ungefähr so aussehen:

    .. image:: img/sp230516_111134.png

#. Sie können das Layout mit der Option **Edit Layout** auf dem Dashboard anpassen.

    .. image:: img/sp230516_111240.png

#. Klicken Sie auf **API KEY**, und Ihr Benutzername und **API KEY** werden angezeigt. Notieren Sie sich diese, da Sie sie für Ihren Code benötigen.

    .. image:: img/sp230516_111641.png

**Code ausführen**

#. Bauen Sie den Schaltkreis.

    .. image:: ../../img/wiring/iot_6_adafruit_io_bb.png

#. Verbinden Sie dann ESP32-WROOM-32E mit dem Computer über das USB-Kabel.

    .. image:: ../../img/plugin_esp32.png

#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``iot_6_adafruit_io.ino``, die sich im Verzeichnis ``esp32-starter-kit-main\c\codes\iot_6_adafruit_io`` befindet, oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    * Hier werden die Bibliotheken ``Adafruit_MQTT Library`` und ``DHT sensor library`` verwendet, die Sie über den **Library Manager** installieren können.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4cf6ad03-250e-4fe9-aa04-0ca73b997843/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Finden Sie die folgenden Zeilen und ersetzen Sie ``<SSID>`` und ``<PASSWORD>`` mit den spezifischen Details Ihres WLAN-Netzwerks.

    .. code-block::  Arduino

        /************************* WiFi Access Point  *********************************/

        #define WLAN_SSID "<SSID>"
        #define WLAN_PASS "<PASSWORD>"

#. Ersetzen Sie dann ``<YOUR_ADAFRUIT_IO_USERNAME>`` mit Ihrem Adafruit IO-Benutzernamen und ``<YOUR_ADAFRUIT_IO_KEY>`` mit dem **API KEY**, den Sie gerade kopiert haben.

    .. code-block::  Arduino

        // Adafruit IO Account Configuration
        // (to obtain these values, visit https://io.adafruit.com and click on Active Key)
        #define AIO_USERNAME "<YOUR_ADAFRUIT_IO_USERNAME>"
        #define AIO_KEY      "<YOUR_ADAFRUIT_IO_KEY>"

#. Nachdem Sie das richtige Board (ESP32 Dev Module) und den Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.

#. Sobald der Code erfolgreich hochgeladen wurde, werden Sie die folgende Meldung im seriellen Monitor beobachten, die auf eine erfolgreiche Kommunikation mit Adafruit IO hinweist.
    
    .. code-block::

        Adafruit IO MQTTS (SSL/TLS) Example


        Connecting to xxxxx
        WiFi connected
        IP address: 
        192.168.18.76
        Connecting to MQTT... MQTT Connected!
        Temperature: 27.10
        Humidity: 61.00

#. Navigieren Sie zurück zu Adafruit IO. Jetzt können Sie die Temperatur- und Luftfeuchtigkeitsmessungen auf dem Dashboard beobachten oder den LED-Kippschalter nutzen, um den Ein-/Ausschaltzustand der externen LED zu steuern, die mit dem Schaltkreis verbunden ist.

    .. image:: img/sp230516_143220.png

