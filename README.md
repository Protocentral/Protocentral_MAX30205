ProtoCentral MAX30205 Human body temperature Sensor Breakout Board
=========================================================
[![Temperature Sensor](https://github.com/Protocentral/Protocentral_MAX30205/blob/master/extras/board.jpg)  
*PROTOCENTRAL MAX30205 human body temperature breakout (PC-MED-0403)*](https://www.protocentral.com/open-medical-devices/1088-protocentral-max30205-body-temperature-sensor-breakout-board.html)

MAX30205 is the new chip from Maxim which provides accurate human body temperature readings with an accuracy of 0.1 °C

This is a digital I2C temperature sensor, so an ADC would not be required to read this sensor. It also provide an over-temperature alarm as an interrupt to drive microocontroller interrupt lines. 

Features:
---------
High Accuracy: 0.1 °C over a range of 37°C to 39°C
Temperature Resolution: 16-bit (0.00390625°C)
Digital I2C 2-wire interface
"OS" open-drain pin can act as thermostat control 

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
