//////////////////////////////////////////////////////////////////////////////////////////
//
//  Protocentral MAX30205 Arduino Library
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
//  For more information, visit https://github.com/Protocentral/Protocentral_MAX30205
//
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef PROTOCENTRAL_MAX30205_H
#define PROTOCENTRAL_MAX30205_H

#include <Arduino.h>
#include <Wire.h>

// 7-bit I2C slave addresses (selected by the A0/A1/A2 strap pins)
#define MAX30205_ADDRESS1       0x49
#define MAX30205_ADDRESS2       0x48

// Register map
#define MAX30205_TEMPERATURE    0x00    // Temperature, read only
#define MAX30205_CONFIGURATION  0x01    // Configuration
#define MAX30205_THYST          0x02    // Hysteresis threshold
#define MAX30205_TOS            0x03    // Over-temperature shutdown threshold

// Temperature resolution: 1 LSB = 0.00390625 °C (1 / 256)
#define MAX30205_RESOLUTION     0.00390625f

// Configuration register bit positions
typedef enum {
  SHUTDOWN,         // Shutdown mode to reduce power consumption (<3.5uA)
  COMPARATOR,       // 0 = comparator mode, 1 = interrupt mode
  OS_POLARITY,      // 0 = active-low OS output, 1 = active-high
  FAULT_QUEUE_0,    // Fault queue bit 0
  FAULT_QUEUE_1,    // Fault queue bit 1
  DATA_FORMAT,      // Data format
  TIME_OUT,         // Bus timeout
  ONE_SHOT          // 1 = one-shot, 0 = continuous conversion
} configuration;

class MAX30205 {
public:
  MAX30205(uint8_t sensorAddress = MAX30205_ADDRESS1, TwoWire &wirePort = Wire);

  bool  begin();                  // Configure continuous mode; returns true if the sensor responds
  bool  scanAvailableSensors();   // Probe 0x48 and 0x49 and latch the address that responds
  float getTemperature();         // Read body temperature in degrees Celsius
  float getTemperatureF();        // Read body temperature in degrees Fahrenheit
  void  shutdown();               // Put the device into low-power shutdown
  void  printRegisters();         // Dump register contents for debugging

  float   temperature = 0;                    // Last temperature reading (°C)
  uint8_t sensorAddress = MAX30205_ADDRESS1;  // Active I2C address

private:
  TwoWire *_wire;

  void    writeRegister(uint8_t reg, uint8_t data);
  uint8_t readRegister(uint8_t reg);
  void    readRegisters(uint8_t reg, uint8_t *dest, uint8_t count);
};

#endif // PROTOCENTRAL_MAX30205_H
