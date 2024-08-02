.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _bluetooth_audio_player:

7.3 Bluetooth-Audio-Player
==============================

Das Ziel des Projekts ist es, eine einfache Lösung für das Abspielen von Audio von einem Bluetooth-fähigen 
Gerät mithilfe des eingebauten DAC des ESP32 bereitzustellen.

Das Projekt umfasst die Verwendung der ``ESP32-A2DP``-Bibliothek, um Audiodaten 
von einem Bluetooth-fähigen Gerät zu empfangen. Die empfangenen Audiodaten werden dann an den internen 
DAC des ESP32 über die I2S-Schnittstelle übertragen. Die I2S-Schnittstelle ist konfiguriert, um im Master-Modus, 
Sendemodus und mit eingebautem DAC zu arbeiten. Die Audiodaten werden dann über den Lautsprecher, der an den DAC angeschlossen ist, wiedergegeben.

Beim Verwenden des internen DAC des ESP32 ist zu beachten, dass das Ausgangsspannungsniveau auf 1,1 V begrenzt ist. 
Daher wird empfohlen, einen externen Verstärker zu verwenden, um das Ausgangsspannungsniveau auf das gewünschte Niveau zu erhöhen. 
Es ist auch wichtig, sicherzustellen, dass die Audiodaten im richtigen Format und mit der richtigen Abtastrate vorliegen, um Verzerrungen 
oder Geräusche während der Wiedergabe zu vermeiden.

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
    *   - :ref:`cpn_audio_speaker`
        - \-


**Betriebsschritte**

#. Bauen Sie den Schaltkreis auf.

    Da dies ein Mono-Verstärker ist, können Sie IO25 an den L- oder R-Pin des Audioverstärkermoduls anschließen.

    Der 10K-Widerstand wird verwendet, um hochfrequentes Rauschen zu reduzieren und die Lautstärke des Audios zu verringern. Er bildet zusammen mit der parasitären Kapazität des DAC und des Audioverstärkers einen RC-Tiefpassfilter. Dieser Filter verringert die Amplitude von Hochfrequenzsignalen und reduziert so effektiv hochfrequentes Rauschen. Das Hinzufügen des 10K-Widerstands macht die Musik weicher und eliminiert unerwünschtes Hochfrequenzrauschen.

    Wenn die Musik auf Ihrer SD-Karte bereits leise ist, können Sie den Widerstand entfernen oder durch einen kleineren Wert ersetzen.

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``7.3_bluetooth_audio_player.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\7.3_bluetooth_audio_player``.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    * Hier wird die ``ESP32-A2DP``-Bibliothek verwendet, siehe :ref:`install_lib_man` für eine Anleitung zur Installation.

    .. warning::

        Wenn Sie ein ESP32-Entwicklungsboard Version 3.0.0 oder höher verwenden, können während des Kompilierungsprozesses Fehler auftreten.
        Dieses Problem tritt normalerweise auf, weil neuere Versionen des Boards die ``ESP32-A2DP``-Bibliothek nicht mehr unterstützen.
        Um dieses Beispiel ordnungsgemäß auszuführen, wird empfohlen, die Firmware-Version Ihres ESP32-Boards auf 2.0.17 herunterzustufen.
        Nachdem Sie dieses Beispiel abgeschlossen haben, aktualisieren Sie wieder auf die neueste Version.

        .. image:: ../../faq/img/version_2.0.17.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/7bb7d6dd-72d4-4529-bb42-033b38558347/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. Nachdem Sie das richtige Board und den Port ausgewählt haben, klicken Sie auf den Hochladen-Button.

#. Sobald der Code erfolgreich hochgeladen wurde, schalten Sie das Bluetooth-fähige Gerät ein und suchen Sie nach verfügbaren Geräten, dann verbinden Sie sich mit dem ``ESP32_Bluetooth``.

    .. image:: img/connect_bluetooth.png

#. Spielen Sie Audio auf dem Gerät ab, und der Ton sollte über den Lautsprecher, der an den ESP32 angeschlossen ist, wiedergegeben werden.


**Code-Erklärung**

#. Der Code beginnt mit dem Einbinden der Bibliothek ``BluetoothA2DPSink.h``, die verwendet wird, um Audiodaten von dem Bluetooth-fähigen Gerät zu empfangen. Das ``BluetoothA2DPSink``-Objekt wird dann erstellt und mit den Einstellungen der I2S-Schnittstelle konfiguriert. 

    .. code-block:: arduino

        #include "BluetoothA2DPSink.h"

        BluetoothA2DPSink a2dp_sink;


#. In der Setup-Funktion initialisiert der Code eine ``i2s_config_t struct`` mit der gewünschten Konfiguration für die I2S (Inter-IC Sound)-Schnittstelle. 

    .. code-block:: arduino

        void setup() {
        const i2s_config_t i2s_config = {
            .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
            .sample_rate = 44100, // corrected by info from bluetooth
            .bits_per_sample = (i2s_bits_per_sample_t) 16, // the DAC module will only take the 8bits from MSB
            .channel_format =  I2S_CHANNEL_FMT_RIGHT_LEFT,
            .communication_format = (i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
            .intr_alloc_flags = 0, // default interrupt priority
            .dma_buf_count = 8,
            .dma_buf_len = 64,
            .use_apll = false
        };

        a2dp_sink.set_i2s_config(i2s_config);  
        a2dp_sink.start("ESP32_Bluetooth");  

        }

    * Die I2S-Schnittstelle wird verwendet, um digitale Audiodaten zwischen Geräten zu übertragen. 
    * Die Konfiguration umfasst den ``I2S mode``, ``sample rate``, ``bits per sample``, ``channel format``, ``communication format``, ``interrupt allocation flags``, ``DMA buffer count``, ``DMA buffer length`` und ob der APLL (Audio PLL) verwendet wird oder nicht.
    * Die ``i2s_config_t struct`` wird dann als Argument an die ``set_i2s_config``-Funktion des ``BluetoothA2DPSink``-Objekts übergeben, um die I2S-Schnittstelle für die Audiowiedergabe zu konfigurieren.
    * Die ``start``-Funktion des ``BluetoothA2DPSink``-Objekts wird aufgerufen, um den Bluetooth-Audioempfänger zu starten und die Audiowiedergabe über den eingebauten DAC zu beginnen.

