# Protocentral MAX30205 Human Body Temperature Sensor Breakout Board

[![Compile Examples](https://github.com/Protocentral/Protocentral_MAX30205/workflows/Compile%20Examples/badge.svg)](https://github.com/Protocentral/Protocentral_MAX30205/actions?workflow=Compile+Examples)

## Don't have one ? [Buy it here](https://protocentral.com/product/protocentral-max30205-body-temperature-sensor-breakout-board/)

You can buy the Qwiic compatible MAX30205 [here](https://protocentral.com/product/protocentral-max30205-wearable-body-thermometer-breakout-board-qwiic-compatible/).


![MAX30205 Temperature Sensor](docs/images/max30205_brk_0.jpg)
![MAX30205 Temperature Sensor](docs/images/max30205_brk_v2.jpg)


The QWIIC-compatible ProtoCentral MAX30205 breakout board is a wearable human body temperature sensor that reads with an accuracy of +/- 0.1 °C.This is a digital I2C-based sensor, so an ADC would not be required to read this sensor.

In addition, this version of the board is round and designed to be be directly wearable by exposing an Aluminium surface. The alumnium-base PCB helps in easy thermal conduction to make sure most of the heat gets transferred to the sensor, resulting in more accurate readings. The top side of this PCB is encapsulated in clear epoxy resin to make it waterproof. 

Unlike our previous MAX30205 breakout board, what makes it more wearable and fit for human body measurements is the use of a medical-grade biocompatible, flexible cable that does not irritate the skin.

## Hardware Setup

Connection with the Arduino board is as follows:

|MAX30205 pin label| Arduino Connection   |Pin Function      |
|----------------- |:--------------------:|-----------------:|
| 5v      |    Vin (3.3V is also supported, change solder jumper behind the board. Default will be 5V)  | Power Supply |
| GND     |  GND | Power Supply |
| A4      |  SDA | Serial Data |
| A5      |  SCL | Serial Data |


# Visualizing Output

![output](./docs/images/output.png)


For further details of the board, refer the documentation
<center>

[ MAX30205 breakout board Documentation](https://docs.protocentral.com/getting-started-with-max30205/)

</center>


License Information
===================

![License](./license_mark.svg)

This product is open source! Both, our hardware and software are open source and licensed under the following licenses:

Hardware
---------

**All hardware is released under the [CERN-OHL-P v2](https://ohwr.org/cern_ohl_p_v2.txt)** license.

Copyright CERN 2020.

This source describes Open Hardware and is licensed under the CERN-OHL-P v2.

You may redistribute and modify this documentation and make products
using it under the terms of the CERN-OHL-P v2 (https:/cern.ch/cern-ohl).
This documentation is distributed WITHOUT ANY EXPRESS OR IMPLIED
WARRANTY, INCLUDING OF MERCHANTABILITY, SATISFACTORY QUALITY
AND FITNESS FOR A PARTICULAR PURPOSE. Please see the CERN-OHL-P v2
for applicable conditions

Software
--------

**All software is released under the MIT License(http://opensource.org/licenses/MIT).**

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Documentation
-------------
**All documentation is released under [Creative Commons Share-alike 4.0 International](http://creativecommons.org/licenses/by-sa/4.0/).**
![CC-BY-SA-4.0](https://i.creativecommons.org/l/by-sa/4.0/88x31.png)

You are free to:

* Share — copy and redistribute the material in any medium or format
* Adapt — remix, transform, and build upon the material for any purpose, even commercially.
The licensor cannot revoke these freedoms as long as you follow the license terms.

Under the following terms:

* Attribution — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
* ShareAlike — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.

Please check [*LICENSE.md*](LICENSE.md) for detailed license descriptions.