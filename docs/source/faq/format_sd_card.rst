.. _format_sd_card:

How to format the SD card?
====================================

The steps to ensure your SD card is formatted correctly may vary depending on your operating system. Here are simple steps on how to format an SD card in Windows, MacOS, and Linux:

**Windows**

   #. Insert your SD card into the computer, then open "My Computer" or "This PC." Right-click on your SD card and select "Format."

        .. image:: img/sd_format_win1.png

   #. In the file system drop-down menu, select the desired file system (usually choose FAT32, or for SD cards larger than 32GB, you may need to choose exFAT). Check "Quick Format" and then click "Start".

        .. image:: img/sd_format_win2.png

**MacOS**
   
   #. Insert your SD card into the computer. Open the "Disk Utility" application (can be found in the "Utilities" folder).

        .. image:: img/sd_format_mac1.png
    
   #. Select your SD card from the list on the left and then click "Erase".

        .. image:: img/sd_format_mac2.png

   #. From the format drop-down menu, choose your desired file system (usually choose MS-DOS (FAT) for FAT32, or ExFAT for SD cards larger than 32GB) and then click "Erase".

        .. image:: img/sd_format_mac3.png

   #. Finally, wait for the formatting to complete.

        .. image:: img/sd_format_mac3.png

**Linux**

   * First, insert your SD card and then open a terminal.
   * Type ``lsblk`` and find your SD card's name in the device list (e.g., it may be ``sdb``).
   * Use the ``umount`` command to unmount the SD card, like ``sudo umount /dev/sdb*``.
   * Use the ``mkfs`` command to format the SD card. For example, ``sudo mkfs.vfat /dev/sdb1`` will format the SD card to a FAT32 file system (for SD cards larger than 32GB, you might need to use ``mkfs.exfat``).

Before formatting your SD card, make sure to back up any important data on the SD card, as the formatting operation will erase all files on the SD card.