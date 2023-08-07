1.3 Install the ESP32 board(Important)
===========================================

To program the ESP32 microcontroller, we need to install the ESP32 board package in the Arduino IDE. Follow the step-by-step guide below:

#. Open the Arduino IDE. Go to **File** and select **Preferences** from the drop-down menu.

    .. image:: img/install_esp321.png

#. In the Preferences window, locate the **Additional Board Manager URLs** field. Click on it to activate the text box.

    .. image:: img/install_esp322.png

#. Add the following URL to the **Additional Board Manager URLs** field: https://dl.espressif.com/dl/package_esp32_index.json. This URL points to the package index file for the ESP32 boards. Click the **OK** button to save the changes.

    .. image:: img/install_esp323.png

#. In the **Boards Manager** window, type **ESP32** in the search bar. Click the **Install** button to start the installation process. This will download and install the ESP32 board package.

    .. image:: img/install_esp324.png

#. Congratulations! You have successfully installed the ESP32 board package in the Arduino IDE. You can now select the correct board, **ESP32 Dev Module**, by clicking on **Tools** -> **Board** -> **esp32**.

    .. image:: img/install_esp325.png

#. If your ESP32 is connected to the computer, you can choose the correct port by clicking on **Tools** -> **Port**.

    .. image:: img/install_esp326.png

#. Additionally, Arduino 2.0 introduced a new way to quickly select the board and port. For ESP32, it is usually not automatically recognized, so you need to click on **Select other board and port**.

    .. image:: img/install_esp327.png

#. In the search box, type **ESP32 Dev Module** and select it when it appears. Then, choose the correct port and click **OK**.

    .. image:: img/install_esp328.png

#. Afterward, you can select it through this quick access window. Note that during subsequent use, there may be times when ESP32 is not available in the quick access window, and you will need to repeat the above two steps.

    .. image:: img/install_esp329.png

#. Both methods allow you to select the correct board and port, so choose the one that suits you best. Now, everything is ready to upload the code to the ESP32.




