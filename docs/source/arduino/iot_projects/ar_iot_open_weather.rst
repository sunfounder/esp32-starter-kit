.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

8.1 Echtzeit-Wetter von @OpenWeatherMap
====================================================

Das IoT Open Weather Display-Projekt nutzt das ESP32-Board und ein I2C LCD1602-Modul, um eine Wetterinformationsanzeige zu erstellen, die Daten von der OpenWeatherMap-API abruft.

Dieses Projekt dient als hervorragende Einführung in die Arbeit mit APIs, Wi-Fi-Konnektivität und Datenanzeige auf einem LCD-Modul mit dem ESP32-Board. Mit dem IoT Open Weather Display können Sie bequem Echtzeit-Wetteraktualisierungen auf einen Blick abrufen, was es zu einer idealen Lösung für Heim- oder Büroumgebungen macht.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**OpenWeather API-Schlüssel abrufen**

|link_openweather| ist ein Online-Dienst von OpenWeather Ltd, der weltweite Wetterdaten über eine API bereitstellt, einschließlich aktueller Wetterdaten, Prognosen, Nowcasts und historischer Wetterdaten für jeden geografischen Standort.

#. Besuchen Sie |link_openweather|, um sich anzumelden/ein Konto zu erstellen.

    .. image:: img/OWM-1.png

#. Klicken Sie in der Navigationsleiste auf die API-Seite.

    .. image:: img/OWM-2.png

#. Finden Sie **Current Weather Data** und klicken Sie auf Abonnieren.

    .. image:: img/OWM-3.png

#. Abonnieren Sie unter **Current weather and forecasts collection** den entsprechenden Dienst. In unserem Projekt ist Free ausreichend.

    .. image:: img/OWM-4.png

#. Kopieren Sie den Schlüssel von der Seite **API keys**.

    .. image:: img/OWM-5.png


**Vollenden Sie Ihr Gerät**

#. Bauen Sie den Schaltkreis.

    .. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
        :width: 800

#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``iot_1_open_weather.ino``, die sich im Verzeichnis ``esp32-starter-kit-main\c\codes\iot_1_open_weather`` befindet, oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    * Hier werden die Bibliotheken ``LiquidCrystal I2C`` und ``Arduino_JSON`` verwendet, die Sie über den **Library Manager** installieren können.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/71b196ce-8a84-4577-af76-43988c7d3f80/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
         

#. Suchen Sie die folgenden Zeilen und ändern Sie sie mit Ihrem ``<SSID>`` und ``<PASSWORD>``.


    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. Fügen Sie die zuvor kopierten API-Schlüssel in ``openWeatherMapApiKey`` ein.

    .. code-block::  Arduino

        // Your Domain name with URL path or IP address with path
        String openWeatherMapApiKey = "<openWeatherMapApiKey>";

#. Ersetzen Sie sie mit Ihrem Ländercode und Ihrer Stadt.

    .. code-block::  Arduino

        // Replace with your country code and city
        // Fine the country code by https://openweathermap.org/find
        String city = "<CITY>";
        String countryCode = "<COUNTRY CODE>";

#. Nachdem der Code ausgeführt wird, sehen Sie die Uhrzeit und Wetterinformationen Ihres Standorts auf dem I2C LCD1602.

.. note::
   Wenn der Code läuft und der Bildschirm leer ist, können Sie das Potentiometer auf der Rückseite des Moduls drehen, um den Kontrast zu erhöhen.


