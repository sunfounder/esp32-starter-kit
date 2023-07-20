10. Android App – RGB LED with Arduino and Bluetooth
=======================================================

In this project you’re going to build an Android app to control the color of an RGB LED with a smartphone via Bluetooth.

You’re going to build the Android app using a free web based software called MIT App Inventor 2. This is a great project to learn how to interface the Arduino with a smartphone.



If you’re not familiar with RGB LEDs, read the following post: How do RGB LEDs work?

Download Android Apps for Arduino with MIT App Inventor 2

Parts Required
Here’s a complete list of the parts required for this project:



Arduino UNO – read Best Arduino Starter Kits
Bluetooth module HC-04 or HC-05 or HC-06 
RGB LED (common anode)
3 x 220Ohm resistor 
Breadboard
Jumper wires
Additionally, you also need a smartphone with bluetooth.

You can use the preceding links or go directly to MakerAdvisor.com/tools to find all the parts for your projects at the best price!



Creating the Android App
The Android App will be created using a free web application called MIT App Inventor. MIT App Inventor is a great place to get started with Android development, because it allows you to build simple apps with drag-n-drop.

You need a Google account to sign up for MIT App Inventor and here’s the login page: http://ai2.appinventor.mit.edu.

After login in go to Projects >Import project (.aia) from my computer and upload the .aia file. Click here to download the .aia file.

import

After uploading the .aia file. You’ll see the application on the MIT App Inventor Software.

Designer
With MIT App Inventor you have 2 main sections: designer and blocks.

The designer is what gives you the ability to add buttons, add text, add screens and edit the overall app look. Int the App Inventor software the app looks like this:



The app looks different in the software and in your smartphone. This is the how the app looks in our smartphone:



Blocks
Then, you have the blocks section. The blocks sections is what allows to create custom functionality for your app, so when you press the buttons it actually does something with that information. These are the blocks for this app (click on the image to zoom):



Installing the App
To install the app in your smartphone, go to the Build tab.build

You can either generate a QR code that you can scan with your smartphone and automatically install the app in your smartphone.
Or you can download the .apk file, connect your smartphone to your computer and move the .apk file to the phone.
Simply follow the installation wizard to install the App and it’s done!

Code
Download or copy the following code to your Arduino IDE, and upload it to your Arduino board. Make sure you have the right Board and COM port selected.

Note: before uploading the code, make sure you have the TX and RX pins disconnected from the bluetooth module!

/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 */

#define max_char 12
char message[max_char];    // stores you message
char r_char;               // reads each character
byte index = 0;            // defines the position into your array
int i;

int redPin = 11;     // Red RGB pin -> D11
int greenPin = 10;   // Green RGB pin -> D10
int bluePin = 9;     // Blue RGB pin -> D9

int redValue = 255;     // Red RGB pin -> D11
int greenValue = 255;   // Green RGB pin -> D10
int blueValue = 255;     // Blue RGB pin -> D9

String redTempValue;     // Red RGB pin -> D11
String greenTempValue;   // Green RGB pin -> D10
String blueTempValue;     // Blue RGB pin -> D9

int flag = 0;
char currentColor;  

void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  //while is reading the message 
  while(Serial.available() > 0){
    flag = 0;
    //the message can have up to 12 characters 
    if(index < (max_char-1)){         
      r_char = Serial.read();      // Reads a character
      message[index] = r_char;     // Stores the character in message array
      if(r_char=='R'){
         currentColor = 'R';
         redTempValue = "";
      }
      else if(r_char=='G'){
         currentColor = 'G';
         greenTempValue = "";
      }
      else if(r_char=='B'){
         currentColor = 'B';
         blueTempValue = "";
      }
      if(currentColor == 'R' && r_char!='R'){
         redTempValue += r_char;
      }
      else if(currentColor == 'G' && r_char!='G'){
         greenTempValue += r_char;
      }
      else if(currentColor == 'B' && r_char!='B'){
         blueTempValue += r_char;
      }
      index++;                     // Increment position
      message[index] = '\0';       // Delete the last position
   }
   
 }
 
 if(flag == 0){
   analogWrite(redPin, 255-redTempValue.toInt());
   analogWrite(greenPin, 255-greenTempValue.toInt());
   analogWrite(bluePin, 255-blueTempValue.toInt());
   /*Serial.print('R');
   Serial.println(redTempValue);
   Serial.print('G');
   Serial.println(greenTempValue);
   Serial.print('B');
   Serial.println(blueTempValue);
   Serial.print("MESSAGE ");*/
   Serial.println(message);
   flag=1;
       for(i=0; i<12; i++){
      message[i] = '\0';
    } 
    //resests the index
    index=0;  
 }

}
Sponsored by Vivint Home Security
Which home security system do experts recommend?
Experts love Vivint. Why? Vivint gives you professional protection from break-ins while being incredibly easy to use. Get yours today!

Learn More



View raw code

Schematics
Follow the schematic diagram in the following figure to wire your circuit.



Sponsored by Vivint Home Security
Which home security system do experts recommend?
Experts love Vivint. Why? Vivint gives you professional protection from break-ins while being incredibly easy to use. Get yours today!

Learn More



Note: If you’re using an RGB LED common cathode, you need to connect the longer lead to GND.

Important: Here’s the bluetooth module connections to the Arduino:

Bluetooth module TX connects to Arduino RX
Bluetooth module RX connects to Arduino TX
Here’s how your circuit should look:



Launching the App
If you haven’t generated the .apk file in a previous step, you can click here to download the .apk file (which is the Android App installation file). Move that file to your smartphone and open it. Follow the installation wizard to install the app.

Turn on your smartphone’s Bluetooth.

screenshot_2016-10-09-15-14-52-copy

Make sure you pair your smartphone with the bluetooth module – search for paired devices in your smartphone’s bluetooth settings.

Then, open the newly installed app. Tap on the Connect bluetooth button to connect via bluetooth to the arduino bluetooth module.



Select your Bluetooth module (it should be named linvor).



Now, it’s ready to use!

Demonstration
Here’s your app in action. Move the sliders and click on CHANGE COLOR to set your RGB LED color to the selected color.





Troubleshooting
1.  I can’t upload code to my Arduino board.

Check if you have the TX and RX cables from the bluetooth module disconnected.

When you’re uploading code to your Arduino you should disconnect the TX and RX cables from the bluetooth module. These pins are needed for serial communication between the Arduino and your computer.

 2. I can’t find my bluetooth module device.

Make sure you have paired your smartphone with your bluetooth module. Go to your bluetooth settings and search for the available devices. Your bluetooth module device should appear (it’s often called: linvor, HC-06, HC-04, HC-05 …). Pair with it. If it asks for a password, it’s 1234.

3. The app doesn’t interact with the Arduino.

If your Android app is connected to your bluetooth module, it should display the “Connected” message (as shown below). Otherwise, press the “Connect Bluetooth” to establish a bluetooth communication.



Double-check your bluetooth module connections:

Bluetooth module TX connects to Arduino RX
Bluetooth module RX connects to Arduino TX
4. My bluetooth module is asking for a password.

If your bluetooth module asks for a password, type 1234.

Wrapping up
In this project you learned how to control the color of an RGB LED with an Android App built with the MIT App Inventor 2 software.

Now, feel free to change how the app looks and give it more functionalities.

If you like this project, make sure you check our latest course: Android Apps for Arduino with MIT App Inventor 2.


