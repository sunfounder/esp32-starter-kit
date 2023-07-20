5. Quick Guide on Thonny
==================================

.. _open_run_code_py:

Open and Run Code Directly
---------------------------------------------

The code section in the projects tells you exactly which code is used, so double-click on the ``.py`` file with the serial number in the ``esp32-ultimate-kit-main\micropython\codes\`` path to open it. 

However, you must first download the package and upload the libraries, as described in :ref:`add_libraries_py`.

#. Open code.

    For example, ``1.1_hello_led.py``.

    If you double click on it, a new window will open on the right. You can open more than one code at the same time.

    .. image:: img/quick_guide1.png

#. Plug the esp32 into your computer with a micro USB cable.

    .. image:: img/plugin_esp32.png

#. Select correct interpreter

    Select the "MicroPython (ESP32).COMxx" interpreter.

    .. image:: img/sec_inter.png

#. Run the code

    To run the script, click the **Run current script** button or press F5.

    .. image:: img/quick_guide2.png

    If the code contains any information that needs to be printed, it will appear in the Shell; otherwise, only the following information will appear.

    Click **View** -> **Edit** to open the Shell window if it doesn't appear on your Thonny.

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; ESP32 module with ESP32

            Type "help()" for more information.

            >>> %Run -c $EDITOR_CONTENT

    * The first line shows the version of MicroPython, the date, and your device information.
    * The second line prompts you to enter "help()" to get some help.
    * The third line is a command from Thonny telling the MicroPython interpreter on your Pico W to run the contents of the script area - "EDITOR_CONTENT".
    * If there is any message after the third line, it is usually a message that you tell MicroPython to print, or an error message for the code.


#. Stop running

    .. image:: img/quick_guide3.png

    To stop the running code, click the **Stop/Restart backend** button. The **%RUN -c $EDITOR_CONTENT** command will disappear after stopping.

#. Save or save as

    You can save changes made to the open example by pressing **Ctrl+S** or clicking the **Save** button on Thonny.

    The code can be saved as a separate file within the **MicroPython drive(ESP32)** by clicking on **File** -> **Save As**.

    .. image:: img/quick_guide4.png

    Select **MicroPython drive**.

    .. image:: img/quick_guide5.png
        
    Then click **OK** after entering the file name and extension **.py**. On the MicroPython drive, you will see your saved file.

    .. image:: img/quick_guide6.png

    .. note::
        Regardless of what name you give your code, it's best to describe what type of code it is, and not give it a meaningless name like ``abc.py``.
        When you save the code as ``main.py``, it will run automatically when the power is turned on.


Create File and Run it
---------------------------


The code is shown directly in the code section. You can copy it to Thonny and run it as follows.

#. Create a new file

    Open Thonny IDE, click **New** button to create a new blank file.

    .. image:: img/quick_guide7.png

#. Copy code

    Copy the code from the project to the Thonny IDE.

    .. image:: img/quick_guide8.png

#. Plug the esp32 into your computer with a micro USB cable.

    .. image:: img/plugin_esp32.png

#. Select correct interpreter

    Select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner.

    .. image:: img/sec_inter.png

#. Run the code

    You need click **Run Current Script** or simply press ``F5`` to run it.

    .. image:: img/quick_guide9.png

    If the code contains any information that needs to be printed, it will appear in the Shell; otherwise, only the following information will appear.

    Click **View** -> **Edit** to open the Shell window if it doesn't appear on your Thonny.

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; ESP32 module with ESP32

            Type "help()" for more information.

            >>> %Run -c $EDITOR_CONTENT

    * The first line shows the version of MicroPython, the date, and your device information.
    * The second line prompts you to enter "help()" to get some help.
    * The third line is a command from Thonny telling the MicroPython interpreter on your Pico W to run the contents of the script area - "EDITOR_CONTENT".
    * If there is any message after the third line, it is usually a message that you tell MicroPython to print, or an error message for the code.


#. Stop running

    .. image:: img/quick_guide3.png

    To stop the running code, click the **Stop/Restart backend** button. The **%RUN -c $EDITOR_CONTENT** command will disappear after stopping.

#. Save or save as

    You can save the code by pressing **Ctrl+S** or clicking the **Save** button on Thonny. In the pop-up window, select the location where you want to save the file.

    .. image:: img/quick_guide5.png
        
    Then click **OK** or **Save** after entering the file name and extension **.py**.

    .. image:: img/quick_guide6.png

    .. note::
        Regardless of what name you give your code, it's best to describe what type of code it is, and not give it a meaningless name like ``abc.py``.
        When you save the code as ``main.py``, it will run automatically when the power is turned on.

#. Open file

    Here are two ways to open a saved code file.

    * The first method is to click the open icon on the Thonny toolbar, just like when you save a program, you will be asked if you want to open it from **this computer** or **MicroPython device**, for example, click **MicroPython device** and you will see a list of all the programs you have saved on the ESP32.
    * The second is to open the file preview directly by clicking **View** -> **Files** -> and then double-clicking on the corresponding ``.py`` file to open it.

