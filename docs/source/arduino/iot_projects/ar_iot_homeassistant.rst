8.8 Camera with Home Assistant
======================================

This project will guide you in setting up a video stream web server for the ESP32 camera and integrating it with the popular home automation platform, Home Assistant. This integration will allow you to access the server from any device on your network.

.. note::
    
    Before diving into this project, you need to have an operating system with Home Assistant installed.
        
    We recommend installing the Home Assistant OS on a Raspberry Pi.
        
    If you don't have a Raspberry Pi, you can also install it on a virtual machine running on Windows, macOS, or Linux.
        
    For installation instructions, refer to the official website link: https://www.home-assistant.io/installation/
        
    Please proceed with this project only after successful installation.

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


**1. Configuration in ESP Home**

#. First plug in the camera.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Connect your ESP32 to the host where you've installed the Home Assistant system (e.g., if installed on a Raspberry Pi, connect to the Pi).

    .. image:: ../../img/plugin_esp32.png

#. Install ESPHome Addon.

    .. image:: img/sp230629_145928.png

#. Click **START**, then **OPEN WEB UI**.

    .. image:: img/sp230629_172645.png
        :width: 700
        :align: center

#. Add new devices.

    .. image:: img/sp230629_172733.png

#. A prompt might appear. Click **CONTINUE**.

    .. image:: img/sp230629_172816.png
        :align: center


#. Create a configuration. Here, you can enter any desired name for **Name**. For WiFi, enter details of the network on which your Home Assistant system is present.

    .. image:: img/sp230629_172926.png

#. Select the **ESP32** as the device type.

    .. image:: img/sp230629_173043.png

#. When you see a fireworks celebration icon, it means you've successfully created the device. Click skip (DO NOT click **INSTALL**).

    .. image:: img/sp230629_173151.png

    At this point, you've only added the device in ESPHome. To integrate the ESP32 module into Home Assistant, additional configurations are needed:

#. Click **EDIT**.

    .. image:: img/sp230629_173322.png

#. After entering the ``.yaml`` interface, modify the ``ssid`` and ``password`` with your WiFi details.

    .. image:: img/sp230629_174301.png

#. Under the ``captive_portal`` section, paste the following code:

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
        
        For more details on the ``.yaml`` configuration for ESP32, you can refer to `ESP32 Camera - ESPHome <https://esphome.io/components/esp32_camera.html>`_.

#. **Save**, then click **INSTALL**.

    .. image:: img/sp230629_174447.png

#. Choose the USB port method for installation.

    .. image:: img/sp230629_174852.png

    .. note:: 
        
        The initial compilation will download dependency packages, which might take around 10 minutes. Please be patient. If the process stalls for a long time, check if there's enough disk space on your system.

#. Wait for the ``INFO Successfully compiled program.`` message, indicating firmware compilation is complete.

    .. image:: img/sp230630_115109.png

    .. sp230630_114902.png

    .. note::

        At this point, you should see the node as **ONLINE**. If not, ensure your ESP32 is on the same network segment or try rebooting the device.

        .. image:: img/sp230630_153024.png

**2. Configuration in Home Assistant**

After integrating with Esphome, you still need to configure the camera in homeassistant. 

#. Go to **Settings** > **Devices & Services**.

    .. image:: img/sp230630_155917.png

#. Now you should see the esphome tab. Click **CONFIGURE**.

    .. image:: img/sp230630_155736.png

#. Click **SUBMIT**.

    .. image:: img/sp230630_162218.png

#. Wait for the **Success** message.

    .. image:: img/sp230630_162311.png

#. In **Overview**, click the top-right menu and select **Edit Dashboard**.

    .. image:: img/sp230630_164745.png

#. Click **ADD CARD**.

    .. image:: img/sp230630_164850.png

#. Choose **Picture entity**.

    .. image:: img/sp230630_164935.png

#. In the entity field, select the ESP32 you just added. Then **save**.

    .. image:: img/sp230630_165019.png

#. Lastly, click **DONE** to exit the **EDIT** interface.

    .. image:: img/sp230630_165235.png

Now, you can view your camera feed on Home Assistant.

