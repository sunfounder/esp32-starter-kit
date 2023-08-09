
.. _add_libraries_py:

1.4 Upload the Libraries (Important)
======================================

In some projects, you will need additional libraries. So here we upload these libraries to ESP32 first, and then we can run the code directly later.

#. Download the relevant code from the link below.


   * :download:`SunFounder ESP32 Starter Kit <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`


#. Open Thonny IDE and plug the ESP32 into your computer with a micro USB cable and click on the "MicroPython (ESP32).COMXX" interpreter in the bottom right corner.

    .. image:: img/sec_inter.png

#. In the top navigation bar, click **View** -> **Files**.

    .. image:: img/th_files.png

#. Switch the path to the folder where you downloaded the `code package <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`_ before, and then go to the ``esp32-starter-kit-main\micropython\libs`` folder.

    .. image:: img/th_path.png

#. Select all the files or folders in the ``libs/`` folder, right-click and click **Upload to**, it will take a while to upload.

    .. image:: img/th_upload.png

#. Now you will see the files you just uploaded inside your drive ``MicroPython device``.

    .. image:: img/th_done.png