
.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _bluetooth_audio_player:

7.3 Bluetooth Audio Player
==============================

The aim of the project is to provide a simple solution for playing audio from a Bluetooth-enabled 
device using the built-in DAC of the ESP32.

The project involves the use of the ``ESP32-A2DP`` library to receive audio data 
from a Bluetooth-enabled device. The received audio data is then transmitted to the internal 
DAC of the ESP32 using the I2S interface. The I2S interface is configured to operate in master mode, 
transmit mode, and DAC built-in mode. The audio data is then played back through the speaker connected to the DAC.

When using the internal DAC of the ESP32, it is important to note that the output voltage level is limited to 1.1V. 
Therefore, it is recommended to use an external amplifier to boost the output voltage level to the desired level. 
It is also important to ensure that the audio data is in the correct format and sample rate to prevent distortion 
or noise during playback.

**Required Components**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

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


**Operating Steps**

#. Build the circuit.

    As this is a mono amplifier, you can connect IO25 to the L or R pin of the audio amplifier module.

    The 10K resistor is used to reduce high-frequency noise and lower the audio volume. It forms an RC low-pass filter with the parasitic capacitance of the DAC and audio amplifier. This filter decreases the amplitude of high-frequency signals, effectively reducing high-frequency noise. So, adding the 10K resistor makes the music sound softer and eliminates unwanted high-frequency noise.

    If your SD card's music is already soft, you can remove or replace the resistor with a smaller value.

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. Open the code.

    * Open the ``7.3_bluetooth_audio_player.ino`` file under the path of ``esp32-starter-kit-main\c\codes\7.3_bluetooth_audio_player``.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``ESP32-A2DP`` library is used here, refer to :ref:`install_lib_man` for a tutorial to install.

    .. warning::

        If you are using an ESP32 development board version 3.0.0 or higher, you may encounter errors during the compilation process.
        This issue is usually because the newer versions of the board no longer support the ``ESP32-A2DP`` library.
        To properly run this example, it is recommended to downgrade your ESP32 board's firmware version to 2.0.17. 
        After completing this example, upgrade back to the latest version.

        .. image:: ../../faq/img/version_2.0.17.png



    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/7bb7d6dd-72d4-4529-bb42-033b38558347/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. After selecting the correct board and port, click on the Upload button.

#. Once the code is uploaded successfully, turn on the Bluetooth-enabled device and search for available devices, then connect to the ``ESP32_Bluetooth``.

    .. image:: img/connect_bluetooth.png

#. Play audio on the device and the audio should be played through the speaker connected to the ESP32.


**Code Explanation**

#. The code starts by including the ``BluetoothA2DPSink.h`` library, which is used to receive audio data from the Bluetooth-enabled device. The ``BluetoothA2DPSink`` object is then created and configured with the I2S interface settings. 

    .. code-block:: arduino

        #include "BluetoothA2DPSink.h"

        BluetoothA2DPSink a2dp_sink;


#. In the setup function, the code initializes an ``i2s_config_t struct`` with the desired configuration for the I2S (Inter-IC Sound) interface. 

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

    * The I2S interface is used to transfer digital audio data between devices. 
    * The configuration includes the ``I2S mode``, ``sample rate``, ``bits per sample``, ``channel format``, ``communication format``, ``interrupt allocation flags``, ``DMA buffer count``, ``DMA buffer length``, and whether to use the APLL (Audio PLL) or not.
    * The ``i2s_config_t struct`` is then passed as an argument to the ``set_i2s_config`` function of the ``BluetoothA2DPSink`` object to configure the I2S interface for audio playback.
    * The ``start`` function of the ``BluetoothA2DPSink`` object is called to start the Bluetooth audio sink and begin playing audio through the built-in DAC.
