.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _sh_shooting:

2.11 GAME - Shooting
====================================

Have you seen those shooting games on TV? The closer a contestant shoots a bullet on the target to the bullseye, the higher his score.

Today we are also doing a shooting game in Scratch. In the game, let the Crosshair shoot as far as possible to the bullseye to get a higher score.

Click on the green flag to start. Use the Obstacle Avoidance module to shoot an bullet.

.. image:: img/14_shooting.png

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

You Will Learn
---------------------

- How the Obstacle Avoidance module works and the angle range
- Paint different sprites
- Touch colors

Build the Circuit
-----------------------

The obstacle avoidance module is a distance-adjustable infrared proximity sensor whose output is normally high and low when an obstacle is detected.

Now build the circuit according to the diagram below.

.. image:: img/circuit/12_shooting_bb.png

Programming
------------------

**1. Paint the Crosshair sprite**

Delete the default sprite, select the **Sprite** button and click **Paint**, a blank sprite **Sprite1** will appear and name it **Crosshair**.

.. image:: img/14_shooting0.png


Go to the **Crosshair** sprite's **Costumes** page. Click on the **Circle** tool, remove the fill color, and set the color and width of the outline.

.. image:: img/14_shooting02.png

Now draw a circle with the **Circle** tool. After drawing, you can click to the **Select** tool and move the circle so that the original point is aligned with the center of the canvas.

.. image:: img/14_shooting03.png

Using the **Line** tool, draw a cross inside the circle.

.. image:: img/14_shooting033.png

**Paint the Target sprite**

Create a new sprite called **Target** sprite.

.. image:: img/14_shooting01.png

Go to the Costumes page of the **Target** sprite, click on the **Circle** tool, select a fill color and remove the Outline and paint a large circle.

.. image:: img/14_shooting05.png

Use the same method to draw additional circles, each with a different color, and you can use the **Forward** or **Backbard** tool to change the position of the overlapping circles. Note that you also need to select the tool to move the circles, so that the origin of all the circles and the center of the canvas are aligned.

.. image:: img/14_shooting04.png

**3. Add a backdrop**

Add a suitable background which preferably does not have too many colors and does not match the colors in the **Target** sprite. Here I have chosen **Wall1** backdrop.

.. image:: img/14_shooting06.png

**4. Script the Crosshair sprite**

Set the random position and size of the **Crosshair** sprite, and let it move randomly.

.. image:: img/14_shooting4.png

When a hand is placed in front of the obstacle avoidance module, it will output a low level as a transmit signal.

.. image:: img/14_shooting5.png

When the **shooting** message is received, the sprite stops moving and slowly shrinks, thus simulating the effect of a bullet being shot.

.. image:: img/14_shooting6.png

Use the [Touch color ()] block to determine the position of the shot.

.. image:: img/14_shooting7.png

When the shot is inside the yellow circle, 10 is reported.

.. image:: img/14_shooting8.png

Use the same method to determine the position of the bullet shot, if it is not set on the **Target** sprite, it means it is out of the circle.

.. image:: img/14_shooting9.png