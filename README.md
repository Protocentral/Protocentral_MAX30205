ProtoCentral MAX30205 Human body temperature Sensor Breakout Board
=========================================================
[![Laser Sensor](https://github.com/Protocentral/Protocentral_MAX30205/blob/master/extras/board.jpg)  
*PROTOCENTRAL MAX30205 human body temperature breakout (PC-SEN-2001)*](https://www.protocentral.com)

The MAX30205 temperature sensor accurately measures temperature and provide an overtemperature alarm/ interrupt/shutdown output. This device converts the temperature measurements to digital form using a highresolution, sigma-delta, analog-to-digital converter (ADC
This breakout board contains everything to connect it to an Arduino's I2C pins and it can be connected to any other platform with support for I2C two-wire interfaces. 

We have made several cool projects with it including proximity sensing and liquid-level sensing from the outside of a tank. Check out our Hackster page (hackster.io/protocentral) for the detailed project description. 

Features:
---------
On-board 3.3V voltage regulator
Easy-to-use I2C interface

Specifications:
---------------

Includes:
----------
* 1x ProtoCentral MAX30205 Sensor Breakout Board
* 1x Set of breakaway headers

Repository Contents
-------------------
* **/software** - Arduino library and example sketch
* **/hardware** - All Eagle design files (.brd, .sch)
* **/extras** - datasheets and extras

Arduino boards connections


    Arduino  Max30205 board
    -------   -------------
         5v-   Vin (3.3V also supported, change solder jumper behind the board.Default will be 5V)
        GND - GND
         A4 - SDA
         A5 - SCL
 
###  Uploading Arduino Sketch For MAX30205 breakout

 a. Open the Arduino IDE to load the embedded code for Protocentral_MAX30205.

 b. Click on File -> Open and Browse the .ino code for Arduino from Protocentral_MAX30205-master\arduino and export the application to Arduino.
 
 c.  Open serial terminal window, you should see the temperature values obtained from the Protocentral_MAX30205 Breakout Board as shown below.
![Read Temperature](https://github.com/Protocentral/Protocentral_MAX30205/blob/master/extras/output.png)


License Information
===================
This product is open source! Both, our hardware and software are open source and licensed under the following licenses:

Hardware
---------
**All hardware is released under [Creative Commons Share-alike 4.0 International](http://creativecommons.org/licenses/by-sa/4.0/).**
![CC-BY-SA-4.0](https://i.creativecommons.org/l/by-sa/4.0/88x31.png)

Software
--------
**All software is released under the MIT License(http://opensource.org/licenses/MIT).**

Please check [*LICENSE.md*](LICENSE.md) for detailed license descriptions.
