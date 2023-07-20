1. Real-time Weather From @OpenWeatherMap
====================================================

The IoT Open Weather Display project utilizes the ESP32 board and an I2C LCD1602 module to create a weather information display that retrieves data from the OpenWeatherMap API. 

This project serves as an excellent introduction to working with APIs, Wi-Fi connectivity, and data display on an LCD module using the ESP32 board. With the IoT Open Weather Display, you can conveniently access real-time weather updates at a glance, making it an ideal solution for home or office environments.


**Get OpenWeather API keys**

|link_openweather| is an online service, owned by OpenWeather Ltd, that provides global weather data via API, including current weather data, forecasts, nowcasts and historical weather data for any geographical location.

#. Visit |link_openweather| to log in/create an account.

    .. image:: img/OWM-1.png

#. Click into the API page from the navigation bar.

    .. image:: img/OWM-2.png

#. Find **Current Weather Data** and click Subscribe.

    .. image:: img/OWM-3.png

#. Under **Current weather and forecasts collection** , subscribe to the appropriate service. In our project, Free is good enough.

    .. image:: img/OWM-4.png

#. Copy the Key from the **API keys** page.

    .. image:: img/OWM-5.png


**Complete Your Device**

#. Build the circuit.

    .. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
        :width: 800

    * :ref:`cpn_esp32_extension`
    * :ref:`cpn_wires`
    * :ref:`cpn_lcd`

#. Open the code.

    * Open the ``iot_1_open_weather.ino`` file located in the ``esp32-ultimate-kit-main\c\codes\iot_1_open_weather`` directory, or copy the code into the Arduino IDE.
    * Or copy this code into **Arduino IDE**.
    * The ``LiquidCrystal I2C``  and ``Arduino_JSON`` libraries are used here, you can install them from the **Library Manager**.

    .. raw:: html
         

#. Locate the following lines and modify them with your ``<SSID>`` and ``<PASSWORD>``.


    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. Fill in the API keys you copied earlier into ``openWeatherMapApiKey``.

    .. code-block::  Arduino

        // Your Domain name with URL path or IP address with path
        String openWeatherMapApiKey = "<openWeatherMapApiKey>";

#. Replace with your country code and city.

    .. code-block::  Arduino

        // Replace with your country code and city
        // Fine the country code by https://openweathermap.org/find
        String city = "<CITY>";
        String countryCode = "<COUNTRY CODE>";

#. After the code runs, you will see the time and weather information of your location on the I2C LCD1602.

.. note::
   When the code is running, if the screen is blank, you can turn the potentiometer on the back of the module to increase the contrast.

