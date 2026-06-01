//////////////////////////////////////////////////////////////////////////////////////////
//
//  Protocentral MAX30205 Arduino example — temperature on the Serial Plotter
//
//  Author: Ashwin Whitchurch
//  Copyright (c) 2018-2025 Protocentral Electronics
//
//  SPDX-License-Identifier: MIT
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//
//////////////////////////////////////////////////////////////////////////////////////////
//
//  Streams the body temperature in Celsius for plotting with the Arduino Serial Plotter
//  (Tools -> Serial Plotter, baud 115200).
//
//  Hardware connections (breakout board to Arduino):
//      Vin  ->  5V (3.3V is also supported)
//      GND  ->  GND
//      SDA  ->  A4 (or the board's SDA pin)
//      SCL  ->  A5 (or the board's SCL pin)
//
//////////////////////////////////////////////////////////////////////////////////////////

#include <Wire.h>
#include "Protocentral_MAX30205.h"

MAX30205 tempSensor;

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  while (!tempSensor.scanAvailableSensors())
  {
    Serial.println("Couldn't find the temperature sensor, please connect the sensor.");
    delay(5000);
  }

  tempSensor.begin();
}

void loop()
{
  Serial.println(tempSensor.getTemperature(), 2);   // Single value for the Serial Plotter
  delay(100);
}
