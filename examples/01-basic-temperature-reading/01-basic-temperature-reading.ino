//////////////////////////////////////////////////////////////////////////////////////////
//
//  Protocentral MAX30205 Arduino example — basic body temperature reading
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
//  Prints the body temperature in Celsius and Fahrenheit to the Serial Monitor.
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

  // Scan for the sensor (addresses 0x48 and 0x49) until one is found.
  while (!tempSensor.scanAvailableSensors())
  {
    Serial.println("Couldn't find the temperature sensor, please connect the sensor.");
    delay(5000);
  }

  tempSensor.begin();   // Continuous conversion, active mode
}

void loop()
{
  float tempC = tempSensor.getTemperature();    // Degrees Celsius
  float tempF = tempSensor.getTemperatureF();   // Degrees Fahrenheit

  Serial.print(tempC, 2);
  Serial.print(" C\t");
  Serial.print(tempF, 2);
  Serial.println(" F");

  delay(100);
}
