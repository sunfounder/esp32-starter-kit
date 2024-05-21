.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _sh_colorful_ball:

2.3 Colorful Balls
=====================

In this project, we will make the RGB LEDs display different colors.

Clicking on different colored balls on the stage area will cause the RGB LED to light up in different colors.

.. image:: img/4_color.png

Required Components
---------------------

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

You Will Learn
---------------------

- The principle of RGB LED
- Copy sprites and select different costumes
- Three primary colors superimposed


Build the Circuit
---------------------

An RGB LED packages three LEDs of red, green, and blue into a transparent or semitransparent plastic shell. It can display various colors by changing the input voltage of the three pins and superimpose them, which, according to statistics, can create 16,777,216 different colors.

.. image:: img/4_rgb.png
    :width: 300

.. image:: img/circuit/3_color_ball_bb.png

Programming
------------------

**1. Select sprite**


Delete the default sprite, then choose the **Ball** sprite.

.. image:: img/4_ball.png

And duplicate it 5 times.

.. image:: img/4_duplicate_ball.png

Choose different costumes for these 5 **Ball** sprites and move them to the corresponding positions.

.. note::

    **Ball3** sprite costume color needs to be manually changed to red.

.. image:: img/4_rgb1.png
    :width: 800

**2. Make RGB LEDs light up in the appropriate color**

Before understanding the code, we need to understand the `RGB color model <https://en.wikipedia.org/wiki/RGB_color_model>`_.

The RGB color model is an additive color model in which red, green, and blue light are added together in various ways to reproduce a broad array of colors. 

Additive color mixing: adding red to green yields yellow; adding green to blue yields cyan; adding blue to red yields magenta; adding all three primary colors together yields white.

.. image:: img/4_rgb_addition.png
  :width: 400

So the code to make the RGB LED light yellow is as follows.

.. image:: img/4_yellow.png


When the Ball sprite (yellow ball) is clicked, we set pin 27 high (red LED on), pin 26 high (green LED on) and pin 25 low (blue LED off) so that the RGB LED will light yellow.

You can write codes to other sprites in the same way to make the RGB LEDs light up in the corresponding colors.

**3. Ball2 sprite (light blue)**

.. image:: img/4_blue.png

**4. Ball3 sprite (red)**

.. image:: img/4_red.png

**5. Ball4 sprite (green)**

.. image:: img/4_green.png

**6. Ball5 sprite (purple)**

.. image:: img/4_purple.png



